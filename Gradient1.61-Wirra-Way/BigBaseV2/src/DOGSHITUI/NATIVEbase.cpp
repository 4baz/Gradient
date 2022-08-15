#include "../common.hpp"
#include "../natives.hpp"
#include "NATIVEmenu.h"
#include "NATIVEbase.h"

#include "../DiscordRPC.h"
#include <renderer.hpp>
#include <script_global.hpp>
#include <services/players/player_service.hpp>
#include "../../BigBaseV2/src/services/players/player_service.hpp"
#include "script.hpp"

//dumb as fuck

bool renderonprop = false;


using namespace big;

#define mnux  g->menu.menux
#define mnuy g->menu.menuy
//float mnux = 0.0f;
//float mnuy = 0.0f;
// float mnux = g->menu.menux;
//float mnuy = g->menu.menuy;
#define UI HUD
Player selPlayer = NULL;
const char* selPlayerName;

bool menuSounds = true;
bool rightPress = false;
bool leftPress = false;
bool squarePress = false;
bool gradients = true;

RGBA bannerRect = { 81, 8, 126, 225 };
/*int bannerRectRed = 255;
int bannerRectG = 0;
int bannerRectB = 0;
int bannerRectA = 255;*/

RGBA bannerText = { 255, 255, 255, 255 };
/*int bannerTextR = 255;
int bannerTextG = 255;
int bannerTextB = 255;
int bannerTextA = 255;*/
const char* optionTextToAdd;
int optionCount;
int currentOption;
int maxOptions = 14;

float MainBackGroundX = 0.827f;
float MainBackGroundY = 0.137f;
float MainBackGroundWidth = 0.225f;

RGBA background = { 0, 0, 0, 185 };
/*int backgroundR = 0;
int backgroundG = 0;
int backgroundB = 0;
int backgroundA = 185;*/

RGBA highlight = { 0, 0, 0, 255 };
int highlightRed = 0;
int highlightGreen = 0;
int highlightBlue = 0;

int optionsFont = 0;
RGBA optionsCol = { 255, 255, 255, 255 };
int optionsRed = 255;
int optionsGreen = 255;
int optionsBlue = 255;
int optionsOpacity = 255;

bool optionCenter = FALSE;

float mainTextX = 0.827f;
float mainTextY = 0.106f;

float XValue = 0.827f;

float checkboxY = 0.0135f;

float CounterX = 0.909f;
float CounterY = 0.108f;

float scrollerX = 0.827f;
float scrollerY = 0.1197f;

RGBA scrollerCol = { 255, 255, 255, 255 };
int scrollerRed = 255;
int scrollerGreen = 255;
int scrollerBlue = 255;
int scrollerOpacity = 255;

float secondTitleX = 0.718f;
float secondTitleY = 0.108f;

RGBA secondTitle = { 255, 255, 255, 255 };
int secondTitleRed = 255;
int secondTitleGreen = 255;
int secondTitleBlue = 255;
int secondTitleOpacity = 255;

const char* infoText;

float infoBoxX = 0.827f;
//float infoBoxY = 0.127f;
float infoBoxY = 0.173f;
float infoBoxTextX = 0.718f;
//float infoBoxTextY = 0.114f; original
float infoBoxTextY = 0.160f;



float arrowupdownY = 0.127f;

float arrowupdownBoxY = 0.118f;
float arrowupdownBoxY2 = 0.128f;



float BarUnderHeaderX = 0.827f;
float BarUnderHeaderY = 0.121f;
float BarUnderHeaderHeight = 0.032f;

//float BarAboveInfoY = 0.108f;
float BarAboveInfoY = 0.108f;

float BarAboveInfoHeight = 0.003f;



// mp_menu_glare
int gGlareHandle;
int scaleform;
float gGlareDir;
float GlareX = 1.10f;
float GlareY = 0.41f;
float Glarewidth = 0.71f;
float Glareheight = 0.73f;



int submenu = 0;
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];
int ival = 0;


//Our subhandler. Enum on the left, void on the right. You can relocate this.
void submenuHandler()
{
	switch (submenu)
	{
	case SUB::MAINMENU: sub::MainMenu(); break;
	case SUB::SETTINGS: sub::settings(); break;
	case SUB::HEADER: sub::header(); break;
	case SUB::OPTIONS: sub::options(); break;
	case SUB::CREDITS: sub::credits(); break;
	case SUB::DEVOPTIONS: sub::devoptions(); break;

	case SUB::PLAYER: sub::player(); break;
	case SUB::WEAPONS: sub::weapons(); break;
	case SUB::TELEPORTS: sub::teleport(); break;
	case SUB::PTFX: sub::ptfx(); break;
	case SUB::ANIMATIONS: sub::animations(); break;
	case SUB::PLAYERLIST: sub::playerList(); break;
	case SUB::SELPLAYER: sub::selplayer(); break;
	case SUB::PROTECTIONS: sub::PROTECTIONS(); break;


	case SUB::VEHICLE: sub::vehicle(); break;
	case SUB::VEHSPAWNER: sub::vehspawner(); break;
	case SUB::LSC: sub::lscustoms(); break;
	case SUB::VEH_CAYOPERICHO: sub::VEH_CAYOPERICHO(); break;
	case SUB::VEH_SummerUpdate: sub::VEH_SummerUpdate(); break;
	case SUB::VEH_CasinoHeist: sub::VEH_CasinoHeist(); break;
	case SUB::VEH_CasinoUpdate: sub::VEH_CasinoUpdate(); break;
	case SUB::VEH_ArenaWar: sub::VEH_ArenaWar(); break;
	case SUB::VEH_Vans: sub::VEH_Vans(); break;
	case SUB::VEH_Utility: sub::VEH_Utility(); break;
	case SUB::VEH_TRAINS: sub::VEH_TRAINS(); break;
	case SUB::VEH_trailers: sub::VEH_trailers(); break;
	case SUB::VEH_Super: sub::VEH_Super(); break;
	case SUB::VEH_SportsClassic: sub::VEH_SportsClassic(); break;
	case SUB::VEH_SPORTS: sub::VEH_SPORTS(); break;
	case SUB::VEH_Boats: sub::VEH_Boats(); break;
	case SUB::VEH_Commercials: sub::VEH_Commercials(); break;
	case SUB::VEH_compacts: sub::VEH_compacts(); break;
	case SUB::VEH_Coupes: sub::VEH_Coupes(); break;
	case SUB::VEH_BIKES: sub::VEH_BIKES(); break;
	case SUB::VEH_Emergency: sub::VEH_Emergency(); break;
	case SUB::VEH_Helicopters: sub::VEH_Helicopters(); break;
	case SUB::VEH_industraial: sub::VEH_industraial(); break;
	case SUB::VEH_Military: sub::VEH_Military(); break;
	case SUB::VEH_MOTOCYCLE: sub::VEH_MOTOCYCLE(); break;
	case SUB::VEH_Muscle: sub::VEH_Muscle(); break;
	case SUB::VEH_Offroad: sub::VEH_Offroad(); break;
	case SUB::VEH_Planes: sub::VEH_Planes(); break;
	case SUB::VEH_Suvs: sub::VEH_Suvs(); break;
	case SUB::VEH_Sedans: sub::VEH_Sedans(); break;
	case SUB::VEH_Service: sub::VEH_Service(); break;
	case SUB::VEH_CRIMINALENTPRISE: sub::VEH_CRIMINALENTPRISE(); break;





	case SUB::ONLINE_OPTIONS: sub::online_options(); break;
		//	case SUB::OBJECTS: sub::attach_objects(); break;
	case SUB::LOBBY: sub::lobby(); break;
	case SUB::ESP_SETTINGS: sub::ESP_SETTINGS(); break;

	case SUB::RECOVERY: sub::recovery(); break;
//	case SUB::RANK: sub::set_rank(); break;
		//	case SUB::VEH_DOOMSDAY: sub::veh_doomsday(); break;
	}
}
//Change submenu function to change submenus lol
void changeSubmenu(int newSubmenu)
{
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}

