#include "raylib.h"
#include <iostream>
#include "Screens.h"
using namespace std;

int main() {

    const int screenWidth = 1366;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "PointSale (version 1.0)");
    SetTargetFPS(60);
    bool running = true;

    while (running) {
        switch (screen)
        {
        case Home: {
            HomeScreen(screen);
            break;
        }
        case R_Login: {
            RLogin(screen);
            break;
        }
        case Quit: {
            running = false;
            break;
        }
        default:
            //404
            break;
        }
    }

    CloseWindow();
    return 0;
}