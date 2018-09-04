#pragma once
#pragma once

///////////////////////
//menu bools
int submenu = 0;
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];
bool showCoords;
bool showInfos;
bool newTimerTick = true;
int maxTimerCount;
int currentOption;
int optionCount;
bool optionPress = false;
int selectedPlayer;
bool test = false;

float titlex = 0.845f;
float titlebox = 0.845f;// original

float menutext = 0.745f;
float backx = 0.845f;
bool centerd = false;
int width = 30;


int titleTextRed = 255;
int titleTextGreen = 255;
int titleTextBlue = 255;
int titleTextOpacity = 255;
/////////////////////////////
int menutextcolor[4] = { titleTextRed, titleTextGreen, titleTextBlue, titleTextOpacity };
int titleTextFont = 1;
int titleRectRed = 20;
int titleRectGreen = 20;
int titleRectBlue = 20;
int titleRectOpacity = 255;//
						   /////////////////////////
int backgroundRed = 15;
int backgroundGreen = 15;
int backgroundBlue = 15;
int backgroundOpacity = 220;
////////////////////////////////
int optionsRed = 255;
int optionsGreen = 255;
int optionsBlue = 255;
int optionsOpacity = 255;
int optionsFont = 6;
/////////////////////////////
int scrollerRed = 220;
int scrollerGreen = 220;
int scrollerBlue = 220;
int scrollerOpacity = 190;
/////////////////////////////
int highlightRed = 49;
int highlightGreen = 65;
int highlightBlue = 185;
int highlightOpacity = 255;
//////////////////////////////
int indicatorRed = 255;//
int indicatorGreen = 44;//
int indicatorBlue = 55;
int indicatorOpacity = 255;
///////////////////////////////




#pragma region Option Helpers


void drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_DRAW_TEXT(x, y);
}
void changeSubmenu(int newSubmenu)
{
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}
void SetupTimer(int tickTime)
{
	if (newTimerTick) {
		maxTimerCount = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick = false;
	}
}
bool IsTimerReady()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount;
}
void ResetTimer()
{
	newTimerTick = true;
}


