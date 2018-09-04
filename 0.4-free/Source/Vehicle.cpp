#include "stdafx.h"

rgba PrimarySpawnRGBVeh = { 0, 0, 0 };
rgba SecondarySpawnRGBVeh = { 0, 255, 0 };

namespace VehicleOptions
{
	bool godmodebool = false;
	void godmode()
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, godmodebool);
			ENTITY::SET_ENTITY_PROOFS(vehicle, godmodebool, godmodebool, godmodebool, godmodebool, godmodebool, godmodebool, godmodebool, godmodebool);
			VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
			VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
			VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, godmodebool);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, godmodebool);
			VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !godmodebool);
			VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !godmodebool);
			VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !godmodebool);
			VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !godmodebool);
			VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !godmodebool);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !godmodebool);
		}
	}

	void fix()
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
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
			}
		}
	}

	bool bulletprooftiresbool = false;
	void bulletprooftires()
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !bulletprooftiresbool);
		}
	}

	bool speedobool = false;
	void speedo()
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			float speed = ENTITY::GET_ENTITY_SPEED(vehicle) * 2.23694f;
			Speedo(speed);
		}
	}

	bool rainbowbool = false;
	rgba primary{ 255, 0, 0 };
	rgba secondary{ 0, 255, 0 };
	void rainbow()
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			if (primary.r > 0 && primary.b == 0)
			{
				primary.r--;
				primary.g++;
			}
			if (primary.g > 0 && primary.r == 0)
			{
				primary.g--;
				primary.b++;
			}
			if (primary.b > 0 && primary.g == 0)
			{
				primary.r++;
				primary.b--;
			}
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, primary.r, primary.g, primary.b);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, secondary.r, secondary.g, secondary.b);
		}
	}
	/*  Sudo Mod
	bool vehiclegravitybool = true;
	void vehiclegravity()
	{
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_GRAVITY }, vehiclegravitybool ? 9.8f : 0.f);
	}*/

	void maxvehicle()
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
		{
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
			}
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Gradient Free");
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehicle, 0, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehicle, 0, 0, 0);
		}
	}

	bool randommodsbool = false;
	void randommods()
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
		for (int i = 0; i < 50; i++)
		{
			VEHICLE::SET_VEHICLE_MOD(vehicle, i, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i)), false);
		}
	}

	float accelerationfloat = 1.f;
	float brakeforcefloat = 1.f;
	float tractionfloat = 1.f;
	float deformfloat = 1.f;
	float upshiftfloat = 1.f;
	float suspensionfloat = 1.f;
	/*{
	accelerationfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_ACCELERATION });
	brakeforcefloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_BRAKEFORCE });
	tractionfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MIN });
	deformfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING,  OFFSET_VEHICLE_HANDLING_DEFORM_MULTIPLIER });
	upshiftfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_UPSHIFT });
	suspensionfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_SUSPENSION_FORCE });
	}
	void acceleration()
	{
	Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_ACCELERATION }, accelerationfloat);
	}
	void brakeforce()
	{
	Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_BRAKEFORCE }, brakeforcefloat);
	}
	void traction()
	{
	Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MIN }, tractionfloat);
	}
	void deform()
	{
	Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_DEFORM_MULTIPLIER }, deformfloat);
	}
	void upshift()
	{
	Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_UPSHIFT }, upshiftfloat);
	}
	void suspension()
	{
	Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_SUSPENSION_FORCE }, suspensionfloat);
	}*/

	bool spawnincar = 1;
	bool spawnmaxed = 0;

	void Spawn(std::string vehicle)
	{
		Hash model = GAMEPLAY::GET_HASH_KEY((char*)_strdup(vehicle.c_str()));
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
			int netId = NETWORK::VEH_TO_NET(veh);
			if (NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(netId))
			{
				ENTITY::_NETWORK_SET_ENTITY_AS_NETWORKED_ENTITY(veh, TRUE);
				if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(netId, TRUE);
			}
			DECORATOR::DECOR_REGISTER("Player_Vehicle", 3);
			DECORATOR::DECOR_REGISTER("PV_Slot", 3);
			DECORATOR::DECOR_REGISTER("Veh_Modded_By_Player", 3);
			DECORATOR::DECOR_SET_INT(veh, "Player_Vehicle", NETWORK::_0xBC1D768F2F5D6C05(PLAYER::PLAYER_ID()));
			DECORATOR::DECOR_SET_INT(veh, "Veh_Modded_By_Player", GAMEPLAY::GET_HASH_KEY(PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())));
			DECORATOR::DECOR_SET_INT(veh, "Not_Allow_As_Saved_Veh", 0);
			DECORATOR::DECOR_SET_BOOL(veh, "IgnoredByQuickSave", 0);

			int var;
			if (DECORATOR::DECOR_EXIST_ON(veh, "MPBitset"))
			{
				var = DECORATOR::DECOR_GET_INT(veh, "MPBitset");
			}
			GAMEPLAY::SET_BIT(&var, 3);
			DECORATOR::DECOR_SET_INT(veh, "MPBitset", var);

			VEHICLE::SET_VEHICLE_IS_STOLEN(veh, false);
			if (!STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_ID_ADMIN_WEB"), &veh, 1))
			{
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_ID_ADMIN_WEB"), veh, 1);
			}

			if (spawnmaxed) {

				VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
				for (int i = 0; i < 50; i++)
				{
					VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
				}
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "Gradient Free");
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, PrimarySpawnRGBVeh.r, PrimarySpawnRGBVeh.g, PrimarySpawnRGBVeh.b);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, SecondarySpawnRGBVeh.r, SecondarySpawnRGBVeh.g, SecondarySpawnRGBVeh.b);
			}

			if (spawnincar) { PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1); }
			WAIT(150);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

			//	return veh;
		}
		//return -1;
	}

	void opendoors()
	{
		for (int dad = 0; dad < 100; dad++)
		{
			for (int i = 0; i < 12; i++)
			{
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), i, false, true);
			}
		}
	}

	void closedoors()
	{
		VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false), true);
	}

	void flip()
	{
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false));
	}
	/*Sudo Mod
	bool seatbeltbool = false;
	void seatbelt()
	{
		Memory::set_value<DWORD>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_SEATBELT }, seatbeltbool ? 0xC9 : 0xC8);
	}*/

	bool enginealwaysonbool = false;
	void enginealwayson()
	{
		VEHICLE::SET_VEHICLE_ENGINE_ON(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), enginealwaysonbool, enginealwaysonbool, enginealwaysonbool);
		VEHICLE::SET_VEHICLE_LIGHTS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), 0);
		//VEHICLE::_0x1FD09E7390A74D54(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true), 2);
	}

	void changemod(int type, int index)
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		if (index == -1)
		{
			VEHICLE::REMOVE_VEHICLE_MOD(veh, type);
		}
		else
		{
			VEHICLE::SET_VEHICLE_MOD(veh, type, index, false);
		}
	}

	bool hornboostbool = false;
	void hornboost()
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		if (AUDIO::IS_HORN_ACTIVE(veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 50.f);
		}
	}

	bool allplayerhornboostbool = false;
	void allplayerhornboost()
	{
		for (int i = 0; i < 30; i++)
		{
			if (i != PLAYER::PLAYER_ID())
			{
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
				if (AUDIO::IS_HORN_ACTIVE(veh))
				{
					RequestControlOfEnt(veh);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 50.f);
				}
			}
		}
	}

	bool allplayershornbool = false;
	void allplayershorn()
	{
		for (int i = 0; i < 30; i++)
		{
			if (i != PLAYER::PLAYER_ID())
			{
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
				RequestControlOfEnt(veh);
				AUDIO::_SOUND_VEHICLE_HORN_THIS_FRAME(veh);
			}
		}
	}

	bool fuckedhandling[MAX_PLAYERS] = { false };
	void fuckhandling(Player player)
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_STEER_BIAS(veh, fuckedhandling[player] ? 1.0f : 0.0f);
	}

	bool vehiclefixloopbool = false;
	void vehiclefixloop()
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		VEHICLE::SET_VEHICLE_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, true);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		if (VEHICLE::_IS_VEHICLE_DAMAGED(vehicle))
		{
			for (int i = 0; i < 10; i++)
			{
				try {
					VEHICLE::SET_VEHICLE_TYRE_FIXED(vehicle, i);
				}
				catch (...) {
					return;
				}
			}
		}
	}
	void save(char * name)
	{
		std::string dir = ".\\GradientFree\\Favorite\\" + (std::string)name + ".SinCool";
		WritePrivateProfileStringA("FACT", "Sinfool", "is SinCool", strdup(dir.c_str()));
	
	}
}
/*
std::vector<std::string> listFiles(LPCSTR directory)
{
	std::vector<std::string> tempVector;
	int fileCount = 0;
	std::stringstream tempStringStream;
	for (auto & collectedFiles : std::experimental::filesystem::v1::directory_iterator(directory)) {
		tempStringStream << collectedFiles;
		std::string testing = tempStringStream.str();
		if (testing.substr(testing.find_last_of(".") + 1) == "Thenecromance") {
			unsigned foundAmount = testing.find_last_of("/\\");
			std::string TempHolder = testing.substr(0, foundAmount);
			std::string TempHolder2 = testing.substr(foundAmount + 1);
			tempVector.push_back(TempHolder2.substr(0, TempHolder2.find(".", 0)));
		}
	}
	return tempVector;
}*/