#include "common.hpp"
#include "file_manager.hpp"
#include "fonts/fonts.hpp"
#include "gui.hpp"
#include "pointers.hpp"
#include "renderer.hpp"
#include <imgui.h>
#include <backends/imgui_impl_dx11.h>
#include <backends/imgui_impl_win32.h>
#include <imgui_internal.h>
#include "DOGSHITUI/NATIVEmenu.h"
//#include "../stb_image.h"
#include "../dxcustomdrawbaz.h"
#include "DOGSHITUI/NATIVEbase.h"
#include "services/players/player_service.hpp"
#include "script_global.hpp"
#include "views/view.hpp"
#define mnux  g->menu.menux
#define mnuy g->menu.menuy
//#include "./"
//#include <D3DX11tex.h>


IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
 const char* playernm; Player plr;
void onlineplayerinfoA(const char* playername, Player player) {

	plr = player;
	playernm = playername;

}

namespace big
{
	renderer::renderer() :
		m_dxgi_swapchain(*g_pointers->m_swapchain)
	{
		void* d3d_device{};
		if (SUCCEEDED(m_dxgi_swapchain->GetDevice(__uuidof(ID3D11Device), &d3d_device)))
		{
			m_d3d_device.Attach(static_cast<ID3D11Device*>(d3d_device));
		}
		else
		{
			throw std::runtime_error("Failed to get D3D device.");
		}

		m_d3d_device->GetImmediateContext(m_d3d_device_context.GetAddressOf());

		auto file_path = g_file_manager->get_project_file("./imgui.ini").get_path();

		ImGuiContext* ctx = ImGui::CreateContext();

		static std::string path = file_path.make_preferred().string();
		ctx->IO.IniFilename = path.c_str();

		ImGui_ImplDX11_Init(m_d3d_device.Get(), m_d3d_device_context.Get());
		ImGui_ImplWin32_Init(g_pointers->m_hwnd);

		ImFontConfig font_storopia_cfg{};
		font_storopia_cfg.FontDataOwnedByAtlas = false;
		std::strcpy(font_storopia_cfg.Name, "Storopia");
		m_font = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(font_storopia), sizeof(font_storopia), 20.f, &font_storopia_cfg);

