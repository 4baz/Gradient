
struct rgba {
	int r, g, b, a;
};
extern float menux;
extern rgba titleText;
extern rgba titleRect;
extern rgba scroller;
extern rgba options;
extern rgba optionsrect;


class InfoMenu
{
public:
	static void healthOption();
};

int IconNotification(char *text, char *text2, char *Subject);

class Menu {
public:
	static int getKeyPressed(int key);
	static char* StringToChar(std::string string);
	static bool currentMenu(char* menuname);
	static void changeMenu(char* menuname);
	static void backMenu();

	static void drawText(char* text, int font, float x, float y, float scalex, float scaley, rgba rgba, bool center);
	static void drawNotification(char* msg);
	static void drawRect(float x, float y, float width, float height, rgba rgba);
	static void drawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, rgba rgba);

	static void Title(char* title);
	static bool Option(char* option, char* des="");
	static bool MenuOption(char* option, char* menu);
	static bool IntOption(char* option, int *var, int min, int max, int step = 1);
	static bool FloatOption(char* option, float *var, float min, float max, float step = 0.1);
	static bool BoolOption(char* option, bool *b00l);
	static bool BoolSpriteOption(char* option, bool b00l, char* category, char* spriteOn, char* spriteOff);
	static bool IntArray(char* option, int display[], int *PlaceHolderInt);
	static bool FloatArray(char* option, float display[], int *PlaceHolderInt);
	static bool CharArray(char* option, char* display[], int *PlaceHolderInt);
	static void TeleportOption(char* option, float x, float y, float z);
	static void RPOption(char* option, int value);

	static void IniWriteInt(LPCWSTR file, LPCWSTR section, LPCWSTR key, int value);
	static int IniReadInt(LPCWSTR file, LPCWSTR section, LPCWSTR key);
	static void IniWriteFloat(LPCWSTR file, LPCWSTR section, LPCWSTR key, float value);

	static void LoadMenuTheme(LPCWSTR file);
	static void SaveMenuTheme(LPCWSTR file);


	static void endMenu();
	static void checkKeys();


	static void drawMap();
	static void SmallTitle(char* title);
	static void Menu::SmallOption(char * text, char* Streamedtexture, char* textureName);
	static void WeaponMenu();
	static void PlayerMenu();
};
	static char * weaponicon[] =
{ "vehicle_weapon_player_buzzard", "weapon_assault_mg", "weapon_automatic_shotgun", "weapon_ball", "weapon_bat", "weapon_battle_axe", "weapon_bottle", "weapon_bullpuprifle", "weapon_buzzard_rocket", "weapon_combatpdw", "weapon_compactrifle", "weapon_compact_grenade_launcher", "weapon_crowbar", "weapon_dagger", "weapon_dbshotgun", "weapon_firework", "weapon_flare", "weapon_flare_gun", "weapon_flashlight", "weapon_golfclub", "weapon_gusenberg", "weapon_hammer", "weapon_hatchet", "weapon_heavypistol", "weapon_heavyshotgun", "weapon_heavy_grenade_launcher", "weapon_heavy_minigun", "weapon_heavy_rifle", "weapon_heavy_rpg", "weapon_hominglauncher", "weapon_jerry_can", "weapon_knife", "weapon_knuckle", "weapon_lmg", "weapon_lmg_combat", "weapon_machete", "weapon_machinepistol", "weapon_marksmanpistol", "weapon_marksmanrifle", "weapon_mini_smg", "weapon_molotov", "weapon_musket", "weapon_nightstick", "weapon_pipebomb", "weapon_pistol", "weapon_pistol_50", "weapon_pistol_ap", "weapon_pistol_combat", "weapon_pool_cue", "weapon_programmable_ar", "weapon_proximine", "weapon_railgun", "weapon_revolver", "weapon_rifle_advanced", "weapon_rifle_assault", "weapon_rifle_carbine", "weapon_shotgun_assault", "weapon_shotgun_bullpup", "weapon_shotgun_pump", "weapon_shotgun_sawnoff", "weapon_smg", "weapon_smg_assault", "weapon_smg_micro", "weapon_sniper", "weapon_sniper_assault", "weapon_sniper_heavy", "weapon_snowball", "weapon_snspistol", "weapon_specialcarbine", "weapon_stungun", "weapon_switchblade", "weapon_thermalcharge", "weapon_thrown_bz_gas", "weapon_thrown_grenade", "weapon_thrown_sticky", "weapon_unarmed", "weapon_vintagepistol" };


extern float x, y, width, height, percent;
extern bool BoolMap;


void PTFXCALL(char *call1, char* call2, char *name);

void Talker(Player player);
void Speedo(float speed);

void RequestControlOfEnt(Entity entity);
float degToRad(float degs);