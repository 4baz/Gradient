#pragma once

#ifndef MENU_FEATURES_H
#define MENU_FEATURES_H

#include "stdafx.h"
#include <functional>

//Variables

/*
bool menuSounds = true;
bool rightPress = false;
bool leftPress = false;
bool squarePress = false;
bool gradients = false;

RGBA bannerRectCol = { 255, 0, 0, 255 };
int bannerRectRed = 255;
int bannerRectGreen = 0;
int bannerRectBlue = 0;
int bannerRectOpacity = 255;

RGBA bannerTextCol = { 255, 255, 255, 255 };
int bannerTextRed = 255;
int bannerTextGreen = 255;
int bannerTextBlue = 255;
int bannerTextOpacity = 255;
char* optionTextToAdd;
int optionCount;
int currentOption;
int maxOptions = 14;

float MainBackGroundX = 0.827f;
float MainBackGroundY = 0.137f;
float MainBackGroundWidth = 0.225f;

RGBA backgroundCol = { 0, 0, 0, 185 };
int backgroundRed = 0;
int backgroundGreen = 0;
int backgroundBlue = 0;
int backgroundOpacity = 185;

RGBA highlightCol = { 0, 0, 0, 255 };
int highlightRed = 0;
int highlightGreen = 0;
int highlightBlue = 0;

int optionsFont = 0;
RGBA optionCol = { 255, 255, 255, 255 };
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

RGBA secondTitleCol = { 255, 255, 255, 255 };
int secondTitleRed = 255;
int secondTitleGreen = 255;
int secondTitleBlue = 255;
int secondTitleOpacity = 255;

char *infoText;

float infoBoxX = 0.827f;
float infoBoxY = 0.127f;
float infoBoxTextX = 0.718f;
float infoBoxTextY = 0.114f;

float BarUnderHeaderX = 0.827f;
float BarUnderHeaderY = 0.121f;
float BarUnderHeaderHeight = 0.032f;

float BarAboveInfoY = 0.108f;
float BarAboveInfoHeight = 0.003f;

int submenu = 0;
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];
*/
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
extern char* optionTextToAdd;
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

extern char *infoText;

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

void changeSubmenu(int newSubmenu);
void setupText(char *text);
void drawText(char *text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, int position, bool outline);
void drawSprite(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
void drawSpriteLayer(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a, int layer);
void PlayFrontendSound(char* sound);
void DisplayHelpTextThisFrame(char* text);
void AddTitle(char *title);
void AddTitleColour(char *title, int red, int green, int blue);
void AddWeaponTitle(char *title);
void AddVehicleTitle(char *title);
void AddSubmenu(char *option, int submenu, char *info);
void AddOption(char *option, char *info);
void AddOption(char *option, char* string, char *info);
void AddOption(char *option, std::function<void()> function, char *info);
void AddToggle(char *option, bool* boolean, char *info);
void AddToggle(char * option, bool boolean, std::function<void()> function, char * info);
void addBoolOption(char* option, bool b00l, char *info);
void AddInt(char *option, int *inttochange, int min, int max, int increments, char *info);
void AddFloat(char* option, float *floattochange, float min, float max, float increments, char *info);
void AddString(char *optiontext, char* option, int *var, int min, int max, char *info);
void AddString(char *optiontext, char* option, int *var, int min, int max, std::function<void()> callback, char *info);
void AddPlayer(char * name, Player player, char * info);
void addrpOption(char *option, int value, char *info);

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
#endif