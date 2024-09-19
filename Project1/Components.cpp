#include "Components.h"
#include "raylib.h"

void DrawCurrentTime(int posX, int posY, int fontSize, Color tColor)
{
    string currentTime = GetCurrentDateTime();
    DrawText(TextFormat("%s - %d/%d/%d", ExtractTime(currentTime).c_str(), ExtractMonth(currentTime), ExtractDay(currentTime), ExtractYear(currentTime)), posX, posY, fontSize, BLACK);
}

void DrawRec(Rectangle rec,Color bColor, Color lColor)
{
	DrawRectangleRec(rec, bColor);
	DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, lColor);
}

void DrawRec(Rectangle rec, const char* text, Color bColor, Color lColor, Color tColor, int fontSize, int align)
{
    DrawRectangleRec(rec, bColor);
    DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, lColor);
    Vector2 textDimension = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
    if (align == LEFT) {
        DrawText(text, rec.x + 5, (rec.y + (rec.height / 2)) - (textDimension.y / 2), fontSize, tColor);
    }
    else if (align == CENTER) {
        DrawText(text, (rec.x + (rec.width / 2)) - (textDimension.x / 2)-5, (rec.y + (rec.height / 2)) - (textDimension.y / 2), fontSize, tColor);
    }
    else if (align == RIGHT) {
        DrawText(text, (rec.x + rec.width) - textDimension.x - 5, (rec.y + (rec.height / 2)) - (textDimension.y / 2), fontSize, tColor);
    }
}

void DrawTextOnRec(Rectangle rec, const char* text, int fontSize, Color tColor, int align)
{
	Vector2 textDimension = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
	if (align == LEFT) {
		DrawText(text, rec.x+5, (rec.y+(rec.height/2)) - (textDimension.y/2), fontSize, tColor);
	}
	else if (align == CENTER) {
		DrawText(text, (rec.x +(rec.width / 2)) - (textDimension.x / 2), (rec.y + (rec.height / 2)) - (textDimension.y / 2), fontSize, tColor);
	}
	else if (align == RIGHT) {
		DrawText(text, (rec.x + rec.width) - textDimension.x -5, (rec.y + (rec.height / 2)) - (textDimension.y / 2), fontSize, tColor);
	}
}

void DrawTextOnRec(Rectangle rec, int posY, const char* text, int fontSize, Color tColor, int align)
{
	Vector2 textDimension = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
	if (align == LEFT) {
		DrawText(text, rec.x + 5, posY, fontSize, tColor);
	}
	else if (align == CENTER) {
		DrawText(text, (rec.x + (rec.width / 2)) - (textDimension.x / 2), posY, fontSize, tColor);
	}
	else if (align == RIGHT) {
		DrawText(text, (rec.x + rec.width) - textDimension.x-5, posY, fontSize, tColor);
	}
}

void DrawItemBox(Rectangle rec, Color bColor, Color lColor, Color tColor,int fontSize, Item item)
{
    DrawRectangleRec(rec, bColor);
    DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, lColor);
    Vector2 textSize = MeasureTextEx(GetFontDefault(), item.GetName().c_str(), fontSize, 1);
    DrawText(TextFormat("%s", item.GetName().c_str()), rec.x + 5, rec.y + 5, fontSize, tColor);
    DrawText(TextFormat("%s | $%.3f", item.GetId().c_str(), item.GetPrice()), rec.x + 5, rec.y + 5+textSize.y, fontSize, tColor);
}

void DrawEmployeeBox(int posX, int posY, Color bColor, Color lColor, Color tColor, Employee employee)
{
    Rectangle employeeBox = { posX, posY, 400,100 };
    DrawRec(employeeBox, bColor, lColor);
    DrawTextOnRec(employeeBox, employeeBox.y + 10, TextFormat("ID: %s", employee.GetId().c_str()), 30, tColor, LEFT);
    DrawTextOnRec(employeeBox, employeeBox.y + 40, TextFormat("Name: %s", employee.GetName().c_str()), 30, tColor, LEFT);
}

void DrawInputField(Rectangle rec, string& savedText, Color bColor, Color lColor, Color tColor, int fontSize, int MaxChars, InputField& inputField)
{
    // Check if mouse is over the box
    bool mouseOver = CheckCollisionPointRec(GetMousePosition(), rec);

    // Activate the box if clicked
    if (mouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        inputField.isActive = true;
    }
    else if (!mouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        inputField.isActive = false;
    }

    // Draw the box
    DrawRectangle(rec.x, rec.y, rec.width, rec.height, bColor);
    DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, inputField.isActive ? RED : lColor);

    // Handle input only if active
    if (inputField.isActive) {
        // Input handling logic
        if (IsKeyPressed(KEY_BACKSPACE) && inputField.textLength > 0) {
            inputField.inputText[--inputField.textLength] = '\0';
        }
        else if (IsKeyPressed(KEY_ENTER)) {
            inputField.isActive = false;
            savedText = inputField.inputText;
        }
        else {
            int key = GetCharPressed();
            if (key != 0 && inputField.textLength < MaxChars) {
                inputField.inputText[inputField.textLength++] = (char)key;
                inputField.inputText[inputField.textLength] = '\0';
            }
        }
    }
    else if (!inputField.isActive && inputField.textLength != 0) {
        savedText = inputField.inputText;
    }
    //else {
    //    savedText = "";
    //}

    // Draw the input text
    DrawText(inputField.inputText, rec.x + 5, rec.y + 5, fontSize, BLACK);
}

