#pragma once
#include "raylib.h"
#include "iostream"
#include "SharedResources.h"
#include "Time.h"

using namespace std;

#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define STRING 3
#define INT 4
#define FLOAT 5

void DrawCurrentTime(int posX, int posY, int fontSize, Color tColor);

void DrawRec(Rectangle rec, Color bColor, Color lColor);
void DrawRec(Rectangle rec, const char* text, Color bColor, Color lColor, Color tColor, int fontSize, int align);
void DrawTextOnRec(Rectangle rec, const char* text, int fontSize, Color tColor, int align);
void DrawTextOnRec(Rectangle rec, int posY, const char* text, int fontSize, Color tColor, int align);

void DrawInputField(Rectangle rec, string& savedText, Color bColor, Color lColor, Color tColor, int fontSize, int MaxChars, InputField& inputField);
void DrawInputField(Rectangle rec, int& savedInt, Color bColor, Color lColor, Color tColor, int fontSize, int MaxChars, InputField& inputField);
void DrawInputField(Rectangle rec, float& savedFloat, Color bColor, Color lColor, Color tColor, int fontSize, int MaxChars, InputField& inputField);
bool IsNumberOrDecimal(const char* str);
void DrawCharIndicator(int posX, int posY, int fontSize, Color tColor, InputField inputField, int maxChar);

