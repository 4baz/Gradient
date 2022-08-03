// ForceAuthDebugger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sha256.h"

// WMIC:
#include <comdef.h>
#pragma comment(lib, "wbemuuid.lib")
#include <Wbemidl.h>

// Server:
#pragma comment(lib, "wininet.lib")
#include <wininet.h>

// GetHostByName()
#pragma comment(lib, "Ws2_32.lib")
#include "winsock.h"

#pragma warning(disable : 4996) // sscanf warning
using namespace std;


string hex_to_string(const string& input) {
	static const char* const lut = "0123456789ABCDEF";
	size_t len = input.length();
	if (len & 1) throw invalid_argument("odd length");

	string output;
	output.reserve(len / 2);
	for (size_t i = 0; i < len; i += 2) {
		char a = input[i];
		const char* p = lower_bound(lut, lut + 16, a);
		if (*p != a) throw invalid_argument("not a hex digit");

		char b = input[i + 1];
		const char* q = lower_bound(lut, lut + 16, b);
		if (*q != b) throw invalid_argument("not a hex digit");

		output.push_back(((p - lut) << 4) | (q - lut));
	}
	return output;
}

string extract(string& str, string beg, string end) {
	size_t begPos;
	if ((begPos = str.find(beg)) != string::npos) {
		size_t endPos;
		if ((endPos = str.find(end, begPos)) != string::npos) {
			string result = str.substr(begPos + 1, endPos - begPos - 1);
			str.erase(begPos, endPos - begPos + 1);
			return result;
		}
	}
	return ""; //string();
}

int StringToWString(wstring &ws, const string &s) {
	wstring wsTmp(s.begin(), s.end());
	ws = wsTmp;
	return 0;
}

void CleanUpString(string &str) {
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
}

/*string GetHardwareProfileGUID() {
	HW_PROFILE_INFO hwpi;
	GetCurrentHwProfile(&hwpi); // Spoofable from Registry HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\IDConfigDB\Hardware Profiles\0001\HwProfileGuid
	wstring wGUID = hwpi.szHwProfileGuid;
	string GUIDstr(wGUID.begin(), wGUID.end());
	return GUIDstr;
}*/

string GetVolumeInfo() {
	DWORD dwSerial;
	stringstream ss;

	if (GetVolumeInformation(NULL, NULL, 0, &dwSerial, NULL, NULL, NULL, NULL)) ss << dwSerial;  // Spoofable w/ VolumeId
	else ss << "Error:" << GetLastError();

	return ss.str();
}

// https://msdn.microsoft.com/en-us/library/aa390423(v=vs.85).aspx
// https://blogs.technet.microsoft.com/askperf/2012/02/17/useful-wmic-queries/
// https://msdn.microsoft.com/en-us/library/aa389273(v=vs.85).aspx
string GetWMIData() {
	HRESULT hres;

#ifndef _WINDLL
	hres = CoInitializeEx(0, COINIT_MULTITHREADED);
	if (FAILED(hres)) {
		Log::Fatal("HWID read error!");
		exit(0);
		return false;
	}
#endif

	IWbemLocator *pLoc = NULL;
	hres = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&pLoc);
	IWbemServices *pSvc = NULL;
	hres = pLoc->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &pSvc);
	if (FAILED(hres)) {
		Log::Fatal("HWID read error!");
		exit(0);
		return false;
	}

	hres = CoSetProxyBlanket(pSvc, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE);
	if (FAILED(hres)) {
		Log::Fatal("HWID read error!");
		exit(0);
		return false;
	}

	// ComputerSystem
	IEnumWbemClassObject* pEnumerator = NULL;
	hres = pSvc->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_ComputerSystemProduct"), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator);
	if (FAILED(hres)) {
		Log::Fatal("HWID read error!");
		exit(0);
		return false;
	}

	IWbemClassObject *pclsOsObj = NULL;
	ULONG osReturn = 0;

	HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsOsObj, &osReturn);
	if (FAILED(hres)) {
		Log::Fatal("HWID read error!");
		exit(0);
		return false;
	}

	VARIANT uniqueUserID;
	hr = pclsOsObj->Get(L"uuid", 0, &uniqueUserID, 0, 0);

	// CPU
	IEnumWbemClassObject* cpuEnumerator = NULL;
	hres = pSvc->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_Processor"), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &cpuEnumerator);
	if (FAILED(hres)) {
		Log::Fatal("HWID read error!");
		exit(0);
		return false;
	}

	IWbemClassObject *pclsCpuObj = NULL;
	ULONG CpuReturn = 0;

	hr = cpuEnumerator->Next(WBEM_INFINITE, 1, &pclsCpuObj, &CpuReturn);
	if (FAILED(hres)) {
		Log::Fatal("HWID read error!");
		exit(0);
		return false;
	}

	VARIANT cpuProcessorID;
	hr = pclsCpuObj->Get(L"ProcessorID", 0, &cpuProcessorID, 0, 0);
	wstringstream HWSerial;
	HWSerial << cpuProcessorID.bstrVal << uniqueUserID.bstrVal;

	wstring WMIC = HWSerial.str();
	string WMICInfo(WMIC.begin(), WMIC.end());

	return WMICInfo;
}


