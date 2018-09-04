#pragma once

extern rgba PrimarySpawnRGBVeh;
extern rgba SecondarySpawnRGBVeh;

namespace VehicleOptions
{
	extern bool godmodebool;
	void godmode();

	void fix();

	extern bool bulletprooftiresbool;
	void bulletprooftires();

	extern bool speedobool;
	void speedo();

	extern bool rainbowbool;
	void rainbow();

	extern bool vehiclegravitybool;
	void vehiclegravity();

	void maxvehicle();

	extern bool randommodsbool;
	void randommods();

	extern float accelerationfloat;
	extern float brakeforcefloat;
	extern float tractionfloat;
	extern float deformfloat;
	extern float upshiftfloat;
	extern float suspensionfloat;
	//	void updatePhysics();
	void acceleration();
	void brakeforce();
	void traction();
	void deform();
	void upshift();
	void suspension();

	extern bool spawnincar;
	extern bool spawnmaxed;
	void Spawn(std::string vehicle);

	void opendoors();
	void closedoors();

	void flip();

	extern bool seatbeltbool;
	void seatbelt();

	extern bool enginealwaysonbool;
	void enginealwayson();

	void changemod(int type, int index);

	extern bool hornboostbool;
	void hornboost();

	extern bool allplayerhornboostbool;
	void allplayerhornboost();

	extern bool allplayershornbool;
	void allplayershorn();

	extern bool fuckedhandling[MAX_PLAYERS];
	void fuckhandling(Player player);

	extern bool vehiclefixloopbool;
	void vehiclefixloop();

	void save(char* name);
}

//std::vector<std::string> listFiles(LPCSTR directory);