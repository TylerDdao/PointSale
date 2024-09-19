#pragma once
#include "Zones.h"

void Initialize(int screenWidth, int screenHeight, string name, int fps);
void DeInitialize();
void HomeScreen(int& screen);
void NotFound404(int& screen);
void Login(int& screen, Core& system);
void TestScreen(int& screen, Core& system);