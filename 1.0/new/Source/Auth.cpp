#include "stdafx.h"
//#include "webFunctions.h"
/*
#include "WinHttpClient.h"
#include "sha256.h"
#include "File.h"



#include "WinHttpClient.h"
#include "INI.h"
#include "sha256.h"
#include "resource.h"
Ini *settingsIni = new Ini(".\\Gradient\\settings.ini");
string name = settingsIni->GetString("Login", "User");
string pw = settingsIni->GetString("Login", "Pass");
char* version;
// https://luxx.menu/test_auth_diredan/multi_level_test/multi_level_auth.php
//https://luxx.menu/auth/gradient/auth.php
namespace auth {
network server(L"https://luxx.menu/auth/gradient/auth.php");
std::string imfat[]{
"WbdYpWaY8GFGtCLyJ",
"EtjZbTz5yde6RxHFu",
"rs7SfNKDQjHcfHRD5",
"FU5R2Tds88a39SHdf",
"mtguYQe5kVthPuu3e",
"ZnxmjmBAAxwwHe6eT",
"w3DVqKhfg2UXJP6kJ",
"fBs5bjUuP34tmRKEA",
"fYzJB235nQvLPN7nh",
"muzn4ZJhYpyGbQBMp",
"qDfZsaBTpgNffEdxD",
"4kgRhXeN3uReKZ2ww",
"JesBFthkY8azt37sz",
"MJrWrDJhNTukGaFAp",
"L2dXUB3y9hYpHkuUj",
"Y7PPbnveTvVau7NB3",
"wCDyCfa5HwzW6zv3m",
"R7J2FBt75j2WS8c5v",
"K7UxBfT62XfH2SEWf"
};
std::vector<std::wstring> responses;
std::string getHWID() {
char hwid[4096];

// total physical memory
MEMORYSTATUSEX statex;
statex.dwLength = sizeof(statex);
GlobalMemoryStatusEx(&statex);
sprintf_s(hwid, "%I64i", statex.ullTotalPhys / 1024);

// volume information
TCHAR volume_name[MAX_PATH + 1] = { 0 };
TCHAR filesystem_name[MAX_PATH + 1] = { 0 };
DWORD serial_number = 0, maxcomponentlen = 0, filesystemflags = 0;
GetVolumeInformation(_T("C:\\"), volume_name, ARRAYSIZE(volume_name), &serial_number, &maxcomponentlen, &filesystemflags, filesystem_name, ARRAYSIZE(filesystem_name));
sprintf_s(hwid, "%s%li%ws%li", hwid, serial_number, filesystem_name, maxcomponentlen);

// computer name
TCHAR computer_name[MAX_COMPUTERNAME_LENGTH + 1];
DWORD size = sizeof(computer_name) / sizeof(computer_name[0]);
GetComputerName(computer_name, &size);
sprintf_s(hwid, "%s%ws", hwid, computer_name);

// hash the hwid we made
return sha256(static_cast<std::string>(hwid));
//internals::notifyMap("~b~HWID is: ~w~"s + static_cast<std::string>(hwid), 0);
//internals::notifyMap("~b~You can also find this in the menu log file", 0);
Log::Msg(hwid);
}
void readFile(std::string *discord, std::string *token, std::string *scid) {
*(std::string*)discord = name;  //file::ReadIniKey("auth", "Auth", "reference");//auth_file.readLine(1);  string name = settingsIni->GetString("Login", "User");

*(std::string*)token = pw;//file::ReadIniKey("auth", "Auth", "token");//auth_file.readLine(2);


*(std::string*)scid = static_cast<std::string>(SOCIALCLUB::_SC_GET_NICKNAME());
//internals::notifyMap("~b~Discord Username is: ~w~"s + discord, 0);
//internals::notifyMap("~b~Token is: ~w~"s + token, 0);
//internals::notifyMap("~b~SCID is: ~w~"s + scid, 0);
}
bool signIn(bool notify = false) {

std::string discord, token, scid, hashed_hwid_string = getHWID();
// get their discord, token and construct the post message
readFile(&discord, &token, &scid);
std::string message = "scid=" + scid + "&hwid=" + hashed_hwid_string + "&reference=" + discord + "&token=" + token;

// make the post request
std::wstring response = server.post(message);

// check if the response has been made before, we only allow 2 same responses
static int repeat_count = 0;
for (auto &check : responses) {
if (check == response) {
repeat_count += 1;
if (repeat_count == 2) {
notifyMap("Dulplicate Response Received", 0);
Log::Msg("Dulplicate Response Received");
//exit(0);
}
}
}
// add this response into the response vector
responses.push_back(response);

// cast to string
std::string str_response; str_response.assign(response.begin(), response.end());
//Log::Msg(const_cast<char*>(str_response.c_str()));

//Check if the response is correct
if (str_response.find(hashed_hwid_string) == std::string::npos) {
notifyMap(str_response, 0); //when using with luxx, change this to game::notifyError(str_response); and remove error from the start of the response.
return false;
}

// split the response into a vector
std::size_t position = 0; std::string split_token; std::vector<std::string> contents;
while ((position = str_response.find("q")) != std::string::npos) {
split_token = str_response.substr(0, position);
contents.push_back(split_token);
str_response.erase(0, position + 1);
}

contents.push_back(str_response);
Log::Msg("Split into the vector");

std::string token1 = imfat[atoi(contents[1].c_str())],
token2 = imfat[atoi(contents[4].c_str())],
token3 = imfat[atoi(contents[2].c_str())],
token4 = imfat[atoi(contents[5].c_str())],
combined_unhashed_token = token1 + token2 + token3 + token4,
hashed_token = sha256(combined_unhashed_token);

if (hashed_token == contents[3]) {
version = "premium";	//Standard Luxx Premium
notifyMap("~g~Auth Success.~w~ Welcome: "s + discord, 0);
Log::Msg("Auth Success, it fockin worked");
//	file::load::Config(0);
return true;
}

}
}
*/
#include "File.h"
#include "stdafx.h"
#include "Web2.0.h"
#include "sha512.hh"
#pragma once