void DrawInputField(Rectangle rec, int& savedInt,Color bColor, Color lColor, Color tColor, int fontSize, int MaxChars, InputField& inputField)
{
    // Check if mouse is over the box
    bool mouseOver = CheckCollisionPointRec(GetMousePosition(), rec);

    // Activate the box if clicked
    if (mouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        inputField.isActive = true;
    }
    else if (!mouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        inputField.isActive = false;
    }
    // Draw the box
    DrawRectangle(rec.x, rec.y, rec.width, rec.height, bColor);
    DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, inputField.isActive ? RED : lColor);

    // Handle input only if active
    if (inputField.isActive) {
        // Input handling logic
        if (IsKeyPressed(KEY_BACKSPACE) && inputField.textLength > 0) {
            inputField.inputText[--inputField.textLength] = '\0';
        }
        else if (IsKeyPressed(KEY_ENTER)) {
            inputField.isActive = false;
        }
        else {
            int key = GetCharPressed();
            if (key != 0 && inputField.textLength < MaxChars && isdigit(key)) {
                inputField.inputText[inputField.textLength++] = (char)key;
                inputField.inputText[inputField.textLength] = '\0';
            }
        }
    }
    else if (!inputField.isActive && inputField.textLength != 0) {
        savedInt = stoi(inputField.inputText);
    }
    //else {
    //    savedInt = 0;
    //}

    // Draw the input text
    DrawText(inputField.inputText, rec.x + 5, rec.y + 5, fontSize, BLACK);
}

void DrawInputField(Rectangle rec, float& savedFloat, Color bColor, Color lColor, Color tColor, int fontSize,int MaxChars, InputField& inputField) {
    // Check if mouse is over the box
    bool mouseOver = CheckCollisionPointRec(GetMousePosition(), rec);

    // Activate the box if clicked
    if (mouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        inputField.isActive = true;
    }
    else if (!mouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        inputField.isActive = false;
    }

    // Draw the box
    DrawRectangle(rec.x, rec.y, rec.width, rec.height, bColor);
    DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, inputField.isActive ? RED : lColor);

    // Handle input only if active
    if (inputField.isActive) {
        // Input handling logic
        if (IsKeyPressed(KEY_BACKSPACE) && inputField.textLength > 0) {
            if (inputField.inputText[inputField.textLength - 1] == '.') {
                inputField.hasDecimalPoint = false;
            }
            inputField.inputText[--inputField.textLength] = '\0';
        }
        else if (IsKeyPressed(KEY_ENTER)) {
            inputField.isActive = false;
        }
        else {
            int key = GetCharPressed();
            if (key != 0 && inputField.textLength < MaxChars) {
                if (isdigit(key)) {
                    inputField.inputText[inputField.textLength++] = (char)key;
                    inputField.inputText[inputField.textLength] = '\0';
                }
                else if (key == '.' && !inputField.hasDecimalPoint) {
                    inputField.inputText[inputField.textLength++] = '.';
                    inputField.inputText[inputField.textLength] = '\0';
                    inputField.hasDecimalPoint = true;
                }
            }
        }
    }
    else if (!inputField.isActive && inputField.textLength != 0) {
        if (IsNumberOrDecimal(inputField.inputText)) {
            savedFloat = atof(inputField.inputText);
        }
    }
    //else {
    //    savedFloat = 0.0f;
    //}

    // Draw the input text
    DrawText(inputField.inputText, rec.x + 5, rec.y + 5, fontSize, tColor);
}

bool IsNumberOrDecimal(const char* str) {
    if (str == nullptr || *str == '\0') {
        return false;
    }

    bool hasDecimalPoint = false;

    // Check for optional negative sign
    if (*str == '-') {
        str++;
    }

    // Check for digits and decimal point
    while (*str != '\0') {
        if (isdigit(*str)) {
            return true;
        }
        else if (*str == '.' && !hasDecimalPoint) {
            hasDecimalPoint = true;
        }
        else {
            return false; // Invalid character
        }
        str++;
    }

    return true;
}

void DrawCharIndicator(int posX, int posY, int fontSize, Color tColor, InputField inputField, int maxChar)
{
    if (inputField.textLength < maxChar) {
        DrawText(TextFormat("%d/%d", maxChar - inputField.textLength, maxChar), posX, posY, fontSize, tColor);
    }
    else {
        DrawText(TextFormat("%d/%d", maxChar - inputField.textLength, maxChar), posX, posY, fontSize, RED);
    }
}

void DrawItemSoldBox(int posX, int posY, Item item, int sold)
{
    Rectangle itemBox = { posX, posY, 400,100 };
    DrawRec(itemBox, WHITE, BLACK);
    DrawTextOnRec(itemBox, posY + 10, TextFormat("%s", item.GetName().c_str()), 30, BLACK,LEFT);
    DrawTextOnRec(itemBox, posY + 50, TextFormat("Sold: %d", sold), 30, BLACK, LEFT);
}
