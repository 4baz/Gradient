#pragma once
#include "../natives.hpp"
#include "../common.hpp"
#include <services/players/player_service.hpp>

//using namespace Big;

//extern float mnux;
//extern float mnuy;


extern bool menuSounds;
extern bool rightPress;
extern bool leftPress;
extern bool squarePress;
extern bool gradients;

extern RGBA bannerRect;
/*extern int bannerRectRed;
extern int bannerRectGreen;
extern int bannerRectBlue;*/

extern RGBA bannerText;
/*extern int bannerTextRed;
extern int bannerTextGreen;
extern int bannerTextBlue;
extern int bannerTextOpacity;*/
extern const char* optionTextToAdd;
extern int optionCount;
extern int currentOption;
extern int maxOptions;

extern float MainBackGroundX;
extern float MainBackGroundY;
extern float MainBackGroundWidth;

extern RGBA background;
/*extern int backgroundRed;
extern int backgroundGreen;
extern int backgroundBlue;
extern int backgroundOpacity;*/

extern RGBA highlight;
extern int highlightRed;
extern int highlightGreen;
extern int highlightBlue;

extern RGBA optionsCol;
extern int optionsFont;
extern int optionsRed;
extern int optionsGreen;
extern int optionsBlue;
extern int optionsOpacity;

extern bool optionCenter;

extern float mainTextX;
extern float mainTextY;

extern float XValue;

extern float checkboxY;

extern float CounterX;
extern float CounterY;

extern float scrollerX;
extern float scrollerY;

extern RGBA scrollerCol;
extern int scrollerRed;
extern int scrollerGreen;
extern int scrollerBlue;
extern int scrollerOpacity;

extern float secondtitleX;
extern float secondTitleY;

extern RGBA secondTitle;
extern int secondTitleRed;
extern int secondTitleGreen;
extern int secondTitleBlue;
extern int secondTitleOpacity;

extern const char* infoText;

extern float infoBoxX;
extern float infoBoxY;
extern float infoBoxTextX;
extern float infoBoxTextY;

extern float BarUnderHeaderX;
extern float BarUnderHeaderY;
extern float BarUnderHeaderHeight;

extern float BarAboveInfoY;
extern float BarAboveInfoHeight;

extern int submenu;
extern int submenuLevel;
extern int lastSubmenu[];
extern int lastOption[];
extern int ival;

extern Player selPlayer;
extern const char* selPlayerName;
extern bool GfriendCheck(Player player);


extern const char* CharKeyboard(const char* windowName, int maxInput, const char* defaultText);


