#pragma once
#include <windows.h>
#define GLFW_INCLUDE_NONE
#include "imgui.h"
#include "imgui_internal.h"
//#include "ImGuizmo.h"
#include "imgui_impl_win32.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

class Win32UILayer
{
public:
	void BeginFrame();
	void EndFrame();
	void OnUpdate(float ts);
	void OnInit();
	void OnRender();

	// HANDLE SOME EVENTS HERE

	Win32UILayer(HWND window_handle) : m_Hwnd{ window_handle }
	{
		//OnInit();
	}
	~Win32UILayer() 
	{

		ImGui_ImplOpenGL3_Shutdown();

		ImGui_ImplWin32_Shutdown();

		ImGui::DestroyContext();
	}

private:
	HWND m_Hwnd;
	ImGuiContext * m_MainContext, * m_SecondaryContext;
};