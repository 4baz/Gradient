#include "stdafx.h"
//#include "stdafx.h"
#include "CrossMapping.h"
#include "script.h"
std::string statusText;
DWORD statusTextDrawTicksMax;
bool statusTextGxtEntry;
#include "stdafx.h"
#include "natives.h"
#include <Windows.h>
#include <Psapi.h>



//#include "CrossMapping.cpp"
namespace Features {
	void spawn_vehicle(char* toSpawn) {
		Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
		if (STREAMING::IS_MODEL_VALID(model))
		{
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
			Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			float forward = 5.f;
			float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
			float xVector = forward * sin(degToRad(heading)) * -1.f;
			float yVector = forward * cos(degToRad(heading));
			Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
			RequestControlOfEnt(veh);
			VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
			DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
			auto networkId = NETWORK::VEH_TO_NET(veh);
			ENTITY::_NETWORK_SET_ENTITY_AS_NETWORKED_ENTITY(veh, true);
			if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
				NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		//	if (Features::spawnincar)
		//	{
		//		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		//	}
		//	if (Features::spawnmaxed)
		//	{
		//		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		//		for (int i = 0; i < 50; i++)
		//		{
		//			VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
		//		}
			}
			WAIT(150);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
		}
	}

static char* Boats1[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};
static char* Commercial1[] = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3"
};
static char* Compacts1[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
};
static char* Coupes1[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
};
static char* Cycles1[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};
static char* Emergency1[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
};
static char* Helicopters1[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
};
static char* Industrial1[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};
static char* Military1[] = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
};
static char* Motorcycles1[] = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2"
};
static char* Muscle1[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
};
static char* OffRoad1[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
	"BLAZER5"
};
static char* Planes1[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
};
static char* Sedans1[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
};
static char* Service1[] = {
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
	"WASTELANDER",
};
static char* Sports1[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUINER2", "PHANTOM2", "RUSTON"
};
static char* SportsClassics1[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "INFERNUS2", "TURISMO2",
};
static char* Super1[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1"
};
static char* Gunrunning1[] = {
	"APC", "Ardent", "Caddy3", "Cheetah2", "Dune3", "Halftrack", "Hauler2", "Insurgent3",
	"Nightshark", "Oppressor", "Phantom3", "Tampa3", "Technical13", "Torero", "TrailerLarge",
	"Trailers4", "Trailersma11", "Vagner", "Xa21"
};
static char* SUVs1[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
};
static char* Trailer1[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
};
static char* Trains1[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};
static char* Utility1[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
};
static char* Vans1[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};
static char* smugglers1[] = {
	"VIGILANTE", "BOMBUSHKA", "ALPHAZ1", "TULA", "HUNTER",
	"ROGUE", "PYRO", "MOGUL", "NOKOTA", "MOLOTOK", "SEABREEZE",
	"HAVOK", "microlight", "HOWARD", "STARLING", "RAPIDGT3",
	"RETINUE", "CYCLONE", "VISIONE"
};



// onlineplayerinfo is broken ish


struct OnlinePlayer
{
	int playerId;
	bool toggleEsp;
	bool enablePlayerInfo;
	bool badsport;
	bool advCashDrop;
	bool stealMoney;
	bool disableTasks;
	bool moneyGun;
	bool teleportGun;
};
OnlinePlayer OnlinePlayers[32];

#pragma comment(lib, "Psapi.lib")

// FOR DEFINING NATIVES WITH THERE STRINGS ///////////////////////////////////////////////////////////////

//typedef int(__fasctall* tGET_PLAYER_PED)(Player player);
//int GET_PLAYER_PED(Player player) { static tGET_PLAYER_PED oGET_PLAYER_PED = (tGET_PLAYER_PED)(Memory::pattern("pat here").count(1).get(0).get<void>()); return oGET_PLAYER_PED(player); }

////////////////////////////////////////////////////////////////////////////////////////////

typedef Ped(__fastcall* tGET_PLAYER_PED)(Player player);
static Ped GET_PLAYER_PED(Player player) { static tGET_PLAYER_PED oGET_PLAYER_PED = (tGET_PLAYER_PED)(Memory::pattern("40 53 48 83 EC 20 33 DB 83 F9 FF 74 09 B2 01 E8 ? ? ? ? EB 16").count(1).get(0).get<void>()); return oGET_PLAYER_PED(player); }

typedef char*(__fastcall* tGET_PLAYER_NAME)(Player player);
static char* GET_PLAYER_NAME(Player player) { static tGET_PLAYER_NAME oGET_PLAYER_NAME = (tGET_PLAYER_NAME)(Memory::pattern("40 53 48 83 EC 20 80 3D ? ? ? ? ? 8B D9 74 22").count(1).get(0).get<void>()); return oGET_PLAYER_NAME(player); }

typedef float(__fastcall* tGET_ENTITY_HEADING)(Entity entity); //PROBS BROKEN/WRONG SIG
static float GET_ENTITY_HEADING(Entity entity) { static tGET_ENTITY_HEADING oGET_ENTITY_HEADING = (tGET_ENTITY_HEADING)(Memory::pattern("35 ? ? ? ? EF 92 92").count(1).get(0).get<void>()); return oGET_ENTITY_HEADING(entity); } //PROBS BROKEN/WRONG SIG

typedef Vector3(__fastcall* tGET_ENTITY_COORDS)(Entity entity, BOOL alive);
static Vector3 GET_ENTITY_COORDS(Entity entity, BOOL alive) { static tGET_ENTITY_COORDS oGET_ENTITY_COORDS = (tGET_ENTITY_COORDS)(Memory::pattern("40 53 48 83 EC 30 48 8B D9 8B CA E8 ? ? ? ? 0F 57 C0").count(1).get(0).get<void>()); return oGET_ENTITY_COORDS(entity, alive); }




// TEST SIGNATURES
//SET_TEXT_ENTRY | 48 8B 49 10 48 8B 09 48 89 6C 24 ? E9 ? ? ? ? 48 8D 64 24 ? 48 89 2C 24

//typedef void(__fastcall* t_SET_TEXT_ENTRY)(char* text);
//static void _SET_TEXT_ENTRY(char* text) { static t_SET_TEXT_ENTRY o_SET_TEXT_ENTRY = (t_SET_TEXT_ENTRY)(Memory::pattern("48 8B 49 10 48 8B 09 48 89 6C 24 ? E9 ? ? ? ? 48 8D 64 24 ? 48 89 2C 24").count(1).get(0).get<void>()); return o_SET_TEXT_ENTRY(text); }


//PLAYER_PED_ID | 48 89 E0 E9 ? ? ? ? 8B 85 ? ? ? ? 85 C0
//typedef Ped(__fastcall* tPLAYER_PED_ID)();
//static Ped PLAYER_PED_ID() { static tPLAYER_PED_ID oPLAYER_PED_ID = (tPLAYER_PED_ID)(Memory::pattern("48 89 E0 E9 ? ? ? ? 8B 85 ? ? ? ? 85 C0").count(1).get(0).get<void>()); return oPLAYER_PED_ID(); }

typedef void(__fastcall* t_DRAW_TEXT)(float x, float y); 
static void _DRAW_TEXT(float x, float y) { static t_DRAW_TEXT o_DRAW_TEXT = (t_DRAW_TEXT)(Memory::pattern("40 53 48 83 EC 40 0F 29 74 24 ? 0F 29 7C 24 ? 41 8B D8").count(1).get(0).get<void>()); return o_DRAW_TEXT(x, y); } //PROBS BROKEN/WRONG SIG



/*
Startup GTA V Faster (Disable/Skip Intro & Legal Messages)

Saves 30 Seconds of your life each time you run GTA V

Copyright (c) 2015 - Rafa³ 'grasmanek94/Gamer_Z' Grasman

License: MIT

grasmanek94 at gmail dot com
*/
int carspawnActiveLineIndex = 0;
int carspawnActiveItemIndex = 0;
bool featureVehWrapInSpawned = false;