//Setup text draw function
void setupText(const char* text)
{
	GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();
}

//Draw text function
void drawText(const char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, int position, bool outline)
{
	UI::SET_TEXT_FONT(font);
//	UI::SET_TEXT_SCALE(scalex, scaley);
	if (renderonprop) {
		UI::SET_TEXT_SCALE(scalex * 0.3, scaley *0.3);

	}
	else {
		UI::SET_TEXT_SCALE(scalex, scaley);

	}
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);

	if (position == 0 || position == 1)
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
	else
		UI::SET_TEXT_WRAP(0.0f, x);

	if (position == 1)
		UI::SET_TEXT_CENTRE(true);
	else if (position == 2)
		UI::SET_TEXT_RIGHT_JUSTIFY(true);

	if (outline)
		UI::SET_TEXT_OUTLINE();

	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);

	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
}

//NOT COOKED FUNCTION FOR DRAWING ON TV OMEGALUL
/*
void drawText(const char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, int position, bool outline)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);

	if (position == 0 || position == 1)
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
	else
		UI::SET_TEXT_WRAP(0.0f, x);

	if (position == 1)
		UI::SET_TEXT_CENTRE(true);
	else if (position == 2)
		UI::SET_TEXT_RIGHT_JUSTIFY(true);

	if (outline)
		UI::SET_TEXT_OUTLINE();

	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);

	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y,0);
}




*/




void drawText2( char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, int position, bool outline)
{
	UI::SET_TEXT_FONT(font);
	//UI::SET_TEXT_SCALE(scalex, scaley);

	if (renderonprop) {
		UI::SET_TEXT_SCALE(scalex * 0.3, scaley * 0.3);

	}
	else {
		UI::SET_TEXT_SCALE(scalex, scaley);

	}


	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);

	if (position == 0 || position == 1)
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
	else
		UI::SET_TEXT_WRAP(0.0f, x);

	if (position == 1)
		UI::SET_TEXT_CENTRE(true);
	else if (position == 2)
		UI::SET_TEXT_RIGHT_JUSTIFY(true);

	if (outline)
		UI::SET_TEXT_OUTLINE();

	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT2("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME2(text);

	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 0);
}


//Draw sprite function
void drawSprite(const char* Streamedtexture, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);

	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
	{
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a,0,0);
	}
}
//draw help text/ top left notification
void DisplayHelpTextThisFrame(const char* text)
{
	UI::BEGIN_TEXT_COMMAND_DISPLAY_HELP("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::END_TEXT_COMMAND_DISPLAY_HELP(0, 0, 1, -1);
}
//Draw layered sprite
void drawSpriteLayer(const char* Streamedtexture, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a, int layer)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);

	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
	{
	//	GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(layer);
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a,0,0);
	}
}

//Play sound function
void PlayFrontendSound(const char* sound)
{
	if (menuSounds)
		AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}

//Adds the title of a submenu
void AddTitle(const char* title)
{
	//	drawGlare(0.827f, 0.1410f, 0.190f, 0.034f, 255, 255, 255);

	drawText("4ass", 1, mnux+ 0.827f, mnuy+ 0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);
	drawText(title, 0, mnux + secondTitleX, mnuy +secondTitleY, 0.35f, 0.35f, secondTitleRed, secondTitleGreen, secondTitleBlue, secondTitleOpacity, FALSE, FALSE);
}

//Adds a title with a certain colour
void AddTitleColour(const char* title, int red, int green, int blue)
{
	drawText("4ass", 1, mnux+0.827f, mnuy+0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, true, false);
	drawText(title, 0, mnux+secondTitleX, mnuy+secondTitleY, 0.35f, 0.35f, red, green, blue, secondTitleOpacity, false, false);
}
void AddWeaponTitle(const char* title)
{
	//	drawGlare(0.827f, 0.1410f, 0.190f, 0.034f, 255, 255, 255);
	drawSprite("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", mnux+0.827f, mnuy+ 0.06f, 0.225f, 0.09f, 0, 255, 255, 255, bannerRect.A);

	drawText("4ass", 1, mnux+ 0.827f, mnuy+ 0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);
	drawText(title, 0, mnux+secondTitleX, mnuy+ secondTitleY, 0.35f, 0.35f, secondTitleRed, secondTitleGreen, secondTitleBlue, secondTitleOpacity, FALSE, FALSE);
}
void AddVehicleTitle(const char* title)
{
	//	drawGlare(0.827f, 0.1410f, 0.190f, 0.034f, 255, 255, 255);
	drawSprite("shopui_title_clubhousemod", "shopui_title_clubhousemod", mnux+0.827f, mnuy+0.06f, 0.225f, 0.09f, 0, 255, 255, 255, bannerRect.A);

	drawText("4ass", 1, mnux+0.827f, mnuy+ 0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);
	drawText(title, 0, mnux+secondTitleX, mnuy+secondTitleY, 0.35f, 0.35f, secondTitleRed, secondTitleGreen, secondTitleBlue, secondTitleOpacity, FALSE, FALSE);
}

