#include "stdafx.h"
#include "shellapi.h"
#include "File.h"
using namespace std;
#include "MenuFunctions.h"

/*Things to do:

- add 2.5k self drop // drop hash: -1666779307
- see how t3zz3r3t does his drop and use that to fix normal 2k
- take a quick look at vehicle options


*/
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

bool Script::isInit()
{
	// Initialize some stuff here
	bool returnVal = true;

	return returnVal;
}
void initialize() {

}
#pragma region BOOLS
// self menu
bool god = false;
bool invis = false;
bool SuperJump = false;
bool fastswim = false;
bool fastrun = false;
// wanted editor
bool NeverWanted = false;
// weapons
bool ExpAmmo = false;
bool fireAmmo = false;
bool ExpMelee = false;
bool NoReload = false;
bool InfAmmo = false;
// vehicles
bool HornBoost = false;
bool GodVeh = false;
bool RainbowVeh = false;
bool RainbowMods = false;
//online
int TimePD1;
bool dildoTest[32];
bool lobbyESP;
bool lobbyFuckCam;
// recovery
bool moneydrop4stealth = false;
bool Money_rain = false;
bool twofivek = false;
// misc
bool MobileRadio = false;
bool MoneyGun = false;
#pragma endregion

// Updates all features that can be turned off by the game, being called each game frame


// Updates menu drawing.
void process_main_menu() {
	addTitle("Main Menu");
	addSubmenuOption("Self Options", 2);
	addSubmenuOption("Weapon Options", 6);
	addSubmenuOption("Teleport Options", 7);
	addSubmenuOption("Vehicle Options", 9);
	addSubmenuOption("Online Options", 36);
	addSubmenuOption("Misc", 44);
	addSubmenuOption("Settings", 47);
	addSubmenuOption("Credits", 3);
	addOption("http://gradienthacks.com/");
	addOption("Yo CrispyCunt when u gon crack dis");

	normalMenuActions();
}
void credits() {
	addTitle("Credits");
	addOption("Head Developer - Sinfool#2522");
	addOption("The Gradient Staff Team");
	addOption("auth - paulth2gaming");
	addOption("Infamous dev team");
	addOption("The sinister team/ redhunter");
	addOption("The member's of sinfool's dev server");
	normalMenuActions();

}
void Selfmenu() {
	addTitle("Self Options");
	addSubmenuOption("Particle FX", 5);
	addSubmenuOption("Wanted Editor", 4);
	addSubmenuOption("Animations", 46);
	addBoolOption("God Mode", god);//4		
	addBoolOption("Invisibility", invis);//5		
	addBoolOption("Super Jump", SuperJump);//6	
	addBoolOption("Fast Swim", fastswim);//7	
	addBoolOption("Fast Run", fastrun);//8
	normalMenuActions();

	switch (getOption())
	{
	case 4: god = !god; break;
	case 5: invis = !invis; break;
	case 6: SuperJump = !SuperJump; break;
	case 7: fastswim = !fastswim; break;
	case 8: fastrun = !fastrun; break;
	}
}

