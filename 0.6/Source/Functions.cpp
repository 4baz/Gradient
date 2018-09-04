#include "stdafx.h"

std::set<Ped> lastSeenPeds;
using namespace std;
//=================
// PED FUNCTIONS
//=================

Ped ClonePed(Ped ped)
{
	if (ENTITY::DOES_ENTITY_EXIST(ped) && !ENTITY::IS_ENTITY_DEAD(ped))
	{
		return PED::CLONE_PED(ped, ENTITY::GET_ENTITY_HEADING(ped), 1, 1);
	}

	return 0;
}

Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle)
{
	Ped NewPed;
	int PedHash = $(PedName);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(PedHash))
	{
		if (STREAMING::IS_MODEL_VALID(PedHash))
		{
			STREAMING::REQUEST_MODEL(PedHash);
			while (!STREAMING::HAS_MODEL_LOADED(PedHash)) WAIT(0);

			NewPed = PED::CREATE_PED(ped_type, PedHash, SpawnCoordinates.x, SpawnCoordinates.y, SpawnCoordinates.z, 0, network_handle, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PedHash);
			return NewPed;
		}
	}

	return -1;
}

//Animations
void LoadAnim(char * dict)
{
	int tick = 0;
	STREAMING::REQUEST_ANIM_DICT(dict);
	while (tick < 100 && !STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		tick++;
		WAIT(0);
	}
}

void playAnimation(Ped ped, bool loop, char * dict, char * anim)
{
	LoadAnim(dict);
	int a = -1;
	int b = 1;

	if (!loop)
	{
		a = 1;
		b = 0;
	}

	AI::TASK_PLAY_ANIM(ped, dict, anim, 10000.0f, -1.5f, a, b, 0.445f, false, false, false);

}

//Skins
bool applyChosenSkin(DWORD model)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model))
		{
			WAIT(0);
		}

		Vehicle veh = NULL;
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		}

		PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
		//PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), FALSE);
		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
		WAIT(0);

		if (veh != NULL)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}

		WAIT(100);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

		return true;
	}
	return false;
}

bool applyChosenSkin(std::string skinName)
{
	DWORD model = $((char *)skinName.c_str());
	return applyChosenSkin(model);
}

//CONTROL
void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED()) 
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}

//FORCE
void ApplyForceToEntity(Entity e, float x, float y, float z)
{
	if (e != PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == FALSE)
	{
		RequestControlOfEnt(e);
	}

	ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);

}

//GOD MODE
void GodMode(bool toggle)
{
	static int armour_player = 0;
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (armour_player == 0)
	{
		armour_player = PED::GET_PED_ARMOUR(playerPed);
	}

	if (toggle)
	{
		//set_status_text("Activating godmode");
		PLAYER::SET_PLAYER_INVINCIBLE(player, true);
		ENTITY::SET_ENTITY_PROOFS(playerPed, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE);
		PED::SET_PED_CAN_RAGDOLL(playerPed, FALSE);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, FALSE);
		PED::ADD_ARMOUR_TO_PED(playerPed, PLAYER::GET_PLAYER_MAX_ARMOUR(player) - PED::GET_PED_ARMOUR(playerPed));
	}
	else
	{
		//set_status_text("Deactivating godmode");
		PLAYER::SET_PLAYER_INVINCIBLE(player, false);
		ENTITY::SET_ENTITY_PROOFS(playerPed, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
		PED::SET_PED_CAN_RAGDOLL(playerPed, TRUE);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, TRUE);
		if (armour_player != 0)
		{
			PED::SET_PED_ARMOUR(playerPed, armour_player);
			armour_player = 0;
		}
	}
}

//NEARBY PEDS
std::set<Ped> getNearbyPeds()
{
	return lastSeenPeds;
}

void update_nearby_peds(Ped playerPed, int count)
{
	const int numElements = count;
	const int arrSize = numElements * 2 + 2;

	Ped *peds = new Ped[arrSize];
	peds[0] = numElements;
	int found = PED::GET_PED_NEARBY_PEDS(playerPed, peds, -1);

	for (int i = 0; i < found; i++)
	{
		int offsettedID = i * 2 + 2;

		if (!ENTITY::DOES_ENTITY_EXIST(peds[offsettedID]))
		{
			continue;
		}

		Ped xped = peds[offsettedID];

		bool inSet = lastSeenPeds.find(xped) != lastSeenPeds.end();
		if (!inSet)
		{
			lastSeenPeds.insert(xped);
		}
	}

	std::set<Ped>::iterator it;
	for (it = lastSeenPeds.begin(); it != lastSeenPeds.end();)
	{
		if (!ENTITY::DOES_ENTITY_EXIST(*it))
		{
			lastSeenPeds.erase(it++);
		}
		else
		{
			++it;
		}
	}

	delete peds;
}

