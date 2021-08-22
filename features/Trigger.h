#pragma once

#include "../Basic.h"

using namespace std;

class Trigger {
	public:
		static void loop() {
			Screen::getSize();

			int x = Screen::width / 2;  //DONT NEED TO BE CALLED EVERY TICK, THE DESKTOP MONITOR SIZE DOESNT CHANGE!
			int y = Screen::height / 2; //DONT NEED TO BE CALLED EVERY TICK, THE DESKTOP MONITOR SIZE DOESNT CHANGE!

			RGBTRIPLE rgbTriple;
			HDC desktopHdc = GetDC(NULL);

			int addX = 0, addY = 0;

			while (1) {
				int TRIGGER_SIZE = settings.Trigger_ScanSize;

				if ((GetAsyncKeyState(VK_XBUTTON2) && isDown) && !(GetAsyncKeyState(VK_LBUTTON) && isDown)) { //IS PRESSING TRIGGER KEY AND ISNT PRESSING THE MOUSE 1
					for (int iX = 0; iX < TRIGGER_SIZE; iX++) {
						for (int iY = 0; iY < TRIGGER_SIZE; iY++) {
							if (iX >= TRIGGER_SIZE / 2) addX = ((TRIGGER_SIZE / 2) - iX); //MAKES A x RECT AROUND THE MIDDLE SCREEN
							if (iX < TRIGGER_SIZE / 2) addX = ((TRIGGER_SIZE / 2) - iX); //MAKES A x RECT AROUND THE MIDDLE SCREEN

							if (iY >= TRIGGER_SIZE / 2) addY = (iY - (TRIGGER_SIZE / 2)); //MAKES A y RECT AROUND THE MIDDLE SCREEN
							if (iY < TRIGGER_SIZE / 2) addY = (iY - (TRIGGER_SIZE / 2)); //MAKES A y RECT AROUND THE MIDDLE SCREEN

							COLORREF color = GetPixel(desktopHdc, x + addX, y + addY);

							rgbTriple.rgbtRed = GetRValue(color);
							rgbTriple.rgbtGreen = GetGValue(color);
							rgbTriple.rgbtBlue = GetBValue(color);

							Color::HSV rgbToHue = toHSV((float)rgbTriple.rgbtRed, (float)rgbTriple.rgbtGreen, (float)rgbTriple.rgbtBlue);
							Color::ColorName name = Categorize(rgbToHue);
							string cname = Color::toString(name);

							if (cname == "magenta") {
								if (rgbToHue.s * 100 <= 80 && rgbToHue.s * 100 > 15) {
									if ((GetAsyncKeyState(VK_XBUTTON2) && isDown) && !(GetAsyncKeyState(VK_LBUTTON) && isDown)) { //IS PRESSING TRIGGER KEY AND ISNT PRESSING THE MOUSE 1
										this_thread::sleep_for(settings.Trigger_Delay);
										keybd_event(VK_K, 0, KEYDOWN, 0);
										this_thread::sleep_for(10ms);
										keybd_event(VK_K, 0, KEYUP, 0);
									}
								}
							}
						}
					}
				}
			}
		};
};