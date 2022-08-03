//add auth later
#pragma once
#include "stdafx.h"
#include "shellapi.h"
//#include "File.h"
#include "base.h"
#include "subswitch.h"
#include "vehicle.hh"
#include "types.h"
#include "Structs.h"
#include "File.h"
char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };

Player selPlayer = NULL;
char* selPlayerName;
void manualSelect() {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	string tempmodel = show_keyboard("Vehicle Model", "");
	if (tempmodel == "")
	{
		notifyMap("Cannot be blank", false);
	}
	else
	{
		if (GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT() != "")
		{
			char *vehModel = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
			if (STREAMING::IS_MODEL_VALID($(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT())))//tempmodel.c_str;
				Spawn(vehModel);
			else
				notifyMap("Vehicle is invalid", false);
		}
		else
		{
			notifyMap("Cannot be blank", false);
		}
	}
}
void AddPlayer(char *name, Player player, char *info = NULL)
{
	char buf[50], ibuf[50];
	if (player == PLAYER::PLAYER_ID()) {
		snprintf(buf, sizeof(buf), "%s~g~ [SELF] ", name);
		AddOption(buf, "~g~SELF");
	}
	else if (NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(player)) {
		snprintf(buf, sizeof(buf), "%s~r~ [ROCKSTAR]", name);
		AddOption(buf, "~r~ROCKSTAR ADMIN");
	}
	else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", -1, 0) == player) {
		snprintf(buf, sizeof(buf), "%s~y~ [HOST]", name);
		AddOption(buf, "~y~SESSION HOST");
	}
	//	else if (online::isPlayerFriend(player)) {
	//	snprintf(buf, sizeof(buf), "%s~b~ [FRIEND] ", name);
	//		AddOption(buf, "~b~FRIEND ");
	//	}
	else
		AddOption(name, "");

	if (currentOption == optionCount && optionPress()) {

		//Set our variables and change the submenu
		selPlayer = player;
		selPlayerName = name;
		PlayFrontendSound("SELECT");
		changeSubmenu(SUB::SELPLAYER);
	}

}

Vector3 addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
double DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;

}
Vector3 multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
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
using namespace std;


//toggles

bool riskymode = false;

bool god = false;
bool invis = false;
bool fastrun = false;
bool fastswim = false;
bool superjump = false;
bool neverwanted = false;
bool superman = false;
bool expammo = false;
bool fireammo = false;
bool NoReload = false;
bool expmelee = false;
bool rapidfire = false;
bool ragdoll = false;
bool twopointfivekdrop[32];
//bool warpintoveh = false;
//bool spawnmaxed = false;
bool hornboost = false;
bool godveh = false;
bool RainbowVeh = false;
bool RainbowMods = false;
bool lobbyESP;
bool lobbyFuckCam;
bool tenmil = false;
bool moneyrain = false;
bool localdrop = false;
//


namespace sub {
	void sub::settings()
	{
		AddTitle("SETTINGS");
		AddSubmenu("Header", SUB::HEADER, "Change the header.");
		AddSubmenu("Options", SUB::OPTIONS, "Change the options.");
		AddToggle("Gradients", &gradients, "Once toggled, cool fades will appear.");
		AddToggle("Risky mode", &riskymode, "does nothing atm bc nothing is risky ;p");


	}
	void sub::header()
	{
		AddTitle("HEADER");
		AddInt("Red", &bannerRect.R, 0, 255, 1, "Adjust the ~r~red~s~ channel.");
		AddInt("Green", &bannerRect.G, 0, 255, 1, "Adjust the ~g~green~s~ channel.");
		AddInt("Blue", &bannerRect.B, 0, 255, 1, "Adjust the ~b~blue~s~ channel.");
	}
	void sub::options()
	{
		AddTitle("OPTIONS");
		AddInt("Highlight red", &highlightRed, 0, 255, 1, "Adjust the ~r~red~s~ channel.");
		AddInt("Highlight green", &highlightGreen, 0, 255, 1, "Adjust the ~g~green~s~ channel.");
		AddInt("Hightlight blue", &highlightBlue, 0, 255, 1, "Adjust the ~b~blue~s~ channel.");
		AddInt("Options red", &optionsRed, 0, 255, 1, "Adjust the ~r~red~s~ channel.");
		AddInt("Options green", &optionsGreen, 0, 255, 1, "Adjust the ~g~green~s~ channel.");
		AddInt("Options blue", &optionsBlue, 0, 255, 1, "Adjust the ~b~blue~s~ channel.");
	}
	void sub::credits()
	{
		AddTitle("Credits");
		AddOption("Sinfool#2522 - developer", [] {}, "");
		AddOption("Paulth2gaming - auth", [] {}, "");
		AddOption("Localhost - Multitool", [] {}, "");
		AddOption("Any other dev that has helped me :)", [] {}, "");
	}




