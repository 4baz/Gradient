#pragma once
#include "stdafx.h"

bool RequestNetworkControl(uint vehID);
void RequestingControl(Entity e);

extern bool forceexplodewave;
void ForceExplodeWavePED();
void ForceExplodeWave();
void GiveWeaponPed(int Ped, int WeaponHash);
void DeletePed(int pedID);
void makePedHostile(uint Ped, int Target, bool choporswat = false, bool isClone = false);
extern bool mcriot ;
void MCRiot();
extern bool mcdance;
void MCDance();
void MCPushups();
void MCFollow();
void MCBurn();
void MCWater();
void MCPush();
void MCShock();
void ForceBoost();
void ForceThrow();
extern bool forcewave;
void ForceWave();

void walldrive();