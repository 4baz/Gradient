#pragma once

//=================
// PED FUNCTIONS
//=================

Ped ClonePed(Ped ped);
Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle);

//Animations
void LoadAnim(char * dict);
void playAnimation(Ped ped, bool loop, char * dict, char * anim);

//SKINS
bool applyChosenSkin(std::string skinName);

//CONTROL
void RequestControlOfEnt(Entity entity);

//stealth
void stealthtwelve(bool toggle, bool tobank);

//FORCE
void ApplyForceToEntity(Entity e, float x, float y, float z);

//GOD MODE
void GodMode(bool toggle);

//CALM PEDS
void set_all_nearby_peds_to_calm();

//NEARBY PEDS
std::set<Ped> getNearbyPeds();
void update_nearby_peds(Ped playerPed, int count);

//little one-line function called '$' to convert $TRING into a hash-key:
Hash $(std::string str);

//Converts Radians to Degrees
float degToRad(float degs);

//quick function to get-coords-of-entity:
Vector3 coordsOf(Entity entity);

//quick function to convert vector to float (length)
void VectorToFloat(Vector3 unk, float *Out);

//quick function to get distance between 2 points:
float distanceBetween(Vector3 A, Vector3 B);

//quick "get random int in range 0-x" function:
int rndInt(int start, int end);

//TELEPORTATION
Vector3 get_blip_marker();
void teleport_to_marker();
void teleport_to_objective();
void teleport_to_coords(Entity e, Vector3 coords);

//KEYBOARD
std::string show_keyboard(char* title_id, char* prepopulated_text);

//VEHICLE
void request_vehicle();

void notifyMap(std::string msg, BOOL blink);
