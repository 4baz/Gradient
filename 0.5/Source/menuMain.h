#pragma once
#include "File.h"

#ifndef MENU_MAIN_H
#define MENU_MAIN_H




void Loops();
//Declare submenus
namespace sub {

	void MainMenu();
	void Submenu1();
	void Settings();
	void scrollertest();
	void header();
	void options();
	void LSCustoms();
	void online();
	void recovery();
	void statEditor();
	void playerList();
	void PlayerIndex();
	void player();
	void vehicle();
	void vehicleSpawner();
	// recovery
	void onlinerecovery();
	void offlinerecovery();
	void setrp();
	//
	void teleport();
	void weapon();
	void world();
	void misc();
	void lobby();
	void PlayerMenu();
	void attackers();
	void credits();
	void wanted_editor();
	void wheels_list();
	void ptfx();
//	void object_attatcher_thing();
	void ONLINE_ATTACHMENT_SEL_PLAYER();
	void CRASH_OBJECTS();
	void prop_gun();

}

#endif