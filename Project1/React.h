#pragma once
#include "raylib.h"
#include "Time.h"
bool IsButtonClicked(Rectangle rec, int key);
bool MonthHas31Days(int month);
bool IsLaterThanToday(int day, int month, int year);