	void sub::MainMenu()
	{
		DisplayHelpTextThisFrame("Gradient GTA (premium) v1.0.0-Wirraway gradienthacks.com");
		AddTitle("Main Menu");
		AddSubmenu("Player Options", SUB::PLAYER, "");
		AddSubmenu("Weapon Options", SUB::WEAPONS, "");
		AddSubmenu("Teleport Locations", SUB::TELEPORTS, "");
		AddSubmenu("Vehicle Options", SUB::VEHICLE, "");
		AddSubmenu("Online Options", SUB::ONLINE_OPTIONS, "");
		AddSubmenu("Settings", SUB::SETTINGS, "");
		AddSubmenu("Credits", SUB::CREDITS, "");
		AddOption(">when crispycunt cant crack ur menu", "");

	}


	void sub::player()
	{
		AddTitle("Player Options");
		AddSubmenu("Particle FX", SUB::PTFX, "");
		AddSubmenu("Animations", SUB::ANIMATIONS, "");
		AddToggle("God Mode", &god, "invinsible");
		AddToggle("Invisibility", &invis, "ghost mode");
		AddToggle("Fast run", &fastrun, "no matter how fast i run i cant run away from the pain");
		AddToggle("Fast swim", &fastswim, "");
		AddToggle("Super jump", &superjump, "");
		AddToggle("Superman", &superman, "W, S, SHIFT");
		AddToggle("Never wanted", &neverwanted, "");
		AddToggle("No ragdoll", &ragdoll, "");
		AddOption("Wanted up", [] {wantedUP(); }, "");
		AddOption("Wanted down", [] {wantedDOWN(); }, "");
		AddOption("New look", [] {PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true); }, "");

	}
	void sub::weapons()
	{
		AddWeaponTitle("Weapon Options");
		AddOption("Give all weapons", [] {give_all_weps(); }, "");
		AddOption("Give all attachments", [] {upgrade_guns(); }, "");
		AddToggle("Explosive ammo", &expammo, "");
		AddToggle("Fire ammo", &fireammo, "");
		AddToggle("No reload", &NoReload, "");
		AddToggle("Explosive melee", &expmelee, "");
	}
	void sub::teleports()
	{
		AddTitle("Teleport Locations");
		AddOption("Teleport to waypoint", [] {teleport_to_marker(); }, "");
		AddOption("Teleport to objective", [] {teleport_to_objective(); }, "");

		for (auto id : teleportMenu)
		{
			AddOption(id.name, [id] { tp_entity_to_coords(id.x, id.y, id.z); }, "");
		}
	}
	void sub::ptfx()
	{
		AddTitle("Partice FX");
		AddOption("Clown Appears", [] { PTFX("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears"); }, "");
		AddOption("Firework 1", [] { PTFX("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst"); }, "");
		AddOption("Firework 2", [] { PTFX("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw"); }, "");
		AddOption("Firework 3", [] { PTFX("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw"); }, "");
		AddOption("Banknotes", [] { PTFX("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes"); }, "");
		AddOption("Truck Crash", [] { PTFX("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash"); }, "");
		AddOption("Alien 1", [] { PTFX("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate"); }, "");
		AddOption("Alien 2", [] { PTFX("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport"); }, "");
		AddOption("Electric Box", [] { PTFX("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box"); }, "");
	}
	void sub::animations()
	{
		AddTitle("Animations");
		AddOption("Stop animation", [] {	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID()); }, "");
		//	for (auto car : animName) { addOptionBool(car, [car] { Spawn(car); }); }
		for (auto id : Animlist)
		{
			AddOption(id.animName, [id] { PlayAnim(id.animDict, id.animName); }, "");
		}
	}


	void sub::vehicle()
	{
		AddVehicleTitle("Vehicle Options");
		AddSubmenu("Vehicle Spawner", SUB::VEHSPAWNER, "");
		AddOption("Repair Vehicle", [] {repair(VEHICLE::GET_LAST_DRIVEN_VEHICLE()); }, "");
		AddToggle("Horn Boost", &hornboost, "");
		AddToggle("God Vehicle", &godveh, "");
		AddToggle("Rainbow Vehicle", &RainbowVeh, "");
		AddToggle("Rawinbow Mods", &RainbowMods, "");
		AddOption("Max Vehicle", [] {MaxVeh(); }, "");
		AddOption("Open all doors", [] {openDoors(); }, "");
		AddOption("Set plate text", [] {Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false); setPlate(veh); }, "");
	}
	void sub::vehspawner()
	{
	//	int vehString;
	//	char* vehClasses[]{ "Doomsday heist", "smugglers run" ,"Gunrunning","Boats","Commercial","Compacts", "Coupes", "Cycles","Emergency", "Helicopters", "Industrial", "Military","Motorcycles","Muscle","OffRoad", "Planes","Sedans","Service","Sports","Sports Classics","Super","SUVs","Trailer","Trains","Utility","Vans" };
		AddVehicleTitle("Vehicle Spawner");
	//	AddString("Vehicle Class", vehClasses[vehString], &vehString, 0, 25, "Choose Your Vehicle Class");
		AddToggle("Spawn Maxed", &spawnmaxed, "");
		AddOption("Enter Model", [] {manualSelect(); }, "");
		AddToggle("warp into vehicle", &warpintoveh, "");
		AddSubmenu("Doomsday heist [1.42]", SUB::VEH_DOOMSDAY, "");
		/*
		switch (vehString)
		{
		case 0:
			for (auto car : doomsdayheist) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 1:
			for (auto car : smugglersrun) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 2:
			for (auto car : Gunrunning) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 3:
			for (auto car : Boats) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 4:
			for (auto car : Commercial) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 5:
			for (auto car : Compacts) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 6:
			for (auto car : Coupes) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 7:
			for (auto car : Cycles) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 8:
			for (auto car : Emergency) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 9:
			for (auto car : Helicopters) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 10:
			for (auto car : Industrial) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 11:
			for (auto car : Military) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 12:
			for (auto car : Motorcycles) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 13:
			for (auto car : Muscle) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 14:
			for (auto car : OffRoad) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 15:
			for (auto car : Planes) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 16:
			for (auto car : Sedans) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 17:
			for (auto car : Service) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 18:
			for (auto car : Sports) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 19:
			for (auto car : SportsClassics) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 20:
			for (auto car : Super) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 21:
			for (auto car : SUVs) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 22:
			for (auto car : Trailer) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 23:
			for (auto car : Trains) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 24:
			for (auto car : Utility) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		case 25:
			for (auto car : Vans) { AddOption(car, [car] { Spawn(car); }, ""); };
			break;
		}
		*/
	}

	void sub::veh_doomsday()
	{
		AddVehicleTitle("Doomsday heist [1.42]");

		for (auto car : doomsdayheist) { AddOption(car, [car] { Spawn(car); }, ""); };

	}
