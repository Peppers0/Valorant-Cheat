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
  
# Arduino code  
   
Send data to comport like: x,y
If send '15,9' arduino will move your mouse 15 to x and 9 to y (15 right 9 down)
  
```ino
#include <Mouse.h>

void setup() {
  Mouse.begin();
  Serial.begin(9600);
  Serial.setTimeout(0);
}

void loop() {
  if(Serial.available() > 0) {
    String rawdata = Serial.readString();
    String _x = split(rawdata, ',', 0);
    String _y = split(rawdata, ',', 1);

    if((_x != "") && (_y != "")) {
      int x = _x.toInt();
      int y = _y.toInt();

      Mouse.move(x, y);
    }
  }
}

String split(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

```
