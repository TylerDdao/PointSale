#pragma once

#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

string GetCurrentDateTime();

int ExtractYear(string time);

int ExtractMonth(string time);

int ExtractDay(string time);

string ExtractTime(string time);
