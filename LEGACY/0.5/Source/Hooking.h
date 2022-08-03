#pragma once
enum eThreadState
{
	ThreadStateIdle = 0x0,
	ThreadStateRunning = 0x1,
	ThreadStateKilled = 0x2,
	ThreadState3 = 0x3,
	ThreadState4 = 0x4,
};

struct scrThreadContext
{
	int ThreadID;
	int ScriptHash;
	eThreadState State;
	int _IP;
	int FrameSP;
	int _SPP;
	float TimerA;
	float TimerB;
	int TimerC;
	int _mUnk1;
	int _mUnk2;
	int _f2C;
	int _f30;
	int _f34;
	int _f38;
	int _f3C;
	int _f40;
	int _f44;
	int _f48;
	int _f4C;
	int _f50;
	int pad1;
	int pad2;
	int pad3;
	int _set1;
	int pad[17];
};

struct scrThread
{
	void *vTable;
	scrThreadContext m_ctx;
	void *m_pStack;
	void *pad;
	void *pad2;
	const char *m_pszExitMessage;
};

struct ScriptThread : scrThread
{
	char Name[64];
	void *m_pScriptHandler;
	char gta_pad2[40];
	char flag1;
	char m_networkFlag;
	bool bool1;
	bool bool2;
	bool bool3;
	bool bool4;
	bool bool5;
	bool bool6;
	bool bool7;
	bool bool8;
	bool bool9;
	bool bool10;
	bool bool11;
	bool bool12;
	char gta_pad3[10];
};
//void moneyBypass(bool toggle);
void stealthTextbs();
typedef bool(__cdecl*	fpIsEntityDead)(Entity entity);
typedef bool(__cdecl*    fpshopBeginService)(int* serviceIDOut, int p1, int p2, int p3, int amount, int p5);
typedef BOOL(__cdecl*	fpNetworkShopBeginService)(int* transID, int p1, int p2, int p3, int p4, int p5);
typedef BOOL(__cdecl*	wait)(int ms);


class Hooking
{
public:
	static __int64** getGlobalPtr();

	static fpIsEntityDead						is_entity_dead;
	static fpshopBeginService                   shop_begin_service;
	static fpNetworkShopBeginService			network_shop_begin_service;
	static wait                                  wait_test;
	static std::vector<LPVOID>		m_hookedNative;
	static void Start(HMODULE hmoduleDLL);
	static void Cleanup();
	static eGameState GetGameState();
	static BlipList* GetBlipList();
	static uint64_t getWorldPtr();
	static void onTickInit();
	static bool HookNatives();
	static CRITICAL_SECTION			m_critSec;

	// Native function handler type
	typedef void(__cdecl * NativeHandler)(scrNativeCallContext * context);
	struct NativeRegistration
	{
		NativeRegistration * nextRegistration;
		Hooking::NativeHandler handlers[7];
		uint32_t numEntries;
		uint64_t hashes[7];
	};
	static NativeHandler GetNativeHandler(uint64_t origHash);

private:
	static BOOL InitializeHooks();
	static void FindPatterns();
	static void FailPatterns(const char* name, Memory::pattern ptn);
};	void WAIT(DWORD ms);




//from ya boi sudo IF YOU SEE THIS CASP3R TO NOT POST ANYWHERE. OR SUDO WILL HUNT ME DOWN LOL




template <typename T>
bool Function(LPVOID targetFunction, LPVOID hookFunction, T** trampoline, char *optDescription = 0)
{
	optDescription = optDescription ? optDescription : "anonymous";
	if (targetFunction == nullptr) {
		ERROR("Target was null (pattern not found?) while attempting to hook: %s", optDescription);
		return false;
	}

	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;

	MH_STATUS createHookStatus = MH_CreateHook(targetFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
	if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(targetFunction) == MH_OK))
	{
		Log::Msg("Hooked %s at %p", optDescription, targetFunction);
		return true;
	}
	Log::Msg("Error #%i while attempting to hook: %s", createHookStatus, optDescription);
	return false;
}

/*
LPVOID TrampolineNetworkShopBeginService;
bool  NetworkShopBeginService( int* serviceIDOut,  Any p1, Any p2, Any p3, int amount, int p5)
{
	return reinterpret_cast<decltype(&NetworkShopBeginService)>(TrampolineNetworkShopBeginService)(serviceIDOut, p1,  p2,  p3,  amount,  p5);
}
*/
//int* serviceIDOut, Any p1, Any p2, Any p3, int amount, int p5