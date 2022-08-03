#include "stdafx.h"

#include "./Auth/WinHttpClient.h" 
#include "./Auth/INI.h" 
#include "./Auth/sha256.h" 
#include "./Auth/resource.h"


// opals dank ass auth https://media.giphy.com/media/A4R8sdUG7G9TG/giphy.gif


std::string Chwid; void setHwid() {
	char hwid[4096];     // total physical memory     MEMORYSTATUSEX statex;     statex.dwLength = sizeof(statex);     GlobalMemoryStatusEx(&statex);     sprintf_s(hwid, "%I64i", statex.ullTotalPhys / 1024);     // volume information     TCHAR volume_name[MAX_PATH + 1] = { 0 };     TCHAR filesystem_name[MAX_PATH + 1] = { 0 };     DWORD serial_number = 0, maxcomponentlen = 0, filesystemflags = 0;     GetVolumeInformation(_T("C:\\"), volume_name, ARRAYSIZE(volume_name), &serial_number, &maxcomponentlen, &filesystemflags, filesystem_name, ARRAYSIZE(filesystem_name));     sprintf_s(hwid, "%s%li%ws%li", hwid, serial_number, filesystem_name, maxcomponentlen);     // computer name     TCHAR computer_name[MAX_COMPUTERNAME_LENGTH + 1];     DWORD size = sizeof(computer_name) / sizeof(computer_name[0]);     GetComputerName(computer_name, &size);     sprintf_s(hwid, "%s%ws", hwid, computer_name);     // cast the hwid we made to string     Chwid = static_cast<std::string>(hwid);     tsOut("HWID: "s + Chwid + " stored."); }







						 //credz to diredan for the response stuff
	std::vector<std::wstring> responses; bool is_cracked; std::string imfat[]{ "WbdYpWaY8GFGtCLyJ",     "EtjZbTz5yde6RxHFu",     "rs7SfNKDQjHcfHRD5",     "FU5R2Tds88a39SHdf",     "mtguYQe5kVthPuu3e",     "ZnxmjmBAAxwwHe6eT",     "w3DVqKhfg2UXJP6kJ",     "fBs5bjUuP34tmRKEA",     "fYzJB235nQvLPN7nh",     "muzn4ZJhYpyGbQBMp",     "qDfZsaBTpgNffEdxD",     "4kgRhXeN3uReKZ2ww",     "JesBFthkY8azt37sz",     "MJrWrDJhNTukGaFAp",     "L2dXUB3y9hYpHkuUj",     "Y7PPbnveTvVau7NB3",     "wCDyCfa5HwzW6zv3m",     "R7J2FBt75j2WS8c5v",     "K7UxBfT62XfH2SEWf" };