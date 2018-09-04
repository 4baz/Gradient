#pragma once

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