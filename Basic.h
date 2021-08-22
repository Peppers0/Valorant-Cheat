#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_opengl3_loader.h"

#include <stdio.h>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <sstream>

#include <GLFW/glfw3.h> 

#include "features/HSV.h"
#include "features/Screen.h"
#include "features/Keys.h"

//DEFAULT VALUES AND CROSS FILES IMPORTS/DEFINITIONS

int basicsWidth;
int basicsHeight;

GLFWwindow* window;
bool shouldDraw = true;
bool shouldExit = false;

ImVec4 fade(1, 0, 0, 1);

struct Settings { //SETTINGS STRUCT
	int Trigger_ScanSize;
	int Aim_ScanSize;
	int fade_fps = 1;
	chrono::milliseconds Aim_Move_Delay;
	chrono::milliseconds Trigger_Delay;
};

Settings settings; //CREATE SETTINGS USING THE SETTINGS STRUCT