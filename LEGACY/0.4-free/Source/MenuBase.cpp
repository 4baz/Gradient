#include "stdafx.h"

float menux = 0.2f;
rgba titleText = { 255, 255, 255, 255 };
rgba SecTitle = { 255, 255, 255, 255 };
rgba titleRect = { 244, 14, 67, 225 };
rgba titleRect2 = { 0,0,0,255 };
rgba scroller = { 255, 255, 255, 200 };
rgba options = { 255, 255, 255, 255 };
rgba optionsrect = { 0,0,0, 100 };
rgba endmenu = { 0, 0, 0,100 };
rgba selectedOption = { 0,0,0,255 };
rgba boder = { 235,235,235,100 };
rgba BoolColor1 = { 255,255,255,255 };
rgba BoolColor2 = { 0,0,0,255 };

int optioncount;
int currentoption;
bool optionpress = false;
bool leftpress = false;
bool rightpress = false;
bool uppress = false;
bool downpress = false;

char* currentmenu[100];
char* actualmenu = "";
int lastoption[100];
int menulevel = 0;
int infocount;
int Delay = GetTickCount();

float x = 0.0f,
y = 0.0f,
width = 0.f,
height = 0.f,
percent = 1.0f;

int weaponnum = 0;

char* test;

int Menu::getKeyPressed(int key) {
	return GetAsyncKeyState(key);
}

char* Menu::StringToChar(std::string string) {
	return _strdup(string.c_str());
}

bool Menu::currentMenu(char* menuname) {
	if (menuname == actualmenu) return true;
	else return false;
}

void Menu::changeMenu(char* menuname) {
	currentmenu[menulevel] = actualmenu;
	lastoption[menulevel] = currentoption;
	menulevel++;
	actualmenu = menuname;
	currentoption = 1;
}

void Menu::backMenu() {
	menulevel--;
	actualmenu = currentmenu[menulevel];
	currentoption = lastoption[menulevel];
}

void Menu::drawText(char* text, int font, float x, float y, float scalex, float scaley, rgba rgba, bool center) {
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgba.r, rgba.g, rgba.b, rgba.a);
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
};

void Menu::drawNotification(char* msg) {
	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
};

void Menu::drawRect(float x, float y, float width, float height, rgba rgba) {
	GRAPHICS::DRAW_RECT(x, y, width, height, rgba.r, rgba.g, rgba.b, rgba.a);
};

void Menu::drawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, rgba rgba)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);		
	else
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, rgba.r, rgba.g, rgba.b, rgba.a);
};




void Menu::Title(char* title) {
	optioncount = 0;
	drawText(title, 6, menux, 0.095f - 0.02f, 0.90f, 0.90f, titleText, true);
	drawText("http://gradienthacks.com/", 6, menux , 0.095f+0.024f, 0.40f, 0.40f, SecTitle, true);
	drawSprite("CommonMenu","interaction_bgd", menux, 0.1175f, 0.23f, 0.085f, 0.0f, titleRect);

	/*drawRect(menux - 0.116f, 0.116f, 0.002f, 0.085f, boder);//×ó²à±ß¿ò
	drawRect(menux + 0.116f, 0.116f, 0.002f, 0.085f, boder);//ÓÒ²à±ß¿òÉè¼Æ
	drawRect(menux, 0.0745f, 0.230f, 0.004f, boder);//¶¥²¿±ß¿ò*/

	
};