void wanted_editor() {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	addTitle("Wanted Editor");
	addBoolOption("Never Wanted", NeverWanted);
	addOption("Wanted Up");
	addOption("Wanted Down");
	normalMenuActions();

	switch (getOption())
	{
	case 1: NeverWanted = !NeverWanted; break;
	case 2:
	

		//			if (!PLAYER::IS_PLAYER_PLAYING(player)) return;

		if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) < 5)
		{
			PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, PLAYER::GET_PLAYER_WANTED_LEVEL(player) + 1, false);
			PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);
		}
		break;
	case 3:
	

		//		if (!PLAYER::IS_PLAYER_PLAYING(player)) return;

		if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) > 0)
		{
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(player);
			PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(player, PLAYER::GET_PLAYER_WANTED_LEVEL(player) - 1, false);
			PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, FALSE);
		}
		break;

	}
}
void ptfx() {
	addTitle("Particle FX");

	addOption("Clown Appears"); if (getOption() == 1){ ptfx("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears"); }
	addOption("Firework 1");    if (getOption() == 2){ ptfx("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst"); }
	addOption("Firework 2");    if (getOption() == 3){ ptfx("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw"); }
	addOption("Firework 3");    if (getOption() == 4) { ptfx("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw"); }
	addOption("Banknotes");     if (getOption() == 5){ ptfx("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes"); }
	addOption("Truck Crash");   if (getOption() == 6){ ptfx("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash"); }
	addOption("Alien 1");       if (getOption() == 7){ ptfx("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate"); }
	addOption("Alien 2");       if (getOption() == 8){ ptfx("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport"); }
	addOption("Electric Box");  if (getOption() == 9){ ptfx("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box"); }
	normalMenuActions();

}
void weapon_menu() {
	addTitle("Weapon Options");
	addOption("Give all Weapons");//1
	addOption("Give all Attachments");//2
	addBoolOption("Explosive Ammo", ExpAmmo);//3
	addBoolOption("Fire Ammo", fireAmmo); //4
	addBoolOption("Explosive Melee", ExpMelee); //5
	addBoolOption("No Reload", NoReload); //6
	addBoolOption("Infinite Ammo", InfAmmo); //7
	normalMenuActions();
	switch (getOption())
	{
	case 1: give_all_weps();   break;
	case 2: upgrade_guns(); break;
	case 3: ExpAmmo = !ExpAmmo; break;
	case 4: fireAmmo = !fireAmmo; break;
	case 5: ExpMelee = !ExpMelee; break;
	case 6: NoReload = !NoReload; break;
	case 7: InfAmmo = !InfAmmo;  break;
	}
}
void tp_options()
{
	addTitle("Teleport Options");
	addSubmenuOption("Ipls", 8);
	addOption("Teleport To Marker"); if (getOption() == 2){ teleport_to_marker(); }
	addOption("Teleport To Objective"); if (getOption() == 3) { teleport_to_objective(); }
	addTPOption("Micheal's House", -852.4f, 160.0f, 65.6f);
	addTPOption("Franklin's House", 7.9f, 548.1f, 175.5f);
	addTPOption("Franklin's House (Old)",-14.9693f, -1436.4430f, 31.1185f);
	addTPOption("Trevor's Trailer", 1985.7f, 3812.2f, 32.2f);
	addTPOption("Airport Enterance", -1034.6f, -2733.6f, 13.8f);
	addTPOption("Aiport Field", -1336.0f, -3044.0f, 13.9f);
	addTPOption("Elysian Island", 338.2f, -2715.9f, 38.5f);
	addTPOption("Strip Club DJ Booth", 126.135F, -1278.583F, 29.270F);
	addTPOption("Stripclub", 127.4f, -1307.7f, 29.2f);
	addTPOption("Elburro Heights", 1384.0f, -2057.1f, 52.0f);
	addTPOption("Ferris Wheel", -1670.7f, -1125.0f, 13.0f);
	addTPOption("Chumash", -3192.6f, 1100.0f, 20.2f);
	addTPOption("Windfarm", 2354.0f, 1830.3f, 101.1f);
	addTPOption("Military Base", -2047.4f, 3132.1f, 32.8f);
	addTPOption("Maze Bank", -75.015F, -818.215F, 326.176F);
	addTPOption("Desert Airfield", 1747.0f, 3273.7f, 41.1f);
	addTPOption("Chilliad", 425.4f, 5614.3f, 766.5f);
	addTPOption("North Yankton", 3360.19f, -4849.67f, 111.8f);
	addTPOption("Torture Warehouse", 136.514F, -2203.15F, 7.30914F);
	addTPOption("Plane Crash", 2395.096F, 3049.616F, 60.053F);
	addTPOption("Out to the sea", 1845.673f, -13787.4884f, 0.0000f);
	addTPOption("Your own Island",-2159.147f, 5196.89f, 20.00f);
	addTPOption("Under da Map", 132.1470f, -739.5430f, 39.00f);
	addTPOption("Far Away Beach", 178.3295f, 7041.8220f, 1.8671);
	addTPOption("On top of a lighthouse",3433.6570f, 5175.4090f, 35.8053f);
	addTPOption("Building Glitch", -11.5143f, -691.2623f, 54.7947f);
	addTPOption("500k Apartment",-793.36f, 296.86f, 87.84f);
	addTPOption("500k Garage", -795.4600f, 308.8900f, 85.7100f);
	addTPOption("Mors Mutual Impound", 408.923f, -1633.860f, 30.29f);
	addTPOption("Car Impound", 391.4746f, -1637.9750f, 29.3153f);
	addTPOption("Prison", 1679.0490f, 2513.7110f, 45.5649f);
	addTPOption("Prison Gym",1640.7910f, 2530.0440f, 45.5649f);
	normalMenuActions();
}
void ipls() {
	addTitle("Ipls");
	addOption("North Yankton");//1
	addOption("Yacht1 (MP ONLY)");//2
	addOption("Cluckin Bell");//3
	addOption("Morgue");//4
	addOption("Cargo Ship");//5
	addOption("Cargo Ship (Destroyed)");//6
	addOption("Destroyed Hospital");//7
	addOption("Lester Factory");//8
	addOption("Lester Factory (fire?)");//9
	addOption("Fort Zanacudo UFO");//10	
	addOption("Paleto Bay UFO");//11			
	addOption("O'Neil Farm (Destroyed)");//12
	addOption("O'Neil Farm");//13
	addOption("Life Invader Lobby");//14
	addOption("Airfield?");//15
	addOption("Simeon's Garage");//16		
	addOption("Union Depository Vault");//17
	addOption("Union Depository Garage");//18
	addOption("Jewelry Store");//19
	normalMenuActions();
	switch (getOption()) {
	case 1:nyankton(); break;
	case 2:Yacht1(); break;
	case 3:cbell(); break;
	case 4: Mmorg(); break;
	case 5:cship(); break;
	case 6:cshipSunk(); break;
	case 7: dhosp(); break;
	case 8: lfactduringDoor(); break;
	case 9: lfactFire(); break;
	case 10:ufo1(); break;
	case 11:ufo2(); break;
	case 12:destFarm(); break;
	case 13:intFarm(); break;
	case 14:facelobby(); break;
	case 15:airfield(); break;
	case 16:simeon(); break;
	case 17:udBigVault(); break;
	case 18: udShutters(); break;
	case 19:jewelStore(); break;

	}
}
void Vehicle_options() {
	addTitle("Vehicle Options");
	addSubmenuOption("Vehicle Spawner", 10);//1
	addOption("Repair Vehicle");//2			
	addBoolOption("Horn Boost", HornBoost);//3
	addBoolOption("God vehicle", GodVeh);//4		
	addBoolOption("Rainbow vehicle", RainbowVeh);//5
	addOption("Max Vehicle");//6	
	addOption("Open All Doors");//7
	addOption("Set Plate Text", [] {Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false); setPlate(veh); });//8						
	addBoolOption("Rainbow Mods", RainbowMods);//9
	switch (getOption())
	{
	case 2: repair(VEHICLE::GET_LAST_DRIVEN_VEHICLE()); break;
	case 3: HornBoost = !HornBoost; break;
	case 4: GodVeh = !GodVeh; break;
	case 5: RainbowVeh = !RainbowVeh; break;
	case 6: MaxVeh(); break;
	case 7: openDoors(); break;
	//case 8: Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false); setPlate(veh); break;
	case 9: RainbowMods = !RainbowMods; break;
	}
	normalMenuActions();
}
#include "VehSpawner.h"

