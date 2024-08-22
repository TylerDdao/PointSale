#pragma once
#include <iostream>
using namespace std;
static string staffName = "\0";

#define MAX_CHARS 50
#define MAX_ITEM_ID 10
#define MAX_ITEM_NAME 25
#define MAX_EMPLOYEE_ID 5

class InputField {
public:
    char inputText[MAX_CHARS + 1] = { 0 };
    int textLength = 0;
    bool isActive = false;
    bool hasDecimalPoint = false;

    InputField();
    void Clear();
};
