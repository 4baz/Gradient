#include"stdafx.h"
#include"Menufunc.h"
//Converts Radians to Degrees

float degToRad(float degs)
{
	return degs*3.141592653589793f / 180.f;
}
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



char *call1o;
char *call2o;
char *nameo;
void animatePlayer(Player target, char* dict, char* anim)
{
	Ped targ_ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);//seleted player
	STREAMING::REQUEST_ANIM_DICT(dict);
	if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(targ_ped, 0.0, 0.0, 0.0);//since get_coord is patched i found this native
		int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 120, 0, 100, 0);/*i changed any to char* i provide the native below(modificated)*/
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);//will start the animation
	}
}
void PTFXCALL(char *call1, char *call2, char *name)
{
	call1o = call1;
	call2o = call2;
	nameo = name;

	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

}

Vector3 TPCoords;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}
void teleporttocoords(Player player, Vector3 target)
{
	for (int iz = 0; iz < 2; iz++)
	{
		Ped destPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
		Vector3 ourLoc = target;
		AI::CLEAR_PED_TASKS_IMMEDIATELY(destPed);
		int netScene = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(ourLoc.x, ourLoc.y, ourLoc.z, 0.f, 0.f, 0.f, 0, 0, 0, 0.f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(destPed, netScene, "amb@code_human_cower@female@base", "base", 8.f, -8.f, 2, 0, 100.f, 0);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(netScene);
		WAIT(150);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(destPed);
		NETWORK::NETWORK_STOP_SYNCHRONISED_SCENE(netScene);
	}
}

void killall()
{
	for (int i = 0; i < 32; i++)
	{
		if (i != PLAYER::PLAYER_ID())
		{
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(32), 0);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 4, 1000.f, true, false, 100.f);
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
	for (int i = 0; i < 32; i++)
	{
		if (i != PLAYER::PLAYER_ID())
		{
			kickfromveh(i);
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



bool allespboxbool = false;
bool espboxbool[32] = { false };
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

static char* blacklistedCrashObjects[]
{
	"barracks","barracks3","dune","marquis","marshall","monster","tug","ng_proc_temp","proc_brittlebush_01","proc_desert_sage_01","proc_dry_plants_01",
	"proc_drygrasses01", "proc_drygrasses01b","proc_drygrassfronds01","proc_dryplantsgrass_01","proc_dryplantsgrass_02","proc_forest_grass_01","proc_forest_ivy_01",
	"proc_grassdandelion01","proc_grasses01","proc_grasses01b","proc_grassfronds01","proc_grassplantmix_01","proc_grassplantmix_02","proc_indian_pbrush_01","proc_leafybush_01",
	"proc_leafyplant_01","proc_lizardtail_01","proc_lupins_01","proc_meadowmix_01","proc_meadowpoppy_01","proc_sage_01","proc_scrub_bush01","proc_sml_reeds_01","proc_sml_reeds_01b",
	"proc_sml_reeds_01c","proc_stones_01","proc_stones_02","proc_stones_03","proc_stones_04","proc_stones_05","proc_stones_06","proc_wildquinine","prop_dandy_b","prop_dryweed_001_a",
	"prop_dryweed_002_a","prop_fern_01","prop_fernba","prop_fernbb","prop_flowerweed_005_a","prop_grass_001_a","prop_grass_ca","prop_grass_da","prop_log_aa","prop_log_ab","prop_log_ac",
	"prop_log_ad","prop_log_ae","prop_log_af","prop_saplin_001_b","prop_saplin_001_c","prop_saplin_002_b","prop_saplin_002_c","prop_small_bushyba","prop_tall_drygrass_aa","prop_thindesertfiller_aa",
	"prop_weed_001_aa","prop_weed_002_ba","urbandryfrnds_01","urbandrygrass_01","urbangrnfrnds_01","urbangrngrass_01","urbanweeds01","urbanweeds01_l1","urbanweeds02","urbanweeds02_l2","v_proc2_temp",
};

void instacrash(Player target)
{

	if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
	{
		RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
		AI::CLEAR_PED_TASKS_IMMEDIATELY(target);
		Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		for (auto crashObject : blacklistedCrashObjects)
		{
			OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY(crashObject), playerCoords.x, playerCoords.y, playerCoords.z, true, true, true);
		}
	}
}

void shakecam(Player target)
{
	Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 4, 1000.f, false, true, 1000.f);
}
