// 3DMMS.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "Window.h"
#include "Camera.h"
#include "Event.h"
#include "Mouse.h"
#include "KeyBoard.h"
#include "SceneEvent.h"
#include "TimeStep.h"
//#include "Square.h"

#include "UI.h"
#include <opencv2/calib3d/calib3d_c.h>
#include <opencv2/calib3d/calib3d.hpp>
// TODO: Reference additional headers your program requires here.
//#include "csv.hpp"
//#include "Dependencies/CSV/csv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "sba.h"
#include "compiler.h"
#include "eucsbademo.h"
#include "readparams.h"
#include "eucsbademo.h"

#include "QuadrupedDynamics.h"

/*

#ifndef _SBA_DEMO_H_
#define _SBA_DEMO_H_

#define SBA_MAX_REPROJ_ERROR    4.0 // max motion only reprojection error

#define BA_NONE                 -1
#define BA_MOTSTRUCT            0
#define BA_MOT                  1
#define BA_STRUCT               2
#define BA_MOT_MOTSTRUCT        3

///* in imgproj.c 
extern void calcImgProj(double a[5], double qr0[4], double v[3], double t[3], double M[3], double n[2]);
extern void calcImgProjFullR(double a[5], double qr0[4], double t[3], double M[3], double n[2]);
extern void calcImgProjJacKRTS(double a[5], double qr0[4], double v[3], double t[3], double M[3], double jacmKRT[2][11], double jacmS[2][3]);
extern void calcImgProjJacKRT(double a[5], double qr0[4], double v[3], double t[3], double M[3], double jacmKRT[2][11]);
extern void calcImgProjJacS(double a[5], double qr0[4], double v[3], double t[3], double M[3], double jacmS[2][3]);
extern void calcImgProjJacRTS(double a[5], double qr0[4], double v[3], double t[3], double M[3], double jacmRT[2][6], double jacmS[2][3]);
extern void calcImgProjJacRT(double a[5], double qr0[4], double v[3], double t[3], double M[3], double jacmRT[2][6]);
extern void calcDistImgProj(double a[5], double kc[5], double qr0[4], double v[3], double t[3], double M[3], double n[2]);
extern void calcDistImgProjFullR(double a[5], double kc[5], double qr0[4], double t[3], double M[3], double n[2]);
extern void calcDistImgProjJacKDRTS(double a[5], double kc[5], double qr0[4], double v[3], double t[3], double M[3], double jacmKDRT[2][16], double jacmS[2][3]);
extern void calcDistImgProjJacKDRT(double a[5], double kc[5], double qr0[4], double v[3], double t[3], double M[3], double jacmKDRT[2][16]);
extern void calcDistImgProjJacS(double a[5], double kc[5], double qr0[4], double v[3], double t[3], double M[3], double jacmS[2][3]);

///* in eucsbademo.c
extern void sba_driver(char* camsfname, char* ptsfname, char* calibfname, int cnp, int pnp, int mnp,
	void (*caminfilter)(double* pin, int nin, double* pout, int nout),
	void (*camoutfilter)(double* pin, int nin, double* pout, int nout),
	int cnfp, char* refcamsfname, char* refptsfname);

#endif /* _SBA_DEMO_H_ 

*/

std::vector<Vertex> m_mesh_points;

class Quadruped
{
public:

	uint32_t m_CurrentFrame;
	uint32_t m_NumberofFrames;
	std::vector<std::string> m_FirstStereoPairFileNames;
	std::vector<Mesh> m_Frames;

	Quadruped() : m_NumberofFrames{ 0 },
		m_CurrentFrame{ 0 }, 
		m_FirstStereoPairFileNames {}
	{

	}
	Quadruped(std::vector<std::string> m_filepaths) :
		m_CurrentFrame{ 0 },
		m_NumberofFrames{ 0 },
		m_FirstStereoPairFileNames{ m_filepaths }
	{
		for (auto str : m_filepaths)
		{
			LoadFramesFromeCSV(str);
		}
	}

	Quadruped(std::string first_frame) :
		m_CurrentFrame{ 0 },
		m_NumberofFrames{ 0 },
		m_FirstStereoPairFileNames{}
	{
		m_FirstStereoPairFileNames.push_back(first_frame);
		//LoadFramesFromeCSV();
	}

	void AdvanceFrame();
	void LoadFramesFromeCSV(std::string csv_filepath);
	Mesh GetCurrentFrame() { return m_Frames[m_CurrentFrame]; }
};



