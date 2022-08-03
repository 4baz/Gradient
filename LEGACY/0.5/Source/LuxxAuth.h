


/*

#pragma once
#include "WinHttpClient.h"
#include "sha256.h"
#include "test.h"
#pragma once
using namespace std;





#ifndef WEB_FUNCTIONS_H
#define WEB_FUNCTIONS_H

namespace auth {

	extern network authServer;
	extern std::string imfat[];
	extern std::vector<std::wstring> responses;
	std::string getHWID();
	void readFile(std::string * discord, std::string * token, std::string * scid);
	bool signIn(bool notify);
}
#endif // !WEB_FUNCTIONS_H
*/


#pragma once
#include "stdafx.h"


std::wstring s2ws(const std::string& str);

bool is_user_authed();