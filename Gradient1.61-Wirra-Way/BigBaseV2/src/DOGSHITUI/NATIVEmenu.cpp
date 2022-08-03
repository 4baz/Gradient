#include "../common.hpp"
#include "NATIVEmenu.h"
#include "NATIVEbase.h"
#include "../natives.hpp"
#include "imgui.h"
#include "imgui_internal.h"
#include <util/vehicle.hpp>
#include "gta/Weapons.h"
#include "../../discordwirra.h"
#include <util/mobile.hpp>
#include <renderer.hpp>
//#include "../services/pickups/pickup_service.hpp"

#include "gta_util.hpp"
#include "services/pickups/pickup_service.hpp"
#include "services/players/player_service.hpp"
#include "util/globals.hpp"
#include "util/misc.hpp"
#include "util/ped.hpp"
#include "util/teleport.hpp"
#include "views/view.hpp"
#include "services/players/player_service.hpp"
#include "util/local_player.hpp"

#include <DOGSHITUI/NATIVEfeatures.h>
#include "backend/backend.hpp"
#define mnux  g->menu.menux
#define mnuy g->menu.menuy

using namespace VEHICLE;
//self options


bool p_god = false;
bool p_invis = false;
bool p_neverwanted = false;
bool p_mradio = false;
bool p_offradar = false;
bool p_fuckradio = false;

bool t_test_money = false;

bool v_proofs = false;
//Vector3 spawn_location = big::vehicle::get_spawn_location(big::g->spawn.spawn_inside);
//float spawn_heading = ENTITY::GET_ENTITY_HEADING(self::ped);
//int vehString;
//char* vehClasses[]{ "Super", "Sports", "Sports Classic", "Coupe", "Muscle", "Sedans", "Compacts", "SUV", "Offroad", "Motorcycles", "Planes", "Helicopters", "Vans", "Commercial", "Military", "Emergency", "Utility", "Industrial", "Service", "Cycles", "Trains", "Trailers" };

//player info
bool toggleplayerinfo = false;

//online
bool enable_esp_rgbmenu = false;



//dev/imgui values
bool enable_cursor = false;
bool dev_penis = false;
int penisposy = 200;
int penisposx = 150;
bool dev_imguiimage = false;

int pinfox = 980;
int pinfoy= 80;
int pinfosizex= 300;
int pinfosizey=400;


Hash $(std::string str) {
	std::string lowerNative = str;
	transform(lowerNative.begin(), lowerNative.end(), lowerNative.begin(), tolower);
	Hash num = 0;
	const char* bytes = lowerNative.c_str();;
	int length = strlen(bytes);
	for (int i = 0; i < length; i++)
	{
		num += bytes[i];
		num += num << 10;
		num ^= num >> 6;
	}
	num += num << 3;
	num ^= num >> 11;
	return (num + (num << 15));
}
using namespace vehiclehsh;

using namespace big;
using namespace self;
namespace sub{
	int speedtype = 0;


	void sub::vehicle() {

		AddVehicleTitle("Vehicle Options");
		AddSubmenu("Vehicle Spawner",SUB::VEHSPAWNER,"");
		AddSubmenu("LOS SANTOS CUSTOMS", SUB::LSC, "");
		AddToggle("Vehicle God Mode", &g->vehicle.god_mode,"");
		AddOption("Repair Vehicle", [] { vehicle::repair(self::veh); },"");
		AddToggle("Vehicle Damage Proof", &v_proofs, "");
		AddToggle("Horn Boost", &g->vehicle.horn_boost, "");
		AddToggle("Vehicle Jump", &g->vehicle.vehicle_jump, "");
		AddToggle("Drive On Water", &g->vehicle.drive_on_water, "");
		AddBreak("Vehicle Fly Options","");
		AddToggle("Vehicle Fly", &g->vehicle.fly.enabled, "");
		AddFloat("Fly Speed",&g->vehicle.fly.speed,1,5000,50,"");
		AddBreak("Vehicle Speedometer options","");
		AddToggle("Speedo On",&g->vehicle.speedo_meter.enabled,"");
		AddKmsSwitch(&speedtype, 0, 2, 1, "");
		g->vehicle.speedo_meter.x = .700f;
		g->vehicle.speedo_meter.y = .900f;
	//	g->vehicle.speed_unit = SpeedUnit::KMPH;
		//add your own way to set speed that doesnt use conversions and just the raw float values so not too complicated
		// 
		//AddKmsSwitch(&speedtype,0,2,1,"");
	//	AddFloat("Fly Speed", &user_fly, vehicle::mps_to_speed(0.f, g->vehicle.speed_unit),vehicle::mps_to_speed(150.f, g->vehicle.speed_unit), 10,"");
	//	g->vehicle.fly.speed = vehicle::speed_to_mps(user_fly, g->vehicle.speed_unit);
		
		//add speedo toggle

	}
	void testspawn(Hash test) {

		Vector3 spawn_location = vehicle::get_spawn_location(g->spawn.spawn_inside);
		float spawn_heading = ENTITY::GET_ENTITY_HEADING(self::ped);

		const Vehicle veh = vehicle::spawn(test, spawn_location, spawn_heading);

		if (veh == 0)
		{
			g_notification_service->push_error("Vehicle", "Unable to spawn vehicle");
		}
		else
		{
			if (g->spawn.spawn_maxed)
			{
				vehicle::max_vehicle(veh);
			}

			//	vehicle::set_plate(veh, plate);

			if (g->spawn.spawn_inside)
			{
				vehicle::teleport_into_vehicle(veh);
			}
		}


	}
	int veh_armor = 0;
	int veh_engine = 0;
	int veh_brakes = 0;
	int veh_spoilers = 0;
	int veh_skirts = 0;
	int veh_suspen = 0;
	int veh_trans = 0;
	int veh_paint = 0;
	int veh_windows = 0;
	int veh_tsmoke = 0;
	int veh_horn = 0;
	int veh_wheels = 0;
	int veh_fbumper = 0;
	int veh_rbumper = 0;
	int veh_plate = 0;
	const char* smoketype = "";

	int vehcolourr;
	int vehcolourg;
	int vehcolourb;

	int smokecarr;
	int smokecarg;
	int smokecarb;


	void sub::lscustoms() {
		int Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);