void sub::online_options()
{
	AddTitle("Online Options");
	AddSubmenu("Player List", SUB::PLAYERLIST,"");
	AddSubmenu("Lobby Options", SUB::LOBBY, "");
	AddSubmenu("Recovery Options", SUB::RECOVERY, "");
}

void sub::recovery()
{
	AddTitle("recovery options");

	
	//AddToggle("Broke Ass Stealth", &tenmil, "");//2
	//2k local
	AddSubmenu("Set rank", SUB::RANK, "");//2
	AddOption("Unlock All", [] { Unlock_all(); }, "");//4
	if (riskymode == true) {
		AddToggle("Money Rain", &moneyrain, "");//3

		AddToggle("Local 2k drop", &localdrop, "");
	}
}
void sub::set_rank()
{
	AddTitle("Set Rank");
	addrpOption("level 100", 1584350, "");	addrpOption("level 200", 4691850, "");	addrpOption("level 300", 8299350, "");	addrpOption("level 400", 12406850, "");	addrpOption("level 500", 17014350, "");	addrpOption("level 600", 22121850, "");	addrpOption("level 700", 27729350, "");	addrpOption("level 800", 33836850, "");	addrpOption("level 900", 40444350, "");	addrpOption("level 1000", 47551850, "");
}
void sub::playerList() {
	AddTitle("Player Index");
	for (int i = 0; i < 32; i++) {
		char* playerName = PLAYER::GET_PLAYER_NAME(i);
		if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i))
		{
			AddPlayer(playerName, i, "");
		}
	}
}
void sub::selplayer()
{
	
	if (strcmp(selPlayerName, "**Invalid**") == 0);
	AddTitle(selPlayerName);
	
	AddSubmenu("Attach objects",SUB::OBJECTS, "");
	if (riskymode == true)
	{
		AddToggle("2k drop", &twopointfivekdrop[selPlayer], "");
	}
	AddOption("Teleport to player", [] {Entity handle;
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer), false);
	PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
	ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false); }, "");
	AddOption("Kick from vehicle", [] {kickVeh(selPlayer); }, "");
	AddOption("Delete vehicle", [] {deletePedVeh(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer)); }, "");
	//AddOption("Explode Player", [] {explodePed(selPlayer); }, "");

}
int attachobj[100];
int nuattach = 1;
void Prop_create(char* hash) {
	bool custom = false;
	int objecthash = 0;
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer), true);
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
					ENTITY::ATTACH_ENTITY_TO_ENTITY(attachobj[nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
					nuattach++;
					if (nuattach >= 101) { nuattach = 1; }
				}
			}
		}
	}

}
void remove_objects() {
	for (int i = 0; i < 5; i++) {
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer), 1);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
		for (int i = 0; i < 136; i++) {
			Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer))) {
				RequestControlOfEnt(obj);
				int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
				RequestControlOfid(netID);
				ENTITY::DETACH_ENTITY(obj, 1, 1);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
					ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
					ENTITY::DELETE_ENTITY(&obj);
				}
			}
		}
	}
}
void sub::attach_objects()
{
	Ini *settingsIni = new Ini(".\\settings.ini");
	string user = settingsIni->GetString("Login", "User");
	string pw = settingsIni->GetString("Login", "Pass");
	//std::string attach = "Attach Objects to:";
	AddTitle("Attach Objects To Selected Player");
	//if (user == "sinfool") {
	//	addSubmenuOption("Crash Objects", 40);
//	}
	AddOption("Remove Objects", [] { remove_objects(); }, "");
	for (auto car : objects) { AddOption(car, [car] { Prop_create(car); }, ""); }
}