		g->window.font_title = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(font_storopia), sizeof(font_storopia), 40.f, &font_storopia_cfg);
		g->window.font_sub_title = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(font_storopia), sizeof(font_storopia), 30.f, &font_storopia_cfg);
		g->window.font_small = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(font_storopia), sizeof(font_storopia), 17.5f, &font_storopia_cfg);

		ImFontConfig font_icons_cfg{};
		font_icons_cfg.FontDataOwnedByAtlas = false;
		std::strcpy(font_icons_cfg.Name, "Icons");
		m_font_icons = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(font_icons), sizeof(font_icons), 24.f, &font_icons_cfg);

		

		g_gui.dx_init();
		g_renderer = this;
	}

	renderer::~renderer()
	{
		ImGui_ImplWin32_Shutdown();
		ImGui_ImplDX11_Shutdown();
		ImGui::DestroyContext();

		g_renderer = nullptr;
	}

	void renderer::on_present()
	{



		if (g_gui.m_opened || enable_cursor)
		{
			ImGui::GetIO().MouseDrawCursor = true;
			ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
		}
		else
		{
			ImGui::GetIO().MouseDrawCursor = false;
			ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouse;
		}

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		g_gui.always_draw();
		WWdxmain();

		if (g_gui.m_opened)
		{
			g_gui.dx_on_tick();
		}
		static ImVec4 col_friend = ImGui::ColorConvertU32ToFloat4(g->esp.friend_color);
		static ImVec4 col_default = ImGui::ColorConvertU32ToFloat4(g->esp.default_color);
		if (enable_esp_rgbmenu) {
			ImGui::Begin("ESP RGB SETTINGS");
			ImGui::SetWindowSize(ImVec2{500,500});
			if (ImGui::ColorEdit4("###Default ESP Color##esp_picker", (float*)&col_default, ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_NoSidePreview))
			{
				g->esp.default_color = ImGui::ColorConvertFloat4ToU32(col_default);
			}

			ImGui::Text("Friendly Color:");
			if (ImGui::ColorEdit4("###Friend ESP Color##friend_picker", (float*)&col_friend, ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_NoSidePreview))
			{
				g->esp.friend_color = ImGui::ColorConvertFloat4ToU32(col_friend);
			}
			if (ImGui::Button("Close Menu"))
			{
				enable_cursor = false;
				enable_esp_rgbmenu = false;
			}
			ImGui::End();

		}




		if (dev_penis) {
			ImDrawList* test = ImGui::GetForegroundDrawList();

			test->AddRectFilled(ImVec2(penisposx, penisposy), ImVec2(penisposx + 200 + rand() % 3, penisposy + 550 + rand() % 3), IM_COL32(255, 241, 196, 255));
			test->AddCircleFilled(ImVec2(penisposx, penisposy + 550), 100.f + rand() % 3, IM_COL32(255, 241, 196, 255), 100);
			test->AddCircleFilled(ImVec2(penisposx + 200, penisposy + 550 + rand() % 3), 100.f + rand() % 3, IM_COL32(255, 241, 196, 255), 100);
			test->AddCircleFilled(ImVec2(penisposx + 100, penisposy), 100.f, IM_COL32(249, 196, 255, 255), 100);
			test->AddLine(ImVec2(penisposx + 100 + rand() % 3, penisposy - 100), ImVec2(penisposx + 100 + rand() % 3, penisposy - 70 + rand() % 3), IM_COL32(246, 148, 255, 255), 4.f);
		
		}
		
	//	if (toggleplayerinfo) {
	//		playerminiinfoondxtick(playernm, plr);
			
		
	//	}
		

		if (dev_imguiimage) {
			ImDrawList* test2 = ImGui::GetForegroundDrawList();

			//test rect
		//	test2->AddRectFilled(ImVec2(pinfox, pinfoy), ImVec2(pinfosizex, pinfosizey), IM_COL32(0, 0, 0, 150));
			//20
			





			//imgui p info render 
			// 
		//	test2->AddRectFilled(ImVec2(1350, 100), ImVec2(974, 620), IM_COL32(0, 0, 0, 150));//backgroundRect
		//	test2->AddRectFilled(ImVec2(1350, 20), ImVec2(974, 100), IM_COL32(81, 8, 126, 225));//bannerbackgroundRect
		//	test2->AddText(ImVec2(1100, 40), IM_COL32(255, 255, 255, 255),"PlayerNameHere");//title

		//	test2->AddText(ImVec2(990, 110), IM_COL32(255, 255, 255, 255), "Test Text");//first text so to print the rest do some maths so that its automatically further under



//need to use text overload to change font and size too
			ImGui::Begin("int value changer test thingy");
			ImGui::Text("side menu pos X,Y");
			ImGui::SliderFloat("X###Xpos",&mnux,-0.8000f,0.4000f);
			ImGui::SliderFloat("Y###Ypos", &mnuy, -0.8000f, 0.4000f);

			ImGui::Text("menu size X,Y (ImVec2)");
			ImGui::SliderInt("X###sizex", &pinfosizex, 0, 2000);
			ImGui::SliderInt("Y###sizey", &pinfosizey, 0, 2000);




			ImGui::End();

		//	ImDrawList* test2 = ImGui::GetForegroundDrawList();
		//	int my_image_width = 0;
		//	int my_image_height = 0;
		//	ID3D11ShaderResourceView* my_texture = NULL;
			//test image render innit
		//	ID3D11ShaderResourceView* my_texture = NULL;
		//	bool ret = LoadTextureFromFile("../../img.png", &my_texture, &my_image_width, &my_image_height);
		//	IM_ASSERT(ret);
		//	test2->AddImage(my_texture, ImVec2(penisposx, penisposy), ImVec2(penisposx, penisposy), ImVec2(0,0), ImVec2(1,1));
		//	ImGui::Begin("DirectX11 Texture Test");
		//	ImGui::Text("pointer = %p", my_texture);
		//	ImGui::Text("size = %d x %d", my_image_width, my_image_height);
		//	ImGui::Image(my_texture, ImVec2(my_image_width, my_image_height));
		//	ImGui::End();
		

		}


		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

	void renderer::pre_reset()
	{
		ImGui_ImplDX11_InvalidateDeviceObjects();
	}

	void renderer::post_reset()
	{
		ImGui_ImplDX11_CreateDeviceObjects();
	}

	void renderer::wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		if (msg == WM_KEYUP && wparam == g->settings.hotkeys.menu_toggle)
		{
			//Persist and restore the cursor position between menu instances.
			static POINT cursor_coords{};
			if (g_gui.m_opened || enable_cursor)
			{
				GetCursorPos(&cursor_coords);
			}
			else if (cursor_coords.x + cursor_coords.y != 0)
			{
				SetCursorPos(cursor_coords.x, cursor_coords.y);
			}

			g_gui.m_opened = g->settings.hotkeys.editing_menu_toggle || !g_gui.m_opened;
			if (g->settings.hotkeys.editing_menu_toggle)
				g->settings.hotkeys.editing_menu_toggle = false;
		}

		if (g_gui.m_opened || enable_cursor)
		{
			ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
		}
	}
}
