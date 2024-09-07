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