//CALM PEDS
void set_all_nearby_peds_to_calm()
{
	for each (Ped xped in lastSeenPeds)
	{
		PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(xped, true);
		PED::SET_PED_FLEE_ATTRIBUTES(xped, 0, 0);
		PED::SET_PED_COMBAT_ATTRIBUTES(xped, 17, 1);
	}
}

//Converts Radians to Degrees
float degToRad(float degs)
{
	return degs*3.141592653589793f / 180.f;
}

//little one-line function called '$' to convert $TRING into a hash-key:
Hash $(std::string str) {
	return GAMEPLAY::GET_HASH_KEY(&str[0u]);
}

// quick function to get - coords - of - entity:
Vector3 coordsOf(Entity entity) {
	return ENTITY::GET_ENTITY_COORDS(entity, 1);
}

//quick function to get distance between 2 points: eg - if (distanceBetween(coordsOf(player), targetCoords) < 50)
float distanceBetween(Vector3 A, Vector3 B) {
	return GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}

//quick "get random int in range 0-x" function:
int rndInt(int start, int end) {
	return GAMEPLAY::GET_RANDOM_INT_IN_RANGE(start, end);
}

//TELEPORTATION
void teleport_to_coords(Entity e, Vector3 coords)
{
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
	WAIT(0);
}

Vector3 get_blip_marker()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
	if (blipFound)
	{
		return coords;
	}

	return zero;
}

void teleport_to_marker()
{
	Vector3 coords = get_blip_marker();

	if (coords.x == 0 && coords.y == 0)
	{
		notifyMap("No Waypoint has been set!", 0);
		return;
	}

	// get entity to teleport
	Entity e = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	{
		e = PED::GET_VEHICLE_PED_IS_USING(e);
	}

	// load needed map region and check height levels for ground existence
	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}
	// if ground not found then set Z in air and give player a parachute
	if (!groundFound)
	{
		coords.z = 1000.0;
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
	}
	//do it
	teleport_to_coords(e, coords);
}

void teleport_to_objective()
{
	Vector3 coords;
	Entity e;
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, FALSE))
		e = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	else e = playerPed;

	bool blipFound = false;

	if (ENTITY::IS_ENTITY_A_VEHICLE(e)) RequestControlOfEnt(e);
	for (int i = 0; i <= 1000; i++)
	{
		Blip_t* blip = Hooking::GetBlipList()->m_Blips[i];
		if (blip)
		{
			if ((blip->dwColor == ColorYellowMission && blip->iIcon == SpriteStandard) || (blip->dwColor == ColorYellow && blip->iIcon == SpriteStandard) ||
				(blip->dwColor == ColorWhite && blip->iIcon == SpriteRaceFinish) || (blip->dwColor == ColorGreen && blip->iIcon == SpriteStandard) || (blip->iIcon == SpriteCrateDrop)) {
				coords = blip->coords;
				blipFound = true;
				break; //During a race there's sometimes 2 yellow markers. We want the first one.
			}
		}
	}

	blipFound ? teleport_to_coords(e, coords) : notifyMap("Objective not found!", 0);
	
}

//In Game KEYBOARD
std::string show_keyboard(char* title_id, char* prepopulated_text)
{
	DWORD time = GetTickCount() + 400;
	while (GetTickCount() < time)
	{
		WAIT(0);
	}

	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, (title_id == NULL ? "HUD_TITLE" : title_id), "", (prepopulated_text == NULL ? "" : prepopulated_text), "", "", "", 64);

	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0)
	{
		WAIT(0);
	}

	std::stringstream ss;
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT())
	{
		return std::string("");
	}
	else
	{
		return std::string(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
	}
}

//VEHICLE
static std::string lastvehmodel("");
bool get_vehicle_keyboard_result()
{
	std::string result = show_keyboard("FMMC_KEY_TIP", &lastvehmodel[0]);
	if (!result.empty())
	{
		uint model = $(result);
		if (STREAMING::IS_MODEL_A_VEHICLE(model))
		{
			lastvehmodel = result;
			RequestedModel = model;
			return true;
		}

		else
		{
			lastvehmodel = "";
			RequestedModel = 0ul;
			notifyMap("Not A Valid Model!", true);
			return get_vehicle_keyboard_result();
		}

	}

	return false;
}

