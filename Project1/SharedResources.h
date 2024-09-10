#pragma once
#include <iostream>
#include <vector>
#include "Core.h"
using namespace std;

#define MAX_CHARS 50
#define MAX_PRICE 10
#define MAX_ITEM_ID 10
#define MAX_MENU_ID 10
#define MAX_ITEM_NAME 25
#define MAX_EMPLOYEE_ID 10

enum Screen { Home = 0, Login_Site, Not_Found_404, Quit,
    R_Home, R_Menu, R_NewOrder, R_Current_Order, R_Confirm,
M_Home, M_Menu_List, M_Menu_Edit, M_Edit_Menu_Id, M_Item_Edit};

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

class InterScreensVars {
public:
    vector<bool> isActive;
    Menu* currertMenu;
    Item* currentItem;
    Order* currentOrder;

    InterScreensVars();
    void ClearAll();
    void ClearCurrentItem();
    void ClearCurrentOrder();
};

static string staffName = "\0";
static int prevScreen = 0;
static InterScreensVars interScreensVars;
static Sale saleTemp;