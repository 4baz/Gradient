#include "stdafx.h"
#include "subswitch.h"
#include "enums.h"
//#include "menuVariables.h"


bool menuSounds = true;
bool rightPress = false;
bool leftPress = false;
bool squarePress = false;
bool gradients = true;

RGBA bannerRect = { 244, 14, 67, 225 };
/*int bannerRectRed = 255;
int bannerRectG = 0;
int bannerRectB = 0;
int bannerRectA = 255;*/

RGBA bannerText = { 255, 255, 255, 255 };
/*int bannerTextR = 255;
int bannerTextG = 255;
int bannerTextB = 255;
int bannerTextA = 255;*/
char* optionTextToAdd;
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

char *infoText;

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
	case SUB::PLAYER: sub::player(); break;
	case SUB::WEAPONS: sub::weapons(); break;
	case SUB::TELEPORTS: sub::teleports(); break;
	case SUB::PTFX: sub::ptfx(); break;
	case SUB::ANIMATIONS: sub::animations(); break;
	case SUB::PLAYERLIST: sub::playerList(); break;
	case SUB::SELPLAYER: sub::selplayer(); break;
	case SUB::VEHICLE: sub::vehicle(); break;
	case SUB::VEHSPAWNER: sub::vehspawner(); break;
	case SUB::ONLINE_OPTIONS: sub::online_options(); break;
	case SUB::OBJECTS: sub::attach_objects(); break;
	case SUB::LOBBY: sub::lobby(); break;
	case SUB::RECOVERY: sub::recovery(); break;
	case SUB::RANK: sub::set_rank(); break;
	case SUB::VEH_DOOMSDAY: sub::veh_doomsday(); break;
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
void setupText(char *text)
{
	GRAPHICS::_BEGIN_TEXT_COMPONENT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	GRAPHICS::_END_TEXT_COMPONENT();
}

//Draw text function
void drawText(char *text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, int position, bool outline)
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

	UI::_SET_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);

	UI::_DRAW_TEXT(x, y);
}

//Draw sprite function
void drawSprite(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);

	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
	{
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
	}
}
//draw help text/ top left notification
void DisplayHelpTextThisFrame(char* text)
{
	UI::_SET_TEXT_COMPONENT_FORMAT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_DISPLAY_HELP_TEXT_FROM_STRING_LABEL(0, 0, 1, -1);
}
//Draw layered sprite
void drawSpriteLayer(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a, int layer)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);

	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
	{
		GRAPHICS::_SET_2D_LAYER(layer);
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
	}
}

//Play sound function
void PlayFrontendSound(char* sound)
{
	if (menuSounds)
		AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}

//Adds the title of a submenu
void AddTitle(char *title)
{
//	drawGlare(0.827f, 0.1410f, 0.190f, 0.034f, 255, 255, 255);

	drawText("Gradient premium", 1, 0.827f, 0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);
	drawText(title, 0, secondTitleX, secondTitleY, 0.35f, 0.35f, secondTitleRed, secondTitleGreen, secondTitleBlue, secondTitleOpacity, FALSE, FALSE);
}

