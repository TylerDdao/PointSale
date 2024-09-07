#pragma once
#include <iostream>
#include <vector>
#include "Sale.h"
using namespace std;

#define MAX_CHARS 50
#define MAX_ITEM_ID 10
#define MAX_ITEM_NAME 25
#define MAX_EMPLOYEE_ID 10

class InputField {
public:
    char inputText[MAX_CHARS + 1] = { 0 };
    int textLength = 0;
    bool isActive = false;
    bool hasDecimalPoint = false;

    InputField();
    void Clear();
};

class DisplayVars {
public:
    int count;
    int totalPage;
    int currentPage;
    int remainder;
    vector<bool> isActive;

    DisplayVars();
    void ClearAll();
};

class DefaultVars {
public:
    float taxRate;

    DefaultVars();
    bool SetTax(float value);
};

static string staffName = "\0";
static int prevScreen = 0;
static Sale saleTemp;