#include "stdafx.h"
#include "menuMain.h"
#include "menuFeatures.h"
#include "gameFeatures.h"
#include "menuEnums.h"
//#include "WebFunctions.h"
#include "shellapi.h"


/*
Shit to add for 0.5.3

-lsc
-colour changer
-money gun
- THIS GOD DAMN FUCKING STEALTH WHY IS IT SO HARD 





*/




//#include "test2.h"

//https://www.youtube.com/watch?v=8C1dsCzfwY8





; using namespace sub;
using namespace VEHICLE;

//Char arrays
int stringIndex, vehString, LSString, teleString, lobbyString = 0, attkString = 0, lscmodstring = 0, vehoptionsstring;
char* strings[] = {

	"Hello 1",
	"Hello 2",
	"Hello 3",
	"Hello 4"

};

char* upgrades[]{ "Performance", "Visuals", "Wheels", "Benny's Mods" };
char* upgradeEMS[]{ "Stock", "EMS Upgrade, Level 1", "EMS Upgrade, Level 2", "EMS Upgrade, Level 3", "EMS Upgrade, Level 4", "EMS Upgrade, Level 5" };
char* upgradeBrakes[]{ "Stock Brakes", "Street Brakes", "Sport Brakes", "Race Brakes" };
char* upgradeSuspension[]{ "Stock Suspension", "Lowered Suspension", "Street Suspension", "Sport Suspension", "Competition Suspension" };
char* upgradeTransmission[]{ "Stock Transmission", "Street Transmission", "Sports Transmission", "Race Transmission" };
char* upgradeArmour[]{ "None", "20%", "40%", "60&", "80%", "100%" };
char* wheelTypes[]{ "Sport", "Muscle", "Lowrider", "SUV", "Offroad", "Tuner", "Bike", "High End", "Benny's Classic", "Benny's Bespoke" };
char* lobbyRest[]{ "Everyone", "Friends Only", "Everyone except Friends" };
char* Types[]{ "Presets", "Peds", "Vehicles", "Squads" };
char* frontbumper[]{"Level 1", "Level 2", "Level 3", "Level 4"};
Attacker
Jesus = { "Angry Jesus", "", "", false, PED_MALE },
Cop = { "Crooked Cop", "", "", true, PED_COP },
Swat = { "Swat Team", "s_m_y_swat_01", "weapon_stungun", true, PED_SWAT },
SwatRiot = { "Swat Riot Squad", "s_m_y_swat_01", "weapon_stungun", true, PED_SWAT, "riot" }
;

Attacker types[]{ Jesus, Cop, Swat, SwatRiot };

RGBA colourName = { 255, 255, 255, 255 };

//Variables
bool notification	= false;
bool toggle			= false;
int integer			= 1;
float float1		= 1.0f;
Ped selPed			= 0ul;
Vehicle playerVeh;
Player selPlayer = NULL;
char* selPlayerName;


// vehicle spawner options

bool Money_prop_gun = false;

//player bools
bool playerGodMode = false, playerSuperJump = false, playerInvisible = false, playerNeverWanted = false, accessAreas = false, ragdolltoggle = false, unlimitedradar = false, ragdollActive = false, fastrun = false, fastswim = false;

//vehicle bools
bool vehInvincible = false, vehInvincibleWheels = false, vehInvisible = false, vehSeatbelt = false, vehSpeedBoost = false, vehAirEnabled = false, vehDriveOnWater = false, 
vehKaboom = false, vehEject = false, vehicleJump = false, vehScrollActive = false, vehChr0m3Speedo = false, turbo = false, hornboost = false, godcar = false, rainbowcar = false;

//vehicle floats
float vehDefMult = 1.f, vehDamMult = 1.f;

//vehicle ints
int speedoPos = 1, engine, transmission, brakes, suspension, armour, modIndex, modIndexes[50], wheels = 0, FRONTBUMPER, REARBUMPER, SIDESKIRT, SPOILER, EXHAUST, CHASSIS, GRILLE, HOOD, FENDER, RIGHTFENDER, ROOF, HORNS, UNK17, UNK19, TIRESMOKE, UNK21, XENONLIGHTS;

//bennys ints
//look in discord
//weapon bools
bool wepAmmoExplosive, wepAmmoFire, wepDamage, wepAmmoInfClip, wepAmmoInfinite, wepMeleeExplosive;

float waveheight = 0;
//misc bools
bool miscMobileRadio, miscRainbowMode, miscHideHUD, waveHeight;

//world bools
bool worldSync;

//online vars
bool netKillPeds[32], netFreezePlayer[32], netFuckCam[32], netAnnoyingLoop[32], netForceField[32], netTrack[32], netStealth[32], netStealth2[32], lobbyESP, lobbyCash, lobbyFreeze, lobbyFuckCam, lobbForceField, lobbyExplode, dildoTest[32];
unsigned int ExplodeDelay = 0, StealthDelay = 0;
int remoteInt = 0;

//recovery bools
bool toBank = true, stealth = false, dildodroponline = false, moneyrain = false, stealthtest = false, stealthtest2 = false;
//recovery ints
int dropAmount = 200000, intStep = 100000;

std::function<void()> recoveryFunc[]{ [] {recovery::bypassSellTimer(); },[] {recovery::clearBadSport(); },[] {recovery::RemoveBadSport(); },
[] {recovery::enableRoosevelt(); },[] {recovery::clearReports(); },[] {recovery::unlockHeistVehicles(); },[] {recovery::maxStats(); },
[] {recovery::unlockTattoos(); },[] {recovery::unlimitedSnacks(); },[] {recovery::unlimitedArmour(); },[] {recovery::unlimitedFireworks(); },
[] {recovery::unlockCamoParachutes(); },[] {recovery::unlockChromeRims(); },[] {recovery::unlockTshirts(); },[] {recovery::unlockVehicleMods(); },
[] {recovery::characterPrompt(); },[] {recovery::skipTutorial(); },[] {recovery::unlockAllAwards(); },[] {recovery::unlockHeistTrophies(); },
[] {recovery::unlockAllHairstyles(); },[] {recovery::ownAllWeapons(); },[] {recovery::unlockAll(); } };
char* recoveryFuncName[]{ "Bypass Sell Timer", "Clear Bad Sport", "Remove Bad Sport", "Enable Roosevelt (patched)", "Clear Reports", "Unlock Heist Vehicles",
"Max Stats", "Unlock Tattoos", "Unlimited Snacks", "Unlimited Armour", "Unlimited Fireworks", "Unlock Camo Parachutes", "Unlock Chrome Rims",
"Unlock All T-Shirts", "Unlock All Vehicle Mods", "Reset Character Prompt (patched)", "Skip Tutorials", "Unlock All Awards", "Unlock Heist Trophies",
"Unlock All Hairstyles", "Own All Weapons", "Unlock All" };


static char* smugglers1[] = {//19
	"VIGILANTE", "BOMBUSHKA", "ALPHAZ1", "TULA", "HUNTER",
	"ROGUE", "PYRO", "MOGUL", "NOKOTA", "MOLOTOK", "SEABREEZE",
	"HAVOK", "microlight", "HOWARD", "STARLING", "RAPIDGT3",
	"RETINUE", "CYCLONE", "VISIONE"
};
static char* Gunrunning1[] = {//19
	"APC", "Ardent", "Caddy3", "Cheetah2", "Dune3", "Halftrack", "Hauler2", "Insurgent3",
	"Nightshark", "Oppressor", "Phantom3", "Tampa3", "Technical13", "Torero", "TrailerLarge",
	"Trailers4", "Trailersma11", "Vagner", "Xa21"
};