void spawn_vehicle()
{
	float forward = 5.f;
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float playerHeading = ENTITY::GET_ENTITY_HEADING(playerPed);
	Vehicle playerVeh = NULL;
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, FALSE))
		playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

	float xVect = forward * sin(degToRad(playerHeading)) * -1.0f;
	float yVect = forward * cos(degToRad(playerHeading));
	BOOL isAircraft = VEHICLE::IS_THIS_MODEL_A_HELI(RequestedModel) || VEHICLE::IS_THIS_MODEL_A_PLANE(RequestedModel);
	if (playerVeh != NULL) AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);

	if (isAircraft) playerVeh = VEHICLE::CREATE_VEHICLE(RequestedModel, playerPos.x + xVect, playerPos.y + yVect, playerPos.z + 1000, playerHeading, TRUE, TRUE);
	else
	{
		playerVeh = VEHICLE::CREATE_VEHICLE(RequestedModel, playerPos.x + xVect, playerPos.y + yVect, playerPos.z, playerHeading, TRUE, TRUE);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(playerVeh);
	}

	PED::SET_PED_INTO_VEHICLE(playerPed, playerVeh, -1);

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RequestedModel);
	RequestedModel = 0ul;
	notifyMap("Spawned " + lastvehmodel, 0);

	if (isAircraft) {
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(playerVeh, 500.0f);
		VEHICLE::SET_HELI_BLADES_FULL_SPEED(playerVeh);
	}

	ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&playerVeh);
}

void request_vehicle()
{
	if (get_vehicle_keyboard_result())
	{
		modelFunction = spawn_vehicle;
		model_state = requesting;
	}
}

//NOTIFICATIONS
void notifyMap(std::string msg, BOOL blink) {
	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(&msg[0u]);
	UI::_DRAW_NOTIFICATION(blink, FALSE);
}

void ptfx(char* call1, char* call2, char* name) {
	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(call2);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

}
const static Hash weaponlist[] = {

	//Melee
	-1716189206, 1737195953,
	1317494643, -1786099057,
	-2067956739, 1141786504,
	-102323637, -1834847097,
	-102973651, -656458692,
	-581044007, -1951375401,
	-538741184, -1810795771,
	419712736, -853065399, //16 (excluding unarmed

						   //Handguns
						   453432689, 1593441988,
						   -1716589765, -1076751822,
						   -771403250, 137902532,
						   -598887786, -1045183535,
						   584646201, 911657153,
						   1198879012, 3219281620, //12

												   //SMGs and Machine guns
												   324215364, -619010992,
												   736523883, -270015777,
												   171789620, -1660422300,
												   2144741730, 1627465347,
												   -1121678507, 2024373456,
												   3686625920, -1121678507 //11

																		   //Assault Rifles
	- 1074790547, -2084633992,
	-1357824103, -1063057011,
	2132975508, 1649403952,
	961495388, 4208062921, //8

						   //Sniper Rifles
	100416529, 205991906,
	-952879014, 177293209, //4

						   //Shotguns
	487013001, 2017895192,
	-1654528753, -494615257,
	-1466123874, 984333226,
	-275439685, 317205821, //8

						   //Heavy weapons
	-1568386805, -1312131151,
	1119849093, 2138347493,
	1834241177, 1672152130,
	1305664598, 125959754, //8

						   //Thrown weapons
	-1813897027, 741814745,
	-1420407917, -1600701090,
	615608432, 101631238,
	883325847, 1233104067,
	600439132, 126349499,
	-37975472, -1169823560, //12

							//Parachute
	-72657034 //1

};
void give_all_weps() {

	Ped ped = PLAYER::PLAYER_PED_ID();

	for each (Hash weaponlist in weaponlist) {
		if (WEAPON::HAS_PED_GOT_WEAPON(ped, weaponlist, FALSE) == FALSE)
		{
			WEAPON::GIVE_WEAPON_TO_PED(ped, weaponlist, 9999, FALSE, TRUE);
			WEAPON::SET_PED_WEAPON_TINT_INDEX(ped, weaponlist, WeaponTintGold);
		}
	}
}