		AddVehicleTitle("Baz's Customs");
		AddOption("Coming soon","I couldnt be bothered making this");
		AddInt("Veh Colour R", &vehcolourr, 0, 255, 1, "");
		AddInt("Veh Colour G", &vehcolourg, 0, 255, 1, "");
		AddInt("Veh Colour B", &vehcolourb, 0, 255, 1, "");

		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Veh, vehcolourr, vehcolourg, vehcolourb);
		//AddInt(smoketype, &veh_tsmoke, 0, 5, 1, "");

		AddInt("Plate", &veh_plate, 0, 5, 1, "");
		VEHICLE::SET_VEHICLE_MOD_KIT(Veh, 0);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Veh, veh_plate);


	}

	void sub::VEH_CRIMINALENTPRISE() {
		AddVehicleTitle("Criminal Enterprise");
		AddOption("OMNISEGT", [] {testspawn(VEHICLE_OMNISEGT); }, "");
		AddOption("SENTINEL4", [] {testspawn(VEHICLE_SENTINEL4); }, "");
		AddOption("CONADA", [] {testspawn(VEHICLE_CONADA); }, "");
		AddOption("RUINER4", [] {testspawn(VEHICLE_RUINER4); }, "");
		AddOption("BRIOSO3", [] {testspawn(VEHICLE_BRIOSO3); }, "");
		AddOption("CORSITA", [] {testspawn(VEHICLE_CORSITA); }, "");
		AddOption("DRAUGUR", [] {testspawn(VEHICLE_DRAUGUR); }, "");
		AddOption("KANJOSJ", [] {testspawn(VEHICLE_KANJOSJ); }, "");
		AddOption("POSTLUDE", [] {testspawn(VEHICLE_POSTLUDE); }, "");
		AddOption("TORERO2", [] {testspawn(VEHICLE_TORERO2); }, "");
		AddOption("VIGERO2", [] {testspawn(VEHICLE_VIGERO2); }, "");
		AddOption("LM87", [] {testspawn(VEHICLE_LM87); }, "");
		AddOption("TENF", [] {testspawn(VEHICLE_TENF); }, "");
		AddOption("TENF2", [] {testspawn(VEHICLE_TENF2); }, "");
		AddOption("RHINEHART", [] {testspawn(VEHICLE_RHINEHART); }, "");
		AddOption("GREENWOOD", [] {testspawn(VEHICLE_GREENWOOD); }, "");
		AddOption("SM722", [] {testspawn(VEHICLE_SM722); }, "");
		AddOption("WEEVIL2", [] {testspawn(VEHICLE_WEEVIL2); }, "");
	

	}
	void sub::VEH_Boats() {
		AddVehicleTitle("Boats");
		AddOption("DINGHY", [] {testspawn(VEHICLE_DINGHY); }, "");
		AddOption("DINGHY2", [] {testspawn(VEHICLE_DINGHY2); }, "");
		AddOption("DINGHY3", [] {testspawn(VEHICLE_DINGHY3); }, "");
		AddOption("DINGHY4", [] {testspawn(VEHICLE_DINGHY4); }, "");
		AddOption("JETMAX", [] {testspawn(VEHICLE_JETMAX); }, "");
		AddOption("MARQUIS", [] {testspawn(VEHICLE_MARQUIS); }, "");
		AddOption("SEASHARK", [] {testspawn(VEHICLE_SEASHARK); }, "");
		AddOption("SEASHARK2", [] {testspawn(VEHICLE_SEASHARK2); }, "");
		AddOption("SEASHARK3", [] {testspawn(VEHICLE_SEASHARK3); }, "");
		AddOption("SPEEDER", [] {testspawn(VEHICLE_SPEEDER); }, "");
		AddOption("SPEEDER2", [] {testspawn(VEHICLE_SPEEDER2); }, "");
		AddOption("SQUALO", [] {testspawn(VEHICLE_SQUALO); }, "");
		AddOption("SUBMERSIBLE", [] {testspawn(VEHICLE_SUBMERSIBLE); }, "");
		AddOption("SUBMERSIBLE2", [] {testspawn(VEHICLE_SUBMERSIBLE2); }, "");
		AddOption("SUNTRAP", [] {testspawn(VEHICLE_SUNTRAP); }, "");
		AddOption("TORO", [] {testspawn(VEHICLE_TORO); }, "");
		AddOption("TORO2", [] {testspawn(VEHICLE_TORO2); }, "");
		AddOption("TROPIC", [] {testspawn(VEHICLE_TROPIC); }, "");
		AddOption("TROPIC2", [] {testspawn(VEHICLE_TROPIC2); }, "");
		AddOption("TUG", [] {testspawn(VEHICLE_TUG); }, "");

	}

	void sub::VEH_Commercials() {

		AddVehicleTitle("Commercial");
		AddOption("BENSON", [] {testspawn(VEHICLE_BENSON); }, "");
		AddOption("BIFF", [] {testspawn(VEHICLE_BIFF); }, "");
		AddOption("HAULER", [] {testspawn(VEHICLE_HAULER); }, "");
		AddOption("HAULER2", [] {testspawn(VEHICLE_HAULER2); }, "");
		AddOption("MULE", [] {testspawn(VEHICLE_MULE); }, "");
		AddOption("MULE2", [] {testspawn(VEHICLE_MULE2); }, "");
		AddOption("MULE3", [] {testspawn(VEHICLE_MULE3); }, "");
		AddOption("MULE4", [] {testspawn(VEHICLE_MULE4); }, "");
		AddOption("PACKER", [] {testspawn(VEHICLE_PACKER); }, "");
		AddOption("PHANTOM", [] {testspawn(VEHICLE_PHANTOM); }, "");
		AddOption("PHANTOM2", [] {testspawn(VEHICLE_PHANTOM2); }, "");
		AddOption("PHANTOM3", [] {testspawn(VEHICLE_PHANTOM3); }, "");
		AddOption("POUNDER", [] {testspawn(VEHICLE_POUNDER); }, "");
		AddOption("POUNDER2", [] {testspawn(VEHICLE_POUNDER2); }, "");
		AddOption("STOCKADE", [] {testspawn(VEHICLE_STOCKADE); }, "");
		AddOption("STOCKADE3", [] {testspawn(VEHICLE_STOCKADE3); }, "");
		AddOption("TERBYTE", [] {testspawn(VEHICLE_TERBYTE); }, "");

	}

	void sub::VEH_compacts() {
		AddVehicleTitle("Compacts");
		AddOption("BLISTA", [] {testspawn(VEHICLE_BLISTA); }, "");
		AddOption("BRIOSO", [] {testspawn(VEHICLE_BRIOSO); }, "");
		AddOption("DILETTANTE", [] {testspawn(VEHICLE_DILETTANTE); }, "");
		AddOption("DILETTANTE2", [] {testspawn(VEHICLE_DILETTANTE2); }, "");
		AddOption("ISSI2", [] {testspawn(VEHICLE_ISSI2); }, "");
		AddOption("ISSI3", [] {testspawn(VEHICLE_ISSI3); }, "");
		AddOption("PANTO", [] {testspawn(VEHICLE_PANTO); }, "");
		AddOption("PRAIRIE", [] {testspawn(VEHICLE_PRAIRIE); }, "");
		AddOption("RHAPSODY", [] {testspawn(VEHICLE_RHAPSODY); }, "");


	}

	void sub::VEH_Coupes() {
		AddVehicleTitle("Coupes");
		AddOption("COGCABRIO", [] {testspawn(VEHICLE_COGCABRIO); }, "");
		AddOption("EXEMPLAR", [] {testspawn(VEHICLE_EXEMPLAR); }, "");
		AddOption("F620", [] {testspawn(VEHICLE_F620); }, "");
		AddOption("FELON", [] {testspawn(VEHICLE_FELON); }, "");
		AddOption("FELON2", [] {testspawn(VEHICLE_FELON2); }, "");
		AddOption("JACKAL", [] {testspawn(VEHICLE_JACKAL); }, "");
		AddOption("ORACLE", [] {testspawn(VEHICLE_ORACLE); }, "");
		AddOption("ORACLE2", [] {testspawn(VEHICLE_ORACLE2); }, "");
		AddOption("SENTINEL", [] {testspawn(VEHICLE_SENTINEL); }, "");
		AddOption("SENTINEL2", [] {testspawn(VEHICLE_SENTINEL2); }, "");
		AddOption("WINDSOR", [] {testspawn(VEHICLE_WINDSOR); }, "");
		AddOption("WINDSOR2", [] {testspawn(VEHICLE_WINDSOR2); }, "");
		AddOption("ZION", [] {testspawn(VEHICLE_ZION); }, "");
		AddOption("ZION2", [] {testspawn(VEHICLE_ZION2); }, "");

	}


	void sub::VEH_BIKES() {
		AddVehicleTitle("Bikes");
		AddOption("BMX", [] {testspawn(VEHICLE_BMX); }, "");
		AddOption("CRUISER", [] {testspawn(VEHICLE_CRUISER); }, "");
		AddOption("FIXTER", [] {testspawn(VEHICLE_FIXTER); }, "");
		AddOption("SCORCHER", [] {testspawn(VEHICLE_SCORCHER); }, "");
		AddOption("TRIBIKE", [] {testspawn(VEHICLE_TRIBIKE); }, "");
		AddOption("TRIBIKE2", [] {testspawn(VEHICLE_TRIBIKE2); }, "");
		AddOption("TRIBIKE3", [] {testspawn(VEHICLE_TRIBIKE3); }, "");


	}


	void sub::VEH_Emergency() {
		AddVehicleTitle("Emergency");
		AddOption("AMBULANCE", [] {testspawn(VEHICLE_AMBULANCE); }, "");
		AddOption("FBI", [] {testspawn(VEHICLE_FBI); }, "");
		AddOption("FBI2", [] {testspawn(VEHICLE_FBI2); }, "");
		AddOption("FIRETRUK", [] {testspawn(VEHICLE_FIRETRUK); }, "");
		AddOption("LGUARD", [] {testspawn(VEHICLE_LGUARD); }, "");
		AddOption("PBUS", [] {testspawn(VEHICLE_PBUS); }, "");
		AddOption("POLICE", [] {testspawn(VEHICLE_POLICE); }, "");
		AddOption("POLICE2", [] {testspawn(VEHICLE_POLICE2); }, "");
		AddOption("POLICE3", [] {testspawn(VEHICLE_POLICE3); }, "");
		AddOption("POLICE4", [] {testspawn(VEHICLE_POLICE4); }, "");
		AddOption("POLICEB", [] {testspawn(VEHICLE_POLICEB); }, "");
		AddOption("POLMAV", [] {testspawn(VEHICLE_POLMAV); }, "");
		AddOption("POLICEOLD1", [] {testspawn(VEHICLE_POLICEOLD1); }, "");
		AddOption("POLICEOLD2", [] {testspawn(VEHICLE_POLICEOLD2); }, "");
		AddOption("POLICET", [] {testspawn(VEHICLE_POLICET); }, "");
		AddOption("PRANGER", [] {testspawn(VEHICLE_PRANGER); }, "");
		AddOption("PREDATOR", [] {testspawn(VEHICLE_PREDATOR); }, "");
		AddOption("RIOT", [] {testspawn(VEHICLE_RIOT); }, "");
		AddOption("RIOT2", [] {testspawn(VEHICLE_RIOT2); }, "");
		AddOption("SHERIFF", [] {testspawn(VEHICLE_SHERIFF); }, "");
		AddOption("SHERIFF2", [] {testspawn(VEHICLE_SHERIFF2); }, "");


	}

	void sub::VEH_Helicopters() {

		AddVehicleTitle("Helicopters");
		AddOption("AKULA", [] {testspawn(VEHICLE_AKULA); }, "");
		AddOption("ANNIHILATOR", [] {testspawn(VEHICLE_ANNIHILATOR); }, "");
		AddOption("BUZZARD", [] {testspawn(VEHICLE_BUZZARD); }, "");
		AddOption("BUZZARD2", [] {testspawn(VEHICLE_BUZZARD2); }, "");
		AddOption("CARGOBOB", [] {testspawn(VEHICLE_CARGOBOB); }, "");
		AddOption("CARGOBOB2", [] {testspawn(VEHICLE_CARGOBOB2); }, "");
		AddOption("CARGOBOB3", [] {testspawn(VEHICLE_CARGOBOB3); }, "");
		AddOption("CARGOBOB4", [] {testspawn(VEHICLE_CARGOBOB4); }, "");
		AddOption("FROGGER", [] {testspawn(VEHICLE_FROGGER); }, "");
		AddOption("FROGGER2", [] {testspawn(VEHICLE_FROGGER2); }, "");
		AddOption("HAVOK", [] {testspawn(VEHICLE_HAVOK); }, "");
		AddOption("HUNTER", [] {testspawn(VEHICLE_HUNTER); }, "");
		AddOption("MAVERICK", [] {testspawn(VEHICLE_MAVERICK); }, "");
		AddOption("SAVAGE", [] {testspawn(VEHICLE_SAVAGE); }, "");
		AddOption("SKYLIFT", [] {testspawn(VEHICLE_SKYLIFT); }, "");
		AddOption("SUPERVOLITO", [] {testspawn(VEHICLE_SUPERVOLITO); }, "");
		AddOption("SUPERVOLITO2", [] {testspawn(VEHICLE_SUPERVOLITO2); }, "");
		AddOption("SWIFT", [] {testspawn(VEHICLE_SWIFT); }, "");
		AddOption("SWIFT2", [] {testspawn(VEHICLE_SWIFT2); }, "");
		AddOption("VALKYRIE", [] {testspawn(VEHICLE_VALKYRIE); }, "");
		AddOption("VALKYRIE2", [] {testspawn(VEHICLE_VALKYRIE2); }, "");
		AddOption("VOLATUS", [] {testspawn(VEHICLE_VOLATUS); }, "");


	}

	void sub::VEH_industraial() {
		AddVehicleTitle("Industrial");
		AddOption("BULLDOZER", [] {testspawn(VEHICLE_BULLDOZER); }, "");
		AddOption("CUTTER", [] {testspawn(VEHICLE_CUTTER); }, "");
		AddOption("DUMP", [] {testspawn(VEHICLE_DUMP); }, "");
		AddOption("FLATBED", [] {testspawn(VEHICLE_FLATBED); }, "");
		AddOption("GUARDIAN", [] {testspawn(VEHICLE_GUARDIAN); }, "");
		AddOption("HANDLER", [] {testspawn(VEHICLE_HANDLER); }, "");
		AddOption("MIXER", [] {testspawn(VEHICLE_MIXER); }, "");
		AddOption("MIXER2", [] {testspawn(VEHICLE_MIXER2); }, "");
		AddOption("RUBBLE", [] {testspawn(VEHICLE_RUBBLE); }, "");
		AddOption("TIPTRUCK", [] {testspawn(VEHICLE_TIPTRUCK); }, "");
		AddOption("TIPTRUCK2", [] {testspawn(VEHICLE_TIPTRUCK2); }, "");



	}

	void sub::VEH_Military() {
		AddVehicleTitle("Military");
		AddOption("APC", [] {testspawn(VEHICLE_APC); }, "");
		AddOption("BARRACKS", [] {testspawn(VEHICLE_BARRACKS); }, "");
		AddOption("BARRACKS2", [] {testspawn(VEHICLE_BARRACKS2); }, "");
		AddOption("BARRACKS3", [] {testspawn(VEHICLE_BARRACKS3); }, "");
		AddOption("BARRAGE", [] {testspawn(VEHICLE_BARRAGE); }, "");
		AddOption("CHERNOBOG", [] {testspawn(VEHICLE_CHERNOBOG); }, "");
		AddOption("CRUSADER", [] {testspawn(VEHICLE_CRUSADER); }, "");
		AddOption("HALFTRACK", [] {testspawn(VEHICLE_HALFTRACK); }, "");
		AddOption("KHANJALI", [] {testspawn(VEHICLE_KHANJALI); }, "");
		AddOption("RHINO", [] {testspawn(VEHICLE_RHINO); }, "");
		AddOption("THRUSTER", [] {testspawn(VEHICLE_THRUSTER); }, "");
		AddOption("TRAILERSMALL2", [] {testspawn(VEHICLE_TRAILERSMALL2); }, "");
		

	}


	void sub::VEH_MOTOCYCLE() {
		AddVehicleTitle("Motocycle");
		AddOption("AKUMA", [] {testspawn(VEHICLE_AKUMA); }, "");
		AddOption("AVARUS", [] {testspawn(VEHICLE_AVARUS); }, "");
		AddOption("BAGGER", [] {testspawn(VEHICLE_BAGGER); }, "");
		AddOption("BATI", [] {testspawn(VEHICLE_BATI); }, "");
		AddOption("BATI2", [] {testspawn(VEHICLE_BATI2); }, "");
		AddOption("BF400", [] {testspawn(VEHICLE_BF400); }, "");
		AddOption("CARBONRS", [] {testspawn(VEHICLE_CARBONRS); }, "");
		AddOption("CHIMERA", [] {testspawn(VEHICLE_CHIMERA); }, "");
		AddOption("CLIFFHANGER", [] {testspawn(VEHICLE_CLIFFHANGER); }, "");
		AddOption("DAEMON", [] {testspawn(VEHICLE_DAEMON); }, "");
		AddOption("DAEMON2", [] {testspawn(VEHICLE_DAEMON2); }, "");
		AddOption("DEFILER", [] {testspawn(VEHICLE_DEFILER); }, "");
		AddOption("DIABLOUS", [] {testspawn(VEHICLE_DIABLOUS); }, "");
		AddOption("DIABLOUS2", [] {testspawn(VEHICLE_DIABLOUS2); }, "");
		AddOption("DOUBLE", [] {testspawn(VEHICLE_DOUBLE); }, "");
		AddOption("ENDURO", [] {testspawn(VEHICLE_ENDURO); }, "");
		AddOption("ESSKEY", [] {testspawn(VEHICLE_ESSKEY); }, "");
		AddOption("FAGGIO", [] {testspawn(VEHICLE_FAGGIO); }, "");
		AddOption("FAGGIO2", [] {testspawn(VEHICLE_FAGGIO2); }, "");
		AddOption("FAGGIO3", [] {testspawn(VEHICLE_FAGGIO3); }, "");
		AddOption("FCR", [] {testspawn(VEHICLE_FCR); }, "");
		AddOption("FCR2", [] {testspawn(VEHICLE_FCR2); }, "");
		AddOption("GARGOYLE", [] {testspawn(VEHICLE_GARGOYLE); }, "");
		AddOption("HAKUCHOU", [] {testspawn(VEHICLE_HAKUCHOU); }, "");
		AddOption("HAKUCHOU2", [] {testspawn(VEHICLE_HAKUCHOU2); }, "");
		AddOption("HEXER", [] {testspawn(VEHICLE_HEXER); }, "");
		AddOption("INNOVATION", [] {testspawn(VEHICLE_INNOVATION); }, "");
		AddOption("LECTRO", [] {testspawn(VEHICLE_LECTRO); }, "");
		AddOption("MANCHEZ", [] {testspawn(VEHICLE_MANCHEZ); }, "");
		AddOption("NEMESIS", [] {testspawn(VEHICLE_NEMESIS); }, "");
		AddOption("NIGHTBLADE", [] {testspawn(VEHICLE_NIGHTBLADE); }, "");
		AddOption("OPPRESSOR", [] {testspawn(VEHICLE_OPPRESSOR); }, "");
		AddOption("OPPRESSOR2", [] {testspawn(VEHICLE_OPPRESSOR2); }, "");
		AddOption("PCJ", [] {testspawn(VEHICLE_PCJ); }, "");
		AddOption("RATBIKE", [] {testspawn(VEHICLE_RATBIKE); }, "");
		AddOption("RUFFIAN", [] {testspawn(VEHICLE_RUFFIAN); }, "");
		AddOption("SANCHEZ2", [] {testspawn(VEHICLE_SANCHEZ2); }, "");
		AddOption("SANCTUS", [] {testspawn(VEHICLE_SANCTUS); }, "");
		AddOption("SHOTARO", [] {testspawn(VEHICLE_SHOTARO); }, "");
		AddOption("SOVEREIGN", [] {testspawn(VEHICLE_SOVEREIGN); }, "");
		AddOption("THRUST", [] {testspawn(VEHICLE_THRUST); }, "");
		AddOption("VADER", [] {testspawn(VEHICLE_VADER); }, "");
		AddOption("VINDICATOR", [] {testspawn(VEHICLE_VINDICATOR); }, "");
		AddOption("VORTEX", [] {testspawn(VEHICLE_VORTEX); }, "");
		AddOption("WOLFSBANE", [] {testspawn(VEHICLE_WOLFSBANE); }, "");
		AddOption("ZOMBIEA", [] {testspawn(VEHICLE_ZOMBIEA); }, "");
		AddOption("ZOMBIEB", [] {testspawn(VEHICLE_ZOMBIEB); }, "");

	}

	void sub::VEH_Muscle() {
		AddVehicleTitle("Muscle");
		AddOption("BLADE", [] {testspawn(VEHICLE_BLADE); }, "");
		AddOption("BUCCANEER", [] {testspawn(VEHICLE_BUCCANEER); }, "");
		AddOption("BUCCANEER2", [] {testspawn(VEHICLE_BUCCANEER2); }, "");
		AddOption("CHINO", [] {testspawn(VEHICLE_CHINO); }, "");
		AddOption("CHINO2", [] {testspawn(VEHICLE_CHINO2); }, "");
		AddOption("COQUETTE3", [] {testspawn(VEHICLE_COQUETTE3); }, "");
		AddOption("DOMINATOR", [] {testspawn(VEHICLE_DOMINATOR); }, "");
		AddOption("DOMINATOR2", [] {testspawn(VEHICLE_DOMINATOR2); }, "");
		AddOption("DOMINATOR3", [] {testspawn(VEHICLE_DOMINATOR3); }, "");
		AddOption("VEHICLE_DUKES", [] {testspawn(VEHICLE_DUKES); }, "");
		AddOption("VEHICLE_DUKES2", [] {testspawn(VEHICLE_DUKES2); }, "");
		AddOption("VEHICLE_ELLIE", [] {testspawn(VEHICLE_ELLIE); }, "");
		AddOption("VEHICLE_FACTION", [] {testspawn(VEHICLE_FACTION); }, "");
		AddOption("VEHICLE_FACTION2", [] {testspawn(VEHICLE_FACTION2); }, "");
		AddOption("VEHICLE_FACTION3", [] {testspawn(VEHICLE_FACTION3); }, "");
		AddOption("VEHICLE_GAUNTLET", [] {testspawn(VEHICLE_GAUNTLET); }, "");
		AddOption("VEHICLE_GAUNTLET2", [] {testspawn(VEHICLE_GAUNTLET2); }, "");
		AddOption("VEHICLE_HERMES", [] {testspawn(VEHICLE_HERMES); }, "");
		AddOption("VEHICLE_HOTKNIFE", [] {testspawn(VEHICLE_HOTKNIFE); }, "");
		AddOption("VEHICLE_LURCHER", [] {testspawn(VEHICLE_LURCHER); }, "");
		AddOption("VEHICLE_MOONBEAM", [] {testspawn(VEHICLE_MOONBEAM); }, "");
		AddOption("VEHICLE_MOONBEAM2", [] {testspawn(VEHICLE_MOONBEAM2); }, "");
		AddOption("VEHICLE_NIGHTSHADE", [] {testspawn(VEHICLE_NIGHTSHADE); }, "");
		AddOption("VEHICLE_PHOENIX", [] {testspawn(VEHICLE_PHOENIX); }, "");
		AddOption("VEHICLE_PICADOR", [] {testspawn(VEHICLE_PICADOR); }, "");
		AddOption("VEHICLE_RATLOADER", [] {testspawn(VEHICLE_RATLOADER); }, "");
		AddOption("VEHICLE_RATLOADER2", [] {testspawn(VEHICLE_RATLOADER2); }, "");
		AddOption("VEHICLE_RUINER", [] {testspawn(VEHICLE_RUINER); }, "");
		AddOption("VEHICLE_RUINER2", [] {testspawn(VEHICLE_RUINER2); }, "");
		AddOption("VEHICLE_RUINER3", [] {testspawn(VEHICLE_RUINER3); }, "");
		AddOption("VEHICLE_SABREGT", [] {testspawn(VEHICLE_SABREGT); }, "");
		AddOption("VEHICLE_SABREGT2", [] {testspawn(VEHICLE_SABREGT2); }, "");
		AddOption("VEHICLE_SLAMVAN", [] {testspawn(VEHICLE_SLAMVAN); }, "");
		AddOption("VEHICLE_SLAMVAN2", [] {testspawn(VEHICLE_SLAMVAN2); }, "");
		AddOption("VEHICLE_SLAMVAN3", [] {testspawn(VEHICLE_SLAMVAN3); }, "");
		AddOption("VEHICLE_STALION", [] {testspawn(VEHICLE_STALION); }, "");
		AddOption("VEHICLE_STALION2", [] {testspawn(VEHICLE_STALION2); }, "");
		AddOption("VEHICLE_TAMPA", [] {testspawn(VEHICLE_TAMPA); }, "");
		AddOption("VEHICLE_TAMPA3", [] {testspawn(VEHICLE_TAMPA3); }, "");
		AddOption("VEHICLE_VIGERO", [] {testspawn(VEHICLE_VIGERO); }, "");
		AddOption("VEHICLE_VIRGO", [] {testspawn(VEHICLE_VIRGO); }, "");
		AddOption("VEHICLE_VIRGO2", [] {testspawn(VEHICLE_VIRGO2); }, "");
		AddOption("VEHICLE_VIRGO3", [] {testspawn(VEHICLE_VIRGO3); }, "");
		AddOption("VEHICLE_VOODOO", [] {testspawn(VEHICLE_VOODOO); }, "");
		AddOption("VEHICLE_VOODOO2", [] {testspawn(VEHICLE_VOODOO2); }, "");
		AddOption("VEHICLE_YOSEMITE", [] {testspawn(VEHICLE_YOSEMITE); }, "");
	
	}


	void sub::VEH_Offroad() {
		AddVehicleTitle("OffRoad");
		AddOption("BFINJECTION", [] {testspawn(VEHICLE_BFINJECTION); }, "");
		AddOption("BIFTA", [] {testspawn(VEHICLE_BIFTA); }, "");
		AddOption("BLAZER", [] {testspawn(VEHICLE_BLAZER); }, "");
		AddOption("BLAZER2", [] {testspawn(VEHICLE_BLAZER2); }, "");
		AddOption("BLAZER3", [] {testspawn(VEHICLE_BLAZER3); }, "");
		AddOption("BLAZER4", [] {testspawn(VEHICLE_BLAZER4); }, "");
		AddOption("BLAZER5", [] {testspawn(VEHICLE_BLAZER5); }, "");
		AddOption("BODHI2", [] {testspawn(VEHICLE_BODHI2); }, "");
		AddOption("BRAWLER", [] {testspawn(VEHICLE_BRAWLER); }, "");
		AddOption("DLOADER", [] {testspawn(VEHICLE_DLOADER); }, "");
		AddOption("DUBSTA3", [] {testspawn(VEHICLE_DUBSTA3); }, "");
		AddOption("DUNE", [] {testspawn(VEHICLE_DUNE); }, "");
		AddOption("DUNE2", [] {testspawn(VEHICLE_DUNE2); }, "");
		AddOption("DUNE3", [] {testspawn(VEHICLE_DUNE3); }, "");
		AddOption("DUNE4", [] {testspawn(VEHICLE_DUNE4); }, "");
		AddOption("DUNE5", [] {testspawn(VEHICLE_DUNE5); }, "");
		AddOption("FREECRAWLER", [] {testspawn(VEHICLE_FREECRAWLER); }, "");
		AddOption("INSURGENT", [] {testspawn(VEHICLE_INSURGENT); }, "");
		AddOption("INSURGENT2", [] {testspawn(VEHICLE_INSURGENT2); }, "");
		AddOption("INSURGENT3", [] {testspawn(VEHICLE_INSURGENT3); }, "");
		AddOption("KALAHARI", [] {testspawn(VEHICLE_KALAHARI); }, "");
		AddOption("KAMACHO", [] {testspawn(VEHICLE_KAMACHO); }, "");
		AddOption("MARSHALL", [] {testspawn(VEHICLE_MARSHALL); }, "");
		AddOption("MESA3", [] {testspawn(VEHICLE_MESA3); }, "");
		AddOption("MONSTER", [] {testspawn(VEHICLE_MONSTER); }, "");
		AddOption("MENACER", [] {testspawn(VEHICLE_MENACER); }, "");
		AddOption("NIGHTSHARK", [] {testspawn(VEHICLE_NIGHTSHARK); }, "");
		AddOption("RANCHERXL", [] {testspawn(VEHICLE_RANCHERXL); }, "");
		AddOption("RANCHERXL2", [] {testspawn(VEHICLE_RANCHERXL2); }, "");
		AddOption("REBEL", [] {testspawn(VEHICLE_REBEL); }, "");
		AddOption("REBEL2", [] {testspawn(VEHICLE_REBEL2); }, "");
		AddOption("RIATA", [] {testspawn(VEHICLE_RIATA); }, "");
		AddOption("SANDKING", [] {testspawn(VEHICLE_SANDKING); }, "");
		AddOption("SANDKING2", [] {testspawn(VEHICLE_SANDKING2); }, "");
		AddOption("TECHNICAL", [] {testspawn(VEHICLE_TECHNICAL); }, "");
		AddOption("TECHNICAL2", [] {testspawn(VEHICLE_TECHNICAL2); }, "");
		AddOption("TECHNICAL3", [] {testspawn(VEHICLE_TECHNICAL3); }, "");
		AddOption("TROPHYTRUCK", [] {testspawn(VEHICLE_TROPHYTRUCK); }, "");
		AddOption("TROPHYTRUCK2", [] {testspawn(VEHICLE_TROPHYTRUCK2); }, "");

	}

	void sub::VEH_Planes() {
		AddVehicleTitle("Planes");
		AddOption("ALPHAZ1", [] {testspawn(VEHICLE_ALPHAZ1); }, "");
		AddOption("AVENGER", [] {testspawn(VEHICLE_AVENGER); }, "");
		AddOption("BESRA", [] {testspawn(VEHICLE_BESRA); }, "");
		AddOption("BLIMP", [] {testspawn(VEHICLE_BLIMP); }, "");
		AddOption("BLIMP2", [] {testspawn(VEHICLE_BLIMP2); }, "");
		AddOption("BLIMP3", [] {testspawn(VEHICLE_BLIMP3); }, "");
		AddOption("BOMBUSHKA", [] {testspawn(VEHICLE_BOMBUSHKA); }, "");
		AddOption("CARGOPLANE", [] {testspawn(VEHICLE_CARGOPLANE); }, "");
		AddOption("CUBAN800", [] {testspawn(VEHICLE_CUBAN800); }, "");
		AddOption("DODO", [] {testspawn(VEHICLE_DODO); }, "");
		AddOption("DUSTER", [] {testspawn(VEHICLE_DUSTER); }, "");
		AddOption("HOWARD", [] {testspawn(VEHICLE_HOWARD); }, "");
		AddOption("HYDRA", [] {testspawn(VEHICLE_HYDRA); }, "");
		AddOption("JET", [] {testspawn(VEHICLE_JET); }, "");
		AddOption("LAZER", [] {testspawn(VEHICLE_LAZER); }, "");
		AddOption("LUXOR", [] {testspawn(VEHICLE_LUXOR); }, "");
		AddOption("LUXOR2", [] {testspawn(VEHICLE_LUXOR2); }, "");
		AddOption("MAMMATUS", [] {testspawn(VEHICLE_MAMMATUS); }, "");
		AddOption("MICROLIGHT", [] {testspawn(VEHICLE_MICROLIGHT); }, "");
		AddOption("MILJET", [] {testspawn(VEHICLE_MILJET); }, "");
		AddOption("MOGUL", [] {testspawn(VEHICLE_MOGUL); }, "");
		AddOption("MOLOTOK", [] {testspawn(VEHICLE_MOLOTOK); }, "");
		AddOption("NIMBUS", [] {testspawn(VEHICLE_NIMBUS); }, "");
		AddOption("NOKOTA", [] {testspawn(VEHICLE_NOKOTA); }, "");
		AddOption("PYRO", [] {testspawn(VEHICLE_PYRO); }, "");
		AddOption("ROGUE", [] {testspawn(VEHICLE_ROGUE); }, "");
		AddOption("SEABREEZE", [] {testspawn(VEHICLE_SEABREEZE); }, "");
		AddOption("SHAMAL", [] {testspawn(VEHICLE_SHAMAL); }, "");
		AddOption("STARLING", [] {testspawn(VEHICLE_STARLING); }, "");
		AddOption("STRIKEFORCE", [] {testspawn(VEHICLE_STRIKEFORCE); }, "");
		AddOption("STUNT", [] {testspawn(VEHICLE_STUNT); }, "");
		AddOption("TITAN", [] {testspawn(VEHICLE_TITAN); }, "");
		AddOption("TULA", [] {testspawn(VEHICLE_TULA); }, "");
		AddOption("VELUM", [] {testspawn(VEHICLE_VELUM); }, "");
		AddOption("VELUM2", [] {testspawn(VEHICLE_VELUM2); }, "");
		AddOption("VESTRA", [] {testspawn(VEHICLE_VESTRA); }, "");
		AddOption("VOLATOL", [] {testspawn(VEHICLE_VOLATOL); }, "");


	}
	void sub::VEH_Suvs() {
			AddVehicleTitle("Suvs");
			AddOption("BALLER", [] {testspawn(VEHICLE_BALLER); }, "");
			AddOption("BALLER2", [] {testspawn(VEHICLE_BALLER2); }, "");
			AddOption("BALLER3", [] {testspawn(VEHICLE_BALLER3); }, "");
			AddOption("BALLER4", [] {testspawn(VEHICLE_BALLER4); }, "");
			AddOption("BALLER5", [] {testspawn(VEHICLE_BALLER5); }, "");
			AddOption("BALLER6", [] {testspawn(VEHICLE_BALLER6); }, "");
			AddOption("BJXL", [] {testspawn(VEHICLE_BJXL); }, "");
			AddOption("CAVALCADE", [] {testspawn(VEHICLE_CAVALCADE); }, "");
			AddOption("CAVALCADE2", [] {testspawn(VEHICLE_CAVALCADE2); }, "");
			AddOption("CONTENDER", [] {testspawn(VEHICLE_CONTENDER); }, "");
			AddOption("DUBSTA", [] {testspawn(VEHICLE_DUBSTA); }, "");
			AddOption("DUBSTA2", [] {testspawn(VEHICLE_DUBSTA2); }, "");
			AddOption("FQ2", [] {testspawn(VEHICLE_FQ2); }, "");
			AddOption("GRANGER", [] {testspawn(VEHICLE_GRANGER); }, "");
			AddOption("GRESLEY", [] {testspawn(VEHICLE_GRESLEY); }, "");
			AddOption("HABANERO", [] {testspawn(VEHICLE_HABANERO); }, "");
			AddOption("HUNTLEY", [] {testspawn(VEHICLE_HUNTLEY); }, "");
			AddOption("LANDSTALKER", [] {testspawn(VEHICLE_LANDSTALKER); }, "");
			AddOption("MESA", [] {testspawn(VEHICLE_MESA); }, "");
			AddOption("MESA2", [] {testspawn(VEHICLE_MESA2); }, "");
			AddOption("PATRIOT", [] {testspawn(VEHICLE_PATRIOT); }, "");
			AddOption("PATRIOT2", [] {testspawn(VEHICLE_PATRIOT2); }, "");
			AddOption("RADI", [] {testspawn(VEHICLE_RADI); }, "");
			AddOption("ROCOTO", [] {testspawn(VEHICLE_ROCOTO); }, "");
			AddOption("SEMINOLE", [] {testspawn(VEHICLE_SEMINOLE); }, "");
			AddOption("SERRANO", [] {testspawn(VEHICLE_SERRANO); }, "");
			AddOption("XLS", [] {testspawn(VEHICLE_XLS); }, "");
			AddOption("XLS2", [] {testspawn(VEHICLE_XLS2); }, "");
		

	}
	void sub::VEH_Sedans() {
		AddVehicleTitle("Sedans");
		AddOption("ASEA", [] {testspawn(VEHICLE_ASEA); }, "");
		AddOption("ASEA2", [] {testspawn(VEHICLE_ASEA2); }, "");
		AddOption("ASTEROPE", [] {testspawn(VEHICLE_ASTEROPE); }, "");
		AddOption("CHEBUREK", [] {testspawn(VEHICLE_CHEBUREK); }, "");
		AddOption("COG55", [] {testspawn(VEHICLE_COG55); }, "");
		AddOption("COG552", [] {testspawn(VEHICLE_COG552); }, "");
		AddOption("COGNOSCENTI", [] {testspawn(VEHICLE_COGNOSCENTI); }, "");
		AddOption("COGNOSCENTI2", [] {testspawn(VEHICLE_COGNOSCENTI2); }, "");
		AddOption("EMPEROR", [] {testspawn(VEHICLE_EMPEROR); }, "");
		AddOption("EMPEROR2", [] {testspawn(VEHICLE_EMPEROR2); }, "");
		AddOption("EMPEROR3", [] {testspawn(VEHICLE_EMPEROR3); }, "");
		AddOption("FUGITIVE", [] {testspawn(VEHICLE_FUGITIVE); }, "");
		AddOption("GLENDALE", [] {testspawn(VEHICLE_GLENDALE); }, "");
		AddOption("INGOT", [] {testspawn(VEHICLE_INGOT); }, "");
		AddOption("INTRUDER", [] {testspawn(VEHICLE_INTRUDER); }, "");
		AddOption("LIMO2", [] {testspawn(VEHICLE_LIMO2); }, "");
		AddOption("PREMIER", [] {testspawn(VEHICLE_PREMIER); }, "");
		AddOption("PRIMO", [] {testspawn(VEHICLE_PRIMO); }, "");
		AddOption("PRIMO2", [] {testspawn(VEHICLE_PRIMO2); }, "");
		AddOption("REGINA", [] {testspawn(VEHICLE_REGINA); }, "");
		AddOption("ROMERO", [] {testspawn(VEHICLE_ROMERO); }, "");
		AddOption("SCHAFTER2", [] {testspawn(VEHICLE_SCHAFTER2); }, "");
		AddOption("SCHAFTER5", [] {testspawn(VEHICLE_SCHAFTER5); }, "");
		AddOption("SCHAFTER6", [] {testspawn(VEHICLE_SCHAFTER6); }, "");
		AddOption("STAFFORD", [] {testspawn(VEHICLE_STAFFORD); }, "");
		AddOption("STANIER", [] {testspawn(VEHICLE_STANIER); }, "");
		AddOption("STRATUM", [] {testspawn(VEHICLE_STRATUM); }, "");
		AddOption("STRETCH", [] {testspawn(VEHICLE_STRETCH); }, "");
		AddOption("SUPERD", [] {testspawn(VEHICLE_SUPERD); }, "");
		AddOption("SURGE", [] {testspawn(VEHICLE_SURGE); }, "");
		AddOption("TAILGATER", [] {testspawn(VEHICLE_TAILGATER); }, "");
		AddOption("WARRENER", [] {testspawn(VEHICLE_WARRENER); }, "");
		AddOption("WASHINGTON", [] {testspawn(VEHICLE_WASHINGTON); }, "");

	}

	void sub::VEH_Service() {
		AddVehicleTitle("Service");
		AddOption("BRICKADE", [] {testspawn(VEHICLE_AIRBUS); }, "");
		AddOption("BRICKADE", [] {testspawn(VEHICLE_BRICKADE); }, "");
		AddOption("BUS", [] {testspawn(VEHICLE_BUS); }, "");
		AddOption("COACH", [] {testspawn(VEHICLE_COACH); }, "");
		AddOption("PBUS2", [] {testspawn(VEHICLE_PBUS2); }, "");
		AddOption("RALLYTRUCK", [] {testspawn(VEHICLE_RALLYTRUCK); }, "");
		AddOption("RENTALBUS", [] {testspawn(VEHICLE_RENTALBUS); }, "");
		AddOption("TAXI", [] {testspawn(VEHICLE_TAXI); }, "");
		AddOption("TOURBUS", [] {testspawn(VEHICLE_TOURBUS); }, "");
		AddOption("TRASH", [] {testspawn(VEHICLE_TRASH); }, "");
		AddOption("TRASH2", [] {testspawn(VEHICLE_TRASH2); }, "");
		AddOption("WASTELANDER", [] {testspawn(VEHICLE_WASTELANDER); }, "");

	}

	void sub::VEH_SPORTS() {
		AddVehicleTitle("Sports");
		AddOption("ALPHA", [] {testspawn(VEHICLE_ALPHA); }, "");
		AddOption("BANSHEE", [] {testspawn(VEHICLE_BANSHEE); }, "");
		AddOption("BESTIAGTS", [] {testspawn(VEHICLE_BESTIAGTS); }, "");
		AddOption("BLISTA2", [] {testspawn(VEHICLE_BLISTA2); }, "");
		AddOption("BLISTA3", [] {testspawn(VEHICLE_BLISTA3); }, "");
		AddOption("BUFFALO", [] {testspawn(VEHICLE_BUFFALO); }, "");
		AddOption("BUFFALO2", [] {testspawn(VEHICLE_BUFFALO2); }, "");
		AddOption("BUFFALO3", [] {testspawn(VEHICLE_BUFFALO3); }, "");
		AddOption("CARBONIZZARE", [] {testspawn(VEHICLE_CARBONIZZARE); }, "");
		AddOption("COMET2", [] {testspawn(VEHICLE_COMET2); }, "");
		AddOption("COMET3", [] {testspawn(VEHICLE_COMET3); }, "");
		AddOption("COMET4", [] {testspawn(VEHICLE_COMET4); }, "");
		AddOption("COMET5", [] {testspawn(VEHICLE_COMET5); }, "");
		AddOption("COQUETTE", [] {testspawn(VEHICLE_COQUETTE); }, "");
		AddOption("ELEGY", [] {testspawn(VEHICLE_ELEGY); }, "");
		AddOption("ELEGY2", [] {testspawn(VEHICLE_ELEGY2); }, "");
		AddOption("FELTZER2", [] {testspawn(VEHICLE_FELTZER2); }, "");
		AddOption("FLASHGT", [] {testspawn(VEHICLE_FLASHGT); }, "");
		AddOption("FUROREGT", [] {testspawn(VEHICLE_FUROREGT); }, "");
		AddOption("FUSILADE", [] {testspawn(VEHICLE_FUSILADE); }, "");
		AddOption("FUTO", [] {testspawn(VEHICLE_FUTO); }, "");
		AddOption("GB200", [] {testspawn(VEHICLE_GB200); }, "");
		AddOption("HOTRING", [] {testspawn(VEHICLE_HOTRING); }, "");
		AddOption("JESTER", [] {testspawn(VEHICLE_JESTER); }, "");
		AddOption("JESTER2", [] {testspawn(VEHICLE_JESTER2); }, "");
		AddOption("JESTER3", [] {testspawn(VEHICLE_JESTER3); }, "");
		AddOption("KHAMELION", [] {testspawn(VEHICLE_KHAMELION); }, "");
		AddOption("KURUMA", [] {testspawn(VEHICLE_KURUMA); }, "");
		AddOption("KURUMA2", [] {testspawn(VEHICLE_KURUMA2); }, "");
		AddOption("LYNX2", [] {testspawn(VEHICLE_LYNX2); }, "");
		AddOption("MASSACRO", [] {testspawn(VEHICLE_MASSACRO); }, "");
		AddOption("MASSACRO2", [] {testspawn(VEHICLE_MASSACRO2); }, "");
		AddOption("NEON", [] {testspawn(VEHICLE_NEON); }, "");
		AddOption("NINEF", [] {testspawn(VEHICLE_NINEF); }, "");
		AddOption("NINEF2", [] {testspawn(VEHICLE_NINEF2); }, "");
		AddOption("OMNIS", [] {testspawn(VEHICLE_OMNIS); }, "");
		AddOption("PARIAH", [] {testspawn(VEHICLE_PARIAH); }, "");
		AddOption("PENUMBRA", [] {testspawn(VEHICLE_PENUMBRA); }, "");
		AddOption("RAIDEN", [] {testspawn(VEHICLE_RAIDEN); }, "");
		AddOption("RAPIDGT", [] {testspawn(VEHICLE_RAPIDGT); }, "");
		AddOption("RAPIDGT2", [] {testspawn(VEHICLE_RAPIDGT2); }, "");
		AddOption("RAPTOR", [] {testspawn(VEHICLE_RAPTOR); }, "");
		AddOption("REVOLTER", [] {testspawn(VEHICLE_REVOLTER); }, "");
		AddOption("RUSTON", [] {testspawn(VEHICLE_RUSTON); }, "");
		AddOption("SCHAFTER3", [] {testspawn(VEHICLE_SCHAFTER3); }, "");
		AddOption("SCHAFTER4", [] {testspawn(VEHICLE_SCHAFTER4); }, "");
		AddOption("SCHWARZER", [] {testspawn(VEHICLE_SCHWARZER); }, "");
		AddOption("SENTINEL3", [] {testspawn(VEHICLE_SENTINEL3); }, "");
		AddOption("SEVEN70", [] {testspawn(VEHICLE_SEVEN70); }, "");
		AddOption("SPECTER", [] {testspawn(VEHICLE_SPECTER); }, "");
		AddOption("SPECTER2", [] {testspawn(VEHICLE_SPECTER2); }, "");
		AddOption("STREITER", [] {testspawn(VEHICLE_STREITER); }, "");
		AddOption("SULTAN", [] {testspawn(VEHICLE_SULTAN); }, "");
		AddOption("SURANO", [] {testspawn(VEHICLE_SURANO); }, "");
		AddOption("TAMPA2", [] {testspawn(VEHICLE_TAMPA2); }, "");
		AddOption("TROPOS", [] {testspawn(VEHICLE_TROPOS); }, "");
		AddOption("VERLIERER2", [] {testspawn(VEHICLE_VERLIERER2); }, "");
		

	}
	void sub::VEH_SportsClassic() {
		AddVehicleTitle("Sports Classics");
		AddOption("ARDENT", [] {testspawn(VEHICLE_ARDENT); }, "");
		AddOption("BTYPE", [] {testspawn(VEHICLE_BTYPE); }, "");
		AddOption("BTYPE2", [] {testspawn(VEHICLE_BTYPE2); }, "");
		AddOption("BTYPE3", [] {testspawn(VEHICLE_BTYPE3); }, "");
		AddOption("CASCO", [] {testspawn(VEHICLE_CASCO); }, "");
		AddOption("CHEETAH2", [] {testspawn(VEHICLE_CHEETAH2); }, "");
		AddOption("COQUETTE2", [] {testspawn(VEHICLE_COQUETTE2); }, "");
		AddOption("DELUXO", [] {testspawn(VEHICLE_DELUXO); }, "");
		AddOption("FAGALOA", [] {testspawn(VEHICLE_FAGALOA); }, "");
		AddOption("FELTZER3", [] {testspawn(VEHICLE_FELTZER3); }, "");
		AddOption("GT500", [] {testspawn(VEHICLE_GT500); }, "");
		AddOption("HUSTLER", [] {testspawn(VEHICLE_HUSTLER); }, "");
		AddOption("INFERNUS2", [] {testspawn(VEHICLE_INFERNUS2); }, "");
		AddOption("JB700", [] {testspawn(VEHICLE_JB700); }, "");
		AddOption("MAMBA", [] {testspawn(VEHICLE_MAMBA); }, "");
		AddOption("MANANA", [] {testspawn(VEHICLE_MANANA); }, "");
		AddOption("MICHELLI", [] {testspawn(VEHICLE_MICHELLI); }, "");
		AddOption("MONROE", [] {testspawn(VEHICLE_MONROE); }, "");
		AddOption("PEYOTE", [] {testspawn(VEHICLE_PEYOTE); }, "");
		AddOption("PIGALLE", [] {testspawn(VEHICLE_PIGALLE); }, "");
		AddOption("RAPIDGT3", [] {testspawn(VEHICLE_RAPIDGT3); }, "");
		AddOption("RETINUE", [] {testspawn(VEHICLE_RETINUE); }, "");
		AddOption("SAVESTRA", [] {testspawn(VEHICLE_SAVESTRA); }, "");
		AddOption("STINGER", [] {testspawn(VEHICLE_STINGER); }, "");
		AddOption("STINGERGT", [] {testspawn(VEHICLE_STINGERGT); }, "");
		AddOption("STROMBERG", [] {testspawn(VEHICLE_STROMBERG); }, "");
		AddOption("SWINGER", [] {testspawn(VEHICLE_SWINGER); }, "");
		AddOption("TORERO", [] {testspawn(VEHICLE_TORERO); }, "");
		AddOption("TORNADO", [] {testspawn(VEHICLE_TORNADO); }, "");
		AddOption("TORNADO2", [] {testspawn(VEHICLE_TORNADO2); }, "");
		AddOption("TORNADO3", [] {testspawn(VEHICLE_TORNADO3); }, "");
		AddOption("TORNADO4", [] {testspawn(VEHICLE_TORNADO4); }, "");
		AddOption("TORNADO5", [] {testspawn(VEHICLE_TORNADO5); }, "");
		AddOption("TORNADO6", [] {testspawn(VEHICLE_TORNADO6); }, "");
		AddOption("TURISMO2", [] {testspawn(VEHICLE_TURISMO2); }, "");
		AddOption("VISERIS", [] {testspawn(VEHICLE_VISERIS); }, "");
		AddOption("Z190", [] {testspawn(VEHICLE_Z190); }, "");
		AddOption("ZTYPE", [] {testspawn(VEHICLE_ZTYPE); }, "");


	}

	void sub::VEH_Super() {
		AddVehicleTitle("Super");
		AddOption("ADDER", [] {testspawn(VEHICLE_ADDER); }, "");
		AddOption("AUTARCH", [] {testspawn(VEHICLE_AUTARCH); }, "");
		AddOption("BANSHEE2", [] {testspawn(VEHICLE_BANSHEE2); }, "");
		AddOption("BULLET", [] {testspawn(VEHICLE_BULLETGT); }, "");
		AddOption("CHEETAH", [] {testspawn(VEHICLE_CHEETAH); }, "");
		AddOption("CYCLONE", [] {testspawn(VEHICLE_CYCLONE); }, "");
		AddOption("ENTITYXF", [] {testspawn(VEHICLE_ENTITYXF); }, "");
		AddOption("ENTITY2", [] {testspawn(VEHICLE_ENTITY2); }, "");
		AddOption("FMJ", [] {testspawn(VEHICLE_FMJ); }, "");
		AddOption("GP1", [] {testspawn(VEHICLE_GP1); }, "");
		AddOption("INFERNUS", [] {testspawn(VEHICLE_INFERNUS); }, "");
		AddOption("ITALIGTB", [] {testspawn(VEHICLE_ITALIGTB); }, "");
		AddOption("ITALIGTB2", [] {testspawn(VEHICLE_ITALIGTB2); }, "");
		AddOption("LE7B", [] {testspawn(VEHICLE_LE7B); }, "");
		AddOption("NERO", [] {testspawn(VEHICLE_NERO); }, "");
		AddOption("NERO2", [] {testspawn(VEHICLE_NERO2); }, "");
		AddOption("OSIRIS", [] {testspawn(VEHICLE_OSIRIS); }, "");
		AddOption("PENETRATOR", [] {testspawn(VEHICLE_PENETRATOR); }, "");
		AddOption("PFISTER811", [] {testspawn(VEHICLE_PFISTER811); }, "");
		AddOption("PROTOTIPO", [] {testspawn(VEHICLE_PROTOTIPO); }, "");
		AddOption("REAPER", [] {testspawn(VEHICLE_REAPER); }, "");
		AddOption("SC1", [] {testspawn(VEHICLE_SC1); }, "");
		AddOption("SCRAMJET", [] {testspawn(VEHICLE_SCRAMJET); }, "");
		AddOption("SHEAVA", [] {testspawn(VEHICLE_SHEAVA); }, "");
		AddOption("SULTANRS", [] {testspawn(VEHICLE_SULTANRS); }, "");
		AddOption("T20", [] {testspawn(VEHICLE_T20); }, "");
		AddOption("TAIPAN", [] {testspawn(VEHICLE_TAIPAN); }, "");
		AddOption("TEMPESTA", [] {testspawn(VEHICLE_TEMPESTA); }, "");
		AddOption("TEZERACT", [] {testspawn(VEHICLE_TEZERACT); }, "");
		AddOption("TURISMOR", [] {testspawn(VEHICLE_TURISMOR); }, "");
		AddOption("TYRANT", [] {testspawn(VEHICLE_TYRANT); }, "");
		AddOption("TYRUS", [] {testspawn(VEHICLE_TYRUS); }, "");
		AddOption("VACCA", [] {testspawn(VEHICLE_VACCA); }, "");
		AddOption("VAGNER", [] {testspawn(VEHICLE_VAGNER); }, "");
		AddOption("VIGILANTE", [] {testspawn(VEHICLE_VIGILANTE); }, "");
		AddOption("VISIONE", [] {testspawn(VEHICLE_VISIONE); }, "");
		AddOption("VOLTIC", [] {testspawn(VEHICLE_VOLTIC); }, "");
		AddOption("VOLTIC2", [] {testspawn(VEHICLE_VOLTIC2); }, "");
		AddOption("XA21", [] {testspawn(VEHICLE_XA21); }, "");
		AddOption("ZENTORNO", [] {testspawn(VEHICLE_ZENTORNO); }, "");
	

	}


	void sub::VEH_trailers() {
		AddVehicleTitle("Trailers");
		AddOption("ARMYTANKER", [] {testspawn(VEHICLE_ARMYTANKER); }, "");
		AddOption("ARMYTRAILER2", [] {testspawn(VEHICLE_ARMYTRAILER2); }, "");
		AddOption("BALETRAILER", [] {testspawn(VEHICLE_BALETRAILER); }, "");
		AddOption("BOATTRAILER", [] {testspawn(VEHICLE_BOATTRAILER); }, "");
		AddOption("CABLECAR", [] {testspawn(VEHICLE_CABLECAR); }, "");
		AddOption("DOCKTRAILER", [] {testspawn(VEHICLE_DOCKTRAILER); }, "");
		AddOption("GRAINTRAILER", [] {testspawn(VEHICLE_GRAINTRAILER); }, "");
		AddOption("PROPTRAILER", [] {testspawn(VEHICLE_PROPTRAILER); }, "");
		AddOption("RAKETRAILER", [] {testspawn(VEHICLE_RAKETRAILER); }, "");
		AddOption("TR2", [] {testspawn(VEHICLE_TR2); }, "");
		AddOption("TR3", [] {testspawn(VEHICLE_TR3); }, "");
		AddOption("TR4", [] {testspawn(VEHICLE_TR4); }, "");
		AddOption("TRFLAT", [] {testspawn(VEHICLE_TRFLAT); }, "");
		AddOption("TVTRAILER", [] {testspawn(VEHICLE_TVTRAILER); }, "");
		AddOption("TANKER", [] {testspawn(VEHICLE_TANKER); }, "");
		AddOption("TANKER2", [] {testspawn(VEHICLE_TANKER2); }, "");
		AddOption("TRAILERLOGS", [] {testspawn(VEHICLE_TRAILERLOGS); }, "");
		AddOption("TRAILERSMALL", [] {testspawn(VEHICLE_TRAILERSMALL); }, "");
		AddOption("TRAILERS", [] {testspawn(VEHICLE_TRAILERS); }, "");
		AddOption("TRAILERS2", [] {testspawn(VEHICLE_TRAILERS2); }, "");
		AddOption("TRAILERS3", [] {testspawn(VEHICLE_TRAILERS3); }, "");

	}

	void sub::VEH_TRAINS() {

		AddVehicleTitle("Trains");
		AddOption("FREIGHT", [] {testspawn(VEHICLE_FREIGHT); }, "");
		AddOption("FREIGHTCAR", [] {testspawn(VEHICLE_FREIGHTCAR); }, "");
		AddOption("FREIGHTCONT1", [] {testspawn(VEHICLE_FREIGHTCONT1); }, "");
		AddOption("FREIGHTCONT2", [] {testspawn(VEHICLE_FREIGHTCONT2); }, "");
		AddOption("FREIGHTGRAIN", [] {testspawn(VEHICLE_FREIGHTGRAIN); }, "");
		AddOption("TANKERCAR", [] {testspawn(VEHICLE_TANKERCAR); }, "");




	}
	void sub::VEH_Utility() {
		AddVehicleTitle("Utility");
		AddOption("AIRTUG", [] {testspawn(VEHICLE_AIRTUG); }, "");
		AddOption("CADDY", [] {testspawn(VEHICLE_CADDY); }, "");
		AddOption("CADDY2", [] {testspawn(VEHICLE_CADDY2); }, "");
		AddOption("CADDY3", [] {testspawn(VEHICLE_CADDY3); }, "");
		AddOption("CARACARA", [] {testspawn(VEHICLE_CARACARA); }, "");
		AddOption("DOCKTUG", [] {testspawn(VEHICLE_DOCKTUG); }, "");
		AddOption("FORKLIFT", [] {testspawn(VEHICLE_FORKLIFT); }, "");
		AddOption("MOWER", [] {testspawn(VEHICLE_MOWER); }, "");
		AddOption("RIPLEY", [] {testspawn(VEHICLE_RIPLEY); }, "");
		AddOption("SADLER", [] {testspawn(VEHICLE_SADLER); }, "");
		AddOption("SADLER2", [] {testspawn(VEHICLE_SADLER2); }, "");
		AddOption("SCRAP", [] {testspawn(VEHICLE_SCRAP); }, "");
		AddOption("TOWTRUCK", [] {testspawn(VEHICLE_TOWTRUCK); }, "");
		AddOption("TOWTRUCK2", [] {testspawn(VEHICLE_TOWTRUCK2); }, "");
		AddOption("TRACTOR", [] {testspawn(VEHICLE_TRACTOR); }, "");
		AddOption("TRACTOR2", [] {testspawn(VEHICLE_TRACTOR2); }, "");
		AddOption("TRACTOR3", [] {testspawn(VEHICLE_TRACTOR3); }, "");
		AddOption("UTILLITRUCK", [] {testspawn(VEHICLE_UTILLITRUCK); }, "");
		AddOption("UTILLITRUCK2", [] {testspawn(VEHICLE_UTILLITRUCK2); }, "");
		AddOption("UTILLITRUCK3", [] {testspawn(VEHICLE_UTILLITRUCK3); }, "");

	}
	void sub::VEH_Vans() {
		AddVehicleTitle("Vans");
		AddOption("BISON", [] {testspawn(VEHICLE_BISON); }, "");
		AddOption("BISON2", [] {testspawn(VEHICLE_BISON2); }, "");
		AddOption("BISON3", [] {testspawn(VEHICLE_BISON3); }, "");
		AddOption("BOBCATXL", [] {testspawn(VEHICLE_BOBCATXL); }, "");
		AddOption("BOXVILLE", [] {testspawn(VEHICLE_BOXVILLE); }, "");
		AddOption("BOXVILLE2", [] {testspawn(VEHICLE_BOXVILLE2); }, "");
		AddOption("BOXVILLE3", [] {testspawn(VEHICLE_BOXVILLE3); }, "");
		AddOption("BOXVILLE4", [] {testspawn(VEHICLE_BOXVILLE4); }, "");
		AddOption("BOXVILLE5", [] {testspawn(VEHICLE_BOXVILLE5); }, "");
		AddOption("BURRITO", [] {testspawn(VEHICLE_BURRITO); }, "");
		AddOption("BURRITO2", [] {testspawn(VEHICLE_BURRITO2); }, "");
		AddOption("BURRITO3", [] {testspawn(VEHICLE_BURRITO3); }, "");
		AddOption("BURRITO4", [] {testspawn(VEHICLE_BURRITO4); }, "");
		AddOption("BURRITO5", [] {testspawn(VEHICLE_BURRITO5); }, "");
		AddOption("CAMPER", [] {testspawn(VEHICLE_CAMPER); }, "");
		AddOption("GBURRITO", [] {testspawn(VEHICLE_GBURRITO); }, "");
		AddOption("GBURRITO2", [] {testspawn(VEHICLE_GBURRITO2); }, "");
		AddOption("JOURNEY", [] {testspawn(VEHICLE_JOURNEY); }, "");
		AddOption("MINIVAN", [] {testspawn(VEHICLE_MINIVAN); }, "");
		AddOption("MINIVAN2", [] {testspawn(VEHICLE_MINIVAN2); }, "");
		AddOption("PARADISE", [] {testspawn(VEHICLE_PARADISE); }, "");
		AddOption("PONY", [] {testspawn(VEHICLE_PONY); }, "");
		AddOption("PONY2", [] {testspawn(VEHICLE_PONY2); }, "");
		AddOption("RUMPO", [] {testspawn(VEHICLE_RUMPO); }, "");
		AddOption("RUMPO2", [] {testspawn(VEHICLE_RUMPO2); }, "");
		AddOption("RUMPO3", [] {testspawn(VEHICLE_RUMPO3); }, "");
		AddOption("SPEEDO", [] {testspawn(VEHICLE_SPEEDO); }, "");
		AddOption("SPEEDO2", [] {testspawn(VEHICLE_SPEEDO2); }, "");
		AddOption("SPEEDO4", [] {testspawn(VEHICLE_SPEEDO4); }, "");
		AddOption("SURFER", [] {testspawn(VEHICLE_SURFER); }, "");
		AddOption("SURFER2", [] {testspawn(VEHICLE_SURFER2); }, "");
		AddOption("TACO", [] {testspawn(VEHICLE_TACO); }, "");
		AddOption("YOUGA", [] {testspawn(VEHICLE_YOUGA); }, "");
		AddOption("YOUGA2", [] {testspawn(VEHICLE_YOUGA2); }, "");

	}
	void sub::VEH_ArenaWar() {
		AddVehicleTitle("Area War");
		AddOption("BRUISER", [] {testspawn(VEHICLE_BRUISER); }, "");
		AddOption("BRUISER2", [] {testspawn(VEHICLE_BRUISER2); }, "");
		AddOption("BRUISER3", [] {testspawn(VEHICLE_BRUISER3); }, "");
		AddOption("BRUTUS", [] {testspawn(VEHICLE_BRUTUS); }, "");
		AddOption("BRUTUS2", [] {testspawn(VEHICLE_BRUTUS2); }, "");
		AddOption("BRUTUS3", [] {testspawn(VEHICLE_BRUTUS3); }, "");
		AddOption("CERBERUS", [] {testspawn(VEHICLE_CERBERUS); }, "");
		AddOption("CERBERUS2", [] {testspawn(VEHICLE_CERBERUS2); }, "");
		AddOption("CERBERUS3", [] {testspawn(VEHICLE_CERBERUS3); }, "");
		AddOption("CLIQUE", [] {testspawn(VEHICLE_CLIQUE); }, "");
		AddOption("DEATHBIKE", [] {testspawn(VEHICLE_DEATHBIKE); }, "");
		AddOption("DEATHBIKE2", [] {testspawn(VEHICLE_DEATHBIKE2); }, "");
		AddOption("DEATHBIKE3", [] {testspawn(VEHICLE_DEATHBIKE3); }, "");
		AddOption("DEVESTE", [] {testspawn(VEHICLE_DEVESTE); }, "");
		AddOption("DEVIANT", [] {testspawn(VEHICLE_DEVIANT); }, "");
		AddOption("DOMINATOR4", [] {testspawn(VEHICLE_DOMINATOR4); }, "");
		AddOption("DOMINATOR5", [] {testspawn(VEHICLE_DOMINATOR5); }, "");
		AddOption("DOMINATOR6", [] {testspawn(VEHICLE_DOMINATOR6); }, "");
		AddOption("IMPALER", [] {testspawn(VEHICLE_IMPALER); }, "");
		AddOption("IMPALER2", [] {testspawn(VEHICLE_IMPALER2); }, "");
		AddOption("IMPALER3", [] {testspawn(VEHICLE_IMPALER3); }, "");
		AddOption("IMPALER4", [] {testspawn(VEHICLE_IMPALER4); }, "");
		AddOption("IMPERATOR", [] {testspawn(VEHICLE_IMPERATOR); }, "");
		AddOption("IMPERATOR2", [] {testspawn(VEHICLE_IMPERATOR2); }, "");
		AddOption("IMPERATOR3", [] {testspawn(VEHICLE_IMPERATOR3); }, "");
		AddOption("ISSI4", [] {testspawn(VEHICLE_ISSI4); }, "");
		AddOption("ISSI5", [] {testspawn(VEHICLE_ISSI5); }, "");
		AddOption("ISSI6", [] {testspawn(VEHICLE_ISSI6); }, "");
		AddOption("ITALIGTO", [] {testspawn(VEHICLE_ITALIGTO); }, "");
		AddOption("MONSTER3", [] {testspawn(VEHICLE_MONSTER3); }, "");
		AddOption("MONSTER4", [] {testspawn(VEHICLE_MONSTER4); }, "");
		AddOption("MONSTER5", [] {testspawn(VEHICLE_MONSTER5); }, "");
		AddOption("RCBANDITO", [] {testspawn(VEHICLE_RCBANDITO); }, "");
		AddOption("SCARAB2", [] {testspawn(VEHICLE_SCARAB2); }, "");
		AddOption("SCARAB3", [] {testspawn(VEHICLE_SCARAB3); }, "");
		AddOption("SCHLAGEN", [] {testspawn(VEHICLE_SCHLAGEN); }, "");
		AddOption("SLAMVAN4", [] {testspawn(VEHICLE_SLAMVAN4); }, "");
		AddOption("SLAMVAN5", [] {testspawn(VEHICLE_SLAMVAN5); }, "");
		AddOption("SLAMVAN6", [] {testspawn(VEHICLE_SLAMVAN6); }, "");
		AddOption("TOROS", [] {testspawn(VEHICLE_TOROS); }, "");
		AddOption("TULIP", [] {testspawn(VEHICLE_TULIP); }, "");
		AddOption("VAMOS", [] {testspawn(VEHICLE_VAMOS); }, "");
		AddOption("ZR380", [] {testspawn(VEHICLE_ZR380); }, "");
		AddOption("ZR3802", [] {testspawn(VEHICLE_ZR3802); }, "");
		AddOption("ZR3803", [] {testspawn(VEHICLE_ZR3803); }, "");
	


	}

	void sub::VEH_CasinoUpdate() {
		AddVehicleTitle("Casino Update");
		AddOption("CARACARA2", [] {testspawn(VEHICLE_CARACARA2); }, "");
		AddOption("DRAFTER", [] {testspawn(VEHICLE_DRAFTER); }, "");
		AddOption("DYNASTY", [] {testspawn(VEHICLE_DYNASTY); }, "");
		AddOption("EMERUS", [] {testspawn(VEHICLE_EMERUS); }, "");
		AddOption("GAUNTLET3", [] {testspawn(VEHICLE_GAUNTLET3); }, "");
		AddOption("GAUNTLET4", [] {testspawn(VEHICLE_GAUNTLET4); }, "");
		AddOption("HELLION", [] {testspawn(VEHICLE_HELLION); }, "");
		AddOption("ISSI7", [] {testspawn(VEHICLE_ISSI7); }, "");
		AddOption("JUGULAR", [] {testspawn(VEHICLE_JUGULAR); }, "");
		AddOption("KRIEGER", [] {testspawn(VEHICLE_KRIEGER); }, "");
		AddOption("LOCUST", [] {testspawn(VEHICLE_LOCUST); }, "");
		AddOption("NEBULA", [] {testspawn(VEHICLE_NEBULA); }, "");
		AddOption("NEO", [] {testspawn(VEHICLE_NEO); }, "");
		AddOption("NOVAK", [] {testspawn(VEHICLE_NOVAK); }, "");
		AddOption("PARAGON", [] {testspawn(VEHICLE_PARAGON); }, "");
		AddOption("PARAGON2", [] {testspawn(VEHICLE_PARAGON2); }, "");
		AddOption("PEYOTE2", [] {testspawn(VEHICLE_PEYOTE2); }, "");
		AddOption("RROCKET", [] {testspawn(VEHICLE_RROCKET); }, "");
		AddOption("S80", [] {testspawn(VEHICLE_S80); }, "");
		AddOption("THRAX", [] {testspawn(VEHICLE_THRAX); }, "");
		AddOption("ZION3", [] {testspawn(VEHICLE_ZION3); }, "");
		AddOption("ZORRUSSO", [] {testspawn(VEHICLE_ZORRUSSO); }, "");

	}

	void sub::VEH_CasinoHeist() {
		AddVehicleTitle("Casino Heist");
		AddOption("ABSO", [] {testspawn(VEHICLE_ASBO); }, "");
		AddOption("EVERON", [] {testspawn(VEHICLE_EVERON); }, "");
		AddOption("FORMULA", [] {testspawn(VEHICLE_FORMULA); }, "");
		AddOption("FORMULA2", [] {testspawn(VEHICLE_FORMULA2); }, "");
		AddOption("FURIA", [] {testspawn(VEHICLE_FURIA); }, "");
		AddOption("IMORGON", [] {testspawn(VEHICLE_IMORGON); }, "");
		AddOption("JB7002", [] {testspawn(VEHICLE_JB7002); }, "");
		AddOption("KANJO", [] {testspawn(VEHICLE_KANJO); }, "");
		AddOption("KOMODA", [] {testspawn(VEHICLE_KOMODA); }, "");
		AddOption("MINITANK", [] {testspawn(VEHICLE_MINITANK); }, "");
		AddOption("OUTLAW", [] {testspawn(VEHICLE_OUTLAW); }, "");
		AddOption("REBLA", [] {testspawn(VEHICLE_REBLA); }, "");
		AddOption("RETINUE2", [] {testspawn(VEHICLE_RETINUE2); }, "");
		AddOption("STRYDER", [] {testspawn(VEHICLE_STRYDER); }, "");
		AddOption("SUGOI", [] {testspawn(VEHICLE_SUGOI); }, "");
		AddOption("SULTAN2", [] {testspawn(VEHICLE_SULTAN2); }, "");
		AddOption("VAGRANT", [] {testspawn(VEHICLE_VAGRANT); }, "");
		AddOption("VSTR", [] {testspawn(VEHICLE_VSTR); }, "");
		AddOption("YOSEMITE2", [] {testspawn(VEHICLE_YOSEMITE2); }, "");
		AddOption("ZHABA", [] {testspawn(VEHICLE_ZHABA); }, "");

	}
	void sub::VEH_SummerUpdate() {
		AddVehicleTitle("Summer Update");
		AddOption("CLUB", [] {testspawn(VEHICLE_CLUB); }, "");
		AddOption("COQUETTE4", [] {testspawn(VEHICLE_COQUETTE4); }, "");
		AddOption("DUKES3", [] {testspawn(VEHICLE_DUKES3); }, "");
		AddOption("GAUNTLET5", [] {testspawn(VEHICLE_GAUNTLET5); }, "");
		AddOption("GLENDALE2", [] {testspawn(VEHICLE_GLENDALE2); }, "");
		AddOption("LANDSTALKER2", [] {testspawn(VEHICLE_LANDSTALKER2); }, "");
		AddOption("MANANA2", [] {testspawn(VEHICLE_MANANA2); }, "");
		AddOption("OPENWHEEL1", [] {testspawn(VEHICLE_OPENWHEEL1); }, "");
		AddOption("OPENWHEEL2", [] {testspawn(VEHICLE_OPENWHEEL2); }, "");
		AddOption("PENUMBRA2", [] {testspawn(VEHICLE_PENUMBRA2); }, "");
		AddOption("PEYOTE3", [] {testspawn(VEHICLE_PEYOTE3); }, "");
		AddOption("SEMINOLE2", [] {testspawn(VEHICLE_SEMINOLE2); }, "");
		AddOption("TIGON", [] {testspawn(VEHICLE_TIGON); }, "");
		AddOption("YOSEMITE3", [] {testspawn(VEHICLE_YOSEMITE3); }, "");
		AddOption("YOUGA3", [] {testspawn(VEHICLE_YOUGA3); }, "");
	
	}
	void sub::VEH_CAYOPERICHO() {
		AddVehicleTitle("Cayo Perico Heist");
		AddOption("ALKONOST", [] {testspawn(VEHICLE_ALKONOST); }, "");
		AddOption("ANNIHILATOR2", [] {testspawn(VEHICLE_ANNIHILATOR2); }, "");
		AddOption("AVISA", [] {testspawn(VEHICLE_AVISA); }, "");
		AddOption("BRIOSO2", [] {testspawn(VEHICLE_BRIOSO2); }, "");
		AddOption("VEHICLE_DINGHY5", [] {testspawn(VEHICLE_DINGHY5); }, "");
		AddOption("ITALIRSX", [] {testspawn(VEHICLE_ITALIRSX); }, "");
		AddOption("KOSATKA", [] {testspawn(VEHICLE_KOSATKA); }, "");
		AddOption("LONGFIN", [] {testspawn(VEHICLE_LONGFIN); }, "");
		AddOption("MANCHEZE", [] {testspawn(VEHICLE_MANCHEZE); }, "");
		AddOption("PATROLBOAT", [] {testspawn(VEHICLE_PATROLBOAT); }, "");
		AddOption("SEASPARROW2", [] {testspawn(VEHICLE_SEASPARROW2); }, "");
		AddOption("SLAMTRUCK", [] {testspawn(VEHICLE_SLAMTRUCK); }, "");
		AddOption("SQUADDIE", [] {testspawn(VEHICLE_SQUADDIE); }, "");
		AddOption("TOREADOR", [] {testspawn(VEHICLE_TOREADOR); }, "");
		AddOption("VERUS", [] {testspawn(VEHICLE_VERUS); }, "");
		AddOption("VETIR", [] {testspawn(VEHICLE_VETIR); }, "");
		AddOption("VETO", [] {testspawn(VEHICLE_VETO); }, "");
		AddOption("VETO2", [] {testspawn(VEHICLE_VETO2); }, "");
		AddOption("WEEVIL", [] {testspawn(VEHICLE_WEEVIL); }, "");
		AddOption("WINKY", [] {testspawn(VEHICLE_WINKY); }, "");
	

	}
	/*const char* CharKeyboard(const char* windowName, int maxInput, const char* defaultText)
	{
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) 			script::get_current()->yield(0);
		if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
		return (char*)GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	}*/
	void sub::vehspawner() {
		AddVehicleTitle("Vehicle Spawner");
		
		AddToggle("Spawn Inside", &g->spawn.spawn_inside,"");
		AddToggle("Spawn Maxed", &g->spawn.spawn_maxed, "");
		AddOption("Spawn Via Model Name", [] {
			
			//static auto test = MISC::GET_ONSCREEN_KEYBOARD_RESULT();
			//	Hash hts = MISC::GET_HASH_KEY(test);
			//static auto test = CharKeyboard("", 99, "");
		
				Hash hts = MISC::GET_HASH_KEY(CharKeyboard("", 99, ""));

				//	static auto veh_hash = RAGE_JOAAT(hts);
				testspawn(hts);
						
			}, "");
		AddSubmenu("Criminal Enterprises", SUB::VEH_CRIMINALENTPRISE, "");
		AddSubmenu("Cayo Perico Heist", SUB::VEH_CAYOPERICHO,"");
		AddSubmenu("Summer Update", SUB::VEH_SummerUpdate,"");
		AddSubmenu("Casino Heist", SUB::VEH_CasinoHeist, "");
		AddSubmenu("Casino Update", SUB::VEH_CasinoUpdate, "");
		AddSubmenu("Arena War", SUB::VEH_ArenaWar, "");
		AddSubmenu("Vans", SUB::VEH_Vans, "");
		AddSubmenu("Utility", SUB::VEH_Utility, "");
		AddSubmenu("Trains", SUB::VEH_TRAINS, "");
		AddSubmenu("Trailers", SUB::VEH_trailers, "");
		AddSubmenu("Super", SUB::VEH_Super, "");
		AddSubmenu("Sports Classics", SUB::VEH_SportsClassic, "");
		AddSubmenu("Sports", SUB::VEH_SPORTS, "");
		AddSubmenu("Boats", SUB::VEH_Boats, "");
		AddSubmenu("Commercial", SUB::VEH_Commercials, "");
		AddSubmenu("Compacts", SUB::VEH_compacts, "");
		AddSubmenu("Coupes", SUB::VEH_Coupes, "");
		AddSubmenu("Bikes", SUB::VEH_BIKES, "");
		AddSubmenu("Emergency", SUB::VEH_Emergency, "");
		AddSubmenu("Helicopters", SUB::VEH_Helicopters, "");
		AddSubmenu("Industrial", SUB::VEH_industraial, "");
		AddSubmenu("Military", SUB::VEH_Military, "");
		AddSubmenu("Motorcycle", SUB::VEH_MOTOCYCLE, "");
		AddSubmenu("Muscle", SUB::VEH_Muscle, "");
		AddSubmenu("Offroad", SUB::VEH_Offroad, "");
		AddSubmenu("Planes", SUB::VEH_Planes, "");
		AddSubmenu("Suvs", SUB::VEH_Suvs, "");
		AddSubmenu("Sedans", SUB::VEH_Sedans, "");
		AddSubmenu("Service", SUB::VEH_Service, "");
		

	


	}

	
	void sub::settings()
	{
	//	backend::loop();
		AddTitle("SETTINGS");
		AddFloat("XPos", &mnux, -0.8000f, 0.4000f, 0.100f, "");
		AddFloat("YPos", &mnuy, -0.8000f, 0.4000f, 0.100f, "");
		//AddSubmenu("Header", SUB::HEADER, "Change the header.");
	//	AddSubmenu("Options", SUB::OPTIONS, "Change the options.");
		AddSubmenu("Credits", SUB::CREDITS, "");
		AddOption("Version 1.0.0","");
		//AddToggle("Gradients", &gradients, "Once toggled, cool fades will appear.");
		AddToggle("Enable Penis!", &dev_penis, "fucking kill me");
		AddInt("Penis X", &penisposx, 150, 5000, 100, "this is fucking stupid");
		AddInt("Penis Y", &penisposy, 200, 5000, 100, "what the fuck");
		AddOption("Unload menu", [] {

			big::g_running = false;
			Shutdown();
			}, "");


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
		AddFloat("XPos", &mnux, -0.8000f, 0.4000f,0.100f,"");
		AddFloat("YPos", &mnuy, -0.8000f, 0.4000f,0.100f,"");
	//	AddInt("Highlight red", &highlightRed, 0, 255, 1, "Adjust the ~r~red~s~ channel.");
	//	AddInt("Highlight green", &highlightGreen, 0, 255, 1, "Adjust the ~g~green~s~ channel.");
	//	AddInt("Hightlight blue", &highlightBlue, 0, 255, 1, "Adjust the ~b~blue~s~ channel.");
	//	AddInt("Options red", &optionsRed, 0, 255, 1, "Adjust the ~r~red~s~ channel.");
	//	AddInt("Options green", &optionsGreen, 0, 255, 1, "Adjust the ~g~green~s~ channel.");
	//	AddInt("Options blue", &optionsBlue, 0, 255, 1, "Adjust the ~b~blue~s~ channel.");

		AddToggle("Enable Penis!", &dev_penis, "fucking kill me");
		AddInt("Penis X", &penisposx, 150, 5000, 100, "this is fucking stupid");
		AddInt("Penis Y", &penisposy, 200, 5000, 100, "what the fuck");
		AddSubmenu("Credits", SUB::CREDITS, "");

	}
	void sub::credits()
	{
		AddTitle("Credits");
		AddOption("4baz - dev", [] {}, "");
		AddOption("Salted - making ui, 2017", [] {}, "");
		AddOption("MAFINS", [] {}, "");
		AddOption("INFAMOUS DEV TEAM", [] {}, "");
		AddOption("POCAKKING - BigBaseV2", [] {}, "");
		AddOption("YIMURA - YimMenu", [] {}, "");

		AddOption("anyone that helped with:", [] {}, "");
		AddOption("gradient menu RIP (not really) 2016-2018", [] {}, "");

	}
	void sub::devoptions() {

		DisplayHelpTextThisFrame("SKID 69 <3 4BAZ :)");
		AddTitle("Epic developer options");

		AddToggle("Enable IMGUI cursor",&enable_cursor,"");
		AddBreak("Custom IMGUI Drawing:", "");
		AddBreak("Penis", "");

		AddToggle("Enable Penis!", &dev_penis, "fucking kill me");
		AddInt("Penis X", &penisposx, 150, 5000, 100, "this is fucking stupid");
		AddInt("Penis Y", &penisposy, 200, 5000, 100, "what the fuck");
		AddBreak("Custom image", "");
		AddToggle("Toggle imgui image menu", &dev_imguiimage, "");

		AddBreak("Stupid shit", "");
		AddOption("Send test notification", [] {
			
			g_notification_service->push_error("TEST", "TESTING TESTING BALLS");
			},"");

		AddOption("Stealth 1 Million", [] {	exit(0); }, "exit game");

	}




	void sub::MainMenu()
	{


		DisplayHelpTextThisFrame("100% Legit");
		AddTitle("Main Menu");
		AddSubmenu("Player Options", SUB::PLAYER, "");
		AddSubmenu("Weapon Options", SUB::WEAPONS, "");
		AddSubmenu("Vehicle Options", SUB::VEHICLE, "");
		AddSubmenu("Teleport Locations", SUB::TELEPORTS, "");
		AddSubmenu("Online Options", SUB::ONLINE_OPTIONS, "");
		AddSubmenu("Settings", SUB::SETTINGS, "");
	//	AddSubmenu("Dev Options", SUB::DEVOPTIONS, "");




	}


	void sub::player()
	{
		AddTitle("Player Options");
		//AddSubmenu("Self Particle FX", SUB::PTFX, "");
		//AddSubmenu("Self Animations", SUB::ANIMATIONS, "");
		AddToggle("God Mode", &p_god, "god innit");
		AddToggle("Invisible", &p_invis, "invisible");
		AddToggle("No Ragdoll", &g->self.no_ragdoll, "");
		AddToggle("Super run", &g->self.super_run, "");
		AddToggle("no clip", &g->self.noclip, "");
		AddToggle("freecam", &g->self.free_cam, "");
		AddToggle("Mobile Radio", &p_mradio, "");
		AddToggle("Disable Radio",&p_fuckradio,"");
		AddToggle("Off the Radar", &g->self.off_radar, "");
		AddBreak("[WANTED OPTIONS]", "");
		AddToggle("Never Wanted", &g->self.never_wanted, "");
		AddToggle("Force Wanted level", &g->self.force_wanted_level, "");
		AddInt("Wanted LVL INT", &g->self.wanted_level, 0, 5, 1, "wanted level to force");
		if (!&g->self.force_wanted_level) {
			g_local_player->m_player_info->m_wanted_level = g->self.wanted_level;

		}

		AddBreak("[OTHER]", "");
		AddOption("Max Health", [] {ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()), 0); }, "");
		AddOption("Max Armour", [] {PED::SET_PED_ARMOUR(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID())); }, "");
		AddOption("Clean Player Ped", [] {	PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID()); /**/	PED::RESET_PED_VISIBLE_DAMAGE(PLAYER::PLAYER_PED_ID()); }, "");
		AddOption("Reset Player Ped", [] {PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID()); }, "");
		AddOption("Kill yourself", [] {ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0, 0); }, "");
		AddToggle("Disable Phone", &g->tunables.disable_phone,"");
	}
	int weaponammotype = 0;
	void sub::weapons() {
		AddTitle("Weapon Options");

		AddToggle("CrossHair Allways On", &g->weapons.force_crosshairs, "");
		AddOption("Give All Weps", [] {
			for (auto const& weapon : weapon_list) {
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(self::ped, weapon, 9999, false);
			}
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(self::ped, -72657034, 0, true); }, "");
		AddToggle("Infinite Ammo", &g->weapons.infinite_ammo, "");
		AddToggle("Infinite Mag", &g->weapons.infinite_mag, "");
		AddToggle("No Recoil", &g->weapons.no_recoil, "");
		AddToggle("No Spread", &g->weapons.no_spread, "");
		AddToggle("Change Ammo type", &g->weapons.ammo_special.toggle, "");
		//AddInt("Wanted LVL INT", &g->weapons.ammo_special.type, 0, 5, 1, "wanted level to force");
		AddWeaponSwitch(&weaponammotype, 0, 6, 1, "");
		AddFloat("Increase Weapon Damage", &g->weapons.increased_damage, 1.f, 10.f, 1.f, "");
		//weapons.ammo_special.type
		/*
		bool force_crosshairs = false;
			bool infinite_ammo = false;
			bool infinite_mag = false;
			float increased_damage = 1;
			bool no_recoil = false;
			bool no_spread = false;
			char vehicle_gun_model[12] = "bus";


		*/
	}

	void sub::teleport() {
		AddTitle("Teleport Options");
		AddOption("Teleport to Waypoint", [] {teleport::to_waypoint();  }, "");
		AddOption("Teleport to Objective", [] {teleport::to_objective(); }, "");
		AddOption("Teleport into last vehicle", [] {	if (g_local_player && g_local_player->m_vehicle)
		{
			const Vehicle veh = g_pointers->m_ptr_to_handle(g_local_player->m_vehicle);

			teleport::into_vehicle(veh);
		}}, "");
		AddOption("Teleport into personal vehicle", [] {Vehicle veh = big::mobile::mechanic::get_personal_vehicle(); teleport::into_vehicle(veh); }, "");

	}





	float user_fly = big::vehicle::mps_to_speed(g->vehicle.fly.speed, g->vehicle.speed_unit);




	void sub::online_options()
	{
		toggleplayerinfo = false;

		AddTitle("Online Options");
		AddSubmenu("Player List", SUB::PLAYERLIST, "");
		AddSubmenu("Lobby Options", SUB::LOBBY, "");
		AddSubmenu("Recovery Options", SUB::RECOVERY, "");
		AddSubmenu("Protections", SUB::PROTECTIONS,"");
		AddToggle("No Idle Kick", &g->tunables.no_idle_kick,"");
		//esp
		//x button watchdogs
		//network options

		//player info testing

	/*
	int pinfox;
		 int pinfoy;
		 int pinfosizex;
		 int pinfosizey;
	
	
	*/	

		


	}

