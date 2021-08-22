#include "Basic.h"
#include "WindowManager.h"
#include "Keyboard.h"
#include "Faded.h"
#include "features/Trigger.h"
#include "features/Aim.h"

void exitShouldI()
{
    shouldExit = false;
    while (1)
    {
        #ifndef _DEBUG 
                ShowWindow(GetConsoleWindow(), SW_HIDE); //HIDE CONSOLE
        #else
            ShowWindow(GetConsoleWindow(), SW_SHOW); //HIDE CONSOLE
        #endif

        if (shouldExit == true) exit(0);
    }
}


int main()
{
    #ifdef _DEBUG 
        cout << "BECAREFULL, I KNOW THAT YOU ARE SEEING THIS WITH DEBUG, GUESS WHAT, I'M FUCKING YOUR O.S 32 FOLDER RIGHT NOW" << endl;
    #endif

    thread exit_manager(exitShouldI);
    thread keyboard_manager(KeyBoard::keyboard);
    thread windows_manager(WManager::manage);
    thread trigger_manager(Trigger::loop);
    thread aim_manager(Aim::loop);
    thread fade_manager(Faded::faded);

    exit_manager.join();
    keyboard_manager.join();
    windows_manager.join();
    fade_manager.join();
    trigger_manager.join();
    aim_manager.join();

    return 0;
}