static Hash SuperCars[] {
	0x92EF6E04, 0xB779A091, 0x9AE6DDA1, 0x25C5AF13, 0xB1D95DA0, 0xB2FE5CF9, 0x30D3F6D8, 0x5502626C, 0x4992196C,
	0x18F25AC7, 0x85E8E76B, 0xE33A477B, 0x3DA47243, 0x4131F378, 0xB6846A55, 0x767164D6, 0x9734F3EA, 0x0DF381E5,
	0x3AF76F4A, 0xEE6024BC, 0x6322B39A, 0x1044926F, 0x185484E1, 0x7B406EFB, 0x142E0DC3, 0x9F4B77BE, 0x7E8F677F,
	0xAC5DF515, 0x7397224C, 0x36B4A8A9
};
static Hash SportsCars[] {
	0x3D8FA25C, 0xA8E38B01, 0x2DB8D1AA, 0xC1E908D2, 0x4BFCF28B, 0x3DEE5EDA, 0xEDD516C6, 0x2BEC3CBE, 0x7B8AB45F,
	0xC1AE4D16, 0x877358AD, 0x067BC037, 0xC0240885, 0xDE3D9D22, 0x0BBA2261, 0x8911B9F5, 0xBF1691E0, 0x1DC0BA53,
	0x7836CE2F, 0xDCBC1C3B, 0xB2A716A3, 0xBE0E6126, 0x206D1B68, 0xAE2BFE94, 0x187D938D, 0x1CBDC10B, 0xF77ADE32,
	0xDA5819A3, 0xD1AD4937, 0xE9805550, 0x8CB29A14, 0x679450AF, 0xD7C56D39, 0x2AE524A8, 0x58CF185C, 0xA774B5A6,
	0xD37B7976, 0x97398A4B, 0x706E2B40, 0x400F5147, 0x0E2C013E, 0x39DA2754, 0x16E478C1, 0x707E63A4, 0x41B77FA4,
	0x41B77FA4, 0x41B77FA4,
};
static Hash SportsClassic[] {
	0x3822BDFE, 0x3C4E2113, 0xCE6B35A4, 0xAC33179C, 0x3EAB5555, 0x9CFFFC56, 0xE62B361B, 0x6D19CCBC, 0x404B6381,
	0x06FF6914, 0xDC19D101, 0x5C23AF9B, 0x82E499FA, 0xA29D6D10, 0x1BB290BC, 0x690A4153, 0x86CF7CDD, 0x94DA98EF,
	0xA31CB573, 0xC575DF11, 0x2D3BD401, 0x59A9E570, 0x0D4E5F4D, 0x097E5533
};
static Hash Coupe[] {
	0x13B57D8A, 0xFFB15B5E, 0xDCBCBE48, 0xE8A8BDA8, 0xFAAD85EE, 0xDAC67112, 0xE18195B2, 0x506434F6, 0x3412AE2D,
	0x50732C82, 0x5E4327C8, 0x8CF5CAE1, 0xBD1B39C3, 0xB8E2AE18
};
static char* Muscle[] {
	"blade", "buccaneer", "buccaneer2", "stalion2", "chino", "chino", "chino2", "coquette3", "dominator", "dukes2",
	"dukes", "faction", "faction2", "faction3", "gauntlet", "hotknife", "slamvan", "lurcher", "moonbeam", "moonbeam2",
	"nightshade", "phoenix", "picador", "dominator2", "ratloader", "ratloader2", "gauntlet2", "ruiner", "ruiner2",
	"ruiner3", "sabregt", "sabregt2", "slamvan2", "slamvan3", "stalion", "tampa", "TAMPA3", "vigero", "virgo", "virgo3", "virgo2",
	"voodoo2", "voodoo"
};
static char* Boats[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};
static char* Commercial[] = {
	"BENSON", "BIFF", "HAULER", "HAULER2", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "PHANTOM2", "PHANTOM3", "POUNDER", "STOCKADE",
	"STOCKADE3"
};
static char* Compacts[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
};
static char* Cycles[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};
static char* Emergency[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
};
static char* Helicopters[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
};
static char* Industrial[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};
static char* Military[] = {
	"APC", "BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "HALFTRACK", "RHINO"
};
static char* Motorcycles[] = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "OPPRESSOR", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2"
};
static char* OffRoad[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "DUNE3", "INSURGENT", "INSURGENT2", "INSURGENT3", "KALAHARI",
	"NIGHTSHARK", "MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "TECHNICAL3", "DUNE4", "DUNE5",
	"BLAZER5"
};
static char* Planes[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
};
static char* Sedans[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
};
static char* Service[] = {
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
	"WASTELANDER",
};
static char* SUVs[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
};
static char* Trailer[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
};
static char* Trains[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};
static char* Utility[] = {
	"AIRTUG", "CADDY", "CADDY2", "CADDY3", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"TRAILERLARGE", "TRAILERS4", "TRAILERSMALL2", "UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
};
static char* Vans[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};

void AddPlayer(char *name, Player player, char *info = NULL)
{
	char buf[50], ibuf[50];
	if (player == PLAYER::PLAYER_ID()) {
		snprintf(buf, sizeof(buf), "%s~g~ [SELF] ", name);
		AddOption(buf, "~g~SELF");
	}
	else if (NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(player)) {
		snprintf(buf, sizeof(buf), "%s~r~ [ROCKSTAR/MODDER]", name);
		AddOption(buf, "~r~ROCKSTAR/MODDER");
	}
	else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", -1, 0) == player) {
		snprintf(buf, sizeof(buf), "%s~y~ [HOST]", name);
		AddOption(buf, "~y~SESSION HOST");
	}
	else if (online::isPlayerFriend(player)) {
		snprintf(buf, sizeof(buf), "%s~b~ [FRIEND] ", name);
		AddOption(buf, "~b~FRIEND ");
	}
	else
		AddOption(name, "");

	if (currentOption == optionCount && optionPress()) {

		//Set our variables and change the submenu
		selPlayer = player;
		selPlayerName = name;
		PlayFrontendSound("SELECT");
		changeSubmenu(SUB::PLAYEROPTIONS);
	}

}

//Anything that needs to be looped is in here
void Loops()
{


	//look in discord



	if (notification)
		game::notifyBottom("Hai :)");

	//PLAYER LOOPS
	if (playerSuperJump)
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
	if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RLEFT) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RRIGHT))
		player::ragdollSwitch();
	if (ragdollActive)
		player::loopRagdoll();
/*	if (playerGodMode) {
		if (ENTITY::GET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID()) < 1000)
			ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 1000);
		ENTITY::SET_ENTITY_PROOFS(PLAYER::PLAYER_PED_ID(), 1, 1, 1, 1, 1, 1, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
	}*/
	if (playerGodMode == false) {
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
		//	drawNotification("God Mode: ~b~Disabled");
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		//		drawNotification("God Mode: ~b~Enabled");
	}
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
/*	if (playerInvisible) {
		if (ENTITY::GET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID()) != 0.f)
			ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 0, 1);
		if (ENTITY::IS_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID()))
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);
	}*/
	if (playerInvisible == false)
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
	if (playerNeverWanted == false) {
	//	PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), false);
		PLAYER::SET_MAX_WANTED_LEVEL(5);
	}
	else {
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), 1);
		PLAYER::SET_MAX_WANTED_LEVEL(0);
	}

	//VEHICLE LOOPS
	if (vehAirEnabled)
		vehicle::loop_vehAirRide(PLAYER::GET_PLAYERS_LAST_VEHICLE());
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
		if (vehSpeedBoost)
			vehicle::speedBoost();
		if (vehicleJump) {
			if (KeyJustUp(VK_SPACE) || PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID())) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				if (IS_VEHICLE_ON_ALL_WHEELS(veh))
					ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0 + ENTITY::GET_ENTITY_FORWARD_X(veh), 0 + ENTITY::GET_ENTITY_FORWARD_Y(veh), 7, 0, 0, 0, 1, 0, 1, 1, 1, 1);
			}
		}
		if (vehDriveOnWater)
			vehicle::loop_driveOnWater();
		if (vehEject)
			vehicle::loop_ejectorSeat();
		if (vehChr0m3Speedo)
			vehicle::loop_chr0m3Speedo(1, 1, 0, speedoPos);
	}

	//WEAPON LOOPS
	if (wepAmmoExplosive)
		GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
	if (wepAmmoFire)
		GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
	if (wepAmmoInfClip)
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), 1);
	if (wepAmmoInfinite)
		weapon::loop_infiniteAmmo(PLAYER::PLAYER_PED_ID());
	if (wepMeleeExplosive)
		GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());

	//RECOVERY LOOPS
	if (stealth)
		if (StealthDelay < GetTickCount())
			recovery::sixhundeestealth();
			//recovery::testnetcash(toBank, dropAmount);

	//MISC LOOPS
	if (miscHideHUD)
		misc::hide_hud();
	if (miscMobileRadio)
		misc::mobile_radio();
	if (miscRainbowMode)
		misc::loop_rainbowMenu(&bannerRect, &scrollerCol, &highlight);
	if (waveHeight == false) {

	}
	else {
		WATER::_SET_WAVES_INTENSITY(waveheight);
	}

	//WORLD LOOPS
	if (worldSync)
		world::time_sync();

	//ONLINE LOOPS
	int TimePD1;
	if (moneyrain == true) {
		int CashHash = -422877666; // money bag = 0x113FD533
		Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 10.0);
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(5, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(5, 15);

		if ((timeGetTime() - TimePD1) > 4000) // Time between drops
		{
			int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
			STREAMING::REQUEST_MODEL(CashHash);
			while (!STREAMING::HAS_MODEL_LOADED(CashHash)) WAIT(0);
			OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, pp.x + offset1, pp.y + offset2, pp.z, 0, 2000, CashHash, false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(CashHash);
		}
	}
	if (dildodroponline == true) {
		Ped iPed = PLAYER::GET_PLAYER_PED(selPlayer);
		{

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
	if (hornboost == true) {
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		if (AUDIO::IS_HORN_ACTIVE(veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 50.f);
		}

	}

	if (rainbowcar == true) {

		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);

		if (PED::IS_PED_IN_ANY_VEHICLE) {
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);

		}

	}

	if (godcar == true) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, godcar);
			ENTITY::SET_ENTITY_PROOFS(vehicle, godcar, godcar, godcar, godcar, godcar, godcar, godcar, godcar);
			VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
			VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, godcar);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, godcar);
			VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !godcar);
			VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !godcar);
			VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !godcar);
			VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !godcar);
			VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !godcar);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !godcar);
		}
	}

	if (Money_prop_gun == true) {





	}

	if (NETWORK::NETWORK_IS_SESSION_STARTED()) {
		for (int i = 0; i < 30; i++)
		{
			Ped playerPed = game::GET_PLAYER_PED(i);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(playerPed, true);

			bool validPlayer = NETWORK::NETWORK_IS_PLAYER_CONNECTED(i);

			if (netKillPeds[i])
			{
				if (!validPlayer) netKillPeds[i] = false;
				else
				{
					online::loop_killpeds(i);
				}
			}

			if (netFreezePlayer[i] || lobbyFreeze)
			{
				if (!validPlayer) netFreezePlayer[i] = false;
				else
					if (ExplodeDelay < GetTickCount())
					{
						online::loop_freezePlayer(i);
					}
			}
			if (netFuckCam[i] || lobbyFuckCam)
			{
				if (!validPlayer) netFuckCam[i] = false;
				else
					if (ExplodeDelay < GetTickCount())
					{
						online::loop_fuckCam(i);
					}
			}
			if (netAnnoyingLoop[i] || lobbyExplode)
			{
				if (!validPlayer) netAnnoyingLoop[i] = false;
				else
					if (ExplodeDelay < GetTickCount())
					{
						online::loop_annoyBomb(i);
					}
			}
			if (netForceField[i] || lobbForceField)
			{
				if (!validPlayer) netForceField[i] = false;
				else
					if (ExplodeDelay < GetTickCount())
					{
						online::loop_forcefield(i);
					}
			}
			if (netTrack[i] || lobbyESP)
			{
				if (!validPlayer) netTrack[i] = false;
				else
					online::loop_esp(i, bannerRect.R, bannerRect.G, bannerRect.B);
			}
			if (NETWORK::NETWORK_IS_SESSION_STARTED()) {

				if (stealthtest == true) {

					stealthtwelve(true, true);
				}
				if (stealthtest2 == true) {

					int transactionCode = -1586170317;// 15 M $
													  //int transactionCode = 1982688246; // 90 M $
					int cash_to_receive = 15000000;
					bool toBank = true;//why the fuck are calling in main
					int transactionID = 1146239992;
					if (Hooking::network_shop_begin_service(&transactionID, 1474183246, transactionCode, 1445302971, cash_to_receive, toBank ? 4 : 1))
					UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);//wtf is this
				}

				if (dildoTest[i]) {
					if (!validPlayer) dildoTest[i] = false;
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
				if (netStealth[i]) {
					if (!validPlayer) netStealth[i] = false;
					else
						if (StealthDelay < GetTickCount())
							online::remoteSilent(i);
				}
				if (netStealth2[i] || lobbyCash) {
					if (!validPlayer)netStealth2[i] = false;
					else
						if (StealthDelay < GetTickCount())
							online::remote50k(i);
				}
			}
		}
		if (StealthDelay < GetTickCount())	StealthDelay = GetTickCount() + 120;
		if (ExplodeDelay < GetTickCount())  ExplodeDelay = GetTickCount() + 200;
	}
}

