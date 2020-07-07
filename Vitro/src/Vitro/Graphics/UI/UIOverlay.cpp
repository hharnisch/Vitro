#include "_pch.h"
#include "UIOverlay.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_win32.h>

namespace Vitro
{
	void UIOverlay::OnAttach()
	{
		ImGui::StyleColorsDark();

	#if $OPENGL
		ImGui_ImplOpenGL3_Init("#version 460");
	#endif
	}

	void UIOverlay::OnDetach()
	{
	#if $OPENGL
		ImGui_ImplOpenGL3_Shutdown();
	#endif

	#if $WINDOWS
		ImGui_ImplWin32_Shutdown();
	#endif

		ImGui::DestroyContext();
	}

	void UIOverlay::OnUpdate()
	{
	#if $OPENGL
		ImGui_ImplOpenGL3_NewFrame();
	#endif

	#if $WINDOWS
		ImGui_ImplWin32_NewFrame();
	#endif

		ImGui::NewFrame();
		ImGui::ShowDemoWindow();
		ImGui::Render();

	#if $OPENGL
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	#endif

		ImGui::EndFrame();
	}

	void UIOverlay::OnEvent(Event& event)
	{
	}
}
