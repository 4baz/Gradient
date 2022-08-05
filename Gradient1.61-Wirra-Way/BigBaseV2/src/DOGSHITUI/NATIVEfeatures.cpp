#include "NATIVEfeatures.h"

#include "../common.hpp"
#include "../natives.hpp"
#include "NATIVEmenu.h"

#include "script_global.hpp"
#include "util/system.hpp"
#include "pointers.hpp"
#include "script_local.hpp"
#include <util/vehicle.hpp>

#include "services/notifications/notification_service.hpp"

using namespace big;
const char* stringtochar;
const char* stringtochar2;

void FeatureLoop()
{

	//self options
	if (p_god) {
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(),true);
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);

	}

	if (p_invis) {
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(),false,0);
	}
	else {
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true,0);

	}


	/*if (p_neverwanted) {
		Entity player = PLAYER::PLAYER_PED_ID();
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_MAX_WANTED_LEVEL(0);
		PLAYER::SET_POLICE_IGNORE_PLAYER(player, true);
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, false);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, true);
		PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, true);
	}
	else {
		Entity player = PLAYER::PLAYER_PED_ID();
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_MAX_WANTED_LEVEL(5);
		PLAYER::SET_POLICE_IGNORE_PLAYER(player, false);
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, true);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, false);
		PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, false);
	}*/

	if (p_mradio) {
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
	}
	else
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);

	}

	if (p_fuckradio) {
		///fuck knows if this works tbh
		AUDIO::SET_RADIO_TO_STATION_NAME("RADIO_19_USER");
		AUDIO::SET_VEH_RADIO_STATION(self::veh, "RADIO_19_USER");
		AUDIO::SET_FRONTEND_RADIO_ACTIVE(false);
		AUDIO::FREEZE_RADIO_STATION("RADIO_19_USER");
		p_mradio = false;
	}
	else {
		AUDIO::SET_FRONTEND_RADIO_ACTIVE(true);
		AUDIO::UNFREEZE_RADIO_STATION("RADIO_19_USER");
	}


	if (t_test_money) {
	//	*script_global(1963962, 728).at(11).as<int*>() != 4

	}




	if (v_proofs) {
	//	vehicle::repair(self::veh);


		VEHICLE::SET_VEHICLE_FIXED(self::veh);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(self::veh);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(self::veh, 0.f);

		g->vehicle.proof_bullet = true;
		g->vehicle.proof_collision = true;
		g->vehicle.proof_explosion = true;
		g->vehicle.proof_fire = true;
		g->vehicle.proof_mask = true;
		g->vehicle.proof_melee = true;
		g->vehicle.proof_steam = true;
		g->vehicle.proof_water = true;
	}
	else {
		g->vehicle.proof_bullet = false;
		g->vehicle.proof_collision = false;
		g->vehicle.proof_explosion = false;
		g->vehicle.proof_fire = false;
		g->vehicle.proof_mask = false;
		g->vehicle.proof_melee = false;
		g->vehicle.proof_steam = false;
		g->vehicle.proof_water = false;
	}

	std::vector<notification> notifications = g_notification_service->get();

	float prev_pos = 0.f;
	for (int i = 0; i < notifications.size(); i++) {
		notification& n = notifications[i];

		stringtochar = n.title.c_str();
		stringtochar2 = n.message.c_str();


		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(stringtochar);
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("CHAR_MP_STRIPCLUB_PR", true);
		HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT("CHAR_MP_STRIPCLUB_PR", "CHAR_MP_STRIPCLUB_PR", false, 1, "WIRRA-WAY", stringtochar2);


	}

	int Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);


	//vehicle horn
	
	

}

void setwantedlevel(int lvl) {
	//Big::MemoryHandle::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, Features::WantedLevel);
	
}

void OpenEspColourMenu() {

	enable_cursor = true;
	enable_esp_rgbmenu = true;

}

