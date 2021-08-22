#pragma once

#include "Basic.h"
#include <vector>

using namespace std;

void SettingsWIN() {

    ImGui::Begin("Settings", NULL, //BEGIN RECT OF TRIGGER SETTINGS
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoScrollbar
    );

    ImGui::SetWindowPos(ImVec2(0, 0)); //SELF EXPLAIN
    ImGui::SetWindowSize(ImVec2(basicsWidth, 55));

    ImGui::TextColored(fade, "Settings"); //TITLE

    static int sfps = settings.fade_fps; //GRABS THE VALUE OF DEFAULT TRIGGER SCAN SIZE

    ImGui::Text("Fade speed: ");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(basicsWidth - ImGui::GetWindowPos().x - 112); //FIT TO THE RECT
    ImGui::SliderInt("##fade_fps_slider", &sfps, 1, 100, "%dfps"); //SET THE SLIDER VALUE TO THE DEFAULT TRIGGER SCAN SIZE

    settings.fade_fps = sfps;  //REPLACE THE TRIGGER SCAN SIZE WITH THE SLIDER VALUE (ON CHANGE/OR NOT)

    ImGui::End();
}