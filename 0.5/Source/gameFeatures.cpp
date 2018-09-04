#include "stdafx.h"
#include "menuVariables.h"
#include "gameFeatures.h"
#include "test2.h"
#include "menuFeatures.h"
#include "menuEnums.h"
using namespace PLAYER;
using namespace ENTITY;
using namespace PED;
using namespace VEHICLE;
using namespace OBJECT;
using namespace AI;
using namespace GAMEPLAY;
using namespace AUDIO;
using namespace CUTSCENE;
using namespace INTERIOR;
using namespace CAM;
using namespace WEAPON;
using namespace ITEMSET;
using namespace STREAMING;
using namespace SCRIPT;
using namespace UI;
using namespace GRAPHICS;
using namespace STATS;
using namespace BRAIN;
using namespace MOBILE;
using namespace APP;
using namespace TIME;
using namespace PATHFIND;
using namespace CONTROLS;
using namespace DATAFILE;
using namespace FIRE;
using namespace DECISIONEVENT;
using namespace ZONE;
using namespace ROPE;
using namespace WATER;
using namespace WORLDPROBE;
using namespace NETWORK;
using namespace NETWORKCASH;
using namespace DLC1;
using namespace DLC2;
using namespace SYSTEM;
using namespace DECORATOR;
using namespace SOCIALCLUB;
using namespace UNK;
using namespace UNK1;
using namespace UNK2;
using namespace UNK3;
using namespace std;
using namespace vehicleVars;
using namespace recoveryVars;
using namespace playerVars;
using namespace weaopnVars;
using namespace miscVars;
using namespace onlineVars;

float vehAirHeight = 0.f;
float vehAirLimit = -0.5f;
//EJECTOR SEAT
float ejectForce = 2.f;
float speedoPosX = 0.12f, speedoPosY = 0.2f, speedoSizeX = 0.2f, speedoSizeY = 0.35f, needlePosX = 0.9f, needlePosY = 0.9f, needleSizeX = 0.25f, needleSizeY = 0.25f;
float needleOffset = 0.f;

extern bool despawnold = false;
extern bool warpintoveh = false;
extern bool spawnmaxed = false;

void autisticTestbs() {
	AddToggle("Despawn old vehicle", &despawnold, "");
	AddToggle("Warp into spawned vehicle", &warpintoveh, "");
	AddToggle("Spawn maxed", &spawnmaxed, "");
}


enum eWheelIDs
{
	WHEEL_LF,	//wheel_lf / bike, plane or jet front
	WHEEL_RF,	//wheel_rf
	WHEEL_LM,	//wheel_lm / in 6 wheels trailer, plane or jet is first one on left
	WHEEL_RM,	//wheel_rm / in 6 wheels trailer, plane or jet is first one on right
	WHEEL_LR,	//wheel_lr / bike rear / in 6 wheels trailer, plane or jet is last one on left
	WHEEL_RR,	//wheel_rr / in 6 wheels trailer, plane or jet is last one on right
	WHEEL_TRAILER_LM,	//6 wheels trailer mid wheel left
	WHEEL_TRAILER_RM	//6 wheels trailer mid wheel right
};
enum eScriptEvent : unsigned
{
	SCRIPTEVENT_PHONE_INVITE_APARTMENT = 34,
	SCRIPTEVENT_PHONE_INVITE_1ON1_DM = 44,
	SCRIPTEVENT_INSURANCE_BILL = 378,
	SCRIPTEVENT_HOSPITAL_BILL = 390,
	SCRIPTEVENT_INVITE_APARTMENT = 445,
	SCRIPTEVENT_JOIN_ORGANISATION = 485,
	SCRIPTEVENT_SECURO_PAYMENT = 487,
	SCRIPTEVENT_SECURO_PAYMENT_SILENT = 490,
	SCRIPTEVENT_RP = 506,
	SCRIPTEVENT_KICK = 556,
};

namespace game {

	void ptfx(char* call1,char* call2,char* name) {
		STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
		GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(call2);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

	}

	void notifyBottom(std::string msg) {
		UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
		UI::_ADD_TEXT_COMPONENT_SCALEFORM(&msg[0u]);
		UI::END_TEXT_COMMAND_PRINT(2000, 1);
	}
	void notifyMap(std::string msg, BOOL blink) {
		UI::SET_TEXT_OUTLINE();
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(&msg[0u]);
		UI::_DRAW_NOTIFICATION(blink, FALSE);
	}
	void notifyClan(std::string msg) {
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_SCALEFORM(&msg[0u]);
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 7, "~b~JOB Menu", "~c~Boi", 1, "___GTA*", 9, 0);
		UI::_DRAW_NOTIFICATION(3000, 1);
	}
	void notifyError(std::string errorType) {
		game::notifyMap("~r~Error: ~w~" + errorType, 0);
	}
	Ped GET_PLAYER_PED(Player player)
	{
		return PLAYER::GET_PLAYER_PED(player);
	}
	float calcSpeed(bool mphOut, Vehicle veh)
	{
		float speed = GET_ENTITY_SPEED(veh);
		float MetersPerHour = (speed * 3600);
		if (mphOut) {
			float mph = (MetersPerHour / 1609.344f);
			return mph;
		}
		else if (!mphOut) {
			float kmh = MetersPerHour / 1000;
			return kmh;
		}
		else
			return speed;
	}
	static unsigned int lastSec = GetTickCount();
	static int framesThisSec = 0;
	static int framePerSec = 0;
	double calcAverageTick()
	{
		framesThisSec++;
		if (GetTickCount() - lastSec >= 1000) {
			framePerSec = framesThisSec;
			framesThisSec = 0;
			lastSec = GetTickCount();
		}
		return framePerSec;
	}

	//Vector & Cam Stuff
	double DegreeToRadian(double n) {
		return n * 0.017453292519943295;
	}
	float Get3DDistance(Vector3 a, Vector3 b) {
		float x = pow((a.x - b.x), 2);
		float y = pow((a.y - b.y), 2);
		float z = pow((a.z - b.z), 2);
		return sqrt(x + y + z);
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
	Vector3 addVector(Vector3 vector, Vector3 vector2) {
		vector.x += vector2.x;
		vector.y += vector2.y;
		vector.z += vector2.z;
		vector._paddingx += vector2._paddingx;
		vector._paddingy += vector2._paddingy;
		vector._paddingz += vector2._paddingz;
		return vector;
	}
	RaycastResult Raycast(Vector3 source, Vector3 endCoords, IntersectOptions inter, Entity entityToignore = 0) {
		RaycastResult endResult;
		try {
			Vector3 emptyVector;
			DWORD Handle = START_SHAPE_TEST_CAPSULE(source.x, source.y, source.z, endCoords.x, endCoords.y, endCoords.z, 1, inter, entityToignore, 7);//_CAST_RAY_POINT_TO_POINT(source.x, source.y, source.z, endCoords.x, endCoords.y, endCoords.z, 19/*inter/*19*/, entityToignore, 7);
			GET_SHAPE_TEST_RESULT(Handle, &endResult.DidHitAnything, &endResult.HitCoords, &emptyVector, &endResult.HitEntity);
			if (DOES_ENTITY_EXIST(endResult.HitEntity)) endResult.DidHitEntity = true; else endResult.DidHitEntity = false;
		}
		catch (...) {

		}
		return endResult;
	}
	float conv360(float base, float min, float max) {
		// This is the function the script used. I just adapted it for C++.
		float fVar0;
		if (min == max) return min;
		fVar0 = max - min;
		base -= round(base - min / fVar0) * fVar0;
		if (base < min) base += fVar0;
		return base;
	}
	void offsetFromEnt(int entity, float X, float Y, float Z, float * Out)
	{
		VectorToFloat(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity, X, Y, Z), Out);
	}

	//MISC TEXTURE SHIT
	void DrawSprite(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
	{
		REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
		HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture);
		DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
	}
}

namespace vehicle {

