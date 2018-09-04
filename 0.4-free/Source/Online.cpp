#include "stdafx.h"
#include "data.h"
	int selectedplayer;

	void teleportto()
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedplayer), false);
		Entity entity = (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) == 1) ? PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false) : PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS(entity, coords.x, coords.y, coords.z, false, false, false, false);
	}

	bool pedcashbool[MAX_PLAYERS] = { false }; // <- dont use
	void pedcash(Player target) {
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		constexpr int CashHash = -422877666;
		int PickupHash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_WALLET");
		STREAMING::REQUEST_MODEL(CashHash);
		while (!STREAMING::HAS_MODEL_LOADED(CashHash)) WAIT(0);
		OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, coords.x, coords.y, coords.z, 0, 2000, CashHash, false, true);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(CashHash);
	}

	void bagcash(Player target) {

		Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		int numBags = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(2, 6);
		int cashMoneyBaby = (GAMEPLAY::GET_RANDOM_INT_IN_RANGE(4000, 12001) / numBags);
		cashMoneyBaby = (int)round(cashMoneyBaby);

		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"));
		while (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01")))
			WAIT(0);
		OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_CASE"), pos.x, pos.y, pos.z + 0.5f, 0, cashMoneyBaby, GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"), FALSE, TRUE);

	}

	bool freezebool[MAX_PLAYERS] = { false };
	void freeze(Player target) {
		if (target != PLAYER::PLAYER_ID())
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
			{
				Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(vic);
				AI::CLEAR_PED_TASKS(vic);
				AI::CLEAR_PED_SECONDARY_TASK(vic);
			}
		}
	}

	bool displaytalkerbool = false;
	void displaytalker()
	{
		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			if (NETWORK::NETWORK_IS_PLAYER_TALKING(i))
			{
				Talker(i);
			}
		}
	}

	bool allesplinebool = false;
	bool esplinesbool[MAX_PLAYERS] = { false };
	void espline(Player target)
	{
		if (target != PLAYER::PLAYER_ID())
		{
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
			{
				Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
				Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
				GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 0, 255, 0, 255);
			}
		}
	}

	bool allespboxbool = false;
	bool espboxbool[MAX_PLAYERS] = { false };
	void espbox(Player target)
	{
		if (target != PLAYER::PLAYER_ID())
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

			GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top3world.x, top3world.y, top3world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, top4world.x, top4world.y, top4world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top1world.x, top1world.y, top1world.z, 0, 255, 0, 255);

			GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom3world.x, bottom3world.y, bottom3world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(bottom4world.x, bottom4world.y, bottom4world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 255, 0, 255);

			GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, 0, 255, 0, 255);
			GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 255, 0, 255);
		}
	}

	bool espnameallbool = false;
	bool espnamebool[MAX_PLAYERS] = { false };
	void espname(Player target)
	{
		if (target != PLAYER::PLAYER_ID())
		{
			Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
			vector2 screenPos;
			GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(entitylocation.x, entitylocation.y, entitylocation.z, &screenPos.x, &screenPos.y);
			UI::SET_TEXT_OUTLINE();
			Menu::drawText(PLAYER::GET_PLAYER_NAME(target),4,  screenPos.x, screenPos.y, 0.4f, 0.4f , options, false);
		}
	}

	void instacrash(Player target)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
		{
			RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
			AI::CLEAR_PED_TASKS_IMMEDIATELY(target);
			Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
			for (auto crashObject : blacklistedCrashObjects)
			{
				OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(&crashObject[0u]), playerCoords.x, playerCoords.y, playerCoords.z, true, true, true);
			}
		}
	}

	void shakecam(Player target)
	{
		Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 4, 1000.f, false, true, 1000.f);
	}

	void removeweapons(Player target)
	{
		WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
	}

	void ramWithVeh(Player target)
	{
		Hash model = GAMEPLAY::GET_HASH_KEY("trophytruck2");
		if (STREAMING::IS_MODEL_VALID(model))
		{
			for (int i = 0; i < 3; i++)
			{
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
				float forward = 10.f;
				float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
				float xVector = forward * sin(degToRad(heading)) * -1.f;
				float yVector = forward * cos(degToRad(heading));
				Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x - xVector, ourCoords.y - yVector, ourCoords.z, heading, true, true);
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 250);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}
		}
	}


	bool rploopbool = false;
	int ticker = 0;
	void rploop()
	{
		Player player = PLAYER::PLAYER_ID();
		Vector3 pos = { 1500.0f,1500.0f,1500.0f };
		if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) == 0)
		{
			PLAYER::SET_PLAYER_WANTED_LEVEL(player, 5, false);
			PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(player, 5);
			if (PLAYER::GET_PLAYER_WANTED_LEVEL(player) > 4)
			{
				PLAYER::SET_PLAYER_WANTED_CENTRE_POSITION(player, &pos,1,1);
			}
		}
		else
		{
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(player);
		}
	}

	void teleportall(Player target)
	{
		for (int i2 = 0; i2 < 2; i2++)
		{
			Vector3 targetCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
			for (int i = 0; i < MAX_PLAYERS; i++)
			{
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)) && i != target)
				{
					AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					int netScene = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(targetCoords.x, targetCoords.y, targetCoords.z, 0.f, 0.f, 0.f, 0, 0, 0, 0.f);
					NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), netScene, "amb@code_human_cower@female@base", "base", 8.f, -8.f, 2, 0, 100.f, 0);
					NETWORK::NETWORK_START_SYNCHRONISED_SCENE(netScene);
				}
			}
			WAIT(150);
			for (int i = 0; i < MAX_PLAYERS; i++)
			{
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)) && i != target)
				{
					AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				}
			}
		}
	}

	void teleporttome(Player player)
	{
		for (int i = 0; i < 2; i++)
		{
			Ped destPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
			Ped ourPed = PLAYER::PLAYER_PED_ID();
			Vector3 ourLoc = ENTITY::GET_ENTITY_COORDS(ourPed, false);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(destPed);
			int netScene = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(ourLoc.x, ourLoc.y, ourLoc.z, 0.f, 0.f, 0.f, 0, 0, 0, 0.f);
			NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(destPed, netScene, "amb@code_human_cower@female@base", "base", 8.f, -8.f, 2, 0, 100.f, 0);
			NETWORK::NETWORK_START_SYNCHRONISED_SCENE(netScene);
			WAIT(150);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(destPed);
			NETWORK::NETWORK_STOP_SYNCHRONISED_SCENE(netScene);
		}
	}

	void attach(Player player)
	{
		if (player != PLAYER::PLAYER_ID())
		{
			ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, true, false, true, 2, true);
		}
	}

	void detach()
	{
		ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
	}

	void clone(Player player)
	{
		PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), 0.f, true, false);
	}

	void cloneenemey(Player player)
	{
		Ped ped = PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), 0.f, true, false);
		PED::SET_PED_AS_ENEMY(ped, true);
	}

	void teleportinveh(Player player)
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
		for (int i = -1; i < 16; i++)
		{
			if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, i);
				return;
			}
		}
	}

	void kickfromveh(Player player)
	{
		RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
		AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
		AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player));
	}
	void kickallfromveh()
	{
		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			if (i != PLAYER::PLAYER_ID())
			{
				kickfromveh(i);
			}
		}
	}

	void explode(Player target)
	{
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), 0);
		FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
	}

	void killall()
	{
		for (int i = 0; i < MAX_PLAYERS; i++)
		{
			if (i != PLAYER::PLAYER_ID())
			{
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(MAX_PLAYERS), 0);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
			}
		}
	}