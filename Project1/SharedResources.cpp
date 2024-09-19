#include "SharedResources.h"

InputField::InputField()
{
    this->inputText[0] = '\0';
    this->isActive = false;
    this->textLength = 0;
    this->hasDecimalPoint = false;
}

void InputField::Clear()
{
    this->inputText[0] = '\0';
    this->isActive = false;
    this->textLength = 0;
    this->hasDecimalPoint = false;
}

DisplayVars::DisplayVars()
{
    for (size_t i = 0; i < isActive.size();i++) {
        isActive.pop_back();
    }
    this->count = 0;
    this->currentPage = 1;
    this->totalPage = 1;
    this->remainder = 0;
}

void DisplayVars::ClearAll()
{
    for (size_t i = 0; i < isActive.size();i++) {
        isActive.pop_back();
    }
    this->count = 0;
    this->currentPage = 1;
    this->totalPage = 1;
    this->remainder = 0;
}


DefaultVars::DefaultVars()
{
}

bool DefaultVars::SetTax(float value)
{
    this->taxRate = value;
    return true;
}

InterScreensVars::InterScreensVars()
{
    currertMenu = nullptr;
    currentItem = nullptr;
    currentOrder = nullptr;
    currentSale = nullptr;
    currentEmployee = nullptr;
    this->day = 0;
    this->month = 0;
    this->year = 0;
    this->stringId = "\0";
}

void InterScreensVars::ClearAll()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
    currertMenu = nullptr;
    currentItem = nullptr;
    currentOrder = nullptr;
    currentSale = nullptr;
    currentEmployee = nullptr;
    this->stringId = "\0";
}

void InterScreensVars::ClearCurrentItem()
{
    currentItem = nullptr;
}

void InterScreensVars::ClearCurrentOrder()
{
    currentOrder = nullptr;
}

void InterScreensVars::ClearCurrentSale()
{
    currentSale = nullptr;
}

void InterScreensVars::ClearCurrentEmployee()
{
    currentEmployee = nullptr;
}

void InterScreensVars::ClearStringId()
{
    this->stringId = "\0";
}

void InterScreensVars::ClearDate()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

bool InterScreensVars::SetDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    return true;
}

bool InterScreensVars::SetItem(Item* ptr)
{
    currentItem = ptr;
    return true;
}

bool InterScreensVars::SetMenu(Menu* ptr)
{
    currertMenu = ptr;
    return true;
}

bool InterScreensVars::SetOrder(Order* ptr)
{
    currentOrder = ptr;
    return true;
}

bool InterScreensVars::SetSale(Sale* ptr)
{
    currentSale = ptr;
    return true;
}

bool InterScreensVars::SetEmployee(Employee* ptr)
{
    currentEmployee = ptr;
    return true;
}

bool InterScreensVars::SetStringId(string id)
{
    this->stringId = id;
    return true;
}

int InterScreensVars::GetDay()
{
    return day;
}

int InterScreensVars::GetMonth()
{
    return month;
}

int InterScreensVars::GetYear()
{
    return year;
}

string InterScreensVars::GetStringId()
{
    return stringId;
}

Menu* InterScreensVars::GetMenu()
{
    return currertMenu;
}

Item* InterScreensVars::GetItem()
{
    return currentItem;
}

Order* InterScreensVars::GetOrder()
{
    return currentOrder;
}

Sale* InterScreensVars::GetSale()
{
    return currentSale;
}

Employee* InterScreensVars::GetEmployee()
{
    return currentEmployee;
}
