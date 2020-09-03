#include "_pch.h"
#include "Editor.h"

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
	Editor::Editor(void* nativeWindowHandle)
	{
		IMGUI_CHECKVERSION();
		auto context = ImGui::CreateContext();
		auto& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.IniFilename = nullptr;
		ImGui::StyleColorsDark();

	#if VTR_SYSTEM_WINDOWS
		ImGui_ImplWin32_Init(nativeWindowHandle);
	#endif
	#if VTR_API_DIRECTX
		ImGui_ImplDX11_Init(DirectX::RHI::Device, DirectX::RHI::Context);
	#endif
	}

	Editor::~Editor()
	{
	#if VTR_API_DIRECTX
		ImGui_ImplDX11_Shutdown();
	#endif
	#if VTR_SYSTEM_WINDOWS
		ImGui_ImplWin32_Shutdown();
	#endif

		ImGui::DestroyContext();
	}

	void Editor::OnAttach()
	{}

	void Editor::OnDetach()
	{}

	void Editor::OnTick(Tick t)
	{
		BeginFrame();

		ImGui::ShowDemoWindow();
		ImGui::Begin("Statistics");
		ImGui::Text(t.ToString().c_str(), "");
		ImGui::End();

		EndFrame();
	}

	void Editor::OnEvent(Event& e)
	{}

	void Editor::BeginFrame()
	{
	#if VTR_API_DIRECTX
		ImGui_ImplDX11_NewFrame();
	#endif
	#if VTR_SYSTEM_WINDOWS
		ImGui_ImplWin32_NewFrame();
	#endif

		ImGui::NewFrame();
	}

	void Editor::EndFrame()
	{
		ImGui::Render();
		ImGui::EndFrame();

	#if VTR_SYSTEM_WINDOWS
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	#endif
	#if VTR_API_DIRECTX
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	#endif
	}
}
