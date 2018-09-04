#pragma once
#include "crossMapping.h"
void ScriptMain();
//void set_status_text(std::string str, DWORD time = 2500, bool isGxtEntry = false);

class Script
{
public:
	static bool isInit();
	static void onTick();
	//	static void loops();
}; extern uint RequestedModel;
enum RequestState
{
	loaded,
	requesting
};
extern RequestState model_state;
extern void(*modelFunction)();

//extern uint64_t __HASHMAPDATA[];

//uint64_t HashMapData[5];


void drawHeader();


