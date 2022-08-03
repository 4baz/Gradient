#pragma once
//Variables
#ifndef MENUVARIABLES_H



namespace vehicleVars {
	bool vehThemeActive = false;
	bool vehSpawnDelete = true;
	bool spawnAirplaneInAir = false;
	bool spawnInVehicle = true;
	bool vehSpawnNeon = true;
	bool vehSpawnMaxed = false;
}
namespace playerVars {
	bool LifelessRagdoll = false;
	bool ragdolltoggle = true;
	int ragdollDelay = 80;
	bool ragdollActive = false;
	bool toVehicle = false;
}
namespace weaopnVars {
	float wepDamageValue = 1.f;
	float punchForce = 5.f;
	bool hitSomething = false;
	Object latestObj = -1;
}
namespace miscVars {
	bool unlimitedradar = false;
}
namespace recoveryVars {
	int dropAmount = 200000;
	bool netcashLoop = false;
	bool netcashLoop90m = false;
	bool netcash200k = false;
	//bool stealthBank = true;
}
namespace onlineVars {
	int remoteDropAmount = 50000;
}
#endif // !MENUVARIABLES_H
