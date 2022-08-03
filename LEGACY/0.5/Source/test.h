#pragma once
class network
{
private:
	std::wstring siteurl;
public:
	network(std::wstring url)
	{
		this->siteurl = url;
	}

	std::wstring post(std::string message)
	{
		WinHttpClient client(this->siteurl);

		string data = message;
		client.SetAdditionalDataToSend((BYTE*)data.c_str(), data.size());

		client.SetRequireValidSslCertificates(true);

		wchar_t szSize[50] = L"";
		swprintf_s(szSize, L"%zd", data.size());
		std::wstring headers = L"Content-Length: ";
		headers += szSize;
		headers += L"\r\nContent-Type: application/x-www-form-urlencoded\r\n";
		client.SetAdditionalRequestHeaders(headers);

		client.SendHttpRequest(L"POST");

		return client.GetResponseContent();
	}
};