//////////////////////////////////
void DRAW_TEXTURE(string Streamedtexture, string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void drawRect(float x, float y, float width, float height, int r,int g, int b, int a) {
	GRAPHICS::DRAW_RECT(x, y, width, height, r, g, b, a);
};
char * StringToChar(std::string string)
{
	return _strdup(string.c_str());
}
void normalMenuActions()
{


	if (optionCount > 16)
	{
		GRAPHICS::DRAW_RECT(backx, (((16 * 0.035f) / 2) + 0.159f), 0.25f, (16 * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
		if (currentOption > 16)
		{
			GRAPHICS::DRAW_RECT(backx, ((16 * 0.035f) + 0.1415f), 0.25f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller

			GRAPHICS::DRAW_RECT(backx, 0.156f, 0.23f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Up Indicator
		}
		else
		{
			GRAPHICS::DRAW_RECT(backx, ((currentOption * 0.035f) + 0.1415f), 0.25f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller

			GRAPHICS::DRAW_RECT(backx, 0.156f, 0.23f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Up Indicator
		}
		if (currentOption != optionCount)
		{
			GRAPHICS::DRAW_RECT(backx, 0.721f, 0.25f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Down Indicator
		}
	}
	else
	{
		GRAPHICS::DRAW_RECT(backx, (((optionCount * 0.035f) / 2) + 0.159f), 0.25f, (optionCount * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background

		GRAPHICS::DRAW_RECT(backx, ((currentOption * 0.035f) + 0.1415f), 0.25f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
	}
	
	/*	if (optionCount > 16)
		{
			drawText(StringToChar(std::to_string(currentOption) + "/" + std::to_string(optionCount)),6, backx - 0.1f, (17 * 0.035f + 0.125f), 0.5f, 0.5f, titleTextRed, titleTextGreen, titleTextBlue, titleTextOpacity, false);
			drawRect(backx, (17 * 0.035f + 0.1415f), 0.23f, 0.035f, backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity);
		}
		else
		{
			drawText(StringToChar(std::to_string(currentOption) + "/" + std::to_string(optionCount)),6, backx - 0.1f, ((optionCount + 1) * 0.035f + 0.125f), 0.5f, 0.5f, titleTextRed, titleTextGreen, titleTextBlue, titleTextOpacity, false);
			drawRect(backx, ((optionCount + 1) * 0.035f + 0.1415f), 0.23f, 0.035f, backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity);
		}*/
	float CountX = 0.958f;
	float CountY = 0.130f;
	float CountScale = 0.300f;
	char buf[30];
	snprintf(buf, sizeof(buf), "%i / %i", currentOption, optionCount);
	drawText(buf, 0, CountX, CountY, CountScale, CountScale, 255, 255, 255, 255, 2);
}

void addTitle(char *title)
{
	drawText("The Gradient Project", titleTextFont, titlex, /*0.09f original */0.040f, 0.75f, 0.75f, titleTextRed, titleTextGreen, titleTextBlue, titleTextOpacity, true);
	drawText(title, 7, /*0.845 original X*/ 0.800, 0.132f, 0.50f, 0.40f, titleTextRed, titleTextGreen, titleTextBlue, titleTextOpacity, true);
	DRAW_TEXTURE("CommonMenu", "interaction_bgd", titlebox, /*0.1175f original*/0.080f, 0.25f, 0.085f, 180, indicatorRed, indicatorGreen, indicatorBlue, 255);
	//void drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
	//DRAW_TEXTURE(string Streamedtexture, string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
//	DRAW_TEXTURE("CommonMenu", "interaction_bgd", titlebox, 0.1175f, 0.25f, 0.085f, 180, indicatorRed, indicatorGreen, indicatorBlue, 255);//gradient blue rect
	float BarUnderHeaderX = 0.845f;
	float BarUnderHeaderY = 0.145f;
	float BarUnderHeaderHeight = 0.032f;
	GRAPHICS::DRAW_RECT(BarUnderHeaderX, BarUnderHeaderY, 0.25f, BarUnderHeaderHeight, 0, 0, 0, 255);
	normalMenuActions();
}

void addOption(char *option)
{
	optionCount++;
	if (currentOption <= 16 && optionCount <= 16)
		drawText(option, optionsFont, menutext, (optionCount * 0.035f + 0.125f), 0.5f, 0.5f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, centerd);

	else if ((optionCount > (currentOption - 16)) && optionCount <= currentOption)
		drawText(option, optionsFont, menutext, ((optionCount - (currentOption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, centerd);
}



#include <functional>
bool addOptionBool(char * option, std::function<void()> function)
{
	addOption(option);

	if (optionCount == currentOption && optionPress) {
		function();
		return true;
	}
	return false;
}
bool addOption(char * option, std::function<void()> function)
{
	addOption(option);

	if (optionCount == currentOption && optionPress) {
		function();
		return true;
	}
	return false;
}


bool rightPress = false;
bool leftPress = false;
void addIntOption(char *option, int *var, int min, int max)
{
	char buf[100];
	_snprintf(buf, sizeof(buf), "%s < %i >", option, *var);
	addOption(buf);
	if (currentOption == optionCount)
	{
		if (rightPress)
		{
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
			rightPress = false;
		}
		else if (leftPress)
		{
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
			leftPress = false;
		}
	}
}

void addFloatOption(char *option, float var, float min, float max)
{
	char buf[100];
	_snprintf(buf, sizeof(buf), "%s < %i >", option, var);
	addOption(buf);
	if (currentOption == optionCount)
	{
		if (rightPress)
		{
			if (var >= max)
				var = min;
			else
				var = var + 1;
			rightPress = false;
		}
		else if (leftPress)
		{
			if (var <= min)
				var = max;
			else
				var = var - 1;
			leftPress = false;
		}
	}
}
bool rightPress1 = false;
bool leftPress1 = false;
void addArrayOption(char *test, int *var, int min, int max)
{//var = pointer to array
	addOption(test);
	if (currentOption == optionCount)
	{
		if (rightPress1)
		{
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
			rightPress1 = false;
		}
		else if (leftPress1)
		{
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
			leftPress1 = false;
		}
	}
}

int getOptionint()
{
	return currentOption;
}


void addSubmenuOption(char *option, int newSubmenu)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s~p~ >>", option);
	addOption(buf);
	if (currentOption == optionCount && optionPress)
		changeSubmenu(newSubmenu);
}


void addTPOption(char *option, float xPos, float yPos, float zPos)
{
	Entity e = PLAYER::PLAYER_PED_ID();

	addOption(option);
	if (currentOption == optionCount && optionPress & 1)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
			e = PED::GET_VEHICLE_PED_IS_USING(e);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, xPos, yPos, zPos, 1, 1, 1);
	}
}

void End()
{

}
int getOption()
{
	if (optionPress)
	{
		return currentOption;
	}
	else return 0;
}

bool getKeyPressed(int key) {
	return (GetAsyncKeyState(key) & 0xFFFF) == 0x8001;
}

char* SoundToPlay;
char* SoundSetToPlay;
bool PlaySounds;

void PlaySoundz(char* SoundName, char* SoundSetName)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, SoundName, SoundSetName, 1);
}

void authuser()
{

	bool is_user_authed();
	notifyMap("Welcome To Gradient Premium", false);
	notifyMap("Beta v6", false);
	notifyMap("Made by Sinfool#2522", false);

}


int DelayCounter = GetTickCount();
bool firstopenmenu = false;
void monitorButtons()
{
	if (GetTickCount() - DelayCounter > 150)
	{
		if (submenu == 0)
		{
			VMProtectBegin("Auth_fuck_me_crispy_f8");

			if (getKeyPressed(VK_F8) && submenu == 0)
			{
				//auth
				static bool first_time = false;
				if (!first_time)
				{
				//	authuser();
					first_time = true;
				}
				DelayCounter = GetTickCount();
				submenu = 1;
				submenuLevel = 0;
				currentOption = 1;
				SoundToPlay = "FLIGHT_SCHOOL_LESSON_PASSED";
				SoundSetToPlay = "HUD_AWARDS";
				PlaySounds = true;
			}
			ResetTimer();
			VMProtectEnd();

		}
		else {

			if (getKeyPressed(VK_NUMPAD0) && submenu != 0)//exit
			{
				DelayCounter = GetTickCount();
				if (submenu == 1)
				{
					submenu = 0;
				}
				else {
					submenu = lastSubmenu[submenuLevel - 1];
					currentOption = lastOption[submenuLevel - 1];
					submenuLevel--;
				}
				SoundToPlay = "BACK";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD5) && submenu != 0)//option select
			{
				DelayCounter = GetTickCount();
				optionPress = true;
				SoundToPlay = "SELECT";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD8) && submenu != 0)//up
			{
				DelayCounter = GetTickCount();

				currentOption--;
				currentOption = currentOption < 1 ? optionCount : currentOption;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD2) && submenu != 0)//down
			{
				DelayCounter = GetTickCount();
				currentOption++;
				currentOption = currentOption > optionCount ? 1 : currentOption;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD4))//down
			{
				leftPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD6))//down
			{
				rightPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
		}
	}
}


void addBoolOption(char* option, bool b00l, char* text = "", bool meg = false)
{
	
	char buf[30];
	if (b00l)
	{
		_snprintf(buf, sizeof(buf), "%s ~b~ENABLED", option);
		addOption(buf);
	}
	else
	{
		_snprintf(buf, sizeof(buf), "%s ~r~DISABLED", option);
		addOption(buf);
	}
}

void addNotifyOption(char *option, char *notification)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
	}
}

void addrpOption(char *option, int value, char *info)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		STATS::STAT_SET_INT($("MP0_CHAR_XP_FM"), value, true);
		STATS::STAT_SET_INT($("MP1_CHAR_XP_FM"), value, true);
		STATS::STAT_SET_INT($("MP2_CHAR_XP_FM"), value, true);
	}
}


void MenuRun()
{
	monitorButtons();
	optionPress = false;
}


int Messages = 0;
bool SpawnedPedHasGodmode[20];
