#pragma once

// Generated 21 Oct 2016

#include "types.h"
#include "nativeCaller.h"
#include <minwindef.h>

namespace PLAYER
{
	static Ped GET_PLAYER_PED(Player player) { return invoke<Ped>(0xDF7CE83326F434E9, player); } // 0xDF7CE83326F434E9 0x6E31E993
	static Ped GET_PLAYER_PED_SCRIPT_INDEX(Player player) { return invoke<Ped>(0xD560851477A3D4CA, player); } // 0xD560851477A3D4CA 0x6AC64990
	static void SET_PLAYER_MODEL(Player player, Hash model) { invoke<Void>(0x90B0C9C83043B8C4, player, model); } // 0x90B0C9C83043B8C4 0x774A4C54
	static void CHANGE_PLAYER_PED(Player player, Ped ped, BOOL b2, BOOL b3) { invoke<Void>(0x83A5C1DD0F909806, player, ped, b2, b3); } // 0x83A5C1DD0F909806 0xBE515485
	static void GET_PLAYER_RGB_COLOUR(Player player, int* r, int* g, int* b) { invoke<Void>(0x0F745F20A1F953BA, player, r, g, b); } // 0x0F745F20A1F953BA 0x6EF43BBB
	static int GET_NUMBER_OF_PLAYERS() { return invoke<int>(0xF56BF42596FFA911); } // 0xF56BF42596FFA911 0x4C1B8867
	static int GET_PLAYER_TEAM(Player player) { return invoke<int>(0xB58DEBB81964A4E9, player); } // 0xB58DEBB81964A4E9 0x9873E404
	static void SET_PLAYER_TEAM(Player player, int team) { invoke<Void>(0x8E5400CBA02308DC, player, team); } // 0x8E5400CBA02308DC 0x725ADCF2
	static char* GET_PLAYER_NAME(Player player) { return invoke<char*>(0x592E5DF66777D40F, player); } // 0x592E5DF66777D40F 0x406B4B20
	static float GET_WANTED_LEVEL_RADIUS(Player player) { return invoke<float>(0x2D5183EE284C9151, player); } // 0x2D5183EE284C9151 0x1CF7D7DA
	static Vector3 GET_PLAYER_WANTED_CENTRE_POSITION(Player player) { return invoke<Vector3>(0xD042870114E8EF82, player); } // 0xD042870114E8EF82 0x821F2D2C
	static void SET_PLAYER_WANTED_CENTRE_POSITION(Player player, float x, float y, float z) { invoke<Void>(0x27585A116B23621D, player, x, y, z); } // 0x27585A116B23621D 0xF261633A
	static int GET_WANTED_LEVEL_THRESHOLD(int wantedLevel) { return invoke<int>(0xFEBDFA40CE0D54BE, wantedLevel); } // 0xFEBDFA40CE0D54BE 0xD9783F6B
	static void SET_PLAYER_WANTED_LEVEL(Player player, int wantedLevel, BOOL disableNoMission) { invoke<Void>(0x809D9B021F305A70, player, wantedLevel, disableNoMission); } // 0x809D9B021F305A70 0xB7A0914B
	static void SET_PLAYER_WANTED_LEVEL_NO_DROP(Player player, int wantedLevel, BOOL p2) { invoke<Void>(0x2B46008B9EA5E05B, player, wantedLevel, p2); } // 0x2B46008B9EA5E05B 0xED6F44F5
	static void SET_PLAYER_WANTED_LEVEL_NOW(Player player, BOOL p1) { invoke<Void>(0xD189588DEC407D28, player, p1); } // 0xD189588DEC407D28 0xAF3AFD83
	static BOOL ARE_PLAYER_FLASHING_STARS_ABOUT_TO_DROP(Player player) { return invoke<BOOL>(0x5B9C2C48817E7BC9, player); } // 0x5B9C2C48817E7BC9 0xE13A71C7
	static BOOL ARE_PLAYER_STARS_GREYED_OUT(Player player) { return invoke<BOOL>(0x7648BB9293F4C87E, player); } // 0x7648BB9293F4C87E 0x5E72AB72
	static void SET_DISPATCH_COPS_FOR_PLAYER(Player player, BOOL toggle) { invoke<Void>(0x86127BA83F24D556, player, toggle); } // 0x86127BA83F24D556 0x48A18913
	static BOOL IS_PLAYER_WANTED_LEVEL_GREATER(Player player, int wantedLevel) { return invoke<BOOL>(0x0DD3F4C17D207474, player, wantedLevel); } // 0x0DD3F4C17D207474 0x589A2661
	static void CLEAR_PLAYER_WANTED_LEVEL(Player player) { invoke<Void>(0x9A03DB8A4DBF9E88, player); } // 0x9A03DB8A4DBF9E88 0x54EA5BCC
	static BOOL IS_PLAYER_DEAD(Player player) { return invoke<BOOL>(0xCEB2A4290BD633BE, player); } // 0xCEB2A4290BD633BE 0x140CA5A8
	static BOOL IS_PLAYER_PRESSING_HORN(Player player) { return invoke<BOOL>(0xB6FF35C3DAE3B8A1, player); } // 0xB6FF35C3DAE3B8A1 0xED1D1662
	static void SET_PLAYER_CONTROL(Player player, BOOL toggle, int possiblyFlags) { invoke<Void>(0xC8C3338D4DBC00FE, player, toggle, possiblyFlags); } // 0xC8C3338D4DBC00FE 0xD17AFCD8
	static int GET_PLAYER_WANTED_LEVEL(Player player) { return invoke<int>(0xA54996763FD89E65, player); } // 0xA54996763FD89E65 0xBDCDD163
	static void SET_MAX_WANTED_LEVEL(int maxWantedLevel) { invoke<Void>(0x6751FA44D6CA586D, maxWantedLevel); } // 0x6751FA44D6CA586D 0x665A06F5
	static void SET_POLICE_RADAR_BLIPS(BOOL toggle) { invoke<Void>(0xB80E9DA2EC792EE4, toggle); } // 0xB80E9DA2EC792EE4 0x8E114B10
	static void SET_POLICE_IGNORE_PLAYER(Player player, BOOL toggle) { invoke<Void>(0x60040905B2978982, player, toggle); } // 0x60040905B2978982 0xE6DE71B7
	static BOOL IS_PLAYER_PLAYING(Player player) { return invoke<BOOL>(0xCF7855B965948E97, player); } // 0xCF7855B965948E97 0xE15D777F
	static void SET_EVERYONE_IGNORE_PLAYER(Player player, BOOL toggle) { invoke<Void>(0x8549D98B1C1FCFA7, player, toggle); } // 0x8549D98B1C1FCFA7 0xC915285E
	static void SET_ALL_RANDOM_PEDS_FLEE(Player player, BOOL toggle) { invoke<Void>(0xC8F90C1233866A01, player, toggle); } // 0xC8F90C1233866A01 0x49EAE968
	static void SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME(Player player) { invoke<Void>(0x271C07D02388CBCB, player); } // 0x271C07D02388CBCB 0xBF974891
	static void SET_HUD_ANIM_STOP_LEVEL(Player player, BOOL toggle) { invoke<Void>(0x32B69D0C4B1A4C61, player, toggle); } // 0x32B69D0C4B1A4C61 0x274631FE
	static void SET_AREAS_GENERATOR_ORIENTATION(Player player) { invoke<Void>(0xA7C880975F63452B, player); } // 0xA7C880975F63452B 0x02DF7AF4
	static void SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(Player player, BOOL toggle) { invoke<Void>(0x2AC69FCDE075DAE1, player, toggle); } // 0x2AC69FCDE075DAE1 0xA3D675ED
	static void SET_WANTED_LEVEL_MULTIPLIER(float multiplier) { invoke<Void>(0x000E46314C3A507F, multiplier); } // 0x000E46314C3A507F 0x1359292F
	static void SET_WANTED_LEVEL_DIFFICULTY(Player player, float difficulty) { invoke<Void>(0x4361500C7F56A212, player, difficulty); } // 0x4361500C7F56A212 0xB552626C
	static void RESET_WANTED_LEVEL_DIFFICULTY(Player player) { invoke<Void>(0x0DACC47E5EC16CF6, player); } // 0x0DACC47E5EC16CF6 0xA64C378D
	static void START_FIRING_AMNESTY(int duration) { invoke<Void>(0x21F9081DAE2F8AF5, duration); } // 0x21F9081DAE2F8AF5 0x5F8A22A6
	static void REPORT_CRIME(Player player, int crimeType, int wantedLvlThresh) { invoke<Void>(0xDEF3636CEB1A14E7, player, crimeType, wantedLvlThresh); } // 0xDEF3636CEB1A14E7 0xD8EB3A44
	static void RESERVE_ENTITY_EXPLODES_ON_HIGH_EXPLOSION_COMBO(Player player, int p1) { invoke<Void>(0x62AB53D880F2DCC1, player, p1); } // 0x62AB53D880F2DCC1 0x59B5C2A2
	static void _0x2B80C4DD7C4BB325(Player player) { invoke<Void>(0x2B80C4DD7C4BB325, player); } // 0x2B80C4DD7C4BB325 0x6B34A160
	static void _0x1B7B205820ED9CE2(Player player) { invoke<Void>(0x1B7B205820ED9CE2, player); } // 0x1B7B205820ED9CE2 0xB9FB142F
	static void _0x727E7D1075104A33(Player player) { invoke<Void>(0x727E7D1075104A33, player); } // 0x727E7D1075104A33 0x85725848
	static void _0x9A282B898547F943(Player player) { invoke<Void>(0x9A282B898547F943, player); } // 0x9A282B898547F943 0x3A7E5FB6
	static void _0xE90104D9EBFC3619(Player player) { invoke<Void>(0xE90104D9EBFC3619, player); } // 0xE90104D9EBFC3619 0xD15C4B1C
	static void _0xF94A98F41CFB3ABF(float p0) { invoke<Void>(0xF94A98F41CFB3ABF, p0); } // 0xF94A98F41CFB3ABF 0xBF6993C7
	static void _0xA1D2FFAD14A3E5D7() { invoke<Void>(0xA1D2FFAD14A3E5D7); } // 0xA1D2FFAD14A3E5D7 0x47CAB814
	static BOOL CAN_PLAYER_START_MISSION(Player player) { return invoke<BOOL>(0xD37F3675F4465D41, player); } // 0xD37F3675F4465D41 0x39E3CB3F
	static BOOL IS_PLAYER_READY_FOR_CUTSCENE(Player player) { return invoke<BOOL>(0x3D6EEB2BAADEC759, player); } // 0x3D6EEB2BAADEC759 0xBB77E9CD
	static BOOL IS_PLAYER_TARGETTING_ENTITY(Player player, Entity entity) { return invoke<BOOL>(0x5ADC20A7C6AB8336, player, entity); } // 0x5ADC20A7C6AB8336 0xF3240B77
	static BOOL GET_PLAYER_TARGET_ENTITY(Player player, Entity* entity) { return invoke<BOOL>(0x41B9773A1CCDC74C, player, entity); } // 0x41B9773A1CCDC74C 0xF6AAA2D7
	static BOOL IS_PLAYER_FREE_AIMING(Player player) { return invoke<BOOL>(0xE58A1B5558D2DC66, player); } // 0xE58A1B5558D2DC66 0x1DEC67B7
	static BOOL IS_PLAYER_FREE_AIMING_AT_ENTITY(Player player, Entity entity) { return invoke<BOOL>(0x42B260AC2C6CA4ED, player, entity); } // 0x42B260AC2C6CA4ED 0x7D80EEAA
	static BOOL GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(Player player, Entity* entity) { return invoke<BOOL>(0x7940476800F126AE, player, entity); } // 0x7940476800F126AE 0x8866D9D0
	static void SET_PLAYER_LOCKON_RANGE_OVERRIDE(Player player, float range) { invoke<Void>(0xA53DDE01E11817A1, player, range); } // 0xA53DDE01E11817A1 0x74D42C03
	static void SET_PLAYER_CAN_DO_DRIVE_BY(Player player, BOOL toggle) { invoke<Void>(0x4536CA73A019CB85, player, toggle); } // 0x4536CA73A019CB85 0xF4D99685
	static void SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(Player player, BOOL toggle) { invoke<Void>(0x60DB1BD4EAA89D0D, player, toggle); } // 0x60DB1BD4EAA89D0D 0x71B305BB
	static void SET_PLAYER_CAN_USE_COVER(Player player, BOOL toggle) { invoke<Void>(0xA0A78EC22BFC648E, player, toggle); } // 0xA0A78EC22BFC648E 0x13CAFAFA
	static int GET_MAX_WANTED_LEVEL() { return invoke<int>(0x21B9C652ECEE5A6D); } // 0x21B9C652ECEE5A6D 0x457F1E44
	static BOOL IS_PLAYER_TARGETTING_ANYTHING(Player player) { return invoke<BOOL>(0x091275C60C62F17B, player); } // 0x091275C60C62F17B 0x456DB50D
	static void SET_PLAYER_SPRINT(Player player, BOOL toggle) { invoke<Void>(0xD3DF83881C2FC709, player, toggle); } // 0xD3DF83881C2FC709 0x7DD7900C
	static void RESET_PLAYER_STAMINA(Player player) { invoke<Void>(0x1A0F6CE53D486831, player); } // 0x1A0F6CE53D486831 0xC0445A9C
	static void RESTORE_PLAYER_STAMINA(Player player, float p1) { invoke<Void>(0xF5FADF6DFD6DC1FF, player, p1); } // 0xF5FADF6DFD6DC1FF 0x62A93608
	static float GET_PLAYER_SPRINT_STAMINA_REMAINING(Player player) { return invoke<float>(0x0C5AC23055DF0003, player); } // 0x0C5AC23055DF0003 0x47017C90
	static float GET_PLAYER_SPRINT_TIME_REMAINING(Player player) { return invoke<float>(0x750733677CCFD548, player); } // 0x750733677CCFD548 0x40E80543
	static float GET_PLAYER_UNDERWATER_TIME_REMAINING(Player player) { return invoke<float>(0x21DA3E95A4DF3A61, player); } // 0x21DA3E95A4DF3A61 0x1317125A
	static int GET_PLAYER_GROUP(Player player) { return invoke<int>(0xDC8370280C455166, player); } // 0xDC8370280C455166 0xA5EDCDE8
	static int GET_PLAYER_MAX_ARMOUR(Player player) { return invoke<int>(0x525FDE9356F4170E, player); } // 0x525FDE9356F4170E 0x02A50657
	static BOOL IS_PLAYER_CONTROL_ON(Player player) { return invoke<BOOL>(0x94A5DEE82C898FDF, player); } // 0x94A5DEE82C898FDF 0x618857F2
	static BOOL _IS_PLAYER_CAM_CONTROL_DISABLED() { return invoke<BOOL>(0x593C7E6CB36E2042); } // 0x593C7E6CB36E2042
	static BOOL IS_PLAYER_SCRIPT_CONTROL_ON(Player player) { return invoke<BOOL>(0x3F7E4FA3D49208FD, player); } // 0x3F7E4FA3D49208FD 0x61B00A84
	static BOOL IS_PLAYER_CLIMBING(Player player) { return invoke<BOOL>(0xA4FEB0448027296A, player); } // 0xA4FEB0448027296A 0x4A9E9AE0
	static BOOL IS_PLAYER_BEING_ARRESTED(Player player, BOOL atArresting) { return invoke<BOOL>(0x5078D2C096A3D8E4, player, atArresting); } // 0x5078D2C096A3D8E4 0x7F6A60D3
	static void RESET_PLAYER_ARREST_STATE(Player player) { invoke<Void>(0xA01561C15F35DBDC, player); } // 0xA01561C15F35DBDC 0x453C7CAB
	static Vehicle GET_PLAYERS_LAST_VEHICLE() { return invoke<Vehicle>(0x0C00E753D78DEA62); } // 0x0C00E753D78DEA62 0xE2757AC1
	static Player GET_PLAYER_INDEX() { return invoke<Player>(0x592069F95C314814); } // 0x592069F95C314814 0x309BBDC1
	static Player INT_TO_PLAYERINDEX(int value) { return invoke<Player>(0x0C36F33B3F746611, value); } // 0x0C36F33B3F746611 0x98DD98F1
	static int INT_TO_PARTICIPANTINDEX(int value) { return invoke<int>(0x62C65E3042052191, value); } // 0x62C65E3042052191 0x98F3B274
	static int GET_TIME_SINCE_PLAYER_HIT_VEHICLE(Player player) { return invoke<int>(0x07ED27B1770E70C4, player); } // 0x07ED27B1770E70C4 0x6E9B8B9E
	static int GET_TIME_SINCE_PLAYER_HIT_PED(Player player) { return invoke<int>(0xF23F82CD34BEF310, player); } // 0xF23F82CD34BEF310 0xB6209195
	static int GET_TIME_SINCE_PLAYER_DROVE_ON_PAVEMENT(Player player) { return invoke<int>(0x90F8DE1AAC964995, player); } // 0x90F8DE1AAC964995 0x8836E732
	static int GET_TIME_SINCE_PLAYER_DROVE_AGAINST_TRAFFIC(Player player) { return invoke<int>(0x181845D09B2FD3ED, player); } // 0x181845D09B2FD3ED 0x9F27D00E
	static BOOL IS_PLAYER_FREE_FOR_AMBIENT_TASK(Player player) { return invoke<BOOL>(0x2AAAA411A3CBAFE2, player); } // 0x2AAAA411A3CBAFE2 0x85C7E232
	static Player PLAYER_ID() { return invoke<Player>(0xBE369BE1BC57A796); } // 0xBE369BE1BC57A796 0x8AEA886C
	static Ped PLAYER_PED_ID() { return invoke<Ped>(0x17B5CC8A8615737D); } // 0x17B5CC8A8615737D 0xFA92E226
	static int NETWORK_PLAYER_ID_TO_INT() { return invoke<int>(0x08578C183D455935); } // 0x08578C183D455935 0x8DD5B838
	static BOOL HAS_FORCE_CLEANUP_OCCURRED(int cleanupFlags) { return invoke<BOOL>(0xBCA819F9975BEDFA, cleanupFlags); } // 0xBCA819F9975BEDFA 0x4B37333C
	static void FORCE_CLEANUP(int cleanupFlags) { invoke<Void>(0xBED07ACDB4C03BB0, cleanupFlags); } // 0xBED07ACDB4C03BB0 0xFDAAEA2B
	static void FORCE_CLEANUP_FOR_ALL_THREADS_WITH_THIS_NAME(char* name, int cleanupFlags) { invoke<Void>(0xC6539417A29F3471, name, cleanupFlags); } // 0xC6539417A29F3471 0x04256C73
	static void FORCE_CLEANUP_FOR_THREAD_WITH_THIS_ID(int id, int cleanupFlags) { invoke<Void>(0x4841E9AF7173E4AF, id, cleanupFlags); } // 0x4841E9AF7173E4AF 0x882D3EB3
	static int GET_CAUSE_OF_MOST_RECENT_FORCE_CLEANUP() { return invoke<int>(0xF8A4157569AF4F61); } // 0xF8A4157569AF4F61 0x39AA9FC8
	static void SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE(Player player, Vehicle vehicle) { invoke<Void>(0xD83BCC50677CCD4B, player, vehicle); } // 0xD83BCC50677CCD4B 0xA454DD29
	static void SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE(Player player) { invoke<Void>(0x8960FF6F26EA1D88, player); } // 0x8960FF6F26EA1D88 0xAF7AFCC4
	static BOOL GIVE_ACHIEVEMENT_TO_PLAYER(int achievement) { return invoke<BOOL>(0xDDAC6D364DFB4FD7, achievement); } // 0xDDAC6D364DFB4FD7 0x822BC992
	static BOOL _0xA1657EA7F5F15A59(Any p0, Any p1) { return invoke<BOOL>(0xA1657EA7F5F15A59, p0, p1); } // 0xA1657EA7F5F15A59
	static Cam _0x71AAA4D97165244D(Any p0) { return invoke<Cam>(0x71AAA4D97165244D, p0); } // 0x71AAA4D97165244D
	static BOOL HAS_ACHIEVEMENT_BEEN_PASSED(int achievement) { return invoke<BOOL>(0xF0EE2EF8EA972239, achievement); } // 0xF0EE2EF8EA972239 0x136A5BE9
	static BOOL IS_PLAYER_ONLINE() { return invoke<BOOL>(0x9B0FAF2C1DE9BB5A); } // 0x9B0FAF2C1DE9BB5A 0x9FAB6729
	static BOOL IS_PLAYER_LOGGING_IN_NP() { return invoke<BOOL>(0xDEE22C9F1A4191BA); } // 0xDEE22C9F1A4191BA 0x8F72FAD0
	static void DISPLAY_SYSTEM_SIGNIN_UI(BOOL unk) { invoke<Void>(0xEFC67FF618C4DD5F, unk); } // 0xEFC67FF618C4DD5F 0x4264CED2
	static BOOL IS_SYSTEM_UI_BEING_DISPLAYED() { return invoke<BOOL>(0xBC409B03D8BA213A); } // 0xBC409B03D8BA213A 0xE495B6DA
	static void SET_PLAYER_INVINCIBLE(Player player, BOOL toggle) { invoke<Void>(0xF7A1A67D26D29975, player, toggle); } // 0xF7A1A67D26D29975 0xDFB9A2A2
	static BOOL GET_PLAYER_INVINCIBLE(Player player) { return invoke<BOOL>(0x8339F26C68EAA375, player); } // 0x8339F26C68EAA375 0x680C90EE
	static void _0xBEE74FA549BDABA3(Player player, BOOL p1) { invoke<Void>(0xBEE74FA549BDABA3, player, p1); } // 0xBEE74FA549BDABA3 0x00563E0D
	static void REMOVE_PLAYER_HELMET(Player player, BOOL p2) { invoke<Void>(0x6E56C821FA64C1F3, player, p2); } // 0x6E56C821FA64C1F3 0x6255F3B4
	static void GIVE_PLAYER_RAGDOLL_CONTROL(Player player, BOOL toggle) { invoke<Void>(0x29C492865610BB71, player, toggle); } // 0x29C492865610BB71 0xC7B4D7AC
	static void SET_PLAYER_LOCKON(Player player, BOOL toggle) { invoke<Void>(0x864B3FD728E133BB, player, toggle); } // 0x864B3FD728E133BB 0x0B270E0F
	static void SET_PLAYER_TARGETING_MODE(int targetMode) { invoke<Void>(0x769E7DC0F1D7956B, targetMode); } // 0x769E7DC0F1D7956B 0x61CAE253
	static void _0x9477C21D2E0E95E0(Any p0) { invoke<Void>(0x9477C21D2E0E95E0, p0); } // 0x9477C21D2E0E95E0
	static Any _0xE88E1BC2E51494FF() { return invoke<Any>(0xE88E1BC2E51494FF); } // 0xE88E1BC2E51494FF
	static void CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED(Player player) { invoke<Void>(0x6B406797594AEA51, player); } // 0x6B406797594AEA51 0x1D31CBBD
	static BOOL HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED(Player player) { return invoke<BOOL>(0xB95F3BAC01F95DB8, player); } // 0xB95F3BAC01F95DB8 0x14F52453
	static void CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED(Player player) { invoke<Void>(0xB2C7E752EB146AE1, player); } // 0xB2C7E752EB146AE1 0x7E3BFBC5
	static BOOL HAS_PLAYER_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED(Player player) { return invoke<BOOL>(0xE2A9DE343F2FC00E, player); } // 0xE2A9DE343F2FC00E 0xA3707DFC
	static void SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE(Player player, float multiplier) { invoke<Void>(0xAFC3FD1D11D31506, player, multiplier); } // 0xAFC3FD1D11D31506 0xF20F72E5
	static void SET_SWIM_MULTIPLIER_FOR_PLAYER(Player player, float multiplier) { invoke<Void>(0xAF6BF84845852C1F, player, multiplier); } // 0xAF6BF84845852C1F 0xB986FF47
	static void SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(Player player, float multiplier) { invoke<Void>(0xC403E60714279361, player, multiplier); } // 0xC403E60714279361 0x825423C2
	static int GET_TIME_SINCE_LAST_ARREST() { return invoke<int>(0x5080BCFF54EB4623); } // 0x5080BCFF54EB4623 0x62824EF4
	static int GET_TIME_SINCE_LAST_DEATH() { return invoke<int>(0x58F6C9143C05241D); } // 0x58F6C9143C05241D 0x24BC5AC0
	static void ASSISTED_MOVEMENT_CLOSE_ROUTE() { invoke<Void>(0x5C3503CA72FEDDED); } // 0x5C3503CA72FEDDED 0xF23277F3
	static void ASSISTED_MOVEMENT_FLUSH_ROUTE() { invoke<Void>(0xE6BEFD3733892445); } // 0xE6BEFD3733892445 0xD04568B9
	static void SET_PLAYER_FORCED_AIM(Player player, BOOL toggle) { invoke<Void>(0x4B1F999A78B61BDB, player, toggle); } // 0x4B1F999A78B61BDB 0x94E42E2E
	static void SET_PLAYER_FORCED_ZOOM(Player player, BOOL toggle) { invoke<Void>(0xAEE80C7754C14958, player, toggle); } // 0xAEE80C7754C14958 0xB0C576CB
	static void SET_PLAYER_FORCE_SKIP_AIM_INTRO(Player player, BOOL toggle) { invoke<Void>(0x1CF1F952810884F3, player, toggle); } // 0x1CF1F952810884F3 0x374F42F0
	static void DISABLE_PLAYER_FIRING(Player player, BOOL toggle) { invoke<Void>(0x31A91341B577742F, player, toggle); } // 0x31A91341B577742F 0x30CB28CB
	static void _0xC357E174B2861724() { invoke<Void>(0xC357E174B2861724); } // 0xC357E174B2861724
	static void SET_DISABLE_AMBIENT_MELEE_MOVE(Player player, BOOL toggle) { invoke<Void>(0x6427146CC449B3BC, player, toggle); } // 0x6427146CC449B3BC 0xCCD937E7
	static void SET_PLAYER_MAX_ARMOUR(Player player, int value) { invoke<Void>(0x9ADEE05698B96CFE, player, value); } // 0x9ADEE05698B96CFE 0xC6C3C53B
	static void SPECIAL_ABILITY_DEACTIVATE(Player player) { invoke<Void>(0xC23C2ED7CCA1618F, player); } // 0xC23C2ED7CCA1618F 0x80C2AB09
	static void SPECIAL_ABILITY_DEACTIVATE_FAST(Player player) { invoke<Void>(0x75416EE69CE8B797, player); } // 0x75416EE69CE8B797 0x0751908A
	static void SPECIAL_ABILITY_RESET(Player player) { invoke<Void>(0x5249981A1916BF74, player); } // 0x5249981A1916BF74 0xA7D8BCD3
	static void _0xF6B2E0D2CFCE7923(Player player) { invoke<Void>(0xF6B2E0D2CFCE7923, player); } // 0xF6B2E0D2CFCE7923 0x4136829A
	static void SPECIAL_ABILITY_CHARGE_SMALL(Player player, BOOL p1, BOOL p2) { invoke<Void>(0xF2AAEF6B5EB5D682, player, p1, p2); } // 0xF2AAEF6B5EB5D682 0x6F463F56
	static void SPECIAL_ABILITY_CHARGE_MEDIUM(Player player, BOOL p1, BOOL p2) { invoke<Void>(0x3BE8875479DC50A2, player, p1, p2); } // 0x3BE8875479DC50A2 0xAB55D8F3
	static void SPECIAL_ABILITY_CHARGE_LARGE(Player player, BOOL p1, BOOL p2) { invoke<Void>(0x2F79404B267913E1, player, p1, p2); } // 0x2F79404B267913E1 0xF440C04D
	static void SPECIAL_ABILITY_CHARGE_CONTINUOUS(Player player, BOOL p1) { invoke<Void>(0xD9B526057993867B, player, p1); } // 0xD9B526057993867B 0x5FEE98A2
	static void SPECIAL_ABILITY_CHARGE_ABSOLUTE(Player player, int p1, BOOL p2) { invoke<Void>(0x4E09E7C0F04B5D22, player, p1, p2); } // 0x4E09E7C0F04B5D22 0x72429998
	static void SPECIAL_ABILITY_CHARGE_NORMALIZED(Player player, float normalizedValue, BOOL p2) { invoke<Void>(0x163B0E4E52B0FAB1, player, normalizedValue, p2); } // 0x163B0E4E52B0FAB1 0x8C7E68C1
	static void SPECIAL_ABILITY_FILL_METER(Player player, BOOL p1) { invoke<Void>(0xF74BF04E3FF80B44, player, p1); } // 0xF74BF04E3FF80B44 0xB71589DA
	static void SPECIAL_ABILITY_DEPLETE_METER(Player player, BOOL p1) { invoke<Void>(0x2CD28F0D6C86D292, player, p1); } // 0x2CD28F0D6C86D292 0x9F80F6DF
	static void SPECIAL_ABILITY_LOCK(Hash playerModel) { invoke<Void>(0x1633F076CBF05620, playerModel); } // 0x1633F076CBF05620 0x1B7BB388
	static void SPECIAL_ABILITY_UNLOCK(Hash playerModel) { invoke<Void>(0xDBAD2EC810555434, playerModel); } // 0xDBAD2EC810555434 0x1FDB2919
	static BOOL IS_SPECIAL_ABILITY_UNLOCKED(Hash playerModel) { return invoke<BOOL>(0xDBE9845E4347B9B9, playerModel); } // 0xDBE9845E4347B9B9 0xC9C75E82
	static BOOL IS_SPECIAL_ABILITY_ACTIVE(Player player) { return invoke<BOOL>(0xDB3C032119056A8B, player); } // 0xDB3C032119056A8B 0x1B17E334
	static BOOL IS_SPECIAL_ABILITY_METER_FULL(Player player) { return invoke<BOOL>(0x78D8C60E9FBA1AA8, player); } // 0x78D8C60E9FBA1AA8 0x2E19D7F6
	static void ENABLE_SPECIAL_ABILITY(Player player, BOOL toggle) { invoke<Void>(0x54EF513433B8F177, player, toggle); } // 0x54EF513433B8F177 0xC86C1B4E
	static BOOL IS_SPECIAL_ABILITY_ENABLED(Player player) { return invoke<BOOL>(0x61BE528D623E6AA1, player); } // 0x61BE528D623E6AA1 0xC01238CC
	static void SET_SPECIAL_ABILITY_MULTIPLIER(float multiplier) { invoke<Void>(0x774EBBE5B3122792, multiplier); } // 0x774EBBE5B3122792 0xFF1BC556
	static void _0x7F4952D4B3B4448A(Player player) { invoke<Void>(0x7F4952D4B3B4448A, player); } // 0x7F4952D4B3B4448A 0x5D0FE25B
	static BOOL _0x69A760207AA1FDC6(Player player) { return invoke<BOOL>(0x69A760207AA1FDC6, player); } // 0x69A760207AA1FDC6 0x46E7E31D
	static BOOL _0xA63B1E354C7DC608(Player player, int p1) { return invoke<BOOL>(0xA63B1E354C7DC608, player, p1); } // 0xA63B1E354C7DC608 0x1E359CC8
	static BOOL _0xCD11DF3DA63A67D4(Player player, float p1) { return invoke<BOOL>(0xCD11DF3DA63A67D4, player, p1); } // 0xCD11DF3DA63A67D4 0x8CB53C9F
	static void START_PLAYER_TELEPORT(Player player, float x, float y, float z, float heading, BOOL p5, BOOL p6, BOOL p7) { invoke<Void>(0xC48E328891A0934A, player, x, y, z, heading, p5, p6, p7); } // 0xC48E328891A0934A 0xC552E06C
	static BOOL _HAS_PLAYER_TELEPORT_FINISHED(Player player) { return invoke<BOOL>(0xD3BCEF961E7EE680, player); } // 0xD3BCEF961E7EE680
	static void STOP_PLAYER_TELEPORT() { invoke<Void>(0xDD3490F2272A85A2); } // 0xDD3490F2272A85A2 0x86AB8DBB
	static BOOL IS_PLAYER_TELEPORT_ACTIVE() { return invoke<BOOL>(0x86DB3331A7FB14B2); } // 0x86DB3331A7FB14B2 0x3A11D118
	static float GET_PLAYER_CURRENT_STEALTH_NOISE(Player player) { return invoke<float>(0xB96AF58FE20B9050, player); } // 0xB96AF58FE20B9050 0xC3B02362
	static void SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(Player player, float regenRate) { invoke<Void>(0x73C8729A36D6FDBC, player, regenRate); } // 0x73C8729A36D6FDBC 0x45514731
	static void SET_PLAYER_WEAPON_DAMAGE_MODIFIER(Player player, float damageAmount) { invoke<Void>(0x36D329DB9B841EE5, player, damageAmount); } // 0x36D329DB9B841EE5 0xB02C2F39
	static void SET_PLAYER_WEAPON_DEFENSE_MODIFIER(Player player, float modifier) { invoke<Void>(0x20F3A42843EDE83D, player, modifier); } // 0x20F3A42843EDE83D 0xAE446344
	static void SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(Player player, float modifier) { invoke<Void>(0x86B7738264429568, player, modifier); } // 0x86B7738264429568 0x362E69AD
	static void SET_PLAYER_MELEE_WEAPON_DEFENSE_MODIFIER(Player player, float modifier) { invoke<Void>(0x9FA27E3C44D7B264, player, modifier); } // 0x9FA27E3C44D7B264 0x9F3D577F
	static void SET_PLAYER_VEHICLE_DAMAGE_MODIFIER(Player player, float damageAmount) { invoke<Void>(0xA687E94B465DEFFF, player, damageAmount); } // 0xA687E94B465DEFFF 0x823ECA63
	static void SET_PLAYER_VEHICLE_DEFENSE_MODIFIER(Player player, float modifier) { invoke<Void>(0x240454F87F8FCCAE, player, modifier); } // 0x240454F87F8FCCAE 0xA16626C7
	static void SET_PLAYER_PARACHUTE_TINT_INDEX(Player player, int tintIndex) { invoke<Void>(0xD913311486F1186F, player, tintIndex); } // 0xD913311486F1186F 0x8EA12EDB
	static void GET_PLAYER_PARACHUTE_TINT_INDEX(Player player, int* tintIndex) { invoke<Void>(0x1B23C1C42CDDE0E5, player, tintIndex); } // 0x1B23C1C42CDDE0E5 0x432B0509
	static void SET_PLAYER_RESERVE_PARACHUTE_TINT_INDEX(Player player, int index) { invoke<Void>(0x485CBC4FFA6D5E36, player, index); } // 0x485CBC4FFA6D5E36 0x70689638
	static void GET_PLAYER_RESERVE_PARACHUTE_TINT_INDEX(Player player, int* index) { invoke<Void>(0xA4E7BBB507C43148, player, index); } // 0xA4E7BBB507C43148 0x77B8EF01
	static void SET_PLAYER_PARACHUTE_PACK_TINT_INDEX(Player player, int tintIndex) { invoke<Void>(0x72F20383CC729325, player, tintIndex); } // 0x72F20383CC729325 0xD79D5D1B
	static void GET_PLAYER_PARACHUTE_PACK_TINT_INDEX(Player player, int* tintIndex) { invoke<Void>(0xD8B4ACC0B5F2BA05, player, tintIndex); } // 0xD8B4ACC0B5F2BA05 0x4E418E13
	static void SET_PLAYER_HAS_RESERVE_PARACHUTE(Player player) { invoke<Void>(0x775FF64EC73AB50D, player); } // 0x775FF64EC73AB50D 0xA3E4798E
	static BOOL GET_PLAYER_HAS_RESERVE_PARACHUTE(Player player) { return invoke<BOOL>(0x28B8490B6A478ABD, player); } // 0x28B8490B6A478ABD 0x30DA1DA1
	static void SET_PLAYER_CAN_LEAVE_PARACHUTE_SMOKE_TRAIL(Player player, BOOL enabled) { invoke<Void>(0x7C3C897A77D5867A, player, enabled); } // 0x7C3C897A77D5867A 0x832DEB7A
	static void SET_PLAYER_PARACHUTE_SMOKE_TRAIL_COLOR(Player player, int r, int g, int b) { invoke<Void>(0x626C1B2D2CD72EA3, player, r, g, b); } // 0x626C1B2D2CD72EA3 0x14FE9264
	static void GET_PLAYER_PARACHUTE_SMOKE_TRAIL_COLOR(Player player, int* r, int* g, int* b) { invoke<Void>(0x3FEFC04643A0F0A1, player, r, g, b); } // 0x3FEFC04643A0F0A1 0xF66E5CDD
	static void SET_PLAYER_RESET_FLAG_PREFER_REAR_SEATS(Player player, int flags) { invoke<Void>(0x4C97AC11E3D49677, player, flags); } // 0x4C97AC11E3D49677 0x725C6174
	static void SET_PLAYER_NOISE_MULTIPLIER(Player player, float multiplier) { invoke<Void>(0x07B06D1DF7FB9392, player, multiplier); } // 0x07B06D1DF7FB9392 0x15786DD1
	static void SET_PLAYER_SNEAKING_NOISE_MULTIPLIER(Player player, float multiplier) { invoke<Void>(0xB03DD283D080159E, player, multiplier); } // 0xB03DD283D080159E 0x8D2D89C4
	static BOOL CAN_PED_HEAR_PLAYER(Player player, Ped ped) { return invoke<BOOL>(0xAD0529AB45195362, player, ped); } // 0xAD0529AB45195362 0x1C70B2EB
	static void SIMULATE_PLAYER_INPUT_GAIT(Player player, float amount, int gaitType, float speed, BOOL p4, BOOL p5) { invoke<Void>(0x5436326547492A67, player, amount, gaitType, speed, p4, p5); } // 0x5436326547492A67 0x0D77CC34
	static void RESET_PLAYER_INPUT_GAIT(Player player) { invoke<Void>(0xA036D470439BFF99, player); } // 0xA036D470439BFF99 0x4A701EE1
	static void SET_AUTO_GIVE_PARACHUTE_WHEN_ENTER_PLANE(Player player, BOOL toggle) { invoke<Void>(0xD46D90F77553EA44, player, toggle); } // 0xD46D90F77553EA44 0xA97C2059
	static void _0x0AE18774CF41508C(Player player, BOOL p1) { invoke<Void>(0x0AE18774CF41508C, player, p1); } // 0x0AE18774CF41508C 0xA25D767E
	static void SET_PLAYER_STEALTH_PERCEPTION_MODIFIER(Player player, float value) { invoke<Void>(0x50172E6C8E98A56F, player, value); } // 0x50172E6C8E98A56F 0x3D26105F
	static BOOL _0xC3352F799F18CC8E(Any p0) { return invoke<BOOL>(0xC3352F799F18CC8E, p0); } // 0xC3352F799F18CC8E 0x1D371529
	static void _0x1087E6E181663AE4(Player player) { invoke<Void>(0x1087E6E181663AE4, player); } // 0x1087E6E181663AE4 0xE30A64DC
	static void SET_PLAYER_SIMULATE_AIMING(Player player, BOOL toggle) { invoke<Void>(0x3442EB1ED32DAC35, player, toggle); } // 0x3442EB1ED32DAC35 0xF1E0CAFC
	static void SET_PLAYER_CLOTH_PIN_FRAMES(Player player, BOOL toggle) { invoke<Void>(0x8E9619F1D689D28F, player, toggle); } // 0x8E9619F1D689D28F 0xF7A0F00F
	static void SET_PLAYER_CLOTH_PACKAGE_INDEX(int index) { invoke<Void>(0x01FBE05FBB95201F, index); } // 0x01FBE05FBB95201F 0xB8209F16
	static void SET_PLAYER_CLOTH_LOCK_COUNTER(int value) { invoke<Void>(0x0FBD3B3227B8FFA3, value); } // 0x0FBD3B3227B8FFA3 0x8D9FD4D1
	static void PLAYER_ATTACH_VIRTUAL_BOUND(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7) { invoke<Void>(0xBEF25CA055BA5B0A, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xBEF25CA055BA5B0A 0xECD12E60
	static void PLAYER_DETACH_VIRTUAL_BOUND() { invoke<Void>(0xE0EFF3F0E64C0E02); } // 0xE0EFF3F0E64C0E02 0x96100EA4
	static BOOL HAS_PLAYER_BEEN_SPOTTED_IN_STOLEN_VEHICLE(Player player) { return invoke<BOOL>(0x5ABE9DD3103FC9D1, player); } // 0x5ABE9DD3103FC9D1 0x4A01B76A
	static BOOL _0x6A938874794628B1(Player player) { return invoke<BOOL>(0x6A938874794628B1, player); } // 0x6A938874794628B1 0x013B4F72
	static BOOL _0xB5E4C8A517C3E09F(Player player, int p1, BOOL p2) { return invoke<BOOL>(0xB5E4C8A517C3E09F, player, p1, p2); } // 0xB5E4C8A517C3E09F 0x9DF75B2A
	static void _0x55730D5769312729(float x, float y, float z) { invoke<Void>(0x55730D5769312729, x, y, z); } // 0x55730D5769312729
	static BOOL IS_PLAYER_RIDING_TRAIN(Player player) { return invoke<BOOL>(0x012CF4110A50B8CF, player); } // 0x012CF4110A50B8CF 0x9765E71D
	static BOOL HAS_PLAYER_LEFT_THE_WORLD(Player player) { return invoke<BOOL>(0x6E7C27BBE0DAA551, player); } // 0x6E7C27BBE0DAA551 0xFEA40B6C
	static void _0x4C7EA1272F36765B(Player player, BOOL p1) { invoke<Void>(0x4C7EA1272F36765B, player, p1); } // 0x4C7EA1272F36765B 0xAD8383FA
	static void SET_PLAYER_PARACHUTE_VARIATION_OVERRIDE(Player player, int p1, Any p2, Any p3, BOOL p4) { invoke<Void>(0x7C5645E2294E9058, player, p1, p2, p3, p4); } // 0x7C5645E2294E9058 0x9254249D
	static void CLEAR_PLAYER_PARACHUTE_VARIATION_OVERRIDE(Player player) { invoke<Void>(0x58C88FDDCD926217, player); } // 0x58C88FDDCD926217 0xFD60F5AB
	static void SET_PLAYER_PARACHUTE_MODEL_OVERRIDE(Player player, Hash model) { invoke<Void>(0x42DE5A4C53BD8400, player, model); } // 0x42DE5A4C53BD8400 0x5D382498
	static void CLEAR_PLAYER_PARACHUTE_MODEL_OVERRIDE(Player player) { invoke<Void>(0x81BDBB85C8F8EAC8, player); } // 0x81BDBB85C8F8EAC8 0x6FF034BB
	static void SET_PLAYER_PARACHUTE_PACK_MODEL_OVERRIDE(Player player, Hash model) { invoke<Void>(0x8F6A887B2D9FC666, player, model); } // 0x8F6A887B2D9FC666 0xA877FF5E
	static void CLEAR_PLAYER_PARACHUTE_PACK_MODEL_OVERRIDE(Player player) { invoke<Void>(0x244A3A24C6AE36FC, player); } // 0x244A3A24C6AE36FC 0xBB62AAC5
	static void DISABLE_PLAYER_VEHICLE_REWARDS(Player player) { invoke<Void>(0x15D6A8B53C4CE891, player); } // 0x15D6A8B53C4CE891 0x8C6E611D
	static void _0x8DE72BBF7E520C41(BOOL p0) { invoke<Void>(0x8DE72BBF7E520C41, p0); } // 0x8DE72BBF7E520C41 0x2849D4B2
	static void _0x2E6EC8A635DB3DE8(BOOL p0, ScrHandle p1) { invoke<Void>(0x2E6EC8A635DB3DE8, p0, p1); } // 0x2E6EC8A635DB3DE8
	static BOOL _0xCA30614C39A8D9B7(Player p0) { return invoke<BOOL>(0xCA30614C39A8D9B7, p0); } // 0xCA30614C39A8D9B7
	static void _0x966988F43C865C0F(Any p0) { invoke<Void>(0x966988F43C865C0F, p0); } // 0x966988F43C865C0F
	static Player _0x37327D0F0DD18E8F(int* p0) { return invoke<Player>(0x37327D0F0DD18E8F, p0); } // 0x37327D0F0DD18E8F
}

namespace ENTITY
{
	static BOOL DOES_ENTITY_EXIST(Entity entity) { return invoke<BOOL>(0x23E9113C762466ED, entity); } // 0x23E9113C762466ED 0x3AC90869
	static BOOL DOES_ENTITY_BELONG_TO_THIS_SCRIPT(Entity entity, BOOL p1) { return invoke<BOOL>(0x45CA7F42CA715849, entity, p1); } // 0x45CA7F42CA715849 0xACFEB3F9
	static BOOL DOES_ENTITY_HAVE_DRAWABLE(Entity entity) { return invoke<BOOL>(0x187275C7EBD45454, entity); } // 0x187275C7EBD45454 0xA5B33300
	static BOOL DOES_ENTITY_HAVE_PHYSICS(Entity entity) { return invoke<BOOL>(0x4720158F9AAE8C56, entity); } // 0x4720158F9AAE8C56 0x9BCD2979
	static BOOL HAS_ENTITY_ANIM_FINISHED(Entity entity, char* animDict, char* animName, int p3) { return invoke<BOOL>(0x2C25C5D1DD2F94CE, entity, animDict, animName, p3); } // 0x2C25C5D1DD2F94CE 0x1D9CAB92
	static BOOL HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT(Entity entity) { return invoke<BOOL>(0xC951922EF432DFAE, entity); } // 0xC951922EF432DFAE 0x6B74582E
	static BOOL HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED(Entity entity) { return invoke<BOOL>(0x15CAF505CC185675, entity); } // 0x15CAF505CC185675 0x53FD4A25
	static BOOL HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE(Entity entity) { return invoke<BOOL>(0x502D8CF96961DF1A, entity); } // 0x502D8CF96961DF1A 0x878C2CE0
	static BOOL HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY(Entity entity1, Entity entity2, BOOL p2) { return invoke<BOOL>(0xC017443DBE6DA4D6, entity1, entity2, p2); } // 0xC017443DBE6DA4D6 0x07FC77E0
	static BOOL HAS_ENTITY_CLEAR_LOS_TO_ENTITY(Entity entity1, Entity entity2, int traceType) { return invoke<BOOL>(0x7F5C1711F4E1FDF7, entity1, entity2, traceType); } // 0x7F5C1711F4E1FDF7 0x53576FA7
	static BOOL HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT(Entity entity1, Entity entity2) { return invoke<BOOL>(0xBFA45A07A3FB8280, entity1, entity2); } // 0xBFA45A07A3FB8280 0x210D87C8
	static BOOL HAS_ENTITY_COLLIDED_WITH_ANYTHING(Entity entity) { return invoke<BOOL>(0xDF0087E7822095AA, entity); } // 0xDF0087E7822095AA 0x662A2F41
	static Hash GET_LAST_MATERIAL_HIT_BY_ENTITY(Entity entity) { return invoke<Hash>(0x67275CB070FBB2E1, entity); } // 0x67275CB070FBB2E1 0xC0E3AA47
	static Vector3 GET_COLLISION_NORMAL_OF_LAST_HIT_FOR_ENTITY(Entity entity) { return invoke<Vector3>(0xBD084C8E198BF30A, entity); } // 0xBD084C8E198BF30A 0xAB415C07
	static void FORCE_ENTITY_AI_AND_ANIMATION_UPDATE(Entity entity) { invoke<Void>(0x464F1CA52B023D8D, entity); } // 0x464F1CA52B023D8D 0x58D9775F
	static float GET_ENTITY_ANIM_CURRENT_TIME(Entity entity, char* animDict, char* animName) { return invoke<float>(0x8E978F99E8F731CB, entity, animDict, animName); } // 0x8E978F99E8F731CB 0x83943F41
	static float GET_ENTITY_ANIM_TOTAL_TIME(Entity entity, char* animDict, char* animName) { return invoke<float>(0x2C543E10BA51C209, entity, animDict, animName); } // 0x2C543E10BA51C209 0x433A9D18
	static float _GET_ENTITY_ANIM_DURATION(char* animDict, char* animName) { return invoke<float>(0x17133AD43DA5886F, animDict, animName); } // 0x17133AD43DA5886F
	static Entity GET_ENTITY_ATTACHED_TO(Entity entity) { return invoke<Entity>(0xE0614756D21445A5, entity); } // 0xE0614756D21445A5 0xFE1589F9
	static Vector3 GET_ENTITY_COORDS(Entity entity, BOOL alive) { return invoke<Vector3>(0x57240623C1BC6E88, entity, alive); } // 0x57240623C1BC6E88 0x1647F1CB
	static Vector3 GET_ENTITY_FORWARD_VECTOR(Entity entity) { return invoke<Vector3>(0x8C79B6FF2A91C93F, entity); } // 0x8C79B6FF2A91C93F 0x84DCECBF
	static float GET_ENTITY_FORWARD_X(Entity entity) { return invoke<float>(0x3CC705FEE75AD924, entity); } // 0x3CC705FEE75AD924 0x49FAE914
	static float GET_ENTITY_FORWARD_Y(Entity entity) { return invoke<float>(0x2CC1DDDC40661097, entity); } // 0x2CC1DDDC40661097 0x9E2F917C
	static float GET_ENTITY_HEADING(Entity entity) { return invoke<float>(0x638527C9799F2AE4, entity); } // 0x638527C9799F2AE4 0x972CC383
	static float _GET_ENTITY_PHYSICS_HEADING(Entity entity) { return invoke<float>(0xFC63C35C4CCFDDF1, entity); } // 0xFC63C35C4CCFDDF1
	static int GET_ENTITY_HEALTH(Entity entity) { return invoke<int>(0xB5DF060B138CD2EA, entity); } // 0xB5DF060B138CD2EA 0x8E3222B7
	static int GET_ENTITY_MAX_HEALTH(Entity entity) { return invoke<int>(0xCB889EF93F21460A, entity); } // 0xCB889EF93F21460A 0xC7AE6AA1
	static void SET_ENTITY_MAX_HEALTH(Entity entity, int value) { invoke<Void>(0x26504D4D69F462A1, entity, value); } // 0x26504D4D69F462A1 0x96F84DF8
	static float GET_ENTITY_HEIGHT(Entity entity, float X, float Y, float Z, BOOL atTop, BOOL inWorldCoords) { return invoke<float>(0xF36B7776BFB03234, entity, X, Y, Z, atTop, inWorldCoords); } // 0xF36B7776BFB03234 0xEE443481
	static float GET_ENTITY_HEIGHT_ABOVE_GROUND(Entity entity) { return invoke<float>(0xEF1ECDC49CE81822, entity); } // 0xEF1ECDC49CE81822 0x57F56A4D
	static void GET_ENTITY_MATRIX(Entity entity, Vector3* rightVector, Vector3* forwardVector, Vector3* upVector, Vector3* position) { invoke<Void>(0x0A3949A30D4211BD, entity, rightVector, forwardVector, upVector, position); } // 0x0A3949A30D4211BD 0xEB9EB001
	static Hash GET_ENTITY_MODEL(Entity entity) { return invoke<Hash>(0x0324EEB10F81965F, entity); } // 0x0324EEB10F81965F 0xDAFCB3EC
	static Vector3 GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS(Entity entity, float posX, float posY, float posZ) { return invoke<Vector3>(0x3ACAA2B62026685B, entity, posX, posY, posZ); } // 0x3ACAA2B62026685B 0x6477EC9E
	static Vector3 GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Entity entity, float offsetX, float offsetY, float offsetZ) { return invoke<Vector3>(0x854ED33E6D715648, entity, offsetX, offsetY, offsetZ); } // 0x854ED33E6D715648 0xABCF043A
	static float GET_ENTITY_PITCH(Entity entity) { return invoke<float>(0x00A1AAF0D1B4A3AF, entity); } // 0x00A1AAF0D1B4A3AF 0xFCE6ECE5
	static void GET_ENTITY_QUATERNION(Entity entity, float* x, float* y, float* z, float* w) { invoke<Void>(0x356B03AFE1FA3C9A, entity, x, y, z, w); } // 0x356B03AFE1FA3C9A 0x5154EC90
	static float GET_ENTITY_ROLL(Entity entity) { return invoke<float>(0x36C61EAA91A65598, entity); } // 0x36C61EAA91A65598 0x36610842
	static Vector3 GET_ENTITY_ROTATION(Entity entity, int rotationOrder) { return invoke<Vector3>(0xED13B51A133E020F, entity, rotationOrder); } // 0xED13B51A133E020F 0x8FF45B04
	static Vector3 GET_ENTITY_ROTATION_VELOCITY(Entity entity) { return invoke<Vector3>(0x6FC0E19BFAEEC071, entity); } // 0x6FC0E19BFAEEC071 0x9BF8A73F
	static char* GET_ENTITY_SCRIPT(Entity entity, ScrHandle* script) { return invoke<char*>(0x1F1F11C691B0636E, entity, script); } // 0x1F1F11C691B0636E 0xB7F70784
	static float GET_ENTITY_SPEED(Entity entity) { return invoke<float>(0x13B7ACE69D27E3E4, entity); } // 0x13B7ACE69D27E3E4 0x9E1E4798
	static Vector3 GET_ENTITY_SPEED_VECTOR(Entity entity, BOOL relative) { return invoke<Vector3>(0x4C17A06B99B6CC49, entity, relative); } // 0x4C17A06B99B6CC49 0x3ED2B997
	static float GET_ENTITY_UPRIGHT_VALUE(Entity entity) { return invoke<float>(0x2BB7527A68E10019, entity); } // 0x2BB7527A68E10019 0xF4268190
	static Vector3 GET_ENTITY_VELOCITY(Entity entity) { return invoke<Vector3>(0xACA666C39EA49E82, entity); } // 0xACA666C39EA49E82 0xC14C9B6B
	static Object GET_OBJECT_INDEX_FROM_ENTITY_INDEX(Entity entity) { return invoke<Object>(0xACDCB2312E61BD53, entity); } // 0xACDCB2312E61BD53 0xBC5A9C58
	static Ped GET_PED_INDEX_FROM_ENTITY_INDEX(Entity entity) { return invoke<Ped>(0xB80CAAF3D65FBC1F, entity); } // 0xB80CAAF3D65FBC1F 0xC46F74AC
	static Vehicle GET_VEHICLE_INDEX_FROM_ENTITY_INDEX(Entity entity) { return invoke<Vehicle>(0xBFC71CD990E479DB, entity); } // 0xBFC71CD990E479DB 0xC69CF43D
	static Vector3 GET_WORLD_POSITION_OF_ENTITY_BONE(Entity entity, int boneIndex) { return invoke<Vector3>(0xE9833D7A09D570F1, entity, boneIndex); } // 0xE9833D7A09D570F1 0x7C6339DF
	static Player GET_NEAREST_PLAYER_TO_ENTITY(Entity entity) { return invoke<Player>(0x3E9719F9B6ECC4E2, entity); } // 0x3E9719F9B6ECC4E2 0xCE17FDEC
	static Player GET_NEAREST_PLAYER_TO_ENTITY_ON_TEAM(Entity entity, int team) { return invoke<Player>(0x81FF9E041D07C752, entity, team); } // 0x81FF9E041D07C752 0xB1808F56
	static int GET_ENTITY_TYPE(Entity entity) { return invoke<int>(0xAAF5E7F32D990A34, entity); } // 0xAAF5E7F32D990A34 0x0B1BD08D
	static int _GET_ENTITY_POPULATION_TYPE(Entity entity) { return invoke<int>(0x9ACD5DC406070E12, entity); } // 0x9ACD5DC406070E12
	static BOOL IS_AN_ENTITY(int handle) { return invoke<BOOL>(0x2032470B7EE4912E, handle); } // 0x2032470B7EE4912E 0xD4B9715A
	static BOOL IS_ENTITY_A_PED(Entity entity) { return invoke<BOOL>(0x80E9CA64E9C8E070, entity); } // 0x80E9CA64E9C8E070 0x55D33EAB
	static BOOL IS_ENTITY_A_MISSION_ENTITY(Entity entity) { return invoke<BOOL>(0xC26429B504BA534D, entity); } // 0xC26429B504BA534D 0x2632E124
	static BOOL IS_ENTITY_A_VEHICLE(Entity entity) { return invoke<BOOL>(0x3983CCB0D958159C, entity); } // 0x3983CCB0D958159C 0xBE800B01
	static BOOL IS_ENTITY_AN_OBJECT(Entity entity) { return invoke<BOOL>(0x1461B0B259D86067, entity); } // 0x1461B0B259D86067 0x3F52E561
	static BOOL IS_ENTITY_AT_COORD(Entity entity, float xPos, float yPos, float zPos, float xSize, float ySize, float zSize, BOOL p7, BOOL p8, int p9) { return invoke<BOOL>(0x1C34CE8087E3897C, entity, xPos, yPos, zPos, xSize, ySize, zSize, p7, p8, p9); } // 0x1C34CE8087E3897C 0xD749B606
	static BOOL IS_ENTITY_AT_ENTITY(Entity entity1, Entity entity2, float xSize, float ySize, float zSize, BOOL p5, BOOL p6, int p7) { return invoke<BOOL>(0x4E84D2C9B54F79BA, entity1, entity2, xSize, ySize, zSize, p5, p6, p7); } // 0x4E84D2C9B54F79BA 0xDABDCB52
	static BOOL IS_ENTITY_ATTACHED(Entity entity) { return invoke<BOOL>(0xDDBA7A42B9B819EE, entity); } // 0xDDBA7A42B9B819EE 0xEC1479D5
	static BOOL IS_ENTITY_ATTACHED_TO_ANY_OBJECT(Entity entity) { return invoke<BOOL>(0x55544CA7BCF065EB, entity); } // 0x55544CA7BCF065EB 0x0B5DE340
	static BOOL IS_ENTITY_ATTACHED_TO_ANY_PED(Entity entity) { return invoke<BOOL>(0xF928485DD4C9E3C3, entity); } // 0xF928485DD4C9E3C3 0x9D7A609C
	static BOOL IS_ENTITY_ATTACHED_TO_ANY_VEHICLE(Entity entity) { return invoke<BOOL>(0xE59622A0BE598996, entity); } // 0xE59622A0BE598996 0xDE5C995E
	static BOOL IS_ENTITY_ATTACHED_TO_ENTITY(Entity from, Entity to) { return invoke<BOOL>(0xB5F23D615B19D188, from, to); } // 0xB5F23D615B19D188 0xB0ABFEA8
	static BOOL IS_ENTITY_DEAD(Entity entity) { return invoke<BOOL>(0xA929B2923D14E2F8, entity); } // 0xA929B2923D14E2F8 0xB6F7CBAC
	static BOOL IS_ENTITY_IN_AIR(Entity entity) { return invoke<BOOL>(0x14E01C4EC4170496, entity); } // 0x14E01C4EC4170496 0xA4157987
	static BOOL IS_ENTITY_IN_ANGLED_AREA(Entity entity, float originX, float originY, float originZ, float edgeX, float edgeY, float edgeZ, float angle, BOOL p8, BOOL p9, Any p10) { return invoke<BOOL>(0x70A9F320A34FAC28, entity, originX, originY, originZ, edgeX, edgeY, edgeZ, angle, p8, p9, p10); } // 0x70A9F320A34FAC28 0x883622FA
	static BOOL IS_ENTITY_IN_AREA(Entity entity, float x1, float y1, float z1, float x2, float y2, float z2, BOOL p7, BOOL p8, Any p9) { return invoke<BOOL>(0xDCA576CE5CF67643, entity, x1, y1, z1, x2, y2, z2, p7, p8, p9); } // 0xDCA576CE5CF67643 0x8C2DFA9D
	static BOOL IS_ENTITY_IN_ZONE(Entity entity, char* zone) { return invoke<BOOL>(0xD241E7F168CCC46B, entity, zone); } // 0xD241E7F168CCC46B 0x45C82B21
	static BOOL IS_ENTITY_IN_WATER(Entity entity) { return invoke<BOOL>(0xA77EE6C138A588EB, entity); } // 0xA77EE6C138A588EB 0x4C3C2508
	static float GET_ENTITY_SUBMERGED_LEVEL(Entity entity) { return invoke<float>(0x36A9D1BD116D3378, entity); } // 0x36A9D1BD116D3378 0x0170F68C
	static void _0x40C86342C3155AA3(Entity entity, BOOL p1) { invoke<Void>(0x40C86342C3155AA3, entity, p1); } // 0x40C86342C3155AA3 0x40C84A74
	static BOOL IS_ENTITY_ON_SCREEN(Entity entity) { return invoke<BOOL>(0x1DCFA79E268F3EE5, entity); } // 0x1DCFA79E268F3EE5 0xC1FEC5ED
	static BOOL IS_ENTITY_PLAYING_ANIM(Entity entity, char* animDict, char* animName, int p4) { return invoke<BOOL>(0x5132972D2BBC5A62, entity, animDict, animName, p4); } // 0x5132972D2BBC5A62 0x0D130D34
	static BOOL IS_ENTITY_STATIC(Entity entity) { return invoke<BOOL>(0xE9B3D890AA708E65, entity); } // 0xE9B3D890AA708E65 0x928E12E9
	static BOOL IS_ENTITY_TOUCHING_ENTITY(Entity entity, Entity targetEntity) { return invoke<BOOL>(0xB42101338C533CB4, entity, targetEntity); } // 0xB42101338C533CB4 0x6B931477
	static BOOL IS_ENTITY_TOUCHING_MODEL(Entity entity, Hash modelHash) { return invoke<BOOL>(0x9A0AFF9F9438A569, entity, modelHash); } // 0x9A0AFF9F9438A569 0x307E7611
	static BOOL IS_ENTITY_UPRIGHT(Entity entity, float angle) { return invoke<BOOL>(0x16924971637B41FA, entity, angle); } // 0x16924971637B41FA 0x3BCDF4E1
	static BOOL IS_ENTITY_UPSIDEDOWN(Entity entity) { return invoke<BOOL>(0x879A5482D4D7A218, entity); } // 0x879A5482D4D7A218 0x5ACAA48F
	static BOOL IS_ENTITY_VISIBLE(Entity entity) { return invoke<BOOL>(0xADA6DD2D53C59AF0, entity); } // 0xADA6DD2D53C59AF0 0x120B4ED5
	static BOOL IS_ENTITY_VISIBLE_TO_SCRIPT(Entity entity) { return invoke<BOOL>(0xF86EF5C41AFF5F1F, entity); } // 0xF86EF5C41AFF5F1F 0x5D240E9D
	static BOOL IS_ENTITY_OCCLUDED(Entity entity) { return invoke<BOOL>(0xF6563E19EDE84B8C, entity); } // 0xF6563E19EDE84B8C 0x46BC5B40
	static BOOL WOULD_ENTITY_BE_OCCLUDED(Hash hash, float x, float y, float z, BOOL p4) { return invoke<BOOL>(0x2A1D8FBE752DC0A9, hash, x, y, z, p4); } // 0x2A1D8FBE752DC0A9 0xEA127CBC
	static BOOL IS_ENTITY_WAITING_FOR_WORLD_COLLISION(Entity entity) { return invoke<BOOL>(0x8AE479EBB6CE5562, entity); } // 0x8AE479EBB6CE5562 0x00AB7A4A
	static void APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(Entity entity, int forceType, float x, float y, float z, BOOL p5, BOOL isRel, BOOL highForce, BOOL p8) { invoke<Void>(0x71B44214524C059C, entity, forceType, x, y, z, p5, isRel, highForce, p8); } // 0x71B44214524C059C 0x28924E98
	static void APPLY_FORCE_TO_ENTITY(Entity entity, int forceType, float x, float y, float z, float xRot, float yRot, float zRot, int boneIndex, BOOL isRel, BOOL p10, BOOL highForce, BOOL p12, BOOL p13) { invoke<Void>(0x5C9883713FC5A923, entity, forceType, x, y, z, xRot, yRot, zRot, boneIndex, isRel, p10, highForce, p12, p13); } // 0x5C9883713FC5A923 0xC1C0855A
	static void ATTACH_ENTITY_TO_ENTITY(Entity entity1, Entity entity2, int boneIndex, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, BOOL p9, BOOL useSoftPinning, BOOL collision, BOOL isPed, int vertexIndex, BOOL fixedRot) { invoke<Void>(0x593C85206F061E3E, entity1, entity2, boneIndex, xPos, yPos, zPos, xRot, yRot, zRot, p9, useSoftPinning, collision, isPed, vertexIndex, fixedRot); } // 0x593C85206F061E3E 0xEC024237
	static void ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(Entity entity1, Entity entity2, int boneIndex1, int boneIndex2, float xPos1, float yPos1, float zPos1, float xPos2, float yPos2, float zPos2, float xRot, float yRot, float zRot, float breakForce, BOOL fixedRot, BOOL p15, BOOL collision, BOOL p17, int p18) { invoke<Void>(0x5B804E38147E1CF0, entity1, entity2, boneIndex1, boneIndex2, xPos1, yPos1, zPos1, xPos2, yPos2, zPos2, xRot, yRot, zRot, breakForce, fixedRot, p15, collision, p17, p18); } // 0x5B804E38147E1CF0 0x0547417F
	static void PROCESS_ENTITY_ATTACHMENTS(Entity entity) { invoke<Void>(0x4647402DC8FF2646, entity); } // 0x4647402DC8FF2646 0x6909BA59
	static int GET_ENTITY_BONE_INDEX_BY_NAME(Entity entity, char* boneName) { return invoke<int>(0x36ACE2C7E56D90D6, entity, boneName); } // 0x36ACE2C7E56D90D6 0xE4ECAC22
	static void CLEAR_ENTITY_LAST_DAMAGE_ENTITY(Entity entity) { invoke<Void>(0xCF458DC2F9000261, entity); } // 0xCF458DC2F9000261 0x2B83F43B
	static void DELETE_ENTITY(Entity* entity) { invoke<Void>(0x31D01D6DEF4B35AD, entity); } // 0x31D01D6DEF4B35AD 0xFAA3D236
	static void DETACH_ENTITY(Entity entity, BOOL p1, BOOL collision) { invoke<Void>(0xB2E72B5CFE1EC372, entity, p1, collision); } // 0xB2E72B5CFE1EC372 0xC8EFCB41
	static void FREEZE_ENTITY_POSITION(Entity entity, BOOL toggle) { invoke<Void>(0x98F0FA127445E343, entity, toggle); } // 0x98F0FA127445E343 0x65C16D57
	static void _SET_ENTITY_REGISTER(Entity entity, BOOL toggle) { invoke<Void>(0xBDE4C59FD939CE4E, entity, toggle); } // 0xBDE4C59FD939CE4E 0xD3850671
	static BOOL PLAY_ENTITY_ANIM(Entity entity, char* animName, char* propName, float p3, BOOL p4, BOOL p5, BOOL p6, float delta, Any bitset) { return invoke<BOOL>(0x15DDCF52D0DB08C1, entity, animName, propName, p3, p4, p5, p6, delta, bitset); } // 0x15DDCF52D0DB08C1 0x878753D5
	static BOOL PLAY_SYNCHRONIZED_ENTITY_ANIM(Entity entity, int syncedScene, char* animation, char* propName, float p4, float p5, Any p6, float p7) { return invoke<BOOL>(0x9C8510D976CE0748, entity, syncedScene, animation, propName, p4, p5, p6, p7); } // 0x9C8510D976CE0748 0x012760AA
	static BOOL PLAY_SYNCHRONIZED_MAP_ENTITY_ANIM(float p0, float p1, float p2, float p3, Any p4, Any p5, Any* p6, Any* p7, float p8, float p9, Any p10, float p11) { return invoke<BOOL>(0xB15E8754980122F2, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0xB15E8754980122F2 0xEB4CBA74
	static BOOL STOP_SYNCHRONIZED_MAP_ENTITY_ANIM(float p0, float p1, float p2, float p3, Any p4, float p5) { return invoke<BOOL>(0xADF869CA2E63487D, p0, p1, p2, p3, p4, p5); } // 0xADF869CA2E63487D 0x7253D5B2
	static Any STOP_ENTITY_ANIM(Entity entity, char* animation, char* animGroup, float p3) { return invoke<Any>(0x37879AC2AEA8EA4A, entity, animation, animGroup, p3); } // 0x37879AC2AEA8EA4A 0xC4769830
	static BOOL STOP_SYNCHRONIZED_ENTITY_ANIM(Entity entity, float p1, BOOL p2) { return invoke<BOOL>(0x36CA2EF7ACE06D15, entity, p1, p2); } // 0x36CA2EF7ACE06D15 0xE27D2FC1
	static BOOL HAS_ANIM_EVENT_FIRED(Entity entity, Hash actionHash) { return invoke<BOOL>(0x36D713BA3613126D, entity, actionHash); } // 0x36D713BA3613126D 0x66571CA0
	static BOOL FIND_ANIM_EVENT_PHASE(char* animDictionary, char* animName, char* p2, Any* p3, Any* p4) { return invoke<BOOL>(0x35CEBCB94FB318E2, animDictionary, animName, p2, p3, p4); } // 0x35CEBCB94FB318E2 0xC41DDA62
	static void SET_ENTITY_ANIM_CURRENT_TIME(Entity entity, char* animDictionary, char* animName, float time) { invoke<Void>(0x87CD14ED799DFD65, entity, animDictionary, animName, time); } // 0x87CD14ED799DFD65 0x99D90735
	static void SET_ENTITY_ANIM_SPEED(Entity entity, char* animDictionary, char* animName, float speedMultiplier) { invoke<Void>(0x64E8BCBA7FB39814, entity, animDictionary, animName, speedMultiplier); } // 0x64E8BCBA7FB39814 0x3990C90A
	static void SET_ENTITY_AS_MISSION_ENTITY(Entity entity, BOOL p1, BOOL byThisScript) { invoke<Void>(0xF0F77C99098F999B, entity, p1, byThisScript); } // 0xF0F77C99098F999B 0x5D1F9E0F
	static void SET_ENTITY_AS_NO_LONGER_NEEDED(Entity* entity) { invoke<Void>(0x47C2619E72CEAA4F, entity); } // 0x47C2619E72CEAA4F 0xADF2267C
	static void SET_PED_AS_NO_LONGER_NEEDED(Ped* ped) { invoke<Void>(0x6500ADB01E821BC0, ped); } // 0x6500ADB01E821BC0 0x9A388380
	static void SET_VEHICLE_AS_NO_LONGER_NEEDED(Vehicle* vehicle) { invoke<Void>(0x921CF98C637B0043, vehicle); } // 0x921CF98C637B0043 0x9B0E10BE
	static void SET_OBJECT_AS_NO_LONGER_NEEDED(Object* object) { invoke<Void>(0x7572E8CAC3330ACE, object); } // 0x7572E8CAC3330ACE 0x3F6B949F
	static void SET_ENTITY_CAN_BE_DAMAGED(Entity entity, BOOL toggle) { invoke<Void>(0xC3085A602BCA8C13, entity, toggle); } // 0xC3085A602BCA8C13 0x60B6E744
	static void SET_ENTITY_CAN_BE_DAMAGED_BY_RELATIONSHIP_GROUP(Entity entity, BOOL p1, Any p2) { invoke<Void>(0xF13F51867F2A8475, entity, p1, p2); } // 0xF13F51867F2A8475 0x34165B5D
	static void SET_ENTITY_CAN_BE_TARGETED_WITHOUT_LOS(Entity entity, BOOL toggle) { invoke<Void>(0x78AB5E99B83BE3F1, entity, toggle); } // 0x78AB5E99B83BE3F1 0x3B13797C
	static void SET_ENTITY_COLLISION(Entity entity, BOOL toggle, BOOL keepPhysics) { invoke<Void>(0xCEDF2A713644AEDA, entity, toggle, keepPhysics); } // 0xCEDF2A713644AEDA 0x139FD37D
	static BOOL _IS_ENTITY_COLLISON_DISABLED(Entity entity) { return invoke<BOOL>(0xD1249B1013276283, entity); } // 0xD1249B1013276283
	static void _0x67B1B694FCB6690D(Entity entity, BOOL p1, BOOL p2) { invoke<Void>(0x67B1B694FCB6690D, entity, p1, p2); } // 0x67B1B694FCB6690D
	static void SET_ENTITY_COORDS(Entity entity, float xPos, float yPos, float zPos, BOOL xAxis, BOOL yAxis, BOOL zAxis, BOOL clearArea) { invoke<Void>(0x5DC8C2F2F8A363C2, entity, xPos, yPos, zPos, xAxis, yAxis, zAxis, clearArea); } // 0x5DC8C2F2F8A363C2 0xDF70B41B
	static void _SET_ENTITY_COORDS_2(Entity entity, float xPos, float yPos, float zPos, BOOL xAxis, BOOL yAxis, BOOL zAxis, BOOL clearArea) { invoke<Void>(0x6E7F479275A5ADC8, entity, xPos, yPos, zPos, xAxis, yAxis, zAxis, clearArea); } // 0x6E7F479275A5ADC8
	static void SET_ENTITY_COORDS_NO_OFFSET(Entity entity, float xPos, float yPos, float zPos, BOOL xAxis, BOOL yAxis, BOOL zAxis) { invoke<Void>(0x394AE1BE8F25AC5B, entity, xPos, yPos, zPos, xAxis, yAxis, zAxis); } // 0x394AE1BE8F25AC5B 0x4C83DE8D
	static void SET_ENTITY_DYNAMIC(Entity entity, BOOL toggle) { invoke<Void>(0x46B421AC0DE69583, entity, toggle); } // 0x46B421AC0DE69583 0x236F525B
	static void SET_ENTITY_HEADING(Entity entity, float heading) { invoke<Void>(0x0608D50823C6AA6D, entity, heading); } // 0x0608D50823C6AA6D 0xE0FF064D
	static void SET_ENTITY_HEALTH(Entity entity, int health) { invoke<Void>(0x4B04B4FAE554FA03, entity, health); } // 0x4B04B4FAE554FA03 0xFBCD1831
	static void SET_ENTITY_INVINCIBLE(Entity entity, BOOL toggle) { invoke<Void>(0xC6042F55A6EA17B2, entity, toggle); } // 0xC6042F55A6EA17B2 0xC1213A21
	static void SET_ENTITY_IS_TARGET_PRIORITY(Entity entity, BOOL p1, float p2) { invoke<Void>(0x7771211498B88EA3, entity, p1, p2); } // 0x7771211498B88EA3 0x9729EE32
	static void SET_ENTITY_LIGHTS(Entity entity, BOOL toggle) { invoke<Void>(0xD1702E0E0BF90AEF, entity, toggle); } // 0xD1702E0E0BF90AEF 0xE8FC85AF
	static void SET_ENTITY_LOAD_COLLISION_FLAG(Entity entity, BOOL toggle) { invoke<Void>(0x4114B83B329702FF, entity, toggle); } // 0x4114B83B329702FF 0xC52F295B
	static BOOL HAS_COLLISION_LOADED_AROUND_ENTITY(Entity entity) { return invoke<BOOL>(0xDFC6732B93B0B773, entity); } // 0xDFC6732B93B0B773 0x851687F9
	static void SET_ENTITY_MAX_SPEED(Entity entity, float speed) { invoke<Void>(0xDC7CC8030D7E6D2E, entity, speed); } // 0xDC7CC8030D7E6D2E 0x46AFFED3
	static void SET_ENTITY_ONLY_DAMAGED_BY_PLAYER(Entity entity, BOOL toggle) { invoke<Void>(0x6FE87B0CB5BE8FB1, entity, toggle); } // 0x6FE87B0CB5BE8FB1 0x4B707F50
	static void SET_ENTITY_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP(Entity entity, BOOL p1, Any p2) { invoke<Void>(0x23863B7BF3FD2FDA, entity, p1, p2); } // 0x23863B7BF3FD2FDA 0x202237E2
	static void SET_ENTITY_PROOFS(Entity entity, BOOL bulletProof, BOOL fireProof, BOOL explosionProof, BOOL collisionProof, BOOL meleeProof, BOOL p6, BOOL p7, BOOL drownProof) { invoke<Void>(0x4C44C1A3160350E2, entity, bulletProof, fireProof, explosionProof, collisionProof, meleeProof, p6, p7, drownProof); } // 0x4C44C1A3160350E2 0x7E9EAB66
	static void SET_ENTITY_QUATERNION(Entity entity, float x, float y, float z, float w) { invoke<Void>(0xFE2306F4BAC122B2, entity, x, y, z, w); } // 0xFE2306F4BAC122B2 0x83B6046F
	static void SET_ENTITY_RECORDS_COLLISIONS(Entity entity, BOOL toggle) { invoke<Void>(0xF7190FFAC79BD5C5, entity, toggle); } // 0xF7190FFAC79BD5C5 0x6B189A1A
	static void SET_ENTITY_ROTATION(Entity entity, float pitch, float roll, float yaw, int rotationOrder, BOOL p5) { invoke<Void>(0x04A5FAE5B1EB8E28, entity, pitch, roll, yaw, rotationOrder, p5); } // 0x04A5FAE5B1EB8E28 0x0A345EFE
	static void SET_ENTITY_VISIBLE(Entity entity, BOOL toggle, BOOL unk) { invoke<Void>(0x027DB6817AB239EB, entity, toggle, unk); } // 0x027DB6817AB239EB 0xD043E8E1
	static void SET_ENTITY_VELOCITY(Entity entity, float x, float y, float z) { invoke<Void>(0x7B846714372D2EEF, entity, x, y, z); } // 0x7B846714372D2EEF 0xFF5A1988
	static void SET_ENTITY_HAS_GRAVITY(Entity entity, BOOL toggle) { invoke<Void>(0xEE71EA1985CE0622, entity, toggle); } // 0xEE71EA1985CE0622 0xE2F262BF
	static void SET_ENTITY_LOD_DIST(Entity entity, int value) { invoke<Void>(0x2380074FC04D1644, entity, value); } // 0x2380074FC04D1644 0xD7ACC7AD
	static int GET_ENTITY_LOD_DIST(Entity entity) { return invoke<int>(0x969F825B7EACA49A, entity); } // 0x969F825B7EACA49A 0x4DA3D51F
	static void SET_ENTITY_ALPHA(Entity entity, int alphaLevel, BOOL skin) { invoke<Void>(0x40687975EC655FA3, entity, alphaLevel, skin); } // 0x40687975EC655FA3 0xAE667CB0
	static int GET_ENTITY_ALPHA(Entity entity) { return invoke<int>(0x82B2A4B3FACCFED6, entity); } // 0x82B2A4B3FACCFED6 0x1560B017
	static void RESET_ENTITY_ALPHA(Entity entity) { invoke<Void>(0xECCF1F643FA6EA50, entity); } // 0xECCF1F643FA6EA50 0x8A30761C
	static void _0xA0C5F6CD3881AC11(Entity entity, float p1) { invoke<Void>(0xA0C5F6CD3881AC11, entity, p1); } // 0xA0C5F6CD3881AC11
	static void SET_ENTITY_ALWAYS_PRERENDER(Entity entity, BOOL toggle) { invoke<Void>(0x8BD47DD2FF60B258, entity, toggle); } // 0x8BD47DD2FF60B258 0xD8FF798A
	static void SET_ENTITY_RENDER_SCORCHED(Entity entity, BOOL toggle) { invoke<Void>(0x91742AFAA0864828, entity, toggle); } // 0x91742AFAA0864828 0xAAC9317B
	static void SET_ENTITY_TRAFFICLIGHT_OVERRIDE(Entity entity, int state) { invoke<Void>(0x2C8C62D26B8027F5, entity, state); } // 0x2C8C62D26B8027F5 0xC47F5B91
	static void _0x9E59B9B479ACB6F0(Entity entity) { invoke<Void>(0x9E59B9B479ACB6F0, entity); } // 0x9E59B9B479ACB6F0
	static void CREATE_MODEL_SWAP(float x, float y, float z, float radius, Hash originalModel, Hash newModel, BOOL p6) { invoke<Void>(0x95D497EEDCDA9DD1, x, y, z, radius, originalModel, newModel, p6); } // 0x95D497EEDCDA9DD1 0x0BC12F9E
	static void REMOVE_MODEL_SWAP(float x, float y, float z, float radius, Hash originalModel, Hash newModel, BOOL p6) { invoke<Void>(0xBFB926900526C8A5, x, y, z, radius, originalModel, newModel, p6); } // 0xBFB926900526C8A5 0xCE0AA8BC
	static void CREATE_MODEL_HIDE(float x, float y, float z, float radius, Hash model, BOOL p5) { invoke<Void>(0xB30185B1BE926A58, x, y, z, radius, model, p5); } // 0xB30185B1BE926A58 0x7BD5CF2F
	static void CREATE_MODEL_HIDE_EXCLUDING_SCRIPT_OBJECTS(float x, float y, float z, float radius, Hash model, BOOL p5) { invoke<Void>(0x51A83E0BB392D7CF, x, y, z, radius, model, p5); } // 0x51A83E0BB392D7CF 0x07AAF22C
	static void REMOVE_MODEL_HIDE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<Void>(0x55718AC3667F2A7D, p0, p1, p2, p3, p4, p5); } // 0x55718AC3667F2A7D 0x993DBC10
	static void CREATE_FORCED_OBJECT(float x, float y, float z, Any p3, Hash modelHash, BOOL p5) { invoke<Void>(0x9ADE91E3B3EF91ED, x, y, z, p3, modelHash, p5); } // 0x9ADE91E3B3EF91ED 0x335190A2
	static void REMOVE_FORCED_OBJECT(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0xCEDCD4EE7A593BF3, p0, p1, p2, p3, p4); } // 0xCEDCD4EE7A593BF3 0xAED73ADD
	static void SET_ENTITY_NO_COLLISION_ENTITY(Entity entity1, Entity entity2, BOOL collision) { invoke<Void>(0xBA2FCD05F658F91E, entity1, entity2, collision); } // 0xBA2FCD05F658F91E 0x1E11BFE9
	static void SET_ENTITY_MOTION_BLUR(Entity entity, BOOL toggle) { invoke<Void>(0x0E4C7333057699B6, entity, toggle); } // 0x0E4C7333057699B6 0xE90005B8
	static void _0xABCF7963E043518F(Entity entity, BOOL p1) { invoke<Void>(0xABCF7963E043518F, entity, p1); } // 0xABCF7963E043518F 0x44767B31
	static void _0xDBC1E13AD78EA66B(Entity entity, BOOL p1) { invoke<Void>(0xDBC1E13AD78EA66B, entity, p1); } // 0xDBC1E13AD78EA66B 0xE224A6A5
	static void _0x0CFC8E2C09FCEB99(Entity entity, BOOL p1) { invoke<Void>(0x0CFC8E2C09FCEB99, entity, p1); } // 0x0CFC8E2C09FCEB99
	static void _0x9F3F8AAB427A0ABA(Entity entity, BOOL p1) { invoke<Void>(0x9F3F8AAB427A0ABA, entity, p1); } // 0x9F3F8AAB427A0ABA
	static void _0x87A4D012E49F7266(Entity entity, BOOL p1) { invoke<Void>(0x87A4D012E49F7266, entity, p1); } // 0x87A4D012E49F7266
}

namespace PED
{
	static Ped CREATE_PED(int pedType, Hash modelHash, float x, float y, float z, float heading, BOOL networkHandle, BOOL pedHandle) { return invoke<Ped>(0x2AD5F4170F4ACBEB, pedType, modelHash, x, y, z, heading, networkHandle, pedHandle); } // 0x2AD5F4170F4ACBEB 0x0389EF71
	static void DELETE_PED(Ped* ped) { invoke<Void>(0x478AE709A466CB7E, ped); } // 0x478AE709A466CB7E 0x13EFB9A0
	static Ped CLONE_PED(Ped ped, float heading, BOOL networkHandle, BOOL pedHandle) { return invoke<Ped>(0x3E0339625D0649A5, ped, heading, networkHandle, pedHandle); } // 0x3E0339625D0649A5 0x8C8A8D6E
	static void CLONE_PED_TO_TARGET(Ped ped1, Ped ped2) { invoke<Void>(0xC48D9574604CA563, ped1, ped2); } // 0xC48D9574604CA563 0xFC70EEC7
	static BOOL IS_PED_IN_VEHICLE(Ped ped, Vehicle vehicle, BOOL atGetIn) { return invoke<BOOL>(0x2315BB1606BC3DC3, ped, vehicle, atGetIn); } // 0x2315BB1606BC3DC3 0x7DA6BC83
	static BOOL IS_PED_IN_MODEL(Ped ped, Hash modelHash) { return invoke<BOOL>(0x0B231830DD7F8FD0, ped, modelHash); } // 0x0B231830DD7F8FD0 0xA6438D4B
	static BOOL IS_PED_IN_ANY_VEHICLE(Ped ped, BOOL atGetIn) { return invoke<BOOL>(0xFD0FE723227D5AB6, ped, atGetIn); } // 0xFD0FE723227D5AB6 0x3B0171EE
	static BOOL IS_COP_PED_IN_AREA_3D(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<BOOL>(0xDE8297C170BC834C, x1, y1, z1, x2, y2, z2); } // 0xDE8297C170BC834C 0xB98DB96B
	static BOOL IS_PED_INJURED(Ped ped) { return invoke<BOOL>(0xCA41A00932714525, ped); } // 0xCA41A00932714525 0x2530A087
	static BOOL IS_PED_HURT(Ped ped) { return invoke<BOOL>(0xD7E38AFD85859524, ped); } // 0xD7E38AFD85859524 0x69DFA0AF
	static BOOL IS_PED_FATALLY_INJURED(Ped ped) { return invoke<BOOL>(0x5315600F216E4653, ped); } // 0x5315600F216E4653 0xBADA0093
	static BOOL IS_PED_DEAD_OR_DYING(Ped ped, BOOL p1) { return invoke<BOOL>(0xE34CF180A5429DEA, ped, p1); } // 0xE34CF180A5429DEA 0xCBDB7739
	static BOOL IS_CONVERSATION_PED_DEAD(Ped ped) { return invoke<BOOL>(0xEF9D83EE772706A1, ped); } // 0xEF9D83EE772706A1 0x1FA39EFE
	static BOOL IS_PED_AIMING_FROM_COVER(Ped ped) { return invoke<BOOL>(0xBF8D41DF98D12931, ped); } // 0xBF8D41DF98D12931 0xDEBAB2AF
	static BOOL IS_PED_RELOADING(Ped ped) { return invoke<BOOL>(0x9A68600819F7F8C3, ped); } // 0x9A68600819F7F8C3 0x961E1745
	static BOOL IS_PED_A_PLAYER(Ped ped) { return invoke<BOOL>(0x0764AC92F08BEC9E, ped); } // 0x0764AC92F08BEC9E 0x404794CA
	static Ped CREATE_PED_INSIDE_VEHICLE(Vehicle vehicle, int pedType, Hash modelHash, int seat, BOOL networkHandle, BOOL pedHandle) { return invoke<Ped>(0x3FBC0964EB7878AF, vehicle, pedType, modelHash, seat, networkHandle, pedHandle); } // 0x3FBC0964EB7878AF 0x3000F092
	static void SET_PED_DESIRED_HEADING(Ped ped, float heading) { invoke<Void>(0x27C0989509D4C407, ped, heading); } // 0x27C0989509D4C407 0x961458F9
	static void _0xD2924AD1DB705845(Ped ped) { invoke<Void>(0xD2924AD1DB705845, ped); } // 0xD2924AD1DB705845 0x290421BE
	static BOOL IS_PED_FACING_PED(Ped ped, Ped otherPed, float angle) { return invoke<BOOL>(0xCAA82A181F15BFF5, ped, otherPed, angle); } // 0xCAA82A181F15BFF5 0x0B775838
	static BOOL IS_PED_IN_MELEE_COMBAT(Ped ped) { return invoke<BOOL>(0x658CF746EFCB633E, ped); } // 0x658CF746EFCB633E 0xFD7814A5
	static BOOL IS_PED_STOPPED(Ped ped) { return invoke<BOOL>(0x078054927A8129E2, ped); } // 0x078054927A8129E2 0xA0DC0B87
	static BOOL IS_PED_SHOOTING_IN_AREA(Ped ped, float x1, float y1, float z1, float x2, float y2, float z2, BOOL p7, BOOL p8) { return invoke<BOOL>(0x3ADADED9839E575B, ped, x1, y1, z1, x2, y2, z2, p7, p8); } // 0x3ADADED9839E575B 0x741BF04F
	static BOOL IS_ANY_PED_SHOOTING_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2, BOOL p6, BOOL p7) { return invoke<BOOL>(0x9EC2A5A476FD900B, x1, y1, z1, x2, y2, z2, p6, p7); } // 0x9EC2A5A476FD900B 0x91833867
	static BOOL IS_PED_SHOOTING(Ped ped) { return invoke<BOOL>(0x1B30FA4AAC96F398, ped); } // 0x1B30FA4AAC96F398 0xE7C3405E
	static void SET_PED_ACCURACY(Ped ped, int accuracy) { invoke<Void>(0xFA4023BBD5BCB8B5, ped, accuracy); } // 0xFA4023BBD5BCB8B5 0x6C17122E
	static int GET_PED_ACCURACY(Ped ped) { return invoke<int>(0x73CB4B8366071C85, ped); } // 0x73CB4B8366071C85 0x0A2A0AA0
	static BOOL IS_PED_MODEL(Ped ped, Hash modelHash) { return invoke<BOOL>(0x840280E0FC76F9F6, ped, modelHash); } // 0x840280E0FC76F9F6 0x5F1DDFCB
	static void EXPLODE_PED_HEAD(Ped ped, Hash weaponHash) { invoke<Void>(0xE9582AAEA2A5C794, ped, weaponHash); } // 0xE9582AAEA2A5C794 0x05CC1380
	static void REMOVE_PED_ELEGANTLY(Ped* ped) { invoke<Void>(0xFAF7B63356ED24E5, ped); } // 0xFAF7B63356ED24E5 0x4FFB8C6C
	static void ADD_ARMOUR_TO_PED(Ped ped, int amount) { invoke<Void>(0x89355F5A211BA286, ped, amount); } // 0x89355F5A211BA286 0xF686B26E
	static void SET_PED_ARMOUR(Ped ped, int amount) { invoke<Void>(0x06B74CD245641716, ped, amount); } // 0x06B74CD245641716 0x4E3A0CC4
	static void SET_PED_INTO_VEHICLE(Ped ped, Vehicle vehicle, int seatIndex) { invoke<Void>(0xFCB4AA590A0D6A59, ped, vehicle, seatIndex); } // 0xFCB4AA590A0D6A59 0x07500C79
	static void SET_PED_ALLOW_VEHICLES_OVERRIDE(Ped ped, BOOL toggle) { invoke<Void>(0xF1BDE718E5E4709F, ped, toggle); } // 0xF1BDE718E5E4709F 0x58A80BD5
	static BOOL CAN_CREATE_RANDOM_PED(BOOL unk) { return invoke<BOOL>(0x3FD9034277246451, unk); } // 0x3FD9034277246451 0xF9ABE88F
	static Ped CREATE_RANDOM_PED(float posX, float posY, float posZ) { return invoke<Ped>(0x01688CC3144E8710, posX, posY, posZ); } // 0x01688CC3144E8710 0x5A949543
	static Ped CREATE_RANDOM_PED_AS_DRIVER(Vehicle vehicle, BOOL returnHandle) { return invoke<Ped>(0x1F31203F4E478E9D, vehicle, returnHandle); } // 0x1F31203F4E478E9D 0xB927CE9A
	static BOOL CAN_CREATE_RANDOM_DRIVER() { return invoke<BOOL>(0xB4BE8FC646019C61); } // 0xB4BE8FC646019C61 0x99861609
	static BOOL CAN_CREATE_RANDOM_BIKE_RIDER() { return invoke<BOOL>(0x18EF36DA59C7300B); } // 0x18EF36DA59C7300B 0x7018BE31
	static void SET_PED_MOVE_ANIMS_BLEND_OUT(Ped ped) { invoke<Void>(0xA8064BAC66AE3E4E, ped); } // 0xA8064BAC66AE3E4E 0x20E01957
	static void SET_PED_CAN_BE_DRAGGED_OUT(Ped ped, BOOL toggle) { invoke<Void>(0x5A1E5F0E805EF8B8, ped, toggle); } // 0x5A1E5F0E805EF8B8 0xAA7F1131
	static void _0x3AD2EF10AB0CD8FC(BOOL toggle) { invoke<Void>(0x3AD2EF10AB0CD8FC, toggle); } // 0x3AD2EF10AB0CD8FC 0x6CD58238
	static BOOL IS_PED_MALE(Ped ped) { return invoke<BOOL>(0x81E2E02C57D459E6, ped); } // 0x81E2E02C57D459E6 0x90950455
	static BOOL IS_PED_HUMAN(Ped ped) { return invoke<BOOL>(0xAD3EB04F6E75AFD2, ped); } // 0xAD3EB04F6E75AFD2 0x194BB7B0
	static Vehicle GET_VEHICLE_PED_IS_IN(Ped ped, BOOL getLastVehicle) { return invoke<Vehicle>(0x60604E51E30D25B8, ped, getLastVehicle); } // 0x60604E51E30D25B8 0xAFE92319
	static void RESET_PED_LAST_VEHICLE(Ped ped) { invoke<Void>(0xE31C711433681463, ped); } // 0xE31C711433681463 0x5E3B5942
	static void SET_PED_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier) { invoke<Void>(0x4547FC28D02AD087, multiplier); } // 0x4547FC28D02AD087 0x039C82BB
	static void SET_SCENARIO_PED_DENSITY_MULTIPLIER_THIS_FRAME(float p0, float p1) { invoke<Void>(0x6CCF43768046B678, p0, p1); } // 0x6CCF43768046B678 0x2909ABF0
	static void _0xD2E94BC7581F4CDB() { invoke<Void>(0xD2E94BC7581F4CDB); } // 0xD2E94BC7581F4CDB 0xB48C0C04
	static void SET_SCRIPTED_CONVERSION_COORD_THIS_FRAME(float x, float y, float z) { invoke<Void>(0x4241ADB294679760, x, y, z); } // 0x4241ADB294679760 0x25EA2AA5
	static void SET_PED_NON_CREATION_AREA(float x1, float y1, float z1, float x2, float y2, float z2) { invoke<Void>(0xB57996B091C5D677, x1, y1, z1, x2, y2, z2); } // 0xB57996B091C5D677 0x7A97283F
	static void CLEAR_PED_NON_CREATION_AREA() { invoke<Void>(0xB61819CCF7A3F445); } // 0xB61819CCF7A3F445 0x6F7043A3
	static void _0x6E530062194EEB59() { invoke<Void>(0x6E530062194EEB59); } // 0x6E530062194EEB59 0x8C555ADD
	static BOOL IS_PED_ON_MOUNT(Ped ped) { return invoke<BOOL>(0xB761218A37B51027, ped); } // 0xB761218A37B51027 0x43103006
	static Ped GET_MOUNT(Ped ped) { return invoke<Ped>(0x720D1699053B8902, ped); } // 0x720D1699053B8902 0xDD31EC4E
	static BOOL IS_PED_ON_VEHICLE(Ped ped) { return invoke<BOOL>(0x284A003388A8DDB2, ped); } // 0x284A003388A8DDB2 0xA1AE7CC7
	static BOOL IS_PED_ON_SPECIFIC_VEHICLE(Ped ped, Vehicle vehicle) { return invoke<BOOL>(0x8D6447F7685A7D77, ped, vehicle); } // 0x8D6447F7685A7D77 0x63CB4603
	static void SET_PED_MONEY(Ped ped, int amount) { invoke<Void>(0x4DF0B516187EED5A, ped, amount); } // 0x4DF0B516187EED5A 0x40D90BF2
	static int GET_PED_MONEY(Ped ped) { return invoke<int>(0xF53EE9CF8055130D, ped); } // 0xF53EE9CF8055130D 0xEB3C4C7E
	static void _0xD42AE5185AAFAA03(float p0, Any p1) { invoke<Void>(0xD42AE5185AAFAA03, p0, p1); } // 0xD42AE5185AAFAA03 0xD41C9AED
	static void _0xC7B810BEEA02EC2E(BOOL p0) { invoke<Void>(0xC7B810BEEA02EC2E, p0); } // 0xC7B810BEEA02EC2E 0x30B98369
	static void _0x5C4D25D25371C589(BOOL p0) { invoke<Void>(0x5C4D25D25371C589, p0); } // 0x5C4D25D25371C589 0x02A080C8
	static void SET_PED_SUFFERS_CRITICAL_HITS(Ped ped, BOOL toggle) { invoke<Void>(0x9AA7339B5138B5EF, ped, toggle); } // 0x9AA7339B5138B5EF 0x6F6FC7E6
	static void _0x611AE5E57A690A9F(Ped ped, BOOL toggle) { invoke<Void>(0x611AE5E57A690A9F, ped, toggle); } // 0x611AE5E57A690A9F 0x1572022A
	static BOOL IS_PED_SITTING_IN_VEHICLE(Ped ped, Vehicle vehicle) { return invoke<BOOL>(0x7B816C72877502C5, ped, vehicle); } // 0x7B816C72877502C5 0xDDDE26FA
	static BOOL IS_PED_SITTING_IN_ANY_VEHICLE(Ped ped) { return invoke<BOOL>(0xD035C652F0986F10, ped); } // 0xD035C652F0986F10 0x0EA9CA03
	static BOOL IS_PED_ON_FOOT(Ped ped) { return invoke<BOOL>(0x9EFEA3B33DE2B966, ped); } // 0x9EFEA3B33DE2B966 0xC60D0785
	static BOOL IS_PED_ON_ANY_BIKE(Ped ped) { return invoke<BOOL>(0x3B22E4CC0F88E52E, ped); } // 0x3B22E4CC0F88E52E 0x4D885B2E
	static BOOL IS_PED_PLANTING_BOMB(Ped ped) { return invoke<BOOL>(0x95E290AF7BCBF364, ped); } // 0x95E290AF7BCBF364 0x0EDAC574
	static Vector3 GET_DEAD_PED_PICKUP_COORDS(Ped ped, float p1, float p2) { return invoke<Vector3>(0x795835F85C52F363, ped, p1, p2); } // 0x795835F85C52F363 0x129F9DC1
	static BOOL IS_PED_IN_ANY_BOAT(Ped ped) { return invoke<BOOL>(0x72FC030E928A5207, ped); } // 0x72FC030E928A5207 0x1118A947
	static BOOL IS_PED_IN_ANY_SUB(Ped ped) { return invoke<BOOL>(0xC5DC3C111D329A7C, ped); } // 0xC5DC3C111D329A7C 0xE65F8059
	static BOOL IS_PED_IN_ANY_HELI(Ped ped) { return invoke<BOOL>(0x8EC3C2BC25ED8ECA, ped); } // 0x8EC3C2BC25ED8ECA 0x7AB5523B
	static BOOL IS_PED_IN_ANY_PLANE(Ped ped) { return invoke<BOOL>(0xE40FC0529CC75B0F, ped); } // 0xE40FC0529CC75B0F 0x51BBCE7E
	static BOOL IS_PED_IN_FLYING_VEHICLE(Ped ped) { return invoke<BOOL>(0xE1EB864800193FC8, ped); } // 0xE1EB864800193FC8 0xCA072485
	static void SET_PED_DIES_IN_WATER(Ped ped, BOOL toggle) { invoke<Void>(0x2BFFCC859E7DDFFF, ped, toggle); } // 0x2BFFCC859E7DDFFF 0x604C872B
	static void SET_PED_DIES_IN_SINKING_VEHICLE(Ped ped, BOOL toggle) { invoke<Void>(0x2F944797D47913A7, ped, toggle); } // 0x2F944797D47913A7 0x8D4D9ABB
	static int GET_PED_ARMOUR(Ped ped) { return invoke<int>(0x55C72967EFB9CECF, ped); } // 0x55C72967EFB9CECF 0x2CE311A7
	static void SET_PED_STAY_IN_VEHICLE_WHEN_JACKED(Ped ped, BOOL toggle) { invoke<Void>(0x7CA9312EDAAC4056, ped, toggle); } // 0x7CA9312EDAAC4056 0xB014A09C
	static void SET_PED_CAN_BE_SHOT_IN_VEHICLE(Ped ped, BOOL toggle) { invoke<Void>(0x2732F3B9AFC5F703, ped, toggle); } // 0x2732F3B9AFC5F703 0x5DB7B3A9
	static BOOL GET_PED_LAST_DAMAGE_BONE(Ped ped, int* outBone) { return invoke<BOOL>(0xBCAFF9F764C4479E, ped, outBone); } // 0xBCAFF9F764C4479E 0xAB933841
	static void CLEAR_PED_LAST_DAMAGE_BONE(Ped ped) { invoke<Void>(0xC0C56F3B3B52658A, ped); } // 0xC0C56F3B3B52658A 0x56CB715E
	static void SET_AI_WEAPON_DAMAGE_MODIFIER(float value) { invoke<Void>(0x7AE49440B6EF92DE, value); } // 0x7AE49440B6EF92DE 0x516E30EE
	static void RESET_AI_WEAPON_DAMAGE_MODIFIER() { invoke<Void>(0xCFBE072F24B5F5D1); } // 0xCFBE072F24B5F5D1 0x6E965420
	static void SET_AI_MELEE_WEAPON_DAMAGE_MODIFIER(float modifier) { invoke<Void>(0x8D9FCB2ECC6AB94A, modifier); } // 0x8D9FCB2ECC6AB94A 0x0F9A401F
	static void RESET_AI_MELEE_WEAPON_DAMAGE_MODIFIER() { invoke<Void>(0xA91B6E75CD868D7F); } // 0xA91B6E75CD868D7F 0x97886238
	static void _0xC0F3230231C7F8CA(Any p0, BOOL p1) { invoke<Void>(0xC0F3230231C7F8CA, p0, p1); } // 0xC0F3230231C7F8CA 0xCC9D7F1A
	static void SET_PED_CAN_BE_TARGETTED(Ped ped, BOOL toggle) { invoke<Void>(0x6F65279C9BC14EDB, ped, toggle); } // 0x6F65279C9BC14EDB 0x75C49F74
	static void SET_PED_CAN_BE_TARGETTED_BY_TEAM(Ped ped, int team, BOOL toggle) { invoke<Void>(0x6FB5E2A2F932A260, ped, team, toggle); } // 0x6FB5E2A2F932A260 0xB103A8E1
	static void SET_PED_CAN_BE_TARGETTED_BY_PLAYER(Ped ped, Player player, BOOL toggle) { invoke<Void>(0x80011E0B47592D8A, ped, player, toggle); } // 0x80011E0B47592D8A 0xD050F490
	static void _0x5F96190265F66F44(Any p0, BOOL p1) { invoke<Void>(0x5F96190265F66F44, p0, p1); } // 0x5F96190265F66F44 0x7DA12905
	static void SET_TIME_EXCLUSIVE_DISPLAY_TEXTURE(Any p0, BOOL p1) { invoke<Void>(0xEBFBB303E9D8F361, p0, p1); } // 0xEBFBB303E9D8F361 0x7F67671D
	static BOOL IS_PED_IN_ANY_POLICE_VEHICLE(Ped ped) { return invoke<BOOL>(0x38128B88AC8D7C33, ped); } // 0x38128B88AC8D7C33 0x84FA790D
	static void FORCE_PED_TO_OPEN_PARACHUTE(Ped ped) { invoke<Void>(0x62FFFDA3B39F6DA8, ped); } // 0x62FFFDA3B39F6DA8 0xA819680B
	static BOOL IS_PED_IN_PARACHUTE_FREE_FALL(Ped ped) { return invoke<BOOL>(0xC3B1F1C9A58948C2, ped); } // 0xC3B1F1C9A58948C2 0xCD71F11B
	static BOOL IS_PED_FALLING(Ped ped) { return invoke<BOOL>(0xA9969D6750AB48B7, ped); } // 0xA9969D6750AB48B7 0xABF77334
	static BOOL IS_PED_JUMPING(Ped ped) { return invoke<BOOL>(0x39027D725EF551EA, ped); } // 0x39027D725EF551EA 0x07E5BC0E
	static BOOL IS_PED_CLIMBING(Ped ped) { return invoke<BOOL>(0xDBB75EFBFFEDB00D, ped); } // 0xDBB75EFBFFEDB00D 0xBCE03D35
	static BOOL IS_PED_VAULTING(Ped ped) { return invoke<BOOL>(0x85F3B64B2021DA27, ped); } // 0x85F3B64B2021DA27 0xC3169BDA
	static BOOL IS_PED_DIVING(Ped ped) { return invoke<BOOL>(0x7DD74A441504EFD8, ped); } // 0x7DD74A441504EFD8 0x7BC5BF3C
	static BOOL IS_PED_JUMPING_OUT_OF_VEHICLE(Ped ped) { return invoke<BOOL>(0x53E28743D432E98F, ped); } // 0x53E28743D432E98F 0xB19215F6
	static BOOL _0x0353A9BCF5968155(Ped ped) { return invoke<BOOL>(0x0353A9BCF5968155, ped); } // 0x0353A9BCF5968155
	static int GET_PED_PARACHUTE_STATE(Ped ped) { return invoke<int>(0xD4337557D3DEFC11, ped); } // 0xD4337557D3DEFC11 0x7D4BC475
	static int GET_PED_PARACHUTE_LANDING_TYPE(Ped ped) { return invoke<int>(0xBCA1A84F8B429B95, ped); } // 0xBCA1A84F8B429B95 0x01F3B035
	static void SET_PED_PARACHUTE_TINT_INDEX(Ped ped, Any tintIndex) { invoke<Void>(0xE8D7389DB94A1091, ped, tintIndex); } // 0xE8D7389DB94A1091 0x5AEFEC3A
	static void GET_PED_PARACHUTE_TINT_INDEX(Ped ped, Any* outTintIndex) { invoke<Void>(0x902ECBE66CD2605F, ped, outTintIndex); } // 0x902ECBE66CD2605F 0xE9E7FAC5
	static void SET_PED_RESERVE_PARACHUTE_TINT_INDEX(Any p0, Any p1) { invoke<Void>(0x2634BB4AB5E59FC3, p0, p1); } // 0x2634BB4AB5E59FC3 0x177EFC79
	static Entity _0x337A8DE1D5BFE775(Ped ped, BOOL p1, BOOL p2) { return invoke<Entity>(0x337A8DE1D5BFE775, ped, p1, p2); } // 0x337A8DE1D5BFE775
	static void SET_PED_DUCKING(Ped ped, BOOL toggle) { invoke<Void>(0xE851CEA79471B7D0, ped, toggle); } // 0xE851CEA79471B7D0 0xB90353D7
	static BOOL IS_PED_DUCKING(Ped ped) { return invoke<BOOL>(0xAC74327A3E5299B6, ped); } // 0xAC74327A3E5299B6 0x9199C77D
	static BOOL IS_PED_IN_ANY_TAXI(Ped ped) { return invoke<BOOL>(0x9CE8181CB6710437, ped); } // 0x9CE8181CB6710437 0x16FD386C
	static void SET_PED_ID_RANGE(Ped ped, float value) { invoke<Void>(0x1247C00E9DC4EDDD, ped, value); } // 0x1247C00E9DC4EDDD 0xEF3B4ED9
	static void _0x94E4AB66D79E55A5(Ped ped, BOOL p1) { invoke<Void>(0x94E4AB66D79E55A5, ped, p1); } // 0x94E4AB66D79E55A5 0x9A2180FF
	static void _0x2AEA40ADD86CD53E(Any p0, float p1) { invoke<Void>(0x2AEA40ADD86CD53E, p0, p1); } // 0x2AEA40ADD86CD53E 0xF30658D2
	static void _0x9D2028D09B5F336E(Any p0) { invoke<Void>(0x9D2028D09B5F336E, p0); } // 0x9D2028D09B5F336E 0x43709044
	static void SET_PED_SEEING_RANGE(Ped ped, float value) { invoke<Void>(0x9593ABA7B045F264, ped, value); } // 0x9593ABA7B045F264 0x4BD72FE8
	static void SET_PED_HEARING_RANGE(Ped ped, float value) { invoke<Void>(0xB84298F7B203EA5A, ped, value); } // 0xB84298F7B203EA5A 0xB32087E0
	static void SET_PED_VISUAL_FIELD_MIN_ANGLE(Ped ped, float value) { invoke<Void>(0xBF3335C87BD4D491, ped, value); } // 0xBF3335C87BD4D491 0x72E2E18B
	static void SET_PED_VISUAL_FIELD_MAX_ANGLE(Ped ped, float value) { invoke<Void>(0x1C9759DCD0A0CAE4, ped, value); } // 0x1C9759DCD0A0CAE4 0x0CEA0F9A
	static void SET_PED_VISUAL_FIELD_MIN_ELEVATION_ANGLE(Ped ped, float angle) { invoke<Void>(0x6696DB24C775A190, ped, angle); } // 0x6696DB24C775A190 0x5CC2F1B8
	static void SET_PED_VISUAL_FIELD_MAX_ELEVATION_ANGLE(Ped ped, float angle) { invoke<Void>(0x306E435D414AF22C, ped, angle); } // 0x306E435D414AF22C 0x39D9102F
	static void SET_PED_VISUAL_FIELD_PERIPHERAL_RANGE(Ped ped, float range) { invoke<Void>(0xE5B08A5C0283C229, ped, range); } // 0xE5B08A5C0283C229 0xFDF2F7C2
	static void SET_PED_VISUAL_FIELD_CENTER_ANGLE(Ped ped, float angle) { invoke<Void>(0xCC2DA14A520CC195, ped, angle); } // 0xCC2DA14A520CC195 0xE57202A1
	static void SET_PED_STEALTH_MOVEMENT(Ped ped, BOOL p1, char* action) { invoke<Void>(0x4C1D7D2B3355D863, ped, p1, action); } // 0x4C1D7D2B3355D863 0x67E28E1D
	static BOOL GET_PED_STEALTH_MOVEMENT(Ped ped) { return invoke<BOOL>(0x4BF0D40F31431B8F, ped); } // 0x4BF0D40F31431B8F 0x40321B83
	static int CREATE_GROUP(int unused) { return invoke<int>(0x40E0AA73F3D2AB1F, unused); } // 0x40E0AA73F3D2AB1F 0x8DC0368D
	static void SET_PED_AS_GROUP_LEADER(Ped ped, int groupId) { invoke<Void>(0xCA32FBDF236790F6, ped, groupId); } // 0xCA32FBDF236790F6 0x7265BEA2
	static void SET_PED_AS_GROUP_MEMBER(Ped ped, int groupId) { invoke<Void>(0xD25D00F8613DE69F, ped, groupId); } // 0xD25D00F8613DE69F 0x0EE13F92
	static void SET_PED_CAN_TELEPORT_TO_GROUP_LEADER(Ped pedHandle, int groupHandle, BOOL toggle) { invoke<Void>(0xA31A95BC78694E79, pedHandle, groupHandle, toggle); } // 0xA31A95BC78694E79 0xD0D8BDBC
	static void REMOVE_GROUP(int groupId) { invoke<Void>(0xCD2E18E350309849, groupId); } // 0xCD2E18E350309849 0x48D72B88
	static void REMOVE_PED_FROM_GROUP(Ped ped) { invoke<Void>(0xFB2D342CDD441DD9, ped); } // 0xFB2D342CDD441DD9 0x82697713
	static BOOL IS_PED_GROUP_MEMBER(Ped ped, int groupId) { return invoke<BOOL>(0x143230304C45DBF3, ped, groupId); } // 0x143230304C45DBF3 0x876D5363
	static BOOL IS_PED_HANGING_ON_TO_VEHICLE(Ped ped) { return invoke<BOOL>(0x73D75E5206725CCD, ped); } // 0x73D75E5206725CCD 0x9678D4FF
	static void SET_GROUP_SEPARATION_RANGE(int groupHandle, float separationRange) { invoke<Void>(0x79530D3E0E0D8259, groupHandle, separationRange); } // 0x79530D3E0E0D8259 0x7B820CD5
	static void SET_PED_MIN_GROUND_TIME_FOR_STUNGUN(Ped ped, int ms) { invoke<Void>(0x9B899FF3AE9C1198, ped, ms); } // 0x9B899FF3AE9C1198 0x2F0D0973
	static BOOL IS_PED_PRONE(Ped ped) { return invoke<BOOL>(0xCA8CA260AD1BCD17, ped); } // 0xCA8CA260AD1BCD17 0x02C2A6C3
	static BOOL IS_PED_IN_COMBAT(Ped ped, Ped target) { return invoke<BOOL>(0x018477A7947BC4B4, ped, target); } // 0x018477A7947BC4B4 0xFE027CB5
	static BOOL CAN_PED_IN_COMBAT_SEE_TARGET(Ped ped, Ped target) { return invoke<BOOL>(0x3D27B054244F08CD, ped, target); } // 0x3D27B054244F08CD 0xCCD525E1
	static BOOL IS_PED_DOING_DRIVEBY(Ped ped) { return invoke<BOOL>(0x828DB08E3536867D, ped); } // 0x828DB08E3536867D 0xAC3CEB9C
	static BOOL IS_PED_JACKING(Ped ped) { return invoke<BOOL>(0x34D81E587C110E92, ped); } // 0x34D81E587C110E92 0x3B321816
	static BOOL IS_PED_BEING_JACKED(Ped ped) { return invoke<BOOL>(0x4FF557C7B233F003, ped); } // 0x4FF557C7B233F003 0xD45D605C
	static BOOL IS_PED_BEING_STUNNED(Ped ped, int p1) { return invoke<BOOL>(0xB965476E8F962C70, ped, p1); } // 0xB965476E8F962C70 0x0A66CE30
	static Ped GET_PEDS_JACKER(Ped ped) { return invoke<Ped>(0xFFE01300722A85E9, ped); } // 0xFFE01300722A85E9 0xDE1DBB59
	static Ped GET_JACK_TARGET(Ped ped) { return invoke<Ped>(0xB14331E50C01A61B, ped); } // 0xB14331E50C01A61B 0x1D196361
	static BOOL IS_PED_FLEEING(Ped ped) { return invoke<BOOL>(0x48368B3E430594FA, ped); } // 0x48368B3E430594FA 0x85D813C6
	static BOOL IS_PED_IN_COVER(Ped ped, BOOL p1) { return invoke<BOOL>(0x6A67A9A75CEBC97E, ped, p1); } // 0x6A67A9A75CEBC97E 0x972C5A8B
	static BOOL IS_PED_IN_COVER_FACING_LEFT(Ped ped) { return invoke<BOOL>(0x1E9EF30F88C30CD9, ped); } // 0x1E9EF30F88C30CD9 0xB89DBB80
	static BOOL _0xE84871E43E92F47F(Ped ped) { return invoke<BOOL>(0xE84871E43E92F47F, ped); } // 0xE84871E43E92F47F
	static BOOL IS_PED_GOING_INTO_COVER(Ped ped) { return invoke<BOOL>(0xBE211E3B0F783C51, ped); } // 0xBE211E3B0F783C51 0xA3589628
	static Any SET_PED_PINNED_DOWN(Ped ped, BOOL pinned, int i) { return invoke<Any>(0x03FA1F9A025D90D8, ped, pinned, i); } // 0x03FA1F9A025D90D8 0xCC78999D
	static int GET_SEAT_PED_IS_TRYING_TO_ENTER(Ped ped) { return invoke<int>(0x8B35FEE244B42770, ped); } // 0x8B35FEE244B42770 0xACF162E0
	static Vehicle GET_VEHICLE_PED_IS_TRYING_TO_ENTER(Ped ped) { return invoke<Vehicle>(0xD25C1B2A4414A0B2, ped); } // 0xD25C1B2A4414A0B2 0x99968B37
	static Entity GET_PED_SOURCE_OF_DEATH(Ped ped) { return invoke<Entity>(0x94EC6331FEE44512, ped); } // 0x94EC6331FEE44512 0x84ADF9EB
	static Hash GET_PED_CAUSE_OF_DEATH(Ped ped) { return invoke<Hash>(0x5767F696A1303440, ped); } // 0x5767F696A1303440 0x63458C27
	static int _GET_PED_TIME_OF_DEATH(Ped ped) { return invoke<int>(0xE7FF5651AC89C3D5, ped); } // 0xE7FF5651AC89C3D5
	static int _0x25C61DB1A6681EC6(Any p0) { return invoke<int>(0x25C61DB1A6681EC6, p0); } // 0x25C61DB1A6681EC6 0xEF0B78E6
	static Any _0x4FAD0D54A61A57B3(Any p0, float p1, float p2, float p3, float p4) { return invoke<Any>(0x4FAD0D54A61A57B3, p0, p1, p2, p3, p4); } // 0x4FAD0D54A61A57B3 0xFB18CB19
	static void SET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(Ped ped, Hash hash) { invoke<Void>(0x09184E650331F23B, ped, hash); } // 0x09184E650331F23B 0x423B7BA2
	static void SET_PED_RELATIONSHIP_GROUP_HASH(Ped ped, Hash hash) { invoke<Void>(0x3BB70315907D9456, ped, hash); } // 0x3BB70315907D9456 0x79F8C18C
	static void SET_RELATIONSHIP_BETWEEN_GROUPS(int relationship, Hash group1, Hash group2) { invoke<Void>(0xDE574EA7A7A2CAF8, relationship, group1, group2); } // 0xDE574EA7A7A2CAF8 0xD4A215BA
	static void CLEAR_RELATIONSHIP_BETWEEN_GROUPS(int relationship, Hash group1, Hash group2) { invoke<Void>(0x3DAB418001EEA955, relationship, group1, group2); } // 0x3DAB418001EEA955 0x994B8C2D
	static Any ADD_RELATIONSHIP_GROUP(char* name, Hash* groupHash) { return invoke<Any>(0x1EF7A8224AE81790, name, groupHash); } // 0x1EF7A8224AE81790 0x8B635546
	static void REMOVE_RELATIONSHIP_GROUP(Hash groupHash) { invoke<Void>(0x111E99E32A85B908, groupHash); } // 0x111E99E32A85B908 0x4A1DC59A
	static int GET_RELATIONSHIP_BETWEEN_PEDS(Ped ped1, Ped ped2) { return invoke<int>(0x29E276F2F5E8AEF0, ped1, ped2); } // 0x29E276F2F5E8AEF0 0xE254C39C
	static Hash GET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(Ped ped) { return invoke<Hash>(0x648647DDD71905E9, ped); } // 0x648647DDD71905E9 0x714BD6E4
	static Hash GET_PED_RELATIONSHIP_GROUP_HASH(Ped ped) { return invoke<Hash>(0x7B619B0C33282280, ped); } // 0x7B619B0C33282280 0x354F283C
	static int GET_RELATIONSHIP_BETWEEN_GROUPS(Hash group1, Hash group2) { return invoke<int>(0x380FD986263724B3, group1, group2); } // 0x380FD986263724B3 0x4E372FE2
	static void SET_PED_CAN_BE_TARGETED_WITHOUT_LOS(Ped ped, BOOL toggle) { invoke<Void>(0x22396E0EC628249D, ped, toggle); } // 0x22396E0EC628249D 0x7FDDC0A6
	static void SET_PED_TO_INFORM_RESPECTED_FRIENDS(Ped ped, float radius, int maxFriends) { invoke<Void>(0x8DFE8FABD0A1066E, ped, radius, maxFriends); } // 0x8DFE8FABD0A1066E 0xD78AC46C
	static BOOL IS_PED_RESPONDING_TO_EVENT(Any p0, Any p1) { return invoke<BOOL>(0xE82C1D96F3EA52AF, p0, p1); } // 0xE82C1D96F3EA52AF 0x7A877554
	static void SET_PED_FIRING_PATTERN(Ped ped, Hash patternHash) { invoke<Void>(0x9CE039D54B14B412, ped, patternHash); } // 0x9CE039D54B14B412 0xB4629D66
	static void SET_PED_SHOOT_RATE(Ped ped, int shootRate) { invoke<Void>(0x5B36DF5C54D0170F, ped, shootRate); } // 0x5B36DF5C54D0170F 0xFB301746
	static void SET_COMBAT_FLOAT(Ped ped, int combatType, float p2) { invoke<Void>(0x601DD91B5FAE848C, ped, combatType, p2); } // 0x601DD91B5FAE848C 0xD8B7637C
	static float GET_COMBAT_FLOAT(Ped ped, int p1) { return invoke<float>(0xF3180893D81F3FCC, ped, p1); } // 0xF3180893D81F3FCC 0x511D7EF8
	static void GET_GROUP_SIZE(int groupID, Any* unknown, int* sizeInMembers) { invoke<Void>(0x74379B98CE025846, groupID, unknown, sizeInMembers); } // 0x74379B98CE025846 0xF7E1A691
	static BOOL DOES_GROUP_EXIST(int groupId) { return invoke<BOOL>(0xA383F5B15F4F8356, groupId); } // 0xA383F5B15F4F8356 0x935C978D
	static int GET_PED_GROUP_INDEX(Ped ped) { return invoke<int>(0xBC4F82F0863D3F60, ped); } // 0xBC4F82F0863D3F60 0x134E0785
	static BOOL IS_PED_IN_GROUP(Ped ped) { return invoke<BOOL>(0xF30AB065E07D2B0F, ped); } // 0xF30AB065E07D2B0F 0x836D9795
	static Player GET_PLAYER_PED_IS_FOLLOWING(Ped Ped) { return invoke<Player>(0x51B63388722101BD, Ped); } // 0x51B63388722101BD 0xDE7442EE
	static void SET_GROUP_FORMATION(int groupId, int formationType) { invoke<Void>(0xD80C7E92F2CAB25C, groupId, formationType); } // 0xD80C7E92F2CAB25C 0x08FAC739
	static void SET_GROUP_FORMATION_SPACING(int groupId, float p1, float p2, float p3) { invoke<Void>(0x59B89354BBE1A4E7, groupId, p1, p2, p3); } // 0x59B89354BBE1A4E7 0xB1E086FF
	static void RESET_GROUP_FORMATION_DEFAULT_SPACING(int groupHandle) { invoke<Void>(0x13D2F378909496D9, groupHandle); } // 0x13D2F378909496D9 0x267FCEAD
	static Vehicle GET_VEHICLE_PED_IS_USING(Ped ped) { return invoke<Vehicle>(0xFD05A5AA90984873, ped); } // 0xFD05A5AA90984873 0x6DE3AADA
	static Vehicle SET_EXCLUSIVE_PHONE_RELATIONSHIPS(Ped pedToCheck) { return invoke<Vehicle>(0xF566689615D97192, pedToCheck); } // 0xF566689615D97192 0x56E0C163
	static void SET_PED_GRAVITY(Ped ped, BOOL toggle) { invoke<Void>(0xC591BE13F389CFA7, ped, toggle); } // 0xC591BE13F389CFA7 0x3CA16652
	static void APPLY_DAMAGE_TO_PED(Ped ped, int damageAmount, BOOL p2) { invoke<Void>(0x04B2722F51BC08A8, ped, damageAmount, p2); } // 0x04B2722F51BC08A8 0x4DC27FCF
	static Any _0xEC00323C546285D3(Ped ped, Any p1) { return invoke<Any>(0xEC00323C546285D3, ped, p1); } // 0xEC00323C546285D3
	static void SET_PED_ALLOWED_TO_DUCK(Ped ped, BOOL toggle) { invoke<Void>(0x229B37FF6E1D1510, ped, toggle); } // 0x229B37FF6E1D1510 0xC4D122F8
	static void SET_PED_NEVER_LEAVES_GROUP(Ped ped, BOOL toggle) { invoke<Void>(0xE4FFBEDDCAF2776A, ped, toggle); } // 0xE4FFBEDDCAF2776A 0x0E038813
	static int GET_PED_TYPE(Ped ped) { return invoke<int>(0x233FA4E882378E72, ped); } // 0x233FA4E882378E72 0xB1460D43
	static void SET_PED_AS_COP(Ped ped, BOOL toggle) { invoke<Void>(0x2B2A8BB6D756A886, ped, toggle); } // 0x2B2A8BB6D756A886 0x84E7DE9F
	static void SET_PED_MAX_HEALTH(Ped ped, int value) { invoke<Void>(0x0C4DC21C9C8111ED, ped, value); } // 0x0C4DC21C9C8111ED 0x5533F60B
	static int GET_PED_MAX_HEALTH(Ped ped) { return invoke<int>(0x5D709FE87FA3B4C5, ped); } // 0x5D709FE87FA3B4C5 0xA45B6C8D
	static void SET_PED_MAX_TIME_IN_WATER(Ped ped, float value) { invoke<Void>(0xA09E96F8EA5F37C4, ped, value); } // 0xA09E96F8EA5F37C4 0xFE0A106B
	static void SET_PED_MAX_TIME_UNDERWATER(Ped ped, float value) { invoke<Void>(0x86534A8EC2C9DA71, ped, value); } // 0x86534A8EC2C9DA71 0x082EF240
	static void _0x93B7D88E58BECAC8(Ped ped, float p1) { invoke<Void>(0x93B7D88E58BECAC8, ped, p1); } // 0x93B7D88E58BECAC8 0x373CC405
	static void _0x4742A30F60B37BB3(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x4742A30F60B37BB3, p0, p1, p2, p3); } // 0x4742A30F60B37BB3
	static void _0x9F8EECE853488ACA(Any p0) { invoke<Void>(0x9F8EECE853488ACA, p0); } // 0x9F8EECE853488ACA
	static void SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(Ped ped, int state) { invoke<Void>(0x290EF12D0174E093, ped, state); } // 0x290EF12D0174E093 0x8A251612
	static BOOL CAN_KNOCK_PED_OFF_VEHICLE(Ped ped) { return invoke<BOOL>(0x1AF86F0EF24DC6D4, ped); } // 0x1AF86F0EF24DC6D4 0xC9D098B3
	static void KNOCK_PED_OFF_VEHICLE(Ped ped) { invoke<Void>(0xE0D1605D3819AA27, ped); } // 0xE0D1605D3819AA27 0xACDD0674
	static void SET_PED_COORDS_NO_GANG(Ped ped, float posX, float posY, float posZ) { invoke<Void>(0xEC36A83EF3DFC773, ped, posX, posY, posZ); } // 0xEC36A83EF3DFC773 0x9561AD98
	static Ped GET_PED_AS_GROUP_MEMBER(int groupID, int memberNumber) { return invoke<Ped>(0x61BD476A11E12D19, groupID, memberNumber); } // 0x61BD476A11E12D19 0x9AA3CC8C
	static Ped _GET_PED_AS_GROUP_LEADER(int groupID) { return invoke<Ped>(0xBDE83BBAF844977E, groupID); } // 0xBDE83BBAF844977E
	static void SET_PED_KEEP_TASK(Ped ped, BOOL toggle) { invoke<Void>(0x650BB0E111420EAF, ped, toggle); } // 0x650BB0E111420EAF 0xA7EC79CE
	static void _0xD4ECEB990D2F6EC6(Ped ped, BOOL p1) { invoke<Void>(0xD4ECEB990D2F6EC6, ped, p1); } // 0xD4ECEB990D2F6EC6 0x397F06E3
	static BOOL IS_PED_SWIMMING(Ped ped) { return invoke<BOOL>(0x5FD7D852A3EAF133, ped); } // 0x5FD7D852A3EAF133 0x7AB43DB8
	static BOOL IS_PED_SWIMMING_UNDER_WATER(Ped ped) { return invoke<BOOL>(0x3AD4FC6271B0E925, ped); } // 0x3AD4FC6271B0E925 0x0E8D524F
	static void SET_PED_COORDS_KEEP_VEHICLE(Ped ped, float posX, float posY, float posZ) { invoke<Void>(0x76E52B58E2C506DA, ped, posX, posY, posZ); } // 0x76E52B58E2C506DA 0xD66AE1D3
	static void SET_PED_DIES_IN_VEHICLE(Ped ped, BOOL toggle) { invoke<Void>(0x0B1CE86F89F85FC7, ped, toggle); } // 0x0B1CE86F89F85FC7 0x6FE1E440
	static void SET_CREATE_RANDOM_COPS(BOOL toggle) { invoke<Void>(0x59D2C41577DCED43, toggle); } // 0x59D2C41577DCED43 0x23441648
	static void SET_CREATE_RANDOM_COPS_NOT_ON_SCENARIOS(BOOL toggle) { invoke<Void>(0x54ADB3BA4CBB9B86, toggle); } // 0x54ADB3BA4CBB9B86 0x82E548CC
	static void SET_CREATE_RANDOM_COPS_ON_SCENARIOS(BOOL toggle) { invoke<Void>(0xE0738ED4C4BF3B80, toggle); } // 0xE0738ED4C4BF3B80 0xEDC31475
	static BOOL CAN_CREATE_RANDOM_COPS() { return invoke<BOOL>(0x6F9A8E000994DC24); } // 0x6F9A8E000994DC24 0xAA73DAD9
	static void SET_PED_AS_ENEMY(Ped ped, BOOL toggle) { invoke<Void>(0xCCEA0D9BEB843226, ped, toggle); } // 0xCCEA0D9BEB843226 0xAE620A1B
	static void SET_PED_CAN_SMASH_GLASS(Ped ped, BOOL p1, BOOL p2) { invoke<Void>(0xE475E58A2A0CC3BE, ped, p1, p2); } // 0xE475E58A2A0CC3BE 0x149C60A8
	static BOOL IS_PED_IN_ANY_TRAIN(Ped ped) { return invoke<BOOL>(0xA66773CB22F42448, ped); } // 0xA66773CB22F42448 0x759EF63A
	static BOOL IS_PED_GETTING_INTO_A_VEHICLE(Ped ped) { return invoke<BOOL>(0x9172DCBCA2E183EC, ped); } // 0x9172DCBCA2E183EC 0x90E805AC
	static BOOL IS_PED_TRYING_TO_ENTER_A_LOCKED_VEHICLE(Ped ped) { return invoke<BOOL>(0xA0EA20B19599F3D4, ped); } // 0xA0EA20B19599F3D4 0x46828B4E
	static void SET_ENABLE_HANDCUFFS(Ped ped, BOOL toggle) { invoke<Void>(0x089C773055A0A998, ped, toggle); } // 0x089C773055A0A998 0xAC9BBA23
	static void SET_ENABLE_BOUND_ANKLES(Ped ped, BOOL toggle) { invoke<Void>(0x03CBC435425CBDB6, ped, toggle); } // 0x03CBC435425CBDB6 0x9208D689
	static void SET_ENABLE_SCUBA(Ped ped, BOOL toggle) { invoke<Void>(0xC61E497A67A12DAA, ped, toggle); } // 0xC61E497A67A12DAA 0x7BF61471
	static void SET_CAN_ATTACK_FRIENDLY(Ped ped, BOOL toggle, BOOL p2) { invoke<Void>(0x79EB923C56B28B5A, ped, toggle, p2); } // 0x79EB923C56B28B5A 0x47C60963
	static int GET_PED_ALERTNESS(Ped ped) { return invoke<int>(0x292906400A71F327, ped); } // 0x292906400A71F327 0xF83E4DAF
	static void SET_PED_ALERTNESS(Ped ped, int value) { invoke<Void>(0xE12EA5A110F070E9, ped, value); } // 0xE12EA5A110F070E9 0x2C32D9AE
	static void SET_PED_GET_OUT_UPSIDE_DOWN_VEHICLE(Ped ped, BOOL toggle) { invoke<Void>(0x5E36942B3AE4C67F, ped, toggle); } // 0x5E36942B3AE4C67F 0x89AD49FF
	static void SET_PED_MOVEMENT_CLIPSET(Ped ped, char* clipSet, float p2) { invoke<Void>(0x64A85DB6D037D644, ped, clipSet, p2); } // 0x64A85DB6D037D644 0xA817CDEB
	static void RESET_PED_MOVEMENT_CLIPSET(Ped ped, float p1) { invoke<Void>(0xCFEAF108FE47852A, ped, p1); } // 0xCFEAF108FE47852A 0xB83CEE93
	static void SET_PED_STRAFE_CLIPSET(Ped ped, char* clipSet) { invoke<Void>(0x2F04D344EE0E0A31, ped, clipSet); } // 0x2F04D344EE0E0A31 0x0BACF010
	static void RESET_PED_STRAFE_CLIPSET(Ped ped) { invoke<Void>(0xD92A51DBA55B6784, ped); } // 0xD92A51DBA55B6784 0xF1967A12
	static void SET_PED_WEAPON_MOVEMENT_CLIPSET(Ped ped, char* clipSet) { invoke<Void>(0x4BF468C68449B4AB, ped, clipSet); } // 0x4BF468C68449B4AB 0xF8BE54DC
	static void RESET_PED_WEAPON_MOVEMENT_CLIPSET(Ped ped) { invoke<Void>(0x61B0D22DE2115B25, ped); } // 0x61B0D22DE2115B25 0xC60C9ACD
	static void SET_PED_DRIVE_BY_CLIPSET_OVERRIDE(Ped ped, char* clipset) { invoke<Void>(0x2987F96FC530AD32, ped, clipset); } // 0x2987F96FC530AD32 0xD4C73595
	static void CLEAR_PED_DRIVE_BY_CLIPSET_OVERRIDE(Ped ped) { invoke<Void>(0x12BD4808F35C1DE2, ped); } // 0x12BD4808F35C1DE2 0xAEC9163B
	static void _0x3932356BC526E105(Any p0, char* p1) { invoke<Void>(0x3932356BC526E105, p0, p1); } // 0x3932356BC526E105
	static void _0x5B1A084567D95BAC(Any p0) { invoke<Void>(0x5B1A084567D95BAC, p0); } // 0x5B1A084567D95BAC
	static void _0xAB62A5DD2881BB7E(Any p0) { invoke<Void>(0xAB62A5DD2881BB7E, p0); } // 0xAB62A5DD2881BB7E
	static void SET_PED_IN_VEHICLE_CONTEXT(Ped ped, Hash context) { invoke<Void>(0xB0EC96103205B498, ped, context); } // 0xB0EC96103205B498 0x27F25C0E
	static void RESET_PED_IN_VEHICLE_CONTEXT(Ped ped) { invoke<Void>(0x35EC81F39F03BDAC, ped); } // 0x35EC81F39F03BDAC 0x3C94D88A
	static BOOL IS_SCRIPTED_SCENARIO_PED_USING_CONDITIONAL_ANIM(Ped ped, char* animDict, char* anim) { return invoke<BOOL>(0x9D3A0D5430FED670, ped, animDict, anim); } // 0x9D3A0D5430FED670 0x3C30B447
	static void SET_PED_ALTERNATE_WALK_ANIM(Any p0, Any* p1, Any* p2, float p3, BOOL p4) { invoke<Void>(0xC175A4C4931183B4, p0, p1, p2, p3, p4); } // 0xC175A4C4931183B4 0x895E1D67
	static void CLEAR_PED_ALTERNATE_WALK_ANIM(Any p0, float p1) { invoke<Void>(0x751C57B99B6C0320, p0, p1); } // 0x751C57B99B6C0320 0x5736FB23
	static void SET_PED_ALTERNATE_MOVEMENT_ANIM(Ped ped, int stance, char* animDictionary, char* animationName, float p4, BOOL p5) { invoke<Void>(0x01DDEEADA68830EB, ped, stance, animDictionary, animationName, p4, p5); } // 0x01DDEEADA68830EB 0xBA84FD8C
	static void CLEAR_PED_ALTERNATE_MOVEMENT_ANIM(Ped ped, int stance, float p2) { invoke<Void>(0x2009870663964FB4, ped, stance, p2); } // 0x2009870663964FB4 0x7A7F5BC3
	static void SET_PED_GESTURE_GROUP(Ped ped, Any* p1) { invoke<Void>(0x7C5FEE9D3129B5CB, ped, p1); } // 0x7C5FEE9D3129B5CB 0x170DA109
	static Vector3 GET_ANIM_INITIAL_OFFSET_POSITION(char* animDict, char* animName, float x, float y, float z, float xRot, float yRot, float zRot, float p8, int p9) { return invoke<Vector3>(0xE31EC4AE3D955F3A, animDict, animName, x, y, z, xRot, yRot, zRot, p8, p9); } // 0xE31EC4AE3D955F3A 0xC59D4268
	static Vector3 GET_ANIM_INITIAL_OFFSET_ROTATION(char* animDict, char* animName, float x, float y, float z, float xRot, float yRot, float zRot, float p8, int p9) { return invoke<Vector3>(0x6D7B8A9E275D9A37, animDict, animName, x, y, z, xRot, yRot, zRot, p8, p9); } // 0x6D7B8A9E275D9A37 0x5F7789E6
	static int GET_PED_DRAWABLE_VARIATION(Ped ped, int componentId) { return invoke<int>(0xC72E4A160D2D5004, ped, componentId); } // 0xC72E4A160D2D5004 0x29850FE2
	static int GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(Ped ped, int componentId) { return invoke<int>(0xC351741D5A347BCE, ped, componentId); } // 0xC351741D5A347BCE 0x9754C27D
	static int GET_PED_TEXTURE_VARIATION(Ped ped, int componentId) { return invoke<int>(0x9E9290608A6EFB37, ped, componentId); } // 0x9E9290608A6EFB37 0xC0A8590A
	static int GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(Ped ped, int componentId, int drawableId) { return invoke<int>(0xD9BF60A9D14F12C8, ped, componentId, drawableId); } // 0xD9BF60A9D14F12C8 0x83D9FBE7
	static int GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(Ped ped, int propId) { return invoke<int>(0x092E56DBB01C4882, ped, propId); } // 0x092E56DBB01C4882 0xC9780B95
	static int GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(Ped ped, int propId, int drawableId) { return invoke<int>(0x1D948F0050408132, ped, propId, drawableId); } // 0x1D948F0050408132 0x4892B882
	static int GET_PED_PALETTE_VARIATION(Ped ped, int componentId) { return invoke<int>(0x15D0CB3C99F0F8B0, ped, componentId); } // 0x15D0CB3C99F0F8B0 0xEF1BC082
	static BOOL _0x0EA5B2E9788DE9F6(Any* p0, Any* p1) { return invoke<BOOL>(0x0EA5B2E9788DE9F6, p0, p1); } // 0x0EA5B2E9788DE9F6
	static Any _0x1EC7846EE87D4DF2(Any p0) { return invoke<Any>(0x1EC7846EE87D4DF2, p0); } // 0x1EC7846EE87D4DF2
	static Any _0xE8FEEF250EAC0115(Any p0) { return invoke<Any>(0xE8FEEF250EAC0115, p0); } // 0xE8FEEF250EAC0115
	static BOOL IS_PED_COMPONENT_VARIATION_VALID(Ped ped, int componentId, int drawableId, int textureId) { return invoke<BOOL>(0x5BD7095479D4BA28, ped, componentId, drawableId, textureId); } // 0x5BD7095479D4BA28 0x952ABD9A
	static void SET_PED_COMPONENT_VARIATION(Ped ped, int componentId, int drawableId, int textureId, int paletteId) { invoke<Void>(0x2F933BB106547968, ped, componentId, drawableId, textureId, paletteId); } // 0x2F933BB106547968 0xD4F7B05C
	static void SET_PED_RANDOM_COMPONENT_VARIATION(Ped ped, BOOL p1) { invoke<Void>(0x38FF4F54BBF14419, ped, p1); } // 0x38FF4F54BBF14419 0x4111BA46
	static void SET_PED_RANDOM_PROPS(Ped ped) { invoke<Void>(0x0BBA1AE2173B5B5C, ped); } // 0x0BBA1AE2173B5B5C 0xE3318E0E
	static void SET_PED_DEFAULT_COMPONENT_VARIATION(Ped ped) { invoke<Void>(0x7F73E2B58861632F, ped); } // 0x7F73E2B58861632F 0xC866A984
	static void SET_PED_BLEND_FROM_PARENTS(Ped ped, Any p1, Any p2, float p3, float p4) { invoke<Void>(0xBFF72100DF0FC7D2, ped, p1, p2, p3, p4); } // 0xBFF72100DF0FC7D2 0x837BD370
	static void SET_PED_HEAD_BLEND_DATA(Ped ped, int shapeFirstID, int shapeSecondID, int shapeThirdID, int skinFirstID, int skinSecondID, int skinThirdID, float shapeMix, float skinMix, float thirdMix, BOOL isParent) { invoke<Void>(0x21823138E415F2B4, ped, shapeFirstID, shapeSecondID, shapeThirdID, skinFirstID, skinSecondID, skinThirdID, shapeMix, skinMix, thirdMix, isParent); } // 0x21823138E415F2B4 0x60746B88
	static BOOL _GET_PED_HEAD_BLEND_DATA(Ped ped, Any* headBlendData) { return invoke<BOOL>(0xEE5C82ADA51A6503, ped, headBlendData); } // 0xEE5C82ADA51A6503
	static void UPDATE_PED_HEAD_BLEND_DATA(Ped ped, float shapeMix, float skinMix, float thirdMix) { invoke<Void>(0x3355FCBDBC1D0503, ped, shapeMix, skinMix, thirdMix); } // 0x3355FCBDBC1D0503 0x5CB76219
	static void _SET_PED_EYE_COLOR(Ped ped, int index) { invoke<Void>(0x2131972779E4DC47, ped, index); } // 0x2131972779E4DC47
	static void SET_PED_HEAD_OVERLAY(Ped ped, int overlayID, int index, float opacity) { invoke<Void>(0xE21D4E549BDF0595, ped, overlayID, index, opacity); } // 0xE21D4E549BDF0595 0xD28DBA90
	static int _GET_PED_HEAD_OVERLAY_VALUE(Ped ped, int overlayID) { return invoke<int>(0x96623EBAF88F0879, ped, overlayID); } // 0x96623EBAF88F0879
	static int _GET_NUM_HEAD_OVERLAY_VALUES(int overlayID) { return invoke<int>(0x88055B08DABC2C39, overlayID); } // 0x88055B08DABC2C39 0xFF43C18D
	static void _SET_PED_HEAD_OVERLAY_COLOR(Ped ped, int overlayID, int colorType, int colorID, int secondColorID) { invoke<Void>(0x2B240A614D3381DF, ped, overlayID, colorType, colorID, secondColorID); } // 0x2B240A614D3381DF
	static void _SET_PED_HAIR_COLOR(Ped ped, int colorID, int highlightColorID) { invoke<Void>(0x5F40E6D620C0D9DF, ped, colorID, highlightColorID); } // 0x5F40E6D620C0D9DF
	static int _GET_NUM_HAIR_COLORS() { return invoke<int>(0x5C98C5BA52768492); } // 0x5C98C5BA52768492
	static int _GET_NUM_MAKEUP_COLORS() { return invoke<int>(0x01B45684012990D8); } // 0x01B45684012990D8
	static void _0xF23330FD0D24EA25(Any p0, Any* p1, Any* p2, Any* p3) { invoke<Void>(0xF23330FD0D24EA25, p0, p1, p2, p3); } // 0xF23330FD0D24EA25
	static void _0x18BF7675463EFF6E(Any p0, Any* p1, Any* p2, Any* p3) { invoke<Void>(0x18BF7675463EFF6E, p0, p1, p2, p3); } // 0x18BF7675463EFF6E
	static BOOL _0x44B101277A46642C(Any p0) { return invoke<BOOL>(0x44B101277A46642C, p0); } // 0x44B101277A46642C
	static int _0x18B3624604A43678(Any p0) { return invoke<int>(0x18B3624604A43678, p0); } // 0x18B3624604A43678
	static BOOL _0xF357CD28CC5EFC18(Any p0) { return invoke<BOOL>(0xF357CD28CC5EFC18, p0); } // 0xF357CD28CC5EFC18
	static BOOL _0x0078E9AC714FD133(Any p0) { return invoke<BOOL>(0x0078E9AC714FD133, p0); } // 0x0078E9AC714FD133
	static BOOL _IS_A_VALID_HAIR_COLOR(int colorID) { return invoke<BOOL>(0x3606F68D9AB32FF3, colorID); } // 0x3606F68D9AB32FF3
	static Any _0xF37A5D3FDAF2330C(Any p0) { return invoke<Any>(0xF37A5D3FDAF2330C, p0); } // 0xF37A5D3FDAF2330C
	static BOOL _IS_A_VALID_LIPSTICK_COLOR(int colorID) { return invoke<BOOL>(0x6E6A8C804BBFEBC5, colorID); } // 0x6E6A8C804BBFEBC5
	static BOOL _IS_A_VALID_BLUSH_COLOR(int colorID) { return invoke<BOOL>(0xD2B8C2B779612AD3, colorID); } // 0xD2B8C2B779612AD3
	static Any _0xF571BE27790EBE2F(Any p0, Any p1, Any p2) { return invoke<Any>(0xF571BE27790EBE2F, p0, p1, p2); } // 0xF571BE27790EBE2F
	static void _SET_PED_FACE_FEATURE(Ped ped, int index, float scale) { invoke<Void>(0x50518135F3506D63, ped, index, scale); } // 0x50518135F3506D63
	static BOOL HAS_PED_HEAD_BLEND_FINISHED(Ped ped) { return invoke<BOOL>(0x7B7F1A6A713AFD3C, ped); } // 0x7B7F1A6A713AFD3C 0x2B1BD9C5
	static void _0x5D3680D916012130(Ped ped) { invoke<Void>(0x5D3680D916012130, ped); } // 0x5D3680D916012130 0x894314A4
	static void _0x0FBAC39D86E8FA60(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x0FBAC39D86E8FA60, p0, p1, p2, p3, p4); } // 0x0FBAC39D86E8FA60 0x57E5B3F9
	static void _0xA5764D5EB4F09023(Any p0) { invoke<Void>(0xA5764D5EB4F09023, p0); } // 0xA5764D5EB4F09023 0xC6F36292
	static int _GET_FIRST_PARENT_ID_FOR_PED_TYPE(int type) { return invoke<int>(0x1825E77465DE8AF5, type); } // 0x1825E77465DE8AF5 0x211DEFEC
	static int _GET_NUM_PARENT_PEDS_OF_TYPE(int type) { return invoke<int>(0x17D1BCB103DB6C41, type); } // 0x17D1BCB103DB6C41 0x095D3BD8
	static Any _0xE50A76982D0AC76B(Ped ped, int p1, int drawableId, int textureId) { return invoke<Any>(0xE50A76982D0AC76B, ped, p1, drawableId, textureId); } // 0xE50A76982D0AC76B 0x45F3BDFB
	static BOOL _0x7881BE6417F0114C(Ped p0) { return invoke<BOOL>(0x7881BE6417F0114C, p0); } // 0x7881BE6417F0114C 0xC6517D52
	static void _0xDA3FFBE8BB881944(Any p0) { invoke<Void>(0xDA3FFBE8BB881944, p0); } // 0xDA3FFBE8BB881944 0x6435F67F
	static BOOL _IS_PED_PROP_VALID(Ped ped, int componentId, int drawableId, int TextureId) { return invoke<BOOL>(0x19EFBCD702676D76, ped, componentId, drawableId, TextureId); } // 0x19EFBCD702676D76 0xC0E23671
	static BOOL _0x447674400D90C0C7(Ped ped) { return invoke<BOOL>(0x447674400D90C0C7, ped); } // 0x447674400D90C0C7 0x3B0CA391
	static void _0x46C5765307FAF1A5(Ped ped) { invoke<Void>(0x46C5765307FAF1A5, ped); } // 0x46C5765307FAF1A5 0xFD103BA7
	static int GET_PED_PROP_INDEX(Ped ped, int componentId) { return invoke<int>(0xB50239D338267F95, ped, componentId); } // 0xB50239D338267F95 0x746DDAC0
	static void SET_PED_PROP_INDEX(Ped ped, int componentId, int drawableId, int TextureId, BOOL attach) { invoke<Void>(0xCAA97B7826076AFA, ped, componentId, drawableId, TextureId, attach); } // 0xCAA97B7826076AFA 0x0829F2E2
	static void KNOCK_OFF_PED_PROP(Ped ped, BOOL p1, BOOL p2, BOOL p3, BOOL p4) { invoke<Void>(0x41CC9EF5A6CBC418, ped, p1, p2, p3, p4); } // 0x41CC9EF5A6CBC418 0x08D8B180
	static void CLEAR_PED_PROP(Ped ped, int propId) { invoke<Void>(0x53BF0F279B4289EA, ped, propId); } // 0x53BF0F279B4289EA 0x2D23D743
	static void CLEAR_ALL_PED_PROPS(Ped ped) { invoke<Void>(0x77DA108F7A79FB28, ped); } // 0x77DA108F7A79FB28 0x81DF8B43
	static void _0x64496588E1954554(Ped ped) { invoke<Void>(0x64496588E1954554, ped); } // 0x64496588E1954554
	static int GET_PED_PROP_TEXTURE_INDEX(Ped ped, int componentId) { return invoke<int>(0xBE372F0FD574ACB1, ped, componentId); } // 0xBE372F0FD574ACB1 0x922A6653
	static void _0xC1FE9C35F31A46D0(Any p0) { invoke<Void>(0xC1FE9C35F31A46D0, p0); } // 0xC1FE9C35F31A46D0 0x7BCD8991
	static void _0xC7DC6041C2A8A03C(Any p0) { invoke<Void>(0xC7DC6041C2A8A03C, p0); } // 0xC7DC6041C2A8A03C
	static void _0x4933F73D74B0CAA1(Any p0) { invoke<Void>(0x4933F73D74B0CAA1, p0); } // 0x4933F73D74B0CAA1 0x080275EE
	static BOOL _0x425980AE8FAA7A59(Any p0) { return invoke<BOOL>(0x425980AE8FAA7A59, p0); } // 0x425980AE8FAA7A59
	static void SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Ped ped, BOOL toggle) { invoke<Void>(0xCC61640A821F277C, ped, toggle); } // 0xCC61640A821F277C 0xDFE34E4A
	static void SET_PED_BOUNDS_ORIENTATION(Ped ped, float p1, float p2, float p3, float p4, float p5) { invoke<Void>(0x2059B43E91ACCFDA, ped, p1, p2, p3, p4, p5); } // 0x2059B43E91ACCFDA 0xCFA20D68
	static void REGISTER_TARGET(Ped ped, Ped target) { invoke<Void>(0xD566ED2019261F1D, ped, target); } // 0xD566ED2019261F1D 0x50A95442
	static void REGISTER_HATED_TARGETS_AROUND_PED(Ped ped, float radius) { invoke<Void>(0x133457C00E3354B0, ped, radius); } // 0x133457C00E3354B0 0x7F87559E
	static Ped GET_RANDOM_PED_AT_COORD(float x, float y, float z, float xRadius, float yRadius, float zRadius, int pedType) { return invoke<Ped>(0x2A205FF565510CFB, x, y, z, xRadius, yRadius, zRadius, pedType); } // 0x2A205FF565510CFB 0xDC8239EB
	static BOOL GET_CLOSEST_PED(float x, float y, float z, float radius, BOOL p4, BOOL p5, Ped* outPed, BOOL p7, BOOL p8, int pedType) { return invoke<BOOL>(0x4FBC81B313E0458D, x, y, z, radius, p4, p5, outPed, p7, p8, pedType); } // 0x4FBC81B313E0458D 0x8F6C1F55
	static void SET_SCENARIO_PEDS_TO_BE_RETURNED_BY_NEXT_COMMAND(BOOL value) { invoke<Void>(0xF5F9776B970526EC, value); } // 0xF5F9776B970526EC 0x85615FD0
	static BOOL _0x7009695F3C23104A(Ped ped, BOOL p1, BOOL p2, BOOL p3, BOOL p4, BOOL p5, BOOL p6, BOOL p7, Any p8) { return invoke<BOOL>(0x7009695F3C23104A, ped, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x7009695F3C23104A 0x18DD76A1
	static void _0xE18D8FB27FECC640(Ped driver, float p1) { invoke<Void>(0xE18D8FB27FECC640, driver, p1); } // 0xE18D8FB27FECC640 0x6D55B3B3
	static void SET_DRIVER_ABILITY(Ped driver, float ability) { invoke<Void>(0x217599C9B6509830, driver, ability); } // 0x217599C9B6509830 0xAAD4012C
	static void SET_DRIVER_AGGRESSIVENESS(Ped driver, float aggressiveness) { invoke<Void>(0xF10A666B8D8A8ACE, driver, aggressiveness); } // 0xF10A666B8D8A8ACE 0x8B02A8FB
	static BOOL CAN_PED_RAGDOLL(Ped ped) { return invoke<BOOL>(0xDD7D72B61A31ED6B, ped); } // 0xDD7D72B61A31ED6B 0xC0EFB7A3
	static BOOL SET_PED_TO_RAGDOLL(Ped ped, int time1, int time2, int ragdollType, BOOL p4, BOOL p5, BOOL p6) { return invoke<BOOL>(0xE9062A1E9EC059E7, ped, time1, time2, ragdollType, p4, p5, p6); } // 0xE9062A1E9EC059E7 0x83CB5052
	static BOOL SET_PED_TO_RAGDOLL_WITH_FALL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13) { return invoke<BOOL>(0x601E14D760DB6D5A, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); } // 0x601E14D760DB6D5A 0xFA12E286
	static void SET_PED_RAGDOLL_ON_COLLISION(Ped ped, BOOL toggle) { invoke<Void>(0xAC87B30145BDB6A0, ped, toggle); } // 0xAC87B30145BDB6A0 0x2654A0F4
	static BOOL IS_PED_RAGDOLL(Ped ped) { return invoke<BOOL>(0x7F4AE93855973529, ped); } // 0x7F4AE93855973529 0xC833BBE1
	static BOOL IS_PED_RUNNING_RAGDOLL_TASK(Ped ped) { return invoke<BOOL>(0x6AA6883001999D61, ped); } // 0x6AA6883001999D61 0x44A153F2
	static void SET_PED_RAGDOLL_FORCE_FALL(Ped ped) { invoke<Void>(0x4315AB5FE0B98113, ped); } // 0x4315AB5FE0B98113 0x20A5BDE0
	static void RESET_PED_RAGDOLL_TIMER(Ped ped) { invoke<Void>(0x6E2C609A2EDCB15D, ped); } // 0x6E2C609A2EDCB15D 0xF2865370
	static void SET_PED_CAN_RAGDOLL(Ped ped, BOOL toggle) { invoke<Void>(0x78F48B47DB1C3316, ped, toggle); } // 0x78F48B47DB1C3316 0xCF1384C4
	static BOOL _0x3EDD5C28EABCCF87(Ped ped) { return invoke<BOOL>(0x3EDD5C28EABCCF87, ped); } // 0x3EDD5C28EABCCF87
	static BOOL IS_PED_RUNNING_MOBILE_PHONE_TASK(Ped ped) { return invoke<BOOL>(0xF2AD8EF337DD09CD, ped); } // 0xF2AD8EF337DD09CD 0xFB2AFED1
	static BOOL _0x09AC47599199E644(Ped ped) { return invoke<BOOL>(0x09AC47599199E644, ped); } // 0x09AC47599199E644 0x97353375
	static void _SET_PED_RAGDOLL_FLAG(Ped ped, int flag) { invoke<Void>(0xBC2A4F3CEAB33199, ped, flag); } // 0xBC2A4F3CEAB33199 0x9C8F830D
	static void _SET_PED_RESET_RAGDOLL_FLAG(Ped ped, int flag) { invoke<Void>(0x104D9251F717880B, ped, flag); } // 0x104D9251F717880B 0x77CBA290
	static void SET_PED_ANGLED_DEFENSIVE_AREA(Ped ped, float p1, float p2, float p3, float p4, float p5, float p6, float p7, BOOL p8, BOOL p9) { invoke<Void>(0x7DFA2BDB740BB1B6, ped, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x7DFA2BDB740BB1B6 0x3EFBDD9B
	static void SET_PED_SPHERE_DEFENSIVE_AREA(Ped ped, float x, float y, float z, float radius, BOOL p5, BOOL p6) { invoke<Void>(0x6DE4D679A0565F8A, ped, x, y, z, radius, p5, p6); } // 0x6DE4D679A0565F8A 0xBD96D8E8
	static void SET_PED_DEFENSIVE_SPHERE_ATTACHED_TO_PED(Ped ped, Any p1, float p2, float p3, float p4, float p5, BOOL p6) { invoke<Void>(0x305A87F89FC63738, ped, p1, p2, p3, p4, p5, p6); } // 0x305A87F89FC63738 0x40638BDC
	static void _0xC392D787BDBE6F53(Ped ped, Any p1, float p2, float p3, float p4, float p5, BOOL p6) { invoke<Void>(0xC392D787BDBE6F53, ped, p1, p2, p3, p4, p5, p6); } // 0xC392D787BDBE6F53 0x4763B2C6
	static void SET_PED_DEFENSIVE_AREA_ATTACHED_TO_PED(Ped ped, Ped attachPed, float p2, float p3, float p4, float p5, float p6, float p7, float p8, BOOL p9, BOOL p10) { invoke<Void>(0x8778FE919703835F, ped, attachPed, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x8778FE919703835F 0x74BDA7CE
	static void SET_PED_DEFENSIVE_AREA_DIRECTION(Ped ped, float p1, float p2, float p3, BOOL p4) { invoke<Void>(0x210C0737FD499E54, ped, p1, p2, p3, p4); } // 0x210C0737FD499E54 0xB66B0C9A
	static void REMOVE_PED_DEFENSIVE_AREA(Ped ped, BOOL toggle) { invoke<Void>(0x844F37B6504C4747, ped, toggle); } // 0x844F37B6504C4747 0x34AAAFA5
	static Vector3 GET_PED_DEFENSIVE_AREA_POSITION(Ped ped, BOOL p1) { return invoke<Vector3>(0x7D36729F5BE924D8, ped, p1); } // 0x7D36729F5BE924D8 0xCB65198D
	static BOOL _0x781B4E03A59DB04A(Ped ped, BOOL p1) { return invoke<BOOL>(0x781B4E03A59DB04A, ped, p1); } // 0x781B4E03A59DB04A
	static void SET_PED_PREFERRED_COVER_SET(Ped ped, Any itemSet) { invoke<Void>(0xFF024202EEA2DE70, ped, itemSet); } // 0xFF024202EEA2DE70 0xF3B7EFBF
	static void REMOVE_PED_PREFERRED_COVER_SET(Ped ped) { invoke<Void>(0x8AB47CFF4C03ECBC, ped); } // 0x8AB47CFF4C03ECBC 0xA0134498
	static void REVIVE_INJURED_PED(Ped ped) { invoke<Void>(0x4817F003DF0A94CE, ped); } // 0x4817F003DF0A94CE 0x14D3E6E3
	static void RESURRECT_PED(Ped ped) { invoke<Void>(0x1209916B7D978EA1, ped); } // 0x1209916B7D978EA1 0xA4B82097
	static void SET_PED_NAME_DEBUG(Ped ped, char* name) { invoke<Void>(0x3BEB2E27EBD72589, ped, name); } // 0x3BEB2E27EBD72589 0x20D6273E
	static Vector3 GET_PED_EXTRACTED_DISPLACEMENT(Ped ped, BOOL worldSpace) { return invoke<Vector3>(0x17D38689F909C06E, ped, worldSpace); } // 0x17D38689F909C06E 0x5231F901
	static void SET_PED_DIES_WHEN_INJURED(Ped ped, BOOL toggle) { invoke<Void>(0x9DFD53125A4416A3, ped, toggle); } // 0x9DFD53125A4416A3 0xE94E24D4
	static void SET_PED_ENABLE_WEAPON_BLOCKING(Ped ped, BOOL toggle) { invoke<Void>(0xE1C7CF4692C294F3, ped, toggle); } // 0xE1C7CF4692C294F3 0x4CAD1A4A
	static void _0x5585E2BE317846CD(Ped ped, BOOL p1) { invoke<Void>(0x5585E2BE317846CD, ped, p1); } // 0x5585E2BE317846CD 0x141CC936
	static void RESET_PED_VISIBLE_DAMAGE(Ped ped) { invoke<Void>(0xDE659F99B7BE0F71, ped); } // 0xDE659F99B7BE0F71 0xC4BC4841
	static void APPLY_PED_BLOOD_DAMAGE_BY_ZONE(Ped ped, Any p1, float p2, float p3, Any p4) { invoke<Void>(0xB0F740A97E728966, ped, p1, p2, p3, p4); } // 0xB0F740A97E728966 0x1E54DB12
	static void APPLY_PED_BLOOD(Ped ped, int boneIndex, float xRot, float yRot, float zRot, char* woundType) { invoke<Void>(0x2A1AB18A10D93CD5, ped, boneIndex, xRot, yRot, zRot, woundType); } // 0x2A1AB18A10D93CD5 0x376CE3C0
	static void APPLY_PED_BLOOD_BY_ZONE(Ped ped, Any p1, float p2, float p3, Any* p4) { invoke<Void>(0x93D8B2235CEFAD90, ped, p1, p2, p3, p4); } // 0x93D8B2235CEFAD90 0x8F3F3A9C
	static void APPLY_PED_BLOOD_SPECIFIC(Ped ped, Any p1, float p2, float p3, float p4, float p5, Any p6, float p7, Any* p8) { invoke<Void>(0xF444169F4A47AD24, ped, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xF444169F4A47AD24 0xFC13CE80
	static void APPLY_PED_DAMAGE_DECAL(Ped ped, int p1, float p2, float p3, float p4, float p5, float p6, int p7, BOOL p8, char* p9) { invoke<Void>(0x938B27000590D583, ped, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x938B27000590D583 0x8A13A41F
	static void APPLY_PED_DAMAGE_PACK(Ped ped, char* damagePack, float damage, float mult) { invoke<Void>(0x85F7DD7836DF465E, ped, damagePack, damage, mult); } // 0x85F7DD7836DF465E 0x208D0CB8
	static void CLEAR_PED_BLOOD_DAMAGE(Ped ped) { invoke<Void>(0x266CE9B8FB237C77, ped); } // 0x266CE9B8FB237C77 0xF7ADC960
	static void CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(Ped ped, int p1) { invoke<Void>(0xAF624723A68AE843, ped, p1); } // 0xAF624723A68AE843 0xF210BE69
	static void HIDE_PED_BLOOD_DAMAGE_BY_ZONE(Ped ped, Any p1, BOOL p2) { invoke<Void>(0x1D8ED606E08FF028, ped, p1, p2); } // 0x1D8ED606E08FF028 0x0CB6C4ED
	static void CLEAR_PED_DAMAGE_DECAL_BY_ZONE(Ped ped, int p1, char* p2) { invoke<Void>(0x8962B4972C884718, ped, p1, p2); } // 0x8962B4972C884718 0x70AA5B7D
	static Any GET_PED_DECORATIONS_STATE(Ped ped) { return invoke<Any>(0x04C6FCD293F48DE5, ped); } // 0x04C6FCD293F48DE5 0x47187F7F
	static void _0x96702500652F8F8B(Ped ped, BOOL p1) { invoke<Void>(0x96702500652F8F8B, ped, p1); } // 0x96702500652F8F8B
	static void CLEAR_PED_WETNESS(Ped ped) { invoke<Void>(0x76956C8D11F030FD, ped); } // 0x76956C8D11F030FD 0x629F15BD
	static void SET_PED_WETNESS_HEIGHT(Ped ped, float height) { invoke<Void>(0x5D14BFEB360E8F4A, ped, height); } // 0x5D14BFEB360E8F4A 0x7B33289A
	static void SET_PED_WETNESS_ENABLED_THIS_FRAME(Ped ped) { invoke<Void>(0x42D159357CF12279, ped); } // 0x42D159357CF12279 0xBDE749F7
	static void _0x098E09028664B0BC(Ped ped) { invoke<Void>(0x098E09028664B0BC, ped); } // 0x098E09028664B0BC 0xA993915F
	static void SET_PED_SWEAT(Ped ped, float sweat) { invoke<Void>(0x7E80D8B826765647, ped, sweat); } // 0x7E80D8B826765647 0x76A1DB9F
	static void _SET_PED_DECORATION(Ped ped, Hash collection, Hash overlay) { invoke<Void>(0x3083789AF1A352BE, ped, collection, overlay); } // 0x3083789AF1A352BE 0x70559AC7
	static void _SET_PED_FACIAL_DECORATION(Ped ped, Hash collection, Hash overlay) { invoke<Void>(0xFCE540C604D3279B, ped, collection, overlay); } // 0xFCE540C604D3279B
	static int _GET_TATTOO_ZONE(Hash collection, Hash overlay) { return invoke<int>(0xF972851AD06E4330, collection, overlay); } // 0xF972851AD06E4330 0x3543019E
	static void CLEAR_PED_DECORATIONS(Ped ped) { invoke<Void>(0x0EC30B3C90166E64, ped); } // 0x0EC30B3C90166E64 0xD4496BF3
	static void _CLEAR_PED_FACIAL_DECORATIONS(Ped ped) { invoke<Void>(0x15B2FDE70362CCB8, ped); } // 0x15B2FDE70362CCB8 0xEFD58EB9
	static BOOL WAS_PED_SKELETON_UPDATED(Ped ped) { return invoke<BOOL>(0x9AEA5C4E8846FB40, ped); } // 0x9AEA5C4E8846FB40 0xF7E2FBAD
	static Vector3 GET_PED_BONE_COORDS(Ped ped, int boneId, float offsetX, float offsetY, float offsetZ) { return invoke<Vector3>(0x425DAA25CBB7EDE2, ped, boneId, offsetX, offsetY, offsetZ); } // 0x425DAA25CBB7EDE2 0x4579CAB1
	static void CREATE_NM_MESSAGE(BOOL startImmediately, int messageId) { invoke<Void>(0xCFEAB63EF8DBCD4F, startImmediately, messageId); } // 0xCFEAB63EF8DBCD4F 0x1CFBFD4B
	static void GIVE_PED_NM_MESSAGE(Ped ped) { invoke<Void>(0xE5CACF25DC3EA736, ped); } // 0xE5CACF25DC3EA736 0x737C3689
	static Any ADD_SCENARIO_BLOCKING_AREA(float p0, float p1, float p2, float p3, float p4, float p5, BOOL p6, BOOL p7, BOOL p8, BOOL p9) { return invoke<Any>(0xD1D19967E553E144, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xD1D19967E553E144 0xA38C0234
	static void REMOVE_SCENARIO_BLOCKING_AREAS() { invoke<Void>(0xCC76050C3A61CF48); } // 0xCC76050C3A61CF48 0x4DDF845F
	static void REMOVE_SCENARIO_BLOCKING_AREA(Any p0, BOOL p1) { invoke<Void>(0x571422CE42B47889, p0, p1); } // 0x571422CE42B47889 0x4483EF06
	static void SET_SCENARIO_PEDS_SPAWN_IN_SPHERE_AREA(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x4B82A95B04656802, p0, p1, p2, p3, p4); } // 0x4B82A95B04656802 0x80EAD297
	static BOOL IS_PED_USING_SCENARIO(Ped ped, char* scenario) { return invoke<BOOL>(0xA2E55F41F8746CEB, ped, scenario); } // 0xA2E55F41F8746CEB 0x0F65B0D4
	static BOOL IS_PED_USING_ANY_SCENARIO(Ped ped) { return invoke<BOOL>(0x0B1B005A46EF4C32, ped); } // 0x0B1B005A46EF4C32 0x195EF5B7
	static Any _0x43A5B92AFDE81292(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x43A5B92AFDE81292, p0, p1, p2, p3); } // 0x43A5B92AFDE81292 0x59DE73AC
	static void _0x35E5A58E1AF7CDE7(Any p0, BOOL p1) { invoke<Void>(0x35E5A58E1AF7CDE7, p0, p1); } // 0x35E5A58E1AF7CDE7 0xC08FE5F6
	static Any _0x76A4A2A04E5F11A7(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x76A4A2A04E5F11A7, p0, p1, p2, p3); } // 0x76A4A2A04E5F11A7 0x58C0F6CF
	static Any _0x1F1174C36C9DE30C(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x1F1174C36C9DE30C, p0, p1, p2, p3); } // 0x1F1174C36C9DE30C 0x761F8F48
	static void _0x7CEB7C943DD6C8EF(Any p0) { invoke<Void>(0x7CEB7C943DD6C8EF, p0); } // 0x7CEB7C943DD6C8EF 0x033F43FA
	static void _0xD4D420EA885FC154(Any p0) { invoke<Void>(0xD4D420EA885FC154, p0); } // 0xD4D420EA885FC154 0x4C684C81
	static Any _0xB816D6D03DB95012(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0xB816D6D03DB95012, p0, p1, p2, p3); } // 0xB816D6D03DB95012 0x7B4C3E6F
	static void _0x2CCE9DBC11976AB5(Ped ped, BOOL p1) { invoke<Void>(0x2CCE9DBC11976AB5, ped, p1); } // 0x2CCE9DBC11976AB5 0x5BC276AE
	static void _0xCCEFBEC38863B41D(Any p0, BOOL p1) { invoke<Void>(0xCCEFBEC38863B41D, p0, p1); } // 0xCCEFBEC38863B41D
	static void _0x6E3CF926D359D531(Any p0, BOOL p1) { invoke<Void>(0x6E3CF926D359D531, p0, p1); } // 0x6E3CF926D359D531
	static void PLAY_FACIAL_ANIM(Ped ped, char* animName, char* animDict) { invoke<Void>(0x08D44FD7F5CC1F86, ped, animName, animDict); } // 0x08D44FD7F5CC1F86 0x1F6CCDDE
	static void SET_FACIAL_IDLE_ANIM_OVERRIDE(Ped ped, char* animName, char* animDict) { invoke<Void>(0xF2F66822E1357C31, ped, animName, animDict); } // 0xF2F66822E1357C31 0x9BA19C13
	static void CLEAR_FACIAL_IDLE_ANIM_OVERRIDE(Ped ped) { invoke<Void>(0xE81FB651EA53A574, ped); } // 0xE81FB651EA53A574 0x5244F4E2
	static void SET_PED_CAN_PLAY_GESTURE_ANIMS(Ped ped, BOOL toggle) { invoke<Void>(0xCBDAC684E585E384, ped, toggle); } // 0xCBDAC684E585E384 0xE131E3B3
	static void SET_PED_CAN_PLAY_VISEME_ANIMS(Ped ped, BOOL p1, BOOL p2) { invoke<Void>(0x8103A9BD5A37D8FB, ped, p1, p2); } // 0x8103A9BD5A37D8FB 0xA2FDAF27
	static void _0xCDC7F8B1A84D80E6(Any p0, BOOL p1) { invoke<Void>(0xCDC7F8B1A84D80E6, p0, p1); } // 0xCDC7F8B1A84D80E6 0xADB2511A
	static void SET_PED_CAN_PLAY_AMBIENT_ANIMS(Ped ped, BOOL toggle) { invoke<Void>(0xFB616ABA635A95B3, ped, toggle); } // 0xFB616ABA635A95B3 0xF8053081
	static void SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS(Ped ped, BOOL toggle) { invoke<Void>(0xEABCB9D3B3CDC77E, ped, toggle); } // 0xEABCB9D3B3CDC77E 0x5720A5DD
	static void _0xF15D6935BFC61815(Ped ped) { invoke<Void>(0xF15D6935BFC61815, ped); } // 0xF15D6935BFC61815 0xB7CD0A49
	static void SET_PED_CAN_ARM_IK(Ped ped, BOOL toggle) { invoke<Void>(0xB458986B6214110A, ped, toggle); } // 0xB458986B6214110A 0x343B4DE0
	static void SET_PED_CAN_HEAD_IK(Ped ped, BOOL toggle) { invoke<Void>(0x5D9E175938ABA8BD, ped, toggle); } // 0x5D9E175938ABA8BD 0xD3B04476
	static void SET_PED_CAN_LEG_IK(Ped ped, BOOL toggle) { invoke<Void>(0xC82292F24EDEA9B5, ped, toggle); } // 0xC82292F24EDEA9B5 0x9955BC6F
	static void SET_PED_CAN_TORSO_IK(Ped ped, BOOL toggle) { invoke<Void>(0x606DF30CCCD0D407, ped, toggle); } // 0x606DF30CCCD0D407 0x8E5D4EAB
	static void _0x34ABFE93C705F65C(Any p0, BOOL p1) { invoke<Void>(0x34ABFE93C705F65C, p0, p1); } // 0x34ABFE93C705F65C 0x7B0040A8
	static void _0x24227AAF002F8E18(Any p0, BOOL p1) { invoke<Void>(0x24227AAF002F8E18, p0, p1); } // 0x24227AAF002F8E18 0x0FDA62DE
	static void SET_PED_CAN_USE_AUTO_CONVERSATION_LOOKAT(Ped ped, BOOL toggle) { invoke<Void>(0x8E601051A3FDE8ED, ped, toggle); } // 0x8E601051A3FDE8ED 0x584C5178
	static BOOL IS_PED_HEADTRACKING_PED(Ped ped1, Ped ped2) { return invoke<BOOL>(0x1D0EB673E1AE9A25, ped1, ped2); } // 0x1D0EB673E1AE9A25 0x2A5DF721
	static BOOL IS_PED_HEADTRACKING_ENTITY(Ped ped, Entity entity) { return invoke<BOOL>(0x3D6623406E6D16C8, ped, entity); } // 0x3D6623406E6D16C8 0x233C9ACF
	static void SET_PED_PRIMARY_LOOKAT(Ped ped, Ped lookAt) { invoke<Void>(0x1F5EA25E2EA3CD05, ped, lookAt); } // 0x1F5EA25E2EA3CD05 0x6DEF6F1C
	static void _0x828A3F86BE8AC724(Any p0, Any p1) { invoke<Void>(0x828A3F86BE8AC724, p0, p1); } // 0x828A3F86BE8AC724 0xFC942D7C
	static void _0xEB59775AE11B804A(Any p0, Any p1) { invoke<Void>(0xEB59775AE11B804A, p0, p1); } // 0xEB59775AE11B804A 0x89EEE07B
	static void _0xFAFA9FB1FA4609DF(Any p0, BOOL p1) { invoke<Void>(0xFAFA9FB1FA4609DF, p0, p1); } // 0xFAFA9FB1FA4609DF
	static void SET_PED_CONFIG_FLAG(Ped ped, int flagId, BOOL value) { invoke<Void>(0x6018E338F7ABCE75, ped, flagId, value); } // 0x6018E338F7ABCE75 0x9CFBE10D
	static void SET_PED_RESET_FLAG(Ped ped, int flagId, BOOL doReset) { invoke<Void>(0x0E21DA99F698AF06, ped, flagId, doReset); } // 0x0E21DA99F698AF06 0xCFF6FF66
	static BOOL GET_PED_CONFIG_FLAG(Ped ped, int flagId, BOOL p2) { return invoke<BOOL>(0x780A193B53AF21CF, ped, flagId, p2); } // 0x780A193B53AF21CF 0xABE98267
	static BOOL GET_PED_RESET_FLAG(Ped ped, int flagId) { return invoke<BOOL>(0xD293AF5C0E169D20, ped, flagId); } // 0xD293AF5C0E169D20 0x2FC10D11
	static void SET_PED_GROUP_MEMBER_PASSENGER_INDEX(Ped ped, int index) { invoke<Void>(0x346D6A5BC2F879E2, ped, index); } // 0x346D6A5BC2F879E2 0x2AB3670B
	static void SET_PED_CAN_EVASIVE_DIVE(Ped ped, BOOL toggle) { invoke<Void>(0x39C0001723FB41FF, ped, toggle); } // 0x39C0001723FB41FF 0x542FEB4D
	static BOOL IS_PED_EVASIVE_DIVING(Ped ped, Entity* evadingEntity) { return invoke<BOOL>(0x49916BC4637A9BFB, ped, evadingEntity); } // 0x49916BC4637A9BFB 0xD82829DC
	static void SET_PED_SHOOTS_AT_COORD(Ped ped, float x, float y, float z, BOOL toggle) { invoke<Void>(0xC3EA0842372A4F90, ped, x, y, z, toggle); } // 0xC3EA0842372A4F90 0xFD64EAE5
	static void SET_PED_MODEL_IS_SUPPRESSED(Ped ped, BOOL toggle) { invoke<Void>(0x16A327AF9E84ABA6, ped, toggle); } // 0x16A327AF9E84ABA6 0x7820CA43
	static void STOP_ANY_PED_MODEL_BEING_SUPPRESSED() { invoke<Void>(0xE1EC2239C8C9964C); } // 0xE1EC2239C8C9964C 0x5AD7DC55
	static void SET_PED_CAN_BE_TARGETED_WHEN_INJURED(Ped ped, BOOL toggle) { invoke<Void>(0xEF41D0768379FCB0, ped, toggle); } // 0xEF41D0768379FCB0 0x6FD9A7CD
	static void SET_PED_GENERATES_DEAD_BODY_EVENTS(Ped ped, BOOL toggle) { invoke<Void>(0xF948D65AD588A760, ped, toggle); } // 0xF948D65AD588A760 0xE9B97A2B
	static void _0x9B151A3A1CA38FD3(Ped ped, BOOL p1) { invoke<Void>(0x9B151A3A1CA38FD3, ped, p1); } // 0x9B151A3A1CA38FD3 0xFF1F6AEB
	static void SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(Ped ped, BOOL toggle) { invoke<Void>(0xB5E6A8B9C64444C4, ped, toggle); } // 0xB5E6A8B9C64444C4 0xE9BD733A
	static void GIVE_PED_HELMET(Ped ped, BOOL cannotRemove, int helmetFlag, int textureIndex) { invoke<Void>(0xD0CB3DBFBB095E91, ped, cannotRemove, helmetFlag, textureIndex); } // 0xD0CB3DBFBB095E91 0x1862A461
	static void REMOVE_PED_HELMET(Ped ped, BOOL instantly) { invoke<Void>(0x741356C018C53F6F, ped, instantly); } // 0x741356C018C53F6F 0x2086B1F0
	static BOOL _0xBB9E77D2069FCD64(Ped ped) { return invoke<BOOL>(0xBB9E77D2069FCD64, ped); } // 0xBB9E77D2069FCD64
	static void SET_PED_HELMET(Ped ped, BOOL canWearHelmet) { invoke<Void>(0x17E7D6CE3100F6AF, ped, canWearHelmet); } // 0x17E7D6CE3100F6AF 0xED366E53
	static void SET_PED_HELMET_FLAG(Ped ped, int helmetFlag) { invoke<Void>(0x6DE1F9EA99D62907, ped, helmetFlag); } // 0x6DE1F9EA99D62907 0x12677780
	static void SET_PED_HELMET_PROP_INDEX(Ped ped, int propIndex) { invoke<Void>(0xB2E3D8768AF03A5F, ped, propIndex); } // 0xB2E3D8768AF03A5F 0xA316D13F
	static void SET_PED_HELMET_TEXTURE_INDEX(Ped ped, int textureIndex) { invoke<Void>(0x0F8E1ED530A1A30E, ped, textureIndex); } // 0x0F8E1ED530A1A30E 0x5F6C3328
	static BOOL IS_PED_WEARING_HELMET(Ped ped) { return invoke<BOOL>(0x697A7F59AC98FE0F, ped); } // 0x697A7F59AC98FE0F 0x0D680D49
	static void _0x2CBA5DD30B4714EC(Any p0) { invoke<Void>(0x2CBA5DD30B4714EC, p0); } // 0x2CBA5DD30B4714EC 0x24A1284E
	static Any _0x5FC915A947F19410(Any p0) { return invoke<Any>(0x5FC915A947F19410, p0); } // 0x5FC915A947F19410 0x8A3A3116
	static Any _0x9015F42528E39793(Any p0) { return invoke<Any>(0x9015F42528E39793, p0); } // 0x9015F42528E39793 0x74EB662D
	static BOOL _0xFE7AB4DBD27BB8B9(Any p0) { return invoke<BOOL>(0xFE7AB4DBD27BB8B9, p0); } // 0xFE7AB4DBD27BB8B9 0xFFF149FE
	static void SET_PED_TO_LOAD_COVER(Ped ped, BOOL toggle) { invoke<Void>(0xAA70EB198C6F2985, ped, toggle); } // 0xAA70EB198C6F2985 0xCF94BA97
	static void SET_PED_CAN_COWER_IN_COVER(Ped ped, BOOL toggle) { invoke<Void>(0xF88082E80A889571, ped, toggle); } // 0xF88082E80A889571 0x5194658B
	static void SET_PED_CAN_PEEK_IN_COVER(Ped ped, BOOL toggle) { invoke<Void>(0xEDD058CD2D16A6DA, ped, toggle); } // 0xEDD058CD2D16A6DA 0xC1DAE216
	static void SET_PED_PLAYS_HEAD_ON_HORN_ANIM_WHEN_DIES_IN_VEHICLE(Ped ped, BOOL toggle) { invoke<Void>(0x5DB3F34649E95823, ped, toggle); } // 0x5DB3F34649E95823 0x7C563CD2
	static void SET_PED_LEG_IK_MODE(Ped ped, int mode) { invoke<Void>(0xFFADE963D2B7CD6E, ped, mode); } // 0xFFADE963D2B7CD6E 0xFDDB042E
	static void SET_PED_MOTION_BLUR(Ped ped, BOOL toggle) { invoke<Void>(0xE1E912F17D68C44E, ped, toggle); } // 0xE1E912F17D68C44E 0xA211A128
	static void SET_PED_CAN_SWITCH_WEAPON(Ped ped, BOOL toggle) { invoke<Void>(0x6F2C1CD778FB751C, ped, toggle); } // 0x6F2C1CD778FB751C 0xB5F8BA28
	static void SET_PED_DIES_INSTANTLY_IN_WATER(Ped ped, BOOL toggle) { invoke<Void>(0x4C7BBC06754E0F32, ped, toggle); } // 0x4C7BBC06754E0F32 0xFE2554FC
	static void _0x59193BCA0E026681(Ped ped, int p1) { invoke<Void>(0x59193BCA0E026681, ped, p1); } // 0x59193BCA0E026681 0x77BB7CB8
	static void STOP_PED_WEAPON_FIRING_WHEN_DROPPED(Ped ped) { invoke<Void>(0xF084FF26364E8DEF, ped); } // 0xF084FF26364E8DEF 0x4AC3421E
	static void SET_SCRIPTED_ANIM_SEAT_OFFSET(Ped ped, float p1) { invoke<Void>(0x85D39137BA9F08EF, ped, p1); } // 0x85D39137BA9F08EF 0x7CEFFA45
	static void SET_PED_COMBAT_MOVEMENT(Ped ped, int combatMovement) { invoke<Void>(0x2937901439E611F5, ped, combatMovement); } // 0x2937901439E611F5 0x12E62F9E
	static int GET_PED_COMBAT_MOVEMENT(Ped ped) { return invoke<int>(0x31BEFDA41FAE9539, ped); } // 0x31BEFDA41FAE9539 0xF3E7730E
	static void SET_PED_COMBAT_ABILITY(Ped ped, int p1) { invoke<Void>(0x8B54B100C5719325, ped, p1); } // 0x8B54B100C5719325 0x6C23D329
	static void SET_PED_COMBAT_RANGE(Ped ped, int p1) { invoke<Void>(0x73655D4147D2FFBC, ped, p1); } // 0x73655D4147D2FFBC 0x8818A959
	static Any GET_PED_COMBAT_RANGE(Ped ped) { return invoke<Any>(0x9E075AA1AD85EE29, ped); } // 0x9E075AA1AD85EE29 0x9B9B7163
	static void SET_PED_COMBAT_ATTRIBUTES(Ped ped, int attributeIndex, BOOL enabled) { invoke<Void>(0xC96275575DC981A9, ped, attributeIndex, enabled); } // 0xC96275575DC981A9 0x81D64248
	static void SET_PED_TARGET_LOSS_RESPONSE(Ped ped, int responseType) { invoke<Void>(0xE1F5F70A15CF94CB, ped, responseType); } // 0xE1F5F70A15CF94CB 0xCFA613FF
	static BOOL _0xF192008F4F403E15(Ped ped) { return invoke<BOOL>(0xF192008F4F403E15, ped); } // 0xF192008F4F403E15 0x139C0875
	static BOOL IS_PED_PERFORMING_STEALTH_KILL(Ped ped) { return invoke<BOOL>(0xDC7181F6D0A035D1, ped); } // 0xDC7181F6D0A035D1 0x9ADD7B21
	static BOOL _0x1A80AC5777F4BAF8(Ped ped) { return invoke<BOOL>(0x1A80AC5777F4BAF8, ped); } // 0x1A80AC5777F4BAF8 0x9BE7C860
	static BOOL IS_PED_BEING_STEALTH_KILLED(Ped ped) { return invoke<BOOL>(0x3AA552083DC1AF0A, ped); } // 0x3AA552083DC1AF0A 0xD044C8AF
	static Ped GET_MELEE_TARGET_FOR_PED(Ped ped) { return invoke<Ped>(0x355DBD6B7B42E4B8, ped); } // 0x355DBD6B7B42E4B8 0xAFEC26A4
	static BOOL WAS_PED_KILLED_BY_STEALTH(Ped ped) { return invoke<BOOL>(0x8E36A9305D573CF7, ped); } // 0x8E36A9305D573CF7 0x2EA4B54E
	static BOOL WAS_PED_KILLED_BY_TAKEDOWN(Ped ped) { return invoke<BOOL>(0x568D9AFEE65D27D1, ped); } // 0x568D9AFEE65D27D1 0xBDD3CE69
	static BOOL _0x900840E300A98517(Ped ped) { return invoke<BOOL>(0x900840E300A98517, ped); } // 0x900840E300A98517 0x3993092B
	static void SET_PED_FLEE_ATTRIBUTES(Ped ped, int attributes, BOOL p2) { invoke<Void>(0xB195EE9DB37DA7F2, ped, attributes, p2); } // 0xB195EE9DB37DA7F2 0xA717A875
	static void SET_PED_COWER_HASH(Ped ped, char* p1) { invoke<Void>(0x25E44A12DC982C36, ped, p1); } // 0x25E44A12DC982C36 0x16F30DF4
	static void _0xD1729B8347CE1334(Any p0, BOOL p1) { invoke<Void>(0xD1729B8347CE1334, p0, p1); } // 0xD1729B8347CE1334 0xA6F2C057
	static void SET_PED_STEERS_AROUND_PEDS(Ped ped, BOOL toggle) { invoke<Void>(0x7C5B84993AB60182, ped, toggle); } // 0x7C5B84993AB60182 0x797CAE4F
	static void SET_PED_STEERS_AROUND_OBJECTS(Ped ped, BOOL toggle) { invoke<Void>(0x031EAEB923DF860D, ped, toggle); } // 0x031EAEB923DF860D 0x3BD9B0A6
	static void SET_PED_STEERS_AROUND_VEHICLES(Ped ped, BOOL toggle) { invoke<Void>(0x3AA6603DF4BE24AA, ped, toggle); } // 0x3AA6603DF4BE24AA 0x533C0651
	static void _0x5EA4C83C0FAAC8B7(Any p0, BOOL p1) { invoke<Void>(0x5EA4C83C0FAAC8B7, p0, p1); } // 0x5EA4C83C0FAAC8B7 0x2276DE0D
	static void _0xAE44D026D0912190(Any p0) { invoke<Void>(0xAE44D026D0912190, p0); } // 0xAE44D026D0912190 0x59C52BE6
	static void _0x517BA203A5584DED(Any p0, BOOL p1) { invoke<Void>(0x517BA203A5584DED, p0, p1); } // 0x517BA203A5584DED 0x1D87DDC1
	static void _0x036B4266CD71AC9C(Any p0) { invoke<Void>(0x036B4266CD71AC9C, p0); } // 0x036B4266CD71AC9C 0xB52BA5F5
	static BOOL IS_ANY_PED_NEAR_POINT(float x, float y, float z, float radius) { return invoke<BOOL>(0x3FDEBC0190C73055, x, y, z, radius); } // 0x3FDEBC0190C73055 0xFBD9B050
	static void _0xDEAF24B058321A05(Ped ped, BOOL p1, BOOL p2) { invoke<Void>(0xDEAF24B058321A05, ped, p1, p2); } // 0xDEAF24B058321A05 0x187B9070
	static BOOL _0xCF2D3F2A51FA8FE5(Any p0, float p1, float p2, float p3, float p4) { return invoke<BOOL>(0xCF2D3F2A51FA8FE5, p0, p1, p2, p3, p4); } // 0xCF2D3F2A51FA8FE5 0x45037B9B
	static void _0xCC614957B282546F(Any p0) { invoke<Void>(0xCC614957B282546F, p0); } // 0xCC614957B282546F 0x840D24D3
	static void GET_PED_FLOOD_INVINCIBILITY(Ped ped, BOOL p1) { invoke<Void>(0x5A0679AC515DA45F, ped, p1); } // 0x5A0679AC515DA45F 0x31C31DAA
	static void _0x9230DA20475F9BF8(Any p0, BOOL p1) { invoke<Void>(0x9230DA20475F9BF8, p0, p1); } // 0x9230DA20475F9BF8
	static void _0x7981ADF661C7BBE7(Any p0, BOOL p1) { invoke<Void>(0x7981ADF661C7BBE7, p0, p1); } // 0x7981ADF661C7BBE7 0x9194DB71
	static BOOL IS_TRACKED_PED_VISIBLE(Ped ped) { return invoke<BOOL>(0x4B08F3A62DC9B336, ped); } // 0x4B08F3A62DC9B336 0x33248CC1
	static Any _0x9A710B67FD2E2938(Any p0) { return invoke<Any>(0x9A710B67FD2E2938, p0); } // 0x9A710B67FD2E2938 0x5B1B70AA
	static BOOL IS_PED_TRACKED(Ped ped) { return invoke<BOOL>(0x88C27597FAF93D9E, ped); } // 0x88C27597FAF93D9E 0x7EB613D9
	static BOOL HAS_PED_RECEIVED_EVENT(Any p0, Any p1) { return invoke<BOOL>(0x080A2F4FECE019B1, p0, p1); } // 0x080A2F4FECE019B1 0xECD73DB0
	static BOOL _0xC37168D3A492594E(Any p0, Any p1) { return invoke<BOOL>(0xC37168D3A492594E, p0, p1); } // 0xC37168D3A492594E 0x74A0F291
	static BOOL _0xD6E8A26ADB4D28A7(Ped p0, Any* p1) { return invoke<BOOL>(0xD6E8A26ADB4D28A7, p0, p1); } // 0xD6E8A26ADB4D28A7
	static int GET_PED_BONE_INDEX(Ped ped, int boneId) { return invoke<int>(0x0FC45085FB4E85B8, ped, boneId); } // 0x0FC45085FB4E85B8 0x259C6BA2
	static int GET_PED_RAGDOLL_BONE_INDEX(Ped ped, int bone) { return invoke<int>(0xEE602251AD2B63FF, ped, bone); } // 0xEE602251AD2B63FF 0x849F0716
	static void SET_PED_ENVEFF_SCALE(Ped ped, float value) { invoke<Void>(0xCC7272ECA53AC07A, ped, value); } // 0xCC7272ECA53AC07A 0xFC1CFC27
	static float GET_PED_ENVEFF_SCALE(Ped ped) { return invoke<float>(0x3632BDB7D59D4538, ped); } // 0x3632BDB7D59D4538 0xA3421E39
	static void SET_ENABLE_PED_ENVEFF_SCALE(Ped ped, BOOL toggle) { invoke<Void>(0x4FD3B2E6CC5939DA, ped, toggle); } // 0x4FD3B2E6CC5939DA 0xC70F4A84
	static void _0x612EBB2E38E5B5B4(Ped ped, float p1) { invoke<Void>(0x612EBB2E38E5B5B4, ped, p1); } // 0x612EBB2E38E5B5B4 0x3B882533
	static void _0x6126F41A214CE26E(Ped ped, int p1, int p2, int p3) { invoke<Void>(0x6126F41A214CE26E, ped, p1, p2, p3); } // 0x6126F41A214CE26E 0x87A0C174
	static void _0x0BE43C21F191F915(Any p0, Any p1) { invoke<Void>(0x0BE43C21F191F915, p0, p1); } // 0x0BE43C21F191F915 0x7BD26837
	static void _0xBAC64F3EF817441F(Any p0, BOOL p1) { invoke<Void>(0xBAC64F3EF817441F, p0, p1); } // 0xBAC64F3EF817441F 0x98E29ED0
	static BOOL _0x5411DE7E7DC44E0B(Ped ped) { return invoke<BOOL>(0x5411DE7E7DC44E0B, ped); } // 0x5411DE7E7DC44E0B
	static int CREATE_SYNCHRONIZED_SCENE(float x, float y, float z, float roll, float pitch, float yaw, int p6) { return invoke<int>(0x356EABB012B22D07, x, y, z, roll, pitch, yaw, p6); } // 0x356EABB012B22D07 0xFFDDF8FA
	static int _0x87C75BA8FC95A767(float x, float y, float z, float radius, Hash object) { return invoke<int>(0x87C75BA8FC95A767, x, y, z, radius, object); } // 0x87C75BA8FC95A767 0xF3876894
	static BOOL IS_SYNCHRONIZED_SCENE_RUNNING(int sceneId) { return invoke<BOOL>(0x00743AFDA92F3B04, sceneId); } // 0x00743AFDA92F3B04 0x57A282F1
	static void SET_SYNCHRONIZED_SCENE_ORIGIN(int sceneID, float x, float y, float z, float roll, float pitch, float yaw, BOOL p7) { invoke<Void>(0xC2A05D6865739BED, sceneID, x, y, z, roll, pitch, yaw, p7); } // 0xC2A05D6865739BED 0x2EC2A0B2
	static void SET_SYNCHRONIZED_SCENE_PHASE(int sceneID, float phase) { invoke<Void>(0xCE49D4A5BC766F78, sceneID, phase); } // 0xCE49D4A5BC766F78 0xF5AB0D98
	static float GET_SYNCHRONIZED_SCENE_PHASE(int sceneID) { return invoke<float>(0x96F65998C0685177, sceneID); } // 0x96F65998C0685177 0xB0B2C852
	static void SET_SYNCHRONIZED_SCENE_RATE(int sceneID, float rate) { invoke<Void>(0xB91CBE41BB2F8ED2, sceneID, rate); } // 0xB91CBE41BB2F8ED2 0xF10112FD
	static float GET_SYNCHRONIZED_SCENE_RATE(int sceneID) { return invoke<float>(0xF2C99944203E696F, sceneID); } // 0xF2C99944203E696F 0x89365F0D
	static void SET_SYNCHRONIZED_SCENE_LOOPED(int sceneID, BOOL toggle) { invoke<Void>(0x8B06F7FDDA8B98FB, sceneID, toggle); } // 0x8B06F7FDDA8B98FB 0x32ED9F82
	static BOOL IS_SYNCHRONIZED_SCENE_LOOPED(int sceneID) { return invoke<BOOL>(0x321F732F1070DF12, sceneID); } // 0x321F732F1070DF12 0x47D87A84
	static void _0xD3BB86584359B533(Any p0, BOOL p1) { invoke<Void>(0xD3BB86584359B533, p0, p1); } // 0xD3BB86584359B533 0x2DE48DA1
	static BOOL _0x13C94848B0911D58(Any p0) { return invoke<BOOL>(0x13C94848B0911D58, p0); } // 0x13C94848B0911D58 0x72CF2514
	static void ATTACH_SYNCHRONIZED_SCENE_TO_ENTITY(int sceneID, Entity entity, int boneIndex) { invoke<Void>(0xF0EF1D15A503772A, sceneID, entity, boneIndex); } // 0xF0EF1D15A503772A 0xE9BA6189
	static void DETACH_SYNCHRONIZED_SCENE(int sceneID) { invoke<Void>(0xEABBFB622128F3E7, sceneID); } // 0xEABBFB622128F3E7 0x52A1CAB2
	static void _DISPOSE_SYNCHRONIZED_SCENE(int scene) { invoke<Void>(0x94728DDB2DF4F7FF, scene); } // 0x94728DDB2DF4F7FF 0xBF7F9035
	static BOOL FORCE_PED_MOTION_STATE(Ped ped, Hash motionStateHash, BOOL p2, BOOL p3, BOOL p4) { return invoke<BOOL>(0x44B1CF13D39D96CE, ped, motionStateHash, p2, p3, p4); } // 0x44B1CF13D39D96CE 0x164DDEFF
	static BOOL _0x90F708FC7227DEA4(Ped ped, Any* p1, Any* p2) { return invoke<BOOL>(0x90F708FC7227DEA4, ped, p1, p2); } // 0x90F708FC7227DEA4
	static void SET_PED_MAX_MOVE_BLEND_RATIO(Ped ped, float value) { invoke<Void>(0x7B0D34D6C9709C7A, ped, value); } // 0x7B0D34D6C9709C7A 0xEAD0269A
	static void SET_PED_MIN_MOVE_BLEND_RATIO(Ped ped, float value) { invoke<Void>(0x316B8FE556E99FA1, ped, value); } // 0x316B8FE556E99FA1 0x383EC364
	static void SET_PED_MOVE_RATE_OVERRIDE(Ped ped, float value) { invoke<Void>(0x8F98DF9961F0D013, ped, value); } // 0x8F98DF9961F0D013 0x900008C6
	static BOOL _0x41F851B8E149462D(Ped ped, int flag) { return invoke<BOOL>(0x41F851B8E149462D, ped, flag); } // 0x41F851B8E149462D 0x79543043
	static int GET_PED_NEARBY_VEHICLES(Ped ped, int* sizeAndVehs) { return invoke<int>(0xCF84F5E773EE8DF3, ped, sizeAndVehs); } // 0xCF84F5E773EE8DF3 0xCB716F68
	static int GET_PED_NEARBY_PEDS(Ped ped, int* sizeAndPeds, int ignore) { return invoke<int>(0x537143BA63A7EEFE, ped, sizeAndPeds, ignore); } // 0x537143BA63A7EEFE 0x4D3325F4
	static BOOL _0x291EF658E660C270(Ped ped) { return invoke<BOOL>(0x291EF658E660C270, ped); } // 0x291EF658E660C270 0xF9FB4B71
	static BOOL IS_PED_USING_ACTION_MODE(Ped ped) { return invoke<BOOL>(0x0081A36ACB4392C0, ped); } // 0x0081A36ACB4392C0 0x5AE7EDA2
	static void SET_PED_USING_ACTION_MODE(Ped ped, BOOL p1, Any p2, char* action) { invoke<Void>(0xE2D8919DE58194D4, ped, p1, p2, action); } // 0xE2D8919DE58194D4 0x8802F696
	static void _0xDAAB8F12849596D0(Ped ped, char* p1) { invoke<Void>(0xDAAB8F12849596D0, ped, p1); } // 0xDAAB8F12849596D0
	static void SET_PED_CAPSULE(Ped ped, float value) { invoke<Void>(0x969CD82EB0FA1221, ped, value); } // 0x969CD82EB0FA1221 0xB153E1B9
	static Any REGISTER_PEDHEADSHOT(Ped ped) { return invoke<Any>(0xE131696D8A00BF1B, ped); } // 0xE131696D8A00BF1B 0xFFE2667B
	static Any _0xA18905D4069F3395(Any p0) { return invoke<Any>(0xA18905D4069F3395, p0); } // 0xA18905D4069F3395 0x4DD03628
	static void UNREGISTER_PEDHEADSHOT(Ped ped) { invoke<Void>(0x3DD64AC41265D51A, ped); } // 0x3DD64AC41265D51A 0x0879AE45
	static int IS_PEDHEADSHOT_VALID(int handle) { return invoke<int>(0x570F715345905581, handle); } // 0x570F715345905581 0x0B1080C4
	static BOOL IS_PEDHEADSHOT_READY(int handle) { return invoke<BOOL>(0x97CCE7AE66FA8CB9, handle); } // 0x97CCE7AE66FA8CB9 0x761CD02E
	static char* GET_PEDHEADSHOT_TXD_STRING(int handle) { return invoke<char*>(0x7F897CE1A139406E, handle); } // 0x7F897CE1A139406E 0x76D28E96
	static BOOL _0x72C31DFD90206CE5(Any p0) { return invoke<BOOL>(0x72C31DFD90206CE5, p0); } // 0x72C31DFD90206CE5 0x10F2C023
	static void _0xDED0F13B9A904CF0(Any p0) { invoke<Void>(0xDED0F13B9A904CF0, p0); } // 0xDED0F13B9A904CF0 0x0DBB2FA7
	static Any _0xD688BF5A960D9DA5() { return invoke<Any>(0xD688BF5A960D9DA5); } // 0xD688BF5A960D9DA5 0x810158F8
	static Any _0x32B6068DE4F6CD31() { return invoke<Any>(0x32B6068DE4F6CD31); } // 0x32B6068DE4F6CD31 0x05023F8F
	static Any _0x1C7A59A60290A907() { return invoke<Any>(0x1C7A59A60290A907); } // 0x1C7A59A60290A907 0xAA39FD6C
	static void _0xA64875B0FFDF1F28(Any p0, Any p1) { invoke<Void>(0xA64875B0FFDF1F28, p0, p1); } // 0xA64875B0FFDF1F28 0xEF9142DB
	static void _0xB164C7A08DE32125(Any p0) { invoke<Void>(0xB164C7A08DE32125, p0); } // 0xB164C7A08DE32125 0x0688DE64
	static void _0x3E246E05AB7A5831(float p0, float p1, float p2, float p3, float p4, int interiorFlags, float scale, int duration) { invoke<Void>(0x3E246E05AB7A5831, p0, p1, p2, p3, p4, interiorFlags, scale, duration); } // 0x3E246E05AB7A5831 0x909A1D76
	static void _0x4E6A0A2C891E0ECB(float x, float y, float z, float p3, float p4, float p5, float p6, int interiorFlags, float scale, int duration) { invoke<Void>(0x4E6A0A2C891E0ECB, x, y, z, p3, p4, p5, p6, interiorFlags, scale, duration); } // 0x4E6A0A2C891E0ECB 0x4AAD0ECB
	static void _0xBCEB75150E4BCF86() { invoke<Void>(0xBCEB75150E4BCF86); } // 0xBCEB75150E4BCF86 0x492C9E46
	static Any _0xE2C518FA28FDAE2D() { return invoke<Any>(0xE2C518FA28FDAE2D); } // 0xE2C518FA28FDAE2D 0x814A28F4
	static Any _0x32D4530B5165CC53() { return invoke<Any>(0x32D4530B5165CC53); } // 0x32D4530B5165CC53 0x0B60D2BA
	static Any _0x9F1C1332924286B5() { return invoke<Any>(0x9F1C1332924286B5); } // 0x9F1C1332924286B5 0x6B83ABDF
	static Any _0x7A0B126704E4302C() { return invoke<Any>(0x7A0B126704E4302C); } // 0x7A0B126704E4302C 0xF46B4DC8
	static void _0x6C30149E7BBB83AC(Any p0, Any* p1, Any* p2, Any* p3) { invoke<Void>(0x6C30149E7BBB83AC, p0, p1, p2, p3); } // 0x6C30149E7BBB83AC 0x36A4AC65
	static void _0x9CB3CC62C0C0C0A3(Any p0, Any* p1) { invoke<Void>(0x9CB3CC62C0C0C0A3, p0, p1); } // 0x9CB3CC62C0C0C0A3 0xBA699DDF
	static void SET_IK_TARGET(Ped ped, int p1, Ped targetPed, int boneLookAt, float x, float y, float z, Any p7, int duration, int duration1) { invoke<Void>(0x4367311EB9A8596E, ped, p1, targetPed, boneLookAt, x, y, z, p7, duration, duration1); } // 0x4367311EB9A8596E 0x6FE5218C
	static void _0x18E714E77C27E637(Any p0) { invoke<Void>(0x18E714E77C27E637, p0); } // 0x18E714E77C27E637 0xFB4000DC
	static void REQUEST_ACTION_MODE_ASSET(char* asset) { invoke<Void>(0x0C96CC7C147C102F, asset); } // 0x0C96CC7C147C102F 0x572BA553
	static BOOL HAS_ACTION_MODE_ASSET_LOADED(char* asset) { return invoke<BOOL>(0x801F6E592F430B74, asset); } // 0x801F6E592F430B74 0xF7EB2BF1
	static void REMOVE_ACTION_MODE_ASSET(char* asset) { invoke<Void>(0xDF852BE9403CACA0, asset); } // 0xDF852BE9403CACA0 0x3F480F92
	static void REQUEST_STEALTH_MODE_ASSET(char* asset) { invoke<Void>(0x6939C2E8E26C26CF, asset); } // 0x6939C2E8E26C26CF 0x280A004A
	static BOOL HAS_STEALTH_MODE_ASSET_LOADED(char* asset) { return invoke<BOOL>(0x155DD64120A0676C, asset); } // 0x155DD64120A0676C 0x39245667
	static void REMOVE_STEALTH_MODE_ASSET(char* asset) { invoke<Void>(0x67042DFCA810C753, asset); } // 0x67042DFCA810C753 0x8C0B243A
	static void SET_PED_LOD_MULTIPLIER(Ped ped, float multiplier) { invoke<Void>(0x587770043EE55BD7, ped, multiplier); } // 0x587770043EE55BD7 0x1D2B5C70
	static void _0xCC9424D3A84B806E(Any p0, BOOL p1, Any p2) { invoke<Void>(0xCC9424D3A84B806E, p0, p1, p2); } // 0xCC9424D3A84B806E 0x2F9550C2
	static void _0xEDCA12484954F971(Ped ped, BOOL toggle) { invoke<Void>(0xEDCA12484954F971, ped, toggle); } // 0xEDCA12484954F971 0x37DBC2AD
	static void _0xEA534745EC40E5C6(Any p0, BOOL p1, Any p2, Any p3) { invoke<Void>(0xEA534745EC40E5C6, p0, p1, p2, p3); } // 0xEA534745EC40E5C6 0xC0F1BC91
	static BOOL _0x1440A1A03AFAAE7C(Ped ped, float x, float y, float z, float range) { return invoke<BOOL>(0x1440A1A03AFAAE7C, ped, x, y, z, range); } // 0x1440A1A03AFAAE7C 0x1A464167
	static BOOL _0x8408433488578054(Any p0, Any p1, float p2, float p3, float p4, float p5) { return invoke<BOOL>(0x8408433488578054, p0, p1, p2, p3, p4, p5); } // 0x8408433488578054 0xD0567D41
	static void _0x104ECC8838962916(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x104ECC8838962916, p0, p1, p2, p3, p4); } // 0x104ECC8838962916 0x4BBE5E2C
	static void _0xFEB8E84A97CC9FD5(Ped ped) { invoke<Void>(0xFEB8E84A97CC9FD5, ped); } // 0xFEB8E84A97CC9FD5 0xA89A53F2
	static void _0xF5F7370FBCB01BD5(Any p0, Any p1) { invoke<Void>(0xF5F7370FBCB01BD5, p0, p1); } // 0xF5F7370FBCB01BD5
	static void _0xC3D5460F53F05D4E(Any p0, float p1) { invoke<Void>(0xC3D5460F53F05D4E, p0, p1); } // 0xC3D5460F53F05D4E
}

namespace VEHICLE
{
	static Vehicle CREATE_VEHICLE(Hash modelHash, float x, float y, float z, float heading, BOOL networkHandle, BOOL vehiclehandle) { return invoke<Vehicle>(0x692A2891A2BA7352, modelHash, x, y, z, heading, networkHandle, vehiclehandle); } // 0x692A2891A2BA7352 0xDD75460A
	static void DELETE_VEHICLE(Vehicle* vehicle) { invoke<Void>(0x813865264334331D, vehicle); } // 0x813865264334331D 0x9803AF60
	static void _0x96169B40F2E64880(Vehicle vehicle, BOOL p1, BOOL p2) { invoke<Void>(0x96169B40F2E64880, vehicle, p1, p2); } // 0x96169B40F2E64880 0xBB54ECCA
	static void SET_VEHICLE_ALLOW_NO_PASSENGERS_LOCKON(Vehicle veh, BOOL p1) { invoke<Void>(0x64A0B6624BBD5456, veh, p1); } // 0x64A0B6624BBD5456 0x8BAAC437
	static int _0xED0C9A79E0D03217(Vehicle vehicle) { return invoke<int>(0xED0C9A79E0D03217, vehicle); } // 0xED0C9A79E0D03217 0xFBDE9FD8
	static BOOL IS_VEHICLE_MODEL(Vehicle vehicle, Hash model) { return invoke<BOOL>(0x5AF6E4F22F4B49C3, vehicle, model); } // 0x5AF6E4F22F4B49C3 0x013B10B6
	static BOOL DOES_SCRIPT_VEHICLE_GENERATOR_EXIST(int vehicleGenerator) { return invoke<BOOL>(0xD9017D8DDA14260E, vehicleGenerator); } // 0xD9017D8DDA14260E 0xF6BDDA30
	static int CREATE_SCRIPT_VEHICLE_GENERATOR(float x, float y, float z, float heading, float p4, float p5, Hash modelHash, int p7, int p8, int p9, int p10, BOOL p11, BOOL p12, BOOL p13, BOOL p14, BOOL p15, int p16) { return invoke<int>(0xF0211489870AF60D, x, y, z, heading, p4, p5, modelHash, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16); } // 0xF0211489870AF60D 0x25A9A261
	static void DELETE_SCRIPT_VEHICLE_GENERATOR(int vehicleGenerator) { invoke<Void>(0x5B4A28F653775109, vehicleGenerator); } // 0x5B4A28F653775109 0xE4328E3F
	static void SET_SCRIPT_VEHICLE_GENERATOR(Any vehicleGenerator, BOOL enabled) { invoke<Void>(0xD9EBF236F479D3DA, vehicleGenerator, enabled); } // 0xD9EBF236F479D3DA 0x40D73747
	static void SET_ALL_VEHICLE_GENERATORS_ACTIVE_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2, BOOL p6, BOOL p7) { invoke<Void>(0xB82FD68B5DE68F01, x1, y1, z1, x2, y2, z2, p6, p7); } // 0xB82FD68B5DE68F01 0xB4E0E69A
	static void SET_ALL_VEHICLE_GENERATORS_ACTIVE() { invoke<Void>(0xF076395049E32F0C); } // 0xF076395049E32F0C 0xAB1FDD76
	static void SET_ALL_LOW_PRIORITY_VEHICLE_GENERATORS_ACTIVE(BOOL active) { invoke<Void>(0xE773F55CEC607580, active); } // 0xE773F55CEC607580 0x87F767F2
	static void _0xAE8A9E407CB8C117(float p0, float p1, float p2, float p3) { invoke<Void>(0xAE8A9E407CB8C117, p0, p1, p2, p3); } // 0xAE8A9E407CB8C117 0x935A95DA
	static void _0xEB4D9A8557E16CF5() { invoke<Void>(0xEB4D9A8557E16CF5); } // 0xEB4D9A8557E16CF5 0x6C73E45A
	static BOOL SET_VEHICLE_ON_GROUND_PROPERLY(Vehicle vehicle) { return invoke<BOOL>(0x482AE8C0EAF5AE07, vehicle); } // 0x482AE8C0EAF5AE07 0xE14FDBA6
	static Any SET_ALL_VEHICLES_SPAWN(Vehicle p0, BOOL p1, BOOL p2, BOOL p3) { return invoke<Any>(0xA3DB896EB465CBD2, p0, p1, p2, p3); } // 0xA3DB896EB465CBD2 0xA0909ADB
	static BOOL IS_VEHICLE_STUCK_ON_ROOF(Vehicle vehicle) { return invoke<BOOL>(0x745DF692265C6509, vehicle); } // 0x745DF692265C6509 0x18D07C6C
	static void ADD_VEHICLE_UPSIDEDOWN_CHECK(Vehicle vehicle) { invoke<Void>(0x26C9531CF391AB1D, vehicle); } // 0x26C9531CF391AB1D 0x3A13D384
	static void REMOVE_VEHICLE_UPSIDEDOWN_CHECK(Vehicle vehicle) { invoke<Void>(0xA57C55CEA3DF591D, vehicle); } // 0xA57C55CEA3DF591D 0xF390BA1B
	static BOOL IS_VEHICLE_STOPPED(Vehicle vehicle) { return invoke<BOOL>(0x71427D1CF2654C68, vehicle); } // 0x71427D1CF2654C68 0x655F072C
	static int GET_VEHICLE_NUMBER_OF_PASSENGERS(Vehicle vehicle) { return invoke<int>(0x47ACE3C196F6F5F9, vehicle); } // 0x47ACE3C196F6F5F9 0x1EF20849
	static int GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(Vehicle vehicle) { return invoke<int>(0x58060A1B26EA2597, vehicle); } // 0x58060A1B26EA2597 0x0A2FC08C
	static int GET_VEHICLE_MODEL_NUMBER_OF_SEATS(Hash modelHash) { return invoke<int>(0x74EBEFF57C45B722, modelHash); } // 0x74EBEFF57C45B722 0x838F7BF7
	static BOOL _0x4325876506543E89(Vehicle vehicle, BOOL flag) { return invoke<BOOL>(0x4325876506543E89, vehicle, flag); } // 0x4325876506543E89 0x769E5CF2
	static BOOL _0x8BA66DCE8BBE6FAE(Vehicle vehicle, Any p1) { return invoke<BOOL>(0x8BA66DCE8BBE6FAE, vehicle, p1); } // 0x8BA66DCE8BBE6FAE
	static void SET_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier) { invoke<Void>(0x5BD872FA7F0EC076, multiplier); } // 0x5BD872FA7F0EC076 0xF4187E51
	static void SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier) { invoke<Void>(0x7E46DE5F5C5D350D, multiplier); } // 0x7E46DE5F5C5D350D 0x543F712B
	static void SET_PARKED_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME(float multiplier) { invoke<Void>(0x41103299D4B9FEFE, multiplier); } // 0x41103299D4B9FEFE 0xDD46CEBE
	static void _0xAF4B965B30A1D727(BOOL toggle) { invoke<Void>(0xAF4B965B30A1D727, toggle); } // 0xAF4B965B30A1D727 0x09462665
	static void _0xED3C26C3DD248FA0(float value) { invoke<Void>(0xED3C26C3DD248FA0, value); } // 0xED3C26C3DD248FA0 0xDAE2A2BE
	static void SET_FAR_DRAW_VEHICLES(BOOL toggle) { invoke<Void>(0xAD852AF1A6999A09, toggle); } // 0xAD852AF1A6999A09 0x9F019C49
	static void SET_NUMBER_OF_PARKED_VEHICLES(int value) { invoke<Void>(0x8E2C1C02547F9CA6, value); } // 0x8E2C1C02547F9CA6 0x206A58E8
	static void SET_VEHICLE_DOORS_LOCKED(Vehicle vehicle, int doorLockStatus) { invoke<Void>(0xD602D152E57C823D, vehicle, doorLockStatus); } // 0xD602D152E57C823D 0x4CDD35D0
	static void SET_PED_TARGETTABLE_VEHICLE_DESTROY(Vehicle vehicle, int vehicleComponent, int destroyType) { invoke<Void>(0x630C6302A4301134, vehicle, vehicleComponent, destroyType); } // 0x630C6302A4301134 0xD61D182D
	static void DISABLE_VEHICLE_IMPACT_EXPLOSION_ACTIVATION(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xF99AC88D37F62A7B, vehicle, toggle); } // 0xF99AC88D37F62A7B 0xC54156A9
	static void SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER(Vehicle vehicle, Player player, BOOL toggle) { invoke<Void>(0xD4E8FB600263C993, vehicle, player, toggle); } // 0xD4E8FB600263C993 0x49829236
	static BOOL GET_VEHICLE_DOORS_LOCKED_FOR_PLAYER(Vehicle vehicle, Player player) { return invoke<BOOL>(0xC050CD96550EEFD5, vehicle, player); } // 0xC050CD96550EEFD5 0x1DC50247
	static void SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x1EADD742B8FDE19E, vehicle, toggle); } // 0x1EADD742B8FDE19E 0x891BA8A4
	static void _0x4E05E9FB1C72DFF5(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x4E05E9FB1C72DFF5, vehicle, toggle); } // 0x4E05E9FB1C72DFF5 0xE4EF6514
	static void SET_VEHICLE_DOORS_LOCKED_FOR_TEAM(Vehicle vehicle, int team, BOOL toggle) { invoke<Void>(0x961171FEDD8D00B7, vehicle, team, toggle); } // 0x961171FEDD8D00B7 0x4F85E783
	static void EXPLODE_VEHICLE(Vehicle vehicle, BOOL isAudible, BOOL isInvisible) { invoke<Void>(0x28EB63CAF526B891, vehicle, isAudible, isInvisible); } // 0x28EB63CAF526B891 0xBEDEACEB
	static void SET_VEHICLE_OUT_OF_CONTROL(Vehicle vehicle, BOOL killDriver, BOOL explodeOnImpact) { invoke<Void>(0x0D2BA17E5A6A8017, vehicle, killDriver, explodeOnImpact); } // 0x0D2BA17E5A6A8017 0x3764D734
	static void SET_VEHICLE_TIMED_EXPLOSION(Vehicle vehicle, Ped ped, BOOL toggle) { invoke<Void>(0x48AD51C04BFFFF20, vehicle, ped, toggle); } // 0x48AD51C04BFFFF20 0xDB8CB8E2
	static void _0x22EECAD86DE36524(Any p0) { invoke<Void>(0x22EECAD86DE36524, p0); } // 0x22EECAD86DE36524 0x811373DE
	static Any _0x561E4A8C5AF878DA() { return invoke<Any>(0x561E4A8C5AF878DA); } // 0x561E4A8C5AF878DA 0xA4E69134
	static void _0xF304587A7F542302() { invoke<Void>(0xF304587A7F542302); } // 0xF304587A7F542302 0x65255524
	static BOOL _0x35E8074814B2DFBB(Any p0) { return invoke<BOOL>(0x35E8074814B2DFBB, p0); } // 0x35E8074814B2DFBB 0xE39DAF36
	static void SET_TAXI_LIGHTS(Vehicle vehicle, BOOL state) { invoke<Void>(0x7B44E99A2EB5660F, vehicle, state); } // 0x7B44E99A2EB5660F 0x68639D85
	static BOOL IS_TAXI_LIGHT_ON(Vehicle vehicle) { return invoke<BOOL>(0xFFADBEDD2B2F7E76, vehicle); } // 0xFFADBEDD2B2F7E76 0x6FC4924A
	static BOOL IS_VEHICLE_IN_GARAGE_AREA(char* garageName, Vehicle vehicle) { return invoke<BOOL>(0xA3342DAAC0684FAC, garageName, vehicle); } // 0xA3342DAAC0684FAC 0xA90EC257
	static void SET_VEHICLE_COLOURS(Vehicle vehicle, int colorPrimary, int colorSecondary) { invoke<Void>(0x357EE036FE09513D, vehicle, colorPrimary, colorSecondary); } // 0x357EE036FE09513D 0x57F24253
	static void SET_VEHICLE_FULLBEAM(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x3AA07F1633F8D389, vehicle, toggle); } // 0x3AA07F1633F8D389 0x9C49CC15
	static void STEER_UNLOCK_BIAS(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xCF60FB647DED5EFE, vehicle, toggle); } // 0xCF60FB647DED5EFE 0xA59E3DCD
	static void SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle vehicle, int r, int g, int b) { invoke<Void>(0x9DD4A7AF83B5A817, vehicle, r, g, b); } // 0x9DD4A7AF83B5A817 0x8DF9F9BC
	static void GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle vehicle, int* r, int* g, int* b) { invoke<Void>(0xF1A2595FDE7845CA, vehicle, r, g, b); } // 0xF1A2595FDE7845CA 0x1C2B9FEF
	static void CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle vehicle) { invoke<Void>(0xCE1BE7835278AA2B, vehicle); } // 0xCE1BE7835278AA2B 0x51E1E33D
	static BOOL GET_IS_VEHICLE_PRIMARY_COLOUR_CUSTOM(Vehicle vehicle) { return invoke<BOOL>(0xD74AC52CAC4E709E, vehicle); } // 0xD74AC52CAC4E709E 0xD7EC8760
	static void SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle vehicle, int r, int g, int b) { invoke<Void>(0x2C6350FBF2D740F9, vehicle, r, g, b); } // 0x2C6350FBF2D740F9 0x9D77259E
	static void GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle vehicle, int* r, int* g, int* b) { invoke<Void>(0x44A79540466923A3, vehicle, r, g, b); } // 0x44A79540466923A3 0x3FF247A2
	static void CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle vehicle) { invoke<Void>(0xA53583755F423DE9, vehicle); } // 0xA53583755F423DE9 0x7CE00B29
	static BOOL GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM(Vehicle vehicle) { return invoke<BOOL>(0x9FC3D9B8F2BAF3E6, vehicle); } // 0x9FC3D9B8F2BAF3E6 0x288AD228
	static void _SET_VEHICLE_PAINT_FADE(Vehicle veh, float fade) { invoke<Void>(0x74E356CF63E0D10F, veh, fade); } // 0x74E356CF63E0D10F 0x8332730C
	static float _GET_VEHICLE_PAINT_FADE(Vehicle veh) { return invoke<float>(0x66CA20DD062BE2A0, veh); } // 0x66CA20DD062BE2A0 0xD5F1EEE1
	static void SET_CAN_RESPRAY_VEHICLE(Vehicle vehicle, BOOL state) { invoke<Void>(0x270513E8EE95EEA4, vehicle, state); } // 0x270513E8EE95EEA4 0x37677590
	static void _0x77D18977D299E159(Vehicle vehicle, BOOL p1) { invoke<Void>(0x77D18977D299E159, vehicle, p1); } // 0x77D18977D299E159 0x54E9EE75
	static void _JITTER_VEHICLE(Vehicle vehicle, BOOL p1, float yaw, float pitch, float roll) { invoke<Void>(0x74F9F498094617CB, vehicle, p1, yaw, pitch, roll); } // 0x74F9F498094617CB 0x4A46E814
	static void SET_BOAT_ANCHOR(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x83E56A7E8E3D71F1, vehicle, toggle); } // 0x83E56A7E8E3D71F1 0xA3906284
	static BOOL _GET_BOAT_ANCHOR(Vehicle vehicle) { return invoke<BOOL>(0x3EA02C569D3B5D0A, vehicle); } // 0x3EA02C569D3B5D0A
	static void _0x404338538C00A02F(Vehicle vehicle, BOOL p1) { invoke<Void>(0x404338538C00A02F, vehicle, p1); } // 0x404338538C00A02F 0x0ED84792
	static void _0xD134D83A85397970(Vehicle vehicle, BOOL p1) { invoke<Void>(0xD134D83A85397970, vehicle, p1); } // 0xD134D83A85397970 0xA739012A
	static void _0x17196E1CB6BB411C(Vehicle vehicle, float p1) { invoke<Void>(0x17196E1CB6BB411C, vehicle, p1); } // 0x17196E1CB6BB411C 0x66FA450C
	static void _0xF075943FCBA4FC4A(Vehicle vehicle, BOOL p1) { invoke<Void>(0xF075943FCBA4FC4A, vehicle, p1); } // 0xF075943FCBA4FC4A 0x35614622
	static void SET_VEHICLE_SIREN(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x71FF26FDD46DECD5, vehicle, toggle); } // 0x71FF26FDD46DECD5 0x4AC1EFC7
	static BOOL IS_VEHICLE_SIREN_ON(Vehicle vehicle) { return invoke<BOOL>(0xA06AE352748BB860, vehicle); } // 0xA06AE352748BB860 0x25EB5873
	static BOOL _IS_VEHICLE_SIREN_SOUND_ON(Vehicle vehicle) { return invoke<BOOL>(0x661301889C6CC704, vehicle); } // 0x661301889C6CC704
	static void SET_VEHICLE_STRONG(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xF8EDF3B7E8D2CD26, vehicle, toggle); } // 0xF8EDF3B7E8D2CD26 0xC758D19F
	static void REMOVE_VEHICLE_STUCK_CHECK(Any p0) { invoke<Void>(0x3F270BA6CB751144, p0); } // 0x3F270BA6CB751144 0x81594917
	static void GET_VEHICLE_COLOURS(Vehicle vehicle, int* colorPrimary, int* colorSecondary) { invoke<Void>(0x3C5D9FD265196560, vehicle, colorPrimary, colorSecondary); } // 0x3C5D9FD265196560 0x40D82D88
	static BOOL IS_VEHICLE_SEAT_FREE(Vehicle vehicle, int seatIndex) { return invoke<BOOL>(0xC0FA8EEF6413F866, vehicle, seatIndex); } // 0xC0FA8EEF6413F866 0xDAF42B02
	static Ped GET_PED_IN_VEHICLE_SEAT(Vehicle vehicle, int index) { return invoke<Ped>(0x17206B315923243C, vehicle, index); } // 0x17206B315923243C 0x388FDE9A
	static Ped GET_LAST_PED_IN_VEHICLE_SEAT(Vehicle vehicle, int seatIndex) { return invoke<Ped>(0x67649920B2C3A244, vehicle, seatIndex); } // 0x67649920B2C3A244 0xF7C6792D
	static BOOL GET_VEHICLE_LIGHTS_STATE(Vehicle vehicle, bool* lightsOn, bool* highbeamsOn) { return invoke<BOOL>(0xA22F7633B73159D3, vehicle, lightsOn, highbeamsOn); } // 0xA22F7633B73159D3 0x7C278621
	static BOOL IS_VEHICLE_TYRE_BURST(Vehicle vehicle, int wheelID, BOOL completely) { return invoke<BOOL>(0xC98320A98098650E, vehicle, wheelID, completely); } // 0xC98320A98098650E 0x48C80210
	static void SET_VEHICLE_FORWARD_SPEED(Vehicle vehicle, float speed) { invoke<Void>(0xFAC43F40071FC184, vehicle, speed); } // 0xFAC43F40071FC184 0x69880D14
	static void _SET_VEHICLE_HALT(Vehicle vehicle, float distance, int killEngine, BOOL unknown) { invoke<Void>(0xEEA9C8F490BB3507, vehicle, distance, killEngine, unknown); } // 0xEEA9C8F490BB3507 0xCBC7D3C8
	static void _0x55288535051AB288(Vehicle vehicle, float p1) { invoke<Void>(0x55288535051AB288, vehicle, p1); } // 0x55288535051AB288 0x943A6CFC
	static BOOL SET_PED_ENABLED_BIKE_RINGTONE(Vehicle vehicle, Any p1) { return invoke<BOOL>(0x0792C07B6F5BF82A, vehicle, p1); } // 0x0792C07B6F5BF82A 0x7FB25568
	static BOOL _0x4C649A3827B6C07F(Vehicle vehicle) { return invoke<BOOL>(0x4C649A3827B6C07F, vehicle); } // 0x4C649A3827B6C07F 0x593143B9
	static Vehicle _0x052AD10126829309(Object object) { return invoke<Vehicle>(0x052AD10126829309, object); } // 0x052AD10126829309 0x70DD5E25
	static BOOL _0x09BFA8E588D7AF24(Vehicle vehicle, Any p1) { return invoke<BOOL>(0x09BFA8E588D7AF24, vehicle, p1); } // 0x09BFA8E588D7AF24 0xFBF5536A
	static void _0x8EB5480738A8770E(Vehicle vehicle, Any p1) { invoke<Void>(0x8EB5480738A8770E, vehicle, p1); } // 0x8EB5480738A8770E 0x20AB5783
	static void _0x32BA74DDBEAE33E1(Vehicle vehicle) { invoke<Void>(0x32BA74DDBEAE33E1, vehicle); } // 0x32BA74DDBEAE33E1 0x0F11D01F
	static void _0x76338284483A9671(Vehicle vehicle, BOOL p1) { invoke<Void>(0x76338284483A9671, vehicle, p1); } // 0x76338284483A9671 0xAE040377
	static void _0xE546C1A05A42255C(Vehicle vehicle, BOOL p1) { invoke<Void>(0xE546C1A05A42255C, vehicle, p1); } // 0xE546C1A05A42255C 0x4C0E4031
	static BOOL _0xD365D9FD8737042C(Vehicle vehicle) { return invoke<BOOL>(0xD365D9FD8737042C, vehicle); } // 0xD365D9FD8737042C 0x6346B7CC
	static void _0xB3B3CDBEA6E08F77(Vehicle vehicle, float p1) { invoke<Void>(0xB3B3CDBEA6E08F77, vehicle, p1); } // 0xB3B3CDBEA6E08F77 0xCCB41A55
	static void SET_VEHICLE_TYRE_BURST(Vehicle vehicle, int index, BOOL onRim, float p3) { invoke<Void>(0xE1A2702F96DB1529, vehicle, index, onRim, p3); } // 0xE1A2702F96DB1529 0x89D28068
	static void SET_VEHICLE_DOORS_SHUT(Vehicle vehicle, BOOL closeInstantly) { invoke<Void>(0x016C65ED12A14D44, vehicle, closeInstantly); } // 0x016C65ED12A14D44 0xBB1FF6E7
	static void SET_VEHICLE_TYRES_CAN_BURST(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x5DED87DD8464517B, vehicle, toggle); } // 0x5DED87DD8464517B 0xA198DB54
	static BOOL GET_VEHICLE_TYRES_CAN_BURST(Vehicle vehicle) { return invoke<BOOL>(0x3AAC868F49EC1E0A, vehicle); } // 0x3AAC868F49EC1E0A 0x4D76CD2F
	static void SET_VEHICLE_WHEELS_CAN_BREAK(Vehicle vehicle, BOOL enabled) { invoke<Void>(0x4DD00F90AA077FAC, vehicle, enabled); } // 0x4DD00F90AA077FAC 0x829ED654
	static void SET_VEHICLE_DOOR_OPEN(Vehicle vehicle, int doorIndex, BOOL loose, BOOL openInstantly) { invoke<Void>(0xDE043EE8B3F02B86, vehicle, doorIndex, loose, openInstantly); } // 0xDE043EE8B3F02B86 0xBB75D38B
	static void REMOVE_VEHICLE_WINDOW(Vehicle vehicle, int windowIndex) { invoke<Void>(0x7DCEC4E83315DC12, vehicle, windowIndex); } // 0x7DCEC4E83315DC12 0xBB8104A3
	static void ROLL_DOWN_WINDOWS(Vehicle vehicle) { invoke<Void>(0x7937CC0BE57E2518, vehicle); } // 0x7937CC0BE57E2518 0x51A16DC6
	static void ROLL_DOWN_WINDOW(Vehicle vehicle, int windowIndex) { invoke<Void>(0xCEA8600A1F6B3FE7, vehicle, windowIndex); } // 0xCEA8600A1F6B3FE7 0xF840134C
	static void ROLL_UP_WINDOW(Vehicle vehicle, int windowIndex) { invoke<Void>(0xBF0D873E9B764DE1, vehicle, windowIndex); } // 0xBF0D873E9B764DE1 0x83B7E06A
	static void SMASH_VEHICLE_WINDOW(Vehicle vehicle, int index) { invoke<Void>(0xC02DDC2677C29F43, vehicle, index); } // 0xC02DDC2677C29F43 0xDDD9A8C2
	static void FIX_VEHICLE_WINDOW(Vehicle vehicle, int index) { invoke<Void>(0xC04D41908F04D62E, vehicle, index); } // 0xC04D41908F04D62E 0x6B8E990D
	static void _DETACH_VEHICLE_WINDSCREEN(Vehicle vehicle) { invoke<Void>(0x1AC3F6005C5F3036, vehicle); } // 0x1AC3F6005C5F3036 0xCC95C96B
	static void _EJECT_JB700_ROOF(Vehicle vehicle, float x, float y, float z) { invoke<Void>(0xB55F53E10D423F34, vehicle, x, y, z); } // 0xB55F53E10D423F34 0xFDA7B6CA
	static void SET_VEHICLE_LIGHTS(Vehicle vehicle, int state) { invoke<Void>(0xCA5EA8FBB2C07DB8, vehicle, state); } // 0xCA5EA8FBB2C07DB8 0xE8930226
	static void _0xF0BE60E29FD7A4C3(Vehicle vehicle, BOOL p1) { invoke<Void>(0xF0BE60E29FD7A4C3, vehicle, p1); } // 0xF0BE60E29FD7A4C3 0x4221E435
	static void _0x352DFAF0B4F6AD54(Vehicle vehicle, int p1) { invoke<Void>(0x352DFAF0B4F6AD54, vehicle, p1); } // 0x352DFAF0B4F6AD54
	static void SET_VEHICLE_ALARM(Vehicle vehicle, BOOL state) { invoke<Void>(0x4172F1081FB7C193, vehicle, state); } // 0x4172F1081FB7C193 0x24877D84
	static void START_VEHICLE_ALARM(Vehicle vehicle) { invoke<Void>(0x879A84D74138DEB1, vehicle); } // 0x879A84D74138DEB1 0x5B451FF7
	static BOOL IS_VEHICLE_ALARM_ACTIVATED(Vehicle vehicle) { return invoke<BOOL>(0x347433B4AC067A16, vehicle); } // 0x347433B4AC067A16 0xF2630A4C
	static void SET_VEHICLE_INTERIORLIGHT(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x0512B3C8BBE66B88, vehicle, toggle); } // 0x0512B3C8BBE66B88 0x9AD1FE1E
	static void SET_VEHICLE_LIGHT_MULTIPLIER(Vehicle vehicle, float multiplier) { invoke<Void>(0xD0BA19E7E2215CA7, vehicle, multiplier); } // 0xD0BA19E7E2215CA7 0x48039D6A
	static void ATTACH_VEHICLE_TO_TRAILER(Vehicle vehicle, Vehicle trailer, float radius) { invoke<Void>(0x5F340BF7DE0BA97D, vehicle, trailer, radius); } // 0x5F340BF7DE0BA97D 0x2133977F
	static void _0x5347A68B10374818(Vehicle vehicle, Vehicle trailer, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10, float p11) { invoke<Void>(0x5347A68B10374818, vehicle, trailer, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x5347A68B10374818 0x12AC1A16
	static void _0x3F3DA2ACA6F6B403(Vehicle p0, Entity p1, float p2) { invoke<Void>(0x3F3DA2ACA6F6B403, p0, p1, p2); } // 0x3F3DA2ACA6F6B403 0x40C4763F
	static void DETACH_VEHICLE_FROM_TRAILER(Vehicle vehicle) { invoke<Void>(0xBECFCA7D1FA2657F, vehicle); } // 0xBECFCA7D1FA2657F 0xB5DBF91D
	static BOOL IS_VEHICLE_ATTACHED_TO_TRAILER(Vehicle vehicle) { return invoke<BOOL>(0xB1C3C0AA8E1A5401, vehicle); } // 0xB1C3C0AA8E1A5401 0xE142BBCC
	static void _0x52986A0B4CD533FA(Any p0, float p1) { invoke<Void>(0x52986A0B4CD533FA, p0, p1); } // 0x52986A0B4CD533FA 0xE74E85CE
	static void _0xE6E097515E5ECFB8(Any p0) { invoke<Void>(0xE6E097515E5ECFB8, p0); } // 0xE6E097515E5ECFB8 0x06C47A6F
	static void SET_VEHICLE_TYRE_FIXED(Vehicle vehicle, int tyreIndex) { invoke<Void>(0x9B033ED67B9D801D, vehicle, tyreIndex); } // 0x9B033ED67B9D801D 0xA42EFA6B
	static void SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle vehicle, char* plateText) { invoke<Void>(0xBFA6D869BA395202, vehicle, plateText); } // 0xBFA6D869BA395202 0x400F9556
	static char* GET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle vehicle) { return invoke<char*>(0xE184AC3A4DAF353D, vehicle); } // 0xE184AC3A4DAF353D 0xE8522D58
	static int GET_NUMBER_OF_VEHICLE_NUMBER_PLATES() { return invoke<int>(0x65787AE258BCF6F8); } // 0x65787AE258BCF6F8 0xD24BC1AE
	static void SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Vehicle vehicle, int plateIndex) { invoke<Void>(0xE0B7A718D08DF2B6, vehicle, plateIndex); } // 0xE0B7A718D08DF2B6 0xA1A1890E
	static int GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Vehicle vehicle) { return invoke<int>(0x420AD4B7A2DA4F74, vehicle); } // 0x420AD4B7A2DA4F74 0x499747B6
	static void SET_RANDOM_TRAINS(BOOL toggle) { invoke<Void>(0x223C8480EA6EE20B, toggle); } // 0x223C8480EA6EE20B 0xD461CA7F
	static Vehicle CREATE_MISSION_TRAIN(int variation, float x, float y, float z, BOOL direction) { return invoke<Vehicle>(0x31E4DA47D87171B7, variation, x, y, z, direction); } // 0x31E4DA47D87171B7 0xD4C2EAFD
	static void SWITCH_TRAIN_TRACK(int intersectionId, BOOL state) { invoke<Void>(0x621F3BAA021294D1, intersectionId, state); } // 0x621F3BAA021294D1 0x68BFDD61
	static void _0xAF30FE101CEA20E0(Any p0, Any p1) { invoke<Void>(0xAF30FE101CEA20E0, p0, p1); } // 0xAF30FE101CEA20E0 0xD5774FB7
	static void DELETE_ALL_TRAINS() { invoke<Void>(0xF491075B1A8D5848); } // 0xF491075B1A8D5848 0x83DE7ABF
	static void SET_TRAIN_SPEED(Vehicle train, float speed) { invoke<Void>(0x68AD1450A50267E1, train, speed); } // 0x68AD1450A50267E1 0xDFC35E4D
	static void SET_TRAIN_CRUISE_SPEED(Vehicle train, float speed) { invoke<Void>(0xED138B869E6DF35A, train, speed); } // 0xED138B869E6DF35A 0xB507F51D
	static void SET_RANDOM_BOATS(BOOL toggle) { invoke<Void>(0xA89E4794C19E461E, toggle); } // 0xA89E4794C19E461E 0xB505BD89
	static void SET_GARBAGE_TRUCKS(BOOL toggle) { invoke<Void>(0xA9EB89B3EE589450, toggle); } // 0xA9EB89B3EE589450 0xD9ABB0FF
	static BOOL DOES_VEHICLE_HAVE_STUCK_VEHICLE_CHECK(Vehicle vehicle) { return invoke<BOOL>(0x3EFAA1D388F677C6, vehicle); } // 0x3EFAA1D388F677C6 0x5D91D9AC
	static Any GET_VEHICLE_RECORDING_ID(int p0, char* p1) { return invoke<Any>(0x73E840EE8F5FADA3, p0, p1); } // 0x73E840EE8F5FADA3 0x328D601D
	static void REQUEST_VEHICLE_RECORDING(Any p0, Any* p1) { invoke<Void>(0xF5B59A4EB5622187, p0, p1); } // 0xF5B59A4EB5622187 0x91AFEFD9
	static BOOL HAS_VEHICLE_RECORDING_BEEN_LOADED(Any p0, Any* p1) { return invoke<BOOL>(0x63781672EC63FB83, p0, p1); } // 0x63781672EC63FB83 0xF52CD7F5
	static void REMOVE_VEHICLE_RECORDING(Any p0, Any* p1) { invoke<Void>(0xF8E2640CE709A221, p0, p1); } // 0xF8E2640CE709A221 0xD3C05B00
	static Vector3 _0x488E5EF59AEBBF9B(Any p0, float p1) { return invoke<Vector3>(0x488E5EF59AEBBF9B, p0, p1); } // 0x488E5EF59AEBBF9B 0xF31973BB
	static Vector3 GET_POSITION_OF_VEHICLE_RECORDING_AT_TIME(int p0, float p1, char* p2) { return invoke<Vector3>(0x7E8C3589CF175379, p0, p1, p2); } // 0x7E8C3589CF175379 0x7178558D
	static Vector3 _0xF767E67C36BCA3BB(Any p0, float p1) { return invoke<Vector3>(0xF767E67C36BCA3BB, p0, p1); } // 0xF767E67C36BCA3BB 0x4D1C15C2
	static Vector3 GET_ROTATION_OF_VEHICLE_RECORDING_AT_TIME(Any p0, float p1, Any* p2) { return invoke<Vector3>(0xA6F057A3C8B8C0C4, p0, p1, p2); } // 0xA6F057A3C8B8C0C4 0xD96DEC68
	static float GET_TOTAL_DURATION_OF_VEHICLE_RECORDING_ID(Any p0) { return invoke<float>(0xD51E84ABC1CD715A, p0); } // 0xD51E84ABC1CD715A 0x7116785E
	static Any GET_TOTAL_DURATION_OF_VEHICLE_RECORDING(Any p0, Any p1) { return invoke<Any>(0x5871CF89CF524CD0, p0, p1); } // 0x5871CF89CF524CD0 0x5B35EEB7
	static float GET_POSITION_IN_RECORDING(Any p0) { return invoke<float>(0x221D1159CF7D465D, p0); } // 0x221D1159CF7D465D 0x7DCD644C
	static float GET_TIME_POSITION_IN_RECORDING(Any p0) { return invoke<float>(0x76423F51C82ED0C8, p0); } // 0x76423F51C82ED0C8 0xF8C3E4A2
	static void START_PLAYBACK_RECORDED_VEHICLE(Any p0, Any p1, Any* p2, BOOL p3) { invoke<Void>(0x9D14C436A01A0B15, p0, p1, p2, p3); } // 0x9D14C436A01A0B15 0xCF614CA8
	static void START_PLAYBACK_RECORDED_VEHICLE_WITH_FLAGS(Any p0, Any p1, Any* p2, Any p3, Any p4, Any p5) { invoke<Void>(0xAC472F160C64056B, p0, p1, p2, p3, p4, p5); } // 0xAC472F160C64056B 0x4E721AD2
	static void _0x2099B88C16CE7D57(Any p0, BOOL p1) { invoke<Void>(0x2099B88C16CE7D57, p0, p1); } // 0x2099B88C16CE7D57 0x01B91CD0
	static void STOP_PLAYBACK_RECORDED_VEHICLE(Any p0) { invoke<Void>(0x394D4A83F07AE208, p0); } // 0x394D4A83F07AE208 0xAE99C57C
	static void PAUSE_PLAYBACK_RECORDED_VEHICLE(Any p0) { invoke<Void>(0xDD70F47E7E3A0F76, p0); } // 0xDD70F47E7E3A0F76 0xCCF54912
	static void UNPAUSE_PLAYBACK_RECORDED_VEHICLE(Any p0) { invoke<Void>(0x84BFA822ADDD30C5, p0); } // 0x84BFA822ADDD30C5 0x59060F75
	static BOOL IS_PLAYBACK_GOING_ON_FOR_VEHICLE(Any p0) { return invoke<BOOL>(0x72222684DEA44B9F, p0); } // 0x72222684DEA44B9F 0x61F7650D
	static BOOL IS_PLAYBACK_USING_AI_GOING_ON_FOR_VEHICLE(Any p0) { return invoke<BOOL>(0x30453C5876F286B3, p0); } // 0x30453C5876F286B3 0x63022C58
	static Any GET_CURRENT_PLAYBACK_FOR_VEHICLE(Any p0) { return invoke<Any>(0xE8A3FB5086332078, p0); } // 0xE8A3FB5086332078 0xA3F44390
	static void SKIP_TO_END_AND_STOP_PLAYBACK_RECORDED_VEHICLE(Any p0) { invoke<Void>(0x9D8156A9993E68AB, p0); } // 0x9D8156A9993E68AB 0x8DEA18C8
	static void SET_PLAYBACK_SPEED(Any p0, float speed) { invoke<Void>(0x1ECBE6CE58710983, p0, speed); } // 0x1ECBE6CE58710983 0x684E26E4
	static void START_PLAYBACK_RECORDED_VEHICLE_USING_AI(Any p0, Any p1, Any* p2, float p3, Any p4) { invoke<Void>(0x76370B982D7FB115, p0, p1, p2, p3, p4); } // 0x76370B982D7FB115 0x8DE8E24E
	static void SKIP_TIME_IN_PLAYBACK_RECORDED_VEHICLE(Any p0, float p1) { invoke<Void>(0x367ABC65EA3C0FDD, p0, p1); } // 0x367ABC65EA3C0FDD 0xCF3EFA4B
	static void SET_PLAYBACK_TO_USE_AI(Vehicle vehicle, int flag) { invoke<Void>(0x2E46973EB80D8EDC, vehicle, flag); } // 0x2E46973EB80D8EDC 0xB536CCD7
	static void SET_PLAYBACK_TO_USE_AI_TRY_TO_REVERT_BACK_LATER(Any p0, Any p1, Any p2, BOOL p3) { invoke<Void>(0x727CE7F30980861F, p0, p1, p2, p3); } // 0x727CE7F30980861F 0x0C8ABAA4
	static void _0xA3D97C41F70C8581(Vehicle vehicle, float x, float y, float z, Any p4) { invoke<Void>(0xA3D97C41F70C8581, vehicle, x, y, z, p4); } // 0xA3D97C41F70C8581 0x943A58EB
	static void _0x264AE34853483716(Any p0, float p1, float p2, float p3) { invoke<Void>(0x264AE34853483716, p0, p1, p2, p3); } // 0x264AE34853483716 0x5C9F477C
	static void _0xBD0DCB24543446DF(Any p0, float p1, float p2, float p3) { invoke<Void>(0xBD0DCB24543446DF, p0, p1, p2, p3); } // 0xBD0DCB24543446DF 0xCD83C393
	static void _0xEA9D4889B5E986B5(Any p0, BOOL p1) { invoke<Void>(0xEA9D4889B5E986B5, p0, p1); } // 0xEA9D4889B5E986B5 0x2EF8435C
	static void EXPLODE_VEHICLE_IN_CUTSCENE(Vehicle p0, BOOL p1) { invoke<Void>(0x215EA3559F1F3279, p0, p1); } // 0x215EA3559F1F3279 0xA85207B5
	static void ADD_VEHICLE_STUCK_CHECK_WITH_WARP(Any p0, float p1, Any p2, BOOL p3, BOOL p4, BOOL p5, Any p6) { invoke<Void>(0x47FCC856F2DF0697, p0, p1, p2, p3, p4, p5, p6); } // 0x47FCC856F2DF0697 0xC8B789AD
	static void SET_VEHICLE_MODEL_IS_SUPPRESSED(Hash model, BOOL suppressed) { invoke<Void>(0xD90CB3CF9A40791C, model, suppressed); } // 0xD90CB3CF9A40791C 0x42A08C9B
	static Vehicle GET_RANDOM_VEHICLE_IN_SPHERE(float x, float y, float z, float radius, Hash modelHash, int flags) { return invoke<Vehicle>(0xFEDFCE97371B9236, x, y, z, radius, modelHash, flags); } // 0xFEDFCE97371B9236 0x57216D03
	static Vehicle GET_RANDOM_VEHICLE_FRONT_BUMPER_IN_SPHERE(float p0, float p1, float p2, float p3, int p4, int p5, int p6) { return invoke<Vehicle>(0x1A7C9F3CD17642E2, p0, p1, p2, p3, p4, p5, p6); } // 0x1A7C9F3CD17642E2 0xDCADEB66
	static Vehicle GET_RANDOM_VEHICLE_BACK_BUMPER_IN_SPHERE(float p0, float p1, float p2, float p3, int p4, int p5, int p6) { return invoke<Vehicle>(0xCDCE06C4ECDE92F3, p0, p1, p2, p3, p4, p5, p6); } // 0xCDCE06C4ECDE92F3 0xD6343F6B
	static Vehicle GET_CLOSEST_VEHICLE(float x, float y, float z, float radius, Hash modelHash, int flags) { return invoke<Vehicle>(0xCE499B0B1C2F5684, x, y, z, radius, modelHash, flags); } // 0xCE499B0B1C2F5684 0xD7E26B2C
	static Entity GET_TRAIN_CARRIAGE(Vehicle train, int carriage) { return invoke<Entity>(0xCD5B17B9EC861D4E, train, carriage); } // 0xCD5B17B9EC861D4E 0x2544E7A6
	static void DELETE_MISSION_TRAIN(Vehicle* train) { invoke<Void>(0xC986BC2DAE6ECFB1, train); } // 0xC986BC2DAE6ECFB1 0x86C9497D
	static void SET_MISSION_TRAIN_AS_NO_LONGER_NEEDED(Vehicle* train, BOOL p1) { invoke<Void>(0x9F5197261B33D544, train, p1); } // 0x9F5197261B33D544 0x19808560
	static void SET_MISSION_TRAIN_COORDS(Vehicle train, float x, float y, float z) { invoke<Void>(0x08A90B85A8F54BCF, train, x, y, z); } // 0x08A90B85A8F54BCF 0xD6D70803
	static BOOL IS_THIS_MODEL_A_BOAT(Hash model) { return invoke<BOOL>(0xA55B002FED5A9858, model); } // 0xA55B002FED5A9858 0x10F6085C
	static BOOL _IS_THIS_MODEL_AN_EMERGENCY_BOAT(Hash model) { return invoke<BOOL>(0x94AB8F7D4254DDDE, model); } // 0x94AB8F7D4254DDDE
	static BOOL IS_THIS_MODEL_A_PLANE(Hash model) { return invoke<BOOL>(0x8432EA469FDB418D, model); } // 0x8432EA469FDB418D 0x3B3907BB
	static BOOL IS_THIS_MODEL_A_HELI(Hash model) { return invoke<BOOL>(0xC5082382D5482C0C, model); } // 0xC5082382D5482C0C 0x8AF7F568
	static BOOL IS_THIS_MODEL_A_CAR(Hash model) { return invoke<BOOL>(0xC2AFD5CFEDC8F22A, model); } // 0xC2AFD5CFEDC8F22A 0x60E4C22F
	static BOOL IS_THIS_MODEL_A_TRAIN(Hash model) { return invoke<BOOL>(0x3B548F49528B5FA7, model); } // 0x3B548F49528B5FA7 0xF87DCFFD
	static BOOL IS_THIS_MODEL_A_BIKE(Hash model) { return invoke<BOOL>(0xD28959FE5BC2D14D, model); } // 0xD28959FE5BC2D14D 0x7E702CDD
	static BOOL IS_THIS_MODEL_A_BICYCLE(Hash model) { return invoke<BOOL>(0x4A0388DBE0CE87AA, model); } // 0x4A0388DBE0CE87AA 0x328E6FF5
	static BOOL IS_THIS_MODEL_A_QUADBIKE(Hash model) { return invoke<BOOL>(0xBA3A0947FBDD9ADD, model); } // 0xBA3A0947FBDD9ADD 0xC1625277
	static void SET_HELI_BLADES_FULL_SPEED(Vehicle vehicle) { invoke<Void>(0x85E61E88835AE7F5, vehicle); } // 0x85E61E88835AE7F5 0x033A9408
	static void SET_HELI_BLADES_SPEED(Vehicle vehicle, float speed) { invoke<Void>(0xA55C14D9B341BA28, vehicle, speed); } // 0xA55C14D9B341BA28 0x5C7D4EA9
	static void _0x847F005C4E735DD1(Vehicle vehicle, float p1, float p2) { invoke<Void>(0x847F005C4E735DD1, vehicle, p1, p2); } // 0x847F005C4E735DD1 0x1128A45B
	static void SET_VEHICLE_CAN_BE_TARGETTED(Vehicle vehicle, BOOL state) { invoke<Void>(0x476431A44C7D8609, vehicle, state); } // 0x476431A44C7D8609 0x64B70B1D
	static void _0x9F54265623E980EC(Vehicle vehicle, BOOL p1) { invoke<Void>(0x9F54265623E980EC, vehicle, p1); } // 0x9F54265623E980EC 0x486C1280
	static void SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(Vehicle vehicle, BOOL state) { invoke<Void>(0x7AFA437947CB9C46, vehicle, state); } // 0x7AFA437947CB9C46 0xC5D94017
	static void _0x3283EC6F7BD3A201(Vehicle vehicle, BOOL p1) { invoke<Void>(0x3283EC6F7BD3A201, vehicle, p1); } // 0x3283EC6F7BD3A201 0x009AB49E
	static void _0xC43B345113E0550B(Vehicle vehicle, BOOL p1) { invoke<Void>(0xC43B345113E0550B, vehicle, p1); } // 0xC43B345113E0550B 0x758C5E2E
	static float GET_VEHICLE_DIRT_LEVEL(Vehicle vehicle) { return invoke<float>(0xC89933A0F05DA78A, vehicle); } // 0xC89933A0F05DA78A 0xFD15C065
	static void SET_VEHICLE_DIRT_LEVEL(Vehicle vehicle, float dirtLevel) { invoke<Void>(0xC2BFC2AEE65D5595, vehicle, dirtLevel); } // 0xC2BFC2AEE65D5595 0x2B39128B
	static BOOL _IS_VEHICLE_DAMAGED(Vehicle vehicle) { return invoke<BOOL>(0xEDBB2D977915E63C, vehicle); } // 0xEDBB2D977915E63C 0xDAC523BC
	static BOOL IS_VEHICLE_DOOR_FULLY_OPEN(Vehicle vehicle, int doorIndex) { return invoke<BOOL>(0x8358BFE2634F295E, vehicle, doorIndex); } // 0x8358BFE2634F295E 0xC2385B6F
	static void SET_VEHICLE_ENGINE_ON(Vehicle vehicle, BOOL value, BOOL instantly, BOOL otherwise) { invoke<Void>(0x524A422B74847594, vehicle, value, instantly, otherwise); } // 0x524A422B74847594 0x7FBC86F1
	static void SET_VEHICLE_UNDRIVEABLE(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xC1B95D5AC645957D, vehicle, toggle); } // 0xC1B95D5AC645957D 0x48D02A4E
	static void SET_VEHICLE_PROVIDES_COVER(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x7A741FC9E2D00F7C, vehicle, toggle); } // 0x7A741FC9E2D00F7C 0xEFC01CA9
	static void SET_VEHICLE_DOOR_CONTROL(Vehicle vehicle, int doorIndex, int p2, float angle) { invoke<Void>(0x800D9F6E9FDC9680, vehicle, doorIndex, p2, angle); } // 0x800D9F6E9FDC9680 0x572DD360
	static void SET_VEHICLE_DOOR_LATCHED(Vehicle vehicle, int doorIndex, BOOL p2, BOOL p3, BOOL p4) { invoke<Void>(0x0CDA12DAE9F83318, vehicle, doorIndex, p2, p3, p4); } // 0x0CDA12DAE9F83318 0x4EB7BBFC
	static float GET_VEHICLE_DOOR_ANGLE_RATIO(Vehicle vehicle, int door) { return invoke<float>(0x7F841F0B66D99047, vehicle, door); } // 0x7F841F0B66D99047 0x0E399C26
	static Ped _GET_PED_USING_VEHICLE_DOOR(Vehicle vehicle, int doorIndex) { return invoke<Ped>(0xB48A4AC02C9739EC, vehicle, doorIndex); } // 0xB48A4AC02C9739EC
	static void SET_VEHICLE_DOOR_SHUT(Vehicle vehicle, int doorIndex, BOOL closeInstantly) { invoke<Void>(0xFBD8170293283E41, vehicle, doorIndex, closeInstantly); } // 0xFBD8170293283E41 0x142606BD
	static void SET_VEHICLE_DOOR_BROKEN(Vehicle vehicle, int doorIndex, BOOL createDoorObject) { invoke<Void>(0x5AD55E43AD73D13D, vehicle, doorIndex, createDoorObject); } // 0x5AD55E43AD73D13D 0x8147FEA7
	static void SET_VEHICLE_CAN_BREAK(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x879CEFE7BE03F4A6, vehicle, toggle); } // 0x879CEFE7BE03F4A6 0x90A810D1
	static BOOL DOES_VEHICLE_HAVE_ROOF(Vehicle vehicle) { return invoke<BOOL>(0xB92D42A6AB160A01, vehicle); } // 0xB92D42A6AB160A01 0xDB817403
	static BOOL IS_BIG_VEHICLE(Vehicle vehicle) { return invoke<BOOL>(0x3C6792805E3BEB1B, vehicle); } // 0x3C6792805E3BEB1B 0x9CDBA8DE
	static int GET_NUMBER_OF_VEHICLE_COLOURS(Vehicle vehicle) { return invoke<int>(0x7E1BF62E02C645D9, vehicle); } // 0x7E1BF62E02C645D9 0xF2442EE2
	static void SET_VEHICLE_COLOUR_COMBINATION(Vehicle vehicle, int numCombos) { invoke<Void>(0xEF9B9F466C3E73F6, vehicle, numCombos); } // 0xEF9B9F466C3E73F6 0xA557AEAD
	static int GET_VEHICLE_COLOUR_COMBINATION(Vehicle vehicle) { return invoke<int>(0xDE4621DB8691C664, vehicle); } // 0xDE4621DB8691C664 0x77AC1B4C
	static void SET_VEHICLE_IS_CONSIDERED_BY_PLAYER(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x4F94FF48185A8B4B, vehicle, toggle); } // 0x4F94FF48185A8B4B 0x14413319
	static void _0xE644D27D9C1E3010(Vehicle vehicle, BOOL p1) { invoke<Void>(0xE644D27D9C1E3010, vehicle, p1); } // 0xE644D27D9C1E3010 0xA6D8D7A5
	static void _0x0B9F0E27AE4BF850(Vehicle vehicle, BOOL p1) { invoke<Void>(0x0B9F0E27AE4BF850, vehicle, p1); } // 0x0B9F0E27AE4BF850 0xACAB8FF3
	static void _0xA511918EF0279635(Vehicle vehicle, BOOL p1) { invoke<Void>(0xA511918EF0279635, vehicle, p1); } // 0xA511918EF0279635 0xF0E5C41D
	static void _0x2E6FC5151E3C57F1(Vehicle vehicle, BOOL p1) { invoke<Void>(0x2E6FC5151E3C57F1, vehicle, p1); } // 0x2E6FC5151E3C57F1 0x2F98B4B7
	static void GET_RANDOM_VEHICLE_MODEL_IN_MEMORY(BOOL p0, Hash* modelHash, int* p2) { invoke<Void>(0x2CD1A4FF3E0904FE, p0, modelHash, p2); } // 0x2CD1A4FF3E0904FE 0xE2C45631
	static int GET_VEHICLE_DOOR_LOCK_STATUS(Vehicle vehicle) { return invoke<int>(0xB7541DEA333EE53D, vehicle); } // 0xB7541DEA333EE53D 0x0D72CEF2
	static BOOL IS_VEHICLE_DOOR_DAMAGED(Vehicle veh, int doorID) { return invoke<BOOL>(0x9020DA20CF0C5F11, veh, doorID); } // 0x9020DA20CF0C5F11 0x4999E3C3
	static void _SET_VEHICLE_DOOR_BREAKABLE(Vehicle vehicle, int doorIndex, BOOL isBreakable) { invoke<Void>(0x114D595E662E3EFD, vehicle, doorIndex, isBreakable); } // 0x114D595E662E3EFD 0x065B92B3
	static BOOL _0xAF2163DC1C6702AC(Vehicle vehicle, BOOL p1) { return invoke<BOOL>(0xAF2163DC1C6702AC, vehicle, p1); } // 0xAF2163DC1C6702AC 0xB3A2CC4F
	static BOOL IS_VEHICLE_BUMPER_BROKEN_OFF(Vehicle vehicle, BOOL front) { return invoke<BOOL>(0x75E873C8BF5DB887, vehicle, front); } // 0x75E873C8BF5DB887 0xAF25C027
	static BOOL IS_COP_VEHICLE_IN_AREA_3D(float x1, float x2, float y1, float y2, float z1, float z2) { return invoke<BOOL>(0xD43437C32E35E124, x1, x2, y1, y2, z1, z2); } // 0xD43437C32E35E124 0xFB16C6D1
	static BOOL IS_VEHICLE_ON_ALL_WHEELS(Vehicle vehicle) { return invoke<BOOL>(0x4950AAD2A16D6B22, vehicle); } // 0x4950AAD2A16D6B22 0x10089F8E
	static Hash GET_VEHICLE_LAYOUT_HASH(Vehicle vehicle) { return invoke<Hash>(0x04C5801B1A539DB7, vehicle); } // 0x04C5801B1A539DB7 0xE0B35187
	static Any _0x2F20B4BC6F6FA7CB(Vehicle vehicle, int p1) { return invoke<Any>(0x2F20B4BC6F6FA7CB, vehicle, p1); } // 0x2F20B4BC6F6FA7CB
	static void SET_RENDER_TRAIN_AS_DERAILED(Vehicle train, BOOL toggle) { invoke<Void>(0x0559930CF7778AB6, train, toggle); } // 0x0559930CF7778AB6 0x899D9092
	static void SET_VEHICLE_EXTRA_COLOURS(Vehicle vehicle, int pearlescentColor, int wheelColor) { invoke<Void>(0xB9A1BA07F229F6AC, vehicle, pearlescentColor, wheelColor); } // 0xB9A1BA07F229F6AC 0x515DB2A0
	static void GET_VEHICLE_EXTRA_COLOURS(Vehicle vehicle, int* pearlescentColor, int* wheelColor) { invoke<Void>(0x5CE46A3E89B49FAE, vehicle, pearlescentColor, wheelColor); } // 0x5CE46A3E89B49FAE 0x80E4659B
	static void STOP_ALL_GARAGE_ACTIVITY() { invoke<Void>(0x5E5FE9B87DCA7B33); } // 0x5E5FE9B87DCA7B33 0x17A0BCE5
	static void SET_VEHICLE_FIXED(Vehicle vehicle) { invoke<Void>(0x31589F3476134C55, vehicle); } // 0x31589F3476134C55 0x17469AA1
	static void SET_VEHICLE_DEFORMATION_FIXED(Vehicle vehicle) { invoke<Void>(0xBC02E92AEB20336A, vehicle); } // 0xBC02E92AEB20336A 0xDD2920C8
	static void _0xF2E81703FA1D1D1D(Vehicle vehicle, BOOL p1) { invoke<Void>(0xF2E81703FA1D1D1D, vehicle, p1); } // 0xF2E81703FA1D1D1D
	static void _0xDED89A6CAC392246(Vehicle vehicle, BOOL p1) { invoke<Void>(0xDED89A6CAC392246, vehicle, p1); } // 0xDED89A6CAC392246 0x88F0F7E7
	static void _0xEC2A26A6CA02C73C(Vehicle vehicle, BOOL p1) { invoke<Void>(0xEC2A26A6CA02C73C, vehicle, p1); } // 0xEC2A26A6CA02C73C 0x90D6EE57
	static void SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x1B923DBD91BF893F, vehicle, toggle); } // 0x1B923DBD91BF893F 0xC40192B5
	static void SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xBC120C453A1C2611, vehicle, toggle); } // 0xBC120C453A1C2611 0xAD3E05F2
	static void _0x3D8459AD189E8571(Vehicle vehicle, BOOL p1) { invoke<Void>(0x3D8459AD189E8571, vehicle, p1); } // 0x3D8459AD189E8571 0x1784BA1A
	static void _0xD060A1A0F63DE869(Vehicle vehicle, BOOL p1) { invoke<Void>(0xD060A1A0F63DE869, vehicle, p1); } // 0xD060A1A0F63DE869 0x40C323AE
	static void _0x56F96000EA0EF075(Vehicle vehicle, BOOL p1) { invoke<Void>(0x56F96000EA0EF075, vehicle, p1); } // 0x56F96000EA0EF075 0x847F1304
	static void _0x3C87A0A1456D6253(Vehicle vehicle, BOOL p1) { invoke<Void>(0x3C87A0A1456D6253, vehicle, p1); } // 0x3C87A0A1456D6253 0xCBD98BA1
	static void REMOVE_VEHICLES_FROM_GENERATORS_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2, Any unk) { invoke<Void>(0x862504E4C5E80C78, x1, y1, z1, x2, y2, z2, unk); } // 0x862504E4C5E80C78 0x42CC15E0
	static void SET_VEHICLE_STEER_BIAS(Vehicle vehicle, float value) { invoke<Void>(0x4BE5D7A6A9C8A632, vehicle, value); } // 0x4BE5D7A6A9C8A632 0x7357C1EB
	static BOOL IS_VEHICLE_EXTRA_TURNED_ON(Vehicle vehicle, int extraId) { return invoke<BOOL>(0xA13396827DE7EB7C, vehicle, extraId); } // 0xA13396827DE7EB7C 0x042098B5
	static void SET_VEHICLE_EXTRA(Vehicle vehicle, int extraId, int toggle) { invoke<Void>(0x70888C5F297D3D80, vehicle, extraId, toggle); } // 0x70888C5F297D3D80 0x642D065C
	static BOOL DOES_EXTRA_EXIST(Vehicle vehicle, int extraId) { return invoke<BOOL>(0x1909294695ABD725, vehicle, extraId); } // 0x1909294695ABD725 0x409411CC
	static void SET_CONVERTIBLE_ROOF(Vehicle vehicle, BOOL p1) { invoke<Void>(0x821778A7A73E847F, vehicle, p1); } // 0x821778A7A73E847F 0xC87B6A51
	static void LOWER_CONVERTIBLE_ROOF(Vehicle vehicle, BOOL instantlyLower) { invoke<Void>(0x63677FA149BCF42B, vehicle, instantlyLower); } // 0x63677FA149BCF42B 0xC5F72EAE
	static void RAISE_CONVERTIBLE_ROOF(Vehicle vehicle, BOOL instantlyRaise) { invoke<Void>(0xE4D316C82D08E63D, vehicle, instantlyRaise); } // 0xE4D316C82D08E63D 0xA4E4CBA3
	static int GET_CONVERTIBLE_ROOF_STATE(Vehicle vehicle) { return invoke<int>(0x575D47C669B84572, vehicle); } // 0x575D47C669B84572 0x1B09714D
	static BOOL IS_VEHICLE_A_CONVERTIBLE(Vehicle vehicle, BOOL p1) { return invoke<BOOL>(0x4555FC519F5B33E3, vehicle, p1); } // 0x4555FC519F5B33E3 0x6EF54490
	static BOOL IS_VEHICLE_STOPPED_AT_TRAFFIC_LIGHTS(Vehicle vehicle) { return invoke<BOOL>(0xC996E72A5F5B6CA7, vehicle); } // 0xC996E72A5F5B6CA7 0x69200FA4
	static void SET_VEHICLE_DAMAGE(Vehicle vehicle, float xOffset, float yOffset, float zOffset, float damage, float radius, BOOL p6) { invoke<Void>(0xE4FDA285C25BBA3A, vehicle, xOffset, yOffset, zOffset, damage, radius, p6); } // 0xE4FDA285C25BBA3A 0x21B458B2
	static float GET_VEHICLE_ENGINE_HEALTH(Vehicle vehicle) { return invoke<float>(0x27CB4A87DBB58E6E, vehicle); } // 0x27CB4A87DBB58E6E 0x8880038A
	static void SET_VEHICLE_ENGINE_HEALTH(Vehicle vehicle, float health) { invoke<Void>(0xEC0212C05F98C1DF, vehicle, health); } // 0xEC0212C05F98C1DF 0x1B760FB5
	static float GET_VEHICLE_PETROL_TANK_HEALTH(Vehicle vehicle) { return invoke<float>(0x1667F287C40D3CA4, vehicle); } // 0x1667F287C40D3CA4 0xE41595CE
	static void SET_VEHICLE_PETROL_TANK_HEALTH(Vehicle vehicle, float fix) { invoke<Void>(0x27202347A1928002, vehicle, fix); } // 0x27202347A1928002 0x660A3692
	static BOOL IS_VEHICLE_STUCK_TIMER_UP(Vehicle vehicle, int p1, int p2) { return invoke<BOOL>(0x01F09F0D64EF3285, vehicle, p1, p2); } // 0x01F09F0D64EF3285 0x2FCF58C1
	static void RESET_VEHICLE_STUCK_TIMER(Vehicle vehicle, BOOL nullAttributes) { invoke<Void>(0x9EB6A37211AEE6E6, vehicle, nullAttributes); } // 0x9EB6A37211AEE6E6 0xEF2A6016
	static BOOL IS_VEHICLE_DRIVEABLE(Vehicle vehicle, BOOL p1) { return invoke<BOOL>(0x45CD66F0A131E554, vehicle, p1); } // 0x45CD66F0A131E554 0x41A7267A
	static void SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(Vehicle vehicle, BOOL owned) { invoke<Void>(0xBC7AEF96844AABDE, vehicle, owned); } // 0xBC7AEF96844AABDE 0xB4D3DBFB
	static void SET_VEHICLE_NEEDS_TO_BE_HOTWIRED(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xF3E7BE8862E65B19, vehicle, toggle); } // 0xF3E7BE8862E65B19 0xD8260751
	static void _0xCC4FB7A78D1FA308(Vehicle vehicle, BOOL p1) { invoke<Void>(0xCC4FB7A78D1FA308, vehicle, p1); } // 0xCC4FB7A78D1FA308
	static void _0xADCCF72CB752FA52(Vehicle vehicle, BOOL p1) { invoke<Void>(0xADCCF72CB752FA52, vehicle, p1); } // 0xADCCF72CB752FA52
	static void START_VEHICLE_HORN(Vehicle vehicle, int duration, Hash mode, BOOL forever) { invoke<Void>(0x64A46E3DF379F29C, vehicle, duration, mode, forever); } // 0x64A46E3DF379F29C 0x0DF5ADB3
	static void _SET_VEHICLE_SILENT(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x4A8F33188AE1D8BE, vehicle, toggle); } // 0x4A8F33188AE1D8BE 0x968E5770
	static void SET_VEHICLE_HAS_STRONG_AXLES(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x2B9B4DCEF80D1566, vehicle, toggle); } // 0x2B9B4DCEF80D1566 0x0D1CBC65
	static char* GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(Hash modelHash) { return invoke<char*>(0xF1732F8F07E46184, modelHash); } // 0xF1732F8F07E46184 0xEC86DF39
	static Vector3 GET_VEHICLE_DEFORMATION_AT_POS(Vehicle vehicle, float offsetX, float offsetY, float offsetZ) { return invoke<Vector3>(0x0E58445C1F585AC5, vehicle, offsetX, offsetY, offsetZ); } // 0x0E58445C1F585AC5 0xABF02075
	static void SET_VEHICLE_LIVERY(Vehicle vehicle, int livery) { invoke<Void>(0x866129976ECB1FB9, vehicle, livery); } // 0x866129976ECB1FB9 0x7AD87059
	static int GET_VEHICLE_LIVERY(Vehicle vehicle) { return invoke<int>(0x7C73B96D4046CE64, vehicle); } // 0x7C73B96D4046CE64 0xEC82A51D
	static int GET_VEHICLE_LIVERY_COUNT(Vehicle vehicle) { return invoke<int>(0xD374022FAFC7605F, vehicle); } // 0xD374022FAFC7605F 0xFB0CA947
	static BOOL IS_VEHICLE_WINDOW_INTACT(Vehicle vehicle, int windowIndex) { return invoke<BOOL>(0x4AFDA497DA0BF602, vehicle, windowIndex); } // 0x4AFDA497DA0BF602 0xAC4EF23D
	static BOOL ARE_ALL_VEHICLE_WINDOWS_INTACT(Vehicle vehicle) { return invoke<BOOL>(0x93B6C0A401F9F4DA, vehicle); } // 0x93B6C0A401F9F4DA 0xBB619744
	static BOOL ARE_ANY_VEHICLE_SEATS_FREE(Vehicle vehicle) { return invoke<BOOL>(0x10C3BF43D462F5D4, vehicle); } // 0x10C3BF43D462F5D4 0x648E685A
	static void RESET_VEHICLE_WHEELS(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xE656C4B2B2921EBA, vehicle, toggle); } // 0xE656C4B2B2921EBA 0xD5FFE779
	static BOOL IS_HELI_PART_BROKEN(Vehicle vehicle, BOOL p1, BOOL p2, BOOL p3) { return invoke<BOOL>(0xDC2F71E7D8E274FA, vehicle, p1, p2, p3); } // 0xDC2F71E7D8E274FA 0xF4E4C439
	static float _GET_HELI_MAIN_ROTOR_HEALTH(Vehicle vehicle) { return invoke<float>(0xE43773615BFACDFC, vehicle); } // 0xE43773615BFACDFC 0xF01E2AAB
	static float _GET_HELI_TAIL_ROTOR_HEALTH(Vehicle vehicle) { return invoke<float>(0x84A07E50C10E0007, vehicle); } // 0x84A07E50C10E0007 0xA41BC13D
	static float _GET_HELI_ENGINE_HEALTH(Vehicle vehicle) { return invoke<float>(0x75396C0BE5459B50, vehicle); } // 0x75396C0BE5459B50 0x8A68388F
	static BOOL WAS_COUNTER_ACTIVATED(Vehicle vehicle, Any p1) { return invoke<BOOL>(0xE0D8339EFD6AE718, vehicle, p1); } // 0xE0D8339EFD6AE718 0x2916D69B
	static void SET_VEHICLE_NAME_DEBUG(Vehicle vehicle, char* name) { invoke<Void>(0xA88487C860E7C002, vehicle, name); } // 0xA88487C860E7C002 0xA712FF5C
	static void SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xFF1ED70AA8FAB440, vehicle, toggle); } // 0xFF1ED70AA8FAB440 0x38CC692B
	static void _0xD55ADAFBA1893223(Vehicle vehicle, BOOL p1) { invoke<Void>(0xD55ADAFBA1893223, vehicle, p1); } // 0xD55ADAFBA1893223 0xC306A9A3
	static void _0xC9D9C89B7B1040E5(Vehicle vehicle, BOOL p1) { invoke<Void>(0xC9D9C89B7B1040E5, vehicle, p1); } // 0xC9D9C89B7B1040E5 0x95A9ACCB
	static void _SET_VEHICLE_LANDING_GEAR(Vehicle vehicle, int state) { invoke<Void>(0x2F18827C60FB4AD8, vehicle, state); } // 0x2F18827C60FB4AD8 0x24F873FB
	static int GET_LANDING_GEAR_STATE(Vehicle vehicle) { return invoke<int>(0xF4925FA16E991774, vehicle); } // 0xF4925FA16E991774 0xA6F02670
	static BOOL IS_ANY_VEHICLE_NEAR_POINT(float x, float y, float z, float radius) { return invoke<BOOL>(0x47865C56C9B1EFE6, x, y, z, radius); } // 0x47865C56C9B1EFE6 0x2867A834
	static void REQUEST_VEHICLE_HIGH_DETAIL_MODEL(Vehicle vehicle) { invoke<Void>(0xA5A55E27B5DAA4C2, vehicle); } // 0xA5A55E27B5DAA4C2 0x9DA21956
	static void REMOVE_VEHICLE_HIGH_DETAIL_MODEL(Vehicle vehicle) { invoke<Void>(0x7B6F6365F07F34CE, vehicle); } // 0x7B6F6365F07F34CE 0x382BE070
	static BOOL IS_VEHICLE_HIGH_DETAIL(Vehicle vehicle) { return invoke<BOOL>(0x00F231E164585745, vehicle); } // 0x00F231E164585745 0x55D41928
	static void REQUEST_VEHICLE_ASSET(Hash vehicleHash, int vehicleAsset) { invoke<Void>(0xA56CF5F719228F25, vehicleHash, vehicleAsset); } // 0xA56CF5F719228F25 0x902B4F06
	static BOOL HAS_VEHICLE_ASSET_LOADED(int vehicleAsset) { return invoke<BOOL>(0x18EE473F859D0FB2, vehicleAsset); } // 0x18EE473F859D0FB2 0x8DAAC3CB
	static void REMOVE_VEHICLE_ASSET(int vehicleAsset) { invoke<Void>(0x341B2B69286FBC9D, vehicleAsset); } // 0x341B2B69286FBC9D 0x9620E9C6
	static void _SET_TOW_TRUCK_CRANE_HEIGHT(Vehicle towTruck, float height) { invoke<Void>(0x5D66CF558B7690BE, towTruck, height); } // 0x5D66CF558B7690BE 0x88236E22
	static void ATTACH_VEHICLE_TO_TOW_TRUCK(Vehicle towTruck, Vehicle vehicle, BOOL rear, float hookOffsetX, float hookOffsetY, float hookOffsetZ) { invoke<Void>(0x9CC6E9CE7EDCAFC7, towTruck, vehicle, rear, hookOffsetX, hookOffsetY, hookOffsetZ); } // 0x9CC6E9CE7EDCAFC7 0x8151571A
	static void DETACH_VEHICLE_FROM_TOW_TRUCK(Vehicle towTruck, Vehicle vehicle) { invoke<Void>(0x0A57226793A19176, towTruck, vehicle); } // 0x0A57226793A19176 0xC666CF33
	static BOOL DETACH_VEHICLE_FROM_ANY_TOW_TRUCK(Vehicle vehicle) { return invoke<BOOL>(0x636F6C8843828C1F, vehicle); } // 0x636F6C8843828C1F 0x3BF93651
	static BOOL IS_VEHICLE_ATTACHED_TO_TOW_TRUCK(Vehicle towTruck, Vehicle vehicle) { return invoke<BOOL>(0x2AFFA8434FA2066D, towTruck, vehicle); } // 0x2AFFA8434FA2066D 0x9699CFDC
	static Entity GET_ENTITY_ATTACHED_TO_TOW_TRUCK(Vehicle towTruck) { return invoke<Entity>(0xF0F8585FD7BEB515, towTruck); } // 0xF0F8585FD7BEB515 0x11EC7844
	static Any SET_VEHICLE_AUTOMATICALLY_ATTACHES(Vehicle vehicle, Any p1, Any p2) { return invoke<Any>(0x22BD31A68F219650, vehicle, p1, p2); } // 0x22BD31A68F219650 0x4273A8D3
	static void _0x6316E9B69A1EB712(Any p0, float p1, BOOL p2) { invoke<Void>(0x6316E9B69A1EB712, p0, p1, p2); } // 0x6316E9B69A1EB712 0xED23C8A3
	static void _0x8E66A62D00F6C059(Any p0, float p1, BOOL p2) { invoke<Void>(0x8E66A62D00F6C059, p0, p1, p2); } // 0x8E66A62D00F6C059 0xB1A52EF7
	static void _0xC5705F3548B0E982(Any p0, float p1) { invoke<Void>(0xC5705F3548B0E982, p0, p1); } // 0xC5705F3548B0E982 0xF30C566F
	static void _0xF3C53632F1233D15(Any p0, float p1) { invoke<Void>(0xF3C53632F1233D15, p0, p1); } // 0xF3C53632F1233D15 0xA7DF64D7
	static void _0x19F215EFB8DDAA41(Any p0, float p1) { invoke<Void>(0x19F215EFB8DDAA41, p0, p1); } // 0x19F215EFB8DDAA41 0xDD7936F5
	static BOOL _0xDA47289BC25292A5(Vector3* outVec, Any p1, Vector3* outVec1, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<BOOL>(0xDA47289BC25292A5, outVec, p1, outVec1, p3, p4, p5, p6, p7, p8); } // 0xDA47289BC25292A5 0x34E02FCD
	static void SET_VEHICLE_BURNOUT(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x56163E47309D708D, vehicle, toggle); } // 0x56163E47309D708D 0x9B6EF0EA
	static BOOL IS_VEHICLE_IN_BURNOUT(Vehicle vehicle) { return invoke<BOOL>(0x7790D0EA1C3832B3, vehicle); } // 0x7790D0EA1C3832B3 0x6632BC12
	static void SET_VEHICLE_REDUCE_GRIP(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xF6EF9E157515D6EC, vehicle, toggle); } // 0xF6EF9E157515D6EC 0x90D3A0D9
	static void SET_VEHICLE_INDICATOR_LIGHTS(Vehicle vehicle, int turnSignal, BOOL toggle) { invoke<Void>(0x374812EC633DEA58, vehicle, turnSignal, toggle); } // 0x374812EC633DEA58 0xA6073B5D
	static void SET_VEHICLE_BRAKE_LIGHTS(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x7B717981FC1BCC65, vehicle, toggle); } // 0x7B717981FC1BCC65 0x6D9BA11E
	static void SET_VEHICLE_HANDBRAKE(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xDDB7C0A89C149B60, vehicle, toggle); } // 0xDDB7C0A89C149B60 0xBA729A25
	static void _0x8A4CC8A981660AC2() { invoke<Void>(0x8A4CC8A981660AC2); } // 0x8A4CC8A981660AC2 0x37BC6ACB
	static Any _0xC8E02A4A24779EE9() { return invoke<Any>(0xC8E02A4A24779EE9); } // 0xC8E02A4A24779EE9 0x71D898EF
	static void _0xF5D941156E69AA8C(BOOL p0) { invoke<Void>(0xF5D941156E69AA8C, p0); } // 0xF5D941156E69AA8C 0x0B0523B0
	static BOOL GET_VEHICLE_TRAILER_VEHICLE(Vehicle vehicle, Vehicle* trailer) { return invoke<BOOL>(0x1FB3B232C7EAF710, vehicle, trailer); } // 0x1FB3B232C7EAF710 0xAE84D758
	static void _0x10F2DA1DFEB4BA9C(Vehicle vehicle, BOOL p1) { invoke<Void>(0x10F2DA1DFEB4BA9C, vehicle, p1); } // 0x10F2DA1DFEB4BA9C 0x0B200CE2
	static void SET_VEHICLE_RUDDER_BROKEN(Vehicle vehicle, BOOL p1) { invoke<Void>(0xAF485F17E7930F25, vehicle, p1); } // 0xAF485F17E7930F25 0x3FAC3CD4
	static void _0x36FCE4F2D3DC3D68(Vehicle vehicle, BOOL p1) { invoke<Void>(0x36FCE4F2D3DC3D68, vehicle, p1); } // 0x36FCE4F2D3DC3D68 0x0858678C
	static float _0x613788A47E6DE41D(Vehicle vehicle) { return invoke<float>(0x613788A47E6DE41D, vehicle); } // 0x613788A47E6DE41D 0x7D1A0616
	static float GET_VEHICLE_MAX_BRAKING(Vehicle vehicle) { return invoke<float>(0x2EB70B62856066FA, vehicle); } // 0x2EB70B62856066FA 0x03B926F6
	static float GET_VEHICLE_MAX_TRACTION(Vehicle vehicle) { return invoke<float>(0xDFA8889728BB1918, vehicle); } // 0xDFA8889728BB1918 0x7E5A1587
	static float GET_VEHICLE_ACCELERATION(Vehicle vehicle) { return invoke<float>(0x311582C31080EE69, vehicle); } // 0x311582C31080EE69 0x00478321
	static float _GET_VEHICLE_MODEL_MAX_SPEED(Hash modelHash) { return invoke<float>(0x0F6789FB42DEAFB6, modelHash); } // 0x0F6789FB42DEAFB6 0x8F291C4A
	static float GET_VEHICLE_MODEL_MAX_BRAKING(Hash modelHash) { return invoke<float>(0x774080B9D0611732, modelHash); } // 0x774080B9D0611732 0x7EF02883
	static float _0x3FF13413D24F3190(Hash modelHash) { return invoke<float>(0x3FF13413D24F3190, modelHash); } // 0x3FF13413D24F3190 0xF3A7293F
	static float GET_VEHICLE_MODEL_MAX_TRACTION(Hash modelHash) { return invoke<float>(0x993F9B560BC6E78E, modelHash); } // 0x993F9B560BC6E78E 0x7F985597
	static float GET_VEHICLE_MODEL_ACCELERATION(Hash modelHash) { return invoke<float>(0xF882C3104D5BE40D, modelHash); } // 0xF882C3104D5BE40D 0x29CB3537
	static float _0x6C65C2AC5F12851D(Hash modelHash) { return invoke<float>(0x6C65C2AC5F12851D, modelHash); } // 0x6C65C2AC5F12851D 0x37FBA7BC
	static float _0xD809B4467A57FCD8(Hash modelHash) { return invoke<float>(0xD809B4467A57FCD8, modelHash); } // 0xD809B4467A57FCD8 0x95BB67EB
	static float _0xC2A0202CB7F531B2(Hash modelHash) { return invoke<float>(0xC2A0202CB7F531B2, modelHash); } // 0xC2A0202CB7F531B2 0x87C5D271
	static float _0xCB2EEACF6186D58A(Any p0) { return invoke<float>(0xCB2EEACF6186D58A, p0); } // 0xCB2EEACF6186D58A 0xCE67162C
	static float GET_VEHICLE_CLASS_MAX_TRACTION(Any p0) { return invoke<float>(0xB092655DF3CE60DF, p0); } // 0xB092655DF3CE60DF 0x5B4FDC16
	static float GET_VEHICLE_CLASS_MAX_AGILITY(Any p0) { return invoke<float>(0xA69FD6862C88CBAE, p0); } // 0xA69FD6862C88CBAE 0x45F2BD83
	static float GET_VEHICLE_CLASS_MAX_ACCELERATION(Any p0) { return invoke<float>(0x96B71ED1C0695233, p0); } // 0x96B71ED1C0695233 0x3E220A9B
	static float GET_VEHICLE_CLASS_MAX_BRAKING(Any p0) { return invoke<float>(0xB94DB6EFF824E495, p0); } // 0xB94DB6EFF824E495 0xD08CC1A5
	static Any _0x69C2AF7775CB38F5(float p0, float p1, float p2, float p3, float p4, BOOL p5) { return invoke<Any>(0x69C2AF7775CB38F5, p0, p1, p2, p3, p4, p5); } // 0x69C2AF7775CB38F5 0xD6685803
	static BOOL _0x44BED698F10ECC19(Any p0) { return invoke<BOOL>(0x44BED698F10ECC19, p0); } // 0x44BED698F10ECC19 0x0C0332A6
	static void OPEN_BOMB_BAY_DOORS(Vehicle vehicle) { invoke<Void>(0x14EE703262C11A9B, vehicle); } // 0x14EE703262C11A9B 0x6574041D
	static void CLOSE_BOMB_BAY_DOORS(Vehicle vehicle) { invoke<Void>(0x9A3128E227D4F864, vehicle); } // 0x9A3128E227D4F864 0xF8EC5751
	static BOOL IS_VEHICLE_SEARCHLIGHT_ON(Vehicle vehicle) { return invoke<BOOL>(0xD75E5CC38FC6AADC, vehicle); } // 0xD75E5CC38FC6AADC 0xADAF3513
	static void SET_VEHICLE_SEARCHLIGHT(Vehicle heli, BOOL toggle, BOOL canBeUsedByAI) { invoke<Void>(0x72F3FA2EE5BDD6A1, heli, toggle, canBeUsedByAI); } // 0x72F3FA2EE5BDD6A1 0xE2C0DD8A
	static BOOL _0x1626793F639090A0(Any p0, Any p1, Any p2, BOOL p3, BOOL p4) { return invoke<BOOL>(0x1626793F639090A0, p0, p1, p2, p3, p4); } // 0x1626793F639090A0 0xAB0E79EB
	static BOOL CAN_SHUFFLE_SEAT(Vehicle vehicle, Any p1) { return invoke<BOOL>(0x0839840273EEEE03, vehicle, p1); } // 0x0839840273EEEE03 0xB3EB01ED
	static int GET_NUM_MOD_KITS(Vehicle vehicle) { return invoke<int>(0xFA4A2220118417AE, vehicle); } // 0xFA4A2220118417AE 0xE4903AA0
	static void SET_VEHICLE_MOD_KIT(Vehicle vehicle, int modKit) { invoke<Void>(0x5991FAEA924B5EE0, vehicle, modKit); } // 0x5991FAEA924B5EE0 0xB8132158
	static int GET_VEHICLE_MOD_KIT(Vehicle vehicle) { return invoke<int>(0x868D450960EE0901, vehicle); } // 0x868D450960EE0901 0x9FE60927
	static int GET_VEHICLE_MOD_KIT_TYPE(Vehicle vehicle) { return invoke<int>(0x8811FF219A0B1C20, vehicle); } // 0x8811FF219A0B1C20 0xE5F76765
	static int GET_VEHICLE_WHEEL_TYPE(Vehicle vehicle) { return invoke<int>(0x5AADFFFE972FF9B9, vehicle); } // 0x5AADFFFE972FF9B9 0xDA58D7AE
	static void SET_VEHICLE_WHEEL_TYPE(Vehicle vehicle, int WheelType) { invoke<Void>(0xE8356B7E1B731437, vehicle, WheelType); } // 0xE8356B7E1B731437 0x64BDAAAD
	static int GET_NUM_MOD_COLORS(int p0, BOOL p1) { return invoke<int>(0xAE098F09CCBC17F2, p0, p1); } // 0xAE098F09CCBC17F2 0x73722CD9
	static void SET_VEHICLE_MOD_COLOR_1(Vehicle vehicle, int paintType, int color, int p3) { invoke<Void>(0x23B8F6AE6ED8C09D, vehicle, paintType, color, p3); } // 0x23B8F6AE6ED8C09D 0xCBE9A54D
	static void SET_VEHICLE_MOD_COLOR_2(Vehicle vehicle, int paintType, int color) { invoke<Void>(0xD06C0702F595828B, vehicle, paintType, color); } // 0xD06C0702F595828B 0xC32613C2
	static void GET_VEHICLE_MOD_COLOR_1(Vehicle vehicle, int* paintType, int* color, int* p3) { invoke<Void>(0x79E4DD2A35D7ED5E, vehicle, paintType, color, p3); } // 0x79E4DD2A35D7ED5E 0xE625510A
	static void GET_VEHICLE_MOD_COLOR_2(Vehicle vehicle, int* paintType, int* color) { invoke<Void>(0x9FE3CA9817DE8656, vehicle, paintType, color); } // 0x9FE3CA9817DE8656 0x9B76BB8E
	static char* _GET_VEHICLE_MOD_COLOR_1_TEXT_LABEL(Vehicle vehicle, BOOL p1) { return invoke<char*>(0xA0B4522D518D8E12, vehicle, p1); } // 0xA0B4522D518D8E12 0x9A0840FD
	static char* _GET_VEHICLE_MOD_COLOR_2_TEXT_LABEL(Vehicle vehicle) { return invoke<char*>(0x952691C5DF8903BB, vehicle); } // 0x952691C5DF8903BB 0x9BDC0B49
	static BOOL _0x465B9A8B0A7A6C67(Any p0) { return invoke<BOOL>(0x465B9A8B0A7A6C67, p0); } // 0x465B9A8B0A7A6C67 0x112D637A
	static void SET_VEHICLE_MOD(Vehicle vehicle, int modType, int modIndex, BOOL customTires) { invoke<Void>(0xE8BE9EFA248A9414, vehicle, modType, modIndex, customTires); } // 0xE8BE9EFA248A9414 0xB52E5ED5
	static int GET_VEHICLE_MOD(Vehicle vehicle, int modType) { return invoke<int>(0x68BE46B0EA4FCFAF, vehicle, modType); } // 0x68BE46B0EA4FCFAF 0xDC520069
	static BOOL GET_VEHICLE_MOD_VARIATION(Vehicle vehicle, int modType) { return invoke<BOOL>(0x1D2F98CF2A472A00, vehicle, modType); } // 0x1D2F98CF2A472A00 0xC1B92003
	static int GET_NUM_VEHICLE_MODS(Vehicle vehicle, int modType) { return invoke<int>(0xF218D5E7A1FA1079, vehicle, modType); } // 0xF218D5E7A1FA1079 0x8A814FF9
	static void REMOVE_VEHICLE_MOD(Vehicle vehicle, int modType) { invoke<Void>(0x8762285499CFD42B, vehicle, modType); } // 0x8762285499CFD42B 0x9CC80A43
	static void TOGGLE_VEHICLE_MOD(Vehicle vehicle, int modType, BOOL toggle) { invoke<Void>(0xA6EBC11A2C89D4A1, vehicle, modType, toggle); } // 0xA6EBC11A2C89D4A1 0xD095F811
	static BOOL IS_TOGGLE_MOD_ON(Vehicle vehicle, int modType) { return invoke<BOOL>(0x2E6E95784D18C8E0, vehicle, modType); } // 0x2E6E95784D18C8E0 0xF0E1689F
	static char* GET_MOD_TEXT_LABEL(Vehicle vehicle, int modType, int modValue) { return invoke<char*>(0x945C7AD683103333, vehicle, modType, modValue); } // 0x945C7AD683103333 0x0BA39CA7
	static char* GET_MOD_SLOT_NAME(Vehicle vehicle, int modType) { return invoke<char*>(0xFBC0DA2F385FCE35, vehicle, modType); } // 0xFBC0DA2F385FCE35 0x5E113483
	static char* GET_LIVERY_NAME(Vehicle vehicle, int liveryIndex) { return invoke<char*>(0xC842D7325A73818A, vehicle, liveryIndex); } // 0xC842D7325A73818A 0xED80B5BE
	static Any GET_VEHICLE_MOD_MODIFIER_VALUE(Vehicle vehicle, int modType, int modIndex) { return invoke<Any>(0x3808C96E29A151A9, vehicle, modType, modIndex); } // 0x3808C96E29A151A9 0x73AE5505
	static Any _0x4AEDD9F23956FBAB(Any p0, Any p1, Any p2) { return invoke<Any>(0x4AEDD9F23956FBAB, p0, p1, p2); } // 0x4AEDD9F23956FBAB 0x94850968
	static void PRELOAD_VEHICLE_MOD(Any p0, Any p1, Any p2) { invoke<Void>(0x232449ACE7CE2AAF, p0, p1, p2); } // 0x232449ACE7CE2AAF 0x6EA5F4A8
	static BOOL HAS_PRELOAD_MODS_FINISHED(Any p0) { return invoke<BOOL>(0x28627AE5CA846075, p0); } // 0x28627AE5CA846075 0xA8A0D246
	static void RELEASE_PRELOAD_MODS(Vehicle vehicle) { invoke<Void>(0xFC60ECC396B01FB8, vehicle); } // 0xFC60ECC396B01FB8 0xD442521F
	static void SET_VEHICLE_TYRE_SMOKE_COLOR(Vehicle vehicle, int r, int g, int b) { invoke<Void>(0xF487CED93F263DA0, vehicle, r, g, b); } // 0xF487CED93F263DA0 0x3EDEC0DB
	static void GET_VEHICLE_TYRE_SMOKE_COLOR(Vehicle vehicle, int* r, int* g, int* b) { invoke<Void>(0xEFB6EA0CF01B73B1, vehicle, r, g, b); } // 0xEFB6EA0CF01B73B1 0x75280015
	static void SET_VEHICLE_WINDOW_TINT(Vehicle vehicle, int tint) { invoke<Void>(0xA3C6B7F3E39994ED, vehicle, tint); } // 0xA3C6B7F3E39994ED 0x497C8787
	static int GET_VEHICLE_WINDOW_TINT(Vehicle vehicle) { return invoke<int>(0xB3A30C9CBD0AF035, vehicle); } // 0xB3A30C9CBD0AF035 0x13D53892
	static int GET_NUM_VEHICLE_WINDOW_TINTS() { return invoke<int>(0x894A02E73AAB0840); } // 0x894A02E73AAB0840 0x625C7B66
	static void GET_VEHICLE_COLOR(Vehicle vehicle, int* r, int* g, int* b) { invoke<Void>(0xFA72D0C816AA357C, vehicle, r, g, b); } // 0xFA72D0C816AA357C 0x03BC8F1B
	static int _0x4EBF6609CFA4454A(Vehicle vehicle) { return invoke<int>(0x4EBF6609CFA4454A, vehicle); } // 0x4EBF6609CFA4454A 0x749DEEA2
	static Hash GET_VEHICLE_CAUSE_OF_DESTRUCTION(Vehicle vehicle) { return invoke<Hash>(0xC8FD71F29A49DBC3, vehicle); } // 0xC8FD71F29A49DBC3 0x7F8C20DD
	static BOOL GET_IS_LEFT_VEHICLE_HEADLIGHT_DAMAGED(Vehicle vehicle) { return invoke<BOOL>(0x8141A31C333C24EF, vehicle); } // 0x8141A31C333C24EF 0xA0777943
	static BOOL GET_IS_RIGHT_VEHICLE_HEADLIGHT_DAMAGED(Vehicle vehicle) { return invoke<BOOL>(0x0ACF91BF7586B499, vehicle); } // 0x0ACF91BF7586B499 0xF178390B
	static void _SET_VEHICLE_ENGINE_POWER_MULTIPLIER(Vehicle vehicle, float value) { invoke<Void>(0x0753EA395BE94F83, vehicle, value); } // 0x0753EA395BE94F83 0xE943B09C
	static void _0x4C0BCB4631EE8F68(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x4C0BCB4631EE8F68, vehicle, toggle); } // 0x4C0BCB4631EE8F68 0xDF594D8D
	static void _0x272F05A9188C0AE4(Any p0, BOOL p1) { invoke<Void>(0x272F05A9188C0AE4, p0, p1); } // 0x272F05A9188C0AE4 0x4D840FC4
	static Any _0xA51829F33EDD96BF(float p0, float p1, float p2, float p3, float p4, float p5, float p6) { return invoke<Any>(0xA51829F33EDD96BF, p0, p1, p2, p3, p4, p5, p6); } // 0xA51829F33EDD96BF 0x5AB26C2B
	static void _0xE6162A190827DADC(Any p0) { invoke<Void>(0xE6162A190827DADC, p0); } // 0xE6162A190827DADC 0xEF05F807
	static BOOL _0x4003DFF605B5F9A8(Any p0) { return invoke<BOOL>(0x4003DFF605B5F9A8, p0); } // 0x4003DFF605B5F9A8 0xD656E7E5
	static void _SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(Vehicle vehicle, float value) { invoke<Void>(0x72D227C5C82EB9A6, vehicle, value); } // 0x72D227C5C82EB9A6 0x642DA5AA
	static void _0xEF0E650FF75830C0(Any p0, BOOL p1) { invoke<Void>(0xEF0E650FF75830C0, p0, p1); } // 0xEF0E650FF75830C0 0x04F5546C
	static void SET_VEHICLE_IS_WANTED(Vehicle vehicle, BOOL state) { invoke<Void>(0x3F1D5D367E15601E, vehicle, state); } // 0x3F1D5D367E15601E 0xDAA388E8
	static void _0x17C7FFF1440FD3A5(Any p0, float p1) { invoke<Void>(0x17C7FFF1440FD3A5, p0, p1); } // 0x17C7FFF1440FD3A5 0xA25CCB8C
	static void _0xBDFBF41EDBA8CF08(Any p0, BOOL p1) { invoke<Void>(0xBDFBF41EDBA8CF08, p0, p1); } // 0xBDFBF41EDBA8CF08 0x00966934
	static void _0x1CEBBB94A8AD9695(Any p0, BOOL p1) { invoke<Void>(0x1CEBBB94A8AD9695, p0, p1); } // 0x1CEBBB94A8AD9695 0x113DF5FD
	static float _0xE3EA3D3B9E0D5AEF(Any p0) { return invoke<float>(0xE3EA3D3B9E0D5AEF, p0); } // 0xE3EA3D3B9E0D5AEF 0x7C8D6464
	static void DISABLE_PLANE_AILERON(Vehicle vehicle, BOOL p1, BOOL p2) { invoke<Void>(0x441269234F4A4254, vehicle, p1, p2); } // 0x441269234F4A4254 0x7E84C45C
	static BOOL GET_IS_VEHICLE_ENGINE_RUNNING(Vehicle vehicle) { return invoke<BOOL>(0x5DEB532E62B5680C, vehicle); } // 0x5DEB532E62B5680C 0x7DC6D022
	static void _0x55191A516774AC79(Vehicle vehicle, BOOL p1) { invoke<Void>(0x55191A516774AC79, vehicle, p1); } // 0x55191A516774AC79 0xA03E42DF
	static void _SET_BIKE_LEAN_ANGLE(Vehicle vehicle, float x, float y) { invoke<Void>(0x72D9AA21EE02FCA7, vehicle, x, y); } // 0x72D9AA21EE02FCA7 0x15D40761
	static void _0xB7A086F89FD711C4(Vehicle vehicle, BOOL p1) { invoke<Void>(0xB7A086F89FD711C4, vehicle, p1); } // 0xB7A086F89FD711C4 0x1984F88D
	static void _0x9B43147945BF9BBF(Vehicle vehicle) { invoke<Void>(0x9B43147945BF9BBF, vehicle); } // 0x9B43147945BF9BBF 0x3FBE904F
	static void _0x48682885BE1315AD(Any p0) { invoke<Void>(0x48682885BE1315AD, p0); } // 0x48682885BE1315AD 0xD1B71A25
	static Vehicle GET_LAST_DRIVEN_VEHICLE() { return invoke<Vehicle>(0xA9C8EAA15373F456); } // 0xA9C8EAA15373F456 0xFEB0C0C8
	static void _0x6DD3029D93A2CBA1() { invoke<Void>(0x6DD3029D93A2CBA1); } // 0x6DD3029D93A2CBA1
	static void _0xB4E2D258BC1E3E4A(Any p0, BOOL p1) { invoke<Void>(0xB4E2D258BC1E3E4A, p0, p1); } // 0xB4E2D258BC1E3E4A 0x08CD58F9
	static void _SET_PLANE_MIN_HEIGHT_ABOVE_GROUND(Vehicle plane, int height) { invoke<Void>(0x3CCDB450226D0DAD, plane, height); } // 0x3CCDB450226D0DAD 0x8C4B63E2
	static void SET_VEHICLE_LOD_MULTIPLIER(Vehicle vehicle, float multiplier) { invoke<Void>(0x9665F5FB3A8B2550, vehicle, multiplier); } // 0x9665F5FB3A8B2550 0x569E5AE3
	static void _0x0F2AE8B51289309C(Vehicle vehicle, BOOL p1) { invoke<Void>(0x0F2AE8B51289309C, vehicle, p1); } // 0x0F2AE8B51289309C 0x1604C2F5
	static Any _0xDED22CCAD9B65E46(Any p0) { return invoke<Any>(0xDED22CCAD9B65E46, p0); } // 0xDED22CCAD9B65E46 0x8CDB0C09
	static Any _0x0711AB57E2B1A242(Any p0) { return invoke<Any>(0x0711AB57E2B1A242, p0); } // 0x0711AB57E2B1A242 0xABC99E21
	static void _0x1630B4AF647F0619(Any p0, BOOL p1) { invoke<Void>(0x1630B4AF647F0619, p0, p1); } // 0x1630B4AF647F0619 0x900C878C
	static void _0x3D7D689B52382951(Any p0, BOOL p1) { invoke<Void>(0x3D7D689B52382951, p0, p1); } // 0x3D7D689B52382951 0xB3200F72
	static void _0xB0C59B9382777FE7(Vehicle vehicle, Vehicle vehicle2) { invoke<Void>(0xB0C59B9382777FE7, vehicle, vehicle2); } // 0xB0C59B9382777FE7 0xBAE491C7
	static void _0x8888F9E04B5625E6() { invoke<Void>(0x8888F9E04B5625E6); } // 0x8888F9E04B5625E6 0xF0E59BC1
	static void _0xD34B9272F5A8DFD1(float p0) { invoke<Void>(0xD34B9272F5A8DFD1, p0); } // 0xD34B9272F5A8DFD1 0x929801C6
	static void SET_VEHICLE_SHOOT_AT_TARGET(Ped driver, Entity entity, float xTarget, float yTarget, float zTarget) { invoke<Void>(0x6A5F700EEAAB4EA9, driver, entity, xTarget, yTarget, zTarget); } // 0x6A5F700EEAAB4EA9 0x2343FFDF
	static BOOL _GET_VEHICLE_OWNER(Vehicle vehicle, Entity* entity) { return invoke<BOOL>(0xD3176B1997F97FC7, vehicle, entity); } // 0xD3176B1997F97FC7 0x4A557117
	static void _0x250DE4033DCCFBBA(Vehicle vehicle, BOOL p1) { invoke<Void>(0x250DE4033DCCFBBA, vehicle, p1); } // 0x250DE4033DCCFBBA 0xE0FC6A32
	static void _0x2751D4D7BF274188(Vehicle vehicle, float p1) { invoke<Void>(0x2751D4D7BF274188, vehicle, p1); } // 0x2751D4D7BF274188 0x7D0DE7EA
	static int GET_VEHICLE_PLATE_TYPE(Vehicle vehicle) { return invoke<int>(0x19F813C11DC06D04, vehicle); } // 0x19F813C11DC06D04 0x65CA9286
	static void TRACK_VEHICLE_VISIBILITY(Vehicle vehicle) { invoke<Void>(0x1976D6B36CACBFE7, vehicle); } // 0x1976D6B36CACBFE7 0x78122DC1
	static BOOL IS_VEHICLE_VISIBLE(Vehicle vehicle) { return invoke<BOOL>(0x7D86ADEE79DE4C72, vehicle); } // 0x7D86ADEE79DE4C72 0x7E0D6056
	static void SET_VEHICLE_GRAVITY(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x6A8E2E86A006F4F2, vehicle, toggle); } // 0x6A8E2E86A006F4F2 0x07B2A6DC
	static void _0xC86528A03A2C4F2E(BOOL p0) { invoke<Void>(0xC86528A03A2C4F2E, p0); } // 0xC86528A03A2C4F2E 0xD2B8ACBD
	static Any _0x8A24E3E8126D1C01(Any p0) { return invoke<Any>(0x8A24E3E8126D1C01, p0); } // 0x8A24E3E8126D1C01 0xA4A75FCF
	static void _0x85F4BE704EDD0A70(Any p0, BOOL p1) { invoke<Void>(0x85F4BE704EDD0A70, p0, p1); } // 0x85F4BE704EDD0A70 0x50F89338
	static void _0xBE1DF9725E780EB0(Any p0, BOOL p1) { invoke<Void>(0xBE1DF9725E780EB0, p0, p1); } // 0xBE1DF9725E780EB0 0xEB7D7C27
	static BOOL _0x917B43B283994B16(Vehicle vehicle) { return invoke<BOOL>(0x917B43B283994B16, vehicle); } // 0x917B43B283994B16 0x5EB00A6A
	static void SET_VEHICLE_ENGINE_CAN_DEGRADE(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x77C1DE484C4249F8, vehicle, toggle); } // 0x77C1DE484C4249F8 0x081DAC12
	static void _0x04768BC243CC2D6B(Vehicle vehicle, int p1, int p2) { invoke<Void>(0x04768BC243CC2D6B, vehicle, p1, p2); } // 0x04768BC243CC2D6B 0x5BD8D82D
	static void _0xADF318CEEA6ACE38(Any p0) { invoke<Void>(0xADF318CEEA6ACE38, p0); } // 0xADF318CEEA6ACE38 0x450AD03A
	static BOOL _0x3B236BCC7CA86F1F(Any p0) { return invoke<BOOL>(0x3B236BCC7CA86F1F, p0); } // 0x3B236BCC7CA86F1F 0xBD085DCA
	static BOOL _0xD65B48FFE9F947A8(Any p0) { return invoke<BOOL>(0xD65B48FFE9F947A8, p0); } // 0xD65B48FFE9F947A8 0xABBDD5C6
	static void _0x930207476D7C5D02(Any p0, BOOL p1) { invoke<Void>(0x930207476D7C5D02, p0, p1); } // 0x930207476D7C5D02 0x9B581DE7
	static BOOL IS_VEHICLE_STOLEN(Vehicle vehicle) { return invoke<BOOL>(0xDABC65773FAE7D61, vehicle); } // 0xDABC65773FAE7D61 0x20B61DDE
	static void SET_VEHICLE_IS_STOLEN(Vehicle vehicle, BOOL isStolen) { invoke<Void>(0xBE993A95A7771E1E, vehicle, isStolen); } // 0xBE993A95A7771E1E 0x70912E42
	static void _0x5DB9DA6F770A599A(Any p0, float p1) { invoke<Void>(0x5DB9DA6F770A599A, p0, p1); } // 0x5DB9DA6F770A599A 0xED159AE6
	static BOOL _0x30331D8EBB99E323(Any p0) { return invoke<BOOL>(0x30331D8EBB99E323, p0); } // 0x30331D8EBB99E323 0xAF8CB3DF
	static void _0x6BB858C510EF3E48(Vehicle vehicle) { invoke<Void>(0x6BB858C510EF3E48, vehicle); } // 0x6BB858C510EF3E48 0x45F72495
	static void DETACH_VEHICLE_FROM_CARGOBOB(Vehicle vehicle, Vehicle cargobob) { invoke<Void>(0x7AD9276CC3B5383C, vehicle, cargobob); } // 0x7AD9276CC3B5383C 0x83D3D331
	static BOOL DETACH_VEHICLE_FROM_ANY_CARGOBOB(Vehicle vehicle) { return invoke<BOOL>(0xC684364765A13E34, vehicle); } // 0xC684364765A13E34 0x50E0EABE
	static BOOL IS_VEHICLE_ATTACHED_TO_CARGOBOB(Vehicle cargobob, Vehicle vehicleAttached) { return invoke<BOOL>(0x104771224A913EA4, cargobob, vehicleAttached); } // 0x104771224A913EA4 0x5DEEC76C
	static Vehicle GET_VEHICLE_ATTACHED_TO_CARGOBOB(Vehicle cargobob) { return invoke<Vehicle>(0xCF19BCD8019DB1BC, cargobob); } // 0xCF19BCD8019DB1BC 0x301A1D24
	static void ATTACH_VEHICLE_TO_CARGOBOB(Vehicle vehicle, Vehicle cargobob, int p2, float x, float y, float z) { invoke<Void>(0x7AC1DDAF0CE7C890, vehicle, cargobob, p2, x, y, z); } // 0x7AC1DDAF0CE7C890 0x607DC9D5
	static void _0xE1C0451581641BA1(Any p0, BOOL p1) { invoke<Void>(0xE1C0451581641BA1, p0, p1); } // 0xE1C0451581641BA1
	static Vector3 _GET_CARGOBOB_HOOK_POSITION(Vehicle cargobob) { return invoke<Vector3>(0x33FF9495712A58D9, cargobob); } // 0x33FF9495712A58D9
	static BOOL _IS_CARGOBOB_HOOK_ACTIVE(Vehicle cargobob) { return invoke<BOOL>(0x3B701D8C3A772F5E, cargobob); } // 0x3B701D8C3A772F5E 0xAF769B81
	static void _ENABLE_CARGOBOB_HOOK(Vehicle cargobob, int state) { invoke<Void>(0xDB585B6213F8A5F8, cargobob, state); } // 0xDB585B6213F8A5F8 0x4D3C9A99
	static void _RETRACT_CARGOBOB_HOOK(Vehicle cargobob) { invoke<Void>(0x48D38B9ABD76E152, cargobob); } // 0x48D38B9ABD76E152 0xA8211EE9
	static void _SET_CARGOBOB_HOOK_POSITION(Any p0, float p1, float p2, BOOL p3) { invoke<Void>(0xF780B6C83CB41BA0, p0, p1, p2, p3); } // 0xF780B6C83CB41BA0 0x3A8AB081
	static void _0x5A6BA7C50C16E764(Any p0, float p1) { invoke<Void>(0x5A6BA7C50C16E764, p0, p1); } // 0x5A6BA7C50C16E764
	static BOOL _IS_CARGOBOB_MAGNET_ACTIVE(Vehicle cargobob) { return invoke<BOOL>(0x4C77866E051369C6, cargobob); } // 0x4C77866E051369C6
	static void _CARGOBOB_MAGNET_GRAB_VEHICLE(Vehicle cargobob, BOOL toggle) { invoke<Void>(0xFBEB80D01ED7AACF, cargobob, toggle); } // 0xFBEB80D01ED7AACF
	static void _0xEA3130D41B951AE1(Any p0, float p1) { invoke<Void>(0xEA3130D41B951AE1, p0, p1); } // 0xEA3130D41B951AE1
	static void _0xCDEC9FD85F73146C(Any p0, float p1) { invoke<Void>(0xCDEC9FD85F73146C, p0, p1); } // 0xCDEC9FD85F73146C
	static void _0x0E89DC689E9D6865(Any p0, float p1) { invoke<Void>(0x0E89DC689E9D6865, p0, p1); } // 0x0E89DC689E9D6865
	static void _0x402F987B888ECA09(Any p0, float p1) { invoke<Void>(0x402F987B888ECA09, p0, p1); } // 0x402F987B888ECA09
	static void _0x1DB1D67FB7AA038E(Any p0, float p1) { invoke<Void>(0x1DB1D67FB7AA038E, p0, p1); } // 0x1DB1D67FB7AA038E
	static void _0x47AA5AAC18487335(Any p0, float p1) { invoke<Void>(0x47AA5AAC18487335, p0, p1); } // 0x47AA5AAC18487335
	static void _0x695C00C7A85F552D(Any p0, Any p1) { invoke<Void>(0x695C00C7A85F552D, p0, p1); } // 0x695C00C7A85F552D
	static void _0x079E1A9F21C9B750(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x079E1A9F21C9B750, p0, p1, p2); } // 0x079E1A9F21C9B750
	static void _0x0602CF8A059B3693(Any p0, BOOL p1) { invoke<Void>(0x0602CF8A059B3693, p0, p1); } // 0x0602CF8A059B3693
	static BOOL DOES_VEHICLE_HAVE_WEAPONS(Vehicle vehicle) { return invoke<BOOL>(0x117586D8B9229003, vehicle); } // 0x117586D8B9229003 0xB2E1E1FB
	static void _0x0A21DC9F18ED6952(Any p0, BOOL p1) { invoke<Void>(0x0A21DC9F18ED6952, p0, p1); } // 0x0A21DC9F18ED6952 0x2EC19A8B
	static void DISABLE_VEHICLE_WEAPON(BOOL disabled, Hash weaponHash, Vehicle vehicle, Ped owner) { invoke<Void>(0x52549F98F70EA862, disabled, weaponHash, vehicle, owner); } // 0x52549F98F70EA862 0xA688B7D1
	static void _0x4BC6A24CE5E7F2FB(Any p0, BOOL p1) { invoke<Void>(0x4BC6A24CE5E7F2FB, p0, p1); } // 0x4BC6A24CE5E7F2FB 0x123E5B90
	static void _0x23D171DF93B2E0DC(Any p0, BOOL p1) { invoke<Void>(0x23D171DF93B2E0DC, p0, p1); } // 0x23D171DF93B2E0DC 0xEBC225C1
	static int GET_VEHICLE_CLASS(Vehicle vehicle) { return invoke<int>(0xE6231D996EEECBEB, vehicle); } // 0xE6231D996EEECBEB 0xC025338E
	static int GET_VEHICLE_CLASS_FROM_NAME(Hash modelHash) { return invoke<int>(0xA39567BA8B24B256, modelHash); } // 0xA39567BA8B24B256 0xEA469980
	static void SET_PLAYERS_LAST_VEHICLE(Vehicle vehicle) { invoke<Void>(0xE2F0233968813F8F, vehicle); } // 0xE2F0233968813F8F 0xDE86447D
	static void SET_VEHICLE_CAN_BE_USED_BY_FLEEING_PEDS(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xC302F9682EAE1779, vehicle, toggle); } // 0xC302F9682EAE1779 0x5130DB1E
	static void _0x85D60660250B32A2(Vehicle vehicle, float p1) { invoke<Void>(0x85D60660250B32A2, vehicle, p1); } // 0x85D60660250B32A2 0xB6BE07E0
	static void _SET_VEHICLE_CREATES_MONEY_PICKUPS_WHEN_EXPLODED(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x063AAF8E3A3AC579, vehicle, toggle); } // 0x063AAF8E3A3AC579 0x4BB5605D
	static void _SET_VEHICLE_JET_ENGINE_ON(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xEAC2DCBB234EBC0F, vehicle, toggle); } // 0xEAC2DCBB234EBC0F 0x51E0064F
	static void _0x95E239E0594B0A50(Any p0, Any p1) { invoke<Void>(0x95E239E0594B0A50, p0, p1); } // 0x95E239E0594B0A50
	static void _0x9560F1BE91AE7383(Any p0, Any p1) { invoke<Void>(0x9560F1BE91AE7383, p0, p1); } // 0x9560F1BE91AE7383 0xAEF9611C
	static void _0x07B874309D685FF6(Any p0, float p1) { invoke<Void>(0x07B874309D685FF6, p0, p1); } // 0x07B874309D685FF6 0x585E49B6
	static void _SET_HELICOPTER_ROLL_PITCH_YAW_MULT(Vehicle helicopter, float multiplier) { invoke<Void>(0x1B6FCB5CC61BD408, helicopter, multiplier); } // 0x1B6FCB5CC61BD408 0x6E67FD35
	static void SET_VEHICLE_FRICTION_OVERRIDE(Vehicle vehicle, float friction) { invoke<Void>(0x18F54E9679804E24, vehicle, friction); } // 0x18F54E9679804E24 0x32AFD42E
	static void SET_VEHICLE_WHEELS_CAN_BREAK_OFF_WHEN_BLOW_UP(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x0817FD45DDBDC04E, vehicle, toggle); } // 0x0817FD45DDBDC04E 0x670913A4
	static BOOL _0x576D001DFC016433(Any p0, BOOL p1) { return invoke<BOOL>(0x576D001DFC016433, p0, p1); } // 0x576D001DFC016433
	static void SET_VEHICLE_CEILING_HEIGHT(Vehicle vehicle, float p1) { invoke<Void>(0x3E287C56923AC88E, vehicle, p1); } // 0x3E287C56923AC88E 0x98A10A86
	static void _0x6DFC1ED7CE485135(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x6DFC1ED7CE485135, vehicle, toggle); } // 0x6DFC1ED7CE485135 0xBC649C49
	static void _0x41F0FBFA90253549(Vehicle vehicle) { invoke<Void>(0x41F0FBFA90253549, vehicle); } // 0x41F0FBFA90253549 0x8DD9AA0C
	static BOOL DOES_VEHICLE_EXIST_WITH_DECORATOR(char* decorator) { return invoke<BOOL>(0x906BBB165DE994D1, decorator); } // 0x906BBB165DE994D1 0x39E68EDD
	static void _0x1B2975EC958D29B5(Any p0, BOOL p1) { invoke<Void>(0x1B2975EC958D29B5, p0, p1); } // 0x1B2975EC958D29B5 0xAA8BD440
	static void _SET_VEHICLE_EXCLUSIVE_DRIVER(Vehicle vehicle, Ped ped, int p2) { invoke<Void>(0x7DED4A89B196E1AC, vehicle, ped, p2); } // 0x7DED4A89B196E1AC
	static void _0x6B55C98A4BC4BEDA(Vehicle vehicle, Any p1) { invoke<Void>(0x6B55C98A4BC4BEDA, vehicle, p1); } // 0x6B55C98A4BC4BEDA
	static void _0xCD6265A862EC9A50(Vehicle vehicle, BOOL p1) { invoke<Void>(0xCD6265A862EC9A50, vehicle, p1); } // 0xCD6265A862EC9A50
	static void _DISPLAY_DISTANT_VEHICLES(BOOL toggle) { invoke<Void>(0x6C4203D61B1B3209, toggle); } // 0x6C4203D61B1B3209 0xB5CC548B
	static void _SET_VEHICLE_NEON_LIGHTS_COLOUR(Vehicle vehicle, int r, int g, int b) { invoke<Void>(0x4EC6390E64BE867C, vehicle, r, g, b); } // 0x4EC6390E64BE867C
	static void _GET_VEHICLE_NEON_LIGHTS_COLOUR(Vehicle vehicle, int* r, int* g, int* b) { invoke<Void>(0x86916C0F8ACCF8A7, vehicle, r, g, b); } // 0x86916C0F8ACCF8A7
	static void _SET_VEHICLE_NEON_LIGHT_ENABLED(Vehicle vehicle, int index, BOOL toggle) { invoke<Void>(0x0C93CB3C1E004C79, vehicle, index, toggle); } // 0x0C93CB3C1E004C79
	static BOOL _IS_VEHICLE_NEON_LIGHT_ENABLED(Vehicle vehicle, int index) { return invoke<BOOL>(0xA2BD8E71E4EDAA75, vehicle, index); } // 0xA2BD8E71E4EDAA75
	static void _0x556A959666BD1960(BOOL p0) { invoke<Void>(0x556A959666BD1960, p0); } // 0x556A959666BD1960
	static void _0xCA7CD5ED69C9C191(Vehicle vehicle, BOOL p1) { invoke<Void>(0xCA7CD5ED69C9C191, vehicle, p1); } // 0xCA7CD5ED69C9C191
	static void _0x3399092FD4522AD3(Vehicle vehicle) { invoke<Void>(0x3399092FD4522AD3, vehicle); } // 0x3399092FD4522AD3
	static float GET_VEHICLE_BODY_HEALTH(Vehicle vehicle) { return invoke<float>(0x75F25D2A638B4ADD, vehicle); } // 0x75F25D2A638B4ADD 0x2B2FCC28
	static void SET_VEHICLE_BODY_HEALTH(Vehicle vehicle, float value) { invoke<Void>(0x4C49E14FD31A0773, vehicle, value); } // 0x4C49E14FD31A0773 0x920C2517
	static void _0x397665926E912F5B(Vehicle vehicle, Any p1, Any p2) { invoke<Void>(0x397665926E912F5B, vehicle, p1, p2); } // 0x397665926E912F5B
	static float _GET_VEHICLE_SUSPENSION_HEIGHT(Vehicle vehicle) { return invoke<float>(0x26E6387B8D02B1CB, vehicle); } // 0x26E6387B8D02B1CB 0xB73A1486
	static void _0x857CF02503C95421(float p0) { invoke<Void>(0x857CF02503C95421, p0); } // 0x857CF02503C95421
	static void _0x51E62112EC676F7D(Vehicle vehicle, BOOL p1) { invoke<Void>(0x51E62112EC676F7D, vehicle, p1); } // 0x51E62112EC676F7D
	static float _GET_VEHICLE_BODY_HEALTH_2(Vehicle vehicle) { return invoke<float>(0xE53E8A1D14B34AD9, vehicle); } // 0xE53E8A1D14B34AD9
	static BOOL _0x563766F7557F2334(Vehicle vehicle) { return invoke<BOOL>(0x563766F7557F2334, vehicle); } // 0x563766F7557F2334
	static void _0x9D8A0212353A7A37(Any p0, BOOL p1) { invoke<Void>(0x9D8A0212353A7A37, p0, p1); } // 0x9D8A0212353A7A37
	static void _0xF12C9A582B0A7CE5(Vehicle vehicle, BOOL p1) { invoke<Void>(0xF12C9A582B0A7CE5, vehicle, p1); } // 0xF12C9A582B0A7CE5
	static void _0xA162AB5AFD371B55(Any p0, BOOL p1) { invoke<Void>(0xA162AB5AFD371B55, p0, p1); } // 0xA162AB5AFD371B55
}

namespace OBJECT
{
	static Object CREATE_OBJECT(Hash modelHash, float x, float y, float z, BOOL networkHandle, BOOL createHandle, BOOL dynamic) { return invoke<Object>(0x521A82CF998EDB21, modelHash, x, y, z, networkHandle, createHandle, dynamic); } // 0x521A82CF998EDB21 0x2F7AA05C
	static Object CREATE_OBJECT_NO_OFFSET(Hash modelHash, float x, float y, float z, BOOL networkHandle, BOOL createHandle, BOOL dynamic) { return invoke<Object>(0x89241A4EA7EE46D2, modelHash, x, y, z, networkHandle, createHandle, dynamic); } // 0x89241A4EA7EE46D2 0x58040420
	static void DELETE_OBJECT(Object* object) { invoke<Void>(0x1AAFEA627BB9C402, object); } // 0x1AAFEA627BB9C402 0xD6EF9DA7
	static BOOL PLACE_OBJECT_ON_GROUND_PROPERLY(Object object) { return invoke<BOOL>(0xBA4FE16C36326979, object); } // 0xBA4FE16C36326979 0x8F95A20B
	static BOOL SLIDE_OBJECT(Object object, float toX, float toY, float toZ, float speedX, float speedY, float speedZ, BOOL collision) { return invoke<BOOL>(0xFD083EC44B765F9B, object, toX, toY, toZ, speedX, speedY, speedZ, collision); } // 0xFD083EC44B765F9B 0x63BFA7A0
	static void SET_OBJECT_TARGETTABLE(Object object, BOOL targettable) { invoke<Void>(0x50685F1F2CA528C4, object, targettable); } // 0x50685F1F2CA528C4 0x3F88CD86
	static void _0xF7597986B9A57634(Object object, BOOL p1) { invoke<Void>(0xF7597986B9A57634, object, p1); } // 0xF7597986B9A57634 0x483C5C88
	static Object GET_CLOSEST_OBJECT_OF_TYPE(float x, float y, float z, float radius, Hash modelHash, BOOL isMission, BOOL p6, BOOL p7) { return invoke<Object>(0x29280EF6724677F5, x, y, z, radius, modelHash, isMission, p6, p7); } // 0x29280EF6724677F5 0x45619B33
	static BOOL HAS_OBJECT_BEEN_BROKEN(Object object) { return invoke<BOOL>(0xD53A3C5CA3FC9721, object); } // 0xD53A3C5CA3FC9721 0xFE21F891
	static BOOL HAS_CLOSEST_OBJECT_OF_TYPE_BEEN_BROKEN(float p0, float p1, float p2, float p3, Hash modelHash, Any p5) { return invoke<BOOL>(0xE034424FAFAC009B, p0, p1, p2, p3, modelHash, p5); } // 0xE034424FAFAC009B 0x6FC0353D
	static BOOL _0x5A331E10A1564C34(float p0, float p1, float p2, float p3, Hash modelHash, BOOL p5) { return invoke<BOOL>(0x5A331E10A1564C34, p0, p1, p2, p3, modelHash, p5); } // 0x5A331E10A1564C34 0x7DB578DD
	static Vector3 _GET_OBJECT_OFFSET_FROM_COORDS(float xPos, float yPos, float zPos, float heading, float xOffset, float yOffset, float zOffset) { return invoke<Vector3>(0x3CE07141081BBC2B, xPos, yPos, zPos, heading, xOffset, yOffset, zOffset); } // 0x3CE07141081BBC2B 0x87A42A12
	static Any _0x105D3EFF90A3790E(Any coords, float radius, Hash modelHash, float x, float y, float z, Vector3* p6, int p7) { return invoke<Any>(0x105D3EFF90A3790E, coords, radius, modelHash, x, y, z, p6, p7); } // 0x105D3EFF90A3790E 0x65213FC3
	static void SET_STATE_OF_CLOSEST_DOOR_OF_TYPE(Hash type, float x, float y, float z, BOOL locked, float heading, BOOL p6) { invoke<Void>(0x2AE800DA4E0E5670, type, x, y, z, locked, heading, p6); } // 0x2AE800DA4E0E5670 0x38C951A4
	static void GET_STATE_OF_CLOSEST_DOOR_OF_TYPE(Hash type, float x, float y, float z, BOOL* locked, float* heading) { invoke<Void>(0x2A20BF6DDF92A769, type, x, y, z, locked, heading); } // 0x2A20BF6DDF92A769 0x4B44A83D
	static void _DOOR_CONTROL(Hash doorHash, float x, float y, float z, BOOL locked, float p5, float p6, float p7) { invoke<Void>(0x52C70173F1AF9ECD, doorHash, x, y, z, locked, p5, p6, p7); } // 0x52C70173F1AF9ECD 0x4E0A260B
	static void ADD_DOOR_TO_SYSTEM(Hash doorHash, Hash modelHash, float x, float y, float z, BOOL p5, BOOL p6, BOOL p7) { invoke<Void>(0x49FD1922C9046077, doorHash, modelHash, x, y, z, p5, p6, p7); } // 0x49FD1922C9046077 0x9D2D778D
	static void REMOVE_DOOR_FROM_SYSTEM(Hash doorHash) { invoke<Void>(0x0A5EBD99B82C2B3E, doorHash); } // 0x0A5EBD99B82C2B3E 0x00253286
	static void _SET_DOOR_ACCELERATION_LIMIT(Hash doorHash, int limit, BOOL p2, BOOL p3) { invoke<Void>(0x01C5575F2350FF9E, doorHash, limit, p2, p3); } // 0x01C5575F2350FF9E 0xDF83DB47
	static int _0xA7735BAE257BD051(Hash doorHash) { return invoke<int>(0xA7735BAE257BD051, doorHash); } // 0xA7735BAE257BD051 0xD42A41C2
	static int _0x0DE4575F70E2DA8E(Hash doorHash) { return invoke<int>(0x0DE4575F70E2DA8E, doorHash); } // 0x0DE4575F70E2DA8E 0xD649B7E1
	static void _0xA5EB3CA146EF9FBA(Hash doorHash, float p1, BOOL p2, BOOL p3) { invoke<Void>(0xA5EB3CA146EF9FBA, doorHash, p1, p2, p3); } // 0xA5EB3CA146EF9FBA 0x4F44AF21
	static void _0x970BD4462B1C42AE(Hash doorHash, float heading, BOOL p2, BOOL p3) { invoke<Void>(0x970BD4462B1C42AE, doorHash, heading, p2, p3); } // 0x970BD4462B1C42AE 0x47531446
	static void _SET_DOOR_AJAR_ANGLE(Hash doorHash, float ajar, BOOL p2, BOOL p3) { invoke<Void>(0x7D1C3939CB180509, doorHash, ajar, p2, p3); } // 0x7D1C3939CB180509 0x34883DE3
	static float _0x5B7BB50F64C9D42A(Hash doorHash) { return invoke<float>(0x5B7BB50F64C9D42A, doorHash); } // 0x5B7BB50F64C9D42A 0xB74C3BD7
	static void _0x5172D18A840F75CE(Hash doorHash, BOOL p1, BOOL p2, BOOL p3) { invoke<Void>(0x5172D18A840F75CE, doorHash, p1, p2, p3); } // 0x5172D18A840F75CE 0xB4A9A558
	static void _0x03BDC1590D822B47(Hash doorHash, BOOL p1) { invoke<Void>(0x03BDC1590D822B47, doorHash, p1); } // 0x03BDC1590D822B47 0xECE58AE0
	static void _0xD3DB7D043754D401(Hash doorHash, BOOL p1) { invoke<Void>(0xD3DB7D043754D401, doorHash, p1); } // 0xD3DB7D043754D401 0xF736227C
	static BOOL _DOES_DOOR_EXIST(Hash doorHash) { return invoke<BOOL>(0xE9C3BF0269D0108B, doorHash); } // 0xE9C3BF0269D0108B 0x5AFCD8A1
	static BOOL IS_DOOR_CLOSED(Hash door) { return invoke<BOOL>(0x75B04FF9F8AF8441, door); } // 0x75B04FF9F8AF8441 0x48659CD7
	static void _0x8C693233A65E78E9(BOOL p0) { invoke<Void>(0x8C693233A65E78E9, p0); } // 0x8C693233A65E78E9 0x9BF33E41
	static void _0x72D55C6CCBC06783() { invoke<Void>(0x72D55C6CCBC06783); } // 0x72D55C6CCBC06783 0xF592AD10
	static BOOL _0x603E8C068FBE2532(Any p0) { return invoke<BOOL>(0x603E8C068FBE2532, p0); } // 0x603E8C068FBE2532 0x17FF9393
	static BOOL _0xB6083777D882090D(float p0, float p1, float p2, Any p3, Any* p4) { return invoke<BOOL>(0xB6083777D882090D, p0, p1, p2, p3, p4); } // 0xB6083777D882090D 0xE9AE494F
	static BOOL IS_GARAGE_EMPTY(Any garage, BOOL p1, int p2) { return invoke<BOOL>(0xC765BA9285A8F045, garage, p1, p2); } // 0xC765BA9285A8F045 0xA8B37DEA
	static BOOL _0xF86D292195501D67(Any p0, Player player, float p2, int p3) { return invoke<BOOL>(0xF86D292195501D67, p0, player, p2, p3); } // 0xF86D292195501D67 0xC33ED360
	static BOOL _0xDE0DF4E389216504(Any p0, Player player, int p2) { return invoke<BOOL>(0xDE0DF4E389216504, p0, player, p2); } // 0xDE0DF4E389216504 0x41924877
	static BOOL _0x001B1F355992F964(Any p0, BOOL p1, BOOL p2, BOOL p3, Any p4) { return invoke<BOOL>(0x001B1F355992F964, p0, p1, p2, p3, p4); } // 0x001B1F355992F964 0x4BD59750
	static BOOL _0xB7FE4EA0DC4E3323(Any p0, BOOL p1, BOOL p2, BOOL p3, Any p4) { return invoke<BOOL>(0xB7FE4EA0DC4E3323, p0, p1, p2, p3, p4); } // 0xB7FE4EA0DC4E3323 0x7B44D659
	static BOOL _0x4FD7E69EB8A0BD58(Any p0, Entity entity, float p2, int p3) { return invoke<BOOL>(0x4FD7E69EB8A0BD58, p0, entity, p2, p3); } // 0x4FD7E69EB8A0BD58 0x142C8F76
	static BOOL _0xDFA77B42E880AC29(Any p0, Entity entity, int p2) { return invoke<BOOL>(0xDFA77B42E880AC29, p0, entity, p2); } // 0xDFA77B42E880AC29 0x95A9AB2B
	static void _0xD268D5D329DF19DA(Any p0, BOOL p1, BOOL p2, BOOL p3, BOOL p4) { invoke<Void>(0xD268D5D329DF19DA, p0, p1, p2, p3, p4); } // 0xD268D5D329DF19DA 0xA565E27E
	static void _0x3AEB98F0E7904D11(Hash hash, BOOL toggle) { invoke<Void>(0x3AEB98F0E7904D11, hash, toggle); } // 0x3AEB98F0E7904D11 0x43BB7E48
	static void _0x89FAA6DAB95B0CD9() { invoke<Void>(0x89FAA6DAB95B0CD9); } // 0x89FAA6DAB95B0CD9 0x6158959E
	static BOOL DOES_OBJECT_OF_TYPE_EXIST_AT_COORDS(float x, float y, float z, float radius, Hash hash, BOOL p5) { return invoke<BOOL>(0x8B98C3C1BE2D3F12, x, y, z, radius, hash, p5); } // 0x8B98C3C1BE2D3F12 0x23FF2BA4
	static BOOL IS_POINT_IN_ANGLED_AREA(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9, BOOL p10, BOOL p11) { return invoke<BOOL>(0x3D559A6AF62756C4, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x3D559A6AF62756C4 0x73BCFFDC
	static void _0xEF9C33934A1F8D88(Object object, BOOL toggle) { invoke<Void>(0xEF9C33934A1F8D88, object, toggle); } // 0xEF9C33934A1F8D88 0x19B17769
	static void SET_OBJECT_PHYSICS_PARAMS(Object object, float weight, float p2, float p3, float p4, float p5, float gravity, float p7, float p8, float p9, float p10, float buoyancy) { invoke<Void>(0x5A88A9DD23C56CAF, object, weight, p2, p3, p4, p5, gravity, p7, p8, p9, p10, buoyancy); } // 0x5A88A9DD23C56CAF 0xE8D11C58
	static float GET_OBJECT_FRAGMENT_DAMAGE_HEALTH(Any p0, BOOL p1) { return invoke<float>(0x5EBEF0A29BC4F1B7, p0, p1); } // 0x5EBEF0A29BC4F1B7 0xF0B330AD
	static void SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN(Object object, BOOL toggle) { invoke<Void>(0xF880A68A9F678D9F, object, toggle); } // 0xF880A68A9F678D9F 0x3E263AE1
	static BOOL IS_ANY_OBJECT_NEAR_POINT(float x, float y, float z, float range, BOOL p4) { return invoke<BOOL>(0xC3CEDFD4651E42EC, x, y, z, range, p4); } // 0xC3CEDFD4651E42EC 0xE9E46941
	static BOOL IS_OBJECT_NEAR_POINT(Hash objectHash, float x, float y, float z, float range) { return invoke<BOOL>(0x60C5F2115CCF456F, objectHash, x, y, z, range); } // 0x60C5F2115CCF456F 0x50A62C43
	static void _0xC9BB66B382CBCBE7(Any p0) { invoke<Void>(0xC9BB66B382CBCBE7, p0); } // 0xC9BB66B382CBCBE7 0xE3261B35
	static void _0x23E3549861C69EEC(Object p0, Any p1, BOOL p2) { invoke<Void>(0x23E3549861C69EEC, p0, p1, p2); } // 0x23E3549861C69EEC 0x1E82C2AE
	static void _0x039A20AC705FA9B0(Object object) { invoke<Void>(0x039A20AC705FA9B0, object); } // 0x039A20AC705FA9B0
	static void TRACK_OBJECT_VISIBILITY(Any p0) { invoke<Void>(0xA8A81E4A8E21148C, p0); } // 0xA8A81E4A8E21148C 0x46D06B9A
	static BOOL IS_OBJECT_VISIBLE(Object object) { return invoke<BOOL>(0xC61161F0BC70D70C, object); } // 0xC61161F0BC70D70C 0xF4FD8AE4
	static void _0x583DEDE7E6A1F17F(Any p0, BOOL p1) { invoke<Void>(0x583DEDE7E6A1F17F, p0, p1); } // 0x583DEDE7E6A1F17F 0xF4A1A14A
	static void _0x47FF82DB1EB6DFBA(Any p0, BOOL p1) { invoke<Void>(0x47FF82DB1EB6DFBA, p0, p1); } // 0x47FF82DB1EB6DFBA 0xAF016CC1
	static void _0x0353644530C0AF5B(Any p0, BOOL p1) { invoke<Void>(0x0353644530C0AF5B, p0, p1); } // 0x0353644530C0AF5B 0x3A68AA46
	static Any _0x0CE2297975A4AE38(float x, float y, float z, float p3, char* p4) { return invoke<Any>(0x0CE2297975A4AE38, x, y, z, p3, p4); } // 0x0CE2297975A4AE38 0xA286DE96
	static void _0x08B6ECD80C6BD224(Any p0, Any p1) { invoke<Void>(0x08B6ECD80C6BD224, p0, p1); } // 0x08B6ECD80C6BD224 0x21F51560
	static Any _0x46995C6DD9E9DF8F(Any p0) { return invoke<Any>(0x46995C6DD9E9DF8F, p0); } // 0x46995C6DD9E9DF8F 0xF1B8817A
	static BOOL _0xF1DEF26108040848(Any p0) { return invoke<BOOL>(0xF1DEF26108040848, p0); } // 0xF1DEF26108040848 0xE08C834D
	static float _0xA89D6D3135E73E75(Any p0) { return invoke<float>(0xA89D6D3135E73E75, p0); } // 0xA89D6D3135E73E75 0x020497DE
	static Pickup CREATE_PICKUP(Hash pickupHash, float posX, float posY, float posZ, int p4, int value, BOOL p6, Hash modelHash) { return invoke<Pickup>(0xA26C2D9EE51CAC7D, pickupHash, posX, posY, posZ, p4, value, p6, modelHash); } // 0xA26C2D9EE51CAC7D 0x5E14DF68
	static Pickup CREATE_PICKUP_ROTATE(Hash pickupHash, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, int flag, int amount, Any p9, BOOL p10, Hash modelHash) { return invoke<Pickup>(0xC70DFF4A4A4D72AB, pickupHash, posX, posY, posZ, rotX, rotY, rotZ, flag, amount, p9, p10, modelHash); } // 0xC70DFF4A4A4D72AB 0xF015BFE2
	static Pickup CREATE_AMBIENT_PICKUP(Hash pickupHash, float posX, float posY, float posZ, int p4, int value, Hash modelHash, BOOL p7, BOOL p8) { return invoke<Pickup>(0xAB96B96F513DBFC2, pickupHash, posX, posY, posZ, p4, value, modelHash, p7, p8); } // 0xAB96B96F513DBFC2 0x17B99CE7
	static Pickup CREATE_PORTABLE_PICKUP(Hash pickupHash, float x, float y, float z, BOOL placeOnGround, Hash modelHash) { return invoke<Pickup>(0xD464E492B2F858BA, pickupHash, x, y, z, placeOnGround, modelHash); } // 0xD464E492B2F858BA 0x8C886BE5
	static Pickup _CREATE_PORTABLE_PICKUP_2(Hash pickupHash, float x, float y, float z, BOOL placeOnGround, Hash modelHash) { return invoke<Pickup>(0x3D954C61D9A76816, pickupHash, x, y, z, placeOnGround, modelHash); } // 0x3D954C61D9A76816 0x56A02502
	static void ATTACH_PORTABLE_PICKUP_TO_PED(Ped ped, Any p1) { invoke<Void>(0xD4F8A4FBC3ADDC64, ped, p1); } // 0xD4F8A4FBC3ADDC64 0x184F6AB3
	static void DETACH_PORTABLE_PICKUP_FROM_PED(Ped ped) { invoke<Void>(0x777AC67345D5B1EF, ped); } // 0x777AC67345D5B1EF 0x1D094562
	static void _0x465978A6A16264B0(Any p0, Any p1) { invoke<Void>(0x465978A6A16264B0, p0, p1); } // 0x465978A6A16264B0 0x7EFBA039
	static void _0x7FB3512FE15142C6(BOOL p0) { invoke<Void>(0x7FB3512FE15142C6, p0); } // 0x7FB3512FE15142C6 0xA3CDF152
	static Vector3 GET_SAFE_PICKUP_COORDS(float x, float y, float z, Any p3, Any p4) { return invoke<Vector3>(0x4751CE3168C7B4C6, x, y, z, p3, p4); } // 0x4751CE3168C7B4C6 0x618B5F67
	static Vector3 GET_PICKUP_COORDS(Any p0) { return invoke<Vector3>(0xE63C64081D02EFD3, p0); } // 0xE63C64081D02EFD3 0xC2E1E2C5
	static void REMOVE_ALL_PICKUPS_OF_TYPE(Any p0) { invoke<Void>(0x730185D28F9C0273, p0); } // 0x730185D28F9C0273 0x40062C53
	static BOOL HAS_PICKUP_BEEN_COLLECTED(Any p0) { return invoke<BOOL>(0x386274C5877FE8E9, p0); } // 0x386274C5877FE8E9 0x0BE5CCED
	static void REMOVE_PICKUP(Pickup pickup) { invoke<Void>(0xC2E11A6D29A07A71, pickup); } // 0xC2E11A6D29A07A71 0x64A7A0E0
	static void CREATE_MONEY_PICKUPS(float x, float y, float z, int value, int amount, Hash model) { invoke<Void>(0x75B6732706D6E111, x, y, z, value, amount, model); } // 0x75B6732706D6E111 0x36C9A5EA
	static BOOL DOES_PICKUP_EXIST(Any p0) { return invoke<BOOL>(0xAF6D1E258B973F1D, p0); } // 0xAF6D1E258B973F1D 0x9C6DA0B3
	static BOOL DOES_PICKUP_OBJECT_EXIST(Any p0) { return invoke<BOOL>(0x160653C8E405076A, p0); } // 0x160653C8E405076A 0xE0B32108
	static Object GET_PICKUP_OBJECT(Object object) { return invoke<Object>(0x936571E46A80DCC8, object); } // 0x936571E46A80DCC8 0x6052E62E
	static BOOL _0x82B033D2DA85DE6C(Any p0) { return invoke<BOOL>(0x82B033D2DA85DE6C, p0); } // 0x82B033D2DA85DE6C
	static BOOL _IS_PICKUP_WITHIN_RADIUS(Hash pickupHash, float x, float y, float z, float radius) { return invoke<BOOL>(0x472EA9BECFBD1A1B, pickupHash, x, y, z, radius); } // 0x472EA9BECFBD1A1B 0xF139681B
	static void SET_PICKUP_REGENERATION_TIME(Any p0, Any p1) { invoke<Void>(0x8BA6247807F803C9, p0, p1); } // 0x8BA6247807F803C9 0xAB11267D
	static void _0x22B080FDD555C5D2(Any p0, Any p1, BOOL p2) { invoke<Void>(0x22B080FDD555C5D2, p0, p1, p2); } // 0x22B080FDD555C5D2 0x7FADB4B9
	static void _0x5D35532177921090(Hash p0, BOOL p1) { invoke<Void>(0x5D35532177921090, p0, p1); } // 0x5D35532177921090 0x3A8F1BF7
	static void SET_TEAM_PICKUP_OBJECT(Any p0, Any p1, BOOL p2) { invoke<Void>(0x2418B8A9DEFC0C7B, p0, p1, p2); } // 0x2418B8A9DEFC0C7B 0x77687DC5
	static void _0x5C267611BDE8CBD8(Object object, BOOL p1, BOOL p2) { invoke<Void>(0x5C267611BDE8CBD8, object, p1, p2); } // 0x5C267611BDE8CBD8 0xCBB5F9B6
	static void _0x324259B412EF434C(Any p0, float p1, BOOL p2) { invoke<Void>(0x324259B412EF434C, p0, p1, p2); } // 0x324259B412EF434C 0x276A7807
	static Any _0x3E29CEE75A933B53(Any p0) { return invoke<Any>(0x3E29CEE75A933B53, p0); } // 0x3E29CEE75A933B53 0x000E92DC
	static void _0x9F5E3AF5DBC472AC(float p0) { invoke<Void>(0x9F5E3AF5DBC472AC, p0); } // 0x9F5E3AF5DBC472AC 0x9879AC51
	static void _0x40BA79DB60050CD6(BOOL p0) { invoke<Void>(0x40BA79DB60050CD6, p0); } // 0x40BA79DB60050CD6 0xDB18FA01
	static void _0x533A2A0C84A7B760(Any p0, Any p1) { invoke<Void>(0x533A2A0C84A7B760, p0, p1); } // 0x533A2A0C84A7B760 0xA7E936FD
	static void _0x3CE14912CC9DCE90() { invoke<Void>(0x3CE14912CC9DCE90); } // 0x3CE14912CC9DCE90 0xB241806C
	static void _0x5144912C58076DBD(Any p0) { invoke<Void>(0x5144912C58076DBD, p0); } // 0x5144912C58076DBD 0xD1BAAFB7
	static void _HIGHLIGHT_PLACEMENT_COORDS(float x, float y, float z, int colorIndex) { invoke<Void>(0x91E475883E42A2EF, x, y, z, colorIndex); } // 0x91E475883E42A2EF 0x63B02FAD
	static void _0x1D2BA3FE33F1A915(Object object, BOOL toggle) { invoke<Void>(0x1D2BA3FE33F1A915, object, toggle); } // 0x1D2BA3FE33F1A915 0x132B6D92
	static Hash _0xE3A479C3329DDB05(Pickup pickupHash) { return invoke<Hash>(0xE3A479C3329DDB05, pickupHash); } // 0xE3A479C3329DDB05 0xEDD01937
	static BOOL _0x818FB9816E7A31B1(Any p0) { return invoke<BOOL>(0x818FB9816E7A31B1, p0); } // 0x818FB9816E7A31B1
	static void _0x543E9E5FD3AF0BE6(Object object, int paintIndex) { invoke<Void>(0x543E9E5FD3AF0BE6, object, paintIndex); } // 0x543E9E5FD3AF0BE6
	static Hash _0x038ED6E06873F022(Pickup pickupHash) { return invoke<Hash>(0x038ED6E06873F022, pickupHash); } // 0x038ED6E06873F022 0x6AE36192
	static void SET_FORCE_OBJECT_THIS_FRAME(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x16D1B2F1369D2209, p0, p1, p2, p3); } // 0x16D1B2F1369D2209 0x3DA41C1A
	static void _MARK_OBJECT_FOR_DELETION(Object object) { invoke<Void>(0x6CCB4081AEF003A1, object); } // 0x6CCB4081AEF003A1 0x2048A7DD
}

namespace AI
{
	static void TASK_PAUSE(Ped ped, int ms) { invoke<Void>(0xC47A71ED8C26841E, ped, ms); } // 0xC47A71ED8C26841E 0x17A64668
	static void TASK_STAND_STILL(Ped ped, int time) { invoke<Void>(0x3C1C089273A382C6, ped, time); } // 0x3C1C089273A382C6 0x6F80965D
	static void TASK_JUMP(Ped ped, BOOL unused) { invoke<Void>(0xC2BC5F5C986BEB50, ped, unused); } // 0xC2BC5F5C986BEB50 0x0356E3CE
	static void TASK_COWER(Ped ped, int duration) { invoke<Void>(0x4E61D536D3C86A36, ped, duration); } // 0x4E61D536D3C86A36 0x9CF1C19B
	static void TASK_HANDS_UP(Ped ped, int duration, Ped facingPed, int p3, BOOL p4) { invoke<Void>(0xD3C1FC2A6E8F1095, ped, duration, facingPed, p3, p4); } // 0xD3C1FC2A6E8F1095 0x8DCC19C5
	static void UPDATE_TASK_HANDS_UP_DURATION(Ped ped, int duration) { invoke<Void>(0xB81A66FC0F60A73C, ped, duration); } // 0xB81A66FC0F60A73C 0x3AA39BE9
	static void TASK_OPEN_VEHICLE_DOOR(Ped ped, Vehicle vehicle, int timeOut, int doorIndex, float speed) { invoke<Void>(0x69838B389AD96639, ped, vehicle, timeOut, doorIndex, speed); } // 0x69838B389AD96639 0x8EE06BF4
	static void TASK_ENTER_VEHICLE(Ped ped, Vehicle vehicle, int timeout, int seat, float speed, int p5, Any p6) { invoke<Void>(0x3AD5401AC8DD9226, ped, vehicle, timeout, seat, speed, p5, p6); } // 0x3AD5401AC8DD9226 0xB8689B4E
	static void TASK_LEAVE_VEHICLE(Ped ped, Vehicle vehicle, int flags) { invoke<Void>(0x335F081010BB7A76, ped, vehicle, flags); } // 0x335F081010BB7A76 0x7B1141C6
	static void _TASK_GET_OFF_BOAT(Ped ped, Vehicle boat) { invoke<Void>(0x2C99C1BB792DF599, ped, boat); } // 0x2C99C1BB792DF599
	static void TASK_SKY_DIVE(Ped ped) { invoke<Void>(0x389752588E8E692A, ped); } // 0x389752588E8E692A 0xD3874AFA
	static void TASK_PARACHUTE(Ped ped, BOOL p1) { invoke<Void>(0x24C6759C05C6916A, ped, p1); } // 0x24C6759C05C6916A 0xEC3060A2
	static void TASK_PARACHUTE_TO_TARGET(Ped ped, float x, float y, float z) { invoke<Void>(0x1EC179729373784C, ped, x, y, z); } // 0x1EC179729373784C 0xE0104D6C
	static void SET_PARACHUTE_TASK_TARGET(Ped ped, float x, float y, float z) { invoke<Void>(0x158A4C1EA36ADC06, ped, x, y, z); } // 0x158A4C1EA36ADC06 0x6ED3AD81
	static void SET_PARACHUTE_TASK_THRUST(Ped ped, float thrust) { invoke<Void>(0xFF8EDA5CE91BBBDF, ped, thrust); } // 0xFF8EDA5CE91BBBDF 0xD07C8AAA
	static void TASK_RAPPEL_FROM_HELI(Ped ped, int p1) { invoke<Void>(0x345F865CA03656C0, ped, p1); } // 0x345F865CA03656C0 0x2C7ADB93
	static void TASK_VEHICLE_DRIVE_TO_COORD(Ped ped, Vehicle vehicle, float x, float y, float z, float speed, Any p6, Hash vehicleModel, int drivingMode, float stopRange, float p10) { invoke<Void>(0xBAEDE72EB6870B58, ped, vehicle, x, y, z, speed, p6, vehicleModel, drivingMode, stopRange, p10); } // 0xBAEDE72EB6870B58 0xE4AC0387
	static void TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(Ped ped, Vehicle vehicle, float x, float y, float z, float speed, int driveMode, float stopRange) { invoke<Void>(0x453B5A535815D9B2, ped, vehicle, x, y, z, speed, driveMode, stopRange); } // 0x453B5A535815D9B2 0x1490182A
	static void TASK_VEHICLE_DRIVE_WANDER(Ped ped, Vehicle vehicle, float speed, int drivingStyle) { invoke<Void>(0x9178B6CFE95D27C6, ped, vehicle, speed, drivingStyle); } // 0x9178B6CFE95D27C6 0x36EC0EB0
	static void TASK_FOLLOW_TO_OFFSET_OF_ENTITY(Ped ped, Entity entity, float offsetX, float offsetY, float offsetZ, float movementSpeed, int timeout, float stoppingRange, BOOL persistFollowing) { invoke<Void>(0x8C17F851E89377D3, ped, entity, offsetX, offsetY, offsetZ, movementSpeed, timeout, stoppingRange, persistFollowing); } // 0x8C17F851E89377D3 0x2DF5A6AC
	static void TASK_GO_STRAIGHT_TO_COORD(Ped ped, float x, float y, float z, float speed, int timeout, float targetHeading, float distanceToSlide) { invoke<Void>(0x9C16B2DABAEC929A, ped, x, y, z, speed, timeout, targetHeading, distanceToSlide); } // 0x9C16B2DABAEC929A 0x80A9E7A7
	static void TASK_GO_STRAIGHT_TO_COORD_RELATIVE_TO_ENTITY(Entity entity1, Entity entity2, float p2, float p3, float p4, float p5, Any p6) { invoke<Void>(0x040C07F4080E9D76, entity1, entity2, p2, p3, p4, p5, p6); } // 0x040C07F4080E9D76 0xD26CAC68
	static void TASK_ACHIEVE_HEADING(Ped ped, float heading, int timeout) { invoke<Void>(0x3DB139C144156433, ped, heading, timeout); } // 0x3DB139C144156433 0x0A0E9B42
	static void TASK_FLUSH_ROUTE() { invoke<Void>(0x154D082BE4DC4B50); } // 0x154D082BE4DC4B50 0x34219154
	static void TASK_EXTEND_ROUTE(float x, float y, float z) { invoke<Void>(0xEAB20ED19F0246DA, x, y, z); } // 0xEAB20ED19F0246DA 0x43271F69
	static void TASK_FOLLOW_POINT_ROUTE(Ped ped, float speed, int unknown) { invoke<Void>(0x9270EC8721D41D7B, ped, speed, unknown); } // 0x9270EC8721D41D7B 0xB837C816
	static void TASK_GO_TO_ENTITY(Entity entity, Entity target, int duration, float distance, float speed, float p5, int p6) { invoke<Void>(0x834EF3BF2E6A8D29, entity, target, duration, distance, speed, p5, p6); } // 0x834EF3BF2E6A8D29 0x374827C2
	static void TASK_SMART_FLEE_COORD(Ped ped, float x, float y, float z, float distance, int time, BOOL p6, BOOL p7) { invoke<Void>(0x9145194A1B6CD65A, ped, x, y, z, distance, time, p6, p7); } // 0x9145194A1B6CD65A 0xB2E686FC
	static void TASK_SMART_FLEE_PED(Ped ped, Ped fleeTarget, float distance, Any fleeTime, BOOL p4, BOOL p5) { invoke<Void>(0xCA58071CE9CCE891, ped, fleeTarget, distance, fleeTime, p4, p5); } // 0xCA58071CE9CCE891 0xE52EB560
	static void TASK_REACT_AND_FLEE_PED(Ped ped, Ped fleeTarget) { invoke<Void>(0x294B6C1FB03E36A9, ped, fleeTarget); } // 0x294B6C1FB03E36A9 0x8A632BD8
	static void TASK_SHOCKING_EVENT_REACT(Ped ped, int eventHandle) { invoke<Void>(0xF4ADF7733B61864A, ped, eventHandle); } // 0xF4ADF7733B61864A 0x9BD00ACF
	static void TASK_WANDER_IN_AREA(Ped ped, float x, float y, float z, float radius, float minimalLength, float timeBetweenWalks) { invoke<Void>(0x0D74267B5DF3F6A3, ped, x, y, z, radius, minimalLength, timeBetweenWalks); } // 0x0D74267B5DF3F6A3 0xC6981FB9
	static void TASK_WANDER_STANDARD(Ped ped, float p1, int p2) { invoke<Void>(0x401B18D8E7BEEC86, ped, p1, p2); } // 0x401B18D8E7BEEC86 0xAF59151A
	static void TASK_VEHICLE_PARK(Ped ped, Vehicle vehicle, float x, float y, float z, float heading, int mode, float radius, BOOL keepEngineOn) { invoke<Void>(0x70DC8522F2481F7F, ped, vehicle, x, y, z, heading, mode, radius, keepEngineOn); } // 0x70DC8522F2481F7F 0x5C85FF90
	static void TASK_STEALTH_KILL(Ped killer, Ped target, Hash killType, float p3, BOOL p4) { invoke<Void>(0x53343E4075E45CE4, killer, target, killType, p3, p4); } // 0x53343E4075E45CE4 0x0D64C2FA
	static void TASK_PLANT_BOMB(Ped ped, float x, float y, float z, float heading) { invoke<Void>(0x6841D139FC4E4697, ped, x, y, z, heading); } // 0x6841D139FC4E4697 0x33457535
	static void TASK_FOLLOW_NAV_MESH_TO_COORD(Ped ped, float x, float y, float z, float speed, int timeout, float stoppingRange, BOOL persistFollowing, float unk) { invoke<Void>(0x084522380FECC554, ped, x, y, z, speed, timeout, stoppingRange, persistFollowing, unk); } // 0x084522380FECC554 0xFE4A10D9
	static void TASK_FOLLOW_NAV_MESH_TO_COORD_ADVANCED(Ped ped, float x, float y, float z, float speed, int timeout, float unkFloat, int unkInt, float unkX, float unkY, float unkZ, float unk_40000f) { invoke<Void>(0x630644C1D3612175, ped, x, y, z, speed, timeout, unkFloat, unkInt, unkX, unkY, unkZ, unk_40000f); } // 0x630644C1D3612175 0x6BF6E296
	static void SET_PED_PATH_CAN_USE_CLIMBOVERS(Ped ped, BOOL Toggle) { invoke<Void>(0x6C6C9684BB95A6C5, ped, Toggle); } // 0x6C6C9684BB95A6C5 0xB7B7D442
	static void SET_PED_PATH_CAN_USE_LADDERS(Ped ped, BOOL Toggle) { invoke<Void>(0x652C108992DBE98F, ped, Toggle); } // 0x652C108992DBE98F 0x53A879EE
	static void SET_PED_PATH_CAN_DROP_FROM_HEIGHT(Ped ped, BOOL Toggle) { invoke<Void>(0x84E4BE19D702B6C5, ped, Toggle); } // 0x84E4BE19D702B6C5 0x394B7AC9
	static void _0x1BF805AC60AE224D(Ped ped, float p1) { invoke<Void>(0x1BF805AC60AE224D, ped, p1); } // 0x1BF805AC60AE224D 0x55E06443
	static void SET_PED_PATHS_WIDTH_PLANT(Ped ped, BOOL mayEnterWater) { invoke<Void>(0xD58AE07026EDCFAE, ped, mayEnterWater); } // 0xD58AE07026EDCFAE 0x9C606EE3
	static void SET_PED_PATH_PREFER_TO_AVOID_WATER(Ped ped, BOOL avoidWater) { invoke<Void>(0xAC81755AD10CE43D, ped, avoidWater); } // 0xAC81755AD10CE43D 0x0EA39A29
	static void SET_PED_PATH_AVOID_FIRE(Ped ped, BOOL avoidFire) { invoke<Void>(0x1654F934DC232402, ped, avoidFire); } // 0x1654F934DC232402 0xDCC5B934
	static void SET_GLOBAL_MIN_BIRD_FLIGHT_HEIGHT(float height) { invoke<Void>(0x05E1966C6465CD81, height); } // 0x05E1966C6465CD81 0x2AFB14B8
	static Any GET_NAVMESH_ROUTE_DISTANCE_REMAINING(Ped ped, Any* p1, Any* p2) { return invoke<Any>(0x4047DA6FF4A46779, ped, p1, p2); } // 0x4047DA6FF4A46779 0xD9281778
	static Any GET_NAVMESH_ROUTE_RESULT(Any p0) { return invoke<Any>(0x1D32F16C34EF33B4, p0); } // 0x1D32F16C34EF33B4 0x96491602
	static BOOL _0x7D5EA06CFA62662B(Any p0) { return invoke<BOOL>(0x7D5EA06CFA62662B, p0); } // 0x7D5EA06CFA62662B
	static void TASK_GO_TO_COORD_ANY_MEANS(Ped ped, float x, float y, float z, float speed, Any p5, BOOL p6, int walkingStyle, float p8) { invoke<Void>(0x26AB82CDFC655AC9, ped, x, y, z, speed, p5, p6, walkingStyle, p8); } // 0x26AB82CDFC655AC9 0xF91DF93B
	static void TASK_GO_TO_COORD_ANY_MEANS_EXTRA_PARAMS(Ped ped, float x, float y, float z, float speed, Any p5, BOOL p6, int walkingStyle, float p8, Any p9, Any p10, Any p11) { invoke<Void>(0x7E08FEC6DCA38B0D, ped, x, y, z, speed, p5, p6, walkingStyle, p8, p9, p10, p11); } // 0x7E08FEC6DCA38B0D 0x094B75EF
	static void TASK_GO_TO_COORD_ANY_MEANS_EXTRA_PARAMS_WITH_CRUISE_SPEED(Ped ped, float x, float y, float z, float speed, Any p5, BOOL p6, int walkingStyle, float p8, Any p9, Any p10, Any p11, Any p12) { invoke<Void>(0x6BBCE67E66A4BF21, ped, x, y, z, speed, p5, p6, walkingStyle, p8, p9, p10, p11, p12); } // 0x6BBCE67E66A4BF21 0x86DC03F9
	static void TASK_PLAY_ANIM(Ped ped, char* animDictionary, char* animationName, float speed, float speedMultiplier, int duration, int flag, float playbackRate, BOOL lockX, BOOL lockY, BOOL lockZ) { invoke<Void>(0xEB1EFACA68933402, ped, animDictionary, animationName, speed, speedMultiplier, duration, flag, playbackRate, lockX, lockY, lockZ); } // 0xEB1EFACA68933402 0x5AB552C6
	static void TASK_PLAY_ANIM_ADVANCED(Ped ped, char* animDict, char* animName, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float speed, float speedMultiplier, int duration, Any flag, float animTime, Any p14, Any p15) { invoke<Void>(0x8EBCA87389C95125, ped, animDict, animName, posX, posY, posZ, rotX, rotY, rotZ, speed, speedMultiplier, duration, flag, animTime, p14, p15); } // 0x8EBCA87389C95125 0x3DDEB0E6
	static void STOP_ANIM_TASK(Ped ped, char* animDictionary, char* animationName, float p3) { invoke<Void>(0xA587396DD8FB936E, ped, animDictionary, animationName, p3); } // 0xA587396DD8FB936E 0x2B520A57
	static void TASK_SCRIPTED_ANIMATION(Ped ped, Any* p1, Any* p2, Any* p3, float p4, float p5) { invoke<Void>(0x411FA221C02D6DE8, ped, p1, p2, p3, p4, p5); } // 0x411FA221C02D6DE8 0xFC2DCF47
	static void PLAY_ENTITY_SCRIPTED_ANIM(Any p0, Any* p1, Any* p2, Any* p3, float p4, float p5) { invoke<Void>(0x32162BD58B829EF2, p0, p1, p2, p3, p4, p5); } // 0x32162BD58B829EF2 0x02F72AE5
	static void STOP_ANIM_PLAYBACK(Ped ped, Any p1, BOOL p2) { invoke<Void>(0xF975837A072E320C, ped, p1, p2); } // 0xF975837A072E320C 0xE5F16398
	static void SET_ANIM_WEIGHT(Any p0, float p1, Any p2, Any p3, BOOL p4) { invoke<Void>(0x61B27C230F6FAF4A, p0, p1, p2, p3, p4); } // 0x61B27C230F6FAF4A 0x17229D98
	static void SET_ANIM_RATE(Any p0, float p1, Any p2, BOOL p3) { invoke<Void>(0xD1B387C9CDC557AD, p0, p1, p2, p3); } // 0xD1B387C9CDC557AD 0x6DB46584
	static void SET_ANIM_LOOPED(Any p0, BOOL p1, Any p2, BOOL p3) { invoke<Void>(0x46E7D9C7FA4FE6F1, p0, p1, p2, p3); } // 0x46E7D9C7FA4FE6F1 0x095D61A4
	static void TASK_PLAY_PHONE_GESTURE_ANIMATION(Ped p0, Any* p1, Any* p2, Any* p3, float p4, float p5, BOOL p6, BOOL p7) { invoke<Void>(0xB685B0518D51C972, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xB685B0518D51C972 0x1582162C
	static void _TASK_STOP_PHONE_GESTURE_ANIMATION(Ped ped) { invoke<Void>(0x9D01E991DCC4CA64, ped); } // 0x9D01E991DCC4CA64
	static BOOL IS_PLAYING_PHONE_GESTURE_ANIM(Ped ped) { return invoke<BOOL>(0x303A138A88BE7640, ped); } // 0x303A138A88BE7640 0x500B6805
	static float GET_PHONE_GESTURE_ANIM_CURRENT_TIME(Ped ped) { return invoke<float>(0x141016789DEA34B5, ped); } // 0x141016789DEA34B5 0x7B72AFD1
	static float GET_PHONE_GESTURE_ANIM_TOTAL_TIME(Ped ped) { return invoke<float>(0x6ADF68F981B16DC2, ped); } // 0x6ADF68F981B16DC2 0xEF8C3959
	static void TASK_VEHICLE_PLAY_ANIM(Vehicle vehicle, char* animation_set, char* animation_name) { invoke<Void>(0x0F54253A1DFBE9B0, vehicle, animation_set, animation_name); } // 0x0F54253A1DFBE9B0 0x2B28F598
	static void TASK_LOOK_AT_COORD(Entity entity, float x, float y, float z, float duration, Any p5, Any p6) { invoke<Void>(0x0D322CDF37087C0E, entity, x, y, z, duration, p5, p6); } // 0x0D322CDF37087C0E 0x7B784DD8
	static void TASK_LOOK_AT_ENTITY(Ped ped, Entity lookAt, int duration, int unknown1, int unknown2) { invoke<Void>(0x4718A774D9248520, ped, lookAt, duration, unknown1, unknown2); } // 0x4718A774D9248520 0x991D6619
	static void TASK_CLEAR_LOOK_AT(Ped ped) { invoke<Void>(0xEF9294ED57E4AC3D, ped); } // 0xEF9294ED57E4AC3D 0x60EB4054
	static void OPEN_SEQUENCE_TASK(Object* taskSequence) { invoke<Void>(0x86DD54980FE55567, taskSequence); } // 0x86DD54980FE55567 0xABA6923E
	static void CLOSE_SEQUENCE_TASK(Object taskSequence) { invoke<Void>(0x007AE2AA9E15FA7B, taskSequence); } // 0x007AE2AA9E15FA7B 0x1A7CEBD0
	static void TASK_PERFORM_SEQUENCE(Ped ped, Object taskSequence) { invoke<Void>(0x00E85C3B3BD34B10, ped, taskSequence); } // 0x00E85C3B3BD34B10 0x4D9FBD11
	static void CLEAR_SEQUENCE_TASK(Object* taskSequence) { invoke<Void>(0x08377FB2AE4C6899, taskSequence); } // 0x08377FB2AE4C6899 0x47ED03CE
	static void SET_SEQUENCE_TO_REPEAT(Object taskSequence, BOOL repeat) { invoke<Void>(0x85111902FC00A5CF, taskSequence, repeat); } // 0x85111902FC00A5CF 0xCDDF1508
	static int GET_SEQUENCE_PROGRESS(Ped ped) { return invoke<int>(0x408A2D0FD72AD367, ped); } // 0x408A2D0FD72AD367 0xA3419909
	static BOOL GET_IS_TASK_ACTIVE(Ped ped, int taskNumber) { return invoke<BOOL>(0x8B41403849A60C7C, ped, taskNumber); } // 0x8B41403849A60C7C 0x86FDDF55
	static int GET_SCRIPT_TASK_STATUS(Ped targetPed, Hash taskHash) { return invoke<int>(0x1F8F07D86DA1A701, targetPed, taskHash); } // 0x1F8F07D86DA1A701 0xB2477B23
	static int GET_ACTIVE_VEHICLE_MISSION_TYPE(Vehicle veh) { return invoke<int>(0xE4C8471DA664578A, veh); } // 0xE4C8471DA664578A 0xAFA914EF
	static void TASK_LEAVE_ANY_VEHICLE(Ped ped, int p1, int p2) { invoke<Void>(0x83150B7E65C16AFE, ped, p1, p2); } // 0x83150B7E65C16AFE 0xDBDD79FA
	static void TASK_AIM_GUN_SCRIPTED(Ped ped, Hash scriptTask, BOOL p2, BOOL p3) { invoke<Void>(0x25DECB57013B13FB, ped, scriptTask, p2, p3); } // 0x25DECB57013B13FB 0x9D296BCD
	static void TASK_AIM_GUN_SCRIPTED_WITH_TARGET(Any p0, Any p1, float p2, float p3, float p4, Any p5, BOOL p6, BOOL p7) { invoke<Void>(0xAC65F370F4B2B387, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xAC65F370F4B2B387 0xFD517CE3
	static void UPDATE_TASK_AIM_GUN_SCRIPTED_TARGET(Ped p0, Ped p1, float p2, float p3, float p4, BOOL p5) { invoke<Void>(0xADCC53A17278DA08, p0, p1, p2, p3, p4, p5); } // 0xADCC53A17278DA08 0x67E73525
	static Any GET_CLIP_SET_FOR_SCRIPTED_GUN_TASK(Any p0) { return invoke<Any>(0x3ED4CAEAB321BEC0, p0); } // 0x3ED4CAEAB321BEC0 0x249EB4EB
	static void TASK_AIM_GUN_AT_ENTITY(Ped ped, Entity entity, int duration, BOOL p3) { invoke<Void>(0xC62C6BBB860531B7, ped, entity, duration, p3); } // 0xC62C6BBB860531B7 0xBE32B3B6
	static void TASK_TURN_PED_TO_FACE_ENTITY(Ped ped, Entity entity, int duration) { invoke<Void>(0x6349785089ED32B4, ped, entity, duration); } // 0x6349785089ED32B4 0x3C37C767
	static void TASK_AIM_GUN_AT_COORD(Ped ped, float x, float y, float z, int time, BOOL p5, BOOL p6) { invoke<Void>(0x25EEB78469C970E2, ped, x, y, z, time, p5, p6); } // 0x25EEB78469C970E2 0xFBF44AD3
	static void TASK_SHOOT_AT_COORD(Ped ped, float x, float y, float z, int duration, Hash firingPattern) { invoke<Void>(0x2B70C536A23BC2E6, ped, x, y, z, duration, firingPattern); } // 0x2B70C536A23BC2E6 0x601C22E3
	static void TASK_SHUFFLE_TO_NEXT_VEHICLE_SEAT(Ped ped, Vehicle vehicle) { invoke<Void>(0xB095A8770515915B, ped, vehicle); } // 0xB095A8770515915B 0xBEAF8F67
	static void CLEAR_PED_TASKS(Ped ped) { invoke<Void>(0x15848523A8959DBC, ped); } // 0x15848523A8959DBC 0xDE3316AB
	static void CLEAR_PED_SECONDARY_TASK(Ped ped) { invoke<Void>(0xFFAC04A19BFE8F03, ped); } // 0xFFAC04A19BFE8F03 0xA635F451
	static void TASK_EVERYONE_LEAVE_VEHICLE(Vehicle vehicle) { invoke<Void>(0xBA212BF07E50652E, vehicle); } // 0xBA212BF07E50652E 0xC1971F30
	static void TASK_GOTO_ENTITY_OFFSET(Ped ped, Any p1, Any p2, float x, float y, float z, int duration) { invoke<Void>(0x1195B021D7C2C096, ped, p1, p2, x, y, z, duration); } // 0x1195B021D7C2C096 0x1A17A85E
	static void TASK_GOTO_ENTITY_OFFSET_XY(Any p0, Any p1, Any p2, float p3, float p4, float p5, float p6, Any p7) { invoke<Void>(0x58C48177956BB59A, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x58C48177956BB59A 0xBC1E3D0A
	static void TASK_TURN_PED_TO_FACE_COORD(Ped ped, float x, float y, float z, int duration) { invoke<Void>(0x9F7BF6124414BCF4, ped, x, y, z, duration); } // 0x9F7BF6124414BCF4 0x30463D73
	static void TASK_VEHICLE_TEMP_ACTION(Ped driver, Vehicle vehicle, int action, int time) { invoke<Void>(0x736D228B743132A9, driver, vehicle, action, time); } // 0x736D228B743132A9 0x0679DFB8
	static void TASK_VEHICLE_MISSION(Any p0, Any p1, Any p2, Any p3, float p4, Any p5, float p6, float p7, BOOL p8) { invoke<Void>(0x398C18AE22628160, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x398C18AE22628160 0x20609E56
	static void TASK_VEHICLE_MISSION_PED_TARGET(Ped ped, Vehicle vehicle, Ped pedTarget, int mode, float maxSpeed, int drivingStyle, float minDistance, float p7, BOOL p8) { invoke<Void>(0xA0F84EA3D7C06982, ped, vehicle, pedTarget, mode, maxSpeed, drivingStyle, minDistance, p7, p8); } // 0xA0F84EA3D7C06982 0xC81C4677
	static void TASK_VEHICLE_MISSION_COORS_TARGET(Ped ped, Vehicle vehicle, float x, float Y, float Z, int p5, int p6, int p7, float p8, float p9, BOOL p10) { invoke<Void>(0x83315F81FAC58A20, ped, vehicle, x, Y, Z, p5, p6, p7, p8, p9, p10); } // 0x83315F81FAC58A20 0x6719C109
	static void TASK_VEHICLE_ESCORT(Ped ped, Vehicle vehicle, Vehicle targetVehicle, int mode, float speed, int drivingStyle, float minDistance, int p7, float noRoadsDistance) { invoke<Void>(0x1201F00D632D3F42, ped, vehicle, targetVehicle, mode, speed, drivingStyle, minDistance, p7, noRoadsDistance); } // 0x1201F00D632D3F42 0x9FDCB250
	static void _TASK_VEHICLE_FOLLOW(Ped driver, Vehicle vehicle, Entity targetEntity, int drivingStyle, float speed, int minDistance) { invoke<Void>(0xDE2E29FAA19823DF, driver, vehicle, targetEntity, drivingStyle, speed, minDistance); } // 0xDE2E29FAA19823DF
	static void TASK_VEHICLE_CHASE(Ped driver, Entity targetEnt) { invoke<Void>(0x8E7C2B2C204E1ECE, driver, targetEnt); } // 0x8E7C2B2C204E1ECE 0x55634798
	static void TASK_VEHICLE_HELI_PROTECT(Ped pilot, Vehicle vehicle, Entity entityToFollow, float targetSpeed, int p4, float radius, int altitude, int p7) { invoke<Void>(0xDD3FEC35F7C04914, pilot, vehicle, entityToFollow, targetSpeed, p4, radius, altitude, p7); } // 0xDD3FEC35F7C04914 0x0CB415EE
	static void SET_TASK_VEHICLE_CHASE_BEHAVIOR_FLAG(Ped ped, int flag, BOOL set) { invoke<Void>(0x467E3CFB2AB25B39, ped, flag, set); } // 0x467E3CFB2AB25B39 0x2A83083F
	static void SET_TASK_VEHICLE_CHASE_IDEAL_PURSUIT_DISTANCE(Ped ped, float distance) { invoke<Void>(0xB6411CD8BE9F4E4A, ped, distance); } // 0xB6411CD8BE9F4E4A 0x04FD3EE7
	static void TASK_HELI_CHASE(Ped pilot, Entity entityToFollow, float x, float y, float z) { invoke<Void>(0x49A98E1DB376E4FF, pilot, entityToFollow, x, y, z); } // 0x49A98E1DB376E4FF 0xAC290A21
	static void TASK_PLANE_CHASE(Ped pilot, Entity entityToFollow, float x, float y, float z) { invoke<Void>(0x91EEE9F4E1B9AE4B, pilot, entityToFollow, x, y, z); } // 0x91EEE9F4E1B9AE4B 0x12FA1C28
	static void TASK_PLANE_LAND(Ped pilot, Vehicle plane, float runwayStartX, float runwayStartY, float runwayStartZ, float runwayEndX, float runwayEndY, float runwayEndZ) { invoke<Void>(0xF1129B75FA51A2FA, pilot, plane, runwayStartX, runwayStartY, runwayStartZ, runwayEndX, runwayEndY, runwayEndZ); } // 0xF1129B75FA51A2FA 0x5F7E23EA
	static void TASK_HELI_MISSION(Ped pilot, Vehicle vehicle, Any p2, Ped pedToFollow, float posX, float posY, float posZ, int mode, float speed, float radius, float angle, int p11, int height, float p13, int p14) { invoke<Void>(0xEBB24586B2E08B0B, pilot, vehicle, p2, pedToFollow, posX, posY, posZ, mode, speed, radius, angle, p11, height, p13, p14); } // 0xEBB24586B2E08B0B 0x0C143E97
	static void TASK_PLANE_MISSION(Ped pilot, Vehicle plane, Vehicle targetVehicle, Ped targetPed, float destinationX, float destinationY, float destinationZ, int p7, float physicsSpeed, float p9, float p10, float maxAltitude, float minAltitude) { invoke<Void>(0x5C61DA9E5FA9C0BF, pilot, plane, targetVehicle, targetPed, destinationX, destinationY, destinationZ, p7, physicsSpeed, p9, p10, maxAltitude, minAltitude); } // 0x5C61DA9E5FA9C0BF 0x1D007E65
	static void TASK_BOAT_MISSION(Ped pedDriver, Vehicle boat, Any p2, Any p3, float x, float y, float z, Any p7, float maxSpeed, Any p9, float p10, Any p11) { invoke<Void>(0x3F47F8044B9734ED, pedDriver, boat, p2, p3, x, y, z, p7, maxSpeed, p9, p10, p11); } // 0x3F47F8044B9734ED 0x5865B031
	static void TASK_DRIVE_BY(Ped p0, Ped targetPed, Any p2, float targetX, float targetY, float targetZ, float p6, Any p7, BOOL p8, Hash firingPattern) { invoke<Void>(0xBF17D64933EE9BE1, p0, targetPed, p2, targetX, targetY, targetZ, p6, p7, p8, firingPattern); } // 0xBF17D64933EE9BE1 0x2B84D1C4
	static void SET_DRIVEBY_TASK_TARGET(Any p0, Any p1, Any p2, float p3, float p4, float p5) { invoke<Void>(0x46312DA45092CB07, p0, p1, p2, p3, p4, p5); } // 0x46312DA45092CB07 0xDA6A6FC1
	static void CLEAR_DRIVEBY_TASK_UNDERNEATH_DRIVING_TASK(Ped ped) { invoke<Void>(0x49A6F5684562AD2E, ped); } // 0x49A6F5684562AD2E 0x9B76F7E6
	static BOOL IS_DRIVEBY_TASK_UNDERNEATH_DRIVING_TASK(Ped ped) { return invoke<BOOL>(0x6FF116803583BC8B, ped); } // 0x6FF116803583BC8B 0xB23F46E6
	static BOOL CONTROL_MOUNTED_WEAPON(Ped ped) { return invoke<BOOL>(0x1ADAB058F94C946F, ped); } // 0x1ADAB058F94C946F 0x500D9244
	static void SET_MOUNTED_WEAPON_TARGET(Ped shootingPed, Entity targetEntity, Any p2, float x, float y, float z) { invoke<Void>(0xC5BC2C0462EB59C8, shootingPed, targetEntity, p2, x, y, z); } // 0xC5BC2C0462EB59C8 0x98713C68
	static BOOL IS_MOUNTED_WEAPON_TASK_UNDERNEATH_DRIVING_TASK(Ped ped) { return invoke<BOOL>(0x9AA4DA70B5E6642E, ped); } // 0x9AA4DA70B5E6642E 0x291E938C
	static void TASK_USE_MOBILE_PHONE(Ped ped, int p1) { invoke<Void>(0xD11C043590A1D7B7, ped, p1); } // 0xD11C043590A1D7B7 0x225A38C8
	static void TASK_USE_MOBILE_PHONE_TIMED(Ped ped, int duration) { invoke<Void>(0x61B5A2C8D0F2B440, ped, duration); } // 0x61B5A2C8D0F2B440 0xC99C19F5
	static void TASK_CHAT_TO_PED(Ped ped, Ped target, Any p2, float p3, float p4, float p5, float p6, float p7) { invoke<Void>(0xCD9701056CF2C3B8, ped, target, p2, p3, p4, p5, p6, p7); } // 0xCD9701056CF2C3B8 0xA2BE1821
	static void TASK_WARP_PED_INTO_VEHICLE(Ped ped, Vehicle vehicle, int seat) { invoke<Void>(0xD7BA11D891FF0E6C, ped, vehicle, seat); } // 0xD7BA11D891FF0E6C 0x65D4A35D
	static void TASK_SHOOT_AT_ENTITY(Entity entity, Entity target, int duration, Hash firingPattern) { invoke<Void>(0x53A7EEA1A2E4F1C3, entity, target, duration, firingPattern); } // 0x53A7EEA1A2E4F1C3 0xAC0631C9
	static void TASK_CLIMB(Ped ped, BOOL unused) { invoke<Void>(0xB7B69838798170D4, ped, unused); } // 0xB7B69838798170D4 0x90847790
	static void TASK_CLIMB_LADDER(Ped ped, int p1) { invoke<Void>(0xEB35FC8B6C7E0BC7, ped, p1); } // 0xEB35FC8B6C7E0BC7 0x35BB4EE0
	static void CLEAR_PED_TASKS_IMMEDIATELY(Ped ped) { invoke<Void>(0xBC8C26E1CC191108, ped); } // 0xBC8C26E1CC191108 0xBC045625
	static void TASK_PERFORM_SEQUENCE_FROM_PROGRESS(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0xA970B75D453FE5D1, p0, p1, p2, p3); } // 0xA970B75D453FE5D1 0xFA60601B
	static void SET_NEXT_DESIRED_MOVE_STATE(Any p0) { invoke<Void>(0x13F7E8257DEC9897, p0); } // 0x13F7E8257DEC9897 0x4E937D57
	static void SET_PED_DESIRED_MOVE_BLEND_RATIO(Ped ped, float p1) { invoke<Void>(0x4447B5BB07E71D5A, ped, p1); } // 0x4447B5BB07E71D5A 0xC65FC712
	static float GET_PED_DESIRED_MOVE_BLEND_RATIO(Ped ped) { return invoke<float>(0x95884C7BF6EC7C01, ped); } // 0x95884C7BF6EC7C01 0x5FEFAB72
	static void TASK_GOTO_ENTITY_AIMING(Ped ped, Entity target, float distanceToStopAt, float StartAimingDist) { invoke<Void>(0x7D3B254DDEADA43C, ped, target, distanceToStopAt, StartAimingDist); } // 0x7D3B254DDEADA43C 0xF1C493CF
	static void TASK_SET_DECISION_MAKER(Ped p0, Hash p1) { invoke<Void>(0x62096F14272BAF35, p0, p1); } // 0x62096F14272BAF35 0x830AD50C
	static void TASK_SET_SPHERE_DEFENSIVE_AREA(Any p0, float p1, float p2, float p3, float p4) { invoke<Void>(0x34BD4F801E611586, p0, p1, p2, p3, p4); } // 0x34BD4F801E611586 0x9F3C5D6A
	static void TASK_CLEAR_DEFENSIVE_AREA(Any p0) { invoke<Void>(0x489EC42A4411CC78, p0); } // 0x489EC42A4411CC78 0x7A05BF0D
	static void TASK_PED_SLIDE_TO_COORD(Ped ped, float x, float y, float z, float heading, float p5) { invoke<Void>(0x80DF1844839BB179, ped, x, y, z, heading, p5); } // 0x80DF1844839BB179 0x225380EF
	static void TASK_PED_SLIDE_TO_COORD_HDG_RATE(Ped ped, float x, float y, float z, float heading, float p5, float p6) { invoke<Void>(0x6C2ADB6BAF811E6C, ped, x, y, z, heading, p5, p6); } // 0x6C2ADB6BAF811E6C 0x38A995C1
	static ScrHandle ADD_COVER_POINT(float p0, float p1, float p2, float p3, Any p4, Any p5, Any p6, BOOL p7) { return invoke<ScrHandle>(0x97207FD64FD2E87E, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x97207FD64FD2E87E 0xA0AF0B98
	static void REMOVE_COVER_POINT(ScrHandle coverpoint) { invoke<Void>(0xD6E89188FF81D5E9, coverpoint); } // 0xD6E89188FF81D5E9 0x0776888B
	static BOOL DOES_SCRIPTED_COVER_POINT_EXIST_AT_COORDS(float x, float y, float z) { return invoke<BOOL>(0x24880E015BEC7CEE, x, y, z); } // 0x24880E015BEC7CEE 0x29F97A71
	static Vector3 GET_SCRIPTED_COVER_POINT_COORDS(ScrHandle coverpoint) { return invoke<Vector3>(0xA64B92AE48696BD9, coverpoint); } // 0xA64B92AE48696BD9 0xC6B6CCC1
	static void TASK_COMBAT_PED(Ped ped, Ped targetPed, int p2, int p3) { invoke<Void>(0x7DD7196E1A0C1D43, ped, targetPed, p2, p3); } // 0x7DD7196E1A0C1D43 0xCB0D8932
	static void TASK_COMBAT_PED_TIMED(Any p0, Ped ped, int p2, Any p3) { invoke<Void>(0xC1A77152B8B354C0, p0, ped, p2, p3); } // 0xC1A77152B8B354C0 0xF5CA2A45
	static void TASK_SEEK_COVER_FROM_POS(Any p0, float p1, float p2, float p3, Any p4, BOOL p5) { invoke<Void>(0xE3E64D357F98D969, p0, p1, p2, p3, p4, p5); } // 0xE3E64D357F98D969 0x83F18EE9
	static void TASK_SEEK_COVER_FROM_PED(Ped ped, Ped target, int duration, BOOL p3) { invoke<Void>(0xA5D296AB6DFDEA70, ped, target, duration, p3); } // 0xA5D296AB6DFDEA70 0xC1EC907E
	static void TASK_SEEK_COVER_TO_COVER_POINT(Any p0, Any p1, float p2, float p3, float p4, Any p5, BOOL p6) { invoke<Void>(0x24457948E05FB2A8, p0, p1, p2, p3, p4, p5, p6); } // 0x24457948E05FB2A8 0x3D026B29
	static void TASK_SEEK_COVER_TO_COORDS(Ped ped, float x1, float y1, float z1, float x2, float y2, float z2, Any p7, BOOL p8) { invoke<Void>(0xD3E89D00CD7FD656, ped, x1, y1, z1, x2, y2, z2, p7, p8); } // 0xD3E89D00CD7FD656 0xFFFE754E
	static void TASK_PUT_PED_DIRECTLY_INTO_COVER(Ped ped, float x, float y, float z, Any timeout, BOOL p5, float p6, BOOL p7, BOOL p8, Any p9, BOOL p10) { invoke<Void>(0xDC4F16C663A04D64, ped, x, y, z, timeout, p5, p6, p7, p8, p9, p10); } // 0xDC4F16C663A04D64 0xC9F00E68
	static void TASK_EXIT_COVER(Any p0, Any p1, float p2, float p3, float p4) { invoke<Void>(0x393FC49A97A0A30B, p0, p1, p2, p3, p4); } // 0x393FC49A97A0A30B 0xC829FAC9
	static void TASK_PUT_PED_DIRECTLY_INTO_MELEE(Ped ped, Ped meleeTarget, float p2, float p3, float p4, BOOL p5) { invoke<Void>(0x858EA8BFBCFC6492, ped, meleeTarget, p2, p3, p4, p5); } // 0x858EA8BFBCFC6492 0x79E1D27D
	static void TASK_TOGGLE_DUCK(BOOL p0, BOOL p1) { invoke<Void>(0x038919911B714B85, p0, p1); } // 0x038919911B714B85 0x61CFBCBF
	static void TASK_GUARD_CURRENT_POSITION(Ped p0, float p1, float p2, BOOL p3) { invoke<Void>(0xE7E4CD7E43086CBC, p0, p1, p2, p3); } // 0xE7E4CD7E43086CBC 0x2FB099E9
	static void TASK_GUARD_ASSIGNED_DEFENSIVE_AREA(Any p0, float p1, float p2, float p3, float p4, float p5, Any p6) { invoke<Void>(0x3F2674DD9052E8D1, p0, p1, p2, p3, p4, p5, p6); } // 0x3F2674DD9052E8D1 0x7AF0133D
	static void TASK_GUARD_SPHERE_DEFENSIVE_AREA(Ped p0, float p1, float p2, float p3, float p4, float p5, Any p6, float p7, float p8, float p9, float p10) { invoke<Void>(0x3EE6703D0D732958, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x3EE6703D0D732958 0x86B76CB7
	static void TASK_STAND_GUARD(Ped ped, float x, float y, float z, float heading, char* scenarioName) { invoke<Void>(0xB5D68733ED70B3CF, ped, x, y, z, heading, scenarioName); } // 0xB5D68733ED70B3CF 0xD130F636
	static void SET_DRIVE_TASK_CRUISE_SPEED(Ped driver, float cruiseSpeed) { invoke<Void>(0x264C2948EAADA50E, driver, cruiseSpeed); } // 0x264C2948EAADA50E 0x3CEC07B1
	static void SET_DRIVE_TASK_MAX_CRUISE_SPEED(Any p0, float p1) { invoke<Void>(0x11B96CDE3101F41F, p0, p1); } // 0x11B96CDE3101F41F 0x7FDF6131
	static void SET_DRIVE_TASK_DRIVING_STYLE(Ped ped, int drivingStyle) { invoke<Void>(0xE12531D3BD9E7825, ped, drivingStyle); } // 0xE12531D3BD9E7825 0x59C5FAD7
	static void ADD_COVER_BLOCKING_AREA(float playerX, float playerY, float playerZ, float radiusX, float radiusY, float radiusZ, BOOL p6, BOOL p7, BOOL p8, BOOL p9) { invoke<Void>(0x2827878FADDEB5AB, playerX, playerY, playerZ, radiusX, radiusY, radiusZ, p6, p7, p8, p9); } // 0x2827878FADDEB5AB 0x3536946F
	static void REMOVE_ALL_COVER_BLOCKING_AREAS() { invoke<Void>(0xF5BE97042135745F); } // 0xF5BE97042135745F 0xCF9221A7
	static void TASK_START_SCENARIO_IN_PLACE(Ped ped, char* scenarioName, int unkDelay, BOOL playEnterAnim) { invoke<Void>(0xBD415ADB0A08F6EF, ped, scenarioName, unkDelay, playEnterAnim); } // 0xBD415ADB0A08F6EF 0xE50D6DDE
	static void TASK_START_SCENARIO_AT_POSITION(Ped ped, char* scenarioName, float x, float y, float z, float heading, Any p6, BOOL p7, BOOL p8) { invoke<Void>(0x0806B1CDAAB99FB4, ped, scenarioName, x, y, z, heading, p6, p7, p8); } // 0x0806B1CDAAB99FB4 0xAA2C4AC2
	static void TASK_USE_NEAREST_SCENARIO_TO_COORD(Any p0, float p1, float p2, float p3, float p4, Any p5) { invoke<Void>(0xC2AF726494294D5F, p0, p1, p2, p3, p4, p5); } // 0xC2AF726494294D5F 0x9C50FBF0
	static void TASK_USE_NEAREST_SCENARIO_TO_COORD_WARP(Ped ped, float x, float y, float z, float radius, Any p5) { invoke<Void>(0xA2CF3F29D091EFF2, ped, x, y, z, radius, p5); } // 0xA2CF3F29D091EFF2 0x1BE9D65C
	static void TASK_USE_NEAREST_SCENARIO_CHAIN_TO_COORD(Any p0, float p1, float p2, float p3, float p4, Any p5) { invoke<Void>(0x07E3A1C442D1220E, p0, p1, p2, p3, p4, p5); } // 0x07E3A1C442D1220E 0xE32FFB22
	static void TASK_USE_NEAREST_SCENARIO_CHAIN_TO_COORD_WARP(Any p0, float p1, float p2, float p3, float p4, Any p5) { invoke<Void>(0xED8E355DB7B35F9C, p0, p1, p2, p3, p4, p5); } // 0xED8E355DB7B35F9C 0xBAB4C0AE
	static BOOL DOES_SCENARIO_EXIST_IN_AREA(float x, float y, float z, float radius, BOOL b) { return invoke<BOOL>(0x3F1EB7756B4EA5B4, x, y, z, radius, b); } // 0x3F1EB7756B4EA5B4 0xFA7F5047
	static BOOL DOES_SCENARIO_OF_TYPE_EXIST_IN_AREA(float p0, float p1, float p2, Any* p3, float p4, BOOL p5) { return invoke<BOOL>(0x53119E7F6F58621A, p0, p1, p2, p3, p4, p5); } // 0x53119E7F6F58621A 0x0FB138A5
	static BOOL IS_SCENARIO_OCCUPIED(float p0, float p1, float p2, float p3, BOOL p4) { return invoke<BOOL>(0x736E6FA4DC8080AB, p0, p1, p2, p3, p4); } // 0x736E6FA4DC8080AB 0x697FC008
	static BOOL PED_HAS_USE_SCENARIO_TASK(Ped ped) { return invoke<BOOL>(0x76D0AAE390EBD853, ped); } // 0x76D0AAE390EBD853 0x9BE9C691
	static void PLAY_ANIM_ON_RUNNING_SCENARIO(Ped ped, char* animDict, char* animName) { invoke<Void>(0xA227DF64FF49321D, ped, animDict, animName); } // 0xA227DF64FF49321D 0x1984A5D1
	static BOOL DOES_SCENARIO_GROUP_EXIST(char* scenarioGroup) { return invoke<BOOL>(0x8F2623409AB194EF, scenarioGroup); } // 0x8F2623409AB194EF 0x5F072EB9
	static BOOL IS_SCENARIO_GROUP_ENABLED(char* scenarioGroup) { return invoke<BOOL>(0x678AA675E5FB908B, scenarioGroup); } // 0x678AA675E5FB908B 0x90991122
	static void SET_SCENARIO_GROUP_ENABLED(char* scenarioGroup, BOOL p1) { invoke<Void>(0x63AA98F5AB7E3F81, scenarioGroup, p1); } // 0x63AA98F5AB7E3F81 0x116997B1
	static void RESET_SCENARIO_GROUPS_ENABLED() { invoke<Void>(0xD4E49A8837DDCB7F); } // 0xD4E49A8837DDCB7F 0xBF55025D
	static void SET_EXCLUSIVE_SCENARIO_GROUP(char* scenarioGroup) { invoke<Void>(0x7C5A36A87417135B, scenarioGroup); } // 0x7C5A36A87417135B 0x59DB8F26
	static void RESET_EXCLUSIVE_SCENARIO_GROUP() { invoke<Void>(0x2E3B1A2A729C122F); } // 0x2E3B1A2A729C122F 0x17F9DFE8
	static BOOL IS_SCENARIO_TYPE_ENABLED(char* scenarioType) { return invoke<BOOL>(0x47F521CB0314A6BB, scenarioType); } // 0x47F521CB0314A6BB 0xAE37E969
	static void SET_SCENARIO_TYPE_ENABLED(char* scenarioType, BOOL toggle) { invoke<Void>(0xBFB6E3E25249995F, scenarioType, toggle); } // 0xBFB6E3E25249995F 0xDB18E5DE
	static void RESET_SCENARIO_TYPES_ENABLED() { invoke<Void>(0xF0F23C9E91A580AB); } // 0xF0F23C9E91A580AB 0xF58FDEB4
	static BOOL IS_PED_ACTIVE_IN_SCENARIO(Ped ped) { return invoke<BOOL>(0x9E9346238770C641, ped); } // 0x9E9346238770C641 0x05038F1A
	static BOOL _0x5D09CFEC2E890E40(Ped ped) { return invoke<BOOL>(0x5D09CFEC2E890E40, ped); } // 0x5D09CFEC2E890E40
	static void _0xAA441B4327530171(Ped ped, BOOL p1, BOOL p2) { invoke<Void>(0xAA441B4327530171, ped, p1, p2); } // 0xAA441B4327530171
	static void TASK_COMBAT_HATED_TARGETS_IN_AREA(Ped ped, float x, float y, float z, float radius, Any p5) { invoke<Void>(0xD42F2E17E20C3C7E, ped, x, y, z, radius, p5); } // 0xD42F2E17E20C3C7E 0xDF099E18
	static void TASK_COMBAT_HATED_TARGETS_AROUND_PED(Ped ped, float radius, int p2) { invoke<Void>(0x97B2F6B96CC03922, ped, radius, p2); } // 0x97B2F6B96CC03922 0x2E7064E4
	static void TASK_COMBAT_HATED_TARGETS_AROUND_PED_TIMED(Any p0, float p1, Any p2, Any p3) { invoke<Void>(0x2FBE5828DDC5C3E1, p0, p1, p2, p3); } // 0x2FBE5828DDC5C3E1 0xF127AD6A
	static void TASK_THROW_PROJECTILE(Any p0, float x, float y, float z) { invoke<Void>(0xB88B719CA6E1ADA0, p0, x, y, z); } // 0xB88B719CA6E1ADA0 0xF65C20A7
	static void TASK_SWAP_WEAPON(Ped ped, BOOL p1) { invoke<Void>(0x977CFCF6269F9ABF, ped, p1); } // 0x977CFCF6269F9ABF 0xDAF4F8FC
	static void TASK_RELOAD_WEAPON(Ped ped, BOOL doReload) { invoke<Void>(0xB1AE659909E8E996, ped, doReload); } // 0xB1AE659909E8E996 0xCA6E91FD
	static BOOL IS_PED_GETTING_UP(Ped ped) { return invoke<BOOL>(0x7276DD47CA44085D, ped); } // 0x7276DD47CA44085D 0x320813E6
	static void TASK_WRITHE(Ped ped, Ped target, int time, int p3) { invoke<Void>(0x80589E167C4A5DF3, ped, target, time, p3); } // 0x80589E167C4A5DF3 0x0FDC54FC
	static BOOL IS_PED_IN_WRITHE(Ped ped) { return invoke<BOOL>(0x31969C467F3EBD10, ped); } // 0x31969C467F3EBD10 0x09E61921
	static void OPEN_PATROL_ROUTE(char* patrolRoute) { invoke<Void>(0xEF30AE2504DE7CBB, patrolRoute); } // 0xEF30AE2504DE7CBB 0xF33F83CA
	static void CLOSE_PATROL_ROUTE() { invoke<Void>(0x4578CA8AE5FA38E3); } // 0x4578CA8AE5FA38E3 0x67305E59
	static void ADD_PATROL_ROUTE_NODE(int p0, char* p1, float x1, float y1, float z1, float x2, float y2, float z2, int p8) { invoke<Void>(0x992E0CFA762FF983, p0, p1, x1, y1, z1, x2, y2, z2, p8); } // 0x992E0CFA762FF983 0x21B48F10
	static void ADD_PATROL_ROUTE_LINK(Any p0, Any p1) { invoke<Void>(0x19976DB8D9B9A772, p0, p1); } // 0x19976DB8D9B9A772 0xD8761BB3
	static void CREATE_PATROL_ROUTE() { invoke<Void>(0x22DA0ECEEB9164F2); } // 0x22DA0ECEEB9164F2 0x0A6C7864
	static void DELETE_PATROL_ROUTE(char* patrolRoute) { invoke<Void>(0xD0F8C9F71F53CA88, patrolRoute); } // 0xD0F8C9F71F53CA88 0x2A4E6706
	static void TASK_PATROL(Ped ped, char* p1, Any p2, BOOL p3, BOOL p4) { invoke<Void>(0x57CCCA333BC14F78, ped, p1, p2, p3, p4); } // 0x57CCCA333BC14F78 0xB92E5AF6
	static void TASK_STAY_IN_COVER(Ped ped) { invoke<Void>(0x314042F54BF2FAF1, ped); } // 0x314042F54BF2FAF1 0xA27A9413
	static void ADD_VEHICLE_SUBTASK_ATTACK_COORD(Ped ped, float x, float y, float z) { invoke<Void>(0xB4B97DFC201E7878, ped, x, y, z); } // 0xB4B97DFC201E7878 0x50779A2C
	static void ADD_VEHICLE_SUBTASK_ATTACK_PED(Ped ped, Ped ped2) { invoke<Void>(0x5999F2D444C16D1F, ped, ped2); } // 0x5999F2D444C16D1F 0x80461113
	static void TASK_VEHICLE_SHOOT_AT_PED(Ped ped, Ped target, float p2) { invoke<Void>(0xC8FB92A4CEE66E74, ped, target, p2); } // 0xC8FB92A4CEE66E74 0x59677BA0
	static void TASK_VEHICLE_AIM_AT_PED(Ped ped, Ped target) { invoke<Void>(0x9679E20E3E2DBA72, ped, target); } // 0x9679E20E3E2DBA72 0x920AE6DB
	static void TASK_VEHICLE_SHOOT_AT_COORD(Vehicle vehicle, float x, float y, float z, float p4) { invoke<Void>(0x267FA78A7BE00AEE, vehicle, x, y, z, p4); } // 0x267FA78A7BE00AEE 0xA7AAA4D6
	static void TASK_VEHICLE_AIM_AT_COORD(Vehicle vehicle, float x, float y, float z) { invoke<Void>(0xA85D5A23B4B5FA72, vehicle, x, y, z); } // 0xA85D5A23B4B5FA72 0x010F47CE
	static void TASK_VEHICLE_GOTO_NAVMESH(Ped ped, Vehicle vehicle, float x, float y, float z, float speed, int behaviorFlag, float stoppingRange) { invoke<Void>(0x1D678C0E8B0EC86E, ped, vehicle, x, y, z, speed, behaviorFlag, stoppingRange); } // 0x1D678C0E8B0EC86E 0x55CF3BCD
	static void TASK_GO_TO_COORD_WHILE_AIMING_AT_COORD(Ped ped, float x, float y, float z, float aimAtX, float aimAtY, float aimAtZ, float moveSpeed, BOOL p8, float p9, float p10, BOOL p11, Any flags, BOOL p13, Hash firingPattern) { invoke<Void>(0xE8CF93C61DC938CD, ped, x, y, z, aimAtX, aimAtY, aimAtZ, moveSpeed, p8, p9, p10, p11, flags, p13, firingPattern); } // 0xE8CF93C61DC938CD 0x1552DC91
	static void TASK_GO_TO_COORD_WHILE_AIMING_AT_ENTITY(Any p0, float p1, float p2, float p3, Any p4, float p5, BOOL p6, float p7, float p8, BOOL p9, Any p10, BOOL p11, Any p12, Any p13) { invoke<Void>(0x08F7FC9AC1C10CCE, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); } // 0x08F7FC9AC1C10CCE 0x9BD52ABD
	static void TASK_GO_TO_COORD_AND_AIM_AT_HATED_ENTITIES_NEAR_COORD(Ped ped, float gotoX, float gotoY, float gotoZ, float aimNearX, float aimNearY, float aimNearZ, float speed, BOOL shoot, float unknown1, float unknown2, BOOL unkTrue, int unknown3, BOOL heading, Hash firingPattern) { invoke<Void>(0xDB9934CBD7A392E6, ped, gotoX, gotoY, gotoZ, aimNearX, aimNearY, aimNearZ, speed, shoot, unknown1, unknown2, unkTrue, unknown3, heading, firingPattern); } // 0xDB9934CBD7A392E6 0x3F91358E
	static void TASK_GO_TO_ENTITY_WHILE_AIMING_AT_COORD(Any p0, Any p1, float p2, float p3, float p4, float p5, BOOL p6, float p7, float p8, BOOL p9, BOOL p10, Any p11) { invoke<Void>(0xDF7ACB58AF1D59E0, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0xDF7ACB58AF1D59E0 0xD896CD82
	static void TASK_GO_TO_ENTITY_WHILE_AIMING_AT_ENTITY(Ped ped, Entity entityToWalkTo, Entity entityToAimAt, float speed, BOOL shootatEntity, float p5, float p6, BOOL p7, BOOL p8, Hash firingPattern) { invoke<Void>(0xE44B3F42EB747B10, ped, entityToWalkTo, entityToAimAt, speed, shootatEntity, p5, p6, p7, p8, firingPattern); } // 0xE44B3F42EB747B10 0x68E36B7A
	static void SET_HIGH_FALL_TASK(Ped ped, Any p1, Any p2, Any p3) { invoke<Void>(0x51BA2E942EACE4FA, ped, p1, p2, p3); } // 0x51BA2E942EACE4FA 0xBBB26172
	static void REQUEST_WAYPOINT_RECORDING(char* name) { invoke<Void>(0xD2EFABA17D4F41B0, name); } // 0xD2EFABA17D4F41B0 0xAFABFB5D
	static BOOL GET_IS_WAYPOINT_RECORDING_LOADED(char* name) { return invoke<BOOL>(0x246AF348B8F0270F, name); } // 0x246AF348B8F0270F 0x87125F5D
	static void REMOVE_WAYPOINT_RECORDING(char* name) { invoke<Void>(0x01ADBE1EAD155D08, name); } // 0x01ADBE1EAD155D08 0x624530B0
	static BOOL WAYPOINT_RECORDING_GET_NUM_POINTS(Any* p0, Any* p1) { return invoke<BOOL>(0x59C57A0E783BFE11, p0, p1); } // 0x59C57A0E783BFE11 0xF5F9B71E
	static Any WAYPOINT_RECORDING_GET_COORD(Any p0, Any p1, Any p2) { return invoke<Any>(0x4CC942E875FE1161, p0, p1, p2); } // 0x4CC942E875FE1161 0x19266913
	static float WAYPOINT_RECORDING_GET_SPEED_AT_POINT(Any* p0, Any p1) { return invoke<float>(0x06E8F692D89FF4C7, p0, p1); } // 0x06E8F692D89FF4C7 0xC765633A
	static BOOL WAYPOINT_RECORDING_GET_CLOSEST_WAYPOINT(Any* p0, float p1, float p2, float p3, Any* p4) { return invoke<BOOL>(0x18FA2CCCE2CE1545, p0, p1, p2, p3, p4); } // 0x18FA2CCCE2CE1545 0xC4CD35AF
	static void TASK_FOLLOW_WAYPOINT_RECORDING(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x48AF91AD76812A42, p0, p1, p2, p3, p4); } // 0x48AF91AD76812A42 0xADF9904D
	static BOOL IS_WAYPOINT_PLAYBACK_GOING_ON_FOR_PED(Any p0) { return invoke<BOOL>(0x4EFD03905ADD01D1, p0); } // 0x4EFD03905ADD01D1 0x85B7725F
	static Any GET_PED_WAYPOINT_PROGRESS(Any p0) { return invoke<Any>(0xDDF15C1B6351B52C, p0); } // 0xDDF15C1B6351B52C 0x3595B104
	static float GET_PED_WAYPOINT_DISTANCE(Any p0) { return invoke<float>(0x5C5D7BBC257A8ADC, p0); } // 0x5C5D7BBC257A8ADC 0x084B35B0
	static Any SET_PED_WAYPOINT_ROUTE_OFFSET(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x548664383E5F79E4, p0, p1, p2, p3); } // 0x548664383E5F79E4 0xF867F747
	static float GET_WAYPOINT_DISTANCE_ALONG_ROUTE(Any* p0, Any p1) { return invoke<float>(0x96C03595F3934E6F, p0, p1); } // 0x96C03595F3934E6F 0xE8422AC4
	static BOOL WAYPOINT_PLAYBACK_GET_IS_PAUSED(Any p0) { return invoke<BOOL>(0xD9E4D324EB0CEDAF, p0); } // 0xD9E4D324EB0CEDAF 0xA6BB5717
	static void WAYPOINT_PLAYBACK_PAUSE(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x2018D70D3A44F4D6, p0, p1, p2); } // 0x2018D70D3A44F4D6 0xFE39ECF8
	static void WAYPOINT_PLAYBACK_RESUME(Any p0, BOOL p1, Any p2, Any p3) { invoke<Void>(0x3DA58F6653920015, p0, p1, p2, p3); } // 0x3DA58F6653920015 0x50F392EF
	static void WAYPOINT_PLAYBACK_OVERRIDE_SPEED(Any p0, float p1, BOOL p2) { invoke<Void>(0x142450524CDAF1FA, p0, p1, p2); } // 0x142450524CDAF1FA 0x23E6BA96
	static void WAYPOINT_PLAYBACK_USE_DEFAULT_SPEED(Any p0) { invoke<Void>(0x80824D36F2577DAD, p0); } // 0x80824D36F2577DAD 0x1BBB2CAC
	static void USE_WAYPOINT_RECORDING_AS_ASSISTED_MOVEMENT_ROUTE(Any* p0, BOOL p1, float p2, float p3) { invoke<Void>(0xE67BCD73FCDCAF1B, p0, p1, p2, p3); } // 0xE67BCD73FCDCAF1B 0x4DFD5FEC
	static void WAYPOINT_PLAYBACK_START_AIMING_AT_PED(Any p0, Any p1, BOOL p2) { invoke<Void>(0x6D285ACE4E8106B2, p0, p1, p2); } // 0x6D285ACE4E8106B2 0x75E60CF6
	static void WAYPOINT_PLAYBACK_START_AIMING_AT_COORD(Any p0, float p1, float p2, float p3, BOOL p4) { invoke<Void>(0xFF26F8C8BA331C71, p0, p1, p2, p3, p4); } // 0xFF26F8C8BA331C71 0xF120A34E
	static void _0x9145C48D1D8D8F1B(Any p0, Any p1, BOOL p2, Any p3) { invoke<Void>(0x9145C48D1D8D8F1B, p0, p1, p2, p3); } // 0x9145C48D1D8D8F1B
	static void WAYPOINT_PLAYBACK_START_SHOOTING_AT_COORD(Any p0, float p1, float p2, float p3, BOOL p4, Any p5) { invoke<Void>(0xA9257420B7132DDF, p0, p1, p2, p3, p4, p5); } // 0xA9257420B7132DDF 0xCDDB44D5
	static void WAYPOINT_PLAYBACK_STOP_AIMING_OR_SHOOTING(Any p0) { invoke<Void>(0x95C0949B69AD3928, p0); } // 0x95C0949B69AD3928 0x6D7CF40C
	static void ASSISTED_MOVEMENT_REQUEST_ROUTE(char* route) { invoke<Void>(0x42E12853A6B87574, route); } // 0x42E12853A6B87574 0x48262EDA
	static void ASSISTED_MOVEMENT_REMOVE_ROUTE(char* route) { invoke<Void>(0x728F4732BB4B4AC8, route); } // 0x728F4732BB4B4AC8 0xB3CEC06F
	static BOOL ASSISTED_MOVEMENT_IS_ROUTE_LOADED(char* route) { return invoke<BOOL>(0x696180F7925D128F, route); } // 0x696180F7925D128F 0x79B067AF
	static void ASSISTED_MOVEMENT_SET_ROUTE_PROPERTIES(char* route, int props) { invoke<Void>(0x2D932CC8ACD63A63, route, props); } // 0x2D932CC8ACD63A63 0x01CAAFCC
	static void ASSISTED_MOVEMENT_OVERRIDE_LOAD_DISTANCE_THIS_FRAME(float dist) { invoke<Void>(0x0D564215C7E588FE, dist); } // 0x0D564215C7E588FE 0x8FB923EC
	static void TASK_VEHICLE_FOLLOW_WAYPOINT_RECORDING(Ped ped, Vehicle vehicle, char* WPRecording, int p3, int p4, int p5, int p6, float p7, BOOL p8, float p9) { invoke<Void>(0xAD1391A0485EA6BA, ped, vehicle, WPRecording, p3, p4, p5, p6, p7, p8, p9); } // 0xAD1391A0485EA6BA 0x959818B6
	static BOOL IS_WAYPOINT_PLAYBACK_GOING_ON_FOR_VEHICLE(Any p0) { return invoke<BOOL>(0xA269031A4ECAE4FA, p0); } // 0xA269031A4ECAE4FA 0x80DD15DB
	static Any GET_VEHICLE_WAYPOINT_PROGRESS(Any p0) { return invoke<Any>(0xFF6D60AC4EF373FD, p0); } // 0xFF6D60AC4EF373FD 0xD3CCF64E
	static Any GET_VEHICLE_WAYPOINT_TARGET_POINT(Any p0) { return invoke<Any>(0xBEBDF29A64C20AB1, p0); } // 0xBEBDF29A64C20AB1 0x81049608
	static void VEHICLE_WAYPOINT_PLAYBACK_PAUSE(Any p0) { invoke<Void>(0x1DF16BBD9FC73223, p0); } // 0x1DF16BBD9FC73223 0x7C00B415
	static void VEHICLE_WAYPOINT_PLAYBACK_RESUME(Any p0) { invoke<Void>(0xA9135078CDA79D03, p0); } // 0xA9135078CDA79D03 0xBEB14C82
	static void VEHICLE_WAYPOINT_PLAYBACK_USE_DEFAULT_SPEED(Any p0) { invoke<Void>(0x0859EE3B518EE5E8, p0); } // 0x0859EE3B518EE5E8 0x923C3AA4
	static void VEHICLE_WAYPOINT_PLAYBACK_OVERRIDE_SPEED(Any p0, float p1) { invoke<Void>(0xF69C982EBD3B666B, p0, p1); } // 0xF69C982EBD3B666B 0xBE1E7BB4
	static void TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Ped ped, BOOL toggle) { invoke<Void>(0x29DA211B1C795F27, ped, toggle); } // 0x29DA211B1C795F27 0x1B54FB6B
	static void TASK_FORCE_MOTION_STATE(Ped ped, Hash state, BOOL p2) { invoke<Void>(0xBB65221F01AF8246, ped, state, p2); } // 0xBB65221F01AF8246 0xCAD2EF77
	static void _TASK_MOVE_NETWORK(Ped ped, char* task, float multiplier, BOOL p3, char* animDict, int flags) { invoke<Void>(0x238010BC479F86C6, ped, task, multiplier, p3, animDict, flags); } // 0x238010BC479F86C6 0x6F5D215F
	static void _TASK_MOVE_NETWORK_ADVANCED(Ped ped, char* p1, float p2, float p3, float p4, float p5, float p6, float p7, Any p8, float p9, BOOL p10, char* animDict, int flags) { invoke<Void>(0x446DDBCD570B9D2F, ped, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, animDict, flags); } // 0x446DDBCD570B9D2F 0x71A5C5DB
	static BOOL _0x2DE824AF47266B08(int PlayerID) { return invoke<BOOL>(0x2DE824AF47266B08, PlayerID); } // 0x2DE824AF47266B08 0x902656EB
	static BOOL _0xCBEBD9BE98576702(Any p0) { return invoke<BOOL>(0xCBEBD9BE98576702, p0); } // 0xCBEBD9BE98576702 0x92FDBAE6
	static Any _0x466D37B168FA5357(Ped ped, char* p1) { return invoke<Any>(0x466D37B168FA5357, ped, p1); } // 0x466D37B168FA5357 0x885724DE
	static Any _0x611EE239BDF5444B(Any p0, Any p1) { return invoke<Any>(0x611EE239BDF5444B, p0, p1); } // 0x611EE239BDF5444B
	static char* _0x2E4DA7FE9155628A(Entity entity) { return invoke<char*>(0x2E4DA7FE9155628A, entity); } // 0x2E4DA7FE9155628A 0x96C0277B
	static void _0xE69A8B57AAB5B7B0(Ped p0, char* p1, float p2) { invoke<Void>(0xE69A8B57AAB5B7B0, p0, p1, p2); } // 0xE69A8B57AAB5B7B0 0xA79BE783
	static void _0xF1C8348B9506F756(Ped p0, Any* p1, BOOL p2) { invoke<Void>(0xF1C8348B9506F756, p0, p1, p2); } // 0xF1C8348B9506F756 0xF3538041
	static BOOL _0x641557C9CE94C949(Any p0, char* p1) { return invoke<BOOL>(0x641557C9CE94C949, p0, p1); } // 0x641557C9CE94C949 0x1EBB6F3D
	static BOOL _0xB83FCD04355A9BAF(Any p0, Any* p1) { return invoke<BOOL>(0xB83FCD04355A9BAF, p0, p1); } // 0xB83FCD04355A9BAF 0x72FA5EF2
	static BOOL IS_MOVE_BLEND_RATIO_STILL(Ped ped) { return invoke<BOOL>(0x4D93FFC3DAF95CE8, ped); } // 0x4D93FFC3DAF95CE8 0xE9DAF877
	static BOOL IS_MOVE_BLEND_RATIO_WALKING(Ped ped) { return invoke<BOOL>(0x529847E8B630B73C, ped); } // 0x529847E8B630B73C 0xD21639A8
	static BOOL IS_MOVE_BLEND_RATIO_RUNNING(Ped ped) { return invoke<BOOL>(0xF26CDFC74296D912, ped); } // 0xF26CDFC74296D912 0xE76A2353
	static BOOL IS_MOVE_BLEND_RATIO_SPRINTING(Ped ped) { return invoke<BOOL>(0xAA9D4E3745060F4C, ped); } // 0xAA9D4E3745060F4C 0xDD616893
	static BOOL IS_PED_STILL(Ped ped) { return invoke<BOOL>(0x680C65DB8B4F99B5, ped); } // 0x680C65DB8B4F99B5 0x09E3418D
	static BOOL IS_PED_WALKING(Ped ped) { return invoke<BOOL>(0xF6CC94BA7ACBA7EC, ped); } // 0xF6CC94BA7ACBA7EC 0x4B865C4A
	static BOOL IS_PED_RUNNING(Ped ped) { return invoke<BOOL>(0x2E2AFA316F567F4B, ped); } // 0x2E2AFA316F567F4B 0xE9A5578F
	static BOOL IS_PED_SPRINTING(Ped ped) { return invoke<BOOL>(0x9D317EC24D9CDD2F, ped); } // 0x9D317EC24D9CDD2F 0x4F3E0633
	static BOOL IS_PED_STRAFING(Ped ped) { return invoke<BOOL>(0x52B3271DE218085F, ped); } // 0x52B3271DE218085F 0xEFEED13C
	static void TASK_SYNCHRONIZED_SCENE(Ped ped, int scene, char* animDictionary, char* animationName, float speed, float speedMultiplier, int duration, int flag, float playbackRate, Any p9) { invoke<Void>(0xA17D768ED938600C, ped, scene, animDictionary, animationName, speed, speedMultiplier, duration, flag, playbackRate, p9); } // 0xA17D768ED938600C 0x4F217E7B
	static void TASK_SWEEP_AIM_ENTITY(Ped ped, char* anim, char* p2, char* p3, char* p4, int p5, Vehicle vehicle, float p7, float p8) { invoke<Void>(0xF8EA44F51E6F043F, ped, anim, p2, p3, p4, p5, vehicle, p7, p8); } // 0xF8EA44F51E6F043F 0x4D210467
	static void UPDATE_TASK_SWEEP_AIM_ENTITY(Ped ped, Entity entity) { invoke<Void>(0xDBE28E261002ED59, ped, entity); } // 0xDBE28E261002ED59 0xF65F0F4F
	static void TASK_SWEEP_AIM_POSITION(Any p0, Any* p1, Any* p2, Any* p3, Any* p4, Any p5, float p6, float p7, float p8, float p9, float p10) { invoke<Void>(0xD0AEA9A6DBBC6EAC, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0xD0AEA9A6DBBC6EAC 0x1683FE66
	static void UPDATE_TASK_SWEEP_AIM_POSITION(Any p0, float p1, float p2, float p3) { invoke<Void>(0x66FE24A47B59E42F, p0, p1, p2, p3); } // 0x66FE24A47B59E42F 0x6345EC80
	static void TASK_ARREST_PED(Ped ped, Ped target) { invoke<Void>(0xE335474988E5E8EF, ped, target); } // 0xE335474988E5E8EF 0xBC0F153D
	static BOOL IS_PED_RUNNING_ARREST_TASK(Ped ped) { return invoke<BOOL>(0x1DDE244B1F4650BD, ped); } // 0x1DDE244B1F4650BD 0x6942DB7A
	static BOOL IS_PED_BEING_ARRESTED(Ped ped) { return invoke<BOOL>(0x8ABAB1F335EBFAC2, ped); } // 0x8ABAB1F335EBFAC2 0x5FF6C2ED
	static void UNCUFF_PED(Ped ped) { invoke<Void>(0x03272D55C2E1D027, ped); } // 0x03272D55C2E1D027 0xA23A1D61
	static BOOL IS_PED_CUFFED(Ped ped) { return invoke<BOOL>(0x225AFA39BA10F1B6, ped); } // 0x225AFA39BA10F1B6 0x511CE741
}

namespace GAMEPLAY
{
	static int GET_ALLOCATED_STACK_SIZE() { return invoke<int>(0xFC83C512009EAF62); } // 0xFC83C512009EAF62 0x4E9CA30A
	static int _GET_FREE_STACK_SLOTS_COUNT(int stackSize) { return invoke<int>(0x8080A9940A3EEDB4, stackSize); } // 0x8080A9940A3EEDB4 0x11A178B8
	static void SET_RANDOM_SEED(int time) { invoke<Void>(0x028E183117612A34, time); } // 0x028E183117612A34 0xDB3FEB5C
	static void SET_TIME_SCALE(float time) { invoke<Void>(0x8ADF92E4B51709E2, time); } // 0x8ADF92E4B51709E2 0xA7F84694
	static void SET_MISSION_FLAG(BOOL toggle) { invoke<Void>(0x7E34CF542225E666, toggle); } // 0x7E34CF542225E666 0x57592D52
	static BOOL GET_MISSION_FLAG() { return invoke<BOOL>(0xE6235D8850CC396F); } // 0xE6235D8850CC396F 0x95115F97
	static void SET_RANDOM_EVENT_FLAG(BOOL p0) { invoke<Void>(0x2BC65DD826D4278E, p0); } // 0x2BC65DD826D4278E 0xA77F31E8
	static Any GET_RANDOM_EVENT_FLAG() { return invoke<Any>(0xD3718ACF1D7AD57E); } // 0xD3718ACF1D7AD57E 0x794CC92C
	static char* _GET_EMPTY_STRING() { return invoke<char*>(0xAB62CE47D129AF33); } // 0xAB62CE47D129AF33
	static void _0xF5647F9176F12515(Any p0, Any p1) { invoke<Void>(0xF5647F9176F12515, p0, p1); } // 0xF5647F9176F12515
	static void _0x451DD1CC8815F5F1(Any p0) { invoke<Void>(0x451DD1CC8815F5F1, p0); } // 0x451DD1CC8815F5F1
	static void _0xEF88DBE0AF121F89(Any p0) { invoke<Void>(0xEF88DBE0AF121F89, p0); } // 0xEF88DBE0AF121F89
	static void _0x00277E1A67062C2D(Any p0) { invoke<Void>(0x00277E1A67062C2D, p0); } // 0x00277E1A67062C2D
	static void _0x9D5C5CEDE6D9619D(Any p0, Any p1) { invoke<Void>(0x9D5C5CEDE6D9619D, p0, p1); } // 0x9D5C5CEDE6D9619D
	static void _0x39E311E6864E8C5B(Any p0) { invoke<Void>(0x39E311E6864E8C5B, p0); } // 0x39E311E6864E8C5B
	static void _0x4E5BAFE75ADC9D3F() { invoke<Void>(0x4E5BAFE75ADC9D3F); } // 0x4E5BAFE75ADC9D3F
	static void _0x46274B7C992C3BEA(Any p0) { invoke<Void>(0x46274B7C992C3BEA, p0); } // 0x46274B7C992C3BEA
	static Any _0x11A160238F841AAE() { return invoke<Any>(0x11A160238F841AAE); } // 0x11A160238F841AAE
	static void _0xB3EFCE1243C98BFD(BOOL p0) { invoke<Void>(0xB3EFCE1243C98BFD, p0); } // 0xB3EFCE1243C98BFD
	static void _0x5611E2259EEF82EC(BOOL p0) { invoke<Void>(0x5611E2259EEF82EC, p0); } // 0x5611E2259EEF82EC 0x8B2DE971
	static void _0xAF2DD116D1A48B8C(char* p0) { invoke<Void>(0xAF2DD116D1A48B8C, p0); } // 0xAF2DD116D1A48B8C 0xE77199F7
	static BOOL _0x72AEA8485D9E85F1(Any* p0, Any* p1, Any p2, BOOL p3) { return invoke<BOOL>(0x72AEA8485D9E85F1, p0, p1, p2, p3); } // 0x72AEA8485D9E85F1
	static Hash _GET_CURRENT_WEATHER_TYPE() { return invoke<Hash>(0x8DE87004FECD3B9C); } // 0x8DE87004FECD3B9C 0xA8171E9E
	static Hash _GET_NEXT_WEATHER_TYPE() { return invoke<Hash>(0x1F84C91D43784C43); } // 0x1F84C91D43784C43 0x353E8056
	static BOOL IS_PREV_WEATHER_TYPE(char* weatherType) { return invoke<BOOL>(0x46DBF363373A281A, weatherType); } // 0x46DBF363373A281A 0x250ADA61
	static BOOL IS_NEXT_WEATHER_TYPE(char* weatherType) { return invoke<BOOL>(0xFF94D9CDEB783DE4, weatherType); } // 0xFF94D9CDEB783DE4 0x99CB167F
	static void SET_WEATHER_TYPE_PERSIST(char* weatherType) { invoke<Void>(0x7519F72494CE183F, weatherType); } // 0x7519F72494CE183F 0xC6C04C75
	static void SET_WEATHER_TYPE_NOW_PERSIST(char* weatherType) { invoke<Void>(0xA40F9C430C6F7D6A, weatherType); } // 0xA40F9C430C6F7D6A 0xC869FE97
	static void SET_WEATHER_TYPE_NOW(char* weatherType) { invoke<Void>(0xACB06691F7215039, weatherType); } // 0xACB06691F7215039 0x361E9EAC
	static void _SET_WEATHER_TYPE_OVER_TIME(char* weatherType, float time) { invoke<Void>(0xC953D7FEE6C3F318, weatherType, time); } // 0xC953D7FEE6C3F318 0x386F0D25
	static void SET_RANDOM_WEATHER_TYPE() { invoke<Void>(0xEAFE90AF8E045AFB); } // 0xEAFE90AF8E045AFB 0xE7AA1BC9
	static void CLEAR_WEATHER_TYPE_PERSIST() { invoke<Void>(0x0DBC59D848A695B9); } // 0x0DBC59D848A695B9 0x6AB757D8
	static void _GET_WEATHER_TYPE_TRANSITION(Any* p0, Any* p1, float* progress_or_time) { invoke<Void>(0x4281819BD66C66CF, p0, p1, progress_or_time); } // 0x4281819BD66C66CF 0x9A5C1D56
	static void _SET_WEATHER_TYPE_TRANSITION(Hash sourceWeather, Hash targetWeather, float transitionTime) { invoke<Void>(0x6B23CC8C3EA0A379, sourceWeather, targetWeather, transitionTime); } // 0x6B23CC8C3EA0A379 0x5CA74040
	static void SET_OVERRIDE_WEATHER(char* weatherType) { invoke<Void>(0xF6DF848153C85129, weatherType); } // 0xF6DF848153C85129 0xD9082BB5
	static void CLEAR_OVERRIDE_WEATHER() { invoke<Void>(0xB392F182B2E2F596); } // 0xB392F182B2E2F596 0x7740EA4E
	static void _0x8DAACF07E05F14A9(float p0) { invoke<Void>(0x8DAACF07E05F14A9, p0); } // 0x8DAACF07E05F14A9 0x625181DC
	static void _0xF553A629C99301AD(float p0) { invoke<Void>(0xF553A629C99301AD, p0); } // 0xF553A629C99301AD 0xBEBBFDC8
	static void _0xAB0F1BC267EAB57B(float p0) { invoke<Void>(0xAB0F1BC267EAB57B, p0); } // 0xAB0F1BC267EAB57B 0x6926AB03
	static void _0xD369ABC3E22A29ED(float p0) { invoke<Void>(0xD369ABC3E22A29ED, p0); } // 0xD369ABC3E22A29ED 0xD447439D
	static void _0xDF824915BCAB8C49(float p0) { invoke<Void>(0xDF824915BCAB8C49, p0); } // 0xDF824915BCAB8C49 0x584E9C59
	static void _0xA61FEE89AF3E4814(float p0) { invoke<Void>(0xA61FEE89AF3E4814, p0); } // 0xA61FEE89AF3E4814 0x5656D578
	static void _0xB2CFD1D61C443108(float p0) { invoke<Void>(0xB2CFD1D61C443108, p0); } // 0xB2CFD1D61C443108 0x0DE40C28
	static void _0xFF0EF9FF5B86723B(float p0) { invoke<Void>(0xFF0EF9FF5B86723B, p0); } // 0xFF0EF9FF5B86723B 0x98C9138B
	static void _0xF4D03E4E7A393A63(float p0) { invoke<Void>(0xF4D03E4E7A393A63, p0); } // 0xF4D03E4E7A393A63 0xFB1A9CDE
	static void _0x8B836DE7B67DCAC3(float p0) { invoke<Void>(0x8B836DE7B67DCAC3, p0); } // 0x8B836DE7B67DCAC3 0x1C0CAE89
	static void _0x4289C51B8CE16E52(float p0) { invoke<Void>(0x4289C51B8CE16E52, p0); } // 0x4289C51B8CE16E52 0x4671AC2E
	static void _0xB694E1FDABEC4F0F(float p0) { invoke<Void>(0xB694E1FDABEC4F0F, p0); } // 0xB694E1FDABEC4F0F 0xDA02F415
	static void _0x7F6B5E536B6B5C80(float p0) { invoke<Void>(0x7F6B5E536B6B5C80, p0); } // 0x7F6B5E536B6B5C80 0x5F3DDEC0
	static void _0x1BE6F222257EC7CC(float p0) { invoke<Void>(0x1BE6F222257EC7CC, p0); } // 0x1BE6F222257EC7CC 0x63A89684
	static void SET_WIND(float p0) { invoke<Void>(0xB1D3A3013B87F7C5, p0); } // 0xB1D3A3013B87F7C5 0xC6294698
	static void SET_WIND_SPEED(float speed) { invoke<Void>(0xF59C7E17867E9C6F, speed); } // 0xF59C7E17867E9C6F 0x45705F94
	static float GET_WIND_SPEED() { return invoke<float>(0xC6BB8D17B0F709F9); } // 0xC6BB8D17B0F709F9 0x098F0F3C
	static void SET_WIND_DIRECTION(float direction) { invoke<Void>(0xD73A238C7E09B7A6, direction); } // 0xD73A238C7E09B7A6 0x381AEEE9
	static Vector3 GET_WIND_DIRECTION() { return invoke<Vector3>(0xF56A9A50CD1803CC); } // 0xF56A9A50CD1803CC 0x89499A0D
	static void _SET_RAIN_FX_INTENSITY(float intensity) { invoke<Void>(0x95AFC61BA457183B, intensity); } // 0x95AFC61BA457183B
	static Any GET_RAIN_LEVEL() { return invoke<Any>(0xF08F5592C11B6A59); } // 0xF08F5592C11B6A59 0xC9F67F28
	static Any GET_SNOW_LEVEL() { return invoke<Any>(0x99884A7E5292A390); } // 0x99884A7E5292A390 0x1B09184F
	static void _CREATE_LIGHTNING_THUNDER() { invoke<Void>(0xA1114B22BE9857C8); } // 0xA1114B22BE9857C8 0xDF38165E
	static void _0x5A7A9CACD251BC9F(char* p0) { invoke<Void>(0x5A7A9CACD251BC9F, p0); } // 0x5A7A9CACD251BC9F
	static void _0xD719690CE2FF34B1(char* p0) { invoke<Void>(0xD719690CE2FF34B1, p0); } // 0xD719690CE2FF34B1 0x8727A4C5
	static void _SET_CLOUD_HAT_TRANSITION(char* type, float transitionTime) { invoke<Void>(0x49F2624D925F38DD, type, transitionTime); } // 0x49F2624D925F38DD 0xED88FC61
	static void _0xFDFB9C9BEB5DFDA4(char* p0, float p1) { invoke<Void>(0xFDFB9C9BEB5DFDA4, p0, p1); } // 0xFDFB9C9BEB5DFDA4 0xC9FA6E07
	static void _CLEAR_CLOUD_HAT() { invoke<Void>(0x477BBCB8BFE32CA4); } // 0x477BBCB8BFE32CA4 0x2D7787BC
	static void _0xFCB546F6CB50B0AB(float p0) { invoke<Void>(0xFCB546F6CB50B0AB, p0); } // 0xFCB546F6CB50B0AB
	static float _0xE3682BAB7CB8FBAA() { return invoke<float>(0xE3682BAB7CB8FBAA); } // 0xE3682BAB7CB8FBAA
	static int GET_GAME_TIMER() { return invoke<int>(0x94E3E074F38DF86C); } // 0x94E3E074F38DF86C 0xA4EA0691
	static float GET_FRAME_TIME() { return invoke<float>(0xE9F97E1BC0CACE24); } // 0xE9F97E1BC0CACE24 0x96374262
	static float _0x53D3513B64834C1F() { return invoke<float>(0x53D3513B64834C1F); } // 0x53D3513B64834C1F
	static int GET_FRAME_COUNT() { return invoke<int>(0x0385EDD8AAEC86F4); } // 0x0385EDD8AAEC86F4 0xB477A015
	static float GET_RANDOM_FLOAT_IN_RANGE(float startRange, float endRange) { return invoke<float>(0x6B1497B2FDBC8466, startRange, endRange); } // 0x6B1497B2FDBC8466 0x0562C4D0
	static int GET_RANDOM_INT_IN_RANGE(int startRange, int endRange) { return invoke<int>(0x0E29C61F26D96FDB, startRange, endRange); } // 0x0E29C61F26D96FDB 0x4051115B
	static BOOL GET_GROUND_Z_FOR_3D_COORD(float x, float y, float z, float* groundZ, BOOL unk) { return invoke<BOOL>(0x4F34E573D7F5024B, x, y, z, groundZ, unk); } // 0x4F34E573D7F5024B 0xA1BFD5E0
	static BOOL _0x9624989A9A9E430F(float x, float y, float z, float* p3, Vector3* p4) { return invoke<BOOL>(0x9624989A9A9E430F, x, y, z, p3, p4); } // 0x9624989A9A9E430F 0x64D91CED
	static float ASIN(float p0) { return invoke<float>(0x198E0E541AF419FB, p0); } // 0x198E0E541AF419FB 0x998E5CAD
	static float ACOS(float p0) { return invoke<float>(0x0FF9EC7665185281, p0); } // 0x0FF9EC7665185281 0xF4038776
	static float TAN(float p0) { return invoke<float>(0x5068AD03F32B859D, p0); } // 0x5068AD03F32B859D 0xD320CE5E
	static float ATAN(float p0) { return invoke<float>(0xE471FC6362377F86, p0); } // 0xE471FC6362377F86 0x7A03CC8E
	static float ATAN2(float p0, float p1) { return invoke<float>(0xB318EAE363BA0C2D, p0, p1); } // 0xB318EAE363BA0C2D 0x2508AC81
	static float GET_DISTANCE_BETWEEN_COORDS(float x1, float y1, float z1, float x2, float y2, float z2, BOOL useZ) { return invoke<float>(0x3DC4639D5F23DEA2, x1, y1, z1, x2, y2, z2, useZ); } // 0x3DC4639D5F23DEA2 0xF698765E
	static float GET_ANGLE_BETWEEN_2D_VECTORS(float x1, float y1, float x2, float y2) { return invoke<float>(0xB1B7184870BDC5CC, x1, y1, x2, y2); } // 0xB1B7184870BDC5CC 0xDBF75E58
	static float GET_HEADING_FROM_VECTOR_2D(float dx, float dy) { return invoke<float>(0xC659BC2E3EDC150A, dx, dy); } // 0xC659BC2E3EDC150A 0xD209D52B
	static float _0x46EE3CF726E69356(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, BOOL p9) { return invoke<float>(0x46EE3CF726E69356, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x46EE3CF726E69356 0x89459F0A
	static Vector3 _0xF9362FD10F49D58B(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, BOOL p9) { return invoke<Vector3>(0xF9362FD10F49D58B, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xF9362FD10F49D58B 0xCAECF37E
	static BOOL _0xFA917A2E40767A50(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10, float p11, Any* p12) { return invoke<BOOL>(0xFA917A2E40767A50, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); } // 0xFA917A2E40767A50 0xC6CC812C
	static void SET_BIT(int* address, int offset) { invoke<Void>(0xEB79FECD9022AAF0, address, offset); } // 0xEB79FECD9022AAF0 0x4EFE7E6B
	static void CLEAR_BIT(int* address, int offset) { invoke<Void>(0x21E7933CCC7B3724, address, offset); } // 0x21E7933CCC7B3724 0x8BC9E618
	static Hash GET_HASH_KEY(char* value) { return invoke<Hash>(0x765F5B806B517045, value); } // 0x765F5B806B517045 0x98EFF6F1
	static void _0x86F2444FEC654B0C(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, Any* p9, Any* p10, Any* p11, Any* p12) { invoke<Void>(0x86F2444FEC654B0C, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); } // 0x86F2444FEC654B0C 0x87B92190
	static BOOL IS_AREA_OCCUPIED(float p0, float p1, float p2, float p3, float p4, float p5, BOOL p6, BOOL p7, BOOL p8, BOOL p9, BOOL p10, Any p11, BOOL p12) { return invoke<BOOL>(0x5B5235DE33DC60D1, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); } // 0x5B5235DE33DC60D1 0xC013972F
	static BOOL IS_POSITION_OCCUPIED(float p0, float p1, float p2, float p3, BOOL p4, BOOL p5, BOOL p6, BOOL p7, BOOL p8, Any p9, BOOL p10) { return invoke<BOOL>(0xD77F1BF32D628593, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0xD77F1BF32D628593 0x452E8D9E
	static BOOL IS_POINT_OBSCURED_BY_A_MISSION_ENTITY(float p0, float p1, float p2, float p3, float p4, float p5, Any p6) { return invoke<BOOL>(0x43DE91373283A511, p0, p1, p2, p3, p4, p5, p6); } // 0x43DE91373283A511 0xC161558D
	static void CLEAR_AREA(float X, float Y, float Z, float radius, BOOL p4, BOOL ignoreCopCars, BOOL ignoreObjects, BOOL p7) { invoke<Void>(0x1B60289D0F2A2E3C, X, Y, Z, radius, p4, ignoreCopCars, ignoreObjects, p7); } // 0x1B60289D0F2A2E3C 0x854E9AB8
	static void _CLEAR_AREA_OF_EVERYTHING(float x, float y, float z, float radius, BOOL p4, BOOL p5, BOOL p6, BOOL p7) { invoke<Void>(0xD8392BECA822A035, x, y, z, radius, p4, p5, p6, p7); } // 0xD8392BECA822A035 0x20E4FFD9
	static void CLEAR_AREA_OF_VEHICLES(float x, float y, float z, float radius, BOOL p4, BOOL p5, BOOL p6, BOOL p7, BOOL p8) { invoke<Void>(0x0668B21A0C3A4821, x, y, z, radius, p4, p5, p6, p7, p8); } // 0x0668B21A0C3A4821 0x63320F3C
	static void CLEAR_ANGLED_AREA_OF_VEHICLES(float p0, float p1, float p2, float p3, float p4, float p5, float p6, BOOL p7, BOOL p8, BOOL p9, BOOL p10, BOOL p11) { invoke<Void>(0x2A5905FD3A0ED2A0, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x2A5905FD3A0ED2A0 0xF11A3018
	static void CLEAR_AREA_OF_OBJECTS(float x, float y, float z, float radius, int flags) { invoke<Void>(0x3FE1DC991D646A3B, x, y, z, radius, flags); } // 0x3FE1DC991D646A3B 0xBB720FE7
	static void CLEAR_AREA_OF_PEDS(float x, float y, float z, float radius, int flags) { invoke<Void>(0x26D48449559660BA, x, y, z, radius, flags); } // 0x26D48449559660BA 0x25BE7FA8
	static void CLEAR_AREA_OF_COPS(float x, float y, float z, float radius, int flags) { invoke<Void>(0x3FFDD1F7F08DB3AC, x, y, z, radius, flags); } // 0x3FFDD1F7F08DB3AC 0x95C53824
	static void CLEAR_AREA_OF_PROJECTILES(float x, float y, float z, float radius, int flags) { invoke<Void>(0x7B408F9F309B3E56, x, y, z, radius, flags); } // 0x7B408F9F309B3E56 0x18DB5434
	static void _0xE2DCA0EDF56E75B8() { invoke<Void>(0xE2DCA0EDF56E75B8); } // 0xE2DCA0EDF56E75B8
	static void SET_SAVE_MENU_ACTIVE(BOOL unk) { invoke<Void>(0xE9C010444E79CD58, unk); } // 0xE9C010444E79CD58 0xF5CCF164
	static int _0xBEF9AAFD02F3A244() { return invoke<int>(0xBEF9AAFD02F3A244); } // 0xBEF9AAFD02F3A244 0x39771F21
	static void SET_CREDITS_ACTIVE(BOOL toggle) { invoke<Void>(0x9A1B7E46F18764F7, toggle); } // 0x9A1B7E46F18764F7 0xEC2A0ECF
	static void _0x1DF184D4D8C8B71F(BOOL toggle) { invoke<Void>(0x1DF184D4D8C8B71F, toggle); } // 0x1DF184D4D8C8B71F 0x75B06B5A
	static Any _0x6A4BB4A486CD84CB() { return invoke<Any>(0x6A4BB4A486CD84CB); } // 0x6A4BB4A486CD84CB 0x2569C9A7
	static void TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(char* scriptName) { invoke<Void>(0x414A9320CE716942, scriptName); } // 0x414A9320CE716942 0x9F861FD4
	static void NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME() { invoke<Void>(0x330AFE43E1483B3F); } // 0x330AFE43E1483B3F 0x878486CE
	static int ADD_HOSPITAL_RESTART(float x, float y, float z, float p3, Any p4) { return invoke<int>(0x989BF4520D8D2501, x, y, z, p3, p4); } // 0x989BF4520D8D2501 0x4F3E3104
	static void DISABLE_HOSPITAL_RESTART(int hospitalIndex, BOOL toggle) { invoke<Void>(0x8D81C8465D84F61F, hospitalIndex, toggle); } // 0x8D81C8465D84F61F 0x09F49C72
	static Any ADD_POLICE_RESTART(float p0, float p1, float p2, float p3, Any p4) { return invoke<Any>(0x38DFBCED81375E88, p0, p1, p2, p3, p4); } // 0x38DFBCED81375E88 0xE96C29FE
	static void DISABLE_POLICE_RESTART(int policeIndex, BOOL toggle) { invoke<Void>(0x17E2A3F5EB84EFEB, policeIndex, toggle); } // 0x17E2A3F5EB84EFEB 0x0A280324
	static void _0x5BA8A35DFA47D9C1(float x, float y, float z, float heading) { invoke<Void>(0x5BA8A35DFA47D9C1, x, y, z, heading); } // 0x5BA8A35DFA47D9C1
	static void _0x1CE5B352DE620C6F() { invoke<Void>(0x1CE5B352DE620C6F); } // 0x1CE5B352DE620C6F
	static void _DISABLE_AUTOMATIC_RESPAWN(BOOL disableRespawn) { invoke<Void>(0xFEBB03103CA42EBA, disableRespawn); } // 0xFEBB03103CA42EBA 0x296574AE
	static void IGNORE_NEXT_RESTART(BOOL toggle) { invoke<Void>(0x88120C10222D1D74, toggle); } // 0x88120C10222D1D74 0xDA13A4B6
	static void SET_FADE_OUT_AFTER_DEATH(BOOL toggle) { invoke<Void>(0x32FDBF4A41B0698D, toggle); } // 0x32FDBF4A41B0698D 0xC9F6F0BC
	static void SET_FADE_OUT_AFTER_ARREST(BOOL toggle) { invoke<Void>(0x853F52F88ADE73F4, toggle); } // 0x853F52F88ADE73F4 0xCB074B9D
	static void SET_FADE_IN_AFTER_DEATH_ARREST(BOOL toggle) { invoke<Void>(0x2359C336802E3CB4, toggle); } // 0x2359C336802E3CB4 0xACDE6985
	static void SET_FADE_IN_AFTER_LOAD(BOOL toggle) { invoke<Void>(0x576314C8F156D295, toggle); } // 0x576314C8F156D295 0x6E00EB0B
	static Any REGISTER_SAVE_HOUSE(float p0, float p1, float p2, float p3, Any* p4, Any p5, Any p6) { return invoke<Any>(0x474CD234107F7567, p0, p1, p2, p3, p4, p5, p6); } // 0x474CD234107F7567 0x39C1849A
	static void SET_SAVE_HOUSE(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x7909B21958A4A2AB, p0, p1, p2); } // 0x7909B21958A4A2AB 0xC3240BB4
	static BOOL OVERRIDE_SAVE_HOUSE(BOOL p0, float p1, float p2, float p3, float p4, BOOL p5, float p6, float p7) { return invoke<BOOL>(0x7114329E6852637E, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x7114329E6852637E 0x47436C12
	static Any _0x276C6BB41EA23FDE(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x276C6BB41EA23FDE, p0, p1, p2, p3); } // 0x276C6BB41EA23FDE 0xC4D71AB4
	static void DO_AUTO_SAVE() { invoke<Void>(0x7968D0B9AE40F1A8); } // 0x7968D0B9AE40F1A8 0x54C44B1A
	static Any _0xD1431F5CD526AEBF() { return invoke<Any>(0xD1431F5CD526AEBF); } // 0xD1431F5CD526AEBF 0xA8546914
	static BOOL IS_AUTO_SAVE_IN_PROGRESS() { return invoke<BOOL>(0xF4F87C6CDA931EF1); } // 0xF4F87C6CDA931EF1 0x36F75399
	static Any _0xDAF3C6718B17B7F9() { return invoke<Any>(0xDAF3C6718B17B7F9); } // 0xDAF3C6718B17B7F9 0x78350773
	static void _0xFE4E23A04F329281() { invoke<Void>(0xFE4E23A04F329281); } // 0xFE4E23A04F329281 0x5A45B11A
	static void BEGIN_REPLAY_STATS(Any p0, Any p1) { invoke<Void>(0xCCFCD39336557F9A, p0, p1); } // 0xCCFCD39336557F9A 0x17F4F44D
	static void _0x32D51CDC87C8A564(Any p0) { invoke<Void>(0x32D51CDC87C8A564, p0); } // 0x32D51CDC87C8A564 0x81216EE0
	static void END_REPLAY_STATS() { invoke<Void>(0x74ADF28E70E3DB0E); } // 0x74ADF28E70E3DB0E 0xCB570185
	static Any _0xE9B1D8487400D602() { return invoke<Any>(0xE9B1D8487400D602); } // 0xE9B1D8487400D602 0xC58250F1
	static Any _0x8C6AD904DFE04E9D() { return invoke<Any>(0x8C6AD904DFE04E9D); } // 0x8C6AD904DFE04E9D 0x50C39926
	static Any _0x446085B8BBF8922A() { return invoke<Any>(0x446085B8BBF8922A); } // 0x446085B8BBF8922A 0x710E5D1E
	static Any _0x95CD8C82B270DFE3() { return invoke<Any>(0x95CD8C82B270DFE3); } // 0x95CD8C82B270DFE3 0xC7BD1AF0
	static Any _0x6A84C8E4782263F5(Any p0) { return invoke<Any>(0x6A84C8E4782263F5, p0); } // 0x6A84C8E4782263F5 0x22BE2423
	static void CLEAR_REPLAY_STATS() { invoke<Void>(0xB7CE01AAF5EC861F); } // 0xB7CE01AAF5EC861F 0xC47DFF02
	static Any _0x963EE80701A54A87() { return invoke<Any>(0x963EE80701A54A87); } // 0x963EE80701A54A87 0xF62B3C48
	static Any _0x93C122001618C395() { return invoke<Any>(0x93C122001618C395); } // 0x93C122001618C395 0x3589452B
	static Any _0xF008C463AAAFA12B() { return invoke<Any>(0xF008C463AAAFA12B); } // 0xF008C463AAAFA12B
	static Any _0x47DE856061838A94() { return invoke<Any>(0x47DE856061838A94); } // 0x47DE856061838A94 0x144AAF22
	static BOOL IS_MEMORY_CARD_IN_USE() { return invoke<BOOL>(0x8B15021863F761E4); } // 0x8B15021863F761E4 0x40CE4DFD
	static void SHOOT_SINGLE_BULLET_BETWEEN_COORDS(float x1, float y1, float z1, float x2, float y2, float z2, int damage, BOOL p7, Hash weaponHash, Ped ownerPed, BOOL isAudible, BOOL isInvisible, float speed) { invoke<Void>(0x85E1976B9B8DADE8, x1, y1, z1, x2, y2, z2, damage, p7, weaponHash, ownerPed, isAudible, isInvisible, speed); } // 0x85E1976B9B8DADE8 0xCB7415AC
	static void _0x10C1B371631D4FAB(float x1, float y1, float z1, float x2, float y2, float z2, int damage, BOOL p7, Hash weaponHash, Ped ownerPed, BOOL isAudible, BOOL isInvisible, float speed, Entity entity) { invoke<Void>(0x10C1B371631D4FAB, x1, y1, z1, x2, y2, z2, damage, p7, weaponHash, ownerPed, isAudible, isInvisible, speed, entity); } // 0x10C1B371631D4FAB 0x52ACCB7B
	static void _0x5C2CCC0F26A545ED(float x1, float y1, float z1, float x2, float y2, float z2, int damage, BOOL p7, Hash weaponHash, Ped ownerPed, BOOL isAudible, BOOL isInvisible, float speed, Entity entity, BOOL p14, BOOL p15, BOOL p16, BOOL p17) { invoke<Void>(0x5C2CCC0F26A545ED, x1, y1, z1, x2, y2, z2, damage, p7, weaponHash, ownerPed, isAudible, isInvisible, speed, entity, p14, p15, p16, p17); } // 0x5C2CCC0F26A545ED
	static void GET_MODEL_DIMENSIONS(Hash modelHash, Vector3* minimum, Vector3* maximum) { invoke<Void>(0x9475086C69ACF470, modelHash, minimum, maximum); } // 0x9475086C69ACF470 0x91ABB8E0
	static void SET_FAKE_WANTED_LEVEL(int fakeWantedLevel) { invoke<Void>(0x7EA7D723ADC9DF9E, fakeWantedLevel); } // 0x7EA7D723ADC9DF9E 0x85B1C9FA
	static int GET_FAKE_WANTED_LEVEL() { return invoke<int>(0x11165BF939771BAD); } // 0x11165BF939771BAD 0x0022A430
	static BOOL IS_BIT_SET(int address, int offset) { return invoke<BOOL>(0x48B8265059381CD0, address, offset); } // 0x48B8265059381CD0 0x902E26AC
	static void USING_MISSION_CREATOR(BOOL toggle) { invoke<Void>(0x819160F55AB31FBD, toggle); } // 0x819160F55AB31FBD 0x20AB0B6B
	static void _0x535F7DBF526E51B4(BOOL p0) { invoke<Void>(0x535F7DBF526E51B4, p0); } // 0x535F7DBF526E51B4 0x082BA6F2
	static void SET_MINIGAME_IN_PROGRESS(BOOL toggle) { invoke<Void>(0xE1DCB7A759496CDC, toggle); } // 0xE1DCB7A759496CDC 0x348B9046
	static BOOL IS_MINIGAME_IN_PROGRESS() { return invoke<BOOL>(0xBDEC9B948A62578A); } // 0xBDEC9B948A62578A 0x53A95E13
	static BOOL IS_THIS_A_MINIGAME_SCRIPT() { return invoke<BOOL>(0xDE048B286D8D6EEE); } // 0xDE048B286D8D6EEE 0x7605EF6F
	static BOOL IS_SNIPER_INVERTED() { return invoke<BOOL>(0x7F5279EB30ECDE7B); } // 0x7F5279EB30ECDE7B 0x5C3BF51B
	static Any _0x15EF3CAA574DAEED() { return invoke<Any>(0x15EF3CAA574DAEED); } // 0x15EF3CAA574DAEED 0xBAF17315
	static int GET_PROFILE_SETTING(int profileSetting) { return invoke<int>(0xBE675F7A607B46B0, profileSetting); } // 0xBE675F7A607B46B0 0xD374BEBC
	static BOOL ARE_STRINGS_EQUAL(char* string1, char* string2) { return invoke<BOOL>(0x6A7B0D91FD88D9EE, string1, string2); } // 0x6A7B0D91FD88D9EE 0x877C0BC5
	static int COMPARE_STRINGS(char* str1, char* str2, BOOL matchCase, int maxLength) { return invoke<int>(0x8615D27AA923B8F4, str1, str2, matchCase, maxLength); } // 0x8615D27AA923B8F4 0xFE25A58F
	static int ABSI(int value) { return invoke<int>(0x049F77DED8AE0AF4, value); } // 0x049F77DED8AE0AF4 0xB44677C5
	static float ABSF(float value) { return invoke<float>(0xE851F22ED3518011, value); } // 0xE851F22ED3518011 0xAF6F6E0B
	static BOOL IS_SNIPER_BULLET_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<BOOL>(0x1DFF657AE78DD384, x1, y1, z1, x2, y2, z2); } // 0x1DFF657AE78DD384 0x0483715C
	static BOOL IS_PROJECTILE_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2, BOOL ownedByPlayer) { return invoke<BOOL>(0x3BA3AD8AC9469C63, x1, y1, z1, x2, y2, z2, ownedByPlayer); } // 0x3BA3AD8AC9469C63 0x78E1A557
	static BOOL IS_PROJECTILE_TYPE_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2, int type, BOOL p7) { return invoke<BOOL>(0xD4FBF9E4226D9A5A, x1, y1, z1, x2, y2, z2, type, p7); } // 0xD4FBF9E4226D9A5A 0x2B73BCF6
	static BOOL IS_PROJECTILE_TYPE_IN_ANGLED_AREA(float p0, float p1, float p2, float p3, float p4, float p5, float p6, Any p7, BOOL p8) { return invoke<BOOL>(0x44A30EB8D9EE7035, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x44A30EB8D9EE7035 0xD1AE2681
	static BOOL _0xD2980844C684075E(float p0, float p1, float p2, Any p3, float p4, BOOL p5) { return invoke<BOOL>(0xD2980844C684075E, p0, p1, p2, p3, p4, p5); } // 0xD2980844C684075E 0xBE81F1E2
	static Any _0xBA964BDF5A395EDC(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<Any>(0xBA964BDF5A395EDC, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xBA964BDF5A395EDC 0x1A40454B
	static Any _0x3B7F28D74C18AA5D(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<Any>(0x3B7F28D74C18AA5D, p0, p1, p2, p3, p4); } // 0x3B7F28D74C18AA5D 0x6BDE5CE4
	static Any _0x97200EC3027D534D(Ped ped, Hash weaponhash, float p2, float p3, float p4, float p5) { return invoke<Any>(0x97200EC3027D534D, ped, weaponhash, p2, p3, p4, p5); } // 0x97200EC3027D534D 0x507BC6F7
	static BOOL IS_BULLET_IN_ANGLED_AREA(float p0, float p1, float p2, float p3, float p4, float p5, float p6, BOOL p7) { return invoke<BOOL>(0x40C259C5A05EF89B, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x40C259C5A05EF89B 0xE2DB58F7
	static BOOL IS_BULLET_IN_AREA(float p0, float p1, float p2, float p3, BOOL p4) { return invoke<BOOL>(0x579A94EB2BF9398F, p0, p1, p2, p3, p4); } // 0x579A94EB2BF9398F 0xB54F46CA
	static BOOL IS_BULLET_IN_BOX(float p0, float p1, float p2, float p3, float p4, float p5, BOOL p6) { return invoke<BOOL>(0x1E32F6685CFC5FC7, p0, p1, p2, p3, p4, p5, p6); } // 0x1E32F6685CFC5FC7 0xAB73ED26
	static BOOL HAS_BULLET_IMPACTED_IN_AREA(float p0, float p1, float p2, float p3, BOOL p4, BOOL p5) { return invoke<BOOL>(0x5193E99B6917C701, p0, p1, p2, p3, p4, p5); } // 0x5193E99B6917C701 0x902BC7D9
	static BOOL HAS_BULLET_IMPACTED_IN_BOX(float p0, float p1, float p2, float p3, float p4, float p5, BOOL p6, BOOL p7) { return invoke<BOOL>(0x0445E7F3D3A27E88, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x0445E7F3D3A27E88 0x2C2618CC
	static BOOL IS_ORBIS_VERSION() { return invoke<BOOL>(0x7C2F31E78C33DE0F); } // 0x7C2F31E78C33DE0F 0x40282018
	static BOOL IS_DURANGO_VERSION() { return invoke<BOOL>(0x8EA3D5407E9F4AF0); } // 0x8EA3D5407E9F4AF0 0x46FB06A5
	static BOOL IS_XBOX360_VERSION() { return invoke<BOOL>(0xB15049400DCD8DC9); } // 0xB15049400DCD8DC9 0x24005CC8
	static BOOL IS_PS3_VERSION() { return invoke<BOOL>(0xF20D8448F6AFC86C); } // 0xF20D8448F6AFC86C 0x4C0D5303
	static BOOL IS_PC_VERSION() { return invoke<BOOL>(0xEF4E5E47AF0D4480); } // 0xEF4E5E47AF0D4480 0x4D5D9EE3
	static BOOL IS_AUSSIE_VERSION() { return invoke<BOOL>(0x94508257AD5B30E1); } // 0x94508257AD5B30E1 0x944BA1DC
	static BOOL IS_STRING_NULL(char* string) { return invoke<BOOL>(0xD3115E7F7876D6E6, string); } // 0xD3115E7F7876D6E6 0x8E71E00F
	static BOOL IS_STRING_NULL_OR_EMPTY(char* string) { return invoke<BOOL>(0x9C88EB7B70229335, string); } // 0x9C88EB7B70229335 0x42E9F2CA
	static BOOL STRING_TO_INT(char* string, int* outInteger) { return invoke<BOOL>(0x6EBC82C4F735AFDF, string, outInteger); } // 0x6EBC82C4F735AFDF 0x590A8160
	static void SET_BITS_IN_RANGE(int* var, int rangeStart, int rangeEnd, int p3) { invoke<Void>(0x847FC56255B9284E, var, rangeStart, rangeEnd, p3); } // 0x847FC56255B9284E 0x32094719
	static int GET_BITS_IN_RANGE(int var, int rangeStart, int rangeEnd) { return invoke<int>(0x3501DF8752BA7ECE, var, rangeStart, rangeEnd); } // 0x3501DF8752BA7ECE 0xCA03A1E5
	static int ADD_STUNT_JUMP(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10, float p11, float p12, float p13, float p14, Any p15, Any p16) { return invoke<int>(0x97C4CD23F40E629E, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16); } // 0x97C4CD23F40E629E 0xB630E5FF
	static int ADD_STUNT_JUMP_ANGLED(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10, float p11, float p12, float p13, float p14, float p15, float p16, Any p17, Any p18) { return invoke<int>(0x53FE4C92A98C768F, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18); } // 0x53FE4C92A98C768F 0xB9B7E777
	static void DELETE_STUNT_JUMP(int p0) { invoke<Void>(0xBD03F2DD91561A77, p0); } // 0xBD03F2DD91561A77 0x840CB5DA
	static void ENABLE_STUNT_JUMP_SET(int p0) { invoke<Void>(0x0EC300E96DD061FA, p0); } // 0x0EC300E96DD061FA 0x9D1E7785
	static void DISABLE_STUNT_JUMP_SET(int p0) { invoke<Void>(0x8C1073893D70F1FE, p0); } // 0x8C1073893D70F1FE 0x644C9FA4
	static void _0x5CC1A11777041C3F(BOOL p0) { invoke<Void>(0x5CC1A11777041C3F, p0); } // 0x5CC1A11777041C3F 0x3C806A2D
	static BOOL IS_STUNT_JUMP_IN_PROGRESS() { return invoke<BOOL>(0x485F411081A645B0); } // 0x485F411081A645B0 0xF477D0B1
	static BOOL _0x5092B24E2147F9A9() { return invoke<BOOL>(0x5092B24E2147F9A9); } // 0x5092B24E2147F9A9 0x021636EE
	static Any _0x3C172EE1A94C94ED() { return invoke<Any>(0x3C172EE1A94C94ED); } // 0x3C172EE1A94C94ED 0x006F9BA2
	static Any _0xFE1DA7919487A1C2() { return invoke<Any>(0xFE1DA7919487A1C2); } // 0xFE1DA7919487A1C2
	static void CANCEL_STUNT_JUMP() { invoke<Void>(0xE50B4CDBDBE682AE); } // 0xE50B4CDBDBE682AE 0xF43D9821
	static void SET_GAME_PAUSED(BOOL toggle) { invoke<Void>(0xD278B72A700DC2DC, toggle); } // 0xD278B72A700DC2DC 0x8230FF6C
	static void SET_THIS_SCRIPT_CAN_BE_PAUSED(BOOL toggle) { invoke<Void>(0xAA78C60F0BF0F8D4, toggle); } // 0xAA78C60F0BF0F8D4 0xA0C3CE29
	static void SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(BOOL toggle) { invoke<Void>(0x2624D3879D5473A0, toggle); } // 0x2624D3879D5473A0 0xD06F1720
	static BOOL _HAS_BUTTON_COMBINATION_JUST_BEEN_ENTERED(Hash hash, int amount) { return invoke<BOOL>(0xC90736C320239102, hash, amount); } // 0xC90736C320239102 0xFF6191E1
	static BOOL _HAS_CHEAT_STRING_JUST_BEEN_ENTERED(Hash hash) { return invoke<BOOL>(0x29339E08A465FCF7, hash); } // 0x29339E08A465FCF7
	static void _ENABLE_MP_DLC_MAPS(BOOL toggle) { invoke<Void>(0x7A37812C15EF41D0, toggle); } // 0x7A37812C15EF41D0 0x721B2492
	static void _SET_UNK_MAP_FLAG(int flag) { invoke<Void>(0xFFE4319CE7BE2DBA, flag); } // 0xFFE4319CE7BE2DBA 0xE202879D
	static BOOL IS_FRONTEND_FADING() { return invoke<BOOL>(0x9E0EF228488611AD); } // 0x9E0EF228488611AD 0x8FF6232C
	static void POPULATE_NOW() { invoke<Void>(0x905B1DFCA22F9E69); } // 0x905B1DFCA22F9E69 0x72C20700
	static int GET_INDEX_OF_CURRENT_LEVEL() { return invoke<int>(0x9D5221217E100BDE); } // 0x9D5221217E100BDE 0x6F203C6E
	static void SET_GRAVITY_LEVEL(int level) { invoke<Void>(0x8D41D1D1BAB3D4C1, level); } // 0x8D41D1D1BAB3D4C1 0x2D833F4A
	static void START_SAVE_DATA(Any* p0, Any p1, BOOL p2) { invoke<Void>(0x2BAAE83A20CE6E4A, p0, p1, p2); } // 0x2BAAE83A20CE6E4A 0x881A694D
	static void STOP_SAVE_DATA() { invoke<Void>(0xA815933F383B1E88); } // 0xA815933F383B1E88 0x3B1C07C8
	static Any _0x4ED9122B146390A6(BOOL p0) { return invoke<Any>(0x4ED9122B146390A6, p0); } // 0x4ED9122B146390A6 0x9EF0BC64
	static void REGISTER_INT_TO_SAVE(Any* p0, char* name) { invoke<Void>(0x770B67C1735E424D, p0, name); } // 0x770B67C1735E424D 0xB930956F
	static void _0x2D4DA86D33FFCFF4(Any* p0, Any* p1) { invoke<Void>(0x2D4DA86D33FFCFF4, p0, p1); } // 0x2D4DA86D33FFCFF4
	static void REGISTER_ENUM_TO_SAVE(Any* p0, char* name) { invoke<Void>(0x8AEEB2BEE3F6652D, p0, name); } // 0x8AEEB2BEE3F6652D 0x9B38374A
	static void REGISTER_FLOAT_TO_SAVE(Any* p0, char* name) { invoke<Void>(0xD64B647AB5E5937E, p0, name); } // 0xD64B647AB5E5937E 0xDB06F7AD
	static void REGISTER_BOOL_TO_SAVE(Any* p0, char* name) { invoke<Void>(0xAF7C577CC5CF9AEA, p0, name); } // 0xAF7C577CC5CF9AEA 0x5417E0E0
	static void REGISTER_TEXT_LABEL_TO_SAVE(Any* p0, char* name) { invoke<Void>(0x6B62F2F728DA88EF, p0, name); } // 0x6B62F2F728DA88EF 0x284352C4
	static void _0x6C68431826197548(Any* p0, char* name) { invoke<Void>(0x6C68431826197548, p0, name); } // 0x6C68431826197548 0xE2089749
	static void _0x88159A6727211CED(Any* p0, char* name) { invoke<Void>(0x88159A6727211CED, p0, name); } // 0x88159A6727211CED 0xF91B8C33
	static void _0x842E67ADC8174BD0(Any* p0, char* name) { invoke<Void>(0x842E67ADC8174BD0, p0, name); } // 0x842E67ADC8174BD0 0x74E8FAD9
	static void _0x5B1ADA3285E625AC(Any* p0, char* name) { invoke<Void>(0x5B1ADA3285E625AC, p0, name); } // 0x5B1ADA3285E625AC 0x6B4335DD
	static void _START_SAVE_STRUCT(Any* p0, int p1, char* structName) { invoke<Void>(0xB6DC0C70E4B51F62, p0, p1, structName); } // 0xB6DC0C70E4B51F62 0xFB45728E
	static void STOP_SAVE_STRUCT() { invoke<Void>(0xE3F1001E71986BDD); } // 0xE3F1001E71986BDD 0xC2624A28
	static void _START_SAVE_ARRAY(Any* p0, int p1, char* arrayName) { invoke<Void>(0x18EE864248F0D401, p0, p1, arrayName); } // 0x18EE864248F0D401 0x893A342C
	static void STOP_SAVE_ARRAY() { invoke<Void>(0x253D081AE3F294A4); } // 0x253D081AE3F294A4 0x0CAD8217
	static void ENABLE_DISPATCH_SERVICE(int dispatchType, BOOL toggle) { invoke<Void>(0xFCBD7340FBF1FE46, dispatchType, toggle); } // 0xFCBD7340FBF1FE46 0x0B710A51
	static void _0xF87040A37FD83B8A(Any p0, Any p1) { invoke<Void>(0xF87040A37FD83B8A, p0, p1); } // 0xF87040A37FD83B8A 0xE0F0684F
	static int _0x58E0064FFFD47290(int p0) { return invoke<int>(0x58E0064FFFD47290, p0); } // 0x58E0064FFFD47290 0x3CE5BF6B
	static BOOL CREATE_INCIDENT(int p0, float p2, float p3, float p4, int p5, float p6, int* outIncident) { return invoke<BOOL>(0xCA99D3B8479D90EC, p0, p2, p3, p4, p5, p6, outIncident); } // 0xCA99D3B8479D90EC 0xFC5FF7B3
	static BOOL CREATE_INCIDENT_WITH_ENTITY(int p0, Entity p1, int p2, float p3, int* outIncident) { return invoke<BOOL>(0xE89194C1958B8549, p0, p1, p2, p3, outIncident); } // 0xE89194C1958B8549 0xBBC35B03
	static void DELETE_INCIDENT(int* incidentId) { invoke<Void>(0x67DC6DAF6DB6606C, incidentId); } // 0x67DC6DAF6DB6606C 0x212BD0DC
	static BOOL IS_INCIDENT_VALID(int* incidentId) { return invoke<BOOL>(0x4FC6C50BD6505B89, incidentId); } // 0x4FC6C50BD6505B89 0x31FD0BA4
	static void _0x96E4D9D1B48000CA(Any p0, Any p1, Any p2) { invoke<Void>(0x96E4D9D1B48000CA, p0, p1, p2); } // 0x96E4D9D1B48000CA 0x0242D88E
	static void _0x6E6FCDB19D7D8B3F(Any p0, float p1) { invoke<Void>(0x6E6FCDB19D7D8B3F, p0, p1); } // 0x6E6FCDB19D7D8B3F 0x1F38102E
	static BOOL FIND_SPAWN_POINT_IN_DIRECTION(float x1, float y1, float z1, float x2, float y2, float z2, float distance, Vector3* spawnPoint) { return invoke<BOOL>(0x24350AE82F85E071, x1, y1, z1, x2, y2, z2, distance, spawnPoint); } // 0x24350AE82F85E071 0x71AEFD77
	static Any _0xC143386C24A76ADE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { return invoke<Any>(0xC143386C24A76ADE, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xC143386C24A76ADE 0x42BF09B3
	static BOOL _0xEC86029D1FA363E4(Any p0) { return invoke<BOOL>(0xEC86029D1FA363E4, p0); } // 0xEC86029D1FA363E4
	static void _0xB656CBA013937D05(Any p0, BOOL p1) { invoke<Void>(0xB656CBA013937D05, p0, p1); } // 0xB656CBA013937D05 0xFBDBE374
	static Any _0xCB1538A533E34990(float p0, float p1, float p2, float p3, float p4, float p5, BOOL p6, BOOL p7) { return invoke<Any>(0xCB1538A533E34990, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xCB1538A533E34990
	static void _0x93357AC0BC31BD1D(Any p0, BOOL p1) { invoke<Void>(0x93357AC0BC31BD1D, p0, p1); } // 0x93357AC0BC31BD1D
	static void ENABLE_TENNIS_MODE(Ped ped, BOOL toggle, BOOL p2) { invoke<Void>(0x5E55AEB6A8B82404, ped, toggle, p2); } // 0x5E55AEB6A8B82404 0x0BD3F9EC
	static BOOL IS_TENNIS_MODE(Ped ped) { return invoke<BOOL>(0xD8A94A9D6E0BED69, ped); } // 0xD8A94A9D6E0BED69 0x04A947BA
	static void _0xA3D6E64E82B7B262(Any p0, Any* p1, Any* p2, float p3, float p4, BOOL p5) { invoke<Void>(0xA3D6E64E82B7B262, p0, p1, p2, p3, p4, p5); } // 0xA3D6E64E82B7B262 0xC20A7D2B
	static BOOL _0xDB08D66C754BE42F(Any p0) { return invoke<BOOL>(0xDB08D66C754BE42F, p0); } // 0xDB08D66C754BE42F 0x8501E727
	static BOOL _0xCA5069C40D57243F(Any p0) { return invoke<BOOL>(0xCA5069C40D57243F, p0); } // 0xCA5069C40D57243F 0x1A332D2D
	static BOOL _0xADAB3672EB7DED2A(Any p0) { return invoke<BOOL>(0xADAB3672EB7DED2A, p0); } // 0xADAB3672EB7DED2A
	static void _0x0A6FFDDA426DE2BB(Any p0, Any p1, float p2, float p3, float p4, BOOL p5) { invoke<Void>(0x0A6FFDDA426DE2BB, p0, p1, p2, p3, p4, p5); } // 0x0A6FFDDA426DE2BB 0x0C8865DF
	static void _0xDAB66D2A0C651121(Any p0, char* p1, float p2) { invoke<Void>(0xDAB66D2A0C651121, p0, p1, p2); } // 0xDAB66D2A0C651121 0x49F977A9
	static void _0x6281B0F1D9275D8E(Any p0, Any p1, Any p2) { invoke<Void>(0x6281B0F1D9275D8E, p0, p1, p2); } // 0x6281B0F1D9275D8E 0x6F009E33
	static void RESET_DISPATCH_IDEAL_SPAWN_DISTANCE() { invoke<Void>(0xD4F40BAC3B3B974C); } // 0xD4F40BAC3B3B974C 0xDA65ECAA
	static void SET_DISPATCH_IDEAL_SPAWN_DISTANCE(float p0) { invoke<Void>(0xF49AA4E660769C3E, p0); } // 0xF49AA4E660769C3E 0x6283BE32
	static void SET_DISPATCH_TIME_BETWEEN_SPAWN_ATTEMPTS(Any p0, float p1) { invoke<Void>(0x21EED9819B05969E, p0, p1); } // 0x21EED9819B05969E 0xABADB709
	static void SET_DISPATCH_TIME_BETWEEN_SPAWN_ATTEMPTS_MULTIPLIER(Any p0, float p1) { invoke<Void>(0x073C5B90026C1CDF, p0, p1); } // 0x073C5B90026C1CDF 0x1C996BCD
	static Any _0x47EAD17E2322838B(float p0, float p1, float p2, float p3, float p4, float p5, float p6) { return invoke<Any>(0x47EAD17E2322838B, p0, p1, p2, p3, p4, p5, p6); } // 0x47EAD17E2322838B 0xF557BAF9
	static Any _0xABBB36AE5B19B038(float p0, float p1, float p2, float p3) { return invoke<Any>(0xABBB36AE5B19B038, p0, p1, p2, p3); } // 0xABBB36AE5B19B038
	static void REMOVE_DISPATCH_SPAWN_BLOCKING_AREA(Any p0) { invoke<Void>(0x227D15306DE7640D, p0); } // 0x227D15306DE7640D 0xA8D2FB92
	static void RESET_DISPATCH_SPAWN_BLOCKING_AREAS() { invoke<Void>(0x0E03C51CCAA67BEA); } // 0x0E03C51CCAA67BEA 0x9A17F835
	static void _0x636F144900FC76FD() { invoke<Void>(0x636F144900FC76FD); } // 0x636F144900FC76FD 0xE0C9307E
	static void _0xD33D87E93A2C9410(Any p0, Any p1) { invoke<Void>(0xD33D87E93A2C9410, p0, p1); } // 0xD33D87E93A2C9410 0xA0D8C749
	static void _0x2942DC5709E35A7E(Any p0, Any p1, Any p2) { invoke<Void>(0x2942DC5709E35A7E, p0, p1, p2); } // 0x2942DC5709E35A7E 0x24A4E0B2
	static void _0xD1E7A83C815304C9() { invoke<Void>(0xD1E7A83C815304C9); } // 0xD1E7A83C815304C9 0x66C3C59C
	static void _0x37E45C3155551029(BOOL p0) { invoke<Void>(0x37E45C3155551029, p0); } // 0x37E45C3155551029 0xD9660339
	static void _0xCB91C0BA3439C5BF(int p0, char* windowTitle, Any* p2, char* defaultText, char* defaultConcat1, char* defaultConcat2, char* defaultConcat3, char* defaultConcat4, char* defaultConcat5, char* defaultConcat6, char* defaultConcat7, int maxInputLength) { invoke<Void>(0xCB91C0BA3439C5BF, p0, windowTitle, p2, defaultText, defaultConcat1, defaultConcat2, defaultConcat3, defaultConcat4, defaultConcat5, defaultConcat6, defaultConcat7, maxInputLength); } // 0xCB91C0BA3439C5BF 0xD2688412
	static void DISPLAY_ONSCREEN_KEYBOARD(int p0, char* windowTitle, char* p2, char* defaultText, char* defaultConcat1, char* defaultConcat2, char* defaultConcat3, int maxInputLength) { invoke<Void>(0xBD3B904ED0023B7F, p0, windowTitle, p2, defaultText, defaultConcat1, defaultConcat2, defaultConcat3, maxInputLength); } // 0xBD3B904ED0023B7F 0xAD99F2CE
	static int UPDATE_ONSCREEN_KEYBOARD() { return invoke<int>(0x8F013F929677E75D); } // 0x8F013F929677E75D 0x23D0A1CE
	static char* GET_ONSCREEN_KEYBOARD_RESULT() { return invoke<char*>(0xE26771A3D90DD1DF); } // 0xE26771A3D90DD1DF 0x44828FB3
	static void _0x1EAE7A06BF9A9990(int p0) { invoke<Void>(0x1EAE7A06BF9A9990, p0); } // 0x1EAE7A06BF9A9990 0x3301EA47
	static void _0x2873E2276C3D0384(Hash hash, BOOL p1) { invoke<Void>(0x2873E2276C3D0384, hash, p1); } // 0x2873E2276C3D0384 0x42B484ED
	static void _0xEE82D68720ACF6FA(int p0, BOOL p1) { invoke<Void>(0xEE82D68720ACF6FA, p0, p1); } // 0xEE82D68720ACF6FA 0x8F60366E
	static void SET_EXPLOSIVE_AMMO_THIS_FRAME(Player player) { invoke<Void>(0x11CD732DC8DC84A1, player); } // 0x11CD732DC8DC84A1 0x2EAFA1D1
	static void SET_FIRE_AMMO_THIS_FRAME(Player player) { invoke<Void>(0x589B148F0D998C4C, player); } // 0x589B148F0D998C4C 0x7C18FC8A
	static void SET_EXPLOSIVE_MELEE_THIS_FRAME(Player player) { invoke<Void>(0x54CB1C87BB13C9D2, player); } // 0x54CB1C87BB13C9D2 0x96663D56
	static void SET_SUPER_JUMP_THIS_FRAME(Player player) { invoke<Void>(0x4CA76B1CA16E74F4, player); } // 0x4CA76B1CA16E74F4 0x86745EF3
	static BOOL _0x8DC7318AEB3586A1() { return invoke<BOOL>(0x8DC7318AEB3586A1); } // 0x8DC7318AEB3586A1 0xC3C10FCC
	static void _0xAA1220FB49AB9DC2() { invoke<Void>(0xAA1220FB49AB9DC2); } // 0xAA1220FB49AB9DC2 0x054EC103
	static Any _0x8B57B9443E19F940() { return invoke<Any>(0x8B57B9443E19F940); } // 0x8B57B9443E19F940 0x46B5A15C
	static void _0xA5AA6D05AAD65137() { invoke<Void>(0xA5AA6D05AAD65137); } // 0xA5AA6D05AAD65137
	static void _RESET_LOCALPLAYER_STATE() { invoke<Void>(0xA1868F03EFF4D485); } // 0xA1868F03EFF4D485 0x5D209F25
	static void _0x6B015B1C54825EB0(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x6B015B1C54825EB0, p0, p1, p2, p3); } // 0x6B015B1C54825EB0 0x2D33F15A
	static void _0x02D4BD8916291A5D() { invoke<Void>(0x02D4BD8916291A5D); } // 0x02D4BD8916291A5D 0xDF99925C
	static void _0x55E057B3942DBF26(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x55E057B3942DBF26, p0, p1, p2, p3); } // 0x55E057B3942DBF26 0xA27F4472
	static BOOL _0x47AA0796FEB6544C(Any p0, Any* p1, Any* p2) { return invoke<BOOL>(0x47AA0796FEB6544C, p0, p1, p2); } // 0x47AA0796FEB6544C 0x07FF553F
	static void _0xF1D601B892142AAE() { invoke<Void>(0xF1D601B892142AAE); } // 0xF1D601B892142AAE
	static void _0xD8F12333639ADB65() { invoke<Void>(0xD8F12333639ADB65); } // 0xD8F12333639ADB65
	static void _0x558DF102DE8F6027() { invoke<Void>(0x558DF102DE8F6027); } // 0x558DF102DE8F6027
	static void _0x05A0FB4A03039A94() { invoke<Void>(0x05A0FB4A03039A94); } // 0x05A0FB4A03039A94
	static Any _0x50B7F97704A39FC9() { return invoke<Any>(0x50B7F97704A39FC9); } // 0x50B7F97704A39FC9
	static Any _0xBA2FEF43735E7CE3() { return invoke<Any>(0xBA2FEF43735E7CE3); } // 0xBA2FEF43735E7CE3
	static Any _0x1199292F01DCFBB5() { return invoke<Any>(0x1199292F01DCFBB5); } // 0x1199292F01DCFBB5
	static Any _0x05C0416E99B5C11E() { return invoke<Any>(0x05C0416E99B5C11E); } // 0x05C0416E99B5C11E
	static Any _0xB12593A593A2C9E5() { return invoke<Any>(0xB12593A593A2C9E5); } // 0xB12593A593A2C9E5
	static void _FORCE_SOCIAL_CLUB_UPDATE() { invoke<Void>(0x7336225FB5843F5F); } // 0x7336225FB5843F5F
	static Any _0xA8E27B423E3D3FF7() { return invoke<Any>(0xA8E27B423E3D3FF7); } // 0xA8E27B423E3D3FF7
	static void _0xA763DDA29327BB02() { invoke<Void>(0xA763DDA29327BB02); } // 0xA763DDA29327BB02
	static BOOL _0xF2B825D05B494D4C() { return invoke<BOOL>(0xF2B825D05B494D4C); } // 0xF2B825D05B494D4C
	static Any _0xEC7C0578CC21F6DE() { return invoke<Any>(0xEC7C0578CC21F6DE); } // 0xEC7C0578CC21F6DE
	static void _0x970A161B1DB6E69D(BOOL p0) { invoke<Void>(0x970A161B1DB6E69D, p0); } // 0x970A161B1DB6E69D
	static BOOL _0x9BDD8FB0A8A09F89() { return invoke<BOOL>(0x9BDD8FB0A8A09F89); } // 0x9BDD8FB0A8A09F89
	static void _0x32BAED5B76ABCC9D(BOOL p0) { invoke<Void>(0x32BAED5B76ABCC9D, p0); } // 0x32BAED5B76ABCC9D
	static void _0x76F9BD3E2CC5E49E() { invoke<Void>(0x76F9BD3E2CC5E49E); } // 0x76F9BD3E2CC5E49E
	static Any _0x800431CFB358AFCF() { return invoke<Any>(0x800431CFB358AFCF); } // 0x800431CFB358AFCF
}

namespace AUDIO
{
	static void PLAY_PED_RINGTONE(char* ringtoneName, Ped ped, BOOL p2) { invoke<Void>(0xC0A36C4A908A5D43, ringtoneName, ped, p2); } // 0xC0A36C4A908A5D43 0x1D530E47
	static BOOL IS_PED_RINGTONE_PLAYING(Ped ped) { return invoke<BOOL>(0xDD4476199A5FDBBC, ped); } // 0xDD4476199A5FDBBC 0xFE576EE4
	static void STOP_PED_RINGTONE(Ped ped) { invoke<Void>(0xD54BF47621499950, ped); } // 0xD54BF47621499950 0xFEEA107C
	static BOOL IS_MOBILE_PHONE_CALL_ONGOING() { return invoke<BOOL>(0x3ED8A07C6FA41E1B); } // 0x3ED8A07C6FA41E1B 0x4ED1400A
	static Any _0x58DB14A0C693C660() { return invoke<Any>(0x58DB14A0C693C660); } // 0x58DB14A0C693C660 0x16FB88B5
	static void CREATE_NEW_SCRIPTED_CONVERSATION() { invoke<Void>(0x2EAE4D4764ADC4B5); } // 0x2EAE4D4764ADC4B5 0xB2BC25F8
	static void ADD_LINE_TO_CONVERSATION(Any p0, Any* p1, Any* p2, Any p3, Any p4, BOOL p5, BOOL p6, BOOL p7, BOOL p8, Any p9, BOOL p10, BOOL p11, BOOL p12) { invoke<Void>(0x999BA34C412E3B34, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); } // 0x999BA34C412E3B34 0x96CD0513
	static void ADD_PED_TO_CONVERSATION(Any p0, Any p1, char* p2) { invoke<Void>(0xD893946689A76D8F, p0, p1, p2); } // 0xD893946689A76D8F 0xF8D5EB86
	static void _0x9074D24A8A610983(Any p0, float p1, float p2, float p3) { invoke<Void>(0x9074D24A8A610983, p0, p1, p2, p3); } // 0x9074D24A8A610983 0x73C6F979
	static void _0x1EB71BA83BC60319(Any p0, Any p1) { invoke<Void>(0x1EB71BA83BC60319, p0, p1); } // 0x1EB71BA83BC60319 0x88203DDA
	static void SET_MICROPHONE_POSITION(BOOL p0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) { invoke<Void>(0xDAF9F64A3E5E501D, p0, x1, y1, z1, x2, y2, z2, x3, y3, z3); } // 0xDAF9F64A3E5E501D 0xAD7BB191
	static void _0x263EED6868F6421C(BOOL p0) { invoke<Void>(0x263EED6868F6421C, p0); } // 0x263EED6868F6421C 0x1193ED6E
	static void _0x08F58F314645FF2D(BOOL p0) { invoke<Void>(0x08F58F314645FF2D, p0); } // 0x08F58F314645FF2D
	static void START_SCRIPT_PHONE_CONVERSATION(BOOL p0, BOOL p1) { invoke<Void>(0x35ABFBDBACB79654, p0, p1); } // 0x35ABFBDBACB79654 0x38E42D07
	static void PRELOAD_SCRIPT_PHONE_CONVERSATION(BOOL p0, BOOL p1) { invoke<Void>(0x8B4DC5EBB154F21F, p0, p1); } // 0x8B4DC5EBB154F21F 0x9ACB213A
	static void START_SCRIPT_CONVERSATION(BOOL p0, BOOL p1, BOOL p2, BOOL p3) { invoke<Void>(0x41ACFA25553A5732, p0, p1, p2, p3); } // 0x41ACFA25553A5732 0xE5DE7D9D
	static void PRELOAD_SCRIPT_CONVERSATION(BOOL p0, BOOL p1, BOOL p2, BOOL p3) { invoke<Void>(0x34CA490C757DC319, p0, p1, p2, p3); } // 0x34CA490C757DC319 0xDDF5C579
	static void START_PRELOADED_CONVERSATION() { invoke<Void>(0xFBB765291A96B687); } // 0xFBB765291A96B687 0xA170261B
	static Any _0xC4AC39C3BC732D73() { return invoke<Any>(0xC4AC39C3BC732D73); } // 0xC4AC39C3BC732D73 0x336F3D35
	static BOOL IS_SCRIPTED_CONVERSATION_ONGOING() { return invoke<BOOL>(0x55C74612BE548D78); } // 0x55C74612BE548D78 0xCB8FD96F
	static BOOL IS_SCRIPTED_CONVERSATION_LOADED() { return invoke<BOOL>(0xE7DCACE4E2143116); } // 0xE7DCACE4E2143116 0xE1870EA9
	static Any GET_CURRENT_SCRIPTED_CONVERSATION_LINE() { return invoke<Any>(0xD8D502167864F70D); } // 0xD8D502167864F70D 0x9620E41F
	static void PAUSE_SCRIPTED_CONVERSATION(BOOL p0) { invoke<Void>(0xC05FD77F568965EB, p0); } // 0xC05FD77F568965EB 0xE2C9C6F8
	static void RESTART_SCRIPTED_CONVERSATION() { invoke<Void>(0x5FB0B609B3A49840); } // 0x5FB0B609B3A49840 0x6CB24B56
	static Any STOP_SCRIPTED_CONVERSATION(BOOL p0) { return invoke<Any>(0x660E8E7836E95077, p0); } // 0x660E8E7836E95077 0xAB77DA7D
	static void SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE() { invoke<Void>(0x7E2A2E92B575F006); } // 0x7E2A2E92B575F006 0x85C98304
	static void INTERRUPT_CONVERSATION(Any p0, Any* p1, Any* p2) { invoke<Void>(0x6DBB68211C17EAFC, p0, p1, p2); } // 0x6DBB68211C17EAFC 0xF3A67AF3
	static void _0xC8688B0F3E1C3C08(Ped p0, char* p1, char* p2) { invoke<Void>(0xC8688B0F3E1C3C08, p0, p1, p2); } // 0xC8688B0F3E1C3C08
	static Any _0x3E27923433FC790D(Any* p0) { return invoke<Any>(0x3E27923433FC790D, p0); } // 0x3E27923433FC790D 0xB58B8FF3
	static void _0x98F16FB53C968C64(BOOL p0) { invoke<Void>(0x98F16FB53C968C64, p0); } // 0x98F16FB53C968C64 0x789D8C6C
	static void REGISTER_SCRIPT_WITH_AUDIO(Any p0) { invoke<Void>(0x8D25D78C081AB5E2, p0); } // 0x8D25D78C081AB5E2 0xA6203643
	static void UNREGISTER_SCRIPT_WITH_AUDIO() { invoke<Void>(0xC40055F09E9CA169); } // 0xC40055F09E9CA169 0x66728EFE
	static BOOL REQUEST_MISSION_AUDIO_BANK(char* p0, BOOL p1) { return invoke<BOOL>(0xD5298FB91FAC3479, p0, p1); } // 0xD5298FB91FAC3479 0x916E37CA
	static BOOL REQUEST_AMBIENT_AUDIO_BANK(char* p0, BOOL p1) { return invoke<BOOL>(0xE22CF1078AD4E111, p0, p1); } // 0xE22CF1078AD4E111 0x23C88BC7
	static BOOL REQUEST_SCRIPT_AUDIO_BANK(char* p0, BOOL p1) { return invoke<BOOL>(0x985A2515CBAF7290, p0, p1); } // 0x985A2515CBAF7290 0x21322887
	static Any HINT_AMBIENT_AUDIO_BANK(Any p0, Any p1) { return invoke<Any>(0xCEB0EE315D1A03DB, p0, p1); } // 0xCEB0EE315D1A03DB 0xF1850DDC
	static Any HINT_SCRIPT_AUDIO_BANK(Any p0, Any p1) { return invoke<Any>(0x00F6703CD2E75759, p0, p1); } // 0x00F6703CD2E75759 0x41FA0E51
	static void RELEASE_MISSION_AUDIO_BANK() { invoke<Void>(0x54F450DAA07322DB); } // 0x54F450DAA07322DB 0x8E8824C7
	static void RELEASE_AMBIENT_AUDIO_BANK() { invoke<Void>(0xD7C82655D8064344); } // 0xD7C82655D8064344 0x8C938784
	static void RELEASE_NAMED_SCRIPT_AUDIO_BANK(char* audioBank) { invoke<Void>(0xD293EE6E60B2813E, audioBank); } // 0xD293EE6E60B2813E 0x16707ABC
	static void RELEASE_SCRIPT_AUDIO_BANK() { invoke<Void>(0x9A27E67BCD441C6E); } // 0x9A27E67BCD441C6E 0x22F865E5
	static void _0x115BE5011D8AAE08() { invoke<Void>(0x115BE5011D8AAE08); } // 0x115BE5011D8AAE08 0xA58BBF4F
	static void _0x13F4C67AF710AEF0() { invoke<Void>(0x13F4C67AF710AEF0); } // 0x13F4C67AF710AEF0
	static int GET_SOUND_ID() { return invoke<int>(0x3DF2C10FD29336A3); } // 0x3DF2C10FD29336A3 0x6AE0AD56
	static void RELEASE_SOUND_ID(int soundId) { invoke<Void>(0xB47CC6339ADB0B67, soundId); } // 0xB47CC6339ADB0B67 0x9C080899
	static void PLAY_SOUND(int soundId, char* audioName, char* audioRef, BOOL p3, Any p4, BOOL p5) { invoke<Void>(0x0660C416D5671969, soundId, audioName, audioRef, p3, p4, p5); } // 0x0660C416D5671969 0xB6E1917F
	static void PLAY_SOUND_FRONTEND(int soundId, char* audioName, char* audioRef, BOOL p3) { invoke<Void>(0x4988C48537D1AE4F, soundId, audioName, audioRef, p3); } // 0x4988C48537D1AE4F 0x2E458F74
	static void _0x97A0FE27584E764F(char* p0, char* soundset) { invoke<Void>(0x97A0FE27584E764F, p0, soundset); } // 0x97A0FE27584E764F 0xC70E6CFA
	static void PLAY_SOUND_FROM_ENTITY(int soundId, char* audioName, Entity entity, char* audioRef, BOOL p4, Any p5) { invoke<Void>(0xEE4ED1F88396A702, soundId, audioName, entity, audioRef, p4, p5); } // 0xEE4ED1F88396A702 0x95AE00F8
	static void PLAY_SOUND_FROM_COORD(int soundId, char* audioName, float x, float y, float z, char* audioRef, BOOL p6, Any p7, BOOL p8) { invoke<Void>(0x4876B73C5A534970, soundId, audioName, x, y, z, audioRef, p6, p7, p8); } // 0x4876B73C5A534970 0xCAD3E2D5
	static void STOP_SOUND(int soundId) { invoke<Void>(0x2EB37CDED0E516F3, soundId); } // 0x2EB37CDED0E516F3 0xCD7F4030
	static int GET_NETWORK_ID_FROM_SOUND_ID(int soundId) { return invoke<int>(0x1ADCA8D3EE56F1EB, soundId); } // 0x1ADCA8D3EE56F1EB 0x2576F610
	static int GET_SOUND_ID_FROM_NETWORK_ID(int netId) { return invoke<int>(0x71524EAB5C25CA49, netId); } // 0x71524EAB5C25CA49 0xD064D4DC
	static void SET_VARIABLE_ON_SOUND(int soundId, Any* p1, float p2) { invoke<Void>(0x5209B7FDA124FCCA, soundId, p1, p2); } // 0x5209B7FDA124FCCA 0x606EE5FA
	static void SET_VARIABLE_ON_STREAM(char* p0, float p1) { invoke<Void>(0x88CF3D6AA6CDDC06, p0, p1); } // 0x88CF3D6AA6CDDC06 0xF67BB44C
	static void OVERRIDE_UNDERWATER_STREAM(Any* p0, BOOL p1) { invoke<Void>(0x6A4E9F4F5B853C41, p0, p1); } // 0x6A4E9F4F5B853C41 0x9A083B7E
	static void _0x0DF48721798154C5(Any* p0, float p1) { invoke<Void>(0x0DF48721798154C5, p0, p1); } // 0x0DF48721798154C5 0x62D026BE
	static BOOL HAS_SOUND_FINISHED(int soundId) { return invoke<BOOL>(0x7DFE463FA760D738, soundId); } // 0x7DFE463FA760D738 0xE85AEC2E
	static void _PLAY_AMBIENT_SPEECH1(Ped ped, char* speechName, char* speechParam) { invoke<Void>(0xE4C6605BC74297B4, ped, speechName, speechParam); } // 0xE4C6605BC74297B4 0x5C57B85D
	static void _PLAY_AMBIENT_SPEECH2(Ped ped, char* speechName, char* speechParam) { invoke<Void>(0x0AB804DC85FC3087, ped, speechName, speechParam); } // 0x0AB804DC85FC3087 0x444180DB
	static void _PLAY_AMBIENT_SPEECH_WITH_VOICE(Ped p0, char* speechName, char* voiceName, char* speechParam, BOOL p4) { invoke<Void>(0xECF05B7D463A3321, p0, speechName, voiceName, speechParam, p4); } // 0xECF05B7D463A3321 0x8386AE28
	static void _PLAY_AMBIENT_SPEECH_AT_COORDS(char* p0, char* p1, float p2, float p3, float p4, char* p5) { invoke<Void>(0x5D009C66BC2808A7, p0, p1, p2, p3, p4, p5); } // 0x5D009C66BC2808A7 0xA1A1402E
	static void OVERRIDE_TREVOR_RAGE(Any* p0) { invoke<Void>(0xEA79F3407B338F80, p0); } // 0xEA79F3407B338F80 0x05B9B5CF
	static void RESET_TREVOR_RAGE() { invoke<Void>(0x2C4FF229488DF50F); } // 0x2C4FF229488DF50F 0xE80CF0D4
	static void SET_PLAYER_ANGRY(Ped playerPed, BOOL disabled) { invoke<Void>(0xEA54808EC915AA8C, playerPed, disabled); } // 0xEA54808EC915AA8C 0x782CA58D
	static void PLAY_PAIN(int painID, float p1, int p2) { invoke<Void>(0x4A08C00D2BE77397, painID, p1, p2); } // 0x4A08C00D2BE77397 0x874BD6CB
	static void _0x2156AF318C71023B(Any* p0) { invoke<Void>(0x2156AF318C71023B, p0); } // 0x2156AF318C71023B 0x59A3A17D
	static void _0x80D24361A541257A(Any* p0) { invoke<Void>(0x80D24361A541257A, p0); } // 0x80D24361A541257A 0x0E387BFE
	static void SET_AMBIENT_VOICE_NAME(Ped ped, char* name) { invoke<Void>(0xA0E70AC53ABAB207, ped, name); } // 0xA0E70AC53ABAB207 0xBD2EA1A1
	static void _0xDBB60F8B09988B94(Ped ped) { invoke<Void>(0xDBB60F8B09988B94, ped); } // 0xDBB60F8B09988B94
	static void _0x9D6CC2840C95D30E(Any p0, Any p1) { invoke<Void>(0x9D6CC2840C95D30E, p0, p1); } // 0x9D6CC2840C95D30E
	static void _0xF9F382A9F484C82A(Any p0, BOOL p1) { invoke<Void>(0xF9F382A9F484C82A, p0, p1); } // 0xF9F382A9F484C82A
	static void _0x0DA5E22AA90AA1BC(Ped ped) { invoke<Void>(0x0DA5E22AA90AA1BC, ped); } // 0x0DA5E22AA90AA1BC
	static void STOP_CURRENT_PLAYING_AMBIENT_SPEECH(Ped p0) { invoke<Void>(0xFDD2A35153492430, p0); } // 0xFDD2A35153492430 0xBB8E64BF
	static BOOL IS_AMBIENT_SPEECH_PLAYING(Ped p0) { return invoke<BOOL>(0x872115A210435770, p0); } // 0x872115A210435770 0x1972E8AA
	static BOOL IS_SCRIPTED_SPEECH_PLAYING(Any p0) { return invoke<BOOL>(0x68F6AE14C052BF51, p0); } // 0x68F6AE14C052BF51 0x2C653904
	static BOOL IS_ANY_SPEECH_PLAYING(Ped ped) { return invoke<BOOL>(0x0E6DD0328435009E, ped); } // 0x0E6DD0328435009E 0x2B74A6D6
	static BOOL _0x1F78760E64EABDCD(Any p0, Any* p1, BOOL p2) { return invoke<BOOL>(0x1F78760E64EABDCD, p0, p1, p2); } // 0x1F78760E64EABDCD 0x8BD5F11E
	static BOOL IS_PED_IN_CURRENT_CONVERSATION(Ped ped) { return invoke<BOOL>(0x0850C577FB0C352A, ped); } // 0x0850C577FB0C352A 0x7B2F0743
	static void SET_PED_IS_DRUNK(Ped ped, BOOL toggle) { invoke<Void>(0x2B8E285BD54DCE56, ped, toggle); } // 0x2B8E285BD54DCE56 0xD2EA77A3
	static void _0x91FA3C24CDEB6DC9(Any p0, Any p1, Any* p2) { invoke<Void>(0x91FA3C24CDEB6DC9, p0, p1, p2); } // 0x91FA3C24CDEB6DC9 0x498849F3
	static BOOL _0x0E1954BB7905A8B9(Any p0) { return invoke<BOOL>(0x0E1954BB7905A8B9, p0); } // 0x0E1954BB7905A8B9 0x0CBAF2EF
	static void SET_ANIMAL_MOOD(Any p0, Any p1) { invoke<Void>(0x50763124173CBE5C, p0, p1); } // 0x50763124173CBE5C 0x3EA7C6CB
	static BOOL IS_MOBILE_PHONE_RADIO_ACTIVE() { return invoke<BOOL>(0x5D065E0FD7D34972); } // 0x5D065E0FD7D34972 0x6E502A5B
	static void SET_MOBILE_PHONE_RADIO_STATE(BOOL state) { invoke<Void>(0x63C714DF1D16D06A, state); } // 0x63C714DF1D16D06A 0xE1E0ED34
	static int GET_PLAYER_RADIO_STATION_INDEX() { return invoke<int>(0x04F0F99162081258); } // 0x04F0F99162081258 0x1C4946AC
	static char* GET_PLAYER_RADIO_STATION_NAME() { return invoke<char*>(0x36F10B474C24BFCE); } // 0x36F10B474C24BFCE 0xD909C107
	static char* GET_RADIO_STATION_NAME(int radioStation) { return invoke<char*>(0xE0A4834569DED46F, radioStation); } // 0xE0A4834569DED46F 0x3DF493BC
	static Any GET_PLAYER_RADIO_STATION_GENRE() { return invoke<Any>(0x13705606E6F80E32); } // 0x13705606E6F80E32 0x872CF0EA
	static BOOL IS_RADIO_RETUNING() { return invoke<BOOL>(0x4FF4418C82B0098A); } // 0x4FF4418C82B0098A 0xCF29097B
	static Any _0x5DFA132A185312B1() { return invoke<Any>(0x5DFA132A185312B1); } // 0x5DFA132A185312B1
	static void _0xE29F5B65F0D09371() { invoke<Void>(0xE29F5B65F0D09371); } // 0xE29F5B65F0D09371 0x53DB6994
	static void _0x7E1B37E5A9DBF910() { invoke<Void>(0x7E1B37E5A9DBF910); } // 0x7E1B37E5A9DBF910 0xD70ECC80
	static void SET_RADIO_TO_STATION_NAME(char* stationName) { invoke<Void>(0xF216A70B97EEFD1C, stationName); } // 0xF216A70B97EEFD1C 0x7B36E35E
	static void SET_VEH_RADIO_STATION(Vehicle vehicle, char* radioStation) { invoke<Void>(0x2F40A4997A9C988D, vehicle, radioStation); } // 0x2F40A4997A9C988D 0xE391F55F
	static void _0x06AB700EDFB23155(Vehicle vehicle) { invoke<Void>(0x06AB700EDFB23155, vehicle); } // 0x06AB700EDFB23155 0x7ABB89D2
	static void SET_EMITTER_RADIO_STATION(char* emitterName, char* radioStation) { invoke<Void>(0x3BCA5CED6E64EFBE, emitterName, radioStation); } // 0x3BCA5CED6E64EFBE 0x87431585
	static void SET_STATIC_EMITTER_ENABLED(char* emitterName, BOOL toggle) { invoke<Void>(0x396A8DEFD6DBA5FC, emitterName, toggle); } // 0x396A8DEFD6DBA5FC 0x91F72E92
	static void SET_RADIO_TO_STATION_INDEX(int radioStation) { invoke<Void>(0x2DED14799A1D7B5B, radioStation); } // 0x2DED14799A1D7B5B 0x1D82766D
	static void SET_FRONTEND_RADIO_ACTIVE(BOOL active) { invoke<Void>(0x14416EDB64E4D05E, active); } // 0x14416EDB64E4D05E 0xB1172075
	static void UNLOCK_MISSION_NEWS_STORY(int newsStory) { invoke<Void>(0x92C7309E11785E72, newsStory); } // 0x92C7309E11785E72 0xCCD9ABE4
	static int GET_NUMBER_OF_PASSENGER_VOICE_VARIATIONS(Any p0) { return invoke<int>(0x6AC50891F506AFDE, p0); } // 0x6AC50891F506AFDE 0x27305D37
	static int GET_AUDIBLE_MUSIC_TRACK_TEXT_ID() { return invoke<int>(0x77856D4797118472); } // 0x77856D4797118472 0xA2B88CA7
	static void PLAY_END_CREDITS_MUSIC(BOOL play) { invoke<Void>(0x5431FD7AECC44BE7, play); } // 0x5431FD7AECC44BE7 0x8E88B3CC
	static void SKIP_RADIO_FORWARD() { invoke<Void>(0x52E7E49B77020E8E); } // 0x52E7E49B77020E8E 0x10D36630
	static void FREEZE_RADIO_STATION(char* radioStation) { invoke<Void>(0x8128A2C66B01A00D, radioStation); } // 0x8128A2C66B01A00D 0x286BF543
	static void UNFREEZE_RADIO_STATION(char* radioStation) { invoke<Void>(0xC667DC46FB558FBF, radioStation); } // 0xC667DC46FB558FBF 0x4D46202C
	static void SET_RADIO_AUTO_UNFREEZE(BOOL p0) { invoke<Void>(0x90B08B8088B40212, p0); } // 0x90B08B8088B40212 0xA40196BF
	static void SET_INITIAL_PLAYER_STATION(char* radioStation) { invoke<Void>(0x7DA8E8A0213C87AB, radioStation); } // 0x7DA8E8A0213C87AB 0x9B069233
	static void SET_USER_RADIO_CONTROL_ENABLED(BOOL p0) { invoke<Void>(0x4CE603708D103834, p0); } // 0x4CE603708D103834 0x52E054CE
	static void SET_RADIO_TRACK(char* radioStation, char* radioTrack) { invoke<Void>(0x3DAEDE11E8191422, radioStation, radioTrack); } // 0x3DAEDE11E8191422 0x76E96212
	static void SET_VEHICLE_RADIO_LOUD(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x4A34751849E57DD5, vehicle, toggle); } // 0x4A34751849E57DD5 0x8D9EDD99
	static BOOL _IS_VEHICLE_RADIO_LOUD(Vehicle vehicle) { return invoke<BOOL>(0x948BBD3F5E831A84, vehicle); } // 0x948BBD3F5E831A84 0xCBA99F4A
	static void SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(BOOL Toggle) { invoke<Void>(0xF1C11B6A9E7E70CC, Toggle); } // 0xF1C11B6A9E7E70CC 0x990085F0
	static BOOL _0xF684F1C341919221() { return invoke<BOOL>(0xF684F1C341919221); } // 0xF684F1C341919221 0x46B0C696
	static BOOL _0xD56476253BA11412() { return invoke<BOOL>(0xD56476253BA11412); } // 0xD56476253BA11412 0x2A3E5E8B
	static void SET_VEHICLE_RADIO_ENABLED(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x6CF1FECEFD66F69B, vehicle, toggle); } // 0x6CF1FECEFD66F69B 0x6F812CAB
	static void _0x16448E5C4DD8FEEF(char* radioStation, char* p1, BOOL p2) { invoke<Void>(0x16448E5C4DD8FEEF, radioStation, p1, p2); } // 0x16448E5C4DD8FEEF 0x128C3873
	static void _0xCBDC8F4397A4EF6D(char* radioStation) { invoke<Void>(0xCBDC8F4397A4EF6D, radioStation); } // 0xCBDC8F4397A4EF6D 0x1D766976
	static int _MAX_RADIO_STATION_INDEX() { return invoke<int>(0xAF919E368384882D); } // 0xAF919E368384882D 0xCC91FCF5
	static int FIND_RADIO_STATION_INDEX(int station) { return invoke<int>(0x5F925C7A27947700, station); } // 0x5F925C7A27947700 0xECA1512F
	static void _0x2E33B95DC3E9BF69(char* radioStation, BOOL p1) { invoke<Void>(0x2E33B95DC3E9BF69, radioStation, p1); } // 0x2E33B95DC3E9BF69 0xB1FF7137
	static void _0x4CC35896CB6B59C9(float p0) { invoke<Void>(0x4CC35896CB6B59C9, p0); } // 0x4CC35896CB6B59C9 0xC8B514E2
	static void _0x9AC17C9BA10A0D4B(char* radioStation, char* p1) { invoke<Void>(0x9AC17C9BA10A0D4B, radioStation, p1); } // 0x9AC17C9BA10A0D4B 0xBE998184
	static void _0xF7392B60E0C012F9(Any p0, BOOL p1) { invoke<Void>(0xF7392B60E0C012F9, p0, p1); } // 0xF7392B60E0C012F9 0x8AFC488D
	static void SET_AMBIENT_ZONE_STATE(Any* p0, BOOL p1, BOOL p2) { invoke<Void>(0x8788F758785FCC5A, p0, p1, p2); } // 0x8788F758785FCC5A 0x2849CAC9
	static void CLEAR_AMBIENT_ZONE_STATE(Any* p0, BOOL p1) { invoke<Void>(0xBE8E6D76CEC91C58, p0, p1); } // 0xBE8E6D76CEC91C58 0xCDFF3C82
	static void SET_AMBIENT_ZONE_LIST_STATE(Any* p0, BOOL p1, BOOL p2) { invoke<Void>(0xE4F11FC7E3A665A1, p0, p1, p2); } // 0xE4F11FC7E3A665A1 0xBF80B412
	static void CLEAR_AMBIENT_ZONE_LIST_STATE(Any* p0, BOOL p1) { invoke<Void>(0x0293465B5F810F3E, p0, p1); } // 0x0293465B5F810F3E 0x38B9B8D4
	static void SET_AMBIENT_ZONE_STATE_PERSISTENT(char* ambientZone, BOOL p1, BOOL p2) { invoke<Void>(0x911A2E2113B99B78, ambientZone, p1, p2); } // 0x911A2E2113B99B78 0xC1FFB672
	static void SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT(char* ambientZone, BOOL p1, BOOL p2) { invoke<Void>(0xD68AE97C94873C2B, ambientZone, p1, p2); } // 0xD68AE97C94873C2B 0x5F5A2605
	static BOOL IS_AMBIENT_ZONE_ENABLED(char* ambientZone) { return invoke<BOOL>(0xDD561B5D6E6FF92A, ambientZone); } // 0xDD561B5D6E6FF92A 0xBFABD872
	static void SET_CUTSCENE_AUDIO_OVERRIDE(char* p0) { invoke<Void>(0x2C503D6B42964498, p0); } // 0x2C503D6B42964498 0xCE1332B7
	static void GET_PLAYER_HEADSET_SOUND_ALTERNATE(char* p0, float p1) { invoke<Void>(0x63D698961E2FD474, p0, p1); } // 0x63D698961E2FD474 0xD63CF33A
	static Any PLAY_POLICE_REPORT(char* name, float p1) { return invoke<Any>(0x28A488BA07D3E43B, name, p1); } // 0x28A488BA07D3E43B 0x3F277B62
	static void _DISABLE_POLICE_REPORTS() { invoke<Void>(0xE7965A9B1E03096C); } // 0xE7965A9B1E03096C
	static void BLIP_SIREN(Vehicle vehicle) { invoke<Void>(0x6D15A2D3F14F3197, vehicle); } // 0x6D15A2D3F14F3197 0xC0EB6924
	static void OVERRIDE_VEH_HORN(Vehicle vehicle, BOOL mute, int p2) { invoke<Void>(0xA134DD4C60F49DCD, vehicle, mute, p2); } // 0xA134DD4C60F49DCD 0x2ACAB783
	static BOOL IS_HORN_ACTIVE(Vehicle vehicle) { return invoke<BOOL>(0x11FBFE0D19496697, vehicle); } // 0x11FBFE0D19496697 0x20E2BDD0
	static void SET_AGGRESSIVE_HORNS(BOOL toggle) { invoke<Void>(0x82ED97CBD659E983, toggle); } // 0x82ED97CBD659E983 0x01D6EABE
	static void _0x0104712955F38558(Any p0) { invoke<Void>(0x0104712955F38558, p0); } // 0x0104712955F38558 0x3C395AEE
	static void _0xE1B6AB991E19CE90(BOOL p0, BOOL p1) { invoke<Void>(0xE1B6AB991E19CE90, p0, p1); } // 0xE1B6AB991E19CE90 0x8CE63FA1
	static BOOL IS_STREAM_PLAYING() { return invoke<BOOL>(0x060BC3026AF615FC); } // 0x060BC3026AF615FC 0xF1F51A14
	static int GET_STREAM_PLAY_TIME() { return invoke<int>(0x6F2307FD3CC89CE8); } // 0x6F2307FD3CC89CE8 0xB4F0AD56
	static BOOL LOAD_STREAM(char* streamName, char* soundSet) { return invoke<BOOL>(0xAA18627F95EFB68D, streamName, soundSet); } // 0xAA18627F95EFB68D 0x0D89599D
	static BOOL LOAD_STREAM_WITH_START_OFFSET(char* streamName, int startOffset, char* soundSet) { return invoke<BOOL>(0x66AEDCD3E0332F27, streamName, startOffset, soundSet); } // 0x66AEDCD3E0332F27 0xE5B5745C
	static void PLAY_STREAM_FROM_PED(Ped ped) { invoke<Void>(0x5C028F86E853796F, ped); } // 0x5C028F86E853796F 0xA1D7FABE
	static void PLAY_STREAM_FROM_VEHICLE(Vehicle vehicle) { invoke<Void>(0x8C3C6C334DD85534, vehicle); } // 0x8C3C6C334DD85534 0xF8E4BDA2
	static void PLAY_STREAM_FROM_OBJECT(Object object) { invoke<Void>(0x4B7120F4F448EF8B, object); } // 0x4B7120F4F448EF8B 0xC5266BF7
	static void PLAY_STREAM_FRONTEND() { invoke<Void>(0x49219669A551245B); } // 0x49219669A551245B 0x2C2A16BC
	static void SPECIAL_FRONTEND_EQUAL(float x, float y, float z) { invoke<Void>(0x6A7F27626F5233EC, x, y, z); } // 0x6A7F27626F5233EC 0x6FE5D865
	static void STOP_STREAM() { invoke<Void>(0x4C21FD297A827B45); } // 0x4C21FD297A827B45 0xD1E364DE
	static void STOP_PED_SPEAKING(Ped ped, BOOL shaking) { invoke<Void>(0x22217EB6A9BAC6EE, ped, shaking); } // 0x22217EB6A9BAC6EE 0xFF92B49D
	static void DISABLE_PED_PAIN_AUDIO(Ped ped, BOOL toggle) { invoke<Void>(0xC114CBAEC75AFD9E, ped, toggle); } // 0xC114CBAEC75AFD9E 0x3B8E2D5F
	static BOOL IS_AMBIENT_SPEECH_DISABLED(Ped ped) { return invoke<BOOL>(0xF9B699BA2E522C1D, ped); } // 0xF9B699BA2E522C1D 0x109D1F89
	static void SET_SIREN_WITH_NO_DRIVER(Vehicle vehicle, BOOL set) { invoke<Void>(0x8D0713BFE7CB1CE1, vehicle, set); } // 0x8D0713BFE7CB1CE1 0x77182D58
	static void _SOUND_VEHICLE_HORN_THIS_FRAME(Vehicle vehicle) { invoke<Void>(0x5A2C4FFB2CA788C3, vehicle); } // 0x5A2C4FFB2CA788C3 0xDE8BA3CD
	static void SET_HORN_ENABLED(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xE697D30F88A8C19F, vehicle, toggle); } // 0xE697D30F88A8C19F 0x6EB92D05
	static void SET_AUDIO_VEHICLE_PRIORITY(Vehicle vehicle, Any p1) { invoke<Void>(0x8D90E6E11FFD7E4D, vehicle, p1); } // 0x8D90E6E11FFD7E4D 0x271A9766
	static void _0x22EDE45AD3F93D44(Any p0, float p1) { invoke<Void>(0x22EDE45AD3F93D44, p0, p1); } // 0x22EDE45AD3F93D44 0x2F0A16D1
	static void USE_SIREN_AS_HORN(Vehicle vehicle, BOOL toggle) { invoke<Void>(0xFF7DA2181809A93A, vehicle, toggle); } // 0xFF7DA2181809A93A 0xC6BC16F3
	static void _SET_VEHICLE_AUDIO(Vehicle vehicle, char* audioName) { invoke<Void>(0x597093333A72B521, vehicle, audioName); } // 0x597093333A72B521 0x33B0B007
	static void _0xA33506E6B08744B1(Any p0, char* p1, char* p2) { invoke<Void>(0xA33506E6B08744B1, p0, p1, p2); } // 0xA33506E6B08744B1 0x1C0C5E4C
	static void _0x1501D6F6456EC651(Any p0) { invoke<Void>(0x1501D6F6456EC651, p0); } // 0x1501D6F6456EC651
	static BOOL _0x8112370AF7DBC175(Any p0) { return invoke<BOOL>(0x8112370AF7DBC175, p0); } // 0x8112370AF7DBC175 0x6E660D3F
	static void _0x33488AFC613AF025(Any p0, float p1) { invoke<Void>(0x33488AFC613AF025, p0, p1); } // 0x33488AFC613AF025 0x23BE6432
	static void _0x48329CAC05D81A53(Any p0, float p1) { invoke<Void>(0x48329CAC05D81A53, p0, p1); } // 0x48329CAC05D81A53 0xE81FAC68
	static void _0x2B73B861944C66CF(Any p0, BOOL p1) { invoke<Void>(0x2B73B861944C66CF, p0, p1); } // 0x2B73B861944C66CF 0x9365E042
	static void _0xA2A28E3406482A49(Any p0, BOOL p1) { invoke<Void>(0xA2A28E3406482A49, p0, p1); } // 0xA2A28E3406482A49 0x2A60A90E
	static void SET_VEHICLE_BOOST_ACTIVE(Vehicle vehicle, BOOL Toggle) { invoke<Void>(0x13B4D93C30B00DFC, vehicle, Toggle); } // 0x13B4D93C30B00DFC 0x072F15F2
	static void _0xEBCEB6EDEBED7D55(Any p0, BOOL p1) { invoke<Void>(0xEBCEB6EDEBED7D55, p0, p1); } // 0xEBCEB6EDEBED7D55 0x934BE749
	static void _0x24BF221A8C29A517(Any p0, BOOL p1) { invoke<Void>(0x24BF221A8C29A517, p0, p1); } // 0x24BF221A8C29A517 0xE61110A2
	static void PLAY_VEHICLE_DOOR_OPEN_SOUND(Vehicle vehicle, int p1) { invoke<Void>(0xE161ACE2E474E7B8, vehicle, p1); } // 0xE161ACE2E474E7B8 0x84930330
	static void PLAY_VEHICLE_DOOR_CLOSE_SOUND(Vehicle vehicle, int p1) { invoke<Void>(0xA2E8AC29A465B820, vehicle, p1); } // 0xA2E8AC29A465B820 0xBA2CF407
	static void _0x12E2419FC4FF19C8(Vehicle vehicle, BOOL toggle) { invoke<Void>(0x12E2419FC4FF19C8, vehicle, toggle); } // 0x12E2419FC4FF19C8 0x563B635D
	static BOOL IS_GAME_IN_CONTROL_OF_MUSIC() { return invoke<BOOL>(0xCA9376E820A61C17); } // 0xCA9376E820A61C17 0x7643170D
	static void SET_GPS_ACTIVE(BOOL active) { invoke<Void>(0xF2EBA33AF1876A7C, active); } // 0xF2EBA33AF1876A7C 0x0FC3379A
	static void PLAY_MISSION_COMPLETE_AUDIO(char* audioName) { invoke<Void>(0x3FB911E0030D4BB5, audioName); } // 0x3FB911E0030D4BB5 0x3033EA1D
	static BOOL IS_MISSION_COMPLETE_PLAYING() { return invoke<BOOL>(0x977B627EDE114CDD); } // 0x977B627EDE114CDD 0x939982A1
	static Any _0x83B6D53A5AE06120() { return invoke<Any>(0x83B6D53A5AE06120); } // 0x83B6D53A5AE06120 0xCBE09AEC
	static void _0x1081B60ED8B73AB8(BOOL p0) { invoke<Void>(0x1081B60ED8B73AB8, p0); } // 0x1081B60ED8B73AB8 0xD2858D8A
	static BOOL START_AUDIO_SCENE(char* sceneName) { return invoke<BOOL>(0x4A5D4AD0FE6ACF73, sceneName); } // 0x4A5D4AD0FE6ACF73 0xE48D757B
	static void STOP_AUDIO_SCENE(char* scene) { invoke<Void>(0xB8CAC5F3774894A1, scene); } // 0xB8CAC5F3774894A1 0xA08D8C58
	static void STOP_AUDIO_SCENES() { invoke<Void>(0xF57BC08516FFE51F); } // 0xF57BC08516FFE51F 0xF6C7342A
	static BOOL IS_AUDIO_SCENE_ACTIVE(char* scene) { return invoke<BOOL>(0x4E1850F5FF023071, scene); } // 0x4E1850F5FF023071 0xACBED05C
	static void SET_AUDIO_SCENE_VARIABLE(Any* p0, Any* p1, float p2) { invoke<Void>(0xB47CF941A913A618, p0, p1, p2); } // 0xB47CF941A913A618 0x19BB3CE8
	static void _0x6A84C7C6D4C0E5C8(Any p0) { invoke<Void>(0x6A84C7C6D4C0E5C8, p0); } // 0x6A84C7C6D4C0E5C8 0xE812925D
	static void _0xE4190D6FE693F9EC(Entity p0, char* p1, float p2) { invoke<Void>(0xE4190D6FE693F9EC, p0, p1, p2); } // 0xE4190D6FE693F9EC 0x2BC93264
	static void _0x6741124666983482(Any p0, float p1) { invoke<Void>(0x6741124666983482, p0, p1); } // 0x6741124666983482 0x308ED0EC
	static Any AUDIO_IS_SCRIPTED_MUSIC_PLAYING() { return invoke<Any>(0x12A53380719DE8A7); } // 0x12A53380719DE8A7 0x86E995D1
	static BOOL PREPARE_MUSIC_EVENT(char* eventName) { return invoke<BOOL>(0x5823F1F25CE33C5D, eventName); } // 0x5823F1F25CE33C5D 0x534A5C1C
	static BOOL CANCEL_MUSIC_EVENT(char* eventName) { return invoke<BOOL>(0x01BF9836BF02F6C4, eventName); } // 0x01BF9836BF02F6C4 0x89FF942D
	static BOOL TRIGGER_MUSIC_EVENT(char* eventName) { return invoke<BOOL>(0x5BE53482EFD49141, eventName); } // 0x5BE53482EFD49141 0xB6094948
	static Any _0xCCB27C22187CF0C7() { return invoke<Any>(0xCCB27C22187CF0C7); } // 0xCCB27C22187CF0C7 0x2705C4D5
	static Any GET_MUSIC_PLAYTIME() { return invoke<Any>(0x83C3F51EBB455D6E); } // 0x83C3F51EBB455D6E 0xD633C809
	static void _0x4937A6295F92F8C4(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x4937A6295F92F8C4, p0, p1, p2, p3); } // 0x4937A6295F92F8C4 0x53FC3FEC
	static void CLEAR_ALL_BROKEN_GLASS() { invoke<Void>(0x37D02D87A4624573); } // 0x37D02D87A4624573 0xE6B033BF
	static void _0xFC3482D84EED8A8E(BOOL p0, Any p1) { invoke<Void>(0xFC3482D84EED8A8E, p0, p1); } // 0xFC3482D84EED8A8E 0x95050CAD
	static void _0x3149D07334E5E9EA(float p0, float p1) { invoke<Void>(0x3149D07334E5E9EA, p0, p1); } // 0x3149D07334E5E9EA 0xE64F97A0
	static void _0x8ADB232AC60340AA(float p0, float p1) { invoke<Void>(0x8ADB232AC60340AA, p0, p1); } // 0x8ADB232AC60340AA
	static void _0xE8D4BE42CF780C50() { invoke<Void>(0xE8D4BE42CF780C50); } // 0xE8D4BE42CF780C50 0xD87AF337
	static BOOL PREPARE_ALARM(char* alarmName) { return invoke<BOOL>(0x9A66D28428C3E71C, alarmName); } // 0x9A66D28428C3E71C 0x084932E8
	static void START_ALARM(char* alarmName, BOOL p2) { invoke<Void>(0x6C56935CD477B6CD, alarmName, p2); } // 0x6C56935CD477B6CD 0x703F524B
	static void STOP_ALARM(char* alarmName, BOOL toggle) { invoke<Void>(0xF36BA7C9465AE128, alarmName, toggle); } // 0xF36BA7C9465AE128 0xF987BE8C
	static void STOP_ALL_ALARMS(BOOL stop) { invoke<Void>(0x9746E63468B9DA7C, stop); } // 0x9746E63468B9DA7C 0xC3CB9DC6
	static BOOL IS_ALARM_PLAYING(char* alarmName) { return invoke<BOOL>(0xA8909609E0E433E3, alarmName); } // 0xA8909609E0E433E3 0x9D8E1D23
	static Hash GET_VEHICLE_DEFAULT_HORN(Vehicle veh) { return invoke<Hash>(0x67CC15893A6C9DFC, veh); } // 0x67CC15893A6C9DFC 0xE84ABC19
	static Any _0x40785CB62CE2D8DF(Any p0) { return invoke<Any>(0x40785CB62CE2D8DF, p0); } // 0x40785CB62CE2D8DF 0xFD4B5B3B
	static void RESET_PED_AUDIO_FLAGS(Any p0) { invoke<Void>(0x897438FC009DAD6C, p0); } // 0x897438FC009DAD6C 0xDF720C86
	static void _0x9E51E2360D66DF2B(Any p0, BOOL p1) { invoke<Void>(0x9E51E2360D66DF2B, p0, p1); } // 0x9E51E2360D66DF2B 0xC307D531
	static void _0xDDC5CBDA64BF4668(Any p0, BOOL p1, Any p2) { invoke<Void>(0xDDC5CBDA64BF4668, p0, p1, p2); } // 0xDDC5CBDA64BF4668
	static void _0xBE7DBD7E6C2E322E(Any p0, BOOL p1) { invoke<Void>(0xBE7DBD7E6C2E322E, p0, p1); } // 0xBE7DBD7E6C2E322E
	static void _0xBC9E5374F0F5322B() { invoke<Void>(0xBC9E5374F0F5322B); } // 0xBC9E5374F0F5322B
	static void _0x9A115F154B151630(BOOL p0) { invoke<Void>(0x9A115F154B151630, p0); } // 0x9A115F154B151630 0x13EB5861
	static void _0x5A20D2DCBA30FBF3(Any p0, BOOL p1) { invoke<Void>(0x5A20D2DCBA30FBF3, p0, p1); } // 0x5A20D2DCBA30FBF3 0x7BED1872
	static void SET_AUDIO_FLAG(char* flagName, BOOL toggle) { invoke<Void>(0x589451489CB70B8C, flagName, toggle); } // 0x589451489CB70B8C 0x1C09C9E0
	static Any PREPARE_SYNCHRONIZED_AUDIO_EVENT(char* p0, Any p1) { return invoke<Any>(0x6244BFF5BB1E7059, p0, p1); } // 0x6244BFF5BB1E7059 0xE1D91FD0
	static BOOL PREPARE_SYNCHRONIZED_AUDIO_EVENT_FOR_SCENE(Any p0, Any* p1) { return invoke<BOOL>(0xCC4D784D19851EEA, p0, p1); } // 0xCC4D784D19851EEA 0x7652DD49
	static BOOL PLAY_SYNCHRONIZED_AUDIO_EVENT(Any p0) { return invoke<BOOL>(0x035464080AF1E0AE, p0); } // 0x035464080AF1E0AE 0x507F3241
	static BOOL STOP_SYNCHRONIZED_AUDIO_EVENT(Any p0) { return invoke<BOOL>(0xA76C6422E6F68875, p0); } // 0xA76C6422E6F68875 0xADEED2B4
	static void _0x3B550364A09F68CA(Any* p0, float p1, float p2, float p3) { invoke<Void>(0x3B550364A09F68CA, p0, p1, p2, p3); } // 0x3B550364A09F68CA 0x55A21772
	static void _SET_SYNCHRONIZED_AUDIO_EVENT_POSITION_THIS_FRAME(char* p0, Entity p1) { invoke<Void>(0xD442FCB71B68B935, p0, p1); } // 0xD442FCB71B68B935 0xA17F9AB0
	static void _0xC98DC0B52A9709C5(Any p0) { invoke<Void>(0xC98DC0B52A9709C5, p0); } // 0xC98DC0B52A9709C5 0x62B43677
	static void _0x709C5D80B3419F43(char* p0, char* p1) { invoke<Void>(0x709C5D80B3419F43, p0, p1); } // 0x709C5D80B3419F43 0x8AD670EC
	static void _0xB1F3FFD33B3C25FD(char* p0) { invoke<Void>(0xB1F3FFD33B3C25FD, p0); } // 0xB1F3FFD33B3C25FD 0xD24B4D0C
	static void _0x8113C5E23C692B71() { invoke<Void>(0x8113C5E23C692B71); } // 0x8113C5E23C692B71 0x7262B5BA
	static Any _0x49951891CA893804() { return invoke<Any>(0x49951891CA893804); } // 0x49951891CA893804 0x93A44A1F
	static void _0xBB69BEDBEC5FFA18(Ped ped) { invoke<Void>(0xBB69BEDBEC5FFA18, ped); } // 0xBB69BEDBEC5FFA18 0x13777A0B
	static void _0xA194FBB0A5B1C0EF() { invoke<Void>(0xA194FBB0A5B1C0EF); } // 0xA194FBB0A5B1C0EF 0x1134F68B
	static void _0xAF5302EEF509F664(BOOL p0) { invoke<Void>(0xAF5302EEF509F664, p0); } // 0xAF5302EEF509F664 0xE0047BFD
	static void _0x2869DD47BBC5AF33() { invoke<Void>(0x2869DD47BBC5AF33); } // 0x2869DD47BBC5AF33
	static Any _0xFC7E049E030838E6() { return invoke<Any>(0xFC7E049E030838E6); } // 0xFC7E049E030838E6
	static Any _0x1A3B3F8D204C3A73() { return invoke<Any>(0x1A3B3F8D204C3A73); } // 0x1A3B3F8D204C3A73
}

namespace CUTSCENE
{
	static void REQUEST_CUTSCENE(char* cutsceneName, int p1) { invoke<Void>(0xF7CF05FEB40E538B, cutsceneName, p1); } // 0xF7CF05FEB40E538B 0xB5977853
	static void _REQUEST_CUTSCENE_2(char* cutsceneName, int p1, int p2) { invoke<Void>(0xF2705A63E3587B6C, cutsceneName, p1, p2); } // 0xF2705A63E3587B6C 0xD98F656A
	static void REMOVE_CUTSCENE() { invoke<Void>(0xB5BD48559882D958); } // 0xB5BD48559882D958 0x8052F533
	static BOOL HAS_CUTSCENE_LOADED() { return invoke<BOOL>(0x77888DFE5B94E7E5); } // 0x77888DFE5B94E7E5 0xF9998582
	static BOOL HAS_THIS_CUTSCENE_LOADED(char* cutsceneName) { return invoke<BOOL>(0xC16683E9630D2F2E, cutsceneName); } // 0xC16683E9630D2F2E 0x3C5619F2
	static void _0xBB9CA9BCE1CAC4D0(int p0) { invoke<Void>(0xBB9CA9BCE1CAC4D0, p0); } // 0xBB9CA9BCE1CAC4D0 0x25A2CABC
	static BOOL _0x6E5BBCE1B1E5B2EB() { return invoke<BOOL>(0x6E5BBCE1B1E5B2EB); } // 0x6E5BBCE1B1E5B2EB 0xDD8878E9
	static BOOL _0x7331965972CE52BE(Any p0) { return invoke<BOOL>(0x7331965972CE52BE, p0); } // 0x7331965972CE52BE 0x7B93CDAA
	static void _0xCF5360AD0297403A(char* p0, Any p1, Any p2) { invoke<Void>(0xCF5360AD0297403A, p0, p1, p2); } // 0xCF5360AD0297403A 0x47DB08A9
	static void _0xD0FD1D30DD30537A(Any* p0) { invoke<Void>(0xD0FD1D30DD30537A, p0); } // 0xD0FD1D30DD30537A
	static BOOL _0x241FA2C237BE2566(Any* p0) { return invoke<BOOL>(0x241FA2C237BE2566, p0); } // 0x241FA2C237BE2566
	static void _0x44B028F162D8BE54(Any* p0) { invoke<Void>(0x44B028F162D8BE54, p0); } // 0x44B028F162D8BE54
	static Any _0x4005CB7BED5B008D(Any* p0) { return invoke<Any>(0x4005CB7BED5B008D, p0); } // 0x4005CB7BED5B008D
	static void START_CUTSCENE(int p0) { invoke<Void>(0x51C344BE3DCB5CB5, p0); } // 0x51C344BE3DCB5CB5 0x210106F6
	static void START_CUTSCENE_AT_COORDS(float x, float y, float z, int p3) { invoke<Void>(0xC0420B87A46C58E9, x, y, z, p3); } // 0xC0420B87A46C58E9 0x58BEA436
	static void STOP_CUTSCENE(BOOL p0) { invoke<Void>(0x404A255180289CD1, p0); } // 0x404A255180289CD1 0x5EE84DC7
	static void STOP_CUTSCENE_IMMEDIATELY() { invoke<Void>(0x56F0894B33ED25B7); } // 0x56F0894B33ED25B7 0xF528A2AD
	static void SET_CUTSCENE_ORIGIN(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x72A1E11E19AD9EB4, p0, p1, p2, p3, p4); } // 0x72A1E11E19AD9EB4 0xB0AD7792
	static void _0x86094F7754F9D6F7(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<Void>(0x86094F7754F9D6F7, p0, p1, p2, p3, p4, p5, p6); } // 0x86094F7754F9D6F7
	static int GET_CUTSCENE_TIME() { return invoke<int>(0x4A933E1DE60245B7); } // 0x4A933E1DE60245B7 0x53F5B5AB
	static int GET_CUTSCENE_TOTAL_DURATION() { return invoke<int>(0xC7BE2EB6718826C2); } // 0xC7BE2EB6718826C2 0x0824EBE8
	static BOOL WAS_CUTSCENE_SKIPPED() { return invoke<BOOL>(0x8AE74E6771D8FA39); } // 0x8AE74E6771D8FA39 0xC9B6949D
	static BOOL HAS_CUTSCENE_FINISHED() { return invoke<BOOL>(0xB116D5E6F24B8406); } // 0xB116D5E6F24B8406 0x5DED14B4
	static BOOL IS_CUTSCENE_ACTIVE() { return invoke<BOOL>(0x80A7A5165A9C7607); } // 0x80A7A5165A9C7607 0xCCE2FE9D
	static BOOL IS_CUTSCENE_PLAYING() { return invoke<BOOL>(0x1B76B77EDF24A933); } // 0x1B76B77EDF24A933 0xA3A78392
	static int GET_CUTSCENE_SECTION_PLAYING() { return invoke<int>(0xDB5D8AF59CCF4714); } // 0xDB5D8AF59CCF4714 0x1026F0D6
	static Entity GET_ENTITY_INDEX_OF_CUTSCENE_ENTITY(char* cutsceneEntName, Hash modelHash) { return invoke<Entity>(0xBA7384CA68090F6C, cutsceneEntName, modelHash); } // 0xBA7384CA68090F6C 0x1D09ABC7
	static int _0x54A5232B445E24B8() { return invoke<int>(0x54A5232B445E24B8); } // 0x54A5232B445E24B8 0x5AE68AE6
	static BOOL _0xD104442C45186D3F(char* cutsceneName) { return invoke<BOOL>(0xD104442C45186D3F, cutsceneName); } // 0xD104442C45186D3F
	static void REGISTER_ENTITY_FOR_CUTSCENE(Ped cutscenePed, char* cutsceneEntName, int p2, Hash modelHash, int p4) { invoke<Void>(0xD9C496FEAA81FF4A, cutscenePed, cutsceneEntName, p2, modelHash, p4); } // 0xD9C496FEAA81FF4A 0x7CBC3EC7
	static Entity GET_ENTITY_INDEX_OF_REGISTERED_ENTITY(char* cutsceneEntName, Hash modelHash) { return invoke<Entity>(0x6DFA780BD6E87375, cutsceneEntName, modelHash); } // 0x6DFA780BD6E87375 0x46D18755
	static void _0x10787CF4D40D8657(Hash modelHash) { invoke<Void>(0x10787CF4D40D8657, modelHash); } // 0x10787CF4D40D8657
	static void SET_CUTSCENE_TRIGGER_AREA(float p0, float p1, float p2, float p3, float p4, float p5) { invoke<Void>(0x70E19C6BE5537B46, p0, p1, p2, p3, p4, p5); } // 0x70E19C6BE5537B46 0x9D76D9DE
	static BOOL CAN_SET_ENTER_STATE_FOR_REGISTERED_ENTITY(char* cutsceneEntName, Hash modelHash) { return invoke<BOOL>(0xF63011C1B4831133, cutsceneEntName, modelHash); } // 0xF63011C1B4831133 0x55C30B26
	static BOOL CAN_SET_EXIT_STATE_FOR_REGISTERED_ENTITY(char* cutsceneEntName, Hash modelHash) { return invoke<BOOL>(0x649012AFAC9B7CD0, cutsceneEntName, modelHash); } // 0x649012AFAC9B7CD0 0x8FF5D3C4
	static BOOL CAN_SET_EXIT_STATE_FOR_CAMERA(BOOL p0) { return invoke<BOOL>(0x66FBC42991B0D41E, p0); } // 0x66FBC42991B0D41E 0xEDAE6C02
	static void _0x1DE6AC35EE6430C8(BOOL p0) { invoke<Void>(0x1DE6AC35EE6430C8, p0); } // 0x1DE6AC35EE6430C8 0x35721A08
	static void SET_CUTSCENE_FADE_VALUES(BOOL p0, BOOL p1, BOOL p2, BOOL p3) { invoke<Void>(0x2FBE1F665378345E, p0, p1, p2, p3); } // 0x2FBE1F665378345E 0xD19EF0DD
	static void _0xCE7A426067C66E84(BOOL p0, BOOL p1, BOOL p2, BOOL p3) { invoke<Void>(0xCE7A426067C66E84, p0, p1, p2, p3); } // 0xCE7A426067C66E84
	static void _0x822FC4845512E748(BOOL p0) { invoke<Void>(0x822FC4845512E748, p0); } // 0x822FC4845512E748
	static int _0x5E9889CF18601D1C() { return invoke<int>(0x5E9889CF18601D1C); } // 0x5E9889CF18601D1C
	static void _0xAD89191A0B23916A(BOOL p0) { invoke<Void>(0xAD89191A0B23916A, p0); } // 0xAD89191A0B23916A 0x8338DA1D
	static void _0x7AD4C7413CBB95D6(BOOL p0) { invoke<Void>(0x7AD4C7413CBB95D6, p0); } // 0x7AD4C7413CBB95D6 0x04377C10
	static Any _0x489C8152C23B96EB() { return invoke<Any>(0x489C8152C23B96EB); } // 0x489C8152C23B96EB 0xDBD88708
	static void _0x759FCDAB92CDEA9C(BOOL p0) { invoke<Void>(0x759FCDAB92CDEA9C, p0); } // 0x759FCDAB92CDEA9C 0x28D54A7F
	static void REGISTER_SYNCHRONISED_SCRIPT_SPEECH() { invoke<Void>(0xADB9269F0128E6C7); } // 0xADB9269F0128E6C7 0xB60CFBB9
	static void SET_CUTSCENE_PED_COMPONENT_VARIATION(char* cutsceneEntName, int p1, int p2, int p3, Hash modelHash) { invoke<Void>(0x5C9E441B0B13FC8B, cutsceneEntName, p1, p2, p3, modelHash); } // 0x5C9E441B0B13FC8B 0x6AF994A1
	static void _0x0A970CDB1CD24DA6(char* cutsceneEntName, Ped ped, Hash modelHash) { invoke<Void>(0x0A970CDB1CD24DA6, cutsceneEntName, ped, modelHash); } // 0x0A970CDB1CD24DA6 0x1E7DA95E
	static BOOL DOES_CUTSCENE_ENTITY_EXIST(char* cutsceneEntName, Hash modelHash) { return invoke<BOOL>(0xBE4F136952F476D5, cutsceneEntName, modelHash); } // 0xBE4F136952F476D5 0x58E67409
	static void SET_CUTSCENE_PED_PROP_VARIATION(char* cutsceneEntName, int p1, int p2, int p3, Hash modelHash) { invoke<Void>(0x5677A9C1ADA50A6E, cutsceneEntName, p1, p2, p3, modelHash); } // 0x5677A9C1ADA50A6E 0x22E9A9DE
	static BOOL _0x92B9E65C983F8939() { return invoke<BOOL>(0x92B9E65C983F8939); } // 0x92B9E65C983F8939 0x4315A7C5
}

namespace INTERIOR
{
	static int GET_INTERIOR_GROUP_ID(int interiorID) { return invoke<int>(0x138D1E72F238B873, interiorID); } // 0x138D1E72F238B873 0x09D6376F
	static Vector3 GET_OFFSET_FROM_INTERIOR_IN_WORLD_COORDS(int interiorID, float x, float y, float z) { return invoke<Vector3>(0xC2A8DCEEF00CDAD6, interiorID, x, y, z); } // 0xC2A8DCEEF00CDAD6 0x7D8F26A1
	static BOOL IS_INTERIOR_SCENE() { return invoke<BOOL>(0x7C78CD7E10D3835F); } // 0x7C78CD7E10D3835F 0x55226C13
	static BOOL IS_VALID_INTERIOR(int interiorID) { return invoke<BOOL>(0x623BDE1B17A9D9E3, interiorID); } // 0x623BDE1B17A9D9E3 0x39C0B635
	static void CLEAR_ROOM_FOR_ENTITY(Entity entity) { invoke<Void>(0x0909784B7F47211B, entity); } // 0x0909784B7F47211B 0x7DDADB92
	static void FORCE_ROOM_FOR_ENTITY(Entity entity, int interiorID, Hash roomHashKey) { invoke<Void>(0x5D083173FC8B8A0D, entity, interiorID, roomHashKey); } // 0x5D083173FC8B8A0D 0x10BD4435
	static Hash GET_ROOM_KEY_FROM_ENTITY(Entity entity) { return invoke<Hash>(0x59499E9FE45DE5D5, entity); } // 0x59499E9FE45DE5D5 0xE4ACF8C3
	static Hash GET_KEY_FOR_ENTITY_IN_ROOM(Entity entity) { return invoke<Hash>(0x2891D5935185F77D, entity); } // 0x2891D5935185F77D 0x91EA80EF
	static int GET_INTERIOR_FROM_ENTITY(Entity entity) { return invoke<int>(0xF34287B610CF02CA, entity); } // 0xF34287B610CF02CA 0x5C644614
	static void _0xEB7DEADB891A2BB7(Entity entity, int interiorID) { invoke<Void>(0xEB7DEADB891A2BB7, entity, interiorID); } // 0xEB7DEADB891A2BB7 0xE645E162
	static void _0xF4B56ACC10526746(int interiorID, Hash roomHashKey) { invoke<Void>(0xF4B56ACC10526746, interiorID, roomHashKey); } // 0xF4B56ACC10526746 0xD79803B5
	static void _0xB9C783FF4D0BE1D4(char* roomName) { invoke<Void>(0xB9C783FF4D0BE1D4, roomName); } // 0xB9C783FF4D0BE1D4 0x1F6B4B13
	static void _0x7FDE65CD296D3FDC(Hash roomHashKey) { invoke<Void>(0x7FDE65CD296D3FDC, roomHashKey); } // 0x7FDE65CD296D3FDC 0x0E9529CC
	static Hash _GET_ROOM_KEY_FROM_GAMEPLAY_CAM() { return invoke<Hash>(0xB39E4CB88226E2D3); } // 0xB39E4CB88226E2D3 0x4FF3D3F5
	static void _0x82FD0AAD5AFB144E() { invoke<Void>(0x82FD0AAD5AFB144E); } // 0x82FD0AAD5AFB144E 0x617DC75D
	static int GET_INTERIOR_AT_COORDS(float x, float y, float z) { return invoke<int>(0x1A4C1C534F86E06A, x, y, z); } // 0x1A4C1C534F86E06A 0xA17FBF37
	static void ADD_PICKUP_TO_INTERIOR_ROOM_BY_NAME(Pickup pickup, char* roomName) { invoke<Void>(0x85C3B935EDEA6E23, pickup, roomName); } // 0x85C3B935EDEA6E23 0xA2A73564
	static void _0xB746CFFEAA8CB784(int interiorID) { invoke<Void>(0xB746CFFEAA8CB784, interiorID); } // 0xB746CFFEAA8CB784 0x3ADA414E
	static void UNPIN_INTERIOR(int interiorID) { invoke<Void>(0xDD5B92F304023AEF, interiorID); } // 0xDD5B92F304023AEF 0xFCFF792A
	static BOOL IS_INTERIOR_READY(int interiorID) { return invoke<BOOL>(0x1F02DB541727C048, interiorID); } // 0x1F02DB541727C048 0xE1EF6450
	static Any _0x24046D82D42C9FD7(int interiorID) { return invoke<Any>(0x24046D82D42C9FD7, interiorID); } // 0x24046D82D42C9FD7
	static int GET_INTERIOR_AT_COORDS_WITH_TYPE(float x, float y, float z, char* interiorType) { return invoke<int>(0xCA0D2B42E97CB506, x, y, z, interiorType); } // 0xCA0D2B42E97CB506 0x96525B06
	static int _UNK_GET_INTERIOR_AT_COORDS(float x, float y, float z, int unk) { return invoke<int>(0x42B2C8EB928BC71F, x, y, z, unk); } // 0x42B2C8EB928BC71F
	static BOOL _ARE_COORDS_COLLIDING_WITH_EXTERIOR(float x, float y, float z) { return invoke<BOOL>(0xB0A41EC77A49B189, x, y, z); } // 0xB0A41EC77A49B189 0x7762249C
	static int GET_INTERIOR_FROM_COLLISION(float x, float y, float z) { return invoke<int>(0x26CBF9EAAC681B92, x, y, z); } // 0x26CBF9EAAC681B92 0x7ED33DC1
	static void _ENABLE_INTERIOR_PROP(int interiorID, char* propName) { invoke<Void>(0x874DE19CF8659CF5, interiorID, propName); } // 0x874DE19CF8659CF5 0xC80A5DDF
	static void _DISABLE_INTERIOR_PROP(int interiorID, char* propName) { invoke<Void>(0x9AEED011E34D9C65, interiorID, propName); } // 0x9AEED011E34D9C65 0xDBA768A1
	static BOOL _IS_INTERIOR_PROP_ENABLED(int interiorID, char* propName) { return invoke<BOOL>(0xE3C122250634A582, interiorID, propName); } // 0xE3C122250634A582 0x39A3CC6F
	static void REFRESH_INTERIOR(int interiorID) { invoke<Void>(0xCA6CBCAD7B35C261, interiorID); } // 0xCA6CBCAD7B35C261 0x9A29ACE6
	static void _HIDE_MAP_OBJECT_THIS_FRAME(Hash mapObjectHash) { invoke<Void>(0xE90BEE3DCE95FFF7, mapObjectHash); } // 0xE90BEE3DCE95FFF7 0x1F375B4C
	static void DISABLE_INTERIOR(int interiorID, BOOL toggle) { invoke<Void>(0xAADCD9F192619006, interiorID, toggle); } // 0xAADCD9F192619006 0x093ADEA5
	static BOOL IS_INTERIOR_DISABLED(int interiorID) { return invoke<BOOL>(0x40A923ACA3B756CE, interiorID); } // 0x40A923ACA3B756CE 0x81F34C71
	static void CAP_INTERIOR(int interiorID, BOOL toggle) { invoke<Void>(0x353681975B9718B3, interiorID, toggle); } // 0x353681975B9718B3 0x34E735A6
	static BOOL IS_INTERIOR_CAPPED(int interiorID) { return invoke<BOOL>(0xA8A328A4BA43BA76, interiorID); } // 0xA8A328A4BA43BA76 0x18B17C80
	static void _0x88665DA7AA6F260D(BOOL toggle) { invoke<Void>(0x88665DA7AA6F260D, toggle); } // 0x88665DA7AA6F260D 0x5EF9C5C2
}

namespace CAM
{
	static void RENDER_SCRIPT_CAMS(BOOL render, BOOL ease, int easeTime, BOOL p3, BOOL p4) { invoke<Void>(0x9274EF97A90581BE, render, ease, easeTime, p3, p4); } // 0x9274EF97A90581BE 0x74337969
	static void _0x2FCF54C709BA255D(Any p0, Any p1, Any p2) { invoke<Void>(0x2FCF54C709BA255D, p0, p1, p2); } // 0x2FCF54C709BA255D 0xD3C08183
	static Cam CREATE_CAM(char* camName, BOOL p1) { return invoke<Cam>(0xBD7A488D61CE4287, camName, p1); } // 0xBD7A488D61CE4287 0xE9BF2A7D
	static Cam CREATE_CAM_WITH_PARAMS(char* camName, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float fov, BOOL p8, int p9) { return invoke<Cam>(0x71877D18957B1679, camName, posX, posY, posZ, rotX, rotY, rotZ, fov, p8, p9); } // 0x71877D18957B1679 0x23B02F15
	static Cam CREATE_CAMERA(Hash camHash, BOOL p1) { return invoke<Cam>(0x9F2F24963A4C5E27, camHash, p1); } // 0x9F2F24963A4C5E27 0x5D6739AE
	static Cam CREATE_CAMERA_WITH_PARAMS(Hash camHash, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float fov, BOOL p8, Any p9) { return invoke<Cam>(0x077CBD2E7E281022, camHash, posX, posY, posZ, rotX, rotY, rotZ, fov, p8, p9); } // 0x077CBD2E7E281022 0x0688BE9A
	static void DESTROY_CAM(Cam cam, BOOL destroy) { invoke<Void>(0x2BC4A4AFFC2D937D, cam, destroy); } // 0x2BC4A4AFFC2D937D 0xC39302BD
	static void DESTROY_ALL_CAMS(BOOL destroy) { invoke<Void>(0xA5E21BA8D7CE03D8, destroy); } // 0xA5E21BA8D7CE03D8 0x10C151CE
	static BOOL DOES_CAM_EXIST(Cam cam) { return invoke<BOOL>(0x0F1BF24ED3B7ED40, cam); } // 0x0F1BF24ED3B7ED40 0x1EF89DC0
	static void SET_CAM_ACTIVE(Cam cam, BOOL active) { invoke<Void>(0xA652CA24468EC747, cam, active); } // 0xA652CA24468EC747 0x064659C2
	static BOOL IS_CAM_ACTIVE(Cam cam) { return invoke<BOOL>(0xA6312B4FE4134130, cam); } // 0xA6312B4FE4134130 0x4B58F177
	static BOOL IS_CAM_RENDERING(Cam cam) { return invoke<BOOL>(0x37E527C929CC5067, cam); } // 0x37E527C929CC5067 0x6EC6B5B2
	static Cam GET_RENDERING_CAM() { return invoke<Cam>(0xF4F4D11B2EE4033B); } // 0xF4F4D11B2EE4033B 0x0FCF4DF1
	static Vector3 GET_CAM_COORD(Cam cam) { return invoke<Vector3>(0xA519593E9D64C991, cam); } // 0xA519593E9D64C991 0x7C40F09C
	static Vector3 GET_CAM_ROT(Cam cam, Any p1) { return invoke<Vector3>(0xE20113A830C67A97, cam, p1); } // 0xE20113A830C67A97 0xDAC84C9F
	static float GET_CAM_FOV(Cam cam) { return invoke<float>(0x503C970FCA1E0910, cam); } // 0x503C970FCA1E0910 0xD6E9FCF5
	static float GET_CAM_NEAR_CLIP(Cam cam) { return invoke<float>(0x2AFC48D949D3F5D6, cam); } // 0x2AFC48D949D3F5D6 0xCFCD35EE
	static float GET_CAM_FAR_CLIP(Cam cam) { return invoke<float>(0x420A0CAB77DD73CF, cam); } // 0x420A0CAB77DD73CF 0x09F119B8
	static float GET_CAM_FAR_DOF(Cam cam) { return invoke<float>(0x8A6101787A944E43, cam); } // 0x8A6101787A944E43 0x98C5CCE9
	static void SET_CAM_PARAMS(Cam cam, float p1, float p2, float p3, float p4, float p5, float p6, float p7, Any p8, Any p9, Any p10, Any p11) { invoke<Void>(0x10AEEB80A49DD974, cam, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x10AEEB80A49DD974 0x2167CEBF
	static void SET_CAM_COORD(Cam cam, float posX, float posY, float posZ) { invoke<Void>(0x451B3BE1DE87C4F5, cam, posX, posY, posZ); } // 0x451B3BE1DE87C4F5 0x7A8053AF
	static void SET_CAM_ROT(Cam cam, float rotX, float rotY, float rotZ, int p4) { invoke<Void>(0xF612AE5AD0E3336E, cam, rotX, rotY, rotZ, p4); } // 0xF612AE5AD0E3336E 0xEE38B3C1
	static void SET_CAM_FOV(Cam cam, float fieldOfView) { invoke<Void>(0x4BF6276065449F9C, cam, fieldOfView); } // 0x4BF6276065449F9C 0xD3D5D74F
	static void SET_CAM_NEAR_CLIP(Cam cam, float nearClip) { invoke<Void>(0xDEA73750D98537BF, cam, nearClip); } // 0xDEA73750D98537BF 0x46DB13B1
	static void SET_CAM_FAR_CLIP(Cam cam, float farClip) { invoke<Void>(0x4E0049B7A73D4050, cam, farClip); } // 0x4E0049B7A73D4050 0x0D23E381
	static void SET_CAM_MOTION_BLUR_STRENGTH(Cam cam, float strength) { invoke<Void>(0x9C0D2639DC991371, cam, strength); } // 0x9C0D2639DC991371 0xFD6E0D67
	static void SET_CAM_NEAR_DOF(Cam cam, float nearDOF) { invoke<Void>(0x95158FE242BD6B8C, cam, nearDOF); } // 0x95158FE242BD6B8C 0xF28254DF
	static void SET_CAM_FAR_DOF(Cam cam, float farDOF) { invoke<Void>(0x1451EABCA5C5F5FA, cam, farDOF); } // 0x1451EABCA5C5F5FA 0x58515E8E
	static void SET_CAM_DOF_STRENGTH(Cam cam, float dofStrength) { invoke<Void>(0x17A1435988190BCD, cam, dofStrength); } // 0x17A1435988190BCD 0x3CC4EB3F
	static void SET_CAM_DOF_PLANES(Cam cam, float p1, float p2, float p3, float p4) { invoke<Void>(0x381B81B22CE98146, cam, p1, p2, p3, p4); } // 0x381B81B22CE98146 0xAD6C2B8F
	static void SET_CAM_USE_SHALLOW_DOF_MODE(Cam cam, BOOL toggle) { invoke<Void>(0x091972504610E7D5, cam, toggle); } // 0x091972504610E7D5 0x8306C256
	static void SET_USE_HI_DOF() { invoke<Void>(0x834F57B4BA329093); } // 0x834F57B4BA329093 0x8BBF2950
	static void _0x3BA120F96301FA50(Any p0, float p1) { invoke<Void>(0x3BA120F96301FA50, p0, p1); } // 0x3BA120F96301FA50
	static void _0x98003D45372A58A1(Any p0, float p1) { invoke<Void>(0x98003D45372A58A1, p0, p1); } // 0x98003D45372A58A1
	static void _SET_CAM_DOF_FNUMBER_OF_LENS(Cam camera, float p1) { invoke<Void>(0xD55F7B5BC989E8EA, camera, p1); } // 0xD55F7B5BC989E8EA
	static void _SET_CAM_DOF_FOCUS_DISTANCE_BIAS(Cam camera, float p1) { invoke<Void>(0x8A8072F36C6C40B0, camera, p1); } // 0x8A8072F36C6C40B0
	static void _SET_CAM_DOF_MAX_NEAR_IN_FOCUS_DISTANCE(Cam camera, float p1) { invoke<Void>(0x5E9C47A99AE882D8, camera, p1); } // 0x5E9C47A99AE882D8
	static void _SET_CAM_DOF_MAX_NEAR_IN_FOCUS_DISTANCE_BLEND_LEVEL(Cam camera, float p1) { invoke<Void>(0xC18FF66C06ABD2CD, camera, p1); } // 0xC18FF66C06ABD2CD
	static void ATTACH_CAM_TO_ENTITY(Cam cam, Entity entity, float xOffset, float yOffset, float zOffset, BOOL isRelative) { invoke<Void>(0x3F63C992420F53CD, cam, entity, xOffset, yOffset, zOffset, isRelative); } // 0x3F63C992420F53CD 0xAD7C45F6
	static void ATTACH_CAM_TO_PED_BONE(Cam cam, Ped ped, int boneIndex, float x, float y, float z, BOOL heading) { invoke<Void>(0x9F96EDC178C92D30, cam, ped, boneIndex, x, y, z, heading); } // 0x9F96EDC178C92D30 0x506BB35C
	static void DETACH_CAM(Cam cam) { invoke<Void>(0xC4AB1EFB7D0269E4, cam); } // 0xC4AB1EFB7D0269E4 0xF4FBF14A
	static void SET_CAM_INHERIT_ROLL_VEHICLE(Cam cam, BOOL p1) { invoke<Void>(0x930AC39E43F2EC89, cam, p1); } // 0x930AC39E43F2EC89 0xE4BD5342
	static void POINT_CAM_AT_COORD(Cam cam, float x, float y, float z) { invoke<Void>(0x0D36FB231C6F2A2F, cam, x, y, z); } // 0x0D36FB231C6F2A2F 0x914BC21A
	static void POINT_CAM_AT_ENTITY(Cam cam, Entity entity, float p2, float p3, float p4, BOOL p5) { invoke<Void>(0x38FEEA0E556305D7, cam, entity, p2, p3, p4, p5); } // 0x38FEEA0E556305D7 0x7597A0F7
	static void POINT_CAM_AT_PED_BONE(Cam cam, int ped, int boneIndex, float x, float y, float z, BOOL p6) { invoke<Void>(0x0108F3B000B0D069, cam, ped, boneIndex, x, y, z, p6); } // 0x0108F3B000B0D069 0x09F47049
	static void STOP_CAM_POINTING(Cam cam) { invoke<Void>(0x996FE92319D5E311, cam); } // 0x996FE92319D5E311 0x5435F6A5
	static void SET_CAM_AFFECTS_AIMING(Cam cam, BOOL toggle) { invoke<Void>(0x07BCB28CAA11D3E2, cam, toggle); } // 0x07BCB28CAA11D3E2 0x0C74F9AF
	static void _0xA533A99CD5065321(Any p0, BOOL p1) { invoke<Void>(0xA533A99CD5065321, p0, p1); } // 0xA533A99CD5065321 0xE1A0B2F1
	static void _0x70B1B82B8606A722(Any p0, BOOL p1) { invoke<Void>(0x70B1B82B8606A722, p0, p1); } // 0x70B1B82B8606A722
	static void _0x0AB6A9F788437B9A(Any p0, BOOL p1) { invoke<Void>(0x0AB6A9F788437B9A, p0, p1); } // 0x0AB6A9F788437B9A 0x43220969
	static void SET_CAM_DEBUG_NAME(Cam camera, char* name) { invoke<Void>(0xC0635DA19F194AD9, camera, name); } // 0xC0635DA19F194AD9 0x9B00DF3F
	static void ADD_CAM_SPLINE_NODE(int camera, float x, float y, float z, float xRot, float yRot, float zRot, int length, int p8, int p9) { invoke<Void>(0x9F79E3531887D729, camera, x, y, z, xRot, yRot, zRot, length, p8, p9); } // 0x9F79E3531887D729 0xAD3C7EAA
	static void _0x3207B3344E867C31(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x3207B3344E867C31, p0, p1, p2, p3); } // 0x3207B3344E867C31 0x30510511
	static void _0xF10334B4674D57A1(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0xF10334B4674D57A1, p0, p1, p2, p3); } // 0xF10334B4674D57A1 0xBA6C085B
	static void _0x0005566A73473DF9(Any p0, Any p1, Any p2) { invoke<Void>(0x0005566A73473DF9, p0, p1, p2); } // 0x0005566A73473DF9 0xB4737F03
	static void SET_CAM_SPLINE_PHASE(int cam, float p1) { invoke<Void>(0x262AFF591BB67BCD, cam, p1); } // 0x262AFF591BB67BCD 0xF0AED233
	static float GET_CAM_SPLINE_PHASE(Cam cam) { return invoke<float>(0x349A44057335FE78, cam); } // 0x349A44057335FE78 0x39784DD9
	static float GET_CAM_SPLINE_NODE_PHASE(Any p0) { return invoke<float>(0x8EB7324187E4300C, p0); } // 0x8EB7324187E4300C 0x7B9522F6
	static void SET_CAM_SPLINE_DURATION(int cam, int timeDuration) { invoke<Void>(0x937A55DD5FE21B75, cam, timeDuration); } // 0x937A55DD5FE21B75 0x3E91FC8A
	static void _0x2FD33435045DF7BC(Any p0, Any p1) { invoke<Void>(0x2FD33435045DF7BC, p0, p1); } // 0x2FD33435045DF7BC 0x15E141CE
	static BOOL GET_CAM_SPLINE_NODE_INDEX(int cam) { return invoke<BOOL>(0x7AE883F98B3810BA, cam); } // 0x7AE883F98B3810BA 0xF8AEB6BD
	static void _0x34D1E368C092DCAF(Any p0, Any p1, Any p2, float p3) { invoke<Void>(0x34D1E368C092DCAF, p0, p1, p2, p3); } // 0x34D1E368C092DCAF 0x21D275DA
	static void _0x61F7ABA01FCBEAB4(Any p0, Any p1, float p2) { invoke<Void>(0x61F7ABA01FCBEAB4, p0, p1, p2); } // 0x61F7ABA01FCBEAB4 0xA3BD9E94
	static void OVERRIDE_CAM_SPLINE_VELOCITY(int cam, int p1, float p2, float p3) { invoke<Void>(0x5DC4005FB23CE4A2, cam, p1, p2, p3); } // 0x5DC4005FB23CE4A2 0x326A17E2
	static void OVERRIDE_CAM_SPLINE_MOTION_BLUR(Any p0, Any p1, float p2, float p3) { invoke<Void>(0x095E97C7B52B35EA, p0, p1, p2, p3); } // 0x095E97C7B52B35EA 0x633179E6
	static void _0x9A04942F378B2D26(Any p0, Any p1, Any p2) { invoke<Void>(0x9A04942F378B2D26, p0, p1, p2); } // 0x9A04942F378B2D26 0xC90B2DDC
	static BOOL IS_CAM_SPLINE_PAUSED(Any p0) { return invoke<BOOL>(0x4DD3D114D57E98A3, p0); } // 0x4DD3D114D57E98A3 0x60B34FF5
	static void SET_CAM_ACTIVE_WITH_INTERP(Cam camTo, Cam camFrom, int duration, int easeLocation, int easeRotation) { invoke<Void>(0x6530B35F40F7E78B, camTo, camFrom, duration, easeLocation, easeRotation); } // 0x6530B35F40F7E78B 0x7983E7F0
	static BOOL IS_CAM_INTERPOLATING(Cam cam) { return invoke<BOOL>(0x5EA583D9DE7FD008, cam); } // 0x5EA583D9DE7FD008 0x7159CB5D
	static void SHAKE_CAM(Cam cam, char* type, float amplitude) { invoke<Void>(0x2F0C4DC7A4D75C2E, cam, type, amplitude); } // 0x2F0C4DC7A4D75C2E 0x1D4211B0
	static void ANIMATED_SHAKE_CAM(Cam cam, char* p1, char* p2, char* p3, float amplitude) { invoke<Void>(0xDE6D3982F4FE4C3E, cam, p1, p2, p3, amplitude); } // 0xDE6D3982F4FE4C3E 0xE1168767
	static BOOL IS_CAM_SHAKING(Cam cam) { return invoke<BOOL>(0x0C1C2DD5505D4E04, cam); } // 0x0C1C2DD5505D4E04 0x0961FD9B
	static void SET_CAM_SHAKE_AMPLITUDE(Cam cam, float amplitude) { invoke<Void>(0xB0655D4540B8DF38, cam, amplitude); } // 0xB0655D4540B8DF38 0x60FF6382
	static void STOP_CAM_SHAKING(Cam cam, BOOL p1) { invoke<Void>(0x6E850356BCA62F5C, cam, p1); } // 0x6E850356BCA62F5C 0x40D0EB87
	static void _0xFC434AC9A9DBF766(char* p0, float p1) { invoke<Void>(0xFC434AC9A9DBF766, p0, p1); } // 0xFC434AC9A9DBF766 0x2B0F05CD
	static void _0xFF2DA17088A9F638(char* p0, char* p1, char* p2, float p3) { invoke<Void>(0xFF2DA17088A9F638, p0, p1, p2, p3); } // 0xFF2DA17088A9F638 0xCB75BD9C
	static BOOL _0xE77D3AC9C1449801() { return invoke<BOOL>(0xE77D3AC9C1449801); } // 0xE77D3AC9C1449801 0x6AEFE6A5
	static void _0x011AE968D1EA959B(BOOL p0) { invoke<Void>(0x011AE968D1EA959B, p0); } // 0x011AE968D1EA959B 0x26FCFB96
	static BOOL PLAY_CAM_ANIM(Cam cam, char* animName, char* animDictionary, float x, float y, float z, float xRot, float yRot, float zRot, BOOL p9, int p10) { return invoke<BOOL>(0x18E29DD10BC1C1B8, cam, animName, animDictionary, x, y, z, xRot, yRot, zRot, p9, p10); } // 0x18E29DD10BC1C1B8 0xBCEFB87E
	static BOOL IS_CAM_PLAYING_ANIM(Cam cam, char* animName, char* animDictionary) { return invoke<BOOL>(0xF04B21814588A60D, cam, animName, animDictionary); } // 0xF04B21814588A60D 0xB998CB49
	static void SET_CAM_ANIM_CURRENT_PHASE(Cam cam, float phase) { invoke<Void>(0x7B28A148EF74EFBD, cam, phase); } // 0x7B28A148EF74EFBD 0x3CB1D17F
	static float GET_CAM_ANIM_CURRENT_PHASE(Cam cam) { return invoke<float>(0xF45AFB2ED511F211, cam); } // 0xF45AFB2ED511F211 0x345F72D0
	static BOOL PLAY_SYNCHRONIZED_CAM_ANIM(Any p0, Any p1, char* animName, char* animDictionary) { return invoke<BOOL>(0x563AC676C8BDAD48, p0, p1, animName, animDictionary); } // 0x563AC676C8BDAD48 0x9458459E
	static void _0xA4FB2114C9F09AAE(Any p0, float p1, float p2, float p3) { invoke<Void>(0xA4FB2114C9F09AAE, p0, p1, p2, p3); } // 0xA4FB2114C9F09AAE 0x56F9ED27
	static void _0x78E7CB7A363C6FDD(Any p0, float p1) { invoke<Void>(0x78E7CB7A363C6FDD, p0, p1); } // 0x78E7CB7A363C6FDD 0x71570DBA
	static void _0x7ECBD0BAAAC42F17(Any p0, float p1, float p2, float p3) { invoke<Void>(0x7ECBD0BAAAC42F17, p0, p1, p2, p3); } // 0x7ECBD0BAAAC42F17 0x60B345DE
	static void _0x50D17B18E252C128(Cam p0) { invoke<Void>(0x50D17B18E252C128, p0); } // 0x50D17B18E252C128 0x44473EFC
	static BOOL _0x128607B168094FB5(Any p0) { return invoke<BOOL>(0x128607B168094FB5, p0); } // 0x128607B168094FB5 0xDA931D65
	static BOOL IS_SCREEN_FADED_OUT() { return invoke<BOOL>(0x25BD4C26D84038CD); } // 0x25BD4C26D84038CD 0x9CAA05FA
	static BOOL IS_SCREEN_FADED_IN() { return invoke<BOOL>(0x30F06AB0772AFB80); } // 0x30F06AB0772AFB80 0x4F37276D
	static BOOL IS_SCREEN_FADING_OUT() { return invoke<BOOL>(0x46EEE08565CE19CA); } // 0x46EEE08565CE19CA 0x79275A57
	static BOOL IS_SCREEN_FADING_IN() { return invoke<BOOL>(0x5C0856D86B18EE57); } // 0x5C0856D86B18EE57 0xC7C82800
	static void DO_SCREEN_FADE_IN(int duration) { invoke<Void>(0xC7845898207D067F, duration); } // 0xC7845898207D067F 0x66C1BDEE
	static void DO_SCREEN_FADE_OUT(int duration) { invoke<Void>(0x50FD1894558DE186, duration); } // 0x50FD1894558DE186 0x89D01805
	static void SET_WIDESCREEN_BORDERS(BOOL p0, int p1) { invoke<Void>(0x990821B6B4780D69, p0, p1); } // 0x990821B6B4780D69 0x1A75DC9A
	static Vector3 GET_GAMEPLAY_CAM_COORD() { return invoke<Vector3>(0x667FF09580838E25); } // 0x667FF09580838E25 0x9388CF79
	static Vector3 GET_GAMEPLAY_CAM_ROT(int p0) { return invoke<Vector3>(0xBEBA2DED4C4C66BD, p0); } // 0xBEBA2DED4C4C66BD 0x13A010B5
	static float GET_GAMEPLAY_CAM_FOV() { return invoke<float>(0x38127D79F0518B5D); } // 0x38127D79F0518B5D 0x4D6B3BFA
	static void _0x6BB28C952AFE4B00(float p0) { invoke<Void>(0x6BB28C952AFE4B00, p0); } // 0x6BB28C952AFE4B00 0xA6E73135
	static void _0x53C8D69A01C4E4AD(float p0) { invoke<Void>(0x53C8D69A01C4E4AD, p0); } // 0x53C8D69A01C4E4AD 0x1126E37C
	static float GET_GAMEPLAY_CAM_RELATIVE_HEADING() { return invoke<float>(0x186514F64CF090E1); } // 0x186514F64CF090E1 0xCAF839C2
	static void SET_GAMEPLAY_CAM_RELATIVE_HEADING(float heading) { invoke<Void>(0xBA7CD73403732191, heading); } // 0xBA7CD73403732191 0x20C6217C
	static float GET_GAMEPLAY_CAM_RELATIVE_PITCH() { return invoke<float>(0x45CFDDB22B94FC64); } // 0x45CFDDB22B94FC64 0xFC5A4946
	static void SET_GAMEPLAY_CAM_RELATIVE_PITCH(float x, float Value2) { invoke<Void>(0x503F20CB07C55470, x, Value2); } // 0x503F20CB07C55470 0x6381B963
	static void _SET_GAMEPLAY_CAM_RAW_YAW(float yaw) { invoke<Void>(0xDC012705C7A18C5F, yaw); } // 0xDC012705C7A18C5F
	static void _SET_GAMEPLAY_CAM_RAW_PITCH(float pitch) { invoke<Void>(0x23277C93D66BD376, pitch); } // 0x23277C93D66BD376
	static void _0xB70C52D096AB60E8(BOOL p0) { invoke<Void>(0xB70C52D096AB60E8, p0); } // 0xB70C52D096AB60E8
	static void SHAKE_GAMEPLAY_CAM(char* shakeName, float intensity) { invoke<Void>(0x4037B8BAB7E279CF, shakeName, intensity); } // 0x4037B8BAB7E279CF 0xF2EFE660
	static BOOL IS_GAMEPLAY_CAM_SHAKING() { return invoke<BOOL>(0x5D865887C1F6B69A); } // 0x5D865887C1F6B69A 0x3457D681
	static void SET_GAMEPLAY_CAM_SHAKE_AMPLITUDE(float amplitude) { invoke<Void>(0xB1C84F480C11C413, amplitude); } // 0xB1C84F480C11C413 0x9219D44A
	static void STOP_GAMEPLAY_CAM_SHAKING(BOOL p0) { invoke<Void>(0xF1C53F353A5EB55F, p0); } // 0xF1C53F353A5EB55F 0xFD569E4E
	static void _0x34E32A84A36DFB25(Any p0) { invoke<Void>(0x34E32A84A36DFB25, p0); } // 0x34E32A84A36DFB25 0x7D3007A2
	static BOOL IS_GAMEPLAY_CAM_RENDERING() { return invoke<BOOL>(0x354EBDB72A54F91B); } // 0x354EBDB72A54F91B 0x0EF276DA
	static BOOL _0x5206C6C099078D7A() { return invoke<BOOL>(0x5206C6C099078D7A); } // 0x5206C6C099078D7A 0xC0B00C20
	static BOOL _0x10E80FD1DC70F9F8() { return invoke<BOOL>(0x10E80FD1DC70F9F8); } // 0x10E80FD1DC70F9F8 0x60C23785
	static void _0xF0CC15375387CF6B(BOOL p0) { invoke<Void>(0xF0CC15375387CF6B, p0); } // 0xF0CC15375387CF6B 0x20BFF6E5
	static void _ENABLE_CROSSHAIR_THIS_FRAME() { invoke<Void>(0x307CC7A59C8CBA85); } // 0x307CC7A59C8CBA85 0xA61FF9AC
	static BOOL IS_GAMEPLAY_CAM_LOOKING_BEHIND() { return invoke<BOOL>(0x54271E538645DBDB); } // 0x54271E538645DBDB 0x33C83F17
	static void _0x00A5EEC92B386774(Entity p0) { invoke<Void>(0x00A5EEC92B386774, p0); } // 0x00A5EEC92B386774 0x2701A9AD
	static void _0x9CE839FAAB8F26DE(Any p0) { invoke<Void>(0x9CE839FAAB8F26DE, p0); } // 0x9CE839FAAB8F26DE 0xC4736ED3
	static void _0x1A524AA897F1E4AD(Any p0) { invoke<Void>(0x1A524AA897F1E4AD, p0); } // 0x1A524AA897F1E4AD
	static void _0xB3D0973008822696() { invoke<Void>(0xB3D0973008822696); } // 0xB3D0973008822696 0x6B0E9D57
	static BOOL IS_SPHERE_VISIBLE(float x, float y, float z, float radius) { return invoke<BOOL>(0xF7E1BD8196545EE3, x, y, z, radius); } // 0xF7E1BD8196545EE3 0xDD1329E2
	static BOOL IS_FOLLOW_PED_CAM_ACTIVE() { return invoke<BOOL>(0x43290D7EF08F2309); } // 0x43290D7EF08F2309 0x9F9E856C
	static BOOL SET_FOLLOW_PED_CAM_CUTSCENE_CHAT(char* p0, int p1) { return invoke<BOOL>(0xDE5AB35E9DAE3D57, p0, p1); } // 0xDE5AB35E9DAE3D57 0x1425F6AC
	static void _0xE398FA24DEBD9D33(BOOL p0, BOOL p1) { invoke<Void>(0xE398FA24DEBD9D33, p0, p1); } // 0xE398FA24DEBD9D33 0x8DC53629
	static void _0x0A2B3B102075681D() { invoke<Void>(0x0A2B3B102075681D); } // 0x0A2B3B102075681D 0x1F9DE6E4
	static void _CLAMP_GAMEPLAY_CAM_YAW(float minimum, float maximum) { invoke<Void>(0x590571DE656BA0A3, minimum, maximum); } // 0x590571DE656BA0A3 0x749909AC
	static void _CLAMP_GAMEPLAY_CAM_PITCH(float minimum, float maximum) { invoke<Void>(0xD7ED5B60908EABF8, minimum, maximum); } // 0xD7ED5B60908EABF8 0xFA3A16E7
	static void _ANIMATE_GAMEPLAY_CAM_ZOOM(float p0, float distance) { invoke<Void>(0x5D1C2A538048B57E, p0, distance); } // 0x5D1C2A538048B57E 0x77340650
	static void _0x366682A1A4BCD59D(Vehicle p0, int p1) { invoke<Void>(0x366682A1A4BCD59D, p0, p1); } // 0x366682A1A4BCD59D 0x4B22C5CB
	static void _DISABLE_FIRST_PERSON_CAM_THIS_FRAME() { invoke<Void>(0x46CE2F145CA939F9); } // 0x46CE2F145CA939F9
	static void _0x39C93C3B090205B7() { invoke<Void>(0x39C93C3B090205B7); } // 0x39C93C3B090205B7
	static int GET_FOLLOW_PED_CAM_ZOOM_LEVEL() { return invoke<int>(0x11C9E22936F55273); } // 0x11C9E22936F55273 0x57583DF1
	static int GET_FOLLOW_PED_CAM_VIEW_MODE() { return invoke<int>(0x1066E7A58E2A0D9D); } // 0x1066E7A58E2A0D9D 0xA65FF946
	static void SET_FOLLOW_PED_CAM_VIEW_MODE(int viewMode) { invoke<Void>(0xA3B0E09AABBA9D26, viewMode); } // 0xA3B0E09AABBA9D26 0x495DBE8D
	static BOOL IS_FOLLOW_VEHICLE_CAM_ACTIVE() { return invoke<BOOL>(0xBB4A435CD6A72A8E); } // 0xBB4A435CD6A72A8E 0x8DD49B77
	static void _0xF1529170541DB59D(BOOL p0) { invoke<Void>(0xF1529170541DB59D, p0); } // 0xF1529170541DB59D 0x9DB5D391
	static void SET_TIME_IDLE_DROP(BOOL p0, BOOL p1) { invoke<Void>(0x3BDF797358DC23E8, p0, p1); } // 0x3BDF797358DC23E8 0x92302899
	static int GET_FOLLOW_VEHICLE_CAM_ZOOM_LEVEL() { return invoke<int>(0x3C92B24329DC0C37); } // 0x3C92B24329DC0C37 0x8CD67DE3
	static void SET_FOLLOW_VEHICLE_CAM_ZOOM_LEVEL(int zoomLevel) { invoke<Void>(0x549512E2BF95A1F4, zoomLevel); } // 0x549512E2BF95A1F4 0x8F55EBBE
	static int GET_FOLLOW_VEHICLE_CAM_VIEW_MODE() { return invoke<int>(0x428CA09FA2E92B87); } // 0x428CA09FA2E92B87 0xA4B4DB03
	static void SET_FOLLOW_VEHICLE_CAM_VIEW_MODE(int viewMode) { invoke<Void>(0xD6B605293CA6F397, viewMode); } // 0xD6B605293CA6F397 0xC4FBBBD3
	static Any _0xB866C0EABE959340(Any p0) { return invoke<Any>(0xB866C0EABE959340, p0); } // 0xB866C0EABE959340 0xF3B148A6
	static void _0x09E1CFE7DC472882(Any p0, Any p1) { invoke<Void>(0x09E1CFE7DC472882, p0, p1); } // 0x09E1CFE7DC472882 0x1DEBCB45
	static Any _0xB2CED41F4337ED8B() { return invoke<Any>(0xB2CED41F4337ED8B); } // 0xB2CED41F4337ED8B
	static BOOL IS_AIM_CAM_ACTIVE() { return invoke<BOOL>(0x5053725CE851B850); } // 0x5053725CE851B850 0xC24B4F6F
	static Any _0x716244DC9623EFC8() { return invoke<Any>(0x716244DC9623EFC8); } // 0x716244DC9623EFC8 0x8F320DE4
	static BOOL IS_FIRST_PERSON_AIM_CAM_ACTIVE() { return invoke<BOOL>(0x8BE30CF2E1E63744); } // 0x8BE30CF2E1E63744 0xD6280468
	static void DISABLE_AIM_CAM_THIS_UPDATE() { invoke<Void>(0x48A3BA6F79259A15); } // 0x48A3BA6F79259A15 0x1BAA7182
	static float _GET_GAMEPLAY_CAM_ZOOM() { return invoke<float>(0x6EC62956F36764D4); } // 0x6EC62956F36764D4 0x33951005
	static void _0x8A2806A8676E1544(float p0) { invoke<Void>(0x8A2806A8676E1544, p0); } // 0x8A2806A8676E1544 0x9F4AF763
	static void _0xD25E47CF083D3A94(float p0, float p1) { invoke<Void>(0xD25E47CF083D3A94, p0, p1); } // 0xD25E47CF083D3A94 0x68BA0730
	static void _0xAC52D65705A34D64(float p0, float p1) { invoke<Void>(0xAC52D65705A34D64, p0, p1); } // 0xAC52D65705A34D64 0x2F29F0D5
	static void _0x1E181EBBCD76772F(float p0, float p1) { invoke<Void>(0x1E181EBBCD76772F, p0, p1); } // 0x1E181EBBCD76772F 0x76DAC96C
	static void _0xEE2B16DF9C4A8B9A(float p0) { invoke<Void>(0xEE2B16DF9C4A8B9A, p0); } // 0xEE2B16DF9C4A8B9A 0x0E21069D
	static void _0x5C8C2A00426666A9(float p0) { invoke<Void>(0x5C8C2A00426666A9, p0); } // 0x5C8C2A00426666A9 0x71E9C63E
	static void _0x05B926FDCA4BC864(BOOL p0) { invoke<Void>(0x05B926FDCA4BC864, p0); } // 0x05B926FDCA4BC864 0xD1EEBC45
	static Vector3 _GET_GAMEPLAY_CAM_COORDS() { return invoke<Vector3>(0xF2AD13C8E9138D4B); } // 0xF2AD13C8E9138D4B 0x9C84BDA0
	static Vector3 _GET_GAMEPLAY_CAM_ROT(int p0) { return invoke<Vector3>(0x985A4B24DCC9234C, p0); } // 0x985A4B24DCC9234C 0x1FFBEFC5
	static Vector3 _0x404F0513F2294C43(Any p0, Any p1) { return invoke<Vector3>(0x404F0513F2294C43, p0, p1); } // 0x404F0513F2294C43 0xACADF916
	static Any _0xF3A75749B3F96B25() { return invoke<Any>(0xF3A75749B3F96B25); } // 0xF3A75749B3F96B25 0x721B763B
	static float _0x4419F8B7206C034B(Any p0) { return invoke<float>(0x4419F8B7206C034B, p0); } // 0x4419F8B7206C034B 0x23E3F106
	static Any _0xDDA62FC05E539336() { return invoke<Any>(0xDDA62FC05E539336); } // 0xDDA62FC05E539336 0x457AE195
	static Any _0x0D1F7887B4888108() { return invoke<Any>(0x0D1F7887B4888108); } // 0x0D1F7887B4888108 0x46CB3A49
	static Any _0x9314E9E36BFF838A() { return invoke<Any>(0x9314E9E36BFF838A); } // 0x9314E9E36BFF838A 0x19297A7A
	static Any _0x95A893C1815D3FB8() { return invoke<Any>(0x95A893C1815D3FB8); } // 0x95A893C1815D3FB8 0xF24777CA
	static Any _0xA4C8A4F41457012B() { return invoke<Any>(0xA4C8A4F41457012B); } // 0xA4C8A4F41457012B 0x38992E83
	static void SET_GAMEPLAY_COORD_HINT(float p0, float p1, float p2, Any p3, Any p4, Any p5, Any p6) { invoke<Void>(0x572C7F438DD94431, p0, p1, p2, p3, p4, p5, p6); } // 0x572C7F438DD94431 0xF27483C9
	static void SET_GAMEPLAY_PED_HINT(Ped p0, float x1, float y1, float z1, BOOL p4, Any p5, Any p6, Any p7) { invoke<Void>(0x140A91960D6938B9, p0, x1, y1, z1, p4, p5, p6, p7); } // 0x140A91960D6938B9 0x7C27343E
	static void SET_GAMEPLAY_VEHICLE_HINT(Any p0, float p1, float p2, float p3, BOOL p4, Any p5, Any p6, Any p7) { invoke<Void>(0x7311F9D2C4E44EDB, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x7311F9D2C4E44EDB 0x2C9A11D8
	static void SET_GAMEPLAY_OBJECT_HINT(Any p0, float p1, float p2, float p3, BOOL p4, Any p5, Any p6, Any p7) { invoke<Void>(0x487BC3009C8C5CC9, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x487BC3009C8C5CC9 0x2ED5E2F8
	static void SET_GAMEPLAY_ENTITY_HINT(Entity entity, float xOffset, float yOffset, float zOffset, BOOL p4, int p5, int p6, int p7, Any p8) { invoke<Void>(0x986AC95588E8693B, entity, xOffset, yOffset, zOffset, p4, p5, p6, p7, p8); } // 0x986AC95588E8693B 0x66C32306
	static BOOL IS_GAMEPLAY_HINT_ACTIVE() { return invoke<BOOL>(0xAB01297DD4A8577F); } // 0xAB01297DD4A8577F 0xAD8DA205
	static void STOP_GAMEPLAY_HINT(BOOL p0) { invoke<Void>(0x72B6EAB729050F5B, p0); } // 0x72B6EAB729050F5B 0x1BC28B7B
	static void _0xE507F2F4575755C3(BOOL p0) { invoke<Void>(0xE507F2F4575755C3, p0); } // 0xE507F2F4575755C3 0xCAFEE798
	static void _0xEF718DC7AB9F2C1D(BOOL p0) { invoke<Void>(0xEF718DC7AB9F2C1D, p0); } // 0xEF718DC7AB9F2C1D
	static Any _0x4CA57FB96E3E4ED2() { return invoke<Any>(0x4CA57FB96E3E4ED2); } // 0x4CA57FB96E3E4ED2
	static void SET_GAMEPLAY_HINT_FOV(float FOV) { invoke<Void>(0x052981497D46112E, FOV); } // 0x052981497D46112E 0x96FD173B
	static void _0x32CE35B63F0BF48D(float p0) { invoke<Void>(0x32CE35B63F0BF48D, p0); } // 0x32CE35B63F0BF48D 0x72E8CD3A
	static void _0xACC12FC81030C21A(float p0) { invoke<Void>(0xACC12FC81030C21A, p0); } // 0xACC12FC81030C21A 0x79472AE3
	static void _0x254ECD140D986976(float p0) { invoke<Void>(0x254ECD140D986976, p0); } // 0x254ECD140D986976 0xFC7464A0
	static void _0xAE5FD86A4AD93299(float p0) { invoke<Void>(0xAE5FD86A4AD93299, p0); } // 0xAE5FD86A4AD93299 0x3554AA0E
	static void GET_IS_MULTIPLAYER_BRIEF(BOOL p0) { invoke<Void>(0x7C685139990C384F, p0); } // 0x7C685139990C384F 0x2F0CE859
	static void SET_CINEMATIC_BUTTON_ACTIVE(BOOL p0) { invoke<Void>(0x73624B45C8E405BA, p0); } // 0x73624B45C8E405BA 0x3FBC5D00
	static BOOL IS_CINEMATIC_CAM_RENDERING() { return invoke<BOOL>(0x52B03F09ABF2ECF6); } // 0x52B03F09ABF2ECF6 0x80471AD9
	static void SHAKE_CINEMATIC_CAM(char* p0, float p1) { invoke<Void>(0x6D88E5E936ADD868, p0, p1); } // 0x6D88E5E936ADD868 0x61815F31
	static BOOL IS_CINEMATIC_CAM_SHAKING() { return invoke<BOOL>(0x4B4822665CC22060); } // 0x4B4822665CC22060 0x8376D939
	static void SET_CINEMATIC_CAM_SHAKE_AMPLITUDE(float p0) { invoke<Void>(0x450C8FB521762758, p0); } // 0x450C8FB521762758 0x67510C4B
	static void STOP_CINEMATIC_CAM_SHAKING(BOOL p0) { invoke<Void>(0xFD6E64AFF9352C00, p0); } // 0xFD6E64AFF9352C00 0x71C12904
	static void _DISABLE_VEHICLE_FIRST_PERSON_CAM_THIS_FRAME() { invoke<Void>(0x0E19E128E7EDB92D); } // 0x0E19E128E7EDB92D 0x5AC6DAC9
	static void _0x4A92E8EB1847512B() { invoke<Void>(0x4A92E8EB1847512B); } // 0x4A92E8EB1847512B 0x837F8581
	static void _0xF21388F719E17A6B() { invoke<Void>(0xF21388F719E17A6B); } // 0xF21388F719E17A6B 0x65DDE8AF
	static void _0xEE7439C2B53B715A() { invoke<Void>(0xEE7439C2B53B715A); } // 0xEE7439C2B53B715A 0xD75CDD75
	static Any _0x9F4D6722ADD0AF7E() { return invoke<Any>(0x9F4D6722ADD0AF7E); } // 0x9F4D6722ADD0AF7E 0x96A07066
	static Any _0xC448AAB174DBB233() { return invoke<Any>(0xC448AAB174DBB233); } // 0xC448AAB174DBB233
	static void CREATE_CINEMATIC_SHOT(Any p0, int p1, Any p2, Entity entity) { invoke<Void>(0xFE9A918F5C252AD0, p0, p1, p2, entity); } // 0xFE9A918F5C252AD0 0xAC494E35
	static BOOL IS_CINEMATIC_SHOT_ACTIVE(Any p0) { return invoke<BOOL>(0x881842388B0F0F90, p0); } // 0x881842388B0F0F90 0xA4049042
	static void STOP_CINEMATIC_SHOT(Any p0) { invoke<Void>(0x5F8771202EC72242, p0); } // 0x5F8771202EC72242 0xD78358C5
	static void _0xA9F1F9B054B25077(BOOL p0) { invoke<Void>(0xA9F1F9B054B25077, p0); } // 0xA9F1F9B054B25077 0xFBB85E02
	static void _0xC4B4F436CE32E937() { invoke<Void>(0xC4B4F436CE32E937); } // 0xC4B4F436CE32E937 0x4938C82F
	static void SET_CINEMATIC_MODE_ACTIVE(BOOL p0) { invoke<Void>(0x8C29CF9A058B556F, p0); } // 0x8C29CF9A058B556F 0x2009E747
	static Any _0x4C3947D350B9E253() { return invoke<Any>(0x4C3947D350B9E253); } // 0x4C3947D350B9E253 0x6739AD55
	static Any _0xA07E0C7D04CFDAC7() { return invoke<Any>(0xA07E0C7D04CFDAC7); } // 0xA07E0C7D04CFDAC7
	static void STOP_CUTSCENE_CAM_SHAKING() { invoke<Void>(0xE0F377A90784A9D7); } // 0xE0F377A90784A9D7 0xF07D603D
	static void _0x3E90B76C7865261F(float p0) { invoke<Void>(0x3E90B76C7865261F, p0); } // 0x3E90B76C7865261F 0x067BA6F5
	static Any _0x0D9853624D56642D(float p0, Any p1, float p2, float p3, float p4, float p5, float p6, Any p7, Any p8) { return invoke<Any>(0x0D9853624D56642D, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x0D9853624D56642D 0xFD99BE2B
	static void _0x2DEC6B4621296183() { invoke<Void>(0x2DEC6B4621296183); } // 0x2DEC6B4621296183 0xE206C450
	static void _SET_CAM_EFFECT(int p0) { invoke<Void>(0xDF3F1B5E6EBADFFC, p0); } // 0xDF3F1B5E6EBADFFC 0xB06CCD38
	static void _0x4E795B68CDAA6897(Any p0) { invoke<Void>(0x4E795B68CDAA6897, p0); } // 0x4E795B68CDAA6897
	static void _0x1C67BB36B3613D99(char* vehicleName) { invoke<Void>(0x1C67BB36B3613D99, vehicleName); } // 0x1C67BB36B3613D99
	static void _0x3756576D20DDE4C4(Any p0) { invoke<Void>(0x3756576D20DDE4C4, p0); } // 0x3756576D20DDE4C4
	static Any _0x703C0197BDB431F6() { return invoke<Any>(0x703C0197BDB431F6); } // 0x703C0197BDB431F6
	static Any _0x5134E5E4F9AB5F57() { return invoke<Any>(0x5134E5E4F9AB5F57); } // 0x5134E5E4F9AB5F57
}

namespace WEAPON
{
	static void ENABLE_LASER_SIGHT_RENDERING(BOOL toggle) { invoke<Void>(0x045DC168F6FAE9B8, toggle); } // 0x045DC168F6FAE9B8 0xE3438955
	static Hash GET_WEAPON_COMPONENT_TYPE_MODEL(Hash componentHash) { return invoke<Hash>(0x6D50068985D5EFE0, componentHash); } // 0x6D50068985D5EFE0 0x324FA47A
	static Hash GET_WEAPONTYPE_MODEL(Hash weaponHash) { return invoke<Hash>(0xD5D69CE5364D1F97, weaponHash); } // 0xD5D69CE5364D1F97 0x44E1C269
	static Hash GET_WEAPONTYPE_SLOT(Hash weaponHash) { return invoke<Hash>(0xD7EFB605744F64DD, weaponHash); } // 0xD7EFB605744F64DD 0x2E3759AF
	static Hash GET_WEAPONTYPE_GROUP(Hash weaponHash) { return invoke<Hash>(0x4E2D036E7A49AA3D, weaponHash); } // 0x4E2D036E7A49AA3D 0x5F2DE833
	static void SET_CURRENT_PED_WEAPON(Ped ped, Hash weaponHash, BOOL equipNow) { invoke<Void>(0x0B25AB3A7FA0683C, ped, weaponHash, equipNow); } // 0x0B25AB3A7FA0683C 0xB8278882
	static BOOL GET_CURRENT_PED_WEAPON(Ped ped, Hash* weaponHash, BOOL p2) { return invoke<BOOL>(0x5CD8291F2C5E0AD1, ped, weaponHash, p2); } // 0x5CD8291F2C5E0AD1 0xB0237302
	static Entity GET_CURRENT_PED_WEAPON_ENTITY_INDEX(Ped ped) { return invoke<Entity>(0x8AEC1EA268158819, ped); } // 0x8AEC1EA268158819 0x5D73CD20
	static Hash GET_BEST_PED_WEAPON(Ped ped, BOOL p1) { return invoke<Hash>(0xF3C119E091C0DFEC, ped, p1); } // 0xF3C119E091C0DFEC 0xB998D444
	static BOOL SET_CURRENT_PED_VEHICLE_WEAPON(Ped ped, Hash weaponHash) { return invoke<BOOL>(0x9E087EF1619B5C7B, ped, weaponHash); } // 0x9E087EF1619B5C7B 0x8E6F2AF1
	static BOOL GET_CURRENT_PED_VEHICLE_WEAPON(Ped ped, Hash* weaponHash) { return invoke<BOOL>(0x92A0CEE6C61DA188, ped, weaponHash); } // 0x92A0CEE6C61DA188 0xF26C5D65
	static BOOL IS_PED_ARMED(Ped ped, int p1) { return invoke<BOOL>(0x758839786F3B98F0, ped, p1); } // 0x758839786F3B98F0 0x0BFC892C
	static BOOL IS_WEAPON_VALID(Hash weaponHash) { return invoke<BOOL>(0x3DF31EDD1F139A64, weaponHash); } // 0x3DF31EDD1F139A64 0x38CA2954
	static BOOL HAS_PED_GOT_WEAPON(Ped ped, Hash weaponHash, BOOL p2) { return invoke<BOOL>(0x509A3191A6C4EB38, ped, weaponHash, p2); } // 0x509A3191A6C4EB38 0x43D2FA82
	static BOOL IS_PED_WEAPON_READY_TO_SHOOT(Ped ped) { return invoke<BOOL>(0xAFA764E7E6249161, ped); } // 0xAFA764E7E6249161 0x02A32CB0
	static Hash GET_PED_WEAPONTYPE_IN_SLOT(Ped ped, Hash weaponSlot) { return invoke<Hash>(0x937B062731EC9E7B, ped, weaponSlot); } // 0x937B062731EC9E7B 0x9BC64E16
	static int GET_AMMO_IN_PED_WEAPON(Ped ped, Hash weaponhash) { return invoke<int>(0x034EB52F6D89BFA0, ped, weaponhash); } // 0x034EB52F6D89BFA0 0x0C755733
	static void ADD_AMMO_TO_PED(Ped ped, Hash weaponHash, int ammo) { invoke<Void>(0x66B30A22DE11CA97, ped, weaponHash, ammo); } // 0x66B30A22DE11CA97 0x7F0580C7
	static void SET_PED_AMMO(Ped ped, Hash weaponHash, int ammo) { invoke<Void>(0xD8DA14EE2EDB99FE, ped, weaponHash, ammo); } // 0xD8DA14EE2EDB99FE 0xBF90DF1A
	static void SET_PED_INFINITE_AMMO(Ped ped, BOOL toggle, Hash weaponHash) { invoke<Void>(0xD453481683596C5B, ped, toggle, weaponHash); } // 0xD453481683596C5B 0x9CB8D278
	static void SET_PED_INFINITE_AMMO_CLIP(Ped ped, BOOL toggle) { invoke<Void>(0x0CFD29F9D2B7942B, ped, toggle); } // 0x0CFD29F9D2B7942B 0x5A5E3B67
	static void GIVE_WEAPON_TO_PED(Ped ped, Hash weaponHash, int ammoCount, BOOL isHidden, BOOL equipNow) { invoke<Void>(0xC1B7B5C6FDC0755B, ped, weaponHash, ammoCount, isHidden, equipNow); } // 0xC1B7B5C6FDC0755B 0xC4D88A85
	static void GIVE_DELAYED_WEAPON_TO_PED(Ped ped, Hash weaponHash, int time, BOOL equipNow) { invoke<Void>(0xBA8CA9172F194131, ped, weaponHash, time, equipNow); } // 0xBA8CA9172F194131 0x5868D20D
	static void REMOVE_ALL_PED_WEAPONS(Ped ped, BOOL toggle) { invoke<Void>(0x39DF32F630CC12A7, ped, toggle); } // 0x39DF32F630CC12A7 0xA44CE817
	static void REMOVE_WEAPON_FROM_PED(Ped ped, Hash weaponHash) { invoke<Void>(0x9CA872E9BF4DF131, ped, weaponHash); } // 0x9CA872E9BF4DF131 0x9C37F220
	static void HIDE_PED_WEAPON_FOR_SCRIPTED_CUTSCENE(Ped ped, BOOL toggle) { invoke<Void>(0x774537030DC49089, ped, toggle); } // 0x774537030DC49089 0x00CFD6E9
	static void SET_PED_CURRENT_WEAPON_VISIBLE(Ped ped, BOOL visible, BOOL deselectWeapon, BOOL p3, BOOL p4) { invoke<Void>(0x8D64D92D113BBFB7, ped, visible, deselectWeapon, p3, p4); } // 0x8D64D92D113BBFB7 0x00BECD77
	static void SET_PED_DROPS_WEAPONS_WHEN_DEAD(Ped ped, BOOL toggle) { invoke<Void>(0xED5EF5D8ACAFCEE8, ped, toggle); } // 0xED5EF5D8ACAFCEE8 0x8A444056
	static BOOL HAS_PED_BEEN_DAMAGED_BY_WEAPON(Ped ped, Hash weaponHash, int weaponType) { return invoke<BOOL>(0xD5C8AEE22F8A47C7, ped, weaponHash, weaponType); } // 0xD5C8AEE22F8A47C7 0xCDFBBCC6
	static void CLEAR_PED_LAST_WEAPON_DAMAGE(Ped ped) { invoke<Void>(0xE7DDE11F818A6118, ped); } // 0xE7DDE11F818A6118 0x52C68832
	static BOOL HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON(Entity entity, Hash weaponHash, int weaponType) { return invoke<BOOL>(0x68EF3B23B93EEB24, entity, weaponHash, weaponType); } // 0x68EF3B23B93EEB24 0x6DAABB39
	static void CLEAR_ENTITY_LAST_WEAPON_DAMAGE(Entity entity) { invoke<Void>(0x0E63611F98E0F949, entity); } // 0x0E63611F98E0F949 0xCEC2732B
	static void SET_PED_DROPS_WEAPON(Ped ped) { invoke<Void>(0xE123B8AA81BD49CF, ped); } // 0xE123B8AA81BD49CF 0x3D3329FA
	static void SET_PED_DROPS_INVENTORY_WEAPON(Ped ped, Hash weaponHash, float xOffset, float yOffset, float zOffset, Any p5) { invoke<Void>(0xF92C8F7415D8958D, ped, weaponHash, xOffset, yOffset, zOffset, p5); } // 0xF92C8F7415D8958D 0x81FFB874
	static int GET_MAX_AMMO_IN_CLIP(Ped ped, Hash weaponHash, BOOL p2) { return invoke<int>(0xE167DB47685AF158, ped, weaponHash, p2); } // 0xE167DB47685AF158 0x6961E2A4
	static BOOL GET_AMMO_IN_CLIP(Ped ped, Hash weaponHash, int* ammo) { return invoke<BOOL>(0x2668E4CEBC03647A, ped, weaponHash, ammo); } // 0x2668E4CEBC03647A 0x73C100C3
	static BOOL SET_AMMO_IN_CLIP(Ped ped, Hash weaponHash, int ammo) { return invoke<BOOL>(0xACC235DBD5C9F713, ped, weaponHash, ammo); } // 0xACC235DBD5C9F713 0xA54B0B10
	static BOOL GET_MAX_AMMO(Ped ped, Hash weaponHash, int* ammo) { return invoke<BOOL>(0xEC52867E1145BD99, ped, weaponHash, ammo); } // 0xEC52867E1145BD99 0x0B294796
	static void SET_PED_AMMO_BY_TYPE(Ped ped, Any ammoType, int ammo) { invoke<Void>(0x671BF5885E5A840E, ped, ammoType, ammo); } // 0x671BF5885E5A840E 0x311C52BB
	static int GET_PED_AMMO_BY_TYPE(Ped ped, Any ammoType) { return invoke<int>(0x038A838BA92495ED, ped, ammoType); } // 0x038A838BA92495ED 0x54077C4D
	static void SET_PED_AMMO_TO_DROP(Any p0, Any p1) { invoke<Void>(0xEBB4FB5B2EF5A9DD, p0, p1); } // 0xEBB4FB5B2EF5A9DD 0x2386A307
	static void _0xFCA562A89D9C48A1(float p0) { invoke<Void>(0xFCA562A89D9C48A1, p0); } // 0xFCA562A89D9C48A1 0xD6460EA2
	static Hash GET_PED_AMMO_TYPE_FROM_WEAPON(Ped ped, Hash weaponHash) { return invoke<Hash>(0x67C0DE1556F43AE2, ped, weaponHash); } // 0x67C0DE1556F43AE2 0x09337863
	static BOOL GET_PED_LAST_WEAPON_IMPACT_COORD(Ped ped, Vector3* coords) { return invoke<BOOL>(0x7D79BE5A083FDF7B, ped, coords); } // 0x7D79BE5A083FDF7B 0x9B266079
	static void SET_PED_GADGET(Ped ped, Hash gadgetHash, BOOL p2) { invoke<Void>(0x70A753C714FABCD1, ped, gadgetHash, p2); } // 0x70A753C714FABCD1 0x8A256D0A
	static BOOL GET_IS_PED_GADGET_EQUIPPED(Ped ped, Hash gadgetHash) { return invoke<BOOL>(0xBA11591586E3ABFF, ped, gadgetHash); } // 0xBA11591586E3ABFF 0x8DDD0B5B
	static Hash GET_SELECTED_PED_WEAPON(Ped ped) { return invoke<Hash>(0x7FE5AAFFD84F38D2, ped); } // 0x7FE5AAFFD84F38D2 0xD240123E
	static void EXPLODE_PROJECTILES(Ped ped, Hash weaponHash, BOOL p2) { invoke<Void>(0x359125AF4AE6C89D, ped, weaponHash, p2); } // 0x359125AF4AE6C89D 0x35A0B955
	static void REMOVE_ALL_PROJECTILES_OF_TYPE(Hash weaponHash, BOOL p1) { invoke<Void>(0xFAA53C4CE0A5D10A, weaponHash, p1); } // 0xFAA53C4CE0A5D10A 0xA5F89919
	static float _GET_LOCKON_RANGE_OF_CURRENT_PED_WEAPON(Ped ped) { return invoke<float>(0xA5023410CA1B97CF, ped); } // 0xA5023410CA1B97CF 0x3612110D
	static float GET_MAX_RANGE_OF_CURRENT_PED_WEAPON(Ped ped) { return invoke<float>(0x7CFCCA0F231180BC, ped); } // 0x7CFCCA0F231180BC 0xB2B2BBAA
	static BOOL HAS_VEHICLE_GOT_PROJECTILE_ATTACHED(Ped driver, Vehicle vehicle, Hash weapon, Any p3) { return invoke<BOOL>(0x8BE51858141C7DCA, driver, vehicle, weapon, p3); } // 0x8BE51858141C7DCA 0xA57E2E80
	static void GIVE_WEAPON_COMPONENT_TO_PED(Ped ped, Hash weaponHash, Hash componentHash) { invoke<Void>(0xE6E5306966C198A6, ped, weaponHash, componentHash); } // 0xE6E5306966C198A6 0x3E1E286D
	static void REMOVE_WEAPON_COMPONENT_FROM_PED(Ped ped, Hash weaponHash, Hash componentHash) { invoke<Void>(0x7E07C583ECF896DA, ped, weaponHash, componentHash); } // 0x7E07C583ECF896DA 0x412AA00D
	static BOOL HAS_PED_GOT_WEAPON_COMPONENT(Ped ped, Hash weaponHash, Hash componentHash) { return invoke<BOOL>(0xF848952075C9EC8A, ped, weaponHash, componentHash); } // 0xF848952075C9EC8A 0xDC0FC145
	static BOOL IS_PED_WEAPON_COMPONENT_ACTIVE(Ped ped, Hash weaponHash, Hash componentHash) { return invoke<BOOL>(0xAF582CE9DC06303F, ped, weaponHash, componentHash); } // 0xAF582CE9DC06303F 0x7565FB19
	static BOOL _IS_PED_RELOADING(Ped ped) { return invoke<BOOL>(0x0A972CD5EE258C93, ped); } // 0x0A972CD5EE258C93 0x82EEAF0F
	static BOOL MAKE_PED_RELOAD(Ped ped) { return invoke<BOOL>(0xB616D2C930307E4F, ped); } // 0xB616D2C930307E4F 0x515292C2
	static void REQUEST_WEAPON_ASSET(Hash weaponHash, int p1, int p2) { invoke<Void>(0xD0001D3ECB0CB35E, weaponHash, p1, p2); } // 0xD0001D3ECB0CB35E 0x65D139A5
	static BOOL HAS_WEAPON_ASSET_LOADED(Hash weaponHash) { return invoke<BOOL>(0xC1C884D9C9FA3699, weaponHash); } // 0xC1C884D9C9FA3699 0x1891D5BB
	static void REMOVE_WEAPON_ASSET(Hash weaponHash) { invoke<Void>(0x1309F0C1CB4DA798, weaponHash); } // 0x1309F0C1CB4DA798 0x2C0DFE3C
	static Object CREATE_WEAPON_OBJECT(Hash weaponHash, int ammoCount, float x, float y, float z, BOOL showWorldModel, float heading, Any p7) { return invoke<Object>(0xF6AE9814F412E86C, weaponHash, ammoCount, x, y, z, showWorldModel, heading, p7); } // 0xF6AE9814F412E86C 0x62F5987F
	static void GIVE_WEAPON_COMPONENT_TO_WEAPON_OBJECT(Object weaponObject, Hash addonHash) { invoke<Void>(0xF52314A971B84658, weaponObject, addonHash); } // 0xF52314A971B84658 0xF7612A37
	static void REMOVE_WEAPON_COMPONENT_FROM_WEAPON_OBJECT(Any p0, Any p1) { invoke<Void>(0xE8E90BD6862AA376, p0, p1); } // 0xE8E90BD6862AA376 0xA6E7ED3C
	static BOOL HAS_WEAPON_GOT_WEAPON_COMPONENT(Object weapon, Hash addonHash) { return invoke<BOOL>(0xAAE4AB3492A11C80, weapon, addonHash); } // 0xAAE4AB3492A11C80 0x1D368510
	static void GIVE_WEAPON_OBJECT_TO_PED(Object weaponObject, Ped ped) { invoke<Void>(0x9FBE0CDB60B9F058, weaponObject, ped); } // 0x9FBE0CDB60B9F058 0x639AF3EF
	static BOOL DOES_WEAPON_TAKE_WEAPON_COMPONENT(Hash weaponHash, Hash componentHash) { return invoke<BOOL>(0xA5397B8793256FE5, weaponHash, componentHash); } // 0xA5397B8793256FE5 0xB1817BAA
	static Object GET_WEAPON_OBJECT_FROM_PED(Ped ped, BOOL p1) { return invoke<Object>(0x897D94DABE7539A5, ped, p1); } // 0x897D94DABE7539A5 0xDF939A38
	static void SET_PED_WEAPON_TINT_INDEX(Ped ped, Hash weaponHash, int colorIndex) { invoke<Void>(0x5B92F123AC9475C6, ped, weaponHash, colorIndex); } // 0x5B92F123AC9475C6 0xEB2A7B23
	static int GET_PED_WEAPON_TINT_INDEX(Ped ped, Hash weaponHash) { return invoke<int>(0x56D81513B2CCEDD3, ped, weaponHash); } // 0x56D81513B2CCEDD3 0x3F9C90A7
	static void SET_WEAPON_OBJECT_TINT_INDEX(Entity weapon, int tint) { invoke<Void>(0x68B5EE84AB7433B4, weapon, tint); } // 0x68B5EE84AB7433B4 0x44ACC1DA
	static int GET_WEAPON_OBJECT_TINT_INDEX(Entity weapon) { return invoke<int>(0x3942968E39D40A6C, weapon); } // 0x3942968E39D40A6C 0xD91D9576
	static int GET_WEAPON_TINT_COUNT(Hash weaponHash) { return invoke<int>(0x4D7C6FFAE325BC8B, weaponHash); } // 0x4D7C6FFAE325BC8B 0x99E4EAAB
	static BOOL GET_WEAPON_HUD_STATS(Any p0, Any* p1) { return invoke<BOOL>(0x9DA41BA21FEE026A, p0, p1); } // 0x9DA41BA21FEE026A 0xA9AD3D98
	static BOOL GET_WEAPON_COMPONENT_HUD_STATS(Any p0, Any* p1) { return invoke<BOOL>(0x5A554CFF0BFFB7E1, p0, p1); } // 0x5A554CFF0BFFB7E1 0xBB5498F4
	static float _0xC0173D62EF0C2231(Any p0, Any p1) { return invoke<float>(0xC0173D62EF0C2231, p0, p1); } // 0xC0173D62EF0C2231
	static int GET_WEAPON_CLIP_SIZE(Hash weaponHash) { return invoke<int>(0xD7C4F4F887ACB7D7, weaponHash); } // 0xD7C4F4F887ACB7D7 0x8D515E66
	static void SET_PED_CHANCE_OF_FIRING_BLANKS(Ped ped, float xBias, float yBias) { invoke<Void>(0xC117A6C80516DC40, ped, xBias, yBias); } // 0xC117A6C80516DC40 0xB4F44C6E
	static Entity _0x685BF4CFA33B059A(Ped ped, float p1) { return invoke<Entity>(0x685BF4CFA33B059A, ped, p1); } // 0x685BF4CFA33B059A 0xEC2E5304
	static void REQUEST_WEAPON_HIGH_DETAIL_MODEL(Entity weaponObject) { invoke<Void>(0x5550862943F0F042, weaponObject); } // 0x5550862943F0F042 0xE3BD00F9
	static BOOL IS_PED_CURRENT_WEAPON_SILENCED(Ped ped) { return invoke<BOOL>(0xDC93048D895B2146, ped); } // 0xDC93048D895B2146 0xBAF7BFBE
	static BOOL SET_WEAPON_SMOKEGRENADE_ASSIGNED(Ped ped) { return invoke<BOOL>(0x3C48751F7C0BED05, ped); } // 0x3C48751F7C0BED05 0x76876154
	static Any SET_FLASH_LIGHT_FADE_DISTANCE(float distance) { return invoke<Any>(0x8D78293B4629C6EE, distance); } // 0x8D78293B4629C6EE 0xB0127EA7
	static void SET_WEAPON_ANIMATION_OVERRIDE(Ped ped, Hash animStyle) { invoke<Void>(0x99800391C4C74EF7, ped, animStyle); } // 0x99800391C4C74EF7 0xA5DF7484
	static int GET_WEAPON_DAMAGE_TYPE(Hash weaponHash) { return invoke<int>(0x8A068AE6CC1FBC0D, weaponHash); } // 0x8A068AE6CC1FBC0D 0x013AFC13
	static void _0x7EAD13690222C765(Ped ped) { invoke<Void>(0x7EAD13690222C765, ped); } // 0x7EAD13690222C765 0x64646F1D
	static BOOL CAN_USE_WEAPON_ON_PARACHUTE(Hash weaponHash) { return invoke<BOOL>(0xE42DB87A7EC3DEA1, weaponHash); } // 0xE42DB87A7EC3DEA1 0x135E7AD4
}

namespace ITEMSET
{
	static Any CREATE_ITEMSET(BOOL p0) { return invoke<Any>(0x5EC1E46900DD77B4, p0); } // 0x5EC1E46900DD77B4 0x0A113B2C
	static void DESTROY_ITEMSET(Any p0) { invoke<Void>(0x652D8D7B805AF861, p0); } // 0x652D8D7B805AF861 0x83CE1A4C
	static BOOL IS_ITEMSET_VALID(Any p0) { return invoke<BOOL>(0x2259A8C117A3D6B7, p0); } // 0x2259A8C117A3D6B7 0xD201FC29
	static BOOL ADD_TO_ITEMSET(Any p0, Any p1) { return invoke<BOOL>(0x4EE7306CDCB3C07A, p0, p1); } // 0x4EE7306CDCB3C07A 0x6B0FE61B
	static void REMOVE_FROM_ITEMSET(Any p0, Any p1) { invoke<Void>(0x0C34B1CF9E2D2309, p0, p1); } // 0x0C34B1CF9E2D2309 0xA9565228
	static Any GET_ITEMSET_SIZE(Any p0) { return invoke<Any>(0xADAB429B27179EBC, p0); } // 0xADAB429B27179EBC 0x2B31F41A
	static Any GET_INDEXED_ITEM_IN_ITEMSET(Any p0, Any p1) { return invoke<Any>(0x281812FA8067FFA8, p0, p1); } // 0x281812FA8067FFA8 0x3F712874
	static BOOL IS_IN_ITEMSET(Any p0, Any p1) { return invoke<BOOL>(0xF71183A75AB512C8, p0, p1); } // 0xF71183A75AB512C8 0x0D4B9730
	static void CLEAN_ITEMSET(Any p0) { invoke<Void>(0x9C75FEB7FD1340D3, p0); } // 0x9C75FEB7FD1340D3 0x919A4858
}

namespace STREAMING
{
	static void LOAD_ALL_OBJECTS_NOW() { invoke<Void>(0x4722185376A85590); } // 0x4722185376A85590 0xC9DBDA90
	static void LOAD_SCENE(float x, float y, float z) { invoke<Void>(0x3FC7E3584ABA5F08, x, y, z); } // 0x3FC7E3584ABA5F08 0xB72403F5
	static Any NETWORK_UPDATE_LOAD_SCENE() { return invoke<Any>(0xB8CB7F774F532927); } // 0xB8CB7F774F532927 0xC76E023C
	static void NETWORK_STOP_LOAD_SCENE() { invoke<Void>(0x8DCD45C9EFB0D95A); } // 0x8DCD45C9EFB0D95A 0x24857907
	static BOOL IS_NETWORK_LOADING_SCENE() { return invoke<BOOL>(0x011455194DEB8842); } // 0x011455194DEB8842 0x6DCFC021
	static void SET_INTERIOR_ACTIVE(int interiorID, BOOL toggle) { invoke<Void>(0x88125DB6195C93A6, interiorID, toggle); } // 0x88125DB6195C93A6 0xE1013910
	static void REQUEST_MODEL(Hash model) { invoke<Void>(0xE1324F59713746FA, model); } // 0xE1324F59713746FA 0xFFF1B500
	static void _REQUEST_MODEL_2(Hash model) { invoke<Void>(0x236B2AA46AADC011, model); } // 0x236B2AA46AADC011 0x48CEB6B4
	static BOOL HAS_MODEL_LOADED(Hash model) { return invoke<BOOL>(0x9F746898F7881612, model); } // 0x9F746898F7881612 0x62BFDB37
	static void _0x96EFF28ACC4335E3(int interiorID, char* roomName) { invoke<Void>(0x96EFF28ACC4335E3, interiorID, roomName); } // 0x96EFF28ACC4335E3 0x939243FB
	static void SET_MODEL_AS_NO_LONGER_NEEDED(Hash model) { invoke<Void>(0x924CDE68BA2ED3BA, model); } // 0x924CDE68BA2ED3BA 0xAE0F069E
	static BOOL IS_MODEL_IN_CDIMAGE(Hash model) { return invoke<BOOL>(0x021538A59EA44D7A, model); } // 0x021538A59EA44D7A 0x1094782F
	static BOOL IS_MODEL_VALID(Hash model) { return invoke<BOOL>(0x152BAD1BB44F2768, model); } // 0x152BAD1BB44F2768 0xAF8F8E9D
	static BOOL IS_MODEL_A_VEHICLE(Hash model) { return invoke<BOOL>(0x2ED6701376DBCF71, model); } // 0x2ED6701376DBCF71 0xFFFC85D4
	static void REQUEST_COLLISION_AT_COORD(float x, float y, float z) { invoke<Void>(0x5E9D6E2030B03C36, x, y, z); } // 0x5E9D6E2030B03C36 0xCD9805E7
	static void REQUEST_COLLISION_FOR_MODEL(Hash model) { invoke<Void>(0xD0B354DA2DD694D9, model); } // 0xD0B354DA2DD694D9 0x3930C042
	static BOOL HAS_COLLISION_FOR_MODEL_LOADED(Hash model) { return invoke<BOOL>(0x93CCD536F22C73C6, model); } // 0x93CCD536F22C73C6 0x41A094F8
	static void REQUEST_ADDITIONAL_COLLISION_AT_COORD(float p0, float p1, float p2) { invoke<Void>(0xDC80E0571D441292, p0, p1, p2); } // 0xDC80E0571D441292 0xC2CC1DF2
	static BOOL DOES_ANIM_DICT_EXIST(char* animDict) { return invoke<BOOL>(0x83CF1C6187ECFA7E, animDict); } // 0x83CF1C6187ECFA7E 0xCD31C872
	static void REQUEST_ANIM_DICT(char* animDict) { invoke<Void>(0xA0E7D0E8FE126EE8, animDict); } // 0xA0E7D0E8FE126EE8 0xDCA96950
	static BOOL HAS_ANIM_DICT_LOADED(char* animDict) { return invoke<BOOL>(0xF4F8AE8DD0F08C1E, animDict); } // 0xF4F8AE8DD0F08C1E 0x05E6763C
	static void REMOVE_ANIM_DICT(char* animDict) { invoke<Void>(0xF9FFB9857F3120F8, animDict); } // 0xF9FFB9857F3120F8 0x0AE050B5
	static void REQUEST_ANIM_SET(char* animSet) { invoke<Void>(0xEFA1E47456B98380, animSet); } // 0xEFA1E47456B98380 0x2988B3FC
	static BOOL HAS_ANIM_SET_LOADED(char* animSet) { return invoke<BOOL>(0x0EC7C47AAD110FBD, animSet); } // 0x0EC7C47AAD110FBD 0x4FFF397D
	static void REMOVE_ANIM_SET(char* animSet) { invoke<Void>(0xA617A761C0955C65, animSet); } // 0xA617A761C0955C65 0xD04A817A
	static void REQUEST_CLIP_SET(char* clipSet) { invoke<Void>(0xFD2E59A7CCE66AB3, clipSet); } // 0xFD2E59A7CCE66AB3 0x546C627A
	static BOOL HAS_CLIP_SET_LOADED(char* clipSet) { return invoke<BOOL>(0x69EB2CB272E0AD5D, clipSet); } // 0x69EB2CB272E0AD5D 0x230D5455
	static void REMOVE_CLIP_SET(char* clipSet) { invoke<Void>(0x935A2175858BD59D, clipSet); } // 0x935A2175858BD59D 0x1E21F7AA
	static void REQUEST_IPL(char* iplName) { invoke<Void>(0x059B8D797D20327B, iplName); } // 0x059B8D797D20327B 0x3B70D1DB
	static void REMOVE_IPL(char* iplName) { invoke<Void>(0xE6A366D0E2B7DE39, iplName); } // 0xE6A366D0E2B7DE39 0xDF7CBD36
	static BOOL IS_IPL_ACTIVE(char* iplName) { return invoke<BOOL>(0x4C30048D7CAD04A5, iplName); } // 0x4C30048D7CAD04A5 0xB2C33714
	static void SET_STREAMING(BOOL toggle) { invoke<Void>(0xA4F5802CEA8E4461, toggle); } // 0xA4F5802CEA8E4461 0x27EF6CB2
	static void SET_GAME_PAUSES_FOR_STREAMING(BOOL toggle) { invoke<Void>(0x7314960FF9575FFA, toggle); } // 0x7314960FF9575FFA 0x9211A28A
	static void SET_REDUCE_PED_MODEL_BUDGET(BOOL toggle) { invoke<Void>(0x13317477711A04EA, toggle); } // 0x13317477711A04EA 0xAFCB2B86
	static void SET_REDUCE_VEHICLE_MODEL_BUDGET(BOOL toggle) { invoke<Void>(0x3E0593DDDA7C9B05, toggle); } // 0x3E0593DDDA7C9B05 0xCDB4FB7E
	static void SET_DITCH_POLICE_MODELS(BOOL toggle) { invoke<Void>(0x95E0F1D6C5BADC21, toggle); } // 0x95E0F1D6C5BADC21 0x3EA7FCE4
	static int GET_NUMBER_OF_STREAMING_REQUESTS() { return invoke<int>(0x7AAF7F43809CE9A6); } // 0x7AAF7F43809CE9A6 0xC2EE9A02
	static void REQUEST_PTFX_ASSET() { invoke<Void>(0xD250AE1AB37DC648); } // 0xD250AE1AB37DC648 0x2C649263
	static BOOL HAS_PTFX_ASSET_LOADED() { return invoke<BOOL>(0xD181F97E98E28C18); } // 0xD181F97E98E28C18 0x3EFF96BE
	static void REMOVE_PTFX_ASSET() { invoke<Void>(0x7D861B56FA788D3F); } // 0x7D861B56FA788D3F 0xC10F178C
	static void REQUEST_NAMED_PTFX_ASSET(char* fxName) { invoke<Void>(0x7F6F941DACAF4C08, fxName); } // 0x7F6F941DACAF4C08 0xCFEA19A9
	static BOOL HAS_NAMED_PTFX_ASSET_LOADED(char* fxName) { return invoke<BOOL>(0x672115C456F49B09, fxName); } // 0x672115C456F49B09 0x9ACC6446
	static void _REMOVE_NAMED_PTFX_ASSET(char* fxName) { invoke<Void>(0xD4B45BC7FA2B955B, fxName); } // 0xD4B45BC7FA2B955B
	static void SET_VEHICLE_POPULATION_BUDGET(int p0) { invoke<Void>(0x79920BB32F3C316F, p0); } // 0x79920BB32F3C316F 0x1D56993C
	static void SET_PED_POPULATION_BUDGET(int p0) { invoke<Void>(0xBE02ABAAC92D1A06, p0); } // 0xBE02ABAAC92D1A06 0xD2D026CD
	static void CLEAR_FOCUS() { invoke<Void>(0x6A4C98FC9F7161C7); } // 0x6A4C98FC9F7161C7 0x34D91E7A
	static void _SET_FOCUS_AREA(float x, float y, float z, float offsetX, float offsetY, float offsetZ) { invoke<Void>(0xD491BFA019B278C0, x, y, z, offsetX, offsetY, offsetZ); } // 0xD491BFA019B278C0 0x14680A60
	static void SET_FOCUS_ENTITY(Entity entity) { invoke<Void>(0x74125219FA2555F2, entity); } // 0x74125219FA2555F2 0x18DB04AC
	static BOOL IS_ENTITY_FOCUS(Entity entity) { return invoke<BOOL>(0x57BFAD8F11DF350B, entity); } // 0x57BFAD8F11DF350B 0xB456D707
	static void _0x50C61BFEF2DFC84A(Entity p0) { invoke<Void>(0x50C61BFEF2DFC84A, p0); } // 0x50C61BFEF2DFC84A
	static void _0x4B5D9E858C90AEAD(char* p0, BOOL p1) { invoke<Void>(0x4B5D9E858C90AEAD, p0, p1); } // 0x4B5D9E858C90AEAD 0x403CD434
	static void _0x4751680B6C100F1D(Any p0) { invoke<Void>(0x4751680B6C100F1D, p0); } // 0x4751680B6C100F1D 0xA07BAEB9
	static Any _SET_UNK_CAMERA_SETTINGS(float x, float y, float z, float rad, Any p4, Any p5) { return invoke<Any>(0xB1399416C9156684, x, y, z, rad, p4, p5); } // 0xB1399416C9156684 0x10B6AB36
	static Any _0x0167B3B91458531B(float p0, float p1, float p2, float p3, float p4, float p5, float p6, Any p7, Any p8) { return invoke<Any>(0x0167B3B91458531B, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x0167B3B91458531B 0x72344191
	static Any _0xF3B67EEA298C22B5(float p0, float p1, float p2, float p3, float p4, float p5, Any p6) { return invoke<Any>(0xF3B67EEA298C22B5, p0, p1, p2, p3, p4, p5, p6); } // 0xF3B67EEA298C22B5 0xC0157255
	static void _0xF032432C4371EF58(Any p0) { invoke<Void>(0xF032432C4371EF58, p0); } // 0xF032432C4371EF58 0xE80F8ABE
	static Any _0x3D01C3117AA19C90(Any p0) { return invoke<Any>(0x3D01C3117AA19C90, p0); } // 0x3D01C3117AA19C90 0x1B3521F4
	static Any _0x5EBBA0877DBAC8A8(Any p0) { return invoke<Any>(0x5EBBA0877DBAC8A8, p0); } // 0x5EBBA0877DBAC8A8 0x42CFE9C0
	static Any _0xC9D446AD5B8B7674() { return invoke<Any>(0xC9D446AD5B8B7674); } // 0xC9D446AD5B8B7674 0x56253356
	static BOOL NEW_LOAD_SCENE_START(float p0, float p1, float p2, float p3, float p4, float p5, float p6, Any p7) { return invoke<BOOL>(0xAEA344F4AC19514E, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xAEA344F4AC19514E 0xDF9C38B6
	static BOOL _NEW_LOAD_SCENE_START_SAFE(float p0, float p1, float p2, float p3, Any p4) { return invoke<BOOL>(0x779AA10AF23608EF, p0, p1, p2, p3, p4); } // 0x779AA10AF23608EF 0xFA037FEB
	static void NEW_LOAD_SCENE_STOP() { invoke<Void>(0x772E33FE6031D858); } // 0x772E33FE6031D858 0x7C05B1F6
	static BOOL IS_NEW_LOAD_SCENE_ACTIVE() { return invoke<BOOL>(0xE41614517B6436B2); } // 0xE41614517B6436B2 0xAD234B7F
	static BOOL IS_NEW_LOAD_SCENE_LOADED() { return invoke<BOOL>(0xDDF188456A3373B2); } // 0xDDF188456A3373B2 0x3ECD839F
	static Any _0x1986299B9EACAC5D() { return invoke<Any>(0x1986299B9EACAC5D); } // 0x1986299B9EACAC5D 0xEAA51103
	static void START_PLAYER_SWITCH(Ped from, Ped to, int flags, int switchType) { invoke<Void>(0x0A28C7864B6FE7F3, from, to, flags, switchType); } // 0x0A28C7864B6FE7F3 0x0829E975
	static void STOP_PLAYER_SWITCH() { invoke<Void>(0x4EB2CA772E9700FE); } // 0x4EB2CA772E9700FE 0x2832C010
	static BOOL IS_PLAYER_SWITCH_IN_PROGRESS() { return invoke<BOOL>(0xE9E6B5364105A000); } // 0xE9E6B5364105A000 0x56135ACC
	static int GET_PLAYER_SWITCH_TYPE() { return invoke<int>(0x3108C06B8E90438D); } // 0x3108C06B8E90438D 0x280DC015
	static int GET_IDEAL_PLAYER_SWITCH_TYPE(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<int>(0x126921E87AB6E49A, x1, y1, z1, x2, y2, z2); } // 0x126921E87AB6E49A 0xD5A450F1
	static int GET_PLAYER_SWITCH_STATE() { return invoke<int>(0x4DA93F059B47A9FA); } // 0x4DA93F059B47A9FA 0x39A0E1F2
	static int GET_PLAYER_SHORT_SWITCH_STATE() { return invoke<int>(0x3D275200F5122119); } // 0x3D275200F5122119 0x9B7BA38F
	static void _0x4D5C305339B10FC5(int p0) { invoke<Void>(0x4D5C305339B10FC5, p0); } // 0x4D5C305339B10FC5 0xF0BD420D
	static Any _0x4D4C15F4F14307DE() { return invoke<Any>(0x4D4C15F4F14307DE); } // 0x4D4C15F4F14307DE 0x02BA7AC2
	static void _SET_PLAYER_SWITCH_LOCATION(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, Any p8) { invoke<Void>(0xEF079F42B14567E3, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xEF079F42B14567E3 0x47352E14
	static void _0x35159F85EA98B830(Any* p0) { invoke<Void>(0x35159F85EA98B830, p0); } // 0x35159F85EA98B830 0x279077B0
	static void _0xE54327F462B47CAE() { invoke<Void>(0xE54327F462B47CAE); } // 0xE54327F462B47CAE 0x55CB21F9
	static void _0x0A2543882A6F41B5() { invoke<Void>(0x0A2543882A6F41B5); } // 0x0A2543882A6F41B5 0x1084F2F4
	static void _0xDBC332E2A83ED659() { invoke<Void>(0xDBC332E2A83ED659); } // 0xDBC332E2A83ED659 0x5B1E995D
	static void _0x23A15D77C8E56A65() { invoke<Void>(0x23A15D77C8E56A65); } // 0x23A15D77C8E56A65 0x4B4B9A13
	static Any _0x89ED8589FCADFD44() { return invoke<Any>(0x89ED8589FCADFD44); } // 0x89ED8589FCADFD44 0x408F7148
	static void _0x6185C80EDE2617B1() { invoke<Void>(0x6185C80EDE2617B1); } // 0x6185C80EDE2617B1
	static void _0xDE8DD123F5E855EA() { invoke<Void>(0xDE8DD123F5E855EA); } // 0xDE8DD123F5E855EA
	static void _SWITCH_OUT_PLAYER(Ped ped, int flags, int unknown) { invoke<Void>(0xB8AC221DDF349457, ped, flags, unknown); } // 0xB8AC221DDF349457 0xFB4D062D
	static void _0x9C33A8F51D7D422B(Any p0) { invoke<Void>(0x9C33A8F51D7D422B, p0); } // 0x9C33A8F51D7D422B 0x2349373B
	static Any _0x36CC5E548D84ED46() { return invoke<Any>(0x36CC5E548D84ED46); } // 0x36CC5E548D84ED46 0x74C16879
	static Any SET_PLAYER_INVERTED_UP() { return invoke<Any>(0x2CB62BBF22F8176D); } // 0x2CB62BBF22F8176D 0x569847E3
	static Any _0xCA4D3E886BFAF29A() { return invoke<Any>(0xCA4D3E886BFAF29A); } // 0xCA4D3E886BFAF29A 0xC7A3D279
	static Any DESTROY_PLAYER_IN_PAUSE_MENU() { return invoke<Any>(0xC2DC7E7E61CC8F8C); } // 0xC2DC7E7E61CC8F8C 0x90F64284
	static void _0xDB31D7480E3AFBB8() { invoke<Void>(0xDB31D7480E3AFBB8); } // 0xDB31D7480E3AFBB8
	static Any _0x53481EC8102C6899() { return invoke<Any>(0x53481EC8102C6899); } // 0x53481EC8102C6899 0x7154B6FD
	static void _0x3DBCC03F50C04042(float p0) { invoke<Void>(0x3DBCC03F50C04042, p0); } // 0x3DBCC03F50C04042 0xE5612C1A
	static void _0x0DBF01E2F3B0EBFA(float p0, float p1, float p2, float p3) { invoke<Void>(0x0DBF01E2F3B0EBFA, p0, p1, p2, p3); } // 0x0DBF01E2F3B0EBFA 0x9CD6A451
	static void _0x3CB49EACD6C8CFE9() { invoke<Void>(0x3CB49EACD6C8CFE9); } // 0x3CB49EACD6C8CFE9 0x4267DA87
	static void _0xA803242E292E3E90(BOOL p0) { invoke<Void>(0xA803242E292E3E90, p0); } // 0xA803242E292E3E90 0x9FA4AF99
	static void _0xFFCC3D46D34A3350() { invoke<Void>(0xFFCC3D46D34A3350); } // 0xFFCC3D46D34A3350
	static void _0xB69D39B2C0B6A895(Any* p0, Any* p1) { invoke<Void>(0xB69D39B2C0B6A895, p0, p1); } // 0xB69D39B2C0B6A895 0x9EF0A9CF
	static void _0xB1F310B28A4632E4() { invoke<Void>(0xB1F310B28A4632E4); } // 0xB1F310B28A4632E4 0xF2CDD6A8
	static Any _0xC11636DFD6C40772() { return invoke<Any>(0xC11636DFD6C40772); } // 0xC11636DFD6C40772 0x17B0A1CD
	static void _0x678A196EEEE31F51() { invoke<Void>(0x678A196EEEE31F51); } // 0x678A196EEEE31F51 0x3DA7AA5D
	static Any _0x4D4A69CC6E0C779A() { return invoke<Any>(0x4D4A69CC6E0C779A); } // 0x4D4A69CC6E0C779A 0xDAB4BAC0
	static void PREFETCH_SRL(Any* p0) { invoke<Void>(0x75E3D7DD8F4B0F6F, p0); } // 0x75E3D7DD8F4B0F6F 0x37BE2FBB
	static BOOL IS_SRL_LOADED() { return invoke<BOOL>(0x234438A9D08C3186); } // 0x234438A9D08C3186 0x670FA2A6
	static void BEGIN_SRL() { invoke<Void>(0xB3BD92D552468D00); } // 0xB3BD92D552468D00 0x24F49427
	static void END_SRL() { invoke<Void>(0x2FBF689422F41891); } // 0x2FBF689422F41891 0x1977C56A
	static void SET_SRL_TIME(float p0) { invoke<Void>(0x24B9DA75BC7B980E, p0); } // 0x24B9DA75BC7B980E 0x30F8A487
	static void _0xAFA4343939D2812C(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<Void>(0xAFA4343939D2812C, p0, p1, p2, p3, p4, p5); } // 0xAFA4343939D2812C 0x814D0752
	static void _0x959C4E548A4647AB(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x959C4E548A4647AB, p0, p1, p2, p3); } // 0x959C4E548A4647AB 0x62F02485
	static void _0x04BBEB6C2FBD6731(BOOL p0) { invoke<Void>(0x04BBEB6C2FBD6731, p0); } // 0x04BBEB6C2FBD6731 0xA6459CAA
	static void _0xDA49D0FE9D0459E6(Any p0) { invoke<Void>(0xDA49D0FE9D0459E6, p0); } // 0xDA49D0FE9D0459E6 0xF8F515E4
	static void SET_HD_AREA(float x, float y, float z, float ground) { invoke<Void>(0xD14BBD6C764E2C12, x, y, z, ground); } // 0xD14BBD6C764E2C12 0x80BAA035
	static void CLEAR_HD_AREA() { invoke<Void>(0xF2C4CBD67E45093A); } // 0xF2C4CBD67E45093A 0x7CAC6FA0
	static void _0xF9C99837CF55F6F4() { invoke<Void>(0xF9C99837CF55F6F4); } // 0xF9C99837CF55F6F4 0xE243B2AF
	static void SHUTDOWN_CREATOR_BUDGET() { invoke<Void>(0x512C5F35C115BA38); } // 0x512C5F35C115BA38 0x897A510F
	static BOOL _0x1D72983C07FFE1C3(Any p0) { return invoke<BOOL>(0x1D72983C07FFE1C3, p0); } // 0x1D72983C07FFE1C3 0xC0E83320
	static void _0x3C176DCDF9BCD6BC(Any p0) { invoke<Void>(0x3C176DCDF9BCD6BC, p0); } // 0x3C176DCDF9BCD6BC 0x1C576388
	static Any _0xE7A13DFEB75839D2() { return invoke<Any>(0xE7A13DFEB75839D2); } // 0xE7A13DFEB75839D2 0x3E9C4CBE
}

namespace SCRIPT
{
	static void REQUEST_SCRIPT(char* scriptName) { invoke<Void>(0xFCDDC89C28E82BB4, scriptName); } // 0xFCDDC89C28E82BB4 0xE26B2666
	static void SET_SCRIPT_AS_NO_LONGER_NEEDED(char* scriptName) { invoke<Void>(0x07481837BFD9C1CD, scriptName); } // 0x07481837BFD9C1CD 0x6FCB7795
	static BOOL HAS_SCRIPT_LOADED(char* scriptName) { return invoke<BOOL>(0x32B1F051FF487881, scriptName); } // 0x32B1F051FF487881 0x5D67F751
	static BOOL DOES_SCRIPT_EXIST(char* scriptName) { return invoke<BOOL>(0xD5B2C67F250954B4, scriptName); } // 0xD5B2C67F250954B4 0xDEAB87AB
	static void _REQUEST_STREAMED_SCRIPT(Hash scriptHash) { invoke<Void>(0x40DAFD1EE608CAF6, scriptHash); } // 0x40DAFD1EE608CAF6 0x1C68D9DC
	static void _SET_STREAMED_SCRIPT_AS_NO_LONGER_NEEDED(Hash scriptHash) { invoke<Void>(0x2B3C688FCF1D85DE, scriptHash); } // 0x2B3C688FCF1D85DE 0x96C26F66
	static BOOL _HAS_STREAMED_SCRIPT_LOADED(Hash scriptHash) { return invoke<BOOL>(0x1773B272030A4F46, scriptHash); } // 0x1773B272030A4F46 0x06674818
	static BOOL _IS_STREAMED_SCRIPT_RUNNING(Hash scriptHash) { return invoke<BOOL>(0x7BEA860C3760CB2C, scriptHash); } // 0x7BEA860C3760CB2C
	static void TERMINATE_THREAD(int threadId) { invoke<Void>(0x73FB5ABDF913E4E5, threadId); } // 0x73FB5ABDF913E4E5 0x253FD520
	static BOOL IS_THREAD_ACTIVE(int threadId) { return invoke<BOOL>(0x1EFA84312BB8AA22, threadId); } // 0x1EFA84312BB8AA22 0x78D7A5A0
	static char* _GET_THREAD_NAME(int threadId) { return invoke<char*>(0x956F0F407B6AD8C4, threadId); } // 0x956F0F407B6AD8C4 0xBE7ACD89
	static void _BEGIN_ENUMERATING_THREADS() { invoke<Void>(0x8D6050B3AC8AB6A6); } // 0x8D6050B3AC8AB6A6 0xBB4E2F66
	static int _GET_ID_OF_NEXT_THREAD_IN_ENUMERATION() { return invoke<int>(0xED15F16EEB2F2714); } // 0xED15F16EEB2F2714 0x1E28B28F
	static int GET_ID_OF_THIS_THREAD() { return invoke<int>(0xE9A5FDFDC239B2ED); } // 0xE9A5FDFDC239B2ED 0xDE524830
	static void TERMINATE_THIS_THREAD() { invoke<Void>(0x921053BAF754303D); } // 0x921053BAF754303D 0x3CD9CBB7
	static int _GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT(Hash scriptHash) { return invoke<int>(0x82F1A060D8F4583B, scriptHash); } // 0x82F1A060D8F4583B 0x029D3841
	static char* GET_THIS_SCRIPT_NAME() { return invoke<char*>(0x6AF6B39BFDB53CB5); } // 0x6AF6B39BFDB53CB5 0xA40FD5D9
	static Hash _GET_THIS_SCRIPT_HASH() { return invoke<Hash>(0xBDF22BDA553CBEE4); } // 0xBDF22BDA553CBEE4 0x2BEE1F45
	static int GET_NUMBER_OF_EVENTS(int p0) { return invoke<int>(0x45FF610AA845AFAA, p0); } // 0x45FF610AA845AFAA 0xA3525D60
	static BOOL GET_EVENT_EXISTS(int p0, int eventIndex) { return invoke<BOOL>(0x08E5392A79D45DEE, p0, eventIndex); } // 0x08E5392A79D45DEE 0xA1B447B5
	static int GET_EVENT_AT_INDEX(int p0, int eventIndex) { return invoke<int>(0x93A2B1A9173BC03D, p0, eventIndex); } // 0x93A2B1A9173BC03D 0xB49C1442
	static BOOL GET_EVENT_DATA(int p0, int eventIndex, int* eventData, int p3) { return invoke<BOOL>(0x91015F07066D5841, p0, eventIndex, eventData, p3); } // 0x91015F07066D5841 0x4280F92F
	static void TRIGGER_SCRIPT_EVENT(int p0, void* argsStruct, int argsStructSize, int bitset) { invoke<Void>(0x504D0D40319365B7, p0, argsStruct, argsStructSize, bitset); } // 0x504D0D40319365B7 0x54763B35
	static void SHUTDOWN_LOADING_SCREEN() { invoke<Void>(0xC2EF7C4685DEE308); } // 0xC2EF7C4685DEE308 0xA2826D17
	static void SET_NO_LOADING_SCREEN(BOOL toggle) { invoke<Void>(0x97225621CA125FF2, toggle); } // 0x97225621CA125FF2 0xC8055034
	static BOOL _GET_NO_LOADING_SCREEN() { return invoke<BOOL>(0xEA585FE60D0854B3); } // 0xEA585FE60D0854B3
	static void _0x0EA2022578560B86() { invoke<Void>(0x0EA2022578560B86); } // 0x0EA2022578560B86 0xB03BCCDF
}

namespace UI
{
	static void _SET_LOADING_PROMPT_TEXT_ENTRY(char* string) { invoke<Void>(0x67D9DFC4D91122DD, string); } // 0x67D9DFC4D91122DD 0xCB7C8994
	static void _SHOW_LOADING_PROMPT(int busySpinnerType) { invoke<Void>(0x168CD266B6A65426, busySpinnerType); } // 0x168CD266B6A65426 0x903F5EE4
	static void _REMOVE_LOADING_PROMPT() { invoke<Void>(0xF9E752009D9D07AB); } // 0xF9E752009D9D07AB 0x94119534
	static void _0xA4FA5C56B569B398() { invoke<Void>(0xA4FA5C56B569B398); } // 0xA4FA5C56B569B398 0x71077FBD
	static BOOL _IS_LOADING_PROMPT_BEING_DISPLAYED() { return invoke<BOOL>(0xDFA02D404FFEF5F2); } // 0xDFA02D404FFEF5F2 0xB8B3A5D0
	static Any _0x2E43177BD2DB81F2() { return invoke<Any>(0x2E43177BD2DB81F2); } // 0x2E43177BD2DB81F2
	static void _0x1F38C5ACD36A81DE(BOOL p0) { invoke<Void>(0x1F38C5ACD36A81DE, p0); } // 0x1F38C5ACD36A81DE
	static void _SHOW_CURSOR_THIS_FRAME() { invoke<Void>(0xB05075754D5DD4A3); } // 0xB05075754D5DD4A3
	static void _SET_CURSOR_SPRITE(int spriteId) { invoke<Void>(0x535A960C1D9AE906, spriteId); } // 0x535A960C1D9AE906
	static void _0x4DF2248FCD93C08E(BOOL p0) { invoke<Void>(0x4DF2248FCD93C08E, p0); } // 0x4DF2248FCD93C08E
	static Any _0x2BC8D6E225C1D41E() { return invoke<Any>(0x2BC8D6E225C1D41E); } // 0x2BC8D6E225C1D41E
	static BOOL _0x358D2242514A812F(int scaleformHandle, Any* p1, Any* p2, Any* p3) { return invoke<BOOL>(0x358D2242514A812F, scaleformHandle, p1, p2, p3); } // 0x358D2242514A812F
	static void _0x821799152227D793(BOOL p0) { invoke<Void>(0x821799152227D793, p0); } // 0x821799152227D793 0xA7C8594B
	static void _0xDE0328664F42BCD5(float p0) { invoke<Void>(0xDE0328664F42BCD5, p0); } // 0xDE0328664F42BCD5 0x1DA7E41A
	static void _0x71231C7FAF12B6DB() { invoke<Void>(0x71231C7FAF12B6DB); } // 0x71231C7FAF12B6DB 0x1E63088A
	static void _0x9FB8515100F82AFB() { invoke<Void>(0x9FB8515100F82AFB); } // 0x9FB8515100F82AFB 0x5205C6F5
	static void _REMOVE_NOTIFICATION(int notifactionId) { invoke<Void>(0x20F0B569F9F3A02A, notifactionId); } // 0x20F0B569F9F3A02A 0xECA8ACB9
	static void _0x3BFBAD6F0B43D4BF() { invoke<Void>(0x3BFBAD6F0B43D4BF); } // 0x3BFBAD6F0B43D4BF 0x520FCB6D
	static void _0x54C1AC9CE0B3E676() { invoke<Void>(0x54C1AC9CE0B3E676); } // 0x54C1AC9CE0B3E676 0xC8BAB2F2
	static void _0xD57128A757C0216E() { invoke<Void>(0xD57128A757C0216E); } // 0xD57128A757C0216E 0x4D0449C6
	static void _0x42DE1068884C3BE9() { invoke<Void>(0x42DE1068884C3BE9); } // 0x42DE1068884C3BE9 0xD3F40140
	static Any _0xA91895320E9E71A0() { return invoke<Any>(0xA91895320E9E71A0); } // 0xA91895320E9E71A0 0xC5223796
	static void _0xAC3FF27D293137C9() { invoke<Void>(0xAC3FF27D293137C9); } // 0xAC3FF27D293137C9 0x709B4BCB
	static void _0xB8781D076F734692() { invoke<Void>(0xB8781D076F734692); } // 0xB8781D076F734692 0x4A4A40A4
	static int _GET_CURRENT_NOTIFICATION() { return invoke<int>(0xFAD0FA8DB11A711B); } // 0xFAD0FA8DB11A711B 0x294405D4
	static void _0xE4B96CE0537633A9() { invoke<Void>(0xE4B96CE0537633A9); } // 0xE4B96CE0537633A9 0xF881AB87
	static void _0xDD686429BD21EA7A() { invoke<Void>(0xDD686429BD21EA7A); } // 0xDD686429BD21EA7A 0x1D6859CA
	static void _0x0A9539978AB07142(int p0) { invoke<Void>(0x0A9539978AB07142, p0); } // 0x0A9539978AB07142
	static void _SET_NOTIFICATION_FLASH_COLOR(int red, int green, int blue, int alpha) { invoke<Void>(0x52B729610C062F21, red, green, blue, alpha); } // 0x52B729610C062F21 0xCF14D7F2
	static void _0x0567CC100BE76FDC(Any p0) { invoke<Void>(0x0567CC100BE76FDC, p0); } // 0x0567CC100BE76FDC 0x24A97AF8
	static void _0x2630F75F65F51F56(BOOL p0) { invoke<Void>(0x2630F75F65F51F56, p0); } // 0x2630F75F65F51F56 0x44018EDB
	static void _0xABCBB1F14F69A10B() { invoke<Void>(0xABCBB1F14F69A10B); } // 0xABCBB1F14F69A10B 0xA4524B23
	static void _0xAB6FD993C30709C2() { invoke<Void>(0xAB6FD993C30709C2); } // 0xAB6FD993C30709C2 0xAFA1148B
	static void _0x6ECD70B4740AA2DA() { invoke<Void>(0x6ECD70B4740AA2DA); } // 0x6ECD70B4740AA2DA 0x3CD4307C
	static void _0xC1BC597FCC9AEE6E(BOOL p0) { invoke<Void>(0xC1BC597FCC9AEE6E, p0); } // 0xC1BC597FCC9AEE6E
	static void _0xA15206CC127327EA(Any* p0, Any* p1, Any* p2, Any* p3) { invoke<Void>(0xA15206CC127327EA, p0, p1, p2, p3); } // 0xA15206CC127327EA
	static void _SET_NOTIFICATION_TEXT_ENTRY(char* type) { invoke<Void>(0xBD18006F0815A298, type); } // 0xBD18006F0815A298 0x574EE85C
	static int _0xBD1025142299A003(char* p0, int p1, int p2, int p3, BOOL p4, char* picName1, char* picName2) { return invoke<int>(0xBD1025142299A003, p0, p1, p2, p3, p4, picName1, picName2); } // 0xBD1025142299A003 0xED130FA1
	static int _SET_NOTIFICATION_MESSAGE(char* picName1, char* picName2, BOOL flash, int iconType, char* sender, char* subject) { return invoke<int>(0x6132B0FB7289E50A, picName1, picName2, flash, iconType, sender, subject); } // 0x6132B0FB7289E50A 0xE7E3C98B
	static int _0xB49022457D56C68E(char* picName1, char* picName2, BOOL p2, Any p3, char* p4, char* p5) { return invoke<int>(0xB49022457D56C68E, picName1, picName2, p2, p3, p4, p5); } // 0xB49022457D56C68E
	static int _0xD726078139C639F7(char* picName1, char* picName2, BOOL flash, int iconType, char* sender, char* subject, float duration) { return invoke<int>(0xD726078139C639F7, picName1, picName2, flash, iconType, sender, subject, duration); } // 0xD726078139C639F7 0x0EB382B7
	static int _SET_NOTIFICATION_MESSAGE_CLAN_TAG(char* picName1, char* picName2, BOOL flash, int iconType, char* sender, char* subject, float duration, char* clanTag) { return invoke<int>(0x78BC2A9EA316AD75, picName1, picName2, flash, iconType, sender, subject, duration, clanTag); } // 0x78BC2A9EA316AD75 0x3E807FE3
	static int _SET_NOTIFICATION_MESSAGE_CLAN_TAG_2(char* picName1, char* picName2, BOOL flash, int iconType1, char* sender, char* subject, float duration, char* clanTag, int iconType2, int p9) { return invoke<int>(0xB172BF1A804780CA, picName1, picName2, flash, iconType1, sender, subject, duration, clanTag, iconType2, p9); } // 0xB172BF1A804780CA 0xDEB491C8
	static int _DRAW_NOTIFICATION(BOOL blink, BOOL p1) { return invoke<int>(0x23048DD0C6E21613, blink, p1); } // 0x23048DD0C6E21613 0x08F7AF78
	static int _DRAW_NOTIFICATION_2(BOOL blink, BOOL p1) { return invoke<int>(0xF8E905E2B50EE5EA, blink, p1); } // 0xF8E905E2B50EE5EA 0x57B8D0D4
	static int _DRAW_NOTIFICATION_3(BOOL blink, BOOL p1) { return invoke<int>(0x2A098F49B22352FE, blink, p1); } // 0x2A098F49B22352FE 0x02BCAF9B
	static int _0x7F3419173A01A83F(char* p0, char* p1, int p2, int p3, char* p4) { return invoke<int>(0x7F3419173A01A83F, p0, p1, p2, p3, p4); } // 0x7F3419173A01A83F 0x02DED2B8
	static Any _0xDFBD23CE6CF19FDE(BOOL p0, BOOL p1, Any* p2, Any p3, BOOL p4, BOOL p5, Any p6, Any p7, Any p8, Any p9) { return invoke<Any>(0xDFBD23CE6CF19FDE, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0xDFBD23CE6CF19FDE 0xA9CCEF66
	static int _0x484290510553BCE9(BOOL p0, BOOL p1, Any* p2, Any p3, BOOL p4, BOOL unk0, Any p6, char* playerName, Any p8, Any p9, Any p10) { return invoke<int>(0x484290510553BCE9, p0, p1, p2, p3, p4, unk0, p6, playerName, p8, p9, p10); } // 0x484290510553BCE9 0x88B9B909
	static Any _0x7FA6FF304FEA9B5F(Any p0, Any p1, Any p2) { return invoke<Any>(0x7FA6FF304FEA9B5F, p0, p1, p2); } // 0x7FA6FF304FEA9B5F 0xE05E7052
	static Any _0x7F01C7295BF0CFFC(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0x7F01C7295BF0CFFC, p0, p1, p2, p3); } // 0x7F01C7295BF0CFFC 0x4FA43BA4
	static Any _0xBEFC7038C9219C95(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<Any>(0xBEFC7038C9219C95, p0, p1, p2, p3, p4, p5); } // 0xBEFC7038C9219C95 0x8C90D22F
	static int _DRAW_NOTIFICATION_4(BOOL blink, BOOL p1) { return invoke<int>(0x7D1E53C461C90A7B, blink, p1); } // 0x7D1E53C461C90A7B 0x8E319AB8
	static Any _0x91870C8B86C2D9D3(Any* p0, Any* p1, Any* p2, BOOL p3, BOOL p4) { return invoke<Any>(0x91870C8B86C2D9D3, p0, p1, p2, p3, p4); } // 0x91870C8B86C2D9D3
	static Any _0x24FFDA16E902799D(Any* p0, Any* p1, Any p2, Any* p3, Any* p4, Any p5) { return invoke<Any>(0x24FFDA16E902799D, p0, p1, p2, p3, p4, p5); } // 0x24FFDA16E902799D 0x5E93FBFA
	static Any _0x590EF3EE238D4A0F(int type, int image, char* text) { return invoke<Any>(0x590EF3EE238D4A0F, type, image, text); } // 0x590EF3EE238D4A0F
	static Any _0x9DAD4130D4BE6CD2(int type, char* button, char* text) { return invoke<Any>(0x9DAD4130D4BE6CD2, type, button, text); } // 0x9DAD4130D4BE6CD2
	static void BEGIN_TEXT_COMMAND_PRINT(char* GxtEntry) { invoke<Void>(0x7F755B97D75D9B44, GxtEntry); } // 0x7F755B97D75D9B44 0xF42C43C7
	static void END_TEXT_COMMAND_PRINT(int duration, BOOL drawImmediately) { invoke<Void>(0x6EBC181C75DC822D, duration, drawImmediately); } // 0x6EBC181C75DC822D 0x38F82261
	static void _0x5A99EA84320AB387(Any* p0) { invoke<Void>(0x5A99EA84320AB387, p0); } // 0x5A99EA84320AB387 0xDD524A11
	static BOOL _0x2B886121A03F928A() { return invoke<BOOL>(0x2B886121A03F928A); } // 0x2B886121A03F928A 0x672EFB45
	static void BEGIN_TEXT_COMMAND_DISPLAY_TEXT(char* text) { invoke<Void>(0x169EAB5A8FBE845B, text); } // 0x169EAB5A8FBE845B 0x3E35563E
	static void END_TEXT_COMMAND_DISPLAY_TEXT(float x, float y) { invoke<Void>(0x30122BDF124C9221, x, y); } // 0x30122BDF124C9221 0x6F8350CE
	static void _SET_TEXT_ENTRY_FOR_WIDTH(char* text) { invoke<Void>(0x2FCB88845EB45E2E, text); } // 0x2FCB88845EB45E2E 0x51E7A037
	static float _GET_TEXT_SCREEN_WIDTH(BOOL p0) { return invoke<float>(0x79BC75FF4F056899, p0); } // 0x79BC75FF4F056899 0xD12A643A
	static void _SET_TEXT_GXT_ENTRY(char* entry) { invoke<Void>(0x379D645C3A509EB1, entry); } // 0x379D645C3A509EB1 0x94B82066
	static int _0xC275B500E5D05D0B(float p0, float p1) { return invoke<int>(0xC275B500E5D05D0B, p0, p1); } // 0xC275B500E5D05D0B 0xAA318785
	static void _SET_TEXT_COMPONENT_FORMAT(char* inputType) { invoke<Void>(0x252D021C9D92DBA9, inputType); } // 0x252D021C9D92DBA9 0xB245FC10
	static void _DISPLAY_HELP_TEXT_FROM_STRING_LABEL(Any p0, BOOL loop, BOOL beep, int shape) { invoke<Void>(0x8B1500AADBA665BD, p0, loop, beep, shape); } // 0x8B1500AADBA665BD 0xB59B530D
	static void _0x1B345BEADF0C82A0(char* p0) { invoke<Void>(0x1B345BEADF0C82A0, p0); } // 0x1B345BEADF0C82A0 0x00E20F2D
	static BOOL _0xCF2B4FB18449D099(int p0) { return invoke<BOOL>(0xCF2B4FB18449D099, p0); } // 0xCF2B4FB18449D099 0xF63A13EC
	static void BEGIN_TEXT_COMMAND_SET_BLIP_NAME(char* gxtentry) { invoke<Void>(0x457AECF7F7E33610, gxtentry); } // 0x457AECF7F7E33610 0xF4C211F6
	static void END_TEXT_COMMAND_SET_BLIP_NAME(Blip blip) { invoke<Void>(0xB58BBC88882D90A6, blip); } // 0xB58BBC88882D90A6 0xE8E59820
	static void _0x49E41A3C542367ED(char* p0) { invoke<Void>(0x49E41A3C542367ED, p0); } // 0x49E41A3C542367ED 0x0E103475
	static void _0x4F8EFE2B29992B8F(BOOL p0) { invoke<Void>(0x4F8EFE2B29992B8F, p0); } // 0x4F8EFE2B29992B8F 0x2944A6C5
	static void _0x97C3FF45B25050A7(char* p0) { invoke<Void>(0x97C3FF45B25050A7, p0); } // 0x97C3FF45B25050A7 0x550665AE
	static void _0x8DC57A8DB7696F93() { invoke<Void>(0x8DC57A8DB7696F93); } // 0x8DC57A8DB7696F93 0x67785AF2
	static void _0xB50A432C9B1E76AF(char* p0) { invoke<Void>(0xB50A432C9B1E76AF, p0); } // 0xB50A432C9B1E76AF 0xBF855650
	static void _0x75D327B213A1BF0D(BOOL p0) { invoke<Void>(0x75D327B213A1BF0D, p0); } // 0x75D327B213A1BF0D 0x6E7FDA1C
	static void ADD_TEXT_COMPONENT_INTEGER(int value) { invoke<Void>(0x69967F83C1E636E2, value); } // 0x69967F83C1E636E2 0xFE272A57
	static void ADD_TEXT_COMPONENT_FLOAT(float value, int decimalPlaces) { invoke<Void>(0x561D1C39012D002B, value, decimalPlaces); } // 0x561D1C39012D002B 0x24D78013
	static void _ADD_TEXT_COMPONENT_ITEM_STRING(char* labelName) { invoke<Void>(0x34D84D73B5DF8E80, labelName); } // 0x34D84D73B5DF8E80 0xDCE05406
	static void _ADD_TEXT_COMPONENT_SUBSTRING_LOCALIZED(Hash gxtEntryHash) { invoke<Void>(0x99F531CBB5AE0A27, gxtEntryHash); } // 0x99F531CBB5AE0A27 0x150E03B6
	static void ADD_TEXT_COMPONENT_SUBSTRING_BLIP_NAME(Blip blip) { invoke<Void>(0x082D53819C9AD611, blip); } // 0x082D53819C9AD611 0x5DE98F0A
	static void ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(char* text) { invoke<Void>(0xBAB00B98D1E61BEE, text); } // 0xBAB00B98D1E61BEE 0x27A244D8
	static void ADD_TEXT_COMPONENT_SUBSTRING_TIME(int timestamp, int flags) { invoke<Void>(0x96F1415E7C5E58EB, timestamp, flags); } // 0x96F1415E7C5E58EB 0x135B3CD0
	static void _ADD_TEXT_COMPONENT_SUBSTRING_CASH(int cashAmount, BOOL p1) { invoke<Void>(0x1C4A0E5E77C7F187, cashAmount, p1); } // 0x1C4A0E5E77C7F187 0x12929BDF
	static void _0xBB17A6086E49F98F(char* p0, int p1) { invoke<Void>(0xBB17A6086E49F98F, p0, p1); } // 0xBB17A6086E49F98F 0x65E1D404
	static void ADD_TEXT_COMPONENT_SUBSTRING_WEBSITE(char* website) { invoke<Void>(0xC8AF79457256741A, website); } // 0xC8AF79457256741A 0xC736999E
	static void _ADD_TEXT_COMPONENT_SCALEFORM(char* p0) { invoke<Void>(0xE124F0A8E5E81191, p0); } // 0xE124F0A8E5E81191 0x0829A799
	static void _0x80A171A436807CA0(int p0) { invoke<Void>(0x80A171A436807CA0, p0); } // 0x80A171A436807CA0 0x6F1A1901
	static char* _GET_TEXT_SUBSTRING(char* text, int position, int length) { return invoke<char*>(0xCF2B6C8AD32541B9, text, position, length); } // 0xCF2B6C8AD32541B9 0x34A396EE
	static char* _GET_TEXT_SUBSTRING_SAFE(char* text, int position, int length, int maxLength) { return invoke<char*>(0xA3E25E419FAD44C1, text, position, length, maxLength); } // 0xA3E25E419FAD44C1 0x0183A66C
	static char* _GET_TEXT_SUBSTRING_SLICE(char* text, int startPosition, int endPosition) { return invoke<char*>(0x7EA75A85B76F0078, text, startPosition, endPosition); } // 0x7EA75A85B76F0078 0xFA6373BB
	static char* _GET_LABEL_TEXT(char* labelName) { return invoke<char*>(0xC7E52B74A3B4973C, labelName); } // 0xC7E52B74A3B4973C 0x95C4B5AD
	static void CLEAR_PRINTS() { invoke<Void>(0xD12BCC85C2F8B1DE); } // 0xD12BCC85C2F8B1DE 0x216CB1C5
	static void CLEAR_BRIEF() { invoke<Void>(0x242CD261E3CD2983); } // 0x242CD261E3CD2983 0x9F75A929
	static void CLEAR_ALL_HELP_MESSAGES() { invoke<Void>(0x05528626031014B3); } // 0x05528626031014B3 0x9E5D9198
	static void CLEAR_THIS_PRINT(char* p0) { invoke<Void>(0x69E47427C5084888, p0); } // 0x69E47427C5084888 0x06878327
	static void CLEAR_SMALL_PRINTS() { invoke<Void>(0xED9940795E054052); } // 0xED9940795E054052 0xA869A238
	static BOOL DOES_TEXT_BLOCK_EXIST(char* gxt) { return invoke<BOOL>(0x45028EC213071A32, gxt); } // 0x45028EC213071A32 0x96F74838
	static void REQUEST_ADDITIONAL_TEXT(char* gxt, int slot) { invoke<Void>(0xA73AE78D2491E6E1, gxt, slot); } // 0xA73AE78D2491E6E1 0x9FA9175B
	static void _REQUEST_ADDITIONAL_TEXT_2(char* gxt, int slot) { invoke<Void>(0xCCF06EFB1D1BBFE7, gxt, slot); } // 0xCCF06EFB1D1BBFE7 0xF4D27EBE
	static BOOL HAS_ADDITIONAL_TEXT_LOADED(int slot) { return invoke<BOOL>(0x657558590DD37F85, slot); } // 0x657558590DD37F85 0xB0E56045
	static void CLEAR_ADDITIONAL_TEXT(int p0, BOOL p1) { invoke<Void>(0x6DB5F7460B043A80, p0, p1); } // 0x6DB5F7460B043A80 0x518141E0
	static BOOL IS_STREAMING_ADDITIONAL_TEXT(int p0) { return invoke<BOOL>(0xEAE47C11066BB6A3, p0); } // 0xEAE47C11066BB6A3 0xF079E4EB
	static BOOL HAS_THIS_ADDITIONAL_TEXT_LOADED(char* gxt, int slot) { return invoke<BOOL>(0x207D0680D016A0D2, gxt, slot); } // 0x207D0680D016A0D2 0x80A52040
	static BOOL IS_MESSAGE_BEING_DISPLAYED() { return invoke<BOOL>(0x75342B3CD0FB5275); } // 0x75342B3CD0FB5275 0x6A77FE8D
	static BOOL DOES_TEXT_LABEL_EXIST(char* gxt) { return invoke<BOOL>(0x63A528817609801B, gxt); } // 0x63A528817609801B 0x6ECAE560
	static int GET_LENGTH_OF_STRING_WITH_THIS_TEXT_LABEL(char* gxt) { return invoke<int>(0x711E4C72DC613B80, gxt); } // 0x711E4C72DC613B80 0xA4CA7BE5
	static int GET_LENGTH_OF_LITERAL_STRING(char* string) { return invoke<int>(0xF9108830F4935563, string); } // 0xF9108830F4935563 0x99379D55
	static int _0x761258E562C07369(char* p0) { return invoke<int>(0x761258E562C07369, p0); } // 0x761258E562C07369 0x7DBC0764
	static char* GET_STREET_NAME_FROM_HASH_KEY(Hash hash) { return invoke<char*>(0x17036D965F77705B, hash); } // 0x17036D965F77705B 0x1E8E310C
	static BOOL IS_HUD_PREFERENCE_SWITCHED_ON() { return invoke<BOOL>(0x8AD2A25BB768D737); } // 0x8AD2A25BB768D737 0xC3BC1B4F
	static BOOL IS_RADAR_PREFERENCE_SWITCHED_ON() { return invoke<BOOL>(0x3936A297F675E883); } // 0x3936A297F675E883 0x14AEAA28
	static BOOL IS_SUBTITLE_PREFERENCE_SWITCHED_ON() { return invoke<BOOL>(0xDA5E060432EE0B26); } // 0xDA5E060432EE0B26 0x63BA19F5
	static void DISPLAY_HUD(BOOL toggle) { invoke<Void>(0xE418A8E16B02C0AC, toggle); } // 0xE418A8E16B02C0AC 0xD10E4E31
	static void _0x4B8B84CB64FE28D4() { invoke<Void>(0x4B8B84CB64FE28D4); } // 0x4B8B84CB64FE28D4 0xC380AC85
	static void _0x6B469858A576FB3E() { invoke<Void>(0x6B469858A576FB3E); } // 0x6B469858A576FB3E 0xC47AB1B0
	static void DISPLAY_RADAR(BOOL Toggle) { invoke<Void>(0x2D28D5B324F77D2D, Toggle); } // 0x2D28D5B324F77D2D 0x52816BD4
	static BOOL IS_HUD_HIDDEN() { return invoke<BOOL>(0x6F2032A889AACC62); } // 0x6F2032A889AACC62 0x40BADA1D
	static BOOL IS_RADAR_HIDDEN() { return invoke<BOOL>(0xF4CF563B04C79242); } // 0xF4CF563B04C79242 0x1AB3B954
	static BOOL _IS_RADAR_ENABLED() { return invoke<BOOL>(0xF2760B98826D7768); } // 0xF2760B98826D7768
	static void SET_BLIP_ROUTE(Blip blip, BOOL enabled) { invoke<Void>(0x5ACBCE67F0494242, blip, enabled); } // 0x5ACBCE67F0494242 0x3E160C90
	static void SET_BLIP_ROUTE_COLOUR(Blip blip, int colour) { invoke<Void>(0x4E6CD8C764667FA1, blip, colour); } // 0x4E6CD8C764667FA1 0xDDE7C65C
	static void ADD_NEXT_MESSAGE_TO_PREVIOUS_BRIEFS(BOOL p0) { invoke<Void>(0x99DE51C8DB919DA7, p0); } // 0x99DE51C8DB919DA7 0xB58B25BD
	static void _0x38345EA8DDD86270(BOOL p0) { invoke<Void>(0x38345EA8DDD86270, p0); } // 0x38345EA8DDD86270 0x9854485F
	static void RESPONDING_AS_TEMP(float p0) { invoke<Void>(0x174DB37D201025E8, p0); } // 0x174DB37D201025E8 0xDCA3F423
	static void SET_RADAR_ZOOM(int zoomLevel) { invoke<Void>(0xDC7F84CA79FCF958, zoomLevel); } // 0xDC7F84CA79FCF958 0x2A50D1A6
	static void _0x3DAB8C4BF21332AC(Any p0, float p1) { invoke<Void>(0x3DAB8C4BF21332AC, p0, p1); } // 0x3DAB8C4BF21332AC 0x25EC28C0
	static void _SET_RADAR_ZOOM_LEVEL_THIS_FRAME(float zoomLevel) { invoke<Void>(0x4FFF7FB873C08D6E, zoomLevel); } // 0x4FFF7FB873C08D6E 0x09CF1CE5
	static void _0x3EFF7FC682B839E8() { invoke<Void>(0x3EFF7FC682B839E8); } // 0x3EFF7FC682B839E8 0xE8D3A910
	static void GET_HUD_COLOUR(int hudIndex, int* r, int* g, int* b, int* a) { invoke<Void>(0xE3B46F8779F1AB2E, hudIndex, r, g, b, a); } // 0xE3B46F8779F1AB2E 0x63F66A0B
	static void _0xF234DACE287F3677(int r, int g, int b, int a) { invoke<Void>(0xF234DACE287F3677, r, g, b, a); } // 0xF234DACE287F3677 0x0E41E45C
	static void _0xD5D4C4FF1623EAEB(int r, int g, int b, int a) { invoke<Void>(0xD5D4C4FF1623EAEB, r, g, b, a); } // 0xD5D4C4FF1623EAEB 0x6BE3ACA8
	static void _0x03B4FED16DAC5FFE(Any p0, Any p1) { invoke<Void>(0x03B4FED16DAC5FFE, p0, p1); } // 0x03B4FED16DAC5FFE 0x3B216749
	static void _SET_HUD_COLOUR(int hudIndex, int r, int g, int b, int a) { invoke<Void>(0x9ABE1363D791F2FF, hudIndex, r, g, b, a); } // 0x9ABE1363D791F2FF 0xF6E7E92B
	static void FLASH_ABILITY_BAR(Any p0) { invoke<Void>(0xF670D23D2B1C6D09, p0); } // 0xF670D23D2B1C6D09 0x3648960D
	static void SET_ABILITY_BAR_VALUE(float p0, float p1) { invoke<Void>(0x7F2AA19BEFBB66B4, p0, p1); } // 0x7F2AA19BEFBB66B4 0x24E53FD8
	static void FLASH_WANTED_DISPLAY(BOOL p0) { invoke<Void>(0xF839B1EBAD1A5B3D, p0); } // 0xF839B1EBAD1A5B3D 0x629F866B
	static void _0x807FBD3A3E590108(BOOL p0) { invoke<Void>(0x807FBD3A3E590108, p0); } // 0x807FBD3A3E590108
	static float _GET_TEXT_SCALE_HEIGHT(float size, int font) { return invoke<float>(0x9953FC2B90DA80E3, size, font); } // 0x9953FC2B90DA80E3 0x3330175B
	static void SET_TEXT_SCALE(float p0, float size) { invoke<Void>(0xF52EFF0C6EF215CB, p0, size); } // 0xF52EFF0C6EF215CB 0xB6E15B23
	static void SET_TEXT_COLOUR(int red, int green, int blue, int alpha) { invoke<Void>(0x95F5FAE83A0364F7, red, green, blue, alpha); } // 0x95F5FAE83A0364F7 0xE54DD2C8
	static void SET_TEXT_CENTRE(BOOL align) { invoke<Void>(0xD9DDC2582B7C61C4, align); } // 0xD9DDC2582B7C61C4 0xE26D39A1
	static void SET_TEXT_RIGHT_JUSTIFY(BOOL toggle) { invoke<Void>(0xA38F805C695E23B9, toggle); } // 0xA38F805C695E23B9 0x45B60520
	static void SET_TEXT_JUSTIFICATION(int justifyType) { invoke<Void>(0xE32F769454EED7A6, justifyType); } // 0xE32F769454EED7A6 0x68CDFA60
	static void SET_TEXT_WRAP(float start, float end) { invoke<Void>(0x71D93F31C9937FC7, start, end); } // 0x71D93F31C9937FC7 0x6F60AB54
	static void SET_TEXT_LEADING(BOOL p0) { invoke<Void>(0x33BEE0D70A46B365, p0); } // 0x33BEE0D70A46B365 0x98CE21D4
	static void SET_TEXT_PROPORTIONAL(BOOL p0) { invoke<Void>(0xA37B016FED0FD14C, p0); } // 0xA37B016FED0FD14C 0xF49D8A08
	static void SET_TEXT_FONT(int fontType) { invoke<Void>(0x6C65E322B18B5D28, fontType); } // 0x6C65E322B18B5D28 0x80BC530D
	static void SET_TEXT_DROP_SHADOW() { invoke<Void>(0xB83A3BA4CB555E81); } // 0xB83A3BA4CB555E81 0xE2A11511
	static void SET_TEXT_DROPSHADOW(int distance, int r, int g, int b, int a) { invoke<Void>(0x403F622BEAB190B9, distance, r, g, b, a); } // 0x403F622BEAB190B9 0xE6587517
	static void SET_TEXT_OUTLINE() { invoke<Void>(0x32DAC6D3F4E23D5D); } // 0x32DAC6D3F4E23D5D 0xC753412F
	static void SET_TEXT_EDGE(int p0, int r, int g, int b, int a) { invoke<Void>(0x815C87228CF5C384, p0, r, g, b, a); } // 0x815C87228CF5C384 0x3F1A5DAB
	static void SET_TEXT_RENDER_ID(int renderId) { invoke<Void>(0x9ECF2B67B569A85E, renderId); } // 0x9ECF2B67B569A85E 0xC5C3B7F3
	static int GET_DEFAULT_SCRIPT_RENDERTARGET_RENDER_ID() { return invoke<int>(0x92016DECDDF1828F); } // 0x92016DECDDF1828F 0x8188935F
	static BOOL REGISTER_NAMED_RENDERTARGET(char* p0, BOOL p1) { return invoke<BOOL>(0x470BA9EBFB50ADE1, p0, p1); } // 0x470BA9EBFB50ADE1 0xFAE5D6F0
	static BOOL IS_NAMED_RENDERTARGET_REGISTERED(char* p0) { return invoke<BOOL>(0x2BB2E4C757637EC2, p0); } // 0x2BB2E4C757637EC2 0x284057F5
	static BOOL RELEASE_NAMED_RENDERTARGET(Any* p0) { return invoke<BOOL>(0xE4FE3F56A96CDA73, p0); } // 0xE4FE3F56A96CDA73 0xD3F6C892
	static void LINK_NAMED_RENDERTARGET(Hash hash) { invoke<Void>(0x3D131D0E294702A9, hash); } // 0x3D131D0E294702A9 0x6844C4B9
	static Any GET_NAMED_RENDERTARGET_RENDER_ID(char* p0) { return invoke<Any>(0x6437E76B9AC80AE0, p0); } // 0x6437E76B9AC80AE0 0xF9D7A401
	static BOOL IS_NAMED_RENDERTARGET_LINKED(Hash hash) { return invoke<BOOL>(0x91787D55F1D285D2, hash); } // 0x91787D55F1D285D2 0x8B52601F
	static void CLEAR_HELP(BOOL toggle) { invoke<Void>(0x2E2945F5602A744F, toggle); } // 0x2E2945F5602A744F 0xE6D85741
	static BOOL IS_HELP_MESSAGE_ON_SCREEN() { return invoke<BOOL>(0x7AED88F5CDBFFB3C); } // 0x7AED88F5CDBFFB3C 0x4B3C9CA9
	static BOOL _0x01FDA8DB4057E13F() { return invoke<BOOL>(0x01FDA8DB4057E13F); } // 0x01FDA8DB4057E13F 0x812CBE0E
	static BOOL IS_HELP_MESSAGE_BEING_DISPLAYED() { return invoke<BOOL>(0x9E123D5FF2973C60); } // 0x9E123D5FF2973C60 0xA65F262A
	static BOOL IS_HELP_MESSAGE_FADING_OUT() { return invoke<BOOL>(0x70F6041CE3E701CC); } // 0x70F6041CE3E701CC 0x3E50AE92
	static BOOL _0xD401739A5899EC1B() { return invoke<BOOL>(0xD401739A5899EC1B); } // 0xD401739A5899EC1B 0x87871CE0
	static int _GET_BLIP_INFO_ID_ITERATOR() { return invoke<int>(0xF90D5D0199B23D8A); } // 0xF90D5D0199B23D8A 0xB9827942
	static int GET_NUMBER_OF_ACTIVE_BLIPS() { return invoke<int>(0xB28DB36F2CA9AF91); } // 0xB28DB36F2CA9AF91 0x144020FA
	static Blip GET_NEXT_BLIP_INFO_ID(Blip blip) { return invoke<Blip>(0x2A20AAF6690C1F77, blip); } // 0x2A20AAF6690C1F77 0x9356E92F
	static Blip GET_FIRST_BLIP_INFO_ID(Blip blip) { return invoke<Blip>(0xE4E7011C9D0FC63E, blip); } // 0xE4E7011C9D0FC63E 0x64C0273D
	static Vector3 GET_BLIP_INFO_ID_COORD(int p0) { return invoke<Vector3>(0x7C29905E601946B9, p0); } // 0x7C29905E601946B9 0xB7374A66
	static int GET_BLIP_INFO_ID_DISPLAY(Blip blip) { return invoke<int>(0x1EEC4C322830AE1C, blip); } // 0x1EEC4C322830AE1C 0xD0FC19F4
	static int GET_BLIP_INFO_ID_TYPE(Blip blip) { return invoke<int>(0x56392656F224AE31, blip); } // 0x56392656F224AE31 0x501D7B4E
	static Entity GET_BLIP_INFO_ID_ENTITY_INDEX(Blip blip) { return invoke<Entity>(0x7A6311F77BF290C0, blip); } // 0x7A6311F77BF290C0 0xA068C40B
	static Pickup GET_BLIP_INFO_ID_PICKUP_INDEX(Blip blip) { return invoke<Pickup>(0x97F22913BC44A6B9, blip); } // 0x97F22913BC44A6B9 0x86913D37
	static Blip GET_BLIP_FROM_ENTITY(Entity entity) { return invoke<Blip>(0x224255821C6BA1EC, entity); } // 0x224255821C6BA1EC 0x005A2A47
	static Blip ADD_BLIP_FOR_RADIUS(float posX, float posY, float posZ, float radius) { return invoke<Blip>(0x2528C64BC2C01C92, posX, posY, posZ, radius); } // 0x2528C64BC2C01C92 0x4626756C
	static Blip ADD_BLIP_FOR_ENTITY(Entity entity) { return invoke<Blip>(0xF1FE04D602EA392E, entity); } // 0xF1FE04D602EA392E 0x30822554
	static Blip ADD_BLIP_FOR_PICKUP(Pickup pickup) { return invoke<Blip>(0x0F4B728BCFF10878, pickup); } // 0x0F4B728BCFF10878 0x16693C3A
	static Blip ADD_BLIP_FOR_COORD(float x, float y, float z) { return invoke<Blip>(0x9213703D695C6A7A, x, y, z); } // 0x9213703D695C6A7A 0xC6F43D0E
	static void _0xD478D84B7C1E30B8(float posX, float posY, float posZ, float radius, int p4) { invoke<Void>(0xD478D84B7C1E30B8, posX, posY, posZ, radius, p4); } // 0xD478D84B7C1E30B8 0xBF25E7B2
	static void _0xBC72DA8B8C01F974(BOOL p0) { invoke<Void>(0xBC72DA8B8C01F974, p0); } // 0xBC72DA8B8C01F974 0xE7E1E32B
	static void SET_BLIP_COORDS(Blip blip, float posX, float posY, float posZ) { invoke<Void>(0xC106C8D8B1488032, blip, posX, posY, posZ); } // 0xC106C8D8B1488032 0x680A34D4
	static Vector3 GET_BLIP_COORDS(Blip blip) { return invoke<Vector3>(0xCC1DFCD030782230, blip); } // 0xCC1DFCD030782230 0xEF6FF47B
	static void SET_BLIP_SPRITE(Blip blip, int spriteId) { invoke<Void>(0xA0BCCD5C2B5FC84F, blip, spriteId); } // 0xA0BCCD5C2B5FC84F 0x8DBBB0B9
	static int GET_BLIP_SPRITE(Blip blip) { return invoke<int>(0x0B3DA9F34C184B8E, blip); } // 0x0B3DA9F34C184B8E 0x72FF2E73
	static void SET_BLIP_NAME_FROM_TEXT_FILE(Blip blip, char* gxtEntry) { invoke<Void>(0xAAF15482D9DB27D9, blip, gxtEntry); } // 0xAAF15482D9DB27D9 0xAC8A5461
	static void SET_BLIP_NAME_TO_PLAYER_NAME(Blip blip, Player player) { invoke<Void>(0x81151B3C7E49B4EB, blip, player); } // 0x81151B3C7E49B4EB 0x03A0B8F9
	static void SET_BLIP_ALPHA(Blip blip, int alpha) { invoke<Void>(0x5F97CFBDE7F2B599, blip, alpha); } // 0x5F97CFBDE7F2B599 0xA791FCCD
	static int GET_BLIP_ALPHA(Blip blip) { return invoke<int>(0xC6F9754C5842E80A, blip); } // 0xC6F9754C5842E80A 0x297AF6C8
	static void SET_BLIP_FADE(Blip blip, int opacity, int duration) { invoke<Void>(0xB8312D0C1BCE021A, blip, opacity, duration); } // 0xB8312D0C1BCE021A 0xA5999031
	static void SET_BLIP_ROTATION(Blip blip, int rotation) { invoke<Void>(0x3BB2C768BA8FD249, blip, rotation); } // 0x3BB2C768BA8FD249 0x6B8F44FE
	static void SET_BLIP_FLASH_TIMER(Blip blip, int duration) { invoke<Void>(0x9DD4955F28C1A885, blip, duration); } // 0x9DD4955F28C1A885 0x8D5DF611
	static void SET_BLIP_FLASH_INTERVAL(Blip blip, Any p1) { invoke<Void>(0x1A08FA3744341551, blip, p1); } // 0x1A08FA3744341551 0xEAF67377
	static void SET_BLIP_COLOUR(Blip blip, int color) { invoke<Void>(0xCC930AE12D020496, blip, color); } // 0xCC930AE12D020496 0xBB3C5A41
	static void SET_BLIP_SECONDARY_COLOUR(Blip blip, float r, float g, float b) { invoke<Void>(0x0FCCC389A61ADA7D, blip, r, g, b); } // 0x0FCCC389A61ADA7D 0xC6384D32
	static int GET_BLIP_COLOUR(Blip blip) { return invoke<int>(0xB1E66230B78B5E30, blip); } // 0xB1E66230B78B5E30 0xDD6A1E54
	static int GET_BLIP_HUD_COLOUR(Blip blip) { return invoke<int>(0xD086FBCA505D62AC, blip); } // 0xD086FBCA505D62AC 0xE88B4BC2
	static BOOL IS_BLIP_SHORT_RANGE(Blip blip) { return invoke<BOOL>(0x9B4B1B29E893D00C, blip); } // 0x9B4B1B29E893D00C 0x1226765A
	static BOOL IS_BLIP_ON_MINIMAP(Blip blip) { return invoke<BOOL>(0x4F324812C7F259DE, blip); } // 0x4F324812C7F259DE 0x258CBA3A
	static BOOL _0x741D37F2247F0FA4(Any p0) { return invoke<BOOL>(0x741D37F2247F0FA4, p0); } // 0x741D37F2247F0FA4 0x3E47F357
	static void _0x5202472B608D60CC(Any p0, BOOL p1) { invoke<Void>(0x5202472B608D60CC, p0, p1); } // 0x5202472B608D60CC 0x43996428
	static void SET_BLIP_HIGH_DETAIL(Blip blip, BOOL toggle) { invoke<Void>(0xA3E237652AF6DEB1, blip, toggle); } // 0xA3E237652AF6DEB1 0xD5842BFF
	static void SET_BLIP_AS_MISSION_CREATOR_BLIP(Blip blip, BOOL toggle) { invoke<Void>(0x823C33C6CC49D8E0, blip, toggle); } // 0x823C33C6CC49D8E0 0x802FB686
	static BOOL IS_MISSION_CREATOR_BLIP(Blip blip) { return invoke<BOOL>(0xFFB3092D0A734446, blip); } // 0xFFB3092D0A734446 0x24ACC4E9
	static Blip DISABLE_BLIP_NAME_FOR_VAR() { return invoke<Blip>(0x996E1EDF41FC6719); } // 0x996E1EDF41FC6719 0xFFD7476C
	static BOOL _0xD0940AEB2C796DBC() { return invoke<BOOL>(0xD0940AEB2C796DBC); } // 0xD0940AEB2C796DBC 0xC5EB849A
	static void _0xDA02927D95C46D4A(BOOL p0) { invoke<Void>(0xDA02927D95C46D4A, p0); } // 0xDA02927D95C46D4A 0xA2CAAB4F
	static void SET_BLIP_FLASHES(Blip blip, BOOL toggle) { invoke<Void>(0x76C0584E1FF9B958, blip, toggle); } // 0x76C0584E1FF9B958 0xC0047F15
	static void SET_BLIP_FLASHES_ALTERNATE(Blip blip, BOOL toggle) { invoke<Void>(0xE5902B26C3C446C2, blip, toggle); } // 0xE5902B26C3C446C2 0x1A81202B
	static BOOL IS_BLIP_FLASHING(Blip blip) { return invoke<BOOL>(0x2B4022428FED3F3B, blip); } // 0x2B4022428FED3F3B 0x52E111D7
	static void SET_BLIP_AS_SHORT_RANGE(Blip blip, BOOL toggle) { invoke<Void>(0x7E2A76828C48BFB2, blip, toggle); } // 0x7E2A76828C48BFB2 0x5C67725E
	static void SET_BLIP_SCALE(Blip blip, float scale) { invoke<Void>(0x00EA14207118EEE2, blip, scale); } // 0x00EA14207118EEE2 0x1E6EC434
	static void SET_BLIP_PRIORITY(Blip blip, int priority) { invoke<Void>(0x84DAB725836026C6, blip, priority); } // 0x84DAB725836026C6 0xCE87DA6F
	static void SET_BLIP_DISPLAY(Blip blip, int p1) { invoke<Void>(0x8E5BEC1151739D19, blip, p1); } // 0x8E5BEC1151739D19 0x2B521F91
	static void SET_BLIP_CATEGORY(Blip blip, int index) { invoke<Void>(0xF2FB8A9F8A77339B, blip, index); } // 0xF2FB8A9F8A77339B 0xEF72F533
	static void REMOVE_BLIP(Blip* blip) { invoke<Void>(0x020DF7300725ECAB, blip); } // 0x020DF7300725ECAB 0xD8C3C1CD
	static void SET_BLIP_AS_FRIENDLY(Blip blip, BOOL toggle) { invoke<Void>(0xB8F5F7438C07CC5E, blip, toggle); } // 0xB8F5F7438C07CC5E 0xF290CFD8
	static void PULSE_BLIP(Blip blip) { invoke<Void>(0x6D6B3A81D5616BD2, blip); } // 0x6D6B3A81D5616BD2 0x44253855
	static void SHOW_NUMBER_ON_BLIP(Blip blip, int number) { invoke<Void>(0x186610BD13A4A462, blip, number); } // 0x186610BD13A4A462 0x7BFC66C6
	static void HIDE_NUMBER_ON_BLIP(Blip blip) { invoke<Void>(0xE77791F1FC77FE64, blip); } // 0xE77791F1FC77FE64 0x0B6D610D
	static void _0x1441D969BF79AD61(Any p0, BOOL p1) { invoke<Void>(0x1441D969BF79AD61, p0, p1); } // 0x1441D969BF79AD61 0x1D99F676
	static void _0xB064704376FA0EEC(Blip blip, BOOL toggle) { invoke<Void>(0xB064704376FA0EEC, blip, toggle); } // 0xB064704376FA0EEC 0x3DCF0092
	static void _SET_BLIP_SHOW_HEADING_INDICATOR(Blip blip, BOOL toggle) { invoke<Void>(0xF361DC7F3B4B03AA, blip, toggle); } // 0xF361DC7F3B4B03AA 0xD1C3D71B
	static void _0x4CA2D8ECD2D01291(Blip blip, BOOL toggle) { invoke<Void>(0x4CA2D8ECD2D01291, blip, toggle); } // 0x4CA2D8ECD2D01291 0x8DE82C15
	static void _0xAF30EAFE8EB0901C(Blip blip, BOOL toggle) { invoke<Void>(0xAF30EAFE8EB0901C, blip, toggle); } // 0xAF30EAFE8EB0901C 0x4C8F02B4
	static void _0xB8607C185C55BB28(Any p0, BOOL p1) { invoke<Void>(0xB8607C185C55BB28, p0, p1); } // 0xB8607C185C55BB28 0xABBE1E45
	static void _0xC2E3C3F87482077D(Any p0, BOOL p1) { invoke<Void>(0xC2E3C3F87482077D, p0, p1); } // 0xC2E3C3F87482077D 0x6AA6A1CC
	static void _0x18E7A80639AD3738(Blip blip, BOOL toggle) { invoke<Void>(0x18E7A80639AD3738, blip, toggle); } // 0x18E7A80639AD3738 0xC575F0BC
	static void _0x66EF553C95DBD200(Any p0, BOOL p1) { invoke<Void>(0x66EF553C95DBD200, p0, p1); } // 0x66EF553C95DBD200 0x40E25DB8
	static BOOL DOES_BLIP_EXIST(Blip blip) { return invoke<BOOL>(0xA3794949321E107C, blip); } // 0xA3794949321E107C 0xAE92DD96
	static void SET_WAYPOINT_OFF() { invoke<Void>(0x4A153C0F9AD7B667); } // 0x4A153C0F9AD7B667 0xB3496E1B
	static void _0x14FBDB4CA98A873E() { invoke<Void>(0x14FBDB4CA98A873E); } // 0x14FBDB4CA98A873E 0x62BABF2C
	static void REFRESH_WAYPOINT() { invoke<Void>(0x3DE10B3409D49985); } // 0x3DE10B3409D49985 0xB395D753
	static BOOL IS_WAYPOINT_ACTIVE() { return invoke<BOOL>(0x7E4FB7620270B0DE); } // 0x7E4FB7620270B0DE 0x5E4DF47B
	static void SET_NEW_WAYPOINT(float x, float y) { invoke<Void>(0x25EC5A9329CC212E, x, y); } // 0x25EC5A9329CC212E 0x8444E1F0
	static void SET_BLIP_BRIGHT(Blip blip, BOOL toggle) { invoke<Void>(0xF0D6BB75887FA3EC, blip, toggle); } // 0xF0D6BB75887FA3EC 0x72BEE6DF
	static void SET_BLIP_SHOW_CONE(Blip blip, BOOL toggle) { invoke<Void>(0xED882F7F9743CE54, blip, toggle); } // 0xED882F7F9743CE54 0xFF545AD8
	static void _0x8144BF84C8CE3A37(Ped ped) { invoke<Void>(0x8144BF84C8CE3A37, ped); } // 0x8144BF84C8CE3A37 0x41B0D022
	static Any SET_MINIMAP_COMPONENT(int p0, BOOL p1, int p2) { return invoke<Any>(0x0E82D004A482B8C4, p0, p1, p2); } // 0x0E82D004A482B8C4 0x419DCDC4
	static void _0x027E120C720CE897() { invoke<Void>(0x027E120C720CE897); } // 0x027E120C720CE897
	static Blip GET_MAIN_PLAYER_BLIP_ID() { return invoke<Blip>(0x6CF0A3791A924670); } // 0x6CF0A3791A924670 0xAB93F020
	static void _0x116E00B757C05163(BOOL p0) { invoke<Void>(0x116E00B757C05163, p0); } // 0x116E00B757C05163
	static void HIDE_LOADING_ON_FADE_THIS_FRAME() { invoke<Void>(0x406D7A3B92830257); } // 0x406D7A3B92830257 0x35087963
	static void SET_RADAR_AS_INTERIOR_THIS_FRAME(Hash interior, float x, float y, int z, int p4) { invoke<Void>(0x8DF8BDE651DEC4D0, interior, x, y, z, p4); } // 0x8DF8BDE651DEC4D0 0x6F2626E1
	static void SET_RADAR_AS_EXTERIOR_THIS_FRAME() { invoke<Void>(0xDD1956264071E397); } // 0xDD1956264071E397 0x39ABB10E
	static void _SET_PLAYER_BLIP_POSITION_THIS_FRAME(float x, float y) { invoke<Void>(0x98C7BC8EA63F3B31, x, y); } // 0x98C7BC8EA63F3B31 0x54E75C7D
	static Any _0xC14DEADD40EAA9D1() { return invoke<Any>(0xC14DEADD40EAA9D1); } // 0xC14DEADD40EAA9D1 0x199DED14
	static void _DISABLE_RADAR_THIS_FRAME() { invoke<Void>(0x1B698E94363E9658); } // 0x1B698E94363E9658 0x1A4318F7
	static void _0xBF0F51076A079F60() { invoke<Void>(0xBF0F51076A079F60); } // 0xBF0F51076A079F60 0xCE36E3FE
	static void _CENTER_PLAYER_ON_RADAR_THIS_FRAME() { invoke<Void>(0xF358DE2AC19ED7A9); } // 0xF358DE2AC19ED7A9 0x334EFD46
	static void SET_WIDESCREEN_FORMAT(Any p0) { invoke<Void>(0x251F1D6579B5B73C, p0); } // 0x251F1D6579B5B73C 0xF016E08F
	static void DISPLAY_AREA_NAME(BOOL toggle) { invoke<Void>(0xB8B8762C095A6869, toggle); } // 0xB8B8762C095A6869 0x489FDD41
	static void DISPLAY_CASH(BOOL toggle) { invoke<Void>(0x5539514B674609C8, toggle); } // 0x5539514B674609C8 0x0049DF83
	static void _0xC1E93E0DDDA8D563(BOOL p0) { invoke<Void>(0xC1E93E0DDDA8D563, p0); } // 0xC1E93E0DDDA8D563
	static void _SET_PLAYER_CASH_CHANGE(int cash, int bank) { invoke<Void>(0x502D103A4CD4470D, cash, bank); } // 0x502D103A4CD4470D
	static void DISPLAY_AMMO_THIS_FRAME(BOOL display) { invoke<Void>(0xBE112CB675E9053B, display); } // 0xBE112CB675E9053B 0x60693CEE
	static void DISPLAY_SNIPER_SCOPE_THIS_FRAME() { invoke<Void>(0x4E16CDB5407A7A30); } // 0x4E16CDB5407A7A30 0xBC6C73CB
	static void HIDE_HUD_AND_RADAR_THIS_FRAME() { invoke<Void>(0x6F9E2FAA0B24988A); } // 0x6F9E2FAA0B24988A 0xB75D4AD2
	static void _0x0466E38C315A4CC3(BOOL p0) { invoke<Void>(0x0466E38C315A4CC3, p0); } // 0x0466E38C315A4CC3 0x5476B9FD
	static void _0xD6A939A590634FEB() { invoke<Void>(0xD6A939A590634FEB); } // 0xD6A939A590634FEB 0xF4F3C796
	static void _0xF3B30338C57769A5() { invoke<Void>(0xF3B30338C57769A5); } // 0xF3B30338C57769A5 0x7BFFE82F
	static void SET_MULTIPLAYER_BANK_CASH() { invoke<Void>(0x6120FA85E07AE920); } // 0x6120FA85E07AE920 0x2C842D03
	static void REMOVE_MULTIPLAYER_BANK_CASH() { invoke<Void>(0xB25E454B492F9D29); } // 0xB25E454B492F9D29 0x728B4EF4
	static void SET_MULTIPLAYER_HUD_CASH(int p0, int p1) { invoke<Void>(0x1CE01F557FCA7D8C, p0, p1); } // 0x1CE01F557FCA7D8C 0xA8DB435E
	static void REMOVE_MULTIPLAYER_HUD_CASH() { invoke<Void>(0x74F443ACA051F94A); } // 0x74F443ACA051F94A 0x07BF4A7D
	static void HIDE_HELP_TEXT_THIS_FRAME() { invoke<Void>(0xECE81A92069CEC24); } // 0xECE81A92069CEC24 0xF3807BED
	static void DISPLAY_HELP_TEXT_THIS_FRAME(char* message, BOOL p1) { invoke<Void>(0x14841AF2D55F125F, message, p1); } // 0x14841AF2D55F125F 0x18E3360A
	static void _SHOW_WEAPON_WHEEL(BOOL forcedShow) { invoke<Void>(0x668D7DAF1FE25754, forcedShow); } // 0x668D7DAF1FE25754 0x1EFFB02A
	static void _0xDFAEE93016107557() { invoke<Void>(0xDFAEE93016107557); } // 0xDFAEE93016107557 0xB26FED2B
	static Hash _0x819A98CCFE5FACD6() { return invoke<Hash>(0x819A98CCFE5FACD6); } // 0x819A98CCFE5FACD6 0x22E9F555
	static void _0x965FF89F07F86DF0(Any p0) { invoke<Void>(0x965FF89F07F86DF0, p0); } // 0x965FF89F07F86DF0 0x83B608A0
	static Any _0xB41415484B2631D9(Any p0) { return invoke<Any>(0xB41415484B2631D9, p0); } // 0xB41415484B2631D9
	static void _0xC204ECF953214FBF(BOOL p0) { invoke<Void>(0xC204ECF953214FBF, p0); } // 0xC204ECF953214FBF 0xE70D1F43
	static void SET_GPS_FLAGS(int p0, float p1) { invoke<Void>(0x559F0F361D3673AA, p0, p1); } // 0x559F0F361D3673AA 0x60539BAB
	static void CLEAR_GPS_FLAGS() { invoke<Void>(0x8499F04E8C7E383C); } // 0x8499F04E8C7E383C 0x056AFCE6
	static void _0xB64CD10D194F9B54(BOOL p0) { invoke<Void>(0xB64CD10D194F9B54, p0); } // 0xB64CD10D194F9B54 0xFB9BABF5
	static void CLEAR_GPS_RACE_TRACK() { invoke<Void>(0x88CE1739AD6C0A77); } // 0x88CE1739AD6C0A77 0x40C59829
	static void _0x4972F19E4A212CE1(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x4972F19E4A212CE1, p0, p1, p2); } // 0x4972F19E4A212CE1 0x7F93799B
	static void _0xCBE5CB1AD57A74F2(Any p0, Any p1, Any p2) { invoke<Void>(0xCBE5CB1AD57A74F2, p0, p1, p2); } // 0xCBE5CB1AD57A74F2 0xEEBDFE55
	static void _0xAE29D3F989F087E2(BOOL p0, Any p1, Any p2) { invoke<Void>(0xAE29D3F989F087E2, p0, p1, p2); } // 0xAE29D3F989F087E2 0xDA0AF00E
	static void _0x5201F1932905F2AF() { invoke<Void>(0x5201F1932905F2AF); } // 0x5201F1932905F2AF 0xCF2E3E24
	static void _0x7D49FE2253372FF2(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x7D49FE2253372FF2, p0, p1, p2); } // 0x7D49FE2253372FF2 0xC3DCBEDB
	static void _0x0176EABC26B1AB7F(float x, float y, float z) { invoke<Void>(0x0176EABC26B1AB7F, x, y, z); } // 0x0176EABC26B1AB7F 0xFE485135
	static void _0xAB47D4636B324239(BOOL p0) { invoke<Void>(0xAB47D4636B324239, p0); } // 0xAB47D4636B324239 0xE87CBE4C
	static void _0x527330BECBB9D9CD() { invoke<Void>(0x527330BECBB9D9CD); } // 0x527330BECBB9D9CD 0x0D9969E4
	static void CLEAR_GPS_PLAYER_WAYPOINT() { invoke<Void>(0x5C0C576F26E35273); } // 0x5C0C576F26E35273 0x0B9C7FC2
	static void SET_GPS_FLASHES(BOOL toggle) { invoke<Void>(0xB3EDAA8FE8E48BD6, toggle); } // 0xB3EDAA8FE8E48BD6 0xE991F733
	static void _0x24F4E73BFBD22BF3(Any p0) { invoke<Void>(0x24F4E73BFBD22BF3, p0); } // 0x24F4E73BFBD22BF3
	static void FLASH_MINIMAP_DISPLAY() { invoke<Void>(0x3CB6B08E51C56965); } // 0x3CB6B08E51C56965 0xB8359952
	static void _0xAB69BE23A9C5ED9A(Any p0) { invoke<Void>(0xAB69BE23A9C5ED9A, p0); } // 0xAB69BE23A9C5ED9A 0x79A6CAF6
	static void TOGGLE_STEALTH_RADAR(BOOL toggle) { invoke<Void>(0xD44C86C49C8C0DE4, toggle); } // 0xD44C86C49C8C0DE4 0xC68D47C4
	static void KEY_HUD_COLOUR(BOOL p0, Any p1) { invoke<Void>(0x52E31E86D25659E8, p0, p1); } // 0x52E31E86D25659E8 0xD5BFCADB
	static void SET_MISSION_NAME(BOOL p0, char* name) { invoke<Void>(0x2A8465C4D16098B7, p0, name); } // 0x2A8465C4D16098B7 0x68DCAE10
	static void _0x3B05936DDDB2354C(BOOL p0, Any* p1) { invoke<Void>(0x3B05936DDDB2354C, p0, p1); } // 0x3B05936DDDB2354C 0x8D9A1734
	static void _0x124EDA44178F99ED(BOOL p0, Any* p1, Any* p2, Any* p3, Any* p4, Any* p5, Any* p6, Any* p7, Any* p8) { invoke<Void>(0x124EDA44178F99ED, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x124EDA44178F99ED 0xD2161E77
	static void SET_MINIMAP_BLOCK_WAYPOINT(BOOL toggle) { invoke<Void>(0xA08ADEDF4B195A52, toggle); } // 0xA08ADEDF4B195A52 0xA41C3B62
	static void _SET_MINIMAP_VISIBLE(BOOL toggle) { invoke<Void>(0x0D786362A6EE2303, toggle); } // 0x0D786362A6EE2303 0x02F5F1D1
	static void _SET_MINIMAP_REVEALED(BOOL toggle) { invoke<Void>(0x36364D2FAA470DE4, toggle); } // 0x36364D2FAA470DE4 0xD8D77733
	static float _0x5BFF8696A21369A2() { return invoke<float>(0x5BFF8696A21369A2); } // 0x5BFF8696A21369A2 0xA4098ACC
	static BOOL _IS_MINIMAP_AREA_REVEALED(float x, float y, float radius) { return invoke<BOOL>(0x33FE10504886A9BA, x, y, radius); } // 0x33FE10504886A9BA 0x65B705F6
	static void _0x92F079B25E00211C(BOOL p0) { invoke<Void>(0x92F079B25E00211C, p0); } // 0x92F079B25E00211C
	static void _0xA0727C239DAF134A(float x, float y, float z) { invoke<Void>(0xA0727C239DAF134A, x, y, z); } // 0xA0727C239DAF134A 0xE010F081
	static void _0xAE9FC31F69A6915D(Any p0) { invoke<Void>(0xAE9FC31F69A6915D, p0); } // 0xAE9FC31F69A6915D 0x5133A750
	static void _0x3AC0C84A408D8F86() { invoke<Void>(0x3AC0C84A408D8F86); } // 0x3AC0C84A408D8F86 0x20FD3E87
	static void LOCK_MINIMAP_ANGLE(int angle) { invoke<Void>(0xB1E4E9B0F4CDBACB, angle); } // 0xB1E4E9B0F4CDBACB 0xDEC733E4
	static void UNLOCK_MINIMAP_ANGLE() { invoke<Void>(0x4E922294F8C1353B); } // 0x4E922294F8C1353B 0x742043F9
	static void LOCK_MINIMAP_POSITION(float x, float y) { invoke<Void>(0xBAFFAD0E1F0AFF4B, x, y); } // 0xBAFFAD0E1F0AFF4B 0xB9632A91
	static void UNLOCK_MINIMAP_POSITION() { invoke<Void>(0x13F048D41F427E2C); } // 0x13F048D41F427E2C 0x5E8E6F54
	static void _SET_MINIMAP_ATTITUDE_INDICATOR_LEVEL(float altitude, BOOL p1) { invoke<Void>(0x1BFAAA241E08B70C, altitude, p1); } // 0x1BFAAA241E08B70C 0x0308EDF6
	static void _0x73A506737186B922(Any p0, Any p1, BOOL p2) { invoke<Void>(0x73A506737186B922, p0, p1, p2); } // 0x73A506737186B922 0x7FB6FB2A
	static void _0x3894B76027A00029(Any p0) { invoke<Void>(0x3894B76027A00029, p0); } // 0x3894B76027A00029 0xF07D8CEF
	static void _0x7B7969F903A2A318(Any p0) { invoke<Void>(0x7B7969F903A2A318, p0); } // 0x7B7969F903A2A318 0x827F14DE
	static void _SET_RADAR_BIGMAP_ENABLED(BOOL toggleBigMap, BOOL showFullMap) { invoke<Void>(0x12828E22316A98F1, toggleBigMap, showFullMap); } // 0x12828E22316A98F1 0x08EB83D2
	static BOOL IS_HUD_COMPONENT_ACTIVE(int id) { return invoke<BOOL>(0x33243A46E91831D5, id); } // 0x33243A46E91831D5 0x6214631F
	static BOOL IS_SCRIPTED_HUD_COMPONENT_ACTIVE(int id) { return invoke<BOOL>(0xBA086B10332B39D4, id); } // 0xBA086B10332B39D4 0x2B86F382
	static void HIDE_SCRIPTED_HUD_COMPONENT_THIS_FRAME(int id) { invoke<Void>(0x9E09DC2C42A67471, id); } // 0x9E09DC2C42A67471 0x31ABA127
	static BOOL _0x75D19B091647234E(Any p0) { return invoke<BOOL>(0x75D19B091647234E, p0); } // 0x75D19B091647234E 0xE8C8E535
	static void HIDE_HUD_COMPONENT_THIS_FRAME(int id) { invoke<Void>(0xE57F94EA937AAD99, id); } // 0xE57F94EA937AAD99 0xDB2D0762
	static void SHOW_HUD_COMPONENT_THIS_FRAME(int id) { invoke<Void>(0xD4AB660C54ABFEF2, id); } // 0xD4AB660C54ABFEF2 0x95E1546E
	static void _0x95653006F0206036() { invoke<Void>(0x95653006F0206036); } // 0x95653006F0206036 0x52746FE1
	static void RESET_RETICULE_VALUES() { invoke<Void>(0x4664F1C8718537B5); } // 0x4664F1C8718537B5 0xBE27AA3F
	static void RESET_HUD_COMPONENT_VALUES(int id) { invoke<Void>(0x81118A143DD8B493, id); } // 0x81118A143DD8B493 0xD15B46DA
	static void SET_HUD_COMPONENT_POSITION(int id, float p1, float p2) { invoke<Void>(0x0E544F498B88F47B, id, p1, p2); } // 0x0E544F498B88F47B 0x2F3A0D15
	static Vector3 GET_HUD_COMPONENT_POSITION(Any p0) { return invoke<Vector3>(0x715C91CE329F2B21, p0); } // 0x715C91CE329F2B21 0x080DCED6
	static void _0x24DB6E574207E4FC() { invoke<Void>(0x24DB6E574207E4FC); } // 0x24DB6E574207E4FC 0x5BBCC934
	static Any _0xC8521F8D0C517AC0(float x, float y, float z, Any* p3, Any* p4) { return invoke<Any>(0xC8521F8D0C517AC0, x, y, z, p3, p4); } // 0xC8521F8D0C517AC0 0xFE9A39F8
	static void _0xDE0EB5171E7162D0() { invoke<Void>(0xDE0EB5171E7162D0); } // 0xDE0EB5171E7162D0 0x10DE5150
	static void _0x3E4CE0A70FA03BA1() { invoke<Void>(0x3E4CE0A70FA03BA1); } // 0x3E4CE0A70FA03BA1 0x67649EE0
	static Any _0xA3961278335D3B17() { return invoke<Any>(0xA3961278335D3B17); } // 0xA3961278335D3B17 0x9D2C94FA
	static BOOL _0x70627BC9EA33B9CA(Any p0) { return invoke<BOOL>(0x70627BC9EA33B9CA, p0); } // 0x70627BC9EA33B9CA 0x45472FD5
	static void _0xD65E6FC506984A23(Any p0, float p1, float p2) { invoke<Void>(0xD65E6FC506984A23, p0, p1, p2); } // 0xD65E6FC506984A23 0x198F32D7
	static void _0x4AF66D8098AADE50(Any p0, float x, float y, float z) { invoke<Void>(0x4AF66D8098AADE50, p0, x, y, z); } // 0x4AF66D8098AADE50 0x93045157
	static void _0x86DCE96025C9409C(Any p0, Any p1, float p2, float p3) { invoke<Void>(0x86DCE96025C9409C, p0, p1, p2, p3); } // 0x86DCE96025C9409C 0x18B012B7
	static void _0xDDB796819E994640(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<Void>(0xDDB796819E994640, p0, p1, p2, p3, p4, p5); } // 0xDDB796819E994640 0x97852A82
	static void CLEAR_FLOATING_HELP(Any p0, BOOL p1) { invoke<Void>(0x2B3976C5A4017270, p0, p1); } // 0x2B3976C5A4017270 0xB181F88F
	static void _0x1A29ACFFD69BE695(int headDisplayId, char* username, BOOL pointedClanTag, BOOL isRockstarClan, char* clanTag, Any p5, Any p6, Any p7, Any p8) { invoke<Void>(0x1A29ACFFD69BE695, headDisplayId, username, pointedClanTag, isRockstarClan, clanTag, p5, p6, p7, p8); } // 0x1A29ACFFD69BE695 0xC969F2D0
	static BOOL _0x2C92D004514004C8() { return invoke<BOOL>(0x2C92D004514004C8); } // 0x2C92D004514004C8 0xEFD2564A
	static int _CREATE_HEAD_DISPLAY(Ped ped, char* username, BOOL pointedClanTag, BOOL isRockstarClan, char* clanTag, Any p5) { return invoke<int>(0x4AE6A6509B5C2525, ped, username, pointedClanTag, isRockstarClan, clanTag, p5); } // 0x4AE6A6509B5C2525 0xF5CD2AA4
	static void _0x2B11A26F357773C0(int headDisplayId) { invoke<Void>(0x2B11A26F357773C0, headDisplayId); } // 0x2B11A26F357773C0 0x3D081FE4
	static BOOL _HAS_HEAD_DISPLAY_LOADED(int headDisplayId) { return invoke<BOOL>(0xFBC2A678DCE7B109, headDisplayId); } // 0xFBC2A678DCE7B109 0x60118951
	static BOOL ADD_TREVOR_RANDOM_MODIFIER(int headDisplayId) { return invoke<BOOL>(0xBBC2AB541D2228FA, headDisplayId); } // 0xBBC2AB541D2228FA 0x63959059
	static void _SET_HEAD_DISPLAY_FLAG(int headDisplayId, int sprite, BOOL toggle) { invoke<Void>(0x5E7555358B847B31, headDisplayId, sprite, toggle); } // 0x5E7555358B847B31 0xD41DF479
	static void _0x5958839310B55EF8(int headDisplayId, BOOL p1) { invoke<Void>(0x5958839310B55EF8, headDisplayId, p1); } // 0x5958839310B55EF8 0x767DED29
	static void _0x2074D63AEEA6FCFD(int headDisplayId, BOOL p1) { invoke<Void>(0x2074D63AEEA6FCFD, headDisplayId, p1); } // 0x2074D63AEEA6FCFD 0xB01A5434
	static void _0x6BED78D05DD4E2C2(int headDisplayId, Any p1, int flag) { invoke<Void>(0x6BED78D05DD4E2C2, headDisplayId, p1, flag); } // 0x6BED78D05DD4E2C2 0x7E3AA40A
	static void _0x14E172E29E4A4D73(int headDisplayId, Any p1) { invoke<Void>(0x14E172E29E4A4D73, headDisplayId, p1); } // 0x14E172E29E4A4D73 0x5777EC77
	static void _0x7ED32BA83C1B774E(int headDisplayId, Any p1, Any p2) { invoke<Void>(0x7ED32BA83C1B774E, headDisplayId, p1, p2); } // 0x7ED32BA83C1B774E 0xF4418611
	static void _SET_HEAD_DISPLAY_WANTED(int headDisplayId, int wantedlvl) { invoke<Void>(0xF230D196D49D246C, headDisplayId, wantedlvl); } // 0xF230D196D49D246C 0x0EBB003F
	static void _SET_HEAD_DISPLAY_STRING(int headDisplayId, char* string) { invoke<Void>(0xEB4A8A07F6105B3E, headDisplayId, string); } // 0xEB4A8A07F6105B3E 0x627A559B
	static BOOL _0xD0B94BB1007A6823(int headDisplayId) { return invoke<BOOL>(0xD0B94BB1007A6823, headDisplayId); } // 0xD0B94BB1007A6823 0xF11414C4
	static void _0x8527285852D9C7AD(int headDisplayId, char* string) { invoke<Void>(0x8527285852D9C7AD, headDisplayId, string); } // 0x8527285852D9C7AD 0x939218AB
	static Any _0xE85C83479C0D5825() { return invoke<Any>(0xE85C83479C0D5825); } // 0xE85C83479C0D5825 0xAB5B7C18
	static int GET_CURRENT_WEBSITE_ID() { return invoke<int>(0x229F88D429A4BA92); } // 0x229F88D429A4BA92 0x42A55B14
	static Any _0x8875F5F69CAA7914(Any p0) { return invoke<Any>(0x8875F5F69CAA7914, p0); } // 0x8875F5F69CAA7914 0xD217EE7E
	static void _0x59536718CB2E70FE(BOOL p0) { invoke<Void>(0x59536718CB2E70FE, p0); } // 0x59536718CB2E70FE
	static Any _0x9921E2A63086C7CC() { return invoke<Any>(0x9921E2A63086C7CC); } // 0x9921E2A63086C7CC
	static void SET_WARNING_MESSAGE(char* entryLine1, int instructionalKey, char* entryLine2, BOOL p3, Any p4, Any* p5, Any* p6, BOOL background) { invoke<Void>(0x7B1776B3B53F8D74, entryLine1, instructionalKey, entryLine2, p3, p4, p5, p6, background); } // 0x7B1776B3B53F8D74 0xBE699BDE
	static void _SET_WARNING_MESSAGE_2(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background) { invoke<Void>(0xDC38CC1E35B6A5D7, entryHeader, entryLine1, instructionalKey, entryLine2, p4, p5, p6, p7, background); } // 0xDC38CC1E35B6A5D7 0x2DB9EAB5
	static void _SET_WARNING_MESSAGE_3(char* entryHeader, char* entryLine1, Any instructionalKey, char* entryLine2, BOOL p4, Any p5, Any p6, Any* p7, Any* p8, BOOL p9) { invoke<Void>(0x701919482C74B5AB, entryHeader, entryLine1, instructionalKey, entryLine2, p4, p5, p6, p7, p8, p9); } // 0x701919482C74B5AB 0x749929D3
	static BOOL _0x0C5A80A9E096D529(Any p0, Any* p1, Any p2, Any p3, Any p4, Any p5) { return invoke<BOOL>(0x0C5A80A9E096D529, p0, p1, p2, p3, p4, p5); } // 0x0C5A80A9E096D529
	static BOOL _0x7DC3820CB08246F2(Any p0) { return invoke<BOOL>(0x7DC3820CB08246F2, p0); } // 0x7DC3820CB08246F2
	static void _0x906B58BDD76BE957() { invoke<Void>(0x906B58BDD76BE957); } // 0x906B58BDD76BE957
	static BOOL IS_WARNING_MESSAGE_ACTIVE() { return invoke<BOOL>(0x1CB39616BED2D488); } // 0x1CB39616BED2D488 0x94C834AD
	static void _0xE72D244BC255F603() { invoke<Void>(0xE72D244BC255F603); } // 0xE72D244BC255F603 0x2F9A309C
	static void _0x88DF1837B1F01E19(BOOL p0) { invoke<Void>(0x88DF1837B1F01E19, p0); } // 0x88DF1837B1F01E19 0xE4FD20D8
	static void _0x85EF7353FA8C7D3F(Any p0) { invoke<Void>(0x85EF7353FA8C7D3F, p0); } // 0x85EF7353FA8C7D3F 0x13E7A5A9
	static Any _0x4DFC9CB08E5215EF(float p0, float p1, float p2) { return invoke<Any>(0x4DFC9CB08E5215EF, p0, p1, p2); } // 0x4DFC9CB08E5215EF 0x786CA0A2
	static void _0xCA56DB9193C311CF() { invoke<Void>(0xCA56DB9193C311CF); } // 0xCA56DB9193C311CF 0xCBEC9369
	static Any _0x42F535188B54526E() { return invoke<Any>(0x42F535188B54526E); } // 0x42F535188B54526E 0x3F4AFB13
	static void _0xE8C2955DC69804F5(BOOL p0) { invoke<Void>(0xE8C2955DC69804F5, p0); } // 0xE8C2955DC69804F5 0x2F28F0A6
	static void _0xCB008B01AB1E7CE7() { invoke<Void>(0xCB008B01AB1E7CE7); } // 0xCB008B01AB1E7CE7 0x801D0D86
	static void _0xB732CD8CBDA6FE17() { invoke<Void>(0xB732CD8CBDA6FE17); } // 0xB732CD8CBDA6FE17 0x317775DF
	static void ACTIVATE_FRONTEND_MENU(Hash menuhash, BOOL Toggle_Pause, int p2) { invoke<Void>(0xDE0859BF2E736A50, menuhash, Toggle_Pause, p2); } // 0xDE0859BF2E736A50 0x01D83872
	static void RESTART_FRONTEND_MENU(Hash menuHash, int p1) { invoke<Void>(0xFA0709FE33B0644A, menuHash, p1); } // 0xFA0709FE33B0644A 0xB07DAF98
	static Hash _0x1D1D89EE4B99480F() { return invoke<Hash>(0x1D1D89EE4B99480F); } // 0x1D1D89EE4B99480F 0x33D6868F
	static void SET_PAUSE_MENU_ACTIVE(BOOL toggle) { invoke<Void>(0x35E0F8AED5306984, toggle); } // 0x35E0F8AED5306984 0x1DCD878E
	static void DISABLE_FRONTEND_THIS_FRAME() { invoke<Void>(0x2C8E2F4CCFAAB00F); } // 0x2C8E2F4CCFAAB00F 0xD86A029E
	static void _0xE5ED3E8F8C6274B7() { invoke<Void>(0xE5ED3E8F8C6274B7); } // 0xE5ED3E8F8C6274B7 0x7F349900
	static void _0x4F1142E262783DAC() { invoke<Void>(0x4F1142E262783DAC); } // 0x4F1142E262783DAC 0x630CD8EE
	static void SET_FRONTEND_ACTIVE(BOOL active) { invoke<Void>(0x5163A40A6B824C7B, active); } // 0x5163A40A6B824C7B 0x81E1AD32
	static BOOL IS_PAUSE_MENU_ACTIVE() { return invoke<BOOL>(0x95DBE123BC2DB80B); } // 0x95DBE123BC2DB80B 0xD3600591
	static Any _0x7A1E93F2188B6464() { return invoke<Any>(0x7A1E93F2188B6464); } // 0x7A1E93F2188B6464 0xC85C4487
	static int GET_PAUSE_MENU_STATE() { return invoke<int>(0x3C9A4847496426B9); } // 0x3C9A4847496426B9 0x92F50134
	static Vector3 _0x642D0515DA8BA1DD() { return invoke<Vector3>(0x642D0515DA8BA1DD); } // 0x642D0515DA8BA1DD
	static BOOL IS_PAUSE_MENU_RESTARTING() { return invoke<BOOL>(0x3042F6AAE180C916); } // 0x3042F6AAE180C916 0x3C4CF4D9
	static void _LOG_DEBUG_INFO(char* p0) { invoke<Void>(0x9B4C6B445CDD4735, p0); } // 0x9B4C6B445CDD4735 0x2DFD35C7
	static void _0xD761B28BB3DBE892(Any p0) { invoke<Void>(0xD761B28BB3DBE892, p0); } // 0xD761B28BB3DBE892 0x0A89336C
	static void _0x3EF86DB5C04FAAB5() { invoke<Void>(0x3EF86DB5C04FAAB5); } // 0x3EF86DB5C04FAAB5 0xC84BE309
	static void _0x4DDCE83D0BC7A695(Hash hash) { invoke<Void>(0x4DDCE83D0BC7A695, hash); } // 0x4DDCE83D0BC7A695 0x9FE8FD5E
	static void OBJECT_DECAL_TOGGLE(Hash hash) { invoke<Void>(0x33BA97D6CB5751AA, hash); } // 0x33BA97D6CB5751AA 0x0029046E
	static BOOL _0xF886D55825EAC222(Hash hash) { return invoke<BOOL>(0xF886D55825EAC222, hash); } // 0xF886D55825EAC222 0xC51BC42F
	static Any _0x398D7B7535CCEE68() { return invoke<Any>(0x398D7B7535CCEE68); } // 0x398D7B7535CCEE68 0x016D7AF9
	static Any _0xE5A21F85AA56BB08() { return invoke<Any>(0xE5A21F85AA56BB08); } // 0xE5A21F85AA56BB08
	static Any _0xA8F9CB25DE72E877() { return invoke<Any>(0xA8F9CB25DE72E877); } // 0xA8F9CB25DE72E877
	static Any _0x0F0C7E2964F29E79() { return invoke<Any>(0x0F0C7E2964F29E79); } // 0x0F0C7E2964F29E79
	static BOOL _0xE801E0CEC04F5FE0(Any* p0, Any* p1, Any* p2) { return invoke<BOOL>(0xE801E0CEC04F5FE0, p0, p1, p2); } // 0xE801E0CEC04F5FE0
	static void ENABLE_DEATHBLOOD_SEETHROUGH(BOOL p0) { invoke<Void>(0xE4791CD7B9058A39, p0); } // 0xE4791CD7B9058A39 0x15B24768
	static void _0x2343E6B31EC7047B(BOOL p0, Any p1, Any p2) { invoke<Void>(0x2343E6B31EC7047B, p0, p1, p2); } // 0x2343E6B31EC7047B 0x6C67131A
	static void _0x4740C8595B38A826(BOOL p0) { invoke<Void>(0x4740C8595B38A826, p0); } // 0x4740C8595B38A826 0x11D09737
	static Any _0x1773F603A948CF47() { return invoke<Any>(0x1773F603A948CF47); } // 0x1773F603A948CF47 0xD3BF3ABD
	static void _0x31838BEF2D32FDC7() { invoke<Void>(0x31838BEF2D32FDC7); } // 0x31838BEF2D32FDC7 0xC06B763D
	static void _0x050E16506E4EAEA5() { invoke<Void>(0x050E16506E4EAEA5); } // 0x050E16506E4EAEA5 0xB9392CE7
	static Any _0x37E66CFB92C93B18() { return invoke<Any>(0x37E66CFB92C93B18); } // 0x37E66CFB92C93B18 0x92DAFA78
	static Any _0xB9D2349C9CF90A6F() { return invoke<Any>(0xB9D2349C9CF90A6F); } // 0xB9D2349C9CF90A6F 0x22CA9F2A
	static Any _0x24AE3170BC4A3464() { return invoke<Any>(0x24AE3170BC4A3464); } // 0x24AE3170BC4A3464 0xDA7951A2
	static Any _0xFB2EB4DD1E47E375() { return invoke<Any>(0xFB2EB4DD1E47E375); } // 0xFB2EB4DD1E47E375 0x7D95AFFF
	static Any _0x135117102851346E() { return invoke<Any>(0x135117102851346E); } // 0x135117102851346E 0x96863460
	static void _0xE5863C86A7D79252(Any p0) { invoke<Void>(0xE5863C86A7D79252, p0); } // 0xE5863C86A7D79252
	static void _0x5338427A44630605(Any* p0, Any* p1) { invoke<Void>(0x5338427A44630605, p0, p1); } // 0x5338427A44630605 0x8543AAC8
	static void _0xA6AE0FB06ABB77D8(Any* p0, Any* p1, Any* p2) { invoke<Void>(0xA6AE0FB06ABB77D8, p0, p1, p2); } // 0xA6AE0FB06ABB77D8 0x6025AA2F
	static BOOL _0x3300D0292CF507E7(int* p0, int* p1, int* p2) { return invoke<BOOL>(0x3300D0292CF507E7, p0, p1, p2); } // 0x3300D0292CF507E7 0x46794EB2
	static BOOL SET_USERIDS_UIHIDDEN(Any p0, Any* p1) { return invoke<BOOL>(0xE9AF4D0D57FA13BF, p0, p1); } // 0xE9AF4D0D57FA13BF 0x4370999E
	static BOOL _0x3B88886937131189(Any p0, Any* p1, Any p2) { return invoke<BOOL>(0x3B88886937131189, p0, p1, p2); } // 0x3B88886937131189
	static BOOL _0x7356EB17247C7F43(Any p0, Any* p1, Any p2, Any p3) { return invoke<BOOL>(0x7356EB17247C7F43, p0, p1, p2, p3); } // 0x7356EB17247C7F43 0xD6CC4766
	static BOOL _0xF78BF8CFB920EA15(Any p0, Any* p1, Any p2, Any p3, Any p4) { return invoke<BOOL>(0xF78BF8CFB920EA15, p0, p1, p2, p3, p4); } // 0xF78BF8CFB920EA15
	static BOOL _0x8DEDE4608EC7298C(Any p0, float* p1) { return invoke<BOOL>(0x8DEDE4608EC7298C, p0, p1); } // 0x8DEDE4608EC7298C 0x51972B04
	static BOOL _0x6E19A42768F4C44B(Any p0, Any* p1, Any p2) { return invoke<BOOL>(0x6E19A42768F4C44B, p0, p1, p2); } // 0x6E19A42768F4C44B
	static BOOL _0xD2957053DBB7A565(Hash p0, Any* p1) { return invoke<BOOL>(0xD2957053DBB7A565, p0, p1); } // 0xD2957053DBB7A565 0xD43BB56D
	static void CLEAR_PED_IN_PAUSE_MENU() { invoke<Void>(0x5DEF8A5CA7127A97); } // 0x5DEF8A5CA7127A97 0x28058ACF
	static void GIVE_PED_TO_PAUSE_MENU(Ped ped, int p1) { invoke<Void>(0x112E73EF42D1F3E3, ped, p1); } // 0x112E73EF42D1F3E3 0x2AD2C9CE
	static void _0xCD03E167527833D5(BOOL p0) { invoke<Void>(0xCD03E167527833D5, p0); } // 0xCD03E167527833D5 0x127310EB
	static void _0xC1E7A4AF902B588B(BOOL p0) { invoke<Void>(0xC1E7A4AF902B588B, p0); } // 0xC1E7A4AF902B588B 0x8F45D327
	static void _SHOW_SOCIAL_CLUB_LEGAL_SCREEN() { invoke<Void>(0x5B41EFE6D95A0BAC); } // 0x5B41EFE6D95A0BAC 0x19FCBBB2
	static Any _0x3BF78C8E67D847AF() { return invoke<Any>(0x3BF78C8E67D847AF); } // 0x3BF78C8E67D847AF 0x850690FF
	static Any _0x5F7CFDBB22300BCC() { return invoke<Any>(0x5F7CFDBB22300BCC); } // 0x5F7CFDBB22300BCC 0x9D4934F4
	static void _0x5607262F74817902() { invoke<Void>(0x5607262F74817902); } // 0x5607262F74817902 0x57218529
	static void _0x19DF5FE89AF2144E() { invoke<Void>(0x19DF5FE89AF2144E); } // 0x19DF5FE89AF2144E 0x5F86AA39
	static void _0xD4B482DFF2BF13A2(char* p0) { invoke<Void>(0xD4B482DFF2BF13A2, p0); } // 0xD4B482DFF2BF13A2 0x7AD67C95
	static Any _0xF84F40868AAA98DC() { return invoke<Any>(0xF84F40868AAA98DC); } // 0xF84F40868AAA98DC 0xD4DA14EF
	static void _0xC2B9925B944A1EB9(BOOL p0) { invoke<Void>(0xC2B9925B944A1EB9, p0); } // 0xC2B9925B944A1EB9
	static void _0x92DA779057C37C99() { invoke<Void>(0x92DA779057C37C99); } // 0x92DA779057C37C99
	static BOOL _IS_TEXT_CHAT_ACTIVE() { return invoke<BOOL>(0xF78621B630067487); } // 0xF78621B630067487
	static void _ABORT_TEXT_CHAT() { invoke<Void>(0xE20B1BFAAFEE2C36); } // 0xE20B1BFAAFEE2C36
	static void _SET_TEXT_CHAT_UNK(BOOL p0) { invoke<Void>(0xCD99B30256F6D689, p0); } // 0xCD99B30256F6D689
	static void _0x86F2FAE00D641B31(BOOL p0) { invoke<Void>(0x86F2FAE00D641B31, p0); } // 0x86F2FAE00D641B31 0xFF06772A
	static void _0x53D9FD8A3418C8E9(Ped ped, BOOL p1) { invoke<Void>(0x53D9FD8A3418C8E9, ped, p1); } // 0x53D9FD8A3418C8E9 0x96C4C4DD
	static BOOL DOES_PED_HAVE_AI_BLIP(Ped ped) { return invoke<BOOL>(0x708B478711FA7649, ped); } // 0x708B478711FA7649 0x3BE1257F
	static void _0x7E0E4A8CBE4A8769(Ped ped, Any p1) { invoke<Void>(0x7E0E4A8CBE4A8769, ped, p1); } // 0x7E0E4A8CBE4A8769 0xD8E31B1A
	static void HIDE_SPECIAL_ABILITY_LOCKON_OPERATION(Any p0, BOOL p1) { invoke<Void>(0xB04373FE92ECD69C, p0, p1); } // 0xB04373FE92ECD69C 0x872C2CFB
	static void _0xB9B7F383FB2453E6(Ped ped, BOOL p1) { invoke<Void>(0xB9B7F383FB2453E6, ped, p1); } // 0xB9B7F383FB2453E6 0xFFDF46F0
	static void _0xC49F45795B7AFEEA(Ped ped, float p1) { invoke<Void>(0xC49F45795B7AFEEA, ped, p1); } // 0xC49F45795B7AFEEA 0xF9DC2AF7
	static Any _0x4DFA608A26DB4230(Any p0) { return invoke<Any>(0x4DFA608A26DB4230, p0); } // 0x4DFA608A26DB4230 0x06349065
	static Blip _0x3329BF35D4BD3992(Ped ped) { return invoke<Blip>(0x3329BF35D4BD3992, ped); } // 0x3329BF35D4BD3992 0xCA52CF43
	static Any _0x4A5EEB23B781F757() { return invoke<Any>(0x4A5EEB23B781F757); } // 0x4A5EEB23B781F757
	static void _0x6BDD892D484E0731() { invoke<Void>(0x6BDD892D484E0731); } // 0x6BDD892D484E0731
	static void _0x0631CFD4CF7CAA31(BOOL p0) { invoke<Void>(0x0631CFD4CF7CAA31, p0); } // 0x0631CFD4CF7CAA31
	static void _0x9EB31D48E1688FDD(BOOL p0) { invoke<Void>(0x9EB31D48E1688FDD, p0); } // 0x9EB31D48E1688FDD
}

namespace GRAPHICS
{
	static void SET_DEBUG_LINES_AND_SPHERES_DRAWING_ACTIVE(BOOL enabled) { invoke<Void>(0x95BC36698BEE6EB1, enabled); } // 0x95BC36698BEE6EB1 0x1418CA37
	static void DRAW_DEBUG_LINE(float x1, float y1, float z1, float x2, float y2, float z2, int r, int g, int b, int alpha) { invoke<Void>(0xFC3DFAAD6C8811A5, x1, y1, z1, x2, y2, z2, r, g, b, alpha); } // 0xFC3DFAAD6C8811A5 0xABF783AB
	static void DRAW_DEBUG_LINE_WITH_TWO_COLOURS(float x1, float y1, float z1, float x2, float y2, float z2, int r1, int g1, int b1, int r2, int g2, int b2, int alpha1, int alpha2) { invoke<Void>(0xB40FB5D5A6A33BCE, x1, y1, z1, x2, y2, z2, r1, g1, b1, r2, g2, b2, alpha1, alpha2); } // 0xB40FB5D5A6A33BCE 0xE8BFF632
	static void DRAW_DEBUG_SPHERE(float x, float y, float z, float radius, int r, int g, int b, int alpha) { invoke<Void>(0x7B805D5EC24E5C37, x, y, z, radius, r, g, b, alpha); } // 0x7B805D5EC24E5C37 0x304D0EEF
	static void DRAW_DEBUG_BOX(float x1, float y1, float z1, float x2, float y2, float z2, int r, int g, int b, int alpha) { invoke<Void>(0xFC3DFAAD6C8811A5, x1, y1, z1, x2, y2, z2, r, g, b, alpha); } // 0xFC3DFAAD6C8811A5 0x8524A848
	static void DRAW_DEBUG_CROSS(float x, float y, float z, float size, int r, int g, int b, int alpha) { invoke<Void>(0x76E120B1FED80B47, x, y, z, size, r, g, b, alpha); } // 0x76E120B1FED80B47 0xB6DF3709
	static void DRAW_DEBUG_TEXT(char* text, float x, float y, float z, int r, int g, int b, int alpha) { invoke<Void>(0x9D69CCD890B628E8, text, x, y, z, r, g, b, alpha); } // 0x9D69CCD890B628E8 0x269B006F
	static void DRAW_DEBUG_TEXT_2D(char* text, float x, float y, float z, int r, int g, int b, int alpha) { invoke<Void>(0xCE92FE50F370E679, text, x, y, z, r, g, b, alpha); } // 0xCE92FE50F370E679 0x528B973B
	static void DRAW_LINE(float x1, float y1, float z1, float x2, float y2, float z2, int r, int g, int b, int alpha) { invoke<Void>(0x8B7B6E9B27BEE498, x1, y1, z1, x2, y2, z2, r, g, b, alpha); } // 0x8B7B6E9B27BEE498 0xB3426BCC
	static void DRAW_POLY(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, int r, int g, int b, int alpha) { invoke<Void>(0xF5ABA1A2EE468266, x1, y1, z1, x2, y2, z2, x3, y3, z3, r, g, b, alpha); } // 0xF5ABA1A2EE468266 0xABD19253
	static void DRAW_BOX(float x1, float y1, float z1, float x2, float y2, float z2, int r, int g, int b, int alpha) { invoke<Void>(0xC2B5072ED00F45E0, x1, y1, z1, x2, y2, z2, r, g, b, alpha); } // 0xC2B5072ED00F45E0 0xCD4D9DD5
	static void _0x8CBE51172359EB97(BOOL p0) { invoke<Void>(0x8CBE51172359EB97, p0); } // 0x8CBE51172359EB97 0xC44C2F44
	static Any _0xF61C9F59CC4873C6() { return invoke<Any>(0xF61C9F59CC4873C6); } // 0xF61C9F59CC4873C6 0xBA9AD458
	static Any _0xED6D7B4C99CC3572() { return invoke<Any>(0xED6D7B4C99CC3572); } // 0xED6D7B4C99CC3572 0xADBBA287
	static void _0x937888DD0ED2FEAD() { invoke<Void>(0x937888DD0ED2FEAD); } // 0x937888DD0ED2FEAD 0x9E553002
	static BOOL _0x91BCC114595D65EF(Any* p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0x91BCC114595D65EF, p0, p1, p2, p3); } // 0x91BCC114595D65EF 0x56C1E488
	static int _0xE11B6BE9AD42541A(Any* p0) { return invoke<int>(0xE11B6BE9AD42541A, p0); } // 0xE11B6BE9AD42541A 0x226B08EA
	static Any _0x3A631A03BB656B99() { return invoke<Any>(0x3A631A03BB656B99); } // 0x3A631A03BB656B99 0x1F3CADB0
	static Any _0xE21C3B31C91880AE() { return invoke<Any>(0xE21C3B31C91880AE); } // 0xE21C3B31C91880AE 0xA9DC8558
	static void _0x582A5956069F0834() { invoke<Void>(0x582A5956069F0834); } // 0x582A5956069F0834 0x88EAF398
	static Any _0x874B2B64F2CA22D2() { return invoke<Any>(0x874B2B64F2CA22D2); } // 0x874B2B64F2CA22D2 0x47B0C137
	static Any _0xB1D7EAE561FB3C6A() { return invoke<Any>(0xB1D7EAE561FB3C6A); } // 0xB1D7EAE561FB3C6A 0x65376C9B
	static void _0x1DD8BA0EFD3C15DB() { invoke<Void>(0x1DD8BA0EFD3C15DB); } // 0x1DD8BA0EFD3C15DB 0x9CBA682A
	static void _0x05A3B29B72C03030(BOOL p0) { invoke<Void>(0x05A3B29B72C03030, p0); } // 0x05A3B29B72C03030
	static Any _0xCD4C80B118D3EF70(int p0) { return invoke<Any>(0xCD4C80B118D3EF70, p0); } // 0xCD4C80B118D3EF70 0x3B15D33C
	static Any _0xB7979BC2AF63EC34() { return invoke<Any>(0xB7979BC2AF63EC34); } // 0xB7979BC2AF63EC34 0xEC5D0317
	static BOOL _0x7F35BC023364609F(Any p0) { return invoke<BOOL>(0x7F35BC023364609F, p0); } // 0x7F35BC023364609F 0x25D569EB
	static Any _0x8331D2A49F434D1A(Any p0) { return invoke<Any>(0x8331D2A49F434D1A, p0); } // 0x8331D2A49F434D1A 0xCFCDC518
	static void _0xE6AE9213B5C9CC57() { invoke<Void>(0xE6AE9213B5C9CC57); } // 0xE6AE9213B5C9CC57 0x108F36CC
	static void _0x3B74F775E3152331(BOOL p0, BOOL p1) { invoke<Void>(0x3B74F775E3152331, p0, p1); } // 0x3B74F775E3152331 0xE9F2B68F
	static int GET_MAXIMUM_NUMBER_OF_PHOTOS() { return invoke<int>(0xE1E7B008DD523E21); } // 0xE1E7B008DD523E21 0x727AA63F
	static Any _0x3440CECCDD2E858C() { return invoke<Any>(0x3440CECCDD2E858C); } // 0x3440CECCDD2E858C 0x239272BD
	static Any _0x43D8A0731E72FA43() { return invoke<Any>(0x43D8A0731E72FA43); } // 0x43D8A0731E72FA43 0x21DBF0C9
	static Any _0x4DC9345F61161BC6(Any p0) { return invoke<Any>(0x4DC9345F61161BC6, p0); } // 0x4DC9345F61161BC6 0x199FABF0
	static Any _0x84CF4F3B0C6CB3D3(Any p0) { return invoke<Any>(0x84CF4F3B0C6CB3D3, p0); } // 0x84CF4F3B0C6CB3D3 0x596B900D
	static void _0x6088BF5438A2766D() { invoke<Void>(0x6088BF5438A2766D); } // 0x6088BF5438A2766D 0xC9EF81ED
	static Any _0x809091B9FA64B36F(Any p0) { return invoke<Any>(0x809091B9FA64B36F, p0); } // 0x809091B9FA64B36F 0x9D84554C
	static Any _0xE8555138DA097E74(Any p0) { return invoke<Any>(0xE8555138DA097E74, p0); } // 0xE8555138DA097E74 0x9C106AD9
	static Any _0xC074B95B9528FD99(Any p0) { return invoke<Any>(0xC074B95B9528FD99, p0); } // 0xC074B95B9528FD99 0x762E5C5F
	static void _DRAW_LIGHT_WITH_RANGE_AND_SHADOW(float x, float y, float z, int r, int g, int b, float range, float intensity, float shadow) { invoke<Void>(0x7A5CF0756298D2D3, x, y, z, r, g, b, range, intensity, shadow); } // 0x7A5CF0756298D2D3
	static void DRAW_LIGHT_WITH_RANGE(float posX, float posY, float posZ, int colorR, int colorG, int colorB, float range, float intensity) { invoke<Void>(0x5615D10F62370A67, posX, posY, posZ, colorR, colorG, colorB, range, intensity); } // 0x5615D10F62370A67 0x6A396E9A
	static void DRAW_SPOT_LIGHT(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, int colorR, int colorG, int colorB, float distance, float brightness, float roundness, float radius, float falloff) { invoke<Void>(0xAC54AB627C280EFD, posX, posY, posZ, dirX, dirY, dirZ, colorR, colorG, colorB, distance, brightness, roundness, radius, falloff); } // 0xAC54AB627C280EFD 0xBDBC410C
	static void _DRAW_SPOT_LIGHT_WITH_SHADOW(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, int colorR, int colorG, int colorB, float distance, float brightness, float roundness, float radius, float falloff, float shadow) { invoke<Void>(0x9241CEB4BE0DB31B, posX, posY, posZ, dirX, dirY, dirZ, colorR, colorG, colorB, distance, brightness, roundness, radius, falloff, shadow); } // 0x9241CEB4BE0DB31B 0x32BF9598
	static void _0xAF66F5C656A1CE55(float p0) { invoke<Void>(0xAF66F5C656A1CE55, p0); } // 0xAF66F5C656A1CE55 0x93628786
	static void _0xF566238EF331DC9E(Object object) { invoke<Void>(0xF566238EF331DC9E, object); } // 0xF566238EF331DC9E
	static void DRAW_MARKER(int type, float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ, int colorR, int colorG, int colorB, int alpha, BOOL bobUpAndDown, BOOL faceCamera, int p19, BOOL rotate, char* textureDict, char* textureName, BOOL drawOnEnts) { invoke<Void>(0x3B4F927A1836BD27, type, posX, posY, posZ, dirX, dirY, dirZ, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, colorR, colorG, colorB, alpha, bobUpAndDown, faceCamera, p19, rotate, textureDict, textureName, drawOnEnts); } // 0x3B4F927A1836BD27 0x48D84A02
	static int CREATE_CHECKPOINT(int type, float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2, float radius, int colorR, int colorG, int colorB, int alpha, int reserved) { return invoke<int>(0xACBA4B0C2977A2C7, type, posX1, posY1, posZ1, posX2, posY2, posZ2, radius, colorR, colorG, colorB, alpha, reserved); } // 0xACBA4B0C2977A2C7 0xF541B690
	static void _0x4024D05309197860(int checkpoint, float p0) { invoke<Void>(0x4024D05309197860, checkpoint, p0); } // 0x4024D05309197860 0x80151CCF
	static void SET_CHECKPOINT_CYLINDER_HEIGHT(int checkpoint, float nearHeight, float farHeight, float radius) { invoke<Void>(0x1467292A2098C34E, checkpoint, nearHeight, farHeight, radius); } // 0x1467292A2098C34E 0xFF0F9B22
	static void SET_CHECKPOINT_RGBA(int checkpoint, int r, int g, int b, int alpha) { invoke<Void>(0xA22864F9452216C0, checkpoint, r, g, b, alpha); } // 0xA22864F9452216C0 0xEF9C8CB3
	static void _SET_CHECKPOINT_ICON_RGBA(int checkpoint, int r, int g, int b, int alpha) { invoke<Void>(0x4A249F318F39C3D5, checkpoint, r, g, b, alpha); } // 0x4A249F318F39C3D5 0xA5456DBB
	static void _0x85342AFC4B4324A1(int checkpoint, float posX, float posY, float posZ, float unkX, float unkY, float unkZ) { invoke<Void>(0x85342AFC4B4324A1, checkpoint, posX, posY, posZ, unkX, unkY, unkZ); } // 0x85342AFC4B4324A1 0x20EABD0F
	static void _0x920B22D243B2D315(int checkpoint) { invoke<Void>(0x920B22D243B2D315, checkpoint); } // 0x920B22D243B2D315 0x1E3A3126
	static void DELETE_CHECKPOINT(int checkpoint) { invoke<Void>(0xCD9B3CC980D9A08F, checkpoint); } // 0xCD9B3CC980D9A08F 0xB66CF3CA
	static void _0xF28AB1024B01E661(BOOL p0) { invoke<Void>(0xF28AB1024B01E661, p0); } // 0xF28AB1024B01E661 0x932FDB81
	static void _0xCC1B5BB8EF3906BF(BOOL p0) { invoke<Void>(0xCC1B5BB8EF3906BF, p0); } // 0xCC1B5BB8EF3906BF 0x7E946E87
	static void REQUEST_STREAMED_TEXTURE_DICT(char* textureDict, BOOL p1) { invoke<Void>(0xA6AD245AF4469018, textureDict, p1); } // 0xA6AD245AF4469018 0x4C9B035F
	static BOOL HAS_STREAMED_TEXTURE_DICT_LOADED(char* textureDict) { return invoke<BOOL>(0xE0B615EF03FE4422, textureDict); } // 0xE0B615EF03FE4422 0x3F436EEF
	static void SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED(char* textureDict) { invoke<Void>(0xC07032666ADF86BE, textureDict); } // 0xC07032666ADF86BE 0xF07DDA38
	static void DRAW_RECT(float x, float y, float width, float height, int r, int g, int b, int a) { invoke<Void>(0x2F8697C8670CAD58, x, y, width, height, r, g, b, a); } // 0x2F8697C8670CAD58 0xDD2BFC77
	static void _0xF9B73D09E3ADD73F(BOOL p0) { invoke<Void>(0xF9B73D09E3ADD73F, p0); } // 0xF9B73D09E3ADD73F 0xF8FBCC25
	static void _SET_2D_LAYER(int layer) { invoke<Void>(0x4ED9ECF3735CB826, layer); } // 0x4ED9ECF3735CB826 0xADF81D24
	static void _SET_SCREEN_DRAW_POSITION(int x, int y) { invoke<Void>(0x4933838CDEC9827A, x, y); } // 0x4933838CDEC9827A 0x228A2598
	static void _SCREEN_DRAW_POSITION_END() { invoke<Void>(0x526D61ADDDE6C626); } // 0x526D61ADDDE6C626 0x3FE33BD6
	static void _SCREEN_DRAW_POSITION_RATIO(float x, float y, float p2, float p3) { invoke<Void>(0x28611CDA71EBBA91, x, y, p2, p3); } // 0x28611CDA71EBBA91 0x76C641E4
	static void _0xD1CB8E7D5D255D7C(float p0, float p1, Any* p2, Any* p3) { invoke<Void>(0xD1CB8E7D5D255D7C, p0, p1, p2, p3); } // 0xD1CB8E7D5D255D7C
	static float GET_SAFE_ZONE_SIZE() { return invoke<float>(0x8B0C15BA8FEAA03A); } // 0x8B0C15BA8FEAA03A 0x3F0D1A6F
	static void DRAW_SPRITE(char* textureDict, char* textureName, float screenX, float screenY, float scaleX, float scaleY, float heading, int colorR, int colorG, int colorB, int alpha) { invoke<Void>(0x67972FF1523F6D32, textureDict, textureName, screenX, screenY, scaleX, scaleY, heading, colorR, colorG, colorB, alpha); } // 0x67972FF1523F6D32 0x1FEC16B0
	static Any ADD_ENTITY_ICON(Entity entity, char* icon) { return invoke<Any>(0xA5007ADA95B1BD42, entity, icon); } // 0xA5007ADA95B1BD42 0xF3027D21
	static void SET_ENTITY_ICON_VISIBILITY(Entity entity, BOOL toggle) { invoke<Void>(0x4D778BEA53370919, entity, toggle); } // 0x4D778BEA53370919 0xD1D2FD52
	static void SET_ENTITY_ICON_COLOR(Entity entity, int r, int g, int b, int alpha) { invoke<Void>(0x1459A78CFF9E5FAD, entity, r, g, b, alpha); } // 0x1459A78CFF9E5FAD 0x6EE1E946
	static void SET_DRAW_ORIGIN(float x, float y, float z, Any p3) { invoke<Void>(0x20FF23F2DFFBE847, x, y, z, p3); } // 0x20FF23F2DFFBE847 0xE10198D5
	static void CLEAR_DRAW_ORIGIN() { invoke<Void>(0x5D8751C94099E693); } // 0x5D8751C94099E693 0xDD76B263
	static void ATTACH_TV_AUDIO_TO_ENTITY(Entity entity) { invoke<Void>(0xB99455420C96DB94, entity); } // 0xB99455420C96DB94 0x784944DB
	static void SET_TV_AUDIO_FRONTEND(BOOL toggle) { invoke<Void>(0x8210D21498E02183, toggle); } // 0x8210D21498E02183 0x2E0DFA35
	static int LOAD_MOVIE_MESH_SET(char* movieMeshSetName) { return invoke<int>(0x58D6221B40F3564B, movieMeshSetName); } // 0x58D6221B40F3564B 0x9627905C
	static void RELEASE_MOVIE_MESH_SET(int movieMeshSet) { invoke<Void>(0x507F00555A0A0C5A, movieMeshSet); } // 0x507F00555A0A0C5A 0x4FA5501D
	static Any _0xC6519B8D42C0F62C(Any p0) { return invoke<Any>(0xC6519B8D42C0F62C, p0); } // 0xC6519B8D42C0F62C 0x9D5D9B38
	static void GET_SCREEN_RESOLUTION(int* x, int* y) { invoke<Void>(0xFCD5E0181ABDD64D, x, y); } // 0xFCD5E0181ABDD64D 0x29F3572F
	static void _GET_SCREEN_ACTIVE_RESOLUTION(int* x, int* y) { invoke<Void>(0xC00B89C485A069D9, x, y); } // 0xC00B89C485A069D9
	static float _GET_SCREEN_ASPECT_RATIO(BOOL b) { return invoke<float>(0x73E1DAE2E39E5E52, b); } // 0x73E1DAE2E39E5E52
	static Any _0x7CABD0D1B565661A() { return invoke<Any>(0x7CABD0D1B565661A); } // 0x7CABD0D1B565661A
	static BOOL GET_IS_WIDESCREEN() { return invoke<BOOL>(0x4FF5482BE67FE954); } // 0x4FF5482BE67FE954 0xEC717AEF
	static BOOL GET_IS_HIDEF() { return invoke<BOOL>(0x8D2F3225653CAD77); } // 0x8D2F3225653CAD77 0x1C340359
	static void _0x948C26C24088782C() { invoke<Void>(0x948C26C24088782C); } // 0x948C26C24088782C
	static void SET_NIGHTVISION(BOOL toggle) { invoke<Void>(0xAB88A452C6AD864F, toggle); } // 0xAB88A452C6AD864F 0xD1E5565F
	static Any _0x14F1D080F5A6B200() { return invoke<Any>(0x14F1D080F5A6B200); } // 0x14F1D080F5A6B200
	static BOOL _IS_NIGHTVISION_INACTIVE() { return invoke<BOOL>(0xC06793848501358C); } // 0xC06793848501358C 0x62619061
	static void _0x0D41FEEAFA1A94AD(BOOL p0) { invoke<Void>(0x0D41FEEAFA1A94AD, p0); } // 0x0D41FEEAFA1A94AD
	static void SET_NOISEOVERIDE(BOOL toggle) { invoke<Void>(0x14E50ABE9E7ACFD8, toggle); } // 0x14E50ABE9E7ACFD8 0xD576F5DD
	static void SET_NOISINESSOVERIDE(float value) { invoke<Void>(0x1B25F8904FC1D2AB, value); } // 0x1B25F8904FC1D2AB 0x046B62D9
	static BOOL _WORLD3D_TO_SCREEN2D(float worldX, float worldY, float worldZ, float* screenX, float* screenY) { return invoke<BOOL>(0x28FABF021DDC68FC, worldX, worldY, worldZ, screenX, screenY); } // 0x28FABF021DDC68FC 0x1F950E4B
	static Vector3 GET_TEXTURE_RESOLUTION(char* textureDict, char* textureName) { return invoke<Vector3>(0xD52DED36C2D0B48F, textureDict, textureName); } // 0xD52DED36C2D0B48F 0x096DAA4D
	static void _0xE4CE4C51113A230D(float p0) { invoke<Void>(0xE4CE4C51113A230D, p0); } // 0xE4CE4C51113A230D 0x455F1084
	static void SET_FLASH(float p0, float p1, float fadeIn, float duration, float fadeOut) { invoke<Void>(0x0D3EF5F050CAB83D, p0, p1, fadeIn, duration, fadeOut); } // 0x0D3EF5F050CAB83D 0x7E55A1EE
	static void _0xA0A68AD6EC98D97D() { invoke<Void>(0xA0A68AD6EC98D97D); } // 0xA0A68AD6EC98D97D 0x0DCC0B8B
	static void _SET_BLACKOUT(BOOL enable) { invoke<Void>(0x6F8193B1DED7D644, enable); } // 0x6F8193B1DED7D644 0xAA2A0EAF
	static void _0x6AFE871C19459724() { invoke<Void>(0x6AFE871C19459724); } // 0x6AFE871C19459724
	static Object CREATE_TRACKED_POINT() { return invoke<Object>(0x7A456A99AC4F2040); } // 0x7A456A99AC4F2040 0x3129C31A
	static void SET_TRACKED_POINT_INFO(Object point, float x, float y, float z, float radius) { invoke<Void>(0x27F79F27E6E89D72, point, x, y, z, radius); } // 0x27F79F27E6E89D72 0x28689AA4
	static BOOL IS_TRACKED_POINT_VISIBLE(Object point) { return invoke<BOOL>(0x6207D42480BD9095, point); } // 0x6207D42480BD9095 0x0BFC4F64
	static void DESTROY_TRACKED_POINT(Object point) { invoke<Void>(0x0C866C514CD4D17A, point); } // 0x0C866C514CD4D17A 0x14AC675F
	static Any _0xA09DB663CB40B194(Any p0, Any p1, Any p2, Any p3) { return invoke<Any>(0xA09DB663CB40B194, p0, p1, p2, p3); } // 0xA09DB663CB40B194
	static void _0x8597BFF61DA39505(Any p0) { invoke<Void>(0x8597BFF61DA39505, p0); } // 0x8597BFF61DA39505
	static void _0x9ED516719916B1C1(Any p0, float p1, float p2, float p3, float p4) { invoke<Void>(0x9ED516719916B1C1, p0, p1, p2, p3, p4); } // 0x9ED516719916B1C1
	static void _0x5CF685F79A45F774(Any p0) { invoke<Void>(0x5CF685F79A45F774, p0); } // 0x5CF685F79A45F774
	static Any _0x25BCCA5F938848BC(Any p0) { return invoke<Any>(0x25BCCA5F938848BC, p0); } // 0x25BCCA5F938848BC
	static void _0x59797E2F09F32B6B() { invoke<Void>(0x59797E2F09F32B6B); } // 0x59797E2F09F32B6B
	static void _0xF5665FEB498B1291() { invoke<Void>(0xF5665FEB498B1291); } // 0xF5665FEB498B1291
	static void _0xCEA8520C7CB4711B() { invoke<Void>(0xCEA8520C7CB4711B); } // 0xCEA8520C7CB4711B
	static void _0xA2D894C3F351995E() { invoke<Void>(0xA2D894C3F351995E); } // 0xA2D894C3F351995E
	static void _0xAFEB47935B76CFAF(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<Void>(0xAFEB47935B76CFAF, p0, p1, p2, p3, p4, p5, p6); } // 0xAFEB47935B76CFAF
	static void _0x6902757D904D139A() { invoke<Void>(0x6902757D904D139A); } // 0x6902757D904D139A
	static void _0x093227ED19D84FB6() { invoke<Void>(0x093227ED19D84FB6); } // 0x093227ED19D84FB6 0x48F16186
	static void _0xE10F130989A9CCD3(Any p0, BOOL p1, float p2, float p3, float p4, float p5, BOOL p6, float p7) { invoke<Void>(0xE10F130989A9CCD3, p0, p1, p2, p3, p4, p5, p6, p7); } // 0xE10F130989A9CCD3
	static void _0xFB4E8E1D83CD0857(float p0) { invoke<Void>(0xFB4E8E1D83CD0857, p0); } // 0xFB4E8E1D83CD0857 0x13D4ABC0
	static void _0xB18F56CDDEED619A(float p0) { invoke<Void>(0xB18F56CDDEED619A, p0); } // 0xB18F56CDDEED619A 0xD2157428
	static void _0xD66854E41AE29B4D(float p0) { invoke<Void>(0xD66854E41AE29B4D, p0); } // 0xD66854E41AE29B4D 0xC07C64C9
	static void _SET_FAR_SHADOWS_SUPPRESSED(BOOL toggle) { invoke<Void>(0xBFF7E87106CE7475, toggle); } // 0xBFF7E87106CE7475 0xFE903D0F
	static void _0xE21EFBCE3E025BD4(BOOL p0) { invoke<Void>(0xE21EFBCE3E025BD4, p0); } // 0xE21EFBCE3E025BD4
	static void _0xE4F2005AD56BDBF5(char* p0) { invoke<Void>(0xE4F2005AD56BDBF5, p0); } // 0xE4F2005AD56BDBF5 0xDE10BA1F
	static void _0x1BA3A3C8BC543F83() { invoke<Void>(0x1BA3A3C8BC543F83); } // 0x1BA3A3C8BC543F83
	static void _0xDB63234121DEA9AF(BOOL p0) { invoke<Void>(0xDB63234121DEA9AF, p0); } // 0xDB63234121DEA9AF 0x9F470BE3
	static void _0xDAB7EC0473A3C703(BOOL p0) { invoke<Void>(0xDAB7EC0473A3C703, p0); } // 0xDAB7EC0473A3C703 0x4A124267
	static void _0x78B451BFE118862F(float p0) { invoke<Void>(0x78B451BFE118862F, p0); } // 0x78B451BFE118862F 0xB19B2764
	static void _0xD7EEEA0C84E87998(BOOL p0) { invoke<Void>(0xD7EEEA0C84E87998, p0); } // 0xD7EEEA0C84E87998 0x342FA2B4
	static void _0x72C402070ABBBD7C(BOOL p0) { invoke<Void>(0x72C402070ABBBD7C, p0); } // 0x72C402070ABBBD7C 0x5D3BFFC9
	static void _0x7494DDCFD7BDE67C(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, BOOL p8) { invoke<Void>(0x7494DDCFD7BDE67C, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x7494DDCFD7BDE67C 0xD9653728
	static void _0x706373F5A32E70F1(float p0, float p1, float p2) { invoke<Void>(0x706373F5A32E70F1, p0, p1, p2); } // 0x706373F5A32E70F1 0x72BA8A14
	static void _0x890BCDB35E43CD8A(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11) { invoke<Void>(0x890BCDB35E43CD8A, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x890BCDB35E43CD8A 0x804F444C
	static void _0xC49F6C3D99E8F78E(Any p0, Any p1) { invoke<Void>(0xC49F6C3D99E8F78E, p0, p1); } // 0xC49F6C3D99E8F78E 0xBB1A1294
	static void _0xBA92C8A863323B3E(BOOL p0) { invoke<Void>(0xBA92C8A863323B3E, p0); } // 0xBA92C8A863323B3E 0x1A1A72EF
	static void _0x5ED07D900A89DF68(int type, float xPos, float yPos, float zPos, float p4, int r, int g, int b, int alpha) { invoke<Void>(0x5ED07D900A89DF68, type, xPos, yPos, zPos, p4, r, g, b, alpha); } // 0x5ED07D900A89DF68 0x3BB12B75
	static void _0x5AAE671B31D1C7CC(float p0, float p1, float p2, float p3, float p4) { invoke<Void>(0x5AAE671B31D1C7CC, p0, p1, p2, p3, p4); } // 0x5AAE671B31D1C7CC 0x4EA70FB4
	static void _0xD93400045D75037D(BOOL p0) { invoke<Void>(0xD93400045D75037D, p0); } // 0xD93400045D75037D 0x0D830DC7
	static Any _0xD11088FC2815E409() { return invoke<Any>(0xD11088FC2815E409); } // 0xD11088FC2815E409 0xA08B46AD
	static Vector3 _0xC491913DE62A8601(Any p0) { return invoke<Vector3>(0xC491913DE62A8601, p0); } // 0xC491913DE62A8601 0xECD470F0
	static void SET_SEETHROUGH(BOOL toggle) { invoke<Void>(0xF9E14C8487A7A1FF, toggle); } // 0xF9E14C8487A7A1FF 0x74D4995C
	static BOOL _IS_SEETHROUGH_ACTIVE() { return invoke<BOOL>(0xCFBB7AD6A371BF38); } // 0xCFBB7AD6A371BF38 0x1FE547F2
	static void _0x3AE926ECBC88F827(Any p0, float p1) { invoke<Void>(0x3AE926ECBC88F827, p0, p1); } // 0x3AE926ECBC88F827 0x654F0287
	static void _0xBF3CED2D9E6F0108(float p0) { invoke<Void>(0xBF3CED2D9E6F0108, p0); } // 0xBF3CED2D9E6F0108 0xF6B837F0
	static Any _0x438D4B372FD30D9F() { return invoke<Any>(0x438D4B372FD30D9F); } // 0x438D4B372FD30D9F 0xD906A3A9
	static void _0x4C3121AB93A66DF7(BOOL p0) { invoke<Void>(0x4C3121AB93A66DF7, p0); } // 0x4C3121AB93A66DF7 0xD34A6CBA
	static void _0xD3231CAA928D3149(Any p0) { invoke<Void>(0xD3231CAA928D3149, p0); } // 0xD3231CAA928D3149 0xD8CC7221
	static BOOL _TRANSITION_TO_BLURRED(float transitionTime) { return invoke<BOOL>(0xFBBB74B74690D793, transitionTime); } // 0xFBBB74B74690D793 0x5604B890
	static BOOL _TRANSITION_FROM_BLURRED(float transitionTime) { return invoke<BOOL>(0xFE35776313BCD71F, transitionTime); } // 0xFE35776313BCD71F 0x46617502
	static void _0xFEB52AE389FE28F5() { invoke<Void>(0xFEB52AE389FE28F5); } // 0xFEB52AE389FE28F5 0xDB7AECDA
	static float IS_PARTICLE_FX_DELAYED_BLINK() { return invoke<float>(0xDDD0537061E9A9FF); } // 0xDDD0537061E9A9FF 0xEA432A94
	static Any _0xAE1751DD9B43D155() { return invoke<Any>(0xAE1751DD9B43D155); } // 0xAE1751DD9B43D155 0x926B8734
	static void _SET_FROZEN_RENDERING_DISABLED(BOOL enabled) { invoke<Void>(0x0AB69FD0C563FF2E, enabled); } // 0x0AB69FD0C563FF2E 0x30ADE541
	static Any _0x75A8BFAE880F5884() { return invoke<Any>(0x75A8BFAE880F5884); } // 0x75A8BFAE880F5884
	static void _0xDAF0B721D78E3FDD() { invoke<Void>(0xDAF0B721D78E3FDD); } // 0xDAF0B721D78E3FDD 0x0113EAE4
	static void _0x4964AE7FAD34AF63() { invoke<Void>(0x4964AE7FAD34AF63); } // 0x4964AE7FAD34AF63 0xDCBA251B
	static void _0x11C708C15FD22E1A(BOOL p0, BOOL p1, float p2, float p3, float p4, float p5) { invoke<Void>(0x11C708C15FD22E1A, p0, p1, p2, p3, p4, p5); } // 0x11C708C15FD22E1A 0x513D444B
	static BOOL _0x1D24E4EE14E45829(BOOL p0) { return invoke<BOOL>(0x1D24E4EE14E45829, p0); } // 0x1D24E4EE14E45829 0xB2410EAB
	static Any _0x7EBC0D12B8F1FC9E() { return invoke<Any>(0x7EBC0D12B8F1FC9E); } // 0x7EBC0D12B8F1FC9E 0x5AB94128
	static BOOL _0x87F887F297700AFC(char* textureDict, BOOL p1) { return invoke<BOOL>(0x87F887F297700AFC, textureDict, p1); } // 0x87F887F297700AFC 0xD63FCB3E
	static BOOL START_PARTICLE_FX_NON_LOOPED_AT_COORD(char* effectName, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, float scale, BOOL xAxis, BOOL yAxis, BOOL zAxis) { return invoke<BOOL>(0x289A9D382EC2E2FA, effectName, xPos, yPos, zPos, xRot, yRot, zRot, scale, xAxis, yAxis, zAxis); } // 0x289A9D382EC2E2FA 0xDD79D679
	static BOOL _START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(char* effectName, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, float scale, BOOL xAxis, BOOL yAxis, BOOL zAxis) { return invoke<BOOL>(0xBD26979A7FC5E356, effectName, xPos, yPos, zPos, xRot, yRot, zRot, scale, xAxis, yAxis, zAxis); } // 0xBD26979A7FC5E356 0x633F8C48
	static BOOL START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE(char* effectName, Ped ped, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ, int boneIndex, float scale, BOOL axisX, BOOL axisY, BOOL axisZ) { return invoke<BOOL>(0x41C8593C7D020660, effectName, ped, offsetX, offsetY, offsetZ, rotX, rotY, rotZ, boneIndex, scale, axisX, axisY, axisZ); } // 0x41C8593C7D020660 0x53DAEF4E
	static BOOL _START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(char* effectName, Ped ped, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ, int boneIndex, float scale, BOOL axisX, BOOL axisY, BOOL axisZ) { return invoke<BOOL>(0x37C67309340327C0, effectName, ped, offsetX, offsetY, offsetZ, rotX, rotY, rotZ, boneIndex, scale, axisX, axisY, axisZ); } // 0x37C67309340327C0 0x161780C1
	static BOOL START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(char* effectName, Entity entity, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ, float scale, BOOL axisX, BOOL axisY, BOOL axisZ) { return invoke<BOOL>(0xD5DF168F17272A98, effectName, entity, offsetX, offsetY, offsetZ, rotX, rotY, rotZ, scale, axisX, axisY, axisZ); } // 0xD5DF168F17272A98 0x9604DAD4
	static BOOL _START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2(char* effectName, Entity entity, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ, float scale, BOOL axisX, BOOL axisY, BOOL axisZ) { return invoke<BOOL>(0xBFAA02243BCCD0DB, effectName, entity, offsetX, offsetY, offsetZ, rotX, rotY, rotZ, scale, axisX, axisY, axisZ); } // 0xBFAA02243BCCD0DB
	static void SET_PARTICLE_FX_NON_LOOPED_COLOUR(float r, float g, float b) { invoke<Void>(0x9C7645FFD9900B86, r, g, b); } // 0x9C7645FFD9900B86 0x7B689E20
	static void SET_PARTICLE_FX_NON_LOOPED_ALPHA(float alpha) { invoke<Void>(0xAAFA0D937D78F630, alpha); } // 0xAAFA0D937D78F630 0x497EAFF2
	static void _0x6D2CAEBCEB5EB991(BOOL p0) { invoke<Void>(0x6D2CAEBCEB5EB991, p0); } // 0x6D2CAEBCEB5EB991
	static int START_PARTICLE_FX_LOOPED_AT_COORD(char* effectName, float x, float y, float z, float xRot, float yRot, float zRot, float scale, BOOL xAxis, BOOL yAxis, BOOL zAxis, BOOL p11) { return invoke<int>(0x759E422F846BA6EC, effectName, x, y, z, xRot, yRot, zRot, scale, xAxis, yAxis, zAxis, p11); } // 0x759E422F846BA6EC 0xD348E3E6
	static int START_PARTICLE_FX_LOOPED_ON_PED_BONE(char* effectName, Ped ped, float xOffset, float yOffset, float zOffset, float xRot, float yRot, float zRot, int boneIndex, float scale, BOOL xAxis, BOOL yAxis, BOOL zAxis) { return invoke<int>(0xC6CEE656725431D1, effectName, ped, xOffset, yOffset, zOffset, xRot, yRot, zRot, boneIndex, scale, xAxis, yAxis, zAxis); } // 0xC6CEE656725431D1 0xF8FC196F
	static int START_PARTICLE_FX_LOOPED_ON_ENTITY(char* effectName, Entity entity, float xOffset, float yOffset, float zOffset, float xRot, float yRot, float zRot, float scale, BOOL xAxis, BOOL yAxis, BOOL zAxis) { return invoke<int>(0x4281F7DFB73874A8, effectName, entity, xOffset, yOffset, zOffset, xRot, yRot, zRot, scale, xAxis, yAxis, zAxis); } // 0x4281F7DFB73874A8 0x0D06FF62
	static int _START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE(char* effectName, Entity entity, float xOffset, float yOffset, float zOffset, float xRot, float yRot, float zRot, int boneIndex, float scale, BOOL xAxis, BOOL yAxis, BOOL zAxis) { return invoke<int>(0xC26F9CDF8910A52E, effectName, entity, xOffset, yOffset, zOffset, xRot, yRot, zRot, boneIndex, scale, xAxis, yAxis, zAxis); } // 0xC26F9CDF8910A52E
	static int _START_PARTICLE_FX_LOOPED_ON_ENTITY_2(char* effectName, Entity entity, float xOffset, float yOffset, float zOffset, float xRot, float yRot, float zRot, float scale, BOOL xAxis, BOOL yAxis, BOOL zAxis) { return invoke<int>(0xF8CED496994FDB7C, effectName, entity, xOffset, yOffset, zOffset, xRot, yRot, zRot, scale, xAxis, yAxis, zAxis); } // 0xF8CED496994FDB7C 0x110752B2
	static int _START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(char* effectName, Entity entity, float xOffset, float yOffset, float zOffset, float xRot, float yRot, float zRot, int boneIndex, float scale, BOOL xAxis, BOOL yAxis, BOOL zAxis) { return invoke<int>(0xEAB2A9346EED6163, effectName, entity, xOffset, yOffset, zOffset, xRot, yRot, zRot, boneIndex, scale, xAxis, yAxis, zAxis); } // 0xEAB2A9346EED6163
	static void STOP_PARTICLE_FX_LOOPED(int ptfxHandle, BOOL p1) { invoke<Void>(0x0A977DD607DA1424, ptfxHandle, p1); } // 0x0A977DD607DA1424 0xD245455B
	static void REMOVE_PARTICLE_FX(int ptfxHandle, BOOL p1) { invoke<Void>(0x92AB494608DC00C8, ptfxHandle, p1); } // 0x92AB494608DC00C8 0x6BA48C7E
	static void REMOVE_PARTICLE_FX_FROM_ENTITY(Entity entity) { invoke<Void>(0x47AA80AE50CEA6BF, entity); } // 0x47AA80AE50CEA6BF 0xCEDE52E9
	static void REMOVE_PARTICLE_FX_IN_RANGE(float X, float Y, float Z, float radius) { invoke<Void>(0x38130BEB2174F958, X, Y, Z, radius); } // 0x38130BEB2174F958 0x7EB8F275
	static BOOL DOES_PARTICLE_FX_LOOPED_EXIST(int ptfxHandle) { return invoke<BOOL>(0x97F2912BC85D905D, ptfxHandle); } // 0x97F2912BC85D905D 0xCBF91D2A
	static void SET_PARTICLE_FX_LOOPED_OFFSETS(int ptfxHandle, float x, float y, float z, float rotX, float rotY, float rotZ) { invoke<Void>(0x081BF6C3FF2BB789, ptfxHandle, x, y, z, rotX, rotY, rotZ); } // 0x081BF6C3FF2BB789 0x641F7790
	static void SET_PARTICLE_FX_LOOPED_EVOLUTION(int ptfxHandle, char* propertyName, float amount, BOOL Id) { invoke<Void>(0xD8CBE19051DBD11C, ptfxHandle, propertyName, amount, Id); } // 0xD8CBE19051DBD11C 0x1CBC1373
	static void SET_PARTICLE_FX_LOOPED_COLOUR(int ptfxHandle, float r, float g, float b, BOOL p4) { invoke<Void>(0x56D6973347D1B7B0, ptfxHandle, r, g, b, p4); } // 0x56D6973347D1B7B0 0x5219D530
	static void SET_PARTICLE_FX_LOOPED_ALPHA(int ptfxHandle, float alpha) { invoke<Void>(0xFA6FE63FC98B8066, ptfxHandle, alpha); } // 0xFA6FE63FC98B8066 0x5ED49BE1
	static void SET_PARTICLE_FX_LOOPED_SCALE(int ptfxHandle, float scale) { invoke<Void>(0x6D8C337BB60F9DB2, ptfxHandle, scale); } // 0x6D8C337BB60F9DB2 0x099B8B49
	static void _SET_PARTICLE_FX_LOOPED_RANGE(int ptfxHandle, float range) { invoke<Void>(0xCE2F104F69ED5227, ptfxHandle, range); } // 0xCE2F104F69ED5227 0x233DE879
	static void SET_PARTICLE_FX_CAM_INSIDE_VEHICLE(BOOL p0) { invoke<Void>(0x383AAB2B9469769D, p0); } // 0x383AAB2B9469769D 0x19EC0001
	static void SET_PARTICLE_FX_CAM_INSIDE_NONPLAYER_VEHICLE(Any p0, BOOL p1) { invoke<Void>(0x244F6514022032E3, p0, p1); } // 0x244F6514022032E3 0x6B125A02
	static void SET_PARTICLE_FX_SHOOTOUT_BOAT(Any p0) { invoke<Void>(0xC8667D2F6404099D, p0); } // 0xC8667D2F6404099D 0xD938DEE0
	static void SET_PARTICLE_FX_BLOOD_SCALE(BOOL p0) { invoke<Void>(0x7B4BA24434CC7F4C, p0); } // 0x7B4BA24434CC7F4C 0x18136DE0
	static void ENABLE_CLOWN_BLOOD_VFX(BOOL toggle) { invoke<Void>(0xAC67712F610A4FD1, toggle); } // 0xAC67712F610A4FD1 0xC61C75E9
	static void ENABLE_ALIEN_BLOOD_VFX(BOOL toggle) { invoke<Void>(0x80A67076FC36B2A7, toggle); } // 0x80A67076FC36B2A7 0xCE8B8748
	static void _0x97C23C9B5634663E(float p0) { invoke<Void>(0x97C23C9B5634663E, p0); } // 0x97C23C9B5634663E
	static void _0xC833C05EFD27770E(float p0) { invoke<Void>(0xC833C05EFD27770E, p0); } // 0xC833C05EFD27770E
	static void _0x5B394142E5ADBF78(BOOL p0) { invoke<Void>(0x5B394142E5ADBF78, p0); } // 0x5B394142E5ADBF78
	static void _0xC7C48727C756C856(float p0) { invoke<Void>(0xC7C48727C756C856, p0); } // 0xC7C48727C756C856
	static void _0x2651446B80529630(float p0) { invoke<Void>(0x2651446B80529630, p0); } // 0x2651446B80529630
	static void _0xB38D8282832D6321(BOOL p0) { invoke<Void>(0xB38D8282832D6321, p0); } // 0xB38D8282832D6321
	static void _SET_PTFX_ASSET_NEXT_CALL(char* name) { invoke<Void>(0x6A8D4CCECC6DB79B, name); } // 0x6A8D4CCECC6DB79B 0x9C720B61
	static void _SET_PTFX_ASSET_OLD_TO_NEW(char* oldAsset, char* newAsset) { invoke<Void>(0xFFBD6F4B11799347, oldAsset, newAsset); } // 0xFFBD6F4B11799347
	static void _0x97E27997DACFB342(char* name) { invoke<Void>(0x97E27997DACFB342, name); } // 0x97E27997DACFB342
	static void _0x381B02E754E2697C(BOOL p0) { invoke<Void>(0x381B02E754E2697C, p0); } // 0x381B02E754E2697C
	static void _0x161FFCE801ABBFD8(float p0) { invoke<Void>(0x161FFCE801ABBFD8, p0); } // 0x161FFCE801ABBFD8
	static void WASH_DECALS_IN_RANGE(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x3C1435310E173165, p0, p1, p2, p3, p4); } // 0x3C1435310E173165 0xDEECBC57
	static void WASH_DECALS_FROM_VEHICLE(Vehicle vehicle, float p1) { invoke<Void>(0x3AAEFB58791F2099, vehicle, p1); } // 0x3AAEFB58791F2099 0x2929F11A
	static void FADE_DECALS_IN_RANGE(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x2478F071547F0C76, p0, p1, p2, p3, p4); } // 0x2478F071547F0C76 0xF81E884A
	static void REMOVE_DECALS_IN_RANGE(float x, float y, float z, float range) { invoke<Void>(0x794A3BB49F59DF31, x, y, z, range); } // 0x794A3BB49F59DF31 0x06A619A0
	static void REMOVE_DECALS_FROM_OBJECT(Object obj) { invoke<Void>(0x41202FE90D5D7A58, obj); } // 0x41202FE90D5D7A58 0x8B67DCA7
	static void REMOVE_DECALS_FROM_OBJECT_FACING(Object obj, float x, float y, float z) { invoke<Void>(0xD164EE105930AE0F, obj, x, y, z); } // 0xD164EE105930AE0F 0xF4999A55
	static void REMOVE_DECALS_FROM_VEHICLE(Vehicle vehicle) { invoke<Void>(0x9E1EB9A345B1B414, vehicle); } // 0x9E1EB9A345B1B414 0x831D06CA
	static int ADD_DECAL(Any p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10, float p11, float p12, float p13, float p14, float p15, float p16, BOOL p17, BOOL p18, BOOL p19) { return invoke<int>(0xCFDEE0C0A1CC1B2C, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19); } // 0xCFDEE0C0A1CC1B2C 0xEAD0C412
	static Any ADD_PETROL_DECAL(float x, float y, float z, float groundLvl, float width, float transparency) { return invoke<Any>(0x735E588E3E189B8C, x, y, z, groundLvl, width, transparency); } // 0x735E588E3E189B8C 0x1259DF42
	static void _0x09CBF03539F97883(float p0) { invoke<Void>(0x09CBF03539F97883, p0); } // 0x09CBF03539F97883 0xE3938B0B
	static void _0xD0D5392B79C2D304(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0xD0D5392B79C2D304, p0, p1, p2, p3); } // 0xD0D5392B79C2D304 0xBAEC6ADD
	static void _0xDFCFB4385E3BDC00() { invoke<Void>(0xDFCFB4385E3BDC00); } // 0xDFCFB4385E3BDC00 0xCCCA6855
	static void REMOVE_DECAL(int decal) { invoke<Void>(0x64B885DBCD9EBB95, decal); } // 0x64B885DBCD9EBB95 0xA4363188
	static BOOL IS_DECAL_ALIVE(int decal) { return invoke<BOOL>(0x79A1E82F1580C65D, decal); } // 0x79A1E82F1580C65D 0xCDD4A61A
	static float GET_DECAL_WASH_LEVEL(int decal) { return invoke<float>(0xB30AE29E3BDA3F16, decal); } // 0xB30AE29E3BDA3F16 0x054448EF
	static void _0x5957C9922BF60463() { invoke<Void>(0x5957C9922BF60463); } // 0x5957C9922BF60463 0xEAB6417C
	static void _0xEDCACB559C6622C5() { invoke<Void>(0xEDCACB559C6622C5); } // 0xEDCACB559C6622C5 0xC2703B88
	static void _0xD431A0A3284DCF06() { invoke<Void>(0xD431A0A3284DCF06); } // 0xD431A0A3284DCF06 0xA706E84D
	static BOOL _0x4952E54B6157C12A(float xCoord, float yCoord, float zCoord, float p3) { return invoke<BOOL>(0x4952E54B6157C12A, xCoord, yCoord, zCoord, p3); } // 0x4952E54B6157C12A 0x242C6A04
	static void _0xC839F6CC566B5CB4(Any p0, Any* p1, Any* p2) { invoke<Void>(0xC839F6CC566B5CB4, p0, p1, p2); } // 0xC839F6CC566B5CB4 0x335695CF
	static void _0xA19AED2202A21033(Any p0) { invoke<Void>(0xA19AED2202A21033, p0); } // 0xA19AED2202A21033 0x7B786555
	static void MOVE_VEHICLE_DECALS(Any p0, Any p1) { invoke<Void>(0x3B98E48002B4722F, p0, p1); } // 0x3B98E48002B4722F 0xCE9E6CF2
	static BOOL _ADD_CLAN_DECAL_TO_VEHICLE(Vehicle vehicle, Ped ped, int boneIndex, float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3, float scale, Any p13, int alpha) { return invoke<BOOL>(0x04BE71B102DE90ED, vehicle, ped, boneIndex, x1, x2, x3, y1, y2, y3, z1, z2, z3, scale, p13, alpha); } // 0x04BE71B102DE90ED 0x12077738
	static void _0x1BC899073DCB3338(Vehicle vehicle, Any p1) { invoke<Void>(0x1BC899073DCB3338, vehicle, p1); } // 0x1BC899073DCB3338 0x667046A8
	static int _0xCD96C3E3FD1C4BF4(Vehicle vehicle, Any p1) { return invoke<int>(0xCD96C3E3FD1C4BF4, vehicle, p1); } // 0xCD96C3E3FD1C4BF4 0x4F4D76E8
	static BOOL _DOES_VEHICLE_HAVE_DECAL(Vehicle vehicle, Any p1) { return invoke<BOOL>(0xA95FCE90BA930118, vehicle, p1); } // 0xA95FCE90BA930118 0x6D58F73B
	static void _0xE8CC1DD36CC919B0(BOOL p0) { invoke<Void>(0xE8CC1DD36CC919B0, p0); } // 0xE8CC1DD36CC919B0 0x9BABCBA4
	static void _0x1C982AECFC43993E(BOOL p0) { invoke<Void>(0x1C982AECFC43993E, p0); } // 0x1C982AECFC43993E 0xFDF6D8DA
	static void _0x1765168792D1FEF3(float p0) { invoke<Void>(0x1765168792D1FEF3, p0); } // 0x1765168792D1FEF3 0x2056A015
	static void _0xDADCAC617D045DE9(Any* p0) { invoke<Void>(0xDADCAC617D045DE9, p0); } // 0xDADCAC617D045DE9 0x0F486429
	static void _0xA7D361DF3CA9C241(float p0) { invoke<Void>(0xA7D361DF3CA9C241, p0); } // 0xA7D361DF3CA9C241 0xD87CC710
	static void _0xB5AEC0FD361E29BB() { invoke<Void>(0xB5AEC0FD361E29BB); } // 0xB5AEC0FD361E29BB 0xE29EE145
	static void _0x5B690205147148FA() { invoke<Void>(0x5B690205147148FA); } // 0x5B690205147148FA
	static void DISABLE_VEHICLE_DISTANTLIGHTS(BOOL toggle) { invoke<Void>(0xC722BCC3B094CAE4, toggle); } // 0xC722BCC3B094CAE4 0x7CFAE36F
	static void _0x26488665E9F1BEB4(BOOL p0) { invoke<Void>(0x26488665E9F1BEB4, p0); } // 0x26488665E9F1BEB4 0x60F72371
	static void _0x07BEB0407D190FF5() { invoke<Void>(0x07BEB0407D190FF5); } // 0x07BEB0407D190FF5
	static void _SET_FORCE_PED_FOOTSTEPS_TRACKS(BOOL toggle) { invoke<Void>(0xFBB3CC49F11946D1, toggle); } // 0xFBB3CC49F11946D1
	static void _SET_FORCE_VEHICLE_TRAILS(BOOL toggle) { invoke<Void>(0x332D41DFBF336C62, toggle); } // 0x332D41DFBF336C62
	static void _0x589EA31952E71E81(char* p0) { invoke<Void>(0x589EA31952E71E81, p0); } // 0x589EA31952E71E81
	static void SET_TIMECYCLE_MODIFIER(char* modifierName) { invoke<Void>(0x7B0FD4D19F705700, modifierName); } // 0x7B0FD4D19F705700 0xA81F3638
	static void SET_TIMECYCLE_MODIFIER_STRENGTH(float strength) { invoke<Void>(0x16DE2975B4A918BE, strength); } // 0x16DE2975B4A918BE 0x458F4F45
	static void SET_TRANSITION_TIMECYCLE_MODIFIER(char* modifierName, float transition) { invoke<Void>(0x4ED7770DC3C5EC4E, modifierName, transition); } // 0x4ED7770DC3C5EC4E 0xBB2BA72A
	static void _0x4A4DD903571631E7(float p0) { invoke<Void>(0x4A4DD903571631E7, p0); } // 0x4A4DD903571631E7 0x56345F6B
	static void CLEAR_TIMECYCLE_MODIFIER() { invoke<Void>(0xC1AB7E5821CAB578); } // 0xC1AB7E5821CAB578 0x8D8DF8EE
	static int GET_TIMECYCLE_MODIFIER_INDEX() { return invoke<int>(0xAE38B3AA7D13F9CE); } // 0xAE38B3AA7D13F9CE 0x594FEEC4
	static Any _0x2F149D71502DBBB8() { return invoke<Any>(0x2F149D71502DBBB8); } // 0x2F149D71502DBBB8 0x03C44E4B
	static void PUSH_TIMECYCLE_MODIFIER() { invoke<Void>(0x45DE8468B2F3B58D); } // 0x45DE8468B2F3B58D 0x7E082045
	static void POP_TIMECYCLE_MODIFIER() { invoke<Void>(0x9776C51F040F26BA); } // 0x9776C51F040F26BA 0x79D7D235
	static void _0x7D9B2E749864ACAE(char* p0) { invoke<Void>(0x7D9B2E749864ACAE, p0); } // 0x7D9B2E749864ACAE 0x85BA15A4
	static void _0x34621A0267D823A9(float p0) { invoke<Void>(0x34621A0267D823A9, p0); } // 0x34621A0267D823A9 0x9559BB38
	static void _0xBF604BE03FE409A9(Any* p0) { invoke<Void>(0xBF604BE03FE409A9, p0); } // 0xBF604BE03FE409A9 0x554BA16E
	static void _0xCEC02EF51D5F300F(Any* p0, Any* p1) { invoke<Void>(0xCEC02EF51D5F300F, p0, p1); } // 0xCEC02EF51D5F300F 0xE8F538B5
	static void _0x02E503A1747BB9B6(Any p0) { invoke<Void>(0x02E503A1747BB9B6, p0); } // 0x02E503A1747BB9B6 0x805BAB08
	static void _0x6143530FD2AFD2F4(Any* p0) { invoke<Void>(0x6143530FD2AFD2F4, p0); } // 0x6143530FD2AFD2F4 0x908A335E
	static void _0x801D6236987B0667() { invoke<Void>(0x801D6236987B0667); } // 0x801D6236987B0667 0x6776720A
	static Any _0x58B5AE25720A3640() { return invoke<Any>(0x58B5AE25720A3640); } // 0x58B5AE25720A3640
	static void _0xA182F7A51DEC967A(float p0) { invoke<Void>(0xA182F7A51DEC967A, p0); } // 0xA182F7A51DEC967A
	static void _0x102BB5CDD3B28DCC() { invoke<Void>(0x102BB5CDD3B28DCC); } // 0x102BB5CDD3B28DCC
	static int REQUEST_SCALEFORM_MOVIE(char* scaleformName) { return invoke<int>(0xD6E24789EADD6C70, scaleformName); } // 0xD6E24789EADD6C70 0xC67E3DCB
	static int REQUEST_SCALEFORM_MOVIE_INSTANCE(char* scaleformName) { return invoke<int>(0xFE3B16624B0B356E, scaleformName); } // 0xFE3B16624B0B356E 0x7CC8057D
	static int _REQUEST_SCALEFORM_MOVIE3(char* scaleformName) { return invoke<int>(0x3445B020A650AFC7, scaleformName); } // 0x3445B020A650AFC7
	static BOOL HAS_SCALEFORM_MOVIE_LOADED(int scaleformHandle) { return invoke<BOOL>(0xFF84A94166FBB351, scaleformHandle); } // 0xFF84A94166FBB351 0xDDFB6448
	static BOOL _HAS_NAMED_SCALEFORM_MOVIE_LOADED(char* scaleformName) { return invoke<BOOL>(0x0E774F9CF0179146, scaleformName); } // 0x0E774F9CF0179146
	static BOOL HAS_SCALEFORM_CONTAINER_MOVIE_LOADED_INTO_PARENT(int scaleformHandle) { return invoke<BOOL>(0x6825238F5120115C, scaleformHandle); } // 0x6825238F5120115C 0x1DFE8D8A
	static void SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(int* scaleformHandle) { invoke<Void>(0x33CBABDFE7B17924, scaleformHandle); } // 0x33CBABDFE7B17924 0x5FED3BA1
	static void SET_SCALEFORM_MOVIE_TO_USE_SYSTEM_TIME(int scaleform, BOOL toggle) { invoke<Void>(0xD475F943F6FE2CA6, scaleform, toggle); } // 0xD475F943F6FE2CA6 0x18C9DE8D
	static void DRAW_SCALEFORM_MOVIE(int scaleformHandle, float x, float y, float width, float height, int red, int green, int blue, int alpha, int p9) { invoke<Void>(0x50F4FD9686DBDC91, scaleformHandle, x, y, width, height, red, green, blue, alpha, p9); } // 0x50F4FD9686DBDC91 0x48DA6A58
	static void DRAW_SCALEFORM_MOVIE_FULLSCREEN(int scaleform, int red, int green, int blue, int alpha, BOOL unk) { invoke<Void>(0x90101FEE397F4A7E, scaleform, red, green, blue, alpha, unk); } // 0x90101FEE397F4A7E 0x7B48E696
	static void DRAW_SCALEFORM_MOVIE_FULLSCREEN_MASKED(int scaleform1, int scaleform2, int red, int green, int blue, int alpha) { invoke<Void>(0x27A202AB47C144F0, scaleform1, scaleform2, red, green, blue, alpha); } // 0x27A202AB47C144F0 0x9C59FC06
	static void DRAW_SCALEFORM_MOVIE_3D(int scaleform, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float p7, float p8, float p9, float scaleX, float scaleY, float scaleZ, Any p13) { invoke<Void>(0x986284D394A0B3CD, scaleform, posX, posY, posZ, rotX, rotY, rotZ, p7, p8, p9, scaleX, scaleY, scaleZ, p13); } // 0x986284D394A0B3CD 0xC4F63A89
	static void _DRAW_SCALEFORM_MOVIE_3D_NON_ADDITIVE(int scaleform, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float p7, float p8, float p9, float scaleX, float scaleY, float scaleZ, Any p13) { invoke<Void>(0x112BD61921C7E30C, scaleform, posX, posY, posZ, rotX, rotY, rotZ, p7, p8, p9, scaleX, scaleY, scaleZ, p13); } // 0x112BD61921C7E30C 0x899933C8
	static void CALL_SCALEFORM_MOVIE_METHOD(int scaleform, char* method) { invoke<Void>(0x109A0C435B50DB34, scaleform, method); } // 0x109A0C435B50DB34 0x7AB77B57
	static void _CALL_SCALEFORM_MOVIE_FUNCTION_FLOAT_PARAMS(int scaleform, char* functionName, float param1, float param2, float param3, float param4, float param5) { invoke<Void>(0xE0F9E91D7A2FED46, scaleform, functionName, param1, param2, param3, param4, param5); } // 0xE0F9E91D7A2FED46 0x557EDA1D
	static void _CALL_SCALEFORM_MOVIE_FUNCTION_STRING_PARAMS(int scaleform, char* functionName, char* param1, char* param2, char* param3, char* param4, char* param5) { invoke<Void>(0x312F1FFBC92DFB07, scaleform, functionName, param1, param2, param3, param4, param5); } // 0x312F1FFBC92DFB07 0x91A7FCEB
	static void _CALL_SCALEFORM_MOVIE_FUNCTION_MIXED_PARAMS(int scaleform, char* functionName, float floatParam1, float floatParam2, float floatParam3, float floatParam4, float floatParam5, char* stringParam1, char* stringParam2, char* stringParam3, char* stringParam4, char* stringParam5) { invoke<Void>(0x6754FFF2C499EE91, scaleform, functionName, floatParam1, floatParam2, floatParam3, floatParam4, floatParam5, stringParam1, stringParam2, stringParam3, stringParam4, stringParam5); } // 0x6754FFF2C499EE91 0x6EAF56DE
	static BOOL _PUSH_SCALEFORM_MOVIE_FUNCTION_FROM_HUD_COMPONENT(int hudComponent, char* functionName) { return invoke<BOOL>(0x1A9C7E41E674AE62, hudComponent, functionName); } // 0x1A9C7E41E674AE62 0x5D66CE1E
	static BOOL _PUSH_SCALEFORM_MOVIE_FUNCTION(int scaleform, char* functionName) { return invoke<BOOL>(0xEAC9A8A194DF8F91, scaleform, functionName); } // 0xEAC9A8A194DF8F91 0x215ABBE8
	static BOOL _PUSH_SCALEFORM_MOVIE_FUNCTION_N(char* functionName) { return invoke<BOOL>(0x2F805CDCE0F4A0A5, functionName); } // 0x2F805CDCE0F4A0A5 0xF6015178
	static BOOL _0x38FCCE5B6A704C04(char* functionName) { return invoke<BOOL>(0x38FCCE5B6A704C04, functionName); } // 0x38FCCE5B6A704C04 0x5E219B67
	static void _POP_SCALEFORM_MOVIE_FUNCTION_VOID() { invoke<Void>(0x44983883E630A945); } // 0x44983883E630A945 0x02DBF2D7
	static Any _POP_SCALEFORM_MOVIE_FUNCTION() { return invoke<Any>(0x2B5EF283DBE89739); } // 0x2B5EF283DBE89739 0x2F38B526
	static BOOL _0x78FB53FF5C2D4903(Any funcData) { return invoke<BOOL>(0x78FB53FF5C2D4903, funcData); } // 0x78FB53FF5C2D4903 0x5CD7C3C0
	static int _0x38CC180A8259BCD8(Any funcData) { return invoke<int>(0x38CC180A8259BCD8, funcData); } // 0x38CC180A8259BCD8 0x2CFB0E6D
	static char* SITTING_TV(int scaleform) { return invoke<char*>(0xF5D530FD6C0FDF04, scaleform); } // 0xF5D530FD6C0FDF04 0x516862EB
	static void _PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(int value) { invoke<Void>(0xDF18CF55301CEB8B, value); } // 0xDF18CF55301CEB8B 0x716777CB
	static void _PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(float value) { invoke<Void>(0x584CF9CAE83942E5, value); } // 0x584CF9CAE83942E5 0x9A01FFDA
	static void _PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_BOOL(BOOL value) { invoke<Void>(0x14ED5B5B8289F2FC, value); } // 0x14ED5B5B8289F2FC 0x0D4AE8CB
	static void _BEGIN_TEXT_COMMAND_SCALEFORM(char* componentType) { invoke<Void>(0xDCEB60B79ECB219E, componentType); } // 0xDCEB60B79ECB219E 0x3AC9CB55
	static void _END_TEXT_COMMAND_SCALEFORM() { invoke<Void>(0x1798EBF9408190D3); } // 0x1798EBF9408190D3 0x386CE0B8
	static void _0xCAEC5770D4DAD53E() { invoke<Void>(0xCAEC5770D4DAD53E); } // 0xCAEC5770D4DAD53E 0x2E80DB52
	static void _PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_STRING(char* value) { invoke<Void>(0xFCE11728AE1CFA11, value); } // 0xFCE11728AE1CFA11 0x4DAAD55B
	static void _0x0A7B7FF9E4F6CAA7(char* p0) { invoke<Void>(0x0A7B7FF9E4F6CAA7, p0); } // 0x0A7B7FF9E4F6CAA7 0xCCBF0334
	static BOOL _0xBD43685C3CB5CBEC(Any p0) { return invoke<BOOL>(0xBD43685C3CB5CBEC, p0); } // 0xBD43685C3CB5CBEC 0x91A081A1
	static void _0x25EBDE7D694FB6CD(Any p0) { invoke<Void>(0x25EBDE7D694FB6CD, p0); } // 0x25EBDE7D694FB6CD 0x83A9811D
	static void _REQUEST_HUD_SCALEFORM(int hudComponent) { invoke<Void>(0x65B70E9A24218D01, hudComponent); } // 0x65B70E9A24218D01 0x7AF85862
	static BOOL _HAS_HUD_SCALEFORM_LOADED(int hudComponent) { return invoke<BOOL>(0x393B727E5AB23CC6, hudComponent); } // 0x393B727E5AB23CC6 0x79B43255
	static void _0x72C98F823A0876CB(Any p0) { invoke<Void>(0x72C98F823A0876CB, p0); } // 0x72C98F823A0876CB 0x03D87600
	static BOOL _0x51E4C834DBC9B0B8(int scaleformHandle) { return invoke<BOOL>(0x51E4C834DBC9B0B8, scaleformHandle); } // 0x51E4C834DBC9B0B8 0xE9183D3A
	static void SET_TV_CHANNEL(int channel) { invoke<Void>(0x049E5DD4D9817A5C, channel); } // 0x049E5DD4D9817A5C 0x41A8A627
	static int GET_TV_CHANNEL() { return invoke<int>(0x62A70149E4139642); } // 0x62A70149E4139642 0x6B96145A
	static void SET_TV_VOLUME(float volume) { invoke<Void>(0xBBE28B261CE32FB4, volume); } // 0xBBE28B261CE32FB4 0xF3504F4D
	static float GET_TV_VOLUME() { return invoke<float>(0x544D3096CE17D590); } // 0x544D3096CE17D590 0x39555CF0
	static void DRAW_TV_CHANNEL(float xPos, float yPos, float xScale, float yScale, float rotation, int r, int g, int b, int alpha) { invoke<Void>(0x7A24418F547D6AA6, xPos, yPos, xScale, yScale, rotation, r, g, b, alpha); } // 0x7A24418F547D6AA6 0x8129EF89
	static void _0xD5D523028E8C8363(int p0, char* p1, BOOL p2) { invoke<Void>(0xD5D523028E8C8363, p0, p1, p2); } // 0xD5D523028E8C8363 0xB262DE67
	static void _0x43B8B6830AE635DF(Any p0, Any* p1, Any p2) { invoke<Void>(0x43B8B6830AE635DF, p0, p1, p2); } // 0x43B8B6830AE635DF 0x78C4DCBE
	static void _0x4BFD5557BE89AF12(Any p0) { invoke<Void>(0x4BFD5557BE89AF12, p0); } // 0x4BFD5557BE89AF12 0xCBE7068F
	static BOOL _LOAD_TV_CHANNEL(Hash tvChannel) { return invoke<BOOL>(0x21F56802556B58BF, tvChannel); } // 0x21F56802556B58BF 0x4D1EB0FB
	static void _0x6944F0FB0E003ADB(BOOL p0) { invoke<Void>(0x6944F0FB0E003ADB, p0); } // 0x6944F0FB0E003ADB 0x796DE696
	static void _0xF1657291AB93A482(Any p0) { invoke<Void>(0xF1657291AB93A482, p0); } // 0xF1657291AB93A482 0xD99EC000
	static void ENABLE_MOVIE_SUBTITLES(BOOL toggle) { invoke<Void>(0x039E161BEBDFE36B, toggle); } // 0x039E161BEBDFE36B 0xC2DEBA3D
	static BOOL _0xEDC3CD0FB2505C37() { return invoke<BOOL>(0xEDC3CD0FB2505C37); } // 0xEDC3CD0FB2505C37 0xE40A0F1A
	static BOOL _0xCBF184059FF1AF3E(char* p0) { return invoke<BOOL>(0xCBF184059FF1AF3E, p0); } // 0xCBF184059FF1AF3E 0x2E7D9B98
	static BOOL _0xFD176CE15662D151(char* p0, Ped ped, int p2, float posX, float posY, float posZ) { return invoke<BOOL>(0xFD176CE15662D151, p0, ped, p2, posX, posY, posZ); } // 0xFD176CE15662D151 0x9A0E3BFE
	static void _0x3CDE22E4DEB56CFB() { invoke<Void>(0x3CDE22E4DEB56CFB); } // 0x3CDE22E4DEB56CFB 0x431AA036
	static void _0xC36A3890E457B9C8(BOOL p0) { invoke<Void>(0xC36A3890E457B9C8, p0); } // 0xC36A3890E457B9C8 0x24A7A7F6
	static void _0x3DB89B4026DD49BE(BOOL p0) { invoke<Void>(0x3DB89B4026DD49BE, p0); } // 0x3DB89B4026DD49BE 0xA1CB6C94
	static void _0x6A1E389D96889A27(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10, float p11, float p12) { invoke<Void>(0x6A1E389D96889A27, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12); } // 0x6A1E389D96889A27 0x3B637AA7
	static void _0x2ABB248D3EE35953(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11) { invoke<Void>(0x2ABB248D3EE35953, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11); } // 0x2ABB248D3EE35953 0xDF552973
	static void _START_SCREEN_EFFECT(char* effectName, int duration, BOOL looped) { invoke<Void>(0x9AF1ABF0E97411BF, effectName, duration, looped); } // 0x9AF1ABF0E97411BF 0x1D980479
	static void _STOP_SCREEN_EFFECT(char* effectName) { invoke<Void>(0x8BBC558C75738A6D, effectName); } // 0x8BBC558C75738A6D 0x06BB5CDA
	static int _GET_SCREEN_EFFECT_IS_ACTIVE(char* effectName) { return invoke<int>(0xF8376C74FDEDE7BE, effectName); } // 0xF8376C74FDEDE7BE 0x089D5921
	static void _STOP_ALL_SCREEN_EFFECTS() { invoke<Void>(0xACBDD7C9D459A6D9); } // 0xACBDD7C9D459A6D9 0x4E6D875B
	static void _0x7192914B857E79DD(char* graphicsName) { invoke<Void>(0x7192914B857E79DD, graphicsName); } // 0x7192914B857E79DD
}

namespace STATS
{
	static Any STAT_CLEAR_SLOT_FOR_RELOAD(int statSlot) { return invoke<Any>(0x06236314A2337009, statSlot); } // 0x06236314A2337009 0x84BDD475
	static BOOL STAT_LOAD(int p0) { return invoke<BOOL>(0xD141C46B8B2919C6, p0); } // 0xD141C46B8B2919C6 0x9E5629F4
	static BOOL STAT_SAVE(int p0, BOOL p1, int p2) { return invoke<BOOL>(0x12049319F055CFED, p0, p1, p2); } // 0x12049319F055CFED 0xE10A7CA4
	static void _0x687BBE7470B16822(Any p0) { invoke<Void>(0x687BBE7470B16822, p0); } // 0x687BBE7470B16822 0xC62406A6
	static BOOL STAT_LOAD_PENDING(Any p0) { return invoke<BOOL>(0x920801DE8BAB88DD, p0); } // 0x920801DE8BAB88DD 0x4E9AC983
	static Any STAT_SAVE_PENDING() { return invoke<Any>(0x31251DAFA96F84AF); } // 0x31251DAFA96F84AF 0xC3FD3822
	static Any STAT_SAVE_PENDING_OR_REQUESTED() { return invoke<Any>(0x70E5D3BBA3286D96); } // 0x70E5D3BBA3286D96 0xA3407CA3
	static Any STAT_DELETE_SLOT(Any p0) { return invoke<Any>(0x5ADE9B0211711C58, p0); } // 0x5ADE9B0211711C58 0x2F171B94
	static BOOL STAT_SLOT_IS_LOADED(Any p0) { return invoke<BOOL>(0x827BAABAB70A61FF, p0); } // 0x827BAABAB70A61FF 0x7A299C13
	static BOOL _0x95A44B5E6DBF0529(Any p0) { return invoke<BOOL>(0x95A44B5E6DBF0529, p0); } // 0x95A44B5E6DBF0529 0x0BF0F4B2
	static Any _0x2444D64D638A023E(Any p0) { return invoke<Any>(0x2444D64D638A023E, p0); } // 0x2444D64D638A023E 0xCE6B62B5
	static void _0x5E4EDA66CE24D303(BOOL p0) { invoke<Void>(0x5E4EDA66CE24D303, p0); } // 0x5E4EDA66CE24D303 0xCE7A2411
	static BOOL _0x3312D4C6E81D29BF(Any p0) { return invoke<BOOL>(0x3312D4C6E81D29BF, p0); } // 0x3312D4C6E81D29BF 0x22804C20
	static void _0x7E1FE54D70628161(Any p0) { invoke<Void>(0x7E1FE54D70628161, p0); } // 0x7E1FE54D70628161 0x395D18B1
	static Any _0x92786A66A9400817() { return invoke<Any>(0x92786A66A9400817); } // 0x92786A66A9400817 0xED7000C8
	static void _0x0171ADE5EE56E83D() { invoke<Void>(0x0171ADE5EE56E83D); } // 0x0171ADE5EE56E83D
	static Any _0xFF26E7952E9B4DC1() { return invoke<Any>(0xFF26E7952E9B4DC1); } // 0xFF26E7952E9B4DC1 0x099FCC86
	static BOOL STAT_SET_INT(Hash statName, int value, BOOL save) { return invoke<BOOL>(0x731753D8494ABECD, statName, value, save); } // 0x731753D8494ABECD 0xC9CC1C5C
	static BOOL STAT_SET_FLOAT(Hash statName, float value, BOOL save) { return invoke<BOOL>(0x098CDAAE6268B0D0, statName, value, save); } // 0x098CDAAE6268B0D0 0x6CEA96F2
	static BOOL STAT_SET_BOOL(Hash statName, BOOL value, BOOL save) { return invoke<BOOL>(0xCE46AC18A4A47E2D, statName, value, save); } // 0xCE46AC18A4A47E2D 0x55D79DFB
	static BOOL STAT_SET_GXT_LABEL(Hash statName, char* value, BOOL save) { return invoke<BOOL>(0x5F3FAD0D966E5D02, statName, value, save); } // 0x5F3FAD0D966E5D02 0xC1224AA7
	static BOOL STAT_SET_DATE(Hash statName, Any* value, int numFields, BOOL save) { return invoke<BOOL>(0xC43DC246FFFC2C87, statName, value, numFields, save); } // 0xC43DC246FFFC2C87 0x36BE807B
	static BOOL STAT_SET_STRING(Hash statName, char* value, BOOL save) { return invoke<BOOL>(0xCDCFA600A8ABA84B, statName, value, save); } // 0xCDCFA600A8ABA84B 0xB1EF2E21
	static BOOL STAT_SET_POS(Hash statName, float x, float y, float z, BOOL save) { return invoke<BOOL>(0xC617BEB72DB5651E, statName, x, y, z, save); } // 0xC617BEB72DB5651E 0x1192C9A3
	static BOOL STAT_SET_MASKED_INT(Hash statName, Any p1, Any p2, int p3, BOOL save) { return invoke<BOOL>(0x3141DFACC370CE7D, statName, p1, p2, p3, save); } // 0x3141DFACC370CE7D 0x2CBAA739
	static BOOL STAT_SET_USER_ID(Hash statName, char* value, BOOL save) { return invoke<BOOL>(0x265D11FA42074848, statName, value, save); } // 0x265D11FA42074848 0xDBE78ED7
	static BOOL STAT_SET_CURRENT_POSIX_TIME(Hash statName, BOOL p1) { return invoke<BOOL>(0x1C74E148D82B3559, statName, p1); } // 0x1C74E148D82B3559 0xA286F015
	static BOOL STAT_GET_INT(Hash statHash, int* outValue, int p2) { return invoke<BOOL>(0x7FE4F330D3D74809, statHash, outValue, p2); } // 0x7FE4F330D3D74809 0x1C6FE43E
	static BOOL STAT_GET_FLOAT(Hash statHash, float* outValue, Any p2) { return invoke<BOOL>(0x5BA3D9E4E73996B2, statHash, outValue, p2); } // 0x5BA3D9E4E73996B2 0xFCBDA612
	static BOOL STAT_GET_BOOL(Hash statHash, BOOL* outValue, Any p2) { return invoke<BOOL>(0x70BD7CFD9F825957, statHash, outValue, p2); } // 0x70BD7CFD9F825957 0x28A3DD2B
	static BOOL STAT_GET_DATE(Hash statHash, Any* p1, Any p2, Any p3) { return invoke<BOOL>(0xBF460865A660BFDF, statHash, p1, p2, p3); } // 0xBF460865A660BFDF 0xD762D16C
	static char* STAT_GET_STRING(Hash statHash, int p1) { return invoke<char*>(0x63ACC1C0994F0997, statHash, p1); } // 0x63ACC1C0994F0997 0x10CE4BDE
	static BOOL STAT_GET_POS(Any p0, Any* p1, Any* p2, Any* p3, Any p4) { return invoke<BOOL>(0x2573557FE8AC03D5, p0, p1, p2, p3, p4); } // 0x2573557FE8AC03D5 0xC846ECCE
	static BOOL STAT_GET_MASKED_INT(Any p0, Any* p1, Any p2, Any p3, Any p4) { return invoke<BOOL>(0xBF0855EEDDBBCBB7, p0, p1, p2, p3, p4); } // 0xBF0855EEDDBBCBB7 0xE9D9B70F
	static char* STAT_GET_USER_ID(Any p0) { return invoke<char*>(0xB8C8CC9BF7A2B774, p0); } // 0xB8C8CC9BF7A2B774 0xE2E8B6BA
	static char* STAT_GET_LICENSE_PLATE(Hash statName) { return invoke<char*>(0x973DA1A20C4110FB, statName); } // 0x973DA1A20C4110FB 0x1544B29F
	static BOOL STAT_SET_LICENSE_PLATE(Hash statName, char* str) { return invoke<BOOL>(0x49C315FB02F7E524, statName, str); } // 0x49C315FB02F7E524 0x3507D253
	static void STAT_INCREMENT(Hash statName, float value) { invoke<Void>(0xBA7C565ADABC4947, statName, value); } // 0xBA7C565ADABC4947 0xDFC5F71E
	static BOOL _0x9A4BE9BD14BC6F91() { return invoke<BOOL>(0x9A4BE9BD14BC6F91); } // 0x9A4BE9BD14BC6F91 0x46F21343
	static BOOL _0xB32A41CEB2548735() { return invoke<BOOL>(0xB32A41CEB2548735); } // 0xB32A41CEB2548735 0x02F283CE
	static BOOL _0x6A547398F0887B2C(Hash statName, int p1, float* outValue) { return invoke<BOOL>(0x6A547398F0887B2C, statName, p1, outValue); } // 0x6A547398F0887B2C 0xC4110917
	static void _0x38F298373C529DC9(int p0) { invoke<Void>(0x38F298373C529DC9, p0); } // 0x38F298373C529DC9 0x343B27E2
	static void _0x52BC606F69233BEE(int p0) { invoke<Void>(0x52BC606F69233BEE, p0); } // 0x52BC606F69233BEE 0xE3247582
	static int STAT_GET_NUMBER_OF_DAYS(Hash statName) { return invoke<int>(0xE268096685DAFC46, statName); } // 0xE268096685DAFC46 0xFD66A429
	static int STAT_GET_NUMBER_OF_HOURS(Hash statName) { return invoke<int>(0x4F02606E4347FF12, statName); } // 0x4F02606E4347FF12 0x9B431236
	static int STAT_GET_NUMBER_OF_MINUTES(Hash statName) { return invoke<int>(0xF5E4A06714D654FF, statName); } // 0xF5E4A06714D654FF 0x347B4436
	static int STAT_GET_NUMBER_OF_SECONDS(Hash statName) { return invoke<int>(0x45FD927635B67E9D, statName); } // 0x45FD927635B67E9D 0x2C1D6C31
	static void _STAT_SET_PROFILE_SETTING(int profileSetting, int value) { invoke<Void>(0x2DC979E774D037B9, profileSetting, value); } // 0x2DC979E774D037B9 0x24DD4929
	static int _0xEC40FF50D6867780(int p0) { return invoke<int>(0xEC40FF50D6867780, p0); } // 0xEC40FF50D6867780 0xDFC25D66
	static int _0x94F17AB80A52E8BB(int p0) { return invoke<int>(0x94F17AB80A52E8BB, p0); } // 0x94F17AB80A52E8BB 0xCA160BCC
	static Hash _0xB14C33EF6CDC31A6(int p0, BOOL p1, BOOL p2, Any p3) { return invoke<Hash>(0xB14C33EF6CDC31A6, p0, p1, p2, p3); } // 0xB14C33EF6CDC31A6 0xB5BF87B2
	static Hash _0x92F4E7F362754001(int p0, BOOL p1, BOOL p2, Any p3) { return invoke<Hash>(0x92F4E7F362754001, p0, p1, p2, p3); } // 0x92F4E7F362754001 0x1F938864
	static Hash _0x7425761F86762FAD(int p0, BOOL p1, BOOL p2, Any p3) { return invoke<Hash>(0x7425761F86762FAD, p0, p1, p2, p3); } // 0x7425761F86762FAD 0x3F8E893B
	static Hash _0x55245B8F531886BD(int p0, BOOL p1, BOOL p2, Any p3) { return invoke<Hash>(0x55245B8F531886BD, p0, p1, p2, p3); } // 0x55245B8F531886BD 0xFB93C5A2
	static Hash _0x8C3FF8187D011700(int p0, BOOL p1, BOOL p2, Any p3, char* p4) { return invoke<Hash>(0x8C3FF8187D011700, p0, p1, p2, p3, p4); } // 0x8C3FF8187D011700
	static Hash _0x413C680CFEF1BF9E(int p0, BOOL p1, BOOL p2, Any p3, char* p4) { return invoke<Hash>(0x413C680CFEF1BF9E, p0, p1, p2, p3, p4); } // 0x413C680CFEF1BF9E
	static BOOL STAT_GET_BOOL_MASKED(Hash statName, int mask, int p2) { return invoke<BOOL>(0x083FFE917EBA1560, statName, mask, p2); } // 0x083FFE917EBA1560 0x6ACE1B7D
	static BOOL STAT_SET_BOOL_MASKED(Hash statName, BOOL value, int mask, BOOL save) { return invoke<BOOL>(0x6BA2DFEDEA41B774, statName, value, mask, save); } // 0x6BA2DFEDEA41B774 0x7842C4D6
	static void _0x9EF7E53B0DCC0035(char* p0, Any p1) { invoke<Void>(0x9EF7E53B0DCC0035, p0, p1); } // 0x9EF7E53B0DCC0035 0x61ECC465
	static void PLAYSTATS_NPC_INVITE(Any* p0) { invoke<Void>(0x696C50806E804E35, p0); } // 0x696C50806E804E35 0x598C06F3
	static void PLAYSTATS_AWARD_XP(Any p0, Any p1, Any p2) { invoke<Void>(0x4A006931F5B47F5F, p0, p1, p2); } // 0x4A006931F5B47F5F 0x8770017B
	static void PLAYSTATS_RANK_UP(Any p0) { invoke<Void>(0x773F6A86364159D6, p0); } // 0x773F6A86364159D6 0x56AFB9F5
	static void _0x7EA0A31E19081CA5() { invoke<Void>(0x7EA0A31E19081CA5); } // 0x7EA0A31E19081CA5 0x896CDF8D
	static void _0x9F22479295C80571(Any p0, Any p1) { invoke<Void>(0x9F22479295C80571, p0, p1); } // 0x9F22479295C80571 0x1A66945F
	static void _0x1FDBA8D2D8868566(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x1FDBA8D2D8868566, p0, p1, p2, p3, p4); } // 0x1FDBA8D2D8868566 0xC960E161
	static void PLAYSTATS_MISSION_STARTED(Any* p0, Any p1, Any p2, BOOL p3) { invoke<Void>(0xCC9DF3F34EBA8E95, p0, p1, p2, p3); } // 0xCC9DF3F34EBA8E95 0x3AAB699C
	static void PLAYSTATS_MISSION_OVER(Any* p0, Any p1, Any p2, BOOL p3, BOOL p4, BOOL p5) { invoke<Void>(0xF3081BC2C9027A69, p0, p1, p2, p3, p4, p5); } // 0xF3081BC2C9027A69 0x5B90B5FF
	static void PLAYSTATS_MISSION_CHECKPOINT(Any* p0, Any p1, Any p2, Any p3) { invoke<Void>(0x7EAB099DE46EBC94, p0, p1, p2, p3); } // 0x7EAB099DE46EBC94 0xCDC52280
	static void _0x8B93E6E9B44E0A75(Any* p0, Any p1, Any p2, Any p3) { invoke<Void>(0x8B93E6E9B44E0A75, p0, p1, p2, p3); } // 0x8B93E6E9B44E0A75 0xAC2C7C63
	static void _0xFE624701E3022FDB(Any p0, Any p1, Any p2, float p3) { invoke<Void>(0xFE624701E3022FDB, p0, p1, p2, p3); } // 0xFE624701E3022FDB 0x413539BC
	static void PLAYSTATS_RACE_CHECKPOINT(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x57E8FCA9C63C1932, p0, p1, p2, p3, p4); } // 0x57E8FCA9C63C1932 0x580D5508
	static BOOL _0x6C788331C7A4D6DA(Any* p0, Any* p1) { return invoke<BOOL>(0x6C788331C7A4D6DA, p0, p1); } // 0x6C788331C7A4D6DA 0x489E27E7
	static void PLAYSTATS_MATCH_STARTED(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<Void>(0x4736A737959D8CBD, p0, p1, p2, p3, p4, p5, p6); } // 0x4736A737959D8CBD 0x2BDE85C1
	static void PLAYSTATS_SHOP_ITEM(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x9C3567730526A202, p0, p1, p2, p3, p4); } // 0x9C3567730526A202 0xA4746384
	static void _0x85108D37BA9BD9C7(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<Void>(0x85108D37BA9BD9C7, p0, p1, p2, p3, p4, p5); } // 0x85108D37BA9BD9C7 0x6602CED6
	static void _0x17D0D6E9E6D81D9F(float p0, float p1, float p2) { invoke<Void>(0x17D0D6E9E6D81D9F, p0, p1, p2); } // 0x17D0D6E9E6D81D9F
	static void _0x510271757E9AD31D(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x510271757E9AD31D, p0, p1, p2, p3); } // 0x510271757E9AD31D 0x759E0EC9
	static void _0x96A4F210ED29AB52(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x96A4F210ED29AB52, p0, p1, p2, p3); } // 0x96A4F210ED29AB52 0x62073DF7
	static void _0x05C5D6121A559B6D(Any p0, Any p1, Any p2) { invoke<Void>(0x05C5D6121A559B6D, p0, p1, p2); } // 0x05C5D6121A559B6D 0x30558CFD
	static void _0x79E2AD9632B2BC5C(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9) { invoke<Void>(0x79E2AD9632B2BC5C, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); } // 0x79E2AD9632B2BC5C 0x06CE3692
	static void _0x8F9035CABA266EA0(Any p0) { invoke<Void>(0x8F9035CABA266EA0, p0); } // 0x8F9035CABA266EA0 0x8D5C7B37
	static void PLAYSTATS_WEBSITE_VISITED(Hash scaleformHash, int p1) { invoke<Void>(0x703B3932DF5B41E9, scaleformHash, p1); } // 0x703B3932DF5B41E9 0x37D152BB
	static void PLAYSTATS_FRIEND_ACTIVITY(Any p0, Any p1) { invoke<Void>(0xA8C699F2B8AD248C, p0, p1); } // 0xA8C699F2B8AD248C 0xD1FA1BDB
	static void PLAYSTATS_ODDJOB_DONE(Any p0, Any p1, Any p2) { invoke<Void>(0xD7D18E1FDC28C12C, p0, p1, p2); } // 0xD7D18E1FDC28C12C 0xFE14A8EA
	static void PLAYSTATS_PROP_CHANGE(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0xB698CBA5B28CD68B, p0, p1, p2, p3); } // 0xB698CBA5B28CD68B 0x25740A1D
	static void PLAYSTATS_CLOTH_CHANGE(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0xCC0FFB030BA86CDB, p0, p1, p2, p3, p4); } // 0xCC0FFB030BA86CDB 0x3AFF9E58
	static void _0x08593EB52838338E(Any p0, Any p1, Any p2) { invoke<Void>(0x08593EB52838338E, p0, p1, p2); } // 0x08593EB52838338E 0x79716890
	static void PLAYSTATS_CHEAT_APPLIED(char* cheat) { invoke<Void>(0xF6932EE3C82E0FF5, cheat); } // 0xF6932EE3C82E0FF5 0x345166F3
	static void _0xD68E7E0F0D42A565(Any* p0, Any* p1, Any* p2, Any* p3) { invoke<Void>(0xD68E7E0F0D42A565, p0, p1, p2, p3); } // 0xD68E7E0F0D42A565 0x04181752
	static void _0x0A9CB83364E4CAAA(Any* p0, Any* p1, Any* p2, Any* p3) { invoke<Void>(0x0A9CB83364E4CAAA, p0, p1, p2, p3); } // 0x0A9CB83364E4CAAA
	static void _0xD4E7C8F99EFF5DC3(Any* p0, Any* p1, Any* p2, Any* p3) { invoke<Void>(0xD4E7C8F99EFF5DC3, p0, p1, p2, p3); } // 0xD4E7C8F99EFF5DC3 0x31002201
	static void _0x3EC27FF0A097D481(Any* p0, Any* p1, Any* p2, Any* p3) { invoke<Void>(0x3EC27FF0A097D481, p0, p1, p2, p3); } // 0x3EC27FF0A097D481 0xDDD1F1F3
	static void _0x758F4D9D11ED5553(Any p0, Any* p1) { invoke<Void>(0x758F4D9D11ED5553, p0, p1); } // 0x758F4D9D11ED5553 0x66FEB701
	static void _0xA91C1CD6D4E103A4(int time) { invoke<Void>(0xA91C1CD6D4E103A4, time); } // 0xA91C1CD6D4E103A4 0x9E2B9522
	static void _0x967F3F9D46058B9A(BOOL p0) { invoke<Void>(0x967F3F9D46058B9A, p0); } // 0x967F3F9D46058B9A
	static void _0x3570A24925D3007F(Any p0, Any p1) { invoke<Void>(0x3570A24925D3007F, p0, p1); } // 0x3570A24925D3007F
	static void _0xB3F0982DF75D94F1(Any* p0) { invoke<Void>(0xB3F0982DF75D94F1, p0); } // 0xB3F0982DF75D94F1
	static Any LEADERBOARDS_GET_NUMBER_OF_COLUMNS(Any p0, Any p1) { return invoke<Any>(0x8582B412A1B26F16, p0, p1); } // 0x8582B412A1B26F16 0x0A56EE34
	static Any LEADERBOARDS_GET_COLUMN_ID(Any p0, Any p1, Any p2) { return invoke<Any>(0xBEBC5CD98A7C495F, p0, p1, p2); } // 0xBEBC5CD98A7C495F 0x3821A334
	static Any LEADERBOARDS_GET_COLUMN_TYPE(Any p0, Any p1, Any p2) { return invoke<Any>(0x4ACEF4ED6316F32A, p0, p1, p2); } // 0x4ACEF4ED6316F32A 0x6F2820F4
	static Any LEADERBOARDS_READ_CLEAR_ALL() { return invoke<Any>(0x77A34CED4AC4AE71); } // 0x77A34CED4AC4AE71 0x233E058A
	static Any LEADERBOARDS_READ_CLEAR(Any p0, Any p1, Any p2) { return invoke<Any>(0x3852E9CBAA5895E5, p0, p1, p2); } // 0x3852E9CBAA5895E5 0x7090012F
	static BOOL LEADERBOARDS_READ_PENDING(Any p0, Any p1, Any p2) { return invoke<BOOL>(0x4ABCF24CCFACF610, p0, p1, p2); } // 0x4ABCF24CCFACF610 0xEEB8BF5C
	static Any _0x97E1964D7A4DE8C5() { return invoke<Any>(0x97E1964D7A4DE8C5); } // 0x97E1964D7A4DE8C5 0x1789437B
	static BOOL LEADERBOARDS_READ_SUCCESSFUL(Any p0, Any p1, Any p2) { return invoke<BOOL>(0xADDBC115382FDCBC, p0, p1, p2); } // 0xADDBC115382FDCBC 0x3AC5B2F1
	static BOOL LEADERBOARDS2_READ_FRIENDS_BY_ROW(Any* p0, Any* p1, Any p2, BOOL p3, Any p4, Any p5) { return invoke<BOOL>(0x918B101666F9CB83, p0, p1, p2, p3, p4, p5); } // 0x918B101666F9CB83 0xBD91B136
	static BOOL LEADERBOARDS2_READ_BY_HANDLE(Any* p0, Any* p1) { return invoke<BOOL>(0x2436125B964464D4, p0, p1); } // 0x2436125B964464D4 0x6B553408
	static BOOL LEADERBOARDS2_READ_BY_ROW(Any* p0, Any* p1, Any p2, Any* p3, Any p4, Any* p5, Any p6) { return invoke<BOOL>(0xA9CDB1E3F0A49883, p0, p1, p2, p3, p4, p5, p6); } // 0xA9CDB1E3F0A49883 0xCA931F34
	static BOOL LEADERBOARDS2_READ_BY_RANK(Any* p0, Any p1, Any p2) { return invoke<BOOL>(0x0A4AC7D3FCD38DB3, p0, p1, p2); } // 0x0A4AC7D3FCD38DB3 0x1B03F59F
	static BOOL LEADERBOARDS2_READ_BY_RADIUS(Any* p0, Any p1, Any* p2) { return invoke<BOOL>(0x16D2B6D69F00A7CA, p0, p1, p2); } // 0x16D2B6D69F00A7CA 0xC5B7E685
	static BOOL LEADERBOARDS2_READ_BY_SCORE_INT(Any* p0, Any p1, Any p2) { return invoke<BOOL>(0xAFF73D59D4367282, p0, p1, p2); } // 0xAFF73D59D4367282 0xAC020C18
	static BOOL LEADERBOARDS2_READ_BY_SCORE_FLOAT(Any* p0, float p1, Any p2) { return invoke<BOOL>(0x8CADB782EBDA57D3, p0, p1, p2); } // 0x8CADB782EBDA57D3 0xC678B29F
	static BOOL _0x32D27FCC0375F4C9(Any* p0, Any* p1, Any* p2) { return invoke<BOOL>(0x32D27FCC0375F4C9, p0, p1, p2); } // 0x32D27FCC0375F4C9 0x9BEC3401
	static BOOL _0xA833F4712D5F21B5(Any* p0, Any* p1, Any* p2) { return invoke<BOOL>(0xA833F4712D5F21B5, p0, p1, p2); } // 0xA833F4712D5F21B5
	static BOOL _0x8A14F0DBC19C2B41(Any* p0) { return invoke<BOOL>(0x8A14F0DBC19C2B41, p0); } // 0x8A14F0DBC19C2B41 0xC977D6E2
	static void _0x1A31F8A33E14837C() { invoke<Void>(0x1A31F8A33E14837C); } // 0x1A31F8A33E14837C 0xF2DB6A82
	static BOOL _0x719741006A3E7BE4(Any p0, Any* p1) { return invoke<BOOL>(0x719741006A3E7BE4, p0, p1); } // 0x719741006A3E7BE4 0x766A74FE
	static Any _0xA575B27E61C1FA60(Any p0, Any p1) { return invoke<Any>(0xA575B27E61C1FA60, p0, p1); } // 0xA575B27E61C1FA60 0x6B90E730
	static float _0x965652BFB7155548(Any p0, Any p1) { return invoke<float>(0x965652BFB7155548, p0, p1); } // 0x965652BFB7155548 0x509A286F
	static BOOL LEADERBOARDS2_WRITE_DATA(Any* p0) { return invoke<BOOL>(0xC58559A4D992CC04, p0); } // 0xC58559A4D992CC04 0x5F9DF634
	static void _0x136A09C8ECAD87BC(Any p0, Any p1, float p2) { invoke<Void>(0x136A09C8ECAD87BC, p0, p1, p2); } // 0x136A09C8ECAD87BC 0x7524E27B
	static void _0x9D2E2752576FB498(Any p0, Any p1, Any p2) { invoke<Void>(0x9D2E2752576FB498, p0, p1, p2); } // 0x9D2E2752576FB498 0x1C5CCC3A
	static BOOL LEADERBOARDS_CACHE_DATA_ROW(Any* p0) { return invoke<BOOL>(0x974C568BE891F237, p0); } // 0x974C568BE891F237 0x44F7D82B
	static void LEADERBOARDS_CLEAR_CACHE_DATA() { invoke<Void>(0x8BD1905791EA8289); } // 0x8BD1905791EA8289 0x87F498C1
	static void _0x5A5BDB2F7DE50F84(Any p0) { invoke<Void>(0x5A5BDB2F7DE50F84, p0); } // 0x5A5BDB2F7DE50F84 0x88AE9667
	static BOOL LEADERBOARDS_GET_CACHE_EXISTS(Any p0) { return invoke<BOOL>(0xC849B0705C372C2A, p0); } // 0xC849B0705C372C2A 0xFC8A71F3
	static Any LEADERBOARDS_GET_CACHE_TIME(Any p0) { return invoke<Any>(0xAB7C79D6DB4889EC, p0); } // 0xAB7C79D6DB4889EC 0xEDF02302
	static Any _0x0EC526F51BC94E4C(Any p0) { return invoke<Any>(0x0EC526F51BC94E4C, p0); } // 0x0EC526F51BC94E4C 0xCE7CB520
	static BOOL LEADERBOARDS_GET_CACHE_DATA_ROW(Any p0, Any p1, Any* p2) { return invoke<BOOL>(0x8461C3CFCDF24D89, p0, p1, p2); } // 0x8461C3CFCDF24D89 0xA11289EC
	static void _0x76FDB94571A85364(Any p0, Any p1, Any p2) { invoke<Void>(0x76FDB94571A85364, p0, p1, p2); } // 0x76FDB94571A85364 0x4AC39C6C
	static void _0xC50250EFEE8255D4(Any p0, float p1, Any p2) { invoke<Void>(0xC50250EFEE8255D4, p0, p1, p2); } // 0xC50250EFEE8255D4 0x3E69E7C3
	static void _0xCB5DFE290B59A469(Any p0, Any p1, Any p2, Any* p3) { invoke<Void>(0xCB5DFE290B59A469, p0, p1, p2, p3); } // 0xCB5DFE290B59A469 0x2FFD2FA5
	static BOOL _0x97EFFC2F3CEBA534() { return invoke<BOOL>(0x97EFFC2F3CEBA534); } // 0x97EFFC2F3CEBA534 0x23D70C39
	static void _0x8B58ED3C3D723089() { invoke<Void>(0x8B58ED3C3D723089); } // 0x8B58ED3C3D723089 0x0AD43306
	static void _0xA5806EF8298D075A() { invoke<Void>(0xA5806EF8298D075A); } // 0xA5806EF8298D075A 0xC7DE5C30
	static void _0xD4712D1F6D9FC960(int value) { invoke<Void>(0xD4712D1F6D9FC960, value); } // 0xD4712D1F6D9FC960 0xA3DAC790
	static void _0xC53F82945912C1CD(int value) { invoke<Void>(0xC53F82945912C1CD, value); } // 0xC53F82945912C1CD 0x726FAE66
	static void _0xA6CA78570FE9D75D(int value) { invoke<Void>(0xA6CA78570FE9D75D, value); } // 0xA6CA78570FE9D75D 0xF03895A4
	static void _0x533953094E42A1F0(Any p0, Any p1) { invoke<Void>(0x533953094E42A1F0, p0, p1); } // 0x533953094E42A1F0 0x4C39CF10
	static void _0x79B249530BFA775D(Any p0, Any p1) { invoke<Void>(0x79B249530BFA775D, p0, p1); } // 0x79B249530BFA775D 0x2180AE13
	static void _0xD59127C247FB4FF2(Any p0, float p1) { invoke<Void>(0xD59127C247FB4FF2, p0, p1); } // 0xD59127C247FB4FF2 0xEE292B91
	static void _0xF1F99D8BB06613B7() { invoke<Void>(0xF1F99D8BB06613B7); } // 0xF1F99D8BB06613B7 0xA063CABD
	static BOOL _0xDC0DEBCDED06419B(Any* p0, Any* p1) { return invoke<BOOL>(0xDC0DEBCDED06419B, p0, p1); } // 0xDC0DEBCDED06419B 0x62C19A3D
	static void _0x8760FD35DF3F163A() { invoke<Void>(0x8760FD35DF3F163A); } // 0x8760FD35DF3F163A 0x3B4EF322
	static void _0xD2E1D7CDFCE6C4D3() { invoke<Void>(0xD2E1D7CDFCE6C4D3); } // 0xD2E1D7CDFCE6C4D3
	static BOOL _0x3566266175C4FE8C(Any* p0) { return invoke<BOOL>(0x3566266175C4FE8C, p0); } // 0x3566266175C4FE8C
	static Any _0x9AA66BB4112DFAC9() { return invoke<Any>(0x9AA66BB4112DFAC9); } // 0x9AA66BB4112DFAC9
	static Any _0x374EBE681AEDA2F8() { return invoke<Any>(0x374EBE681AEDA2F8); } // 0x374EBE681AEDA2F8
	static Any _0xFFCEB878F2C145C5() { return invoke<Any>(0xFFCEB878F2C145C5); } // 0xFFCEB878F2C145C5
	static Any _0x81D2E61AA8DE0164(Any p0) { return invoke<Any>(0x81D2E61AA8DE0164, p0); } // 0x81D2E61AA8DE0164
	static Any _0x5B28FBA053AA236E(Any p0, Any* p1) { return invoke<Any>(0x5B28FBA053AA236E, p0, p1); } // 0x5B28FBA053AA236E
	static Any _0x57C621488B8C0D46() { return invoke<Any>(0x57C621488B8C0D46); } // 0x57C621488B8C0D46 0x54E775E0
	static Any _0x7A9539489A4BD6AB(Any* p0) { return invoke<Any>(0x7A9539489A4BD6AB, p0); } // 0x7A9539489A4BD6AB 0xE3F0D62D
	static Any _0xE33BCEA92FFCB946() { return invoke<Any>(0xE33BCEA92FFCB946); } // 0xE33BCEA92FFCB946
	static Any _0x27FBDA7D4499B271() { return invoke<Any>(0x27FBDA7D4499B271); } // 0x27FBDA7D4499B271
	static BOOL _0xCE347FB71A4430D5(Any p0, Any* p1, Any* p2) { return invoke<BOOL>(0xCE347FB71A4430D5, p0, p1, p2); } // 0xCE347FB71A4430D5
	static Any _0xA4E196AEDEFA6EB9(Any* p0) { return invoke<Any>(0xA4E196AEDEFA6EB9, p0); } // 0xA4E196AEDEFA6EB9
	static void _0x50D6CFDB52E78DF5() { invoke<Void>(0x50D6CFDB52E78DF5); } // 0x50D6CFDB52E78DF5
	static void _0x7D11CD09B0022D9B() { invoke<Void>(0x7D11CD09B0022D9B); } // 0x7D11CD09B0022D9B
	static Any _0x3B9B854CD33F36E1() { return invoke<Any>(0x3B9B854CD33F36E1); } // 0x3B9B854CD33F36E1
	static void _0x0D1285E5ED89254D(Any p0) { invoke<Void>(0x0D1285E5ED89254D, p0); } // 0x0D1285E5ED89254D
	static void _0x207F4A917A8DE3B0(Any p0) { invoke<Void>(0x207F4A917A8DE3B0, p0); } // 0x207F4A917A8DE3B0
}

namespace BRAIN
{
	static void ADD_SCRIPT_TO_RANDOM_PED(char* name, Hash model, float p2, float p3) { invoke<Void>(0x5D57B7A57101B85D, name, model, p2, p3); } // 0x5D57B7A57101B85D 0xECC76C3D
	static void REGISTER_OBJECT_SCRIPT_BRAIN(char* scriptName, Hash p1, int p2, float p3, int p4, int p5) { invoke<Void>(0x1382E47F2AF3754B, scriptName, p1, p2, p3, p4, p5); } // 0x1382E47F2AF3754B 0xB6BCC608
	static BOOL IS_OBJECT_WITHIN_BRAIN_ACTIVATION_RANGE(Object object) { return invoke<BOOL>(0x16281BACBF5409B8, object); } // 0x16281BACBF5409B8 0xBA4CAA56
	static void REGISTER_WORLD_POINT_SCRIPT_BRAIN(Any* p0, float p1, Any p2) { invoke<Void>(0x450AC3A7BD2031ED, p0, p1, p2); } // 0x450AC3A7BD2031ED 0x725D91F7
	static BOOL IS_WORLD_POINT_WITHIN_BRAIN_ACTIVATION_RANGE() { return invoke<BOOL>(0x3291E05256869D44); } // 0x3291E05256869D44 0x2CF305A0
	static void ENABLE_SCRIPT_BRAIN_SET(int brainSet) { invoke<Void>(0x21D07A9ED13A689F, brainSet); } // 0x21D07A9ED13A689F 0x2765919F
	static void DISABLE_SCRIPT_BRAIN_SET(int brainSet) { invoke<Void>(0x574F45E6A279322D, brainSet); } // 0x574F45E6A279322D 0xFBD13FAD
	static void _0x427B6FAF4C734879() { invoke<Void>(0x427B6FAF4C734879); } // 0x427B6FAF4C734879 0x19B27825
	static void _0x4237CA2BDC13F13A() { invoke<Void>(0x4237CA2BDC13F13A); } // 0x4237CA2BDC13F13A 0xF3A3AB08
	static void _0x6E6FC548ABB12D5F(char* action) { invoke<Void>(0x6E6FC548ABB12D5F, action); } // 0x6E6FC548ABB12D5F 0x949FE53E
	static void _0x8113EC55DD902618(char* action) { invoke<Void>(0x8113EC55DD902618, action); } // 0x8113EC55DD902618 0x29CE8BAA
}

namespace MOBILE
{
	static void CREATE_MOBILE_PHONE(int phoneType) { invoke<Void>(0x765099C277BC033E, phoneType); } // 0x765099C277BC033E 0x5BBC5E23
	static void DESTROY_MOBILE_PHONE() { invoke<Void>(0xA8C6AEEE2F69C5F2); } // 0xA8C6AEEE2F69C5F2 0x1A65037B
	static void SET_MOBILE_PHONE_SCALE(float scale) { invoke<Void>(0x517AE6E6A9C9B334, scale); } // 0x517AE6E6A9C9B334 0x09BCF1BE
	static void SET_MOBILE_PHONE_ROTATION(float rotX, float rotY, float rotZ, Any p3) { invoke<Void>(0xE018C448439E147D, rotX, rotY, rotZ, p3); } // 0xE018C448439E147D 0x209C28CF
	static void GET_MOBILE_PHONE_ROTATION(Vector3* rotation, Any p1) { invoke<Void>(0xD48D02F749616B61, rotation, p1); } // 0xD48D02F749616B61 0x17A29F23
	static void SET_MOBILE_PHONE_POSITION(float posX, float posY, float posZ) { invoke<Void>(0xBB4FC17174B4A105, posX, posY, posZ); } // 0xBB4FC17174B4A105 0x841800B3
	static void GET_MOBILE_PHONE_POSITION(Vector3* position) { invoke<Void>(0x4EA69F96033BA4FB, position); } // 0x4EA69F96033BA4FB 0xB2E1E1A0
	static void SCRIPT_IS_MOVING_MOBILE_PHONE_OFFSCREEN(BOOL toggle) { invoke<Void>(0x97DE9FFAAC5877AB, toggle); } // 0x97DE9FFAAC5877AB 0x29828690
	static BOOL CAN_PHONE_BE_SEEN_ON_SCREEN() { return invoke<BOOL>(0xD4F16DFE61B583A1); } // 0xD4F16DFE61B583A1 0x5F978584
	static void _MOVE_FINGER(int direction) { invoke<Void>(0xCC21A1BB2C60F0A4, direction); } // 0xCC21A1BB2C60F0A4
	static void _SET_PHONE_LEAN(BOOL Toggle) { invoke<Void>(0xA9A95EAF30673444, Toggle); } // 0xA9A95EAF30673444
	static void CELL_CAM_ACTIVATE(BOOL p0, BOOL p1) { invoke<Void>(0xA08986FC1C702729, p0, p1); } // 0xA08986FC1C702729 0x234C1AE9
	static void _0x1F85777FBABA1F1A(BOOL phoneKeyEnabled) { invoke<Void>(0x1F85777FBABA1F1A, phoneKeyEnabled); } // 0x1F85777FBABA1F1A 0x4479B304
	static void _0x34B12E3900246AE0(BOOL toggle) { invoke<Void>(0x34B12E3900246AE0, toggle); } // 0x34B12E3900246AE0 0xC273BB4D
	static void _0x399BB4C7486EE39D(float p0) { invoke<Void>(0x399BB4C7486EE39D, p0); } // 0x399BB4C7486EE39D
	static void _0x4FED8BD67CB8B802(float p0) { invoke<Void>(0x4FED8BD67CB8B802, p0); } // 0x4FED8BD67CB8B802
	static void _0xB984313AD1C7DDDE(float p0) { invoke<Void>(0xB984313AD1C7DDDE, p0); } // 0xB984313AD1C7DDDE
	static void _0x5A2ED5711938A509(float p0) { invoke<Void>(0x5A2ED5711938A509, p0); } // 0x5A2ED5711938A509
	static void _0x5C13AC0C88BCC0CB(float p0) { invoke<Void>(0x5C13AC0C88BCC0CB, p0); } // 0x5C13AC0C88BCC0CB
	static void _0xF51C3780592D14F3(float p0) { invoke<Void>(0xF51C3780592D14F3, p0); } // 0xF51C3780592D14F3
	static void _0xDECE621ECFD0419F(float p0) { invoke<Void>(0xDECE621ECFD0419F, p0); } // 0xDECE621ECFD0419F
	static void _0xE62F183581E95B41(float p0) { invoke<Void>(0xE62F183581E95B41, p0); } // 0xE62F183581E95B41 0x66DCD9D2
	static BOOL CELL_CAM_IS_CHAR_VISIBLE_NO_FACE_CHECK(Entity entity) { return invoke<BOOL>(0xB1AD74E5682D6E6F, entity); } // 0xB1AD74E5682D6E6F 0xBEA88097
	static void GET_MOBILE_PHONE_RENDER_ID(int* renderId) { invoke<Void>(0xB8AC71CA94B71D85, renderId); } // 0xB8AC71CA94B71D85 0x88E4FECE
	static BOOL _0x03E2F3A2203722EB(char* name) { return invoke<BOOL>(0x03E2F3A2203722EB, name); } // 0x03E2F3A2203722EB
	static BOOL _0xA44EC5084799C668(Hash hash) { return invoke<BOOL>(0xA44EC5084799C668, hash); } // 0xA44EC5084799C668
}

namespace APP
{
	static BOOL APP_DATA_VALID() { return invoke<BOOL>(0x52004107B9352DBE); } // 0x52004107B9352DBE 0x72BDE002
	static int APP_GET_INT(char* property) { return invoke<int>(0x1A9136D347ECF5E7, property); } // 0x1A9136D347ECF5E7 0x2942AAD2
	static float APP_GET_FLOAT(char* property) { return invoke<float>(0x4F97E9ABE293AC7F, property); } // 0x4F97E9ABE293AC7F 0xD87F3A1C
	static char* APP_GET_STRING(char* property) { return invoke<char*>(0x2F0C3A93015277EC, property); } // 0x2F0C3A93015277EC 0x849CEB80
	static void APP_SET_INT(char* property, int value) { invoke<Void>(0x987671C9C1B5332B, property, value); } // 0x987671C9C1B5332B 0x1B509C32
	static void APP_SET_FLOAT(char* property, float value) { invoke<Void>(0x8F9C8517EAC09FBE, property, value); } // 0x8F9C8517EAC09FBE 0xF3076135
	static void APP_SET_STRING(char* property, char* value) { invoke<Void>(0x95EA8B7C356CFB3E, property, value); } // 0x95EA8B7C356CFB3E 0x23DF19A8
	static void APP_SET_APP(char* appName) { invoke<Void>(0x8A5FED5917DE3CC6, appName); } // 0x8A5FED5917DE3CC6 0x8BAC4146
	static void APP_SET_BLOCK(char* blockName) { invoke<Void>(0x2A66FE1E6C4CC563, blockName); } // 0x2A66FE1E6C4CC563 0xC2D54DD9
	static void APP_CLEAR_BLOCK() { invoke<Void>(0x44E9B9112A57EDEB); } // 0x44E9B9112A57EDEB 0xDAB86A18
	static void APP_CLOSE_APP() { invoke<Void>(0x26440119112EFBC0); } // 0x26440119112EFBC0 0x03767C7A
	static void APP_CLOSE_BLOCK() { invoke<Void>(0x3FE4DC6A939603E2); } // 0x3FE4DC6A939603E2 0xED97B202
	static BOOL APP_HAS_LINKED_SOCIAL_CLUB_ACCOUNT() { return invoke<BOOL>(0xC2F8E8EDF17FC1B8); } // 0xC2F8E8EDF17FC1B8 0xD368BA15
	static BOOL APP_HAS_SYNCED_DATA(char* appName) { return invoke<BOOL>(0x5D8881A4C9393DA9, appName); } // 0x5D8881A4C9393DA9 0x1DE2A63D
	static void APP_SAVE_DATA() { invoke<Void>(0xD6A47D2FD86C6A63); } // 0xD6A47D2FD86C6A63 0x84A3918D
	static Any APP_GET_DELETED_FILE_STATUS() { return invoke<Any>(0x3DC12AF329E80EB6); } // 0x3DC12AF329E80EB6 0x784D550B
	static BOOL APP_DELETE_APP_DATA(char* appName) { return invoke<BOOL>(0x5D4261A624C1B997, appName); } // 0x5D4261A624C1B997 0x2A2FBD1C
}

namespace TIME
{
	static void SET_CLOCK_TIME(int hour, int minute, int second) { invoke<Void>(0x673705D8148968BD, hour, minute, second); } // 0x673705D8148968BD 0x26F6AF14
	static void PAUSE_CLOCK(BOOL toggle) { invoke<Void>(0xD1FDEE4A40BFBA76, toggle); } // 0xD1FDEE4A40BFBA76 0xB02D6124
	static void ADVANCE_CLOCK_TIME_TO(int hour, int minute, int second) { invoke<Void>(0xF3D4A802E2CCA46B, hour, minute, second); } // 0xF3D4A802E2CCA46B 0x57B8DA7C
	static void ADD_TO_CLOCK_TIME(int hours, int minutes, int seconds) { invoke<Void>(0x7480AD216086938B, hours, minutes, seconds); } // 0x7480AD216086938B 0xCC40D20D
	static int GET_CLOCK_HOURS() { return invoke<int>(0x80BC37C67CB292E5); } // 0x80BC37C67CB292E5 0x7EF8316F
	static int GET_CLOCK_MINUTES() { return invoke<int>(0x32883EAC7DC86C40); } // 0x32883EAC7DC86C40 0x94AAC486
	static int GET_CLOCK_SECONDS() { return invoke<int>(0x0956E4296D9CC40A); } // 0x0956E4296D9CC40A 0x099C927E
	static void SET_CLOCK_DATE(int day, int month, int year) { invoke<Void>(0xAFECD422B8593851, day, month, year); } // 0xAFECD422B8593851 0x96891C94
	static int GET_CLOCK_DAY_OF_WEEK() { return invoke<int>(0xE477785EDEB446C0); } // 0xE477785EDEB446C0 0x84E4A289
	static int GET_CLOCK_DAY_OF_MONTH() { return invoke<int>(0x202B089E6328ABFA); } // 0x202B089E6328ABFA 0xC7A5ACB7
	static int GET_CLOCK_MONTH() { return invoke<int>(0xCD8338A83E1BCC14); } // 0xCD8338A83E1BCC14 0x3C48A3D5
	static int GET_CLOCK_YEAR() { return invoke<int>(0x1BBFD9409EC2598C); } // 0x1BBFD9409EC2598C 0xB8BECF15
	static int GET_MILLISECONDS_PER_GAME_MINUTE() { return invoke<int>(0x1C4276E44E12611D); } // 0x1C4276E44E12611D 0x3B74095C
	static void GET_POSIX_TIME(int* year, int* month, int* day, int* hour, int* minute, int* second) { invoke<Void>(0xC507DF759A640DF4, year, month, day, hour, minute, second); } // 0xC507DF759A640DF4 0xE15A5281
	static void _GET_LOCAL_TIME_GMT(int* year, int* month, int* day, int* hour, int* minute, int* second) { invoke<Void>(0xCA368DE938514D31, year, month, day, hour, minute, second); } // 0xCA368DE938514D31
	static void GET_LOCAL_TIME(int* year, int* month, int* day, int* hour, int* minute, int* second) { invoke<Void>(0x85650931975D58F5, year, month, day, hour, minute, second); } // 0x85650931975D58F5 0x124BCFA2
}

namespace PATHFIND
{
	static void SET_ROADS_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2, BOOL unknown1, BOOL unknown2) { invoke<Void>(0xE6FC8C18754D8C2D, x1, y1, z1, x2, y2, z2, unknown1, unknown2); } // 0xE6FC8C18754D8C2D 0xEBC7B918
	static void SET_ROADS_IN_ANGLED_AREA(float x1, float y1, float z1, float x2, float y2, float z2, float angle, BOOL unknown1, BOOL unknown2, BOOL unknown3) { invoke<Void>(0x286691C5D34EF4EC, x1, y1, z1, x2, y2, z2, angle, unknown1, unknown2, unknown3); } // 0x286691C5D34EF4EC 0xBD088F4B
	static void SET_PED_PATHS_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2, BOOL unknown) { invoke<Void>(0x176EBAF3DFCF7E54, x1, y1, z1, x2, y2, z2, unknown); } // 0x176EBAF3DFCF7E54 0x2148EA84
	static BOOL GET_SAFE_COORD_FOR_PED(float x, float y, float z, BOOL onGround, Vector3* outPosition, int flags) { return invoke<BOOL>(0xA9CBE5CF275A6B93, x, y, z, onGround, outPosition, flags); } // 0xA9CBE5CF275A6B93 0xB370270A
	static BOOL GET_CLOSEST_VEHICLE_NODE(float x, float y, float z, Vector3* outPosition, int nodeType, float p5, float p6) { return invoke<BOOL>(0x958A4508B04D88F0, x, y, z, outPosition, nodeType, p5, p6); } // 0x958A4508B04D88F0 0x6F5F1E6C
	static BOOL GET_CLOSEST_MAJOR_VEHICLE_NODE(float x, float y, float z, Vector3* outPosition, float unknown1, int unknown2) { return invoke<BOOL>(0x0AC2BDB23322BB77, x, y, z, outPosition, unknown1, unknown2); } // 0x0AC2BDB23322BB77 0x04B5F15B
	static BOOL GET_CLOSEST_VEHICLE_NODE_WITH_HEADING(float x, float y, float z, Vector3* outPosition, float* outHeading, int nodeType, float p6, int p7) { return invoke<BOOL>(0xE06BBF3AAAFDF18B, x, y, z, outPosition, outHeading, nodeType, p6, p7); } // 0xE06BBF3AAAFDF18B 0x8BD5759B
	static BOOL GET_NTH_CLOSEST_VEHICLE_NODE(float x, float y, float z, int nthClosest, Vector3* outPosition, Any unknown1, Any unknown2, Any unknown3) { return invoke<BOOL>(0x50FED0D38D06E0E6, x, y, z, nthClosest, outPosition, unknown1, unknown2, unknown3); } // 0x50FED0D38D06E0E6 0xF125BFCC
	static int GET_NTH_CLOSEST_VEHICLE_NODE_ID(float x, float y, float z, int nth, int nodetype, float p5, float p6) { return invoke<int>(0xADFF8D17FD120DEB, x, y, z, nth, nodetype, p5, p6); } // 0xADFF8D17FD120DEB 0x3F358BEA
	static BOOL GET_NTH_CLOSEST_VEHICLE_NODE_WITH_HEADING(float x, float y, float z, int nthClosest, Vector3* outPosition, float* heading, Any* unknown1, int unknown2, float unknown3, float unknown4) { return invoke<BOOL>(0x25F8DA4A9E82297D, x, y, z, nthClosest, outPosition, heading, unknown1, unknown2, unknown3, unknown4); } // 0x25F8DA4A9E82297D 0x7349C856
	static Any GET_NTH_CLOSEST_VEHICLE_NODE_ID_WITH_HEADING(float x, float y, float z, int nthClosest, Vector3* outPosition, float outHeading, Any p6, float p7, float p8) { return invoke<Any>(0xD32DAE938BCBE6B7, x, y, z, nthClosest, outPosition, outHeading, p6, p7, p8); } // 0xD32DAE938BCBE6B7 0xC1AEB88D
	static BOOL GET_NTH_CLOSEST_VEHICLE_NODE_FAVOUR_DIRECTION(float x, float y, float z, float desiredX, float desiredY, float desiredZ, int nthClosest, Vector3* outPosition, float* outHeading, int nodetype, Any p10, Any p11) { return invoke<BOOL>(0xDDED65F512F431D9, x, y, z, desiredX, desiredY, desiredZ, nthClosest, outPosition, outHeading, nodetype, p10, p11); } // 0xDDED65F512F431D9 0x928A4DEC
	static BOOL GET_VEHICLE_NODE_PROPERTIES(float x, float y, float z, int* density, int* flags) { return invoke<BOOL>(0x2987C771A97EE274, x, y, z, density, flags); } // 0x2987C771A97EE274 0xCC90110B
	static BOOL IS_VEHICLE_NODE_ID_VALID(int vehicleNodeId) { return invoke<BOOL>(0x9B205E72C3C3D4D2, vehicleNodeId); } // 0x9B205E72C3C3D4D2 0x57DFB1EF
	static void GET_VEHICLE_NODE_POSITION(int nodeId, Vector3* outPosition) { invoke<Void>(0x6C75B0230559CABB, nodeId, outPosition); } // 0x6C75B0230559CABB 0xE38E252D
	static BOOL _GET_SUPPORTS_GPS_ROUTE_FLAG(int nodeID) { return invoke<BOOL>(0x363C61D7285EF4DD, nodeID); } // 0x363C61D7285EF4DD 0xEE4B1219
	static BOOL _GET_IS_SLOW_ROAD_FLAG(int nodeID) { return invoke<BOOL>(0x7942816A92DB1A59, nodeID); } // 0x7942816A92DB1A59 0x56737A3C
	static Any GET_CLOSEST_ROAD(float x, float y, float z, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10) { return invoke<Any>(0x2A130353C9214F6A, x, y, z, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x2A130353C9214F6A 0x567B0E11
	static BOOL LOAD_ALL_PATH_NODES(BOOL keepInMemory) { return invoke<BOOL>(0x6E509EE12168E95A, keepInMemory); } // 0x6E509EE12168E95A 0xC66E28C3
	static void _0x92D535AC80F52D10(BOOL p0) { invoke<Void>(0x92D535AC80F52D10, p0); } // 0x92D535AC80F52D10 0xD6A3B458
	static BOOL _0x9DBC66CA24B0F4B8(float p0, float p1, float p2, float p3) { return invoke<BOOL>(0x9DBC66CA24B0F4B8, p0, p1, p2, p3); } // 0x9DBC66CA24B0F4B8 0x86E80A17
	static BOOL _0x0A53F2AFCE4F39E0(float p0, float p1, float p2, float p3) { return invoke<BOOL>(0x0A53F2AFCE4F39E0, p0, p1, p2, p3); } // 0x0A53F2AFCE4F39E0 0x2CDA5012
	static void SET_ROADS_BACK_TO_ORIGINAL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<Void>(0xE7281B4166C6A4CD, p0, p1, p2, p3, p4, p5); } // 0xE7281B4166C6A4CD 0x86AC4A85
	static void SET_ROADS_BACK_TO_ORIGINAL_IN_ANGLED_AREA(float x1, float y1, float z1, float x2, float y2, float z2, float p6) { invoke<Void>(0xD211CBCC0E735E4F, x1, y1, z1, x2, y2, z2, p6); } // 0xD211CBCC0E735E4F 0x9DB5D209
	static void _0xE25789A07C955819(float p0) { invoke<Void>(0xE25789A07C955819, p0); } // 0xE25789A07C955819 0x3C5085E4
	static void _0x0D01B39859B6C965(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<Void>(0x0D01B39859B6C965, p0, p1, p2, p3, p4, p5, p6); } // 0x0D01B39859B6C965 0xD0F51299
	static void SET_PED_PATHS_BACK_TO_ORIGINAL(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<Void>(0x700DE1253BAD8ADC, p0, p1, p2, p3, p4, p5); } // 0x700DE1253BAD8ADC 0x3F1ABDA4
	static BOOL GET_RANDOM_VEHICLE_NODE(float x, float y, float z, float radius, BOOL p4, BOOL p5, BOOL p6, Vector3* outPosition, float* heading) { return invoke<BOOL>(0xFC18BDE0C49AAF34, x, y, z, radius, p4, p5, p6, outPosition, heading); } // 0xFC18BDE0C49AAF34 0xAD1476EA
	static void GET_STREET_NAME_AT_COORD(float x, float y, float z, Hash* streetName, Hash* crossingRoad) { invoke<Void>(0x7F91221B5FD11C75, x, y, z, streetName, crossingRoad); } // 0x7F91221B5FD11C75 0xDEBEEFCF
	static Any GENERATE_DIRECTIONS_TO_COORD(float x, float y, float z, Any p3, int* p4, Vehicle* vehicle, float* p6) { return invoke<Any>(0xB3A4AD445313C817, x, y, z, p3, p4, vehicle, p6); } // 0xB3A4AD445313C817 0xED35C094
	static void SET_IGNORE_NO_GPS_FLAG(BOOL ignore) { invoke<Void>(0xE552BEE61F130CC5, ignore); } // 0xE552BEE61F130CC5 0xB72CF194
	static void _0x1839A5B4CD704CF3(BOOL p0) { invoke<Void>(0x1839A5B4CD704CF3, p0); } // 0x1839A5B4CD704CF3 0x90DF7A4C
	static void SET_GPS_DISABLED_ZONE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { invoke<Void>(0xD6B80735941A5329, p0, p1, p2, p3, p4, p5); } // 0xD6B80735941A5329 0x720B8073
	static Any _0x1BAE65465EB2FB2E() { return invoke<Any>(0x1BAE65465EB2FB2E); } // 0x1BAE65465EB2FB2E 0x4B770634
	static Any _0xB4413CE6C3190B07() { return invoke<Any>(0xB4413CE6C3190B07); } // 0xB4413CE6C3190B07 0x286F82CC
	static Any _0xF95354FAD2A5A3BF(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<Any>(0xF95354FAD2A5A3BF, p0, p1, p2, p3, p4); } // 0xF95354FAD2A5A3BF 0xF6422F9A
	static BOOL IS_POINT_ON_ROAD(float x, float y, float z, Vehicle vehicle) { return invoke<BOOL>(0x7E63382CE7CAE364, x, y, z, vehicle); } // 0x7E63382CE7CAE364 0xCF198055
	static Any _0x7B915566952D2DB9() { return invoke<Any>(0x7B915566952D2DB9); } // 0x7B915566952D2DB9
	static void _0xE1D0C9AC75B7623D(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<Void>(0xE1D0C9AC75B7623D, p0, p1, p2, p3, p4, p5, p6); } // 0xE1D0C9AC75B7623D
	static void _0xC8F9F4596CBDDD09(Any p0) { invoke<Void>(0xC8F9F4596CBDDD09, p0); } // 0xC8F9F4596CBDDD09
	static void ADD_NAVMESH_REQUIRED_REGION(float x, float y, float radius) { invoke<Void>(0x8DC43D7EEE7743A6, x, y, radius); } // 0x8DC43D7EEE7743A6 0x12B086EA
	static void REMOVE_NAVMESH_REQUIRED_REGIONS() { invoke<Void>(0xE3AF2BFF1DE1BCA9); } // 0xE3AF2BFF1DE1BCA9 0x637BB680
	static void DISABLE_NAVMESH_IN_AREA(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { invoke<Void>(0xEEB6FB1A486B379E, p0, p1, p2, p3, p4, p5, p6); } // 0xEEB6FB1A486B379E 0x6E37F132
	static BOOL ARE_ALL_NAVMESH_REGIONS_LOADED() { return invoke<BOOL>(0xDC158329C89CCC17); } // 0xDC158329C89CCC17 0x34C4E789
	static BOOL IS_NAVMESH_LOADED_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<BOOL>(0xE99D6523008CCDE1, x1, y1, z1, x2, y2, z2); } // 0xE99D6523008CCDE1 0x4C2BA99E
	static Any _0x6DD4F596D2035322(float p0, float p1, float p2, float p3, float p4, float p5) { return invoke<Any>(0x6DD4F596D2035322, p0, p1, p2, p3, p4, p5); } // 0x6DD4F596D2035322
	static Any ADD_NAVMESH_BLOCKING_OBJECT(float p0, float p1, float p2, float p3, float p4, float p5, float p6, BOOL p7, Any p8) { return invoke<Any>(0x8655B796E2C96969, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x8655B796E2C96969 0x2952BA56
	static void UPDATE_NAVMESH_BLOCKING_OBJECT(Any p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, Any p8) { invoke<Void>(0x820780392BB770FD, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0x820780392BB770FD 0x4E9776D0
	static void REMOVE_NAVMESH_BLOCKING_OBJECT(Any p0) { invoke<Void>(0xE73D1B19D9500603, p0); } // 0xE73D1B19D9500603 0x098602B0
	static BOOL _0x33CB7E3A2B3E527C(Any p0) { return invoke<BOOL>(0x33CB7E3A2B3E527C, p0); } // 0x33CB7E3A2B3E527C 0x4B67D7EE
	static float _0xAC4CF7688C53AA57(float p0, float p1) { return invoke<float>(0xAC4CF7688C53AA57, p0, p1); } // 0xAC4CF7688C53AA57 0x3FE8C5A0
	static float _0x67634B2A9A0EC090(float p0, float p1, float p2, float p3) { return invoke<float>(0x67634B2A9A0EC090, p0, p1, p2, p3); } // 0x67634B2A9A0EC090 0x3ED21C90
	static float _0x1A64E7F2C4BC2FD8(float left, float right) { return invoke<float>(0x1A64E7F2C4BC2FD8, left, right); } // 0x1A64E7F2C4BC2FD8 0xA07C5B7D
	static float _0xB93C2F745D8F2109(float p0, float p1, float p2, float p3) { return invoke<float>(0xB93C2F745D8F2109, p0, p1, p2, p3); } // 0xB93C2F745D8F2109 0x76751DD4
	static float CALCULATE_TRAVEL_DISTANCE_BETWEEN_POINTS(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<float>(0x7D612D40282A0234, x1, y1, z1, x2, y2, z2); } // 0x7D612D40282A0234 0xB114489B
}

namespace CONTROLS
{
	static BOOL IS_CONTROL_ENABLED(int inputGroup, int control) { return invoke<BOOL>(0xC36DBFD18BF1A53B, inputGroup, control); } // 0xC36DBFD18BF1A53B 0x9174AF84
	static BOOL IS_CONTROL_PRESSED(int inputGroup, int control) { return invoke<BOOL>(0x79888727131C6854, inputGroup, control); } // 0x79888727131C6854 0x517A4384
	static BOOL IS_CONTROL_RELEASED(int inputGroup, int control) { return invoke<BOOL>(0x2BB31504507E9506, inputGroup, control); } // 0x2BB31504507E9506 0x1F91A06E
	static BOOL IS_CONTROL_JUST_PRESSED(int inputGroup, int control) { return invoke<BOOL>(0x4B972043966C2EB8, inputGroup, control); } // 0x4B972043966C2EB8 0x4487F579
	static BOOL IS_CONTROL_JUST_RELEASED(int inputGroup, int control) { return invoke<BOOL>(0x164D7B6E326ECB2A, inputGroup, control); } // 0x164D7B6E326ECB2A 0x2314444B
	static int GET_CONTROL_VALUE(int inputGroup, int control) { return invoke<int>(0x6D95420A284C8601, inputGroup, control); } // 0x6D95420A284C8601 0xC526F3C6
	static float GET_CONTROL_NORMAL(int inputGroup, int control) { return invoke<float>(0xC9C57E7D3CE8A98E, inputGroup, control); } // 0xC9C57E7D3CE8A98E 0x5DE226A5
	static void _0x94FCC8290D599365(BOOL p0) { invoke<Void>(0x94FCC8290D599365, p0); } // 0x94FCC8290D599365
	static float _0x59914E69071E2911(int inputGroup, int control) { return invoke<float>(0x59914E69071E2911, inputGroup, control); } // 0x59914E69071E2911 0xC49343BB
	static BOOL _SET_CONTROL_NORMAL(int inputGroup, int control, float amount) { return invoke<BOOL>(0x09EC89E3937B74EE, inputGroup, control, amount); } // 0x09EC89E3937B74EE
	static BOOL IS_DISABLED_CONTROL_PRESSED(int inputGroup, int control) { return invoke<BOOL>(0x9E3D293A990C1BEF, inputGroup, control); } // 0x9E3D293A990C1BEF 0x32A93544
	static BOOL IS_DISABLED_CONTROL_JUST_PRESSED(int inputGroup, int control) { return invoke<BOOL>(0x698C9A4C14BF3957, inputGroup, control); } // 0x698C9A4C14BF3957 0xEE6ABD32
	static BOOL IS_DISABLED_CONTROL_JUST_RELEASED(int inputGroup, int control) { return invoke<BOOL>(0x7C48E6953368E08B, inputGroup, control); } // 0x7C48E6953368E08B 0xD6A679E1
	static float GET_DISABLED_CONTROL_NORMAL(int inputGroup, int control) { return invoke<float>(0x6E0DC4DEE4A9B736, inputGroup, control); } // 0x6E0DC4DEE4A9B736 0x66FF4FAA
	static float _0xBD25D98B49ED9766(int inputGroup, int control) { return invoke<float>(0xBD25D98B49ED9766, inputGroup, control); } // 0xBD25D98B49ED9766 0xF2A65A4C
	static int _0xE200EC5143687967(int p0) { return invoke<int>(0xE200EC5143687967, p0); } // 0xE200EC5143687967 0x0E8EF929
	static BOOL _IS_INPUT_DISABLED(int inputGroup) { return invoke<BOOL>(0xF23B2033129FFCF0, inputGroup); } // 0xF23B2033129FFCF0
	static BOOL _IS_INPUT_JUST_DISABLED(int inputGroup) { return invoke<BOOL>(0xB94BB6517BF117EA, inputGroup); } // 0xB94BB6517BF117EA
	static BOOL _0x48EE56A8580F09EC(float p0, float p1) { return invoke<BOOL>(0x48EE56A8580F09EC, p0, p1); } // 0x48EE56A8580F09EC
	static BOOL _0x3D9CE3EC27F94B62(Any p0) { return invoke<BOOL>(0x3D9CE3EC27F94B62, p0); } // 0x3D9CE3EC27F94B62
	static BOOL _0x987367D2EDB45658(int inputGroup) { return invoke<BOOL>(0x987367D2EDB45658, inputGroup); } // 0x987367D2EDB45658
	static char* _GET_CONTROL_ACTION_NAME(int inputGroup, int control, BOOL p2) { return invoke<char*>(0x38DDA814F2E19659, inputGroup, control, p2); } // 0x38DDA814F2E19659 0x3551727A
	static char* _0x9AF1671E53EE8CE7(int inputGroup, int control, BOOL p2) { return invoke<char*>(0x9AF1671E53EE8CE7, inputGroup, control, p2); } // 0x9AF1671E53EE8CE7 0x3EE71F6A
	static void _0xB2567F0B570A0798(int p0, int red, int green, int blue) { invoke<Void>(0xB2567F0B570A0798, p0, red, green, blue); } // 0xB2567F0B570A0798
	static void _0xD5959830DA5E9DD8(Any p0) { invoke<Void>(0xD5959830DA5E9DD8, p0); } // 0xD5959830DA5E9DD8
	static void SET_PAD_SHAKE(int p0, int duration, int frequency) { invoke<Void>(0x1C7515726465BC07, p0, duration, frequency); } // 0x1C7515726465BC07 0x5D38BD2F
	static void _0x8BEE307914F4109E(Any p0, Any p1, Any p2, Any p3, Any p4) { invoke<Void>(0x8BEE307914F4109E, p0, p1, p2, p3, p4); } // 0x8BEE307914F4109E
	static void STOP_PAD_SHAKE(Any p0) { invoke<Void>(0xA403D39666633053, p0); } // 0xA403D39666633053 0x8F75657E
	static void _0xBF041EDFFE181B36(Any p0, Any p1) { invoke<Void>(0xBF041EDFFE181B36, p0, p1); } // 0xBF041EDFFE181B36 0x7D65EB6E
	static void _0x0D42C09E15AFAE78(Any p0) { invoke<Void>(0x0D42C09E15AFAE78, p0); } // 0x0D42C09E15AFAE78
	static BOOL IS_LOOK_INVERTED() { return invoke<BOOL>(0x3D58C99BA34BF045); } // 0x3D58C99BA34BF045 0x313434B2
	static BOOL _0xD652E15466D1EA3C() { return invoke<BOOL>(0xD652E15466D1EA3C); } // 0xD652E15466D1EA3C
	static int GET_LOCAL_PLAYER_AIM_STATE() { return invoke<int>(0xF38E4347579BAB61); } // 0xF38E4347579BAB61 0x81802053
	static Any _0xB0F4A15D86DACB3D() { return invoke<Any>(0xB0F4A15D86DACB3D); } // 0xB0F4A15D86DACB3D
	static BOOL _0x7D6A5E911D3E5E66() { return invoke<BOOL>(0x7D6A5E911D3E5E66); } // 0x7D6A5E911D3E5E66
	static BOOL _0x7A81C223E57BFCA4() { return invoke<BOOL>(0x7A81C223E57BFCA4); } // 0x7A81C223E57BFCA4
	static void SET_PLAYERPAD_SHAKES_WHEN_CONTROLLER_DISABLED(BOOL toggle) { invoke<Void>(0xABF5CE3DE0204674, toggle); } // 0xABF5CE3DE0204674 0xA86BD91F
	static void SET_INPUT_EXCLUSIVE(int inputGroup, int control) { invoke<Void>(0x28EAA5C7C54BD253, inputGroup, control); } // 0x28EAA5C7C54BD253 0x4E8E29E6
	static void DISABLE_CONTROL_ACTION(int inputGroup, int control, BOOL disable) { invoke<Void>(0xD1BB2AD73E7FC3A7, inputGroup, control, disable); } // 0xD1BB2AD73E7FC3A7 0x3800C0DC
	static void ENABLE_CONTROL_ACTION(int inputGroup, int control, BOOL enable) { invoke<Void>(0xCA3F0B618E8962EA, inputGroup, control, enable); } // 0xCA3F0B618E8962EA 0xD2753551
	static void DISABLE_ALL_CONTROL_ACTIONS(int inputGroup) { invoke<Void>(0x1FFF117878F2CECE, inputGroup); } // 0x1FFF117878F2CECE 0x16753CF4
	static void ENABLE_ALL_CONTROL_ACTIONS(int inputGroup) { invoke<Void>(0xDA75543D9E5F5E25, inputGroup); } // 0xDA75543D9E5F5E25 0xFC2F119F
	static BOOL _0xC97C3FF3A2EF94E7(char* p0) { return invoke<BOOL>(0xC97C3FF3A2EF94E7, p0); } // 0xC97C3FF3A2EF94E7 0xD2C80B2E
	static BOOL _0xC28769BB534545D7(char* p0) { return invoke<BOOL>(0xC28769BB534545D7, p0); } // 0xC28769BB534545D7 0xBBFC9050
	static void _0x092FD48555352DF6() { invoke<Void>(0x092FD48555352DF6); } // 0x092FD48555352DF6 0x42140FF9
	static void _DISABLE_INPUT_GROUP(int inputGroup) { invoke<Void>(0xD23D06AFFB8CE7ED, inputGroup); } // 0xD23D06AFFB8CE7ED 0x2CEDE6C5
}

namespace DATAFILE
{
	static void _0xACFA71A2AA8775DD(Any p0) { invoke<Void>(0xACFA71A2AA8775DD, p0); } // 0xACFA71A2AA8775DD 0x621388FF
	static void _0x4AC5C6B6D6F1DE8F() { invoke<Void>(0x4AC5C6B6D6F1DE8F); } // 0x4AC5C6B6D6F1DE8F
	static BOOL _0xE45281B6B00DACFA(Any p0) { return invoke<BOOL>(0xE45281B6B00DACFA, p0); } // 0xE45281B6B00DACFA
	static BOOL _0x84518EE57DB73A33(Any p0) { return invoke<BOOL>(0x84518EE57DB73A33, p0); } // 0x84518EE57DB73A33
	static BOOL _0x73D2FB52079F12FD(Any p0) { return invoke<BOOL>(0x73D2FB52079F12FD, p0); } // 0x73D2FB52079F12FD
	static BOOL _0x42103FD8DF7FA31B(Any p0) { return invoke<BOOL>(0x42103FD8DF7FA31B, p0); } // 0x42103FD8DF7FA31B 0xB41064A4
	static BOOL _0x20E232F0309EDEF3(Any p0) { return invoke<BOOL>(0x20E232F0309EDEF3, p0); } // 0x20E232F0309EDEF3 0x9DB63CFF
	static BOOL _0xB2822DADBE2E3DD6(char* p0, BOOL p1, char* p2, Any* p3, Any* p4, char* type, BOOL p6) { return invoke<BOOL>(0xB2822DADBE2E3DD6, p0, p1, p2, p3, p4, type, p6); } // 0xB2822DADBE2E3DD6 0xF09157B0
	static BOOL _0x7142A7729212C03A(char* p0, char* p1, char* p2, char* p3, BOOL p4) { return invoke<BOOL>(0x7142A7729212C03A, p0, p1, p2, p3, p4); } // 0x7142A7729212C03A 0xD96860FC
	static BOOL _0x63BFE3FB35EFA0BA(char* p0, Any* p1, BOOL p2, Any* p3, Any* p4, Any* p5, char* type) { return invoke<BOOL>(0x63BFE3FB35EFA0BA, p0, p1, p2, p3, p4, p5, type); } // 0x63BFE3FB35EFA0BA 0x459F2683
	static BOOL _0x96ECDFDFCDF24500(char* p0, char* p1, char* p2, char* p3, char* type) { return invoke<BOOL>(0x96ECDFDFCDF24500, p0, p1, p2, p3, type); } // 0x96ECDFDFCDF24500 0xDBB83E2B
	static BOOL _0x698839B0D1C25DA9(char* p0, float p1, char* type) { return invoke<BOOL>(0x698839B0D1C25DA9, p0, p1, type); } // 0x698839B0D1C25DA9 0xBB6321BD
	static BOOL _0xDB9B90606DD732C7(int p0) { return invoke<BOOL>(0xDB9B90606DD732C7, p0); } // 0xDB9B90606DD732C7 0xE8D56DA2
	static BOOL _0xEAB52B67DCE90EDF(int p0, BOOL p1) { return invoke<BOOL>(0xEAB52B67DCE90EDF, p0, p1); } // 0xEAB52B67DCE90EDF 0xCB6A351E
	static BOOL _0x84A8231D14195CF9(int p0) { return invoke<BOOL>(0x84A8231D14195CF9, p0); } // 0x84A8231D14195CF9 0xA4D1B30E
	static BOOL _0x20DABE46F2E59AE3(int p0) { return invoke<BOOL>(0x20DABE46F2E59AE3, p0); } // 0x20DABE46F2E59AE3 0xB8515B2F
	static BOOL _LOAD_UGC_FILE(char* filename) { return invoke<BOOL>(0x55E20D3E4D289DA9, filename); } // 0x55E20D3E4D289DA9 0x660C468E
	static void DATAFILE_CREATE() { invoke<Void>(0x2669CD654CF4A8DB); } // 0x2669CD654CF4A8DB 0x95F8A221
	static void DATAFILE_DELETE() { invoke<Void>(0xAD8D0FF9582FEAAB); } // 0xAD8D0FF9582FEAAB 0xDEF31B0A
	static void _0x1679614EE9A31D2F() { invoke<Void>(0x1679614EE9A31D2F); } // 0x1679614EE9A31D2F 0x4E03F632
	static void _0x2BAC1F29EC7C62BF() { invoke<Void>(0x2BAC1F29EC7C62BF); } // 0x2BAC1F29EC7C62BF 0xF11F956F
	static Any* _GET_ROOT_OBJECT() { return invoke<Any*>(0xA41786EFDA9A8895); } // 0xA41786EFDA9A8895 0x86DDF9C2
	static BOOL _0x96E39940E8336F3C(char* filename) { return invoke<BOOL>(0x96E39940E8336F3C, filename); } // 0x96E39940E8336F3C 0x768CBB35
	static BOOL _0x6DB6D8C37AD58C63(BOOL* p0) { return invoke<BOOL>(0x6DB6D8C37AD58C63, p0); } // 0x6DB6D8C37AD58C63 0x0B4087F7
	static BOOL _0x9710FEDD2413A882() { return invoke<BOOL>(0x9710FEDD2413A882); } // 0x9710FEDD2413A882 0x5DCD0796
	static void _OBJECT_VALUE_ADD_BOOLEAN(Any* objectData, char* key, BOOL value) { invoke<Void>(0xBCBE90047B0F6453, objectData, key, value); } // 0xBCBE90047B0F6453 0x9B29D99B
	static void _OBJECT_VALUE_ADD_INTEGER(Any* objectData, char* key, int value) { invoke<Void>(0x07B9D0A77E239396, objectData, key, value); } // 0x07B9D0A77E239396 0xEFCF554A
	static void _OBJECT_VALUE_ADD_FLOAT(Any* objectData, char* key, float value) { invoke<Void>(0x2B3644BFE2FD110F, objectData, key, value); } // 0x2B3644BFE2FD110F 0xE972CACF
	static void _OBJECT_VALUE_ADD_STRING(Any* objectData, char* key, char* value) { invoke<Void>(0xB2E28A238DC0BA48, objectData, key, value); } // 0xB2E28A238DC0BA48 0xD437615C
	static void _OBJECT_VALUE_ADD_VECTOR3(Any* objectData, char* key, float valueX, float valueY, float valueZ) { invoke<Void>(0xFF50D28161DC2DB5, objectData, key, valueX, valueY, valueZ); } // 0xFF50D28161DC2DB5 0x75FC6C3C
	static Any* _OBJECT_VALUE_ADD_OBJECT(Any* objectData, char* key) { return invoke<Any*>(0xBC69B689F6F3BCA1, objectData, key); } // 0xBC69B689F6F3BCA1 0x96A8E05F
	static Any* _OBJECT_VALUE_ADD_ARRAY(Any* objectData, char* key) { return invoke<Any*>(0xB6FE4A7FE2C5D4DF, objectData, key); } // 0xB6FE4A7FE2C5D4DF 0x03939B8D
	static BOOL _OBJECT_VALUE_GET_BOOLEAN(Any* objectData, char* key) { return invoke<BOOL>(0x917AA466A591DA1F, objectData, key); } // 0x917AA466A591DA1F 0x8876C872
	static int _OBJECT_VALUE_GET_INTEGER(Any* objectData, char* key) { return invoke<int>(0x37AC9FA286925FB3, objectData, key); } // 0x37AC9FA286925FB3 0xA6C68693
	static float _OBJECT_VALUE_GET_FLOAT(Any* objectData, char* key) { return invoke<float>(0x43D5E279656505E4, objectData, key); } // 0x43D5E279656505E4 0xA92C1AF4
	static char* _OBJECT_VALUE_GET_STRING(Any* objectData, char* key) { return invoke<char*>(0x12A8355C6ACDA29F, objectData, key); } // 0x12A8355C6ACDA29F 0x942160EC
	static Vector3 _OBJECT_VALUE_GET_VECTOR3(Any* objectData, char* key) { return invoke<Vector3>(0x51AA166972995C47, objectData, key); } // 0x51AA166972995C47 0xE84A127A
	static Any* _OBJECT_VALUE_GET_OBJECT(Any* objectData, char* key) { return invoke<Any*>(0x489F243BF1619568, objectData, key); } // 0x489F243BF1619568 0xC9C13D8D
	static Any* _OBJECT_VALUE_GET_ARRAY(Any* objectData, char* key) { return invoke<Any*>(0x72C98FCC21DF47AA, objectData, key); } // 0x72C98FCC21DF47AA 0x1F2F7D00
	static int _OBJECT_VALUE_GET_TYPE(Any* objectData, char* key) { return invoke<int>(0x0481328AA6FEFDAB, objectData, key); } // 0x0481328AA6FEFDAB 0x2678342A
	static void _ARRAY_VALUE_ADD_BOOLEAN(Any* arrayData, BOOL value) { invoke<Void>(0x40943FD1350534DA, arrayData, value); } // 0x40943FD1350534DA 0x08174B90
	static void _ARRAY_VALUE_ADD_INTEGER(Any* arrayData, int value) { invoke<Void>(0xBFB247548BEBF410, arrayData, value); } // 0xBFB247548BEBF410 0xF29C0B36
	static void _ARRAY_VALUE_ADD_FLOAT(Any* arrayData, float value) { invoke<Void>(0xA31BE22D2243A1B0, arrayData, value); } // 0xA31BE22D2243A1B0 0xE4302123
	static void _ARRAY_VALUE_ADD_STRING(Any* arrayData, char* value) { invoke<Void>(0x9E72D71743CFEBE5, arrayData, value); } // 0x9E72D71743CFEBE5 0xF3C01350
	static void _ARRAY_VALUE_ADD_VECTOR3(Any* arrayData, float valueX, float valueY, float valueZ) { invoke<Void>(0xEA315DD70EADE08C, arrayData, valueX, valueY, valueZ); } // 0xEA315DD70EADE08C 0x16F464B6
	static Any* _ARRAY_VALUE_ADD_OBJECT(Any* arrayData) { return invoke<Any*>(0x54DA546A4AABD9AD, arrayData); } // 0x54DA546A4AABD9AD 0xC174C71B
	static BOOL _ARRAY_VALUE_GET_BOOLEAN(Any* arrayData, int arrayIndex) { return invoke<BOOL>(0x743A454C4B4C0325, arrayData, arrayIndex); } // 0x743A454C4B4C0325 0xA2E5F921
	static int _ARRAY_VALUE_GET_INTEGER(Any* arrayData, int arrayIndex) { return invoke<int>(0xB6790B02AB53A81E, arrayData, arrayIndex); } // 0xB6790B02AB53A81E 0xBB120CFC
	static float _ARRAY_VALUE_GET_FLOAT(Any* arrayData, int arrayIndex) { return invoke<float>(0x5EFB23FE1415D634, arrayData, arrayIndex); } // 0x5EFB23FE1415D634 0x08AD2CC2
	static char* _ARRAY_VALUE_GET_STRING(Any* arrayData, int arrayIndex) { return invoke<char*>(0xC250F19D1D16764D, arrayData, arrayIndex); } // 0xC250F19D1D16764D 0x93F985A6
	static Vector3 _ARRAY_VALUE_GET_VECTOR3(Any* arrayData, int arrayIndex) { return invoke<Vector3>(0xFFFE2DE388037E54, arrayData, arrayIndex); } // 0xFFFE2DE388037E54 0x80E3DA55
	static Any* _ARRAY_VALUE_GET_OBJECT(Any* arrayData, int arrayIndex) { return invoke<Any*>(0xB13A070E8D2CC571, arrayData, arrayIndex); } // 0xB13A070E8D2CC571 0xECE81278
	static int _ARRAY_VALUE_GET_SIZE(Any* arrayData) { return invoke<int>(0x685173272EC83DA9, arrayData); } // 0x685173272EC83DA9 0xA8A21766
	static int _ARRAY_VALUE_GET_TYPE(Any* arrayData, int arrayIndex) { return invoke<int>(0x4C58F55F20941087, arrayData, arrayIndex); } // 0x4C58F55F20941087 0xFA2402C8
}

namespace FIRE
{
	static int START_SCRIPT_FIRE(float X, float Y, float Z, int maxChildren, BOOL isGasFire) { return invoke<int>(0x8A89734A265B8974, X, Y, Z, maxChildren, isGasFire); } // 0x8A89734A265B8974 0xE7529357
	static void REMOVE_SCRIPT_FIRE(int fireHandle) { invoke<Void>(0x44E994D596DB215A, fireHandle); } // 0x44E994D596DB215A 0x6B21FE26
	static Any START_ENTITY_FIRE(Entity entity) { return invoke<Any>(0x5EE43194AFB65DCC, entity); } // 0x5EE43194AFB65DCC 0x8928428E
	static void STOP_ENTITY_FIRE(Entity entity) { invoke<Void>(0x07D0F66D0368BB35, entity); } // 0x07D0F66D0368BB35 0xCE8C9066
	static BOOL IS_ENTITY_ON_FIRE(Entity entity) { return invoke<BOOL>(0x03767DFC5EE2B0C6, entity); } // 0x03767DFC5EE2B0C6 0x8C73E64F
	static int GET_NUMBER_OF_FIRES_IN_RANGE(float x, float y, float z, float radius) { return invoke<int>(0x08A593150B122791, x, y, z, radius); } // 0x08A593150B122791 0x654D93B7
	static void STOP_FIRE_IN_RANGE(float x, float y, float z, float radius) { invoke<Void>(0x8F088665928570EA, x, y, z, radius); } // 0x8F088665928570EA 0x725C7205
	static BOOL GET_CLOSEST_FIRE_POS(Vector3* outPosition, float x, float y, float z) { return invoke<BOOL>(0xC17DD6C225DE4EB8, outPosition, x, y, z); } // 0xC17DD6C225DE4EB8 0xC4977B47
	static void ADD_EXPLOSION(float x, float y, float z, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake) { invoke<Void>(0x3F46E145DB7AB5E4, x, y, z, explosionType, damageScale, isAudible, isInvisible, cameraShake); } // 0x3F46E145DB7AB5E4 0x10AF5258
	static void ADD_OWNED_EXPLOSION(Ped ped, float x, float y, float z, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake) { invoke<Void>(0x7DDB09798E65BAEB, ped, x, y, z, explosionType, damageScale, isAudible, isInvisible, cameraShake); } // 0x7DDB09798E65BAEB 0x27EE0D67
	static void _ADD_SPECFX_EXPLOSION(float x, float y, float z, int explosionType, Hash explosionFx, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake) { invoke<Void>(0xED2234D058AF6F99, x, y, z, explosionType, explosionFx, damageScale, isAudible, isInvisible, cameraShake); } // 0xED2234D058AF6F99 0xCF358946
	static BOOL IS_EXPLOSION_IN_AREA(int explosionType, float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<BOOL>(0x8FDFF30DFDA2BBA8, explosionType, x1, y1, z1, x2, y2, z2); } // 0x8FDFF30DFDA2BBA8 0xFB40075B
	static Any _0x70FDBF7996069E4D(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<Any>(0x70FDBF7996069E4D, p0, p1, p2, p3, p4, p5, p6); } // 0x70FDBF7996069E4D
	static BOOL IS_EXPLOSION_IN_SPHERE(int explosionType, float x, float y, float z, float radius) { return invoke<BOOL>(0x3C04DDC5730997E5, explosionType, x, y, z, radius); } // 0x3C04DDC5730997E5 0xD455A7F3
	static BOOL IS_EXPLOSION_IN_ANGLED_AREA(int explosionType, float x1, float y1, float z1, float x2, float y2, float z2, float angle) { return invoke<BOOL>(0xB52F3660F2D6402D, explosionType, x1, y1, z1, x2, y2, z2, angle); } // 0xB52F3660F2D6402D 0x0128FED9
	static Entity _GET_PED_INSIDE_EXPLOSION_AREA(int explosionType, float x1, float y1, float z1, float x2, float y2, float z2, float radius) { return invoke<Entity>(0xA8D8B790C2F14345, explosionType, x1, y1, z1, x2, y2, z2, radius); } // 0xA8D8B790C2F14345 0xAEC0D176
}

namespace DECISIONEVENT
{
	static void SET_DECISION_MAKER(Ped ped, Hash name) { invoke<Void>(0xE0157A41E8F9EBB3, ped, name); } // 0xE0157A41E8F9EBB3 0x19CEAC9E
	static void CLEAR_DECISION_MAKER_EVENT_RESPONSE(Hash name, int type) { invoke<Void>(0x757077E6DE7D5B44, name, type); } // 0x757077E6DE7D5B44 0x07ABD94D
	static void BLOCK_DECISION_MAKER_EVENT(Hash name, int type) { invoke<Void>(0x89C3FD802851E6B3, name, type); } // 0x89C3FD802851E6B3 0x57506EA6
	static void UNBLOCK_DECISION_MAKER_EVENT(Hash name, int type) { invoke<Void>(0xD7D0765485F52282, name, type); } // 0xD7D0765485F52282 0x62A3161D
	static ScrHandle ADD_SHOCKING_EVENT_AT_POSITION(int type, float x, float y, float z, float duration) { return invoke<ScrHandle>(0xC36D55567F4E06F2, type, x, y, z, duration); } // 0xC36D55567F4E06F2 0x0B30F779
	static ScrHandle ADD_SHOCKING_EVENT_FOR_ENTITY(int type, Entity entity, float duration) { return invoke<ScrHandle>(0x20D29FB605ADAC06, type, entity, duration); } // 0x20D29FB605ADAC06 0xA81B5B71
	static BOOL IS_SHOCKING_EVENT_IN_SPHERE(int type, float x, float y, float z, float radius) { return invoke<BOOL>(0xE11AC3274070664E, type, x, y, z, radius); } // 0xE11AC3274070664E 0x2F98823E
	static BOOL REMOVE_SHOCKING_EVENT(ScrHandle event) { return invoke<BOOL>(0x5E21E9DCEAD267B6, event); } // 0x5E21E9DCEAD267B6 0xF82D5A87
	static void REMOVE_ALL_SHOCKING_EVENTS(BOOL p0) { invoke<Void>(0xC79AECB5F24D683F, p0); } // 0xC79AECB5F24D683F 0x64DF6282
	static void REMOVE_SHOCKING_EVENT_SPAWN_BLOCKING_AREAS() { invoke<Void>(0xC62A69B17D4186AD); } // 0xC62A69B17D4186AD 0xA0CE89C8
	static void SUPPRESS_SHOCKING_EVENTS_NEXT_FRAME() { invoke<Void>(0x10CFB6F6C616AA61); } // 0x10CFB6F6C616AA61 0x4CC674B5
	static void SUPPRESS_SHOCKING_EVENT_TYPE_NEXT_FRAME(int type) { invoke<Void>(0x211E751E53DED039, type); } // 0x211E751E53DED039 0xA0FDCB82
	static void SUPPRESS_AGITATION_EVENTS_NEXT_FRAME() { invoke<Void>(0x2B3D35571F260178); } // 0x2B3D35571F260178 0x80340396
}

namespace ZONE
{
	static int GET_ZONE_AT_COORDS(float x, float y, float z) { return invoke<int>(0x266CA99CE8653B3C, x, y, z); } // 0x266CA99CE8653B3C 0xC9018181
	static int GET_ZONE_FROM_NAME_ID(char* zoneName) { return invoke<int>(0x8B1D9E49321050FD, zoneName); } // 0x8B1D9E49321050FD 0x8EC68304
	static int GET_ZONE_POPSCHEDULE(int zoneId) { return invoke<int>(0xCD5F5DB3C0666D25, zoneId); } // 0xCD5F5DB3C0666D25 0x20AB2FC9
	static char* GET_NAME_OF_ZONE(float x, float y, float z) { return invoke<char*>(0xE5686F221201A131, x, y, z); } // 0xE5686F221201A131 0x7875CE91
	static void SET_ZONE_ENABLED(int zoneId, BOOL toggle) { invoke<Void>(0xBED84675CFFD4D16, zoneId, toggle); } // 0xBED84675CFFD4D16 0x04E21B03
	static int GET_ZONE_SCUMMINESS(int zoneId) { return invoke<int>(0x1E4575495E07790F, zoneId); } // 0x1E4575495E07790F 0xB2FB5C4C
	static void OVERRIDE_POPSCHEDULE_VEHICLE_MODEL(int scheduleId, Hash vehicleHash) { invoke<Void>(0x835CBAF495D58305, scheduleId, vehicleHash); } // 0x835CBAF495D58305 0x3F0A3680
	static void CLEAR_POPSCHEDULE_OVERRIDE_VEHICLE_MODEL(int scheduleId) { invoke<Void>(0x02A1BDF65F91D761, scheduleId); } // 0x02A1BDF65F91D761 0x7A72A24E
	static Hash GET_HASH_OF_MAP_AREA_AT_COORDS(float x, float y, float z) { return invoke<Hash>(0x369F7C4FB0B633FC, x, y, z); } // 0x369F7C4FB0B633FC 0xB5C5C99B
}

namespace ROPE
{
	static Object ADD_ROPE(float x, float y, float z, float rotX, float rotY, float rotZ, float length, int ropeType, float maxLength, float minLength, float p10, BOOL p11, BOOL p12, BOOL rigid, float p14, BOOL breakWhenShot, Any* unkPtr) { return invoke<Object>(0xE3500377256EC3AD, x, y, z, rotX, rotY, rotZ, length, ropeType, maxLength, minLength, p10, p11, p12, rigid, p14, breakWhenShot, unkPtr); } // 0xE3500377256EC3AD 0xA592EC74
	static void DELETE_ROPE(Object* rope) { invoke<Void>(0x98BAB9D3382D040F, rope); } // 0x98BAB9D3382D040F 0x748D72AF
	static void DELETE_CHILD_ROPE(Object rope) { invoke<Void>(0x3746D33DFFDC5621, rope); } // 0x3746D33DFFDC5621 0xB19B4706
	static BOOL DOES_ROPE_EXIST(Object* rope) { return invoke<BOOL>(0x06F48F9878BD3FA6, rope); } // 0x06F48F9878BD3FA6 0x66E4A3AC
	static void ROPE_DRAW_SHADOW_ENABLED(Object* rope, BOOL toggle) { invoke<Void>(0x27A060326DD67C74, rope, toggle); } // 0x27A060326DD67C74 0x51523B8C
	static void LOAD_ROPE_DATA(Object rope, char* rope_preset) { invoke<Void>(0xE8D81C70FD40642E, rope, rope_preset); } // 0xE8D81C70FD40642E 0x9E8F1644
	static void PIN_ROPE_VERTEX(Object rope, int vertex, float x, float y, float z) { invoke<Void>(0x10F46271967EA8E0, rope, vertex, x, y, z); } // 0x10F46271967EA8E0 0xAE1D101B
	static void UNPIN_ROPE_VERTEX(Object rope, int vertex) { invoke<Void>(0xD68AA4915EB24022, rope, vertex); } // 0xD68AA4915EB24022 0xB30B552F
	static int GET_ROPE_VERTEX_COUNT(Object rope) { return invoke<int>(0x217887D21B641698, rope); } // 0x217887D21B641698 0x5131CD2C
	static void ATTACH_ENTITIES_TO_ROPE(Object rope, Entity ent1, Entity ent2, float ent1_x, float ent1_y, float ent1_z, float ent2_x, float ent2_y, float ent2_z, float length, BOOL p10, BOOL p11, Any* p12, Any* p13) { invoke<Void>(0x21E051BEF5FFA09C, rope, ent1, ent2, ent1_x, ent1_y, ent1_z, ent2_x, ent2_y, ent2_z, length, p10, p11, p12, p13); } // 0x21E051BEF5FFA09C 0x7508668F
	static void ATTACH_ROPE_TO_ENTITY(Object rope, Entity entity, float x, float y, float z, BOOL p5) { invoke<Void>(0xAFE0275DF9EA9A08, rope, entity, x, y, z, p5); } // 0xAFE0275DF9EA9A08 0xB25D9536
	static void DETACH_ROPE_FROM_ENTITY(Object rope, Entity entity) { invoke<Void>(0xB887985276063C0C, rope, entity); } // 0xB887985276063C0C 0x3E720BEE
	static void ROPE_SET_UPDATE_PINVERTS(Object rope) { invoke<Void>(0x898846CE97E792E1, rope); } // 0x898846CE97E792E1 0xEAF291A0
	static void _0xCB4951CEACC38842(Any p0, Any p1) { invoke<Void>(0xCB4951CEACC38842, p0, p1); } // 0xCB4951CEACC38842 0x80DB77A7
	static void _0xFFD5F8B49BA8BDC0(Any p0, BOOL p1) { invoke<Void>(0xFFD5F8B49BA8BDC0, p0, p1); } // 0xFFD5F8B49BA8BDC0 0xC67D5CF6
	static BOOL _0xFF22741366DF8D9F(Any* p0) { return invoke<BOOL>(0xFF22741366DF8D9F, p0); } // 0xFF22741366DF8D9F 0x7A18BB9C
	static Vector3 GET_ROPE_LAST_VERTEX_COORD(Object rope) { return invoke<Vector3>(0xB0034D17740813F0, rope); } // 0xB0034D17740813F0 0x91F6848B
	static Vector3 GET_ROPE_VERTEX_COORD(Object rope, int vertex) { return invoke<Vector3>(0x4E4A73621DCDE6FA, rope, vertex); } // 0x4E4A73621DCDE6FA 0x84374452
	static void START_ROPE_WINDING(Object rope) { invoke<Void>(0xB9083920D98E5846, rope); } // 0xB9083920D98E5846 0x5187BED3
	static void STOP_ROPE_WINDING(Object rope) { invoke<Void>(0x8B79E7CDBAB21FAD, rope); } // 0x8B79E7CDBAB21FAD 0x46826B53
	static void START_ROPE_UNWINDING_FRONT(Object rope) { invoke<Void>(0x0920A0D05330FCEC, rope); } // 0x0920A0D05330FCEC 0xFC0DB4C3
	static void STOP_ROPE_UNWINDING_FRONT(Object rope) { invoke<Void>(0x45A6C5ADBE64E1E2, rope); } // 0x45A6C5ADBE64E1E2 0x2EEDB18F
	static void ROPE_CONVERT_TO_SIMPLE(Object rope) { invoke<Void>(0x18EDCD13CAC32E0B, rope); } // 0x18EDCD13CAC32E0B 0x43E92628
	static void ROPE_LOAD_TEXTURES() { invoke<Void>(0x4243490B189E7009); } // 0x4243490B189E7009 0xBA97CE91
	static BOOL ROPE_ARE_TEXTURES_LOADED() { return invoke<BOOL>(0x878B5F0BBCDDFC99); } // 0x878B5F0BBCDDFC99 0x5FDC1047
	static void ROPE_UNLOAD_TEXTURES() { invoke<Void>(0x268C2DC471046803); } // 0x268C2DC471046803 0x584463E0
	static BOOL _0x38B898681D33571D(Object rope) { return invoke<BOOL>(0x38B898681D33571D, rope); } // 0x38B898681D33571D
	static void _0x7C3E143C777B1295(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13) { invoke<Void>(0x7C3E143C777B1295, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13); } // 0x7C3E143C777B1295 0x106BA127
	static void _0xB2ADBEBAEF2226DA(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xB2ADBEBAEF2226DA, p0, p1, p2); } // 0xB2ADBEBAEF2226DA 0x7C6F7668
	static void _0x265B14415C902D05(Any p0, Any p1) { invoke<Void>(0x265B14415C902D05, p0, p1); } // 0x265B14415C902D05 0x686672DD
	static float _GET_ROPE_LENGTH(Object rope) { return invoke<float>(0xA1E0D2374D1F63C5, rope); } // 0xA1E0D2374D1F63C5 0xFD309DC8
	static void ROPE_FORCE_LENGTH(Object rope, float length) { invoke<Void>(0x80A28E760A1AA1C2, rope, length); } // 0x80A28E760A1AA1C2 0xABF3130F
	static void ROPE_RESET_LENGTH(Object rope, BOOL length) { invoke<Void>(0x7DD033D7ECC47620, rope, length); } // 0x7DD033D7ECC47620 0xC8A423A3
	static void APPLY_IMPULSE_TO_CLOTH(float posX, float posY, float posZ, float vecX, float vecY, float vecZ, float impulse) { invoke<Void>(0xC94DB03FCCF2BCFA, posX, posY, posZ, vecX, vecY, vecZ, impulse); } // 0xC94DB03FCCF2BCFA 0xA2A5C9FE
	static void SET_DAMPING(Object rope, int vertex, float value) { invoke<Void>(0x0E3A69653FDD1984, rope, vertex, value); } // 0x0E3A69653FDD1984 0xCFB37773
	static void ACTIVATE_PHYSICS(Entity entity) { invoke<Void>(0x87C7282B1F6CFE6C, entity); } // 0x87C7282B1F6CFE6C 0x031711B8
	static void SET_CGOFFSET(Object rope, float x, float y, float z) { invoke<Void>(0x369E81C55A5BFA37, rope, x, y, z); } // 0x369E81C55A5BFA37 0x59910AB2
	static Vector3 GET_CGOFFSET(Object rope) { return invoke<Vector3>(0x50A49B06D77E6B5F, rope); } // 0x50A49B06D77E6B5F 0x49A11F0D
	static void SET_CG_AT_BOUNDCENTER(Object rope) { invoke<Void>(0x3BA6064318DD03B7, rope); } // 0x3BA6064318DD03B7 0xA5B55421
	static void BREAK_ENTITY_GLASS(Any p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, Any p9, BOOL p10) { invoke<Void>(0x0C6B80A91A175C1C, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); } // 0x0C6B80A91A175C1C 0xD0E0402F
	static void SET_DISABLE_BREAKING(Object rope, BOOL enabled) { invoke<Void>(0x776E1A9DB1D06893, rope, enabled); } // 0x776E1A9DB1D06893 0xEE77C326
	static void _0xB816942B1A08138B(Any p0) { invoke<Void>(0xB816942B1A08138B, p0); } // 0xB816942B1A08138B
	static void SET_DISABLE_FRAG_DAMAGE(Object object, BOOL toggle) { invoke<Void>(0xA8F53BDC9E5639D7, object, toggle); } // 0xA8F53BDC9E5639D7 0x97269DC8
}

namespace WATER
{
	static BOOL GET_WATER_HEIGHT(float x, float y, float z, float* height) { return invoke<BOOL>(0x44C71377DAE09DDF, x, y, z, height); } // 0x44C71377DAE09DDF 0xD864E17C
	static BOOL GET_WATER_HEIGHT_NO_WAVES(float x, float y, float z, float* height) { return invoke<BOOL>(0xC325BBAB9C068E91, x, y, z, height); } // 0xC325BBAB9C068E91 0x262017F8
	static BOOL TEST_PROBE_AGAINST_WATER(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) { return invoke<BOOL>(0x9BD6D9E34A208484, p0, p1, p2, p3, p4, p5, p6); } // 0x9BD6D9E34A208484 0xAA4AE00C
	static BOOL TEST_PROBE_AGAINST_ALL_WATER(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { return invoke<BOOL>(0x9C0E0FA1007A5352, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x9C0E0FA1007A5352 0x4A962D55
	static BOOL TEST_VERTICAL_PROBE_AGAINST_ALL_WATER(float x, float y, float z, Any p3, Any* p4) { return invoke<BOOL>(0x5F9EBD93CAB7FE43, x, y, z, p3, p4); } // 0x5F9EBD93CAB7FE43 0x4C71D143
	static void MODIFY_WATER(float x, float y, float radius, float height) { invoke<Void>(0xBD4383A160E6470D, x, y, radius, height); } // 0xBD4383A160E6470D 0xC49E005A
	static int _0xB8DA5A42866DE29C(float x, float y, float z, float radius, float unk) { return invoke<int>(0xB8DA5A42866DE29C, x, y, z, radius, unk); } // 0xB8DA5A42866DE29C
	static void _0xF7D0E36DCC08DC7A(int p0) { invoke<Void>(0xF7D0E36DCC08DC7A, p0); } // 0xF7D0E36DCC08DC7A
	static void _SET_WAVES_INTENSITY(float intensity) { invoke<Void>(0x10337EBC9FAA6043, intensity); } // 0x10337EBC9FAA6043
	static float _GET_WAVES_INTENSITY() { return invoke<float>(0xAAC45BF78F52587E); } // 0xAAC45BF78F52587E
	static void _RESET_WAVES_INTENSITY() { invoke<Void>(0xF783D5A0108978F9); } // 0xF783D5A0108978F9
}

namespace WORLDPROBE
{
	static int START_SHAPE_TEST_LOS_PROBE(float x1, float y1, float z1, float x2, float y2, float z2, int flags, Entity entity, int p8) { return invoke<int>(0xEA2B91A5203A20DF, x1, y1, z1, x2, y2, z2, flags, entity, p8); } // 0xEA2B91A5203A20DF 0xEFAF4BA6
	static int _CAST_RAY_POINT_TO_POINT(float x1, float y1, float z1, float x2, float y2, float z2, int flags, Entity entity, int p8) { return invoke<int>(0x8EE4A0ABB2B98E41, x1, y1, z1, x2, y2, z2, flags, entity, p8); } // 0x8EE4A0ABB2B98E41 0x8251485D
	static Any START_SHAPE_TEST_BOUNDING_BOX(Entity entity, int flags1, int flags2) { return invoke<Any>(0xB100ECFD0B063440, entity, flags1, flags2); } // 0xB100ECFD0B063440 0xCEEAD94B
	static Any START_SHAPE_TEST_BOX(float x, float y, float z, float x1, float y2, float z2, float rotX, float rotY, float rotZ, Any p9, Any p10, Any entity, Any p12) { return invoke<Any>(0xE52AE227D4CCA8C2, x, y, z, x1, y2, z2, rotX, rotY, rotZ, p9, p10, entity, p12); } // 0xE52AE227D4CCA8C2 0x249BC876
	static Any START_SHAPE_TEST_BOUND(Entity entity, int flags1, int flags2) { return invoke<Any>(0x8F6F6B9BDFF28047, entity, flags1, flags2); } // 0x8F6F6B9BDFF28047 0x13BC46C0
	static int START_SHAPE_TEST_CAPSULE(float x1, float y1, float z1, float x2, float y2, float z2, float radius, int flags, Entity entity, int p9) { return invoke<int>(0x4B5383BCA05B8D30, x1, y1, z1, x2, y2, z2, radius, flags, entity, p9); } // 0x4B5383BCA05B8D30 0x591EA833
	static int _0x4F6AD5B687FE80DC(float x1, float y1, float z1, float x2, float y2, float z2, float radius, int flags, Entity entity, Any p9) { return invoke<int>(0x4F6AD5B687FE80DC, x1, y1, z1, x2, y2, z2, radius, flags, entity, p9); } // 0x4F6AD5B687FE80DC 0x4559460A
	static Any _0x5946BF84C47CF78C(Any p0, Any p1, Any p2, Any p3, Any p4) { return invoke<Any>(0x5946BF84C47CF78C, p0, p1, p2, p3, p4); } // 0x5946BF84C47CF78C
	static int GET_SHAPE_TEST_RESULT(int rayHandle, BOOL* hit, Vector3* endCoords, Vector3* surfaceNormal, Entity* entityHit) { return invoke<int>(0x20122FD3E8B8C933, rayHandle, hit, endCoords, surfaceNormal, entityHit); } // 0x20122FD3E8B8C933 0xF3C2875A
	static int _GET_SHAPE_TEST_RESULT_EX(int rayHandle, BOOL* hit, Vector3* endCoords, Vector3* surfaceNormal, Hash* _materialHash, Entity* entityHit) { return invoke<int>(0xA31DD84CEECDE078, rayHandle, hit, endCoords, surfaceNormal, _materialHash, entityHit); } // 0xA31DD84CEECDE078 0x4301E10C
	static void _0x39DE885984C1A1CB(Entity p0) { invoke<Void>(0x39DE885984C1A1CB, p0); } // 0x39DE885984C1A1CB 0xEC2AAF06
}

namespace NETWORK
{
	static BOOL NETWORK_IS_SIGNED_IN() { return invoke<BOOL>(0x98ECB3AD32B89920); } // 0x98ECB3AD32B89920 0xADD0B40F
	static BOOL NETWORK_IS_SIGNED_ONLINE() { return invoke<BOOL>(0x6C119F3638AC7ABE); } // 0x6C119F3638AC7ABE 0x6E5BDCE2
	static BOOL _0xF16869E6293CD882() { return invoke<BOOL>(0xF16869E6293CD882); } // 0xF16869E6293CD882
	static Any _0x2869A5513B1D6382() { return invoke<Any>(0x2869A5513B1D6382); } // 0x2869A5513B1D6382
	static Any _0x4FAB7C7199BD4411() { return invoke<Any>(0x4FAB7C7199BD4411); } // 0x4FAB7C7199BD4411
	static Any _0x8D5D226E2B8B8ACA() { return invoke<Any>(0x8D5D226E2B8B8ACA); } // 0x8D5D226E2B8B8ACA
	static Any _0x5A52B56677678DDE() { return invoke<Any>(0x5A52B56677678DDE); } // 0x5A52B56677678DDE
	static BOOL _NETWORK_ARE_ROS_AVAILABLE() { return invoke<BOOL>(0xA50BC4F5AE68D0BA); } // 0xA50BC4F5AE68D0BA 0x3FB40673
	static BOOL _0xD3ECCA9D8A950867() { return invoke<BOOL>(0xD3ECCA9D8A950867); } // 0xD3ECCA9D8A950867
	static BOOL NETWORK_IS_CLOUD_AVAILABLE() { return invoke<BOOL>(0x877FC5FAF7DC9BC5); } // 0x877FC5FAF7DC9BC5 0xC7FF5AFC
	static Any _0x0A607CC604F09A55() { return invoke<Any>(0x0A607CC604F09A55); } // 0x0A607CC604F09A55 0x66EC713F
	static Any _0x783051BC9CB4FEFF() { return invoke<Any>(0x783051BC9CB4FEFF); } // 0x783051BC9CB4FEFF 0x358D1D77
	static BOOL NETWORK_IS_HOST() { return invoke<BOOL>(0xB07624F7A9F16680); } // 0xB07624F7A9F16680 0xE46AC10F
	static Any _0x0799371240FC4117() { return invoke<Any>(0x0799371240FC4117); } // 0x0799371240FC4117
	static BOOL _0xBE394AC595FDB9CA() { return invoke<BOOL>(0xBE394AC595FDB9CA); } // 0xBE394AC595FDB9CA
	static BOOL NETWORK_HAVE_ONLINE_PRIVILEGES() { return invoke<BOOL>(0x8AB33CE0431CEDCB); } // 0x8AB33CE0431CEDCB 0xEF63BFDF
	static BOOL _0x26CBBEAE27F89922() { return invoke<BOOL>(0x26CBBEAE27F89922); } // 0x26CBBEAE27F89922
	static BOOL _0x5DC8C64FE18EADF7(Any p0) { return invoke<BOOL>(0x5DC8C64FE18EADF7, p0); } // 0x5DC8C64FE18EADF7 0x1F88819D
	static BOOL _0xD4AA13DCCEC54C48(Any p0, Any p1) { return invoke<BOOL>(0xD4AA13DCCEC54C48, p0, p1); } // 0xD4AA13DCCEC54C48 0x2D817A5E
	static BOOL _0xD03981B8358C668D(Any p0, BOOL p1) { return invoke<BOOL>(0xD03981B8358C668D, p0, p1); } // 0xD03981B8358C668D
	static BOOL _0x65FCCBD8772098C3(Any p0, Any p1, BOOL p2) { return invoke<BOOL>(0x65FCCBD8772098C3, p0, p1, p2); } // 0x65FCCBD8772098C3 0xBB54AA3D
	static BOOL _0xF96D9E5EB6A76AB7(Any p0, Any p1, BOOL p2) { return invoke<BOOL>(0xF96D9E5EB6A76AB7, p0, p1, p2); } // 0xF96D9E5EB6A76AB7
	static Any _0xA97EA4AF4A03DC2E() { return invoke<Any>(0xA97EA4AF4A03DC2E); } // 0xA97EA4AF4A03DC2E
	static Any _0xDE66F722C23AD184() { return invoke<Any>(0xDE66F722C23AD184); } // 0xDE66F722C23AD184
	static Any _0x5685E31ECBB67EC3() { return invoke<Any>(0x5685E31ECBB67EC3); } // 0x5685E31ECBB67EC3
	static Any _0x6C8E92D4F56B150E() { return invoke<Any>(0x6C8E92D4F56B150E); } // 0x6C8E92D4F56B150E
	static void _0x78F3D63925EE827E() { invoke<Void>(0x78F3D63925EE827E); } // 0x78F3D63925EE827E
	static BOOL NETWORK_CAN_BAIL() { return invoke<BOOL>(0x5913BA6DFBB6E3E3); } // 0x5913BA6DFBB6E3E3 0x60E1FEDF
	static void NETWORK_BAIL() { invoke<Void>(0x3AB4D531995C4AB3); } // 0x3AB4D531995C4AB3 0x87D79A04
	static void _0xEECEB4B8D361D963() { invoke<Void>(0xEECEB4B8D361D963); } // 0xEECEB4B8D361D963 0x96E28FE2
	static BOOL _GET_MP_LOADING_STATE(int* loadingState) { return invoke<BOOL>(0x9CFD6DF28398BB96, loadingState); } // 0x9CFD6DF28398BB96 0xA520B982
	static BOOL NETWORK_IS_MULTIPLAYER_DISABLED() { return invoke<BOOL>(0xDAE89A194C4B5BC9); } // 0xDAE89A194C4B5BC9 0x05518C0F
	static BOOL NETWORK_CAN_ENTER_MULTIPLAYER() { return invoke<BOOL>(0x9CC92E01B2C6D1F4); } // 0x9CC92E01B2C6D1F4 0x4A23B9C9
	static Any NETWORK_SESSION_ENTER(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<Any>(0x4C79ABCEC09F0D2C, p0, p1, p2, p3, p4, p5); } // 0x4C79ABCEC09F0D2C 0x543CD2BE
	static BOOL _0x35D0D6827EE5F466(int p0, int p1, int maxPlayers, BOOL p3) { return invoke<BOOL>(0x35D0D6827EE5F466, p0, p1, maxPlayers, p3); } // 0x35D0D6827EE5F466 0x4E53202A
	static BOOL _0xEF6FD2734CAF0CED(int p0, int p1, int p2, int maxPlayers, BOOL p4) { return invoke<BOOL>(0xEF6FD2734CAF0CED, p0, p1, p2, maxPlayers, p4); } // 0xEF6FD2734CAF0CED 0xD7624E6B
	static BOOL _0xD1AE7F6157DA4451(Any p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0xD1AE7F6157DA4451, p0, p1, p2, p3); } // 0xD1AE7F6157DA4451 0x3F75CC38
	static BOOL NETWORK_SESSION_HOST(int p0, int maxPlayers, BOOL p2) { return invoke<BOOL>(0x66F1DD24FBF8D9E3, p0, maxPlayers, p2); } // 0x66F1DD24FBF8D9E3 0x6716460F
	static BOOL NETWORK_SESSION_HOST_CLOSED(int p0, int maxPlayers) { return invoke<BOOL>(0x638A1F1A462569A7, p0, maxPlayers); } // 0x638A1F1A462569A7 0x8AC9EA19
	static BOOL NETWORK_SESSION_HOST_FRIENDS_ONLY(int p0, int maxPlayers) { return invoke<BOOL>(0x48965A92A56BE51B, p0, maxPlayers); } // 0x48965A92A56BE51B 0x26864403
	static BOOL _0x4C9507F8E50FC6AF() { return invoke<BOOL>(0x4C9507F8E50FC6AF); } // 0x4C9507F8E50FC6AF 0x56E75FE4
	static BOOL _0x505CA008E5D66AC1() { return invoke<BOOL>(0x505CA008E5D66AC1); } // 0x505CA008E5D66AC1 0xA95299B9
	static BOOL _0xB61E69EF42A9B490() { return invoke<BOOL>(0xB61E69EF42A9B490); } // 0xB61E69EF42A9B490 0x3D2C1916
	static BOOL _0xBBA3C43AC37CB882() { return invoke<BOOL>(0xBBA3C43AC37CB882); } // 0xBBA3C43AC37CB882 0xDB67785D
	static BOOL NETWORK_SESSION_END(BOOL p0, BOOL p1) { return invoke<BOOL>(0x19E4917F00FC0756, p0, p1); } // 0x19E4917F00FC0756 0xBCACBEA2
	static void NETWORK_SESSION_KICK_PLAYER(Player player) { invoke<Void>(0x2377D4F26EC08B10, player); } // 0x2377D4F26EC08B10 0x1E20138A
	static BOOL _NETWORK_SESSION_ARE_PLAYERS_VOTING_TO_KICK(Player player) { return invoke<BOOL>(0x941F4755FECA1FA3, player); } // 0x941F4755FECA1FA3 0x8A559D26
	static Any _0x49A617823ED9A90B() { return invoke<Any>(0x49A617823ED9A90B); } // 0x49A617823ED9A90B
	static Any _0xCB34DC3F7514A033() { return invoke<Any>(0xCB34DC3F7514A033); } // 0xCB34DC3F7514A033
	static void _0xC8E6808E74392797(int p0) { invoke<Void>(0xC8E6808E74392797, p0); } // 0xC8E6808E74392797 0x3C3E2AB6
	static void _0x0D285199D49FE01A(Any p0, Any p1) { invoke<Void>(0x0D285199D49FE01A, p0, p1); } // 0x0D285199D49FE01A 0x5F29A7E0
	static Any _0x851E563D93D732B7(Any p0) { return invoke<Any>(0x851E563D93D732B7, p0); } // 0x851E563D93D732B7 0x36EAD960
	static void _0xDAFC6C405B58E9C7(Any p0) { invoke<Void>(0xDAFC6C405B58E9C7, p0); } // 0xDAFC6C405B58E9C7 0x5BE529F7
	static void _0xEEBC7C7CF6F84D7C(Any p0) { invoke<Void>(0xEEBC7C7CF6F84D7C, p0); } // 0xEEBC7C7CF6F84D7C 0x454C7B67
	static void _0x452C227A360B9E24(Any p0) { invoke<Void>(0x452C227A360B9E24, p0); } // 0x452C227A360B9E24 0xE5961511
	static void _0x0C296B5FEAF36C37(BOOL p0) { invoke<Void>(0x0C296B5FEAF36C37, p0); } // 0x0C296B5FEAF36C37 0xAE396263
	static void _0x9D3FB07C04E5609E(Any p0) { invoke<Void>(0x9D3FB07C04E5609E, p0); } // 0x9D3FB07C04E5609E 0x913FD7D6
	static void _0x9D5CF505716B3DFC(BOOL p0) { invoke<Void>(0x9D5CF505716B3DFC, p0); } // 0x9D5CF505716B3DFC 0xB3D9A67F
	static void _0x3F652FF4F125E19B(Any p0) { invoke<Void>(0x3F652FF4F125E19B, p0); } // 0x3F652FF4F125E19B 0x6CC062FC
	static void _0x746B1F2FAC9D62A3() { invoke<Void>(0x746B1F2FAC9D62A3); } // 0x746B1F2FAC9D62A3 0x57F9BC83
	static void _0x5B5011706DF2B84E(BOOL p0) { invoke<Void>(0x5B5011706DF2B84E, p0); } // 0x5B5011706DF2B84E 0xF3768F90
	static void NETWORK_ADD_FOLLOWERS(int* p0, int p1) { invoke<Void>(0xA6553F4B58920C6D, p0, p1); } // 0xA6553F4B58920C6D 0x0EC62629
	static void NETWORK_CLEAR_FOLLOWERS() { invoke<Void>(0x836D41645A09325F); } // 0x836D41645A09325F 0x5E557307
	static void _NETWORK_GET_SERVER_TIME(int* hours, int* minutes, int* seconds) { invoke<Void>(0x79E1846FC13351B6, hours, minutes, seconds); } // 0x79E1846FC13351B6 0x74E8C53E
	static void _0xC536B487C344156E(Any p0) { invoke<Void>(0xC536B487C344156E, p0); } // 0xC536B487C344156E 0x959E43A3
	static BOOL _0x1E13E072CE9D6623(Any p0) { return invoke<BOOL>(0x1E13E072CE9D6623, p0); } // 0x1E13E072CE9D6623 0x7771AB83
	static BOOL _0x8386591173D1796D(Any p0, float p1, float p2, float p3) { return invoke<BOOL>(0x8386591173D1796D, p0, p1, p2, p3); } // 0x8386591173D1796D 0xA13045D4
	static BOOL NETWORK_IS_FINDING_GAMERS() { return invoke<BOOL>(0x4E4934E1E7DC89A0); } // 0x4E4934E1E7DC89A0 0xA6DAA79F
	static Any _0xF009079C472A7060() { return invoke<Any>(0xF009079C472A7060); } // 0xF009079C472A7060 0xBEDC4503
	static int NETWORK_GET_NUM_FOUND_GAMERS() { return invoke<int>(0x2DC3B71DFA6BC083); } // 0x2DC3B71DFA6BC083 0xF4B80C7E
	static BOOL NETWORK_GET_FOUND_GAMER(Any* p0, Any p1) { return invoke<BOOL>(0xB3D7444A893F8E45, p0, p1); } // 0xB3D7444A893F8E45 0xA08C9141
	static void NETWORK_CLEAR_FOUND_GAMERS() { invoke<Void>(0xF534332F44D4821A); } // 0xF534332F44D4821A 0x6AA9A154
	static BOOL _0x12EE684A891E617E(Any* p0) { return invoke<BOOL>(0x12EE684A891E617E, p0); } // 0x12EE684A891E617E 0x42BD0780
	static Any _0x6EAC5D0645F92017() { return invoke<Any>(0x6EAC5D0645F92017); } // 0x6EAC5D0645F92017 0xBEB98840
	static Any _0xB038E478B0E2F5D9() { return invoke<Any>(0xB038E478B0E2F5D9); } // 0xB038E478B0E2F5D9 0x08029970
	static Any _0xBE97804825B1C8E5() { return invoke<Any>(0xBE97804825B1C8E5); } // 0xBE97804825B1C8E5 0xC871E745
	static BOOL _0x4D15A63EA6966ED8(Any* p0, Any p1) { return invoke<BOOL>(0x4D15A63EA6966ED8, p0, p1); } // 0x4D15A63EA6966ED8 0xB5ABC4B4
	static void _0xD61E9B126CB18B54() { invoke<Void>(0xD61E9B126CB18B54); } // 0xD61E9B126CB18B54 0x3F7EDBBD
	static void NETWORK_IS_PLAYER_ANIMATION_DRAWING_SYNCHRONIZED() { invoke<Void>(0x43FBEC17FA367FB5); } // 0x43FBEC17FA367FB5 0x3D6360B5
	static void NETWORK_SESSION_CANCEL_INVITE() { invoke<Void>(0x7A116BE1B739EDD6); } // 0x7A116BE1B739EDD6 0x20317535
	static void _0x6DF5BB7FE1EF4328() { invoke<Void>(0x6DF5BB7FE1EF4328); } // 0x6DF5BB7FE1EF4328 0x3FD49D3B
	static BOOL NETWORK_HAS_PENDING_INVITE() { return invoke<BOOL>(0x3913444F2D49E774); } // 0x3913444F2D49E774 0x0C207D6E
	static Any _0x8BFF0B2FFB148A73() { return invoke<Any>(0x8BFF0B2FFB148A73); } // 0x8BFF0B2FFB148A73 0xFBBAC350
	static Any _0xE0DB71A1B62A0A17() { return invoke<Any>(0xE0DB71A1B62A0A17); } // 0xE0DB71A1B62A0A17 0x0907A6BF
	static Any _0x6C80AA1FBEB7938B() { return invoke<Any>(0x6C80AA1FBEB7938B); } // 0x6C80AA1FBEB7938B 0x6A0BEA60
	static void NETWORK_SESSION_GET_INVITER(int* networkHandle) { invoke<Void>(0x22346F9C81FCD613, networkHandle); } // 0x22346F9C81FCD613 0xE9C6B3FD
	static Any _0x7DB9FEA5D5A1A4F3() { return invoke<Any>(0x7DB9FEA5D5A1A4F3); } // 0x7DB9FEA5D5A1A4F3 0x3EA9D44C
	static Any _0x5B27E448407D54DE() { return invoke<Any>(0x5B27E448407D54DE); } // 0x5B27E448407D54DE
	static void NETWORK_SUPPRESS_INVITE(BOOL toggle) { invoke<Void>(0x2D79B64B28B4286A, toggle); } // 0x2D79B64B28B4286A 0x323DC78C
	static void NETWORK_BLOCK_INVITES(BOOL toggle) { invoke<Void>(0xFD55BD7321D5B2F6, toggle); } // 0xFD55BD7321D5B2F6 0xD156FD1A
	static void _0x95945C179F1088BB(BOOL p0) { invoke<Void>(0x95945C179F1088BB, p0); } // 0x95945C179F1088BB
	static void _0xB334D2D129F1D2FD() { invoke<Void>(0xB334D2D129F1D2FD); } // 0xB334D2D129F1D2FD 0x32B7A076
	static void _0x20796956F8CB65EE(BOOL p0) { invoke<Void>(0x20796956F8CB65EE, p0); } // 0x20796956F8CB65EE 0x0FCE995D
	static void _0x47534EF43AC3CF7D(BOOL p0) { invoke<Void>(0x47534EF43AC3CF7D, p0); } // 0x47534EF43AC3CF7D 0xA639DCA2
	static Any _0xD4BD0DD4D6132524() { return invoke<Any>(0xD4BD0DD4D6132524); } // 0xD4BD0DD4D6132524 0x70ED476A
	static void _0x12C264D6F2033968() { invoke<Void>(0x12C264D6F2033968); } // 0x12C264D6F2033968 0x50507BED
	static void NETWORK_SESSION_HOST_SINGLE_PLAYER(int p0) { invoke<Void>(0x9ADF3BA3FA56DC48, p0); } // 0x9ADF3BA3FA56DC48 0xF3B1CA85
	static void NETWORK_SESSION_LEAVE_SINGLE_PLAYER() { invoke<Void>(0x59BE19F0686A3329); } // 0x59BE19F0686A3329 0xC692F86A
	static BOOL NETWORK_IS_GAME_IN_PROGRESS() { return invoke<BOOL>(0x63C468D583002D23); } // 0x63C468D583002D23 0x09B88E3E
	static BOOL NETWORK_IS_SESSION_ACTIVE() { return invoke<BOOL>(0xAB8EF42F356C8AEC); } // 0xAB8EF42F356C8AEC 0x715CB8C4
	static BOOL NETWORK_IS_IN_SESSION() { return invoke<BOOL>(0x9AD8CE0019487D7C); } // 0x9AD8CE0019487D7C 0x4BC4105E
	static BOOL NETWORK_IS_SESSION_STARTED() { return invoke<BOOL>(0xC5930AF404BD7048); } // 0xC5930AF404BD7048 0x9D854A37
	static BOOL NETWORK_IS_SESSION_BUSY() { return invoke<BOOL>(0x7E6F588395BC4766); } // 0x7E6F588395BC4766 0x8592152D
	static BOOL NETWORK_CAN_SESSION_END() { return invoke<BOOL>(0xFA5F44BBDDEEDD86); } // 0xFA5F44BBDDEEDD86 0xE1FCCDBA
	static void _0xBF32F10A886BAC73(BOOL p0) { invoke<Void>(0xBF32F10A886BAC73, p0); } // 0xBF32F10A886BAC73 0x7017257D
	static Any _0xD61E73433C2CC252() { return invoke<Any>(0xD61E73433C2CC252); } // 0xD61E73433C2CC252 0x4977AC28
	static void _0xA3C0B0DABE0194E2(BOOL p0) { invoke<Void>(0xA3C0B0DABE0194E2, p0); } // 0xA3C0B0DABE0194E2 0xE6EEF8AF
	static void ENABLE_CORMORANT_ROS_CHEATER(int p0, BOOL p1) { invoke<Void>(0x637D088821884364, p0, p1); } // 0x637D088821884364 0x6BB93227
	static Any _0x43FBE319ADC6B4BF() { return invoke<Any>(0x43FBE319ADC6B4BF); } // 0x43FBE319ADC6B4BF
	static void NETWORK_SESSION_VOICE_HOST() { invoke<Void>(0xEA442DB136EE090F); } // 0xEA442DB136EE090F 0x345C2980
	static void NETWORK_SESSION_VOICE_LEAVE() { invoke<Void>(0x8F6CF1874D6F6F16); } // 0x8F6CF1874D6F6F16 0xE566C7DA
	static void _0xBBD8EC1AFF021747(Any* globalPtr) { invoke<Void>(0xBBD8EC1AFF021747, globalPtr); } // 0xBBD8EC1AFF021747 0x9DFD89E6
	static void NETWORK_SET_KEEP_FOCUSPOINT(BOOL p0, Any p1) { invoke<Void>(0xF0DBF0EFC514DD89, p0, p1); } // 0xF0DBF0EFC514DD89 0x075321B5
	static void _0x16A524C5EED0F2B6(Any p0) { invoke<Void>(0x16A524C5EED0F2B6, p0); } // 0x16A524C5EED0F2B6 0x6EFC2FD0
	static Any _0x462BB6BF1879A145() { return invoke<Any>(0x462BB6BF1879A145); } // 0x462BB6BF1879A145 0x60AA4AA1
	static Any _0xF4BAEC8602BC9FDB() { return invoke<Any>(0xF4BAEC8602BC9FDB); } // 0xF4BAEC8602BC9FDB
	static BOOL _0x42DEB42B49D342CC() { return invoke<BOOL>(0x42DEB42B49D342CC); } // 0x42DEB42B49D342CC 0x132CA01E
	static Any NETWORK_SEND_TEXT_MESSAGE(char* message, int* networkHandle) { return invoke<Any>(0x33B33E8F3AF3F058, message, networkHandle); } // 0x33B33E8F3AF3F058 0xAFFEA720
	static void NETWORK_SET_ACTIVITY_SPECTATOR(BOOL toggle) { invoke<Void>(0x77CFAD467F0FF409, toggle); } // 0x77CFAD467F0FF409 0xFC9AD060
	static Any NETWORK_IS_ACTIVITY_SPECTATOR() { return invoke<Any>(0xFCE74EBC857BDE9E); } // 0xFCE74EBC857BDE9E 0xAF329720
	static void NETWORK_SET_ACTIVITY_SPECTATOR_MAX(Any p0) { invoke<Void>(0xEEBD7A57A0FA13F5, p0); } // 0xEEBD7A57A0FA13F5 0x74E0BC0A
	static int NETWORK_GET_ACTIVITY_PLAYER_NUM(BOOL p0) { return invoke<int>(0x45CF4A253EB79C0B, p0); } // 0x45CF4A253EB79C0B 0x31F951FD
	static BOOL NETWORK_IS_ACTIVITY_SPECTATOR_FROM_HANDLE(Player* networkHandle) { return invoke<BOOL>(0xA91C8C4F95008A07, networkHandle); } // 0xA91C8C4F95008A07 0x58F1DF7D
	static Any NETWORK_HOST_TRANSITION(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<Any>(0xB5758AA9B76C31F4, p0, p1, p2, p3, p4, p5); } // 0xB5758AA9B76C31F4 0x146764FB
	static BOOL NETWORK_DO_TRANSITION_QUICKMATCH(Any p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0x2A48334D59D55E15, p0, p1, p2, p3); } // 0x2A48334D59D55E15 0x2FF65C0B
	static BOOL _0x30D30CB351CFA1BF(Any p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0x30D30CB351CFA1BF, p0, p1, p2, p3); } // 0x30D30CB351CFA1BF 0x47D61C99
	static BOOL NETWORK_DO_TRANSITION_QUICKMATCH_WITH_GROUP(Any p0, Any p1, Any p2, Any p3, Any* p4, Any p5) { return invoke<BOOL>(0x8C38E5A6C154A7C9, p0, p1, p2, p3, p4, p5); } // 0x8C38E5A6C154A7C9 0x5CE60A11
	static Any _0x60E77D19FC222579() { return invoke<Any>(0x60E77D19FC222579); } // 0x60E77D19FC222579 0x0D7E5CF9
	static void _0x900E2BAA4B7940EB() { invoke<Void>(0x900E2BAA4B7940EB); } // 0x900E2BAA4B7940EB 0x36A5F2DA
	static Any _0xAE89EB66B5EE67B0() { return invoke<Any>(0xAE89EB66B5EE67B0); } // 0xAE89EB66B5EE67B0
	static Any _0xBD71FBD3B56B5FF1() { return invoke<Any>(0xBD71FBD3B56B5FF1); } // 0xBD71FBD3B56B5FF1
	static BOOL _0xA423AA6F78E454FD() { return invoke<BOOL>(0xA423AA6F78E454FD); } // 0xA423AA6F78E454FD
	static BOOL _0x9CF57E6316796B63() { return invoke<BOOL>(0x9CF57E6316796B63); } // 0x9CF57E6316796B63
	static void _0xF7091E3F853F7D57(BOOL p0) { invoke<Void>(0xF7091E3F853F7D57, p0); } // 0xF7091E3F853F7D57 0x7EF353E1
	static void _0x6728B2AF64255564(BOOL p0) { invoke<Void>(0x6728B2AF64255564, p0); } // 0x6728B2AF64255564 0xF60986FC
	static void NETWORK_SET_TRANSITION_CREATOR_HANDLE(Any* p0) { invoke<Void>(0x58D5E920348BECD4, p0); } // 0x58D5E920348BECD4 0x1DD01FE7
	static void NETWORK_CLEAR_TRANSITION_CREATOR_HANDLE() { invoke<Void>(0xEEFEE886E8D72C66); } // 0xEEFEE886E8D72C66 0x8BB336F7
	static BOOL NETWORK_INVITE_GAMERS_TO_TRANSITION(Any* p0, Any p1) { return invoke<BOOL>(0x016A340B74774C05, p0, p1); } // 0x016A340B74774C05 0x5332E645
	static void NETWORK_SET_GAMER_INVITED_TO_TRANSITION(Any* p0) { invoke<Void>(0xEC9CD927D9920ACC, p0); } // 0xEC9CD927D9920ACC 0x17F1C69D
	static Any NETWORK_LEAVE_TRANSITION() { return invoke<Any>(0xA51093B11BCE1CDA); } // 0xA51093B11BCE1CDA 0x3A3599B7
	static Any NETWORK_LAUNCH_TRANSITION() { return invoke<Any>(0x07AF6CDC8D6B7D02); } // 0x07AF6CDC8D6B7D02 0xE3570BA2
	static void _0x62482D8CEC014F92(BOOL p0) { invoke<Void>(0x62482D8CEC014F92, p0); } // 0x62482D8CEC014F92
	static void NETWORK_BAIL_TRANSITION() { invoke<Void>(0x1559C9E7C4EA6A65); } // 0x1559C9E7C4EA6A65 0xB59D74CA
	static BOOL NETWORK_DO_TRANSITION_TO_GAME(BOOL p0, int maxPlayers) { return invoke<BOOL>(0x95D0FAA72E36999F, p0, maxPlayers); } // 0x95D0FAA72E36999F 0x1B2114D2
	static BOOL NETWORK_DO_TRANSITION_TO_NEW_GAME(BOOL p0, int maxPlayers, BOOL p2) { return invoke<BOOL>(0x27EEAAD69E13C626, p0, maxPlayers, p2); } // 0x27EEAAD69E13C626 0x58AFBE63
	static BOOL NETWORK_DO_TRANSITION_TO_FREEMODE(Any* p0, Any p1, BOOL p2, int players, BOOL p4) { return invoke<BOOL>(0x850D4CA3375684FA, p0, p1, p2, players, p4); } // 0x850D4CA3375684FA 0xC7CB8ADF
	static BOOL NETWORK_DO_TRANSITION_TO_NEW_FREEMODE(Any* p0, Any p1, Any p2, BOOL p3, BOOL p4, BOOL p5) { return invoke<BOOL>(0xC06D8CAA66FB4762, p0, p1, p2, p3, p4, p5); } // 0xC06D8CAA66FB4762 0xAD13375E
	static Any NETWORK_IS_TRANSITION_TO_GAME() { return invoke<Any>(0x961526810AA5BE5E); } // 0x961526810AA5BE5E 0x17146B2B
	static Any NETWORK_GET_TRANSITION_MEMBERS(Any* p0, Any p1) { return invoke<Any>(0x752F2DCCA8E9D7C9, p0, p1); } // 0x752F2DCCA8E9D7C9 0x31F19263
	static void _0xC472AB2A46DA8E26(Any p0, Any p1) { invoke<Void>(0xC472AB2A46DA8E26, p0, p1); } // 0xC472AB2A46DA8E26 0xCEE79711
	static void _0xFF619CCAA39F00F2(Any p0, char* p1, BOOL p2) { invoke<Void>(0xFF619CCAA39F00F2, p0, p1, p2); } // 0xFF619CCAA39F00F2 0xE0C28DB5
	static BOOL NETWORK_SEND_TRANSITION_GAMER_INSTRUCTION(int* netHandle, char* p1, int p2, int p3, BOOL p4) { return invoke<BOOL>(0xDD38B2E2FB74A437, netHandle, p1, p2, p3, p4); } // 0xDD38B2E2FB74A437 0x468B0884
	static BOOL NETWORK_MARK_TRANSITION_GAMER_AS_FULLY_JOINED(Any* p0) { return invoke<BOOL>(0xDA6DFCD83DE01AC1, p0); } // 0xDA6DFCD83DE01AC1 0x03383F57
	static Any NETWORK_IS_TRANSITION_HOST() { return invoke<Any>(0x314ACD5D75F807E3); } // 0x314ACD5D75F807E3 0x0C0900BC
	static BOOL NETWORK_IS_TRANSITION_HOST_FROM_HANDLE(int* netHandle) { return invoke<BOOL>(0xEEAB07212533AD87, netHandle); } // 0xEEAB07212533AD87 0x0E2854C4
	static BOOL NETWORK_GET_TRANSITION_HOST(int* netHandle) { return invoke<BOOL>(0x63FD2D2E73D67B0E, netHandle); } // 0x63FD2D2E73D67B0E 0x73098D40
	static Any NETWORK_IS_IN_TRANSITION() { return invoke<Any>(0xDF5840155D99D7A4); } // 0xDF5840155D99D7A4 0xC3CDB626
	static Any NETWORK_IS_TRANSITION_STARTED() { return invoke<Any>(0x5F18944DAABADCA4); } // 0x5F18944DAABADCA4 0x7917E111
	static Any NETWORK_IS_TRANSITION_BUSY() { return invoke<Any>(0xB685A6886EBF25E9); } // 0xB685A6886EBF25E9 0xA357A2C6
	static Any _0x798C342E76128AF9() { return invoke<Any>(0x798C342E76128AF9); } // 0x798C342E76128AF9 0x8262C70E
	static Any _0x0497DB2B6B10861D() { return invoke<Any>(0x0497DB2B6B10861D); } // 0x0497DB2B6B10861D
	static void _0x66073B7BDE4D42CE() { invoke<Void>(0x66073B7BDE4D42CE); } // 0x66073B7BDE4D42CE 0xC71E607B
	static void _0xC6ED991A16280F39() { invoke<Void>(0xC6ED991A16280F39); } // 0xC6ED991A16280F39 0x82D32D07
	static Any _0xCD4238C8960D2BEA() { return invoke<Any>(0xCD4238C8960D2BEA); } // 0xCD4238C8960D2BEA 0xC901AA9F
	static void _0xC44E16BAED80E5DF(BOOL p0, BOOL p1) { invoke<Void>(0xC44E16BAED80E5DF, p0, p1); } // 0xC44E16BAED80E5DF
	static Any _0xAA3C64A575F4F680() { return invoke<Any>(0xAA3C64A575F4F680); } // 0xAA3C64A575F4F680
	static void _0x833B0A0E55647E68(Any p0) { invoke<Void>(0x833B0A0E55647E68, p0); } // 0x833B0A0E55647E68 0xCCA9C022
	static void _0xB260BF7A1B62623D(Any p0, Any p1) { invoke<Void>(0xB260BF7A1B62623D, p0, p1); } // 0xB260BF7A1B62623D 0x1E5F6AEF
	static void _0x7E704E9E2E2A8562(BOOL p0) { invoke<Void>(0x7E704E9E2E2A8562, p0); } // 0x7E704E9E2E2A8562 0x0532DDD2
	static BOOL NETWORK_HAS_PLAYER_STARTED_TRANSITION(Player player) { return invoke<BOOL>(0x2CDC720BF1216A9F, player); } // 0x2CDC720BF1216A9F 0x4ABD1E59
	static BOOL _IS_TRANSITION_JOINABLE(Player player) { return invoke<BOOL>(0xC87618E985B23DA6, player); } // 0xC87618E985B23DA6 0xCDEBCCE7
	static BOOL NETWORK_JOIN_TRANSITION(Player player) { return invoke<BOOL>(0x7B5BD377428CDAFF, player); } // 0x7B5BD377428CDAFF 0xB054EC4B
	static BOOL NETWORK_HAS_INVITED_GAMER_TO_TRANSITION(Any* p0) { return invoke<BOOL>(0x251E033418C0CD03, p0); } // 0x251E033418C0CD03 0x4F41DF6B
	static BOOL _0xC7AC410CB1C25C9C(Any* p0) { return invoke<BOOL>(0xC7AC410CB1C25C9C, p0); } // 0xC7AC410CB1C25C9C
	static Any NETWORK_IS_ACTIVITY_SESSION() { return invoke<Any>(0xF7271A9481CAC8E3); } // 0xF7271A9481CAC8E3 0x577DAA8A
	static void _0x580A787AD1D03FDF(Any p0) { invoke<Void>(0x580A787AD1D03FDF, p0); } // 0x580A787AD1D03FDF 0x18F03AFD
	static BOOL _NETWORK_SEND_PRESENCE_INVITE(Any* p0, Any* p1, Any p2, Any p3) { return invoke<BOOL>(0x6E15A35C62D240AD, p0, p1, p2, p3); } // 0x6E15A35C62D240AD 0x8B99B72B
	static BOOL _0xB66BA61C4291306D(Any* p0, Any* p1, Any p2, Any p3) { return invoke<BOOL>(0xB66BA61C4291306D, p0, p1, p2, p3); } // 0xB66BA61C4291306D 0x877C0E1C
	static BOOL _0x66043E2537B06628(Any* p0, Any* p1, Any p2, Any p3) { return invoke<BOOL>(0x66043E2537B06628, p0, p1, p2, p3); } // 0x66043E2537B06628
	static Any _0x5C3B4F783CB5D4BB(Any p0) { return invoke<Any>(0x5C3B4F783CB5D4BB, p0); } // 0x5C3B4F783CB5D4BB 0x5E832444
	static Any _0x3D558DD62810C8FA() { return invoke<Any>(0x3D558DD62810C8FA); } // 0x3D558DD62810C8FA 0x3FDA00F3
	static BOOL NETWORK_ACCEPT_PRESENCE_INVITE(Any p0) { return invoke<BOOL>(0xEB39D17A265BF2BB, p0); } // 0xEB39D17A265BF2BB 0xE5DA4CED
	static BOOL NETWORK_REMOVE_PRESENCE_INVITE(Any p0) { return invoke<BOOL>(0xD2AB191A39E655D6, p0); } // 0xD2AB191A39E655D6 0x93C665FA
	static Any NETWORK_GET_PRESENCE_INVITE_ID(Any p0) { return invoke<Any>(0x0A5577A7E8FA2AB3, p0); } // 0x0A5577A7E8FA2AB3 0xD50DF46C
	static Any NETWORK_GET_PRESENCE_INVITE_INVITER(Any p0) { return invoke<Any>(0x1CB0B911AB7D44E5, p0); } // 0x1CB0B911AB7D44E5 0x19EC65D9
	static BOOL NETWORK_GET_PRESENCE_INVITE_HANDLE(Any p0, Any* p1) { return invoke<BOOL>(0xEB55887246483FD7, p0, p1); } // 0xEB55887246483FD7 0xB2451429
	static Any _0x13C3B2A23E8595A5(Any p0) { return invoke<Any>(0x13C3B2A23E8595A5, p0); } // 0x13C3B2A23E8595A5 0xC5E0C989
	static Any _0x80B3BDD4159F75D4(Any p0) { return invoke<Any>(0x80B3BDD4159F75D4, p0); } // 0x80B3BDD4159F75D4 0xA4302183
	static Any _0x8D9C63FD6040D434(Any p0) { return invoke<Any>(0x8D9C63FD6040D434, p0); } // 0x8D9C63FD6040D434 0x51B2D848
	static Any _0xD214913FE3C44A7A(Any p0) { return invoke<Any>(0xD214913FE3C44A7A, p0); } // 0xD214913FE3C44A7A 0x4677C656
	static BOOL _0x1AD5A878D8CD335C(Any p0) { return invoke<BOOL>(0x1AD5A878D8CD335C, p0); } // 0x1AD5A878D8CD335C 0xF5E3401C
	static BOOL _0x08A98D36F51E4F1D(Any p0) { return invoke<BOOL>(0x08A98D36F51E4F1D, p0); } // 0x08A98D36F51E4F1D 0x7D593B4C
	static Any _0x4AC15CCCBF9BC4AB() { return invoke<Any>(0x4AC15CCCBF9BC4AB); } // 0x4AC15CCCBF9BC4AB 0xE96CFE7D
	static Any _0xCEEECEB2732472AE() { return invoke<Any>(0xCEEECEB2732472AE); } // 0xCEEECEB2732472AE 0xAB969F00
	static Any _0x047579D7756C5EA7() { return invoke<Any>(0x047579D7756C5EA7); } // 0x047579D7756C5EA7 0x3242F952
	static void _0x77D006D2A65E5826() { invoke<Void>(0x77D006D2A65E5826); } // 0x77D006D2A65E5826 0x9773F36A
	static void NETWORK_REMOVE_TRANSITION_INVITE(Any* p0) { invoke<Void>(0x0329624FE9E263D6, p0); } // 0x0329624FE9E263D6 0xFDE84CB7
	static void _0xAE9781549A279E90() { invoke<Void>(0xAE9781549A279E90); } // 0xAE9781549A279E90 0xF7134E73
	static void _0x7A82F3B234EBE4E7() { invoke<Void>(0x7A82F3B234EBE4E7); } // 0x7A82F3B234EBE4E7 0xC47352E7
	static BOOL NETWORK_INVITE_GAMERS(Any* p0, Any p1, Any* p2, Any* p3) { return invoke<BOOL>(0xBFEE60F78BA1670F, p0, p1, p2, p3); } // 0xBFEE60F78BA1670F 0x52FB8074
	static BOOL NETWORK_HAS_INVITED_GAMER(Any* p0) { return invoke<BOOL>(0x677418FBB02CE154, p0); } // 0x677418FBB02CE154 0xEC651BC0
	static BOOL NETWORK_GET_CURRENTLY_SELECTED_GAMER_HANDLE_FROM_INVITE_MENU(Any* p0) { return invoke<BOOL>(0x4E358E1580A6BE25, p0); } // 0x4E358E1580A6BE25 0x72BA00CE
	static BOOL NETWORK_SET_CURRENTLY_SELECTED_GAMER_HANDLE_FROM_INVITE_MENU(Any* p0) { return invoke<BOOL>(0xB61D4EEFEBDBEF9B, p0); } // 0xB61D4EEFEBDBEF9B 0xFD95899E
	static void _0x0D34607BF13EE140(Any* p0) { invoke<Void>(0x0D34607BF13EE140, p0); } // 0x0D34607BF13EE140
	static BOOL _0x7D40B088925D9BA2(Any p0, Any* p1) { return invoke<BOOL>(0x7D40B088925D9BA2, p0, p1); } // 0x7D40B088925D9BA2
	static void _0x90855AFF43DB2F15(Any* p0, Any* p1) { invoke<Void>(0x90855AFF43DB2F15, p0, p1); } // 0x90855AFF43DB2F15 0x0808D4CC
	static BOOL FILLOUT_PM_PLAYER_LIST(Any* p0, Any p1, Any p2) { return invoke<BOOL>(0x92A6EDBF01540410, p0, p1, p2); } // 0x92A6EDBF01540410 0xCE40F423
	static BOOL FILLOUT_PM_PLAYER_LIST_WITH_NAMES(Any* p0, Any* p1, Any p2, Any p3) { return invoke<BOOL>(0xAB5B2F0092EAD715, p0, p1, p2, p3); } // 0xAB5B2F0092EAD715 0xB8DF604E
	static BOOL USING_NETWORK_WEAPONTYPE(Any p0) { return invoke<BOOL>(0xEC8B8F028D54DC62, p0); } // 0xEC8B8F028D54DC62 0xF49C1533
	static BOOL _0xA09CA383EB560CD7(Any* p0) { return invoke<BOOL>(0xA09CA383EB560CD7, p0); } // 0xA09CA383EB560CD7
	static Any _0x27F5A01680175AC9() { return invoke<Any>(0x27F5A01680175AC9); } // 0x27F5A01680175AC9 0xA812B6CB
	static Any _0x4839F489F40CBB17() { return invoke<Any>(0x4839F489F40CBB17); } // 0x4839F489F40CBB17
	static Any _0x1958672886DC2F95(Any* p0, Any p1) { return invoke<Any>(0x1958672886DC2F95, p0, p1); } // 0x1958672886DC2F95 0xF30E5814
	static Any _0x5F5E265152672306() { return invoke<Any>(0x5F5E265152672306); } // 0x5F5E265152672306 0xC6609191
	static BOOL NETWORK_IS_CHATTING_IN_PLATFORM_PARTY(Player* playerHandle) { return invoke<BOOL>(0x7CD0F2A88A24B1AC, playerHandle); } // 0x7CD0F2A88A24B1AC 0x51367B34
	static BOOL NETWORK_IS_IN_PARTY() { return invoke<BOOL>(0x8B7CCF212B236371); } // 0x8B7CCF212B236371 0xF9D7D67D
	static BOOL NETWORK_IS_PARTY_MEMBER(Any p0) { return invoke<BOOL>(0x8B7CCF212B236371, p0); } // 0x8B7CCF212B236371 0x1D0C929D
	static Any _0x72A618439FD6B0A0() { return invoke<Any>(0x72A618439FD6B0A0); } // 0x72A618439FD6B0A0 0x9156EFC0
	static Any _0x4A73CABB8DBD8C9A() { return invoke<Any>(0x4A73CABB8DBD8C9A); } // 0x4A73CABB8DBD8C9A 0x8FA6EE0E
	static void _0xE134D2C94F78A0CC() { invoke<Void>(0xE134D2C94F78A0CC); } // 0xE134D2C94F78A0CC 0x7F70C15A
	static void _0x7E6AE0911FD66EA0() { invoke<Void>(0x7E6AE0911FD66EA0); } // 0x7E6AE0911FD66EA0
	static void _0x8B7CCF212B236371(Any p0) { invoke<Void>(0x8B7CCF212B236371, p0); } // 0x8B7CCF212B236371 0x8179C48A
	static void _0xF1DF0E78C77618E2(Any p0) { invoke<Void>(0xF1DF0E78C77618E2, p0); } // 0xF1DF0E78C77618E2 0x41702C8A
	static Any _0xF420B0BD58D85894() { return invoke<Any>(0xF420B0BD58D85894); } // 0xF420B0BD58D85894 0x208DD848
	static int _NETWORK_GET_RANDOM_INT_IN_RANGE(int rangeStart, int rangeEnd) { return invoke<int>(0x7965D8431465B5C3, rangeStart, rangeEnd); } // 0x7965D8431465B5C3 0xF9B6426D
	static BOOL NETWORK_PLAYER_IS_CHEATER() { return invoke<BOOL>(0x7AE3326EBD529B19); } // 0x7AE3326EBD529B19 0xA51DC214
	static Any _0xDB64E22599B61F7B() { return invoke<Any>(0xDB64E22599B61F7B); } // 0xDB64E22599B61F7B 0x1720ABA6
	static BOOL NETWORK_PLAYER_IS_BADSPORT() { return invoke<BOOL>(0xE28A9FB5803F5F20); } // 0xE28A9FB5803F5F20 0xA19708E3
	static BOOL _0x49A3590438C70A5B(Any p0, Any p1, Any p2) { return invoke<BOOL>(0x49A3590438C70A5B, p0, p1, p2); } // 0x49A3590438C70A5B 0xF9A51B92
	static BOOL BAD_SPORT_PLAYER_LEFT_DETECTED(Any* p0, Any p1, Any p2) { return invoke<BOOL>(0x579439F4A07CDCB9, p0, p1, p2); } // 0x579439F4A07CDCB9 0x4C2C6B6A
	static void _0xC12C02019CAF9471(Any p0, Any p1) { invoke<Void>(0xC12C02019CAF9471, p0, p1); } // 0xC12C02019CAF9471 0x4818ACD0
	static void NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT(Any p0, BOOL p1, Any p2) { invoke<Void>(0x181A13B993F735EB, p0, p1, p2); } // 0x181A13B993F735EB 0x470810ED
	static BOOL _0xDC3CBB9C53C5C23C(Any p0, BOOL p1, Any p2) { return invoke<BOOL>(0xDC3CBB9C53C5C23C, p0, p1, p2); } // 0xDC3CBB9C53C5C23C
	static BOOL NETWORK_GET_THIS_SCRIPT_IS_NETWORK_SCRIPT() { return invoke<BOOL>(0x9A0AB9C5586EA71E); } // 0x9A0AB9C5586EA71E 0xD9BF6549
	static int _NETWORK_GET_NUM_PARTICIPANTS_HOST() { return invoke<int>(0xCF8627766CD5D4CE); } // 0xCF8627766CD5D4CE 0xCCD8C02D
	static int NETWORK_GET_NUM_PARTICIPANTS() { return invoke<int>(0x22381E1DB54373A4); } // 0x22381E1DB54373A4 0x3E25A3C5
	static int NETWORK_GET_SCRIPT_STATUS() { return invoke<int>(0xCC130A646D137F0D); } // 0xCC130A646D137F0D 0x2BE9235A
	static void NETWORK_REGISTER_HOST_BROADCAST_VARIABLES(int* vars, int numVars) { invoke<Void>(0xB5EAF11213E48C1C, vars, numVars); } // 0xB5EAF11213E48C1C 0xDAF3B0AE
	static void NETWORK_REGISTER_PLAYER_BROADCAST_VARIABLES(int* vars, int numVars) { invoke<Void>(0x0C3BA36587E6FBEE, vars, numVars); } // 0x0C3BA36587E6FBEE 0xBE3D32B4
	static void _0xDE3A7C519522AB3C() { invoke<Void>(0xDE3A7C519522AB3C); } // 0xDE3A7C519522AB3C 0xA71A1D2A
	static BOOL _0xF8A920554B0F81A7() { return invoke<BOOL>(0xF8A920554B0F81A7); } // 0xF8A920554B0F81A7 0x0B739F53
	static int NETWORK_GET_PLAYER_INDEX(Player player) { return invoke<int>(0xD878F413B7BB4895, player); } // 0xD878F413B7BB4895 0xBE1C1506
	static int NETWORK_GET_PARTICIPANT_INDEX(int index) { return invoke<int>(0xB421DCBFBBE3286E, index); } // 0xB421DCBFBBE3286E 0xC4D91094
	static Player _NETWORK_GET_PED_PLAYER(Ped ped) { return invoke<Player>(0xDE881A032F5BA110, ped); } // 0xDE881A032F5BA110 0x40DBF464
	static int NETWORK_GET_NUM_CONNECTED_PLAYERS() { return invoke<int>(0xBAFAE93BF0BF871A); } // 0xBAFAE93BF0BF871A 0xF7952E62
	static BOOL NETWORK_IS_PLAYER_CONNECTED(Player player) { return invoke<BOOL>(0x79A34E9FB759E0C0, player); } // 0x79A34E9FB759E0C0 0x168EE2C2
	static int _0x7ACBE2F705055FDB() { return invoke<int>(0x7ACBE2F705055FDB); } // 0x7ACBE2F705055FDB 0xF4F13B06
	static BOOL NETWORK_IS_PARTICIPANT_ACTIVE(Any p0) { return invoke<BOOL>(0x5877B93374C85567, p0); } // 0x5877B93374C85567 0x4E2C348B
	static BOOL NETWORK_IS_PLAYER_ACTIVE(Player player) { return invoke<BOOL>(0x7268A1112372AA44, player); } // 0x7268A1112372AA44 0x43657B17
	static BOOL NETWORK_IS_PLAYER_A_PARTICIPANT(Any p0) { return invoke<BOOL>(0xD54DE3C9493BFEC2, p0); } // 0xD54DE3C9493BFEC2 0xB08B6992
	static BOOL NETWORK_IS_HOST_OF_THIS_SCRIPT() { return invoke<BOOL>(0x415DF132F15085E8); } // 0x415DF132F15085E8 0x6970BA94
	static Any NETWORK_GET_HOST_OF_THIS_SCRIPT() { return invoke<Any>(0xDC0834EFCFBBC8C6); } // 0xDC0834EFCFBBC8C6 0x89EA7B54
	static int NETWORK_GET_HOST_OF_SCRIPT(char* scriptName, int p1, Any p2) { return invoke<int>(0x8ABF7805AF7306B7, scriptName, p1, p2); } // 0x8ABF7805AF7306B7 0x9C95D0BB
	static void NETWORK_SET_MISSION_FINISHED() { invoke<Void>(0x7C91C1E72910DD87); } // 0x7C91C1E72910DD87 0x3083FAD7
	static BOOL NETWORK_IS_SCRIPT_ACTIVE(char* scriptName, Any p1, BOOL p2, Any p3) { return invoke<BOOL>(0x24A0C7A82D1B9734, scriptName, p1, p2, p3); } // 0x24A0C7A82D1B9734 0x4A65250C
	static Any _0xEE67B2EB75624ADC(Any* p0, Any p1, Any p2) { return invoke<Any>(0xEE67B2EB75624ADC, p0, p1, p2); } // 0xEE67B2EB75624ADC 0x8F7D9F46
	static Any _0x5165D99E0F66DAD1() { return invoke<Any>(0x5165D99E0F66DAD1); } // 0x5165D99E0F66DAD1 0xDB8B5D71
	static BOOL _0x5CBD339318749291(Any p0, Any* p1, Any p2) { return invoke<BOOL>(0x5CBD339318749291, p0, p1, p2); } // 0x5CBD339318749291 0xCEA55F4C
	static void _0xD3F2D358A4D57181() { invoke<Void>(0xD3F2D358A4D57181); } // 0xD3F2D358A4D57181 0x8DCFE77D
	static void _0xCDF33F68BC783C64() { invoke<Void>(0xCDF33F68BC783C64); } // 0xCDF33F68BC783C64 0x331D9A27
	static Player PARTICIPANT_ID() { return invoke<Player>(0x53C80E132FB19A45); } // 0x53C80E132FB19A45 0x9C35A221
	static int PARTICIPANT_ID_TO_INT() { return invoke<int>(0xCA1D9459B2CC7619); } // 0xCA1D9459B2CC7619 0x907498B0
	static int NETWORK_GET_DESTROYER_OF_NETWORK_ID(int netId, Hash* weaponHash) { return invoke<int>(0x74CEEA5617F4A924, netId, weaponHash); } // 0x74CEEA5617F4A924 0x4FCA6436
	static BOOL _0xC1B7B79351378EA0(Any p0, Any p1, Any* p2) { return invoke<BOOL>(0xC1B7B79351378EA0, p0, p1, p2); } // 0xC1B7B79351378EA0 0x28A45454
	static Entity NETWORK_GET_ENTITY_KILLER_OF_PLAYER(Player player, Hash* weaponHash) { return invoke<Entity>(0xB9E840A1991B4719, player, weaponHash); } // 0xB9E840A1991B4719 0xA7E7E04F
	static void NETWORK_RESURRECT_LOCAL_PLAYER(float x, float y, float z, float heading, Any p4, Any p5) { invoke<Void>(0xDCB3CCEA44DF951E, x, y, z, heading, p4, p5); } // 0xDCB3CCEA44DF951E 0xF1F9D4B4
	static void NETWORK_SET_LOCAL_PLAYER_INVINCIBLE_TIME(int time) { invoke<Void>(0xC0EE8981D0E3C9BC, time); } // 0xC0EE8981D0E3C9BC 0xFEA9B85C
	static BOOL NETWORK_IS_LOCAL_PLAYER_INVINCIBLE() { return invoke<BOOL>(0x62A457113B22BC4A); } // 0x62A457113B22BC4A 0x8DE13B36
	static void _0xFB40D113CAF003F4(int participantID, BOOL p1) { invoke<Void>(0xFB40D113CAF003F4, participantID, p1); } // 0xFB40D113CAF003F4 0x8D27280E
	static void _0xA2ADC2314839E0A2(Any p0) { invoke<Void>(0xA2ADC2314839E0A2, p0); } // 0xA2ADC2314839E0A2 0xB72F086D
	static BOOL _0xA33A4B297D498A41(Any p0) { return invoke<BOOL>(0xA33A4B297D498A41, p0); } // 0xA33A4B297D498A41 0xEDA68956
	static int NETWORK_GET_NETWORK_ID_FROM_ENTITY(Entity entity) { return invoke<int>(0x3D9BACD0411D4A4E, entity); } // 0x3D9BACD0411D4A4E 0x9E35DAB6
	static Entity NETWORK_GET_ENTITY_FROM_NETWORK_ID(int netId) { return invoke<Entity>(0xF4135DAB27A502D7, netId); } // 0xF4135DAB27A502D7 0x5B912C3F
	static BOOL NETWORK_GET_ENTITY_IS_NETWORKED(Entity entity) { return invoke<BOOL>(0x04DB71A22837F85C, entity); } // 0x04DB71A22837F85C 0xD7F934F4
	static BOOL NETWORK_GET_ENTITY_IS_LOCAL(Entity entity) { return invoke<BOOL>(0xFB2400809D8DC8C7, entity); } // 0xFB2400809D8DC8C7 0x813353ED
	static void _0x1A12E349F33544EE(Entity entity) { invoke<Void>(0x1A12E349F33544EE, entity); } // 0x1A12E349F33544EE 0x31A630A4
	static void NETWORK_UNREGISTER_NETWORKED_ENTITY(Entity entity) { invoke<Void>(0x5DD5C182E9D1E4D4, entity); } // 0x5DD5C182E9D1E4D4 0x5C645F64
	static BOOL NETWORK_DOES_NETWORK_ID_EXIST(int netID) { return invoke<BOOL>(0x49C2DB27EDED0049, netID); } // 0x49C2DB27EDED0049 0xB8D2C99E
	static BOOL NETWORK_DOES_ENTITY_EXIST_WITH_NETWORK_ID(Entity entity) { return invoke<BOOL>(0x841F312D66362BF7, entity); } // 0x841F312D66362BF7 0x1E2E3177
	static BOOL NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(int netId) { return invoke<BOOL>(0x4EDACF77CDD9CFEB, netId); } // 0x4EDACF77CDD9CFEB 0x9262A60A
	static BOOL NETWORK_HAS_CONTROL_OF_NETWORK_ID(int netId) { return invoke<BOOL>(0x093776FE2E6B4BAC, netId); } // 0x093776FE2E6B4BAC 0x92E77D21
	static BOOL NETWORK_REQUEST_CONTROL_OF_ENTITY(Entity entity) { return invoke<BOOL>(0xE647AA9998A1123E, entity); } // 0xE647AA9998A1123E 0xA05FEBD7
	static BOOL NETWORK_REQUEST_CONTROL_OF_DOOR(int doorID) { return invoke<BOOL>(0xA091236186DCECF0, doorID); } // 0xA091236186DCECF0 0xF60DAAF6
	static BOOL NETWORK_HAS_CONTROL_OF_ENTITY(Entity entity) { return invoke<BOOL>(0xC38F0FBE1914783C, entity); } // 0xC38F0FBE1914783C 0x005FD797
	static BOOL NETWORK_HAS_CONTROL_OF_PICKUP(Pickup pickup) { return invoke<BOOL>(0x95C0409D3F7D4EA1, pickup); } // 0x95C0409D3F7D4EA1 0xF7784FC8
	static BOOL NETWORK_HAS_CONTROL_OF_DOOR(int doorID) { return invoke<BOOL>(0x58291968971DA892, doorID); } // 0x58291968971DA892 0x136326EC
	static BOOL _0x294061F706FE4FCE(int p0) { return invoke<BOOL>(0x294061F706FE4FCE, p0); } // 0x294061F706FE4FCE
	static int VEH_TO_NET(Vehicle vehicle) { return invoke<int>(0x90C414D950E11ED7, vehicle); } // 0x90C414D950E11ED7 0xF17634EB
	static int PED_TO_NET(Ped ped) { return invoke<int>(0x60A7E0316C35C19D, ped); } // 0x60A7E0316C35C19D 0x86A0B759
	static int OBJ_TO_NET(Object object) { return invoke<int>(0x2FE9A6B7899D979E, object); } // 0x2FE9A6B7899D979E 0x1E05F29F
	static Vehicle NET_TO_VEH(int netHandle) { return invoke<Vehicle>(0xC7C67E717B20DA89, netHandle); } // 0xC7C67E717B20DA89 0x7E02FAEA
	static Ped NET_TO_PED(int netHandle) { return invoke<Ped>(0xDE2767751C03729D, netHandle); } // 0xDE2767751C03729D 0x87717DD4
	static Object NET_TO_OBJ(int netHandle) { return invoke<Object>(0xF9D7EA2FA85E2505, netHandle); } // 0xF9D7EA2FA85E2505 0x27AA14D8
	static Entity NET_TO_ENT(int netHandle) { return invoke<Entity>(0x03981D6F4893D7D0, netHandle); } // 0x03981D6F4893D7D0 0x5E149683
	static void NETWORK_GET_LOCAL_HANDLE(int* networkHandle, int bufferSize) { invoke<Void>(0xFAF2D64177CBB076, networkHandle, bufferSize); } // 0xFAF2D64177CBB076 0x08023B16
	static void NETWORK_HANDLE_FROM_USER_ID(char* userId, int* networkHandle, int bufferSize) { invoke<Void>(0xB48D3E05434BD1FF, userId, networkHandle, bufferSize); } // 0xB48D3E05434BD1FF 0x74C2C1B7
	static void NETWORK_HANDLE_FROM_MEMBER_ID(char* memberId, int* networkHandle, int bufferSize) { invoke<Void>(0xFCD8B3B75AE71441, memberId, networkHandle, bufferSize); } // 0xFCD8B3B75AE71441 0x9BFC9FE2
	static void NETWORK_HANDLE_FROM_PLAYER(Player player, int* networkHandle, int bufferSize) { invoke<Void>(0xF3EE72618DF96AF7, player, networkHandle, bufferSize); } // 0xF3EE72618DF96AF7 0xD3498917
	static int _0xBC1D768F2F5D6C05(Player player) { return invoke<int>(0x7081D1CF61F5A498, player); } // _0xBC1D768F2F5D6C05
	static Hash _NETWORK_HASH_FROM_GAMER_HANDLE(int* networkHandle) { return invoke<Hash>(0x94A0E0BA5D089186, networkHandle); } // 0x94A0E0BA5D089186
	static void NETWORK_HANDLE_FROM_FRIEND(Player friendIndex, int* networkHandle, int bufferSize) { invoke<Void>(0x2872F55A505C079E, friendIndex, networkHandle, bufferSize); } // 0x2872F55A505C079E 0x3B0BB3A3
	static BOOL NETWORK_GAMERTAG_FROM_HANDLE_START(int* networkHandle) { return invoke<BOOL>(0x6A382AED99EAEF86, networkHandle); } // 0x6A382AED99EAEF86 0xEBA00C2A
	static BOOL NETWORK_GAMERTAG_FROM_HANDLE_PENDING() { return invoke<BOOL>(0x7ACAC31C555C4D84); } // 0x7ACAC31C555C4D84 0xF000828E
	static BOOL NETWORK_GAMERTAG_FROM_HANDLE_SUCCEEDED() { return invoke<BOOL>(0x4C070B019307642E); } // 0x4C070B019307642E 0x89C2B5EA
	static char* NETWORK_GET_GAMERTAG_FROM_HANDLE(int* networkHandle) { return invoke<char*>(0x1CBFF145EA3C6BCD, networkHandle); } // 0x1CBFF145EA3C6BCD 0xA18A1B26
	static int _0xB3596842106D3397(Any* p0, Any p1) { return invoke<int>(0xB3596842106D3397, p0, p1); } // 0xB3596842106D3397
	static Any _0x080B18BDB2973548(Any p0, Any p1, Any p2) { return invoke<Any>(0x080B18BDB2973548, p0, p1, p2); } // 0x080B18BDB2973548
	static BOOL NETWORK_ARE_HANDLES_THE_SAME(int* netHandle1, int* netHandle2) { return invoke<BOOL>(0xA1AD7C69980A61EC, netHandle1, netHandle2); } // 0xA1AD7C69980A61EC 0x45975AE3
	static BOOL NETWORK_IS_HANDLE_VALID(int* p0, int p1) { return invoke<BOOL>(0x7BC6F3BBFEAB9958, p0, p1); } // 0x7BC6F3BBFEAB9958 0xF0996C6E
	static Player NETWORK_GET_PLAYER_FROM_GAMER_HANDLE(int* networkHandle) { return invoke<Player>(0x471C87EF03143741, networkHandle); } // 0x471C87EF03143741 0x2E96EF1E
	static char* NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(int* networkHandle) { return invoke<char*>(0x93484F815C6EEAB0, networkHandle); } // 0x93484F815C6EEAB0 0x62EF0A63
	static BOOL NETWORK_IS_GAMER_IN_MY_SESSION(int* networkHandle) { return invoke<BOOL>(0xBD6B478BC887CAC6, networkHandle); } // 0xBD6B478BC887CAC6 0x59127716
	static void NETWORK_SHOW_PROFILE_UI(int* networkHandle) { invoke<Void>(0x67BD5B0BE920F912, networkHandle); } // 0x67BD5B0BE920F912 0xF00A20B0
	static char* NETWORK_PLAYER_GET_NAME(Player player) { return invoke<char*>(0xB7229E8D6609EEBF, player); } // 0xB7229E8D6609EEBF 0xCE48F260
	static char* _NETWORK_PLAYER_GET_USER_ID(Player player, int* userID) { return invoke<char*>(0x600808A0B5559074, player, userID); } // 0x600808A0B5559074 0x4EC0D983
	static BOOL NETWORK_PLAYER_IS_ROCKSTAR_DEV(Player player) { return invoke<BOOL>(0x30BC32023EA26E38, player); } // 0x30BC32023EA26E38 0xF6659045
	static BOOL _0x10D90C9BBB67A656(Any p0) { return invoke<BOOL>(0x10D90C9BBB67A656, p0); } // 0x10D90C9BBB67A656 0xD265B049
	static BOOL NETWORK_IS_INACTIVE_PROFILE(Any* p0) { return invoke<BOOL>(0x9E917F0988E78E8F, p0); } // 0x9E917F0988E78E8F 0x95481343
	static int NETWORK_GET_MAX_FRIENDS() { return invoke<int>(0x215F7BA6AB38BE32); } // 0x215F7BA6AB38BE32 0x048171BC
	static int NETWORK_GET_FRIEND_COUNT() { return invoke<int>(0x54F10BD9D7FA4465); } // 0x54F10BD9D7FA4465 0xA396ACDE
	static char* NETWORK_GET_FRIEND_NAME(Player player) { return invoke<char*>(0x95DD8CCEC5BEC12A, player); } // 0x95DD8CCEC5BEC12A 0x97420B6D
	static char* _NETWORK_GET_FRIEND_NAME_FROM_INDEX(int friendIndex) { return invoke<char*>(0x74FDAE0E79E3F35D, friendIndex); } // 0x74FDAE0E79E3F35D
	static BOOL NETWORK_IS_FRIEND_ONLINE(Any* p0) { return invoke<BOOL>(0x9AE76F60790E7E8E, p0); } // 0x9AE76F60790E7E8E 0xE0A42430
	static BOOL _0x00F8BCD915B03B62(Any* p0) { return invoke<BOOL>(0x00F8BCD915B03B62, p0); } // 0x00F8BCD915B03B62
	static BOOL NETWORK_IS_FRIEND_IN_SAME_TITLE(int* networkHandle) { return invoke<BOOL>(0x9360B6049759486E, networkHandle); } // 0x9360B6049759486E 0xC54365C2
	static BOOL NETWORK_IS_FRIEND_IN_MULTIPLAYER(int* networkHandle) { return invoke<BOOL>(0xE8BDD551ECB747DE, networkHandle); } // 0xE8BDD551ECB747DE 0x400BDDD9
	static BOOL NETWORK_IS_FRIEND(int* networkHandle) { return invoke<BOOL>(0x2D5BDD3304DD4725, networkHandle); } // 0x2D5BDD3304DD4725 0x2DA4C282
	static Any NETWORK_IS_PENDING_FRIEND(Any p0) { return invoke<Any>(0xA9E8B852FFCFE18F, p0); } // 0xA9E8B852FFCFE18F 0x5C85FF81
	static Any NETWORK_IS_ADDING_FRIEND() { return invoke<Any>(0x567F47BBEBB58B73); } // 0x567F47BBEBB58B73 0xBB7EC8C4
	static BOOL NETWORK_ADD_FRIEND(Any* p0, char* p1) { return invoke<BOOL>(0x70765F78489B397D, p0, p1); } // 0x70765F78489B397D 0x20E5B3EE
	static BOOL NETWORK_IS_FRIEND_INDEX_ONLINE(int friendIndex) { return invoke<BOOL>(0x17EF5CC2A381764D, friendIndex); } // 0x17EF5CC2A381764D 0x94AE7172
	static void _0xE3275C3071721B6D(BOOL p0) { invoke<Void>(0xE3275C3071721B6D, p0); } // 0xE3275C3071721B6D
	static BOOL _0x6F86193799E398F0(Any p0) { return invoke<BOOL>(0x6F86193799E398F0, p0); } // 0x6F86193799E398F0 0xB802B671
	static BOOL NETWORK_CAN_SET_WAYPOINT() { return invoke<BOOL>(0x5345673683F23BC4); } // 0x5345673683F23BC4 0x009E68F3
	static Any _0x168299CBE52A3A56(Any p0) { return invoke<Any>(0x168299CBE52A3A56, p0); } // 0x168299CBE52A3A56 0x5C0AB2A9
	static Any _0x00951150267AFF9E() { return invoke<Any>(0x00951150267AFF9E); } // 0x00951150267AFF9E 0x9A176B6E
	static BOOL NETWORK_HAS_HEADSET() { return invoke<BOOL>(0xAB37E5254B72592C); } // 0xAB37E5254B72592C 0xA7DC5657
	static void _0xFFCB1DD8F0668EAC(BOOL p0) { invoke<Void>(0xFFCB1DD8F0668EAC, p0); } // 0xFFCB1DD8F0668EAC 0x5C05B7E1
	static Any _0x726A2FEEAA517CE7() { return invoke<Any>(0x726A2FEEAA517CE7); } // 0x726A2FEEAA517CE7
	static BOOL NETWORK_GAMER_HAS_HEADSET(Any* p0) { return invoke<BOOL>(0xC94F91F21041CA8A, p0); } // 0xC94F91F21041CA8A 0xD036DA4A
	static BOOL NETWORK_IS_GAMER_TALKING(int* p0) { return invoke<BOOL>(0xD3C126815A4E4DD6, p0); } // 0xD3C126815A4E4DD6 0x99B58DBC
	static BOOL NETWORK_CAN_COMMUNICATE_WITH_GAMER(int* player) { return invoke<BOOL>(0x600AC8051FFDB784, player); } // 0x600AC8051FFDB784 0xD05EB7F6
	static BOOL NETWORK_IS_GAMER_MUTED_BY_ME(int* p0) { return invoke<BOOL>(0x1A0BD443C067F484, p0); } // 0x1A0BD443C067F484 0x001B4046
	static BOOL NETWORK_AM_I_MUTED_BY_GAMER(Any* p0) { return invoke<BOOL>(0x58C801D1650F3780, p0); } // 0x58C801D1650F3780 0x7685B333
	static BOOL NETWORK_IS_GAMER_BLOCKED_BY_ME(Any* p0) { return invoke<BOOL>(0xA34410C46A032614, p0); } // 0xA34410C46A032614 0x3FDCC8D7
	static BOOL NETWORK_AM_I_BLOCKED_BY_GAMER(Any* p0) { return invoke<BOOL>(0x0C97B9684E5567A8, p0); } // 0x0C97B9684E5567A8 0xD19B312C
	static BOOL _0x7BB94A563F5F14FD(Any* p0) { return invoke<BOOL>(0x7BB94A563F5F14FD, p0); } // 0x7BB94A563F5F14FD
	static BOOL _0x1256452C511A974A(Any* p0) { return invoke<BOOL>(0x1256452C511A974A, p0); } // 0x1256452C511A974A
	static BOOL _0x0BC872EF93FA89B6(Any* p0) { return invoke<BOOL>(0x0BC872EF93FA89B6, p0); } // 0x0BC872EF93FA89B6
	static BOOL _0x1968D2342DEA309D(Any* p0) { return invoke<BOOL>(0x1968D2342DEA309D, p0); } // 0x1968D2342DEA309D
	static BOOL NETWORK_IS_PLAYER_TALKING(Player player) { return invoke<BOOL>(0x21EDB569F6D5EA14, player); } // 0x21EDB569F6D5EA14 0xDA9FD9DB
	static BOOL NETWORK_PLAYER_HAS_HEADSET(Player player) { return invoke<BOOL>(0x243B9A95BC27E337, player); } // 0x243B9A95BC27E337 0x451FB6B6
	static BOOL NETWORK_IS_PLAYER_MUTED_BY_ME(Player player) { return invoke<BOOL>(0x77113BB81E6537DC, player); } // 0x77113BB81E6537DC 0x7A21050E
	static BOOL NETWORK_AM_I_MUTED_BY_PLAYER(Player player) { return invoke<BOOL>(0x8C89DAD59408D3BD, player); } // 0x8C89DAD59408D3BD 0xE128F2B0
	static BOOL NETWORK_IS_PLAYER_BLOCKED_BY_ME(Player player) { return invoke<BOOL>(0x70807A8FA2F0CAE8, player); } // 0x70807A8FA2F0CAE8 0xAE4F4560
	static BOOL NETWORK_AM_I_BLOCKED_BY_PLAYER(Player player) { return invoke<BOOL>(0x8C97DAE550853CC6, player); } // 0x8C97DAE550853CC6 0x953EF45E
	static float NETWORK_GET_PLAYER_LOUDNESS(Any p0) { return invoke<float>(0xCE51FEB70763C873, p0); } // 0xCE51FEB70763C873 0xF2F67014
	static void NETWORK_SET_TALKER_PROXIMITY(float p0) { invoke<Void>(0x305F1A6C81759707, p0); } // 0x305F1A6C81759707 0x67555C66
	static Any NETWORK_GET_TALKER_PROXIMITY() { return invoke<Any>(0xF3D6CD6C66FD68C5); } // 0xF3D6CD6C66FD68C5 0x19991ADD
	static void NETWORK_SET_VOICE_ACTIVE(BOOL toggle) { invoke<Void>(0x50D0006D4F2DDCAF, toggle); } // 0x50D0006D4F2DDCAF 0x8011247F
	static void _0x7BA1899A1838F107(BOOL p0) { invoke<Void>(0x7BA1899A1838F107, p0); } // 0x7BA1899A1838F107 0x1A3EA6CD
	static void _0xD1EAF7DA747349BC(BOOL p0) { invoke<Void>(0xD1EAF7DA747349BC, p0); } // 0xD1EAF7DA747349BC 0xCAB21090
	static void NETWORK_SET_TEAM_ONLY_CHAT(BOOL toggle) { invoke<Void>(0x46379C3B9166434C, toggle); } // 0x46379C3B9166434C 0x3813019A
	static void _0x1C646DA3153BF6B9(int team, BOOL toggle) { invoke<Void>(0x1C646DA3153BF6B9, team, toggle); } // 0x1C646DA3153BF6B9 0xC8CC9E75
	static void NETWORK_SET_OVERRIDE_SPECTATOR_MODE(BOOL toggle) { invoke<Void>(0x621C6AB9D834D943, toggle); } // 0x621C6AB9D834D943 0xA0FD42D3
	static void _0xB633FD209EDA5F87(BOOL p0) { invoke<Void>(0xB633FD209EDA5F87, p0); } // 0xB633FD209EDA5F87 0xC9DDA85B
	static void _0xF87F44A94B49CBDE(BOOL p0) { invoke<Void>(0xF87F44A94B49CBDE, p0); } // 0xF87F44A94B49CBDE
	static void _0x2FB9A31AC976717C(BOOL p0) { invoke<Void>(0x2FB9A31AC976717C, p0); } // 0x2FB9A31AC976717C 0xD33AFF79
	static void _0x8808D855D3B0FB37(BOOL p0) { invoke<Void>(0x8808D855D3B0FB37, p0); } // 0x8808D855D3B0FB37 0x4FFEFE43
	static void _0xCA0A84FFD0366168(Any p0, BOOL p1) { invoke<Void>(0xCA0A84FFD0366168, p0, p1); } // 0xCA0A84FFD0366168 0x74EE2D8B
	static void _0x00A65C4339136926(Any p0, Any p1) { invoke<Void>(0x00A65C4339136926, p0, p1); } // 0x00A65C4339136926
	static void _0x95A163E10BE8482E(BOOL p0) { invoke<Void>(0x95A163E10BE8482E, p0); } // 0x95A163E10BE8482E 0x2F98B405
	static void _0x9C091171A3402F40(Any p0, Any p1) { invoke<Void>(0x9C091171A3402F40, p0, p1); } // 0x9C091171A3402F40 0x95F1C60D
	static void _0x9F63064B30B81943(BOOL p0) { invoke<Void>(0x9F63064B30B81943, p0); } // 0x9F63064B30B81943 0x1BCD3DDF
	static void NETWORK_SET_VOICE_CHANNEL(Any p0) { invoke<Void>(0x84AF128205FF1B8E, p0); } // 0x84AF128205FF1B8E 0x3974879F
	static void _0x5EC3EFD9AE66EF09() { invoke<Void>(0x5EC3EFD9AE66EF09); } // 0x5EC3EFD9AE66EF09 0x9ECF722A
	static void IS_NETWORK_VEHICLE_BEEN_DAMAGED_BY_ANY_OBJECT(Any p0, Any p1, Any p2) { invoke<Void>(0xD8FFE2BDC83F3C9A, p0, p1, p2); } // 0xD8FFE2BDC83F3C9A 0xF1E84832
	static void _0x1180F94C1FD9357A() { invoke<Void>(0x1180F94C1FD9357A); } // 0x1180F94C1FD9357A 0x7F9B9052
	static void _0x312320BD52CC0E40(Any p0) { invoke<Void>(0x312320BD52CC0E40, p0); } // 0x312320BD52CC0E40 0x7BBEA8CF
	static void _0xDC0EFA8C6C768F59(Any p0) { invoke<Void>(0xDC0EFA8C6C768F59, p0); } // 0xDC0EFA8C6C768F59 0xE797A4B6
	static void _0x971C3EDC7BD142DB(Player p0, float* p1, float* p2) { invoke<Void>(0x971C3EDC7BD142DB, p0, p1, p2); } // 0x971C3EDC7BD142DB 0x92268BB5
	static BOOL _NETWORK_IS_TEXT_CHAT_ACTIVE() { return invoke<BOOL>(0x349B6C82BE3EF6DD); } // 0x349B6C82BE3EF6DD
	static void SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME() { invoke<Void>(0x760DEE9485886F2D); } // 0x760DEE9485886F2D 0x92B7351C
	static void NETWORK_SET_FRIENDLY_FIRE_OPTION(BOOL toggle) { invoke<Void>(0x02AC9A2B522D447F, toggle); } // 0x02AC9A2B522D447F 0x6BAF95FA
	static void NETWORK_SET_RICH_PRESENCE(Any p0, Any p1, Any p2, Any p3) { invoke<Void>(0x21E9CCAA51709FD0, p0, p1, p2, p3); } // 0x21E9CCAA51709FD0 0x932A6CED
	static void _0xCDDCD2630EF7A698(Any p0, Any p1) { invoke<Void>(0xCDDCD2630EF7A698, p0, p1); } // 0xCDDCD2630EF7A698 0x017E6777
	static Any _0xC8D7E1A013BE4DE0() { return invoke<Any>(0xC8D7E1A013BE4DE0); } // 0xC8D7E1A013BE4DE0 0xE1F86C6A
	static void _0x78E894779E90EDF9(Player player, float x, float y, float z, BOOL p4, BOOL p5) { invoke<Void>(0x78E894779E90EDF9, player, x, y, z, p4, p5); } // 0x78E894779E90EDF9 0xBE6A30C3
	static void _0x5B2D7EEEBD4DFA07(Player player, BOOL p1) { invoke<Void>(0x5B2D7EEEBD4DFA07, player, p1); } // 0x5B2D7EEEBD4DFA07 0x22E03AD0
	static void _0x7C119226D700932A(Entity entity) { invoke<Void>(0x7C119226D700932A, entity); } // 0x7C119226D700932A 0xCEAE5AFC
	static BOOL _NETWORK_PLAYER_IS_IN_CLAN() { return invoke<BOOL>(0x749CE7B33672D350); } // 0x749CE7B33672D350 0xF5F4BD95
	static BOOL NETWORK_CLAN_PLAYER_IS_ACTIVE(int* netHandle) { return invoke<BOOL>(0x3B13D05FD2D29D80, netHandle); } // 0x3B13D05FD2D29D80 0xAB8319A3
	static BOOL NETWORK_CLAN_PLAYER_GET_DESC(ScrHandle* desc, int p1, int* netHandle) { return invoke<BOOL>(0x7E1D32162078314A, desc, p1, netHandle); } // 0x7E1D32162078314A 0x6EE4A282
	static BOOL _0x1A03CEC7A8F6CCA0(ScrHandle* desc, int p1) { return invoke<BOOL>(0x1A03CEC7A8F6CCA0, desc, p1); } // 0x1A03CEC7A8F6CCA0 0x54E79E9C
	static void _0xC4D7F7FDC44E9AC3(ScrHandle* desc, int p1, Any* p2) { invoke<Void>(0xC4D7F7FDC44E9AC3, desc, p1, p2); } // 0xC4D7F7FDC44E9AC3 0xF633805A
	static int _0x4ADD10F465B53E3C() { return invoke<int>(0x4ADD10F465B53E3C); } // 0x4ADD10F465B53E3C 0x807B3450
	static BOOL NETWORK_CLAN_GET_MEMBERSHIP_DESC(ScrHandle* memberDesc, Any p1) { return invoke<BOOL>(0x113AF801A3B4DD40, memberDesc, p1); } // 0x113AF801A3B4DD40 0x3369DD1F
	static BOOL NETWORK_CLAN_DOWNLOAD_MEMBERSHIP(int* netHandle) { return invoke<BOOL>(0x89F8BC24E5CA98CB, netHandle); } // 0x89F8BC24E5CA98CB 0x8E8CB520
	static BOOL NETWORK_CLAN_DOWNLOAD_MEMBERSHIP_PENDING(Any* p0) { return invoke<BOOL>(0x97A6FD71D83CE92C, p0); } // 0x97A6FD71D83CE92C 0x1FDB590F
	static Any _0x8954D3864D2D056A() { return invoke<Any>(0x8954D3864D2D056A); } // 0x8954D3864D2D056A 0x83ED8E08
	static BOOL NETWORK_CLAN_REMOTE_MEMBERSHIPS_ARE_IN_CACHE(Any* p0) { return invoke<BOOL>(0x21443470ACF2A07A, p0); } // 0x21443470ACF2A07A 0x40202867
	static int NETWORK_CLAN_GET_MEMBERSHIP_COUNT(Any* p0) { return invoke<int>(0x1336292B5148B473, p0); } // 0x1336292B5148B473 0x25924010
	static BOOL NETWORK_CLAN_GET_MEMBERSHIP_VALID(Any* p0, Any p1) { return invoke<BOOL>(0x420DF6DA2A4C54C6, p0, p1); } // 0x420DF6DA2A4C54C6 0x48914F6A
	static BOOL NETWORK_CLAN_GET_MEMBERSHIP(Any* p0, Any* p1, Any p2) { return invoke<BOOL>(0x89D358B066B30B1C, p0, p1, p2); } // 0x89D358B066B30B1C 0xCDC4A590
	static BOOL NETWORK_CLAN_JOIN(int clanHandle) { return invoke<BOOL>(0xFC4298DB9DC3C728, clanHandle); } // 0xFC4298DB9DC3C728 0x79C916C5
	static BOOL _0xAA28E96F8CC431C8(char* animDict, char* animCrew) { return invoke<BOOL>(0xAA28E96F8CC431C8, animDict, animCrew); } // 0xAA28E96F8CC431C8 0xBDA90BAC
	static BOOL _0xC15145C1F1B4373E(int p0, char* p1) { return invoke<BOOL>(0xC15145C1F1B4373E, p0, p1); } // 0xC15145C1F1B4373E 0x8E952B12
	static Any _0x5A1126E7024823D5() { return invoke<Any>(0x5A1126E7024823D5); } // 0x5A1126E7024823D5 0x966C90FD
	static BOOL _0x143C79C845931BB3(Any* p0, Any* p1) { return invoke<BOOL>(0x143C79C845931BB3, p0, p1); } // 0x143C79C845931BB3 0xBA672146
	static BOOL _0x75B4B997D8520CC8(Any p0) { return invoke<BOOL>(0x75B4B997D8520CC8, p0); } // 0x75B4B997D8520CC8 0x7963FA4D
	static BOOL _0xDFF1FC155F879258(Any p0, Any* p1) { return invoke<BOOL>(0xDFF1FC155F879258, p0, p1); } // 0xDFF1FC155F879258 0x88B13CDC
	static void _0x36500A5C39176E74(Any p0) { invoke<Void>(0x36500A5C39176E74, p0); } // 0x36500A5C39176E74 0xD6E3D5EA
	static Any _0x1C3AD40532DE3F7D() { return invoke<Any>(0x1C3AD40532DE3F7D); } // 0x1C3AD40532DE3F7D 0xE22445DA
	static void _0x7BC6DF085CCEEDDB() { invoke<Void>(0x7BC6DF085CCEEDDB); } // 0x7BC6DF085CCEEDDB 0x455DDF5C
	static BOOL NETWORK_GET_PRIMARY_CLAN_DATA_START(Any* p0, Any p1) { return invoke<BOOL>(0x0B5410719E621E4B, p0, p1); } // 0x0B5410719E621E4B 0x89DB0EC7
	static Any _0x8D1783404BD763E6() { return invoke<Any>(0x8D1783404BD763E6); } // 0x8D1783404BD763E6 0xA4EF02F3
	static Any _0x254440C77663CB14() { return invoke<Any>(0x254440C77663CB14); } // 0x254440C77663CB14 0x068A054E
	static BOOL NETWORK_GET_PRIMARY_CLAN_DATA_NEW(Any* p0, Any* p1) { return invoke<BOOL>(0x2F52E0176C13374F, p0, p1); } // 0x2F52E0176C13374F 0x9B8631EB
	static void SET_NETWORK_ID_CAN_MIGRATE(int netId, BOOL toggle) { invoke<Void>(0x73E0878A3E31819C, netId, toggle); } // 0x73E0878A3E31819C 0x47C8E5FF
	static void SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(int netId, BOOL toggle) { invoke<Void>(0xF24AAD892C8B4AC6, netId, toggle); } // 0xF24AAD892C8B4AC6 0x68D486B2
	static void _SET_NETWORK_ID_SYNC_TO_PLAYER(int netId, Player player, BOOL toggle) { invoke<Void>(0xCCE0E665D9CDFB62, netId, player, toggle); } // 0xCCE0E665D9CDFB62 0x4D15FDB1
	static void NETWORK_SET_ENTITY_CAN_BLEND(Entity entity, BOOL toggle) { invoke<Void>(0x7BC257D3C6672B27, entity, toggle); } // 0x7BC257D3C6672B27 0xDE8C0DB8
	static void _0x71924C351AFEAC4D(Entity entity, BOOL toggle) { invoke<Void>(0x71924C351AFEAC4D, entity, toggle); } // 0x71924C351AFEAC4D 0x09CBC4B0
	static void SET_NETWORK_ID_VISIBLE_IN_CUTSCENE(int netId, BOOL p1, BOOL p2) { invoke<Void>(0x329DC2B324A675CD, netId, p1, p2); } // 0x329DC2B324A675CD 0x199E75EF
	static void _0xC9929D396A4491EE(BOOL p0) { invoke<Void>(0xC9929D396A4491EE, p0); } // 0xC9929D396A4491EE
	static void _0x0845A1D84729917B(Any p0, BOOL p1) { invoke<Void>(0x0845A1D84729917B, p0, p1); } // 0x0845A1D84729917B 0x00AE4E17
	static BOOL _0x1E76805ECF5AA8B0(int netId) { return invoke<BOOL>(0x1E76805ECF5AA8B0, netId); } // 0x1E76805ECF5AA8B0 0xEA5176C0
	static void SET_LOCAL_PLAYER_VISIBLE_IN_CUTSCENE(BOOL p0, BOOL p1) { invoke<Void>(0x1D6A85891C36EC72, p0, p1); } // 0x1D6A85891C36EC72 0x59F3479B
	static void SET_LOCAL_PLAYER_INVISIBLE_LOCALLY(BOOL p0) { invoke<Void>(0xD04456560372BE21, p0); } // 0xD04456560372BE21 0x764F6222
	static void SET_LOCAL_PLAYER_VISIBLE_LOCALLY(BOOL p0) { invoke<Void>(0x1544E69732785146, p0); } // 0x1544E69732785146 0x324B56DB
	static void SET_PLAYER_INVISIBLE_LOCALLY(Player player, BOOL toggle) { invoke<Void>(0x5933BDBABD8B2267, player, toggle); } // 0x5933BDBABD8B2267 0x18227209
	static void SET_PLAYER_VISIBLE_LOCALLY(Player player, BOOL toggle) { invoke<Void>(0xB7966FAEB0FF7270, player, toggle); } // 0xB7966FAEB0FF7270 0xBA2BB4B4
	static void FADE_OUT_LOCAL_PLAYER(BOOL p0) { invoke<Void>(0xD629A0523A16EED3, p0); } // 0xD629A0523A16EED3 0x8FA7CEBD
	static void NETWORK_FADE_OUT_ENTITY(Entity entity, BOOL normal, BOOL slow) { invoke<Void>(0x7F9F6D12E7F11F40, entity, normal, slow); } // 0x7F9F6D12E7F11F40 0x47EDEE56
	static void NETWORK_FADE_IN_ENTITY(Entity entity, BOOL state) { invoke<Void>(0x52571C7514BA3D6E, entity, state); } // 0x52571C7514BA3D6E 0x9B9FCD02
	static BOOL _0x29F946E47A2B9B63(Any p0) { return invoke<BOOL>(0x29F946E47A2B9B63, p0); } // 0x29F946E47A2B9B63
	static BOOL _0x868C2F4C27D5C34E(Any p0) { return invoke<BOOL>(0x868C2F4C27D5C34E, p0); } // 0x868C2F4C27D5C34E
	static BOOL IS_PLAYER_IN_CUTSCENE(Player player) { return invoke<BOOL>(0x7C4E00F3A79B305E, player); } // 0x7C4E00F3A79B305E 0xE0A619BD
	static void SET_ENTITY_VISIBLE_IN_CUTSCENE(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x077AD883147F1AA1, p0, p1, p2); } // 0x077AD883147F1AA1 0xDBFB067B
	static void SET_ENTITY_LOCALLY_INVISIBLE(Entity entity) { invoke<Void>(0x2405F36072667687, entity); } // 0x2405F36072667687 0x51ADCC5F
	static void SET_ENTITY_LOCALLY_VISIBLE(Entity entity) { invoke<Void>(0xA6F2CCC966B3C8BF, entity); } // 0xA6F2CCC966B3C8BF 0x235A57B3
	static BOOL IS_DAMAGE_TRACKER_ACTIVE_ON_NETWORK_ID(int netID) { return invoke<BOOL>(0x227E5C7B75F5AB3A, netID); } // 0x227E5C7B75F5AB3A 0x597063BA
	static void ACTIVATE_DAMAGE_TRACKER_ON_NETWORK_ID(int netID, BOOL p1) { invoke<Void>(0x1B564C6049E59F65, netID, p1); } // 0x1B564C6049E59F65 0x95D07BA5
	static BOOL IS_SPHERE_VISIBLE_TO_ANOTHER_MACHINE(float p0, float p1, float p2, float p3) { return invoke<BOOL>(0x905279B0A283D24D, p0, p1, p2, p3); } // 0x905279B0A283D24D 0x23C5274E
	static BOOL IS_SPHERE_VISIBLE_TO_PLAYER(Any p0, float p1, float p2, float p3, float p4) { return invoke<BOOL>(0x5D30227FC384014B, p0, p1, p2, p3, p4); } // 0x5D30227FC384014B 0xE9FCFB32
	static void RESERVE_NETWORK_MISSION_OBJECTS(int p0) { invoke<Void>(0x79AA4F6EE2078BCD, p0); } // 0x79AA4F6EE2078BCD 0x391DF4F3
	static void RESERVE_NETWORK_MISSION_PEDS(int p0) { invoke<Void>(0x06EC4FFE0DCCA716, p0); } // 0x06EC4FFE0DCCA716 0x54998C37
	static void RESERVE_NETWORK_MISSION_VEHICLES(int p0) { invoke<Void>(0x43FD798CD0523B1F, p0); } // 0x43FD798CD0523B1F 0x5062875E
	static BOOL CAN_REGISTER_MISSION_OBJECTS(Any p0) { return invoke<BOOL>(0xF4C0E5422B82B8AF, p0); } // 0xF4C0E5422B82B8AF 0x7F85DFDE
	static BOOL CAN_REGISTER_MISSION_PEDS(Any p0) { return invoke<BOOL>(0x2357075D7B96D56A, p0); } // 0x2357075D7B96D56A 0xCCAA5CE9
	static BOOL CAN_REGISTER_MISSION_VEHICLES(BOOL p0) { return invoke<BOOL>(0x54EBD52F64A07B00, p0); } // 0x54EBD52F64A07B00 0x818B6830
	static BOOL CAN_REGISTER_MISSION_ENTITIES(BOOL p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0x4B112D7DC17F0DDE, p0, p1, p2, p3); } // 0x4B112D7DC17F0DDE 0x83794008
	static int GET_NUM_RESERVED_MISSION_OBJECTS(BOOL p0) { return invoke<int>(0xC124B46B968EA962, p0); } // 0xC124B46B968EA962 0x16A80CD6
	static int GET_NUM_RESERVED_MISSION_PEDS(BOOL p0) { return invoke<int>(0xA2D6CF086A2F622F, p0); } // 0xA2D6CF086A2F622F 0x6C25975C
	static int GET_NUM_RESERVED_MISSION_VEHICLES(BOOL p0) { return invoke<int>(0x71726B5B622E1778, p0); } // 0x71726B5B622E1778 0xA9A308F3
	static Any _0x9A122333624896D4(BOOL p0) { return invoke<Any>(0x9A122333624896D4, p0); } // 0x9A122333624896D4 0x603FA104
	static Any _0x4659AB0B12C8B30D(BOOL p0) { return invoke<Any>(0x4659AB0B12C8B30D, p0); } // 0x4659AB0B12C8B30D 0xD8FEC4F8
	static Any _0xA7DAE2A186E0ACC3(BOOL p0) { return invoke<Any>(0xA7DAE2A186E0ACC3, p0); } // 0xA7DAE2A186E0ACC3 0x20527695
	static Any _0xBFE4F69454EFE6A8() { return invoke<Any>(0xBFE4F69454EFE6A8); } // 0xBFE4F69454EFE6A8 0x8687E285
	static Any _0x306008C5DE2C3782() { return invoke<Any>(0x306008C5DE2C3782); } // 0x306008C5DE2C3782 0x744AC008
	static Any _0x9348406130B30E67() { return invoke<Any>(0x9348406130B30E67); } // 0x9348406130B30E67 0xC3A12135
	static Any _0x360FDC3C803B39C0() { return invoke<Any>(0x360FDC3C803B39C0); } // 0x360FDC3C803B39C0 0x6A036061
	static int GET_NETWORK_TIME() { return invoke<int>(0xCB150A8B81012128); } // 0xCB150A8B81012128 0x998103C2
	static int _0x8F8F2E80A7DA4D64() { return invoke<int>(0x8F8F2E80A7DA4D64); } // 0x8F8F2E80A7DA4D64 0x98AA48E5
	static Any _0x724510EFA1511190() { return invoke<Any>(0x724510EFA1511190); } // 0x724510EFA1511190 0x4538C4A2
	static int GET_TIME_OFFSET(int timeA, int timeB) { return invoke<int>(0xD9D7B8709F0A4696, timeA, timeB); } // 0xD9D7B8709F0A4696 0x2E079AE6
	static BOOL IS_TIME_LESS_THAN(int timeA, int timeB) { return invoke<BOOL>(0x94F6F6877B5A3EDF, timeA, timeB); } // 0x94F6F6877B5A3EDF 0x50EF8FC6
	static BOOL IS_TIME_MORE_THAN(int timeA, int timeB) { return invoke<BOOL>(0xC9DDE872F3412A54, timeA, timeB); } // 0xC9DDE872F3412A54 0xBBB6DF61
	static BOOL IS_TIME_EQUAL_TO(int timeA, int timeB) { return invoke<BOOL>(0xE3E22121ECA881AB, timeA, timeB); } // 0xE3E22121ECA881AB 0x8B4D1C06
	static int GET_TIME_DIFFERENCE(int timeA, int timeB) { return invoke<int>(0xDFD92E57E3A82E9C, timeA, timeB); } // 0xDFD92E57E3A82E9C 0x5666A837
	static char* _FORMAT_TIME(int time) { return invoke<char*>(0x5B9CB4CF56FEC869, time); } // 0x5B9CB4CF56FEC869 0x8218944E
	static int _GET_POSIX_TIME() { return invoke<int>(0x57E9911EC23E2C54); } // 0x57E9911EC23E2C54 0xF2FDF2E0
	static void _GET_DATE_AND_TIME_FROM_UNIX_EPOCH(int unixEpoch, Any* timeStructure) { invoke<Void>(0x394288DA6A60D4E9, unixEpoch, timeStructure); } // 0x394288DA6A60D4E9 0xBB7CCE49
	static void NETWORK_SET_IN_SPECTATOR_MODE(BOOL active, Player playerPed) { invoke<Void>(0x858DD33AFD804F9F, active, playerPed); } // 0x858DD33AFD804F9F 0x5C4C8458
	static void _0xDD6C930D4B10F693(BOOL p0, Any p1, BOOL p2) { invoke<Void>(0xDD6C930D4B10F693, p0, p1, p2); } // 0xDD6C930D4B10F693 0x54058F5F
	static void _0xB2D1F2235D2F2B9C(BOOL p0) { invoke<Void>(0xB2D1F2235D2F2B9C, p0); } // 0xB2D1F2235D2F2B9C 0xA7E36020
	static void _0xC4C27EF871586BB1(BOOL p0, Any p1) { invoke<Void>(0xC4C27EF871586BB1, p0, p1); } // 0xC4C27EF871586BB1 0x64235620
	static BOOL NETWORK_IS_IN_SPECTATOR_MODE() { return invoke<BOOL>(0xC4E56998929B26A3); } // 0xC4E56998929B26A3 0x3EAD9DB8
	static void NETWORK_SET_IN_MP_CUTSCENE(BOOL p0, BOOL p1) { invoke<Void>(0x58015D068E653507, p0, p1); } // 0x58015D068E653507 0x8434CB43
	static BOOL NETWORK_IS_IN_MP_CUTSCENE() { return invoke<BOOL>(0xEE1438344034E8AA); } // 0xEE1438344034E8AA 0x4BB33316
	static BOOL NETWORK_IS_PLAYER_IN_MP_CUTSCENE(Player player) { return invoke<BOOL>(0xB61C11E08C30F9CB, player); } // 0xB61C11E08C30F9CB 0x56F961E4
	static void SET_NETWORK_VEHICLE_RESPOT_TIMER(int netId, Any p1) { invoke<Void>(0xE078A0D7475B39FF, netId, p1); } // 0xE078A0D7475B39FF 0x2C30912D
	static void _0xC98E67AF76D214C7(Entity entity, BOOL p1) { invoke<Void>(0xC98E67AF76D214C7, entity, p1); } // 0xC98E67AF76D214C7 0xEA235081
	static void USE_PLAYER_COLOUR_INSTEAD_OF_TEAM_COLOUR(BOOL toggle) { invoke<Void>(0xBF60B15AF9063410, toggle); } // 0xBF60B15AF9063410 0x4DD46DAE
	static BOOL _0xD8E903806639546A(Any p0) { return invoke<BOOL>(0xD8E903806639546A, p0); } // 0xD8E903806639546A
	static void _0x3F004CC5981CCDEA(BOOL p0) { invoke<Void>(0x3F004CC5981CCDEA, p0); } // 0x3F004CC5981CCDEA
	static int NETWORK_CREATE_SYNCHRONISED_SCENE(float x, float y, float z, float xRot, float yRot, float zRot, int p6, int p7, int p8, float p9, int p10, float p11) { return invoke<int>(0xEFC1A93F65285B77, x, y, z, xRot, yRot, zRot, p6, p7, p8, p9, p10, p11); } // 0xEFC1A93F65285B77 0xB06FE3FE
	static void NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(Ped ped, int netScene, char* animDict, char* animnName, float speed, float speedMultiplier, int duration, int flag, float playbackRate, Any p9) { invoke<Void>(0x477EC31C5BA5FAD8, ped, netScene, animDict, animnName, speed, speedMultiplier, duration, flag, playbackRate, p9); } // 0x477EC31C5BA5FAD8 0xB386713E
	static void NETWORK_ADD_ENTITY_TO_SYNCHRONISED_SCENE(Entity entity, int netScene, char* animDict, char* animName, float speed, float speedMulitiplier, int flag) { invoke<Void>(0x74D8076D69F3BE4C, entity, netScene, animDict, animName, speed, speedMulitiplier, flag); } // 0x74D8076D69F3BE4C 0x10DD636C
	static void _0x9D95E38A3866F191(int netScene, char* animDict, char* animName) { invoke<Void>(0x9D95E38A3866F191, netScene, animDict, animName); } // 0x9D95E38A3866F191 0xBFFE8B5C
	static void NETWORK_ATTACH_SYNCHRONISED_SCENE_TO_ENTITY(int netScene, Entity entity, int bone) { invoke<Void>(0x877595B26A864FFF, netScene, entity, bone); } // 0x877595B26A864FFF 0x3FE5B222
	static void NETWORK_START_SYNCHRONISED_SCENE(int netScene) { invoke<Void>(0xD299F9D47AAE6209, netScene); } // 0xD299F9D47AAE6209 0xA9DFDC40
	static void NETWORK_STOP_SYNCHRONISED_SCENE(int netScene) { invoke<Void>(0x549FC2E6537EE931, netScene); } // 0x549FC2E6537EE931 0x97B1CDF6
	static int _NETWORK_UNLINK_NETWORKED_SYNCHRONISED_SCENE(int netScene) { return invoke<int>(0x91FFFB0475D539A1, netScene); } // 0x91FFFB0475D539A1 0x16AED87B
	static void _0xBF1FF5809E4777AC(Any p0) { invoke<Void>(0xBF1FF5809E4777AC, p0); } // 0xBF1FF5809E4777AC
	static Any _0xEA9E1C4BA09B0D20(int p0, Any p1) { return invoke<Any>(0xEA9E1C4BA09B0D20, p0, p1); } // 0xEA9E1C4BA09B0D20 0x0679CE71
	static BOOL _0xE6B73608C068F565(Player player, float p1, float p2, float p3, float p4, float p5, float p6, float p7, int flags) { return invoke<BOOL>(0xE6B73608C068F565, player, p1, p2, p3, p4, p5, p6, p7, flags); } // 0xE6B73608C068F565 0xC62E77B3
	static BOOL _0x42DDA1362F36AC50(Player player, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9, float p10, int flags) { return invoke<BOOL>(0x42DDA1362F36AC50, player, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, flags); } // 0x42DDA1362F36AC50 0x74D6B13C
	static Any _0x0395226B0E4E32A3(Any* p0) { return invoke<Any>(0x0395226B0E4E32A3, p0); } // 0x0395226B0E4E32A3 0x90700C7D
	static void _0xE54EC49C3C147EF3() { invoke<Void>(0xE54EC49C3C147EF3); } // 0xE54EC49C3C147EF3 0x44BFB619
	static void NETWORK_GET_RESPAWN_RESULT(Any p0, int* p1, int* p2) { invoke<Void>(0x93658CC9BA453FA2, p0, p1, p2); } // 0x93658CC9BA453FA2 0xDDFE9FBC
	static Any _0x1073EF7BBEACF9D9(Any p0) { return invoke<Any>(0x1073EF7BBEACF9D9, p0); } // 0x1073EF7BBEACF9D9 0x03287FD2
	static void _0xBD38FA4A142A1E1B() { invoke<Void>(0xBD38FA4A142A1E1B); } // 0xBD38FA4A142A1E1B 0x408A9436
	static void _0x5DCC9FC2E2D46B67(Any p0, Any p1) { invoke<Void>(0x5DCC9FC2E2D46B67, p0, p1); } // 0x5DCC9FC2E2D46B67 0xFFB2ADA1
	static void NETWORK_END_TUTORIAL_SESSION() { invoke<Void>(0x0A66D748F3BCA844); } // 0x0A66D748F3BCA844 0xBA57E53E
	static Any NETWORK_IS_IN_TUTORIAL_SESSION() { return invoke<Any>(0x51FDEF56E23A7C33); } // 0x51FDEF56E23A7C33 0x34DD7B28
	static Any _0x8B96535CD33037E4() { return invoke<Any>(0x8B96535CD33037E4); } // 0x8B96535CD33037E4 0x755A2B3E
	static Any _0x3FD6595DE5D24849() { return invoke<Any>(0x3FD6595DE5D24849); } // 0x3FD6595DE5D24849 0xA003C40B
	static Any _0xA5546322305E44C5(Any p0) { return invoke<Any>(0xA5546322305E44C5, p0); } // 0xA5546322305E44C5 0x5E1020CC
	static BOOL _0xECE6499178490DE1(Player player, int p1) { return invoke<BOOL>(0xECE6499178490DE1, player, p1); } // 0xECE6499178490DE1 0xE66A0B40
	static void _0x3878BBE6AF57A6FD(Any p0, BOOL p1) { invoke<Void>(0x3878BBE6AF57A6FD, p0, p1); } // 0x3878BBE6AF57A6FD 0x72052DB3
	static BOOL _0x780DF130C9CF301E(Any p0) { return invoke<BOOL>(0x780DF130C9CF301E, p0); } // 0x780DF130C9CF301E 0xB0313590
	static void NETWORK_OVERRIDE_CLOCK_TIME(int Hours, int Minutes, int Seconds) { invoke<Void>(0x8A2AB944595BC051, Hours, Minutes, Seconds); } // 0x8A2AB944595BC051 0xC077BCD6
	static void _0x09B956F0E133BBA9() { invoke<Void>(0x09B956F0E133BBA9); } // 0x09B956F0E133BBA9 0xC4AEAF49
	static Any _0x0F97A477234C5535() { return invoke<Any>(0x0F97A477234C5535); } // 0x0F97A477234C5535 0x2465296D
	static Any NETWORK_ADD_ENTITY_AREA(float p0, float p1, float p2, float p3, float p4, float p5) { return invoke<Any>(0x7578D68ED86C70E5, p0, p1, p2, p3, p4, p5); } // 0x7578D68ED86C70E5 0x51030E5B
	static Any _NETWORK_ADD_ENTITY_ANGLED_AREA(float p0, float p1, float p2, float p3, float p4, float p5, float p6) { return invoke<Any>(0x7FA0DE73F6A07797, p0, p1, p2, p3, p4, p5, p6); } // 0x7FA0DE73F6A07797
	static Any _0xD17373286D54E02A(float p0, float p1, float p2, float p3, float p4, float p5) { return invoke<Any>(0xD17373286D54E02A, p0, p1, p2, p3, p4, p5); } // 0xD17373286D54E02A 0x4C2C2B12
	static BOOL NETWORK_REMOVE_ENTITY_AREA(Any p0) { return invoke<BOOL>(0x6ACF6CEA82656F30, p0); } // 0x6ACF6CEA82656F30 0xEAB97F25
	static BOOL _0xF4B38546B3A1EDA3(Any p0) { return invoke<BOOL>(0xF4B38546B3A1EDA3, p0); } // 0xF4B38546B3A1EDA3 0x69956127
	static BOOL _0x88384729AD1C4262(Any p0) { return invoke<BOOL>(0x88384729AD1C4262, p0); } // 0x88384729AD1C4262 0xCB1CD6D3
	static BOOL _0xC3562A4B065033A3(Any p0) { return invoke<BOOL>(0xC3562A4B065033A3, p0); } // 0xC3562A4B065033A3 0xC6D53AA0
	static void _0xE7D50F1D1622D2F8(Any p0, BOOL p1) { invoke<Void>(0xE7D50F1D1622D2F8, p0, p1); } // 0xE7D50F1D1622D2F8 0x155465EE
	static BOOL _DOWNLOAD_BG_SCRIPT_RPF() { return invoke<BOOL>(0x20D11E99AD0A66A9); } // 0x20D11E99AD0A66A9 0x29532731
	static BOOL _HAS_BG_SCRIPT_BEEN_DOWNLOADED() { return invoke<BOOL>(0x318C0B712478BD0A); } // 0x318C0B712478BD0A
	static void _DOWNLOAD_TUNABLES() { invoke<Void>(0x2F9E83081D07712A); } // 0x2F9E83081D07712A 0xD760CAD5
	static BOOL _HAS_TUNABLES_BEEN_DOWNLOADED() { return invoke<BOOL>(0x166C7C7DA477EC83); } // 0x166C7C7DA477EC83
	static Any _0xC429CF623D45FF95() { return invoke<Any>(0xC429CF623D45FF95); } // 0xC429CF623D45FF95 0x231CFD12
	static BOOL NETWORK_DOES_TUNABLE_EXIST(char* tunableContext, char* tunableName) { return invoke<BOOL>(0xE7F893BEE679C1E1, tunableContext, tunableName); } // 0xE7F893BEE679C1E1 0x9FCE9C9A
	static BOOL NETWORK_ACCESS_TUNABLE_INT(char* tunableContext, char* tunableName, int* value) { return invoke<BOOL>(0x4F318964688EE8FB, tunableContext, tunableName, value); } // 0x4F318964688EE8FB 0xE4B3726A
	static BOOL NETWORK_ACCESS_TUNABLE_FLOAT(char* tunableContext, char* tunableName, float* value) { return invoke<BOOL>(0xD0FCC51B884AFE3C, tunableContext, tunableName, value); } // 0xD0FCC51B884AFE3C 0x41E8912A
	static BOOL NETWORK_ACCESS_TUNABLE_BOOL(char* tunableContext, char* tunableName) { return invoke<BOOL>(0x27B6B40708376AF9, tunableContext, tunableName); } // 0x27B6B40708376AF9 0x8A04E1FE
	static BOOL _NETWORK_DOES_TUNABLE_EXIST_HASH(Hash tunbaleContext, Hash tunableName) { return invoke<BOOL>(0x8680345927C7B34B, tunbaleContext, tunableName); } // 0x8680345927C7B34B
	static BOOL _NETWORK_ACCESS_TUNABLE_INT_HASH(Hash tunableContext, Hash tunableName, int* value) { return invoke<BOOL>(0x42CA69F85F8F7EEF, tunableContext, tunableName, value); } // 0x42CA69F85F8F7EEF
	static BOOL _NETWORK_ACCESS_TUNABLE_FLOAT_HASH(Hash tunableContext, Hash tunableName, float* value) { return invoke<BOOL>(0xF9B8E705BCF8B3BD, tunableContext, tunableName, value); } // 0xF9B8E705BCF8B3BD
	static BOOL _NETWORK_ACCESS_TUNABLE_BOOL_HASH(Hash tunableContext, Hash tunableName) { return invoke<BOOL>(0xCE3556A93DCE81D2, tunableContext, tunableName); } // 0xCE3556A93DCE81D2
	static BOOL _NETWORK_ACCESS_TUNABLE_BOOL_HASH_FAIL_VAL(Hash tunableContext, Hash tunableName, BOOL defaultValue) { return invoke<BOOL>(0xBC92F42219D2F1FA, tunableContext, tunableName, defaultValue); } // 0xBC92F42219D2F1FA
	static int _GET_TUNABLES_CONTENT_MODIFIER_ID(Hash contentHash) { return invoke<int>(0xE6E5B281D791FDB6, contentHash); } // 0xE6E5B281D791FDB6 0xA78571CA
	static Any _0x27F1B555D25FDCD7() { return invoke<Any>(0x27F1B555D25FDCD7); } // 0x27F1B555D25FDCD7 0x053BB329
	static void NETWORK_RESET_BODY_TRACKER() { invoke<Void>(0xDDCBCB448225F46E); } // 0xDDCBCB448225F46E 0x3914463F
	static Any _0x1328251078AAA35E() { return invoke<Any>(0x1328251078AAA35E); } // 0x1328251078AAA35E 0x17CBC608
	static BOOL _0x1F029B02ADCA5BFC(Any p0) { return invoke<BOOL>(0x1F029B02ADCA5BFC, p0); } // 0x1F029B02ADCA5BFC 0xBFAA349B
	static BOOL _0xDB0CFCA496C3FAC9(Any p0, Any p1) { return invoke<BOOL>(0xDB0CFCA496C3FAC9, p0, p1); } // 0xDB0CFCA496C3FAC9 0xBEB7281A
	static Any NETWORK_EXPLODE_VEHICLE(Vehicle vehicle, BOOL isAudible, BOOL isInvisible, BOOL p3) { return invoke<Any>(0x09D52DDC145E0C3F, vehicle, isAudible, isInvisible, p3); } // 0x09D52DDC145E0C3F 0x0E1B38AE
	static void _0x1ABAD35B0CD8C007(Entity entity) { invoke<Void>(0x1ABAD35B0CD8C007, entity); } // 0x1ABAD35B0CD8C007 0xBC54371B
	static void _0x8B4C881D31D865B8(Ped ped, float x, float y, float z, float p4) { invoke<Void>(0x8B4C881D31D865B8, ped, x, y, z, p4); } // 0x8B4C881D31D865B8 0x644141C5
	static void _0x48E4B6DC7C5AE995(int netID) { invoke<Void>(0x48E4B6DC7C5AE995, netID); } // 0x48E4B6DC7C5AE995
	static void NETWORK_SET_PROPERTY_ID(Any p0) { invoke<Void>(0xE6F88BADA3B20FF7, p0); } // 0xE6F88BADA3B20FF7 0x5A74E873
	static void _0x8A400CA6F7E29FF3() { invoke<Void>(0x8A400CA6F7E29FF3); } // 0x8A400CA6F7E29FF3 0x38BC35C8
	static void _0xDC0FC9EF278767EB(int p0) { invoke<Void>(0xDC0FC9EF278767EB, p0); } // 0xDC0FC9EF278767EB 0x53C9563C
	static void _0x476B18330F24CED5(BOOL p0) { invoke<Void>(0x476B18330F24CED5, p0); } // 0x476B18330F24CED5 0x6B97075B
	static void _0x00F3647C918C1C7B() { invoke<Void>(0x00F3647C918C1C7B); } // 0x00F3647C918C1C7B
	static BOOL _0x8D226693BE2BF4F6(Any p0) { return invoke<BOOL>(0x8D226693BE2BF4F6, p0); } // 0x8D226693BE2BF4F6
	static BOOL _0xEB73E3D18E54C32B(Ped ped, Player player) { return invoke<BOOL>(0xEB73E3D18E54C32B, ped, player); } // 0xEB73E3D18E54C32B
	static Any _0xC79B2DE92A346852() { return invoke<Any>(0xC79B2DE92A346852); } // 0xC79B2DE92A346852 0x965EA007
	static Any _0x495574243360B6B0() { return invoke<Any>(0x495574243360B6B0); } // 0x495574243360B6B0 0xEEFC8A55
	static void _0x291DDB49FDF075F0(Any p0) { invoke<Void>(0x291DDB49FDF075F0, p0); } // 0x291DDB49FDF075F0 0x866D1B67
	static Any _0xA846D3C234015DA3() { return invoke<Any>(0xA846D3C234015DA3); } // 0xA846D3C234015DA3 0xED4A272F
	static Any _0x94E556805DABBC7A(Any p0) { return invoke<Any>(0x94E556805DABBC7A, p0); } // 0x94E556805DABBC7A 0x4ACF110C
	static Any _0xFD95E40A76A2CC1F(Any p0) { return invoke<Any>(0xFD95E40A76A2CC1F, p0); } // 0xFD95E40A76A2CC1F 0x1AA3A0D5
	static Any _0x3231F3A9900127C6(Any p0) { return invoke<Any>(0x3231F3A9900127C6, p0); } // 0x3231F3A9900127C6 0x37877757
	static Any _0x8620F646E8C3A1CB(Any p0) { return invoke<Any>(0x8620F646E8C3A1CB, p0); } // 0x8620F646E8C3A1CB 0x1CF89DA5
	static Any _0x9F5289CAB68A347F(Any p0, Any p1) { return invoke<Any>(0x9F5289CAB68A347F, p0, p1); } // 0x9F5289CAB68A347F 0x16E53875
	static void _0xBE400BEB43FB875F(Any p0, Any p1) { invoke<Void>(0xBE400BEB43FB875F, p0, p1); } // 0xBE400BEB43FB875F 0x365C50EE
	static Any _0x1CE7791470873719() { return invoke<Any>(0x1CE7791470873719); } // 0x1CE7791470873719 0x25E2DBA9
	static void SET_STORE_ENABLED(BOOL toggle) { invoke<Void>(0xDF5F1D59B2CA95DF, toggle); } // 0xDF5F1D59B2CA95DF 0xC1F6443B
	static BOOL _0x4BA8A16DCFFED248(Any p0) { return invoke<BOOL>(0x4BA8A16DCFFED248, p0); } // 0x4BA8A16DCFFED248 0x1FDC75DC
	static void _0x86445A407E989EED() { invoke<Void>(0x86445A407E989EED); } // 0x86445A407E989EED 0xCA7A0A49
	static Any _0xAC748C1C03D99A71(Any p0) { return invoke<Any>(0xAC748C1C03D99A71, p0); } // 0xAC748C1C03D99A71 0x44A58B0A
	static Any _0xE36F5BB02676D469() { return invoke<Any>(0xE36F5BB02676D469); } // 0xE36F5BB02676D469 0xD32FA11F
	static void _0xF40DE2D77918A5FA() { invoke<Void>(0xF40DE2D77918A5FA); } // 0xF40DE2D77918A5FA 0xA7FA70AE
	static void _0x8F24DE730F9633F4() { invoke<Void>(0x8F24DE730F9633F4); } // 0x8F24DE730F9633F4 0xCC7DCE24
	static Any _0x603F74F51671502F() { return invoke<Any>(0x603F74F51671502F); } // 0x603F74F51671502F 0x70F6D3AD
	static void _0x7349E3FD67CB2A44(Any p0, Any p1, Any p2) { invoke<Void>(0x7349E3FD67CB2A44, p0, p1, p2); } // 0x7349E3FD67CB2A44
	static Any _0xAA12D65CC961668C(Any* p0) { return invoke<Any>(0xAA12D65CC961668C, p0); } // 0xAA12D65CC961668C 0x2B7B57B3
	static BOOL _0x58E3ED350392E425(Any p0) { return invoke<BOOL>(0x58E3ED350392E425, p0); } // 0x58E3ED350392E425 0xBAF52DD8
	static BOOL _0xAA934D39108FA5FE(Any p0) { return invoke<BOOL>(0xAA934D39108FA5FE, p0); } // 0xAA934D39108FA5FE 0x9B9AFFF1
	static void _0x8903CF673CCD137C() { invoke<Void>(0x8903CF673CCD137C); } // 0x8903CF673CCD137C 0xC38E9DB0
	static Any _0x3BE11A249B7411D5() { return invoke<Any>(0x3BE11A249B7411D5); } // 0x3BE11A249B7411D5 0x32A4EB22
	static Any _0xC4F410904476FC1C() { return invoke<Any>(0xC4F410904476FC1C); } // 0xC4F410904476FC1C 0x9262744C
	static Any _0xBE0962F3D0CD81C6() { return invoke<Any>(0xBE0962F3D0CD81C6); } // 0xBE0962F3D0CD81C6
	static Any _0xB6997BCB406C5C6A() { return invoke<Any>(0xB6997BCB406C5C6A); } // 0xB6997BCB406C5C6A
	static Any _0x9E21E0507CE71E32() { return invoke<Any>(0x9E21E0507CE71E32); } // 0x9E21E0507CE71E32
	static void _0x20C7716E2C72E95F() { invoke<Void>(0x20C7716E2C72E95F); } // 0x20C7716E2C72E95F
	static BOOL _0x79FE336E719ECEBD(Any* p0, Any* p1) { return invoke<BOOL>(0x79FE336E719ECEBD, p0, p1); } // 0x79FE336E719ECEBD 0x08243B79
	static Any _0x27024315C6C7EA12() { return invoke<Any>(0x27024315C6C7EA12); } // 0x27024315C6C7EA12 0x798D6C27
	static Any _0x1FEE2EC11E723BEA() { return invoke<Any>(0x1FEE2EC11E723BEA); } // 0x1FEE2EC11E723BEA 0xE69E8D0D
	static Any _0xD94BF021E9203E78() { return invoke<Any>(0xD94BF021E9203E78); } // 0xD94BF021E9203E78 0x742075FE
	static Any _0x64536605E79748E7() { return invoke<Any>(0x64536605E79748E7); } // 0x64536605E79748E7 0xCE569932
	static Any _0x240D6A4CA493E8B6() { return invoke<Any>(0x240D6A4CA493E8B6); } // 0x240D6A4CA493E8B6 0x82146BE9
	static void _0xBD92CC6DA06C717A() { invoke<Void>(0xBD92CC6DA06C717A); } // 0xBD92CC6DA06C717A 0x133FF2D5
	static BOOL _0xCD1A1B0AB6F5ABE2(Any p0, Any p1, Any* p2, Any p3, Any p4, Any p5) { return invoke<BOOL>(0xCD1A1B0AB6F5ABE2, p0, p1, p2, p3, p4, p5); } // 0xCD1A1B0AB6F5ABE2 0xCBA7242F
	static BOOL _0xA4BD58BBA1927FBD(Any p0, Any p1, Any p2, Any* p3, Any p4, BOOL p5) { return invoke<BOOL>(0xA4BD58BBA1927FBD, p0, p1, p2, p3, p4, p5); } // 0xA4BD58BBA1927FBD
	static BOOL _0x53F0633B39D49EE4(Any* p0, BOOL p1, Any* p2) { return invoke<BOOL>(0x53F0633B39D49EE4, p0, p1, p2); } // 0x53F0633B39D49EE4 0xDED82A6E
	static BOOL _0x29C4FFFF415B914C(Any* p0, Any p1, BOOL p2, Any* p3) { return invoke<BOOL>(0x29C4FFFF415B914C, p0, p1, p2, p3); } // 0x29C4FFFF415B914C
	static BOOL _0xD2CBEA8198A45E01(Any p0, Any p1, Any* p2, Any p3) { return invoke<BOOL>(0xD2CBEA8198A45E01, p0, p1, p2, p3); } // 0xD2CBEA8198A45E01 0x40CF0783
	static BOOL _0xE6539A5D21C2CE15(Any p0, Any p1, Any* p2, Any* p3) { return invoke<BOOL>(0xE6539A5D21C2CE15, p0, p1, p2, p3); } // 0xE6539A5D21C2CE15 0x4609D596
	static BOOL _0x364D389396317447(Any p0, Any p1, Any* p2, Any* p3) { return invoke<BOOL>(0x364D389396317447, p0, p1, p2, p3); } // 0x364D389396317447 0x4C2C0D1F
	static BOOL _0xBDC95F1989147744(Any p0, Any p1, Any* p2, Any* p3) { return invoke<BOOL>(0xBDC95F1989147744, p0, p1, p2, p3); } // 0xBDC95F1989147744 0x9EFBD5D1
	static BOOL _0xD78F44A1F14C45D8(Any p0, Any p1, Any p2, Any* p3, Any* p4) { return invoke<BOOL>(0xD78F44A1F14C45D8, p0, p1, p2, p3, p4); } // 0xD78F44A1F14C45D8 0xA6D8B798
	static BOOL _0xCBF155ACAC7FAA16(Any p0, Any p1, Any p2, Any* p3, Any* p4) { return invoke<BOOL>(0xCBF155ACAC7FAA16, p0, p1, p2, p3, p4); } // 0xCBF155ACAC7FAA16 0x67E74842
	static BOOL SET_BALANCE_ADD_MACHINE(Any* p0, Any* p1) { return invoke<BOOL>(0xC303D95D12685162, p0, p1); } // 0xC303D95D12685162 0xE123C7AC
	static BOOL SET_BALANCE_ADD_MACHINES(Any* p0, Any p1, Any* p2) { return invoke<BOOL>(0x1C0E501152E56A0B, p0, p1, p2); } // 0x1C0E501152E56A0B 0x22C33603
	static BOOL _0xB4D2194215C3FB99(Any p0, Any p1, Any* p2, Any* p3) { return invoke<BOOL>(0xB4D2194215C3FB99, p0, p1, p2, p3); } // 0xB4D2194215C3FB99 0x37F5BD93
	static BOOL NETWORK_GET_BACKGROUND_LOADING_RECIPIENTS(Any p0, Any p1, Any* p2, Any* p3) { return invoke<BOOL>(0xFFCAFC7CE0A68647, p0, p1, p2, p3); } // 0xFFCAFC7CE0A68647 0x1CFB3F51
	static BOOL _0x15121DD62D8443F9(Any p0, Any p1, Any* p2, Any* p3) { return invoke<BOOL>(0x15121DD62D8443F9, p0, p1, p2, p3); } // 0x15121DD62D8443F9 0x87D1E6BD
	static void _0xCBE2021B1969CE01() { invoke<Void>(0xCBE2021B1969CE01); } // 0xCBE2021B1969CE01 0x021D5A94
	static Any _0x5270A333DB8972E6() { return invoke<Any>(0x5270A333DB8972E6); } // 0x5270A333DB8972E6 0x4908A514
	static Any _0x65EC659404540DDA() { return invoke<Any>(0x65EC659404540DDA); } // 0x65EC659404540DDA 0x50296140
	static Any _0xE954C5DD587BC487() { return invoke<Any>(0xE954C5DD587BC487); } // 0xE954C5DD587BC487 0x3970B0DA
	static Any _0x19A334D598E7C108() { return invoke<Any>(0x19A334D598E7C108); } // 0x19A334D598E7C108 0xC1487110
	static Any _0xEBAA8D54A8E4A262() { return invoke<Any>(0xEBAA8D54A8E4A262); } // 0xEBAA8D54A8E4A262 0xCC2356E3
	static Any _0xEE7670C3E86576DD() { return invoke<Any>(0xEE7670C3E86576DD); } // 0xEE7670C3E86576DD 0x2DE69817
	static Any _0x238FFB39D6F554D6() { return invoke<Any>(0x238FFB39D6F554D6); } // 0x238FFB39D6F554D6 0x81BD8D3B
	static Any _0xB659988151EC1B2A() { return invoke<Any>(0xB659988151EC1B2A); } // 0xB659988151EC1B2A 0x8E1D8F78
	static void _0x07B5EC3A715EB8A0() { invoke<Void>(0x07B5EC3A715EB8A0); } // 0x07B5EC3A715EB8A0 0x0D35DD93
	static char* _GET_CONTENT_USER_ID(int p0) { return invoke<char*>(0x0F6A326384FF1386, p0); } // 0x0F6A326384FF1386 0x8F3137E6
	static BOOL _0x7ADADBC8BF607F59(Any p0, Any* p1) { return invoke<BOOL>(0x7ADADBC8BF607F59, p0, p1); } // 0x7ADADBC8BF607F59
	static BOOL _0x332B7A5084B2FE1F(Any p0) { return invoke<BOOL>(0x332B7A5084B2FE1F, p0); } // 0x332B7A5084B2FE1F
	static Any _0x6E63715954663514(Any p0) { return invoke<Any>(0x6E63715954663514, p0); } // 0x6E63715954663514 0xB9137BA7
	static BOOL _0x6EFE5A7418D5B45A(Any p0) { return invoke<BOOL>(0x6EFE5A7418D5B45A, p0); } // 0x6EFE5A7418D5B45A 0x9FEEAA9C
	static int _GET_CONTENT_CATEGORY(int p0) { return invoke<int>(0x9476E3BEABD45EE7, p0); } // 0x9476E3BEABD45EE7 0x5E8A7559
	static char* _GET_CONTENT_ID(Any p0) { return invoke<char*>(0xF60E240F18A45E74, p0); } // 0xF60E240F18A45E74 0x331AEABF
	static char* _GET_ROOT_CONTENT_ID(Any p0) { return invoke<char*>(0xEE35337E483142C4, p0); } // 0xEE35337E483142C4 0x0E5E8E5C
	static Any _0x450A20AE5B480415(Any p0) { return invoke<Any>(0x450A20AE5B480415, p0); } // 0x450A20AE5B480415 0xA5A0C695
	static int _GET_CONTENT_DESCRIPTION_HASH(Any p0) { return invoke<int>(0x6A8E445E09525604, p0); } // 0x6A8E445E09525604 0x91534C6E
	static Any _0x51D177963C1D305E(Any p0, Any p1) { return invoke<Any>(0x51D177963C1D305E, p0, p1); } // 0x51D177963C1D305E 0x744A9EA5
	static void _0xC5447C13AE9BBB23(Any p0, Any* p1) { invoke<Void>(0xC5447C13AE9BBB23, p0, p1); } // 0xC5447C13AE9BBB23 0xA19A238D
	static Any _GET_CONTENT_FILE_VERSION(Any p0, Any p1) { return invoke<Any>(0xEE4AD17A47DE1FB0, p0, p1); } // 0xEE4AD17A47DE1FB0 0xFF7D44E6
	static BOOL _0xF757C7AD9D82553E(Any p0) { return invoke<BOOL>(0xF757C7AD9D82553E, p0); } // 0xF757C7AD9D82553E
	static BOOL _0x029D013657F91B1C(Any p0) { return invoke<BOOL>(0x029D013657F91B1C, p0); } // 0x029D013657F91B1C
	static Any _0x7BE7B9F1E70C3985(Any p0) { return invoke<Any>(0x7BE7B9F1E70C3985, p0); } // 0x7BE7B9F1E70C3985 0xA2C5BD9D
	static BOOL _0xA0195852C2C8BF24(Any p0) { return invoke<BOOL>(0xA0195852C2C8BF24, p0); } // 0xA0195852C2C8BF24 0xA850DDE1
	static BOOL _0x19CAB5E9F434CAE7(Any p0) { return invoke<BOOL>(0x19CAB5E9F434CAE7, p0); } // 0x19CAB5E9F434CAE7 0x8F6754AE
	static Any _0xAD63FAB8C9CDB0B0(Any p0, Any p1) { return invoke<Any>(0xAD63FAB8C9CDB0B0, p0, p1); } // 0xAD63FAB8C9CDB0B0 0x1E34953F
	static Any _0xF64A36CEF66C2E7E(Any p0, Any p1) { return invoke<Any>(0xF64A36CEF66C2E7E, p0, p1); } // 0xF64A36CEF66C2E7E 0x771FE190
	static Any _0x1D6A651CB1724485(Any p0, Any p1) { return invoke<Any>(0x1D6A651CB1724485, p0, p1); } // 0x1D6A651CB1724485 0x3276D9D3
	static Any _0xCFA8142D0AB3F62E(Any p0, Any p1) { return invoke<Any>(0xCFA8142D0AB3F62E, p0, p1); } // 0xCFA8142D0AB3F62E 0x41A0FB02
	static BOOL _0xC407062153252EFB(Any p0) { return invoke<BOOL>(0xC407062153252EFB, p0); } // 0xC407062153252EFB 0x11DC0F27
	static BOOL _0xE3A49CA01F56731E(Any p0) { return invoke<BOOL>(0xE3A49CA01F56731E, p0); } // 0xE3A49CA01F56731E 0x0DEB3F5A
	static Any _0x171DF6A0C07FB3DC(Any p0, Any p1) { return invoke<Any>(0x171DF6A0C07FB3DC, p0, p1); } // 0x171DF6A0C07FB3DC 0x84315226
	static Any _0x7FD2990AF016795E(Any* p0, Any* p1, Any p2, Any p3, Any p4) { return invoke<Any>(0x7FD2990AF016795E, p0, p1, p2, p3, p4); } // 0x7FD2990AF016795E 0x38FC2EEB
	static Any _0x8C4F32DF81D928A6(Any p0) { return invoke<Any>(0x8C4F32DF81D928A6, p0); } // 0x8C4F32DF81D928A6 0x1C4F9FDB
	static BOOL _0xEDA5C7F8DBC4971F(Any p0) { return invoke<BOOL>(0xEDA5C7F8DBC4971F, p0); } // 0xEDA5C7F8DBC4971F 0xA69AE16C
	static BOOL _0xC1F63189707C8C0E(Any p0) { return invoke<BOOL>(0xC1F63189707C8C0E, p0); } // 0xC1F63189707C8C0E 0xF50BC67A
	static BOOL _0xCB82228504DF755A(Any p0) { return invoke<BOOL>(0xCB82228504DF755A, p0); } // 0xCB82228504DF755A 0xB3BBD241
	static Any _0xD4D51C7C86889F60(Any p0, Any p1) { return invoke<Any>(0xD4D51C7C86889F60, p0, p1); } // 0xD4D51C7C86889F60 0x70A2845C
	static BOOL _0xCA077AABEAB5210A(Any p0) { return invoke<BOOL>(0xCA077AABEAB5210A, p0); } // 0xCA077AABEAB5210A 0x346B506C
	static void _0x8846E1A5827118BB() { invoke<Void>(0x8846E1A5827118BB); } // 0x8846E1A5827118BB 0x0095DB71
	static BOOL _0x4DE1BD5BBC1CD3C2(Any* p0, Any* p1, Any* p2) { return invoke<BOOL>(0x4DE1BD5BBC1CD3C2, p0, p1, p2); } // 0x4DE1BD5BBC1CD3C2 0xAD334B40
	static BOOL _0x507E7F1CA7AF3F93(Any* p0, BOOL p1, Any* p2) { return invoke<BOOL>(0x507E7F1CA7AF3F93, p0, p1, p2); } // 0x507E7F1CA7AF3F93 0x980D45D7
	static BOOL _0x24622D2C0AFEE20C(Any* p0, BOOL p1, Any* p2) { return invoke<BOOL>(0x24622D2C0AFEE20C, p0, p1, p2); } // 0x24622D2C0AFEE20C 0x48CCC328
	static Any _0x88B3A82207A192F2() { return invoke<Any>(0x88B3A82207A192F2); } // 0x88B3A82207A192F2 0x8E664EFD
	static Any _0x757B68C6638C2DA6() { return invoke<Any>(0x757B68C6638C2DA6); } // 0x757B68C6638C2DA6 0x611E0BE2
	static Any _0x203C780ABF8A7E0A() { return invoke<Any>(0x203C780ABF8A7E0A); } // 0x203C780ABF8A7E0A 0xF0211AC1
	static Any _0x38C6473B53241D97() { return invoke<Any>(0x38C6473B53241D97); } // 0x38C6473B53241D97 0x1F0DD8AF
	static void _0x2FF61FD61BC59934() { invoke<Void>(0x2FF61FD61BC59934); } // 0x2FF61FD61BC59934 0x405ECA16
	static BOOL _0x96ABF1B3D3BAC4A1(Any* p0, Any* p1) { return invoke<BOOL>(0x96ABF1B3D3BAC4A1, p0, p1); } // 0x96ABF1B3D3BAC4A1 0x9567392B
	static Any _0xA9FF6AAD830594E4() { return invoke<Any>(0xA9FF6AAD830594E4); } // 0xA9FF6AAD830594E4 0xF79FFF3C
	static Any _0xDED90A226849F2E8() { return invoke<Any>(0xDED90A226849F2E8); } // 0xDED90A226849F2E8 0xA7F3F82B
	static Any _0xE95E6BA8D598A4CC() { return invoke<Any>(0xE95E6BA8D598A4CC); } // 0xE95E6BA8D598A4CC 0x410C61D1
	static BOOL _0xECC73AE53A0631F8(Any p0) { return invoke<BOOL>(0xECC73AE53A0631F8, p0); } // 0xECC73AE53A0631F8 0x0D4F845D
	static void _0x9CCDB2F081188D4D() { invoke<Void>(0x9CCDB2F081188D4D); } // 0x9CCDB2F081188D4D 0xE13C1F7F
	static void _0x15D0F7DC829D317B(BOOL p0) { invoke<Void>(0x15D0F7DC829D317B, p0); } // 0x15D0F7DC829D317B 0x213C6D36
	static void _0x77D39EBEFCB55AE4(BOOL p0) { invoke<Void>(0x77D39EBEFCB55AE4, p0); } // 0x77D39EBEFCB55AE4 0x511E6F50
	static BOOL _0xFB0F923C474E44C0(Any p0) { return invoke<BOOL>(0xFB0F923C474E44C0, p0); } // 0xFB0F923C474E44C0 0xB4668B23
	static BOOL _0x438DB6E08A113713(Any* p0, Any p1, Any p2) { return invoke<BOOL>(0x438DB6E08A113713, p0, p1, p2); } // 0x438DB6E08A113713 0x30B51753
	static Any _0xA662DAB720F42B5C() { return invoke<Any>(0xA662DAB720F42B5C); } // 0xA662DAB720F42B5C 0x02DAD93F
	static BOOL _0x3797E9276BB70DC3(Any p0) { return invoke<BOOL>(0x3797E9276BB70DC3, p0); } // 0x3797E9276BB70DC3 0x2D947814
	static Any _0x10FA48822B80810A() { return invoke<Any>(0x10FA48822B80810A); } // 0x10FA48822B80810A 0x37A28C26
	static Any _0xC071D514AFED95D4() { return invoke<Any>(0xC071D514AFED95D4); } // 0xC071D514AFED95D4 0x11E8B5CD
	static Any _0x4D79D5FCC85E82F8() { return invoke<Any>(0x4D79D5FCC85E82F8); } // 0x4D79D5FCC85E82F8 0x429AEAB3
	static int TEXTURE_DOWNLOAD_REQUEST(int* PlayerHandle, char* FilePath, char* Name, BOOL p3) { return invoke<int>(0xF9D69142CFAABE83, PlayerHandle, FilePath, Name, p3); } // 0xF9D69142CFAABE83 0xAD546CC3
	static Any _0xED8E660DE00AC098(Any* p0, Any* p1, BOOL p2) { return invoke<Any>(0xED8E660DE00AC098, p0, p1, p2); } // 0xED8E660DE00AC098 0x1856D008
	static Any _0xEE38B252F829AA28(Any* p0, Any p1, Any p2, Any p3, Any* p4, BOOL p5) { return invoke<Any>(0xEE38B252F829AA28, p0, p1, p2, p3, p4, p5); } // 0xEE38B252F829AA28 0x68C9AF69
	static void TEXTURE_DOWNLOAD_RELEASE(int p0) { invoke<Void>(0x12BA71481B28205E, p0); } // 0x12BA71481B28205E 0xEE8D9E70
	static BOOL TEXTURE_DOWNLOAD_HAS_FAILED(int p0) { return invoke<BOOL>(0x7669BF13593BB0D0, p0); } // 0x7669BF13593BB0D0 0xE4547765
	static char* TEXTURE_DOWNLOAD_GET_NAME(int p0) { return invoke<char*>(0x983E58D77B28DA15, p0); } // 0x983E58D77B28DA15 0xA40EF65A
	static Any _0x4A584676AEB387CC(Any p0) { return invoke<Any>(0x4A584676AEB387CC, p0); } // 0x4A584676AEB387CC 0x03225BA3
	static Any _0x1B8CEC57249A9137() { return invoke<Any>(0x1B8CEC57249A9137); } // 0x1B8CEC57249A9137 0x4DEBC227
	static Any _0xED744D696AC61363() { return invoke<Any>(0xED744D696AC61363); } // 0xED744D696AC61363 0x5C065D55
	static Any _0xBEF1C6430F4D8B14() { return invoke<Any>(0xBEF1C6430F4D8B14); } // 0xBEF1C6430F4D8B14 0x0CA1167F
	static Any _0xFF5DB9468244217E() { return invoke<Any>(0xFF5DB9468244217E); } // 0xFF5DB9468244217E 0x424C6E27
	static BOOL _IS_ROCKSTAR_BANNED() { return invoke<BOOL>(0x90AC3AB2A147035D); } // 0x90AC3AB2A147035D 0xD3BBE42F
	static BOOL _IS_SOCIALCLUB_BANNED() { return invoke<BOOL>(0x6B1A73CF1E472B72); } // 0x6B1A73CF1E472B72 0xBDBB5948
	static BOOL _CAN_PLAY_ONLINE() { return invoke<BOOL>(0x3789ED0E358D6F41); } // 0x3789ED0E358D6F41 0x97287D68
	static Any _0x41C6EE462E89540F() { return invoke<Any>(0x41C6EE462E89540F); } // 0x41C6EE462E89540F 0xC6EA802E
	static BOOL _0x07968C5C1EEDC177(Any p0) { return invoke<BOOL>(0x07968C5C1EEDC177, p0); } // 0x07968C5C1EEDC177 0xFD261E30
	static BOOL _0x6F63A5A50A30E8EB(Any p0, Any* p1, Any* p2) { return invoke<BOOL>(0x6F63A5A50A30E8EB, p0, p1, p2); } // 0x6F63A5A50A30E8EB 0x8570DD34
	static Any _0x017971300978783B() { return invoke<Any>(0x017971300978783B); } // 0x017971300978783B
	static Any _0x31038BF1A9E8DBE4() { return invoke<Any>(0x31038BF1A9E8DBE4); } // 0x31038BF1A9E8DBE4
	static Any _0x881930817E5BC788(Any p0) { return invoke<Any>(0x881930817E5BC788, p0); } // 0x881930817E5BC788
	static Any _0x0687290921191186(Any p0) { return invoke<Any>(0x0687290921191186, p0); } // 0x0687290921191186
	static void _0x3484D6FE1023D321() { invoke<Void>(0x3484D6FE1023D321); } // 0x3484D6FE1023D321 0x273C6180
	static void _0x46E92A09DFA9C7E1() { invoke<Void>(0x46E92A09DFA9C7E1); } // 0x46E92A09DFA9C7E1 0x371BBA08
	static void _0x493460C4292139F4(BOOL p0) { invoke<Void>(0x493460C4292139F4, p0); } // 0x493460C4292139F4 0xA100CC97
	static void _0xE90CCE915745B79C(Any p0, BOOL p1) { invoke<Void>(0xE90CCE915745B79C, p0, p1); } // 0xE90CCE915745B79C 0xBB2D33D3
	static void _0x67E7E44AAA6A4A8F(Any p0) { invoke<Void>(0x67E7E44AAA6A4A8F, p0); } // 0x67E7E44AAA6A4A8F
	static void _0xA1A97788BA5DB1E6() { invoke<Void>(0xA1A97788BA5DB1E6); } // 0xA1A97788BA5DB1E6
	static Any _0x28301B0AB8C694D5() { return invoke<Any>(0x28301B0AB8C694D5); } // 0x28301B0AB8C694D5
	static void _0x63F7470FE0B784A4() { invoke<Void>(0x63F7470FE0B784A4); } // 0x63F7470FE0B784A4
}

namespace NETWORKCASH
{
	static void NETWORK_INITIALIZE_CASH(int p0, int p1) { invoke<Void>(0xFF8F063932DA4346, p0, p1); } // 0xFF8F063932DA4346 0x66DA9935
	static void NETWORK_DELETE_CHARACTER(int characterIndex, BOOL p1, BOOL p2) { invoke<Void>(0xD67788D84C080330, characterIndex, p1, p2); } // 0xD67788D84C080330 0xA9F7E9C3
	static void _0x0572381725C37F21(Any p0) { invoke<Void>(0x0572381725C37F21, p0); } // 0x0572381725C37F21 0x19F0C471
	static void NETWORK_GIVE_PLAYER_JOBSHARE_CASH(int amount, Player* player) { invoke<Void>(0x545E1DCCB51DF97C, amount, player); } // 0x545E1DCCB51DF97C 0xC6047FDB
	static void NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH(int amount, Player* player) { invoke<Void>(0x935DB7A4F09EE25C, amount, player); } // 0x935DB7A4F09EE25C 0x4ED71C1A
	static Any _0x8E5FB8658224FE82() { return invoke<Any>(0x8E5FB8658224FE82); } // 0x8E5FB8658224FE82 0xA27B9FE8
	static void NETWORK_REFUND_CASH(int index, char* context, char* reason, BOOL unk) { invoke<Void>(0x044237928769C94B, index, context, reason, unk); } // 0x044237928769C94B 0x07C92F21
	static BOOL _0x422BC40612F51FA6(Any p0, BOOL p1, BOOL p2) { return invoke<BOOL>(0x422BC40612F51FA6, p0, p1, p2); } // 0x422BC40612F51FA6 0x8474E6F0
	static BOOL NETWORK_CAN_BET(Any p0) { return invoke<BOOL>(0x0A6D5454B089808B, p0); } // 0x0A6D5454B089808B 0xE3802533
	static void NETWORK_EARN_FROM_PICKUP(int amount) { invoke<Void>(0xEA0C18492D8EBE80, amount); } // 0xEA0C18492D8EBE80 0x70A0ED62
	static void _0x2E2C8A05FFD3A922(int amount) { invoke<Void>(0x2E2C8A05FFD3A922, amount); } // 0x2E2C8A05FFD3A922 0x33C20BC4
	static void _NETWORK_EARN_FROM_BAG(int amount) { invoke<Void>(0x14EC28A4A9062D48, amount); } // 0x14EC28A4A9062D48 0x30B3EC0A
	static void _NETWORK_EARN_FROM_CRATE_DROP(int amount) { invoke<Void>(0x3713E89DB6123D21, amount); } // 0x3713E89DB6123D21 0xEAF04923
	static void NETWORK_EARN_FROM_BETTING(int amount, char* p1) { invoke<Void>(0x8BDDC3A1C608CB98, amount, p1); } // 0x8BDDC3A1C608CB98 0xA0F7F07C
	static void NETWORK_EARN_FROM_JOB(int amount, char* p1) { invoke<Void>(0xBA66439E35BCCEBF, amount, p1); } // 0xBA66439E35BCCEBF 0x0B6997FC
	static void _0x560FC4AE4AF8439E(Any p0, Any* p1) { invoke<Void>(0x560FC4AE4AF8439E, p0, p1); } // 0x560FC4AE4AF8439E 0x5E81F55C
	static void _0xF32C08C0F8712409(Any p0, Any* p1, BOOL p2) { invoke<Void>(0xF32C08C0F8712409, p0, p1, p2); } // 0xF32C08C0F8712409 0x2BEFB6C4
	static void NETWORK_EARN_FROM_BOUNTY(int amount, int* playerHandle, Any* p2, Any p3) { invoke<Void>(0xF18338B3588F18E8, amount, playerHandle, p2, p3); } // 0xF18338B3588F18E8 0x127F2DAE
	static void NETWORK_EARN_FROM_IMPORT_EXPORT(Any p0, Any p1) { invoke<Void>(0x3229C056C28C9AF8, p0, p1); } // 0x3229C056C28C9AF8 0xF11FC458
	static void NETWORK_EARN_FROM_HOLDUPS(int amount) { invoke<Void>(0x8949AA5F9C64522A, amount); } // 0x8949AA5F9C64522A 0xE6B90E9C
	static void NETWORK_EARN_FROM_PROPERTY(int amount, Hash propertyName) { invoke<Void>(0x20804FB0C0C02C61, amount, propertyName); } // 0x20804FB0C0C02C61 0x9BE4F7E1
	static void _0xAC37AD7990AC61A0(Any p0, Any p1) { invoke<Void>(0xAC37AD7990AC61A0, p0, p1); } // 0xAC37AD7990AC61A0 0x866004A8
	static void _0x729EDA1109D292A1(int amount) { invoke<Void>(0x729EDA1109D292A1, amount); } // 0x729EDA1109D292A1 0xCC068380
	static void NETWORK_EARN_FROM_ROCKSTAR(int amount) { invoke<Void>(0x2E8D817266A6C873, amount); } // 0x2E8D817266A6C873 0x5A3733CC
	static void NETWORK_EARN_FROM_VEHICLE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7) { invoke<Void>(0x3CFC88A21ED2D0C2, p0, p1, p2, p3, p4, p5, p6, p7); } // 0x3CFC88A21ED2D0C2 0xF803589D
	static void _0xC339B3A7F3354507(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) { invoke<Void>(0xC339B3A7F3354507, p0, p1, p2, p3, p4, p5, p6, p7, p8); } // 0xC339B3A7F3354507 0x96B8BEE8
	static void _0x3CE63808E0E38FD7(int p0, char* p1, int p2) { invoke<Void>(0x3CE63808E0E38FD7, p0, p1, p2); } // 0x3CE63808E0E38FD7
	static void _0x55F7C756B6776120(int p0, char* p1, Any* p2) { invoke<Void>(0x55F7C756B6776120, p0, p1, p2); } // 0x55F7C756B6776120
	static void _0x4F6AA2DF436F324F(Any p0, Any* p1, Any* p2) { invoke<Void>(0x4F6AA2DF436F324F, p0, p1, p2); } // 0x4F6AA2DF436F324F
	static BOOL _HAS_ITEM_BEEN_UNLOCKED(Any p0, BOOL p1, BOOL p2, BOOL p3, Any p4) { return invoke<BOOL>(0xB78F8387015B354D, p0, p1, p2, p3, p4); } // 0xB78F8387015B354D 0x5AA379D9
	static BOOL _0x48F44D5AE42B1A0A(Any p0, BOOL p1, BOOL p2, BOOL p3, Any* p4, Any p5) { return invoke<BOOL>(0x48F44D5AE42B1A0A, p0, p1, p2, p3, p4, p5); } // 0x48F44D5AE42B1A0A
	static void NETWORK_BUY_ITEM(Ped player, Hash item, Any p2, Any p3, BOOL p4, char* item_name, Any p6, Any p7, Any p8, BOOL p9) { invoke<Void>(0x6199F1B5A4FA1F4D, player, item, p2, p3, p4, item_name, p6, p7, p8, p9); } // 0x6199F1B5A4FA1F4D 0xA07B6368
	static void NETWORK_SPENT_TAXI(int amount, BOOL p1, BOOL p2) { invoke<Void>(0x749458A4D8135D20, amount, p1, p2); } // 0x749458A4D8135D20 0x1F3DB3E3
	static void _0xB346609A8F4A3EBC(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xB346609A8F4A3EBC, p0, p1, p2); } // 0xB346609A8F4A3EBC 0xBE70849B
	static void _0x613C571E7C2CF816(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x613C571E7C2CF816, p0, p1, p2); } // 0x613C571E7C2CF816 0x451A2644
	static void _0xF1428308724B4830(Any p0, Any* p1, BOOL p2, BOOL p3) { invoke<Void>(0xF1428308724B4830, p0, p1, p2, p3); } // 0xF1428308724B4830 0x224A3488
	static void NETWORK_SPENT_BETTING(Any p0, Any p1, Any* p2, BOOL p3, BOOL p4) { invoke<Void>(0xFFED21E517994A7C, p0, p1, p2, p3, p4); } // 0xFFED21E517994A7C 0xF8A07513
	static void _0x1AA9F0ADB70AF946(Any p0, BOOL p1, Any p2, BOOL p3) { invoke<Void>(0x1AA9F0ADB70AF946, p0, p1, p2, p3); } // 0x1AA9F0ADB70AF946 0x8957038E
	static void NETWORK_BUY_HEALTHCARE(int cost, BOOL p1, BOOL p2) { invoke<Void>(0x17E7DA9581CB0120, cost, p1, p2); } // 0x17E7DA9581CB0120 0x832150E5
	static void NETWORK_BUY_AIRSTRIKE(int cost, BOOL p1, BOOL p2) { invoke<Void>(0x2E4F5336AA39BE2F, cost, p1, p2); } // 0x2E4F5336AA39BE2F 0x40470683
	static void NETWORK_BUY_HELI_STRIKE(int cost, BOOL p1, BOOL p2) { invoke<Void>(0x694D337B073CFAAD, cost, p1, p2); } // 0x694D337B073CFAAD 0x047547D4
	static void NETWORK_SPENT_AMMO_DROP(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x1E2E19DAC6EE20D7, p0, p1, p2); } // 0x1E2E19DAC6EE20D7 0x4B643076
	static void NETWORK_BUY_BOUNTY(int amount, Player victim, BOOL p2, BOOL p3) { invoke<Void>(0xFCBF9107C05E17CA, amount, victim, p2, p3); } // 0xFCBF9107C05E17CA 0xCB89CBE0
	static void NETWORK_BUY_PROPERTY(float propertyCost, Hash propertyName, BOOL p2, BOOL p3) { invoke<Void>(0x4F0FF2E5AB10CCC9, propertyCost, propertyName, p2, p3); } // 0x4F0FF2E5AB10CCC9 0x7D479AAB
	static void NETWORK_SPENT_HELI_PICKUP(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x0984C3A47203893E, p0, p1, p2); } // 0x0984C3A47203893E 0x27EEBCAB
	static void NETWORK_SPENT_BOAT_PICKUP(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xB53BF8C777444CD6, p0, p1, p2); } // 0xB53BF8C777444CD6 0xB241CABD
	static void NETWORK_SPENT_BULL_SHARK(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xFB748CEE8A82FEAA, p0, p1, p2); } // 0xFB748CEE8A82FEAA 0xDE7D398C
	static void NETWORK_SPENT_CASH_DROP(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xC6638F0671995782, p0, p1, p2); } // 0xC6638F0671995782 0x87BD1D11
	static void NETWORK_SPENT_HIRE_MUGGER(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xC98FC49B7C23BE7C, p0, p1, p2); } // 0xC98FC49B7C23BE7C 0xE792C4A5
	static void _0x992A163FF2B46AFF(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x992A163FF2B46AFF, p0, p1, p2); } // 0x992A163FF2B46AFF 0xE6AAA0D5
	static void NETWORK_SPENT_HIRE_MERCENARY(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x699D9389FF2C86EB, p0, p1, p2); } // 0x699D9389FF2C86EB 0x99CF02C4
	static void NETWORK_SPENT_BUY_WANTEDLEVEL(Any p0, Any* p1, BOOL p2, BOOL p3) { invoke<Void>(0x10637AB098B9869C, p0, p1, p2, p3); } // 0x10637AB098B9869C 0xE7CB4F95
	static void NETWORK_SPENT_BUY_OFFTHERADAR(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x3F3126B61284F2F3, p0, p1, p2); } // 0x3F3126B61284F2F3 0x20DDCF2F
	static void NETWORK_SPENT_BUY_REVEAL_PLAYERS(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x80A46D59298031DE, p0, p1, p2); } // 0x80A46D59298031DE 0x2F7836E2
	static void NETWORK_SPENT_CARWASH(Any p0, Any p1, Any p2, BOOL p3, BOOL p4) { invoke<Void>(0x800080EE48B458E9, p0, p1, p2, p3, p4); } // 0x800080EE48B458E9 0x8283E028
	static void NETWORK_SPENT_CINEMA(Any p0, Any p1, BOOL p2, BOOL p3) { invoke<Void>(0x2F855448F8C78E23, p0, p1, p2, p3); } // 0x2F855448F8C78E23 0x1100CAF5
	static void NETWORK_SPENT_TELESCOPE(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xA1D520B36EC5D54F, p0, p1, p2); } // 0xA1D520B36EC5D54F 0xAE7FF044
	static void NETWORK_SPENT_HOLDUPS(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xBFCACFFE419C5F7B, p0, p1, p2); } // 0xBFCACFFE419C5F7B 0x1B3803B1
	static void NETWORK_SPENT_BUY_PASSIVE_MODE(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x18BE3F808562BC01, p0, p1, p2); } // 0x18BE3F808562BC01 0x7E97C92C
	static void NETWORK_SPENT_PROSTITUTES(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x0972FD765178121D, p0, p1, p2); } // 0x0972FD765178121D 0x78436D07
	static void NETWORK_SPENT_ARREST_BAIL(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x132A731BDF56B06B, p0, p1, p2); } // 0x132A731BDF56B06B 0x5AEE2FC1
	static void NETWORK_SPENT_PAY_VEHICLE_INSURANCE_PREMIUM(Any p0, Hash VehicleModel, Any* p2, BOOL p3, BOOL p4) { invoke<Void>(0x6F56AD0A318DF458, p0, VehicleModel, p2, p3, p4); } // 0x6F56AD0A318DF458 0x4E665BB2
	static void NETWORK_SPENT_CALL_PLAYER(Any p0, Any* p1, BOOL p2, BOOL p3) { invoke<Void>(0x362A2566E7FDF171, p0, p1, p2, p3); } // 0x362A2566E7FDF171 0x1A89B5FC
	static void NETWORK_SPENT_BOUNTY(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x56251C79067663D6, p0, p1, p2); } // 0x56251C79067663D6 0x3401FC96
	static void _0xDDCA11FE7DE370BE(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0xDDCA11FE7DE370BE, p0, p1, p2); } // 0xDDCA11FE7DE370BE 0x54198922
	static Any PROCESS_CASH_GIFT(Any p0, Any p1, Any p2) { return invoke<Any>(0xB1E66A1A7C401EC2, p0, p1, p2); } // 0xB1E66A1A7C401EC2 0xC5D8B1E9
	static void _0xAEDAA6DF4DB11096(Any p0, Any p1, BOOL p2, BOOL p3) { invoke<Void>(0xAEDAA6DF4DB11096, p0, p1, p2, p3); } // 0xAEDAA6DF4DB11096 0x3D96A21C
	static void _0x1949A1B814449D0C(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x1949A1B814449D0C, p0, p1, p2); } // 0x1949A1B814449D0C 0x2E51C61C
	static void _0x1F8FF78C3CB93001(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x1F8FF78C3CB93001, p0, p1, p2); } // 0x1F8FF78C3CB93001 0xD57A5125
	static void _0x6A1F8CE84FCDAC9F(Any p0, BOOL p1, BOOL p2) { invoke<Void>(0x6A1F8CE84FCDAC9F, p0, p1, p2); } // 0x6A1F8CE84FCDAC9F
	static void _0x7A65D003E99E98E7(Any p0, Any p1, BOOL p2, BOOL p3) { invoke<Void>(0x7A65D003E99E98E7, p0, p1, p2, p3); } // 0x7A65D003E99E98E7 0xD9622D64
	static Any _0xF0EF254F629B648F() { return invoke<Any>(0xF0EF254F629B648F); } // 0xF0EF254F629B648F
	static int _GET_BANK_BALANCE() { return invoke<int>(0xFB77422520228B28); } // 0xFB77422520228B28 0x16184FB5
	static int _WALLET_BALANCE(int player) { return invoke<int>(0x06BA26F22D42BC26, player); } // 0x06BA26F22D42BC26 0x4F5B781C
	static Any _0x5139CCCCBB4EFFA8() { return invoke<Any>(0x5139CCCCBB4EFFA8); } // 0x5139CCCCBB4EFFA8 0xADF8F882
	static Any _0xC62B308C10DA15B8() { return invoke<Any>(0xC62B308C10DA15B8); } // 0xC62B308C10DA15B8
	static BOOL _0x6715E53618B3F291(Any p0, Any p1) { return invoke<BOOL>(0x6715E53618B3F291, p0, p1); } // 0x6715E53618B3F291
	static BOOL NETWORK_CAN_RECEIVE_PLAYER_CASH(Any p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0xF55130F2F7DBFC79, p0, p1, p2, p3); } // 0xF55130F2F7DBFC79 0x41F5F10E
	static Any _0x69C3C9EB327C54CE(Any p0) { return invoke<Any>(0x69C3C9EB327C54CE, p0); } // 0x69C3C9EB327C54CE 0x8B755993
	static BOOL _0x7D208610C8E5AC02(Any p0) { return invoke<BOOL>(0x7D208610C8E5AC02, p0); } // 0x7D208610C8E5AC02 0x8F266745
	static Any _0xA1A1182FE726CD04(Any p0) { return invoke<Any>(0xA1A1182FE726CD04, p0); } // 0xA1A1182FE726CD04 0x531E4892
	static Any _0x4F684F62571334BD(Any p0) { return invoke<Any>(0x4F684F62571334BD, p0); } // 0x4F684F62571334BD 0xB96C7ABE
}

namespace DLC1
{
	static int _0x54B1F2B09A7077C1(int character) { return invoke<int>(0x54B1F2B09A7077C1, character); } // 0x54B1F2B09A7077C1 0x71D0CF3E
	static BOOL _0xC465366D7F353CD7(int p0, int p1, int* outComponent) { return invoke<BOOL>(0xC465366D7F353CD7, p0, p1, outComponent); } // 0xC465366D7F353CD7 0x2E9D628C
	static void INIT_SHOP_PED_COMPONENT(int* outComponent) { invoke<Void>(0x69407F3B7F2A9AB2, outComponent); } // 0x69407F3B7F2A9AB2 0xB818C7FC
	static void INIT_SHOP_PED_PROP(int* outProp) { invoke<Void>(0xA61F5F01E6B7823E, outProp); } // 0xA61F5F01E6B7823E 0xF5659E50
	static int _0x79DC99D75FA1C69F(int p0, int p1, int p2, int p3) { return invoke<int>(0x79DC99D75FA1C69F, p0, p1, p2, p3); } // 0x79DC99D75FA1C69F 0xC937FF3D
	static int _GET_NUM_PROPS_FROM_OUTFIT(int character, int p1, int p2, BOOL p3, int p4, int componentId) { return invoke<int>(0xE423D4D72B60A747, character, p1, p2, p3, p4, componentId); } // 0xE423D4D72B60A747 0x594E862C
	static void GET_SHOP_PED_QUERY_COMPONENT(int componentId, int* outComponent) { invoke<Void>(0xE6F167D1AE3B7FD1, componentId, outComponent); } // 0xE6F167D1AE3B7FD1 0xC0718904
	static void GET_SHOP_PED_COMPONENT(Any p0, Any* p1) { invoke<Void>(0xCD8FF71467FFD88E, p0, p1); } // 0xCD8FF71467FFD88E 0xB39677C5
	static void GET_SHOP_PED_QUERY_PROP(Any p0, Any* p1) { invoke<Void>(0xF9D165820B09B032, p0, p1); } // 0xF9D165820B09B032 0x1D3C1466
	static void _0xFFB7240B94E55FBD(Any p0, Any* p1) { invoke<Void>(0xFFB7240B94E55FBD, p0, p1); } // 0xFFB7240B94E55FBD
	static Hash GET_HASH_NAME_FOR_COMPONENT(Entity entity, int componentId, int drawableVariant, int textureVariant) { return invoke<Hash>(0x872618C3ABCAA03F, entity, componentId, drawableVariant, textureVariant); } // 0x872618C3ABCAA03F 0xC8A4BF12
	static Hash GET_HASH_NAME_FOR_PROP(Entity entity, int componentId, int propIndex, int propTextureIndex) { return invoke<Hash>(0x8315E8D74F0CC85D, entity, componentId, propIndex, propTextureIndex); } // 0x8315E8D74F0CC85D 0x7D876DC0
	static int _0x1544CAEADDEBA808(Hash componentHash) { return invoke<int>(0x1544CAEADDEBA808, componentHash); } // 0x1544CAEADDEBA808 0x159751B4
	static void GET_VARIANT_COMPONENT(Hash componentHash, int componentId, Any* p2, Any* p3, Any* p4) { invoke<Void>(0x622C8EA55B7D9826, componentHash, componentId, p2, p3, p4); } // 0x622C8EA55B7D9826 0xE4FF7103
	static int _GET_NUM_FORCED_COMPONENTS(Hash componentHash) { return invoke<int>(0xFE444DCFB77504AE, componentHash); } // 0xFE444DCFB77504AE 0xCE70F183
	static Any _0x5CE3252CA4047743(Any p0) { return invoke<Any>(0x5CE3252CA4047743, p0); } // 0x5CE3252CA4047743
	static void GET_FORCED_COMPONENT(Hash componentHash, int componentId, Any* p2, Any* p3, Any* p4) { invoke<Void>(0x840A8F646CE04A99, componentHash, componentId, p2, p3, p4); } // 0x840A8F646CE04A99 0x382C70BE
	static void _0x88CB6946D26EEF5F(Any p0, Any p1, Any* p2, Any* p3, Any* p4) { invoke<Void>(0x88CB6946D26EEF5F, p0, p1, p2, p3, p4); } // 0x88CB6946D26EEF5F
	static BOOL _0x0B547E4E2D1A8F1F(Hash componentHash, Hash drawableSlotHash, BOOL p2) { return invoke<BOOL>(0x0B547E4E2D1A8F1F, componentHash, drawableSlotHash, p2); } // 0x0B547E4E2D1A8F1F 0x8E2C7FD5
	static int _0x7B9598A1DCBD186F(int character, BOOL p1) { return invoke<int>(0x7B9598A1DCBD186F, character, p1); } // 0x7B9598A1DCBD186F 0x1ECD23E7
	static void GET_SHOP_PED_QUERY_OUTFIT(Any p0, Any* outfit) { invoke<Void>(0xA56F6F017CB97DFE, p0, outfit); } // 0xA56F6F017CB97DFE 0x2F8013A1
	static void GET_SHOP_PED_OUTFIT(Any p0, Any* p1) { invoke<Void>(0xB615ADF659C5D565, p0, p1); } // 0xB615ADF659C5D565 0xCAFE9209
	static Any _0xAD50B0DC89F876D0(Any p0) { return invoke<Any>(0xAD50B0DC89F876D0, p0); } // 0xAD50B0DC89F876D0 0x2798F56F
	static BOOL _0x79388F76277D529B(Any p0, Any p1, Any* p2) { return invoke<BOOL>(0x79388F76277D529B, p0, p1, p2); } // 0x79388F76277D529B 0x6641A864
	static BOOL _GET_PROP_FROM_OUTFIT(Any outfit, int slot, Any* item) { return invoke<BOOL>(0xABF16728DFC48025, outfit, slot, item); } // 0xABF16728DFC48025 0x818534AC
	static int GET_NUM_DLC_VEHICLES() { return invoke<int>(0x9AEFEF0C873443F4); } // 0x9AEFEF0C873443F4 0x8EAF9CF6
	static Hash GET_DLC_VEHICLE_MODEL(int dlcVehicleIndex) { return invoke<Hash>(0xB11204693B65577E, dlcVehicleIndex); } // 0xB11204693B65577E 0xA2201E09
	static BOOL GET_DLC_VEHICLE_DATA(int dlcVehicleIndex, Any* outData) { return invoke<BOOL>(0xE8885AFFB348EA8C, dlcVehicleIndex, outData); } // 0xE8885AFFB348EA8C 0xCF428FA4
	static int GET_DLC_VEHICLE_FLAGS(int p0) { return invoke<int>(0x40AC431274E0A5DC, p0); } // 0x40AC431274E0A5DC 0xAB12738C
	static int GET_NUM_DLC_WEAPONS() { return invoke<int>(0xDD29471727F67A12); } // 0xDD29471727F67A12 0x2B757E6C
	static BOOL GET_DLC_WEAPON_DATA(int dlcWeaponIndex, Any* outData) { return invoke<BOOL>(0x7DF39E88C502C09C, dlcWeaponIndex, outData); } // 0x7DF39E88C502C09C 0xD88EC8EA
	static int GET_NUM_DLC_WEAPON_COMPONENTS(int dlcWeaponIndex) { return invoke<int>(0x7DCA7EA2B13F77EF, dlcWeaponIndex); } // 0x7DCA7EA2B13F77EF 0x476B23A9
	static BOOL GET_DLC_WEAPON_COMPONENT_DATA(Any p0, Any p1, Any* ComponentDataPtr) { return invoke<BOOL>(0x94C9039E2251B8A8, p0, p1, ComponentDataPtr); } // 0x94C9039E2251B8A8 0x4B83FCAF
	static BOOL _IS_DLC_DATA_EMPTY(int dlcData) { return invoke<BOOL>(0x5D46F50AE982AB28, dlcData); } // 0x5D46F50AE982AB28 0x06396058
	static BOOL _0xB1CDEB360808AB34(Any p0) { return invoke<BOOL>(0xB1CDEB360808AB34, p0); } // 0xB1CDEB360808AB34 0x35BCA844
	static Any _0x92DF07294F23DB91(Any p0) { return invoke<Any>(0x92DF07294F23DB91, p0); } // 0x92DF07294F23DB91 0x59352658
}

namespace DLC2
{
	static BOOL IS_DLC_PRESENT(Hash DlcHash) { return invoke<BOOL>(0x6948821CC8D52AC2, DlcHash); } // 0x6948821CC8D52AC2 0x1F321943
	static BOOL _0x7D8F97E65CD7C02F() { return invoke<BOOL>(0x7D8F97E65CD7C02F); } // 0x7D8F97E65CD7C02F 0x881B1FDB
	static Any _0x5501CD37A099F641() { return invoke<Any>(0x5501CD37A099F641); } // 0x5501CD37A099F641 0xC2169164
	static Any _0xE101BF5AF1957D69() { return invoke<Any>(0xE101BF5AF1957D69); } // 0xE101BF5AF1957D69 0xF79A97F5
	static Any _0xBC94C00B49BF463D() { return invoke<Any>(0xBC94C00B49BF463D); } // 0xBC94C00B49BF463D 0xF69B729C
	static BOOL GET_IS_LOADING_SCREEN_ACTIVE() { return invoke<BOOL>(0x3C8BCFA75814881C); } // 0x3C8BCFA75814881C 0x517B601B
	static BOOL _NULLIFY(Any* variable, Any unused) { return invoke<BOOL>(0xA52330638445D0CA, variable, unused); } // 0xA52330638445D0CA 0x6087C10C
	static void _LOAD_SP_DLC_MAPS() { invoke<Void>(0x9B76EF599B2ECF12); } // 0x9B76EF599B2ECF12
	static void _LOAD_MP_DLC_MAPS() { invoke<Void>(0x88BB318F1E2FAE1D); } // 0x88BB318F1E2FAE1D
}

namespace SYSTEM
{
	static void WAIT_OLD(int ms) { invoke<Void>(0x4EDE34FBADD967A6, ms); } // 0x4EDE34FBADD967A6 0x7715C03B
	static int START_NEW_SCRIPT(char* scriptName, int stackSize) { return invoke<int>(0xE81651AD79516E48, scriptName, stackSize); } // 0xE81651AD79516E48 0x3F166D0E
	static int START_NEW_SCRIPT_WITH_ARGS(char* scriptName, Any* args, int argCount, int stackSize) { return invoke<int>(0xB8BA7F44DF1575E1, scriptName, args, argCount, stackSize); } // 0xB8BA7F44DF1575E1 0x4A2100E4
	static int _START_NEW_STREAMED_SCRIPT(Hash scriptHash, int stackSize) { return invoke<int>(0xEB1C67C3A5333A92, scriptHash, stackSize); } // 0xEB1C67C3A5333A92 0x8D15BE5D
	static int _START_NEW_STREAMED_SCRIPT_WITH_ARGS(Hash scriptHash, Any* args, int argCount, int stackSize) { return invoke<int>(0xC4BB298BD441BE78, scriptHash, args, argCount, stackSize); } // 0xC4BB298BD441BE78 0xE38A3AD4
	static int TIMERA() { return invoke<int>(0x83666F9FB8FEBD4B); } // 0x83666F9FB8FEBD4B 0x45C8C188
	static int TIMERB() { return invoke<int>(0xC9D9444186B5A374); } // 0xC9D9444186B5A374 0x330A9C0C
	static void SETTIMERA(int value) { invoke<Void>(0xC1B1E9A034A63A62, value); } // 0xC1B1E9A034A63A62 0x35785333
	static void SETTIMERB(int value) { invoke<Void>(0x5AE11BC36633DE4E, value); } // 0x5AE11BC36633DE4E 0x27C1B7C6
	static float TIMESTEP() { return invoke<float>(0x0000000050597EE2); } // 0x0000000050597EE2 0x50597EE2
	static float SIN(float value) { return invoke<float>(0x0BADBFA3B172435F, value); } // 0x0BADBFA3B172435F 0xBF987F58
	static float COS(float value) { return invoke<float>(0xD0FFB162F40A139C, value); } // 0xD0FFB162F40A139C 0x00238FE9
	static float SQRT(float value) { return invoke<float>(0x71D93B57D07F9804, value); } // 0x71D93B57D07F9804 0x145C7701
	static float POW(float base, float exponent) { return invoke<float>(0xE3621CC40F31FE2E, base, exponent); } // 0xE3621CC40F31FE2E 0x85D134F8
	static float VMAG(float p0, float p1, float p2) { return invoke<float>(0x652D2EEEF1D3E62C, p0, p1, p2); } // 0x652D2EEEF1D3E62C 0x1FCF1ECD
	static float VMAG2(float p0, float p1, float p2) { return invoke<float>(0xA8CEACB4F35AE058, p0, p1, p2); } // 0xA8CEACB4F35AE058 0xE796E629
	static float VDIST(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<float>(0x2A488C176D52CCA5, x1, y1, z1, x2, y2, z2); } // 0x2A488C176D52CCA5 0x3C08ECB7
	static float VDIST2(float x1, float y1, float z1, float x2, float y2, float z2) { return invoke<float>(0xB7A628320EFF8E47, x1, y1, z1, x2, y2, z2); } // 0xB7A628320EFF8E47 0xC85DEF1F
	static int SHIFT_LEFT(int value, int bitShift) { return invoke<int>(0xEDD95A39E5544DE8, value, bitShift); } // 0xEDD95A39E5544DE8 0x314CC6CD
	static int SHIFT_RIGHT(int value, int bitShift) { return invoke<int>(0x97EF1E5BCE9DC075, value, bitShift); } // 0x97EF1E5BCE9DC075 0x352633CA
	static int FLOOR(float value) { return invoke<int>(0xF34EE736CF047844, value); } // 0xF34EE736CF047844 0x32E9BE04
	static int CEIL(float value) { return invoke<int>(0x11E019C8F43ACC8A, value); } // 0x11E019C8F43ACC8A 0xD536A1DF
	static int ROUND(float value) { return invoke<int>(0xF2DB717A73826179, value); } // 0xF2DB717A73826179 0x323B0E24
	static float TO_FLOAT(int value) { return invoke<float>(0xBBDA792448DB5A89, value); } // 0xBBDA792448DB5A89 0x67116627
}

namespace DECORATOR
{
	static BOOL DECOR_SET_TIME(Entity entity, char* propertyName, int value) { return invoke<BOOL>(0x75693D51F5BD4DD4, entity, propertyName, value); } // 0x75693D51F5BD4DD4 0xBBAEEF94
	static BOOL DECOR_SET_BOOL(Entity entity, char* propertyName, BOOL value) { return invoke<BOOL>(0x6717F72244C0D24C, entity, propertyName, value); } // 0x6717F72244C0D24C 0x8E101F5C
	static BOOL _DECOR_SET_FLOAT(Entity entity, char* propertyName, float value) { return invoke<BOOL>(0x192C4BB6EF3D0304, entity, propertyName, value); } // 0x192C4BB6EF3D0304
	static BOOL DECOR_SET_INT(Entity entity, char* propertyName, int value) { return invoke<BOOL>(0x25E9B908B35A0675, entity, propertyName, value); } // 0x25E9B908B35A0675 0xDB718B21
	static BOOL DECOR_GET_BOOL(Entity entity, char* propertyName) { return invoke<BOOL>(0x12D059B73664565A, entity, propertyName); } // 0x12D059B73664565A 0xDBCE51E0
	static float _DECOR_GET_FLOAT(Entity entity, char* propertyName) { return invoke<float>(0x9476CE7E46D8034C, entity, propertyName); } // 0x9476CE7E46D8034C
	static int DECOR_GET_INT(Entity entity, char* propertyName) { return invoke<int>(0x83CA0CEAC60F17F6, entity, propertyName); } // 0x83CA0CEAC60F17F6 0xDDDE59B5
	static BOOL DECOR_EXIST_ON(Entity entity, char* propertyName) { return invoke<BOOL>(0x44748DA5CF34DA5E, entity, propertyName); } // 0x44748DA5CF34DA5E 0x74EF9C40
	static BOOL DECOR_REMOVE(Entity entity, char* propertyName) { return invoke<BOOL>(0x82EDC5A6930ADD0E, entity, propertyName); } // 0x82EDC5A6930ADD0E 0xE0E2640B
	static void DECOR_REGISTER(char* propertyName, int type) { invoke<Void>(0x1A45C300A76EF1CB, propertyName, type); } // 0x1A45C300A76EF1CB 0x68BD42A9
	static BOOL DECOR_IS_REGISTERED_AS_TYPE(char* propertyName, int type) { return invoke<BOOL>(0x34D7B5822CF22910, propertyName, type); } // 0x34D7B5822CF22910 0x7CF0971D
	static void DECOR_REGISTER_LOCK() { invoke<Void>(0x65C0E8EA7E21D9B9); } // 0x65C0E8EA7E21D9B9 0x7F3F1C02
	static int _0x3BA665A5E80D675E() { return invoke<int>(0x3BA665A5E80D675E); } // 0x3BA665A5E80D675E
}

namespace SOCIALCLUB
{
	static Any _0xBF967BDEE9A8A3EA() { return invoke<Any>(0xBF967BDEE9A8A3EA); } // 0xBF967BDEE9A8A3EA 0x6BE5DF29
	static Hash _0x772DE1039154F04C(int p0) { return invoke<Hash>(0x772DE1039154F04C, p0); } // 0x772DE1039154F04C 0x5ECF955D
	static BOOL _0x0793D2E715DCC40C(Any p0) { return invoke<BOOL>(0x0793D2E715DCC40C, p0); } // 0x0793D2E715DCC40C 0xD1ED1D48
	static BOOL _0x5960DCE39A566AE7(Any p0) { return invoke<BOOL>(0x5960DCE39A566AE7, p0); } // 0x5960DCE39A566AE7 0x19EE0CCB
	static BOOL SC_INBOX_MESSAGE_GET_DATA_INT(Any p0, Any* p1, Any* p2) { return invoke<BOOL>(0x680138FA1DEA7A7E, p0, p1, p2); } // 0x680138FA1DEA7A7E 0x88068C7C
	static BOOL _SC_INBOX_MESSAGE_GET_DATA_BOOL(Any p0, char* p1) { return invoke<BOOL>(0xAB975BBB21AF5A2E, p0, p1); } // 0xAB975BBB21AF5A2E
	static BOOL SC_INBOX_MESSAGE_GET_DATA_STRING(Any p0, Any* p1, Any* p2) { return invoke<BOOL>(0x1D6D530B21399237, p0, p1, p2); } // 0x1D6D530B21399237 0x15607620
	static BOOL _0xAE104621FE06AC00(Any p0) { return invoke<BOOL>(0xAE104621FE06AC00, p0); } // 0xAE104621FE06AC00 0xEBE420A4
	static Any _0x305DE56A81D50501(Any p0) { return invoke<Any>(0x305DE56A81D50501, p0); } // 0x305DE56A81D50501 0x2C959AF9
	static void _0xBD7A65B46308AB69(int* p0) { invoke<Void>(0xBD7A65B46308AB69, p0); } // 0xBD7A65B46308AB69 0x0B9A3512
	static void _0x870DCCA29502424A(char* p0) { invoke<Void>(0x870DCCA29502424A, p0); } // 0x870DCCA29502424A 0x75324674
	static BOOL SC_INBOX_MESSAGE_GET_UGCDATA(Any p0, Any* p1) { return invoke<BOOL>(0x112E356ED3A2BE57, p0, p1); } // 0x112E356ED3A2BE57 0x88CA3BFC
	static BOOL _0xBD4F7EDB1DCF440F(char* p0) { return invoke<BOOL>(0xBD4F7EDB1DCF440F, p0); } // 0xBD4F7EDB1DCF440F 0x628F489B
	static BOOL _0xDC079E0610CE385F(Any p0, int* p1) { return invoke<BOOL>(0xDC079E0610CE385F, p0, p1); } // 0xDC079E0610CE385F 0xAB3346B5
	static void _0x66CBE8A8AB453757(Any p0, Any p1) { invoke<Void>(0x66CBE8A8AB453757, p0, p1); } // 0x66CBE8A8AB453757
	static Any _0xE787252FAF2F8A45() { return invoke<Any>(0xE787252FAF2F8A45); } // 0xE787252FAF2F8A45
	static BOOL _0x4C60175D9C44A6DF(int p0, Any* p1) { return invoke<BOOL>(0x4C60175D9C44A6DF, p0, p1); } // 0x4C60175D9C44A6DF
	static void _0x0AC674D349A4E7B8(Any* p0, Any p1) { invoke<Void>(0x0AC674D349A4E7B8, p0, p1); } // 0x0AC674D349A4E7B8
	static void SC_EMAIL_MESSAGE_PUSH_GAMER_TO_RECIP_LIST(Player* player) { invoke<Void>(0x36C92BEF6F18D687, player); } // 0x36C92BEF6F18D687 0x9A703A2B
	static void _0x1AF7876BBFE924CF() { invoke<Void>(0x1AF7876BBFE924CF); } // 0x1AF7876BBFE924CF 0xD094F11A
	static void _0x38627337DB78F0CA(char* p0) { invoke<Void>(0x38627337DB78F0CA, p0); } // 0x38627337DB78F0CA 0xAF3C081B
	static void _0x943C62732128CCE6(BOOL p0) { invoke<Void>(0x943C62732128CCE6, p0); } // 0x943C62732128CCE6 0x2FB9F53C
	static Any _0xCD313F8A9B5A37BD() { return invoke<Any>(0xCD313F8A9B5A37BD); } // 0xCD313F8A9B5A37BD 0x6C5738AB
	static Any _0x58467AB494F016D8() { return invoke<Any>(0x58467AB494F016D8); } // 0x58467AB494F016D8 0x468668F0
	static BOOL _0x06F5945069FFAD84(Any p0, Any p1) { return invoke<BOOL>(0x06F5945069FFAD84, p0, p1); } // 0x06F5945069FFAD84 0x90C74343
	static BOOL _0x904A287BABAD9263(Any p0, Any* p1) { return invoke<BOOL>(0x904A287BABAD9263, p0, p1); } // 0x904A287BABAD9263 0x3ACE6D6B
	static BOOL _0xB13ABCC930F7B5DC(Any p0, float p1) { return invoke<BOOL>(0xB13ABCC930F7B5DC, p0, p1); } // 0xB13ABCC930F7B5DC 0x579B4510
	static BOOL _0x9704BDB31ED1FC94(Any* p0) { return invoke<BOOL>(0x9704BDB31ED1FC94, p0); } // 0x9704BDB31ED1FC94 0xDF45B2A7
	static BOOL _0x659B6BDD1275003E(char* p0, Any* p1) { return invoke<BOOL>(0x659B6BDD1275003E, p0, p1); } // 0x659B6BDD1275003E 0xDF084A6B
	static BOOL _0x20F731E58C38D75F(Any p0) { return invoke<BOOL>(0x20F731E58C38D75F, p0); } // 0x20F731E58C38D75F 0xFFED3676
	static Any _0xD4C3848DF46DA552(Any p0) { return invoke<Any>(0xD4C3848DF46DA552, p0); } // 0xD4C3848DF46DA552 0xA796D7A7
	static Any _0x214DF5907D547CD9(Any p0) { return invoke<Any>(0x214DF5907D547CD9, p0); } // 0x214DF5907D547CD9 0x09497F31
	static int _0xFDC8410B17CBB5A8(Any p0) { return invoke<int>(0xFDC8410B17CBB5A8, p0); } // 0xFDC8410B17CBB5A8 0x4D8A6521
	static BOOL _0x6F41B87101AAB76E(char* p0, int* p1) { return invoke<BOOL>(0x6F41B87101AAB76E, p0, p1); } // 0x6F41B87101AAB76E 0x7AA36406
	static BOOL _0xAAF716B38981938B(Any p0) { return invoke<BOOL>(0xAAF716B38981938B, p0); } // 0xAAF716B38981938B 0xF379DCE4
	static Any _0x678F2A2326137C72(Any p0) { return invoke<Any>(0x678F2A2326137C72, p0); } // 0x678F2A2326137C72 0x65D84665
	static Any _0xCF10DD683F1A6FFF(Any p0) { return invoke<Any>(0xCF10DD683F1A6FFF, p0); } // 0xCF10DD683F1A6FFF
	static Any _0xDA7FE1C6B4684554(Any p0, Any p1) { return invoke<Any>(0xDA7FE1C6B4684554, p0, p1); } // 0xDA7FE1C6B4684554
	static Any _0x19B92A4F61FDE4B9(Any p0, Any p1) { return invoke<Any>(0x19B92A4F61FDE4B9, p0, p1); } // 0x19B92A4F61FDE4B9
	static BOOL _0x23C29D6FA4F0F837(Any* p0, Any* p1, Any* p2) { return invoke<BOOL>(0x23C29D6FA4F0F837, p0, p1, p2); } // 0x23C29D6FA4F0F837
	static BOOL _0xFA12EF8082FDF7DB(Any* p0, Any* p1, Any* p2) { return invoke<BOOL>(0xFA12EF8082FDF7DB, p0, p1, p2); } // 0xFA12EF8082FDF7DB
	static Any _0x0002F081C336C930(Any p0) { return invoke<Any>(0x0002F081C336C930, p0); } // 0x0002F081C336C930
	static Any _0xBDD56A96DC02111C(Any p0) { return invoke<Any>(0xBDD56A96DC02111C, p0); } // 0xBDD56A96DC02111C
	static BOOL _0xD1CA36ACCA44B969(Any* p0, int* p1) { return invoke<BOOL>(0xD1CA36ACCA44B969, p0, p1); } // 0xD1CA36ACCA44B969
	static Any _0x32D71195038F1CFD(Any p0) { return invoke<Any>(0x32D71195038F1CFD, p0); } // 0x32D71195038F1CFD
	static Any _0x3F61CBC9A4CA4A0D(Any p0) { return invoke<Any>(0x3F61CBC9A4CA4A0D, p0); } // 0x3F61CBC9A4CA4A0D
	static Any _0x56BEACC636957F8F() { return invoke<Any>(0x56BEACC636957F8F); } // 0x56BEACC636957F8F 0xC96456BA
	static Any _0x4BD948B9D1EE15A8(Any* p0) { return invoke<Any>(0x4BD948B9D1EE15A8, p0); } // 0x4BD948B9D1EE15A8 0x8E7AEEB7
	static BOOL _0xA7925C0D2796EB2E(int p0, char* p1, Any* p2) { return invoke<BOOL>(0xA7925C0D2796EB2E, p0, p1, p2); } // 0xA7925C0D2796EB2E 0xE778B2A7
	static BOOL _0x92F1DC7A9FB8B67E(int p0, char* p1, Any* p2) { return invoke<BOOL>(0x92F1DC7A9FB8B67E, p0, p1, p2); } // 0x92F1DC7A9FB8B67E 0xCE7D50A8
	static BOOL _0xEFAC808FC836D22D(Any p0, Any* p1) { return invoke<BOOL>(0xEFAC808FC836D22D, p0, p1); } // 0xEFAC808FC836D22D 0xD26CCA46
	static BOOL _0x306F3E0935874E8F(Any p0) { return invoke<BOOL>(0x306F3E0935874E8F, p0); } // 0x306F3E0935874E8F 0x24D84334
	static BOOL _0x97C7A1FF56A64345(Any p0, Any p1) { return invoke<BOOL>(0x97C7A1FF56A64345, p0, p1); } // 0x97C7A1FF56A64345 0x8A023024
	static Any _0x0D2D069AAADFC556() { return invoke<Any>(0x0D2D069AAADFC556); } // 0x0D2D069AAADFC556 0x1C65B038
	static BOOL _0x338F69E824C1ADB8() { return invoke<BOOL>(0x338F69E824C1ADB8); } // 0x338F69E824C1ADB8 0x4D4C37B3
	static BOOL _0x169064D7761B7D87(char* p0, int* p1) { return invoke<BOOL>(0x169064D7761B7D87, p0, p1); } // 0x169064D7761B7D87 0xAED95A6F
	static void _0x4C8BADE33B0F8900() { invoke<Void>(0x4C8BADE33B0F8900); } // 0x4C8BADE33B0F8900 0x486867E6
	static char* _SC_GET_NICKNAME() { return invoke<char*>(0xC99924EE31B87B5D); } // 0xC99924EE31B87B5D
	static BOOL _0x8566126394FCF8F8(int* p0) { return invoke<BOOL>(0x8566126394FCF8F8, p0); } // 0x8566126394FCF8F8
	static BOOL _0x6D91ACC14EC1A0A5(int p0) { return invoke<BOOL>(0x6D91ACC14EC1A0A5, p0); } // 0x6D91ACC14EC1A0A5
}

namespace UNK
{
	static int _0x740B927E847E9F6D() { return invoke<int>(0x740B927E847E9F6D); } // 0x740B927E847E9F6D 0x106C8317
	static BOOL _0x38BBE2A31080CC5E() { return invoke<BOOL>(0x38BBE2A31080CC5E); } // 0x38BBE2A31080CC5E 0xD87F3A9E
	static void _GET_BROADCAST_FINSHED_LOS_SOUND(BOOL p0) { invoke<Void>(0x37C3FB356334026A, p0); } // 0x37C3FB356334026A 0xC0B971EA
	static Any _0xD20E450F63392126() { return invoke<Any>(0xD20E450F63392126); } // 0xD20E450F63392126 0x94BCAC7C
	static void _0xD1480F1CBE528128(BOOL p0) { invoke<Void>(0xD1480F1CBE528128, p0); } // 0xD1480F1CBE528128 0x7D90EEE5
	static BOOL _IS_UI_LOADING_MULTIPLAYER() { return invoke<BOOL>(0xC29F87548D8DEF9E); } // 0xC29F87548D8DEF9E 0x734CFEDA
	static void _0x01F502D2DEA650FD(BOOL p0) { invoke<Void>(0x01F502D2DEA650FD, p0); } // 0x01F502D2DEA650FD 0x8C227332
	static void _0x4D55DD8D84A4BC1D(BOOL p0) { invoke<Void>(0x4D55DD8D84A4BC1D, p0); } // 0x4D55DD8D84A4BC1D 0x5C350D78
	static int _GET_UI_LANGUAGE_ID() { return invoke<int>(0xB8EB22F9350F13DC); } // 0xB8EB22F9350F13DC
	static int _GET_USER_LANGUAGE_ID() { return invoke<int>(0x5C40DBAFFFE19F43); } // 0x5C40DBAFFFE19F43
}

namespace UNK1
{
	static void _0x46081AAD7F4633BD(BOOL p0) { invoke<Void>(0x46081AAD7F4633BD, p0); } // 0x46081AAD7F4633BD
	static void _0x2EE4FDDB1E7664FB() { invoke<Void>(0x2EE4FDDB1E7664FB); } // 0x2EE4FDDB1E7664FB
	static void _0x95703CE234C12EA4() { invoke<Void>(0x95703CE234C12EA4); } // 0x95703CE234C12EA4
	static void _0x2DE9FDD822EE641B(float p0, float p1, BOOL p2) { invoke<Void>(0x2DE9FDD822EE641B, p0, p1, p2); } // 0x2DE9FDD822EE641B
	static void _0x31683E0D6DBB707E(char* missionNameLabel, Any p1) { invoke<Void>(0x31683E0D6DBB707E, missionNameLabel, p1); } // 0x31683E0D6DBB707E
	static void _0xF6EFB598FD123B39() { invoke<Void>(0xF6EFB598FD123B39); } // 0xF6EFB598FD123B39
	static void _0x4FA8AEB213D884E7() { invoke<Void>(0x4FA8AEB213D884E7); } // 0x4FA8AEB213D884E7
	static void _0xD7280B704D00444C() { invoke<Void>(0xD7280B704D00444C); } // 0xD7280B704D00444C
	static void _0x419A343900CD043F(Any p0, Any p1, Any p2) { invoke<Void>(0x419A343900CD043F, p0, p1, p2); } // 0x419A343900CD043F
	static void _START_RECORDING(int mode) { invoke<Void>(0x17D1CFC6D788CE64, mode); } // 0x17D1CFC6D788CE64
	static void _STOP_RECORDING_AND_SAVE_CLIP() { invoke<Void>(0x319B2408D3EC19AC); } // 0x319B2408D3EC19AC
	static void _STOP_RECORDING_AND_DISCARD_CLIP() { invoke<Void>(0x725CDCF22D80AF27); } // 0x725CDCF22D80AF27
	static BOOL _0x201D32254A226171() { return invoke<BOOL>(0x201D32254A226171); } // 0x201D32254A226171
	static BOOL _IS_RECORDING() { return invoke<BOOL>(0xC81784511829F091); } // 0xC81784511829F091
	static Any _0xF819501453FBCA67() { return invoke<Any>(0xF819501453FBCA67); } // 0xF819501453FBCA67
	static Any _0x739C34C9F5FE7772() { return invoke<Any>(0x739C34C9F5FE7772); } // 0x739C34C9F5FE7772
	static BOOL _0x24FB412D02D3AB57(BOOL p0) { return invoke<BOOL>(0x24FB412D02D3AB57, p0); } // 0x24FB412D02D3AB57
}

namespace UNK2
{
	static void _0x1E143F55CABD9E2B(Any p0, Any p1) { invoke<Void>(0x1E143F55CABD9E2B, p0, p1); } // 0x1E143F55CABD9E2B
	static BOOL _IS_INTERIOR_RENDERING_DISABLED() { return invoke<BOOL>(0xC190A6722E8665F6); } // 0xC190A6722E8665F6
	static void _0x2BCC9FBF69CE810E() { invoke<Void>(0x2BCC9FBF69CE810E); } // 0x2BCC9FBF69CE810E
	static void _0x159D3B4B17CB5376(BOOL p0) { invoke<Void>(0x159D3B4B17CB5376, p0); } // 0x159D3B4B17CB5376
	static void _0x804EDD782FCB2F15() { invoke<Void>(0x804EDD782FCB2F15); } // 0x804EDD782FCB2F15
	static void _0x6F637F791E1EC830() { invoke<Void>(0x6F637F791E1EC830); } // 0x6F637F791E1EC830
}

namespace UNK3
{
	static int _NETWORK_SHOP_GET_PRICE(Hash hash, Hash hash2, BOOL p2) { return invoke<int>(0xCBDF10F1223CF5BB, hash, hash2, p2); } // 0xCBDF10F1223CF5BB
	static Any _0x46FAD7ACB83BB140() { return invoke<Any>(0x46FAD7ACB83BB140); } // 0x46FAD7ACB83BB140
	static Any _0x05C084C84AF972C6() { return invoke<Any>(0x05C084C84AF972C6); } // 0x05C084C84AF972C6
	static Any _0x795AA9F7D6640A22() { return invoke<Any>(0x795AA9F7D6640A22); } // 0x795AA9F7D6640A22
	static Any _0x027F84CA151FBB8E() { return invoke<Any>(0x027F84CA151FBB8E); } // 0x027F84CA151FBB8E
	static BOOL _0xB57988FA790ABC83(Any* p0) { return invoke<BOOL>(0xB57988FA790ABC83, p0); } // 0xB57988FA790ABC83
	static Any _0xE8551F99C74EDFB4() { return invoke<Any>(0xE8551F99C74EDFB4); } // 0xE8551F99C74EDFB4
	static BOOL _0xF37ED0EA4F9AB950(Any* p0) { return invoke<BOOL>(0xF37ED0EA4F9AB950, p0); } // 0xF37ED0EA4F9AB950
	static BOOL _NETWORK_SHOP_START_SESSION(Any p0) { return invoke<BOOL>(0xC23A35199ACDA36C, p0); } // 0xC23A35199ACDA36C
	static Any _0xBD11C73C5005DED2() { return invoke<Any>(0xBD11C73C5005DED2); } // 0xBD11C73C5005DED2
	static BOOL _0xD692741D46843CA0(Any* p0) { return invoke<BOOL>(0xD692741D46843CA0, p0); } // 0xD692741D46843CA0
	static BOOL _0x6C942D65B2703BE3(Any* p0) { return invoke<BOOL>(0x6C942D65B2703BE3, p0); } // 0x6C942D65B2703BE3
	static BOOL _0xAE2B681D784C7E64(Any p0) { return invoke<BOOL>(0xAE2B681D784C7E64, p0); } // 0xAE2B681D784C7E64
	static BOOL _0x3B40E2FA46EFB288(Any p0) { return invoke<BOOL>(0x3B40E2FA46EFB288, p0); } // 0x3B40E2FA46EFB288
	static BOOL _NETWORK_SHOP_SESSION_APPLY_RECEIVED_DATA(Any p0) { return invoke<BOOL>(0x883BDBB64F400A5C, p0); } // 0x883BDBB64F400A5C
	static Any _0xB4EE84164EB16A6B() { return invoke<Any>(0xB4EE84164EB16A6B); } // 0xB4EE84164EB16A6B
	static BOOL _0xD0937CCE0DA3780C(BOOL p0, BOOL p1) { return invoke<BOOL>(0xD0937CCE0DA3780C, p0, p1); } // 0xD0937CCE0DA3780C
	static BOOL _0x5E5FAFB02AD6B99F(Any* p0, Any* p1) { return invoke<BOOL>(0x5E5FAFB02AD6B99F, p0, p1); } // 0x5E5FAFB02AD6B99F
	static BOOL _NETWORK_SHOP_BASKET_START(Any* p0, Any p1, Any p2, Any p3) { return invoke<BOOL>(0x444D632DAA38A3DE, p0, p1, p2, p3); } // 0x444D632DAA38A3DE
	static Any _NETWORK_SHOP_BASKET_END() { return invoke<Any>(0x5953D0610E433FF7); } // 0x5953D0610E433FF7
	static Any _NETWORK_SHOP_BASKET_ADD_ITEM(Player p0, Object p1) { return invoke<Any>(0x07FBBA7EF527DAC7, p0, p1); } // 0x07FBBA7EF527DAC7
	static Any _NETWORK_SHOP_BASKET_IS_FULL() { return invoke<Any>(0x361A95A7D257C87D); } // 0x361A95A7D257C87D
	static BOOL _NETWORK_SHOP_BASKET_APPLY_SERVER_DATA(Any p0, Any* p1) { return invoke<BOOL>(0xB342BA10FDF934AE, p0, p1); } // 0xB342BA10FDF934AE
	static BOOL _NETWORK_SHOP_CHECKOUT_START(Any p0) { return invoke<BOOL>(0x0F0045367541BC90, p0); } // 0x0F0045367541BC90
	static BOOL _NETWORK_SHOP_BEGIN_SERVICE(int* p0, Any p1, Any p2, Any p3, Any p4, Any p5) { return invoke<BOOL>(0x1EB4A371BFB0E524, p0, p1, p2, p3, p4, p5); } // 0x1EB4A371BFB0E524
	static BOOL _NETWORK_SHOP_END_SERVICE(Any p0) { return invoke<BOOL>(0x2A618463FE332188, p0); } // 0x2A618463FE332188
	static BOOL _0x6912075BB0677AAC(Any p0, BOOL p1, Any p2) { return invoke<BOOL>(0x6912075BB0677AAC, p0, p1, p2); } // 0x6912075BB0677AAC
	static Any _0x952FF85AFF584759() { return invoke<Any>(0x952FF85AFF584759); } // 0x952FF85AFF584759
	static Any _NETWORK_SHOP_DELETE_SET_TELEMETRY_NONCE_SEED() { return invoke<Any>(0x05E1935B276EE48F); } // 0x05E1935B276EE48F
	static BOOL _NETWORK_TRANSFER_BANK_TO_WALLET(int charStatInt, int amount) { return invoke<BOOL>(0xF311EB954FFCB963, charStatInt, amount); } // 0xF311EB954FFCB963
	static BOOL _NETWORK_TRANSFER_WALLET_TO_BANK(int charStatInt, int amount) { return invoke<BOOL>(0x36C196466CF34D18, charStatInt, amount); } // 0x36C196466CF34D18
	static Any _0x226C93ED6675DA1B() { return invoke<Any>(0x226C93ED6675DA1B); } // 0x226C93ED6675DA1B
	static Any _0x5FDF1CFC129767E3() { return invoke<Any>(0x5FDF1CFC129767E3); } // 0x5FDF1CFC129767E3
	static Any _NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED() { return invoke<Any>(0x0D8A37A2FB3CB31A); } // 0x0D8A37A2FB3CB31A
	static BOOL _NETWORK_SHOP_SET_TELEMETRY_NONCE_SEED(Any p0) { return invoke<BOOL>(0x3C40768B37383BE6, p0); } // 0x3C40768B37383BE6
	static char* _GET_ONLINE_VERSION() { return invoke<char*>(0xA7EBBDAD19E94E58); } // 0xA7EBBDAD19E94E58
}
