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

void DrawCurrentTime(float posX, float posY, int fontSize, Color tColor);

void DrawRec(Rectangle rec, Color bColor, Color lColor);
void DrawTextOnRec(Rectangle rec, const char* text, float fontSize, Color tColor, int align);
void DrawTextOnRec(Rectangle rec, float posY, const char* text, float fontSize, Color tColor, int align);

void DrawInputField(Rectangle rec, const char* boxTitle, string& savedText, Color bColor, Color lColor, Color tColor, Color titleColor, int fontSize, int titleSize, int MaxChars, InputField& inputField);
void DrawInputField(Rectangle rec, const char* boxTitle, int& savedInt, Color bColor, Color lColor, Color tColor, Color titleColor, int fontSize, int titleSize, int MaxChars, InputField& inputField);
void DrawInputField(Rectangle rec, const char* boxTitle, float& savedFloat, Color bColor, Color lColor, Color tColor, Color titleColor, int fontSize, int titleSize, int MaxChars, InputField& inputField);
bool IsNumberOrDecimal(const char* str);
void DrawCharIndicator(float posX, float posY, int fontSize, Color tColor, InputField inputField, int maxChar);

