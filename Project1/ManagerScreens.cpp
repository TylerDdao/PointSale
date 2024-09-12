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
			screen = M_Search_Sale;
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
				interScreensVars.SetMenu(system.GetMenu(i));
			}
		}
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);

		if (interScreensVars.GetMenu() != nullptr) {
			screen = M_Menu_Edit;
		}

		EndDrawing();
	}
}

void MMenuEdit(int& screen, Core& system)
{
	DisplayVars itemListVars;
	Menu currentMenu = *interScreensVars.GetMenu();
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
				interScreensVars.SetItem(interScreensVars.GetMenu()->GetItem(i));
			}
		}
		Rectangle modifyMenuIdButton = { 55,416,300,100 };
		Rectangle addItemButton = { 55,526,300,100 };
		DrawRec(modifyMenuIdButton, "Modify ID", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(addItemButton, "Add Item", WHITE, BLACK, BLACK, 40, CENTER);
		if (interScreensVars.GetItem() != nullptr) {
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
		DrawInputField(newIdInputField, newId, WHITE, BLACK, BLACK, 40, MAX_MENU_ID, idInput);
		DrawText("New ID", 483, 267, 50, BLACK);
		Rectangle saveButton = { 55,526,300,100 };
		DrawRec(saveButton, "Save", GREEN, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(saveButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.GetMenu()->ModifyId(newId);
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
	string newItemName = interScreensVars.GetItem()->GetName();
	string newItemId = interScreensVars.GetItem()->GetId();
	float newPrice = interScreensVars.GetItem()->GetPrice();
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
		DrawItemBox(itemBox, WHITE, BLACK, BLACK, 30, *interScreensVars.GetItem());

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
			interScreensVars.GetMenu()->RemoveItem(interScreensVars.GetItem()->GetId());
			interScreensVars.ClearCurrentItem();
			screen = M_Menu_Edit;
		}
		Rectangle saveButton = { 55,526,300,100 };
		DrawRec(saveButton, "Save", GREEN, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(saveButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.GetItem()->ModifyItem(newItemName, newItemId, newPrice);
			interScreensVars.ClearCurrentItem();
			screen = M_Menu_Edit;
		}
		EndDrawing();
	}
}

void MSearchSale(int& screen, Core& system)
{
	int month = 0;
	int day = 0;
	int year = 0;

	InputField monthInput;
	InputField dayInput;
	InputField yearInput;
	while (screen == M_Search_Sale) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(5, 5, 35, BLACK);
		Rectangle monthInputField = { 253,301,200,100 };
		Rectangle dayInputField = { 483 ,301,200,100 };
		Rectangle yearInputField = { 713 ,301,400,100 };
		DrawInputField(monthInputField, month, WHITE, BLACK, BLACK, 50, 2, monthInput);
		DrawInputField(dayInputField, day, WHITE, BLACK, BLACK, 50, 2, dayInput);
		DrawInputField(yearInputField, year, WHITE, BLACK, BLACK, 50, 4, yearInput);
		Rectangle searchButton = { 693 ,420,200,100 };
		Rectangle returnButton = { 473 ,421,200,100 };
		DrawRec(searchButton, "Search", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawText("Month", 253, 248, 40, BLACK);
		DrawText("Day", 483, 248, 40, BLACK);
		DrawText("Year", 713, 248, 40, BLACK);
		if (IsButtonClicked(searchButton, MOUSE_BUTTON_LEFT)&& year> 0) {
			if (!IsLaterThanToday(day, month, year)) {
				if (MonthHas31Days(month)) {
					if (day <= 31) {
						interScreensVars.SetDate(day, month, year);
						screen = M_Sale_List;
					}
				}
				else {
					if (day < 31 && day>0) {
						interScreensVars.SetDate(day, month, year);
						screen = M_Sale_List;
					}
				}
			}
		}
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Home;
		}

		EndDrawing();
	}
}

void MSaleList(int& screen, Core& system)
{
	DisplayVars saleListVars;
	while (screen == M_Sale_List) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearCurrentItem();
			screen = M_Search_Sale;
			break;
		}
		SaleListZone(490, 76, system, saleListVars, interScreensVars.GetDay(), interScreensVars.GetMonth(), interScreensVars.GetYear());
		for (size_t i = 0; i < saleListVars.isActive.size(); i++) {
			if (saleListVars.isActive[i] == true) {
				interScreensVars.SetSale(system.GetSale(interScreensVars.GetMonth(), interScreensVars.GetDay(), interScreensVars.GetYear(), i));
				break;
			}
		}

		if (interScreensVars.GetSale() != nullptr) {
			screen = M_Order_List;
		}
		EndDrawing();
	}
}

void MOrderList(int& screen, Core& system)
{
	DisplayVars orderListVars;
	Sale temp = *interScreensVars.GetSale();
	interScreensVars.ClearCurrentSale();
	while (screen == M_Order_List) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRectangle(410, 0, 956, 768, WHITE);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Sale_List;
			break;
		}
		OrderListManagerZone(691, 159, system, orderListVars, temp);
		DrawText(TextFormat("Sub Total: $%.2f", temp.GetTotal()), 696, 539, 30,BLACK);
		DrawText(TextFormat("Tax (%.2f%%): $%.2f", system.GetTax(), temp.GetTotal()*system.GetTax()/100), 696, 579, 30, BLACK);
		DrawText(TextFormat("Total: $%.2f", temp.GetTotal() + temp.GetTotal() * system.GetTax() / 100), 696, 629, 40, BLACK);

		Rectangle refundButton = { 55 ,526,300,100 };
		DrawRec(refundButton, "Refund", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(refundButton, MOUSE_BUTTON_LEFT)) {
			system.RemoveSale(temp.GetId());
			screen = M_Sale_List;
		}
		EndDrawing();
	}
}

void MEmployeeList(int& screen, Core& system)
{
	while (screen == M_Employee_List) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearCurrentItem();
			screen = M_Search_Sale;
			break;
		}

		EndDrawing();
	}
}
