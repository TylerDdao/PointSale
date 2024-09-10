#include "ManagerScreens.h"

void MHome(int& screen, Core& system)
{
	while (screen == M_Home) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(0, 0, 30, BLACK);
		Rectangle newSaleButton = { 483,279,400,100 };
		Rectangle reportButton = { 688,389,400,100 };
		Rectangle saleButton = { 278,389,400,100 };
		Rectangle editMenuButton = { 278,499,400,100 };
		Rectangle employeeButton = { 688,499,400,100 };
		Rectangle settingButton = { 688 ,609,400,100 };
		Rectangle logoutButton = { 278,609,400,100 };
		DrawRec(newSaleButton, "New Sale", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(saleButton, "Sale", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(editMenuButton, "Menu", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(reportButton, "Report", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(employeeButton, "Employee", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(settingButton, "Setting", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(logoutButton, "Log Out", WHITE, BLACK, BLACK, 40, CENTER);
		DrawText(TextFormat("%s", system.GetEmployeeName(system.GetCurrentWorking()).c_str()), 483, 135, 50, BLACK);
		DrawRectangle(483, 202, 200, 10, WHITE);
		DrawText(TextFormat("ID: %s", system.GetCurrentWorking().c_str()), 483, 212, 50, BLACK);
		if (IsButtonClicked(newSaleButton, MOUSE_BUTTON_LEFT)) {
			saleTemp.ClearSale();
			screen = R_Menu;
		}
		if (IsButtonClicked(logoutButton, MOUSE_BUTTON_LEFT)) {
			screen = Login_Site;
		}
		if (IsButtonClicked(editMenuButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Menu_List;
		}
		if (IsButtonClicked(saleButton, MOUSE_BUTTON_LEFT)) {

		}
		if (IsButtonClicked(reportButton, MOUSE_BUTTON_LEFT)) {

		}
		if (IsButtonClicked(employeeButton, MOUSE_BUTTON_LEFT)) {

		}
		if (IsButtonClicked(settingButton, MOUSE_BUTTON_LEFT)) {

		}

		EndDrawing();
	}
}

void MMenuList(int& screen, Core& system)
{
	DisplayVars menuListVars;
	while (screen == M_Menu_List) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Home;
		}
		DrawRectangle(410, 0, 956, 768, WHITE);
		MenuListVerticalZone(490, 132, system, menuListVars);
		for (size_t i = 0; i<menuListVars.isActive.size(); i++) {
			if (menuListVars.isActive[i] == true) {
				interScreensVars.currertMenu = system.GetMenu(i);
			}
		}
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);

		if (interScreensVars.currertMenu != nullptr) {
			screen = M_Menu_Edit;
		}

		EndDrawing();
	}
}

void MMenuEdit(int& screen, Core& system)
{
	DisplayVars itemListVars;
	Menu currentMenu = *interScreensVars.currertMenu;
	while (screen == M_Menu_Edit) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearAll();
			screen = M_Menu_List;
		}
		DrawRectangle(410, 0, 956, 768, WHITE);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		ItemDisplayZone(483, 126, system, currentMenu, itemListVars);
		for (size_t i = 0; i < itemListVars.isActive.size(); i++) {
			if (itemListVars.isActive[i] == true) {
				interScreensVars.currentItem = interScreensVars.currertMenu->GetItem(i);
			}
		}
		Rectangle modifyMenuIdButton = { 55,416,300,100 };
		Rectangle addItemButton = { 55,526,300,100 };
		DrawRec(modifyMenuIdButton, "Modify ID", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(addItemButton, "Add Item", WHITE, BLACK, BLACK, 40, CENTER);
		if (interScreensVars.currentItem != nullptr) {
			screen = M_Item_Edit;
		}
		if (IsButtonClicked(modifyMenuIdButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Edit_Menu_Id;
		}
		if (IsButtonClicked(addItemButton, MOUSE_BUTTON_LEFT)) {

		}
		EndDrawing();
	}
}

void MEditMenuId(int& screen, Core& system) {
	string newId = "\0";
	InputField idInput;
	while (screen == M_Edit_Menu_Id) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearAll();
			screen = M_Menu_List;
		}
		DrawRectangle(410, 0, 956, 768, WHITE);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		Rectangle newIdInputField = { 483 ,334,500,100 };
		DrawInputField(newIdInputField, newId, WHITE, BLACK, BLACK, 30, MAX_MENU_ID, idInput);
		DrawText("New ID", 483, 267, 50, BLACK);
		Rectangle saveButton = { 55,526,300,100 };
		DrawRec(saveButton, "Save", GREEN, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(saveButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.currertMenu->ModifyId(newId);
			screen = M_Menu_Edit;
		}
		EndDrawing();
	}
}

void MItemEdit(int& screen, Core& system)
{
	InputField newItemNameInput;
	InputField newItemIdInput;
	InputField newPriceInput;
	string newItemName = interScreensVars.currentItem->GetName();
	string newItemId = interScreensVars.currentItem->GetId();
	float newPrice = interScreensVars.currentItem->GetPrice();
	while (screen == M_Item_Edit) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRectangle(410, 0, 956, 768, WHITE);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearCurrentItem();
			screen = M_Menu_List;
			break;
		}
		Rectangle itemBox = { 658 ,35,400,100 };
		DrawItemBox(itemBox, WHITE, BLACK, BLACK, 30, *interScreensVars.currentItem);

		Rectangle newNameInputField = {638,201 ,500,100};
		Rectangle newIdInputField = { 638,354 ,500,100 };
		Rectangle newPriceInputField = { 638,507 ,500,100 };
		DrawText("New Name", 638, 148, 40, BLACK);
		DrawText("New ID", 638, 301, 40, BLACK);
		DrawText("New Price", 638, 454, 40, BLACK);
		DrawInputField(newNameInputField, newItemName, WHITE, BLACK, BLACK, 30, MAX_ITEM_NAME, newItemNameInput);
		DrawInputField(newIdInputField, newItemId, WHITE, BLACK, BLACK, 30, MAX_ITEM_ID, newItemIdInput);
		DrawInputField(newPriceInputField, newPrice, WHITE, BLACK, BLACK,30, MAX_PRICE, newPriceInput);

		Rectangle deleteButton = { 738 ,636,300,100 };
		DrawRec(deleteButton, "Delete", RED, BLACK, BLACK, 40, CENTER);
		if(IsButtonClicked(deleteButton,MOUSE_BUTTON_LEFT)){
			interScreensVars.currertMenu->RemoveItem(interScreensVars.currentItem->GetId());
			interScreensVars.ClearCurrentItem();
			screen = M_Menu_Edit;
		}
		Rectangle saveButton = { 55,526,300,100 };
		DrawRec(saveButton, "Save", GREEN, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(saveButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.currentItem->ModifyItem(newItemName, newItemId, newPrice);
			interScreensVars.ClearCurrentItem();
			screen = M_Menu_Edit;
		}
		EndDrawing();
	}
}