void sub::lobby()
{
	AddTitle("Lobby Options");
	AddToggle("Lobby ESP", &lobbyESP, "");
	//AddToggle("Fuck Camera", &lobbyFuckCam, "");
//	AddOption("Explode all", [] {for (int i = 0; i < 32; i++) { explodePed(i); }}, "");
}
};















void Features()
{
	int TimePD3;

	if (localdrop == true)
	{
		/*	int CashHash = -422877666; // money bag = 0x113FD533
		Ped iPed = PLAYER::PLAYER_PED_ID();
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);

		if ((timeGetTime() - TimePD1) > 4000) // Time between drops
		{
		int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
		STREAMING::REQUEST_MODEL(CashHash);
		while (!STREAMING::HAS_MODEL_LOADED(CashHash)) WAIT(0);
		OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, coords.x, coords.y, coords.z, 0, 10, CashHash, false, true);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(CashHash);
		}*/
		Ped iPed = PLAYER::PLAYER_PED_ID();
		int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");

		Vector3 coords = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
		int amount = 2000;

		if ((timeGetTime() - TimePD3) > 1000) // Time between drops
		{
#define prop_money_bag_01 289396019

			STREAMING::REQUEST_MODEL(prop_money_bag_01);
			if (!STREAMING::HAS_MODEL_LOADED(prop_money_bag_01)) {
				WAIT(0);
			}
			else {
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
				OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, playerPosition.x, playerPosition.y, playerPosition.z + 1.5f, 0, amount, prop_money_bag_01, FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(prop_money_bag_01);

				TimePD3 = timeGetTime();
			}
		}
	}
	int TimePD2;

	if (moneyrain == true)
	{
		int CashHash = -422877666; // money bag = 0x113FD533
		Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 10.0);
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(5, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(5, 15);

		if ((timeGetTime() - TimePD2) > 4000) // Time between drops
		{
			int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
			STREAMING::REQUEST_MODEL(CashHash);
			while (!STREAMING::HAS_MODEL_LOADED(CashHash)) WAIT(0);
			OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, pp.x + offset1, pp.y + offset2, pp.z, 0, 2000, CashHash, false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(CashHash);
		}
	}
	

if (god)
{
GodMode(true);
}
if (!god)
{
GodMode(false);

}



if (invis == false)
{
	ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);
	//	drawNotification("God Mode: ~b~Disabled");
}
else
{
	ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, false);
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

