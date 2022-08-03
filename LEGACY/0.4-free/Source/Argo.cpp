#include"stdafx.h"
#include "Argo.h"
#include "force.h"
#include "data.h"
#include "shellapi.h"

 char * Version = "Beta: 0.4.3";

bool firstload = true;
Hash* testhash;
LPCWSTR menuStyleLocation = L".\\GradientFree\\MenuConfig.ini";
int timer, wantedLevel;

bool neverwanted = false;
bool superrun = false;
bool Invincible = false;
bool RagDoll = false;
bool superswim = false;
bool hornboost = false;
bool featurePlayerSuperJump = false,
featureWeaponNoReload = false,
neverwantedbool = false,
featureVisionThermal = false,
featureVisionNight = false,
featureWeaponFireAmmo = false,
featureWeaponExplosiveAmmo = false,
featureWeaponExplosiveMelee = false,
featureWeaponOneHit = false,
featureWeaponRainbowTint = false,
WeatherWind = false,
track = false,
invisibe = false,
rpLoop = false,
dildodrop[32];


void Update();
void Changemodel(Hash Model);
bool Dead = false;

bool freecambool = false;
void freecam();

bool check = false;


bool doesBashDirExist()
{
	DWORD dwAttrib = GetFileAttributesA(".\\GradientFree");

	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}
bool doesFavDirExist()
{
	DWORD dwAttrib = GetFileAttributesA(".\\GradientFree\\favcars");

	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

Ped getPed(Player player) {
	int netHandle[13];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, netHandle, 13);
	Ped ped = NETWORK::NET_TO_PED(*netHandle);
	return ped;
}

