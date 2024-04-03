#include "UI.h"

void Win32UILayer::BeginFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void Win32UILayer::EndFrame()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	ImGui::EndFrame();
}

void Win32UILayer::OnUpdate(float ts)
{
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDown[0] = static_cast<bool>(GetAsyncKeyState(VK_LBUTTON) & 0x8000);
	io.MouseDown[1] = static_cast<bool>(GetAsyncKeyState(VK_RBUTTON) & 0x8000);
	io.MouseDown[2] = static_cast<bool>(GetAsyncKeyState(VK_MBUTTON) & 0x8000);
}

void Win32UILayer::OnRender()
{
	//m_MainContext->CurrentWindow->Flags |= ImGuiWindowFlags_MenuBar;
	//ImGui::Begin("MenuBar Window", nullptr, ImGuiWindowFlags_MenuBar);
	bool is_open = true;
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("New", "..."))
			{
				if (ImGui::IsItemClicked())
				{
					char buffer[512];
					ImGui::InputText("File Name", buffer, sizeof(char) * 512);

				}
			}
			if (ImGui::MenuItem("Open", "..."))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Close", "..."))
			{
			}
			if (ImGui::MenuItem("Close Project", "..."))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Save Selected", "crtl+s"))
			{
			}
			if (ImGui::MenuItem("Save All", "crtl+shift+s"))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Recent Files", "..."))
			{
			}
			if (ImGui::MenuItem("Recent Projects", "..."))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Quit", "alt+'?'"))
			{
			}
		}
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
			if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
			ImGui::Separator();
			if (ImGui::MenuItem("Cut", "CTRL+X")) {}
			if (ImGui::MenuItem("Copy", "CTRL+C")) {}
			if (ImGui::MenuItem("Paste", "CTRL+V")) {}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("View"))
		{
		}

		ImGui::EndMainMenuBar();
	}
}
void Win32UILayer::OnInit()
{
	IMGUI_CHECKVERSION();
	m_MainContext = ImGui::CreateContext();
	m_MainContext->WantCaptureMouseNextFrame;
	ImGuiIO& io = ImGui::GetIO(); // Enable ImGui IO
	io.WantCaptureMouse;
	(void)io;

	ImGui::SetCurrentContext(m_MainContext);

	ImGui_ImplWin32_Init(m_Hwnd);
	const char* gl_ver = "#version 450 core";
	ImGui_ImplOpenGL3_Init(gl_ver);
	ImGui::StyleColorsDark();

	//m_MainContext->CurrentWindow->Flags |= ImGuiWindowFlags_MenuBar;
}