if (superjump == true)
{
GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
}

if (neverwanted == false) {
//	PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), false);
PLAYER::SET_MAX_WANTED_LEVEL(5);
}
else {
PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), 1);
PLAYER::SET_MAX_WANTED_LEVEL(0);
}
if (superman == true)
{
Hash hash = GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE");
WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);
ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
PED::SET_PED_TO_RAGDOLL_WITH_FALL(PLAYER::PLAYER_PED_ID(), 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
{
if (GetAsyncKeyState(0x57)) // W key
{
ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 6, 0);
}

if (GetAsyncKeyState(0x53)) // S key
{
ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, -6, 0);
}
if (GetAsyncKeyState(VK_SHIFT)) //VK_SHIFT
{
ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 0, 6);
}
}
}
else {
ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
}

if (expammo == true)
{
GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
}

if (fireammo == true)
{
GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());

}
if (NoReload == false) {
WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), 0);
}
else {
WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), 1);
}
if (expmelee == true) {
GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());
}
if (ragdoll == true)
{
Ped playerPed = PLAYER::PLAYER_PED_ID();

PED::SET_PED_CAN_RAGDOLL(playerPed, FALSE);
PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, FALSE);
}
else
{
Ped playerPed = PLAYER::PLAYER_PED_ID();

PED::SET_PED_CAN_RAGDOLL(playerPed, TRUE);
PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, TRUE);
}

if (hornboost == true)
{
Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
if (AUDIO::IS_HORN_ACTIVE(veh))
{
VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 50.f);
}

}

if (godveh == true)
{
if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
{
Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
ENTITY::SET_ENTITY_INVINCIBLE(vehicle, godveh);
ENTITY::SET_ENTITY_PROOFS(vehicle, godveh, godveh, godveh, godveh, godveh, godveh, godveh, godveh);
VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
VEHICLE::_SET_VEHICLE_PAINT_FADE(vehicle, 0.f);
VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, godveh);
VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, godveh);
VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !godveh);
VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !godveh);
VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !godveh);
VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !godveh);
VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !godveh);
VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !godveh);
}
}
if (RainbowVeh == true)
{

Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);

if (PED::IS_PED_IN_ANY_VEHICLE) {
VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);

}
}
if (RainbowMods == true)
{
Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
for (int i = 0; i < 50; i++)
{
VEHICLE::SET_VEHICLE_MOD(vehicle, i, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i)), false);
}
}
for (int i = 0; i < 32; i++)
{
bool validPlayer = NETWORK::NETWORK_IS_PLAYER_CONNECTED(i);
int TimePD1;

if (twopointfivekdrop[i]) {
if (!validPlayer) twopointfivekdrop[i] = false;
else
{

int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);

int amount = 2000;

if ((timeGetTime() - TimePD1) > 1000) // Time between drops
{
#define prop_money_bag_01 289396019

STREAMING::REQUEST_MODEL(prop_money_bag_01);
if (!STREAMING::HAS_MODEL_LOADED(prop_money_bag_01)) {
WAIT(0);
}
else {
Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, playerPosition.x, playerPosition.y, playerPosition.z + 1.5f, 0, amount, prop_money_bag_01, FALSE, TRUE);
STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(prop_money_bag_01);

TimePD1 = timeGetTime();
}
}


}

}


if (lobbyESP)
{
	loop_esp(i, bannerRect.R, bannerRect.G, bannerRect.B);
}
if (lobbyFuckCam)
{
	unsigned int ExplodeDelay = 0;

	if (ExplodeDelay < GetTickCount())
	{
		loop_fuckCam(i);
	}
}
}
}




void ScriptMain() {
	srand(GetTickCount());

	main();
}