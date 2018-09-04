#pragma once


	extern int selectedplayer;

	void teleportto();

	extern bool pedcashbool[MAX_PLAYERS];
	void pedcash(Player target);

	void bagcash(Player target);

	extern bool displaytalkerbool;
	void displaytalker();

	void giveweapons();

	extern bool allesplinebool;
	extern bool esplinesbool[MAX_PLAYERS];
	void espline(Player target);

	extern bool allespboxbool;
	extern bool espboxbool[MAX_PLAYERS];
	void espbox(Player target);

	void instacrash(Player target);

	extern bool offradarbool;
	void offradar();

	extern bool rploopbool;
	void rploop();

	void teleporttome(Player player);

	void attach(Player player);
	void detach();

	extern bool espnameallbool;
	extern bool espnamebool[MAX_PLAYERS];
	void espname(Player target);

	void ramWithVeh(Player target);

	void teleportinveh(Player player);

	void teleportall(Player target);

	void shakecam(Player target);

	void removeweapons(Player target);

	void kickfromveh(Player player);
	void kickallfromveh();

	void explode(Player target);

	BOOL isOffRadar(Player player);

	extern bool revealAll;
	void removeOffRadar(Player player);

	extern bool freezebool[MAX_PLAYERS];
	void freeze(Player target);

	void killall();