//Adds a title with a certain colour
void AddTitleColour(char *title, int red, int green, int blue)
{
	drawText("TEST 277", 1, 0.827f, 0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, true, false);
	drawText(title, 0, secondTitleX, secondTitleY, 0.35f, 0.35f, red, green, blue, secondTitleOpacity, false, false);
}
void AddWeaponTitle(char *title)
{
	//	drawGlare(0.827f, 0.1410f, 0.190f, 0.034f, 255, 255, 255);
	drawSprite("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.827f, 0.06f, 0.225f, 0.09f, 0, 255, 255, 255, bannerRect.A);

	drawText("Gradient", 1, 0.827f, 0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);
	drawText(title, 0, secondTitleX, secondTitleY, 0.35f, 0.35f, secondTitleRed, secondTitleGreen, secondTitleBlue, secondTitleOpacity, FALSE, FALSE);
}
void AddVehicleTitle(char *title)
{
	//	drawGlare(0.827f, 0.1410f, 0.190f, 0.034f, 255, 255, 255);
	drawSprite("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.827f, 0.06f, 0.225f, 0.09f, 0, 255, 255, 255, bannerRect.A);

	drawText("Gradient", 1, 0.827f, 0.036f, 0.77f, 0.77f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, TRUE, FALSE);
	drawText(title, 0, secondTitleX, secondTitleY, 0.35f, 0.35f, secondTitleRed, secondTitleGreen, secondTitleBlue, secondTitleOpacity, FALSE, FALSE);
}
//Overloads of AddOption to simplify
void AddOption(char *option, char *info = NULL)
{
	optionTextToAdd = option;
	optionCount++;

	//Changes color when you highlight a certain option.
	if (currentOption == optionCount) {

		infoText = info;

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(optionTextToAdd, optionsFont, mainTextX - 0.108f, (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, optionsOpacity, optionCenter, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(optionTextToAdd, optionsFont, mainTextX - 0.108f, ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, optionsOpacity, optionCenter, false);
	}

	//Makes other options the colour, that you choose.
	else {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(optionTextToAdd, optionsFont, mainTextX - 0.108f, (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, optionCenter, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(optionTextToAdd, optionsFont, mainTextX - 0.108f, ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, optionCenter, false);

	}
}
//Adds a submenu
void AddSubmenu(char *option, int submenu, char *info = NULL)
{
	

	
	char buf[30];
	snprintf(buf, sizeof(buf), "%s~h~ ~m~>", option);
	AddOption(buf, info);

	if (currentOption == optionCount && GetAsyncKeyState(VK_NUMPAD5) & 1) {
		PlayFrontendSound("SELECT");
		changeSubmenu(submenu);
	}

}


	

//AddOption to show certain string
void AddOption(char *option, char* string, char *info)
{
	//Use of our overload to simplify
	AddOption(option, info);

	if (currentOption == optionCount) {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(string, optionsFont, (0.108f + (XValue)), (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, 255, 2, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(string, optionsFont, (0.108f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, highlightRed, highlightGreen, highlightBlue, 255, 2, false);

	}

	else {

		if (currentOption <= maxOptions && optionCount <= maxOptions)
			drawText(string, optionsFont, (0.108f + (XValue)), (optionCount * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, 2, false);

		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
			drawText(string, optionsFont, (0.108f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY), 0.35f, 0.35f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, 2, false);

	}
}

//Our main AddOption function
void AddOption(char *option, std::function<void()> function, char *info = NULL)
{
	AddOption(option, info);

	//Checks if NUMPAD5 has been pressed and excecutes certain code.
	if (currentOption == optionCount && GetAsyncKeyState(VK_NUMPAD5) & 1) {
		function();
		PlayFrontendSound("SELECT");
	}

}
void addrpOption(char *option, int value, char *info = NULL)
{
	AddOption(option, info);
	if (currentOption == optionCount && GetAsyncKeyState(VK_NUMPAD5) & 1) {
		{
			STATS::STAT_SET_INT($("MP0_CHAR_XP_FM"), value, true);
			STATS::STAT_SET_INT($("MP1_CHAR_XP_FM"), value, true);
			STATS::STAT_SET_INT($("MP2_CHAR_XP_FM"), value, true);
		}
	}
}
void addBoolOption(char* option, bool b00l, char *info = NULL)
{

	char buf[30];
	if (b00l)
	{
		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}

		else {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}
		AddOption(option, info);
	}
	else
	{
		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}

		else {
			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}		AddOption(option, info);
	}

}
//Our AddToggle option for looped stuff
void AddToggle(char *option, bool* boolean, char *info = NULL)
{
	//Use of overloads once again
	AddOption(option, info);

	//If NUMPAD5 is pressed it changes the bool to On/Off
	if (currentOption == optionCount && GetAsyncKeyState(VK_NUMPAD5) & 1) {
		PlayFrontendSound("SELECT");
		*(bool*)boolean = !*(bool*)boolean;
	}

	//Here we are going to use sprites as our On/Off indicators. You can change this to text, if you feel like it.
	if (*(bool*)boolean) {

		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}

		else {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}
	}

	else {

		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}

		else {
			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
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
void AddToggle(char *option, bool boolean, std::function<void()> function, char *info = NULL)
{
	//Use of overloads once again
	AddOption(option, info);

	//If NUMPAD5 is pressed it executes function, bool indicator uses passive bool
	if (currentOption == optionCount && GetAsyncKeyState(VK_NUMPAD5) & 1) {
		function();
		PlayFrontendSound("SELECT");
	}

	//Here we are going to use sprites as our On/Off indicators. You can change this to text, if you feel like it.
	if (boolean) {

		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}

		else {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 0, 255, 0, 255, 2);
		}
	}

	else {

		if (currentOption == optionCount) {

			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}

		else {
			if (currentOption <= maxOptions && optionCount <= maxOptions)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), (optionCount * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);

			else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
				drawSpriteLayer("commonmenu", "common_medal", (0.1015f + (XValue)), ((optionCount - (currentOption - maxOptions)) * 0.035f + mainTextY) + checkboxY, 0.015f, 0.025f, 0, 255, 0, 0, 255, 2);
		}
	}
}

//Our int changer
void AddInt(char *option, int *inttochange, int min, int max, int increments, char *info = NULL)
{
	char buf[30];

	snprintf(buf, sizeof(buf), "[%i]", *inttochange);

	AddOption(option, buf, info);

	if (currentOption == optionCount) {

		if (GetAsyncKeyState(VK_NUMPAD6) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange >= max)
				*inttochange = min;

			else
				*inttochange = *inttochange + increments;
		}

		else if (GetAsyncKeyState(VK_NUMPAD4) & 1) {
			PlayFrontendSound("NAV_UP_DOWN");

			if (*inttochange <= min)
				*inttochange = max;

			else
				*inttochange = *inttochange - increments;
		}
	}
}

//Our float changer
void AddFloat(char* option, float *floattochange, float min, float max, float increments, char *info = NULL)
{
	char buf[30];
	sprintf(buf, "[%g]", *floattochange);

	AddOption(option, buf, info);
	if (currentOption == optionCount) {
		if (GetAsyncKeyState(VK_NUMPAD6) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");
			if (*floattochange >= max)
				*floattochange = min;
			else
				*floattochange = *floattochange + increments;

		}

		else if (GetAsyncKeyState(VK_NUMPAD4) & 1) {

			PlayFrontendSound("NAV_UP_DOWN");
			if (*floattochange <= min)
				*floattochange = max;
			else
				*floattochange = *floattochange - increments;
		}
	}
}

//Our string selector function whatever
void AddString(char *optiontext, char* option, int *var, int min, int max, char *info = NULL)
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
	}
}

//Our string selector function whatever with execution
void AddString(char *optiontext, char* option, int *var, int min, int max, std::function<void()> callback, char *info = NULL)
{
	AddString(optiontext, option, var, min, max, info);
	if (currentOption == optionCount && (GetAsyncKeyState(VK_NUMPAD4) || GetAsyncKeyState(VK_NUMPAD6)) & 1)
		callback();
}

bool friendCheck(Player player) {
	if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(player)) {
		int handle;
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle, 13);
		return NETWORK::NETWORK_IS_FRIEND(&handle);
	}
	return false;
}

/*void AddString(char *optiontext, char* option, int *var, int min, int max, std::function<void()> function, char *info = NULL)
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
	if (GetAsyncKeyState(VK_NUMPAD5) & 1)
		return currentOption;
	else return 0;
}

//Draws our header
void drawHeader()
{
	//if (gradients)
	//thia titlw only works wright with the custom openIV texture
		drawSprite("commonmenu", "interaction_bgd", 0.827f, 0.06f, 0.225f, 0.09f, 0, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A);
	//else
	//	GRAPHICS::DRAW_RECT(0.827f, 0.06f, 0.225f, 0.09f, bannerRect.R, bannerRect.G, bannerRect.B, bannerRect.A);
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

//Disable our controls, whenever menu is up (optional)
void DisableControls()
{
	
}

//Draws our background
void DrawBackground()
{
	if (optionCount > maxOptions) {

		//Sets the layer of the background, so our sprites can go on top
		GRAPHICS::_SET_2D_LAYER(1);
		//Background
		GRAPHICS::DRAW_RECT(MainBackGroundX, (((maxOptions * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (maxOptions * 0.035f), background.R, background.G, background.B, background.A);

		//Scroller
		if (currentOption > maxOptions) {
			GRAPHICS::_SET_2D_LAYER(1);
			if (gradients)
				drawSprite("commonmenu", "gradient_nav", scrollerX, ((maxOptions * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
			else
				GRAPHICS::DRAW_RECT(scrollerX, ((maxOptions * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);
		}
		else {
			GRAPHICS::_SET_2D_LAYER(1);
			if (gradients)
				drawSprite("commonmenu", "gradient_nav", scrollerX, ((currentOption * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
			else
				GRAPHICS::DRAW_RECT(scrollerX, ((currentOption * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);
		}

		//Bar under header
		GRAPHICS::DRAW_RECT(BarUnderHeaderX, BarUnderHeaderY, 0.225f, BarUnderHeaderHeight, 0, 0, 0, 255);

		//Bar above infobox
	//	if (gradients)
		//	drawSprite("CommonMenu", "interaction_bgd", BarUnderHeaderX, (((maxOptions + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, 0, bannerRect.R, bannerRect.G, bannerRect.B, 255);
	//	else
		//	GRAPHICS::DRAW_RECT(BarUnderHeaderX, (((maxOptions + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, bannerRect.R, bannerRect.G, bannerRect.B, 255);

	}

	else {

		//Set layer
		GRAPHICS::_SET_2D_LAYER(1);
		//Background
		GRAPHICS::DRAW_RECT(MainBackGroundX, (((optionCount * 0.035f) / 2) + MainBackGroundY), MainBackGroundWidth, (optionCount * 0.035f), background.R, background.G, background.B, background.A);

		//Scroller
		GRAPHICS::_SET_2D_LAYER(1);
		if (gradients)
			drawSprite("commonmenu", "gradient_nav", scrollerX, ((currentOption * 0.035f) + scrollerY), 0.225f, 0.035f, 0, 255, 255, 255, 255);
		else
			GRAPHICS::DRAW_RECT(scrollerX, ((currentOption * 0.035f) + scrollerY), MainBackGroundWidth, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity);

		//Bar under header
		GRAPHICS::DRAW_RECT(BarUnderHeaderX, BarUnderHeaderY, 0.225f, BarUnderHeaderHeight, 0, 0, 0, 255);

		//Bar above infobox
	//	if (gradients)
		//	drawSprite("CommonMenu", "interaction_bgd", BarUnderHeaderX, (((optionCount + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, 0, bannerRect.R, bannerRect.G, bannerRect.B, 255);
		//else
		//	GRAPHICS::DRAW_RECT(BarUnderHeaderX, (((optionCount + 1) * 0.035f) + BarAboveInfoY), 0.225f, BarAboveInfoHeight, bannerRect.R, bannerRect.G, bannerRect.B, 255);

	}

	//Our infobox
	if (optionCount > maxOptions)
	{
		drawText(infoText, optionsFont, infoBoxTextX, ((maxOptions + 1) * 0.035f + infoBoxTextY), 0.3f, 0.3f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE, FALSE);
		GRAPHICS::DRAW_RECT(infoBoxX, (((maxOptions + 1) * 0.035f) + infoBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A); //Info Box
	}
	else
	{
		drawText(infoText, optionsFont, infoBoxTextX, ((optionCount + 1) * 0.035f + infoBoxTextY), 0.3f, 0.3f, bannerText.R, bannerText.G, bannerText.B, bannerText.A, FALSE, FALSE);
		GRAPHICS::DRAW_RECT(infoBoxX, (((optionCount + 1) * 0.035f) + infoBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A); //Info Box
	}

	//arrow up down
	if (optionCount > maxOptions) {
		GRAPHICS::DRAW_RECT(infoBoxX, (((maxOptions + 1) * 0.035f) + arrowupdownBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A); //Info Box

		if (currentOption == 1) {
			drawSprite("commonmenu", "arrowright", infoBoxX, ((maxOptions + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", infoBoxX, ((maxOptions + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
		}
		else if (currentOption == optionCount) {
			drawSprite("commonmenu", "arrowright", infoBoxX, ((maxOptions + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", infoBoxX, ((maxOptions + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);

		}
		else {
			drawSprite("commonmenu", "arrowright", infoBoxX, ((maxOptions + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", infoBoxX, ((maxOptions + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
		}
	}
	else
	{
	
		GRAPHICS::DRAW_RECT(infoBoxX, (((optionCount + 1) * 0.035f) + arrowupdownBoxY), 0.225f, 0.035f, background.R, background.G, background.B, background.A); //Info Box

		if (currentOption == 1 && optionCount > 1) {
			drawSprite("commonmenu", "arrowright", infoBoxX, ((optionCount + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", infoBoxX, ((optionCount + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
		}
		else if (currentOption == optionCount && optionCount > 1) {
			drawSprite("commonmenu", "arrowright", infoBoxX, ((optionCount + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", infoBoxX, ((optionCount + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);

		}
		else if (optionCount > 1) {
			drawSprite("commonmenu", "arrowright", infoBoxX, ((optionCount + 1) * 0.035f + arrowupdownBoxY), 0.02f, 0.02f, 270, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
			drawSprite("commonmenu", "arrowright", infoBoxX, ((optionCount + 1) * 0.035f + arrowupdownBoxY2), 0.02f, 0.02f, 90, bannerText.R, bannerText.G, bannerText.B, bannerText.A);
		}
	}
}

//Our option counter, credits to Mafins.
void optionCounter()
{
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_SCALE(0.35f, 0.35f);
	UI::_SET_TEXT_ENTRY("CM_ITEM_COUNT");
	UI::ADD_TEXT_COMPONENT_INTEGER(currentOption);
	UI::ADD_TEXT_COMPONENT_INTEGER(optionCount);

	//Checks whether option count is bigger than 10
	if (optionCount > maxOptions - 5)
		UI::_DRAW_TEXT(CounterX - 0.006f, CounterY);
	//If not draw normally
	else
		UI::_DRAW_TEXT(CounterX, CounterY);
}

//Monitors our menu, while it is open
void OpenMonitor()
{

	optionCounter();
	DrawBackground();
	DisableControls();

	if (GetAsyncKeyState(VK_NUMPAD8) & 1) {

		PlayFrontendSound("NAV_UP_DOWN");
		currentOption--;

		if (currentOption < 1)
			currentOption = optionCount;

	}

	else if (GetAsyncKeyState(VK_NUMPAD2) & 1) {

		PlayFrontendSound("NAV_UP_DOWN");
		currentOption++;

		if (currentOption > optionCount)
			currentOption = 1;

	}

	else if (GetAsyncKeyState(VK_NUMPAD0) & 1) {

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

}

//Monitors our menu, whenever it is closed
void ClosedMonitor()
{
	if (GetAsyncKeyState(VK_MULTIPLY) & 1) {

		PlayFrontendSound("SELECT");
		is_user_authed();
			submenu = SUB::MAINMENU;
			submenuLevel = 0;
			currentOption = 1;
		
	}
}




void main() {
	while (true) {
		WAIT(0);
		static bool first_time = false;
		if (!first_time)
		{
			Features();
		}
		if (submenu != SUB::CLOSED) {
			OpenMonitor();
			ResetVars();
			submenuHandler();
		}

		else ClosedMonitor();
	}
}