void ForceWeapAddons(Ped ped, Hash weaponHash, bool bSilencer)
{
	//Since only I get these anyway, might as well craft it for me.
	static Hash weaponAddons[] = { COMPONENT_AT_SCOPE_MACRO, COMPONENT_AT_SCOPE_MACRO_02, COMPONENT_AT_SCOPE_SMALL, COMPONENT_AT_SCOPE_SMALL_02, COMPONENT_AT_SCOPE_MEDIUM, COMPONENT_AT_SCOPE_LARGE, COMPONENT_AT_SCOPE_MAX, COMPONENT_AT_RAILCOVER_01, COMPONENT_AT_AR_AFGRIP, COMPONENT_AT_PI_FLSH, COMPONENT_AT_AR_FLSH, COMPONENT_PISTOL_CLIP_02, COMPONENT_COMBATPISTOL_CLIP_02, COMPONENT_APPISTOL_CLIP_02, COMPONENT_MICROSMG_CLIP_02, COMPONENT_SMG_CLIP_02, COMPONENT_ASSAULTRIFLE_CLIP_02, COMPONENT_CARBINERIFLE_CLIP_02, COMPONENT_ADVANCEDRIFLE_CLIP_02, COMPONENT_MG_CLIP_02, COMPONENT_COMBATMG_CLIP_02, COMPONENT_ASSAULTSHOTGUN_CLIP_02, COMPONENT_PISTOL50_CLIP_02, COMPONENT_ASSAULTSMG_CLIP_02, COMPONENT_SNSPISTOL_CLIP_02, COMPONENT_COMBATPDW_CLIP_02, COMPONENT_HEAVYPISTOL_CLIP_02, COMPONENT_SPECIALCARBINE_CLIP_02, COMPONENT_BULLPUPRIFLE_CLIP_02, COMPONENT_VINTAGEPISTOL_CLIP_02, COMPONENT_MARKSMANRIFLE_CLIP_02, COMPONENT_HEAVYSHOTGUN_CLIP_02, COMPONENT_GUSENBERG_CLIP_02 };
	for each (Hash addonHash in weaponAddons)
	{
		if (WEAPON::DOES_WEAPON_TAKE_WEAPON_COMPONENT(weaponHash, addonHash))
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, weaponHash, addonHash);
	}
	if (bSilencer)
	{
		//static Hash silencers[] = { COMPONENT_AT_PI_SUPP, COMPONENT_AT_PI_SUPP_02, COMPONENT_AT_AR_SUPP, COMPONENT_AT_SR_SUPP, COMPONENT_AT_AR_SUPP_02 };
		static Hash silencers[] = { COMPONENT_AT_PI_SUPP_02, COMPONENT_AT_AR_SUPP };
		for each (Hash silencerHash in silencers)
		{
			if (WEAPON::DOES_WEAPON_TAKE_WEAPON_COMPONENT(weaponHash, silencerHash)) {
				if (weaponHash != 0xAF113F99 && WEAPON::GET_WEAPONTYPE_GROUP(weaponHash) != 0x33431399)
					WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, weaponHash, silencerHash);
			}
		}
		if (weaponHash == 0x05FC3C11 || weaponHash == 0x13532244)
			WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(ped, weaponHash, COMPONENT_AT_AR_SUPP_02);
	}
}



void upgrade_guns() {
	Ped ped = PLAYER::PLAYER_PED_ID();

	for each (Hash weaponlist in weaponlist) {
		ForceWeapAddons(ped, weaponlist, 1);
	}
}

void loop_infiniteAmmo(Ped playerPed)
{
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

void moveMe(float x, float y, float z)
{
	Entity e = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
		e = PED::GET_VEHICLE_PED_IS_USING(e);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, x, y, z, 1, 1, 1);
}