	void setPerf(int engine, int brakes, int transmission, int suspension, bool turbo) {
		if (VEHICLE::GET_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 11) != engine)
			SET_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 11, engine, 0);
		if (VEHICLE::GET_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 11) != brakes)
			SET_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 11, brakes, 0);
		if (VEHICLE::GET_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 11) != transmission)
			SET_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 11, transmission, 0);
		if (VEHICLE::GET_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 11) != suspension)
			SET_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 11, suspension, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(VEHICLE::GET_LAST_DRIVEN_VEHICLE(), 18, turbo);
	}
	void speedBoost() {
		if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 1)) {
			Vehicle veh = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
			bool bUp = PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER_ID()) || KeyDown(VK_NUMPAD9);
			bool bDown = KeyDown(VK_NUMPAD3) || (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LT));

			if (bUp || bDown) {
				float speed = GET_ENTITY_SPEED(veh);
				if (bUp) {
					speed += speed * 0.05f;
					SET_VEHICLE_FORWARD_SPEED(veh, speed);
				}
				else if (IS_ENTITY_IN_AIR(veh) || speed > 5.0)
					SET_VEHICLE_FORWARD_SPEED(veh, 0.0);
			}
		}
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
			VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.0f);
			VEHICLE::SET_VEHICLE_UNDRIVEABLE(vehicle, FALSE);
			VEHICLE::SET_VEHICLE_IS_CONSIDERED_BY_PLAYER(vehicle, TRUE);
			VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, TRUE, TRUE, TRUE);
			VEHICLE::_SET_VEHICLE_JET_ENGINE_ON(vehicle, TRUE);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, FALSE);
			game::notifyBottom("Vehicle Repaired");
		}
		else {
			game::notifyError("Player is not in Vehicle");
		}
	}
	void paintRandom(Vehicle vehicle, BOOL primary, BOOL secondary, BOOL neon, BOOL wheels, BOOL tyresmoke) {
		if (tyresmoke)
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, rndInt(0, 255), rndInt(0, 255), rndInt(0, 255));
		if (neon)
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, rndInt(0, 255), rndInt(0, 255), rndInt(0, 255));
		if (wheels)
			VEHICLE::SET_VEHICLE_EXTRA_COLOURS(vehicle, rndInt(0, VEHICLE::GET_NUMBER_OF_VEHICLE_COLOURS(vehicle)), rndInt(0, 67));

		VEHICLE::SET_VEHICLE_COLOURS(vehicle, rndInt(0, VEHICLE::GET_NUMBER_OF_VEHICLE_COLOURS(vehicle)), rndInt(0, VEHICLE::GET_NUMBER_OF_VEHICLE_COLOURS(vehicle)));

		if (primary)
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, rndInt(0, 255), rndInt(0, 255), rndInt(0, 255));
		if (secondary)
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, rndInt(0, 255), rndInt(0, 255), rndInt(0, 255));
	}
	void upgradeBase(Vehicle vehicle, int *engine, int *transmission, int *brakes, int *suspension, int *armour) {
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
	void upgradeMax(Vehicle vehicle) {
		RequestControlOfEnt(vehicle);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(vehicle, 7);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 0) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 1, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 1) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 2, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 2) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 3, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 3) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 4, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 4) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 5, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 5) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 6, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 6) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 7, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 7) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 8, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 8) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 9, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 9) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 10, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 10) - 1, 10);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 11, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 11) - 1, 11);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 12, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 12) - 1, 12);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 13, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 13) - 1, 13);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 14, rand() % 32, 0);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 15, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 15) - 1, 1);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 16, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 16) - 1, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 17, TRUE);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 18, TRUE);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 19, TRUE);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 20, TRUE);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 20, 20, 20);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 21, TRUE);
		VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 22, TRUE);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 23, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 23) - 1, 0);
		VEHICLE::SET_VEHICLE_MOD(vehicle, 24, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 24) - 1, 0);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(vehicle, 1);
		for (int i = 0; i < 4; i++)
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, i, 1);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(vehicle, rand() % 5);
		VEHICLE::SET_VEHICLE_LIVERY(vehicle, (VEHICLE::GET_VEHICLE_LIVERY_COUNT(vehicle) - 1));
		VEHICLE::SET_VEHICLE_MOD(vehicle, 48, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 48) - 1, 0);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, FALSE);
		VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, FALSE);
		VEHICLE::SET_VEHICLE_HAS_STRONG_AXLES(vehicle, TRUE);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.0f);
		if (vehThemeActive)
		{
			//	VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, scrollerCol.R, scrollerCol.G, scrollerCol.B);
			//VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, bannerRectCol.R, bannerRectCol.G, bannerRectCol.B);
			//VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, scrollerCol.R, scrollerCol.G, scrollerCol.B);
			//VEHICLE::SET_VEHICLE_EXTRA_COLOURS(vehicle, 1, 1);
		}
	}
	void upgradeStock(Vehicle vehicle) {
		for (int i = 0; i < 48; i++)
			SET_VEHICLE_MOD(vehicle, i, -1, 0);
	}
	void deletePedVeh(Ped p) {
		if (IS_PED_IN_ANY_VEHICLE(p, 1)) {
			Vehicle vehicle = GET_VEHICLE_PED_IS_IN(p, 0);
			if (!NETWORK_IS_SESSION_STARTED()) {
				SET_ENTITY_AS_MISSION_ENTITY(vehicle, true, true);
				DELETE_VEHICLE(&vehicle);
				game::notifyBottom("*poof*");
			}
			else {
				RequestControlOfEnt(vehicle);
				WAIT(0);
				SET_NETWORK_ID_CAN_MIGRATE(vehicle, 1);
				SET_ENTITY_AS_MISSION_ENTITY(vehicle, true, true);
				DELETE_VEHICLE(&vehicle);
			}
		}
		else if (DOES_ENTITY_EXIST(GET_LAST_DRIVEN_VEHICLE())) {
			Vehicle vehicle = GET_VEHICLE_PED_IS_IN(p, 0);
			if (!NETWORK_IS_SESSION_STARTED()) {
				SET_ENTITY_AS_MISSION_ENTITY(vehicle, true, true);
				DELETE_VEHICLE(&vehicle);
				game::notifyBottom("*poof*");
			}
			else {
				RequestControlOfEnt(vehicle);
				SET_NETWORK_ID_CAN_MIGRATE(vehicle, 1);
				SET_ENTITY_AS_MISSION_ENTITY(vehicle, true, true);
				DELETE_VEHICLE(&vehicle);
			}
		}
		else {
			game::notifyError("~w~Vehicle Not Found");
			return;
		}
	}
	void explodeToggle(Vehicle vehicle, BOOL kaboom) {
		Ped playerPed = PLAYER_PED_ID();
		if (vehicle != NULL)
		{
			if (!kaboom)
			{
				SET_VEHICLE_OUT_OF_CONTROL(vehicle, 0, 1);
				game::notifyBottom("Don't Crash ;)");
			}
			else
			{
				SET_VEHICLE_OUT_OF_CONTROL(vehicle, 0, 0);
				game::notifyBottom("Disarmed");
			}
		}
	}
	void bypassOnlineKick(Vehicle vehicle)
	{
		Player player = PLAYER_ID();
		int var;
		DECOR_REGISTER("Player_Vehicle", 3);
		DECOR_REGISTER("Veh_Modded_By_Player", 3);
		DECOR_SET_INT(vehicle, "Player_Vehicle", _0xBC1D768F2F5D6C05(player));
		DECOR_SET_INT(vehicle, "Veh_Modded_By_Player", $(GET_PLAYER_NAME(player)));
		DECOR_SET_INT(vehicle, "Not_Allow_As_Saved_Veh", 0);
		if (DECOR_EXIST_ON(vehicle, "MPBitset"))
			var = DECOR_GET_INT(vehicle, "MPBitset");
		SET_BIT(&var, 3);
		DECOR_SET_INT(vehicle, "MPBitset", var);
		SET_VEHICLE_IS_STOLEN(vehicle, false);
	}
	//Spawn vehicle function
	Vehicle spawn(Hash model, Ped playerPed, Vector3 playerPos)
	{
		Vehicle vehicle = 0; int NetID = 0;

		//Delete old vehicle
		if (despawnold == true) {
		if (IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
			RequestControlOfEnt(playerPed);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
		}
	//	if (despawnold == true) {
			int old = PLAYER::GET_PLAYERS_LAST_VEHICLE();
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(old);
			VEHICLE::DELETE_VEHICLE(&old);
		}

		//Get player heading
		float direction = ENTITY::GET_ENTITY_HEADING(playerPed);

		if (!STREAMING::IS_MODEL_IN_CDIMAGE(model)) return 0;

		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);

		//if player is offline
		if (!NETWORK::NETWORK_IS_IN_SESSION()) {
			vehicle = VEHICLE::CREATE_VEHICLE(model, playerPos.x, playerPos.y, playerPos.z, direction, TRUE, TRUE);
			if (warpintoveh == true) {
			PED::SET_PED_INTO_VEHICLE(playerPed, vehicle, -1);
			if (spawnmaxed == true) {

				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				for (int i = 0; i < 50; i++)
				{
					VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
				}
			}
		}
			VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, TRUE, TRUE, TRUE);

			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

			if (!ENTITY::DOES_ENTITY_EXIST(vehicle)) return 0;

			return vehicle;
		}

		//rest if player is online
		vehicle = VEHICLE::CREATE_VEHICLE(model, playerPos.x, playerPos.y, playerPos.z, direction, TRUE, TRUE);
		NetID = NETWORK::VEH_TO_NET(vehicle);
		if (!NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(NetID))
			WAIT(0);

		vehicle::bypassOnlineKick(vehicle);
		DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
		if (spawnmaxed == true) {

			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
			}
		}

		ENTITY::_SET_ENTITY_REGISTER(NetID, TRUE);

		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(NetID)) NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(NetID, TRUE);

		if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(playerPed)) RequestControlOfEnt(playerPed);

		if (playerPed == PLAYER::PLAYER_PED_ID())
			if (warpintoveh == true) {
		PED::SET_PED_INTO_VEHICLE(playerPed, vehicle, -1);
	}
		VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, TRUE, TRUE, TRUE);

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
		//fade in and out, just cause
		NETWORK::NETWORK_FADE_OUT_ENTITY(vehicle, TRUE, FALSE);
		NETWORK::NETWORK_FADE_IN_ENTITY(vehicle, TRUE);

		return vehicle;
	}
	Vehicle spawn(Hash model, Ped playerPed)
	{
		return vehicle::spawn(model, playerPed, coordsOf(playerPed));
	}
	/*Vehicle spawn(Hash toSpawn, Ped playerPed) {
	float forward = 5.f;
	Vector3 playerPos = GET_ENTITY_COORDS(playerPed, 0);
	float playerHeading = GET_ENTITY_HEADING(playerPed);
	Vector3 playerVelocity = GET_ENTITY_VELOCITY(playerPed);

	float xVect = forward * sin(degToRad(playerHeading)) * -1.0f;
	float yVect = forward * cos(degToRad(playerHeading));

	DWORD model = toSpawn;
	BOOL isAircraft = IS_THIS_MODEL_A_HELI(model) || IS_THIS_MODEL_A_PLANE(model);
	Vehicle veh;

	if (IS_MODEL_IN_CDIMAGE(model) && IS_MODEL_A_VEHICLE(model)) {
	REQUEST_MODEL(model);
	while (!HAS_MODEL_LOADED(model))
	WAIT(0);

	veh = CREATE_VEHICLE(model, playerPos.x + xVect, playerPos.y + yVect, playerPos.z, playerHeading, TRUE, TRUE);
	auto veh2net = VEH_TO_NET(veh);
	if (NETWORK_HAS_CONTROL_OF_NETWORK_ID(veh2net)) {
	// 1
	SET_NETWORK_ID_CAN_MIGRATE(veh2net, 1);
	SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(veh2net, 1);
	}
	else {
	game::notifyError("Vehicle Unk1");
	// Make note of an error here, you got problems boyo
	}
	if (vehSpawnDelete)
	vehicle::deletePedVeh(playerPed);

	if (isAircraft) {
	if (spawnAirplaneInAir) {
	SET_ENTITY_COORDS(veh, playerPos.x + xVect, playerPos.y + yVect, playerPos.z + 1000, false, false, false, false);
	SET_ENTITY_VELOCITY(veh, playerVelocity.x, playerVelocity.y, playerVelocity.z);
	}
	else
	SET_ENTITY_VELOCITY(veh, playerVelocity.x, playerVelocity.y, playerVelocity.z);
	}
	else {
	SET_ENTITY_VELOCITY(veh, playerVelocity.x, playerVelocity.y, playerVelocity.z);
	SET_VEHICLE_ENGINE_ON(veh, TRUE, TRUE, TRUE);
	}

	vehicle::bypassOnlineKick(veh);

	if (spawnInVehicle) {
	if (!NETWORK_HAS_CONTROL_OF_ENTITY(playerPed))
	RequestControlOfEnt(playerPed);
	SET_PED_INTO_VEHICLE(playerPed, veh, -1);
	}

	if ((vehSpawnNeon) && (!vehSpawnMaxed)) {
	_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
	_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
	_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
	_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
	_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 225, 96, 150);
	}

	if (vehSpawnMaxed)
	vehicle::upgradeMax(veh);

	if (isAircraft && spawnAirplaneInAir) {
	SET_VEHICLE_FORWARD_SPEED(veh, 500.0f);
	SET_HELI_BLADES_FULL_SPEED(veh);
	}

	SET_VEHICLE_DIRT_LEVEL(veh, 0);

	SET_VEH_RADIO_STATION(veh, "OFF");
	return veh;
	}
	else {
	return 0;
	}
	}*/
	Vehicle spawn(char* toSpawn, Ped playerPed) {
		return spawn($(toSpawn), playerPed);
	}
	Vehicle clone(Player toClone) {

		Vehicle pedVeh = NULL;
		Ped ped = game::GET_PLAYER_PED(toClone);
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(ped, FALSE))
			pedVeh = PED::GET_VEHICLE_PED_IS_IN(ped, FALSE);
		else
			pedVeh = PED::GET_VEHICLE_PED_IS_IN(ped, TRUE);
		if (ENTITY::DOES_ENTITY_EXIST(pedVeh)) {
			Hash vehicleModelHash = ENTITY::GET_ENTITY_MODEL(pedVeh);
			Vehicle playerVeh = spawn(vehicleModelHash, playerPed);
			int primaryColor, secondaryColor;
			VEHICLE::GET_VEHICLE_COLOURS(pedVeh, &primaryColor, &secondaryColor);
			VEHICLE::SET_VEHICLE_COLOURS(playerVeh, primaryColor, secondaryColor);
			if (VEHICLE::GET_IS_VEHICLE_PRIMARY_COLOUR_CUSTOM(pedVeh)) {
				int r, g, b;
				VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(pedVeh, &r, &g, &b);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(playerVeh, r, g, b);
			}
			if (VEHICLE::GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM(pedVeh)) {
				int r, g, b;
				VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(pedVeh, &r, &g, &b);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(playerVeh, r, g, b);
			}
			if (IS_THIS_MODEL_A_CAR(vehicleModelHash) || VEHICLE::IS_THIS_MODEL_A_BIKE(vehicleModelHash)) {
				VEHICLE::SET_VEHICLE_MOD_KIT(playerVeh, 0);
				VEHICLE::SET_VEHICLE_WHEEL_TYPE(playerVeh, VEHICLE::GET_VEHICLE_WHEEL_TYPE(pedVeh));
				for (int i = 0; i <= 24; i++) {
					if (i > 16 && i < 23)
						VEHICLE::TOGGLE_VEHICLE_MOD(playerVeh, i, VEHICLE::IS_TOGGLE_MOD_ON(pedVeh, i));
					else
						VEHICLE::SET_VEHICLE_MOD(playerVeh, i, VEHICLE::GET_VEHICLE_MOD(pedVeh, i), VEHICLE::GET_VEHICLE_MOD_VARIATION(pedVeh, i));
				}
				int tireSmokeColor[3], pearlescentColor, wheelColor;
				VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR(pedVeh, &tireSmokeColor[0], &tireSmokeColor[1], &tireSmokeColor[2]);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(playerVeh, tireSmokeColor[0], tireSmokeColor[1], tireSmokeColor[2]);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(playerVeh, GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(pedVeh));
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(playerVeh, GET_VEHICLE_NUMBER_PLATE_TEXT(pedVeh));
				VEHICLE::GET_VEHICLE_EXTRA_COLOURS(pedVeh, &pearlescentColor, &wheelColor);
				VEHICLE::SET_VEHICLE_EXTRA_COLOURS(playerVeh, pearlescentColor, wheelColor);
				if (VEHICLE::IS_VEHICLE_A_CONVERTIBLE(pedVeh, 0)) {
					int convertableState = VEHICLE::GET_CONVERTIBLE_ROOF_STATE(pedVeh);
					if (convertableState == 0 || convertableState == 3 || convertableState == 5)
						VEHICLE::RAISE_CONVERTIBLE_ROOF(playerVeh, 1);
					else
						VEHICLE::LOWER_CONVERTIBLE_ROOF(playerVeh, 1);
				}
				for (int i = 0; i <= 3; i++) {
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(playerVeh, i, VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(pedVeh, i));
				}
				for (int i = 0; i <= 11; i++) {
					if (DOES_EXTRA_EXIST(pedVeh, i))
						VEHICLE::SET_VEHICLE_EXTRA(playerVeh, i, !VEHICLE::IS_VEHICLE_EXTRA_TURNED_ON(pedVeh, i));
				}
				if ((VEHICLE::GET_VEHICLE_LIVERY_COUNT(pedVeh) > 1) && VEHICLE::GET_VEHICLE_LIVERY(pedVeh) >= 0) {
					VEHICLE::SET_VEHICLE_LIVERY(playerVeh, VEHICLE::GET_VEHICLE_LIVERY(pedVeh));
				}
				int neonColor[3];
				VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR(pedVeh, &neonColor[0], &neonColor[1], &neonColor[2]);
				VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(playerVeh, neonColor[0], neonColor[1], neonColor[2]);
				VEHICLE::SET_VEHICLE_WINDOW_TINT(playerVeh, VEHICLE::GET_VEHICLE_WINDOW_TINT(pedVeh));
				VEHICLE::SET_VEHICLE_DIRT_LEVEL(playerVeh, VEHICLE::GET_VEHICLE_DIRT_LEVEL(pedVeh));
				//SET_VEHICLE_ENGINE_ON(playerVeh, TRUE, TRUE);
			}
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(vehicleModelHash);
		}
		else {
			string msg = " is not in a vehicle";
			game::notifyError(PLAYER::GET_PLAYER_NAME(toClone) + msg);
		}
		return pedVeh;
	}
	void vehRandom() {
		Hash randomVehicle;
		int unk;
		GET_RANDOM_VEHICLE_MODEL_IN_MEMORY(1, &randomVehicle, &unk);
		vehicle::spawn(randomVehicle, PLAYER_PED_ID());
	}
	void openDoors(Vehicle vehicle) {
		for (int i = 0; i < 10; i++)
			SET_VEHICLE_DOOR_OPEN(vehicle, i, 0, 1);
	}
	void closeDoors(Vehicle vehicle) {
		for (int i = 0; i < 10; i++)
			SET_VEHICLE_DOOR_SHUT(vehicle, i, 0);
	}
	void lockDoors(Vehicle vehicle) {
		for (int i = 0; i < 10; i++)
			SET_VEHICLE_DOORS_LOCKED(vehicle, i);
	}
	void removeOwnership(Vehicle vehicle) {
		if (!ENTITY::DOES_ENTITY_EXIST(vehicle)) {
			game::notifyError("Could not remove ownership. Vehicle does not exist.");
			return;
		}

		if (DECOR_EXIST_ON(vehicle, "Player_Vehicle"))
		{
			DECOR_REMOVE(vehicle, "Player_Vehicle");
			game::notifyBottom("~g~Removed Players Ownership Of Vehicle");
		}
		else
			game::notifyError("Player Does Not Own This Vehicle");
	}
	void setPlate(Vehicle vehicle) {
		if (IS_PED_IN_ANY_VEHICLE(game::GET_PLAYER_PED(PLAYER_ID()), 1))
		{
			string plateTemp = show_keyboard("Numberplate Text", GET_VEHICLE_NUMBER_PLATE_TEXT(vehicle));
			if (plateTemp == "")
			{
				game::notifyError("Cannot be blank");
			}
			else
			{
				RequestControlOfEnt(vehicle);
				while (!NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
				{
					WAIT(0);
				}
				SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, GET_ONSCREEN_KEYBOARD_RESULT());
			}
		}
		else
		{
			game::notifyError("Player not in vehicle");
		}
	}
	void manualSelect() {
		Ped playerPed = PLAYER_PED_ID();
		string tempmodel = show_keyboard("Vehicle Model", "");
		if (tempmodel == "")
		{
			game::notifyError("Cannot be blank");
		}
		else
		{
			if (GET_ONSCREEN_KEYBOARD_RESULT() != "")
			{
				char *vehModel = GET_ONSCREEN_KEYBOARD_RESULT();
				if (IS_MODEL_VALID($(GET_ONSCREEN_KEYBOARD_RESULT())))//tempmodel.c_str;
					vehicle::spawn(vehModel, playerPed);
				else
					game::notifyError("Vehicle is invalid");
			}
			else
			{
				game::notifyError("Cannot be blank");
			}
		}
	}


	void changeSeat(Vehicle vehicle, Ped playerPed)
	{
		if (IS_PED_IN_ANY_VEHICLE(playerPed, 1))
		{
			if (ARE_ANY_VEHICLE_SEATS_FREE(vehicle))
			{
				GET_VEHICLE_MODEL_NUMBER_OF_SEATS(vehicle);
			}
		}
	}
	void disableSiren(Vehicle vehicle)
	{
		//SIREN
	}
	void driveWaypoint() {
		Vector3 wpcoords;
		int driver = PLAYER_PED_ID();
		int waypoint = GET_FIRST_BLIP_INFO_ID(8);
		if (DOES_BLIP_EXIST(waypoint)) {
			wpcoords = GET_BLIP_COORDS(waypoint);
			if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0)) {
				Vehicle vehicle = GET_VEHICLE_PED_IS_IN(driver, 0);
				int model = GET_ENTITY_MODEL(vehicle);
				TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(driver, vehicle, wpcoords.x, wpcoords.y, wpcoords.z, 45.0f, 1, 20);
				game::notifyBottom("~g~Alert: ~w~Driving you to waypoint.");
			}
			else
				game::notifyError("You are not in a vehicle.");
		}
		else
			game::notifyError("No waypoint has been set.");
	}
	void breakDoors(bool deleteDoors, Player player = PLAYER_ID()) {
		Ped playerPed = game::GET_PLAYER_PED(player);
		if (IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			Vehicle veh = GET_VEHICLE_PED_IS_IN(playerPed, 0);
			RequestControlOfEnt(veh);
			while (!NETWORK_HAS_CONTROL_OF_ENTITY(veh))
				WAIT(0);
			for (int i = 0; i < 10; i++)
				SET_VEHICLE_DOOR_BROKEN((veh), i, deleteDoors);
		}
		else
			game::notifyError("You are not in a vehicle.");
	}
	void setIndicators(Vehicle vehicle, bool left, bool both) {
		//1 is left, 0 is right
		if (!both) {
			bool toggle = true;
			SET_VEHICLE_INDICATOR_LIGHTS(vehicle, left, toggle);
			SET_VEHICLE_INDICATOR_LIGHTS(vehicle, !left, !toggle);
		}
	}
	void unlockBias(Ped p, float bias) {
		if (IS_PED_IN_ANY_VEHICLE(p, 0)) {
			Vehicle vehicle = GET_VEHICLE_PED_IS_USING(p);
			STEER_UNLOCK_BIAS(vehicle, 1);
			SET_VEHICLE_STEER_BIAS(vehicle, bias);
		}
		else
			game::notifyError("You are not in a vehicle");
	}
	void removeTopSpeed(Vehicle vehicle, BOOL &toggle) {
		if (!toggle) {
			SET_ENTITY_MAX_SPEED(vehicle, 10000.f);
			toggle = true;
		}
		else {
			SET_ENTITY_MAX_SPEED(vehicle, 335.f);
			toggle = false;
		}
	}
	void loop_vehAirRide(Vehicle lastVeh)
	{
		float speed = GET_ENTITY_SPEED(lastVeh);
		float MetersPerHour = (speed * 3600);
		float MilesPerHour = (MetersPerHour / 1609.344f);
		int MilesPerHourInt = floorf(MilesPerHour);
		bool manInflate;
		//int vehAirint = vehAirHeight * 100;
		if (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RDOWN))
			manInflate = true;
		else
			manInflate = false;

		if (manInflate)
		{
			if (vehAirHeight < 0.f)
			{
				float vehAirDyn = vehAirHeight + 0.001f;
				vehAirHeight = vehAirDyn;
				APPLY_FORCE_TO_ENTITY(lastVeh, true, 0, 0, vehAirHeight, 0, 0, 0, true, true, true, true, false, true);
			}
		}

		if (MilesPerHourInt < 6 && IS_VEHICLE_ON_ALL_WHEELS(lastVeh) && !manInflate)
		{
			if (vehAirHeight > vehAirLimit)
			{
				float vehAirDyn = vehAirHeight - 0.001f;
				vehAirHeight = vehAirDyn;
				APPLY_FORCE_TO_ENTITY(lastVeh, true, 0, 0, vehAirHeight, 0, 0, 0, true, true, true, true, false, true);
			}
			else
			{
				APPLY_FORCE_TO_ENTITY(lastVeh, true, 0, 0, vehAirLimit, 0, 0, 0, true, true, true, true, false, true);
			}
		}

		if (MilesPerHourInt > 6 && IS_VEHICLE_ON_ALL_WHEELS(lastVeh))
		{
			if (vehAirHeight < 0.f)
			{
				float vehAirDyn = vehAirHeight + 0.001f;
				vehAirHeight = vehAirDyn;
				APPLY_FORCE_TO_ENTITY(lastVeh, true, 0, 0, vehAirHeight, 0, 0, 0, true, true, true, true, false, true);
			}
		}
	}
	void loop_driveOnWater() {
		Ped playerPed = PLAYER_PED_ID();
		Vehicle veh = GET_VEHICLE_PED_IS_IN(playerPed, 0);
		DWORD model = GET_ENTITY_MODEL(veh);
		Vector3 pos = GET_ENTITY_COORDS(playerPed, 0);
		float height = 0;
		if (!(IS_THIS_MODEL_A_PLANE(model) || IS_THIS_MODEL_A_BOAT(model) || IS_THIS_MODEL_A_HELI(model)) && GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
			Object container = GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
			if (DOES_ENTITY_EXIST(container) && height > -50.0f) {
				Vector3 pRot = GET_ENTITY_ROTATION(playerPed, 0);
				if (IS_PED_IN_ANY_VEHICLE(playerPed, 1)) pRot = GET_ENTITY_ROTATION(veh, 0);
				RequestControlOfEnt(container);
				SET_ENTITY_COORDS(container, pos.x, pos.y, height - 1.5f, 0, 0, 0, 1);
				SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
				Vector3 containerCoords = GET_ENTITY_COORDS(container, 1);
				if (pos.z < containerCoords.z) {
					if (!IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
						SET_ENTITY_COORDS(playerPed, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
					}
					else {
						RequestControlOfEnt(veh);
						Vector3 vehc = GET_ENTITY_COORDS(veh, 1);
						SET_ENTITY_COORDS(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
					}
				}
			}
			else {
				Hash model = GET_HASH_KEY("prop_container_ld2");
				REQUEST_MODEL(model);
				while (!HAS_MODEL_LOADED(model)) WAIT(0);
				container = CREATE_OBJECT(model, pos.x, pos.y, pos.z, 1, 1, 0);
				RequestControlOfEnt(container);
				FREEZE_ENTITY_POSITION(container, 1);
				SET_ENTITY_ALPHA(container, 0, 1);
				SET_ENTITY_VISIBLE(container, 0, 0);
			}
		}
		else {
			Object container = GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
			if (DOES_ENTITY_EXIST(container)) {
				RequestControlOfEnt(container);
				SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
				WAIT(10);
				SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
				DELETE_ENTITY(&container);
			}
		}
	}
	void loop_ejectorSeat()
	{
		if (GetAsyncKeyState(VK_KEY_R) || (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RB) && IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RUP)))
		{
			Ped playerPed = PLAYER_PED_ID();
			Vehicle vehicle = GET_VEHICLE_PED_IS_IN(playerPed, 0);
			Vector3 speed = GET_ENTITY_VELOCITY(vehicle);
			//Vector3 seatLoc = GET_ENTITY_COORDS(vehicle, 1);
			CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
			SET_VEHICLE_OUT_OF_CONTROL(vehicle, 0, 1);
			SET_ENTITY_INVINCIBLE(vehicle, 0);
			WAIT(10);
			SET_HIGH_FALL_TASK(playerPed, 3500, 0, 0);
			SET_ENTITY_VELOCITY(playerPed, speed.x, speed.y, max(-5, speed.z));
			APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(playerPed, 1, 0., 0.f, (10.f + speed.z) * ejectForce, 0, 1, 1, 0);
		}
		else
			return;
	}
	void loop_chr0m3Speedo(bool engineState, bool dayNite, bool wheelState, int speedoPos) {
		bool damaged, dark, lightsOn;
		RGBA engineLight, speedoCols;
		RGBA wheelCols[8];
		Vehicle veh = -1;
		float speedoPosX, speedoPosY;
		char* needleTex, *gaugeTex;
		/*
		<stat Name="DIST_CAR"                     Type="float"  SaveCategory="1"   online="true"  profile="true"    Owner="coder"   characterStat="true"  Comment="Total Distance in a car" />
		<stat Name="DIST_DRIVING_CAR"             Type="float"  SaveCategory="1"   online="true"  profile="false"   Owner="coder"   characterStat="true"  Comment="Total Distance driving a car" />
		*/
		float distanceFloat;// = recovery::GET_STAT_f("MPPLY_DIST_DRIVING_CAR");
		veh = GET_VEHICLE_PED_IS_IN(PLAYER_PED_ID(), 0);
		float speed = game::calcSpeed(true, veh);
		if (speed < 2.f)
			speed = 2.f;
		float needleRot = speed * 210.f / 140.f;//*circle max*//* + 0.655f arrow initial rotation*/
												/** 2.51f as miles * 1.6f /*as kilometers*/
		stringstream oss;
		oss << round(speed);
		if (wheelState) {
			for (int i = 0; i > 8; i++) {
				if (i == (WHEEL_RR || WHEEL_LR || WHEEL_LF || WHEEL_RF)) {
					if (IS_VEHICLE_TYRE_BURST(veh, i, 0))
						wheelCols[i] = { 249, 195, 29, 225 };
					else if (IS_VEHICLE_TYRE_BURST(veh, i, 1))
						wheelCols[i] = { 240, 38, 23, 225 };
					else
						wheelCols[i] = { 9, 179, 9, 225 };
				}
			}
		}
		if (engineState) {
			int engineHealth = floorf(GET_VEHICLE_ENGINE_HEALTH(veh));
			if (engineHealth > 500) {
				engineLight = { 20, 20, 20, 150 };
				damaged = 0;
			}
			else if ((engineHealth < 500) && (engineHealth > 0)) {
				engineLight = { 249, 195, 29, 225 };
				damaged = 1;
			}
			else {
				engineLight = { 240, 38, 23, 225 };
				damaged = 1;
			}
		}
		if (dayNite) {
			bool unk;
			GET_VEHICLE_LIGHTS_STATE(veh, &lightsOn, &unk);
			if (!GET_IS_VEHICLE_ENGINE_RUNNING(veh)) {
				dark = false;
				speedoCols = { 20, 20, 20, 150 };
				needleTex = "needleDay";
				gaugeTex = "gaugeDay";
			}
			else {
				if (GET_CLOCK_HOURS() > 19 || GET_CLOCK_HOURS() < 7) {
					dark = true;
					speedoCols = { 255, 255, 255, 225 };
					needleTex = "needleNight";
					gaugeTex = "gaugeNight";
				}
				else if (GET_CLOCK_HOURS() < 7) {
					dark = true;
					speedoCols = { 255, 255, 255, 225 };
					needleTex = "needleNight";
					gaugeTex = "gaugeNight";
				}
				else {
					dark = false;
					speedoCols = { 190, 190, 210, 225 };
					needleTex = "needleDay";
					gaugeTex = "gaugeDay";
				}
			}
		}
		switch (speedoPos) {
		case 1: speedoPosX = 0.12f; speedoPosY = 0.2f; break;
		case 2: speedoPosX = 0.88f; speedoPosY = 0.8f; break;
		default: break;
		}
		game::DrawSprite("LuxxSpeedo", gaugeTex, speedoPosX, speedoPosY, speedoSizeX, speedoSizeY, 0.0f, speedoCols.R, speedoCols.G, speedoCols.B, speedoCols.A);
		game::DrawSprite("LuxxSpeedo", needleTex, speedoPosX, speedoPosY, speedoSizeX, speedoSizeY, needleRot, speedoCols.R, speedoCols.G, speedoCols.B, speedoCols.A);
		if (engineState)
			game::DrawSprite("LuxxSpeedo", "engineLight", speedoPosX, speedoPosY, speedoSizeX, speedoSizeY, 0.0f, engineLight.R, engineLight.G, engineLight.B, engineLight.A);
		if (wheelState) {
			game::DrawSprite("LuxxSpeedo", "wheelBody", speedoPosX, speedoPosY, speedoSizeX, speedoSizeY, 0.0f, 200, 200, 200, 225);
			game::DrawSprite("LuxxSpeedo", "wheelFL", speedoPosX, speedoPosY, speedoSizeX, speedoSizeY, 0.0f, wheelCols[WHEEL_LF].R, wheelCols[WHEEL_LF].G, wheelCols[WHEEL_LF].B, wheelCols[WHEEL_LF].A);
			game::DrawSprite("LuxxSpeedo", "wheelFR", speedoPosX, speedoPosY, speedoSizeX, speedoSizeY, 0.0f, wheelCols[WHEEL_RF].R, wheelCols[WHEEL_RF].G, wheelCols[WHEEL_RF].B, wheelCols[WHEEL_RF].A);
			game::DrawSprite("LuxxSpeedo", "wheelRL", speedoPosX, speedoPosY, speedoSizeX, speedoSizeY, 0.0f, wheelCols[WHEEL_LR].R, wheelCols[WHEEL_LR].G, wheelCols[WHEEL_LR].B, wheelCols[WHEEL_LR].A);
			game::DrawSprite("LuxxSpeedo", "wheelRR", speedoPosX, speedoPosY, speedoSizeX, speedoSizeY, 0.0f, wheelCols[WHEEL_RR].R, wheelCols[WHEEL_RR].G, wheelCols[WHEEL_RR].B, wheelCols[WHEEL_RR].A);
		}
		/*	case 2: {
		drawText((char*)oss.str().c_str(), 5, speedoPosX, speedoPosY, 0.80000000, 0.80000000, 0, 255, 0, 255, 0);
		if (speed < 120)
		drawText((char*)oss.str().c_str(), 5, speedoPosX, speedoPosY, 0.80000000, 0.80000000, 0, 255, 0, 255, 0);
		if (speed > 120)
		drawText((char*)oss.str().c_str(), 5, speedoPosX, speedoPosY, 0.80000000, 0.80000000, 255, 255, 0, 255, 0);
		if (speed > 180)
		drawText((char*)oss.str().c_str(), 5, speedoPosX, speedoPosY, 0.80000000, 0.80000000, 255, 165, 0, 255, 0);
		if (speed > 240)
		drawText((char*)oss.str().c_str(), 5, speedoPosX, speedoPosY, 0.80000000, 0.80000000, 255, 0, 0, 255, 0);
		game::DrawSprite("mpmissmarkers256", "custom_icon", 0.12f, 0.2f, 0.2f, 0.3f, 0.0f, 0, 0, 255, 225);
		if (speed > 293)
		game::DrawSprite("mpmissmarkers256", "tennis_icon", 0.12f, 0.2f, 0.2f, 0.3f, 294, 0, 255, 0, 255);
		else
		game::DrawSprite("mpmissmarkers256", "tennis_icon", 0.12f, 0.2f, 0.2f, 0.3f, speed, 255, 0, 0, 255);
		break;
		}
		case 3: {
		drawText((char*)oss.str().c_str(), 0.1, 0.27000000, 0, 77, 33, 225, 0.50000000, 0.50000000, 0, 5);
		game::DrawSprite("mpmissmarkers256", "basejump_icon", 0.12f, 0.2f, 0.2f, 0.3f, 0.0f, 255, 255, 255, 225);
		if (speed > 293)
		game::DrawSprite("mpmissmarkers256", "deathmatch_marker_256", 0.12f, 0.2f, 0.2f, 0.3f, 294 - 89, 255, 255, 255, 255);
		else
		game::DrawSprite("mpmissmarkers256", "deathmatch_marker_256", 0.12f, 0.2f, 0.2f, 0.3f, speed - 89, 255, 255, 255, 255);
		break;
		}
		case 4: {
		if (!dark) {
		game::DrawSprite("mpmissmarkers256", "vehicledeathmatch_icon", 0.12f, 0.2f, 0.35f, 0.45f, 0.0f, 255, 255, 255, 225);
		if (damaged)
		game::DrawSprite("mpmissmarkers256", "gangattack_icon", 0.12f, 0.2f, 0.35f, 0.45f, 0.0f, 255, 255, 255, 225);
		if (speed > 250)
		game::DrawSprite("mpmissmarkers256", "darts_icon", 0.12f, 0.2f, 0.35f, 0.45f, 251 - 65, 255, 255, 255, 255);
		else
		game::DrawSprite("mpmissmarkers256", "darts_icon", 0.12f, 0.2f, 0.35f, 0.45f, speed - 65, 255, 255, 255, 255);
		}
		else if (dark) {
		game::DrawSprite("mpmissmarkers256", "bike_race_icon", 0.12f, 0.2f, 0.35f, 0.45f, 0.0f, 255, 255, 255, 225);
		if (damaged)
		game::DrawSprite("mpmissmarkers256", "gangattack_icon", 0.12f, 0.2f, 0.35f, 0.45f, 0.0f, 255, 255, 255, 225);
		if (speed > 250)
		game::DrawSprite("mpmissmarkers256", "corona_point", 0.12f, 0.2f, 0.35f, 0.45f, 251 - 65, 255, 255, 255, 255);
		else
		game::DrawSprite("mpmissmarkers256", "corona_point", 0.12f, 0.2f, 0.35f, 0.45f, speed - 65, 255, 255, 255, 255);
		}
		break;
		}*/
	}
}

