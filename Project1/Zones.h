#pragma once
#include "Components.h"
#include "Time.h"
#include "React.h"
#include "Core.h"

void MenuListZone(int posX, int posY, Core system, DisplayVars& menuListVars); // Done
void ItemDisplayZone(int posX, int posY, Core system, Menu currentMenu, DisplayVars& itemListVars); //Done
void ItemChoosingZone(int posX, int posY, Core system, DisplayVars& menuListVars, DisplayVars& itemListVars); //Done
void OrderListZone(int posX, int posY, Core system, DisplayVars& orderListVars, Sale& saleTemp); //Done
void NewOrderZone(int posX, int posY, Core system, Sale& saleTemp, int quantity, float amountPromotion, float percentPromotion, string note, Item current, DisplayVars ordervar, InputField quantityInput, InputField percentPromotionInput, InputField amountPromotionInput, InputField noteInput); //Done
void MenuListVerticalZone(int posX, int posY, Core system, DisplayVars& menuListVars);
void SaleListZone(int posX, int posY, Core system, DisplayVars& saleListVars, int day, int month, int year);
void OrderListManagerZone(int posX, int posY, Core system, DisplayVars& orderListVars, Sale temp);
void EmployeeListZone(int posX, int posY, Core system, DisplayVars& employeeListVars, string department);