bool Menu::Option(char* option,char* des) {
	optioncount++;
	test = des;
	bool thisOption = false;
	if (currentoption == optioncount) thisOption = true;

	if (currentoption <= 16 && optioncount <= 16)
	{		
		drawText(option, 6, menux - 0.1f+x, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, false);
		drawRect(menux, ((optioncount * 0.035f) + 0.1415f), 0.23f, 0.035f, optionsrect);//main RECT

		/*drawRect(menux - 0.116f, ((optioncount ) * 0.035f + 0.1416f), 0.002f, 0.035f, boder);//×ó²à±ß¿ò
		drawRect(menux + 0.23f - 0.114f, ((optioncount) * 0.035f + 0.1416f), 0.002f, 0.035f, boder);//ÓÒ²à±ß¿òÉè¼Æ*/

		if (thisOption) {
		//drawSprite("ps_menu", "mp_main_gradient", menux, ((optioncount * 0.035f) + 0.1415f), 0.412f, 0.035f, 270, scroller);
			drawText(option, 6, menux - 0.1f+x, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, BoolColor2, false);
			drawRect(menux, ((optioncount * 0.035f) + 0.1415f), 0.23f, 0.035f, scroller);
		}
	}

	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
	{
		drawText(option, 6, menux - 0.1f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, false);
		drawRect(menux, ((optioncount - (currentoption - 16)) * 0.035f + 0.1415f), 0.23f, 0.035f, optionsrect);
		/*drawRect(menux - 0.116f, ((optioncount - (currentoption - 16)) * 0.035f + 0.1416f), 0.002f, 0.035f, boder);//×ó²à±ß¿ò
		drawRect(menux + 0.23f - 0.114f, ((optioncount - (currentoption - 16)) * 0.035f + 0.1416f), 0.002f, 0.035f, boder);//ÓÒ²à±ß¿òÉè¼Æ*/
		if (thisOption)
		{//drawSprite("timebars", "all_white_bg", menux,((optioncount * 0.035f) + 0.1415f), 0.23f, 0.035f, 0, scroller);
			drawSprite("ps_menu", "mp_main_gradient", menux, (((optioncount - (currentoption - 16)) * 0.035f) + 0.1415f), 0.412f, 0.035f, 270, scroller);
			//drawRect(menux, ((optioncount - (currentoption - 16)) * 0.035f + 0.1415f), 0.23f, 0.035f, scroller);
		}
	}

	if (optionpress && currentoption == optioncount) return true;
	else return false;
};

