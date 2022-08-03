// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Library Files:
#pragma comment(lib, "ws2_32.lib")





// Windows Header Files:
#include <windows.h>
#include <Mmsystem.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <memory>
#include <Psapi.h>
#include <MinHook.h>
#include <timeapi.h>
#include <time.h>
#include <shellapi.h>
#include <typeinfo>
#include <wincrypt.h>
#include <cstring>
#include <fstream>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <filesystem>
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
//extern bool tenmil = false;
//extern bool twelvemil = false;
#pragma comment(lib, "winmm.lib")

// Additional Header Files:
#include "Log.h"
#include "Memory.h"
#include "types.h"
#include "enums.h"
#include "InputHook.h"
#include "keyboard.h"
#include "CrossMapping.h"
#include "NativeInvoker.h"
#include "nativeCaller.h"
#include "natives.h"
#include "Hooking.h"
#include "Structs.h"
#include "Functions.h"
#include "script.h"
#include "endme.h"
#include "testcunt.cpp"
#include "VMProtectSDK.h"

#include "WinHttpClient.h"
#include "Auth.h"