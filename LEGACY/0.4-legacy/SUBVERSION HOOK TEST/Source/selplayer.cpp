#include "stdafx.h"

/*
void draw_rect(float A_0, float A_1, float A_2, float A_3, int A_4, int A_5, int A_6, int A_7)
{
	GRAPHICS::DRAW_RECT((A_0 + (A_2 * 0.5f)), (A_1 + (A_3 * 0.5f)), A_2, A_3, A_4, A_5, A_6, A_7);
}

void draw_menu_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true)
{
	//If you use this design in a public menu, please credit me, The Crusader, for the design :)

	// default values
	int text_col[4] = { 255, 255, 255, 250.0f },
		rect_col[4] = { 0, 0, 0, 239.f };
	float text_scale = 0.35;
	int font = 0;
	bool outline = false;   //your choice
	bool dropShadow = false; //your choice

							 // correcting values for active line
	if (active)
	{
		text_col[0] = 0;
		text_col[1] = 0;
		text_col[2] = 0;
		text_col[3] = 240.f;

		rect_col[0] = 200;
		rect_col[1] = 9;
		rect_col[2] = 5;
		rect_col[3] = 220;



		if (rescaleText) text_scale = 0.39; //37

	}
	else if (title)
	{
		text_col[0] = 255;
		text_col[1] = 255;
		text_col[2] = 255;

		rect_col[0] = 200;
		rect_col[1] = 9;
		rect_col[2] = 5;
		rect_col[3] = 220;

		if (rescaleText) text_scale = 0.75;
		outline = true;

		font = 7;
	}
	else
	{
		outline = true;
	}


	int screen_w, screen_h;
	GRAPHICS::GET_SCREEN_RESOLUTION(&screen_w, &screen_h);

	textLeft += lineLeft;

	float lineWidthScaled = lineWidth / (float)screen_w; // line width
	float lineTopScaled = lineTop / (float)screen_h; // line top offset
	float textLeftScaled = textLeft / (float)screen_w; // text left offset
	float lineHeightScaled = lineHeight / (float)screen_h; // line height

	float lineLeftScaled = lineLeft / (float)screen_w;

	// this is how it's done in original scripts

	// text upper part
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, text_scale);
	UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
	UI::SET_TEXT_CENTRE(0);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)caption.c_str());
	UI::_DRAW_TEXT(textLeftScaled, (((lineTopScaled + 0.00278f) + lineHeightScaled) - 0.005f));

	// text lower part
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, text_scale);
	UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
	UI::SET_TEXT_CENTRE(0);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::_SET_TEXT_GXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)caption.c_str());
	int num25 = UI::_GET_TEXT_SCREEN_LINE_COUNT(textLeftScaled, (((lineTopScaled + 0.00278f) + lineHeightScaled) - 0.005f));

	// rect
	draw_rect(lineLeftScaled, lineTopScaled + (0.00278f),
		lineWidthScaled, ((((float)(num25)* UI::_GET_TEXT_SCALE_HEIGHT(text_scale, 0)) + (lineHeightScaled * 1.5f)) + 0.006f),
		rect_col[0], rect_col[1], rect_col[2], rect_col[3]);
}


void process_highlight_player_menu()
{
	const float lineWidth = 250.0;
	const int lineCount = 7;

	std::string caption = PLAYER::GET_PLAYER_NAME(currentOption);

	static struct {
		LPCSTR      text;
		bool        *pState;
		bool        *pUpdated;
	} lines[lineCount] = {
		{ "SKIN CHANGER", NULL, NULL }, //case 0
		{ "TELEPORT", NULL, NULL },
		{ "FIX PLAYER", NULL, NULL },
		{ "RESET SKIN", NULL, NULL },
		{ "ADD CASH", NULL, NULL },
		{ "WANTED UP", NULL, NULL },
		{ "WANTED DOWN", NULL, NULL },
		
	};

	DWORD waitTime = 150;
	while (true)
	{
		// timed menu draw, used for pause after active line switch
		DWORD maxTickCount = GetTickCount() + waitTime;
		do
		{
			// draw menu
			draw_menu_line(caption, lineWidth, 15.0, 18.0, 0.0, 5.0, false, true);
			for (int i = 0; i < lineCount; i++)
				if (i != activeLineIndexPlayer)
					draw_menu_line(line_as_str(lines[i].text, lines[i].pState),
						lineWidth, 9.0, 60.0 + i * 36.0, 0.0, 9.0, false, false);
			draw_menu_line(line_as_str(lines[activeLineIndexPlayer].text, lines[activeLineIndexPlayer].pState),
				lineWidth + 1.0, 11.0, 56.0 + activeLineIndexPlayer * 36.0, 0.0, 7.0, true, false);

			//update_features2();
			WAIT(0);
		} while (GetTickCount() < maxTickCount);
		waitTime = 0;

	}

}


*/