namespace misc {

	float GET_STAT(char *stat) {
		if (_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY") {
			float stat_get;
			STAT_GET_FLOAT($(stat), &stat_get, 1);
			return stat_get;
		}
		else {
			char sbuf[50];
			int stat_r;
			STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
			snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
			float stat_get;
			STAT_GET_FLOAT($(sbuf), &stat_get, 1);
			return stat_get;
		}
	}
	void allCheevos()
	{
		for (int i = 0; i > 100; i++) {
			if (!HAS_ACHIEVEMENT_BEEN_PASSED(i))
				GIVE_ACHIEVEMENT_TO_PLAYER(i);
			if (i == 100)
			{
				game::notifyBottom("~g~All Achievements Given");	break;
			}
		}
	}
	void moveMe(float x, float y, float z)
	{
		if (!(IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0)))
		{
			SET_ENTITY_COORDS(PLAYER_PED_ID(), x, y, z, 1, 0, 0, 1);
			LOAD_ALL_OBJECTS_NOW();
		}
		else
		{
			Vehicle playerVeh = (GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()));
			RequestControlOfEnt(playerVeh);
			SET_ENTITY_COORDS(playerVeh, x, y, z, 1, 0, 0, 1);
			LOAD_ALL_OBJECTS_NOW();
		}

	}
	void sample_createEscort(char *drivername, char *vehiclename)
	{
		if (!IS_WAYPOINT_ACTIVE())
			game::notifyError("No Waypoint Set");
		else
		{
			float Pos[3];
			Vector3 Coord = GET_BLIP_COORDS(GET_FIRST_BLIP_INFO_ID(_GET_BLIP_INFO_ID_ITERATOR()));
			GET_GROUND_Z_FOR_3D_COORD(Coord.x, Coord.y, Coord.z, &Coord.z, 1);
			VectorToFloat(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER_PED_ID(), 0.0f, 5.0f, 1.0f), Pos);
			WAIT(10);
			int tempPed = CREATE_PED(1, $(drivername), Pos[0], Pos[1], Pos[2], 0.0f, 1, 1);	//CREATE_PED(1, $("A_C_CHIMP"), Pos[0], Pos[1], Pos[2], 0.0f, 1, 1);
			int tempVehicle = vehicle::spawn(vehiclename, PLAYER_PED_ID());
			//($(vehiclename), Pos[0], Pos[1], Pos[2] + 2.0f, GET_ENTITY_HEADING(PLAYER_PED_ID()), 1, 1);
			RequestControlOfEnt(tempVehicle);
			SET_VEHICLE_COLOURS(tempVehicle, 0, 0);
			SET_VEHICLE_NUMBER_PLATE_TEXT(tempVehicle, "opvl");
			for (int i = -1; i <= 20; i++)
			{
				if (!IS_VEHICLE_SEAT_FREE(tempVehicle, i)) continue;
				TASK_WARP_PED_INTO_VEHICLE(PLAYER_PED_ID(), tempVehicle, i); break;
			}
			TASK_VEHICLE_MISSION_COORS_TARGET(tempPed, tempVehicle, Coord.x, Coord.y, Coord.z, 4, 20, 786469, 20.0f, 10.0f, 1);
		}
	}
	void opal_mode(int vehicle)
	{
		/*
		bannerRectRed = 225;
		bannerRectGreen = 96;
		bannerRectBlue = 150;
		bannerRectOpacity = 255;
		backgroundRed = 219;
		backgroundGreen = 212;
		backgroundBlue = 211;
		backgroundOpacity = 255;
		scrollerRed = 225;
		scrollerGreen = 96;
		scrollerBlue = 150;
		scrollerOpacity = 255;
		bannerTextRed = 219;
		bannerTextGreen = 212;
		bannerTextBlue = 211;
		bannerTextOpacity = 255;
		bannerTextFont = 2;
		optionsRed = 219;
		optionsGreen = 212;
		optionsBlue = 211;
		optionsOpacity = 255;
		optionsFont = 0;
		indicatorRed = 225;
		indicatorGreen = 96;
		indicatorBlue = 150;
		indicatorOpacity = 255;
		*/
		//theme_opvl();
		//rainbowBody = false;
		//rainbowFade = true;
		_SET_VEHICLE_NEON_LIGHTS_COLOUR((GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())), 225, 96, 150);
		SET_VEHICLE_CUSTOM_PRIMARY_COLOUR((GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())), 225, 96, 150);
		SET_VEHICLE_CUSTOM_SECONDARY_COLOUR((GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())), 225, 225, 225);
		SET_VEHICLE_EXTRA_COLOURS((GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())), 1, 1);
		SET_VEHICLE_TYRE_SMOKE_COLOR((GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID())), 225, 96, 150);
		game::notifyBottom("~q~OOOOOOOOOH SHIET YOU 'GON DUN IT NAW");
	}
	bool CompareMemory(const uint8_t* pData, const uint8_t* bMask, const char* sMask)
	{
		for (; *sMask; ++sMask, ++pData, ++bMask)
			if (*sMask == 'x' && *pData != *bMask)
				return false;

		return *sMask == NULL;
	}
	intptr_t FindPattern(const char* bMask, const char* sMask)
	{
		// Game Base & Size
		static intptr_t pGameBase = (intptr_t)GetModuleHandle(nullptr);
		static uint32_t pGameSize = 0;
		if (!pGameSize)
		{
			MODULEINFO info;
			GetModuleInformation(GetCurrentProcess(), (HMODULE)pGameBase, &info, sizeof(MODULEINFO));
			pGameSize = info.SizeOfImage;
		}

		// Scan
		for (uint32_t i = 0; i < pGameSize; i++)
			if (CompareMemory((uint8_t*)(pGameBase + i), (uint8_t*)bMask, sMask))
				return pGameBase + i;

		return 0;
	}
	void EnableTracks(bool tracksVehicle = false, bool tracksPeds = false, bool deepTracksVehicle = false, bool deepTracksPed = false)
	{
		static auto VAR_FeetSnowTracks_call = FindPattern("\x80\x3D\x00\x00\x00\x00\x00\x48\x8B\xD9\x74\x37", "xx?????xxxxx");
		if (!VAR_FeetSnowTracks_call)
		{
			return;
		}
		static auto VAR_FeetSnowTracks = VAR_FeetSnowTracks_call + (*(int32_t *)(VAR_FeetSnowTracks_call + 2)) + 7;
		//
		static auto VAR_VehicleSnowTracks_call = FindPattern("\x40\x38\x3D\x00\x00\x00\x00\x48\x8B\x42\x20", "xxx????xxxx");
		if (!VAR_VehicleSnowTracks_call)
		{
			return;
		}
		static auto VAR_VehicleSnowTracks = VAR_VehicleSnowTracks_call + (*(int32_t *)(VAR_VehicleSnowTracks_call + 3)) + 7;
		//

		VirtualProtect((void*)VAR_FeetSnowTracks, 1, PAGE_EXECUTE_READWRITE, nullptr);
		VirtualProtect((void*)VAR_VehicleSnowTracks, 1, PAGE_EXECUTE_READWRITE, nullptr);

		// Enable/Disable Vehicle/Foot Snow tracks
		*(uint8_t *)VAR_FeetSnowTracks = tracksVehicle;
		*(uint8_t *)VAR_VehicleSnowTracks = tracksPeds;

		// Switch for big/small tracks
		static auto vehicleTrackTypes = FindPattern("\xB9\x00\x00\x00\x00\x84\xC0\x44\x0F\x44\xF1", "x????xxxxxx");
		if (!vehicleTrackTypes)
		{
			return;
		}

		VirtualProtect((void*)vehicleTrackTypes, 1, PAGE_EXECUTE_READWRITE, nullptr);
		*(uint8_t *)(vehicleTrackTypes + 1) = deepTracksVehicle ? 0x13 : 0x14;

		static auto pedTrackTypes = FindPattern("\xB9\x00\x00\x00\x00\x84\xC0\x0F\x44\xD9\x48\x8B\x4F\x30", "x????xxxxxxxxx");
		if (!pedTrackTypes)
		{
			return;
		}
		VirtualProtect((void*)pedTrackTypes, 1, PAGE_EXECUTE_READWRITE, nullptr);
		*(uint8_t *)(pedTrackTypes + 1) = deepTracksPed ? 0x13 : 0x14;
	}
	void EnableSnow(bool bEnable)
	{
		if (bEnable)
			EnableTracks(1, 1, 1, 1);
		else
			EnableTracks();

		// Adresses
		static auto addr1 = FindPattern("\x80\x3D\x00\x00\x00\x00\x00\x74\x27\x84\xC0", "xx?????xxxx");
		static auto addr2 = FindPattern("\x44\x38\x3D\x00\x00\x00\x00\x74\x0F", "xxx????xx");

		// Outdated
		// In future the patterns might change
		if (!addr1 || !addr2)
		{
			return;
		}

		// Original Memory
		static uint8_t original1[14] = { 0 };
		static uint8_t original2[15] = { 0 };

		// Initialize
		static bool bInitialized = false;
		if (!bInitialized)
		{
			bInitialized = true;

			// Unprotect Memory
			VirtualProtect((void*)addr1, 13, PAGE_EXECUTE_READWRITE, nullptr);
			VirtualProtect((void*)addr2, 14, PAGE_EXECUTE_READWRITE, nullptr);

			// Copy original Memory
			memcpy(&original1, (void*)addr1, 13);
			memcpy(&original2, (void*)addr2, 14);
		}

		// Toggle
		if (bEnable)
		{
			// Weather
			SET_WEATHER_TYPE_NOW_PERSIST("XMAS");

			// NOP checks
			memset((void*)addr1, 0x90, 13);
			memset((void*)addr2, 0x90, 14);

			// Notification
		}
		else
		{
			// Copy original memory
			memcpy((void*)addr1, &original1, 13);
			memcpy((void*)addr2, &original2, 14);

			// Weather
			CLEAR_WEATHER_TYPE_PERSIST();
			SET_WEATHER_TYPE_NOW("CLEAR");

			// Notification
		}
	}
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
	void showStreetname()
	{
		Hash streetname;
		Hash Crossingroad;
		Vector3 playerLoc = coordsOf(PLAYER_PED_ID());
		GET_STREET_NAME_AT_COORD(playerLoc.x, playerLoc.y, playerLoc.z, &streetname, &Crossingroad);
		game::notifyBottom(GET_STREET_NAME_FROM_HASH_KEY(streetname));
		DISPLAY_AREA_NAME(1);
	}
	Object spawnObject(char* name, Vector3 pos = coordsOf(PLAYER_PED_ID())) {
		Object obj = CREATE_OBJECT($(name), pos.x, pos.y, pos.z, true, 1, 0);
		return obj;
	}
	void DLCCarsOn()
	{
		globalHandle(2593910).As<bool>() = 1;
	}
	void DLCCarsOff()
	{
		globalHandle(2593910).As<bool>() = 0;
	}
	void UnlimitedRadar()
	{
		globalHandle(2421621).At(PLAYER::PLAYER_ID(), 358).At(203).As<int>() = 1;
		globalHandle(2433082).At(69).As<int>() = NETWORK::GET_NETWORK_TIME();
	}
	void UnlimitedRadarOff()
	{
		globalHandle(2421621).At(PLAYER::PLAYER_ID(), 358).At(203).As<int>() = 0;
		globalHandle(2433082).At(69).As<int>() = NETWORK::GET_NETWORK_TIME();
	}
	void OffRadar(bool toggle)
	{
		if (toggle) {
			UnlimitedRadarOff();
			unlimitedradar = false;
		}
		else {
			UnlimitedRadar();
			unlimitedradar = true;
		}
	}
	void changeTime(int amount) {
		TIME::SET_CLOCK_TIME(GET_CLOCK_HOURS() + amount, GET_CLOCK_MINUTES(), 1);
	}
	void mobile_radio()
	{
		SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
	}
	void loop_rainbowMenu(RGBA *banner, RGBA *scroller, RGBA *other)
	{
		static int    rs = 255, gs = 0, bs = 0;
		if (rs > 0 && bs == 0)
		{
			rs--;
			gs++;
		}
		if (gs > 0 && rs == 0)
		{
			gs--;
			bs++;
		}
		if (bs > 0 && gs == 0)
		{
			rs++;
			bs--;
		}
		*(RGBA*)banner = { rs, gs, bs, 0 };
		*(RGBA*)scroller = { rs, gs, bs, 0 };
		*(RGBA*)other = { rs, gs, bs, 0 };
	}
	void hide_hud()
	{
		HIDE_HUD_AND_RADAR_THIS_FRAME();
	}
//	void change_wave_height() {
//		WATER::_SET_WAVES_INTENSITY(waveheight);
//	}
}

namespace world {

	void time_sync()
	{
		time_t now = time(0);
		tm t;
		localtime_s(&t, &now);
		NETWORK_OVERRIDE_CLOCK_TIME(t.tm_hour, t.tm_min, t.tm_sec);
		//SET_CLOCK_TIME(t.tm_hour, t.tm_min, t.tm_sec);
	}
}

namespace player {

