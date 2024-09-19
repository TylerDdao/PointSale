#pragma once
#include "iostream"
#include "SharedResources.h"
#include "Time.h"
#include "raylib.h"

using namespace std;

void DrawCurrentTime(int posX, int posY, int fontSize, Color tColor);

void DrawRec(Rectangle rec, Color bColor, Color lColor);
void DrawRec(Rectangle rec, const char* text, Color bColor, Color lColor, Color tColor, int fontSize, int align);
void DrawTextOnRec(Rectangle rec, const char* text, int fontSize, Color tColor, int align);
void DrawTextOnRec(Rectangle rec, int posY, const char* text, int fontSize, Color tColor, int align);
void DrawItemBox(Rectangle rec, Color bColor, Color lColor, Color tColor, int fontSize, Item item);
void DrawEmployeeBox(int posX, int posY, Color bColor, Color lColor, Color tColor, Employee employee);
void DrawInputField(Rectangle rec, string& savedText, Color bColor, Color lColor, Color tColor, int fontSize, int MaxChars, InputField& inputField);
void DrawInputField(Rectangle rec, int& savedInt, Color bColor, Color lColor, Color tColor, int fontSize, int MaxChars, InputField& inputField);
void DrawInputField(Rectangle rec, float& savedFloat, Color bColor, Color lColor, Color tColor, int fontSize, int MaxChars, InputField& inputField);
bool IsNumberOrDecimal(const char* str);
void DrawCharIndicator(int posX, int posY, int fontSize, Color tColor, InputField inputField, int maxChar);
void DrawItemSoldBox(int posX, int posY, Item item, int sold);

