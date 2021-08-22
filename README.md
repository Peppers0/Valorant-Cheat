# Valorant Color Based Cheat  
  
Basically the cheat will search for a defined area arround the middle screen, check if the HSV color is purple (Defined inside [HSV](features/HSV.h) and [AIMBOT](features/Aim.h) / [TRIGGERBOT](features/Trigger.h)), and if you're pressing the keybind it will work.  
<br>
Using [ImGui](https://github.com/ocornut/imgui) for the cheat menu, there you can change trigger/aimbot "scan size"/"delay" separately.   

# Requirements  
  
- [ImGui](https://github.com/ocornut/imgui)  
- [Glfw](https://www.glfw.org/download)
- [Visual Studio](visualstudio.microsoft.com/)
- [Arduino Micro/Leonard](https://store.arduino.cc/usa/arduino-micro) 
- Purple enemy outline inside valorant settings  
  
# Anti Cheat  
  
Recently Valorant AC is blocking 2nd mouse input, arduino became useless, aimbot wont work but trigger should work fine. 
 
# Features  
 
- Trigger (while pressing VK_XBUTTON2)
- Aimbot (while pressing VK_XBUTTON1)
- Toggle menu (insert)
- Panic button (delete)
- Shit Menu