string CheckAuth(string username, string hwid) {
	DWORD64 authCheckTime = 0;
	bool connected = false;
	string auth_str = "";

	HINTERNET connect = InternetOpenA("T3 Auth", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0); // INTERNET_OPEN_TYPE_PRECONFIG
	HINTERNET authConnection = NULL;
	HINTERNET authRequest = NULL;

	if (!connect) {
		Log::Fatal("Connection to T3zz3r3t.Menu failed, check your network connection.");
		exit(0);
	}

	struct hostent *he;
	he = gethostbyname("t3zz3r3t.menu");
	char* hostIP = inet_ntoa(*((struct in_addr *)he->h_addr_list[0]));

	unsigned char s1, s2, s3, s4;
	unsigned int uip1, uip2;

	sscanf("185.38.149.189", "%hhu.%hhu.%hhu.%hhu", &s1, &s2, &s3, &s4); // If your server ip changes, you need to update this, if you use cloudflare, you need to check the cloudflare ip range instead of comparing against 1 ip.
	uip1 = (s1 << 24) | (s2 << 16) | (s3 << 8) | s4; //store all values in 32bits unsigned int

	sscanf(hostIP, "%hhu.%hhu.%hhu.%hhu", &s1, &s2, &s3, &s4);
	uip2 = (s1 << 24) | (s2 << 16) | (s3 << 8) | s4;

	if (uip1 != uip2) { // Prevent auth server emulation/hosts file editing
		//Log::Error("Server ip doesnt match");
		exit(0);
		return "";
	}

	string authStr = sha256("yBplXLUkSDMNmsC8Qjy_axaLihknxjUf" + hwid + "idZpuuexkkswgNXzzy2Yu" + username + "bfI02Fqd8<4nDo9IRe9Onm[V");

	string postDataStr = "u=" + username + "&h=" + hwid + "&a=" + authStr; //+ "&v=" + displayVersion.str();
	char* frmdata = (char*)postDataStr.c_str();
	char* hdrs = "Content-Type: application/x-www-form-urlencoded"; // \r\n  text/html

	authConnection = InternetConnectA(connect, "t3zz3r3t.menu" /* Server */, INTERNET_DEFAULT_HTTP_PORT, NULL /*Username*/, NULL /*Password*/, INTERNET_SERVICE_HTTP, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE /*INTERNET_FLAG_CACHE_IF_NET_FAIL*/ /*Synchronous*/, NULL /*No Context*/);
	if (authConnection) {
		authRequest = HttpOpenRequestA(authConnection, "POST", "/auth.php", NULL /*"HTTP/1.1" /*Default HTTP Version*/, NULL /*No Referer*/, nullptr /*Accept Anything*/, INTERNET_FLAG_RELOAD /* INTERNET_FLAG_CACHE_IF_NET_FAIL */ /*Flags*/, NULL /*No Context*/);
		if (authRequest) {
			authCheckTime = GetTickCount64();
			while (!connected && (authCheckTime - GetTickCount64() < 15000)) {
				if (HttpSendRequestA(authRequest, hdrs /*headers*/, strlen(hdrs) /*Header length*/, frmdata /*No Body*/, strlen(frmdata) /*Body length*/)) connected = true;
			}
			if (!connected) Log::Fatal("Http Request failed, error code: %i", GetLastError());
			else {
				DWORD dwSize;
				CHAR szTemp[75];
				do {
					if (!InternetReadFile(authRequest, szTemp, 50, &dwSize)) continue; //return FALSE;
					if (!dwSize) break;
					else auth_str.append(szTemp, szTemp + dwSize);
				} while (TRUE);
			}
		}
		else {
			Log::Fatal("OpenRequest failed, error code: %d", GetLastError());
		}
	}
	else {
		Log::Fatal("Internet Connection failed, error code: %i", GetLastError());
	}

	return auth_str;
}