	int timer;
	void invincibility(Entity e, bool *toggle) {
		bool lToggle = !toggle;
		*toggle = lToggle;
		ENTITY::SET_ENTITY_INVINCIBLE(e, lToggle);
		ENTITY::SET_ENTITY_PROOFS(e, lToggle, lToggle, lToggle, lToggle, lToggle, 1, 1, lToggle);
	}
	void invisibility(Entity e, bool *toggle) {
		*toggle = !ENTITY::IS_ENTITY_VISIBLE(e);
		bool lToggle = toggle;
		ENTITY::SET_ENTITY_VISIBLE(e, lToggle, 1);
		if (lToggle)
			ENTITY::RESET_ENTITY_ALPHA(e);
		else
			ENTITY::SET_ENTITY_ALPHA(e, 0, 1);
	}
	void kickVeh(Player player) {
		Ped ped = game::GET_PLAYER_PED(player);
		std::string pname = GET_PLAYER_NAME(player);
		if (IS_PED_IN_ANY_VEHICLE(ped, FALSE))
		{
			RequestControlOfEnt(ped);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(ped);
			REMOVE_WEAPON_FROM_PED(ped, 0xFBAB5776);
			game::notifyBottom("Kicked From Vehicle");
		}
		else
			game::notifyError(pname + " is not in a vehicle");
	}
	void crashClone(Player player) {
		//==========================================//
		//			CRASH ERROR CODES				//
		//											//
		//	0 = Unknown Error.						//
		//	1 = Generic Error, Crash Unsuccessful.	//
		//	2 = Player Too Close, Crash Aborted.	//
		//	3 = Luxx Staff Member.					//
		//	4 = Luxx Premium Member.				//
		//==========================================//

		Ped playerPed = PLAYER_PED_ID();
		Ped ped = game::GET_PLAYER_PED(player);
		string playerName = GET_PLAYER_NAME(player);
		string start = "~y~Crashing Player: ~w~";// in progress";
		string fail = "~r~ Unsuccessful." "\n";
		game::notifyMap(start + playerName, 0);
		const int maxPeds = 70;
		Ped peds[maxPeds];
		if (GET_DISTANCE_BETWEEN_COORDS(GET_ENTITY_COORDS(playerPed, FALSE).x, GET_ENTITY_COORDS(playerPed, FALSE).y, GET_ENTITY_COORDS(playerPed, FALSE).z, GET_ENTITY_COORDS(ped, FALSE).x, GET_ENTITY_COORDS(ped, FALSE).y, GET_ENTITY_COORDS(ped, FALSE).z, FALSE) > 250.0f)
		{
			game::notifyMap("~y~Attempting Crash", 0);
			for (int i = 0; i < maxPeds; i++)
			{
				peds[i] = CLONE_PED(ped, GET_ENTITY_HEADING(PLAYER_PED_ID()), 1, 1);
				WAIT(0);
				ATTACH_ENTITY_TO_ENTITY(peds[i], ped, GET_PED_BONE_INDEX(ped, 0x796e), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE, FALSE, FALSE, FALSE, 2, TRUE);
				WAIT(0);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(ped);
				WAIT(0);
			}
			for (int i = 0; i < maxPeds; i++)
			{
				RequestControlOfEnt(peds[i]);
				WAIT(0);
				DELETE_PED(&peds[i]);
				WAIT(0);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(ped);
				WAIT(0);
				SET_PED_AS_NO_LONGER_NEEDED(&peds[i]);
			}
		}
		else
		{
			game::notifyMap(start + playerName + fail, 0);
			game::notifyError(playerName + " too close");
		}
		return;
	}
	void ragdoll(Ped ped, Player ID, Entity entity) {
		RequestControlOfEnt(ped);
		SET_PED_CAN_RAGDOLL(ped, true);
		SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(ped, true);
		//SET_PLAYER_INVINCIBLE(ped, true);
		SET_ENTITY_INVINCIBLE(entity, true);
		SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(ped, true);
		GIVE_PLAYER_RAGDOLL_CONTROL(ID, true);
		SET_PED_RAGDOLL_ON_COLLISION(ped, true);
	}
	void sendText(Player p, std::string msg) {
		if (strlen(&msg[0u]) < 60) {
			int handle;
			NETWORK::NETWORK_HANDLE_FROM_PLAYER(p, &handle, 13);
			NETWORK::NETWORK_SEND_TEXT_MESSAGE(&msg[0u], &handle);
		}
		else
			game::notifyError("Message Too Long");
	}
	/*void tpInVehicle(Vehicle veh, Player p, bool hijack = false) {
	Ped playerPed = GET_PLAYER_PED(p);
	Vector3 pCoords = GET_ENTITY_COORDS(playerPed, 0);
	moveMe(pCoords.x, pCoords.y, pCoords.z);
	SET_ENTITY_HEADING(veh, GET_ENTITY_HEADING(PLAYER_PED_ID()));
	if (hijack) {
	RequestControlOfEnt(veh);
	SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, 0);
	}
	else {
	RequestControlOfEnt(veh);
	SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, -1);
	}
	}
	void teleport2player(Ped destinationPed, Player selectedPlayer)
	{
	Ped selectedPed = game::GET_PLAYER_PED(selectedPlayer);
	Vector3 destloc = coordsOf(destinationPed);
	if (IS_PED_IN_ANY_VEHICLE(selectedPed, 0)) {
	Vehicle veh = GET_VEHICLE_PED_IS_IN(selectedPed, 0);
	RequestControlOfEnt(veh);
	if (NETWORK_HAS_CONTROL_OF_ENTITY(veh))
	SET_ENTITY_COORDS_NO_OFFSET(veh, destloc.x, destloc.y, destloc.z, 0, 0, 0);
	}
	else if (IS_PED_IN_ANY_VEHICLE(destinationPed, 0))
	{
	RequestControlOfEnt(selectedPed);
	if (NETWORK_HAS_CONTROL_OF_ENTITY(selectedPed))
	SET_ENTITY_COORDS(selectedPed, destloc.x, destloc.y, destloc.z, 1, 0, 0, 1);
	PED::SET_PED_INTO_VEHICLE(selectedPed, GET_VEHICLE_PED_IS_IN(destinationPed, 0), -1);
	}
	} */
	void ragdollToggle(Player player) // keyup0
	{
		Ped playerPed = game::GET_PLAYER_PED(player);
		SET_PED_CAN_RAGDOLL(playerPed, true);
		RESET_PED_RAGDOLL_TIMER(playerPed);
		{
			if (LifelessRagdoll)
			{
				SET_PED_TO_RAGDOLL(playerPed, 100, 100, 0, 1, 1, 1);
			}
			else
			{
				SET_PED_TO_RAGDOLL(playerPed, 100, 100, 100, 1, 1, 1);
			}
		}
	}
	void loopRagdoll()
	{
		SET_PED_CAN_RAGDOLL(PLAYER_PED_ID(), true);
		RESET_PED_RAGDOLL_TIMER(PLAYER_PED_ID());
		{
			if (LifelessRagdoll)
			{
				SET_PED_TO_RAGDOLL(PLAYER_PED_ID(), 100, 100, 0, 1, 1, 1);
			}
			else
			{
				SET_PED_TO_RAGDOLL(PLAYER_PED_ID(), 100, 100, 100, 1, 1, 1);
			}
		}
	}
	void ragdollSwitch()
	{
		if (ragdolltoggle)
		{
			if (ragdollDelay < GET_FRAME_COUNT())
			{
				ragdollDelay = GET_FRAME_COUNT() + 60;
				ragdollActive = !ragdollActive;
			}
		}
		else
			loopRagdoll();
	}
	void teleportToPlayer(Player destination)
	{
		Ped destPed = game::GET_PLAYER_PED(destination);

		if (IS_PED_IN_ANY_VEHICLE(destPed, 0))
		{
			Vector3 location = coordsOf(GET_VEHICLE_PED_IS_IN(destPed, 0));
			if (ARE_ANY_VEHICLE_SEATS_FREE(GET_VEHICLE_PED_IS_IN(destPed, 0)) && toVehicle)
			{
				SET_ENTITY_COORDS(PLAYER_PED_ID(), location.x, location.y, location.z + 5.f, 0, 0, 0, 1);
				LOAD_ALL_OBJECTS_NOW();
				RequestControlOfEnt(GET_VEHICLE_PED_IS_IN(destPed, 0));
				while (NETWORK_HAS_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_IN(destPed, 0)))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), GET_VEHICLE_PED_IS_IN(destPed, 0), -1);
				}
				if (!(GET_VEHICLE_PED_IS_IN(destPed, 0), -1) == (GET_VEHICLE_PED_IS_IN(PLAYER_PED_ID(), 0), -1))
				{
					RequestControlOfEnt(GET_VEHICLE_PED_IS_IN(destPed, 0));
					while (NETWORK_HAS_CONTROL_OF_ENTITY(GET_VEHICLE_PED_IS_IN(destPed, 0)))
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), GET_VEHICLE_PED_IS_IN(destPed, 0), -1);
					}
				}
			}
			else
			{
				if (!IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0)) {
					SET_ENTITY_COORDS(PLAYER_PED_ID(), location.x, location.y, location.z + 4.f, 0, 0, 0, 1);
					LOAD_ALL_OBJECTS_NOW();
				}
				else
				{
					SET_ENTITY_COORDS(GET_VEHICLE_PED_IS_IN(PLAYER_PED_ID(), 0), location.x, location.y, location.z + 4.f, 0, 0, 0, 0);
					LOAD_ALL_OBJECTS_NOW();
				}
			}
		}
		else
		{
			Vector3 location = coordsOf(destPed);
			if (!IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), 0)) {
				SET_ENTITY_COORDS(PLAYER_PED_ID(), location.x, location.y, location.z + 4.f, 0, 0, 0, 1);
				LOAD_ALL_OBJECTS_NOW();
			}
			else
			{
				SET_ENTITY_COORDS(GET_VEHICLE_PED_IS_IN(PLAYER_PED_ID(), 0), location.x, location.y, location.z + 4.f, 0, 0, 0, 0);
				LOAD_ALL_OBJECTS_NOW();
			}
		}
	}
	void noRagdoll(BOOL toggle)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
		{
			PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), toggle);
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), toggle);
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), toggle);
			PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER::PLAYER_PED_ID(), true);
			PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), toggle);
		}
	}
	void AddCash() //SP ONLY
	{
		for (int i = 0; i < 3; i++)
		{
			char statNameFull[32];
			sprintf_s(statNameFull, "SP%d_TOTAL_CASH", i);
			Hash hash = $(statNameFull);
			int val;
			STAT_GET_INT(hash, &val, -1);
			val += 5000000; //Amount of cash
			STAT_SET_INT(hash, val, 1);
			game::notifyBottom("Cash has been added");
		}
	}
	void wantedUp(Player player)
	{
		Ped playerPed = PLAYER_PED_ID();
		BOOL bPlayerExists = DOES_ENTITY_EXIST(playerPed);

		if (bPlayerExists && GET_PLAYER_WANTED_LEVEL(player) < 5)
		{
			//SET_PLAYER_WANTED_LEVEL(player, GET_PLAYER_WANTED_LEVEL(player) + 1, 0);
			SET_PLAYER_WANTED_LEVEL_NOW(player, 0);
			game::notifyBottom("~r~wanted up");
		}
	}
	void wantedDown(Player player)
	{
		Ped playerPed = PLAYER_PED_ID();
		BOOL bPlayerExists = DOES_ENTITY_EXIST(playerPed);

		if (bPlayerExists && GET_PLAYER_WANTED_LEVEL(player) > 0)
		{
			//SET_PLAYER_WANTED_LEVEL(player, GET_PLAYER_WANTED_LEVEL(player) - 1, 0);
			SET_PLAYER_WANTED_LEVEL_NOW(player, 0);
			game::notifyBottom("~r~wanted down");
		}
	}
	void replenish(Ped playerPed)
	{
		CLEAR_PED_BLOOD_DAMAGE(playerPed);
		SET_ENTITY_HEALTH(playerPed, GET_ENTITY_MAX_HEALTH(playerPed));
		ADD_ARMOUR_TO_PED(playerPed, GET_PLAYER_MAX_ARMOUR(PLAYER_ID()) - GET_PED_ARMOUR(playerPed));
		if (IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			Vehicle playerVeh = GET_VEHICLE_PED_IS_USING(playerPed);
			if (DOES_ENTITY_EXIST(playerVeh) && !IS_ENTITY_DEAD(playerVeh))
				SET_VEHICLE_FIXED(playerVeh);
		}
		game::notifyBottom("Now Tumble dry for 20 mins on low heat");
	}
	static char* objects[] = { "prop_bskball_01", };
	/* "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01"
	}; */
	void removeAttached(Ped ped) {
		for (int i = 0; i < 5; i++) {
			Vector3 coords = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
			CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
			CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
			CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
			for (int i = 0; i < 136; i++) {
				Object obj = GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, $(objects[i]), 0, 0, 1);

				if (DOES_ENTITY_EXIST(obj) && IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER_PED_ID())) {
					RequestControlOfEnt(obj);
					int netID = NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
					SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
					DETACH_ENTITY(obj, 1, 1);
					if (NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
						SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
						SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
						DELETE_ENTITY(&obj);
					}
				}
			}
			//WAIT(100);
		}
	}
	void forward(Player player)
	{
		Vector3 playerfw = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(player, 0.f, 6.f, 0.f);
		misc::moveMe(playerfw.x, playerfw.y, playerfw.z);
	}
	void removeAttachd()
	{
		Ped ped = PLAYER_PED_ID();
		Vector3 playerPosition = GET_ENTITY_COORDS(ped, FALSE);
		Hash modelHashes[] = {
			0x2E28CA22 /*p_tram_crash_s*/,			0xA50DDDD0 /*prop_bball_arcade_01*/,
			0xEFC4165A /*prop_food_van_01*/,		0x8E8C7A5B /*prop_crashed_heli*/,
			0x456AA864 /*prop_dj_deck_01*/,			0xBE862050 /*prop_portacabin01*/,
			0xB20E5785 /*prop_sculpt_fix*/,			0x58D3B4EA /*prop_micro_01*/,
			0xC42C019A /*prop_ld_ferris_wheel*/,	0x8AF58425 /*prop_lev_des_barge_01*/,
			0x3DC31836 /*prop_tv_flat_01*/,			0xA9BD0D16 /*prop_coke_block_01*/,
			0x1AFA6A0A /*Prop_weed_01*/,			0x4B3D240F /*prop_wheelchair_01*/,
			0x40F52369 /*p_v_43_safe_s*/,			0xF830B63E /*prop_swiss_ball_01*/,
			0xD541462D /*p_ld_soc_ball_01*/,		0x532B1DD1 /*prop_rub_trolley01a*/,
			0x0E3BA450 /*prop_xmas_tree_int*/,		0xFB631122 /*prop_bumper_car_01*/,
			0x5571173D /*prop_beer_neon_01*/,		0x6AD326C2 /*prop_space_rifle*/,
			0x7FFBC1E2 /*prop_dummy_01*/,			0x678FC2DB /*prop_wheelchair_01_s*/,
			0x5869A8F8 /*prop_large_gold*/,			0xE6CB661E /*PROP_CS_DILDO_01*/,
			0x2AE13DFA /*prop_armchair_01*/,		0x29CB0F3C /*prop_armour_pickup*/,
			0x922C2A43 /*prop_big_shit_01*/,		0xFA686C0E /*prop_bin_04a*/,
			0x1F550C17 /*prop_chair_01a*/,			0x5B5C4263 /*prop_chip_fryer*/,
			0x39885BB5 /*prop_chickencoop_a*/,		0x16A39A90 /*prop_dog_cage_01*/,
			0xE3CE09E2 /*prop_dummy_plane*/,		0x927A5723 /*prop_fan_01*/,
			0x34D5D3FD /*prop_golf_bag_01*/,		0xB467C540 /*p_spinning_anus_s*/,
			0x745F3383 /*prop_windmill_01*/,		0x392D62AA /*prop_gold_cont_01*/,
			0x07121AC4 /*prop_xmas_ext*/,			0x0E8032E4 /*prop_weed_pallet*/,
			0xD44295DD /*p_cablecar_s*/,			0x6F9939C7 /*prop_ld_toilet_01*/,
			0x9C762726 /*prop_lev_des_barge_02*/,	0x8973A868 /*prop_air_bigradar*/,
			0xC2BC19CD /*p_cs_mp_jet_01_s*/,		0x26CF04DB /*garbage bin*/,
			0x6DB9599A /*baskedball */ };

		int removed = 0;
		for each (Hash modelHash in modelHashes)
		{
			for (int i = 0; i < 50000; i++)
			{
				Object obj = GET_CLOSEST_OBJECT_OF_TYPE(playerPosition.x, playerPosition.y, playerPosition.z, 5.0f, modelHash, TRUE, 0, 0);
				if (DOES_ENTITY_EXIST(obj))
				{
					DELETE_ENTITY(&obj);
					removed++;
				}
				else
				{
					break;
				}
			}
		}

		if (removed > 0)
		{
			game::notifyBottom("Objects have been deleted.");
		}
	}
	void resetSkin()
	{
		SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER_PED_ID());
	}
	void JDM_mode()
	{
		static Hash model = 0x5E3DA4A4;
		static Hash primaryWeapon = 0xE284C527;
		static Hash SecondaryWeapon = 0x99AEEB3B;
		Vector3 playerLoc = coordsOf(PLAYER_PED_ID());
		REQUEST_MODEL(model);
		while (!HAS_MODEL_LOADED(model))
			WAIT(0);
		SET_PLAYER_MODEL(PLAYER_ID(), model);
		Ped CompanionCop = CREATE_PED(26, model, playerLoc.x, playerLoc.y, playerLoc.z + 3.f, GET_ENTITY_HEADING(PLAYER_PED_ID()), 1, 0);
		SET_MODEL_AS_NO_LONGER_NEEDED(model);
		SET_PED_AS_COP(PLAYER_PED_ID(), 1);
		SET_PED_AS_COP(CompanionCop, 1);
		Vehicle CopCar = vehicle::spawn("police3", PLAYER_PED_ID());
		SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), CopCar, -1);
		SET_PED_INTO_VEHICLE(CompanionCop, CopCar, 0);
		SET_VEHICLE_IS_STOLEN(CopCar, 0);
		SET_VEHICLE_ENGINE_ON(CopCar, 1, 1, 1);
		GIVE_WEAPON_TO_PED(CompanionCop, primaryWeapon, primaryWeapon, 9999, 9999);
		GIVE_WEAPON_TO_PED(CompanionCop, SecondaryWeapon, SecondaryWeapon, 9999, 9999);
		SET_ENTITY_INVINCIBLE(CompanionCop, false);
		SET_PED_COMBAT_ABILITY(CompanionCop, 100);
		SET_PED_CAN_SWITCH_WEAPON(CompanionCop, true);
		SET_PED_COMBAT_RANGE(CompanionCop, 1000);
		//SET_PED_KEEP_TASK(CompanionCop, true);
		SET_PED_ALERTNESS(CompanionCop, 1000);
	}
	/*void GarbageMan()
	{
	//0xa2719263 multiplayerID
	Ped playerPed = PLAYER_PED_ID();
	Vector3 playerLoc = coordsOf(playerPed);
	static Hash propCRT = 0x42F45560;
	static Hash propBina = 0xF25FE3FD;
	static Hash propBinb = 0xE4114760;
	//static char* propCRT = "prop_crt_mon_02";
	REQUEST_MODEL(propCRT);
	while (!HAS_MODEL_LOADED(propCRT))
	WAIT(0);
	Object CreatedCRT = CREATE_OBJECT(propCRT, playerLoc.x, playerLoc.y, playerLoc.z, 1, 1, 1);
	SET_MODEL_AS_NO_LONGER_NEEDED(propCRT);
	SET_ENTITY_INVINCIBLE(CreatedCRT, 1);
	SET_ENTITY_PROOFS(CreatedCRT, 0, 1, 1, 0, 1, 0, 0, 0);
	ATTACH_ENTITY_TO_ENTITY(CreatedCRT, playerPed, SKEL_Head, crtX, crtY, crtZ, crtXrot, crtYrot, crtZrot, 0, 0, 0, 0, 0, 1);

	//SET_ENTITY_INVINCIBLE(playerPed, 1);
	//SET_ENTITY_PROOFS(playerPed, 1, 0, 1, 1, 1, 0, 0, 0);
	}*/
	void skipCutscene1()
	{
		REMOVE_CUTSCENE();
	}
	void skipCutscene2()
	{
		_RESET_LOCALPLAYER_STATE();
	}
	void skipCutscene3()
	{
		STOP_CUTSCENE_IMMEDIATELY();
	}
	void playAnimation(Ped p, char* anim, char* animID)
	{
		if (!DOES_ENTITY_EXIST(p))
			return;
		Vector3 pos = coordsOf(p);
		REQUEST_ANIM_DICT(anim);
		while (!HAS_ANIM_DICT_LOADED(anim))
			WAIT(0);

		TASK_PLAY_ANIM(p, anim, animID, 8.0f, 1.0f, 9999, 9, 0, 0, 0, 0);
	}
	void stopAnim(Ped who)
	{
		RequestControlOfEnt(who);
		while (!NETWORK_HAS_CONTROL_OF_ENTITY(who))
		{
			WAIT(0);
		}
		AI::CLEAR_PED_TASKS_IMMEDIATELY(who);
	}
	void networkDance(Ped who)
	{
		char *anim = "mini@strip_club@lap_dance_2g@ld_2g_p2";
		char *animID = "ld_2g_p2_s2";
		REQUEST_ANIM_DICT(anim);
		while (!HAS_ANIM_DICT_LOADED(anim))
			WAIT(0);
		Vector3 dest = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
		int network = NETWORK_CREATE_SYNCHRONISED_SCENE(dest.x, dest.y, dest.z, 0, 0, 0, 2, 0, 1, 1.0f, 0, 0);
		NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(who, network, anim, animID, 8.0f, -8.0f, 1, 0, 100.0f, 0);
		NETWORK_START_SYNCHRONISED_SCENE(network);
		WAIT(300);
		CLEAR_PED_TASKS_IMMEDIATELY(who);
		REMOVE_ANIM_DICT(anim);
	}
	void TeleportCoords(Ped who, float x, float y, float z)
	{
		//Vector3 dest = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
		if (!HAS_ANIM_DICT_LOADED("amb@world_human_hiker_standing@female@idle_a"))
			REQUEST_ANIM_DICT("amb@world_human_hiker_standing@female@idle_a");
		while (!HAS_ANIM_DICT_LOADED("amb@world_human_hiker_standing@female@idle_a"))
			WAIT(0);
		CLEAR_PED_TASKS_IMMEDIATELY(who);
		int network = NETWORK_CREATE_SYNCHRONISED_SCENE(x, y, z, 0, 0, 0, 2, 0, 1, 1.0f, 0, 0);
		NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(who, network, "amb@world_human_hiker_standing@female@idle_a", "idle_a", 8.0f, -8.0f, 1, 0, 100.0f, 0);
		NETWORK_START_SYNCHRONISED_SCENE(network);
		WAIT(300);
		CLEAR_PED_TASKS_IMMEDIATELY(who);
		REMOVE_ANIM_DICT("amb@world_human_hiker_standing@female@idle_a");
	}//universal online
	void netTeleport(Ped who, int destination)
	{
		//0/default = to player
		//1 = waypoint
		//2 = other player

		Vector3 dest = { 0.f, 0.f, 0.f };

		switch (destination) {
		case 0: dest = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1); break;
		case 1:	dest = get_blip_marker();
			if (dest.x == 0 && dest.y == 0)
			{
				game::notifyError("No Waypoint has been set");
				return;
			}
			break;
		}
		TeleportCoords(who, dest.x, dest.y, dest.z);
	}//universal online
}

