#include "_pch.h"
#include "UI.h"

#include <imgui/imgui.h>

#if VTR_SYSTEM_WINDOWS
#include <imgui/imgui_impl_win32.h>
#endif

#if VTR_API_DIRECTX
#include "Vitro/API/DirectX/RHI.h"
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
	#if VTR_API_DIRECTX
		ImGui_ImplDX11_Init(DirectX::RHI::Device, DirectX::RHI::Context);
	#endif
	}

	void UI::Finalize()
	{
	#if VTR_API_DIRECTX
		ImGui_ImplDX11_Shutdown();
	#endif
	#if VTR_SYSTEM_WINDOWS
		ImGui_ImplWin32_Shutdown();
	#endif
		ImGui::DestroyContext();
	}
}
