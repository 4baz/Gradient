#pragma once
#include "Natives.hpp"
#include "Common.hpp"

//using namespace Big;

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

extern Big::Player selPlayer;
extern const char* selPlayerName;


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
void AddString(const char* optiontext, const char* option, int* var, int min, int max, const char* info);
void AddString(const char* optiontext, const char* option, int* var, int min, int max, std::function<void()> callback, const char* info);
void AddPlayer(const char* name, Player player, const char* info);
void addrpOption(const char* option, int value, const char* info);
void AddPlayer(const char* name, Player player, const char* info);


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