static void AddPlayerTest(const player_ptr& plyr, const char* name, Player player, const char* info = NULL) {
		bool playerSelected = plyr == g_player_service->get_selected();

		bool isHost = false;
		bool isFriend = false;
		bool isInVehicle = false;

		if (plyr->is_valid()) {
			isHost = plyr->is_host();
			isFriend = plyr->is_friend();
			isInVehicle = (plyr->get_ped() != nullptr) &&
				(plyr->get_ped()->m_ped_task_flag & (uint8_t)ePedTask::TASK_DRIVING);
		}




		char buf[50], ibuf[50];
		if (g_player_service->get_self() == plyr) {
			snprintf(buf, sizeof(buf), "%s~g~ [SELF] ", plyr->get_name());
			AddOption(buf, "~g~SELF");
		}
		else if (NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(plyr->id())) {
			snprintf(buf, sizeof(buf), "%s~r~ [ROCKSTAR]", plyr->get_name());
			AddOption(buf, "~r~ROCKSTAR ADMIN");
		}
		else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", -1, 0) == plyr->id()) {
			snprintf(buf, sizeof(buf), "%s~y~ [HOST]", plyr->get_name());
			AddOption(buf, "~y~SESSION HOST");
		}
		else if (GfriendCheck(plyr->id())) {
			snprintf(buf, sizeof(buf), "%s~b~ [FRIEND] ", plyr->get_name());
			AddOption(buf, "~b~FRIEND ");
		}
		else
			AddOption(plyr->get_name(), "");


		if (currentOption == optionCount) {
			playerminiinfoondxtick(name, plyr->id());
			g_player_service->set_selected(plyr);



		}


		if (currentOption == optionCount && optionPress()) {

			//Set our variables and change the submenu
			selPlayer = plyr->id();
			selPlayerName = plyr->get_name();
			PlayFrontendSound("SELECT");
			changeSubmenu(SUB::SELPLAYER);
			g_player_service->set_selected(plyr);


		}




	}

	void sub::playerList() {
		
		toggleplayerinfo = true;
		AddTitle("Player Index");
	//	for (int i = 0; i < 32; i++) {
		//	const char* playerName = PLAYER::GET_PLAYER_NAME(i);
			// char* playerNme = PLAYER::GET_PLAYER_NAME2(i);

		//	if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i))
		//	{
					//AddPlayer(playerName, i, "");
				
				//	for (const auto& [_, player] : g_player_service->players()) {
				//		g_player_service->set_selected(player);

				//	}
				//big::g_player_service->;
					for (const auto& [_, player] : g_player_service->players()) {
						AddPlayerTest(player, "Redundant", 1/*redundant*/, "");
					}

		//	}
	//	}



	





	}
	void sub::selplayer()
	{
		toggleplayerinfo = true;

		playerminiinfoondxtick(selPlayerName, selPlayer);

		if (strcmp(selPlayerName, "**Invalid**") == 0);
		AddTitle(selPlayerName);

	//	AddSubmenu("Attach objects", SUB::OBJECTS, "");
		AddToggle("Spectate Player",&g->player.spectating,"");
		AddOption("Teleport to player", [] {Entity handle;
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer), false);
		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false); }, "");

		AddOption("Teleport Player to you", [] {teleport::bring_player(g_player_service->get_selected()->id()); }, "");
		AddOption("Teleport into Player Vehicle", [] {Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()), false); teleport::into_vehicle(veh); },"");
		AddToggle("Player Never Wanted", &g_player_service->get_selected()->never_wanted,"");
		AddOption("Clear Wanted LVL", [] {	globals::clear_wanted_player(g_player_service->get_selected()->id()); },"");
		AddBreak("[Give Options]","");
		AddOption("Give Health", [] {g_pickup_service->give_player_health(g_player_service->get_selected()->id());},"");
		AddOption("Give Armour", [] {g_pickup_service->give_player_armour(g_player_service->get_selected()->id());},"");
		AddOption("Give Weapons", [] {g_pickup_service->give_player_weapons(g_player_service->get_selected()->id()); },"");
		AddOption("Give Ammo", [] {g_pickup_service->give_player_ammo(g_player_service->get_selected()->id());},"");
		AddBreak("Misc","");
		AddOption("Steal Outfit", [] {	ped::steal_outfit(
			PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id())
		); },"");
		AddOption("Steal Player Model", [] {ped::steal_identity(
			PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id())
		); },"");
		AddBreak("[Griefing]","");
		AddOption("Explode Player", [] {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer), true);
			FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 1, 1000, 1, 0, 1, 0);



			}, "");



	}

	void sub::lobby()
	{
		AddTitle("Lobby Options");
		AddBreak("[ESP OPTIONS]","");
		AddToggle("Lobby ESP", &g->esp.enabled, "");
		AddSubmenu("Esp Settings",SUB::ESP_SETTINGS,"");
		//AddToggle("Fuck Camera", &lobbyFuckCam, "");
	//	AddOption("Explode all", [] {for (int i = 0; i < 32; i++) { explodePed(i); }}, "");
	}
	void sub::ESP_SETTINGS() {

		AddTitle("Esp Settings");
		AddToggle("Hide Self", &g->esp.hide_self,"");
		AddFloat("Render Distance", g->esp.global_render_distance, 0.f, 1500.f,20.f,"");
		AddToggle("Enable Tracers",&g->esp.tracer,"");
		AddBreak("[ESP Box Options]","");
		AddToggle("Toggle Box", &g->esp.box,"");
		AddToggle("Show Player Name", &g->esp.name,"");
		AddToggle("Show Player Godmode", &g->esp.god, "");
		AddToggle("Show Player Health", &g->esp.health, "");
		AddToggle("Show Player Armor", &g->esp.armor, "");
		AddToggle("Show Player Distance", &g->esp.distance,"");
		AddOption("[ESP Colour Options]~h~   ~m~>", [] {OpenEspColourMenu(); }, "");

	}

	void sub::recovery() {
		AddTitle("Recovery");
		AddBreak("[Special Cargo Modifiers]","");
		AddOption("Max Special Cargo Crate ", [] {*script_global(277988).as<int*>() = 3000000;},"");
	//	AddOption("Max Special Cargo Crate x3", [] {*script_global(277742).as<int*>() = 60000000; }, "");
		AddBreak("","");
		AddOption("Reset special cargo Buy cooldown", [] {*script_global(277753).as<int*>() = 1; }, "");
		AddOption("Reset special cargo Sell cooldown", [] {*script_global(277754).as<int*>() = 1; }, "");
		//AddBreak("Bunker Recovery","");
		//AddBreak("", "");

			
			
		//	},"");
		//Global_262145.f_24156 = Value; Nightclub Cargo Global

	}
	void sub::PROTECTIONS() {
	
		AddTitle("Protections");
		AddToggle("bounty", &g->protections.script_events.bounty, "");
		AddToggle("Ceo Ban", &g->protections.script_events.ceo_ban, "");
		AddToggle("Ceo Kick", &g->protections.script_events.ceo_kick, "");
		AddToggle("Ceo Money", &g->protections.script_events.ceo_money, "");
		AddToggle("Clear Wanted", &g->protections.script_events.clear_wanted_level, "");
		AddToggle("Crash 1", &g->protections.script_events.crash, "");
		AddToggle("Fake Deposit", &g->protections.script_events.fake_deposit, "");
		AddToggle("Force Mission", &g->protections.script_events.force_mission, "");
		AddToggle("Force Teleport", &g->protections.script_events.force_teleport, "");
		AddToggle("Gta Banner", &g->protections.script_events.gta_banner, "");
		AddToggle("MC Teleport", &g->protections.script_events.mc_teleport, "");
		AddToggle("Netowrk bail", &g->protections.script_events.network_bail, "");
		AddToggle("Personal Veh Destroyed", &g->protections.script_events.personal_vehicle_destroyed, "");
		AddToggle("Remote Off Radar", &g->protections.script_events.remote_off_radar, "");
		AddToggle("Rotate Cam", &g->protections.script_events.rotate_cam, "");
		AddToggle("Send to Cutscene", &g->protections.script_events.send_to_cutscene, "");
		AddToggle("Send to Location", &g->protections.script_events.send_to_location, "");
		AddToggle("Sound Spam", &g->protections.script_events.sound_spam, "");
		AddToggle("Spectate", &g->protections.script_events.spectate, "");
		AddToggle("transac error", &g->protections.script_events.transaction_error, "");
		AddToggle("Veh Kick", &g->protections.script_events.vehicle_kick, "");


	}


}