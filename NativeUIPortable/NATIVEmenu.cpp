#include "Common.hpp"
#include "menu.h"
#include "base.h"
#include "Natives.hpp"

//self options


bool p_god = false;
bool p_invis = false;
bool p_neverwanted = false;
bool p_mradio = false;
using namespace Big;
namespace sub{
	void sub::settings()
	{
		AddTitle("SETTINGS");
		AddSubmenu("Header", SUB::HEADER, "Change the header.");
		AddSubmenu("Options", SUB::OPTIONS, "Change the options.");
		AddToggle("Gradients", &gradients, "Once toggled, cool fades will appear.");
		AddOption("Unload menu", [] {

		Big::g_Running = false;

			}, "");


	}
	void sub::header()
	{
		AddTitle("HEADER");
		AddInt("Red", &bannerRect.R, 0, 255, 1, "Adjust the ~r~red~s~ channel.");
		AddInt("Green", &bannerRect.G, 0, 255, 1, "Adjust the ~g~green~s~ channel.");
		AddInt("Blue", &bannerRect.B, 0, 255, 1, "Adjust the ~b~blue~s~ channel.");
	}
	void sub::options()
	{
		AddTitle("OPTIONS");
		AddInt("Highlight red", &highlightRed, 0, 255, 1, "Adjust the ~r~red~s~ channel.");
		AddInt("Highlight green", &highlightGreen, 0, 255, 1, "Adjust the ~g~green~s~ channel.");
		AddInt("Hightlight blue", &highlightBlue, 0, 255, 1, "Adjust the ~b~blue~s~ channel.");
		AddInt("Options red", &optionsRed, 0, 255, 1, "Adjust the ~r~red~s~ channel.");
		AddInt("Options green", &optionsGreen, 0, 255, 1, "Adjust the ~g~green~s~ channel.");
		AddInt("Options blue", &optionsBlue, 0, 255, 1, "Adjust the ~b~blue~s~ channel.");
	}
	void sub::credits()
	{
		AddTitle("Credits");
		AddOption("4baz - dev", [] {}, "");
		AddOption("OPVL - making ui, 2017", [] {}, "");
		AddOption("MAFINS", [] {}, "");
		AddOption("INFAMOUS DEV TEAM", [] {}, "");
		AddOption("anyone that helped with:", [] {}, "");
		AddOption("gradient menu 2016-2018", [] {}, "");

	}




	void sub::MainMenu()
	{
		DisplayHelpTextThisFrame("Skid 69");
		AddTitle("Main Menu");
		AddSubmenu("Player Options", SUB::PLAYER, "");
		AddSubmenu("Weapon Options", SUB::WEAPONS, "");
		AddSubmenu("Vehicle Options", SUB::VEHICLE, "");
		AddSubmenu("Teleport Locations", SUB::TELEPORTS, "");
		AddSubmenu("Online Options", SUB::ONLINE_OPTIONS, "");
		AddSubmenu("Settings", SUB::SETTINGS, "");
		AddSubmenu("Credits", SUB::CREDITS, "");
		//	AddOption(">when crispycunt cant crack ur menu", "");

	}


	void sub::player()
	{
		AddTitle("Player Options");
		//AddSubmenu("Self Particle FX", SUB::PTFX, "");
		//AddSubmenu("Self Animations", SUB::ANIMATIONS, "");
		AddToggle("God Mode", &p_god, "god innit");
		AddToggle("Invisible", &p_invis, "invisible");
		AddToggle("Mobile Radio",&p_mradio,"");
		AddOption("-----[WANTED OPTIONS]-----", "");
		AddToggle("Never Wanted",&p_neverwanted,"");

		

		AddOption("-----[OTHER]-----","");
		AddOption("Max Health", [] {ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()),0);}, "");
		AddOption("Max Armour", [] {PED::SET_PED_ARMOUR(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID()));},"");
		AddOption("Clean Player Ped", [] {	PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID()); /**/	PED::RESET_PED_VISIBLE_DAMAGE(PLAYER::PLAYER_PED_ID()); }, "");
		AddOption("Reset Player Ped", [] {PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());}, "");
		AddOption("Kill yourself", [] {ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0,0); }, "");

	}
	void sub::online_options()
	{
		AddTitle("Online Options");
		AddSubmenu("Player List", SUB::PLAYERLIST, "");
		AddSubmenu("Lobby Options", SUB::LOBBY, "");
		AddSubmenu("Recovery Options", SUB::RECOVERY, "");
	}

	void sub::playerList() {
		AddTitle("Player Index");
		for (int i = 0; i < 32; i++) {
			const char* playerName = PLAYER::GET_PLAYER_NAME(i);
			if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i))
			{
				AddPlayer(playerName, i, "");
			}
		}
	}
	void sub::selplayer()
	{

		if (strcmp(selPlayerName, "**Invalid**") == 0);
		AddTitle(selPlayerName);

	//	AddSubmenu("Attach objects", SUB::OBJECTS, "");

		AddOption("Teleport to player", [] {Entity handle;
		Big::Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selPlayer), false);
		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false); }, "");

		//AddOption("Explode Player", [] {explodePed(selPlayer); }, "");

	}

	void sub::lobby()
	{
		AddTitle("Lobby Options");
	//	AddToggle("Lobby ESP", &lobbyESP, "");
		//AddToggle("Fuck Camera", &lobbyFuckCam, "");
	//	AddOption("Explode all", [] {for (int i = 0; i < 32; i++) { explodePed(i); }}, "");
	}



}