const char* veh_cat(int index)
{
	switch (index)
	{
	case 1: case 2: case 3: return "Boats";
	case 4: case 5: return "Commercial";
	case 6: return "Compacts";
	case 7: case 8: return "Coupes";
	case 9: return "Cycles";
	case 10: case 11: return "Emergency";
	case 12: case 13: case 14: return "Helicopters;";
	case 15: case 16: return "Industrial";
	case 17: return "Military";
	case 18: case 19: case 20: case 21: case 22: return "Motorcycles";
	case 23: case 24: case 25: case 26: case 27: return "Muscle";
	case 28: case 29: case 30: case 31: return "OffRoad";
	case 32: case 33: return "Planes";
	case 34: case 35: case 36: case 37: return "Sedans";
	case 38: case 39: return "Service";
	case 40: case 41: case  42: case 43: case 44: return "Sports";
	case 45: case 46: case  47:	return "SportsClassics";
	case 48: case 49: case 50: return "Super";
	case 51: case 52: case 53: return "Suv";
	case 54: case 55: case 56: return "Trailer";
	case 57: return "Trains";
	case 58: case 59: return "Utility";
	case 60: case 61: case 62: case 63:	return "Vans";
	case 64: case 65: return "Gunrunning DLC";
	default: return "Vehicles";
	}
}
LPCSTR vehicleModels[65][10] = {
	{ "DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX", "MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3" },//boats
	{ "SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2","SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2" },//boats
	{ "TUG", "", "", "", "", "", "", "", "", "" },

	{ "BENSON", "BIFF", "HAULER", "MULE", "MULE2","MULE3", "PACKER", "PHANTOM", "PHANTOM2", "POUNDER" },//Commercial
	{ "STOCKADE","STOCKADE3", "", "", "", "", "", "", "", "" },//Commercial

	{ "BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2","PANTO", "PRAIRIE", "RHAPSODY", "", "" }, //Compacts

	{ "COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2","JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2" }, //Coupes
	{ "WINDSOR", "WINDSOR2", "ZION", "ZION2", "", "", "", "", "", "" },//Coupes

	{ "BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE","TRIBIKE2", "TRIBIKE3", "", "", "" }, //Cycles

	{ "AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD","PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3" },//Emergency
	{ "POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET","SHERIFF", "SHERIFF2", "RIOT", "", "" },// Emergency

	{ "ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2","CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER" },//Helicopters
	{ "FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT","SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE" },// Helicopters
	{ "VALKYRIE2", "VOLATUS", "", "", "", "", "", "", "", "" },// Helicopters

	{ "BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN","HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK" },//Industrial
	{ "TIPTRUCK2", "", "", "", "", "", "", "", "", "" },//Industrial

	{ "BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO", "", "", "", "", "" },//Military

	{ "AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2","BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON" },//Motorcycles
	{ "DAEMON2", "DEFILER", "DIABLOUS", "DIABLOUS2", "DOUBLE", "ENDURO", "ESSKEY","FAGGIO", "FAGGIO2", "FAGGIO3" },//Motorcycles
	{ "FCR", "FCR2", "GARGOYLE", "HAKUCHOU", "HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ", "NEMESIS" },//Motorcycles
	{ "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN","SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN","THRUST" },//Motorcycles
	{ "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE","ZOMBIEA", "ZOMBIEB", "", "", "", "" },//Motorcycles

	{ "BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2","COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2" },//Muscle
	{ "GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3","HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE" },//Muscle
	{ "PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3","SABREGT", "SABREGT2", "SLAMVAN" },//Muscle
	{ "SLAMVAN2", "SLAMVAN3","STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO","VIRGO2", "VIRGO3", "VOODOO" },// Muscle
	{ "VOODOO2", "", "", "", "", "", "", "", "", "" },//Muscle

	{ "BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3","BLAZER4", "BLAZER5", "BODHI2", "BRAWLER", "DLOADER" },//OffRoad
	{ "DUBSTA3","DUNE", "DUNE2", "DUNE4", "DUNE5", "INSURGENT", "INSURGENT2", "KALAHARI","MARSHALL", "MESA3" },//OffRoad
	{ "MONSTER", "RANCHERXL", "RANCHERXL2","REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL", "TECHNICAL2","TROPHYTRUCK" },//OffRoad
	{ "TROPHYTRUCK2", "", "", "", "", "", "", "", "", "" },//OffRoad

	{ "BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER","HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2" },//Planes
	{ "MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT","TITAN", "VELUM", "VELUM2", "VESTRA", "" },//Planes

	{ "ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552","COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3" },//Sedans
	{ "FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2","PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO" },// Sedans
	{ "SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM","STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER" },//Sedans
	{ "WASHINGTON", "", "", "", "", "", "", "", "", "" },//Sedans

	{ "AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK","RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2" },//Service
	{ "WASTELANDER", "", "", "", "", "", "", "", "", "" },//Service

	{ "ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3","BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2" },//Sports
	{ "COMET3","COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE","FUTO", "JESTER", "JESTER2" },//Sports
	{ "KHAMELION", "KURUMA","KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF","NINEF2", "OMNIS", "PENUMBRA" },//Sports
	{ "RAPIDGT", "RAPIDGT2","RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70", "SPECTER", "SPECTER2","SULTAN" },//Sports
	{ "SURANO", "TAMPA2", "TROPOS", "VERLIERER2", "", "", "", "", "", "" },

	{ "BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2","FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE" },//SportsClassics
	{ "PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO","TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6" },//SportsClassics
	{ "ZTYPE", "", "", "", "", "", "", "", "", "" },//SportsClassics

	{ "ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF","FMJ", "SHEAVA", "INFERNUS", "ITALIGTB", "ITALIGTB2" },//Super
	{ "NERO", "NERO2","OSIRIS", "LE7B", "PENETRATOR", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20" },//Super
	{ "TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "VOLTIC2", "ZENTORNO", "", "", "" },//Super

	{ "BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5","BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER" },//SUVs
	{ "DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY","HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2" },//SUVs
	{ "PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO","XLS", "XLS2", "", "", "" },//SUVs

	{ "ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER","DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER" },//Trailer
	{ "TANKER", "TANKER2", "TR2", "TR3", "TR4","TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL" },//Trailer
	{ "TRFLAT", "TVTRAILER", "", "", "", "", "", "", "", "" },//Trailer

	{ "CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2","FREIGHTGRAIN", "METROTRAIN", "TANKERCAR", "", "" },//Trains

	{ "AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT","MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP" },//Utility
	{ "TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3","UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3", "", "" },//Utility

	{ "BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE","BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BOXVILLE5", "BURRITO" },//Vans
	{ "BURRITO2","BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO","GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2" },//Vans 
	{ "PARADISE","PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3","SPEEDO", "SPEEDO2", "SURFER", "SURFER2" },
	{ "TACO","YOUGA", "YOUGA2", "", "", "", "", "", "", "" },//Vans
	{ "APC", "ARDENT", "CADDY3", "CHEETAH2", "DUNE3", "HALFTRACK", "HAULER2", "INSURGENT3", "NIGHTSHARK", "OPPRESSOR" },//1.40
	{ "PHANTOM3", "TAMPA3", "TECHNICAL3", "TORERO", "TRAILERLARGE", "TRAILERSMALL2", "VAGNER", "XA21", "", "" },//1.40

};
void set_status_text()
{

}
bool memory_compare(const BYTE *data, const BYTE *pattern, const char *mask)
{
	for (; *mask; ++mask, ++data, ++pattern)
	{
		if (*mask == 'x' && *data != *pattern)
		{
			return false;
		}
	}
	return (*mask) == NULL;
}

UINT64 FindPattern(char *pattern, char *mask)
{	//Edited, From YSF by Kurta999
	UINT64 i;
	UINT64 size;
	UINT64 address;

	MODULEINFO info = { 0 };

	address = (UINT64)GetModuleHandle(NULL);
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(NULL), &info, sizeof(MODULEINFO));
	size = (UINT64)info.SizeOfImage;

	for (i = 0; i < size; ++i)
	{
		if (memory_compare((BYTE *)(address + i), (BYTE *)pattern, mask))
		{
			return (UINT64)(address + i);
		}
	}
	return 0;
}

void DisableRockstarLogos()
{
	UINT64 logos = FindPattern("platform:/movies/rockstar_logos", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	if (logos != 0)
	{
		//memset((void*)(logos + 0x11), 0x00, 0x0E);
		memcpy((void*)logos, "./nonexistingfilenonexistingfil", 32);
	}
}

void DisableLegalMessagesCompletely()
{
	UINT64 address = FindPattern("\x72\x1F\xE8\x12\x8D\xFB\x00\x8B\x0D\x34\x7F\xC3\x01\xFF\xC1\x48", "xxx???xxx???xxxx");

	if (address != 0)
	{
		unsigned long dwProtect;
		unsigned long dwProtect2;

		VirtualProtect((LPVOID)address, 2, PAGE_EXECUTE_READWRITE, &dwProtect);
		*(unsigned short*)(address) = 0x9090;
		VirtualProtect((LPVOID)address, 2, dwProtect, &dwProtect2);
	}
}

/* Models */
uint RequestedModel = 0ul;
RequestState model_state = loaded;
void(*modelFunction)() = nullptr;
void modelCheck()
{
	switch (model_state)
	{
	case loaded:
		break;
	case requesting:
		if (STREAMING::HAS_MODEL_LOADED(RequestedModel) == TRUE)
		{
			model_state = loaded;

			modelFunction();

			break;
		}
		else
		{
			STREAMING::REQUEST_MODEL(RequestedModel);
			break;
		}
	}
}
static int _GET_TUNABLES_CONTENT_MODIFIER_ID(Hash contentHash) { return invoke<int>(0x187382F8A3E0A6C3, contentHash); } // 0x187382F8A3E0A6C3 0xA78571CA
namespace {
	// Declare/Initialise global variables here.
	char str[50];
	bool controllerinput_bool = 1, menujustopened = 1, null;
	enum ControllerInputs
	{
		//controller mapping goes here
	};
}

/*
THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
http://dev-c.com
(C) Alexander Blade 2015
*/

/*
F4					activate
NUM2/8/4/6			navigate thru the menus and lists (numlock must be on)
NUM5 				select
NUM0/BACKSPACE/F4 	back
NUM9/3 				use vehicle boost when active
NUM+ 				use vehicle rockets when active
*/

#include "script.h"
#include "keyboard.h"

#include <string>
#include <ctime>
#pragma region Variables
//Native_s** g_Natives;
int submenu = 0;
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];
int currentOption;
int optionCount;
bool optionPress = false;
bool rightPress = false;
bool leftPress = false;
bool fastRightPress = false;
bool fastLeftPress = false;
bool squarePress = false;
int selectedPlayer;
bool menuSounds = true;

bool keyboardActive = false;
int keyboardAction;
int *keyboardVar = 0;
char *infoText;

bool newTimerTick = true;
int maxTimerCount;
bool newTimerTick2 = true;
int maxTimerCount2;

bool instructions = true;
int instructCount;
int mov;
bool instructionsSetupThisFrame;
bool xInstruction;
bool squareInstruction;
bool lrInstruction;
int rpamount = 1000000000000;
int bannerTextRed = 255;
int bannerTextGreen = 255;
int bannerTextBlue = 255;
int bannerTextOpacity = 255;
int bannerTextFont = 7;
int bannerRectRed = 0;
int bannerRectGreen = 255;
int bannerRectBlue = 255;
int bannerRectOpacity = 255;
int backgroundRed = 16;
int backgroundGreen = 16;
int backgroundBlue = 16;
int backgroundOpacity = 70;
int optionsRed = 255;
int optionsGreen = 255;
int optionsBlue = 255;
int optionsOpacity = 255;
int optionsFont = 0;
int scrollerRed = 255;
int scrollerGreen = 255;
int scrollerBlue = 255;
int scrollerOpacity = 50;
int indicatorRed = 255;
int indicatorGreen = 255;
int indicatorBlue = 255;
int indicatorOpacity = 255;
float menuXCoord = 0.845f;
float textXCoord = 0.76f;
int maxOptions = 18;
int TimePD1;
// retarded bools
//bool invisible = true;
bool fastrun = false;
bool fastswim = false;
bool inviso = false;
// end retarded bools
bool god = false;
bool infammo = 0;
bool explosiveammo = false;
bool fireammo = false;
bool dildmoney = false;
bool dildomoneylocal = false;
bool StealthLooptoggle2 = false;
int TimePD3;

//uint Weapons[] = { 0xDFE37640, 0xC1B3C3D1, 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D, GAMEPLAY::GET_HASH_KEY("WEAPON_HATCHET"), GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN") };
#pragma endregion


void drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
//UI::_SET_TEXT_ENTRY("STRING");
	UI::_0x5F68520888E69014(text);
	//UI::_DRAW_TEXT(x, y);
	_DRAW_TEXT(x, y);
}
void drawNotification(char* msg)
{
/*	if (menuXCoord == 0.845f) {
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
		UI::_DRAW_NOTIFICATION(2000, 1);
	}
	else
	{
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
		UI::_DRAW_NOTIFICATION(3000, 1);
	}*/
}
void changeSubmenu(int newSubmenu)
{
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}
void SetupTimer(int tickTime)
{
	if (newTimerTick) {
		maxTimerCount = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick = false;
	}
}
bool IsTimerReady()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount;
}
void ResetTimer()
{
	newTimerTick = true;
}
void SetupTimer2(int tickTime)
{
	if (newTimerTick2) {
		maxTimerCount2 = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick2 = false;
	}
}
bool IsTimerReady2()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount2;
}
void ResetTimer2()
{
	newTimerTick2 = true;
}
void drawSprite(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);

	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
	{
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
	}
}
RGBA bannerRect = { 244, 14, 67, 225 };
RGBA bannerText = { 255, 255, 255, 255 };
float secondTitleX = 0.718f;
float secondTitleY = 0.108f;