namespace weapon {

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
		-1074790547, -2084633992,
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
	void giveguns() {
		Ped ped = PLAYER::PLAYER_PED_ID();

		for each (Hash weaponlist in weaponlist) {
			if (WEAPON::HAS_PED_GOT_WEAPON(ped, weaponlist, FALSE) == FALSE)
			{
				WEAPON::GIVE_WEAPON_TO_PED(ped, weaponlist, 9999, FALSE, TRUE);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(ped, weaponlist, WeaponTintGold);
			}
		}
	}
	enum eWeaponAddonComponents : Hash
	{
		COMPONENT_AT_SCOPE_MACRO = 0x9D2FBF29,
		COMPONENT_AT_SCOPE_MACRO_02 = 0x3CC6BA57,
		COMPONENT_AT_SCOPE_SMALL = 0xAA2C45B4,
		COMPONENT_AT_SCOPE_SMALL_02 = 0x3C00AFED,
		COMPONENT_AT_SCOPE_MEDIUM = 0xA0D89C42,
		COMPONENT_AT_SCOPE_LARGE = 0xD2443DDC,
		COMPONENT_AT_SCOPE_MAX = 0xBC54DA77,
		COMPONENT_AT_PI_SUPP = 0xC304849A,
		COMPONENT_AT_PI_SUPP_02 = 0x65EA7EBB,
		COMPONENT_AT_AR_SUPP = 0x837445AA,
		COMPONENT_AT_SR_SUPP = 0xE608B35E,
		COMPONENT_AT_RAILCOVER_01 = 0x75414F30,
		COMPONENT_AT_AR_AFGRIP = 0xC164F53,
		COMPONENT_AT_PI_FLSH = 0x359B7AAE,
		COMPONENT_AT_AR_FLSH = 0x7BC4CDDC,
		COMPONENT_AT_AR_SUPP_02 = 0xA73D4664,
		COMPONENT_PISTOL_CLIP_02 = 0xED265A1C,
		COMPONENT_COMBATPISTOL_CLIP_02 = 0xD67B4F2D,
		COMPONENT_APPISTOL_CLIP_02 = 0x249A17D5,
		COMPONENT_MICROSMG_CLIP_02 = 0x10E6BA2B,
		COMPONENT_SMG_CLIP_02 = 0x350966FB,
		COMPONENT_ASSAULTRIFLE_CLIP_02 = 0xB1214F9B,
		COMPONENT_CARBINERIFLE_CLIP_02 = 0x91109691,
		COMPONENT_ADVANCEDRIFLE_CLIP_02 = 0x8EC1C979,
		COMPONENT_MG_CLIP_02 = 0x82158B47,
		COMPONENT_COMBATPDW_CLIP_02 = 0x334A5203,
		COMPONENT_COMBATMG_CLIP_02 = 0xD6C59CD6,
		COMPONENT_ASSAULTSHOTGUN_CLIP_02 = 0x86BD7F72,
		COMPONENT_PISTOL50_CLIP_02 = 0xD9D3AC92,
		COMPONENT_ASSAULTSMG_CLIP_02 = 0xBB46E417,
		COMPONENT_SNSPISTOL_CLIP_02 = 0x7B0033B3,
		COMPONENT_HEAVYPISTOL_CLIP_02 = 0x64F9C62B,
		COMPONENT_SPECIALCARBINE_CLIP_02 = 0x7C8BD10E,
		COMPONENT_BULLPUPRIFLE_CLIP_02 = 0xB3688B0F,
		COMPONENT_VINTAGEPISTOL_CLIP_02 = 0x33BA12E8,
		COMPONENT_MARKSMANRIFLE_CLIP_02 = 0xCCFD2AC5,
		COMPONENT_HEAVYSHOTGUN_CLIP_02 = 0x971CF6FD,
		COMPONENT_GUSENBERG_CLIP_02 = 0xEAC8C270,
		COMPONENT_KNUCKLE_VARMOD_PIMP = 0xC613F685,
		COMPONENT_KNUCKLE_VARMOD_BALLAS = 0xEED9FD63,
		COMPONENT_KNUCKLE_VARMOD_DOLLAR = 0x50910C31,
		COMPONENT_KNUCKLE_VARMOD_DIAMOND = 0x9761D9DC,
		COMPONENT_KNUCKLE_VARMOD_HATE = 0x7DECFE30,
		COMPONENT_KNUCKLE_VARMOD_LOVE = 0x3F4E8AA6,
		COMPONENT_KNUCKLE_VARMOD_PLAYER = 0x08B808BB,
		COMPONENT_KNUCKLE_VARMOD_KING = 0xE28BABEF,
		COMPONENT_KNUCKLE_VARMOD_VAGOS = 0x7AF3F785
	};
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
	void upgradeguns() {
		Ped ped = PLAYER::PLAYER_PED_ID();

		for each (Hash weaponlist in weaponlist) {
			ForceWeapAddons(ped, weaponlist, 1);
		}
	}
	void replenishguns() {
		Ped ped = PLAYER::PLAYER_PED_ID();

		for each (Hash weaponlist in weaponlist) {
			int ammo;
			if (WEAPON::GET_MAX_AMMO(ped, weaponlist, &ammo)) {
				WEAPON::SET_PED_AMMO(ped, weaponlist, ammo);
			}
		}
	}
	static char* weaponNames[] = {
		"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
		"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
		"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
		"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
		"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
		"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
		"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
		"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
		"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
		"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN",
		"WEAPON_COMBATPDW", "WEAPON_KNUCKLE", "WEAPON_MARKSMANPISTOL",
		"WEAPON_FLASHLIGHT", "WEAPON_MACHETE", "WEAPON_MACHINEPISTOL",
		"WEAPON_SWITCHBLADE", "WEAPON_REVOLVER",
		//DLC
		"WEAPON_BOTTLE", "WEAPON_BALL", "WEAPON_FLARE", "weapon_battleaxe", "weapon_autoshotgun" "weapon_wrench", "weapon_sweeper", "weapon_compactlauncher", "weapon_compactrifle", "weapon_dbshotgun"
	};
	static char* attachmentNames[] = {
		"COMPONENT_AT_SCOPE_MACRO", "COMPONENT_AT_SCOPE_MACRO_02", "COMPONENT_AT_SCOPE_SMALL", "COMPONENT_AT_SCOPE_SMALL_02", "COMPONENT_AT_SCOPE_MEDIUM",
		"COMPONENT_AT_SCOPE_LARGE", "COMPONENT_AT_SCOPE_MAX", "COMPONENT_AT_PI_SUPP", "COMPONENT_AT_AR_AFGRIP", "COMPONENT_SMG_CLIP_02", "COMPONENT_ADVANCEDRIFLE_CLIP_02", "COMPONENT_MARKSMANRIFLE_CLIP_02"
	};
	void addAll(Ped ped)
	{
		for (int i = 0; i < 70; i++)
			GIVE_DELAYED_WEAPON_TO_PED(ped, $(weaponNames[i]), 1000, 0);
	}
	void removeAll(Ped ped) {
		RequestControlOfEnt(ped);
		if (NETWORK_HAS_CONTROL_OF_ENTITY(ped)) {
			REMOVE_ALL_PED_WEAPONS(ped, 1);
			game::notifyBottom("Weps R Gone");
		}
		else
			game::notifyError("Could Not Get Control");
	}
	void loop_infiniteAmmo(Ped playerPed)
	{
		Hash cur;
		if (GET_CURRENT_PED_WEAPON(playerPed, &cur, 1))
		{
			if (IS_WEAPON_VALID(cur))
			{
				int maxAmmo;
				if (GET_MAX_AMMO(playerPed, cur, &maxAmmo))
				{
					SET_PED_AMMO(playerPed, cur, maxAmmo);

					maxAmmo = GET_MAX_AMMO_IN_CLIP(playerPed, cur, 1);
					if (maxAmmo > 0)
						SET_AMMO_IN_CLIP(playerPed, cur, maxAmmo);
				}
			}
		}
	}
	void superDamage(int playerReference, bool toggle)
	{
		if (toggle)
		{
			SET_PLAYER_WEAPON_DAMAGE_MODIFIER(playerReference, wepDamageValue);
			SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(playerReference, wepDamageValue);
			SET_PLAYER_VEHICLE_DAMAGE_MODIFIER(playerReference, wepDamageValue);
		}
		else
		{
			SET_PLAYER_WEAPON_DAMAGE_MODIFIER(playerReference, 1.f);
			SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(playerReference, 1.f);
			SET_PLAYER_VEHICLE_DAMAGE_MODIFIER(playerReference, 1.f);
		}
	}
	void useTheForcePED(Ped playerObj, Ped eObj)
	{
		SET_PED_TO_RAGDOLL(eObj, 100, 100, 100, 1, 1, 1);
		Vector3 ForwardVector = GET_ENTITY_FORWARD_VECTOR(playerObj);
		APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(eObj, 1, ForwardVector.x * punchForce, ForwardVector.y * punchForce, ForwardVector.z * punchForce, 1, 0, 1, 1);
		//eObj.ApplyForce(playerObj.ForwardVector * force);
		CLEAR_ENTITY_LAST_DAMAGE_ENTITY(eObj);
		hitSomething = true;
	} // end of useTheForcePED
	void useTheForceVEH(Ped playerObj, Vehicle eObj)
	{
		float forceCalc = punchForce / 2.f;
		Vector3 ForwardVector = GET_ENTITY_FORWARD_VECTOR(playerObj);
		APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(eObj, 1, ForwardVector.x * forceCalc, ForwardVector.y * forceCalc, ForwardVector.z * forceCalc, 0, 0, 1, 1);
		CLEAR_ENTITY_LAST_DAMAGE_ENTITY(eObj);
		hitSomething = true;
	} // end of useTheForceVEH
	void DeletePEDArray()
	{
		//KillPeds Globals
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		int nearbyPed[arrSize];
		//Setup the array (vehicle Clearing)
		nearbyPed[0] = numElements;	//ped array

		int count = GET_PED_NEARBY_PEDS(PLAYER_PED_ID(), nearbyPed, -1);

		if (nearbyPed != NULL)
		{
			for (int i = 0; i < count; i++)
			{
				nearbyPed[i] = NULL;
			}
			//nearbyPed[i] = null;
		}
	}
	void DeleteVEHArray()
	{
		const int numElementsveh = 10;
		const int arrSizeveh = numElementsveh * 2 + 2;
		int vec[arrSizeveh];
		vec[0] = numElementsveh;

		int count = GET_PED_NEARBY_VEHICLES(PLAYER_PED_ID(), vec);

		if (vec != NULL)
		{
			for (int i = 0; i < count; i++)
			{
				int offsettedID = i * 2 + 2;
				//Make sure it exists
				if (vec[offsettedID] != NULL && DOES_ENTITY_EXIST(vec[offsettedID]))
					vec[i] = NULL;
			}
		}
		//vec[count] = null;
	}
	void checkForStuff()
	{
		Ped player = PLAYER_PED_ID();
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		//int dynamicSize;
		int nearbyPed[arrSize];
		int count = GET_PED_NEARBY_PEDS(PLAYER_PED_ID(), nearbyPed, -1);

		//int offsettedID = i * 2 + 2;

		if (nearbyPed != NULL)
		{
			for (int i = 0; i < count; i++)
			{
				if (HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY(nearbyPed[i], PLAYER_PED_ID(), 0))
				{
					useTheForcePED(player, nearbyPed[i]);
				}
			} // end of ped loop        

			const int numElementsveh = 10;
			const int arrSizeveh = numElementsveh * 2 + 2;
			int nearVehicles[arrSizeveh];
			nearVehicles[0] = numElementsveh;

			int count = GET_PED_NEARBY_VEHICLES(PLAYER_PED_ID(), nearVehicles);

			if (nearVehicles != NULL)
			{
				for (int i = 0; i < count; i++)
				{
					int offsettedID = i * 2 + 2;
					//Make sure it exists
					if (nearVehicles[offsettedID] != NULL && DOES_ENTITY_EXIST(nearVehicles[offsettedID]))
						useTheForceVEH(player, nearVehicles[i]);
				}

			} // end of vehicle loop                

			  // Freeing nearPeds from memory
			DeletePEDArray();

			// Freeing nearVehicles from memory
			DeleteVEHArray();

		}
	}// end of checkForStuff
	void shootItem(char* name) {
		DWORD model = $(name);
		REQUEST_MODEL(model);
		while (!HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 lol;
		Vector3 cameraPosition = GET_GAMEPLAY_CAM_COORD();
		Vector3 gameplayCam = _GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = game::RotationToDirection(gameplayCamRot);
		Vector3 startCoords = game::addVector(gameplayCam, (game::multiplyVector(gameplayCamDirection, 1.0f)));
		Vector3 endCoordinates = game::addVector(startCoords, game::multiplyVector(gameplayCamDirection, 500.0f));
		try {
			RaycastResult rc = game::Raycast(cameraPosition, endCoordinates, IntersectEverything);
			lol = rc.HitCoords;
			if (rc.DidHitAnything) {
				Object obj = CREATE_OBJECT_NO_OFFSET(model, lol.x, lol.y, lol.z, 1, 0, 0);
				latestObj = obj;
				SET_ENTITY_LOD_DIST(obj, 696969);
			}
		}
		catch (...) {

		}
	}
}

namespace recovery {

	void SET_STAT_i(char *stat, int value, bool save) {
		if (_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY")
			STAT_SET_INT($(stat), value, save);
		else {
			char sbuf[50];
			int stat_r;
			STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
			snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
			STAT_SET_INT($(sbuf), value, save);
		}
	}
	void SET_STAT_b(char *stat, int value, bool save) {
		if (_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY")
			STAT_SET_BOOL($(stat), value, save);
		else {
			char sbuf[50];
			int stat_r;
			STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
			snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
			STAT_SET_BOOL($(sbuf), value, save);
		}
	}
	void SET_STAT_f(char *stat, float value, bool save) {
		if (_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY")
			STAT_SET_FLOAT($(stat), value, save);
		else {
			char sbuf[50];
			int stat_r;
			STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
			snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
			STAT_SET_FLOAT($(sbuf), value, save);
		}
	}
	int GET_STAT_i(char *stat) {
		if (_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY") {
			int stat_get;
			STAT_GET_INT($(stat), &stat_get, 1);
			return stat_get;
		}
		else {
			char sbuf[50];
			int stat_r;
			STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
			snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
			int stat_get;
			STAT_GET_INT($(sbuf), &stat_get, 1);
			return stat_get;
		}
	}
	bool GET_STAT_b(char *stat) {
		if (_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY") {
			int stat_get;
			STAT_GET_BOOL($(stat), &stat_get, 1);
			return stat_get;
		}
		else {
			char sbuf[50];
			int stat_r;
			STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
			snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
			int stat_get;
			STAT_GET_BOOL($(sbuf), &stat_get, 1);
			return stat_get;
		}
	}
	float GET_STAT_f(char *stat) {
		if (_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY") {
			float stat_get;
			STAT_GET_FLOAT($(stat), &stat_get, 1);
			return stat_get;
		}
		else {
			char sbuf[50];
			int stat_r;
			STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
			snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
			float stat_get;
			STAT_GET_FLOAT($(sbuf), &stat_get, 1);
			return stat_get;
		}
	}

	char *ItoS(int num)
	{
		char buf[30];
		snprintf(buf, sizeof(buf), "%i", num);
		return buf;
	}
	//money shit
	int customVal(int max, int min, std::string setMsg, std::string closeMsg = NULL) {
		string inputString = show_keyboard("HUD_TITLE", "");
		if (stoi(inputString) > max)
		{
			game::notifyError("Cannot be larger than "s + ItoS(max));
			return 0;
		}
		if (stoi(inputString) < min)
		{
			game::notifyError("Cannot be less than "s + ItoS(min));
			return 0;
		}
		else if (inputString == "")
		{
			game::notifyError("Cannot be blank");
			return 0;
		}
		else
		{
			game::notifyMap(setMsg + "~g~ "s + inputString + "~w~"s + closeMsg, 0);
			return stoi(inputString);
		}
	}
	/*void setcash()
	{
	string tempcash = show_keyboard("HUD_TITLE", "");
	if (stoi(tempcash) > 15000000)
	{
	ErrorLogger(0, "setcash");
	}
	else if (tempcash == "")
	{
	ErrorLogger(6, "setcash");
	}
	else
	{
	dropAmount = stoi(tempcash);
	notifyMap("Cash Set To: " + tempcash, 0);
	int var0 = 1146239992;
	//_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, 393059668, 1445302971, rndInt(14000000, 15000000), 1);
	//_NETWORK_SHOP_CHECKOUT_START(var0);
	}
	}
	void netcash90m()
	{
	int var0 = 1146239992;
	_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, 1982688246, 1445302971, 90000000, 4);
	_NETWORK_SHOP_CHECKOUT_START(var0);
	}*/
	void netcash(bool stealthBank, int value)
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			int var0 = 1146239992, var3 = 1445302971, toBank;					//update.rpf\common\data\networkshop.meta
			if (stealthBank)
				toBank = 4;
			else
				toBank = 1;
			_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, 393059668, 1445302971, value, toBank);
			_NETWORK_SHOP_CHECKOUT_START(var0);
		}
		else
			game::notifyError("You are offline");
	}

