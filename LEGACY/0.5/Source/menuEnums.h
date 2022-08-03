#pragma once

#ifndef MENU_ENUMS_H
#define MENU_ENUMS_H

namespace SUB {

	enum {
		CLOSED,
		MAINMENU,

		//Your subs
		SUBMENU1,
		SRCOLLER,
		SETTINGS,
		HEADER,
		OPTIONS,
		ONLINE,

		RECOVERY,
		ONLINE_RECOVERY,
		OFFLINE_RECOVERY,
		SETRP,

		STATS,
		PLAYERLIST,
		ONLINE_ATTACHMENT_SEL_PLAYER,
		CRASH_OBJECTS,
		PLAYEROPTIONS,
		OBJECT_ATTACHER_THING,
		PTFX,
		LOBBY,
		ATTACKERS,
		PLAYER,
		WANTED_EDITOR,
		ANIMATIONS,
		VEHICLE,
		LSCUSTOMS,
		WHEELS,
		VEHICLESPAWNER,
	
		TELEPORT,
		WEAPON,
		PROP_GUN,
		MISC,
		WORLD,
		CREDITS,
	};
}

namespace WHEEL {

	enum {
		STOCK = -1,
		SPORT,
		MUSCLE,
		LOWRIDER,
		SUV,
		OFFROAD,
		TUNER,
		BIKEWHEELS,
		HIGHEND,
		BENNYCLASSIC,
		BENNYBESPOKE
	};
}

enum VehicleModTypes
{
	MOD_SPOILER,
	MOD_FRONTBUMPER,
	MOD_REARBUMPER,
	MOD_SIDESKIRT,
	MOD_EXHAUST,
	MOD_CHASSIS, //Or roll cage
	MOD_GRILLE,
	MOD_HOOD,
	MOD_FENDER,
	MOD_RIGHTFENDER,
	MOD_ROOF,
	MOD_ENGINE,
	MOD_BRAKES,
	MOD_TRANSMISSION,
	MOD_HORNS,
	MOD_SUSPENSION,
	MOD_ARMOR,
	MOD_UNK17 = 17,
	MOD_TURBO = 18,
	MOD_UNK19 = 19,
	MOD_TIRESMOKE = 20,
	MOD_UNK21 = 21,
	MOD_XENONLIGHTS = 22,
	MOD_FRONTWHEELS = 23,
	MOD_BACKWHEELS = 24, //Bikes only
	//Benny's
	MOD_PLATEHOLDER = 25,
	MOD_VANITY_PLATES = 26,
	MOD_TRIM = 27,
	MOD_ORNAMENTS = 28,
	MOD_DASHBOARD = 29,
	MOD_DIAL = 30,
	MOD_DOOR_SPEAKER = 31,
	MOD_SEATS = 32,
	MOD_STEERINGWHEEL = 33,
	MOD_SHIFTER_LEAVERS = 34,
	MOD_PLAQUES = 35,
	MOD_SPEAKERS = 36,
	MOD_TRUNK = 37,
	MOD_HYDRULICS = 38,
	MOD_ENGINE_BLOCK = 39,
	MOD_AIR_FILTER = 40,
	MOD_STRUTS = 41,
	MOD_ARCH_COVER = 42,
	MOD_AERIALS = 43,
	MOD_TRIM2 = 44,
	MOD_TANK = 45,
	MOD_WINDOWS = 46,
	MOD_UNK47 = 47,
	MOD_LIVERY = 48
};

enum ePedTypes {
	PED_PLAYER = 1,
	PED_MALE = 4,
	PED_FEMALE,
	PED_COP,
	PED_HUMAN = 26,
	PED_SWAT,
	PED_ANIMAL,
	PED_ARMY
};

#endif


