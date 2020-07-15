#include "_pch.h"
#include "UI.h"

#include <imgui/imgui.h>
#if $OPENGL
#include <imgui/imgui_impl_opengl3.h>
#endif
#if $WINDOWS
#include <imgui/imgui_impl_win32.h>
#endif

namespace Vitro
{
	void UI::Initialize()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		auto& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		io.IniFilename = nullptr;
		if(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			auto& style = ImGui::GetStyle();
			style.WindowRounding = 0;
			style.Colors[ImGuiCol_WindowBg].w = 1;
		}
		ImGui::StyleColorsDark();
	#if $OPENGL
		ImGui_ImplOpenGL3_Init("#version 460");
	#endif
	}

	void UI::Finalize()
	{
	#if $OPENGL
		ImGui_ImplOpenGL3_Shutdown();
	#endif
	#if $WINDOWS
		ImGui_ImplWin32_Shutdown();
	#endif
		ImGui::DestroyContext();
	}
}