wstring s2ws(const std::string& str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}

bool is_user_authed()
{

#define URL L"https://rmauth.xyz/GradientAuth/gradient_auth/gradient.php"


	Ini *settingsIni = new Ini(".\\settings.ini");
	string user = settingsIni->GetString("Login", "User");
	string pw = settingsIni->GetString("Login", "Pass");

	char hwid[4096];
	// total physical memory
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	sprintf_s(hwid, "%I64i", statex.ullTotalPhys / 1024);

	// volume information
	TCHAR volumename[MAX_PATH + 1] = { 0 };
	TCHAR filesystemname[MAX_PATH + 1] = { 0 };
	DWORD serialnumber = 0, maxcomponentlen = 0, filesystemflags = 0;
	GetVolumeInformation(_T("C:\\"), volumename, ARRAYSIZE(volumename), &serialnumber, &maxcomponentlen, &filesystemflags, filesystemname, ARRAYSIZE(filesystemname));
	sprintf_s(hwid, "%s%li%ws%li", hwid, serialnumber, filesystemname, maxcomponentlen);

	// computer name
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	GetComputerName(computerName, &size);
	sprintf_s(hwid, "%s%ws", hwid, computerName);

	net::requests m_request(L"galaxy-five", false);
	std::wstring answer = m_request.Post(false, URL, "username=%s&password=%s&hwid=%s", user.c_str(), pw.c_str(), (sw::sha512::calculate(hwid)).c_str());
	if (answer == L"Try again!") {
//		VMProtectBeginUltra("Auth_fuck_me_crispy");

		answer = m_request.Post(false, URL, "username=%s&password=%s&hwid=%s", user.c_str(), pw.c_str(), (sw::sha512::calculate(hwid)).c_str());
//		VMProtectEnd();

	}
	return answer != L"Access granted!" ? false : true;
}