static char* Prop_list[] = {

	"prop_fan_palm_01a",
	"dt1_tc_dufo_core", 
	"ap1_lod_slod4", 
	"prop_alien_egg_01", 
	"prop_windmill_01",
	"prop_Ld_ferris_wheel" ,
	"p_tram_crash_s" , 
	"p_oil_slick_01", 
	"p_ld_stinger_s" , 
	"p_ld_soc_ball_01" , 
	"p_parachute1_s", 
	"p_cablecar_s" ,
	"prop_beach_fire" ,
	"prop_lev_des_barge_02" , 
	"prop_sculpt_fix" ,
	"p_v_43_safe_s" ,
	"prop_a_base_bars_01" , 
	"prop_beach_bars_01" , 

	"prop_skate_flatramp",
	"prop_skate_funbox",
	"prop_skate_halfpipe",
	"prop_skate_kickers",
	"prop_skate_quartpipe",
	"prop_skate_rail",
	"prop_skate_spiner",
	"prop_roofpipe_02",
	"prop_watertower04",
	"stt_prop_stunt_bblock_huge_01","stt_prop_stunt_bblock_huge_02","stt_prop_stunt_bblock_huge_03","stt_prop_stunt_bblock_huge_04","stt_prop_stunt_bblock_huge_05","stt_prop_stunt_bblock_hump_01","stt_prop_stunt_bblock_hump_02","stt_prop_stunt_bblock_lrg1","stt_prop_stunt_bblock_lrg2","stt_prop_stunt_bblock_lrg3","stt_prop_stunt_bblock_mdm1","stt_prop_stunt_bblock_mdm2","stt_prop_stunt_bblock_mdm3","stt_prop_stunt_bblock_qp","stt_prop_stunt_bblock_qp2","stt_prop_stunt_bblock_qp3","stt_prop_stunt_bblock_sml1","stt_prop_stunt_bblock_sml2","stt_prop_stunt_bblock_sml3","stt_prop_stunt_bblock_xl1","stt_prop_stunt_bblock_xl2","stt_prop_stunt_bblock_xl3","stt_prop_stunt_bowling_ball","stt_prop_stunt_bowling_pin","stt_prop_stunt_bowlpin_stand","stt_prop_stunt_domino","stt_prop_stunt_jump15","stt_prop_stunt_jump30","stt_prop_stunt_jump45","stt_prop_stunt_jump_l","stt_prop_stunt_jump_lb","stt_prop_stunt_jump_loop","stt_prop_stunt_jump_m","stt_prop_stunt_jump_mb","stt_prop_stunt_jump_s","stt_prop_stunt_jump_sb","stt_prop_stunt_landing_zone_01","stt_prop_stunt_ramp","stt_prop_stunt_soccer_ball","stt_prop_stunt_soccer_goal","stt_prop_stunt_soccer_lball","stt_prop_stunt_soccer_sball","stt_prop_stunt_target","stt_prop_stunt_target_small","stt_prop_stunt_track_bumps","stt_prop_stunt_track_cutout","stt_prop_stunt_track_dwlink","stt_prop_stunt_track_dwlink_02","stt_prop_stunt_track_dwsh15","stt_prop_stunt_track_dwshort","stt_prop_stunt_track_dwslope15","stt_prop_stunt_track_dwslope30","stt_prop_stunt_track_dwslope45","stt_prop_stunt_track_dwturn","stt_prop_stunt_track_dwuturn","stt_prop_stunt_track_exshort","stt_prop_stunt_track_fork","stt_prop_stunt_track_funlng","stt_prop_stunt_track_funnel","stt_prop_stunt_track_hill","stt_prop_stunt_track_hill2","stt_prop_stunt_track_jump","stt_prop_stunt_track_link","stt_prop_stunt_track_otake","stt_prop_stunt_track_sh15","stt_prop_stunt_track_sh30","stt_prop_stunt_track_sh45","stt_prop_stunt_track_sh45_a","stt_prop_stunt_track_short","stt_prop_stunt_track_slope15","stt_prop_stunt_track_slope30","stt_prop_stunt_track_slope45","stt_prop_stunt_track_start","stt_prop_stunt_track_start_02","stt_prop_stunt_track_straight","stt_prop_stunt_track_straightice","stt_prop_stunt_track_st_01","stt_prop_stunt_track_st_02","stt_prop_stunt_track_turn","stt_prop_stunt_track_turnice","stt_prop_stunt_track_uturn","stt_prop_stunt_tube_crn","stt_prop_stunt_tube_crn2","stt_prop_stunt_tube_crn_15d","stt_prop_stunt_tube_crn_30d","stt_prop_stunt_tube_crn_5d","stt_prop_stunt_tube_cross","stt_prop_stunt_tube_end","stt_prop_stunt_tube_ent","stt_prop_stunt_tube_fn_01","stt_prop_stunt_tube_fn_02","stt_prop_stunt_tube_fn_03","stt_prop_stunt_tube_fn_04","stt_prop_stunt_tube_fn_05","stt_prop_stunt_tube_fork","stt_prop_stunt_tube_gap_01","stt_prop_stunt_tube_gap_02","stt_prop_stunt_tube_gap_03","stt_prop_stunt_tube_hg","stt_prop_stunt_tube_jmp","stt_prop_stunt_tube_jmp2","stt_prop_stunt_tube_l","stt_prop_stunt_tube_m","stt_prop_stunt_tube_qg","stt_prop_stunt_tube_s","stt_prop_stunt_tube_speed","stt_prop_stunt_tube_speeda","stt_prop_stunt_tube_speedb","stt_prop_stunt_tube_xs","stt_prop_stunt_tube_xxs","stt_prop_stunt_wideramp"
//127 objects so far




};


