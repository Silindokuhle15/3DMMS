// 3DMMS.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "Window.h"
#include "Application.h"
#include "Camera.h"
#include "Event.h"
#include "Mouse.h"
#include "KeyBoard.h"
#include "SceneEvent.h"
#include "TimeStep.h"
#include "Square.h"

#include "UI.h"

// TODO: Reference additional headers your program requires here.

class MyApplication
{
public:
	bool m_ExitApplication;
	TimeStep ts;
	// Get A few things done
	// (1) Open A Window
	// (2) Draw 6 Cubes using the Extrinsic Parameters for the cameras

	void Run();
	void StartTimer() {
		t_start = static_cast<double>(m_Window.milliseconds_now());
	}

	void BeginFrame() 
	{ 
		m_UILayer.BeginFrame(); 
		m_UILayer.OnRender();
	}
	void EndFrame() { m_UILayer.EndFrame(); }

	void EndTimer() {
		t_end = static_cast<double>(m_Window.milliseconds_now());
	}

	glm::mat4 GetVP() const { return  m_Cam.GetVP(); }

	HWND GetWin32WindowHandle() const { return m_Window.m_Hwnd; }

	MyApplication(uint32_t w, uint32_t h, const char* name) : 
		m_ExitApplication{ false }, 
		m_Window{ w, h, name },
		m_Cam{int(w), int(h), 1.0f, 10000.f},
		m_UILayer{m_Window.m_Hwnd}
	{
		m_Window.SetUpForRendering();
		m_Cam.m_eye = glm::vec3(0.0f, 0.0f, -2.0f);
		m_Cam.m_center = glm::vec3(0.0f, 0.0f, 0.0f);
		m_Cam.m_up = glm::vec3(0.0f, 1.0f, 0.0f);
		m_Cam.OnInit();
		m_UILayer.OnInit();
	}
	~MyApplication() {}
private:
	Win32Window m_Window;
	Camera m_Cam;
	TimeStep t_start, t_end;
	Win32UILayer m_UILayer;

};
