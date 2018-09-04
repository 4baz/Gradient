#pragma once

//void moneyBypass(bool toggle);

typedef bool(__cdecl*	fpIsEntityDead)(Entity entity);

class Hooking
{
public:
	
	static fpIsEntityDead						is_entity_dead;

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
