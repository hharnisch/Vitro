#include "_pch.h"
#include "UIOverlay.h"

#include <imgui/imgui.h>

#if VTR_SYSTEM_WINDOWS
#include <imgui/imgui_impl_win32.h>
#endif

#if VTR_API_DIRECTX
#include <imgui/imgui_impl_dx11.h>
#endif

namespace Vitro
{
	void UIOverlay::OnAttach()
	{}

	void UIOverlay::OnDetach()
	{}

	void UIOverlay::OnUpdate(TimeStep ts)
	{
	#if VTR_API_DIRECTX
		ImGui_ImplDX11_NewFrame();
	#endif
	#if VTR_SYSTEM_WINDOWS
		ImGui_ImplWin32_NewFrame();
	#endif
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();
		ImGui::Render();


	#if VTR_API_DIRECTX
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	#endif
		ImGui::EndFrame();
	#if VTR_SYSTEM_WINDOWS
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	#endif
	}

	void UIOverlay::OnEvent(Event& event)
	{}
}
