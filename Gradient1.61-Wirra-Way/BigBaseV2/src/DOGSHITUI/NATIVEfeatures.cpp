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
