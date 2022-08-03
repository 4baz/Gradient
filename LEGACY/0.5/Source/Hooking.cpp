//Hooking.cpp
#include "stdafx.h"



/*
Copyright 2016-2017 sub1to

This file is part of subVersion 2 GTA:O Hack.

subVersion 2 GTA:O Hack is free software: you can redistribute
it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

subVersion 2 GTA:O Hack is distributed in the hope that it
will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with subVersion 2 GTA:O Hack.  If not, see <http://www.gnu.org/licenses/>.
*/

void	mem_nop(void* ptr, int size);
static void*					g_eventPtr[REVENT_END] = { nullptr };

/*
//CMetaData
*/

class CMetaData
{
public:
	static uint64_t	begin();
	static uint64_t	end();
	static DWORD	size();
	static void		init();
private:
	static uint64_t	m_begin;
	static uint64_t	m_end;
	static DWORD	m_size;
};

/*
//CPatternResult
*/

class CPatternResult
{
public:
	CPatternResult(void* pVoid);
	CPatternResult(void* pVoid, void* pBegin, void* pEnd);
	~CPatternResult();

	template <typename rT>
	rT*	get(int offset = 0)
	{
		rT*	ret = nullptr;
		if (m_pVoid != nullptr)
			ret = reinterpret_cast<rT*>(reinterpret_cast<char*>(m_pVoid) + offset);
		return ret;
	}

	template <typename rT>
	rT* get_rel(int offset = 0)
	{
		rT*		result = nullptr;
		int32_t	rel;
		char*	ptr = get<char>(offset);

		if (ptr == nullptr)
			goto LABEL_RETURN;

		rel = *(int32_t*)ptr;
		result = reinterpret_cast<rT*>(ptr + rel + sizeof(rel));

	LABEL_RETURN:
		return result;
	}

	template <typename rT>
	rT*	section_begin()
	{
		return reinterpret_cast<rT*>(m_pBegin);
	}

	template <typename rT>
	rT*	section_end()
	{
		return reinterpret_cast<rT*>(m_pEnd);
	}

protected:
	void*	m_pVoid = nullptr;
	void*	m_pBegin = nullptr;
	void*	m_pEnd = nullptr;
};

/*
//CPattern
*/

typedef	std::vector<CPatternResult>	vec_result;
class CPattern
{
public:
	CPattern(char* szByte, char* szMask);
	~CPattern();

	CPattern&		find(int i = 0, uint64_t startAddress = 0);		//scans for i patterns
	CPattern&		virtual_find(int i = 0, uint64_t startAddress = 0);
	CPatternResult	get(int i);				//returns result i

protected:
	char*			m_szByte;
	char*			m_szMask;
	bool			m_bSet;
	vec_result		m_result;

	bool		match(int i = 0, uint64_t startAddress = 0, bool virt = false);
	bool		byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask);
	uint64_t	find_pattern(uint64_t i64Address, uint64_t end, BYTE *btMask, char *szMask);
	uint64_t	virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask);
};


/*
Copyright 2016-2017 sub1to

This file is part of subVersion 2 GTA:O Hack.

subVersion 2 GTA:O Hack is free software: you can redistribute
it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

subVersion 2 GTA:O Hack is distributed in the hope that it
will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with subVersion 2 GTA:O Hack.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdafx.h"

void	mem_nop(void* ptr, int size)
{
	memset(ptr, 0x90, size);
}

/*
//CMetaData
*/

uint64_t	CMetaData::m_begin = 0;
uint64_t	CMetaData::m_end = 0;
DWORD		CMetaData::m_size = 0;

uint64_t	CMetaData::begin()
{
	return m_begin;
}
uint64_t	CMetaData::end()
{
	return m_end;
}
DWORD		CMetaData::size()
{
	return m_size;
}

void		CMetaData::init()
{
	if (m_begin && m_size)
		return;

	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER*	headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS*	headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}

/*
//CPatternResult
*/

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern&	CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
//CPattern Private
*/

bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE*	ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char*	pStart = nullptr;
	char*	pEnd = nullptr;
	char*	res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}





























































































































































// END PATTERN.h AND .CPP C&p
//
//
//
//
//

static __int64**												m_globalPtr;

using namespace Memory;
ScriptThread*(*GetActiveThread)() = nullptr;