void upgradeBase(Vehicle vehicle, int* engine, int* transmission, int* brakes, int* suspension, int* armour) {
	if (VEHICLE::GET_VEHICLE_MOD_KIT(vehicle) != 0)
		VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
	*engine = VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 11);
	*transmission = VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 12);
	*brakes = VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 13);
	*suspension = VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 15);
	*armour = VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 16);
	VEHICLE::SET_VEHICLE_MOD(vehicle, 11, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 11) - 1, 11);
	VEHICLE::SET_VEHICLE_MOD(vehicle, 12, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 12) - 1, 12);
	VEHICLE::SET_VEHICLE_MOD(vehicle, 13, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 13) - 1, 13);
	VEHICLE::SET_VEHICLE_MOD(vehicle, 15, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 15) - 1, 15);
	VEHICLE::SET_VEHICLE_MOD(vehicle, 15, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 16) - 1, 15);
	VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 18, 1);
}


namespace IPLS {


	void CAYOPERICO() {
		STREAMING::REQUEST_IPL("h4_islandx_terrain_01_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_01_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_02");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_02_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_02_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_03");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_03_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_04");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_04_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_04_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_05");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_05_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_05_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_06");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_01_grass_0");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_01_grass_1");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_02_grass_0");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_02_grass_1");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_02_grass_2");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_02_grass_3");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_04_grass_0");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_04_grass_1");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_05_grass_0");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_06_grass_0");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_06_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_06_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_a");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_a_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_b");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_b_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_c");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_c_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_d");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_d_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_d_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_e");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_e_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_e_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_f");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_f_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_05_f_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_a");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_a_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_a_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_b");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_b_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_b_slod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_c");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_c_lod");
		STREAMING::REQUEST_IPL("h4_islandx_terrain_props_06_c_slod");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_01");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_01_long_0");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_02");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_03");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_04");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_05");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_06");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_06_strm_0");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_lod");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_00");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_01");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_02");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_03");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_04");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_05");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_06");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_07");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_08");
		STREAMING::REQUEST_IPL("h4_mph4_terrain_occ_09");
		STREAMING::REQUEST_IPL("h4_boatblockers");
		STREAMING::REQUEST_IPL("h4_islandx");
		STREAMING::REQUEST_IPL("h4_islandx_disc_strandedshark");
		STREAMING::REQUEST_IPL("h4_islandx_disc_strandedshark_lod");
		STREAMING::REQUEST_IPL("h4_islandx_disc_strandedwhale");
		STREAMING::REQUEST_IPL("h4_islandx_disc_strandedwhale_lod");
		STREAMING::REQUEST_IPL("h4_islandx_props");
		STREAMING::REQUEST_IPL("h4_islandx_props_lod");
		STREAMING::REQUEST_IPL("h4_islandx_sea_mines");
		STREAMING::REQUEST_IPL("h4_mph4_island");
		STREAMING::REQUEST_IPL("h4_mph4_island_long_0");
		STREAMING::REQUEST_IPL("h4_mph4_island_strm_0");
		STREAMING::REQUEST_IPL("h4_aa_guns");
		STREAMING::REQUEST_IPL("h4_aa_guns_lod");
		STREAMING::REQUEST_IPL("h4_beach");
		STREAMING::REQUEST_IPL("h4_beach_bar_props");
		STREAMING::REQUEST_IPL("h4_beach_lod");
		STREAMING::REQUEST_IPL("h4_beach_party");
		STREAMING::REQUEST_IPL("h4_beach_party_lod");
		STREAMING::REQUEST_IPL("h4_beach_props");
		STREAMING::REQUEST_IPL("h4_beach_props_lod");
		STREAMING::REQUEST_IPL("h4_beach_props_party");
		STREAMING::REQUEST_IPL("h4_beach_props_slod");
		STREAMING::REQUEST_IPL("h4_beach_slod");
		STREAMING::REQUEST_IPL("h4_islandairstrip");
		STREAMING::REQUEST_IPL("h4_islandairstrip_doorsclosed");
		STREAMING::REQUEST_IPL("h4_islandairstrip_doorsclosed_lod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_doorsopen");
		STREAMING::REQUEST_IPL("h4_islandairstrip_doorsopen_lod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_hangar_props");
		STREAMING::REQUEST_IPL("h4_islandairstrip_hangar_props_lod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_hangar_props_slod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_lod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_props");
		STREAMING::REQUEST_IPL("h4_islandairstrip_propsb");
		STREAMING::REQUEST_IPL("h4_islandairstrip_propsb_lod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_propsb_slod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_props_lod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_props_slod");
		STREAMING::REQUEST_IPL("h4_islandairstrip_slod");
		STREAMING::REQUEST_IPL("h4_islandxcanal_props");
		STREAMING::REQUEST_IPL("h4_islandxcanal_props_lod");
		STREAMING::REQUEST_IPL("h4_islandxcanal_props_slod");
		STREAMING::REQUEST_IPL("h4_islandxdock");
		STREAMING::REQUEST_IPL("h4_islandxdock_lod");
		STREAMING::REQUEST_IPL("h4_islandxdock_props");
		STREAMING::REQUEST_IPL("h4_islandxdock_props_2");
		STREAMING::REQUEST_IPL("h4_islandxdock_props_2_lod");
		STREAMING::REQUEST_IPL("h4_islandxdock_props_2_slod");
		STREAMING::REQUEST_IPL("h4_islandxdock_props_lod");
		STREAMING::REQUEST_IPL("h4_islandxdock_props_slod");
		STREAMING::REQUEST_IPL("h4_islandxdock_slod");
		STREAMING::REQUEST_IPL("h4_islandxdock_water_hatch");
		STREAMING::REQUEST_IPL("h4_islandxtower");
		STREAMING::REQUEST_IPL("h4_islandxtower_lod");
		STREAMING::REQUEST_IPL("h4_islandxtower_slod");
		STREAMING::REQUEST_IPL("h4_islandxtower_veg");
		STREAMING::REQUEST_IPL("h4_islandxtower_veg_lod");
		STREAMING::REQUEST_IPL("h4_islandxtower_veg_slod");
		STREAMING::REQUEST_IPL("h4_islandx_barrack_hatch");
		STREAMING::REQUEST_IPL("h4_islandx_barrack_props");
		STREAMING::REQUEST_IPL("h4_islandx_barrack_props_lod");
		STREAMING::REQUEST_IPL("h4_islandx_barrack_props_slod");
		STREAMING::REQUEST_IPL("h4_islandx_checkpoint");
		STREAMING::REQUEST_IPL("h4_islandx_checkpoint_lod");
		STREAMING::REQUEST_IPL("h4_islandx_checkpoint_props");
		STREAMING::REQUEST_IPL("h4_islandx_checkpoint_props_lod");
		STREAMING::REQUEST_IPL("h4_islandx_checkpoint_props_slod");
		STREAMING::REQUEST_IPL("h4_islandx_maindock");
		STREAMING::REQUEST_IPL("h4_islandx_maindock_lod");
		STREAMING::REQUEST_IPL("h4_islandx_maindock_props");
		STREAMING::REQUEST_IPL("h4_islandx_maindock_props_2");
		STREAMING::REQUEST_IPL("h4_islandx_maindock_props_2_lod");
		STREAMING::REQUEST_IPL("h4_islandx_maindock_props_2_slod");
		STREAMING::REQUEST_IPL("h4_islandx_maindock_props_lod");
		STREAMING::REQUEST_IPL("h4_islandx_maindock_props_slod");
		STREAMING::REQUEST_IPL("h4_islandx_maindock_slod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_b");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_b_lod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_b_side_fence");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_b_slod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_entrance_fence");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_guardfence");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_lights");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_01");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_01_lod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_02");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_02_lod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_03");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_lockup_03_lod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_lod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_office");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_office_lod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_props");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_props_lod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_props_slod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_slod");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_vault");
		STREAMING::REQUEST_IPL("h4_islandx_mansion_vault_lod");
		STREAMING::REQUEST_IPL("h4_island_padlock_props");
		STREAMING::REQUEST_IPL("h4_mansion_gate_broken");
		STREAMING::REQUEST_IPL("h4_mansion_gate_closed");
		STREAMING::REQUEST_IPL("h4_mansion_remains_cage");
		STREAMING::REQUEST_IPL("h4_mph4_airstrip");
		STREAMING::REQUEST_IPL("h4_mph4_airstrip_interior_0_airstrip_hanger");
		STREAMING::REQUEST_IPL("h4_mph4_beach");
		STREAMING::REQUEST_IPL("h4_mph4_dock");
		STREAMING::REQUEST_IPL("h4_mph4_island_lod");
		STREAMING::REQUEST_IPL("h4_mph4_island_ne_placement");
		STREAMING::REQUEST_IPL("h4_mph4_island_nw_placement");
		STREAMING::REQUEST_IPL("h4_mph4_island_se_placement");
		STREAMING::REQUEST_IPL("h4_mph4_island_sw_placement");
		STREAMING::REQUEST_IPL("h4_mph4_mansion");
		STREAMING::REQUEST_IPL("h4_mph4_mansion_b");
		STREAMING::REQUEST_IPL("h4_mph4_mansion_b_strm_0");
		STREAMING::REQUEST_IPL("h4_mph4_mansion_strm_0");
		STREAMING::REQUEST_IPL("h4_mph4_wtowers");
		STREAMING::REQUEST_IPL("h4_ne_ipl_00");
		STREAMING::REQUEST_IPL("h4_ne_ipl_00_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_00_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_01");
		STREAMING::REQUEST_IPL("h4_ne_ipl_01_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_01_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_02");
		STREAMING::REQUEST_IPL("h4_ne_ipl_02_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_02_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_03");
		STREAMING::REQUEST_IPL("h4_ne_ipl_03_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_03_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_04");
		STREAMING::REQUEST_IPL("h4_ne_ipl_04_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_04_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_05");
		STREAMING::REQUEST_IPL("h4_ne_ipl_05_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_05_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_06");
		STREAMING::REQUEST_IPL("h4_ne_ipl_06_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_06_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_07");
		STREAMING::REQUEST_IPL("h4_ne_ipl_07_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_07_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_08");
		STREAMING::REQUEST_IPL("h4_ne_ipl_08_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_08_slod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_09");
		STREAMING::REQUEST_IPL("h4_ne_ipl_09_lod");
		STREAMING::REQUEST_IPL("h4_ne_ipl_09_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_00");
		STREAMING::REQUEST_IPL("h4_nw_ipl_00_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_00_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_01");
		STREAMING::REQUEST_IPL("h4_nw_ipl_01_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_01_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_02");
		STREAMING::REQUEST_IPL("h4_nw_ipl_02_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_02_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_03");
		STREAMING::REQUEST_IPL("h4_nw_ipl_03_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_03_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_04");
		STREAMING::REQUEST_IPL("h4_nw_ipl_04_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_04_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_05");
		STREAMING::REQUEST_IPL("h4_nw_ipl_05_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_05_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_06");
		STREAMING::REQUEST_IPL("h4_nw_ipl_06_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_06_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_07");
		STREAMING::REQUEST_IPL("h4_nw_ipl_07_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_07_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_08");
		STREAMING::REQUEST_IPL("h4_nw_ipl_08_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_08_slod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_09");
		STREAMING::REQUEST_IPL("h4_nw_ipl_09_lod");
		STREAMING::REQUEST_IPL("h4_nw_ipl_09_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_00");
		STREAMING::REQUEST_IPL("h4_se_ipl_00_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_00_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_01");
		STREAMING::REQUEST_IPL("h4_se_ipl_01_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_01_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_02");
		STREAMING::REQUEST_IPL("h4_se_ipl_02_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_02_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_03");
		STREAMING::REQUEST_IPL("h4_se_ipl_03_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_03_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_04");
		STREAMING::REQUEST_IPL("h4_se_ipl_04_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_04_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_05");
		STREAMING::REQUEST_IPL("h4_se_ipl_05_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_05_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_06");
		STREAMING::REQUEST_IPL("h4_se_ipl_06_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_06_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_07");
		STREAMING::REQUEST_IPL("h4_se_ipl_07_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_07_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_08");
		STREAMING::REQUEST_IPL("h4_se_ipl_08_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_08_slod");
		STREAMING::REQUEST_IPL("h4_se_ipl_09");
		STREAMING::REQUEST_IPL("h4_se_ipl_09_lod");
		STREAMING::REQUEST_IPL("h4_se_ipl_09_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_00");
		STREAMING::REQUEST_IPL("h4_sw_ipl_00_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_00_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_01");
		STREAMING::REQUEST_IPL("h4_sw_ipl_01_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_01_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_02");
		STREAMING::REQUEST_IPL("h4_sw_ipl_02_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_02_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_03");
		STREAMING::REQUEST_IPL("h4_sw_ipl_03_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_03_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_04");
		STREAMING::REQUEST_IPL("h4_sw_ipl_04_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_04_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_05");
		STREAMING::REQUEST_IPL("h4_sw_ipl_05_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_05_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_06");
		STREAMING::REQUEST_IPL("h4_sw_ipl_06_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_06_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_07");
		STREAMING::REQUEST_IPL("h4_sw_ipl_07_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_07_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_08");
		STREAMING::REQUEST_IPL("h4_sw_ipl_08_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_08_slod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_09");
		STREAMING::REQUEST_IPL("h4_sw_ipl_09_lod");
		STREAMING::REQUEST_IPL("h4_sw_ipl_09_slod");
		STREAMING::REQUEST_IPL("h4_underwater_gate_closed");
		STREAMING::REQUEST_IPL("h4_islandx_placement_01");
		STREAMING::REQUEST_IPL("h4_islandx_placement_02");
		STREAMING::REQUEST_IPL("h4_islandx_placement_03");
		STREAMING::REQUEST_IPL("h4_islandx_placement_04");
		STREAMING::REQUEST_IPL("h4_islandx_placement_05");
		STREAMING::REQUEST_IPL("h4_islandx_placement_06");
		STREAMING::REQUEST_IPL("h4_islandx_placement_07");
		STREAMING::REQUEST_IPL("h4_islandx_placement_08");
		STREAMING::REQUEST_IPL("h4_islandx_placement_09");
		STREAMING::REQUEST_IPL("h4_islandx_placement_10");
		STREAMING::REQUEST_IPL("h4_mph4_island_placement");
	}
	void YANKTON() {

		if (STREAMING::IS_IPL_ACTIVE((char*)"prologue01"))
		{
			STREAMING::IS_IPL_ACTIVE((char*)"prologue01");
			STREAMING::IS_IPL_ACTIVE((char*)"Prologue01c");
			STREAMING::IS_IPL_ACTIVE((char*)"Prologue01d");
			STREAMING::IS_IPL_ACTIVE((char*)"Prologue01e");
			STREAMING::IS_IPL_ACTIVE((char*)"Prologue01f");
			STREAMING::IS_IPL_ACTIVE((char*)"Prologue01g");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue01h");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue01i");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue01j");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue01k");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue01z");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue02");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue03");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue03b");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue03_grv_cov");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue03_grv_dug");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue03_grv_fun");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue04");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue04b");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue04_cover");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue05");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue05b");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue06");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue06b");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue06_int");
			STREAMING::IS_IPL_ACTIVE((char*)"prologuerd");
			STREAMING::IS_IPL_ACTIVE((char*)"prologuerdb");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue_DistantLights");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue_grv_torch");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue_m2_door");
			STREAMING::IS_IPL_ACTIVE((char*)"prologue_LODLights");
			STREAMING::IS_IPL_ACTIVE((char*)"DES_ProTree_start");
			return;
		}
		STREAMING::REQUEST_IPL((char*)"prologue01");
		STREAMING::REQUEST_IPL((char*)"Prologue01c");
		STREAMING::REQUEST_IPL((char*)"Prologue01d");
		STREAMING::REQUEST_IPL((char*)"Prologue01e");
		STREAMING::REQUEST_IPL((char*)"Prologue01f");
		STREAMING::REQUEST_IPL((char*)"Prologue01g");
		STREAMING::REQUEST_IPL((char*)"prologue01h");
		STREAMING::REQUEST_IPL((char*)"prologue01i");
		STREAMING::REQUEST_IPL((char*)"prologue01j");
		STREAMING::REQUEST_IPL((char*)"prologue01k");
		STREAMING::REQUEST_IPL((char*)"prologue01z");
		STREAMING::REQUEST_IPL((char*)"prologue02");
		STREAMING::REQUEST_IPL((char*)"prologue03");
		STREAMING::REQUEST_IPL((char*)"prologue03b");
		STREAMING::REQUEST_IPL((char*)"prologue03_grv_cov");
		STREAMING::REQUEST_IPL((char*)"prologue03_grv_dug");
		STREAMING::REQUEST_IPL((char*)"prologue03_grv_fun");
		STREAMING::REQUEST_IPL((char*)"prologue04");
		STREAMING::REQUEST_IPL((char*)"prologue04b");
		STREAMING::REQUEST_IPL((char*)"prologue04_cover");
		STREAMING::REQUEST_IPL((char*)"prologue05");
		STREAMING::REQUEST_IPL((char*)"prologue05b");
		STREAMING::REQUEST_IPL((char*)"prologue06");
		STREAMING::REQUEST_IPL((char*)"prologue06b");
		STREAMING::REQUEST_IPL((char*)"prologue06_int");
		STREAMING::REQUEST_IPL((char*)"prologuerd");
		STREAMING::REQUEST_IPL((char*)"prologuerdb");
		STREAMING::REQUEST_IPL((char*)"prologue_DistantLights");
		STREAMING::REQUEST_IPL((char*)"prologue_grv_torch");
		STREAMING::REQUEST_IPL((char*)"prologue_m2_door");
		STREAMING::REQUEST_IPL((char*)"prologue_LODLights");
		STREAMING::REQUEST_IPL((char*)"DES_ProTree_start");
	}



	void CARRIER() {

		if (STREAMING::IS_IPL_ACTIVE((char*)"hei_carrier"))
		{
			STREAMING::IS_IPL_ACTIVE((char*)"hei_carrier");
			STREAMING::IS_IPL_ACTIVE((char*)"hei_carrier_DistantLights");
			STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int1");
			STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int2");
			STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int3");
			STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int4");
			STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int5");
			STREAMING::IS_IPL_ACTIVE((char*)"hei_Carrier_int6");
			STREAMING::IS_IPL_ACTIVE((char*)"hei_carrier_LODLights");
			return;
		}
		STREAMING::REQUEST_IPL((char*)"hei_carrier");
		STREAMING::REQUEST_IPL((char*)"hei_carrier_DistantLights");
		STREAMING::REQUEST_IPL((char*)"hei_Carrier_int1");
		STREAMING::REQUEST_IPL((char*)"hei_Carrier_int2");
		STREAMING::REQUEST_IPL((char*)"hei_Carrier_int3");
		STREAMING::REQUEST_IPL((char*)"hei_Carrier_int4");
		STREAMING::REQUEST_IPL((char*)"hei_Carrier_int5");
		STREAMING::REQUEST_IPL((char*)"hei_Carrier_int6");
		STREAMING::REQUEST_IPL((char*)"hei_carrier_LODLights");
	}

	void FARM() {
		if (STREAMING::IS_IPL_ACTIVE((char*)"farm_burnt"))
		{
			STREAMING::IS_IPL_ACTIVE((char*)"farm_burnt");
			STREAMING::IS_IPL_ACTIVE((char*)"farm_burnt_props");
			STREAMING::IS_IPL_ACTIVE((char*)"farm");
			STREAMING::IS_IPL_ACTIVE((char*)"farm_props");
			STREAMING::IS_IPL_ACTIVE((char*)"farmint");
			STREAMING::IS_IPL_ACTIVE((char*)"farmint_cap");

			return;
		}
		STREAMING::REQUEST_IPL((char*)"farm_burnt");
		STREAMING::REQUEST_IPL((char*)"farm_burnt_props");
		STREAMING::REQUEST_IPL((char*)"farm");
		STREAMING::REQUEST_IPL((char*)"farm_props");
		STREAMING::REQUEST_IPL((char*)"farmint");
		STREAMING::REQUEST_IPL((char*)"farmint_cap");
	}


};