using namespace STREAMING;
void nyankton()
{
	REQUEST_IPL("prologue01");
	REQUEST_IPL("prologue01_lod");
	REQUEST_IPL("prologue01c");
	REQUEST_IPL("prologue01c_lod");
	REQUEST_IPL("prologue01d");
	REQUEST_IPL("prologue01d_lod");
	REQUEST_IPL("prologue01e");
	REQUEST_IPL("prologue01e_lod");
	REQUEST_IPL("prologue01f");
	REQUEST_IPL("prologue01f_lod");
	REQUEST_IPL("prologue01g");
	REQUEST_IPL("prologue01h");
	REQUEST_IPL("prologue01h_lod");
	REQUEST_IPL("prologue01i");
	REQUEST_IPL("prologue01i_lod");
	REQUEST_IPL("prologue01j");
	REQUEST_IPL("prologue01j_lod");
	REQUEST_IPL("prologue01k");
	REQUEST_IPL("prologue01k_lod");
	REQUEST_IPL("prologue01z");
	REQUEST_IPL("prologue01z_lod");
	REQUEST_IPL("plg_02");
	REQUEST_IPL("prologue02");
	REQUEST_IPL("prologue02_lod");
	REQUEST_IPL("plg_03");
	REQUEST_IPL("prologue03");
	REQUEST_IPL("prologue03_lod");
	REQUEST_IPL("prologue03b");
	REQUEST_IPL("prologue03b_lod");
	REQUEST_IPL("prologue03_grv_dug");
	REQUEST_IPL("prologue03_grv_dug_lod");
	REQUEST_IPL("prologue_grv_torch");
	REQUEST_IPL("plg_04");
	REQUEST_IPL("prologue04");
	REQUEST_IPL("prologue04_lod");
	REQUEST_IPL("prologue04b");
	REQUEST_IPL("prologue04b_lod");
	REQUEST_IPL("prologue04_cover");
	REQUEST_IPL("des_protree_end");
	REQUEST_IPL("des_protree_start");
	REQUEST_IPL("des_protree_start_lod");
	REQUEST_IPL("plg_05");
	REQUEST_IPL("prologue05");
	REQUEST_IPL("prologue05_lod");
	REQUEST_IPL("prologue05b");
	REQUEST_IPL("prologue05b_lod");
	REQUEST_IPL("plg_06");
	REQUEST_IPL("prologue06");
	REQUEST_IPL("prologue06_lod");
	REQUEST_IPL("prologue06b");
	REQUEST_IPL("prologue06b_lod");
	REQUEST_IPL("prologue06_int");
	REQUEST_IPL("prologue06_int_lod");
	REQUEST_IPL("prologue06_pannel");
	REQUEST_IPL("prologue06_pannel_lod");
	REQUEST_IPL("prologue_m2_door");
	REQUEST_IPL("prologue_m2_door_lod");
	REQUEST_IPL("plg_occl_00");
	REQUEST_IPL("prologue_occl");
	REQUEST_IPL("plg_rd");
	REQUEST_IPL("prologuerd");
	REQUEST_IPL("prologuerdb");
	REQUEST_IPL("prologuerd_lod");
	REMOVE_IPL("prologue03_grv_cov");
	REMOVE_IPL("prologue03_grv_cov_lod");
	REMOVE_IPL("prologue03_grv_fun");

	moveMe(3360.19f, -4849.67f, 111.8f);
}
void lfactFire()
{
	REQUEST_IPL("id2_14_on_fire");
	moveMe(716.84f, -962.05f, 31.59f);
}
void lfactduringDoor()
{
	REQUEST_IPL("id2_14_during_door");
	moveMe(716.84f, -962.05f, 31.59f);
}
void Yacht1()
{
	REQUEST_IPL("hei_yacht_heist");
	REQUEST_IPL("hei_yacht_heist_Bar");
	REQUEST_IPL("hei_yacht_heist_Bedrm");
	REQUEST_IPL("hei_yacht_heist_Bridge");
	REQUEST_IPL("hei_yacht_heist_DistantLights");
	REQUEST_IPL("hei_yacht_heist_enginrm");
	REQUEST_IPL("hei_yacht_heist_LODLights");
	REQUEST_IPL("hei_yacht_heist_Lounge");
	moveMe(-2045.8f, -1031.2f, 11.9f);
}
void dhosp()
{
	REQUEST_IPL("RC12B_Destroyed");
	REQUEST_IPL("RC12B_HospitalInterior");
	moveMe(356.8f, -590.1f, 43.3f);
}
void ufo1()
{
	REQUEST_IPL("ufo");
	moveMe(-2051.99463f, 3237.05835f, 1456.97021f);
}
void ufo2() {
	REQUEST_IPL("ufo");
	moveMe(2490.47729f, 3774.84351f, 2414.035f);
}
void Mmorg()
{
	REQUEST_IPL("Coroner_Int_on");
	moveMe(244.9f, -1374.7f, 39.5f);
}
void cship()
{
	REMOVE_IPL("sunkcargoship");
	REQUEST_IPL("cargoship");
	moveMe(-90.0f, -2365.8f, 14.3f);
}
void cshipSunk()
{
	REMOVE_IPL("cargoship");
	REQUEST_IPL("sunkcargoship");
	moveMe(-162.8918f, -2365.7690f, 0.f);
}
void hcarrier()
{
	REQUEST_IPL("hei_carrier");
	REQUEST_IPL("hei_carrier_DistantLights");
	REQUEST_IPL("hei_Carrier_int1");
	REQUEST_IPL("hei_Carrier_int2");
	REQUEST_IPL("hei_Carrier_int3");
	REQUEST_IPL("hei_Carrier_int4");
	REQUEST_IPL("hei_Carrier_int5");
	REQUEST_IPL("hei_Carrier_int6");
	REQUEST_IPL("hei_carrier_LODLights");
	moveMe(3069.98f, -4632.49f, 16.26f);
}
void cbell()
{
	REMOVE_IPL("CS1_02_cf_offmission1");
	REQUEST_IPL("CS1_02_cf_onmission1");
	REQUEST_IPL("CS1_02_cf_onmission2");
	REQUEST_IPL("CS1_02_cf_onmission3");
	REQUEST_IPL("CS1_02_cf_onmission4");
	moveMe(-72.68752f, 6253.72656f, 31.08991f);
}
void airfield()
{
	REQUEST_IPL("airfield");
	moveMe(1743.682f, 3286.251f, 40.0875f);
}
void destFarm()
{
	REMOVE_IPL("farm_int");
	REMOVE_IPL("farm_props");
	REMOVE_IPL("farm");
	REQUEST_IPL("farm_burnt");
	REQUEST_IPL("farm_burnt_props");
	REQUEST_IPL("farm_int_cap");
	moveMe(2447.9f, 4973.4f, 47.7f);
}
void intFarm()
{
	REQUEST_IPL("farm_int");
	REQUEST_IPL("farm_props");
	REQUEST_IPL("farm");
	REMOVE_IPL("farm_burnt");
	REMOVE_IPL("farm_burnt_props");
	REMOVE_IPL("farm_int_cap");
	moveMe(2447.9f, 4973.4f, 47.7f);
}
void facelobby()
{
	REQUEST_IPL("facelobby");
	moveMe(-1047.9f, -233.0f, 39.0f);
}
void simeon()
{
	REMOVE_IPL("fakeint");
	REQUEST_IPL("v_carshowroom");
	REQUEST_IPL("shutter_open");
	REQUEST_IPL("shr_int");
	moveMe(-30.8793f, -1088.336f, 25.4221f);
}
void udBigVault()
{
	REQUEST_IPL("FINBANK");
	moveMe(2.69689322f, -667.0166f, 16.1306286f);
}
void udShutters()
{
	REMOVE_IPL("DT1_03_Gr_Closed");
	REQUEST_IPL("DT1_03_Shutter");
	moveMe(23.9346f, -669.7552f, 30.8853f);
}
void jewelStore()
{
	REMOVE_IPL("jewel2fake");
	REMOVE_IPL("bh1_16_refurb");
	REQUEST_IPL("post_hiest_unload");
	moveMe(-630.4f, -236.7f, 40.0f);
}


