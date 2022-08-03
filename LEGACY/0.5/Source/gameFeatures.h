#pragma once

#ifndef GAME_FEATURES_H
#define GAME_FEATURES_H

#include <string>

namespace game {
	void ptfx(char* call1, char* call2, char* name);
	void notifyBottom(std::string str);
	void notifyMap(std::string msg, BOOL blink);
	void notifyClan(std::string msg);
	void notifyError(std::string errorType);
	Ped GET_PLAYER_PED(Player player);
	float calcSpeed(bool mphOut, Vehicle veh);
	double calcAverageTick();

	//Vector Shit
	double DegreeToRadian(double n);
	float Get3DDistance(Vector3 a, Vector3 b);
	Vector3 RotationToDirection(Vector3 rot);
	Vector3 multiplyVector(Vector3 vector, float inc);
	Vector3 addVector(Vector3 vector, Vector3 vector2);
	RaycastResult Raycast(Vector3 source, Vector3 endCoords, IntersectOptions inter, Entity entityToignore);
	void offsetFromEnt(int entity, float X, float Y, float Z, float * Out);
	void DrawSprite(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
}

namespace vehicle {
	void setPerf(int engine, int brakes, int transmission, int suspension, bool turbo);
	void speedBoost();
	void repair(Vehicle vehicle);
	void paintRandom(Vehicle vehicle, BOOL primary, BOOL secondary, BOOL neon, BOOL wheels, BOOL tyresmoke);
	void upgradeBase(Vehicle vehicle, int *engine, int *brakes, int *transmission, int *suspension, int *armour);
	void upgradeMax(Vehicle vehicle);
	void upgradeStock(Vehicle vehicle);
	void deletePedVeh(Ped p);
	void explodeToggle(Vehicle vehicle, BOOL kaboom);
	void bypassOnlineKick(Vehicle vehicle);
	Vehicle spawn(char* toSpawn, Ped playerPed);
	Vehicle spawn(Hash model, Ped playerPed, Vector3 playerPos);
	Vehicle spawn(Hash toSpawn, Ped playerPed);
	Vehicle clone(Player toClone);
	void vehRandom();
	void removeOwnership(Vehicle vehicle);
	void openDoors(Vehicle vehicle);
	void closeDoors(Vehicle vehicle);
	void lockDoors(Vehicle vehicle);
	void setPlate(Vehicle vehicle);
	void manualSelect();
	void changeSeat(Vehicle vehicle, Ped playerPed);
	void disableSiren(Vehicle vehicle);
	void driveWaypoint();
	void breakDoors(bool deleteDoors, Player player);
	void setIndicators(Vehicle vehicle, bool left, bool both);
	void unlockBias(Ped p, float bias);
	void removeTopSpeed(Vehicle vehicle, BOOL &toggle);
	void loop_vehAirRide(Vehicle lastVeh);
	void loop_driveOnWater();
	void loop_ejectorSeat();
	void loop_chr0m3Speedo(bool engineState, bool dayNite, bool wheelState, int speedoPos);
}

namespace player {

