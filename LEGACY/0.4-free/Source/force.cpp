#include "stdafx.h"

int selectedPlayer = 0;


bool RequestNetworkControl(uint vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}
void RequestingControl(Entity e)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
	if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e))
		WAIT(0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
}
bool forceexplodewave = false;
void ForceExplodeWavePED()
{
	if (IsKeyDown(VK_ADD))
	{
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		Ped ped[arrSize];
		ped[0] = numElements;
		int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
		if (ped != NULL)
		{
			for (int i = 1; i <= count; i++)
			{
				int offsettedID = i;
				if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
				{
					int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
					RequestNetworkControl(ped[offsettedID]);
					ENTITY::SET_ENTITY_HEALTH(ped[offsettedID], 0);
				}
			}
		}
	}
}
void ForceExplodeWave()
{
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], true);
				FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, 0.5f, true, true, 1.0f);

				char *dict = "rcmcollect_paperleadinout@";
				char *anim = "meditiate_idle";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			}
		}
	}
}

void GiveWeaponPed(int Ped, int WeaponHash)
{
	WEAPON::GIVE_WEAPON_TO_PED(Ped, WeaponHash, 9999, 1, 1);

}

void DeletePed(int pedID)
{
	if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pedID))
		while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pedID));

	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(pedID, 1, 1);
	PED::DELETE_PED(&pedID);
}

void makePedHostile(uint Ped, int Target, bool choporswat = false, bool isClone = false)
{
	if (choporswat)
	{
		AI::TASK_COMBAT_PED(Ped, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 16);
		PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
	}
	else
	{
		if (isClone)
		{
			int Hash = ENTITY::GET_ENTITY_MODEL(Ped);
			DeletePed(Ped);

			STREAMING::REQUEST_MODEL(Hash);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(Target), 1);
			if (STREAMING::HAS_MODEL_LOADED(Hash))
			{
				int newPed = PED::CREATE_PED(21, Hash, coords.x, coords.y, coords.z, 0, 1, 0);
				if (ENTITY::GET_ENTITY_HEALTH(newPed) == ENTITY::GET_ENTITY_MAX_HEALTH(newPed))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hash);
					RequestNetworkControl(newPed);
					AI::TASK_COMBAT_PED(newPed, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 16);
					PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
				}
			}
		}
		else
		{
			int TargetHandle = PLAYER::GET_PLAYER_PED(Target);
			AI::TASK_COMBAT_PED(Ped, TargetHandle, 0, 16);
		}
	}
}

bool mcriot = false;
void MCRiot()
{
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);
				GiveWeaponPed(ped[offsettedID], 0x47757124);
				makePedHostile(ped[offsettedID], TargetHandle, true);
			}
		}
	}
}
bool mcdance = false;
void MCDance()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);
				char *dict = "mini@strip_club@private_dance@part1";
				char *anim = "priv_dance_p1";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(ped[offsettedID], dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			}
		}
	}
}
void MCPushups()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);
				char *dict = "amb@world_human_push_ups@male@base";
				char *anim = "base";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(ped[offsettedID], dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			}
		}
	}
}
//amb@world_human_push_ups@male@base", "base"
void MCFollow()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
				PED::SET_PED_AS_GROUP_LEADER(PLAYER::PLAYER_PED_ID(), my_group);
				PED::SET_PED_AS_GROUP_MEMBER(ped[offsettedID], my_group);
			}
		}
	}
}
void MCBurn()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(ped[offsettedID], true);
				FIRE::ADD_OWNED_EXPLOSION(PLAYER::PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 12, 5, true, true, 0);

			}
		}
	}
}
void MCWater()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(ped[offsettedID], true);
				FIRE::ADD_OWNED_EXPLOSION(PLAYER::PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 13, 5, false, true, 0);

			}
		}
	}
}
void MCPush()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				ENTITY::APPLY_FORCE_TO_ENTITY(ped[offsettedID], 1, 9, 9, 0, 0, 0, 0, 1, true, true, true, true, true);

				PED::SET_PED_CAN_RAGDOLL(ped[offsettedID], true);
				PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(ped[offsettedID], true);
				PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(ped[offsettedID], true);
				PED::SET_PED_RAGDOLL_ON_COLLISION(ped[offsettedID], true);

			}
		}
	}
}
void MCShock()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Ped ped[arrSize];
	ped[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), ped, 1);
	if (ped != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (ped[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(ped[offsettedID]))
			{
				int TargetHandle = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_PED(selectedPlayer));
				RequestNetworkControl(ped[offsettedID]);

				Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped[offsettedID], 0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x + 5, coords.y + 5, coords.z + 5, coords.x, coords.y, coords.z, 100, 1, GAMEPLAY::GET_HASH_KEY("WEAPON_STUNGUN"), PLAYER::PLAYER_PED_ID(), 1, 1, 100);


			}
		}
	}
}
void ForceBoost()
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestNetworkControl(veh[offsettedID]);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh[offsettedID], 100.0f);
			}
		}
	}
}

void ForceThrow()
{
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	//setAnimation("rcmpaparazzo_4", "lift_hands_in_air_loop");
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, true, true);
				PTFXCALL("scr_trevor1", "scr_trevor1", "scr_trev1_trailer_boosh");
				GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", veh[offsettedID], 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
				//draw(sizeof(veh));
			}
		}
	}
}
bool forcewave = false;
void ForceWave() {

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	PTFXCALL("scr_reconstructionaccident", "scr_reconstructionaccident", "scr_reconstructionaccident");
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 9, 9, 0, 0, 0, 0, 1, true, true, true, true, true);

				char *dict = "rcmcollect_paperleadinout@";
				char *anim = "meditiate_idle";
				STREAMING::REQUEST_ANIM_DICT(dict);
				AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			}
		}
	}
}
bool walldrive_ = false;
void walldrive()
{
	int ped = PLAYER::PLAYER_PED_ID();
	int veh = PED::GET_VEHICLE_PED_IS_IN(ped, true);
	if (PED::IS_PED_IN_VEHICLE(ped, veh, true))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, -0.4, 0, 0, 0, 1, true, true, true, true, true);
	}
}