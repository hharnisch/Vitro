#include "_pch.h"
#include "UIOverlay.h"

#include <glad/glad.h>
#include <imgui/imgui.h>

#if $OPENGL
#include <imgui/imgui_impl_opengl3.h>
#endif

#if $WINDOWS
#include <imgui/imgui_impl_win32.h>
#endif

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

		glClearColor(0.5, 0.5, 0.5, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::ShowDemoWindow();
		ImGui::Render();

	#if $OPENGL
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	#endif
		ImGui::EndFrame();
	#if $WINDOWS
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	#endif
	}

	void UIOverlay::OnEvent(Event& event)
	{}
}