void repair(Vehicle vehicle) {
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), FALSE)) {
		if (FIRE::IS_ENTITY_ON_FIRE(vehicle))
			FIRE::STOP_ENTITY_FIRE(vehicle);
		VEHICLE::SET_VEHICLE_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.0f);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.0f);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.0f);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.0f);
		VEHICLE::_SET_VEHICLE_PAINT_FADE(vehicle, 0.0f);
		VEHICLE::SET_VEHICLE_UNDRIVEABLE(vehicle, FALSE);
		VEHICLE::SET_VEHICLE_IS_CONSIDERED_BY_PLAYER(vehicle, TRUE);
		VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, TRUE, TRUE, TRUE);
		VEHICLE::_SET_VEHICLE_JET_ENGINE_ON(vehicle, TRUE);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, FALSE);
	}
}
	


	void MaxVeh() {
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
		}
	}




	void openDoors() {
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorFrontLeftDoor, true, true);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorFrontRightDoor, true, true);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorBackLeftDoor, true, true);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorBackRightDoor, true, true);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorHood, true, true);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorTrunk, true, true);
		VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, VehicleDoorTrunk2, true, true);
	}

	void setPlate(Vehicle vehicle) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1))
		{
			string plateTemp = show_keyboard("Numberplate Text", VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT(vehicle));
			if (plateTemp == "")
			{
				notifyMap("Cannot be blank", 0);
			}
			else
			{
				RequestControlOfEnt(vehicle);
				while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
				{
					WAIT(0);
				}
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
			}
		}
		else
		{
			notifyMap("Player not in vehicle", 0);
		}
	}

	void kickVeh(Player player) {
		Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		std::string pname = PLAYER::GET_PLAYER_NAME(player);
		if (PED::IS_PED_IN_ANY_VEHICLE(ped, FALSE))
		{
			RequestControlOfEnt(ped);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(ped);
			WEAPON::REMOVE_WEAPON_FROM_PED(ped, 0xFBAB5776);
			notifyMap("Kicked From Vehicle", 0);
		}
		else
			notifyMap(pname + " is not in a vehicle", 0);
	}

	void deletePedVeh(Ped p) {
		if (PED::IS_PED_IN_ANY_VEHICLE(p, 1)) {
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(p, 0);
			if (!NETWORK::NETWORK_IS_SESSION_STARTED()) {
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehicle, true, true);
				VEHICLE::DELETE_VEHICLE(&vehicle);
				notifyMap("*poof*", 0);
			}
			else {
				RequestControlOfEnt(vehicle);
				WAIT(0);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(vehicle, 1);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehicle, true, true);
				VEHICLE::DELETE_VEHICLE(&vehicle);
			}
		}
		else if (ENTITY::DOES_ENTITY_EXIST(VEHICLE::GET_LAST_DRIVEN_VEHICLE())) {
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(p, 0);
			if (!NETWORK::NETWORK_IS_SESSION_STARTED()) {
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehicle, true, true);
				VEHICLE::DELETE_VEHICLE(&vehicle);
				notifyMap("*poof*", 0);
			}
			else {
				RequestControlOfEnt(vehicle);
				NETWORK::SET_NETWORK_ID_CAN_MIGRATE(vehicle, 1);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehicle, true, true);
				VEHICLE::DELETE_VEHICLE(&vehicle);
			}
		}
		else {
			notifyMap("~w~Vehicle Not Found", 0);
			return;
		}
	}


	void loop_esp(Player target, int r, int g, int b)
	{
		if (target != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
		{
			Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
			Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
			Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
			Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
			Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
			Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
			Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
			Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
			Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };

			GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, r, g, b, 255);

			GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, r, g, b, 255);

			GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, r, g, b, 255);
			GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, r, g, b, 255);

			Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
			Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, r, g, b, 255);
		}
	}


	void loop_fuckCam(Player target)
	{
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
		FIRE::ADD_EXPLOSION(pCoords.x, pCoords.y, pCoords.z + 15, 29, 999999.5f, false, true, 1.0f, true);

	}

	void Unlock_all() {
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);

		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_8"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_9"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_10"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_11"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_12"), -1, 1);

		STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
		STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
		STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
		STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
		STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 50, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);

		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
	}
	int TimePD4 = 1000;
	void Stealth10Mil(bool toggle) {

		if ((timeGetTime() - TimePD4) > 100)
		{
			int money = 2147483647;
			Any transactionID = money;
			if (Hooking::network_shop_begin_service(&transactionID, 1474183246, 312105838, 1445302971, 100000000, 4))
				UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);
		}
	}

	void explodePed(Player target) {
		Hooking::ownedExplosionBypass(true);
		
		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);

		FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f, false);
	}

	void PlayAnim(char* animationName, char* animDict) {
		STREAMING::REQUEST_ANIM_DICT(animDict);
		while (!STREAMING::HAS_ANIM_DICT_LOADED(animDict))
			WAIT(0);
		AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), animDict, animationName, 8.0, 0.0, -1, 0, 0, 0, 0, 0);
	}


	void unhook()
	{
		Log::Msg("Cleaning up hooks (via unhook menu option)");
		for (int i = 0; i < Hooking::m_hooks.size(); i++)
			if (MH_DisableHook(Hooking::m_hooks[i]) != MH_OK && MH_RemoveHook(Hooking::m_hooks[i]) != MH_OK)
				Log::Error("Failed to unhook %p", (void*)Hooking::m_hooks[i]);
		MH_Uninitialize();
	}