fpIsEntityDead						Hooking::is_entity_dead;
fpshopBeginService                  Hooking::shop_begin_service;
fpNetworkShopBeginService			Hooking::network_shop_begin_service;
wait                                Hooking::wait_test;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;
std::vector<LPVOID>		Hooking::m_hookedNative;
static eGameState* 											m_gameState;
static uint64_t												m_worldPtr;
static BlipList*											m_blipList;
static Hooking::NativeRegistration**						m_registrationTable;
static std::unordered_map<uint64_t, Hooking::NativeHandler>	m_handlerCache;
CRITICAL_SECTION		Hooking::m_critSec;

/* Start Hooking */
const int EVENT_COUNT = 78;

void Hooking::Start(HMODULE hmoduleDLL)
{
	_hmoduleDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	FindPatterns();
	//	moneyBypass(true);
	if (!InitializeHooks()) Cleanup();
}

/* Hooks */

// Initialization
BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;
	InitializeCriticalSection(&m_critSec);
	// Input hook
	if (!iHook.Initialize()) {

		Log::Error("Failed to initialize InputHook");
		returnVal = FALSE;
	}

	// init minhook
	if (MH_Initialize() != MH_OK) {
		Log::Error("MinHook failed to initialize");
		returnVal = FALSE;
	}

	// init native hook
	if (!HookNatives()) {

		Log::Error("Failed to initialize NativeHooks");
		returnVal = FALSE;
	}

	return returnVal;
}

/* Native Hook Function  */
template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Hooking::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}

//Hooking::NativeHandler ORIG_GET_FRAME_COUNT = NULL;
//void* __cdecl MY_GET_FRAME_COUNT(NativeContext *cxt)
//{
//	Hooking::onTickInit();
//	return cxt;
//}
/*
Hooking::NativeHandler ORIG_GET_NUMBER_OF_EVENTS = NULL;
void* __cdecl MY_GET_NUMBER_OF_EVENTS(NativeContext *cxt)
{
ScriptThread* pThread = GetActiveThread();
if (pThread->m_ctx.ScriptHash == 0x5700179c) //thread that we want to hijack
{
//if (pThread->m_ctx.State == ThreadStateRunning) {
Hooking::onTickInit();
//}
}
}
*/

/*
Hooking::NativeHandler ORIG_GET_NUMBER_OF_EVENTS = NULL;
void* __cdecl MY_GET_NUMBER_OF_EVENTS(NativeContext *cxt)
{
Hooking::onTickInit();
return cxt;
}
*/


template <typename T>
bool hook(uint64_t hash, void* hkFn, T** trampoline)
{
	void**	trFn = (void**)trampoline;
	if (*trFn != nullptr)
		return true;
	Hooking::NativeHandler orgFn = Hooking::GetNativeHandler(hash);
	if (orgFn == nullptr)
		return false;
	MH_STATUS status = MH_CreateHook(orgFn, hkFn, trFn);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(orgFn) != MH_OK)
		return false;
	Hooking::m_hookedNative.push_back((void*)orgFn);
	return true;
}

/*
BOOL(__cdecl *OG_GET_NUMBER_OF_EVENTS)(scrNativeCallContext* context) = nullptr;
BOOL __cdecl HK_GET_NUMBER_OF_EVENTS(NativeContext* cxt)
{
if (TryEnterCriticalSection(&Hooking::m_critSec))
{
static int    last = 0;
int            cur = GAMEPLAY::GET_FRAME_COUNT();
if (last != cur)
{
last = cur;
Hooking::onTickInit();
}
LeaveCriticalSection(&Hooking::m_critSec);
}
return OG_GET_NUMBER_OF_EVENTS(cxt);
}
*/










bool stealthTestohno = false;
#include "menuFeatures.h"
void stealthTextbs() {

	AddToggle("Stealth 15mil (test)", &stealthTestohno, "");

}
/*
fpshopBeginService  ORIG_NETWORK_SHOP_BEGIN_SERVICE = nullptr;
BOOL *__cdecl MY_NETWORK_SHOP_BEGIN_SERVICE(int* serviceIDOut, Any p1, Any p2, Any p3, int amount, int p5)
{
	static uint64_t	last = 0;
	uint64_t		cur = ORIG_NETWORK_SHOP_BEGIN_SERVICE(serviceIDOut, p1, p2, p3, amount, p5);
	//Player player = cxt->GetArgument<int>(0);
	if (last != cur)
	{
		last = cur;
		if (stealthTestohno == true) {
			//	int transactionCode = 393059668;
			int transactionCode = -1586170317;// 15 M $
											  //int transactionCode = 1982688246; // 90 M $
			int cash_to_receive = 15000000;
			bool toBank = true;
			int transactionID = 1146239992;

			if (ORIG_NETWORK_SHOP_BEGIN_SERVICE(&transactionID, 1474183246, transactionCode, 1445302971, cash_to_receive, toBank ? 4 : 1));
			void dildocashdrop();
			UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);

		}
		// could i run the code for the stealth here? i wonder

		ORIG_NETWORK_SHOP_BEGIN_SERVICE(serviceIDOut, p1, p2, p3, amount, p5);
	}
	return nullptr;
}
*/
Hooking::NativeHandler ORIG_WAIT = NULL;
void* __cdecl MY_WAIT(NativeContext *cxt)
{
	ScriptThread* pThread = GetActiveThread();

	if (pThread->m_ctx.ScriptHash == 0x5700179c)
	{
		if (pThread->m_ctx.State == ThreadStateRunning)
		{
			Hooking::onTickInit();
		}
	}

	ORIG_WAIT(cxt);
	return cxt;
}

