/*
THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
(C) Alexander Blade 2017
*/

#pragma once

namespace sub {

	void MainMenu();
	void settings();
	void header();
	void options();
	void credits();
	void player();
	void weapons();
	void teleports();
	void ptfx();
	void animations();
	void playerList();
	void selplayer();
	void vehicle();
	void vehspawner();
	void online_options();
	void attach_objects();
	void lobby();
	void recovery();
	void set_rank();
	void veh_doomsday();
};
class Script
{
public:
	static bool isInit();
	static void onTick();
}; extern uint RequestedModel;
enum RequestState
{
	loaded,
	requesting
};
extern RequestState model_state;
extern void(*modelFunction)();
void ScriptMain();
void Features();