#include "Window.h"

#include <Windows.h>
#include <iostream>
#include <thread>

using namespace std;

void Window::init() {

    while (1) {
        GetWindowText(GetForegroundWindow(), Window::title, 255);
        this_thread::sleep_for(1s);
    }
}

char Window::title[255] = { };