void Vehicle_spawner() {
	addTitle("Vehicle Spawner");
	addBoolOption("Spawn In Veh", warpintoveh); if (getOption() == 1) { warpintoveh = !warpintoveh; }
	addBoolOption("Spawn Maxed", spawnmaxed); if (getOption() == 2) { spawnmaxed = !spawnmaxed; }
	addSubmenuOption("smugglers run", 35);
	addSubmenuOption("Gunrunning", 34);
	addSubmenuOption("Boats", 11);
	addSubmenuOption("Commercial", 12);
	addSubmenuOption("Compacts", 13);
	addSubmenuOption("Coupes", 14);
	addSubmenuOption("Coupes", 15);
	addSubmenuOption("Emergency", 16);
	addSubmenuOption("Helicopters", 17);
	addSubmenuOption("Industrial", 18);
	addSubmenuOption("Military", 19);
	addSubmenuOption("Motorcycles", 20);
	addSubmenuOption("Muscle", 21);
	addSubmenuOption("OffRoad", 22);
	addSubmenuOption("Planes", 23);
	addSubmenuOption("Sedans", 24);
	addSubmenuOption("Service", 25);
	addSubmenuOption("Sports", 26);
	addSubmenuOption("Sports Classics", 27);
	addSubmenuOption("Super", 28);
	addSubmenuOption("SUVs", 29);
	addSubmenuOption("Trailer", 30);
	addSubmenuOption("Trains", 31);
	addSubmenuOption("Utility", 32);
	addSubmenuOption("Vans", 33);
	normalMenuActions();

}
void Vehicle_spawner_boats() {
	addTitle("Boats");

	for (auto car : Boats) { addOptionBool(car, [car] { Spawn(car); }); };
	normalMenuActions();

}
void Vehicle_spawner_Commercial() {
	addTitle("Commercial");

	for (auto car : Commercial) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();


}
void Vehicle_spawner_Compacts() {
	addTitle("Compacts");

	for (auto car : Compacts) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();

}
void vehicle_spawner_Coupes() {
	addTitle("Coupes");

	for (auto car : Coupes) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();

}
void vehicle_spawner_Cycles() {
	addTitle("Cycles");
	for (auto car : Cycles) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();

}
void vehicle_spawner_Emergency() {
	addTitle("Emergency");
	for (auto car : Emergency) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Helicopters() {
	addTitle("Helicopters");
	for (auto car : Helicopters) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Industrial() {
	addTitle("Industrial");
	for (auto car : Industrial) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Military() {
	addTitle("Military");
	for (auto car : Military) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Motorcycles() {
	addTitle("Motorcycles");
	for (auto car : Motorcycles) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Muscle() {
	addTitle("Muscle");
	for (auto car : Muscle) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_OffRoad() {
	addTitle("OffRoad");
	for (auto car : OffRoad) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Planes() {
	addTitle("Planes");
	for (auto car : Planes) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Sedans() {
	addTitle("Sedans");
	for (auto car : Sedans) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Service() {
	addTitle("Service");
	for (auto car : Service) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Sports() {
	addTitle("Sports");
	for (auto car : Sports) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_SportsClassics() {
	addTitle("Sports Classics");
	for (auto car : SportsClassics) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Super() {
	addTitle("Super");
	for (auto car : Super) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_SUVs() {
	addTitle("SUVs");
	for (auto car : SUVs) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Trailer() {
	addTitle("Trailer");
	for (auto car : Trailer) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Trains() {
	addTitle("Trains");
	for (auto car : Trains) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Utility() {
	addTitle("Utility");
	for (auto car : Utility) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Vans() {
	addTitle("Vans");
	for (auto car : Vans) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_Gunrunning() {
	addTitle("Gunrunning");
	for (auto car : Gunrunning) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void vehicle_spawner_smugglersrun() {
	addTitle("smugglers run");
	for (auto car : smugglersrun) { addOptionBool(car, [car] { Spawn(car); }); }
	normalMenuActions();
}
void Onlineoptions() {
	addTitle("Online Options");
	addSubmenuOption("Lobby", 41);
	addSubmenuOption("Player List", 37);
	addSubmenuOption("Recovery", 42);
	// recovery 
	normalMenuActions();
}
bool isPlayerFriend(Player player) {
	if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(player)) {
		int handle;
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle, 13);
		return NETWORK::NETWORK_IS_FRIEND(&handle);
	}
	return false;
}
void Player_list() {
	addTitle("Player List");
	char buf[30];
	Ped selectedPed = 0ul;
	Vehicle veh = 0ul;
	for (int i = 0; i < 32; i++)
	{
		if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", -1, 0) == i) {
			snprintf(buf, sizeof(buf), "%s~y~ [HOST]", PLAYER::GET_PLAYER_NAME(i));
			addOption(buf);
		}
		else if (NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(i)) {
			snprintf(buf, sizeof(buf), "%s~r~ [ROCKSTAR/MODDER]", PLAYER::GET_PLAYER_NAME(i));
			addOption(buf);
		}
		else if (isPlayerFriend(i)) {
			snprintf(buf, sizeof(buf), "%s~b~ [FRIEND]", PLAYER::GET_PLAYER_NAME(i));
			addOption(buf);
		}
		else
			addOption(PLAYER::GET_PLAYER_NAME(i));
		if (i == 32)
			break;
	}
	if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
	{
		selectedPlayer = currentOption - 1;
		changeSubmenu(38);
	}
	normalMenuActions();

}
void Selected_player() {
	Ped selPed = 0ul;

	selPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);

	addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
	addSubmenuOption("Attach Objects", 39);

	addBoolOption("2k Drop", dildoTest[selectedPlayer]);
	addOption("Teleport To Player");
	addOption("Kick From Vehicle");
	addOption("Delete vehicle");
	addOption("Explode Player", [] {explodePed(selectedPlayer); });
	normalMenuActions();

	switch (getOption())
	{
	case 2:dildoTest[selectedPlayer] = !dildoTest[selectedPlayer]; break;
	case 3: Entity handle;
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false); break;
	case 4: kickVeh(selectedPlayer); break;
	case 5: deletePedVeh(selPed); break;
	}
}
int attachobj[100];
int nuattach = 1;
char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };
void Prop_create(char* hash) {
	bool custom = false;
	int objecthash = 0;
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
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
					ENTITY::ATTACH_ENTITY_TO_ENTITY(attachobj[nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
					nuattach++;
					if (nuattach >= 101) { nuattach = 1; }
				}
			}
		}
	}

}
void remove_objects() {
	for (int i = 0; i < 5; i++) {
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
		for (int i = 0; i < 136; i++) {
			Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer))) {
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
void Object_attacher(){
	Ini *settingsIni = new Ini(".\\settings.ini");
	string user = settingsIni->GetString("Login", "User");
	string pw = settingsIni->GetString("Login", "Pass");
	//std::string attach = "Attach Objects to:";
	addTitle("Attach Objects To Selected Player");
	if (user == "sinfool") {
		addSubmenuOption("Crash Objects", 40);
	}
	addOptionBool("Remove Objects",  [] { remove_objects(); });
	for (auto car : objects) { addOptionBool(car, [car] { Prop_create(car); }); }
	normalMenuActions();

}
void attach_crash_objects() {
	addTitle("Attach crash Objects To Selected Player");

	for (auto car : crash_objects) { addOptionBool(car, [car] { Prop_create(car); }); }
	normalMenuActions();

}
void lobby_options()
{
	addTitle("Lobby Options");
	addBoolOption("Lobby ESP", lobbyESP);
	addBoolOption("Fuck Camera", lobbyFuckCam);
	addOption("Explode all", [] {for (int i = 0; i < 32; i++){explodePed(i);}});
	normalMenuActions();

	switch (getOption())
	{
	case 1: lobbyESP = !lobbyESP; break;
	case 2: lobbyFuckCam = !lobbyFuckCam; break;
	}
}
bool tenmil2 = false;
bool twelvemil2 = false;
void Recovery()
{
	Ini *settingsIni = new Ini(".\\settings.ini");
	string user = settingsIni->GetString("Login", "User");
	string pw = settingsIni->GetString("Login", "Pass");
	addTitle("Recovery Options");
	
	addBoolOption("$10 drop", moneydrop4stealth);//1
	addBoolOption("Broke Ass Stealth", tenmil2);//2
	addOption("Enable $10 drop for stealth to work");//3
	addSubmenuOption("Set rank", 43);//2
	addBoolOption("Money Rain", Money_rain);//3
	addOption("Unlock All");//4
	addBoolOption("2.5k drop", twofivek);
	normalMenuActions();
	switch (getOption()) {
	case 1: moneydrop4stealth = !moneydrop4stealth; break;
	case 2: tenmil2 = !tenmil2; break;
//	case 3: twelvemil2 = !twelvemil2; break;
	case 5: Money_rain = !Money_rain; break;
	case 6: Unlock_all(); break;
	case 7: twofivek = !twofivek; break;
	}
	
}
void set_rank() {
	addTitle("Set Rank");
	addrpOption("level 100", 1584350, "");	addrpOption("level 200", 4691850, "");	addrpOption("level 300", 8299350, "");	addrpOption("level 400", 12406850, "");	addrpOption("level 500", 17014350, "");	addrpOption("level 600", 22121850, "");	addrpOption("level 700", 27729350, "");	addrpOption("level 800", 33836850, "");	addrpOption("level 900", 40444350, "");	addrpOption("level 1000", 47551850, "");
	normalMenuActions();
}
float waveheight = 0;

void misc() {
	addTitle("Misc");
	addBoolOption("Mobile Radio", MobileRadio);
	addSubmenuOption("Weather", 45);

	normalMenuActions();
	//addBoolOption("Money Gun", MoneyGun);zz
	switch (getOption())
	{
	case 1: MobileRadio = !MobileRadio; break;
//	case 2: MoneyGun = !MoneyGun; break;
	}
}
void weather() {
	addTitle("Weather Options");
	addOption("Weather Options are local only");
	addOption("Sunny", [] { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear"); });
	addOption("Rainy", [] {GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clearing"); });
	addOption("Foggy", [] {GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Foggy"); });
	addOption("Overcast", [] {GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast"); });
	addOption("Thunder", [] {GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder"); });
	addOption("Cloudy", [] {GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds"); });
	addOption("Snow", [] {GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Snowlight"); });
	addOption("Blizzard", [] {GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard"); } );
	addOption("Smog", [] { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog");  });
	normalMenuActions();
	
}
void Animations() {
	addTitle("Animations");
	addOption("Stop animation", [] {	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());});
//	for (auto car : animName) { addOptionBool(car, [car] { Spawn(car); }); }
	for (auto id : Animlist)
	{
		addOption(id.animName, [id] { PlayAnim(id.animDict, id.animName); });
	}
	normalMenuActions();

}
void Settings()
{
	addOption("Exit", [] { unhook(); });
}

void update_features()
{
	if (god == false) {
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
		//	drawNotification("God Mode: ~b~Disabled");
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		//		drawNotification("God Mode: ~b~Enabled");
	}
	if (invis == false) {
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);
		//	drawNotification("God Mode: ~b~Disabled");
	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, false);
		//		drawNotification("God Mode: ~b~Enabled");
	}
	if (SuperJump == true) {
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
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
	if (NeverWanted == false) {
		//	PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), false);
		PLAYER::SET_MAX_WANTED_LEVEL(5);
	}
	else {
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), 1);
		PLAYER::SET_MAX_WANTED_LEVEL(0);
	}
	if (ExpAmmo == true){
		GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
	}
	if (fireAmmo == true) {
		GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
    }
	if (ExpMelee == true) {
		GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());
    }
	if (NoReload == false) {
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), 0);
	}
	else {
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), 1);
	}
	if (InfAmmo == true) {
	loop_infiniteAmmo(PLAYER::PLAYER_PED_ID());

	}
	if (HornBoost == true) {
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		if (AUDIO::IS_HORN_ACTIVE(veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 50.f);
		}

	}
	if (GodVeh == true) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, GodVeh);
			ENTITY::SET_ENTITY_PROOFS(vehicle, GodVeh, GodVeh, GodVeh, GodVeh, GodVeh, GodVeh, GodVeh, GodVeh);
			VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
			VEHICLE::_SET_VEHICLE_PAINT_FADE(vehicle, 0.f);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, GodVeh);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, GodVeh);
			VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !GodVeh);
			VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !GodVeh);
			VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !GodVeh);
			VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !GodVeh);
			VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !GodVeh);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !GodVeh);
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
	if (Money_rain == true)
	{
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
	if (moneydrop4stealth == true)
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
		int amount = 10;

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
	if (twofivek == true)
	{
		int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
		Ped iPed = PLAYER::PLAYER_PED_ID();
		int amount = 2500;

		if ((timeGetTime() - TimePD1) > 1000) // Time between drops
		{
#define prop_money_bag_2point5k -1666779307

			STREAMING::REQUEST_MODEL(prop_money_bag_2point5k);
			if (!STREAMING::HAS_MODEL_LOADED(prop_money_bag_2point5k)) {
				WAIT(0);
			}
			else {
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
				OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, playerPosition.x, playerPosition.y, playerPosition.z + 1.5f, 0, amount, prop_money_bag_2point5k, FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(prop_money_bag_2point5k);

				TimePD1 = timeGetTime();
			}
		}
	}

	if (MobileRadio == false) {
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
	}
	else
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
	}
	if (MoneyGun == true)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if (ENTITY::DOES_ENTITY_EXIST(playerPed))
		{
			float Tmp[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)Tmp);
			if (Tmp[0] != 0 || Tmp[2] != 0 || Tmp[4] != 0)
			{
				int CashHash = 289396019; // prop_money_bag_01
										   //	int CashHash = -1803909274;  // prop_paper_bag_small = -1803909274
				int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
				STREAMING::REQUEST_MODEL(CashHash);
				while (!STREAMING::HAS_MODEL_LOADED(CashHash)) WAIT(0);
				OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, Tmp[0], Tmp[2], Tmp[4], 0, 2000, CashHash, false, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(CashHash);
			}

		 }
	}
	/*
	if (tenmil2 == true)
	{
		int TimePD4 = 1000;
		
			if ((timeGetTime() - TimePD4) > 100)
			{
				int money = 2147483647;
				Any transactionID = money;
				if (Hooking::network_shop_begin_service(&transactionID, 1474183246, 312105838, 1445302971, 100000000, 4))
					Hooking::stealth_bypass(&transactionID);
			}
		
	}*/
	if (tenmil2 == true) {
		tenmilstealth(true);
	}
	if (twelvemil2 == true)
	{
		twelvemilstealth(true);
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

		if (dildoTest[i]) {
			if (!validPlayer) dildoTest[i] = false;
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
/*
				Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);

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

				}*/
			}
		}
		RGBA bannerRect = { 244, 14, 67, 225 };

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
void main() {
	initialize();
	while (true)
	{
		update_features();
		monitorButtons();
		optionCount = 0;



		if (submenu == 1)
		{
			process_main_menu();
		}
		else if (submenu == 2)
		{
			Selfmenu();
     	}
		else if (submenu == 3)
		{
			credits();
		}
		else if (submenu == 4)
		{
			wanted_editor();
		}
		else if (submenu == 5)
		{
			ptfx();
		}
		else if (submenu == 6)
		{
			weapon_menu();
		}
		else if (submenu == 7)
		{
			tp_options();
		}
		else if (submenu == 8)
		{
			ipls();
		}
		else if (submenu == 9)
		{
			Vehicle_options();
		}
		else if (submenu == 10)
		{
			Vehicle_spawner();
		}
		else if (submenu == 11)
		{
			Vehicle_spawner_boats();
		}
		else if (submenu == 12)
		{
			Vehicle_spawner_Commercial();
		}
		else if (submenu == 13)
		{
			Vehicle_spawner_Compacts();
		}
		else if (submenu == 14)
		{
			vehicle_spawner_Coupes();
		}
		else if (submenu == 15)
		{
			vehicle_spawner_Cycles();
		}
		else if (submenu == 16)
		{
			vehicle_spawner_Emergency();
		}
		else if (submenu == 17)
		{
			vehicle_spawner_Helicopters();
		}
		else if (submenu == 18)
		{
			vehicle_spawner_Industrial();
		}
		else if (submenu == 19)
		{
			vehicle_spawner_Military();
		}
		else if (submenu == 20)
		{
			vehicle_spawner_Motorcycles();
		}
		else if (submenu == 21)
		{
			vehicle_spawner_Muscle();
		}
		else if (submenu == 22)
		{
			vehicle_spawner_OffRoad();
		}
		else if (submenu == 23)
		{
			vehicle_spawner_Planes();
		}
		else if (submenu == 24)
		{
			vehicle_spawner_Sedans();
		}
		else if (submenu == 25)
		{
			vehicle_spawner_Service();
		}
		else if (submenu == 26)
		{
			vehicle_spawner_Sports();
		}
		else if (submenu == 27)
		{
			vehicle_spawner_SportsClassics();
		}
		else if (submenu == 28)
		{
			vehicle_spawner_Super();
		}
		else if (submenu == 29)
		{
			vehicle_spawner_SUVs();
		}
		else if (submenu == 30)
		{
			vehicle_spawner_Trailer();
		}
		else if (submenu == 31)
		{
			vehicle_spawner_Trains();
		}
		else if (submenu == 32)
		{
			vehicle_spawner_Utility();
		}
		else if (submenu == 33)
		{
			vehicle_spawner_Vans();
		}
		else if (submenu == 34)
		{
			vehicle_spawner_Gunrunning();
		}
		else if (submenu == 35)
		{
			vehicle_spawner_smugglersrun();
		}
		else if (submenu == 36)
		{
			Onlineoptions();
		}
		else if (submenu == 37)
		{
			Player_list();
		}
		else if (submenu == 38)
		{
			Selected_player();
		}
		else if (submenu == 39)
		{
			Object_attacher();
		}
		else if (submenu == 40)
		{
			attach_crash_objects();
		}
		else if (submenu == 41)
		{
			lobby_options();
		}
		else if (submenu == 42)
		{
			Recovery();
		}
		else if (submenu == 43)
		{
			set_rank();
		}
		else if (submenu == 44)
		{
			misc();
		}
		else if (submenu == 45)
		{
			weather();
		}
		else if (submenu == 46)
		{
			Animations();
		}
		else if (submenu == 47)
		{
			Settings();
		}
		optionPress = false;
		WAIT(0);
	}
}
void Script::onTick()
{
	// Per game frame
	srand(GetTickCount());
	main();
}


















