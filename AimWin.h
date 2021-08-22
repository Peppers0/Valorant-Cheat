#pragma once

#include "Basic.h"
#include <vector>

using namespace std;

void AimWIN() {
    
    ImGui::Begin("Aimbot", NULL, //BEGIN RECT OF TRIGGER SETTINGS
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus | 
        ImGuiWindowFlags_NoResize | 
        ImGuiWindowFlags_NoCollapse | 
        ImGuiWindowFlags_NoSavedSettings
    );
    
    ImGui::SetWindowPos(ImVec2(0, 165)); //SELF EXPLAIN
    ImGui::SetWindowSize(ImVec2(basicsWidth, 80));

    ImGui::TextColored(fade, "Aimbot"); //TITLE

    static int ssize = settings.Aim_ScanSize; //GRABS THE VALUE OF DEFAULT TRIGGER SCAN SIZE
    
    ImGui::Text("Scan area: ");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(basicsWidth - ImGui::GetWindowPos().x - 112); //FIT TO THE RECT
    ImGui::SliderInt("##aim_scan_slider", &ssize, 1, 50, "%dpx"); //SET THE SLIDER VALUE TO THE DEFAULT TRIGGER SCAN SIZE
    
    settings.Aim_ScanSize = ssize;  //REPLACE THE TRIGGER SCAN SIZE WITH THE SLIDER VALUE (ON CHANGE/OR NOT)

    static int sdelay = settings.Aim_Move_Delay.count();  //GRABS THE VALUE OF DEFAULT TRIGGER DELAY
    
    ImGui::Text("Mouse Speed:");
    ImGui::SameLine();
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 7);
    ImGui::SetNextItemWidth(basicsWidth - ImGui::GetWindowPos().x - 112); //FIT TO THE RECT
    ImGui::SliderInt("##aim_delay_slider", &sdelay, 1, 30, "%dms"); //SET THE SLIDER VALUE TO THE DEFAULT TRIGGER DELAY
    
    settings.Aim_Move_Delay = chrono::milliseconds(sdelay); //REPLACE THE TRIGGER DELAY WITH THE SLIDER VALUE (ON CHANGE/OR NOT)

    ImGui::End();
}