#pragma once
void update_features();

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


