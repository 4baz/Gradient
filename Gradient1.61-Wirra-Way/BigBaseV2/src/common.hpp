#pragma once

#include <SDKDDKVer.h>
#include <Windows.h>
#include <D3D11.h>
#include <wrl/client.h>

#include <cinttypes>
#include <cstddef>
#include <cstdint>

#include <chrono>
#include <ctime>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <atomic>
#include <mutex>
#include <thread>

#include <memory>
#include <new>

#include <sstream>
#include <string>
#include <string_view>

#include <algorithm>
#include <functional>
#include <utility>

#include <stack>
#include <vector>

#include <typeinfo>
#include <type_traits>

#include <exception>
#include <stdexcept>

#include <any>
#include <optional>
#include <variant>

#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <nlohmann/json.hpp>

#include "logger.hpp"

#include "core/globals.hpp"
#include "gta/natives.hpp"
#include "CPed.hpp"

#include "services/notifications/notification_service.hpp"

namespace big
{
	using namespace std::chrono_literals;
	
	template <typename T>
	using comptr = Microsoft::WRL::ComPtr<T>;

	inline HMODULE g_hmodule{};
	inline HANDLE g_main_thread{};
	inline DWORD g_main_thread_id{};
	inline std::atomic_bool g_running{ false };

	inline CPed* g_local_player;
}

namespace self
{
	inline Ped ped;
	inline Player id;
	inline Vector3 pos;
	inline Vehicle veh;
}

struct RGBA {
public:
	int R;
	int G;
	int B;
	int A;
};


namespace SUB {

	enum {
		CLOSED,
		MAINMENU,
		SETTINGS,
		HEADER,
		OPTIONS,
		CREDITS,
		DEVOPTIONS,
		PLAYER,
		WEAPONS,
		TELEPORTS,
		PTFX,
		ANIMATIONS,

		VEHICLE,
		VEHSPAWNER,
		VEH_CAYOPERICHO,
		VEH_SummerUpdate,
		VEH_CasinoHeist,
		VEH_CasinoUpdate,
		VEH_ArenaWar,
		VEH_Vans,
		VEH_Utility,
		VEH_TRAINS,
		VEH_trailers,
		VEH_Super,
		VEH_SportsClassic,
		VEH_SPORTS,
		VEH_Boats,
		VEH_Commercials,
		VEH_compacts,
		VEH_Coupes,
		VEH_BIKES,
		VEH_Emergency,
		VEH_Helicopters,
		VEH_industraial,
		VEH_Military,
		VEH_MOTOCYCLE,
		VEH_Muscle,
		VEH_Offroad,
		VEH_Planes,
		VEH_Suvs,
		VEH_Sedans,
		VEH_Service,
		VEH_CRIMINALENTPRISE,

		LSC,
	//	VEH_DOOMSDAY,

		ONLINE_OPTIONS,
		PLAYERLIST,
		SELPLAYER,
		OBJECTS,
		LOBBY,
		ESP_SETTINGS,
		RECOVERY,
		RANK,
		PROTECTIONS,

	};
};