RGBA secondTitle = { 255, 255, 255, 255 };
int secondTitleRed = 255;
int secondTitleGreen = 255;
int secondTitleBlue = 255;
int secondTitleOpacity = 255;

void drawHeader()
{
	
	
//
		//	GRAPHICS::DRAW_RECT(0.827f, 0.06f, 0.225f, 0.09f, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A);
	//	drawSprite("CommonMenu", "interaction_bgd", 0.827f, 0.06f, 0.225f, 0.09f, 0, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A);
}
void addTitle(char *title)
{
//	drawText(title, bannerTextFont, menuXCoord, 0.1f, 0.75f, 0.75f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
//	GRAPHICS::DRAW_RECT(menuXCoord, 0.1175f, 0.19f, 0.083f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity);
	// Request the scaleform

	drawSprite("CommonMenu", "interaction_bgd", 0.827f, 0.06f, 0.225f, 0.09f, 0, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A);
	//drawSprite("mpawardheists", "livealittle", 0.827f, 0.06f, 0.225f, 0.09f, 0, 188, 0, 255, bannerRect.A);
	drawText("gradient BETA", 1, 0.827f, 0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE/*, FALSE*/);
	drawText(title, 0, secondTitleX, secondTitleY, 0.35f, 0.35f, secondTitleRed, secondTitleGreen, secondTitleBlue, secondTitleOpacity, FALSE/*, FALSE*/);
	
	float yValue = 0.0968f;
	int GlareMovie = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE"); //credits to IamMADNESS & the leaked amengine source lol
	GRAPHICS::DRAW_SCALEFORM_MOVIE(GlareMovie, menuXCoord + 0.333, yValue + 0.414, 0.98, 1.0200, 255, 0, 0, 255, 0);
//	GRAPHICS::DRAW_SCALEFORM_MOVIE(GlareMovie, 0.827f, 0.06f, 0.98, 1.0200, 255, 0, 0, 255, 0);
	// 0.827f, 0.06f
	//
//	int gGlareHandle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");                                                  //BROKEN 
//	GRAPHICS::DRAW_SCALEFORM_MOVIE(gGlareHandle, menuXCoord, 0.1175f, 0.75f, 0.87f, bannerRectRed, bannerRectGreen, bannerRectBlue, 255, 0);

}
#pragma region Option Helpers
char* optionTextToAdd;
float mainTextX = 0.827f;
float mainTextY = 0.106f;
RGBA highlight = { 0, 0, 0, 255 };
int highlightRed = 0;
int highlightGreen = 0;
bool optionCenter = FALSE;
int highlightBlue = 0;
void addOption(char *option, char *info = NULL)
{
	optionCount++;
	if (currentOption == optionCount)
		infoText = info;
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	//	drawText(option, optionsFont, textXCoord, (optionCount * 0.035f + 0.125f), 0.4f, 0.4f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
    	drawText(option, optionsFont, mainTextX - 0.108f, (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	//	drawText(option, optionsFont, textXCoord, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.125f), 0.4f, 0.4f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	    drawText(option, optionsFont, mainTextX - 0.108f, ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
		

}
#include <functional>
bool addop2(char *option, std::function<void()> function, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
		{
			if (optionCount == currentOption && optionPress) {
				function();
				return true;
			}
			return false;
		}
	}
}
void addtpOption(char *option, float xPos, float yPos, float zPos,  char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
		{
			//SET_PED_INTO_VEHICLE
			//GET_VEHICLE_PED_IS_IN
			//GET_VEHICLE_PED_IS_USING
		//PLAYER::GET_PLAYERS_LAST_VEHICLE()

			
			Entity e = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
				e = PED::GET_VEHICLE_PED_IS_USING(e);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, xPos, yPos, zPos, 1, 1, 1);
		}
	}
}


