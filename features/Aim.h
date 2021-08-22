#pragma once

#include "../Basic.h"
#include "serial/SimpleSerial.h"

using namespace std;

class Aim {
	public:
		static void move(int x, int y) {
			char com_port[] = "\\\\.\\COM10";
			DWORD COM_BAUD_RATE = CBR_9600;
			SimpleSerial serial(com_port, COM_BAUD_RATE);

			if (serial.connected_) {
				char data[255] = "";

				char bufferX[100];
				sprintf_s(bufferX, "%d", x);

				char bufferY[100];
				sprintf_s(bufferY, "%d", y);

				strcat_s(data, bufferX);
				strcat_s(data, ",");
				strcat_s(data, bufferY);

				serial.WriteSerialPort(data);
			}

		};

		static void loop() {
			Screen::getSize();

			int x = Screen::width / 2;  //DONT NEED TO BE CALLED EVERY TICK, THE DESKTOP MONITOR SIZE DOESNT CHANGE!
			int y = Screen::height / 2; //DONT NEED TO BE CALLED EVERY TICK, THE DESKTOP MONITOR SIZE DOESNT CHANGE!

			RGBTRIPLE rgbTriple;
			HDC desktopHdc = GetDC(NULL);

			int addX = 0, addY = 0;

			int grabbX = 0, grabbY = 0;

			while (1) {
				int AIM_SIZE = settings.Aim_ScanSize;
				if (GetAsyncKeyState(VK_XBUTTON1) && isDown) { //IS PRESSING AIM KEY
					for (int iX = 0; iX < AIM_SIZE; iX++) {
						for (int iY = 0; iY < AIM_SIZE; iY++) {

							if (iX >= AIM_SIZE / 2) addX = ((AIM_SIZE / 2) - iX); //MAKES A x RECT AROUND THE MIDDLE SCREEN
							if (iX < AIM_SIZE / 2) addX = ((AIM_SIZE / 2) - iX); //MAKES A x RECT AROUND THE MIDDLE SCREEN

							if (iY >= AIM_SIZE / 2) addY = (iY - (AIM_SIZE / 2)); //MAKES A y RECT AROUND THE MIDDLE SCREEN
							if (iY < AIM_SIZE / 2) addY = (iY - (AIM_SIZE / 2)); //MAKES A y RECT AROUND THE MIDDLE SCREEN

							COLORREF color = GetPixel(desktopHdc, x + addX, y + addY);

							rgbTriple.rgbtRed = GetRValue(color);
							rgbTriple.rgbtGreen = GetGValue(color);
							rgbTriple.rgbtBlue = GetBValue(color);

							Color::HSV rgbToHue = toHSV((float)rgbTriple.rgbtRed, (float)rgbTriple.rgbtGreen, (float)rgbTriple.rgbtBlue);
							Color::ColorName name = Categorize(rgbToHue);
							string cname = Color::toString(name);

							if (cname == "magenta") {
								if (rgbToHue.s * 100 <= 80 && rgbToHue.s * 100 > 15) {
									if (GetAsyncKeyState(VK_XBUTTON1) && isDown) {
										if (grabbX == 0) grabbX = addX;
										if (grabbY == 0) grabbY = addY;

										int pAddX = addX;
										int pAddY = addY;

										if (addX < 0) pAddX = addX * -1;
										if (pAddX < grabbX) grabbX = addX;

										if (addY < 0) pAddX = addY * -1;
										if (pAddY < grabbY) grabbX = addY;

										int mX = (grabbX + 1);
										int mY = (grabbY + 1);

										move(1, 1);
									}
								}
							}
						}
					}
				}
			}
		};
};