//Define submenus
namespace sub {

	Ini *settingsIni = new Ini(".\\settings.ini");
	string user = settingsIni->GetString("Login", "User");
	string pw = settingsIni->GetString("Login", "Pass");
	void sub::MainMenu()
	{
		AddTitle("Main Menu");


		
		AddSubmenu("Player", SUB::PLAYER, "this aint no skid");
		AddSubmenu("Weapon", SUB::WEAPON, "Wawixs is pretty cool");
		AddSubmenu("Vehicle", SUB::VEHICLE, "So is casp3r");
		AddSubmenu("Teleport", SUB::TELEPORT, "Dont crack my shit");
		AddSubmenu("Recovery Options", SUB::RECOVERY, "Unban me on xen pls");
		AddSubmenu("Online Options", SUB::ONLINE, "The infamous devs are bae");
     	AddSubmenu("World Options", SUB::WORLD, "HI YOUTUBE!!");
		AddSubmenu("Misc", SUB::MISC, "Please stop calling me gay ):");
		AddSubmenu("Settings", SUB::SETTINGS, "I touched a willy in highschool once");
		AddSubmenu("credits", SUB::CREDITS, "and it was just a little mistake");
		switch (currentOption) {
		case 3: selPed = PLAYER::PLAYER_PED_ID(); break;
		}
		/*AddSubmenu("Submenu1", SUB::SUBMENU1, "This is a submenu!");
		AddSubmenu("Scroller", SUB::SRCOLLER, "This is another submenu!");
		AddSubmenu("Settings", SUB::SETTINGS, "Customize your menu.");*/
	}
	void sub::credits() {
		AddTitle("Credits");
		

		AddOption("gradienthacks.com", [] {	ShellExecute(NULL, L"open", L"http://gradienthacks.com/", NULL, NULL, SW_SHOWNORMAL);  }, "");
		AddOption("paulth2gaming - auth", [] {}, "");
		AddOption("Uberlije - auth/launcher", [] {} , "");
		AddOption("Mr. Anonymous - stealth transaction ids", [] {}, "");
		AddOption("Based on job menu (with major parts re-written)", [] {}, "");
		AddOption("Infamous Dev Team", [] { ShellExecute(NULL, L"open", L"https://static.fjcdn.com/pictures/Expand+dong+comp+_44af51_5261181.jpg", NULL, NULL, SW_SHOWNORMAL); }, "");
		AddOption("^^ for sudomod ^^", [] {}, "");
		AddOption("opal for slothority, opalbeats", [] { ShellExecute(NULL, L"open", L"https://luxx.menu/", NULL, NULL, SW_SHOWNORMAL); }, "");
		AddOption("The poopstar devs", [] {}, "");
		AddOption("Alexander Blade", [] {}, "");
		AddOption("Sudo for teaching me how to get sigs", [] {}, "");
		AddOption("^^ and wawixs and taranVG for failing ^^", [] {}, "");
		AddOption("sub1to for subVersion's hook  (v0.4)", [] {}, "");
		AddOption("-------------------------------------------", [] {}, "");
		AddOption("worked on by:", [] {}, "");
		AddOption("Sinfool#2522", [] {}, "");

	}
	void sub::Settings()
	{
		AddTitle("SETTINGS");
		AddSubmenu("Header", SUB::HEADER, "Change the header colour");
		AddSubmenu("Options", SUB::OPTIONS, "Change the options colour");
	//	AddToggle("Gradients", &gradients, "Once toggled, cool fades will appear.");
	}

	void sub::online() {
		AddTitle("Online Options");
		AddSubmenu("Player List", SUB::PLAYERLIST, "");
		AddSubmenu("Lobby Options", SUB::LOBBY, "");
	}
	void sub::recovery() {
		AddTitle("Recovery");
		AddSubmenu("Online Recovery", SUB::ONLINE_RECOVERY, "");
		AddSubmenu("Offline Recovery", SUB::OFFLINE_RECOVERY, "");
	}

	void sub::onlinerecovery() {
		AddTitle("Online Options");
		AddToggle("Money Rain", &moneyrain, "");
		AddSubmenu("Set level", SUB::SETRP, "");
		AddOption("Unlock All", [] {recovery::unlockAll(); }, "");
		AddOption("Max Stats", [] {recovery::maxStats(); }, "");
		//	AddSubmenu("Stat Editor", SUB::STATS, "Full List of ~b~Recovery Stats");
			//	AddToggle("Stealth Loop", &stealth, "");
	//	stealthTextbs();
		if (user == "sinfool") {
		//	AddToggle("12Mil Drop", sdrop, "");
		//		sdrop = !sdrop;
			AddOption("50k (ban predicted)", [] { online::remote50K3(PLAYER::PLAYER_ID()); }, "");


		AddToggle("stealth test 1", &stealthtest, "");
		AddToggle("Stelath test 2 15mil", &stealthtest2, "");
		AddOption("stealth", [] {/*recovery::netcash(toBank, dropAmount);*/
			int TimePD3;
			if ((timeGetTime() - TimePD3) > 1)
			{
				int var0 = 0ul;
				int var3 = 393059668;//now where do you call it oi!!!!!!!
				int bankVal = 1;//loop it and name the function k

				if (!toBank)
					bankVal = 4;

				Hooking::network_shop_begin_service(&var0, 1474183246, var3, 0x562592BB, 12000000, bankVal);
				UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

				TimePD3 = timeGetTime();
			}
			//where is it 

			//the hook or the stealth code? i assume the code





		}, "");//	void netcash(bool stealthBank, int value)
	}


				  //AddInt("Set Amount", &dropAmount, 0, 15000000, intStep, "Changes the amount give by stealth drop");
			  //AddToggle("ToBank", &toBank, "");
	}
	void sub::setrp() {
		AddTitle("Set Level");
		addrpOption("level 100", 1584350, "");		addrpOption("level 200", 4691850, "");		addrpOption("level 300", 8299350, "");		addrpOption("level 400", 12406850, "");		addrpOption("level 500", 17014350, "");		addrpOption("level 600", 22121850, "");		addrpOption("level 700", 27729350, "");		addrpOption("level 800", 33836850, "");		addrpOption("level 900", 40444350, "");		addrpOption("level 1000", 47551850, "");
		addrpOption("Level 2000", 293314850, "");
		addrpOption("Level 3000", 491489850, "");
		addrpOption("Level 8000 (be carefull)", 1787576850, "");




	}
	void sub::offlinerecovery() {
		AddTitle("Offline Recovery");
		AddOption("10 million", [] {
		
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
		
		
		
		
		}, "SINGLE PLAYER ONLY");
		AddOption("1 million", [] {
		
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
		
		
		
		
		}, "SINGLE PLAYER ONLY");
		AddOption("100 thousand", [] {
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
		}, "SINGLE PLAYER ONLY");
	}