static char* crash_objects[] = {

"ng_proc_temp",
"proc_brittlebush_01",
"proc_desert_sage_01",
"proc_dry_plants_01",
"proc_drygrasses01",
"proc_drygrasses01b",
"proc_drygrassfronds01",
"proc_dryplantsgrass_01",
"proc_dryplantsgrass_02",
"proc_forest_grass_01",
"proc_forest_ivy_01",
"proc_grassdandelion01",
"proc_grasses01",
"proc_grasses01b",
"proc_grassfronds01",
"proc_grassplantmix_01",
"proc_grassplantmix_02",
"proc_indian_pbrush_01",
"proc_leafybush_01",
"proc_leafyplant_01",
"proc_lizardtail_01",
"proc_lupins_01",
"proc_meadowmix_01",
"proc_meadowpoppy_01",
"proc_sage_01",
"proc_scrub_bush01",
"proc_sml_reeds_01",
"proc_sml_reeds_01b",
"proc_sml_reeds_01c",
"proc_stones_01",
"proc_stones_02",
"proc_stones_03",
"proc_stones_04",
"proc_stones_05",
"proc_stones_06",
"proc_wildquinine",
"prop_dandy_b",
"prop_dryweed_001_a",
"prop_dryweed_002_a",
"prop_fern_01",
"prop_fernba",
"prop_fernbb",
"prop_flowerweed_005_a",
"prop_grass_001_a",
"prop_grass_ca",
"prop_grass_da",
"prop_log_aa",
"prop_log_ab",
"prop_log_ac",
"prop_log_ad",
"prop_log_ae",
"prop_log_af",
"prop_saplin_001_b",
"prop_saplin_001_c",
"prop_saplin_002_b",
"prop_saplin_002_c",
"prop_small_bushyba",
"prop_tall_drygrass_aa",
"prop_thindesertfiller_aa",
"prop_weed_001_aa",
"prop_weed_002_ba",
"urbandryfrnds_01",
"urbandrygrass_01",
"urbangrnfrnds_01",
"urbangrngrass_01",
"urbanweeds01",
"urbanweeds01_l1",
"urbanweeds02",
"urbanweeds02_l2",
"v_proc2_temp",
//70

};