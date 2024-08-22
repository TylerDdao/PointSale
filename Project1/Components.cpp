#include "Components.h"

void DrawCurrentTime(float posX, float posY, int fontSize, Color tColor)
{
    string currentTime = GetCurrentDateTime();
    DrawText(TextFormat("%s - %d/%d/%d", ExtractTime(currentTime).c_str(), ExtractMonth(currentTime), ExtractDay(currentTime), ExtractYear(currentTime)), 0, 0, 50, BLACK);
}

void DrawRec(Rectangle rec,Color bColor, Color lColor)
{
	DrawRectangleRec(rec, bColor);
	DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, lColor);
}

void DrawTextOnRec(Rectangle rec, const char* text,float fontSize, Color tColor, int align)
{
	Vector2 textDimension = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
	if (align == LEFT) {
		DrawText(text, rec.x+5, (rec.y+(rec.height/2)) - (textDimension.y/2), fontSize, tColor);
	}
	else if (align == CENTER) {
		DrawText(text, (rec.x +(rec.width / 2)) - (textDimension.x / 2), (rec.y + (rec.height / 2)) - (textDimension.y / 2), fontSize, tColor);
	}
	else if (align == RIGHT) {
		DrawText(text, (rec.x + rec.width) - textDimension.x, (rec.y + (rec.height / 2)) - (textDimension.y / 2), fontSize, tColor);
	}
}

void DrawTextOnRec(Rectangle rec, float posY, const char* text, float fontSize, Color tColor, int align)
{
	Vector2 textDimension = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
	if (align == LEFT) {
		DrawText(text, rec.x + 5, posY, fontSize, tColor);
	}
	else if (align == CENTER) {
		DrawText(text, (rec.x + (rec.width / 2)) - (textDimension.x / 2), posY, fontSize, tColor);
	}
	else if (align == RIGHT) {
		DrawText(text, (rec.x + rec.width) - textDimension.x, posY, fontSize, tColor);
	}
}

void DrawInputField(Rectangle rec, const char* boxTitle, string& savedText, Color bColor, Color lColor, Color tColor, Color titleColor, int fontSize, int titleSize, int MaxChars, InputField& inputField)
{
    Vector2 titleDimension = MeasureTextEx(GetFontDefault(), boxTitle, titleSize, 1);

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
    DrawText(boxTitle, rec.x, rec.y - titleDimension.y, 20, tColor);

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
    else {
        savedText = "";
    }

    // Draw the input text
    DrawText(inputField.inputText, rec.x + 5, rec.y + 5, fontSize, BLACK);
}

void DrawInputField(Rectangle rec, const char* boxTitle, int& savedInt,Color bColor, Color lColor, Color tColor, Color titleColor, int fontSize, int titleSize, int MaxChars, InputField& inputField)
{
    Vector2 textSize = MeasureTextEx(GetFontDefault(), boxTitle, 20, 1);
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
    DrawText(boxTitle, rec.x, rec.y - textSize.y, 20, tColor);

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
    else {
        savedInt = 0;
    }

    // Draw the input text
    DrawText(inputField.inputText, rec.x + 5, rec.y + 5, fontSize, BLACK);
}

void DrawInputField(Rectangle rec, const char* boxTitle, float& savedFloat, Color bColor, Color lColor, Color tColor, Color titleColor, int fontSize, int titleSize, int MaxChars, InputField& inputField) {
    Vector2 textSize = MeasureTextEx(GetFontDefault(), boxTitle, 20, 1);

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
    DrawRectangle(rec.x, rec.y, rec.width, rec.height, LIGHTGRAY);
    DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, inputField.isActive ? RED : BLACK);
    DrawText(boxTitle, rec.x, rec.y - textSize.y, 20, BLACK);

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
            if (key != 0 && inputField.textLength < MAX_CHARS) {
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
    else {
        savedFloat = 0.0f;
    }

    // Draw the input text
    DrawText(inputField.inputText, rec.x + 5, rec.y + 5, fontSize, BLACK);
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

void DrawCharIndicator(float posX, float posY, int fontSize, Color tColor, InputField inputField, int maxChar)
{
    if (inputField.textLength < maxChar) {
        DrawText(TextFormat("%d/%d", maxChar - inputField.textLength, maxChar), posX, posY, fontSize, tColor);
    }
    else {
        DrawText(TextFormat("%d/%d", maxChar - inputField.textLength, maxChar), posX, posY, fontSize, RED);
    }
}