	void sub::statEditor() {
		AddTitle("Stat Editor");
		for (int ival = 0; ival < 22; ival++) {
			AddOption(recoveryFuncName[ival], recoveryFunc[ival], "");
		}
		//AddOption("Set Rank", [] {recovery::setRank(); }, "");
	}
	void sub::playerList() {
		AddTitle("Players List");
		char buf[30];
		Ped selectedPed = 0ul;
		Vehicle veh = 0ul;
		for (int i = 0; i < 32; i++)
		{
			if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", -1, 0) == i) {
				snprintf(buf, sizeof(buf), "%s~y~ [HOST]", PLAYER::GET_PLAYER_NAME(i));
				AddOption(buf, "~y~SESSION HOST");
			}
			else if (NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(i)) {
				snprintf(buf, sizeof(buf), "%s~r~ [ROCKSTAR/MODDER]", PLAYER::GET_PLAYER_NAME(i));
				AddOption(buf, "~r~ROCKSTAR ADMIN/MODDER");
			}
			else if (online::isPlayerFriend(i)) {
				snprintf(buf, sizeof(buf), "%s~b~ [FRIEND]", PLAYER::GET_PLAYER_NAME(i));
				AddOption(buf, "~b~FRIEND");
			}
			else
				AddOption(PLAYER::GET_PLAYER_NAME(i), "");
			if (i == 32)
				break;
		}
		if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
		{
			selPlayer = currentOption - 1;
			changeSubmenu(SUB::PLAYER);
		}
	}
	void sub::PlayerIndex()
	{
		AddTitle("Player Index");
		for (int i = 0; i < 32; i++) {
			char* playerName = PLAYER::GET_PLAYER_NAME(i);
			if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i))
			{
				AddPlayer(playerName, i, "");
			}
		}
	}
	void selplayerinfobox() {
		GRAPHICS::DRAW_RECT(MainBackGroundX - 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f ,0.175f, 0.255f, background.R, background.G, background.B, background.A); // not working
	}
	void sub::PlayerMenu()
	{
	 SelPlayerInfoStolenFromGalaxyLOLFIghtME(PLAYER::GET_PLAYER_NAME(selPlayer), selPlayer);
		if (strcmp(selPlayerName, "[Invalid]") == 0);
		selPed = game::GET_PLAYER_PED(selPlayer);
		AddTitle(selPlayerName);
		AddSubmenu("Attach Objects (BETA)", SUB::ONLINE_ATTACHMENT_SEL_PLAYER, "");
	//	AddToggle("2k drop", &dildodroponline,"");
		AddToggle("2k drop (online only)", &dildoTest[selPlayer], "smexy");
	//	AddSubmenu("Send Attackers", SUB::ATTACKERS, "outsource everything"); //3
		AddSubmenu("Give Vehicle", SUB::VEHICLESPAWNER, "");
	//	AddOption("Clone Vehicle", [] {vehicle::clone(selPlayer); }, ""); //2
		//dildoTest
//		AddToggle("Give 50K (silent)", &netStealth[selPlayer], "WIP");
		//AddToggle("Give 50K (securoserv)", &netStealth2[selPlayer], "WIP");
	//	AddOption("Give Firework Launcher", "WIP"); //4
		AddOption("Teleport To Player", [] {
		
	
		

			Entity handle;
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selPlayer), false);
			PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
			ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
		
		}, "set_entity_coords ;p");
		AddOption("Kick From Vehicle", [] {player::kickVeh(selPlayer); }, "boot em"); //private
		AddOption("Delete Vehicle", [] {vehicle::deletePedVeh(selPed); }, "boop"); //private
		AddOption("Shoot Player", [] {online::shootPed(selPlayer); }, "get sniped boi");
		AddToggle("Kill Peds Loop", &netKillPeds[selPlayer], "I see dead people 0_0"); //test 5
		AddToggle("Freeze Player (might not work)", &netFreezePlayer[selPlayer], ""); //test
		//AddToggle("Fuck Camera", &netFuckCam[selPlayer], ""); //test
		//AddToggle("Explosion Loop", &netAnnoyingLoop[selPlayer], ""); //test
		//AddToggle("Forcefield", &netForceField[selPlayer], ""); //test
		//AddOption("TP to Me", [] {player::netTeleport(selPed, 0); }, ""); //4
		//AddOption("TP to Player", [] {player::teleportToPlayer(selPlayer); }, ""); //5
		//AddOption("TP to Waypoint", [] {player::netTeleport(selPed, 1); }, ""); //6
	//	AddToggle("Track", &netTrack[selPlayer], "Tracks the player");
		//AddOption("Infinite Load Screen", [] {online::remoteInv(selPlayer); }, "WIP");
	//	AddOption("Clone Crash", [] {player::crashClone(selPlayer); }, ""); //private
		//AddOption("Kick Player", [] {online::remoteKick(selPlayer); }, "WIP");
		//AddInt("remoteTest", &remoteInt, 0, 600, 1, "lmao bydget");
		//AddOption("Execute Remote", [] {online::blankRemote(selPlayer, remoteInt); }, "");


		/*void CREATE_AND_ATTACH(Entity Entity, Hash ObjectHash, float Offset_X = 0, float Offset_Y = 0, float Offset_Z = 0, float Pitch = 0, float Roll = 0, float Yaw = 0, bool HasPhysics = false, bool Invisible = false)
{
	Hash hash = ObjectHash;
	Vector3 MyPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
	Object Handle = OBJECT::CREATE_OBJECT(hash, MyPos.x, MyPos.y, MyPos.z, true, true, false);
	if (Handle == 0)
	{
		STREAMING::REQUEST_MODEL(hash);//Load model into memory
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash);
	    Object Handle = OBJECT::CREATE_OBJECT(hash, MyPos.x, MyPos.y, MyPos.z, true, true, false);
	}
	if (Invisible)
		ENTITY::SET_ENTITY_VISIBLE(Handle, false);
	ATTACH_ENTITY_TO_ENTITY(Handle, Entity, Offset_X, Offset_Y, Offset_Z, Pitch, Roll, Yaw, HasPhysics);
	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
}
		*/







		switch (currentOption) {
		case 2: selPed = game::GET_PLAYER_PED(selPlayer); break;
		}
	}
	int attachobj[100];
	int nuattach = 1;
	void Prop_create(char* hash) {
		bool custom = false;
		int objecthash = 0;
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selPlayer), true);
		objecthash = GAMEPLAY::GET_HASH_KEY(hash);


		if (STREAMING::IS_MODEL_IN_CDIMAGE(objecthash))
		{
			if (STREAMING::IS_MODEL_VALID(objecthash))
			{
				STREAMING::REQUEST_MODEL(objecthash);
				if (STREAMING::HAS_MODEL_LOADED(objecthash))
				{
					attachobj[nuattach] = OBJECT::CREATE_OBJECT(objecthash, pos.x, pos.y, pos.z, 1, 1, 1);
					if (ENTITY::DOES_ENTITY_EXIST(attachobj[nuattach]))
					{
						ENTITY::ATTACH_ENTITY_TO_ENTITY(attachobj[nuattach], PLAYER::GET_PLAYER_PED(selPlayer), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
						nuattach++;
						if (nuattach >= 101) { nuattach = 1; }
					}
				}
			}
		}

	}
	 void ONLINE_ATTACHMENT_SEL_PLAYER() {
		AddTitle("attach objects to selected player");

		AddOption("Remove all objects", [] {online::Remove_Objects(selPlayer);}, "");
		if (user == "sinfool") {
			AddSubmenu("Crash Objects", SUB::CRASH_OBJECTS, "");
		}
		//127
		for (ival = 0; ival < 127; ival++) AddOption(Prop_list[ival], [] {Prop_create(Prop_list[ival]); }, "");
		


		/*
		AddOption("Attach Orange Ball", [] {
		
			Hash oball = GAMEPLAY::GET_HASH_KEY("prop_juicestand");
			STREAMING::REQUEST_MODEL(oball);
			while (!STREAMING::HAS_MODEL_LOADED(oball))
				WAIT(0);
			int orangeball = OBJECT::CREATE_OBJECT(oball, 0, 0, 0, true, 1, 0);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(orangeball, selPed, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
		
		}, "");*/
	
	}
	 void CRASH_OBJECTS() {
		 AddTitle("Crash Objects (dev only)");
	/*	 AddOption("Invalid Object Crash", [] {

			 Hash oball = GAMEPLAY::GET_HASH_KEY("v_proc2_temp");
			 STREAMING::REQUEST_MODEL(oball);
			 while (!STREAMING::HAS_MODEL_LOADED(oball))
				 WAIT(0);
			 int orangeball = OBJECT::CREATE_OBJECT(oball, 0, 0, 0, true, 1, 0);
			 ENTITY::ATTACH_ENTITY_TO_ENTITY(orangeball, selPed, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);

		 }, "");*/

		 for (ival = 0; ival < 70; ival++) AddOption(crash_objects[ival], [] {Prop_create(crash_objects[ival]); }, "");


	 }
	void sub::attackers() {
		AddTitle("Attackers");
		AddString("Switch Attacker Types", Types[attkString], &attkString, 0, 3, "");
		switch (attkString)
		{
		case 0:
			for (ival = 0; ival < 4; ival++)
				AddOption(types[ival].displayName, [] {online::attackPed(selPlayer, types[ival].pedModel, types[ival].weapon, types[ival].isCop, types[ival].type); }, "");
			break;
		case 1:
			AddOption("", "");
			AddOption("", "");
			AddOption("", "");
			AddOption("", "");
			break;
		}
		AddOption("", "");
	}
	void sub::player() {
		AddTitle("Self Options");
		AddSubmenu("Particle Fx", SUB::PTFX, "");
		AddSubmenu("wanted editor", SUB::WANTED_EDITOR, "");
		AddToggle("Godmode", &playerGodMode, "I AM JESUS");
		AddToggle("Invisibility", &playerInvisible, "your still on the map m8");
		AddToggle("Fast Run", &fastrun, "");
		AddToggle("Fast Swim", &fastswim, "");
		AddToggle("Super Jump", &playerSuperJump, "im higher than that stoner");
		AddOption("Replenish Player", [] {player::replenish(PLAYER::PLAYER_PED_ID()); }, "have a bath");
	//	AddToggle("Restricted Areas", &accessAreas, "");
		AddOption("Reset Skin", [] { player::resetSkin(); }, "");
   //	AddToggle("Ragdoll", &ragdolltoggle, "WEEEEEEEEEEEEEEEEEE");
	//	AddToggle("Off Radar", &unlimitedradar, "more underground than bassline");
	//	AddSubmenu("Animation Menu", SUB::ANIMATIONS, "strip that down for me  ( ͡° ͜ʖ ͡°)");
		//switch (optionPress())
		//{
		//case 1: if (playerGodMode) ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), 0); break;//your to
		//case 2: if (playerInvisible) ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), 1, 1); break;
		//}
	}
	void sub::ptfx() {
		AddTitle("Particle Fx");
		AddOption("Clown Appears", []  { game::ptfx("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");  }, "");
		AddOption("Firework 1", [] { game::ptfx("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst"); }, "");
		AddOption("Firework 2", [] {game::ptfx("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw"); }, "");
		AddOption("Firework 3", [] {game::ptfx("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw"); }, "");
		AddOption("Banknotes", [] {game::ptfx("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes"); }, "");
		AddOption("Truck Crash", [] {game::ptfx("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash"); }, "");
		AddOption("Alien 1", [] {game::ptfx("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate"); }, "");
		AddOption("Alien 2", [] {game::ptfx("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport"); }, "");
		AddOption("Electric Box", [] {game::ptfx("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box"); }, "");
		/*
		if (Menu::Option("Electric Box")) PTFXCALL("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box");
		if (Menu::Option("Water Splash")) PTFXCALL("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash");
		if (Menu::Option("Bubbles")) PTFXCALL("scr_fbi5a", "scr_fbi5a", "water_splash_ped_bubbles");
		if (Menu::Option("Blood Entry")) PTFXCALL("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry");
		if (Menu::Option("Sniper Impact")) PTFXCALL("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact");
		if (Menu::Option("Dirt Throw")) PTFXCALL("core_snow", "core_snow", "cs_mich1_spade_dirt_throw");
		if (Menu::Option("Blood Stab")) PTFXCALL("scr_michael2", "scr_michael2", "scr_mich2_blood_stab");
		if (Menu::Option("Ped Sliced")) PTFXCALL("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced");
		if (Menu::Option("Camera")) PTFXCALL("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera");
		if (Menu::Option("Meth Smoke")) PTFXCALL("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke");
		if (Menu::Option("Burial Dirt")) PTFXCALL("scr_reburials", "scr_reburials", "scr_burial_dirt");*/
	}
	void sub::wanted_editor() {
		AddTitle("Wanted Editor");

		AddToggle("Never Wanted", &playerNeverWanted, "Cant catch me"); //add loop and update variables for loop functions, loop section at top and variables in varibales.h
		AddOption("Wanted up (may not work)", [] {
		
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();

			//			if (!PLAYER::IS_PLAYER_PLAYING(player)) return;

			if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) < 5)
			{
				PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, PLAYER::GET_PLAYER_WANTED_LEVEL(player) + 1, false);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);
			}
		
		},"");
		AddOption("Wanted down (may not work)", [] {
		
		
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();

			//		if (!PLAYER::IS_PLAYER_PLAYING(player)) return;

			if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) > 0)
			{
				PLAYER::CLEAR_PLAYER_WANTED_LEVEL(player);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, PLAYER::GET_PLAYER_WANTED_LEVEL(player) - 1, false);
				PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);
			}
		
		
		
		
		}, "");
	}
	void sub::vehicle() {
		AddTitle("Vehicle Options");
		AddSubmenu("Vehicle Spawner", SUB::VEHICLESPAWNER, "spawn a batmobile?");
		AddSubmenu("Sinfool's Customs 1.1", SUB::LSCUSTOMS, "Testes for dank");
	//	AddOption("Repair Vehicle", [] {vehicle::repair(VEHICLE::GET_LAST_DRIVEN_VEHICLE()); }, "");

		char* vehclasses[]{ "Vehicle Spawner Settings", "Vehicle Options"};
		AddString("Vehicle Mods", vehclasses[vehoptionsstring], &vehoptionsstring, 0, 1, "");
		
		switch (vehoptionsstring) {
		case 0:
		/*	AddToggle("Despawn old vehicle", &despawnold, "");
			AddToggle("Warp into spawned vehicle", &warpintoveh, "");
			AddToggle("Spawn maxed", &spawnmaxed, ""); */
			 autisticTestbs();
			// warp into vehicle
			//spawn maxed
			break;
		case 1:
			AddOption("Repair Vehicle", [] {vehicle::repair(VEHICLE::GET_LAST_DRIVEN_VEHICLE()); }, "");
			AddOption("Max Vehicle", [] {
				if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
				{
					Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
					VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
					for (int i = 0; i < 50; i++)
					{
						VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
					}
					VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Gradient");
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 0, 0, 0);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 0, 0, 0);
				}}, "");
			AddToggle("Horn Boost", &hornboost, "");
			AddToggle("God Car", &godcar, "");
			AddOption("Open All Doors", [] {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorFrontLeftDoor, true, true);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorFrontRightDoor, true, true);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorBackLeftDoor, true, true);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorBackRightDoor, true, true);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorHood, true, true);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorTrunk, true, true);
			VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorTrunk2, true, true);
	        }, "");
			AddToggle("Rainbow Car", &rainbowcar, "");
			AddOption("Set Plate Text", [] {		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false); vehicle::setPlate(veh); }, "");
			
			break;
	
		}
		/*			AddToggle("Invinciblity", &vehInvincible, "");
		//AddToggle("BulletProof Tyres", &vehInvincibleWheels, "");
	AddToggle("Invisibility", &vehInvisible, "*insert eerie ghost noise here*");
		AddToggle("SeatBelt", &vehSeatbelt, "'they kill more people than they save'");
		AddToggle("Speed Boost", &vehSpeedBoost, "");
		AddToggle("Air Suspension", &vehAirEnabled, "for that hella slammed experience");
		AddToggle("Drive on Water", &vehDriveOnWater, "ONLY FOR ROAD VEHICLES");
		AddToggle("Explode on Impact", &vehKaboom, "self-explanatory");
		AddToggle("Ejector Seat", &vehEject, "007 suck my balls");
		AddOption("Smoke Trails", "leave smoke trails like a thug");
		AddToggle("Vehicle Hop", &vehicleJump, "Jump on Space or LS");
		AddFloat("Defense Multiplier", &vehDefMult, -5.f, 5.f, 0.1f, "Multiplies the defense of your vehicle");
		AddFloat("Damage Multiplier", &vehDamMult, -5.f, 5.f, 0.1f, "Multiplies damage done by vehicle");
		AddToggle("Matrix Plates", &vehScrollActive, "oh shit scrolling numberplate WIP"); //test 
		*/
		//AddToggle("Speedo", &vehChr0m3Speedo, "");
		//AddInt("Speedo Position", &speedoPos, 1, 3, 1, "");
		AddOption("Delete Vehicle", [] {vehicle::deletePedVeh(PLAYER::PLAYER_PED_ID()); }, "");
		if (LSString != 0) LSString = 0;
	}
	void sub::LSCustoms() {
		AddLSCTitle("Sinfool's Customs");
		char* modClasses[]{"Normal Mods", "Bennys Mods"};
		AddString("Vehice Mods", modClasses[lscmodstring], &lscmodstring, 0, 1, "Choose Your Mod Type");
		if (VEHICLE::GET_VEHICLE_MOD_KIT(VEHICLE::GET_LAST_DRIVEN_VEHICLE()) != 0)
			VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 0);
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1))
			playerVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		else
			playerVeh = 0ul;
		switch (lscmodstring) {
		case 0:
			AddOption("BETA", [] {}, "");
			AddOption("Max Performance", [] {vehicle::upgradeBase(playerVeh, &engine, &brakes, &transmission, &suspension, &armour); }, "");
			AddString("Engine", upgradeEMS[engine], &engine, 0, GET_NUM_VEHICLE_MODS(playerVeh, MOD_ENGINE), [] {SET_VEHICLE_MOD(playerVeh, MOD_ENGINE, engine - 1, 0); }, "");
			AddString("Brakes", upgradeBrakes[brakes], &brakes, 0, GET_NUM_VEHICLE_MODS(playerVeh, MOD_BRAKES), [] {SET_VEHICLE_MOD(playerVeh, MOD_BRAKES, brakes - 1, 0); }, "");
			AddString("Transmission", upgradeTransmission[transmission], &transmission, 0, GET_NUM_VEHICLE_MODS(playerVeh, MOD_TRANSMISSION), [] {SET_VEHICLE_MOD(playerVeh, MOD_TRANSMISSION, transmission - 1, 0); }, "");
			AddString("Suspension", upgradeSuspension[suspension], &suspension, 0, GET_NUM_VEHICLE_MODS(playerVeh, MOD_SUSPENSION), [] {SET_VEHICLE_MOD(playerVeh, MOD_SUSPENSION, suspension - 1, 0); }, "");
            AddString("Armour", upgradeArmour[armour], &armour, 0, GET_NUM_VEHICLE_MODS(playerVeh, MOD_ARMOR), [] {SET_VEHICLE_MOD(playerVeh, MOD_ARMOR, armour - 1, 0); }, "");
		    AddString("Front Bumper", frontbumper[FRONTBUMPER], &FRONTBUMPER, 0, GET_NUM_VEHICLE_MODS(playerVeh, MOD_FRONTBUMPER), [] {SET_VEHICLE_MOD(playerVeh, MOD_FRONTBUMPER, FRONTBUMPER - 1, 0); }, "");

			AddToggle("Turbo", IS_TOGGLE_MOD_ON(playerVeh, MOD_TURBO), [] {TOGGLE_VEHICLE_MOD(playerVeh, MOD_TURBO, !IS_TOGGLE_MOD_ON(playerVeh, MOD_TURBO)); }, "");
			AddToggle("Xenon Lights", IS_TOGGLE_MOD_ON(playerVeh, MOD_XENONLIGHTS), [] {TOGGLE_VEHICLE_MOD(playerVeh, MOD_XENONLIGHTS, !IS_TOGGLE_MOD_ON(playerVeh, MOD_XENONLIGHTS)); }, "");
		//	AddToggle("Neon Lights", IS_TOGGLE_MOD_ON(playerVeh, MOD_TURBO), [] {TOGGLE_VEHICLE_MOD(playerVeh, MOD_XENONLIGHTS, !IS_TOGGLE_MOD_ON(playerVeh, MOD_TURBO)); }, "");
			AddSubmenu("Wheels", SUB::WHEELS, "Wheel editor");
			AddToggle("Tyre Smoke", IS_TOGGLE_MOD_ON(playerVeh, MOD_TIRESMOKE), [] {TOGGLE_VEHICLE_MOD(playerVeh, MOD_TIRESMOKE, !IS_TOGGLE_MOD_ON(playerVeh, MOD_TIRESMOKE)); }, "");
			break;
		case 1:
			AddOption("NOT DONE ):", [] {}, "");




			break;
		}
		
		/*MOD_SPOILER,
	MOD_FRONTBUMPER,
	MOD_REARBUMPER,
	MOD_SIDESKIRT,
	MOD_EXHAUST,
	MOD_CHASSIS, //Or roll cage
	MOD_GRILLE,
	MOD_HOOD,
	MOD_FENDER,
	MOD_RIGHTFENDER,
	MOD_ROOF,
	
	
	MOD_HORNS,
	
	
	MOD_UNK17 = 17,
	MOD_UNK19 = 19,
	MOD_TIRESMOKE = 20,
	MOD_UNK21 = 21,
	MOD_XENONLIGHTS = 22,

	// not in yet
	MOD_BACKWHEELS = 24, //Bikes only*/
	}
	void sub::wheels_list() {
		AddLSCTitle("Wheel Changer");
		AddString("Wheel Type", wheelTypes[wheels], &wheels, 0, 9, [] {SET_VEHICLE_WHEEL_TYPE(playerVeh, wheels); }, "");
		for (ival = 0; ival < GET_NUM_VEHICLE_MODS(playerVeh, MOD_FRONTWHEELS); ival++)
			AddOption(UI::_GET_LABEL_TEXT(GET_MOD_TEXT_LABEL(playerVeh, MOD_FRONTWHEELS, ival)), [] {SET_VEHICLE_MOD(playerVeh, MOD_FRONTWHEELS, ival, 0); }, "");
	}
	void sub::vehicleSpawner() {
		char* vehClasses[]{ "Super", "Sports", "Sports Classic", "Coupe", "Muscle", "Sedans", "Compacts", "SUV", "Offroad", "Motorcycles", "Planes", "Helicopters", "Vans", "Commercial", "Military", "Emergency", "Utility", "Industrial", "Service", "Cycles", "Trains", "Trailers" , "Gunrunning", "smugglers run", "boats" };
		AddTitle("Vehicle Spawner");
		AddString("Vehicle Class", vehClasses[vehString], &vehString, 0, 25, "Choose Your Vehicle Class");




		switch (vehString) {

		case 0: for (ival = 0; ival < 28; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(SuperCars[ival])), [] {vehicle::spawn(SuperCars[ival], selPed); }, ""); break;
		case 1: for (ival = 0; ival < 45; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(SportsCars[ival])), [] {vehicle::spawn(SportsCars[ival], selPed); }, ""); break;
		case 2: for (ival = 0; ival < 21; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(SportsClassic[ival])), [] {vehicle::spawn(SportsClassic[ival], selPed); }, ""); break;
		case 3: for (ival = 0; ival < 14; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(Coupe[ival])), [] {vehicle::spawn(Coupe[ival], selPed); }, ""); break;
		case 4: for (ival = 0; ival < 42; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Muscle[ival]))), [] {vehicle::spawn(Muscle[ival], selPed); }, ""); break;
		case 5: for (ival = 0; ival < 31; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Sedans[ival]))), [] {vehicle::spawn(Sedans[ival], selPed); }, ""); break;
		case 6: for (ival = 0; ival < 8; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Compacts[ival]))), [] {vehicle::spawn(Compacts[ival], selPed); }, ""); break;
		case 7: for (ival = 0; ival < 27; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(SUVs[ival]))), [] {vehicle::spawn(SUVs[ival], selPed); }, ""); break;
		case 8: for (ival = 0; ival < 31; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(OffRoad[ival]))), [] {vehicle::spawn(OffRoad[ival], selPed); }, ""); break;
		case 9: for (ival = 0; ival < 46; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Motorcycles[ival]))), [] {vehicle::spawn(Motorcycles[ival], selPed); }, ""); break;
		case 10: for (ival = 0; ival < 19; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Planes[ival]))), [] {vehicle::spawn(Planes[ival], selPed); }, ""); break;
		case 11: for (ival = 0; ival < 22; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Helicopters[ival]))), [] {vehicle::spawn(Helicopters[ival], selPed); }, ""); break;
		case 12: for (ival = 0; ival < 32; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vans[ival]))), [] {vehicle::spawn(Vans[ival], selPed); }, ""); break;
		case 13: for (ival = 0; ival < 11; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Commercial[ival]))), [] {vehicle::spawn(Commercial[ival], selPed); }, ""); break;
		case 14: for (ival = 0; ival < 5; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Military[ival]))), [] {vehicle::spawn(Military[ival], selPed); }, ""); break;
		case 15: for (ival = 0; ival < 18; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Emergency[ival]))), [] {vehicle::spawn(Emergency[ival], selPed); }, ""); break;
		case 16: for (ival = 0; ival < 18; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Utility[ival]))), [] {vehicle::spawn(Utility[ival], selPed); }, ""); break;
		case 17: for (ival = 0; ival < 11; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Industrial[ival]))), [] {vehicle::spawn(Industrial[ival], selPed); }, ""); break;
		case 18: for (ival = 0; ival < 11; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Service[ival]))), [] {vehicle::spawn(Service[ival], selPed); }, ""); break;
		case 19: for (ival = 0; ival < 7; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Cycles[ival]))), [] {vehicle::spawn(Cycles[ival], selPed); }, ""); break;
		case 20: for (ival = 0; ival < 8; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Trains[ival]))), [] {vehicle::spawn(Trains[ival], selPed); }, ""); break;
		case 21: for (ival = 0; ival < 22; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Trailer[ival]))), [] {vehicle::spawn(Trailer[ival], selPed); }, ""); break;
	//	case 22: for (ival = 0; ival < 28; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(Gunrunning1[ival])), [] {vehicle::spawn(Gunrunning1[ival], selPed); }, ""); break;
		case 22: for (ival = 0; ival < 19; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Gunrunning1[ival]))), [] {vehicle::spawn(Gunrunning1[ival], selPed); }, ""); break;
		case 23: for (ival = 0; ival < 19; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(smugglers1[ival]))), [] {vehicle::spawn(smugglers1[ival], selPed); }, ""); break;
		case 24: for (ival = 0; ival < 21; ival++) AddOption(UI::_GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Boats[ival]))), [] {vehicle::spawn(Boats[ival], selPed); }, ""); break;

			//Boats
		}
		AddOption("Enter Model", [] {vehicle::manualSelect(); }, "");

	}
	void sub::teleport() {
		char* teleportLocs[]{ "Far Away", "Online", "Exploration", "SP Locations", "Activities", "IPLS", "Shops", "High Up", "other" };
		AddTitle("Teleport Locations");
		AddString("Locations", teleportLocs[teleString], &teleString, 0, 8, "");
		switch (teleString) {
		case 0:
			AddOption("Out to the sea", [] {misc::moveMe(1845.673f, -13787.4884f, 0.0000f); }, "");
			AddOption("Your own Island", [] {misc::moveMe(-2159.147f, 5196.89f, 20.00f); }, "");
			AddOption("Under da Map", [] {misc::moveMe(132.1470f, -739.5430f, 39.00f); }, "");
			AddOption("Far Away Beach", [] {misc::moveMe(178.3295f, 7041.8220f, 1.8671f); }, "");
			AddOption("On top of a lighthouse", [] {misc::moveMe(3433.6570f, 5175.4090f, 35.8053f); }, "");
			AddOption("Building Glitch", [] {misc::moveMe(-11.5143f, -691.2623f, 54.7947f); }, "");
			break;
		case 1:
			AddOption("500k Apartment", [] {misc::moveMe(-793.36f, 296.86f, 87.84f); }, "");
			AddOption("500k Garage", [] {misc::moveMe(-795.4600f, 308.8900f, 85.7100f); }, "");
			AddOption("Mors Mutual Impound", [] {misc::moveMe(408.923f, -1633.860f, 30.29f); }, "");
			AddOption("Car Impound", [] {misc::moveMe(391.4746f, -1637.9750f, 29.3153f); }, "");
			AddOption("Prison", [] {misc::moveMe(1679.0490f, 2513.7110f, 45.5649f); }, "");
			AddOption("Prison Gym", [] {misc::moveMe(1640.7910f, 2530.0440f, 45.5649f); }, "");
			break;
		case 2:
			AddOption("Fort Zancudo", [] {misc::moveMe(-2012.8470f, 2956.5271f, 32.8101f); }, "");
			AddOption("Coral Reef", [] {misc::moveMe(106.6972f, 7282.0550f, 1.8821f); }, "");
			AddOption("Dirtbike Trail", [] {misc::moveMe(-1202.0910f, 2802.4400f, 14.8256f); }, "");
			AddOption("Zancudo River", [] {misc::moveMe(-558.9814f, 2945.7010f, 14.5917f); }, "");
			AddOption("On top of Waterfall", [] {misc::moveMe(-540.4822f, 4402.3590f, 34.3786f); }, "");
			AddOption("Water Fountain", [] {misc::moveMe(-104.8196f, -856.3741f, 41.0868f); }, "");
			AddOption("Del-Perro Pier", [] {misc::moveMe(-1600.0930f, -1041.8920f, 13.0209f); }, "");
			AddOption("Land Act Dam", [] {misc::moveMe(1655.8130f, 0.8890f, 173.7747f); }, "");
			AddOption("Jetski Pier", [] {misc::moveMe(-1624.1540f, -1165.0890f, 2.0955f); }, "");
			AddOption("Mountain Creek", [] {misc::moveMe(2559.2640f, 6184.1520f, 162.7809f); }, "");
			AddOption("Mount Josiah", [] {misc::moveMe(-1189.1070f, 3849.7530f, 489.0641f); }, "");
			break;
		case 3:
			AddOption("Trevor's Office (Strip Club)", [] {misc::moveMe(97.2707f, -1290.9940f, 29.2688f); }, "");
			AddOption("Trevor's Air Field", [] {misc::moveMe(1740.4960f, 3269.2570f, 41.6014f); }, "");
			AddOption("Trevor's House", [] {misc::moveMe(1974.7580f, 3819.4570f, 33.4363f); }, "");
			AddOption("Trevor's Meth Lab", [] {misc::moveMe(1397.5240f, 3607.4230f, 38.9419f); }, "");
			AddOption("Michael's House", [] {misc::moveMe(-813.6030f, 179.4738f, 72.1589f); }, "");
			AddOption("Franklin's House (New)", [] {misc::moveMe(7.4150f, 535.5486f, 176.0279f); }, "");
			AddOption("Franklin's House (Old)", [] {misc::moveMe(-14.9693f, -1436.4430f, 31.1185f); }, "");
			break;
		case 4:
			AddOption("Bike Race", [] {misc::moveMe(2124.5260f, 1668.7090f, 96.2708f); }, "");
			AddOption("Land Race", [] {misc::moveMe(2678.6920f, 1341.6110f, 24.5118f); }, "");
			AddOption("Parachuting", [] {misc::moveMe(496.2334f, 5527.2700f, 778.4734f); }, "");
			AddOption("Deathmatch", [] {misc::moveMe(138.1327f, -1448.6800f, 29.2240f); }, "");
			AddOption("Team Deathmatch", [] {misc::moveMe(361.7499f, -1957.4250f, 24.6453f); }, "");
			break;
		case 5:
			AddOption("North Yankton", [] {misc::nyankton(); }, "");
			AddOption("Yacht1 (MP ONLY)", [] {misc::Yacht1(); }, "");
			AddOption("Cluckin Bell", [] {misc::cbell(); }, "");
			AddOption("Morgue", [] {misc::Mmorg(); }, "");
			AddOption("Cargo Ship", [] {misc::cship(); }, "");
			AddOption("Cargo Ship (Destroyed)", [] {misc::cshipSunk(); }, "");
			AddOption("Destroyed Hospital", [] {misc::dhosp(); }, "");
			AddOption("Lester Factory", [] {misc::lfactduringDoor(); }, "");
			AddOption("Lester Factory (fire?)", [] {misc::lfactFire(); }, "");
			AddOption("Fort Zanacudo UFO", [] {misc::ufo1(); }, "");
			AddOption("Paleto Bay UFO", [] {misc::ufo2(); }, "");
			AddOption("O'Neil Farm (Destroyed)", [] {misc::destFarm(); }, "");
			AddOption("O'Neil Farm", [] {misc::intFarm(); }, "");
			AddOption("Life Invader Lobby", [] {misc::facelobby(); }, "");
			AddOption("Airfield?", [] {misc::airfield(); }, "");
			AddOption("Simeon's Garage", [] {misc::simeon(); }, "");
			AddOption("Union Depository Vault", [] {misc::udBigVault(); }, "");
			AddOption("Union Depository Garage", [] {misc::udShutters(); }, "");
			AddOption("Jewelry Store", [] {misc::jewelStore(); }, "");
			break;
		case 6:
			AddOption("Burton - Los Santos Customs", [] {misc::moveMe(-361.732f, -132.968f, 37.9515f); }, "Burton");
			AddOption("Burton - Ponsonbys", [] {misc::moveMe(-149.828f, -307.939f, 37.8623f); }, "Burton");
			AddOption("Cypress Flats - Ammunation", [] {misc::moveMe(814.976f, -2144.03f, 28.5611f); }, "Cypress Flats");
			AddOption("Davis - Gasoline Store [14]", [] {misc::moveMe(-53.5097f, -1764.59f, 28.2464f); }, "Davis");
			AddOption("Davis - Herr Kutz (Barber)", [] {misc::moveMe(128.629f, -1715.75f, 28.3319f); }, "Davis");
			AddOption("Del Perro - Sub-Urban", [] {misc::moveMe(-1210.76f, -781.273f, 16.5507f); }, "Del Perro");
			AddOption("Downtown Vinewood - 24/7 Store [9]", [] {misc::moveMe(373.249f, 317.598f, 102.658f); }, "Downtown Vinewood");
			AddOption("Downtown Vinewood - Blazing Tattoo", [] {misc::moveMe(321.031f, 171.868f, 102.983f); }, "Downtown Vinewood");
			AddOption("El Burro Heights - Tattoo Parlour", [] {misc::moveMe(1316.51f, 1648.6f, 51.4071f); }, "El Burro Heights");
			AddOption("Hawick - Hair on Harwick (Barber)", [] {misc::moveMe(-30.678f, -136.889f, 56.2678f); }, "Hawick");
			AddOption("Hawick - Sub-Urban", [] {misc::moveMe(133.319f, -199.826f, 53.6291f); }, "Hawick");
			AddOption("La Mesa - Ammunation", [] {misc::moveMe(839.463f, -1020.11f, 26.7274f); }, "La Mesa");
			AddOption("La Mesa - Los Santos Customs", [] {misc::moveMe(718.007f, -1089.42f, 21.6029f); }, "La Mesa");
			AddOption("Little Seoul - Ammunation", [] {misc::moveMe(-662.182f, -949.493f, 21.5386f); }, "Little Seoul");
			AddOption("Little Seoul - LTD Store/Car Wash", [] {misc::moveMe(-708.535f, -921.384f, 18.2758f); }, "Little Seoul");
			AddOption("Mirror Park - Herr Kutz (Barber)", [] {misc::moveMe(1197.85f, -469.579f, 65.3589f); }, "Mirror Park");
			AddOption("Mirror Park - Gasoline Store [18]", [] {misc::moveMe(1157.03f, -331.703f, 68.1191f); }, "Mirror Park");
			AddOption("Morningwood - Ammunation", [] {misc::moveMe(-1323.37f, -392.401f, 35.7302f); }, "Morningwood");
			AddOption("Morningwood - Liquor Store [12]", [] {misc::moveMe(-1504.4f, -385.354f, 39.7755f); }, "Morningwood");
			AddOption("Murrieta Heights - Liquor Store [11]", [] {misc::moveMe(1146.74f, -982.816f, 45.3493f); }, "Murrieta Heights");
			AddOption("Pillbox Hill - Ammunation", [] {misc::moveMe(16.3855f, -1124.18f, 28.0527f); }, "Pillbox Hill");
			AddOption("Ammunation Gun Range", [] {misc::moveMe(22.153f, -1072.854f, 29.797f); }, "Pillbox Hill");
			AddOption("Ammunation Office", [] {misc::moveMe(12.494f, -1110.130f, 29.797f); }, "Pillbox Hill");
			AddOption("Richman - Store [15]", [] {misc::moveMe(-1819.4f, 785.192f, 137.174f); }, "Richman");
			AddOption("Rockford Hills - Bob Mulet (Barber)", [] {misc::moveMe(-830.037f, -191.123f, 36.7017f); }, "Rockford Hills");
			AddOption("Rockford Hills - Ponsonbys", [] {misc::moveMe(-715.54f, -170.697f, 36.0662f); }, "Rockford Hills");
			AddOption("Strawberry - Benny's Customs", [] {misc::moveMe(-206.367f, -1302.21f, 30.5649f); }, "Strawberry");
			AddOption("Strawberry - Car Wash", [] {misc::moveMe(53.9021f, -1391.88f, 28.651f); }, "Strawberry");
			AddOption("Strawberry - Discount Store", [] {misc::moveMe(87.3876f, -1393.33f, 28.4515f); }, "Strawberry");
			AddOption("Strawberry - Store [8]", [] {misc::moveMe(24.818f, -1357.46f, 28.5068f); }, "Strawberry");
			AddOption("Textile City - Binco Clothing", [] {misc::moveMe(411.544f, -806.999f, 28.4231f); }, "Textile City");
			AddOption("Vespucci - Hot Shave (Barbers)", [] {misc::moveMe(-1294.32f, -1117.05f, 6.64755f); }, "Vespucci");
			AddOption("Vespucci - Kill Me plz xo", "37 Fucking Regions");
			AddOption("Vespucci Beach - Mask Shop", [] {misc::moveMe(-1340.23f, -1279.64f, 4.12567f); }, "Vespucci Beach");
			AddOption("Vespucci Canals - Binco Clothing", [] {misc::moveMe(-816.507f, -1084.84f, 11.0118f); }, "Vespucci Canals");
			AddOption("Vespucci Canals - Store [17]", [] {misc::moveMe(-1230.51f, -897.825f, 12.1041f); }, "Vespucci Canals");
			AddOption("Vespucci Canals - Tattoo Parlour", [] {misc::moveMe(-1157.99f, -1415.24f, 4.80859f); }, "Vespucci Canals");
			break;
		case 7:
			AddOption("High in the sky", [] {misc::moveMe(-129.9f, 8130.8f, 6705.6f); }, "");
			AddOption("Mount Chilliad View", [] {misc::moveMe(489.3171f, 5580.8870f, 792.8515f); }, "");
			AddOption("IAA Roof", [] {misc::moveMe(134.085f, -637.859f, 262.851f); }, "");
			AddOption("FIB Roof", [] {misc::moveMe(150.126f, -754.591f, 262.865f); }, "");
			AddOption("FIB Top Floor", [] {misc::moveMe(135.733f, -749.216f, 258.152f); }, "");
			AddOption("Maze Bank Roof", [] {misc::moveMe(-75.015f, -818.215f, 326.176f); }, "");
			AddOption("Galileo Observatory Roof", [] {misc::moveMe(-438.804f, 1076.097f, 352.411f); }, "");
			AddOption("Maze Bank Arena Roof", [] {misc::moveMe(-324.300f, -1968.545f, 67.002f); }, "");
			AddOption("Satellite Dish Antenna", [] {misc::moveMe(2034.988f, 2953.105f, 74.602f); }, "");
			AddOption("Windmill Top", [] {misc::moveMe(2026.677f, 1842.684f, 133.313f); }, "");
			AddOption("Sandy Shores Building Site Crane", [] {misc::moveMe(1051.209f, 2280.452f, 89.727f); }, "");
			AddOption("Rebel Radio", [] {misc::moveMe(736.153f, 2583.143f, 79.634f); }, "");
			AddOption("Palmer-Taylor Power Station Chimney", [] {misc::moveMe(2732.931f, 1577.540f, 83.671f); }, "");
			AddOption("Mile High Club", [] {misc::moveMe(-144.274f, -946.813f, 269.135f); }, "");
			break;
		case 8:
			AddOption("teleport to waypoint", [] { teleport_to_marker(); }, "");
			AddOption("teleport to objective", [] { teleport_to_objective(); }, "");


		break;
		}
	}
	void sub::weapon() {
		AddTitle("Weapon Options");
		AddSubmenu("Prop Gun", SUB::PROP_GUN, "");
		AddOption("Give All", [] {weapon::giveguns(); }, "Give Player All Weapons");
//		AddOption("Give All Attachments", [] {weapon::upgradeguns(); }, "Upgrade Weapons");
		AddOption("Fill Ammo", [] {weapon::replenishguns(); }, "");
		AddToggle("Explosive Ammo", &wepAmmoExplosive, "");
		AddToggle("Fire Ammo", &wepAmmoFire, "");
	//	AddToggle("Super Damage", &wepDamage, [] {weapon::superDamage(PLAYER::PLAYER_ID(), wepDamage); }, "");
	//	AddOption("Set Weapon Damage", "");
		AddToggle("No Reload", &wepAmmoInfClip, "");
		AddToggle("Infinite Ammo", &wepAmmoInfinite, "");
		AddToggle("Explosive Melee", &wepMeleeExplosive, "");
		//AddOption("Remove Weapons", [] {weapon::removeAll(PLAYER::PLAYER_PED_ID()); }, "");
	}
	void sub::prop_gun() {

		AddTitle("Prop Gun");

		AddToggle("2k money gun", &Money_prop_gun, "");

	}
	void sub::world() {
		AddTitle("World Options");
		AddToggle("Sync Time", &worldSync, "");
	}
	void sub::misc() {
		AddTitle("Misc Options");
		AddToggle("Mobile Radio", &miscMobileRadio, "Mobile Music :D");
	//	AddToggle("Rainbow Mode", &miscRainbowMode, "Everything is dank");
		AddToggle("Hide HUD", &miscHideHUD, "For them youtube videos");
		AddTestFloat("wave hight changer", waveheight, 0, 2000, 1, "");
		AddToggle("set wave hight", &waveHeight, "");
	//	AddOption("Test Notification", [] {web::checkNotices(); }, "");
	//	AddOption("Check Server is up", [] {web::pingServer(); }, "");
	//	AddOption("Check if update is available", [] {web::checkUpdate(); }, "");
	}
	void sub::lobby() {
		AddTitle("Lobby Options");
		AddString("Restrict to: ", lobbyRest[lobbyString], &lobbyString, 0, 2, "be a nice person :D");
		//AddOption("Teleport All To Me", [] {online::teleportallcoords(PLAYER::PLAYER_ID()); }, "~r~WIP");
		//AddOption("Kick From ~y~Lobby", [] {lobby::kickAll(lobbyString); }, "Sort of a douchebag move");
		//AddOption("Kick From ~o~Vehicle", [] {lobby::kickVeh(lobbyString); }, "~g~Bonus Points~w~ for use in a race");
		//AddOption("Delete Vehicles", [] {lobby::deleteVeh(lobbyString); }, "ayylmao");
		//AddToggle("Explode All", &lobbyExplode, "douchebag move");
	//	AddOption("Give Vehicle", [] {lobby::giveVeh(lobbyString, "adder"); }, "everyone gets a car");
		//AddOption("Remove Weapons", [] {lobby::removeWeps(lobbyString); }, "get the upper hand");
		//AddToggle("Give 50K", &lobbyCash, "be like oprah");
		AddToggle("1337 haxor esp", &lobbyESP, "pervert");
		AddToggle("Freeze All", &lobbyFreeze, "you cant move bitch");
		AddToggle("Fuck Camera", &lobbyFuckCam, "lol you druggo");
	}
	void sub::Submenu1()
	{
		AddTitle("SUBMENU1");
		AddOption("Options test", [] { game::notifyBottom("Hello World!"); }, "HELLO ME!");
		AddToggle("Toggle", &toggle, "Hello! I'm a toggle.");
		AddInt("Int", &integer, 0, 255, 1, "Test int from 0 to 255.");
		AddFloat("Float", &float1, 0.0f, 255.0f, 1.0f, "Test float from 0.0f to 255.0f.");
		AddString("String", strings[stringIndex], &stringIndex, 0, 3, "Shows some text.");

		switch (optionPress())
		{
		case 5: if (stringIndex == 1) game::notifyBottom("Hello 2"); break;
		}
	}
	void sub::header()
	{
		AddTitle("HEADER");
		AddInt("Red", &bannerRect.R, 0, 255, 1, " ~r~red~s~ ");
		AddInt("Green", &bannerRect.G, 0, 255, 1, " ~g~green~s~ ");
		AddInt("Blue", &bannerRect.B, 0, 255, 1, " ~b~blue~s~ ");
	}
	void sub::options()
	{
		AddTitle("OPTIONS");
		AddInt("Highlight red", &highlightRed, 0, 255, 1, " ~r~red~s~ ");
		AddInt("Highlight green", &highlightGreen, 0, 255, 1, " ~g~green~s~ ");
		AddInt("Hightlight blue", &highlightBlue, 0, 255, 1, " ~b~blue~s~ ");
		AddInt("Options red", &optionsRed, 0, 255, 1, " ~r~red~s~ ");
		AddInt("Options green", &optionsGreen, 0, 255, 1, " ~g~green~s~ ");
		AddInt("Options blue", &optionsBlue, 0, 255, 1, " ~b~blue~s~ ");
	}
	void sub::scrollertest()
	{
		AddTitle("SCROLLER TEST");
		AddOption("Scroller1", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller2", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller3", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller4", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller5", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller6", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller7", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller8", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller9", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller10", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller11", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller12", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller13", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller14", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller15", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller16", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller17", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller18", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
		AddOption("Scroller19", [] { game::notifyBottom("Hello Scroller bish!"); }, "Just a scroller bish.");
	}
}