	void invincibility(Entity e, bool *toggle);
	void invisibility(Entity e, bool * toggle);
	void kickVeh(Player player);
	void crashClone(Player player);
	void ragdoll(Ped ped, Player ID, Entity entity);
	void sendText(Player p, std::string msg);
	//void teleport2player(Ped destinationPed, Player selectedPlayer);
	void ragdollToggle(Player player); // keyup0
	void loopRagdoll();
	void ragdollSwitch();
	void teleportToPlayer(Player destination);
	void noRagdoll(BOOL toggle);
	void AddCash(); //SP ONLY
	void wantedUp(Player player);
	void wantedDown(Player player);
	void replenish(Ped playerPed);
	void removeAttached(Ped ped);
	void forward(Player player);
	void removeAttachd();
	void resetSkin();
	void JDM_mode();
	void skipCutscene1();
	void skipCutscene2();
	void skipCutscene3();
	void playAnimation(Ped p, char* anim, char* animID);
	void stopAnim(Ped who);
	void networkDance(Ped who);
	void netTeleport(Ped who, int destination);
	void TeleportCoords(Ped who, float x, float y, float z);
}

namespace misc {
	float GET_STAT(char *stat);
	void allCheevos();
	void moveMe(float x, float y, float z);
	void sample_createEscort(char *drivername, char *vehiclename);
	void opal_mode(int vehicle);
	bool CompareMemory(const uint8_t* pData, const uint8_t* bMask, const char* sMask);
	intptr_t FindPattern(const char* bMask, const char* sMask);
	void EnableTracks(bool tracksVehicle, bool tracksPeds, bool deepTracksVehicle, bool deepTracksPed );
	void EnableSnow(bool bEnable);
	void nyankton();
	void lfactFire();
	void lfactduringDoor();
	void Yacht1();
	void dhosp();
	void ufo1();
	void ufo2();
	void Mmorg();
	void cship();
	void cshipSunk();
	void hcarrier();
	void cbell();
	void airfield();
	void destFarm();
	void intFarm();
	void facelobby();
	void simeon();
	void udBigVault();
	void udShutters();
	void jewelStore();
	void showStreetname();
	Object spawnObject(char* name, Vector3 pos);
	void DLCCarsOn();
	void DLCCarsOff();
	void UnlimitedRadar();
	void UnlimitedRadarOff();
	void OffRadar(bool toggle);
	void changeTime(int amount);
	void mobile_radio();
	void loop_rainbowMenu(RGBA *banner, RGBA *scroller, RGBA *other);
	void hide_hud();
}

namespace world {
	void time_sync();
}

namespace weapon {
	void giveguns();
	void ForceWeapAddons(Ped ped, Hash weaponHash, bool bSilencer);
	void upgradeguns();
	void replenishguns();
	void addAll(Ped ped);
	void removeAll(Ped ped);
	void loop_infiniteAmmo(Ped playerPed);
	void superDamage(int playerReference, bool toggle);
	void useTheForcePED(Ped playerObj, Ped eObj);
	void useTheForceVEH(Ped playerObj, Vehicle eObj);
	void DeletePEDArray();
	void DeleteVEHArray();
	void checkForStuff();
	void shootItem(char* name); 
}

namespace recovery {
	void sixhundeestealth();
	int customVal(int max, int min, std::string setMsg, std::string closeMsg);
	void netcash(bool stealthBank, int value);
	void netcashCustom();
	void testnetcash();
	void bankTransfer(bool toBank);
	void MoneyDrop(Player p, int amount);
	void setRank();
	void setRP(char *slot);
	void bypassSellTimer();
	void clearBadSport();
	void RemoveBadSport();
	void enableRoosevelt();
	void clearReports();
	void unlockHeistVehicles();
	void maxStats();
	void unlockTattoos();
	void unlimitedSnacks();
	void unlimitedArmour();
	void unlimitedFireworks();
	void unlockCamoParachutes();
	void unlockChromeRims();
	void unlockTshirts();
	void unlockVehicleMods();
	void characterPrompt();
	void skipTutorial();
	void unlockAllAwards();
	void unlockHeistTrophies();
	void unlockAllHairstyles();
	void ownAllWeapons();
	void unlockAll();
}

namespace online {

	void remote50K3(Player player);

	void Remove_Objects(Player SelectedPlayer);
	void triggerScript(ScrHandle id, Player player, uint64_t arg2, uint64_t arg3);
	//void silent50K(Player player);
	//void remote50K(Player player);
	void remoteKick(Player player);
	void remoteInv(Player player);
	void remoteRP(Player target);
	void remoteSilent(Player target);
	void remote50k(Player target);
	void blankRemote(Player target, int scriptID);
	int GetFreeSeat(Vehicle vehicle);
	void teleportToCar(Ped ped);
	bool isPlayerFriend(Player target);
	void teleportallcoords(Player target);
	void shootPed(Player target);
	void dropWeapon(char * weapon, Ped recievingPed);
	Ped attackPed(Player target, char * pedModel, char * weapon, bool cop, ePedType variation);
	void attackPed(Player target, char * pedModel, char * weapon, bool cop, ePedType variation, char * vehModel);
	void attckSwat(Player target);
	void attackJesus(Player target);
	void attackSwatRiot(Player target);
	void loop_esp(Player target, int r, int g, int b);
	void loop_killpeds(Player target);
	void loop_remoteCash(Player target);
	void loop_stealthR(Player target);
	void loop_fuckCam(Player target);
	void loop_annoyBomb(Player target);
	void loop_forcefield(Player target);
	void loop_freezePlayer(Player target);
	void loop_massacre(Player target);
}

namespace lobby {

	void kickAll(int restriction);
	void kickVeh(int restriction);
	void deleteVeh(int restriction);
	void giveVeh(int restriction, char * vehicle);
	void removeWeps(int restriction);
	void explode(int restriction);
	void remote50K(int restriction);
}
void SelPlayerInfoStolenFromGalaxyLOLFIghtME(char* playerName, Player p);
void autisticTestbs();
#endif