fpIsEntityDead	OG_IS_ENTITY_DEAD = nullptr;
BOOL __cdecl HK_IS_ENTITY_DEAD(Entity entity)
{
	static uint64_t	last = 0;
	uint64_t		cur = GAMEPLAY::GET_FRAME_COUNT();
	if (last != cur)
	{
		last = cur;
		Hooking::onTickInit();
	}
	return OG_IS_ENTITY_DEAD(entity);
}
template <typename T>
void	setPat
(
	const char*	name,
	char*		pat,
	char*		mask,
	T**			out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr)
			failPat(name);

		if (deref <= 0)
			break;
		ptr = *(T**)ptr;
		--deref;
	}

	*out = ptr;
	return;
}
template <typename T>
bool Patternhook(LPVOID hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = hash;
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			DEBUGMSG("Hooked Native 0x%#p", hash);
			return true;
		}
	}

	return false;
}
//48 8D 64 24 ? 48 8B 5C 24 ? 48 8D 64 24 ? FF 64 24 F8  is entity dead
LPVOID TrampolineEntityDead;
bool  is_entity_dead(Entity entity)
{
	static uint64_t	last = 0;
	uint64_t		cur = GAMEPLAY::GET_FRAME_COUNT();
	if (last != cur)
	{
		last = cur;
		Log::Msg("on tick hooked");

		Hooking::onTickInit();
	}
	return reinterpret_cast<decltype(&is_entity_dead)>(TrampolineEntityDead)(entity);
}
/*
wait	ORIG_WAIT = nullptr;
BOOL __cdecl MY_WAIT(int ms)
{
	static uint64_t	last = 0;
	uint64_t		cur = GAMEPLAY::GET_FRAME_COUNT();
	if (last != cur)
	{
		last = cur;
		Hooking::onTickInit();
	}
	return ORIG_WAIT(ms);
}*/
bool Hooking::HookNatives()
{
	return true
		// native hooks	
		&& Native(0x4EDE34FBADD967A6, &MY_WAIT, &ORIG_WAIT);
	/*
	return true
		// native hooks	
		&& Patternhook(pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 50 45 8B F1").count(1).get(0).get<void>(0), &MY_WAIT, &ORIG_WAIT)
		;

	*/

	//if bellow doesnt work check reliency's post on uc



	// didn't work. Errpr 7? idk
/*	Function(pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 50 45 8B F1").count(1).get(0).get<void>(0),
		(void *)&is_entity_dead, &TrampolineEntityDead, "NetworkShopBeginService");

	*/
		/*
	MH_STATUS status = MH_CreateHook(Hooking::wait_test, MY_WAIT, (void**)&ORIG_WAIT);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::wait_test) != MH_OK)
		return false;
	Hooking::m_hookedNative.push_back(Hooking::wait_test);
	Log::Msg("hooked natives");
	*/


	/*
MH_STATUS status = MH_CreateHook(Hooking::is_entity_dead, HK_IS_ENTITY_DEAD, (void**)&OG_IS_ENTITY_DEAD);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_entity_dead) != MH_OK)
		return false;
	Hooking::m_hookedNative.push_back(Hooking::is_entity_dead);
	Log::Msg("hooked natives");*/
//	return true;    // un comment for sig hook!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	//return false;
//	return true;

	/*
		// native hooks	
		MH_STATUS status2 = MH_CreateHook(Hooking::shop_begin_service, MY_NETWORK_SHOP_BEGIN_SERVICE, (void**)&ORIG_NETWORK_SHOP_BEGIN_SERVICE);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::shop_begin_service) != MH_OK)
		return false;
	Hooking::m_hookedNative.push_back(Hooking::shop_begin_service);  //48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 50 45 8B F1
  //  && Native(0x39BE7CEA8D9CC8E6, &MY_NETWORK_SHOP_CHECKOUT_START, &ORIG_NETWORK_SHOP_CHECKOUT_START);  NOT NEEDED
	 Log::Msg("hooked Stealth Bullshit");
	 */

	//	&& Native(0x5F92A689A06620AA, &MY_GET_NUMBER_OF_EVENTS, &ORIG_GET_NUMBER_OF_EVENTS);
	//		&& hook(0x5F92A689A06620AA, &HK_GET_NUMBER_OF_EVENTS, &OG_GET_NUMBER_OF_EVENTS); //LATEST NON SIG!!

	//	auto pWait = pattern("\x8B\x15\x00\x00\x00\x00\x65\x48\x8B\x04\x25\x00\x00\x00\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\x04\xD0\x49\x8B\x14\x00\x83\x7A\x10\x01");

}