bool CustomerCheck(string username) {
	string PubKey = "3*&x#Zc]{HY@I@!7mre.,)^FRnh(r<Ce9w3j`0YQycPp~IQTH-Vigs&6FA-1W^sTWYu[jU$7k*oHsY4O5.C8t8K^!yW6U!D6bQf`@l?.rzhF:aX9UPBr[7bzr}t?s1>_rFyGSILT3r,VwokRmAV{ym~<*:DOVu7T)7%YhyUE5LiAlQcMN[v(h<[Y*{BQ/4l1v4>IYjUx$GHffoT8xsVgbc5u)R}RMh!lD)q)i@~TGtim4i_[#8X<CevOt-*k^HVQtA$@av$_/JBQK,^V%^:Ya)3g~7:f5L)uo7BCTO*JBY`E7-Ps<{yWZPlJF8l(K@,CW@HXWB3/p.05[B>2B_hkhx[!i3M@*raAk9Zzti@rICD0SN}%Y`5j2@3.jF8K_p$i3GtAUw3QsL2N*YBq&$v1cF7]3RFnPlGR:$zyS)UkfP8*IWY-<}mZ2MC<8M6Ia#oj.KzHymP!#7o9f`Y}G.OY:Osx-k18.}O)oA/mk{V36Q!4}>Gw;)%l4Rtf<6q;l{P^"; // 512 characters

	reverse(PubKey.begin(), PubKey.end());
#ifdef _DEBUG
	Log::Msg("VolumeInfo: %s WMIData: %s", GetVolumeInfo(), GetWMIData());
#endif
	string hwid = sha256("D6PwthTdUorF1}]F}<hn_dkKN)ib2M5M" + GetVolumeInfo() + "leQyu78]](O}ehx>BW6)sR" + GetWMIData());
	string serverReturn = CheckAuth(username, hwid);

	if (serverReturn != "") {
		string Hashes[2] = { sha256(username), sha256(hwid) };
		string found_auth = extract(hex_to_string(serverReturn), "[", "]");
#ifdef _DEBUG
		Log::Msg(found_auth);
#endif

		string ban_message = extract(hex_to_string(serverReturn), "{", "}");
		string FirstNumber = found_auth.substr(0, 3);
		string SecondNumber = found_auth.substr(3, 3);

		int firstChar = atoi(FirstNumber.c_str());
		int lastChar = atoi(SecondNumber.c_str());
		found_auth.erase(found_auth.begin(), found_auth.begin() + 6);

		ostringstream OValidClientSideHash;
		OValidClientSideHash << PubKey[firstChar] << "[VERIFIED]" << Hashes[0] << "HW" << Hashes[1] << "SALT@@" << sha256(sha256(PubKey)) << PubKey[lastChar];
		string ValidClientSideHash = sha256(OValidClientSideHash.str());

		ostringstream OInvalidSCUser;
		OInvalidSCUser << PubKey[firstChar] << "[NOSC]" << Hashes[0] << "HW" << Hashes[1] << "_*/SALT@@" << sha256(sha256(PubKey)) << PubKey[lastChar];
		string InvalidSCUser = sha256(OInvalidSCUser.str());

		ostringstream OHWIDClientSideHash;
		OHWIDClientSideHash << PubKey[firstChar] << "[HWID]" << Hashes[0] << "HW" << Hashes[1] << "_*/SALT@@" << sha256(sha256(PubKey)) << PubKey[lastChar];
		string HWIDClientSideHash = sha256(OHWIDClientSideHash.str());

		ostringstream OBannedClientSideHash;
		OBannedClientSideHash << PubKey[firstChar] << "[BANNED]" << Hashes[0] << "HW" << Hashes[1] << "_*/SALT@@" << sha256(sha256(PubKey)) << PubKey[lastChar];
		string BannedClientSideHash = sha256(OBannedClientSideHash.str());

		ostringstream OInvalidAuthHash;
		OInvalidAuthHash << PubKey[firstChar] << "[INVALIDAUTH]_*/SALT@@" << sha256(sha256(PubKey)) << PubKey[lastChar];
		string InvalidAuthHash = sha256(OInvalidAuthHash.str());


		if (found_auth == ValidClientSideHash) {
#ifdef _DEBUG
			Log::Msg("Valid Auth!");
#endif
			return true;
		}
		else if (found_auth == InvalidSCUser) {
			Log::Fatal("Social Club Not Found");
			return false;
		}
		else if (found_auth == HWIDClientSideHash) {
			Log::Fatal("Invalid HWID");
			return false;
		}
		else if (found_auth == BannedClientSideHash) {
			Log::Fatal("Banned - %s", ban_message);
			return false;
		}
		else if (found_auth == InvalidAuthHash) {
			Log::Fatal("Authentication Error");
			return false;
		}
	}
	else Log::Fatal("Empty server response");

	Log::Fatal("Auth Failed To Connect");
	return false;
}