void AddBreak(const char* option, const char* info = NULL)
{
	optionTextToAdd = option;
	optionCount++;

	//Changes color when you highlight a certain option.
	if (currentOption == optionCount) {

		infoText = info;

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(optionTextToAdd, optionsFont, mnux+ mainTextX, mnuy+(optionCount * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, optionsOpacity, 1, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(optionTextToAdd, optionsFont, mnux+ mainTextX, mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, optionsOpacity, 1, false);
	}

	//Makes other options the colour, that you choose.
	else {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(optionTextToAdd, optionsFont, mnux+mainTextX, mnuy+(optionCount * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, 1, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(optionTextToAdd, optionsFont, mnux+ mainTextX, mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, 1, false);

	}
}


//Overloads of AddOption to simplify
void AddOption(const char* option, const char* info = NULL)
{
	optionTextToAdd = option;
	optionCount++;

	//Changes color when you highlight a certain option.
	if (currentOption == optionCount) {

		infoText = info;

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(optionTextToAdd, optionsFont, mnux+ mainTextX - 0.108f, mnuy+(optionCount * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, optionsOpacity, optionCenter, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(optionTextToAdd, optionsFont, mnux+ mainTextX - 0.108f, mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, optionsOpacity, optionCenter, false);
	}

	//Makes other options the colour, that you choose.
	else {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(optionTextToAdd, optionsFont, mnux+ mainTextX - 0.108f, mnuy+(optionCount * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, optionCenter, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(optionTextToAdd, optionsFont, mnux+ mainTextX - 0.108f, mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, optionCenter, false);

	}
}





//MainBackGroundX


//Adds a submenu
void AddSubmenu(const char* option, int submenu, const char* info = NULL)
{



	char buf[30];
	snprintf(buf, sizeof(buf), "%s~h~ ~m~>", option);
	AddOption(buf, info);

	if (currentOption == optionCount && GetAsyncKeyState(VK_RETURN) & 1) {
		PlayFrontendSound("SELECT");
		changeSubmenu(submenu);
	}

}

void AddOption2( char* option, char* string, const char* info)
{
	//Use of our overload to simplify
	AddOption(option, info);

	if (currentOption == optionCount) {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText2(string, optionsFont, mnux + (0.108f + (XValue)), mnuy + (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, 255, 2, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText2(string, optionsFont, mnux + (0.108f + (XValue)), mnuy + ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, 255, 2, false);

	}

	else {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText2(string, optionsFont, mnux + (0.108f + (XValue)), mnuy + (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, 2, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText2(string, optionsFont, mnux + (0.108f + (XValue)), mnuy + ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, 2, false);

	}
}
void AddOption2( char* option, const char* info = NULL)
{
	char* optionTextToAdd = option;
	optionCount++;

	//Changes color when you highlight a certain option.
	if (currentOption == optionCount) {

		infoText = info;

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText2(optionTextToAdd, optionsFont, mnux + mainTextX - 0.108f, mnuy + (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, optionsOpacity, optionCenter, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText2(optionTextToAdd, optionsFont, mnux + mainTextX - 0.108f, mnuy + ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, optionsOpacity, optionCenter, false);
	}

	//Makes other options the colour, that you choose.
	else {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText2(optionTextToAdd, optionsFont, mnux + mainTextX - 0.108f, mnuy + (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, optionCenter, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText2(optionTextToAdd, optionsFont, mnux + mainTextX - 0.108f, mnuy + ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, optionCenter, false);

	}
}

//AddOption to show certain string
void AddOption(const char* option, char* string, const char* info)
{
	//Use of our overload to simplify
	AddOption(option, info);

	if (currentOption == optionCount) {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(string, optionsFont, mnux+(0.108f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, 255, 2, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(string, optionsFont, mnux+(0.108f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, 255, 2, false);

	}

	else {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(string, optionsFont, mnux+(0.108f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, 2, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(string, optionsFont, mnux+(0.108f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, 2, false);

	}
}

//Our main AddOption function
void AddOption(const char* option, std::function<void()> function, const char* info = NULL)
{
	AddOption(option, info);

	//Checks if NUMPAD5 has been pressed and excecutes certain code.
	if (currentOption == optionCount && GetAsyncKeyState(VK_RETURN) & 1) {
		function();
		PlayFrontendSound("SELECT");
	}

}

bool AddOptionTEST(const char* option, std::function<void()> function)
{
	AddOption(option, "");

	//Checks if NUMPAD5 has been pressed and excecutes certain code.
	if (currentOption == optionCount && GetAsyncKeyState(VK_RETURN) & 1) {
		function();
		PlayFrontendSound("SELECT");
		return true;
	}
	return false;
}



void addrpOption(const char* option, int value, const char* info = NULL)
{
	AddOption(option, info);
	if (currentOption == optionCount && GetAsyncKeyState(VK_RETURN) & 1) {
		{
		//	STATS::STAT_SET_INT($("MP0_CHAR_XP_FM"), value, true);
		//	STATS::STAT_SET_INT($("MP1_CHAR_XP_FM"), value, true);
		//	STATS::STAT_SET_INT($("MP2_CHAR_XP_FM"), value, true);
		}
	}
}
void addBoolOption(const char* option, bool b00l, const char* info = NULL)
{

	char buf[30];
	if (b00l)
	{
		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}

		else {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}
		AddOption(option, info);
	}
	else
	{
		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}

		else {
			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}		AddOption(option, info);
	}

}
//Our AddToggle option for looped stuff
void AddToggle(const char* option, bool* boolean, const char* info = NULL)
{
	//Use of overloads once again
	AddOption(option, info);

	//If NUMPAD5 is pressed it changes the bool to On/Off
	if (currentOption == optionCount && GetAsyncKeyState(VK_RETURN) & 1) {
		PlayFrontendSound("SELECT");
		*(bool*)boolean = !*(bool*)boolean;
	}

	//Here we are going to use sprites as our On/Off indicators. You can change this to text, if you feel like it.
	if (*(bool*)boolean) {

		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}

		else {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}
	}

	else {

		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}

		else {
			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}
	}
}

//Our AddToggle option for looped stuff with execution
/*void AddToggle(char *option, bool* boolean, std::function<void()> function, char *info = NULL)
{
AddToggle(option, boolean, info);
if (currentOption == optionCount && GetAsyncKeyState(VK_NUMPAD5) & 1)
function();
}*/

//Our Dumb (passive) AddToggle option
void AddToggle(const char* option, bool boolean, std::function<void()> function, const char* info = NULL)
{
	//Use of overloads once again
	AddOption(option, info);

	//If NUMPAD5 is pressed it executes function, bool indicator uses passive bool
	if (currentOption == optionCount && GetAsyncKeyState(VK_RETURN) & 1) {
		function();
		PlayFrontendSound("SELECT");
	}

	//Here we are going to use sprites as our On/Off indicators. You can change this to text, if you feel like it.
	if (boolean) {

		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}

		else {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}
	}

	else {

		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}

		else {
			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+(optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", mnux+(0.1015f + (XValue)), mnuy+((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}
	}
}

//Our int changer
void AddInt(const char* option, int* inttochange, int min, int max, int increments, const char* info = NULL)
{
	char buf[30];

	snprintf(buf, sizeof(buf), "[%i]", *inttochange);

	AddOption(option, buf, info);

	if (currentOption == optionCount) {

		if (GetAsyncKeyState(VK_RIGHT) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange >= max)
				*inttochange = min;

			else
				*inttochange = *inttochange + increments;
		}

		else if (GetAsyncKeyState(VK_LEFT) & 1) {
			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange <= min)
				*inttochange = max;

			else
				*inttochange = *inttochange - increments;
		}
	}
}

bool AddIntTEST(const char* option, int* inttochange, int min, int max, int increments, const char* info = NULL)
{
	char buf[30];

	snprintf(buf, sizeof(buf), "[%i]", *inttochange);

	AddOption(option, buf, info);

	if (currentOption == optionCount) {

		if (GetAsyncKeyState(VK_RIGHT) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange >= max)
				*inttochange = min;

			else
				*inttochange = *inttochange + increments;
		}

		else if (GetAsyncKeyState(VK_LEFT) & 1) {
			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange <= min)
				*inttochange = max;

			else
				*inttochange = *inttochange - increments;
		}
		else if (GetAsyncKeyState(VK_RETURN) & 1) {
			return true;
		}
		return false;
	}
}


//Our float changer
void AddFloat(const char* option, float* floattochange, float min, float max, float increments, const char* info = NULL)
{
	char buf[30];
	sprintf(buf, "[%g]", *floattochange);

	AddOption(option, buf, info);
	if (currentOption == optionCount) {
		if (GetAsyncKeyState(VK_RIGHT) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");
			if (*floattochange >= max)
				*floattochange = min;
			else
				*floattochange = *floattochange + increments;

		}

		else if (GetAsyncKeyState(VK_LEFT) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");
			if (*floattochange <= min)
				*floattochange = max;
			else
				*floattochange = *floattochange - increments;
		}
	}
}

//Our string selector function whatever
void AddString( char *optiontext,  char* option, int *var, int min, int max,const  char *info = NULL)
{
	char buf[30];
	sprintf(buf, "< %s >", option);

	AddOption2(optiontext, buf, info);
	if (currentOption == optionCount) {
		if (GetAsyncKeyState(VK_RIGHT) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;

		}
		else if (GetAsyncKeyState(VK_LEFT) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
	}
}

void AddWeaponSwitch(int* inttochange, int min, int max, int increments, const char* info = NULL)
{//eAmmoSpecialType
	char buf[30];

	char myoption[30];

	snprintf(buf, sizeof(buf), "[%i]", *inttochange);
	/*
	
		{ "No Special Ammo",		eAmmoSpecialType::None },
	{ "Armor Piercing Ammo",	eAmmoSpecialType::ArmorPiercing },
	{ "Explosive Ammo",		eAmmoSpecialType::Explosive },
	{ "Full Metal Jacket Ammo",eAmmoSpecialType::FMJ },
	{ "Hollow Point Ammo",		eAmmoSpecialType::HollowPoint },
	{ "Incendiary Ammo",		eAmmoSpecialType::Incendiary },
	{ "Tracer Ammo",			eAmmoSpecialType::Tracer },


	*/

	switch (*inttochange) {
	case 0:
		g->weapons.ammo_special.type =	eAmmoSpecialType::None;
		//myoption = 'None';
		snprintf(myoption, sizeof(myoption), "[%s]", "None");

		break;
	case 1:
		g->weapons.ammo_special.type = eAmmoSpecialType::ArmorPiercing;
	//	myoption = 'Armor Piercing';
		snprintf(myoption, sizeof(myoption), "[%s]", "Armour Piercing");

		break;
	case 2:
		g->weapons.ammo_special.type = eAmmoSpecialType::Explosive;
		snprintf(myoption, sizeof(myoption), "[%s]", "Explosive");

		break;
	case 3:
		g->weapons.ammo_special.type = eAmmoSpecialType::FMJ;
		snprintf(myoption, sizeof(myoption), "[%s]", "FMJ");

		break;
	case 4:
		g->weapons.ammo_special.type = eAmmoSpecialType::HollowPoint;
		snprintf(myoption, sizeof(myoption), "[%s]", "HollowPoint");

		break;
	case 5:
		g->weapons.ammo_special.type = eAmmoSpecialType::Incendiary;
		snprintf(myoption, sizeof(myoption), "[%s]", "Incendiary");

		break;
	case 6:
		g->weapons.ammo_special.type = eAmmoSpecialType::Tracer;
		snprintf(myoption, sizeof(myoption), "[%s]", "Tracer");

		break;

	}



	AddOption(myoption, buf, info);

	if (currentOption == optionCount) {

		if (GetAsyncKeyState(VK_RIGHT) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange >= max)
				*inttochange = min;

			else
				*inttochange = *inttochange + increments;
		}

		else if (GetAsyncKeyState(VK_LEFT) & 1) {
			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange <= min)
				*inttochange = max;

			else
				*inttochange = *inttochange - increments;
		}
	}
}
void AddKmsSwitch(int* inttochange, int min, int max, int increments, const char* info = NULL)
{//eAmmoSpecialType
	char buf[30];

	char myoption[30];

	snprintf(buf, sizeof(buf), "[%i]", *inttochange);


	switch (*inttochange) {
	case 0:
		g->vehicle.speed_unit = SpeedUnit::KMPH;
		//myoption = 'None';
		snprintf(myoption, sizeof(myoption), "[%s]", "KMPH");

		break;
	case 1:
		g->vehicle.speed_unit = SpeedUnit::MIPH;
		//	myoption = 'Armor Piercing';
		snprintf(myoption, sizeof(myoption), "[%s]", "MIPH");

		break;
	case 2:
		g->vehicle.speed_unit = SpeedUnit::MPS;
		snprintf(myoption, sizeof(myoption), "[%s]", "MPS");


	}



	AddOption(myoption, buf, info);

	if (currentOption == optionCount) {

		if (GetAsyncKeyState(VK_RIGHT) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange >= max)
				*inttochange = min;

			else
				*inttochange = *inttochange + increments;
		}

		else if (GetAsyncKeyState(VK_LEFT) & 1) {
			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange <= min)
				*inttochange = max;

			else
				*inttochange = *inttochange - increments;
		}
	}
}


//Our string selector function whatever with execution
void AddString( char* optiontext,  char* option, int* var, int min, int max, std::function<void()> callback, const char* info = NULL)
{
	AddString(optiontext, option, var, min, max, info);
	if (currentOption == optionCount && (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT)) & 1)
		callback();
}

bool friendCheck(Player player) {
	if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(player)) {
		Big:Any handle;
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle, 13);
		return NETWORK::NETWORK_IS_FRIEND(&handle);
	}
	return false;
}


/*
void AddString(const char *optiontext,const char* option, int *var, int min, int max, std::function<void()> function,const char *info = NULL)
{
char buf[30];
sprintf(buf, "< %s >", option);

AddOption(optiontext, buf, info);
if (currentOption == optionCount) {
if (GetAsyncKeyState(VK_NUMPAD6) & 1) {

PlayFrontendSound("NAV_UP_DOWN");
if (*var >= max)
*var = min;
else
*var = *var + 1;

}
else if (GetAsyncKeyState(VK_NUMPAD4) & 1) {

PlayFrontendSound("NAV_UP_DOWN");
if (*var <= min)
*var = max;
else
*var = *var - 1;
}
else if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
function();
PlayFrontendSound("SELECT");
}
}
}*/

//If option is pressed do something
int optionPress()
{
	if (GetAsyncKeyState(VK_RETURN) & 1)
		return currentOption;
	else return 0;
}

Hash bruh(std::string str) {
	std::string lowerNative = str;
	transform(lowerNative.begin(), lowerNative.end(), lowerNative.begin(), tolower);
	Hash num = 0;
	const char* bytes = lowerNative.c_str();;
	int length = strlen(bytes);
	for (int i = 0; i < length; i++)
	{
		num += bytes[i];
		num += num << 10;
		num ^= num >> 6;
	}
	num += num << 3;
	num ^= num >> 11;
	return (num + (num << 15));
}
//Draws our header
void drawHeader()
{

	
		GRAPHICS::DRAW_RECT(mnux + 0.827f, mnuy + 0.06f, 0.225f, 0.09f, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A, 0);

	


	//if (gradients)
	//thia titlw only works wright with the custom openIV texture
	//	drawSprite("commonmenu", "interaction_bgd", 0.827f, 0.06f, 0.225f, 0.09f, 0, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A);
	//else
}

//Resets everything
void ResetVars()
{
	drawHeader();
	rightPress = false;
	leftPress = false;
	squarePress = false;
	optionCount = NULL;
	ival = 0;
}



//Draws our background
void DrawBackground()
{
	


	if (optionCount > maxOptions) {

		//Sets the layer of the background, so our sprites can go on top
//		GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
		//Background
		GRAPHICS::DRAW_RECT(mnux+MainBackGroundX, mnuy+(((maxOptions * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (maxOptions * 0.035f), background.R, background.G, background.B, background.A,0);

		//Scroller
		if (currentOption > maxOptions) {
			if (gradients)
				drawSprite("commonmenu", "gradient_nav", mnux+ scrollerX, mnuy+((maxOptions * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
			else
				GRAPHICS::DRAW_RECT(mnux+scrollerX, mnuy+((maxOptions * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity,0);
		}
		else {
//			GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
			if (gradients)
				drawSprite("commonmenu", "gradient_nav", mnux+ scrollerX, mnuy+((currentOption * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
			else
				GRAPHICS::DRAW_RECT(mnux+scrollerX, mnuy+((currentOption * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity,0);
		}

		//Bar under header
		GRAPHICS::DRAW_RECT(mnux+BarUnderHeaderX, mnuy+ BarUnderHeaderY, 0.225f, BarUnderHeaderHeight, 0, 0, 0, 255,0);

		//Bar above infobox
	//	if (gradients)
		//	drawSprite("CommonMenu", "interaction_bgd", BarUnderHeaderX, (((maxOptions + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, 0, bannerRect.R, bannerRect.G, bannerRect.B, 255);
	//	else
		//	GRAPHICS::DRAW_RECT(BarUnderHeaderX, (((maxOptions + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, bannerRect.R, bannerRect.G, bannerRect.B, 255);

	}

	else {

		//Set layer
	//	GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
		//Background
		GRAPHICS::DRAW_RECT(mnux+MainBackGroundX, mnuy+(((optionCount * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (optionCount * 0.035f), background.R, background.G, background.B, background.A,0);

		//Scroller
	//	GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(1);
		if (gradients)
			drawSprite("commonmenu", "gradient_nav", mnux+ scrollerX, mnuy+((currentOption * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
		else
			GRAPHICS::DRAW_RECT(mnux+scrollerX, mnuy+((currentOption * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity,0);

		//Bar under header
		GRAPHICS::DRAW_RECT(mnux+BarUnderHeaderX, mnuy+ BarUnderHeaderY, 0.225f, BarUnderHeaderHeight, 0, 0, 0, 255,0);

		//Bar above infobox
	//	if (gradients)
		//	drawSprite("CommonMenu", "interaction_bgd", BarUnderHeaderX, (((optionCount + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, 0, bannerRect.R, bannerRect.G, bannerRect.B, 255);
		//else
		//	GRAPHICS::DRAW_RECT(BarUnderHeaderX, (((optionCount + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, bannerRect.R, bannerRect.G, bannerRect.B, 255);

	}

	//Our infobox
	if (optionCount > maxOptions)
	{
		drawText(infoText, optionsFont, mnux+ infoBoxTextX, mnuy+((maxOptions + 1) * 0.035f + infoBoxTextY), 0.3f, 0.3f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE, FALSE);
		GRAPHICS::DRAW_RECT(mnux+infoBoxX, mnuy+(((maxOptions + 1) * 0.035f) + infoBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A,0); //Info Box
	}
	else
	{
		drawText(infoText, optionsFont, mnux+ infoBoxTextX, mnuy+((optionCount + 1) * 0.035f + infoBoxTextY), 0.3f, 0.3f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE, FALSE);
		GRAPHICS::DRAW_RECT(mnux+ infoBoxX, mnuy+(((optionCount + 1) * 0.035f) + infoBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A,0); //Info Box
	}

	//arrow up down
	if (optionCount > maxOptions) {
		GRAPHICS::DRAW_RECT(mnux+infoBoxX, mnuy+(((maxOptions + 1) * 0.035f) + arrowupdownBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A,0); //Info Box

		if (currentOption == 1) {
			drawSprite("commonmenu", "arrowright", mnux+ infoBoxX, mnuy+((maxOptions + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", mnux+infoBoxX, mnuy+((maxOptions + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
		}
		else if (currentOption == optionCount) {
			drawSprite("commonmenu", "arrowright", mnux+infoBoxX, mnuy+((maxOptions + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", mnux+ infoBoxX, mnuy+((maxOptions + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);

		}
		else {
			drawSprite("commonmenu", "arrowright", mnux+ infoBoxX, mnuy+((maxOptions + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", mnux+ infoBoxX, mnuy+((maxOptions + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
		}
	}
	else
	{

		GRAPHICS::DRAW_RECT(mnux+infoBoxX, mnuy+(((optionCount + 1) * 0.035f) + arrowupdownBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A,0); //Info Box

		if (currentOption == 1 && optionCount > 1) {
			drawSprite("commonmenu", "arrowright", mnux+infoBoxX, mnuy+((optionCount + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", mnux+infoBoxX, mnuy+((optionCount + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
		}
		else if (currentOption == optionCount && optionCount > 1) {
			drawSprite("commonmenu", "arrowright", mnux+ infoBoxX, mnuy+((optionCount + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", mnux+ infoBoxX, mnuy+((optionCount + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);

		}
		else if (optionCount > 1) {
			drawSprite("commonmenu", "arrowright", mnux+ infoBoxX, mnuy+((optionCount + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", mnux+ infoBoxX, mnuy+((optionCount + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
		}
	}
}
bool GfriendCheck(Player player) {
	if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(player)) {
		Any handle;
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle, 13);
		return NETWORK::NETWORK_IS_FRIEND(&handle);
	}
	return false;
}
void AddPlayer(const char* name, Player player,const char* info = NULL)
{
	char buf[50], ibuf[50];
	if (player == PLAYER::PLAYER_ID()) {
		snprintf(buf, sizeof(buf), "%s~g~ [SELF] ", name);
		AddOption(buf, "~g~SELF");
	}
	else if (NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(player)) {
		snprintf(buf, sizeof(buf), "%s~r~ [ROCKSTAR]", name);
		AddOption(buf, "~r~ROCKSTAR ADMIN");
	}
	else if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", -1, 0) == player) {
		snprintf(buf, sizeof(buf), "%s~y~ [HOST]", name);
		AddOption(buf, "~y~SESSION HOST");
	}
	else if (GfriendCheck(player)) {
		snprintf(buf, sizeof(buf), "%s~b~ [FRIEND] ", name);
		AddOption(buf, "~b~FRIEND ");
	}
	else
		AddOption(name, "");

	
	if (currentOption == optionCount) {
		playerminiinfoondxtick(name, player);
	
	
		
	}


	if (currentOption == optionCount && optionPress()) {

		//Set our variables and change the submenu
		selPlayer = player;
		selPlayerName = name;
		PlayFrontendSound("SELECT");
		changeSubmenu(SUB::SELPLAYER);


	}

}






//				onlineplayerinfoA(playerNme,i);




//works but rects and text screwed up need to fix


float testtitlex;
float testtitley;

float backgroundx = 0.220f;
float backgroundy= 0.220f;
float backgroundsizex;
float backgroundsizey;


void Smalltitle(const char* text) {

	if (mnux <= -0.500f) {
		drawText(text, optionsFont, mnux + XValue + 0.220f, mnuy + mainTextY - 0.0355f, 0.43f, 0.43f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);

		GRAPHICS::DRAW_RECT(mnux + XValue + 0.220f, mnuy + mainTextY - 0.0195f, 0.195f, 0.045f, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A, 0);
	}
	else {
		drawText(text, optionsFont, mnux + XValue - 0.220f, mnuy + mainTextY - 0.0355f, 0.43f, 0.43f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);

		GRAPHICS::DRAW_RECT(mnux + XValue - 0.220f, mnuy + mainTextY - 0.0195f, 0.195f, 0.045f, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A, 0);
	}


	

//	Drawing::Rect( Settings::menuX - 0.220f, Settings::menuY - 0.019f }, { 0.195f, 0.045f });
//	Drawing::Rect( Settings::menuX - 0.220f, Settings::menuY - 0.019f }, { 0.195f, 0.045f });
}
void SmallInfo(const char* text, short line) {
	//drawText(text, optionsFont, XValue - 0.200f, (line * 0.022f) + mainTextY + 0.0035f ,  0.27f, 0.27f ,  bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);
	if (mnux <= -0.500f) {

		GRAPHICS::DRAW_RECT(mnux + XValue + 0.220f, mnuy + (line * 0.022f) + mainTextY + 0.0145f, 0.195f, 0.022f, 0, 0, 0, 200, 0);


		drawText(text, optionsFont, mnux + XValue + 0.150f, mnuy + (line * 0.022f) + mainTextY + 0.0035f, 0.27f, 0.27f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE, FALSE);

	}
	else {
		GRAPHICS::DRAW_RECT(mnux + XValue - 0.220f, mnuy + (line * 0.022f) + mainTextY + 0.0145f, 0.195f, 0.022f, 0, 0, 0, 200, 0);


		drawText(text, optionsFont, mnux + XValue - 0.300f, mnuy + (line * 0.022f) + mainTextY + 0.0035f, 0.27f, 0.27f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE, FALSE);
	}
	
	

}


void playerminiinfoondxtick( const char* playername,Player plr) {
	// const char* playernm; Player plr;
	if (toggleplayerinfo) {

		Player p = plr;
		Ped SelectedCoords = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)) && NETWORK::NETWORK_IS_PLAYER_CONNECTED(p)) {
			const char* playerName = PLAYER::GET_PLAYER_NAME(p);
			Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
			const char* rockstarID = "";
			//const char* IP = "";

			bool isfriend;
			int NETWORK_HANDLE[76];
			NETWORK::NETWORK_HANDLE_FROM_PLAYER(p, &NETWORK_HANDLE[0], 13);
			if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13)) {
				rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
				isfriend = NETWORK::NETWORK_IS_FRIEND(&NETWORK_HANDLE[0]);
			}
			



			std::ostringstream title; title << "Player Title: [Player]";

			bool ishost; if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("Freemode", -1, 0) == p) {
				ishost = true;
			}
			else
			{
				ishost = false;
			}
			bool inside = INTERIOR::IS_VALID_INTERIOR(INTERIOR::GET_INTERIOR_FROM_ENTITY(ped));
			NETWORK::NETWORK_HANDLE_FROM_PLAYER(p, &NETWORK_HANDLE[0], 13);
			const char* UserID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);

			if (isfriend)title << " [Friend]";
			if (ishost)  title << " [S-Host]";
			if (inside)	 title << " [Inside]";


			

			float health = ENTITY::GET_ENTITY_HEALTH(ped);
			float maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
			float healthPercent = health * 100 / maxHealth;


			float armor = PED::GET_PED_ARMOUR(ped);
			float maxArmor = PLAYER::GET_PLAYER_MAX_ARMOUR(p);
			float armorPercent = armor * 100 / maxArmor;

			bool alive = !PED::IS_PED_DEAD_OR_DYING(ped, 1);
			const char* aliveStatus;
			if (alive)
				aliveStatus = "Yes";
			else
				aliveStatus = " ~No";

			bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);

			std::ostringstream Armor; Armor << "Armor: " << armorPercent << "%";
			std::ostringstream Alive; Alive << "Alive: " << aliveStatus;
			std::ostringstream RockstarID; RockstarID << "Rockstar ID: " << rockstarID;
	
	

			std::ostringstream Health; Health << "Health: " << healthPercent << "%";
			std::ostringstream VehicleModel; VehicleModel << "Vehicle: ";
			std::ostringstream Vehicle_Hash; Vehicle_Hash << "Vehicle Hash: ";
			std::ostringstream Speed; Speed << "Speed: ";
			std::ostringstream IsInAVehicle; IsInAVehicle << "In Vehicle: ";
			std::ostringstream WantedLevel; WantedLevel << "Wanted Level: " << PLAYER::GET_PLAYER_WANTED_LEVEL(p);

			if (inVehicle)
			{

				IsInAVehicle << " Yes";
				Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
				VehicleModel << UI::GET_LABEL_TEXT_(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
				Vehicle_Hash << MISC::GET_HASH_KEY(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
				float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
				float vehSpeedConverted;
				vehSpeedConverted = round(vehSpeed * 3.6f);
				Speed << vehSpeedConverted << " KM/H";
			}
			else
			{
				IsInAVehicle << "No";
				float speed = round(ENTITY::GET_ENTITY_SPEED(ped) * 100) / 100;
				Speed << speed << " M/S";
				VehicleModel << "None";
			}
			std::ostringstream Weapon; Weapon << "Weapon: ";
			Hash weaponHash;
			if (WEAPON::GET_CURRENT_PED_WEAPON(ped, &weaponHash, 1))
			{
				const char* weaponName;
				if (weaponHash == 2725352035) { weaponName = "Unarmed"; }
				else if (weaponHash == 2578778090) { weaponName = "Knife"; }
				else if (weaponHash == 0x678B81B1) { weaponName = "Nightstick"; }
				else if (weaponHash == 0x4E875F73) { weaponName = "Hammer"; }
				else if (weaponHash == 0x958A4A8F) { weaponName = "Bat"; }
				else if (weaponHash == 0x440E4788) { weaponName = "GolfClub"; }
				else if (weaponHash == 0x84BD7BFD) { weaponName = "Crowbar"; }
				else if (weaponHash == 0x1B06D571) { weaponName = "Pistol"; }
				else if (weaponHash == 0x5EF9FEC4) { weaponName = "Combat Pistol"; }
				else if (weaponHash == 0x22D8FE39) { weaponName = "AP Pistol"; }
				else if (weaponHash == 0x99AEEB3B) { weaponName = "Pistol 50"; }
				else if (weaponHash == 0x13532244) { weaponName = "Micro SMG"; }
				else if (weaponHash == 0x2BE6766B) { weaponName = "SMG"; }
				else if (weaponHash == 0xEFE7E2DF) { weaponName = "Assault SMG"; }
				else if (weaponHash == 0xBFEFFF6D) { weaponName = "Assault Riffle"; }
				else if (weaponHash == 0x83BF0278) { weaponName = "Carbine Riffle"; }
				else if (weaponHash == 0xAF113F99) { weaponName = "Advanced Riffle"; }
				else if (weaponHash == 0x9D07F764) { weaponName = "MG"; }
				else if (weaponHash == 0x7FD62962) { weaponName = "Combat MG"; }
				else if (weaponHash == 0x1D073A89) { weaponName = "Pump Shotgun"; }
				else if (weaponHash == 0x7846A318) { weaponName = "Sawed-Off Shotgun"; }
				else if (weaponHash == 0xE284C527) { weaponName = "Assault Shotgun"; }
				else if (weaponHash == 0x9D61E50F) { weaponName = "Bullpup Shotgun"; }
				else if (weaponHash == 0x3656C8C1) { weaponName = "Stun Gun"; }
				else if (weaponHash == 0x05FC3C11) { weaponName = "Sniper Rifle"; }
				else if (weaponHash == 0x0C472FE2) { weaponName = "Heavy Sniper"; }
				else if (weaponHash == 0xA284510B) { weaponName = "Grenade Launcher"; }
				else if (weaponHash == 0x4DD2DC56) { weaponName = "Smoke Grenade Launcher"; }
				else if (weaponHash == 0xB1CA77B1) { weaponName = "RPG"; }
				else if (weaponHash == 0x42BF8A85) { weaponName = "Logogun"; }
				else if (weaponHash == 0x93E220BD) { weaponName = "Grenade"; }
				else if (weaponHash == 0x2C3731D9) { weaponName = "Sticky Bomb"; }
				else if (weaponHash == 0xFDBC8A50) { weaponName = "Smoke Grenade"; }
				else if (weaponHash == 0xA0973D5E) { weaponName = "BZGas"; }
				else if (weaponHash == 0x24B17070) { weaponName = "Molotov"; }
				else if (weaponHash == 0x060EC506) { weaponName = "Fire Extinguisher"; }
				else if (weaponHash == 0x34A67B97) { weaponName = "Petrol Can"; }
				else if (weaponHash == 0xFDBADCED) { weaponName = "Digital scanner"; }
				else if (weaponHash == 0x88C78EB7) { weaponName = "Briefcase"; }
				else if (weaponHash == 0x23C9F95C) { weaponName = "Ball"; }
				else if (weaponHash == 0x497FACC3) { weaponName = "Flare"; }
				else if (weaponHash == 0xF9E6AA4B) { weaponName = "Bottle"; }
				else if (weaponHash == 0x61012683) { weaponName = "Gusenberg"; }
				else if (weaponHash == 0xC0A3098D) { weaponName = "Special Carabine"; }
				else if (weaponHash == 0xD205520E) { weaponName = "Heavy Pistol"; }
				else if (weaponHash == 0xBFD21232) { weaponName = "SNS Pistol"; }
				else if (weaponHash == 0x7F229F94) { weaponName = "Bullpup Rifle"; }
				else if (weaponHash == 0x92A27487) { weaponName = "Dagger"; }
				else if (weaponHash == 0x083839C4) { weaponName = "Vintage Pistol"; }
				else if (weaponHash == 0x7F7497E5) { weaponName = "Firework"; }
				else if (weaponHash == 0xA89CB99E) { weaponName = "Musket"; }
				else if (weaponHash == 0x3AABBBAA) { weaponName = "Heavy Shotgun"; }
				else if (weaponHash == 0xC734385A) { weaponName = "Marksman Rifle"; }
				else if (weaponHash == 0x63AB0442) { weaponName = "Homing Launcher"; }
				else if (weaponHash == 0xAB564B93) { weaponName = "Proximity Mine"; }
				else if (weaponHash == 0x787F0BB) { weaponName = "Snowball"; }
				else if (weaponHash == 0x47757124) { weaponName = "Flare Gun"; }
				else if (weaponHash == 0xE232C28C) { weaponName = "Garbage Bag"; }
				else if (weaponHash == 0xD04C944D) { weaponName = "Handcuffs"; }
				else if (weaponHash == 0x0A3D4D34) { weaponName = "Combat PDW"; }
				else if (weaponHash == 0xDC4DB296) { weaponName = "Marksman Pistol"; }
				else if (weaponHash == 0xD8DF3C3C) { weaponName = "Brass Knuckles"; }
				else if (weaponHash == 0x6D544C99) { weaponName = "Railgun"; }
				else { weaponName = "Unkown Weapon"; }
				Weapon << weaponName;
			}
			else Weapon << "Unarmed";
			Vector3 myCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
			Hash streetName, crossingRoad;
			PATHFIND::GET_STREET_NAME_AT_COORD(coords.x, coords.y, coords.z, &streetName, &crossingRoad);
			float distance = MISC::GET_DISTANCE_BETWEEN_COORDS(myCoords.x, myCoords.y, myCoords.z, coords.x, coords.y, coords.z, false);

			std::ostringstream Distance; Distance << "Distance: ";
			std::ostringstream Street; Street << "Street: " << UI::GET_STREET_NAME_FROM_HASH_KEY(streetName);
			std::ostringstream Zone; Zone << "Zone: " << UI::GET_LABEL_TEXT_(ZONE::GET_NAME_OF_ZONE(coords.x, coords.y, coords.z));

			if (distance > 1000) {
				distance = round((distance / 1000) * 100) / 100;
				Distance << distance << " Kilometers";
			}
			else {
				distance = round(distance * 1000) / 1000;
				Distance << distance << " Meters";
			}
			std::ostringstream IP;
			std::string iptest;
	//	if (rage::netPlayerData* net_player_data = g_player_service->get_selected()->get_net_data(); net_player_data != nullptr){
		//	{
			//	ImGui::Text("Rockstar ID: %d", net_player_data->m_rockstar_id);
			//	ImGui::Text(
			//		"IP Address: %d.%d.%d.%d:%d",
			//		net_player_data->m_external_ip.m_field1,
			//		net_player_data->m_external_ip.m_field2,
			//		net_player_data->m_external_ip.m_field3,
			//		net_player_data->m_external_ip.m_field4,
			//		net_player_data->m_external_port
			//	);
			
			//	rage::netPlayerData* net_player_data = g_player_service->get_selected()->get_net_data();
		//		 IP << "IP Address:"<< net_player_data->m_external_ip.m_field1 <<"."<< net_player_data->m_external_ip.m_field2 << "." << net_player_data->m_external_ip.m_field3
		//			<< "." << net_player_data->m_external_ip.m_field4 << "." << net_player_data->m_external_port;

		//			
		//		 std::string iptest = "TEST IP:" + net_player_data->m_external_ip.m_field1 +'.'+ net_player_data->m_external_ip.m_field2+'.' +net_player_data->m_external_ip.m_field3 +'.'+ net_player_data->m_external_ip.m_field4 + ':'+ net_player_data->m_external_port;
				

		//	}
		

			/*
			static auto ASD = (std::uintptr_t(*)(int))(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));
			auto bruh = ASD(plr);
			char ipBuf[32] = {}; //External IP
			if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(plr)) {
				if (plr != PLAYER::PLAYER_ID()) std::snprintf(ipBuf, sizeof(ipBuf) - 1, "0.0.0.0"); else {
					if (bruh) {
						auto idot = *(uintptr_t*)(bruh + 0x10C8); if (idot)
						{
							auto ip = (BYTE*)(idot + 0x6C); std::snprintf(ipBuf, sizeof(ipBuf) - 1, "%u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
						}
					}
				}
			}
			else
			{
				if (bruh)
				{
					auto idot = *(uintptr_t*)(bruh + 0x10C8); if (idot)
					{
						auto ip = (BYTE*)(idot + 0x6C); std::snprintf(ipBuf, sizeof(ipBuf) - 1, "%u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
					}
				}
			}
			char ipBuf2[32] = {}; //Internal IP
			if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(plr))
			{
				if (plr != PLAYER::PLAYER_ID()) std::snprintf(ipBuf, sizeof(ipBuf2) - 1, "0.0.0.0"); else
				{
					if (bruh)
					{
						auto idot = *(uintptr_t*)(bruh + 0x10C8); if (idot) {
							auto ip = (BYTE*)(idot + 0x74); std::snprintf(ipBuf, sizeof(ipBuf) - 1, "%u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
						}
					}
				}
			}
			else
			{
				if (bruh)
				{
					auto idot = *(uintptr_t*)(bruh + 0x10C8); if (idot)
					{
						auto ip = (BYTE*)(idot + 0x74); std::snprintf(ipBuf, sizeof(ipBuf2) - 1, "%u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
					}
				}
			}
			char ipBufs[32] = {};
			if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(plr))
			{
				if (g_SelectedPlayer != PLAYER::PLAYER_ID()) std::snprintf(ipBufs, sizeof(ipBufs) - 1, "0.0.0.0");
				else
				{
					if (bruh) {
						auto idot = *(uintptr_t*)(bruh + 0x10C8); if (idot)
						{
							auto ip = (BYTE*)(idot + 0x6C); std::snprintf(ipBufs, sizeof(ipBufs) - 4, "%u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
						}
					}
				}
			}
			else
			{
				if (bruh)
				{
					auto idot = *(uintptr_t*)(bruh + 0x10C8); if (idot)
					{
						auto ip = (BYTE*)(idot + 0x6C); std::snprintf(ipBufs, sizeof(ipBufs) - 1, "%u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);
					}
				}
			}*/


			std::ostringstream X; X << "X: " << coords.x;
			std::ostringstream Y; Y << "Y: " << coords.y;
			std::ostringstream Z; Z << "Z: " << coords.z;
			std::ostringstream close; close << "";
			std::ostringstream Model; Model << "Model: 0x" << ENTITY::GET_ENTITY_MODEL(SelectedCoords);
		//	std::ostringstream Externalip; Externalip << "External IP: " << ipBuf;
		//	std::ostringstream Internalip; Internalip << "Internal IP: " << ipBufs;

		//	auto m_player = cPointers->m_GetPlayerNetworkId(plr);
		//	std::ostringstream Slods; Slods << "Player Slot: " << m_player->slot;
		//	std::ostringstream CHost; CHost << "Host Token: " << m_player->get_net_data()->host_token;
		//	std::ostringstream conected; conected << "Port: " << m_player->get_net_data()->m_local_port;


			Smalltitle(playerName);
			SmallInfo((char*)RockstarID.str().c_str(), 0);
			if (rage::netPlayerData* net_player_data = g_player_service->get_selected()->get_net_data(); net_player_data != nullptr)
			{
				char ipBuf[32] = {}; //External IP

				auto ip = std::snprintf(ipBuf, sizeof(ipBuf) - 1, "%d.%d.%d.%d:%d",
					net_player_data->m_external_ip.m_field1,
					net_player_data->m_external_ip.m_field2,
					net_player_data->m_external_ip.m_field3,
					net_player_data->m_external_ip.m_field4,
					net_player_data->m_external_port);


				std::ostringstream Externalip; Externalip << "External IP: " << ipBuf;


			//	SmallInfo((char*)Externalip.str().c_str(), 1); NOT FOR UC

			}

			SmallInfo("", 2);

		//	ui::SmallInfo((char*)Slods.str().c_str(), 1);
			SmallInfo((char*)title.str().c_str(), 3);
			SmallInfo((char*)Alive.str().c_str(), 4);
			SmallInfo((char*)Health.str().c_str(), 5);
			SmallInfo((char*)Armor.str().c_str(), 6);
			SmallInfo((char*)WantedLevel.str().c_str(), 7);
			SmallInfo((char*)Weapon.str().c_str(), 8);

			SmallInfo("", 9);

			SmallInfo((char*)IsInAVehicle.str().c_str(), 10);
			SmallInfo((char*)VehicleModel.str().c_str(), 11);
			SmallInfo((char*)Speed.str().c_str(), 12);
			SmallInfo("", 13);

			SmallInfo((char*)Zone.str().c_str(), 14);
			SmallInfo((char*)Street.str().c_str(), 15);
			SmallInfo((char*)Distance.str().c_str(), 16);
			
			SmallInfo("", 17);

			
			SmallInfo((char*)Model.str().c_str(), 18);
			SmallInfo((char*)close.str().c_str(), 19);
			SmallInfo((char*)X.str().c_str(), 20);
			SmallInfo((char*)Y.str().c_str(), 21);
			SmallInfo((char*)Z.str().c_str(), 22);
			
			
				
			

			
		

		//	SmallInfo((char*)RockstarID.str().c_str(), 0);
	



}





	}

}
const char* CharKeyboard(const char* windowName, int maxInput, const char* defaultText)
{
	MISC::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (MISC::UPDATE_ONSCREEN_KEYBOARD() == 0) script::get_current()->yield();
	if (!MISC::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return (char*)MISC::GET_ONSCREEN_KEYBOARD_RESULT();
}

//Our option counter, credits to Mafins.
void optionCounter()
{
	if (renderonprop) {
		UI::SET_TEXT_SCALE(0.35f * 0.3, 0.35f * 0.3);

	}
	else {
		UI::SET_TEXT_SCALE(0.35f, 0.35f);
	}

	UI::SET_TEXT_FONT(0);
	//UI::SET_TEXT_SCALE(0.35f, 0.35f);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("CM_ITEM_COUNT");
	UI::ADD_TEXT_COMPONENT_INTEGER(currentOption);
	UI::ADD_TEXT_COMPONENT_INTEGER(optionCount);

	//Checks whether option count is bigger than 10
	if (optionCount > maxOptions - 5)
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(mnux+CounterX - 0.006f, mnuy+ CounterY,0);
	//If not draw normally
	else
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(mnux+CounterX, mnuy+ CounterY,0);
}

//Monitors our menu, while it is open
void OpenMonitor()
{

	optionCounter();
	DrawBackground();
	DisableControls();

	if (GetAsyncKeyState(VK_UP) & 1) {

		PlayFrontendSound("NAV_UP_DOWN");
		currentOption--;

		if (currentOption < 1)
			currentOption = optionCount;

	}

	else if (GetAsyncKeyState(VK_DOWN) & 1) {

		PlayFrontendSound("NAV_UP_DOWN");
		currentOption++;

		if (currentOption > optionCount)
			currentOption = 1;

	}

	else if (GetAsyncKeyState(VK_BACK) & 1) {

		PlayFrontendSound("BACK");

		if (submenu == SUB::MAINMENU) {
			submenu = SUB::CLOSED;
		}

		else {
			submenu = lastSubmenu[submenuLevel - 1];
			currentOption = lastOption[submenuLevel - 1];
			submenuLevel--;
		}

	}
	else if (GetAsyncKeyState(VK_F8) & 1) {

		PlayFrontendSound("SELECT");
		//	is_user_authed();
		submenu = SUB::CLOSED;
		

	}

}

//Monitors our menu, whenever it is closed
void ClosedMonitor()
{
	if (GetAsyncKeyState(VK_F8) & 1) {

		PlayFrontendSound("SELECT");
		//	is_user_authed();
		submenu = SUB::MAINMENU;
		submenuLevel = 0;
		currentOption = 1;

	}
}


void PTFXCALLO(char* call1, char* call2, char* name, Player target)
{
	Ped user = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
//	call1o = call1;
//	call2o = call2;
	//nameo = name;
	//PTLoopPed = user;
	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::USE_PARTICLE_FX_ASSET(call2);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, user, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

}
bool Control(int vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	return !giveUp;
}
void PlayerAnimation(char* anim, char* animid)
{
	int pPlayer = PLAYER::PLAYER_PED_ID();
	Control(pPlayer);
	STREAMING::REQUEST_ANIM_DICT(anim);
	if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
	{
		TASK::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
	}
}

void DisableControls()
{
/*	for (uint8_t i = 0; i <= 6; i++)

	PAD::DISABLE_CONTROL_ACTION(2, i, true);
	PAD::DISABLE_CONTROL_ACTION(2, 106, true);
	PAD::DISABLE_CONTROL_ACTION(2, 329, true);
	PAD::DISABLE_CONTROL_ACTION(2, 330, true);

	PAD::DISABLE_CONTROL_ACTION(2, 14, true);
	PAD::DISABLE_CONTROL_ACTION(2, 15, true);
	PAD::DISABLE_CONTROL_ACTION(2, 16, true);
	PAD::DISABLE_CONTROL_ACTION(2, 17, true);
	PAD::DISABLE_CONTROL_ACTION(2, 24, true);
	PAD::DISABLE_CONTROL_ACTION(2, 69, true);
	PAD::DISABLE_CONTROL_ACTION(2, 70, true);
	PAD::DISABLE_CONTROL_ACTION(2, 84, true);
	PAD::DISABLE_CONTROL_ACTION(2, 85, true);
	PAD::DISABLE_CONTROL_ACTION(2, 99, true);
	PAD::DISABLE_CONTROL_ACTION(2, 92, true);
	PAD::DISABLE_CONTROL_ACTION(2, 100, true);
	PAD::DISABLE_CONTROL_ACTION(2, 114, true);
	PAD::DISABLE_CONTROL_ACTION(2, 115, true);
	PAD::DISABLE_CONTROL_ACTION(2, 121, true);
	PAD::DISABLE_CONTROL_ACTION(2, 142, true);
	PAD::DISABLE_CONTROL_ACTION(2, 241, true);
	PAD::DISABLE_CONTROL_ACTION(2, 261, true);
	PAD::DISABLE_CONTROL_ACTION(2, 257, true);
	PAD::DISABLE_CONTROL_ACTION(2, 262, true);
	PAD::DISABLE_CONTROL_ACTION(2, 331, true);*/
	PAD::DISABLE_CONTROL_ACTION(0, 27, true); // Disable phone

}

int	test1 = 300;

int test2 = 400;
int test3 = 300;

int test4 = 400;
void WWdxmain() {
	
	ImGui::Begin("int value changer test thingy");
	ImGui::Text("side menu pos X,Y");
	ImGui::SliderInt("X###Xpos", &test1, 0, 1000);
	ImGui::SliderInt("Y###Ypos", &test2, 0, 1000);
	ImGui::SliderInt("Xf###Xfpos", &test3, 0, 1000);
	ImGui::SliderInt("Yf###Yfpos", &test4, 0, 1000);
	ImGui::End();


	ImDrawList* MainMenu = ImGui::GetForegroundDrawList();

	//first value is left, second is bottom, third is right, forth is top
	//the way this works is that its each border of the rectangle 
	MainMenu->AddRectFilled(ImVec2( 10 ,460), ImVec2( 350,80 ), IM_COL32(0, 0, 0, 150));//background
//	ImDrawList* pinfo = ImGui::GetForegroundDrawList();
	//imgui p info render 
	// 
	//pinfo->AddRectFilled(ImVec2(mnux +1350, mnuy+100), ImVec2(mnux+974, mnuy+ 620), IM_COL32(0, 0, 0, 150));//backgroundRect
	//pinfo->AddRectFilled(ImVec2(mnux+1350, mnuy+20), ImVec2(mnux+974, mnuy+ 100), IM_COL32(81, 8, 126, 225));//bannerbackgroundRect
	//pinfo->AddText(ImVec2(mnux+ 1100, mnuy+40), IM_COL32(255, 255, 255, 255),"PlayerNameHere");//title

	//pinfo->AddText(ImVec2(mnux +990, mnuy+ 110), IM_COL32(255, 255, 255, 255), "Test Text");//first text so to print the rest do some maths so that its automatically further under








}
const char* renda_hash[] = {"prop_big_cin_screen"	};

const char* renda_name[] = {"cinscreen"	};
void main() {

//	while (g_Running) {
	//	big::WAIT(0);
		//	static bool first_time = false;
		//	if (!first_time)
		//	{
			//	Features();
		//	}
	//	featureloop();
		if (submenu != SUB::CLOSED) {

			if (renderonprop) {


				Any render_id = 0;
				auto hash = bruh("prop_big_cin_screen");
				char* render_name = "cinscreen";
				if (!UI::IS_NAMED_RENDERTARGET_REGISTERED(render_name))
					UI::REGISTER_NAMED_RENDERTARGET(render_name, false);
				if (!UI::IS_NAMED_RENDERTARGET_LINKED(hash))
					UI::LINK_NAMED_RENDERTARGET(hash);
				if (UI::IS_NAMED_RENDERTARGET_REGISTERED(render_name))
					render_id = UI::GET_NAMED_RENDERTARGET_RENDER_ID(render_name);

				UI::SET_TEXT_RENDER_ID(render_id);
				GRAPHICS::SET_SCRIPT_GFX_DRAW_ORDER(4);



			}

			OpenMonitor();
			ResetVars();
			submenuHandler();
			DisableControls();
			playerminiinfoondxtick;

			//test rect drawing rr


		}

		else ClosedMonitor();
//	}
}