/*
Hooking::NativeHandler ORIG_GET_FRAME_COUNT = NULL;
void* __cdecl MY_GET_FRAME_COUNT(NativeContext *cxt)
{
Hooking::onTickInit();
return cxt;
}
Hooking::NativeHandler ORIG_APP_HAS_LINKED_SOCIAL_CLUB_ACCOUNT = NULL;
void* __cdecl MY_APP_HAS_LINKED_SOCIAL_CLUB_ACCOUNT(NativeContext *cxt)
{
Hooking::onTickInit();
return cxt;
}

bool Hooking::HookNatives()
{
return true
// native hooks
//&& Native(0x2F8B4D1C595B11DB, &MY_GET_FRAME_COUNT, &ORIG_GET_FRAME_COUNT);
&& Native(0x71EEE69745088DA0, &MY_APP_HAS_LINKED_SOCIAL_CLUB_ACCOUNT, &ORIG_APP_HAS_LINKED_SOCIAL_CLUB_ACCOUNT);

auto pWait = pattern("\x8B\x15\x00\x00\x00\x00\x65\x48\x8B\x04\x25\x00\x00\x00\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\x04\xD0\x49\x8B\x14\x00\x83\x7A\x10\x01");

}
*/
void __stdcall ScriptFunction(LPVOID lpParameter)
{

	if (Script::isInit())
	{
		try
		{
			while (1)
			{
				Script::onTick();
				SwitchToFiber(mainFiber);
			}
		}
		catch (...)
		{
			Log::Fatal("Failed scriptFiber");
		}
	}
	else
	{
		Log::Fatal("Script::isInit");
	}
}

void Hooking::onTickInit()
{
	if (mainFiber == nullptr)
		mainFiber = ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}

/* Pattern Scanning */

void Hooking::FailPatterns(const char* name, pattern ptn)
{
	Log::Error("finding %s", name);
	Cleanup();
}

void	failPat(const char* name)
{
	Log::Msg("Failed to find %s pattern. Game should be killed here but im to lazy to fix the CleanUp error lol", name);
	//Cleanup();
}

template <typename T>
void	setFn
(
	const char*	name,
	char*		pat,
	char*		mask,
	T*			out,
	int			skip = 0
)
{
	char*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);

	*out = (T)ptr;
	return;
}