bool Menu::MenuOption(char* option, char* menu) {
	Option(option);

	if (currentoption <= 16 && optioncount <= 16)
		//drawSprite("golfputting", "puttingmarker", menux + 0.068f, (optioncount * 0.035f + 0.143f), 0.02f, 0.02f,270, options);
		drawText("", 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
		//drawSprite("golfputting", "puttingmarker", menux + 0.068f, (optioncount * 0.035f + 0.143f), 0.02f, 0.02f,270, options);
		drawText("", 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);

	if (optionpress && currentoption == optioncount) {
		optionpress = false;
		changeMenu(menu);
		return true;
	}
	else return false;
}

bool Menu::IntOption(char* option, int *var, int min, int max, int step) {
	Option(option);

	if (currentoption <= 16 && optioncount <= 16)
		drawText(StringToChar("<" + std::to_string(*var) + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
		drawText(StringToChar("<" + std::to_string(*var) + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);

	if (currentoption == optioncount) {
		if (leftpress) {
			if (*var <= min) *var = max;
			else *var -= step;
			leftpress = false;
			return true;
		}
		if (*var < min) *var = max;
		if (rightpress) {
			if (*var >= max) *var = min;
			else *var += step;
			rightpress = false;
			return true;
		}
		if (*var > max) *var = min;
	}

	if (optionpress && currentoption == optioncount)
		return true;
	else return false;
}

bool Menu::FloatOption(char* option, float *var, float min, float max, float step) {
	Option(option);



	char buf[100];
	_snprintf_s(buf, sizeof(buf), "%.4f", *var);

	if (currentoption <= 16 && optioncount <= 16)
		drawText(StringToChar("<" + (std::string)buf + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
		drawText(StringToChar("<" + (std::string)buf + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);

	if (currentoption == optioncount) 
	{
		if (leftpress) {
			if (*var <= min) *var = max;
			else *var -= step;
			leftpress = false;
			return true;
		}
		if (*var < min) *var = max;

		if (rightpress) {
			if (*var >= max) *var = min;
			else *var += step;
			rightpress = false;
			return true;
		}
		if (*var > max) *var = min;
	}

	if (optionpress && currentoption == optioncount)
		return true;
	else return false;
}

bool Menu::BoolOption(char* option, bool *b00l) {
	Option(option);
	if (currentoption <= 16 && optioncount <= 16)
		//drawSprite("pilotschool", "medaldot_32", menux + 0.068f, (optioncount * 0.035f + 0.143f), 0.01f, 0.01f, 0, *b00l?BoolColor1: BoolColor2);
		drawSprite("commonmenu", *b00l ? "shop_box_tick" :"shop_box_blank",menux + 0.068f, (optioncount * 0.035f + 0.143f), 0.03f, 0.05f, 0, options);//Æ«ÉÏ
	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
		drawSprite("commonmenu", *b00l ? "shop_box_tick" : "shop_box_blank",menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.143f), 0.03f, 0.05f, 0, options);
	if (optionpress && currentoption == optioncount) {
		*b00l ^= 1;
		return true;
	}
	else return false;
}

bool Menu::BoolSpriteOption(char* option, bool b00l, char* category, char* spriteOn, char* spriteOff) {
	Option(option);

	if (currentoption <= 16 && optioncount <= 16)
		drawSprite(category, b00l ? spriteOn : spriteOff,
			menux + 0.068f, (optioncount * 0.035f + 0.141f), 0.03f, 0.05f, 0, options);
	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)	
		drawSprite(category, b00l ? spriteOn : spriteOff,
			menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.141f), 0.03f, 0.05f, 0, options);

	if (optionpress && currentoption == optioncount) return true;
	else return false;
}

bool Menu::IntArray(char* option, int display[], int *PlaceHolderInt) {
	Option(option);

	int min = 0;
	int max = sizeof(display) / sizeof(*display);

	if (currentoption == optioncount) {
		if (leftpress) {
			if (*PlaceHolderInt <= min) *PlaceHolderInt = max;
			else PlaceHolderInt -= 1;
			leftpress = false;
			return true;
		}
		if (*PlaceHolderInt < min) *PlaceHolderInt = max;
		if (rightpress) {
			if (*PlaceHolderInt >= max) *PlaceHolderInt = min;
			else *PlaceHolderInt += 1;
			rightpress = false;
			return true;
		}
		if (*PlaceHolderInt > max) *PlaceHolderInt = min;
	}
	if (currentoption <= 16 && optioncount <= 16)
		drawText(StringToChar("<" + std::to_string(display[*PlaceHolderInt]) + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
		drawText(StringToChar("<" + std::to_string(display[*PlaceHolderInt]) + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
	if (optionpress && currentoption == optioncount)
		return true;
	else return false;
}

bool Menu::FloatArray(char* option, float display[], int *PlaceHolderInt) {
	Option(option);

	int min = 0;
	int max = sizeof(display) / sizeof(*display);

	if (currentoption == optioncount) {
		if (leftpress) {
			if (*PlaceHolderInt <= min) *PlaceHolderInt = max;
			else *PlaceHolderInt -= 1;
			leftpress = false;
			return true;
		}
		if (*PlaceHolderInt < min) *PlaceHolderInt = max;
		if (rightpress) {
			if (*PlaceHolderInt >= max) *PlaceHolderInt = min;
			else *PlaceHolderInt += 1;
			rightpress = false;
			return true;
		}
		if (*PlaceHolderInt > max) *PlaceHolderInt = min;
	}

	char buf[30];
	_snprintf_s(buf, sizeof(buf), "%.2f", display[*PlaceHolderInt]);

	if (currentoption <= 16 && optioncount <= 16)
		drawText(StringToChar("<" + (std::string)buf + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
		drawText(StringToChar("<" + (std::string)buf + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);

	if (optionpress && currentoption == optioncount)
		return true;
	else return false;
}

bool Menu::CharArray(char* option, char* display[], int *PlaceHolderInt) {
	Option(option);

	int min = 0;
	int max = sizeof(display) / sizeof(*display) + 1;

	if (currentoption == optioncount) {
		if (leftpress) {
			if (*PlaceHolderInt <= min) *PlaceHolderInt = max;
			else *PlaceHolderInt -= 1;
			leftpress = false;
		}
		if (*PlaceHolderInt < min) *PlaceHolderInt = max;
		if (rightpress) {
			if (*PlaceHolderInt >= max) *PlaceHolderInt = min;
			else *PlaceHolderInt += 1;
			rightpress = false;
		}
		if (*PlaceHolderInt > max) *PlaceHolderInt = min;
	}
	if (currentoption <= 16 && optioncount <= 16)
		drawText(StringToChar("<" + (std::string)display[*PlaceHolderInt] + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
		drawText(StringToChar("<" + (std::string)display[*PlaceHolderInt] + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);

	if (optionpress && currentoption == optioncount)
		return true;
	else return false;
}

void Menu::TeleportOption(char* option, float x, float y, float z) {
	Option(option);
	
	if (currentoption == optioncount && optionpress) {
		Entity handle = PLAYER::PLAYER_PED_ID();
		//PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false)) handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(handle, x, y, z, false, false, false);
		
	}
}
Hash $(std::string str) {
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
void Menu::RPOption(char* option, int value) {
	Option(option);

	if (currentoption == optioncount && optionpress) {

		STATS::STAT_SET_INT($("MP0_CHAR_XP_FM"), value, true);
		STATS::STAT_SET_INT($("MP1_CHAR_XP_FM"), value, true);
		STATS::STAT_SET_INT($("MP2_CHAR_XP_FM"), value, true);

	}
}


void Menu::IniWriteInt(LPCWSTR file, LPCWSTR section, LPCWSTR key, int value)
{
	wchar_t newValue[256];
	wsprintfW(newValue, L"%d", value);
	WritePrivateProfileStringW(section, key, newValue, file);
}
void Menu::IniWriteFloat(LPCWSTR file, LPCWSTR section, LPCWSTR key, float value)
{
	wchar_t newValue[256];
	wsprintfW(newValue, L"%f", value);
	WritePrivateProfileStringW(section, key, newValue, file);
}
int Menu::IniReadInt(LPCWSTR file, LPCWSTR section, LPCWSTR key)
{
	int returning = GetPrivateProfileIntW(section, key, NULL, file);
	return returning;
}

void Menu::LoadMenuTheme(LPCWSTR file)
{
	// Title Text
	titleText.r = IniReadInt(file, L"Title Text", L"Red");
	titleText.g = IniReadInt(file, L"Title Text", L"Green");
	titleText.b = IniReadInt(file, L"Title Text", L"Blue");
	titleText.a = IniReadInt(file, L"Title Text", L"Alpha");

	// Title Rect
	titleRect.r = IniReadInt(file, L"Title Rect", L"Red");
	titleRect.g = IniReadInt(file, L"Title Rect", L"Green");
	titleRect.b = IniReadInt(file, L"Title Rect", L"Blue");
	titleRect.a = IniReadInt(file, L"Title Rect", L"Alpha");

	// Scroller
	scroller.r = IniReadInt(file, L"Scroller", L"Red");
	scroller.g = IniReadInt(file, L"Scroller", L"Green");
	scroller.b = IniReadInt(file, L"Scroller", L"Blue");
	scroller.a = IniReadInt(file, L"Scroller", L"Alpha");

	// Option Text
	options.r = IniReadInt(file, L"Options Text", L"Red");
	options.g = IniReadInt(file, L"Options Text", L"Green");
	options.b = IniReadInt(file, L"Options Text", L"Blue");
	options.a = IniReadInt(file, L"Options Text", L"Alpha");

	// Option Rect
	optionsrect.r = IniReadInt(file, L"Options Rect", L"Red");
	optionsrect.g = IniReadInt(file, L"Options Rect", L"Green");
	optionsrect.b = IniReadInt(file, L"Options Rect", L"Blue");
	optionsrect.a = IniReadInt(file, L"Options Rect", L"Alpha");

}

void Menu::SaveMenuTheme(LPCWSTR file)
{
	// Title Text
	IniWriteInt(file, L"Title Text", L"Red", titleText.r);
	IniWriteInt(file, L"Title Text", L"Green", titleText.g);
	IniWriteInt(file, L"Title Text", L"Blue", titleText.b);
	IniWriteInt(file, L"Title Text", L"Alpha", titleText.a);

	// Title Rect
	IniWriteInt(file, L"Title Rect", L"Red", titleRect.r);
	IniWriteInt(file, L"Title Rect", L"Green", titleRect.g);
	IniWriteInt(file, L"Title Rect", L"Blue", titleRect.b);
	IniWriteInt(file, L"Title Rect", L"Alpha", titleRect.a);

	// Scroller 
	IniWriteInt(file, L"Scroller", L"Red", scroller.r);
	IniWriteInt(file, L"Scroller", L"Green", scroller.g);
	IniWriteInt(file, L"Scroller", L"Blue", scroller.b);
	IniWriteInt(file, L"Scroller", L"Alpha", scroller.a);

	// Options Text
	IniWriteInt(file, L"Options Text", L"Red", options.r);
	IniWriteInt(file, L"Options Text", L"Green", options.g);
	IniWriteInt(file, L"Options Text", L"Blue", options.b);
	IniWriteInt(file, L"Options Text", L"Alpha", options.a);

	// Options Rect
	IniWriteInt(file, L"Options Rect", L"Red", optionsrect.r);
	IniWriteInt(file, L"Options Rect", L"Green", optionsrect.g);
	IniWriteInt(file, L"Options Rect", L"Blue", optionsrect.b);
	IniWriteInt(file, L"Options Rect", L"Alpha", optionsrect.a);
}

void Menu::endMenu() {
	if (menulevel > 0)
	{
		if (optioncount > 16)
		{
			drawText(StringToChar(std::to_string(currentoption) + "/" + std::to_string(optioncount)),
				6, menux - 0.1f, (17 * 0.035f + 0.125f), 0.5f, 0.5f, titleText, false);
			drawRect(menux, (17 * 0.035f + 0.1415f), 0.23f, 0.035f, endmenu);//Main UI
			drawText("0.4.3", 6, menux - 0.089f, (17 * 0.035f + 0.1415f), 0.5f, 0.5f, titleText, false);
			/*drawRect(menux, ((17) * 0.035f + 0.1415f + 0.019f), 0.234f, 0.004f, boder);//µ×²¿±ß¿ò 
			drawRect(menux - 0.116f, ((17) * 0.035f + 0.1416f), 0.002f, 0.034f, boder);//×ó²à±ß¿ò
			drawRect(menux + 0.23f - 0.114f, ((17) * 0.035f + 0.1416f), 0.002f, 0.034f, boder);//ÓÒ²à±ß¿òÉè¼Æ*/
			
			if (currentoption == 1) {
				drawSprite("commonmenu", "arrowright", menux + 0.074f, ((16 + 1) * 0.035f + 0.145f), 0.02f, 0.02f, 90, titleText);
			}
			else if (currentoption == optioncount) {
				drawSprite("commonmenu", "arrowright", menux + 0.074f, ((16 + 1) * 0.035f + 0.145f), 0.02f, 0.02f, 270, titleText);
			}
			else {
				drawSprite("commonmenu", "arrowright", menux + 0.074f, ((16 + 1) * 0.035f + 0.14f), 0.02f, 0.02f, 270, titleText);
				drawSprite("commonmenu", "arrowright", menux + 0.074f, ((16 + 1) * 0.035f + 0.15f), 0.02f, 0.02f, 90, titleText);
			}
		}
		else
		{
			drawText(StringToChar(std::to_string(currentoption) + "/" + std::to_string(optioncount)),
				6, menux +0.089f, ((optioncount + 1) * 0.035f + 0.125f), 0.5f, 0.5f, titleText, false);
			drawText("0.4.3", 6, menux - 0.089f, ((optioncount + 1) * 0.035f + 0.125f), 0.5f, 0.5f, titleText, false);
			drawSprite("mphud", "missionpassedgradient", menux, ((optioncount + 1) * 0.035f + 0.1415f), 0.23f, 0.035f, 0.0f, titleRect);
			//drawRect(menux, ((optioncount + 1) * 0.035f + 0.1415f), 0.23f, 0.035f, endmenu);
			/*drawRect(menux, ((optioncount + 1) * 0.035f + 0.1415f + 0.019f), 0.234f, 0.002f, boder);//µ×²¿±ß¿ò 
			drawRect(menux-0.116f, ((optioncount + 1) * 0.035f + 0.1416f), 0.002f, 0.035f, boder);//×ó²à±ß¿ò
			drawRect(menux + 0.23f-0.114f, ((optioncount + 1) * 0.035f + 0.1416f), 0.002f, 0.035f, boder);//ÓÒ²à±ß¿òÉè¼Æ*/
			//Global icon 
			drawSprite("mpleaderboard", "leaderboard_globe_icon", menux - 0.1f, ((optioncount + 1) * 0.035f + 0.141f), 0.02f, 0.03f, 0, titleRect);
			if (currentoption == 1 && optioncount > 1) {
				drawSprite("commonmenu", "arrowright", menux+0.074f, ((optioncount + 1) * 0.035f + 0.145f)-0.003f, 0.02f, 0.02f, 90, titleText);
			}
			else if (currentoption == optioncount && optioncount > 1) {
				drawSprite("commonmenu", "arrowright", menux + 0.074f, ((optioncount + 1) * 0.035f + 0.145f)-0.003f, 0.02f, 0.02f, 270, titleText);
			}
			else if (optioncount > 1) {
				drawSprite("commonmenu", "arrowright", menux + 0.074f, ((optioncount + 1) * 0.035f + 0.14f)-0.003f, 0.02f, 0.02f, 270, titleText);
				drawSprite("commonmenu", "arrowright", menux + 0.074f, ((optioncount + 1) * 0.035f + 0.15f)-0.003f, 0.02f, 0.02f, 90, titleText);
			}
		}

		/*
		UI::HIDE_HELP_TEXT_THIS_FRAME();
		CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlNextCamera, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlPhone, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleCinCam, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterMichael, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterFranklin, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterTrevor, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterMultiplayer, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlCharacterWheel, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackLight, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackHeavy, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackAlternate, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMultiplayerInfo, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMapPointOfInterest, true);*/

		if (currentoption > optioncount) currentoption = optioncount;
		if (currentoption < 1) currentoption = 1;
	}
}

void Menu::checkKeys() {
	optionpress = false;
	if (GetTickCount() - Delay > 150) {
		if (getKeyPressed(VK_F8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendLb) &&
			CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRb)) {
			if (menulevel == 0) changeMenu("mainmenu");
			else if (menulevel > 0) backMenu();
			Delay = GetTickCount();
		}
		if (getKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel)) {
			if (menulevel > 0)
				backMenu();
			Delay = GetTickCount();
		}
		if (getKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
			optionpress = true;
			Delay = GetTickCount();
		}
		if (getKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown)) {
			if (currentoption < optioncount)
				currentoption++;
			else
				currentoption = 1;
			Delay = GetTickCount();
			downpress = true;
		}
		if (getKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp)) {
			if (currentoption > 1)
				currentoption--;
			else
				currentoption = optioncount;
			Delay = GetTickCount();
			uppress = true;
		}
		if (getKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft)) {
			leftpress = true;
			Delay = GetTickCount();
		}
		if (getKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight)) {
			rightpress = true;
			Delay = GetTickCount();
		}
	}
}



int smalloptioncount;
void Menu::SmallTitle(char* title) {
	if (menulevel>0)
	{
		smalloptioncount = 0;
		drawText(title, 6, menux + 0.24f, 0.095f-0.018f, 0.85f, 0.85f, titleText, true);
		drawSprite("mphud", "missionpassedgradient", menux + 0.24f, 0.1175f, 0.23f+width, 0.085f, 0.0f, titleRect);
	}
};
void Menu::SmallOption(char * text, char* Streamedtexture=NULL, char* textureName=NULL)
{
	if (menulevel>0)
	{
		smalloptioncount++;
		if (Streamedtexture != NULL&&textureName != NULL)
		{
			drawRect(menux + 0.24f, ((smalloptioncount * 0.035f) + 0.1415f), 0.23f + width, 0.035f, optionsrect);
			drawSprite(Streamedtexture, textureName, menux+0.134f  , (smalloptioncount * 0.035f + 0.14f),0.015f,0.031f,0,titleRect);
			drawText(text, 6, menux + 0.14f, (smalloptioncount * 0.035f + 0.125f), 0.4f, 0.4f, options, false);
		}
		else
		{
			drawText(text, 6, menux - 0.1f + 0.24f , (smalloptioncount * 0.035f + 0.125f), 0.4f, 0.4f, options, false);
			drawRect(menux + 0.24f, ((smalloptioncount * 0.035f) + 0.1415f), 0.23f + width, 0.035f, optionsrect);
		}
	}
}
//0.7f + realx  +x, 0.5f + realy - y
bool BoolMap = false;
void Menu::drawMap() 
{
	Player player = PLAYER::GET_PLAYER_PED(0);
	Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(player, 0);
	float realx= playerPos.x/ (31300.0f*percent),
		  realy = playerPos.y/ (31300.0f*percent);
	if (BoolMap)
	{
		drawText("Map", 7, 0.7f, 0.095f, 0.85f, 0.85f, titleText, true);
		drawSprite("mphud", "missionpassedgradient", 0.7f, 0.1175f, 0.24f, 0.085f, 0.0f, titleRect);
		drawSprite("mp_freemode_mc", "debugmap", 0.7f, 0.4175f+0.007f, 0.24f, 0.53f, 0.0f, titleRect);//0.51f,0.43f,0.24f,0.53f
		drawSprite("mpleaderboard","leaderboard_kd_icon",0.6920f+realx,0.516f+y-realy,0.017f+width,0.022f+height, ENTITY::GET_ENTITY_HEADING(player),titleRect);
	}
}

void Menu::WeaponMenu()
{
	Menu::SmallTitle("weapon");

		Menu::drawRect(0.44f, 0.21f, 0.23f, 0.1f, optionsrect);
		Menu::drawSprite("mpkillquota", weaponicon[currentoption], menux + 0.24f, 0.2f, 0.11f, 0.11f, 0, titleRect);

	
	
}

char* StringToChar(std::string string)
{
	//char* character = new char[string.length() + 1];
	//strcpy(character, string.c_str());
	//return character;
	return _strdup(string.c_str());
}

//Player Info
int GetEntitySpeedMiles(Entity selectedEntity)
{
	return (ENTITY::GET_ENTITY_SPEED(selectedEntity) * 2.23693629f);
}

int GetEntitySpeedKilometers(Entity selectedEntity)
{
	return ((ENTITY::GET_ENTITY_SPEED(selectedEntity) * 2.23693629f) * 1.609f);
}

Hash WeapHash;
void Menu::PlayerMenu()
{
	int playerIndex = 0;
	Player player = PLAYER::GET_PLAYER_PED(0);
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
	if (ENTITY::DOES_ENTITY_EXIST(player))
	{
		Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(player, 0), localPos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
		std::string canSeePed = ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT(PLAYER::PLAYER_PED_ID(), player) ? "~g~TRUE" : "~r~FALSE";
		int stamina = PLAYER::GET_PLAYER_SPRINT_STAMINA_REMAINING(playerIndex);

		Menu::SmallTitle(PLAYER::GET_PLAYER_NAME(playerIndex));
		Menu::SmallOption(StringToChar("WANTED LEVEL: " + std::to_string(PLAYER::GET_PLAYER_WANTED_LEVEL(playerIndex))),"commonmenutu","custom_mission");
		InfoMenu::healthOption();
		Menu::SmallOption(StringToChar("PLAYER LEVEL: ~r~"));
		Menu::SmallOption(StringToChar("STAMINA: " + std::to_string(100 - stamina) + "%"));
		
		char* vehicle = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(player, 0)));
		char* vehPrefix = "ON FOOT: ";
		char* text = "mp_specitem_ped";
		if (!strcmp(vehicle, "CARNOTFOUND"))
		{
			if (PED::IS_PED_SWIMMING(player))
			{
				vehicle = "SWIMMING";
				text = "mp_specitem_boat";
			}
			else if (AI::IS_PED_STILL(player))
			{
				vehicle = "STILL";
				text = "mp_specitem_ped";
			}
			else if (AI::IS_PED_WALKING(player))
			{
				vehicle = "WALKING";
				text = "mp_specitem_ped";
			}
			else if (AI::IS_PED_RUNNING(player))
			{
				vehicle = "RUNNING";
			}
			else if (AI::IS_PED_SPRINTING(player))
			{
				vehicle = "SPRINTING";
			}
			else if (AI::IS_PED_STRAFING(player))
			{
				vehicle = "STAFING";
			}
		}
		else if (strcmp(vehicle, "CARNOTFOUND"))
		{
			vehPrefix = "VEHICLE: ";
			text = "mp_specitem_car";
		}
		
		Menu::SmallOption(StringToChar((std::string)vehPrefix + (std::string)vehicle),"mpinventory", text);
		Menu::SmallOption(StringToChar("SPEED (KMH): " + std::to_string(GetEntitySpeedKilometers(player))), "commonmenutu","stunt");
		//Menu::SmallOption(StringToChar("SPEED (MPH): " + std::to_string(GetEntitySpeedMiles(player))));

		Menu::SmallOption(StringToChar("VISIBLE: " + canSeePed),"mphud","spectating");
		Hash streetHash, crossRoad;
		PATHFIND::GET_STREET_NAME_AT_COORD(playerPos.x, playerPos.y, playerPos.z, &streetHash, &crossRoad);
		Menu::SmallOption(StringToChar("STREET: " + (std::string)UI::GET_STREET_NAME_FROM_HASH_KEY(streetHash)));
		Menu::SmallOption(StringToChar("X: " + std::to_string((int)playerPos.x) + " Y: " + std::to_string((int)playerPos.y) + " Z: " + std::to_string((int)playerPos.z)));
		Menu::SmallOption(StringToChar("HEADING: " + std::to_string((int)ENTITY::GET_ENTITY_HEADING(player))));
		Menu::SmallOption(StringToChar("DISTANCE: " + std::to_string((int)GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(localPos.x, localPos.y, localPos.z, playerPos.x, playerPos.y, playerPos.z, false)) + "ft"));
		Menu::SmallOption(StringToChar("WeaponHash:"+std::to_string(WeapHash)));	
	}
}

void PTFXCALL(char *call1,char* call2,  char *name)
{
	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

}

//HealthInfo Done!
rgba health = { 102, 102, 102,255 };
rgba HP = { 0,255,0 ,255};
void InfoMenu::healthOption()
{
	int playerIndex = 0;
	Player player = PLAYER::GET_PLAYER_PED(0);
	float healthPercent = (ENTITY::GET_ENTITY_HEALTH(player) / ((ENTITY::GET_ENTITY_MAX_HEALTH(player) / 100))) / 100;
	float ischanged = 1.0f;
	if (menulevel>0)
	{
		smalloptioncount++;
		
		if (ischanged!=healthPercent)
		{
			//255,0,0--------red
			//255,255,0------yellow
			//0,255,0--------green
			
			/*HP.r = 255 * (1 - healthPercent);
			HP.g = 255*healthPercent;*/
			if (healthPercent>=0.5f)
			{
				HP.r = 255 * ((1 - healthPercent)*2);//done
			}
			else if (healthPercent>0.0f&&healthPercent<0.5f)//done
			{
				HP.g = 255 * (healthPercent*2);
			}
			else//done
			{
				 HP = { 0,255,0 ,255 };
			}
			ischanged = healthPercent;
		}
		Menu::drawRect(menux + 0.24f, ((smalloptioncount * 0.035f) + 0.1415f), 0.23f, 0.035f, optionsrect);
		Menu::drawText(StringToChar("HP: " + std::to_string(ENTITY::GET_ENTITY_HEALTH(player) / ((ENTITY::GET_ENTITY_MAX_HEALTH(player) / 100))) + "%"), 6, menux + 0.14f, (smalloptioncount * 0.035f + 0.125f), 0.4f, 0.4f, options, false);
		Menu::drawRect(menux + 0.232f, ((smalloptioncount * 0.035f) + 0.1385f), 0.1044f, 0.012f, health);//health bgd
		Menu::drawRect(menux + 0.232f-(0.1044f*(1- healthPercent)/2), ((smalloptioncount * 0.035f) + 0.1385f), 0.1044f*healthPercent, 0.012f, HP);//ÒÑÓÐÑªÁ¿

		/*Menu::drawText(StringToChar("HP: " + std::to_string(ENTITY::GET_ENTITY_HEALTH(player) / ((ENTITY::GET_ENTITY_MAX_HEALTH(player) / 100))) + "%"), 6, menux + 0.14f, 0.095f+0.041f, 0.4f, 0.4f, options, false);
		Menu::drawRect(menux + 0.232f+x, 0.095f +0.055f, 0.1044f, 0.012f, health);//health bgd
		Menu::drawRect(menux + 0.232f - (0.1044f*(1 - healthPercent) / 2)+x, 0.095f + 0.055f, 0.1044f*healthPercent, 0.012f, HP);//ÒÑÓÐÑªÁ¿*/

	}
}



int IconNotification(char *text, char *text2, char *Subject)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
#ifdef DEBUG
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 9, text2, Subject, 1.0f, "___DBUG", 6, 8);
#else
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 9, text2, Subject, 1.0f, "___FREE", 6, 8);
#endif // DEBUG

	return UI::_DRAW_NOTIFICATION(1, 1);
}


void Talker(Player player)
{
	Menu::drawText(StringToChar(("Talker: " + (std::string)PLAYER::GET_PLAYER_NAME(player)).c_str()), 6, menux - 0.1f, (17 * 0.035f + 0.125f), 0.5f, 0.5f, titleText, false);
}
void Speedo(float speed)
{
	Menu::drawText(StringToChar(("Speed: " + std::to_string(speed) + "Mph").c_str()), 6, menux - 0.1f, (17 * 0.035f + 0.125f), 0.5f, 0.5f, titleText, false);
}


void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}


void RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}


float degToRad(float degs)
{
	return degs*3.141592653589793f / 180.f;
}

std::string show_keyboard(char* title_id, char* prepopulated_text)
{
	DWORD time = GetTickCount() + 400;
	while (GetTickCount() < time)
	{
		WAIT(0);
	}

	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, (title_id == NULL ? "HUD_TITLE" : title_id), "", (prepopulated_text == NULL ? "" : prepopulated_text), "", "", "", 64);

	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0)
	{
		WAIT(0);
	}

	std::stringstream ss;
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT())
	{
		return std::string("");
	}
	else
	{
		return std::string(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
	}
}