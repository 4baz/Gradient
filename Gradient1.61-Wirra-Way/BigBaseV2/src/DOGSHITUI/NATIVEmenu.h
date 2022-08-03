#pragma once

extern bool p_god;
extern bool p_invis;
extern bool p_neverwanted;
extern bool p_mradio;
extern bool p_offradar;
extern bool t_test_money;
extern 	int weaponammotype;
extern bool p_fuckradio;
extern bool v_proofs;



//online options
extern bool enable_esp_rgbmenu;




extern bool dev_penis;
extern bool enable_cursor;
extern int penisposx;
extern int penisposy;


//values for player info drawing and text using imgui
extern int pinfox;
extern int pinfoy;
extern int pinfosizex;
extern int pinfosizey;


extern bool dev_imguiimage;
extern bool toggleplayerinfo;

//vehicle



namespace sub {

	void MainMenu();
	void settings();
	void header();
	void options();
	void credits();
	void devoptions();
	void player();
	void weapons();
	void teleport();
	//void ptfx();
//	void animations();
	
	void playerList();
	void selplayer();
	void online_options();
	void lobby();
	void recovery();
	void ESP_SETTINGS();
	void PROTECTIONS();

	void vehicle();
	void vehspawner();
	void VEH_CAYOPERICHO();
	void VEH_SummerUpdate();
	void VEH_CasinoHeist();
	void VEH_CasinoUpdate();
	void VEH_ArenaWar();
	//
	void VEH_Vans();
	void VEH_Utility();
	void VEH_TRAINS();
	void VEH_trailers();
	void VEH_Super();
	void VEH_SportsClassic();
	void VEH_SPORTS();
	//
	void VEH_Boats();
	void VEH_Commercials();
	void	VEH_compacts();
	void VEH_Coupes();
	void VEH_BIKES();
	void VEH_Emergency();
	void VEH_Helicopters();
	void VEH_industraial();
	void VEH_Military();
	void VEH_MOTOCYCLE();
	void VEH_Muscle();
	void VEH_Offroad();
	void VEH_Planes();
	void VEH_Suvs();
	void VEH_Sedans();
	void VEH_Service();
	void VEH_CRIMINALENTPRISE();


	void lscustoms();
	//void attach_objects();
//	void recovery();
//	void set_rank();
//	void veh_doomsday();
};