void Hooking::FindPatterns()
{
	char*	ptr = nullptr;

	auto p_fixVector3Result = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	auto p_gameState = pattern("83 3D ? ? ? ? ? 8A D9 74 0A");
	auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	auto p_nativeTable = pattern("76 61 49 8B 7A 40 48 8D 0D");
	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");
	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");
	auto p_modelCheck = pattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");
	auto p_modelSpawn = pattern("48 8B C8 FF 52 30 84 C0 74 05 48");
	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03");
	auto p_activeThread = pattern("E8 ? ? ? ? 48 8B 88 10 01 00 00");


	char * c_location = nullptr;

	// Executable Base Address
	DEBUGMSG("baseAddr\t\t 0x%p", get_base());

	// Executable End Address
	DEBUGMSG("endAddr\t\t 0x%p", get_base() + get_size());

	// Get game state
	c_location = p_gameState.count(1).get(0).get<char>(2);
	while (c_location == nullptr) Sleep(60);
	c_location == nullptr ? FailPatterns("gameState", p_gameState) : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	// Get Active Script Thread
	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Trhead", p_activeThread) : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);

	// Skip game logos
	//	Memory::putVP<uint8_t>(p_gameLogos.count(1).get(0).get<void>(0), 0xC3);

	// Wait for legals
	//	DWORD ticks = GetTickCount();
	//	while (*m_gameState != GameStateLicenseShit || GetTickCount() < ticks + 5000) Sleep(50);

	// Skip game legals
	//	Memory::nop(p_gameLegals.count(1).get(0).get<void>(0), 2);

	// Get vector3 result fixer function
	auto void_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (void_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(void_location);

	// Get native registration table
	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration Table", p_nativeTable) : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);

	// Get world pointer
	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer", p_worldPtr) : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;

	// Get blip list
	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List", p_blipList) : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);

	// Bypass online model requests block
	Memory::nop(p_modelCheck.count(1).get(0).get<void>(0), 24);

	// Bypass is player model allowed to spawn checks
	Memory::nop(p_modelSpawn.count(1).get(0).get<void>(8), 2);

	DEBUGMSG("Initializing natives");
	CrossMapping::initNativeMap();

	// Check if game is ready
	Log::Msg("Checking if game is ready...");
	while (!*m_gameState == GameStatePlaying || !ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID())) {
		Sleep(100);
	}


	setFn<fpIsEntityDead>("is_entity_dead",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xFA\xE8\x00\x00\x00\x00\x33\xDB",
		"xxxx?xxxx?xxxxxxxxx????xx",
		&Hooking::is_entity_dead);

	setFn<fpshopBeginService>("shop_begin_service", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 50 45 8B F1", "",&Hooking::shop_begin_service);


	//network_shop_begin_service
/*	setFn<fpshopBeginService>("network_shop_begin_service",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x50\x45\x8B\xF1",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxx",
		&Hooking::shop_begin_service);
	*/


	setFn<fpNetworkShopBeginService>("network_shop_begin_service",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x50\x45\x8B\xF1",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxx",
		&Hooking::network_shop_begin_service);




	Log::Msg("Getting Event Hook...");
	constexpr char	pattern_event[] = "\x4C\x8D\x05";

	CPattern pattern_eventHook("\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\x4C\x8D\x0D\x00\x00\x00\x00\x4C\x8D\x05\x00\x00\x00\x00\xBA\x03",
		"xxxxx????xxx????xxx????xxx????xx");
	ptr = pattern_eventHook.find(0).get(0).get<char>(0);
	if (ptr == nullptr)
		Log::Error("Failed to find event hook pattern");

	//find events
	for (uint32_t i = 0, match = 0, found = 0; found < REVENT_END; ++ptr)
	{
		if (*ptr != pattern_event[i])
			goto LABEL_RESET;

		if (++match < 3)
		{
			++i;
			continue;
		}

		++ptr;
		g_eventPtr[found] = (void*)(ptr + *(int32_t*)ptr + 4);
		++found;

	LABEL_RESET:
		i = match = 0;
	}











	/*
	if ((c_location = p_eventHook.count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		while (found != EVENT_COUNT)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}
	*/
	// fpshopBeginService = pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 50 45 8B F1");

	Log::Msg("Game ready");
}

static Hooking::NativeHandler _Handler(uint64_t origHash) {

	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0) {
		return nullptr;
	}

	Hooking::NativeRegistration * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->nextRegistration)
	{
		for (uint32_t i = 0; i < table->numEntries; i++)
		{
			if (newHash == table->hashes[i])
			{
				return table->handlers[i];
			}

		}
	}

	return nullptr;
}

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

BlipList* Hooking::GetBlipList()
{
	return m_blipList;
}
uint64_t Hooking::getWorldPtr()
{
	return m_worldPtr;
}
__int64** Hooking::getGlobalPtr()
{
	return m_globalPtr;
}
void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}

static std::vector<void*> EventPtr;
static char EventRestore[REVENT_END] = {};

void patchEvent(eRockstarEvent e, bool b) {
	if (EventPtr.size() == 0) return;
	static const BYTE ret = 0xC3;
	BYTE* ptr = (BYTE*)EventPtr[e];
	if (b) {
		if (EventRestore[e] == 0) EventRestore[e] = ptr[0];
		*ptr = ret;
	}
	else if (EventRestore[e] != 0) *ptr = EventRestore[e];
}

//void moneyBypass(bool toggle) {
//	patchEvent(REVENT_REQUEST_PICKUP_EVENT, toggle);
//}

/* Clean Up */
void Hooking::Cleanup()
{
	Log::Msg("CleanUp: Gradient BETA");

	for (int i = 0; i < m_hookedNative.size(); i++)
		if (MH_DisableHook(m_hookedNative[i]) != MH_OK && MH_RemoveHook(m_hookedNative[i]) != MH_OK)
			Log::Msg("Failed to unhook %p", (void*)m_hookedNative[i]);


	DeleteCriticalSection(&m_critSec);
	iHook.keyboardHandlerUnregister(OnKeyboardMessage);
	iHook.Remove();
	MH_Uninitialize();
	FreeLibraryAndExitThread(_hmoduleDLL, 0);
}