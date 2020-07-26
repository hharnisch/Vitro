#include "_pch.h"
#include "UI.h"

#include <imgui/imgui.h>

#if $WINDOWS
#include <imgui/imgui_impl_win32.h>
#endif
#if $DIRECTX
#include "Vitro/API/DirectX/API.h"
#include <imgui/imgui_impl_dx11.h>
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
	#if $DIRECTX
		ImGui_ImplDX11_Init(DirectX::API::Device, DirectX::API::DeviceContext);
	#endif
	}

	void UI::Finalize()
	{
	#if $DIRECTX
		ImGui_ImplDX11_Shutdown();
	#endif
	#if $WINDOWS
		ImGui_ImplWin32_Shutdown();
	#endif
		ImGui::DestroyContext();
	}
}