template <size_t Len>
Hash joaat(const char(&string)[Len])
{
	size_t i = 0;
	uint32_t hash = 0;
	while (i != Len) {
		hash += string[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return hash;
}


void GradientFree()
{/*
	auto create_transaction_begin_service = [=](unsigned int *shop_thing, unsigned int a2, unsigned int a3, unsigned int amount, int a5) {
		static t_transaction oGET_PLAYER_PED = (t_transaction)(Memory::pattern("40 53 48 83 EC 20 33 DB 83 F9 FF 74 09 B2 01 E8 ? ? ? ? EB").count(1).get(0).get<void>(0));
		return oGET_PLAYER_PED(shop_thing, a2, a3, amount, a5);
	};
	*/
	if (firstload)
	{
#ifdef BUILD
		IconNotification(Menu::StringToChar("~y~Welcom~w~" + (std::string)PLAYER::GET_PLAYER_NAME(0)), "Menu Design", Menu::StringToChar(UNK3::_GET_ONLINE_VERSION()));
#else
		//IconNotification(Menu::StringToChar("~y~Welcom~w~" + (std::string)PLAYER::GET_PLAYER_NAME(0)), "Pulse Design", Menu::StringToChar(UNK3::_GET_ONLINE_VERSION()));
#endif // DEBUG
		firstload = false;
	}

	Menu::checkKeys();
#ifdef BUILD


#else
	if (Menu::currentMenu("mainmenu"))
	{
		Menu::Title("Gradient Free");
		
		Menu::MenuOption("Player Options", "player");
		Menu::MenuOption("Weapon Options", "weapon");
		Menu::MenuOption("Teleport Options", "teleport");
		Menu::MenuOption("Vehicle Options", "Vehicle");
		
		Menu::MenuOption("Online Options", "online");
		Menu::MenuOption("Settings", "settings");
		Menu::MenuOption("Credits", "credits");
	//	Menu::MenuOption("weather Options", "weather");
		//Menu::MenuOption("Force", "force");
		//Menu::MenuOption("PTFX", "PTFX");
		//Menu::MenuOption("vision", "vision");
		//Menu::MenuOption("Scenarios", "Scenarios");
	//	if (Menu::IntOption("Lock time", &timer, 0, 23, 1))NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(timer, 0, 0);
	}

	if (Menu::currentMenu("credits")) {
		Menu::Title("Credits");
		Menu::Option("Made by Sinfool#2522");
		Menu::Option("Buy premium by pressing the link below");
		if (Menu::Option("http://gradienthacks.com/")) { ShellExecute(NULL, L"open", L"http://gradienthacks.com/", NULL, NULL, SW_SHOWNORMAL); }
		Menu::Option("Free Version based on bgg base/pirate menu/argo skid");
	    Menu::Option("^^^But i re-wrote all the code^^^");
		Menu::Option(Version);
	}
	if (Menu::currentMenu("weapon"))
	{
		Menu::Title("Weapon");
		Menu::BoolOption("No Reload", &featureWeaponNoReload);
		Menu::BoolOption("Fire Ammo", &featureWeaponFireAmmo);
		Menu::BoolOption("Explosive Ammo", &featureWeaponExplosiveAmmo);
		Menu::BoolOption("Explosive Melee", &featureWeaponExplosiveMelee);
		if (Menu::Option("Give All Weapons")) {

			Ped ped = PLAYER::PLAYER_PED_ID();

			for each (Hash weaponlist in weaponlist) {
				if (WEAPON::HAS_PED_GOT_WEAPON(ped, weaponlist, FALSE) == FALSE)
				{
					WEAPON::GIVE_WEAPON_TO_PED(ped, weaponlist, 9999, FALSE, TRUE);
					WEAPON::SET_PED_WEAPON_TINT_INDEX(ped, weaponlist, WeaponTintGold);
				}
			}

		}
	//	Menu::BoolOption("One Hit Kill", &featureWeaponOneHit);
	//	Menu::BoolOption("Rainbow Camo", &featureWeaponRainbowTint);
		//Menu::MenuOption("WeaponSkin", "weaponskin");

	}

	//Online Option Group
	if (Menu::currentMenu("online"))
	{
		Menu::Title("online");
		Menu::MenuOption("Player List", "sp");
		Menu::MenuOption("RP Options", "RP");
	//	Menu::MenuOption("All Player", "ap");
	}
	if (Menu::currentMenu("RP"))
	{
		Menu::Title("Rp Options");
		Menu::RPOption("Rank 50", 448800);
		Menu::RPOption("Rank 100", 1584350);
		Menu::RPOption("Rank 150", 3075600);
		Menu::RPOption("Rank 200", 4691850);
	}
	if (Menu::currentMenu("ap"))
	{
		Menu::Title("allPlayer");
		Menu::MenuOption("ESP", "ESP_ALL");
	}
	if (Menu::currentMenu("sp"))
	{
		Menu::Title("Player");
		for (int i = 0; i < 32; ++i) {
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED(i))) {
				if (Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), "OnlinePlayer"))
				{
					selectedplayer = i;
				}
			}
		}
	//	Menu::PlayerMenu();
	}
	if (Menu::currentMenu("OnlinePlayer"))
	{
		Menu::Title(PLAYER::GET_PLAYER_NAME(selectedplayer));
		Menu::BoolOption("2k drop", &dildodrop[selectedplayer]);
	
	}
	


	//Vehicle Option Group
	if (Menu::currentMenu("Vehicle"))
	{
		Menu::Title("Vehicle Menu");
		Menu::MenuOption("Spawn", "Spawn");
		if (Menu::BoolOption("God Mode", &VehicleOptions::godmodebool)) VehicleOptions::godmode();
	//	if (Menu::BoolOption("Fix Loop", &VehicleOptions::vehiclefixloopbool)) VehicleOptions::vehiclefixloop();
		if (Menu::Option("Fix Vehicle", "Good as new!")) VehicleOptions::fix();
		if (Menu::Option("Max Vehicle", "Oh baby!")) VehicleOptions::maxvehicle();
	//	if (Menu::BoolOption("No Tire Burst", &VehicleOptions::bulletprooftiresbool)) VehicleOptions::bulletprooftires();
	//	if (Menu::BoolOption("Speedo", &VehicleOptions::speedobool)) VehicleOptions::speedo();
	//	if (Menu::BoolOption("Engine Always On",& VehicleOptions::enginealwaysonbool)) VehicleOptions::enginealwayson();
		Menu::BoolOption("Horn Boost", &hornboost);

	//	if (Menu::Option("Flip Upright", "Dad Flip Me ;)")) VehicleOptions::flip();
	}
	if (Menu::currentMenu("Spawn"))
	{
		Menu::Title("Spawner");
		Menu::MenuOption("Vehicle Settings", "vehsetting");
		//if (Menu::Option("Custom Model")){
		Menu::MenuOption("Smugglers Run", "smug_run");
		Menu::MenuOption("Super", "Super");
		Menu::MenuOption("Gunrunning", "Gunrunning");
		Menu::MenuOption("Sports", "Sports");
		Menu::MenuOption("Sport Classic", "Sport Classic");
		Menu::MenuOption("Offroad", "Offroad");
		Menu::MenuOption("Sedans", "Sedans");
		Menu::MenuOption("Coupes", "Coupes");
		Menu::MenuOption("Muscle", "Muscle");
		Menu::MenuOption("Boats", "Boats");
		Menu::MenuOption("Commercial", "Commercial");
		Menu::MenuOption("Compacts", "Compacts");
		Menu::MenuOption("Cycles", "Cycles");
		Menu::MenuOption("Emergency", "Emergency");
		Menu::MenuOption("Helicopters", "Helicopters");
		Menu::MenuOption("Industrial", "Industrial");
		Menu::MenuOption("Military", "Military");
		Menu::MenuOption("Motorcycles", "Motorcycles");
		Menu::MenuOption("Planes", "Planes");
		Menu::MenuOption("Service", "Service");
		Menu::MenuOption("SUV", "SUV");
		Menu::MenuOption("Trailer", "Trailer");
		Menu::MenuOption("Trains", "Trains");
		Menu::MenuOption("Utility", "Utility");
		Menu::MenuOption("Vans", "Vans");
	}

	if (Menu::currentMenu("smug_run")) {
		Menu::Title("Smugglers Run");
		for (auto id : smugglersRun)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}

	if (Menu::currentMenu("vehsetting"))
	{
		Menu::Title("Setting");
		Menu::BoolOption("Spawn In Car", &VehicleOptions::spawnincar);
		Menu::BoolOption("Spawn Maxed",&VehicleOptions::spawnmaxed);
	}
	if (Menu::currentMenu("Boats"))
	{
		Menu::Title("Boats");
		for (auto id : Boats)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Commercial"))
	{
		Menu::Title("Commercial");
		for (auto id : Commercial)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Compacts"))
	{
		Menu::Title("Compacts");
		for (auto id : Compacts)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Coupes"))
	{
		Menu::Title("Coupes");
		for (auto id : Coupes)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Cycles"))
	{
		Menu::Title("Cycles");
		for (auto id : Cycles)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}

	}
	if (Menu::currentMenu("Emergency"))
	{
		Menu::Title("Emergency");
		for (auto id : Emergency)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Helicopters"))
	{
		Menu::Title("Helicopters");
		for (auto id : Helicopters)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Industrial"))
	{
		Menu::Title("Industrial");
		for (auto id : Industrial)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Military"))
	{
		Menu::Title("Military");
		for (auto id : Military)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}

	}
	if (Menu::currentMenu("Motorcycles"))
	{
		Menu::Title("Motorcycles");
		for (auto id : Motorcycles)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Muscle"))
	{
		Menu::Title("Muscle");
		for (auto id : Muscle)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}

	}
	if (Menu::currentMenu("OffRoad"))
	{
		Menu::Title("OffRoad");
		for (auto id : OffRoad)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Planes"))
	{
		Menu::Title("Planes");
		for (auto id : Planes)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Sedans"))
	{
		Menu::Title("Sedans");
		for (auto id : Sedans)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Service"))
	{
		Menu::Title("Service");
		for (auto id : Service)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Sports"))
	{
		Menu::Title("Sports");
		for (auto id : Sports)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("SportsClassics"))
	{
		Menu::Title("SportsClassics");
		for (auto id : SportsClassics)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Super"))
	{
		Menu::Title("Super");
		for (auto id : Super)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("SUVs"))
	{
		Menu::Title("SUVs");
		for (auto id : SUVs)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Trailer"))
	{
		Menu::Title("Trailer");
		for (auto id : Trailer)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}

	}
	if (Menu::currentMenu("Trains"))
	{
		Menu::Title("Trains");
		for (auto id : Trains)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Utility"))
	{
		Menu::Title("Utility");
		for (auto id : Utility)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Vans"))
	{
		Menu::Title("Vans");
		for (auto id : Vans)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}
	if (Menu::currentMenu("Gunrunning"))
	{
		Menu::Title("Gunrunning");
		for (auto id : Gunrunning)
		{
			if (Menu::Option(id)) VehicleOptions::Spawn((std::string)id);
		}
	}


#endif // DEBUG
	if (Menu::currentMenu("teleport"))
	{
		Menu::Title("teleport");
		Menu::TeleportOption("0.0", 0.0f, 0.0f, 72.0f);
		Menu::TeleportOption("Micheal's House", -852.4f, 160.0f, 65.6f);
		Menu::TeleportOption("Franklin's House", 7.9f, 548.1f, 175.5f);
		Menu::TeleportOption("Trevor's Trailer", 1985.7f, 3812.2f, 32.2f);
		Menu::TeleportOption("Airport Enterance", -1034.6f, -2733.6f, 13.8f);
		Menu::TeleportOption("Aiport Field", -1336.0f, -3044.0f, 13.9f);
		Menu::TeleportOption("Elysian Island", 338.2f, -2715.9f, 38.5f);
		Menu::TeleportOption("Strip Club DJ Booth", 126.135F, -1278.583F, 29.270F);
		Menu::TeleportOption("Stripclub", 127.4f, -1307.7f, 29.2f);
		Menu::TeleportOption("Elburro Heights", 1384.0f, -2057.1f, 52.0f);
		Menu::TeleportOption("Ferris Wheel", -1670.7f, -1125.0f, 13.0f);
		Menu::TeleportOption("Chumash", -3192.6f, 1100.0f, 20.2f);
		Menu::TeleportOption("Windfarm", 2354.0f, 1830.3f, 101.1f);
		Menu::TeleportOption("Military Base", -2047.4f, 3132.1f, 32.8f);
		Menu::TeleportOption("Maze Bank", -75.015F, -818.215F, 326.176F);
		Menu::TeleportOption("Desert Airfield", 1747.0f, 3273.7f, 41.1f);
		Menu::TeleportOption("Chilliad", 425.4f, 5614.3f, 766.5f);
		Menu::TeleportOption("North Yankton", 3360.19f, -4849.67f, 111.8f);
		Menu::TeleportOption("Torture Warehouse", 136.514F, -2203.15F, 7.30914F);
		Menu::TeleportOption("Plane Crash", 2395.096F, 3049.616F, 60.053F);
	}

	

	if (Menu::currentMenu("player"))
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		//Menu::PlayerMenu();
		Menu::Title("Player Options");
		
		Menu::MenuOption("Wanted Editor", "wanted_editor");

		Menu::BoolOption("God Mode", &Invincible);
		Menu::BoolOption("Invisible Player", &invisibe);
		Menu::BoolOption("Fast Run", &superrun);
		Menu::BoolOption("fast Swim", &superswim);
	}
	if (Menu::currentMenu("wanted_editor")) {
		Menu::Title("Wanted Editor");
		Menu::BoolOption("Never Wanted", &neverwantedbool);



		if (Menu::Option("Wanted up")) {
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();

			//			if (!PLAYER::IS_PLAYER_PLAYING(player)) return;

			if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) < 5)
			{
				PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, PLAYER::GET_PLAYER_WANTED_LEVEL(player) + 1, false);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);
			}
		}


		if (Menu::Option("Wanted down")) {
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();

			//		if (!PLAYER::IS_PLAYER_PLAYING(player)) return;

			if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) > 0)
			{
				PLAYER::CLEAR_PLAYER_WANTED_LEVEL(player);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, PLAYER::GET_PLAYER_WANTED_LEVEL(player) - 1, false);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);
			}
          }




	}


	/*
	if (Menu::currentMenu("weaponskin"))
	{
		Hash WeapHash;
		Menu::Title("weaponskin");
		for (int i = 0; i<8; i++)
		{
			if (Menu::Option(Weaponskin_Hash[i]))
			{
				WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(PLAYER::PLAYER_PED_ID(), WeapHash, i);
			}
		}

	}
	*/


	///==================Setting Options=========================================
/*	if (Menu::currentMenu("settings")) {
		Menu::Title("Settings Menu");
		Menu::MenuOption("Theme", "settings_theme");
	}*/
	if (Menu::currentMenu("settings")) { // normally theme menu
		Menu::Title("Settings Menu");

		Menu::MenuOption("Title Text", "settings_theme_titletext");
		Menu::MenuOption("Title Rect", "settings_theme_titlerect");
		Menu::MenuOption("Scroller", "settings_theme_scroller");
		Menu::MenuOption("Options Text", "settings_theme_options");
		Menu::MenuOption("Options Rect", "settings_theme_optionsrect");
		Menu::FloatOption("Menu X: ", &menux, 0, 255);

		if (Menu::Option("Save Theme")) Menu::SaveMenuTheme(menuStyleLocation);
		if (Menu::Option("Load Theme")) Menu::LoadMenuTheme(menuStyleLocation);
		if (Menu::Option("Revert To Default")) {
			titleText = { 0, 0, 0, 255 };
			titleRect = { 255, 200, 0, 255 };
			scroller = { 80, 80, 80, 200 };
			options = { 0, 0, 0, 255 };
			optionsrect = { 255, 220, 30, 60 };
		}
	}
	if (Menu::currentMenu("settings_theme_titletext")) {
		Menu::Title("Title Text");

		Menu::IntOption("Red: ", &titleText.r, 0, 255);
		Menu::IntOption("Green: ", &titleText.g, 0, 255);
		Menu::IntOption("Blue: ", &titleText.b, 0, 255);
		Menu::IntOption("Alpha: ", &titleText.a, 0, 255);
	}
	if (Menu::currentMenu("settings_theme_titlerect")) {
		Menu::Title("Title Rect");

		Menu::IntOption("Red: ", &titleRect.r, 0, 255);
		Menu::IntOption("Green: ", &titleRect.g, 0, 255);
		Menu::IntOption("Blue: ", &titleRect.b, 0, 255);
		Menu::IntOption("Alpha: ", &titleRect.a, 0, 255);
	}
	if (Menu::currentMenu("settings_theme_scroller")) {
		Menu::Title("Scroller");

		Menu::IntOption("Red: ", &scroller.r, 0, 255);
		Menu::IntOption("Green: ", &scroller.g, 0, 255);
		Menu::IntOption("Blue: ", &scroller.b, 0, 255);
		Menu::IntOption("Alpha: ", &scroller.a, 0, 255);
	}
	if (Menu::currentMenu("settings_theme_options")) {
		Menu::Title("Options Text");

		Menu::IntOption("Red: ", &options.r, 0, 255);
		Menu::IntOption("Green: ", &options.g, 0, 255);
		Menu::IntOption("Blue: ", &options.b, 0, 255);
		Menu::IntOption("Alpha: ", &options.a, 0, 255);
	}
	if (Menu::currentMenu("settings_theme_optionsrect")) {
		Menu::Title("Options Rect");

		Menu::IntOption("Red: ", &optionsrect.r, 0, 255);
		Menu::IntOption("Green: ", &optionsrect.g, 0, 255);
		Menu::IntOption("Blue: ", &optionsrect.b, 0, 255);
		Menu::IntOption("Alpha: ", &optionsrect.a, 0, 255);
	}
	///==================End Setting Options=========================================


	Update();
	Menu::endMenu();
}



void Update()
{
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID());
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	short rplooptimer = 0;
	Vector3 pos = { 1500.0f,1500.0f,1500.0f };


	if (hornboost == true) {

		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		if (AUDIO::IS_HORN_ACTIVE(veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 50.f);
		}

	}
	
	if (Invincible == false)
	{
	//	ENTITY::SET_ENTITY_INVINCIBLE(player, true);
		ENTITY::SET_ENTITY_INVINCIBLE(playerPed, false);

	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(playerPed, true);
	}

	if (featureWeaponNoReload) {
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), 1);

	}
	if (featureWeaponFireAmmo)
	{
		if (bPlayerExists)
			GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(player);
	}

	if (featureWeaponExplosiveAmmo)
	{
		if (bPlayerExists)
			GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(player);
	}

	if (featureWeaponExplosiveMelee)
	{
		if (bPlayerExists)
			GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(player);
	}
	if (neverwantedbool) {
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), 1);
		PLAYER::SET_MAX_WANTED_LEVEL(0);
	}
	else
	{
		//	PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), false);
		PLAYER::SET_MAX_WANTED_LEVEL(5);
	}
	if (invisibe) {
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, false);

	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);

	}
	if (superrun) {
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 2.0f);

	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1.0f);

	}
	if (superswim) {
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 2.0f);

	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 1.0f);

	}
	int TimePD1;


		for (int i = 0; i < 30; i++)
		{
			bool validPlayer = NETWORK::NETWORK_IS_PLAYER_CONNECTED(i);


			if (dildodrop[i]) {
				if (!validPlayer) dildodrop[i] = false;
				else
				{
					Ped iPed = PLAYER::GET_PLAYER_PED(i);

					if ((timeGetTime() - TimePD1) > 4000) // Time between drops
					{
						void CashDrop(int pedHandle, char* CashModel, int Value);

						{
							//(PLAYER::PLAYER_PED_ID(selectedPlayer))
							Vector3 coords = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
							int CashHash = -422877666; // prop_cs_dildo
													   //	int CashHash = -1803909274;  // prop_paper_bag_small = -1803909274
							int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
							STREAMING::REQUEST_MODEL(CashHash);
							while (!STREAMING::HAS_MODEL_LOADED(CashHash)) WAIT(0);
							OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, coords.x, coords.y, coords.z, 0, 2000, CashHash, false, true);
							STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(CashHash);
						}

					}
				}
			}





		}
	


}