	void dildocashdrop() {
		Ped iPed = PLAYER::PLAYER_PED_ID();
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
	void testnetcash()
	{
		// yeah this shit is from job. i mean its public code so fight me :dabs:
		if (NETWORK_IS_SESSION_STARTED())
		{
		/*	int var0 = 1146239992, var3 = 1445302971, toBank;					//update.rpf\common\data\networkshop.meta
			if (stealthBank)
				toBank = 4;
			else
				toBank = 1;
			dildocashdrop();
			_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET"), 1445302971, value, toBank);
			dildocashdrop();
			_NETWORK_SHOP_CHECKOUT_START(var0);
			*/
		//	int transactionCode = 393059668;
			int transactionCode = -1586170317;// 15 M $
			//int transactionCode = 1982688246; // 90 M $
			int cash_to_receive = 15000000;
			bool toBank = true;
			int transactionID = 1146239992;
			if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&transactionID, 1474183246, transactionCode, 1445302971, cash_to_receive, toBank ? 4 : 1))
				dildocashdrop();
				UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);
		}
		else
			game::notifyError("You are offline");
	}

	void sixhundeestealth() {
		int TrasID = 1146239992; // -1586170317 Im guessing your using this one and it does not work!
		if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&TrasID, 1474183246, 393059668, -1586170317, 100000, 4))
	/*		^ OTHER Trasaction Codes ^ */
			if (!UNK3::_NETWORK_SHOP_CHECKOUT_START(TrasID)) {
				game::notifyError("transaction failed");
			}
	}
	void newCash(bool stealthBank, int value)
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			int var0 = 1146239992, var3 = 1445302971, toBank;					//update.rpf\common\data\networkshop.meta
			if (stealthBank)
				toBank = 4;
			else
				toBank = 1;
			_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, 393059668, 1445302971, value, toBank);
			_NETWORK_SHOP_CHECKOUT_START(var0);

			/*	Any iParam3, iParam4, iParam2;
			int iVar3, iParam5, iParam6; //iParam6 4 is bank 1 is wallet
			if (bVar0 || UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&iVar3, iParam3, iParam4, iParam2, iParam5, iParam6))
			{
			if (bVar0 || UNK3::_NETWORK_SHOP_CHECKOUT_START(iVar3))
			{
			*iParam0 = func_993(iVar3, iParam1, iParam4, iParam2, iParam3, iParam5, 0, iParam6, iParam7);
			if (bVar0)
			{
			if (*iParam0 != -1)
			{
			Global_2590252[*iParam0 /*76*//*].f_69 = 1;
			}
			}
			Global_2590752 = 1;
			return true;
			}
			}*/
		}
		else
			game::notifyError("You are offline");

	}
	void netcashCustom()
	{
		string tempcash = show_keyboard("HUD_TITLE", "");
		if (stoi(tempcash) < 15000000)
		{
			dropAmount = stoi(tempcash);
			netcash(1, 0);
		}
		else if (tempcash == "")
		{
			game::notifyError("Cannot be blank");
		}
		else
		{
			float desiredvalueFlt = TO_FLOAT(stoi(tempcash));
			float dividedVal = desiredvalueFlt / 15000000.f;
			int numLoops = floorf(dividedVal);
			int spillover = numLoops * 15000000;
			netcash(0, spillover);
			dropAmount = 15000000;
		}
	}
	void bankTransfer(bool toBank) {
		if (NETWORK_IS_SESSION_STARTED()) {
			int amount = customVal(100000000000, 0, "~g~Transferring ", " to Bank");
			int iVar0;
			STAT_GET_INT($("mpply_last_mp_char"), &iVar0, -1);
			if (toBank)
				_NETWORK_TRANSFER_WALLET_TO_BANK(iVar0, amount);
			else
				_NETWORK_TRANSFER_BANK_TO_WALLET(iVar0, amount);
		}
		else
			game::notifyError("You are offline");
	}
	void MoneyDrop(Player p, int amount)
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(game::GET_PLAYER_PED(p), 0);
		int bagAmount = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1500, 2000);

		STREAMING::REQUEST_MODEL(0x113FD533);
		while (!STREAMING::HAS_MODEL_LOADED(0x113FD533)) WAIT(0);

		for (int i = 0; i < amount; i++) {
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, coords.x, coords.y, coords.z + 1.5, 0, bagAmount, 0x113FD533, 0, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
		}
	}
	void anotherDrop() {

		STREAMING::REQUEST_MODEL(0x113FD533);

		Vector3 pp = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
		{
			static Hash PICKUP_MONEY_CASE = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_CASE");
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pp.x, pp.y, pp.z + 1, 0, 40000, 0x113FD533, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
		}
	}
	//stat shit
	void setRank() {
		if (NETWORK_IS_SESSION_STARTED())
		{
			int rank = customVal(8000, 0, "Setting Rank to");
			if (rank < 99)
				recovery::SET_STAT_i("MP0_CHAR_XP_FM", RankValues2[rank], 0);
			else
				//recovery::SET_STAT_i("MP0_CHAR_XP_FM", 25 * (rank * rank) + 23575 * rank - 1023150, 0);
				recovery::SET_STAT_i("MP0_CHAR_XP_FM", 25 * (rank * rank) + 23575 * rank - 1023150, 0);
		}
		else
			game::notifyError("You are offline");
	}
	void setRP(char *slot)
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			bool custominput = 0;
			string temprank = show_keyboard("Set Rank", "");
			if (temprank == "")
			{
				game::notifyError("Cannot be blank");
			}
			else
			{
				int rank = stoi(temprank) - 1;
				int rpvalue = 4; //RankValues[rank];
				SET_STAT_i("MP0_CHAR_XP_FM", rpvalue, 0);
				game::notifyMap("Rank Set to ~o~" + temprank, 0);
			}
		}
		else
			game::notifyError("You are offline");
	}
	void bypassSellTimer()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("mpply_vehicle_sell_time"), 0, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void clearBadSport()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_BAD_SPORT_BITSET"), 0, 1);
			STAT_SET_INT($("MP0_MPPLY_WAS_I_BAD_SPORT"), 0, 1);
			STAT_SET_INT($("MP0_MPPLY_OVERALL_BADSPORT"), 0, 1);
			STAT_SET_INT($("MP0_MPPLY_CHAR_IS_BADSPORT"), 0, 1);
			STAT_SET_INT($("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
			STAT_SET_INT($("MP0_MPPLY_DESTROYED_PVEHICLES"), 0, 1);
			STAT_SET_FLOAT($("MPPLY_OVERALL_BADSPORT"), 0.0f, TRUE);
			STAT_SET_INT($("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
			STAT_SET_INT($("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
			STAT_SET_INT($("MPPLY_BECAME_BADSPORT_NUM"), 0, TRUE);
		}
		else
			game::notifyError("You are offline");
	}
	void RemoveBadSport()
	{
		STAT_SET_FLOAT($("MPPLY_OVERALL_BADSPORT"), 0.0f, TRUE);
		STAT_SET_INT($("MPPLY_DESTROYED_PVEHICLES"), 0, TRUE);
		STAT_SET_INT($("MPPLY_BADSPORT_MESSAGE"), 0, TRUE);
		STAT_SET_INT($("MPPLY_BECAME_BADSPORT_NUM"), 0, TRUE);
	}
	void enableRoosevelt()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MPPLY_VEHICLE_ID_ADMIN_WEB"), 117401876, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void clearReports()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MPPLY_REPORT_STRENGTH"), 0, 1);
			STAT_SET_INT($("MPPLY_COMMEND_STRENGTH"), 100, 1);
			STAT_SET_INT($("MPPLY_FRIENDLY"), 100, 1);
			STAT_SET_INT($("MPPLY_HELPFUL"), 100, 1);
			STAT_SET_INT($("MPPLY_GRIEFING"), 0, 1);
			STAT_SET_INT($("MPPLY_VC_ANNOYINGME"), 0, 1);
			STAT_SET_INT($("MPPLY_VC_HATE"), 0, 1);
			STAT_SET_INT($("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
			STAT_SET_INT($("MPPLY_OFFENSIVE_TAGPLATE"), 0, 1);
			STAT_SET_INT($("MPPLY_OFFENSIVE_UGC"), 0, 1);
			STAT_SET_INT($("MPPLY_BAD_CREW_NAME"), 0, 1);
			STAT_SET_INT($("MPPLY_BAD_CREW_MOTTO"), 0, 1);
			STAT_SET_INT($("MPPLY_BAD_CREW_STATUS"), 0, 1);
			STAT_SET_INT($("MPPLY_BAD_CREW_EMBLEM"), 0, 1);
			STAT_SET_INT($("MPPLY_GAME_EXPLOITS"), 0, 1);
			STAT_SET_INT($("MPPLY_EXPLOITS"), 0, 1);
			STAT_SET_INT($("MPPLY_ISPUNISHED"), 0, 1);
		}
		else
			game::notifyError("You are offline");
	}

	//recovery stats
	void unlockHeistVehicles()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1);
			game::notifyBottom("Unlocked Heist Vehicles");
		}
		else
			game::notifyError("You are offline");
	}
	void maxStats()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_SCRIPT_INCREASE_STAM"), 100, 1);
			STAT_SET_INT($("MP0_SCRIPT_INCREASE_STRN"), 100, 1);
			STAT_SET_INT($("MP0_SCRIPT_INCREASE_LUNG"), 100, 1);
			STAT_SET_INT($("MP0_SCRIPT_INCREASE_DRIV"), 100, 1);
			STAT_SET_INT($("MP0_SCRIPT_INCREASE_FLY"), 100, 1);
			STAT_SET_INT($("MP0_SCRIPT_INCREASE_SHO"), 100, 1);
			STAT_SET_INT($("MP0_SCRIPT_INCREASE_STL"), 100, 1);
			game::notifyBottom("Player Stats Maxed");
		}
		else
			game::notifyError("You are offline");
	}
	void unlockTattoos()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_AWD_FM_DM_WINS"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_TDM_MVP"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_DM_TOTALKILLS"), 500, 1);
			STAT_SET_BOOL($("MP0_AWD_FMATTGANGHQ"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMBBETWIN"), 50000, 1);
			STAT_SET_BOOL($("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMFULLYMODDEDCAR"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMMOSTKILLSSURVIVE"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMKILL3ANDWINGTARACE"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMKILLBOUNTY"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FMREVENGEKILLSDM"), 50, 1);
			STAT_SET_BOOL($("MP0_AWD_FMKILLSTREAKSDM"), 1, 1);
			STAT_SET_INT($("MP0_AWD_HOLD_UP_SHOPS"), 20, 1);
			STAT_SET_INT($("MP0_AWD_LAPDANCES"), 25, 1);
			STAT_SET_INT($("MP0_AWD_SECURITY_CARS_ROBBED"), 25, 1);
			STAT_SET_INT($("MP0_AWD_RACES_WON"), 50, 1);
			STAT_SET_INT($("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
			STAT_SET_INT($("MP0_PLAYER_HEADSHOTS"), 500, 1);
			STAT_SET_INT($("MP0_DB_PLAYER_KILLS"), 1000, 1);
			game::notifyBottom("Unlocked All Tattoos");
		}
		else
			game::notifyError("You are offline");
	}
	void unlimitedSnacks()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_NO_BOUGHT_YUM_SNACKS"), 2000000000, 0);
			STAT_SET_INT($("MP0_NO_BOUGHT_HEALTH_SNACKS"), 2000000000, 0);
			STAT_SET_INT($("MP0_NO_BOUGHT_EPIC_SNACKS"), 2000000000, 0);
			STAT_SET_INT($("MP0_NUMBER_OF_ORANGE_BOUGHT"), 2000000000, 0);
			STAT_SET_INT($("MP0_CIGARETTES_BOUGHT"), 2000000000, 0);
			game::notifyBottom("Player has Unlimited Snacks n Smokes");
		}
		else
			game::notifyError("You are offline");
	}
	void unlimitedArmour()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_MP_CHAR_ARMOUR_1_COUNT"), 2000000000, 1);
			STAT_SET_INT($("MP0_MP_CHAR_ARMOUR_2_COUNT"), 2000000000, 1);
			STAT_SET_INT($("MP0_MP_CHAR_ARMOUR_3_COUNT"), 2000000000, 1);
			STAT_SET_INT($("MP0_MP_CHAR_ARMOUR_4_COUNT"), 2000000000, 1);
			STAT_SET_INT($("MP0_MP_CHAR_ARMOUR_5_COUNT"), 2000000000, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void unlimitedFireworks()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_FIREWORK_TYPE_1_WHITE"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_1_RED"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_1_BLUE"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_2_WHITE"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_2_RED"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_2_BLUE"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_3_WHITE"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_3_RED"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_3_BLUE"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_4_WHITE"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_4_RED"), 2000000000, 1);
			STAT_SET_INT($("MP0_FIREWORK_TYPE_4_BLUE"), 2000000000, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void unlockCamoParachutes()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_CHAR_KIT_1_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_2_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_3_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_4_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_5_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_6_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_7_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_8_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_9_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_10_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_11_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_12_FM_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE2"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE3"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE4"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE5"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE6"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE7"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE8"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE9"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE10"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE11"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_KIT_FM_PURCHASE12"), -1, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void unlockChromeRims()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_AWD_WIN_CAPTURES"), 25, 1);
			STAT_SET_INT($("MP0_AWD_DROPOFF_CAP_PACKAGES"), 100, 1);
			STAT_SET_INT($("MP0_AWD_KILL_CARRIER_CAPTURE"), 100, 1);
			STAT_SET_INT($("MP0_AWD_FINISH_HEISTS"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FINISH_HEIST_SETUP_JOB"), 50, 1);
			STAT_SET_INT($("MP0_AWD_NIGHTVISION_KILLS, 100"), 1, 1);
			STAT_SET_INT($("MP0_AWD_WIN_LAST_TEAM_STANDINGS"), 50, 1);
			STAT_SET_INT($("MP0_AWD_ONLY_PLAYER_ALIVE_LTS"), 50, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void unlockTshirts()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_AWD_FMHORDWAVESSURVIVE"), 10, 1);
			STAT_SET_INT($("MP0_AWD_FMPICKUPDLCCRATE1ST"), 1, 1);
			STAT_SET_INT($("MP0_AWD_WIN_CAPTURE_DONT_DYING"), 25, 1);
			STAT_SET_INT($("MP0_AWD_DO_HEIST_AS_MEMBER"), 25, 1);
			STAT_SET_INT($("MP0_AWD_PICKUP_CAP_PACKAGES"), 100, 1);
			STAT_SET_BOOL($("MP0_AWD_FINISH_HEIST_NO_DAMAGE"), 1, 1);
			STAT_SET_INT($("MP0_AWD_WIN_GOLD_MEDAL_HEISTS"), 25, 1);
			STAT_SET_INT($("MP0_AWD_KILL_TEAM_YOURSELF_LTS"), 25, 1);
			STAT_SET_INT($("MP0_AWD_KILL_PSYCHOPATHS"), 100, 1);
			STAT_SET_INT($("MP0_AWD_DO_HEIST_AS_THE_LEADER"), 25, 1);
			STAT_SET_BOOL($("MP0_AWD_STORE_20_CAR_IN_GARAGES"), 1, 1);
			/*
			<stat Name="DELIVERY_VEH_UPGRADES"  		Type="int"   SaveCategory="0" online="true"  profile="true" ServerAuthoritative="true" FlushPriority="15" Owner="script" characterStat="true"  Comment=" store delivery vehicle upgrades " />
			<stat Name="ACCOUNTANTSHIRTUNLOCK"          Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="BAHAMAMAMASHIRTUNLOCK"          Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="DRONESHIRTUNLOCK"          		Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="GROTTISHIRTUNLOCK"          	Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="GOLFSHIRTUNLOCK"          		Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="MAISONETTESHIRTUNLOCK"          Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="MANOPAUSESHIRTUNLOCK"           Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="MELTDOWNSHIRTUNLOCK"            Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="PACIFICBLUFFSSHIRTUNLOCK"       Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="PROLAPSSHIRTUNLOCK"             Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="TENNISSHIRTUNLOCK"              Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="TOESHOESSHIRTUNLOCK"            Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="VANILLAUNICORNSHIRTUNLOCK"      Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="MARLOWESHIRTUNLOCK"             Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"  Comment=" log in item rewards" />
			<stat Name="CRESTSHIRTUNLOCK"               Type="bool"  SaveCategory="0"  online="true"  profile="false"  Owner="script"  characterStat="true"
			*/
			STAT_SET_INT($("DELIVERY_VEH_UPGRADES"), -1, 1);
			STAT_SET_BOOL($("ACCOUNTANTSHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("BAHAMAMAMASHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("DRONESHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("GROTTISHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("GOLFSHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("MAISONETTESHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("MANOPAUSESHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("MELTDOWNSHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("PACIFICBLUFFSSHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("PROLAPSSHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("TENNISSHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("TOESHOESSHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("VANILLAUNICORNSHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("MARLOWESHIRTUNLOCK"), 1, 1);
			STAT_SET_BOOL($("CRESTSHIRTUNLOCK"), 1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void unlockVehicleMods()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_RACES_WON"), 50, 1);
			STAT_SET_INT($("MP0_CHAR_FM_CARMOD_1_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_CARMOD_2_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_CARMOD_3_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_CARMOD_4_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_CARMOD_5_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_CARMOD_6_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_CARMOD_7_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_AWD_FMRALLYWONDRIVE"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMRALLYWONNAV"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMWINSEARACE"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMWINAIRRACE"), 1, 1);
			STAT_SET_INT($("MP0_NUMBER_TURBO_STARTS_IN_RACE"), 50, 1);
			STAT_SET_INT($("MP0_USJS_COMPLETED"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_RACES_FASTEST_LAP"), 50, 1);
			STAT_SET_INT($("MP0_NUMBER_SLIPSTREAMS_IN_RACE"), 100, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void characterPrompt()
	{
		if (NETWORK_IS_SESSION_STARTED())
			STAT_SET_BOOL($("MP0_FM_CHANGECHAR_ASKED"), 0, 1);
		else
			game::notifyError("You are offline");
	}
	void skipTutorial()
	{
		if (NETWORK_IS_SESSION_STARTED())
			STAT_SET_BOOL($("MP0_NO_MORE_TUTORIALS"), 1, 1);
		else
			game::notifyError("You are offline");
	}
	void unlockAllAwards()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_PLAYER_HEADSHOTS"), 500, 1);
			STAT_SET_INT($("MP0_PISTOL_ENEMY_KILLS"), 500, 1);
			STAT_SET_INT($("MP0_SAWNOFF_ENEMY_KILLS"), 500, 1);
			STAT_SET_INT($("MP0_MICROSMG_ENEMY_KILLS"), 500, 1);
			STAT_SET_INT($("MP0_SNIPERRFL_ENEMY_KILLS"), 100, 1);
			STAT_SET_INT($("MP0_UNARMED_ENEMY_KILLS"), 50, 1);
			STAT_SET_INT($("MP0_STKYBMB_ENEMY_KILLS"), 50, 1);
			STAT_SET_INT($("MP0_GRENADE_ENEMY_KILLS"), 50, 1);
			STAT_SET_INT($("MP0_RPG_ENEMY_KILLS"), 50, 1);
			STAT_SET_INT($("MP0_CARS_EXPLODED"), 500, 1);
			STAT_SET_INT($("MP0_AWD_RACES_WON"), 500, 1);
			STAT_SET_INT($("MP0_AWD_5STAR_WANTED_AVOIDANCE"), 50, 1);
			STAT_SET_INT($("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
			STAT_SET_INT($("MP0_AWD_CARS_EXPORTED"), 50, 1);
			STAT_SET_INT($("MP0_PASS_DB_PLAYER_KILLS"), 100, 1);
			STAT_SET_INT($("MP0_AWD_FM_DM_WINS"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_GOLF_WON"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FM_GTA_RACES_WON"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_SHOOTRANG_CT_WON"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FM_SHOOTRANG_RT_WON"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FM_SHOOTRANG_TG_WON"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FM_TDM_WINS"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_TENNIS_WON"), 25, 1);
			STAT_SET_INT($("MP0_MOST_SPINS_IN_ONE_JUMP"), 5, 1);
			STAT_SET_INT($("MPPLY_AWD_FM_CR_DM_MADE"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FMHORDWAVESSURVIVE"), 10, 1);
			STAT_SET_INT($("MP0_AWD_HOLD_UP_SHOPS"), 20, 1);
			STAT_SET_INT($("MP0_ASLTRIFLE_ENEMY_KILLS"), 500, 1);
			STAT_SET_INT($("MP0_MG_ENEMY_KILLS"), 500, 1);
			STAT_SET_INT($("MP0_AWD_LAPDANCES"), 25, 1);
			STAT_SET_INT($("MP0_MOST_ARM_WRESTLING_WINS"), 25, 1);
			STAT_SET_INT($("MP0_AWD_NO_HAIRCUTS"), 25, 1);
			STAT_SET_INT($("MP0_AWD_RACES_WON"), 50, 1);
			STAT_SET_INT($("MP0_AWD_SECURITY_CARS_ROBBED"), 25, 1);
			STAT_SET_INT($("MP0_AWD_VEHICLES_JACKEDR"), 500, 1);
			STAT_SET_INT($("MP0_MOST_FLIPS_IN_ONE_JUMP"), 5, 1);
			STAT_SET_INT($("MP0_AWD_WIN_AT_DARTS"), 25, 1);
			STAT_SET_INT($("MP0_AWD_PASSENGERTIME"), 4, 1);
			STAT_SET_INT($("MP0_AWD_TIME_IN_HELICOPTER"), 4, 1);
			STAT_SET_INT($("MP0_AWD_FM_DM_3KILLSAMEGUY"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_DM_KILLSTREAK"), 100, 1);
			STAT_SET_INT($("MP0_AWD_FM_DM_STOLENKILL"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_DM_TOTALKILLS"), 500, 1);
			STAT_SET_INT($("MP0_AWD_FM_GOLF_BIRDIES"), 25, 1);
			STAT_SET_BOOL($("MP0_AWD_FM_GOLF_HOLE_IN_1"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FM_RACE_LAST_FIRST, 25"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FM_RACES_FASTEST_LAP, 25"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FM_TDM_MVP"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FM_TENNIS_ACE"), 25, 1);
			STAT_SET_BOOL($("MP0_AWD_FM_TENNIS_STASETWIN"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FM6DARTCHKOUT"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMATTGANGHQ"), 1, 1);
			STAT_SET_INT($("MP0_AWD_PARACHUTE_JUMPS_20M"), 25, 1);
			STAT_SET_INT($("MP0_AWD_PARACHUTE_JUMPS_50M"), 25, 1);
			STAT_SET_INT($("MP0_AIR_LAUNCHES_OVER_40M"), 25, 1);
			STAT_SET_BOOL($("MP0_AWD_BUY_EVERY_GUN"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMDRIVEWITHOUTCRASH"), 255, 1);
			STAT_SET_INT($("MP0_AWD_FMCRATEDROPS"), 25, 1);
			STAT_SET_BOOL($("MP0_AWD_FM25DIFFERENTDM"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FM_TENNIS_5_SET_WINS"), 1, 1);
			STAT_SET_INT($("MPPLY_AWD_FM_CR_PLAYED_BY_PEEP"), 100, 1);
			STAT_SET_INT($("MPPLY_AWD_FM_CR_RACES_MADE"), 25, 1);
			STAT_SET_BOOL($("MP0_AWD_FM25DIFFERENTRACES"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FM25DIFITEMSCLOTHES"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMFULLYMODDEDCAR"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMKILLBOUNTY"), 25, 1);
			STAT_SET_INT($("MP0_KILLS_PLAYERS"), 1000, 1);
			STAT_SET_BOOL($("MP0_AWD_FMPICKUPDLCCRATE1ST"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMSHOOTDOWNCOPHELI"), 25, 1);
			STAT_SET_BOOL($("MP0_AWD_FMKILL3ANDWINGTARACE"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMKILLSTREAKSDM"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMMOSTKILLSGANGHIDE"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMMOSTKILLSSURVIVE"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMRALLYWONDRIVE"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FMRALLYWONNAV"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FMREVENGEKILLSDM"), 50, 1);
			STAT_SET_INT($("MP0_AWD_FMWINAIRRACE"), 25, 1);
			STAT_SET_BOOL($("MP0_AWD_FMWINCUSTOMRACE"), 1, 1);
			STAT_SET_INT($("MP0_AWD_FMWINRACETOPOINTS"), 25, 1);
			STAT_SET_INT($("MP0_AWD_FMWINSEARACE"), 25, 1); //AWD_FMWINAIRRACE
															//STAT_SET_INT($("MP0_AWD_FMWINAIRRACE"), 25, 1); //AWD_FMWINAIRRACE
			STAT_SET_INT($("MP0_AWD_FMBASEJMP"), 25, 1);
			STAT_SET_BOOL($("MP0_MP0_AWD_FMWINALLRACEMODES"), 1, 1);
			STAT_SET_BOOL($("MP0_AWD_FMTATTOOALLBODYPARTS"), 1, 1);
			STAT_SET_INT($("MP0_CHAR_WANTED_LEVEL_TIME5STAR"), 2147483647, 1);
			STAT_SET_FLOAT($("MP0_LONGEST_WHEELIE_DIST"), 1000, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void unlockHeistTrophies()
	{
		if (NETWORK_IS_SESSION_STARTED())
			STAT_SET_INT($("MPPLY_HEIST_ACH_TRACKER"), -1, 1);
		else
			game::notifyError("You are offline");
	}
	void unlockAllHairstyles()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
			STAT_SET_INT($("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void ownAllWeapons()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			STAT_SET_INT($("MP0_ADMIN_WEAPON_GV_BS_1"), -1, 1);
			STAT_SET_INT($("MP0_ADMIN_WEAPON_GV_BS_2"), -1, 1);
			STAT_SET_INT($("MP0_ADMIN_WEAPON_GV_BS_3"), -1, 1);
			STAT_SET_INT($("MP0_BOTTLE_IN_POSSESSION"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_WEAP_UNLOCKED"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_WEAP_UNLOCKED2"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_WEAP_FM_PURCHASE"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_WEAP_FM_PURCHASE2"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_WEAP_ADDON_1_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_WEAP_ADDON_2_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_WEAP_ADDON_3_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_WEAP_ADDON_4_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_CHAR_FM_WEAP_ADDON_5_UNLCK"), -1, 1);
			STAT_SET_INT($("MP0_WEAP_FM_ADDON_PURCH"), -1, 1);
			STAT_SET_INT($("MP0_WEAP_FM_ADDON_PURCH2"), -1, 1);
			STAT_SET_INT($("MP0_WEAP_FM_ADDON_PURCH3"), -1, 1);
			STAT_SET_INT($("MP0_WEAP_FM_ADDON_PURCH4"), -1, 1);
			STAT_SET_INT($("MP0_WEAP_FM_ADDON_PURCH5"), -1, 1);
		}
		else
			game::notifyError("You are offline");
	}
	void unlockAll()
	{
		if (NETWORK_IS_SESSION_STARTED())
		{
			unlockAllAwards();
			unlockAllHairstyles();
			unlockCamoParachutes();
			unlockChromeRims();
			unlockHeistTrophies();
			unlockHeistVehicles();
			unlockTshirts();
			unlockVehicleMods();
			unlockTattoos();
			game::notifyBottom("Unlocked All");
		}
		else
			game::notifyError("You are offline");
	}
	void golf_test()
	{
		STAT_SET_INT($("MP0_AWD_RACES_WON"), 500, 1);
		STAT_SET_INT($("MP0_AWD_FM_GOLF_WON"), 500, 1);
	}
}
void RequestControlOfid2(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

namespace online {

	void Remove_Objects(Player SelectedPlayer) {
		for (int i = 0; i < 5; i++) {
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(SelectedPlayer), 1);
			GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
			GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
			GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
			for (int i = 0; i < 127; i++) {
				Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(Prop_list[i]), 0, 0, 1);

				if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED(SelectedPlayer))) {
					RequestControlOfEnt(obj);
					int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
					NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
					RequestControlOfid2(netID);
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

	




	void triggerScript(ScrHandle id, Player player, uint64_t arg2, uint64_t arg3)
	{
		if (NETWORK::NETWORK_IS_SESSION_STARTED())
			return;
		constexpr BYTE	c = 4;
		int32_t			flags = (1 << player);
		uint64_t		args[c] = { id, (uint64_t)player, arg2, arg3 };
		TRIGGER_SCRIPT_EVENT(true, args, c, flags);
	}
	void silent50K3(Player player) {
		int playerID;
		GAMEPLAY::SET_BIT(&playerID, player);
		online::triggerScript(SCRIPTEVENT_SECURO_PAYMENT_SILENT, playerID, 50000, 0Ui64);
	}
	void remote50K3(Player player) {
		int playerID;
		GAMEPLAY::SET_BIT(&playerID, player);
		online::triggerScript(SCRIPTEVENT_SECURO_PAYMENT, playerID, 50000, 0Ui64);
		GAMEPLAY::CLEAR_BIT(&playerID, player);

	}
	void remoteKick3(Player player) {
		int playerID;
		GAMEPLAY::SET_BIT(&playerID, player);
		online::triggerScript(SCRIPTEVENT_KICK, playerID, 0Ui64, 0Ui64);
	}
	void remoteInv3(Player player) {
		online::triggerScript(SCRIPTEVENT_INVITE_APARTMENT, player, 0Ui64, 0Ui64);
	}
	void remoteRP(Player target) {

		if (target == PLAYER_ID()) {
			game::notifyError("You cannot do that to yourself");
			return;
		}

		Any args[5];
		args[0] = SCRIPTEVENT_RP; //506
		args[1] = target;
		args[2] = PLAYER::PLAYER_ID();
		args[3] = 1;
		args[4] = 50000;
		int playerId;
		GAMEPLAY::SET_BIT(&playerId, target);
		SCRIPT::TRIGGER_SCRIPT_EVENT(0x1, args, 5, playerId);
		GAMEPLAY::CLEAR_BIT(&playerId, target);
	}
	void remoteSilent(Player target) {

		if (target == PLAYER_ID()) {
			game::notifyError("You cannot do that to yourself");
			return;
		}

		Any args[5];
		args[0] = SCRIPTEVENT_SECURO_PAYMENT_SILENT; //490
		args[1] = target;
		args[2] = PLAYER::PLAYER_ID();
		args[3] = 1;
		args[4] = 50000;
		int playerId;
		GAMEPLAY::SET_BIT(&playerId, target);
		SCRIPT::TRIGGER_SCRIPT_EVENT(0x1, args, 5, playerId);
		GAMEPLAY::CLEAR_BIT(&playerId, target);
	}
	void remote50k(Player target) {

		if (target == PLAYER_ID()) {
			game::notifyError("You cannot do that to yourself");
			return;
		}

		Any args[5];
		args[0] = SCRIPTEVENT_SECURO_PAYMENT; //487
		args[1] = target;
		args[2] = PLAYER::PLAYER_ID();
		args[3] = 1;
		args[4] = 50000;
		int playerId;
		GAMEPLAY::SET_BIT(&playerId, target);
		SCRIPT::TRIGGER_SCRIPT_EVENT(0x1, args, 5, playerId);
		GAMEPLAY::CLEAR_BIT(&playerId, target);
	}
	void blankRemote(Player target, int scriptID) {

		if (target == PLAYER_ID()) {
			game::notifyError("You cannot do that to yourself");
			return;
		}

		Any args[5];
		args[0] = scriptID; //487
		args[1] = target;
		args[2] = PLAYER::PLAYER_ID();
		args[3] = 500;
		args[4] = 500;
		int playerId;
		GAMEPLAY::SET_BIT(&playerId, target);
		SCRIPT::TRIGGER_SCRIPT_EVENT(0x1, args, 5, playerId);
		GAMEPLAY::CLEAR_BIT(&playerId, target);
	}
	void remoteKick(Player target) {

		if (target == PLAYER_ID()) {
			game::notifyError("You cannot do that to yourself");
			return;
		}

		Any args[2];
		args[0] = SCRIPTEVENT_KICK; //556
		args[1] = target;
		int playerId;
		GAMEPLAY::SET_BIT(&playerId, target);
		SCRIPT::TRIGGER_SCRIPT_EVENT(0x1, args, 2, playerId);
		GAMEPLAY::CLEAR_BIT(&playerId, target);
	}
	void remoteInv(Player target) {

		if (target == PLAYER_ID()) {
			game::notifyError("You cannot do that to yourself");
			return;
		}

		Any args[2];
		args[0] = SCRIPTEVENT_INVITE_APARTMENT; //445
		args[1] = target;
		int playerId;
		GAMEPLAY::SET_BIT(&playerId, target);
		SCRIPT::TRIGGER_SCRIPT_EVENT(0x1, args, 2, playerId);
		GAMEPLAY::CLEAR_BIT(&playerId, target);
	}
	int GetFreeSeat(Vehicle vehicle)
	{
		if (VEHICLE::ARE_ANY_VEHICLE_SEATS_FREE(vehicle)) {
			for (int i = -1; i < 8; i++)	// 0 = first passenger seat
				if (IS_VEHICLE_SEAT_FREE(vehicle, i))
					return i;
		}
		else
			return -2;
	}
	void teleportToCar(Ped ped)
	{
		if (!IS_PED_IN_ANY_VEHICLE(ped, 1))
			return;

		Vehicle veh = GET_VEHICLE_PED_IS_USING(ped);
		int	seatIndex = GetFreeSeat(veh);
		if (seatIndex > -1)
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), veh, seatIndex);
	}
	bool isPlayerFriend(Player player) {
		if (NETWORK_IS_PLAYER_CONNECTED(player)) {
			int handle;
			NETWORK_HANDLE_FROM_PLAYER(player, &handle, 13);
			return NETWORK_IS_FRIEND(&handle);
		}
		return false;
	}
	void teleportallcoords(Player target)
	{
		for (int i2 = 0; i2 < 2; i2++)
		{
			Vector3 targetCoords = coordsOf(game::GET_PLAYER_PED(target));
			for (int i = 0; i < 32; i++)
			{
				if (i == target)
					continue;
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)))
				{
					AI::CLEAR_PED_TASKS_IMMEDIATELY(game::GET_PLAYER_PED(i));
					int netScene = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(targetCoords.x, targetCoords.y, targetCoords.z, 0.f, 0.f, 0.f, 0, 0, 0, 0.f, 0.f, 0.f);
					NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(game::GET_PLAYER_PED(i), netScene, "amb@code_human_cower@female@base", "base", 8.f, -8.f, 2, 0, 100.f, 0);
					NETWORK::NETWORK_START_SYNCHRONISED_SCENE(netScene);
				}
			}
			WAIT(150);
			for (int i = 0; i < 32; i++)
			{
				if (ENTITY::DOES_ENTITY_EXIST(game::GET_PLAYER_PED(i)))
				{
					AI::CLEAR_PED_TASKS_IMMEDIATELY(game::GET_PLAYER_PED(i));
				}
			}
		}
	}
	void shootPed(Player target)
	{
		Ped selectedPed = game::GET_PLAYER_PED(target);
		Vector3 pedLoc = coordsOf(selectedPed);
		Vector3 targetLoc = GET_PED_BONE_COORDS(selectedPed, 24818, 0.f, 0.f, 0.f);
		Ped shooterPed;
		if (GET_CLOSEST_PED(pedLoc.x, pedLoc.y, pedLoc.z, 45.f, 1, 1, &shooterPed, 1, 1, 1)) {
			Vector3 shooterLoc = coordsOf(shooterPed);
			SHOOT_SINGLE_BULLET_BETWEEN_COORDS(shooterLoc.x, shooterLoc.y, shooterLoc.z + 2.f, targetLoc.x, targetLoc.y, targetLoc.z, 300, 1, $("weapon_heavysniper"), shooterPed, 1, 1, 345.f);
		}
		else game::notifyError("No Nearby Ped Found");
	}
	void dropWeapon(char *weapon, Ped recievingPed) {
		Hash pedm = $("csb_stripper_01");
		Hash weaponh = $(weapon);
		Vector3 coords = coordsOf(recievingPed);
		REQUEST_MODEL(pedm);
		while (!HAS_MODEL_LOADED(pedm))
			WAIT(0);
		if (HAS_MODEL_LOADED(pedm)) {
			Ped ped = CREATE_PED(26, pedm, coords.x, coords.y, coords.z + 5.f, 0, 1, 1);
			SET_MODEL_AS_NO_LONGER_NEEDED(pedm);
			SET_ENTITY_VISIBLE(ped, 0, 0);
			GIVE_WEAPON_TO_PED(ped, weaponh, 9999, 1, 1);
			SET_PED_DROPS_WEAPONS_WHEN_DEAD(ped, 1);
			SET_PED_DROPS_WEAPON(ped);
			APPLY_DAMAGE_TO_PED(ped, 9999, 1);
			SET_ENTITY_HEALTH(ped, 0);
			SET_ENTITY_COLLISION(ped, 0, 0);
			SET_ENTITY_AS_NO_LONGER_NEEDED(&ped);
		}
	}
	void attackCops(Player target)
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		if (!DOES_ENTITY_EXIST(playerPed)) return;

		static Hash pedModel = 0x5E3DA4A4;
		Hash weapon = $("weapon_pistol");
		STREAMING::REQUEST_MODEL(pedModel);
		while (!HAS_MODEL_LOADED(pedModel))
			WAIT(0);

		Vector3 targetloc = coordsOf(playerPed);
		Ped createdModel = CREATE_PED(26, pedModel, targetloc.x, targetloc.y, targetloc.z, 1, 1, 0);

		WEAPON::GIVE_WEAPON_TO_PED(createdModel, weapon, weapon, 9999, 9999);
		AI::TASK_COMBAT_PED(createdModel, playerPed, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(createdModel, false);
		PED::SET_PED_COMBAT_ABILITY(createdModel, 100);
		PED::SET_PED_AS_ENEMY(createdModel, 1);
		PED::SET_PED_COMBAT_RANGE(createdModel, 1000);
		PED::SET_PED_KEEP_TASK(createdModel, true);
		PED::SET_PED_AS_COP(createdModel, 1);
		PED::SET_PED_ALERTNESS(createdModel, 1000);
	}
	Ped attackPed(Player target, char* pedModel, char* weapon, bool cop, ePedType variation)
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		if (!DOES_ENTITY_EXIST(playerPed)) return -1;

		Hash pedHash = $(pedModel);
		Hash weaponHash = $(weapon);
		STREAMING::REQUEST_MODEL(pedHash);
		while (!HAS_MODEL_LOADED(pedHash))	WAIT(0);

		Vector3 targetloc = coordsOf(playerPed);
		Ped createdModel = CREATE_PED(variation, pedHash, targetloc.x, targetloc.y, targetloc.z, 1, 1, 0);

		WEAPON::GIVE_WEAPON_TO_PED(createdModel, weaponHash, weaponHash, 9999, 9999);
		AI::TASK_COMBAT_PED(createdModel, playerPed, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(createdModel, false);
		PED::SET_PED_COMBAT_ABILITY(createdModel, 100);
		PED::SET_PED_AS_ENEMY(createdModel, 1);
		PED::SET_PED_COMBAT_RANGE(createdModel, 1000);
		PED::SET_PED_KEEP_TASK(createdModel, true);
		PED::SET_PED_ALERTNESS(createdModel, 1000);
		if (cop) {
			PED::SET_PED_AS_COP(createdModel, 1);

			//attempt to set wanted level
			PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(target, 4, 1);
			PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(target, 1);
		}

		return createdModel;
	}
	void attackPed(Player target, char* pedModel, char* weapon, bool cop, ePedType variation, char* vehModel)
	{

		Ped playerPed = game::GET_PLAYER_PED(target);
		if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

		Hash vehHash = $(vehModel);
		Ped createdModels[4];
		Vehicle veh = 0ul;

		STREAMING::REQUEST_MODEL(vehHash);	while (!STREAMING::HAS_MODEL_LOADED(vehHash))	WAIT(0);

		Vector3 targetloc = game::addVector(coordsOf(playerPed), { 0, 0, 5.f });
		veh = vehicle::spawn(vehHash, playerPed, targetloc);

		//helps to avoid clipping issues
		WAIT(5);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		vehicle::upgradeMax(veh);

		//create peds and put them in the vehicle
		for (int i = 0; i < 8; i++) {

			//check we're not overfilling vehicle
			if (!VEHICLE::ARE_ANY_VEHICLE_SEATS_FREE(veh)) {
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED($(pedModel));
				break;
			}
			createdModels[i] = online::attackPed(target, pedModel, weapon, cop, variation);
			WAIT(0);

			PED::SET_PED_INTO_VEHICLE(createdModels[i], veh, -1);
		}
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(vehHash);
	}
	void attckSwat(Player target)
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		if (!DOES_ENTITY_EXIST(playerPed)) return;

		Hash pedModel = $("s_m_y_swat_01");
		Hash weapon = $("weapon_stungun");
		STREAMING::REQUEST_MODEL(pedModel);
		while (!HAS_MODEL_LOADED(pedModel))
			WAIT(0);

		Vector3 targetloc = coordsOf(playerPed);
		Ped createdModel = CREATE_PED(26, pedModel, targetloc.x, targetloc.y, targetloc.z, 1, 1, 0);

		WEAPON::GIVE_WEAPON_TO_PED(createdModel, weapon, weapon, 9999, 9999);
		AI::TASK_COMBAT_PED(createdModel, playerPed, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(createdModel, false);
		PED::SET_PED_COMBAT_ABILITY(createdModel, 100);
		PED::SET_PED_AS_ENEMY(createdModel, 1);
		PED::SET_PED_COMBAT_RANGE(createdModel, 1000);
		PED::SET_PED_KEEP_TASK(createdModel, true);
		PED::SET_PED_AS_COP(createdModel, 1);
		PED::SET_PED_ALERTNESS(createdModel, 1000);
	}
	void attackJesus(Player target)
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		if (!DOES_ENTITY_EXIST(playerPed)) return;

		static Hash pedModel = 0xCE2CB751;
		static Hash weapon = 0x6D544C99;
		REQUEST_MODEL(pedModel);
		while (!HAS_MODEL_LOADED(pedModel))
			WAIT(0);

		Vector3 targetloc = coordsOf(playerPed);
		Ped createdModel = CREATE_PED(26, pedModel, targetloc.x, targetloc.y, targetloc.z, 1, 1, 0);

		WEAPON::GIVE_WEAPON_TO_PED(createdModel, weapon, weapon, 9999, 9999);
		AI::TASK_COMBAT_PED(createdModel, playerPed, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(createdModel, false);
		PED::SET_PED_COMBAT_ABILITY(createdModel, 100);
		PED::SET_PED_AS_ENEMY(createdModel, 1);
		PED::SET_PED_COMBAT_RANGE(createdModel, 1000);
		PED::SET_PED_KEEP_TASK(createdModel, true);
		PED::SET_PED_ALERTNESS(createdModel, 1000);
	}
	void attackSwatRiot(Player target)
	{

		Ped playerPed = game::GET_PLAYER_PED(target);
		if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;

		Hash pedModel = $("s_m_y_swat_01");
		Hash vehModel = $("riot");
		Hash weapon = $("weapon_bullpupshotgun");
		Ped createdModels[4];
		Vehicle veh = 0ul;
		int unk[5];

		STREAMING::REQUEST_MODEL(vehModel);	while (!STREAMING::HAS_MODEL_LOADED(vehModel))	WAIT(0);

		Vector3 targetloc = game::addVector(coordsOf(playerPed), { 0, 0, 5.f });
		veh = vehicle::spawn(vehModel, playerPed, targetloc);

		//helps to avoid clipping issues
		WAIT(5);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		vehicle::upgradeMax(veh);

		STREAMING::REQUEST_MODEL(pedModel);	while (!STREAMING::HAS_MODEL_LOADED(pedModel))	WAIT(0);

		//create peds and put them in the vehicle
		for (int i = 0; i < 4; i++) {

			//check we're not overfilling vehicle
			if (!VEHICLE::ARE_ANY_VEHICLE_SEATS_FREE(veh)) {
				break;
			}
			createdModels[i] = PED::CREATE_PED(26, pedModel, targetloc.x, targetloc.y, targetloc.z, 1, 1, 0);

			PED::SET_PED_INTO_VEHICLE(createdModels[i], veh, -1);

			//Set ped properties and such
			WEAPON::GIVE_WEAPON_TO_PED(createdModels[i], weapon, weapon, 9999, 9999);
			ENTITY::SET_ENTITY_INVINCIBLE(createdModels[i], false);
			PED::SET_PED_COMBAT_ABILITY(createdModels[i], 100);
			PED::SET_PED_CAN_SWITCH_WEAPON(createdModels[i], true);
			AI::TASK_COMBAT_PED(createdModels[i], playerPed, 1, 1);
			PED::SET_PED_AS_ENEMY(createdModels[i], 1);
			PED::SET_PED_COMBAT_RANGE(createdModels[i], 1000);
			PED::SET_PED_KEEP_TASK(createdModels[i], true);
			PED::SET_PED_AS_COP(createdModels[i], 1000);
			PED::SET_PED_ALERTNESS(createdModels[i], 1000);
			ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&createdModels[i]);
		}
		//attempt to set wanted level
		PLAYER::SET_PLAYER_WANTED_LEVEL_NO_DROP(target, 4, 1);
		PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(target, 1);
	}
	void sendCops(int playerPed, Vector3 targetloc)
	{
		if (!DOES_ENTITY_EXIST(playerPed)) return;
		Hash guysex = $("s_m_y_cop_01");
		REQUEST_MODEL(guysex);
		while (!HAS_MODEL_LOADED(guysex))
			WAIT(0);
		int createdGuySex = CREATE_PED(26, guysex, targetloc.x, targetloc.y, targetloc.z, 1, 1, 0);

		SET_ENTITY_INVINCIBLE(createdGuySex, false);
		//
		int vehmodel = $("police3");
		REQUEST_MODEL(vehmodel);

		while (!HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		//			Vector3 coords = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER_PED_ID(), 0.0, 5.0, 0.0);
		Vehicle veh = vehicle::spawn("police3", createdGuySex);
		SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		//
		Hash railgun = $("weapon_pistol");
		GIVE_WEAPON_TO_PED(createdGuySex, railgun, railgun, 0, 1);
		SET_PED_INTO_VEHICLE(createdGuySex, veh, -1);
		TASK_COMBAT_PED(createdGuySex, playerPed, 1, 1);
		SET_ENTITY_INVINCIBLE(createdGuySex, false);
		SET_PED_COMBAT_ABILITY(createdGuySex, 100);
		SET_PED_CAN_SWITCH_WEAPON(createdGuySex, true);
		TASK_COMBAT_PED(createdGuySex, playerPed, 1, 1);
		SET_PED_AS_ENEMY(createdGuySex, 1);
		SET_PED_COMBAT_RANGE(createdGuySex, 1000);
		SET_PED_KEEP_TASK(createdGuySex, true);
		SET_PED_AS_COP(createdGuySex, 1000);
		SET_PED_ALERTNESS(createdGuySex, 1000);
	}
	void attackTanks(int playerPed, Vector3 targetloc)
	{
		if (!DOES_ENTITY_EXIST(playerPed)) return;
		Hash guysex = $("s_m_y_marine_01");
		REQUEST_MODEL(guysex);
		while (!HAS_MODEL_LOADED(guysex))
			WAIT(0);
		int createdGuySex = CREATE_PED(26, guysex, targetloc.x, targetloc.y, targetloc.z, 1, 1, 0);

		SET_ENTITY_INVINCIBLE(createdGuySex, false);
		//
		int vehmodel = $("rhino");
		REQUEST_MODEL(vehmodel);

		while (!HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		//			Vector3 coords = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER_PED_ID(), 0.0, 5.0, 0.0);
		Vehicle veh = vehicle::spawn("rhino", createdGuySex);
		SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		//
		SET_PED_INTO_VEHICLE(createdGuySex, veh, -1);
		TASK_COMBAT_PED(createdGuySex, playerPed, 1, 1);
		SET_ENTITY_INVINCIBLE(createdGuySex, false);
		SET_PED_COMBAT_ABILITY(createdGuySex, 100);
		SET_PED_CAN_SWITCH_WEAPON(createdGuySex, true);
		TASK_COMBAT_PED(createdGuySex, playerPed, 1, 1);
		SET_PED_AS_ENEMY(createdGuySex, 1);
		SET_PED_COMBAT_RANGE(createdGuySex, 1000);
		SET_PED_KEEP_TASK(createdGuySex, true);
		SET_PED_AS_COP(createdGuySex, 1000);
		SET_PED_ALERTNESS(createdGuySex, 1000);
	}
	void loop_esp(Player target, int r, int g, int b)
	{
		if (target != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(game::GET_PLAYER_PED(target)))
		{
			Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(target), false);
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

			Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(target), false);
			Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, r, g, b, 255);
		}
	}
	void loop_killpeds(Player target = PLAYER_ID())
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		Ped closestped = NULL;
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		int nearbyPed[arrSize];
		bool featureOnlineKillPeds = false;
		//Setup the array (vehicle Clearing)
		const int numElementsveh = 10;
		const int arrSizeveh = numElementsveh * 2 + 2;
		int vec[arrSizeveh];
		Vector3 Coordinates = GET_ENTITY_COORDS(playerPed, 1);
		//featureOnlineKillPeds = false;
		nearbyPed[0] = numElements;	//ped array
		vec[0] = numElementsveh;		//vehicle array
		int count = GET_PED_NEARBY_PEDS(playerPed, nearbyPed, -1);
		if (nearbyPed != NULL) {
			for (int i = 0; i < count; i++) {
				int offsettedID = i * 2 + 2;
				if (nearbyPed[offsettedID] != NULL && DOES_ENTITY_EXIST(nearbyPed[offsettedID])) {
					RequestControlOfEnt(nearbyPed[i]);
					if (NETWORK_HAS_CONTROL_OF_ENTITY(nearbyPed[i])) {
						SET_ENTITY_AS_MISSION_ENTITY((nearbyPed[i]), 1, 1);
						SET_PED_MONEY((nearbyPed[i]), 1000000);
						SET_ENTITY_COORDS(Entity(nearbyPed[i]), Coordinates.x, Coordinates.y, Coordinates.z + 2.5f, 1, 0, 0, 1);
						APPLY_DAMAGE_TO_PED((nearbyPed[i]), 450, 1);
						int count = GET_PED_NEARBY_VEHICLES(playerPed, vec);
						if (vec != NULL) {
							//Simple loop to go through results
							for (int i = 0; i < count; i++) {
								int offsettedID = i * 2 + 2;
								//Make sure it exists
								if (vec[offsettedID] != NULL && DOES_ENTITY_EXIST(vec[offsettedID])) {
									RequestControlOfEnt(vec[i]);
									if (NETWORK_HAS_CONTROL_OF_ENTITY(vec[i])) {
										SET_ENTITY_AS_MISSION_ENTITY((vec[i]), 1, 1);
										DELETE_VEHICLE(&vec[i]);
									}
								}
							}
						}
						SET_ENTITY_AS_NO_LONGER_NEEDED(&nearbyPed[i]);
						SET_PED_AS_NO_LONGER_NEEDED(&nearbyPed[i]);
						SET_ENTITY_AS_NO_LONGER_NEEDED(&vec[i]);
						DELETE_ENTITY(&nearbyPed[i]);
						printf("Peds Grabbed: %i \n", count);
						ATTACH_PORTABLE_PICKUP_TO_PED(playerPed, 1);
					}
				}
			}
		}
	}
	void loop_remoteCash(Player target) {
		DWORD64 par1 = 1;
		DWORD64 par2[5] = { 487, target, remoteDropAmount, remoteDropAmount, remoteDropAmount };
		DWORD64 par3 = 5;
		int iVar5;
		GAMEPLAY::SET_BIT(&iVar5, target);
		SCRIPT::TRIGGER_SCRIPT_EVENT(par1, &par2[0], par3, iVar5);
	}
	void loop_stealthR(Player target) {
		Any args[5];
		args[0] = 490;
		args[1] = target;
		args[2] = PLAYER::PLAYER_ID();
		args[3] = 1;
		args[4] = 50000;
		int playerId;
		GAMEPLAY::SET_BIT(&playerId, target);
		SCRIPT::TRIGGER_SCRIPT_EVENT(0x1, args, 5, playerId);
		GAMEPLAY::CLEAR_BIT(&playerId, target);

	}
	void loop_fuckCam(Player target)
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		Vector3 pCoords = GET_ENTITY_COORDS(playerPed, 0);
		ADD_EXPLOSION(pCoords.x, pCoords.y, pCoords.z + 15, 29, 999999.5f, false, true, 1.0f);

	}
	void loop_annoyBomb(Player target)
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		Vector3 pCoords = GET_ENTITY_COORDS(playerPed, 0);
		ADD_EXPLOSION(pCoords.x, pCoords.y, pCoords.z, 29, 9.0f, true, false, 0.0f);
	}
	void loop_forcefield(Player target)
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		Vector3 pCoords = GET_ENTITY_COORDS(playerPed, 0);
		ADD_EXPLOSION(pCoords.x, pCoords.y, pCoords.z, 7, 9.0f, false, true, 0.0f);

	}
	void loop_freezePlayer(Player target)
	{
		Ped playerPed = game::GET_PLAYER_PED(target);
		if (!NETWORK_HAS_CONTROL_OF_ENTITY(playerPed))
			RequestControlOfEnt(playerPed);
		if (NETWORK_HAS_CONTROL_OF_ENTITY(playerPed))
			CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
		else
			return;
	}
	void loop_massacre(Player target = PLAYER_ID())
	{
		float tempCoords1[3];
		DWORD tempHash;
		DWORD tempPed = game::GET_PLAYER_PED(target);
		DWORD tempVehicle;
		bool tick = 0;

		game::offsetFromEnt(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);

		// Kick away naughty players
		for (int i = 0; i <= 29; i++)
		{
			if (IS_PLAYER_TARGETTING_ENTITY(i, tempPed) || IS_PLAYER_FREE_AIMING_AT_ENTITY(i, tempPed))
			{
				if (!tick)
				{
					game::notifyBottom("~h~You~s~ are being aimed at. Taking care of it!");
					tick = true;
				}
				APPLY_FORCE_TO_ENTITY(game::GET_PLAYER_PED(i), 1, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 1, 1, 1, 1, 0, 1);
			}
		}

		// Kick away nearest vehicle
		tempVehicle = GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 400.0f, 0, 4);
		if (DOES_ENTITY_EXIST(tempVehicle)) APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);

		// Exploding vehicles
		switch (GET_RANDOM_INT_IN_RANGE(1, 10))
		{
		case 1: tempHash = 3945366167; break;
		case 2: tempHash = 92612664; break;
		case 3: tempHash = 1488164764; break;
		case 4: tempHash = 117401876; break;
		case 5: tempHash = 408192225; break;
		case 6: tempHash = 3863274624; break;
		case 7: tempHash = 165154707; break;
		case 8: tempHash = 1011753235; break;
		case 9: tempHash = 941800958; break;
		case 10: tempHash = 970385471; break;
		}

		tempVehicle = GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 15.f, tempHash, 0);
		if (ENTITY::DOES_ENTITY_EXIST(tempVehicle)) {
			APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
			NETWORK_EXPLODE_VEHICLE(tempVehicle, 1, 1, 1);
		}

		// Dying peds
		switch (GET_RANDOM_INT_IN_RANGE(1, 10))
		{
		case 1: tempHash = 1682622302; break;
		case 2: tempHash = 113504370; break;
		case 3: tempHash = 4244282910; break;
		case 4: tempHash = 808859815; break;
		case 5: tempHash = 1004114196; break;
		case 6: tempHash = 3696858125; break;
		case 7: tempHash = 921110016; break;
		case 8: tempHash = 880829941; break;
		case 9: tempHash = 1462895032; break;
		case 10: tempHash = 773063444; break;
		}

		game::offsetFromEnt(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
		tempPed = CREATE_PED(22, tempHash, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
		APPLY_FORCE_TO_ENTITY(tempPed, 1, 5.0f, 5.0f, 5.0f, 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
		EXPLODE_PED_HEAD(tempPed, 324506233);
		ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 26, 4.0f, 1, 0, 3.0f);

		// Water hydrants
		game::offsetFromEnt(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
		ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 13, 8.0f, 1, 0, 3.0f);

		// Zombies
		game::offsetFromEnt(tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f), tempCoords1);
		tempPed = CREATE_PED(22, -1404353274, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
		PED_TO_NET(tempPed);
		SET_PED_COMBAT_ABILITY(tempPed, 100);
		TASK_COMBAT_HATED_TARGETS_AROUND_PED(tempPed, 400.0f, 0);
	}
}

namespace lobby {

	/*void eg() {

	struct tpLoc {
	char* locName;
	Vector3 location;
	};

	Vector3 sShore = { 32, 23, 23 };

	tpLoc sandyShores = { "Sandy Shores Airfield", sShore };

	tpLoc BlaineCounty[]{ sandyShores };

	int loops = sizeof(BlaineCounty);

	for (int i = 0; i < loops; i++) {
	AddTeleport(BlaineCounty[i].locName, BlaineCounty[i].location);
	}
	}*/
	void kickAll(int restriction) {

		int counter;
		string msg = " ~w~Players from the lobby";

		for (int i = 0; i < 32; i++) {
			if (IS_PLAYER_PLAYING(i)) {
				if ((restriction == 0) || (restriction == 1 && online::isPlayerFriend(i)) || (restriction == 2 && !online::isPlayerFriend(i))) {

					if (!(i == PLAYER_ID())) {

						//execute function and add to counter
						online::remoteKick(i);
						counter++;
					}
				}
			}
		}
		//if enough executions were made do shit
		if (counter > 0) {
			string counterStr = static_cast<ostringstream*>(&(ostringstream() << counter))->str();
			game::notifyMap("You kicked ~y~" + counterStr + msg, 0);
		}
		else
			game::notifyError("0 Players Affected");
	}
	void kickVeh(int restriction) {

		int counter;
		string msg = " ~w~Players from their vehicles";

		for (int i = 0; i < 32; i++) {
			if (IS_PLAYER_PLAYING(i)) {
				if ((restriction == 0) || (restriction == 1 && online::isPlayerFriend(i)) || (restriction == 2 && !online::isPlayerFriend(i))) {

					if (!(i == PLAYER_ID())) {

						//execute function and add to counter
						if (PED::IS_PED_IN_ANY_VEHICLE(game::GET_PLAYER_PED(i), 1)) {
							player::kickVeh(i);
							counter++;
						}
					}
				}
			}
		}

		//if enough executions were made do shit
		if (counter > 0) {
			string counterStr = static_cast<ostringstream*>(&(ostringstream() << counter))->str();
			game::notifyMap("You kicked ~y~" + counterStr + msg, 0);
		}
		else
			game::notifyError("0 Players Affected");
	}
	void deleteVeh(int restriction) {

		int counter;
		string msg = " ~w~player vehicles";

		for (int i = 0; i < 32; i++) {
			if (IS_PLAYER_PLAYING(i)) {
				if ((restriction == 0) || (restriction == 1 && online::isPlayerFriend(i)) || (restriction == 2 && !online::isPlayerFriend(i))) {

					if (!(i == PLAYER_ID())) {

						//execute function and add to counter
						if (PED::IS_PED_IN_ANY_VEHICLE(game::GET_PLAYER_PED(i), 1)) {
							vehicle::deletePedVeh(game::GET_PLAYER_PED(i));
							counter++;
						}
					}
				}
			}
		}

		//if enough executions were made do shit
		if (counter > 0) {
			string counterStr = static_cast<ostringstream*>(&(ostringstream() << counter))->str();
			game::notifyMap("You deleted ~y~" + counterStr + msg, 0);
		}
		else
			game::notifyError("0 Players Affected");
	}
	void giveVeh(int restriction, char* vehicle) {

		int counter;
		string vehT = _GET_LABEL_TEXT(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(vehicle)));
		string msg = " ~w~Players " + vehT + "s";

		for (int i = 0; i < 32; i++) {
			if (IS_PLAYER_PLAYING(i)) {
				if ((restriction == 0) || (restriction == 1 && online::isPlayerFriend(i)) || (restriction == 2 && !online::isPlayerFriend(i))) {

					if (!(i == PLAYER_ID())) {

						//execute function and add to counter
						vehicle::spawn(vehicle, game::GET_PLAYER_PED(i));
						counter++;
					}
				}
			}
		}

		//if enough executions were made do shit
		if (counter > 0) {
			string counterStr = static_cast<ostringstream*>(&(ostringstream() << counter))->str();
			game::notifyMap("You gave ~y~" + counterStr + msg, 0);
		}
		else
			game::notifyError("0 Players Affected");

	}
	void removeWeps(int restriction) {

		int counter;
		string msg = " ~w~Players weapons";

		for (int i = 0; i < 32; i++) {
			if (IS_PLAYER_PLAYING(i)) {
				if ((restriction == 0) || (restriction == 1 && online::isPlayerFriend(i)) || (restriction == 2 && !online::isPlayerFriend(i))) {

					if (!(i == PLAYER_ID())) {

						//execute function and add to counter
						weapon::removeAll(game::GET_PLAYER_PED(i));
						counter++;
					}
				}
			}
		}

		//if enough executions were made do shit
		if (counter > 0) {
			string counterStr = static_cast<ostringstream*>(&(ostringstream() << counter))->str();
			game::notifyMap("You removed ~y~" + counterStr + msg, 0);
		}
		else
			game::notifyError("0 Players Affected");
	}
	void explode(int restriction) {

		int counter;
		string msg = " ~w~Players";

		for (int i = 0; i < 32; i++) {
			if (IS_PLAYER_PLAYING(i)) {
				if ((restriction == 0) || (restriction == 1 && online::isPlayerFriend(i)) || (restriction == 2 && !online::isPlayerFriend(i))) {

					if (!(i == PLAYER_ID())) {

						//execute function and add to counter
						online::loop_annoyBomb(i);
						counter++;
					}
				}
			}
		}

		//if enough executions were made do shit
		if (counter > 0) {
			string counterStr = static_cast<ostringstream*>(&(ostringstream() << counter))->str();
			game::notifyMap("You Exploded ~y~" + counterStr + msg, 0);
		}
		else
			game::notifyError("Exploded 0" + msg);
	}
	void remote50K(int restriction) {

		int counter;
		string msg = " ~w~Players ~g~50K";

		for (int i = 0; i < 32; i++) {
			if (IS_PLAYER_PLAYING(i)) {
				if ((restriction == 0) || (restriction == 1 && online::isPlayerFriend(i)) || (restriction == 2 && !online::isPlayerFriend(i))) {

					if (!(i == PLAYER_ID())) {

						//execute function and add to counter
						online::remote50k(i);
						counter++;
					}
				}
			}
		}

		//if enough executions were made do shit
		if (counter > 0) {
			string counterStr = static_cast<ostringstream*>(&(ostringstream() << counter))->str();
			game::notifyMap("You gave ~y~" + counterStr + msg, 0);
		}
		else
			game::notifyError("Gave 0" + msg);
	}
}

typedef struct VECTOR2 {
	float x, y;
};
typedef struct VECTOR2_2 {
	float w, h;
};
typedef struct RGBAF {
	int r, g, b, a, f;
};
void smallRect(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.R, rgba.G, rgba.B, rgba.A);
}
void littleItsyBitsySmallText(const char * text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}
RGBA Smallbannerrect = { 0, 0, 0, 225 };
RGBAF Smallbannertext{ 255, 255, 255, 255, 6 };

void AddSmallInfo(char* text, short line)
{
	if (line == 1) {
		smallRect(Smallbannerrect, { 0.827f - 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
	}
	littleItsyBitsySmallText(text, Smallbannertext, { 0.81f - 0.175f , (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);

}
float Get3DDistance(Vector3 a, Vector3 b) {
	float x = pow((a.x - b.x), 2);
	float y = pow((a.y - b.y), 2);
	float z = pow((a.z - b.z), 2);
	return sqrt(x + y + z);
}
void SelPlayerInfoStolenFromGalaxyLOLFIghtME(char* playerName, Player p){


	Ped ped = PLAYER::GET_PLAYER_PED(p);
	RequestControlOfEnt(ped);
	float health = ENTITY::GET_ENTITY_HEALTH(ped);
	float maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
	float healthPercent = health * 100 / maxHealth;
	ostringstream Health; Health << "Health:~s~ " << healthPercent;
	float armor = PED::GET_PED_ARMOUR(ped);
	float maxArmor = PLAYER::GET_PLAYER_MAX_ARMOUR(p);
	float armorPercent = armor * 100 / maxArmor;
	ostringstream Armor; Armor << "Armor:~s~ " << armorPercent;
	bool alive = !PED::IS_PED_DEAD_OR_DYING(ped, 1);
	char* aliveStatus;
	if (alive) aliveStatus = "Yes"; else aliveStatus = "No";
	ostringstream Alive; Alive << "Alive:~s~ " << aliveStatus;
	bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
	ostringstream VehicleModel; VehicleModel << "Vehicle:~s~ ";
	ostringstream Speed; Speed << "Speed:~s~ ";
	ostringstream IsInAVehicle; IsInAVehicle << "In Vehicle:~s~ ";
	if (inVehicle) {
		IsInAVehicle << "Yes";
		Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		VehicleModel << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
		float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		float vehSpeedConverted;
		vehSpeedConverted = round(vehSpeed * 1.6);
		Speed << vehSpeedConverted << " KM/H";
	}
	else {
		IsInAVehicle << "No";
		float speed = round(ENTITY::GET_ENTITY_SPEED(ped) * 100) / 100;
		Speed << speed << " M/S";
		VehicleModel << "--------";
	}
	ostringstream WantedLevel; WantedLevel << "Wanted Level:~s~ " << PLAYER::GET_PLAYER_WANTED_LEVEL(p);
	ostringstream Weapon; Weapon << "Weapon: ~s~";
	Hash weaponHash;
	if (WEAPON::GET_CURRENT_PED_WEAPON(ped, &weaponHash, 1)) {
		char* weaponName;
		if (weaponHash == 2725352035) {
			weaponName = "Unarmed";
		}
		else if (weaponHash == 2578778090) {
			weaponName = "Knife";
		}
		else if (weaponHash == 0x678B81B1) {
			weaponName = "Nightstick";
		}
		else if (weaponHash == 0x4E875F73) {
			weaponName = "Hammer";
		}
		else if (weaponHash == 0x958A4A8F) {
			weaponName = "Bat";
		}
		else if (weaponHash == 0x440E4788) {
			weaponName = "GolfClub";
		}
		else if (weaponHash == 0x84BD7BFD) {
			weaponName = "Crowbar";
		}
		else if (weaponHash == 0x1B06D571) {
			weaponName = "Pistol";
		}
		else if (weaponHash == 0x5EF9FEC4) {
			weaponName = "Combat Pistol";
		}
		else if (weaponHash == 0x22D8FE39) {
			weaponName = "AP Pistol";
		}
		else if (weaponHash == 0x99AEEB3B) {
			weaponName = "Pistol 50";
		}
		else if (weaponHash == 0x13532244) {
			weaponName = "Micro SMG";
		}
		else if (weaponHash == 0x2BE6766B) {
			weaponName = "SMG";
		}
		else if (weaponHash == 0xEFE7E2DF) {
			weaponName = "Assault SMG";
		}
		else if (weaponHash == 0xBFEFFF6D) {
			weaponName = "Assault Riffle";
		}
		else if (weaponHash == 0x83BF0278) {
			weaponName = "Carbine Riffle";
		}
		else if (weaponHash == 0xAF113F99) {
			weaponName = "Advanced Riffle";
		}
		else if (weaponHash == 0x9D07F764) {
			weaponName = "MG";
		}
		else if (weaponHash == 0x7FD62962) {
			weaponName = "Combat MG";
		}
		else if (weaponHash == 0x1D073A89) {
			weaponName = "Pump Shotgun";
		}
		else if (weaponHash == 0x7846A318) {
			weaponName = "Sawed-Off Shotgun";
		}
		else if (weaponHash == 0xE284C527) {
			weaponName = "Assault Shotgun";
		}
		else if (weaponHash == 0x9D61E50F) {
			weaponName = "Bullpup Shotgun";
		}
		else if (weaponHash == 0x3656C8C1) {
			weaponName = "Stun Gun";
		}
		else if (weaponHash == 0x05FC3C11) {
			weaponName = "Sniper Rifle";
		}
		else if (weaponHash == 0x0C472FE2) {
			weaponName = "Heavy Sniper";
		}
		else if (weaponHash == 0xA284510B) {
			weaponName = "Grenade Launcher";
		}
		else if (weaponHash == 0x4DD2DC56) {
			weaponName = "Smoke Grenade Launcher";
		}
		else if (weaponHash == 0xB1CA77B1) {
			weaponName = "RPG";
		}
		else if (weaponHash == 0x42BF8A85) {
			weaponName = "Minigun";
		}
		else if (weaponHash == 0x93E220BD) {
			weaponName = "Grenade";
		}
		else if (weaponHash == 0x2C3731D9) {
			weaponName = "Sticky Bomb";
		}
		else if (weaponHash == 0xFDBC8A50) {
			weaponName = "Smoke Grenade";
		}
		else if (weaponHash == 0xA0973D5E) {
			weaponName = "BZGas";
		}
		else if (weaponHash == 0x24B17070) {
			weaponName = "Molotov";
		}
		else if (weaponHash == 0x060EC506) {
			weaponName = "Fire Extinguisher";
		}
		else if (weaponHash == 0x34A67B97) {
			weaponName = "Petrol Can";
		}
		else if (weaponHash == 0xFDBADCED) {
			weaponName = "Digital scanner";
		}
		else if (weaponHash == 0x88C78EB7) {
			weaponName = "Briefcase";
		}
		else if (weaponHash == 0x23C9F95C) {
			weaponName = "Ball";
		}
		else if (weaponHash == 0x497FACC3) {
			weaponName = "Flare";
		}
		else if (weaponHash == 0xF9E6AA4B) {
			weaponName = "Bottle";
		}
		else if (weaponHash == 0x61012683) {
			weaponName = "Gusenberg";
		}
		else if (weaponHash == 0xC0A3098D) {
			weaponName = "Special Carabine";
		}
		else if (weaponHash == 0xD205520E) {
			weaponName = "Heavy Pistol";
		}
		else if (weaponHash == 0xBFD21232) {
			weaponName = "SNS Pistol";
		}
		else if (weaponHash == 0x7F229F94) {
			weaponName = "Bullpup Rifle";
		}
		else if (weaponHash == 0x92A27487) {
			weaponName = "Dagger";
		}
		else if (weaponHash == 0x083839C4) {
			weaponName = "Vintage Pistol";
		}
		else if (weaponHash == 0x7F7497E5) {
			weaponName = "Firework";
		}
		else if (weaponHash == 0xA89CB99E) {
			weaponName = "Musket";
		}
		else if (weaponHash == 0x3AABBBAA) {
			weaponName = "Heavy Shotgun";
		}
		else if (weaponHash == 0xC734385A) {
			weaponName = "Marksman Rifle";
		}
		else if (weaponHash == 0x63AB0442) {
			weaponName = "Homing Launcher";
		}
		else if (weaponHash == 0xAB564B93) {
			weaponName = "Proximity Mine";
		}
		else if (weaponHash == 0x787F0BB) {
			weaponName = "Snowball";
		}
		else if (weaponHash == 0x47757124) {
			weaponName = "Flare Gun";
		}
		else if (weaponHash == 0xE232C28C) {
			weaponName = "Garbage Bag";
		}
		else if (weaponHash == 0xD04C944D) {
			weaponName = "Handcuffs";
		}
		else if (weaponHash == 0x0A3D4D34) {
			weaponName = "Combat PDW";
		}
		else if (weaponHash == 0xDC4DB296) {
			weaponName = "Marksman Pistol";
		}
		else if (weaponHash == 0xD8DF3C3C) {
			weaponName = "Brass Knuckles";
		}
		else if (weaponHash == 0x6D544C99) {
			weaponName = "Railgun";
		}
		else {
			weaponName = "Unarmed";
		}
		Weapon << weaponName;
	}
	else Weapon << "Unarmed";
	Vector3 myCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
	ostringstream Zone; Zone << "Zone: ~s~" << UI::_GET_LABEL_TEXT(ZONE::GET_NAME_OF_ZONE(coords.x, coords.y, coords.z));
	Hash streetName, crossingRoad;
	PATHFIND::GET_STREET_NAME_AT_COORD(coords.x, coords.y, coords.z, &streetName, &crossingRoad);
	ostringstream Street; Street << "Street: ~s~" << UI::GET_STREET_NAME_FROM_HASH_KEY(streetName);
	float distance = Get3DDistance(coords, myCoords);
	ostringstream Distance; Distance << "Distance: ~s~";

	if (distance > 1000) {
		distance = round((distance / 1000) * 100) / 100;
		Distance << distance << " Kilometers";
	}
	else {
		distance = round(distance * 1000) / 100;
		Distance << distance << " Meters";
	}

	
    AddSmallInfo((char*)Health.str().c_str(), 0);
	AddSmallInfo((char*)Armor.str().c_str(), 1);
	AddSmallInfo((char*)Alive.str().c_str(), 2);
	AddSmallInfo((char*)IsInAVehicle.str().c_str(), 3);
	AddSmallInfo((char*)VehicleModel.str().c_str(), 4);
	AddSmallInfo((char*)Speed.str().c_str(), 5);
	AddSmallInfo((char*)WantedLevel.str().c_str(), 6);
	AddSmallInfo((char*)Weapon.str().c_str(), 7);
	AddSmallInfo((char*)Zone.str().c_str(), 8);
	AddSmallInfo((char*)Street.str().c_str(), 9);
	AddSmallInfo((char*)Distance.str().c_str(), 10);

}