#pragma once

#include "Basic.h"

class Faded {
	public:
		static void faded()
        {
            while (1)
            {
                float amount = 0.01; //FADE ALGORITHIM

                if (fade.x > 0 && fade.z <= 0) {
                    fade.x -= amount;
                    fade.y += amount;
                }
                if (fade.y > 0 && fade.x <= 0) {
                    fade.y -= amount;
                    fade.z += amount;
                }
                if (fade.z > 0 && fade.y <= 0) {
                    fade.x += amount;
                    fade.z -= amount;
                } //END OF FADE ALGORITHIM

                // 1000 MS = 1 S
                chrono::milliseconds delay;
                int ff = settings.fade_fps;
                if (ff == 0) ff = 60;
                delay = chrono::milliseconds(1000 / ff);
                this_thread::sleep_for(delay);
            }
        }
};