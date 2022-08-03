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

//NOTIFICATION
void notifyMap(std::string msg, BOOL blink);

//VEHICLE
void request_vehicle();

void ptfx(char* call1, char* call2, char* name);

void give_all_weps();

void upgrade_guns();

void loop_infiniteAmmo(Ped playerPed);


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

void repair(Vehicle vehicle);
void MaxVeh();
void openDoors();
void setPlate(Vehicle vehicle);
void kickVeh(Player player);
void deletePedVeh(Ped p);
void loop_esp(Player target, int r, int g, int b);
void loop_fuckCam(Player target);
void Unlock_all();
void RequestControlOfid(Entity netid);
static char* crash_objects[] = {

	"ng_proc_temp",
	"proc_brittlebush_01",
	"proc_desert_sage_01",
	"proc_dry_plants_01",
	"proc_drygrasses01",
	"proc_drygrasses01b",
	"proc_drygrassfronds01",
	"proc_dryplantsgrass_01",
	"proc_dryplantsgrass_02",
	"proc_forest_grass_01",
	"proc_forest_ivy_01",
	"proc_grassdandelion01",
	"proc_grasses01",
	"proc_grasses01b",
	"proc_grassfronds01",
	"proc_grassplantmix_01",
	"proc_grassplantmix_02",
	"proc_indian_pbrush_01",
	"proc_leafybush_01",
	"proc_leafyplant_01",
	"proc_lizardtail_01",
	"proc_lupins_01",
	"proc_meadowmix_01",
	"proc_meadowpoppy_01",
	"proc_sage_01",
	"proc_scrub_bush01",
	"proc_sml_reeds_01",
	"proc_sml_reeds_01b",
	"proc_sml_reeds_01c",
	"proc_stones_01",
	"proc_stones_02",
	"proc_stones_03",
	"proc_stones_04",
	"proc_stones_05",
	"proc_stones_06",
	"proc_wildquinine",
	"prop_dandy_b",
	"prop_dryweed_001_a",
	"prop_dryweed_002_a",
	"prop_fern_01",
	"prop_fernba",
	"prop_fernbb",
	"prop_flowerweed_005_a",
	"prop_grass_001_a",
	"prop_grass_ca",
	"prop_grass_da",
	"prop_log_aa",
	"prop_log_ab",
	"prop_log_ac",
	"prop_log_ad",
	"prop_log_ae",
	"prop_log_af",
	"prop_saplin_001_b",
	"prop_saplin_001_c",
	"prop_saplin_002_b",
	"prop_saplin_002_c",
	"prop_small_bushyba",
	"prop_tall_drygrass_aa",
	"prop_thindesertfiller_aa",
	"prop_weed_001_aa",
	"prop_weed_002_ba",
	"urbandryfrnds_01",
	"urbandrygrass_01",
	"urbangrnfrnds_01",
	"urbangrngrass_01",
	"urbanweeds01",
	"urbanweeds01_l1",
	"urbanweeds02",
	"urbanweeds02_l2",
	"v_proc2_temp",
	//70

};

void wantedUP();

void wantedDOWN();


void tp_entity_to_coords(float xPos, float yPos, float zPos);

void PTFX(char* call1, char* call2, char* name);

void PlayAnim(char* animationName, char* animDict);

void manualSelect();

void explodePed(Player target);