void changeSubmenu(int newSubmenu);
void setupText(const char* text);
void drawText(const char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, int position, bool outline);
void drawSprite(const char* Streamedtexture, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
void drawSpriteLayer(const char* Streamedtexture, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a, int layer);
void PlayFrontendSound(const char* sound);
void DisplayHelpTextThisFrame(const char* text);
void AddTitle(const char* title);
void AddTitleColour(const char* title, int red, int green, int blue);
void AddWeaponTitle(const char* title);
void AddVehicleTitle(const char* title);
void AddSubmenu(const char* option, int submenu,const char* info);
void AddOption(const char* option, const char* info);
void AddOption(const char* option, const char* string, const char* info);
void AddOption(const char* option, std::function<void()> function, const char* info);
void AddToggle(const char* option, bool* boolean, const char* info);
void AddToggle(const char* option, bool boolean, std::function<void()> function, const char* info);
void addBoolOption(const char* option, bool b00l, const char* info);
void AddInt(const char* option, int* inttochange, int min, int max, int increments, const char* info);
void AddFloat(const char* option, float* floattochange, float min, float max, float increments, const char* info);

extern void AddString(char* optiontext, char* option, int* var, int min, int max,const char* info);
 extern void AddString( char* optiontext,   char* option, int* var, int min, int max, std::function<void()> callback, const char* info);
// extern void AddString(char* optiontext, char* option, int* var, int min, int max, std::function<void()> function, const char* info);
void AddPlayer(const char* name, Player player, const char* info);
//static void AddPlayerTest(const player_ptr& plyr, const char* name, Player player, const char* info);

void addrpOption(const char* option, int value, const char* info);
void AddPlayer(const char* name, Player player, const char* info);
void AddBreak(const char* option, const char* info);
void AddWeaponSwitch(int* inttochange, int min, int max, int increments, const char* info);
void AddKmsSwitch(int* inttochange, int min, int max, int increments, const char* info);
///extern void onlineplayerinfoA(const char* playername, Player player);
extern  void playerminiinfoondxtick(const char* playername, Player plr);
extern int optionPress();
void drawHeader();
void ResetVars();
void DisableControls();
void DrawBackground();
void optionCounter();
void OpenMonitor();
void ClosedMonitor();
void submenuHandler();
void main();

extern bool AddIntTEST(const char* option, int* inttochange, int min, int max, int increments, const char* info);

void PTFXCALLO(char* call1, char* call2, char* name, Player target);
void PlayerAnimation(char* anim, char* animid);


namespace vehiclehsh {
	static char* arenawar[] = { "bruiser", "bruiser2", "bruiser3", "brutus", "brutus2",
"brutus3", "cerberus", "cerberus2", "cerberus3", "clique", "deathbike", "deathbike2",
"deathbike3", "deveste", "deviant", "dominator4", "dominator5", "dominator6",
"impaler", "impaler2", "impaler3", "issi4", "issi5", "issi6", "italigto", "monster3",
"monster4", "monster5", "rcbandito", "scarab", "scarab2", "scarab3", "schlagen", "slamvan4",
"slamvan5", "slamvan6", "toros", "tulip", "vamos", "zr380", "zr3802", "zr3803" };


static char* afterhrs[] = { "stafford", "scramjet", "strikeforce", "terbyte",
"pbus2", "oppressor2", "pounder2", "speedo4", "freecrawler", "mule4", "menacer", "blimp3", "swinger", "patriot2" };



static char* SOUTHERNSAN[] = {
	"caracara", "cheburek", "dominator3", "ellie", "entity2", "fagaloa", "flashgt",
	"gb200", "hotring", "issi3", "jester3", "michelli", "seasparrow", "taipan", "tezeract",
	"tyrant"
};


static char* Doomsday1[] = {
	"autarch", "avenger", "barrage", "chernobog", "comet4", "comet5",
	"deluxo", "gt500", "hermes", "hustler", "kamacho","khanjali",
	"neon", "pariah", "raiden", "revolter", "riata", "riot2", "savestra",
	"sc1", "sentinel3", "streiter", "stromberg", "thruster", "viseris",
	"volatol", "yosemite", "z190"
};

static char* SMUGLERSRUN1[] = {
	"havok", "rapidgt3", "retinue", "vigilante", "visione", "cyclone", "ALPHAZ1",
	"BOMBUSHKA", "HOWARD", "HUNTER", "MICROLIGHT", "MOGUL", "MOLOTOK", "NOKOTA", "PYRO",
	"ROGUE", "SEABREEZE", "STARLING", "TULA"
};



static char* GUNRUNNING1[] = {
	"APC", "ARDENT", "CADDY3", "CHEETAH2", "DUNE3", "HALFTRACK", "HAULER2",
	"INSUGENT3", "NIGHTSHARK", "OPPRESSOR", "PHANTOM3", "TAMPA3", "TECHNICAL3",
	"TORENO", "TRAILERLARGE", "TRAILERS4", "TRAILERSMALL2", "VAGNER", "XA21"
};

static char* CUNNINGSTUNTS1[] = {
	"BF400", "BRIOSO", "CLIFFHANGER", "CONTENDER", "GARGOYLE", "LE7B", "LYNX",
	"OMNIS", "RALLYTRUCK", "SHEAVA", "TAMPA2", "TROPHYTRUCK", "TROPHYTRUCK2",
	"TROPOS", "TYRUS"
};
static char* IMPORTEXPORT1[] = {
	"BLAZER5", "BOXVILLE5", "COMET3", "DIABLOUS", "DIABLOUS2", "DUNE4", "DUNE5",
	"ELEGY", "FCR", "FCR2", "ITALIGTB", "ITALIGTB2", "NERO", "NERO2", "PENETRATOR",
	"PHANTOM2", "RUINER2", "SPECTER", "SPECTER2", "TECHNICAL2", "TEMPESTA", "VOLTIC2",
	"WASTELANDER"
};

static char* Boats1[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};

static char* Commercial1[] = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3"
};



static char* Compacts1[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
};

static char* Coupes1[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
};

static char* Cycles1[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};

static char* Emergency1[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
};

static char* Helicopters1[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
};

static char* Industrial1[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};

static char* Military1[] = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
};

static char* Motorcycles1[] = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2", "OPPRESSOR"
};

static char* Muscle1[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
};

static char* OffRoad1[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
	"BLAZER5"
};

static char* Planes1[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
};

static char* Sedans1[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARR"
};

static char* Sports1[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUINER2", "PHANTOM2", "RUSTON"
};

static char* SportsClassics1[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "INFERNUS2", "TURISMO2",
};

static char* Super1[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1"
};

static char* SUVs1[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
};

static char* Trailer1[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
};

static char* Trains1[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};

static char* Utility1[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
};

static char* Vans1[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};

static char* trucks1[] = {
	"boxville","stockade","stockade2","tiptruck","tiptruck2",
	"cutter","handler","docktug","dump","biff","hauler","phantom",
	"rubble","mule","mixer","mixer2","flatbed","packer","pounder",
	"benson","scrap","phanotm2","hauler2","phantom3",
};




}