void addrpOption(char *option, int value, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
			{
				STATS::STAT_SET_INT($("MP0_CHAR_XP_FM"), value, true);
				STATS::STAT_SET_INT($("MP1_CHAR_XP_FM"), value, true);
				STATS::STAT_SET_INT($("MP2_CHAR_XP_FM"), value, true);
			}
		}
	}
}



void addSubmenuOption(char *option, int newSubmenu, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
			changeSubmenu(newSubmenu);
	}
}
void addBoolOption(char *option, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "%s: ~b~ON", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: ~r~OFF", option);
		addOption(buf, info);
	}
}
void addbool2(char* option, bool b00l, char* text = "", bool meg = false)
{
	if (meg)
	{
		drawNotification(text);
	}
	char buf[30];
	if (b00l)
	{
		_snprintf(buf, sizeof(buf), "%s ~b~ON", option);
		addOption(buf);
	}
	else
	{
		_snprintf(buf, sizeof(buf), "%s ~r~OFF", option);
		addOption(buf);
	}
}
template<typename TYPE>
void addCustomBoolOption(char *option, TYPE value, TYPE match, char *info = NULL)
{
	char buf[30];
	if (value == match)
	{
		snprintf(buf, sizeof(buf), "%s: On", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: Off", option);
		addOption(buf, info);
	}
}
// NEEDS WORK
void addIntOption(char *option, int *var, int min, int max, bool keyboard, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %i >", option, *var);
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		if (rightPress)
		{
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
			rightPress = false;
		}
		else if (leftPress)
		{
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
			leftPress = false;
		}
	}
}
void addFloatOption(char *option, float *var, float min, float max, bool holdPress, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %s >", option, (*var));
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (holdPress)
		{
			if (fastRightPress)
			{
				//			playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 0.01f;
			}
			else if (fastLeftPress)
			{
				//			playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 0.01f;
			}
		}
		else
		{
			if (rightPress)
			{
				//		playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 0.01f;
			}
			else if (leftPress)
			{
				//			playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 0.01f;
			}
		}
	}
}
// END NEEDS WORK
int getOption()
{
	xInstruction = true;
	if (optionPress)
		return currentOption;
	else return 0;
}
float MainBackGroundX = 0.827f;
float MainBackGroundY = 0.137f;
float MainBackGroundWidth = 0.225f;
RGBA background = { 0, 0, 0, 185 };
float scrollerX = 0.827f;
float scrollerY = 0.1197f;
float BarUnderHeaderX = 0.827f;
float BarUnderHeaderY = 0.121f;
float BarUnderHeaderHeight = 0.032f;
float infoBoxX = 0.827f;
float infoBoxY = 0.127f;
float infoBoxTextX = 0.718f;
float infoBoxTextY = 0.114f;
float BarAboveInfoY = 0.108f;
float BarAboveInfoHeight = 0.003f;
void normalMenuActions()
{/*
 DWORD wakeAt2;
 if (timeGetTime() < wakeAt2)
 return;

 static HANDLE scriptFiber;
 if (scriptFiber)
 SwitchToFiber(scriptFiber);
 */
	/*
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_FRANKLIN, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_MICHAEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_TREVOR, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_MULTIPLAYER, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 166);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 167);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 177);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 178);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 193);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 194);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 195);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 202);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 203);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 204);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 205);
	*/
/*	if (optionCount > maxOptions)
	{
		GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions * 0.035f) / 2) + 0.159f), 0.19f, (maxOptions * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
		if (currentOption > maxOptions)
		{
			GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
			GRAPHICS::DRAW_RECT(menuXCoord, 0.156f, 0.19f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Up Indicator
		}
		else
		{
			GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
		}
		if (currentOption != optionCount)
		{
			GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.161f), 0.19f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Down Indicator
		}
	}
	else
	{
		GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount * 0.035f) / 2) + 0.159f), 0.19f, (optionCount * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
		GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
	}
	if (!GAMEPLAY::IS_STRING_NULL_OR_EMPTY(infoText))
	{
		if (optionCount > maxOptions)
		{
			drawText(infoText, optionsFont, menuXCoord, ((maxOptions + 1) * 0.035f + 0.125f), 0.4f, 0.4f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
			GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions + 1) * 0.035f) + 0.1415f), 0.19f, 0.035f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); //Info Box
		}
		else
		{
			drawText(infoText, optionsFont, menuXCoord, ((optionCount + 1) * 0.035f + 0.125f), 0.4f, 0.4f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
			GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount + 1) * 0.035f) + 0.1415f), 0.19f, 0.035f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); //Info Box
		}
	}
	SetupTimer2(20);
	if (instructions)
	{
		if (IsTimerReady2())
		{
			//		if (xInstruction)
			//			addInstruction(BUTTON_A, "Select");
			//		if (squareInstruction)
			//			addInstruction(BUTTON_X, "Keyboard");
			//		if (lrInstruction)
			//			addInstruction(BUTTON_DPAD_LEFT_RIGHT, "Scroll");
			//			addInstruction(BUTTON_DPAD_UP_DOWN, "Scroll");
			//		addInstruction(BUTTON_B, "Back");
			//		instructionsClose();
			ResetTimer2();
		}
	}*/
///	if (optionCount > maxOptions) {
///
///		//Sets the layer of the background, so our sprites can go on top
///		GRAPHICS::_SET_2D_LAYER(1);
///		//Background
///		GRAPHICS::DRAW_RECT(MainBackGroundX, (((maxOptions * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (maxOptions * 0.035f), background.R, background.G, background.B, background.A);
///
///		//Scroller
///	/*	if (currentOption > maxOptions) {
///			GRAPHICS::_SET_2D_LAYER(1);
///		//	if (gradients)
///		//		drawSprite("commonmenu", "gradient_nav", scrollerX, ((maxOptions * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
///		//	else
///				GRAPHICS::DRAW_RECT(scrollerX, ((maxOptions * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);
///	}
///		else {
///			GRAPHICS::_SET_2D_LAYER(1);
///		//	if (gradients)
///		//		drawSprite("commonmenu", "gradient_nav", scrollerX, ((currentOption * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
///		//	else
///				GRAPHICS::DRAW_RECT(scrollerX, ((currentOption * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);
///
///		}
///		*/
///
///
///		if (currentOption > maxOptions) {
///		/*	GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions * 0.035f) / 2) + 0.159f), 0.19f, (maxOptions * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
///			if (currentOption > maxOptions)
///			{
///				GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
///				GRAPHICS::DRAW_RECT(menuXCoord, 0.156f, 0.19f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Up Indicator
///			}
///			else
///			{
///				GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
///			}
///			if (currentOption != optionCount)
	///		{
	///			GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.161f), 0.19f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Down Indicator
///			}
///		*/
	///		GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions * 0.035f) / 2) + 0.159f), 0.19f, (maxOptions * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
///			if (currentOption > maxOptions)
///			{
///			GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
///				GRAPHICS::DRAW_RECT(menuXCoord, 0.156f, 0.19f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Up Indicator
///			}
///			else
///			{
///				GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
///			}
///			if (currentOption != optionCount)
///			{
///				GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.161f), 0.19f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Down Indicator
///			}
///		}
///		else
///		{
///			GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (maxOptions * 0.035f), background.R, background.G, background.B, background.A); //Background
///			GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
///		}







		//Bar under header
///		GRAPHICS::DRAW_RECT(BarUnderHeaderX, BarUnderHeaderY, 0.225f, BarUnderHeaderHeight, 0, 0, 0, 255);

		//Bar above infobox
	//	if (gradients)
///			drawSprite("CommonMenu", "interaction_bgd", BarUnderHeaderX, (((maxOptions + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, 0, bannerRect.R, bannerRect.G, bannerRect.B, 255);
	//	else
	//		GRAPHICS::DRAW_RECT(BarUnderHeaderX, (((maxOptions + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, bannerRect.R, bannerRect.G, bannerRect.B, 255);

///	}

///	else {

		//Set layer
///		GRAPHICS::_SET_2D_LAYER(1);
		//Background
///		GRAPHICS::DRAW_RECT(MainBackGroundX, (((optionCount * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (optionCount * 0.035f), background.R, background.G, background.B, background.A);
///
///		//Scroller
///		GRAPHICS::_SET_2D_LAYER(1);
///	//	if (gradients)
///			drawSprite("commonmenu", "gradient_nav", scrollerX, ((currentOption * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
///	//	else
///	//		GRAPHICS::DRAW_RECT(scrollerX, ((currentOption * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);
///
///		//Bar under header
///		GRAPHICS::DRAW_RECT(BarUnderHeaderX, BarUnderHeaderY, 0.225f, BarUnderHeaderHeight, 0, 0, 0, 255);
///
///		//Bar above infobox
///	//	if (gradients)
///			drawSprite("CommonMenu", "interaction_bgd", BarUnderHeaderX, (((optionCount + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, 0, bannerRect.R, bannerRect.G, bannerRect.B, 255);
///	//	else
///	//		GRAPHICS::DRAW_RECT(BarUnderHeaderX, (((optionCount + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, bannerRect.R, bannerRect.G, bannerRect.B, 255);
///
///	}
///
///	//Our infobox
///	if (optionCount > maxOptions)
///	{
///		drawText(infoText, optionsFont, infoBoxTextX, ((maxOptions + 1) * 0.035f + infoBoxTextY), 0.3f, 0.3f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE/*, FALSE*/);
///		GRAPHICS::DRAW_RECT(infoBoxX, (((maxOptions + 1) * 0.035f) + infoBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A); //Info Box
///	}
///	else
///	{
///		drawText(infoText, optionsFont, infoBoxTextX, ((optionCount + 1) * 0.035f + infoBoxTextY), 0.3f, 0.3f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE/*, FALSE*/);
///		GRAPHICS::DRAW_RECT(infoBoxX, (((optionCount + 1) * 0.035f) + infoBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A); //Info Box
///	}



if (optionCount > maxOptions) {

	//Sets the layer of the background, so our sprites can go on top
	GRAPHICS::_SET_2D_LAYER(1);
	//Background
	GRAPHICS::DRAW_RECT(MainBackGroundX, (((maxOptions * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (maxOptions * 0.035f), background.R, background.G, background.B, background.A);

	//Scroller
	if (currentOption > maxOptions) {
		GRAPHICS::_SET_2D_LAYER(1);
	//	if (gradients)
			drawSprite("commonmenu", "gradient_nav", scrollerX, ((maxOptions * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
	//	else
	//		GRAPHICS::DRAW_RECT(scrollerX, ((maxOptions * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);
	}
	else {
		GRAPHICS::_SET_2D_LAYER(1);
	//	if (gradients)
			drawSprite("commonmenu", "gradient_nav", scrollerX, ((currentOption * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
	//	else
	//		GRAPHICS::DRAW_RECT(scrollerX, ((currentOption * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);
	}

	//Bar under header
	GRAPHICS::DRAW_RECT(BarUnderHeaderX, BarUnderHeaderY, 0.225f, BarUnderHeaderHeight, 0, 0, 0, 255);

	//Bar above infobox
	//if (gradients)
		drawSprite("CommonMenu", "interaction_bgd", BarUnderHeaderX, (((maxOptions + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, 0, bannerRect.R, bannerRect.G, bannerRect.B, 255);
//	else
//		GRAPHICS::DRAW_RECT(BarUnderHeaderX, (((maxOptions + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, bannerRect.R, bannerRect.G, bannerRect.B, 255);

}

else {

	//Set layer
	GRAPHICS::_SET_2D_LAYER(1);
	//Background
	GRAPHICS::DRAW_RECT(MainBackGroundX, (((optionCount * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (optionCount * 0.035f), background.R, background.G, background.B, background.A);

	//Scroller
	GRAPHICS::_SET_2D_LAYER(1);
//	if (gradients)
		drawSprite("commonmenu", "gradient_nav", scrollerX, ((currentOption * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
//	else
//		GRAPHICS::DRAW_RECT(scrollerX, ((currentOption * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);

	//Bar under header
	GRAPHICS::DRAW_RECT(BarUnderHeaderX, BarUnderHeaderY, 0.225f, BarUnderHeaderHeight, 0, 0, 0, 255);

	//Bar above infobox
//	if (gradients)
		drawSprite("CommonMenu", "interaction_bgd", BarUnderHeaderX, (((optionCount + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, 0, bannerRect.R, bannerRect.G, bannerRect.B, 255);
//	else
//		GRAPHICS::DRAW_RECT(BarUnderHeaderX, (((optionCount + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, bannerRect.R, bannerRect.G, bannerRect.B, 255);

}

//Our infobox
if (optionCount > maxOptions)
{
	drawText(infoText, optionsFont, infoBoxTextX, ((maxOptions + 1) * 0.035f + infoBoxTextY), 0.3f, 0.3f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE/*, FALSE*/);
	GRAPHICS::DRAW_RECT(infoBoxX, (((maxOptions + 1) * 0.035f) + infoBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A); //Info Box
}
else
{
	drawText(infoText, optionsFont, infoBoxTextX, ((optionCount + 1) * 0.035f + infoBoxTextY), 0.3f, 0.3f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE/*, FALSE*/);
	GRAPHICS::DRAW_RECT(infoBoxX, (((optionCount + 1) * 0.035f) + infoBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A); //Info Box
}







}

void resetVars()
{
	if (submenu != Closed)
		normalMenuActions();


	drawHeader();
	optionPress = false;
	rightPress = false;
	leftPress = false;
	fastRightPress = false;
	fastLeftPress = false;
	squarePress = false;
	infoText = NULL;
	instructionsSetupThisFrame = false;
	squareInstruction = false;
	xInstruction = false;
	lrInstruction = false;
}
char* SoundToPlay;
char* SoundSetToPlay;
bool PlaySounds;

void PlaySoundz(char* SoundName, char* SoundSetName)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, SoundName, SoundSetName, 1);
}
bool getKeyPressed(int key) {
	return (GetAsyncKeyState(key) & 0xFFFF) == 0x8001;
}
int DelayCounter = GetTickCount();

bool trainer_switch_pressed()
{
	//	bool result = KeyJustUp(VK_F9);
	//	return result;
	if (GetTickCount() - DelayCounter > 150)
	{
		if (submenu == Closed)
		{
			if (getKeyPressed(VK_F8) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SCRIPT_LB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SCRIPT_PAD_DOWN)) && submenu == 0)
			{
				DelayCounter = GetTickCount();
				submenu = Main_Menu;
				submenuLevel = 0;
				currentOption = 1;
				SoundToPlay = "FLIGHT_SCHOOL_LESSON_PASSED";
				SoundSetToPlay = "HUD_AWARDS";
				PlaySounds = true;
			}
			ResetTimer();
		}
	/*	else {

			if (getKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_CANCEL) && submenu != 0)//exit
			{
				DelayCounter = GetTickCount();
				if (submenu == Main_Menu)
				{
					submenu = Closed;
				}
				else {
					submenu = lastSubmenu[submenuLevel - 1];
					currentOption = lastOption[submenuLevel - 1];
					submenuLevel--;
				}
				SoundToPlay = "BACK";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_ACCEPT) && submenu != 0)//option select
			{
				DelayCounter = GetTickCount();
				optionPress = true;
				SoundToPlay = "SELECT";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_UP) && submenu != 0)//up
			{
				DelayCounter = GetTickCount();
				currentOption--;
				if (currentOption < 1)
				{
					currentOption = optionCount;
				}
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_DOWN) && submenu != 0)//down
			{
				DelayCounter = GetTickCount();
				currentOption++;
				if (currentOption > optionCount)
				{
					currentOption = 1;
				}
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CELLPHONE_LEFT))//down
			{
				leftPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CELLPHONE_RIGHT))//down
			{
				rightPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
		}
*/	}
	
}
void monitorButtons()
{	//	bool result = KeyJustUp(VK_F9);
	//	return result;
	if (GetTickCount() - DelayCounter > 150)
	{
			if (getKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_PUSH_TO_TALK) && submenu != 0)//exit
			{
				DelayCounter = GetTickCount();
				if (submenu == Main_Menu)
				{
					submenu = Closed;
				}
				else {
					submenu = lastSubmenu[submenuLevel - 1];
					currentOption = lastOption[submenuLevel - 1];
					submenuLevel--;
				}
				SoundToPlay = "BACK";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_PUSH_TO_TALK) && submenu != 0)//option select
			{
				DelayCounter = GetTickCount();
				optionPress = true;
				SoundToPlay = "SELECT";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_PUSH_TO_TALK) && submenu != 0)//up
			{
				DelayCounter = GetTickCount();
				currentOption--;
				if (currentOption < 1)
				{
					currentOption = optionCount;
				}
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_PUSH_TO_TALK) && submenu != 0)//down
			{
				DelayCounter = GetTickCount();
				currentOption++;
				if (currentOption > optionCount)
				{
					currentOption = 1;
				}
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_PUSH_TO_TALK))//down
			{
				leftPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_PUSH_TO_TALK))//down
			{
				rightPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
		}
	}

bool isNumericChar(char x)
{
	return (x >= '0' && x <= '9') ? true : false;
}
#pragma region Other Loop
int StoI(char *str)
{
	if (*str == NULL)
		return 0;

	int res = 0,
		sign = 1,
		i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i)
	{
		if (isNumericChar(str[i]) == false)
			return 0;
		res = res * 10 + str[i] - '0';
	}
	return sign*res;
}
void otherLoop()
{/*
	if (keyboardActive)
	{
		if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 1)
		{
			keyboardActive = false;
			switch (keyboardAction)
			{
			case 0: //addIntOption
				*keyboardVar = StoI(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
				break;
			}
		}
		else if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 2 || GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 3)
		{
			keyboardActive = false;
		}
	} */
}
#pragma endregion
class menu
{
public:
	//static void loops();
};
void update_features()
{
	if (infammo == TRUE)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		Hash cur;
		if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &cur, 1))
		{
			if (WEAPON::IS_WEAPON_VALID(cur))
			{
				int maxAmmo;
				if (WEAPON::GET_MAX_AMMO(playerPed, cur, &maxAmmo))
				{
					WEAPON::SET_PED_AMMO(playerPed, cur, maxAmmo);

					maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, cur, 1);
					if (maxAmmo > 0)
						WEAPON::SET_AMMO_IN_CLIP(playerPed, cur, maxAmmo);
				}
			}
		}
	}

	if (explosiveammo == TRUE)
	{
		Player player = PLAYER::PLAYER_ID();
		GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(player);
	}
	if (fireammo == TRUE)
	{
		GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
	}


	if (dildomoneylocal == TRUE) {
		Ped iPed = PLAYER::PLAYER_PED_ID();
		{

			if ((timeGetTime() - TimePD1) > 20000) // Time between drops
			{
				void CashDrop(int pedHandle, char* CashModel, int Value);

				{
					//(PLAYER::PLAYER_PED_ID(selectedPlayer))
					Vector3 coords = GET_ENTITY_COORDS(iPed, FALSE);
					int CashHash = -422877666;
					int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
					STREAMING::REQUEST_MODEL(CashHash);
					while (!STREAMING::HAS_MODEL_LOADED(CashHash)) WAIT(0);
					OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, coords.x, coords.y, coords.z, 0, 2000, CashHash, false, true);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(CashHash);
				}

			}
		}
	}

	if (dildmoney == TRUE)
	{
		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		{

			if ((timeGetTime() - TimePD1) > 20000) // Time between drops
			{
				void CashDrop(int pedHandle, char* CashModel, int Value);

				{
					//(PLAYER::PLAYER_PED_ID(selectedPlayer))
					Vector3 coords = GET_ENTITY_COORDS(iPed, FALSE);
					int CashHash = -422877666;
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
int Hook()
{
	trainer_switch_pressed();
	monitorButtons();
	otherLoop();
	optionCount = 0;
	//	void Script::loops();
	switch (submenu)
	{
#pragma region Main Menu
	case Main_Menu:
		addTitle("main menu");
		//	addSubmenuOption("Dev Options", dev_options);
		addSubmenuOption("Self Options", Self_Options, "1/8");
		addSubmenuOption("Weapon Options", weapons_options, "2/8");
		addSubmenuOption("Teleport", tp_options, "3/8");
		addSubmenuOption("Vehicle Spawner", Vehicle_Spawner, "4/8");
		addSubmenuOption("Recovery", recovery, "5/8");
		addSubmenuOption("Players List", Players_List, "6/8");
		addSubmenuOption("Settings", Settings, "7/8");
		addSubmenuOption("Credits", credits, "8/8");
		break;
#pragma endregion
#pragma region tp options
	case tp_options:
		addTitle("Teleports");
		addtpOption("GUN RANGE", 22.153, -1072.854, 29.797, "BANG BANG!");
		addtpOption("MICHAEL'S HOUSE", -852.4f, 160.0f, 65.6f, "you creep >_>");
		addtpOption("FRANKLIN'S HOUSE", 7.9f, 548.1f, 175.5f, "this guys mum is creepy");
		addtpOption("TREVOR'S TRAILER", 1985.7f, 3812.2f, 32.2f, "this guy is special");
		addtpOption("AIRPORT ENTRANCE", -1034.6f, -2733.6f, 13.8f, "LETS FLY A JET!");
		addtpOption("AIRPORT FIELD", -1336.0f, -3044.0f, 13.9f, "LETS FLY ANOTHER JET");
		addtpOption("ELYSIAN ISLAND", 338.2f, -2715.9f, 38.5f, "it's an island what more do you want?");
		addtpOption("JETSAM", 760.4f, -2943.2f, 5.8f, "its a thing");
		addtpOption("STRIPCLUB", 127.4f, -1307.7f, 29.2f, "TITTIES TITTIES TITTIES CARTOON TITTIES!");
		addtpOption("ELBURRO HEIGHTS", 1384.0f, -2057.1f, 52.0f, "homes :D");
		addtpOption("FERRIS WHEEL", -1670.7f, -1125.0f, 13.0f, "SO MUCH FUN :D");
		addtpOption("CHUMASH", -3192.6f, 1100.0f, 20.2f, "jack's forehead");
		addtpOption("WINDFARM", 2354.0f, 1830.3f, 101.1f, "it's a windmill");
		addtpOption("MILITARY BASE", -2047.4f, 3132.1f, 32.8f, "dont get shot!");
		addtpOption("MCKENZIE AIRFIELD", 2121.7f, 4796.3f, 41.1f, "lets go fly a kite :D");
		addtpOption("DESERT AIRFIELD", 1747.0f, 3273.7f, 41.1f, "PLANES!");
		addtpOption("CHILLIAD", 425.4f, 5614.3f, 766.5f, "its the biggest thing i ever saw!");
		break;
#pragma endregion

#pragma region dev
	case dev_options:
		addTitle("dev shit");
		

		break;
#pragma endregion
#pragma region recovery
	case recovery:
		addTitle("Recovery Menu");
		addSubmenuOption("Online Recovery", online_recovery, "FOR ONLINE!");
		addSubmenuOption("Offline Recovery", offline_recovery, "FOR OFFLINE!");
		break;
#pragma endregion
#pragma region online recovery
	case online_recovery:
		addTitle("online recovery");
		addSubmenuOption("add rp", rp_set, "");
		addSubmenuOption("add cash", cash_recovery_online, "");
		break;
#pragma endregion
	case rp_set:
		addTitle("add rp");
		addrpOption("level 100", 1584350, "");		addrpOption("level 200", 4691850, "");		addrpOption("level 300", 8299350, "");		addrpOption("level 400", 12406850, "");		addrpOption("level 500", 17014350, "");		addrpOption("level 600", 22121850, "");		addrpOption("level 700", 27729350, "");		addrpOption("level 800", 33836850, "");		addrpOption("level 900", 40444350, "");		addrpOption("level 1000", 47551850, "");
		break;
#pragma endregion
#pragma region cash recovery
	case cash_recovery_online:
		addTitle("Online Cash");
		addBoolOption("2k dildos", dildomoneylocal, "sexy");
		
		switch (getOption())
		{
		case 1: dildomoneylocal = !dildomoneylocal; break;
		}

		


	


		break;
#pragma endregion
#pragma region offline recovery
	case offline_recovery:
		addTitle("offline recovery");
	//	addIntOption("choose amount", &offlineammount, 0, 1000000000000, true);
		addOption("Give 10 million");
		addOption("Give 1 million");
		addOption("Give 100k");
		if (getOption() == 1) {
			for (int i = 0; i < 3; i++)
			{
				char statNameFull[32];
				sprintf_s(statNameFull, "SP%d_TOTAL_CASH", i);
				Hash hash = GAMEPLAY::GET_HASH_KEY(statNameFull);
				int val;
				STATS::STAT_GET_INT(hash, &val, -1);
				val += 10000000;
				STATS::STAT_SET_INT(hash, val, 1);
			}
		}
		if (getOption() == 2) {
			for (int i = 0; i < 3; i++)
			{
				char statNameFull[32];
				sprintf_s(statNameFull, "SP%d_TOTAL_CASH", i);
				Hash hash = GAMEPLAY::GET_HASH_KEY(statNameFull);
				int val;
				STATS::STAT_GET_INT(hash, &val, -1);
				val += 1000000;
				STATS::STAT_SET_INT(hash, val, 1);
			}
		}
		if (getOption() == 3) {
			for (int i = 0; i < 3; i++)
			{
				char statNameFull[32];
				sprintf_s(statNameFull, "SP%d_TOTAL_CASH", i);
				Hash hash = GAMEPLAY::GET_HASH_KEY(statNameFull);
				int val;
				STATS::STAT_GET_INT(hash, &val, -1);
				val += 100000;
				STATS::STAT_SET_INT(hash, val, 1);
			}
		}
		break;
#pragma endregion
#pragma region credits
	case credits:
		addTitle("Credits");
		addOption("Infamous Dev Team");
		addOption("^^ for sudomod ^^");
		addOption("2much4u for his menu base");
		addOption("opal for slothority & opalbeats");
		addOption("The poopstar devs");
		addOption("Alexander Blade");
		addOption("Sudo for teaching me how to get sigs");
		addOption("^^ and wawixs and taranVG for failing ^^");
		addOption("---------------------------------------");
		addOption("worked on by:");
		addOption("Sinfool#2522");


		break;
#pragma endregion
	//	int OnlinePlayers = int i = 0; i < 32; i++;
#pragma region Players List
	case Players_List:
		addTitle("Players List");
		for (int i = 0; i < 32; i++)
		{
			addOption(GET_PLAYER_NAME(i));
		
		}
		if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
		{
			selectedPlayer = currentOption - 1;
			changeSubmenu(Player_Options);
		}
		break;
#pragma endregion

#pragma region Player Options
	case Player_Options:
		addTitle(GET_PLAYER_NAME(selectedPlayer));
		//various player options here
		//use PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer) to get the ped rather than player.
		addBoolOption("2k dildos", dildmoney);
		//addOption("no options because testing");


		switch (getOption())
		{
		case 1: dildmoney = !dildmoney; break;

		}

		break;
#pragma endregion
#pragma region wanted options
	case wanted_options:
		addTitle("Wanted Options");
		addOption("Wanted up", "das da sound of da police");
		addOption("Wanted down", "pussy");

		if (getOption() == 1)
		{
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();

//			if (!PLAYER::IS_PLAYER_PLAYING(player)) return;

			if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) < 5)
			{
				PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, PLAYER::GET_PLAYER_WANTED_LEVEL(player) + 1, false);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);
			}
		}
		if (getOption() == 2)
		{

			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();

	//		if (!PLAYER::IS_PLAYER_PLAYING(player)) return;

			if (PLAYER::GET_PLAYER_WANTED_LEVEL(player)>0)
			{
				PLAYER::CLEAR_PLAYER_WANTED_LEVEL(player);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, PLAYER::GET_PLAYER_WANTED_LEVEL(player) - 1, false);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);
			}
		
		}

		break;
#pragma endregion
#pragma region Self Options
	case Self_Options:
		addTitle("Self Options");
		addSubmenuOption("Wanted level editor", wanted_options);
		addBoolOption("Godmode", god);
		addBoolOption("Invisibility", inviso);
		addBoolOption("Fast Run", fastrun);
		addBoolOption("Fast Swim", fastswim);
		
		switch (getOption())
		{
		case 2: god = !god; break;       //ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_ID(), !PLAYER::GET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID())); break;dildmoney = !dildmoney; break;
		case 3: inviso = !inviso;  break;

		case 4: fastrun = !fastrun; break;
		case 5: fastswim = !fastswim; break;
		}

		//god mode
		if (god == false) {
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
			//	drawNotification("God Mode: ~b~Disabled");
		}
		else
		{
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
			//		drawNotification("God Mode: ~b~Enabled");
		}
		//invis
		if (inviso == false)
		{
			//lol that should do it
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);
			//		drawNotification("Invisibility: ~b~Enabled");
		}
		else
		{
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, false);
			//		drawNotification("Invisibility: ~r~Disabled");
		}
		// fast run
		if (fastrun == false)
		{
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1.0f);
		}
		else
		{
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 2.0f);
		}
		if (fastswim == false)
		{
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 1.0f);
		}
		else
		{
			Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 2.0f);
		}

		break;
#pragma endregion
#pragma region weaponoptions
	case weapons_options:
		addTitle("Weapon Options");
		addOption("give all weapons");
		addbool2("Infinate ammo", infammo);
		addbool2("Explosive ammo", explosiveammo);
		addbool2("Fire ammo", fireammo);
		if (getOption() == 1)
		{
			uint Weapons[] = { 0xDFE37640, 0xC1B3C3D1, 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D, GAMEPLAY::GET_HASH_KEY("WEAPON_HATCHET"), GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN") };
			for (int i = 0; i < (sizeof(Weapons) / 4); i++)
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);

		}
		if (getOption() == 2)
		{
			infammo = !infammo;
		}
		if (getOption() == 3)
		{
			explosiveammo = !explosiveammo;
		}
		if (getOption() == 4)
		{
			fireammo = !fireammo;
		}

		break;
#pragma endregion

#pragma region Settings
	case Settings:
		addTitle("Settings (needs work)");
	//	addSubmenuOption("Banners", Settings_Banners);
		addSubmenuOption("Body", Settings_Body);
	//	addSubmenuOption("Scroller", Settings_Scroller);
	//	addSubmenuOption("Indicators", Settings_Indicators);
	//	addBoolOption("Sounds", menuSounds);
	//	addBoolOption("Instructions", instructions);
	//	addCustomBoolOption("Left Sided", menuXCoord, 0.145f);
		addIntOption("Max Options", &maxOptions, 1, 20, false);
		switch (getOption())
		{
		case 5: menuSounds = !menuSounds; break;
		case 6: instructions = !instructions; break;
		case 7:
			if (menuXCoord == 0.145f)
			{
				menuXCoord = 0.845f;
				textXCoord = 0.76f;
			}
			else
			{
				menuXCoord = 0.145f;
				textXCoord = 0.06f;
			}
			break;
		}
		break;
	case Settings_Banners:
		addTitle("Banners");
		addIntOption("Text Red", &bannerTextRed, 0, 255, true);
		addIntOption("Text Green", &bannerTextGreen, 0, 255, true);
		addIntOption("Text Blue", &bannerTextBlue, 0, 255, true);
		addIntOption("Text Opacity", &bannerTextOpacity, 0, 255, true);
		addIntOption("Text Font", &bannerTextFont, 0, 7, false);
		addIntOption("Rect Red", &bannerRectRed, 0, 255, true);
		addIntOption("Rect Green", &bannerRectGreen, 0, 255, true);
		addIntOption("Rect Blue", &bannerRectBlue, 0, 255, true);
		addIntOption("Rect Opacity", &bannerRectOpacity, 0, 255, true);
		break;
	case Settings_Body:
		addTitle("Body");
		addIntOption("Text Red", &optionsRed, 0, 255, true);
		addIntOption("Text Green", &optionsGreen, 0, 255, true);
		addIntOption("Text Blue", &optionsBlue, 0, 255, true);
		addIntOption("Text Opacity", &optionsOpacity, 0, 255, true);
		addIntOption("Text Font", &optionsFont, 0, 7, false);
		addIntOption("Rect Red", &backgroundRed, 0, 255, true);
		addIntOption("Rect Green", &backgroundGreen, 0, 255, true);
		addIntOption("Rect Blue", &backgroundBlue, 0, 255, true);
		addIntOption("Rect Opacity", &backgroundOpacity, 0, 255, true);
		break;
	case Settings_Scroller:
		addTitle("Scroller");
		addIntOption("Red", &scrollerRed, 0, 255, true);
		addIntOption("Green", &scrollerGreen, 0, 255, true);
		addIntOption("Blue", &scrollerBlue, 0, 255, true);
		addIntOption("Opacity", &scrollerOpacity, 0, 255, true);
		break;
	case Settings_Indicators:
		addTitle("Indicators");
		addIntOption("Red", &indicatorRed, 0, 255, true);
		addIntOption("Green", &indicatorGreen, 0, 255, true);
		addIntOption("Blue", &indicatorBlue, 0, 255, true);
		addIntOption("Opacity", &indicatorOpacity, 0, 255, true);
		break;
#pragma endregion
#pragma region veh spawner
	case Vehicle_Spawner:
		addTitle("Vehicle Spawner");

		addSubmenuOption("Smugglers Run", smugglers_run);
		addSubmenuOption("Gunrunning", Gunrunning);
		addSubmenuOption("Super", Super);
		addSubmenuOption("Sports", Sports);
		addSubmenuOption("Sport Classic", SportClassic);
		addSubmenuOption("Offroad", Offroad);
		addSubmenuOption("Sedans", Sedans);
		addSubmenuOption("Coupes", Coupes);
		addSubmenuOption("Muscle", Muscle);
		addSubmenuOption("Boats", Boats);
		addSubmenuOption("Commercial", Commercial);
		addSubmenuOption("Compacts", Compacts);
		addSubmenuOption("Cycles", Cycles);
		addSubmenuOption("Emergency", Emergency);
		addSubmenuOption("Helicopters", Helicopters);
		addSubmenuOption("Industrial", Industrial);
		addSubmenuOption("Military", Military);
		addSubmenuOption("Motorcycles", Motorcycles);
		addSubmenuOption("Planes", Planes);
		addSubmenuOption("Service", Service);
		addSubmenuOption("SUV", SUV);
		addSubmenuOption("Trailer", Trailer);
		addSubmenuOption("Trains", Trains);
		addSubmenuOption("Utility", Utility);
		addSubmenuOption("Vans", Vans);
	//	Menu::Bool("Spawn in Car", Features::spawnincar);
	//	Menu::Bool("Spawn Maxed", Features::spawnmaxed);

		break;
	case Super:
		addTitle("Super");
		for (auto car : Super1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Gunrunning:
		addTitle("Gunrunning");
		for (auto car : Gunrunning1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Sports:
		addTitle("Sports");
		for (auto car : Sports1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case SportClassic:
		addTitle("Sports Classic");
		for (auto car : SportsClassics1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Offroad:
		addTitle("Offroad");
		for (auto car : OffRoad1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Sedans:
		addTitle("Sedans");
		for (auto car : Sedans1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Coupes:
		addTitle("Coupes");
		for (auto car : Coupes1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Muscle:
		addTitle("Muscle");
		for (auto car : Muscle1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Boats:
		addTitle("Boats");
		for (auto car : Boats1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Commercial:
		addTitle("Commercial");
		for (auto car : Commercial1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Compacts:
		addTitle("Compacts");
		for (auto car : Compacts1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Cycles:
		addTitle("Cycles");
		for (auto car : Cycles1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Emergency:
		addTitle("Emergency");
		for (auto car : Emergency1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Helicopters:
		addTitle("Helicopters");
		for (auto car : Helicopters1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Industrial:
		addTitle("Industrial");
		for (auto car : Industrial1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Military:
		addTitle("Military");
		for (auto car : Military1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Motorcycles:
		addTitle("Motorcycles");
		for (auto car : Motorcycles1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Planes:
		addTitle("Planes");
		for (auto car : Planes1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Service:
		addTitle("Service");
		for (auto car : Service1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case SUV:
		addTitle("SUV");
		for (auto car : SUVs1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Trailer:
		addTitle("Trailer");
		for (auto car : Trailer1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Trains:
		addTitle("Trains");
		for (auto car : Trains1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Utility:
		addTitle("Utility");
		for (auto car : Utility1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case Vans:
		addTitle("Vans");
		for (auto car : Vans1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
	case smugglers_run:
		addTitle("Smugglers Run");
		for (auto car : smugglers1) { addop2(car, [car] { Features::spawn_vehicle(car); }); }
		break;
		break;
#pragma endregion 
#pragma endregion 
	}
	resetVars();
	return true;
}




#pragma endregion




void main() {
	//	reset_globals();
		while (true) {
			if (trainer_switch_pressed()) {
				static bool first_time = false;
				if (!first_time)
				{
				//	welcomeMessage();
					first_time = true;
				}

				menu_beep(NAV_OPEN);
				Hook();
			}
			update_features();
		//	kteleport();
			WAIT(0);
		}
	}

void ScriptMain() {
	srand(GetTickCount());
	main();
}











