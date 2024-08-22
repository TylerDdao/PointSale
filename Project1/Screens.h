#pragma once
#include "Zones.h"
#include "Time.h"
#include "React.h"

enum Screen { Home = 0, R_Login, R_Home, R_Menu, Quit};
static int screen = Home;

void HomeScreen(int& screen);

void RLogin(int& screen);