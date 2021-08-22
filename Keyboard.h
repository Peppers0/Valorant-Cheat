#pragma once

#include "Basic.h"

class KeyBoard {
    public:
        static void keyboard() {
            while (1) {
                if (GetAsyncKeyState(VK_INSERT) && isDown)
                {
                    shouldDraw = !shouldDraw;
                    this_thread::sleep_for(300ms);
                }
                if (GetAsyncKeyState(VK_DELETE) && isDown)
                {
                    glfwSetWindowShouldClose(window, true);
                    this_thread::sleep_for(300ms);
                }
            }
        }
};