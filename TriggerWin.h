#pragma once

#include "Basic.h"
#include <vector>

using namespace std;

void TriggerWIN() {
    
    ImGui::Begin("Trigger", NULL, //BEGIN RECT OF TRIGGER SETTINGS
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus | 
        ImGuiWindowFlags_NoResize | 
        ImGuiWindowFlags_NoCollapse | 
        ImGuiWindowFlags_NoSavedSettings
    );
    
    ImGui::SetWindowPos(ImVec2(0, 60)); //SELF EXPLAIN
    ImGui::SetWindowSize(ImVec2(basicsWidth, 100));

    ImGui::TextColored(fade, "Trigger"); //TITLE

    static int ssize = settings.Trigger_ScanSize; //GRABS THE VALUE OF DEFAULT TRIGGER SCAN SIZE
    
    ImGui::Text("Scan area: ");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(basicsWidth - ImGui::GetWindowPos().x - 112); //FIT TO THE RECT
    ImGui::SliderInt("##trigger_scan_slider", &ssize, 1, 50, "%dpx"); //SET THE SLIDER VALUE TO THE DEFAULT TRIGGER SCAN SIZE
    
    settings.Trigger_ScanSize = ssize;  //REPLACE THE TRIGGER SCAN SIZE WITH THE SLIDER VALUE (ON CHANGE/OR NOT)

    static int sdelay = settings.Trigger_Delay.count();  //GRABS THE VALUE OF DEFAULT TRIGGER DELAY

    ImGui::Text("Delay:     ");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(basicsWidth - ImGui::GetWindowPos().x - 112); //FIT TO THE RECT
    ImGui::SliderInt("##trigger_delay_slider", &sdelay, 0, 200, "%dms"); //SET THE SLIDER VALUE TO THE DEFAULT TRIGGER DELAY
    
    settings.Trigger_Delay = chrono::milliseconds(sdelay); //REPLACE THE TRIGGER DELAY WITH THE SLIDER VALUE (ON CHANGE/OR NOT)

    ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 21); //SET THE NEXT ITEM TO THE BOTTOM OF THE RECT
    ImGui::TextColored(fade, "OH FUCK, THE KEYBINDING METHOD WAS NOT CODED YET!");

    ImGui::End();
}