void DoSomeThing()
{

	std::fstream new_file("Output_points.txt", std::ios::out);
	if (!new_file.is_open())
	{
		std::cerr << "Failed to Create The output file" << std::endl;
	}
	// SET UP THE PAIRWISE PROJECTION MATRICES
	cv::Matx<double, 3, 4> cam1_temp_matrix({526.311f, 0.0f, 861.3363f, 0.0f, 0.0f, 503.3131f, 567.7418f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f});
	cv::Matx<double, 3, 4> cam2_temp_matrix({ -0.479457659599983, - 0.730103805070898,	0.486897100496504, - 5233.59502106588,
							- 0.827042958119812,	0.561465060865778,	0.0275123763317475, - 4217.57296114200,
							- 0.293462600811992, - 0.389493798728534, - 0.873025934710234,	12667.7930065311 });
	cv::InputArray cam1_k(cam1_temp_matrix);
	cv::InputArray cam2_k(cam2_temp_matrix);

	cv::Mat cam1_temp_d({-0.431242225300654, 0.903111890674575, 0.0, 0.0 });
	cv::Mat cam2_temp_d({-0.431242225300654, 0.903111890674575, 0.0, 0.0 });
	cv::InputArray cam1_d(cam1_temp_d);
	cv::InputArray cam2_d(cam2_temp_d);

	cv::Mat cam2_temp_r({ -0.431242225300654, 0.903111890674575, 0.0, 0.0 });
	cv::InputArray cam2_r(cam2_temp_r);

	std::vector<cv::Point2d> cam1_temp_points{
		cv::Point2d(1523.0343679558262, 626.5984257747566),
		cv::Point2d(1545.9584105337703, 650.341184159056),
		cv::Point2d(1595.0813589150791, 656.072194803542),
		cv::Point2d(1654.847612779005, 627.8264994842893),
		cv::Point2d(1731.3975406732113, 793.2070923680292),
		cv::Point2d(1725.2571721255476, 643.7914577082147),
		cv::Point2d(1697.7908159002836, 845.0355906702051),
		cv::Point2d(1835.7444292711261, 776.6728208395502),
		cv::Point2d(1857.03104023636, 851.1759592178687),
		cv::Point2d(1900.0136200700056, 673.5146292388017) };

	std::vector<cv::Point2d> cam2_temp_points = {
		cv::Point2d(698.3733770627184, 628.7765905307556),
		cv::Point2d(685.930185596608, 644.0131515096657),
		cv::Point2d(659.0122612005338, 638.4264124840654),
		cv::Point2d(630.8246233895502, 613.2860868688637),
		cv::Point2d(714.230418880207, 726.8262738054256),
		cv::Point2d(524.3031222797949, 629.6949667510098),
		cv::Point2d(302.33208079282747, 820.8025457635827),
		cv::Point2d(390.3731474289102, 734.6271002168124),
		cv::Point2d(269.07497065047676, 793.3741265769235),
		cv::Point2d(433.15488878401214, 638.0999944601641)
	};

	cv::Mat pt_set1_pt(cam1_temp_points), pt_set2_pt(cam2_temp_points);

	//cv::undistort(cam1_temp_points, pt_set1_pt, cam1_k, cam1_d);
	//cv::undistort(cam2_temp_points, pt_set2_pt, cam2_k, cam2_d);
	int N = cam1_temp_points.size();

	cv::Mat pt_set1_pt_2r = pt_set1_pt.reshape(1, 2);
	cv::Mat pt_set2_pt_2r = pt_set2_pt.reshape(1, 2);
	cv::Mat pt_3d_h(N, cam1_temp_points.size(), CV_32FC4);

	// NOW CONVERT THE POINTS TO HOMOGENEOUS COORDINATES

	std::vector<cv::Point3f> pt_3d;

	cv::triangulatePoints(cam1_k, cam2_k, pt_set1_pt_2r, pt_set2_pt_2r, pt_3d_h);

	pt_3d_h = pt_3d_h.reshape(4, N);
	std::cout << pt_3d_h << std::endl;
	//cv::convertPointsToHomogeneous(pt_3d_h, pt_3d);

	std::vector<glm::vec3> m_3d;
	
	for (uint32_t index = 0; index < N; index++)
	{
		auto p1 = pt_3d_h.at<cv::Matx<double, 4, 1>>(index);
		
		glm::vec3 pt = glm::vec3(p1(0), p1(1), p1(2));
		glm::vec3 pt_adj = glm::vec3(p1(0)/p1(3), p1(1)/p1(3), p1(2)/p1(3));

		m_3d.push_back(pt);
		//m_mesh_points.push_back(Vertex{ {pt_adj},{0.0, 0.0}, index,{0.0, 1.0, 0.0}});
		new_file << p1(0)/p1(3) << ", " << p1(1)/p1(3) << ", " << p1(2)/p1(3) << std::endl;
	}


	new_file.close();		
}

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
		//t_start = static_cast<double>(m_Window.milliseconds_now());
		m_Window.StartTimer();
	}

	void BeginFrame() 
	{ 
		m_UILayer.BeginFrame(); 
		m_UILayer.OnRender();
		//m_Window.SwapBuffer();
	}
	void EndFrame() 
	{ 
		m_UILayer.EndFrame();
		m_Window.SwapBuffer();
	}

	void EndTimer() {
		//t_end = static_cast<double>(m_Window.milliseconds_now());
		m_Window.EndTimer();
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
		m_Cam.m_eye = glm::vec3(0.0f, 5.0f, 5.0f);
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
