#include "ManagerScreens.h"
#include "Components.h"
#include "React.h"
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
			screen = M_R_SearchSale;
		}
		if (IsButtonClicked(employeeButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Employee_List;
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
	int year = 0;
	int day = ExtractDay(GetCurrentDateTime());
	InputField monthInput;
	InputField dayInput;
	InputField yearInput;
	while (screen == M_Search_Sale) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(5, 5, 35, BLACK);
		Rectangle monthInputField = { 368 ,301,200,100 };
		Rectangle yearInputField = { 598 ,301,400,100 };
		DrawInputField(monthInputField, month, WHITE, BLACK, BLACK, 50, 2, monthInput);
		DrawInputField(yearInputField, year, WHITE, BLACK, BLACK, 50, 4, yearInput);
		Rectangle searchButton = { 693 ,420,200,100 };
		Rectangle returnButton = { 473 ,421,200,100 };
		DrawRec(searchButton, "Search", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawText("Month", 368, 248, 40, BLACK);
		DrawText("Year", 598, 248, 40, BLACK);
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
		SaleListZone(490, 76, system, saleListVars,interScreensVars.GetMonth(), interScreensVars.GetYear());
		for (size_t i = 0; i < saleListVars.isActive.size(); i++) {
			if (saleListVars.isActive[i] == true) {
				interScreensVars.SetSale(system.GetSaleByMonth(interScreensVars.GetMonth(),interScreensVars.GetYear(), i));
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
		}
		OrderListManagerZone(483, 159, system, orderListVars, temp);
		DrawText(TextFormat("Sale ID: %d", temp.GetId()), 483, 25, 50, BLACK);
		DrawText(TextFormat("Date: %s", temp.GetSaleTime().c_str()), 483, 92, 50, BLACK);
		DrawText(TextFormat("Sub Total: $%.2f", temp.GetTotal()), 483, 539, 30,BLACK);
		DrawText(TextFormat("Tax (%.2f%%): $%.2f", system.GetTax(), temp.GetTotal()*system.GetTax()/100), 483, 579, 30, BLACK);
		DrawText(TextFormat("Total: $%.2f", temp.GetTotal() + temp.GetTotal() * system.GetTax() / 100), 483, 629, 40, BLACK);

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
	DisplayVars employeeListVars;
	string department = "\0";
	while (screen == M_Employee_List) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		Rectangle managerButton = { 483 , 32,400,100 };
		Rectangle cashierButton = { 900 ,32,400,100 };
		if (IsButtonClicked(managerButton, MOUSE_BUTTON_LEFT)) {
			department = MANAGER;
		}
		if (IsButtonClicked(cashierButton, MOUSE_BUTTON_LEFT)) {
			department = CASHIER;
		}
		if (department == MANAGER || department == CASHIER) {
			if (department == MANAGER) {
				DrawRec(managerButton, "Manager", YELLOW, BLACK, BLACK, 40, CENTER);
				DrawRec(cashierButton, "Cashier", WHITE, BLACK, BLACK, 40, CENTER);
				EmployeeListZone(490, 159, system, employeeListVars, department);
			}
			else if(department == CASHIER){
				DrawRec(managerButton, "Manager", WHITE, BLACK, BLACK, 40, CENTER);
				DrawRec(cashierButton, "Cashier", YELLOW, BLACK, BLACK, 40, CENTER);
				EmployeeListZone(490, 159, system, employeeListVars, department);
			}

		}
		else {
			DrawRec(managerButton, "Manager", WHITE, BLACK, BLACK, 40, CENTER);
			DrawRec(cashierButton, "Cashier", WHITE, BLACK, BLACK, 40, CENTER);
		}
		for (size_t i = 0; i < employeeListVars.isActive.size(); i++) {
				if (employeeListVars.isActive[i] == true) {
					interScreensVars.SetStringId(system.GetEmployee(department, i)->GetId());
					break;
				}
		}
		Rectangle addButton = { 55 ,526,300,100 };
		DrawRec(addButton, "Add", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(addButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Add_Employee;
		}
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		if (interScreensVars.GetStringId() != "\0") {
			screen = M_Edit_Employee;
		}
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
				interScreensVars.ClearCurrentItem();
				screen = M_Home;
				break;
		}
		EndDrawing();
	}
}

void MAddEmployee(int& screen, Core& system)
{
	InputField nameInput;
	string name = "\0";
	bool isManager = false;
	bool isCashier = false;

	while (screen == M_Add_Employee) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Employee_List;
		}
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		Rectangle nameInputField = { 483 ,212,500,100 };
		DrawInputField(nameInputField, name, WHITE, BLACK, BLACK, 40, MAX_EMPLOYEE_NAME, nameInput);
		DrawText("Employee Name", 483, 159, 40, BLACK);
		DrawText("Add New Employee", 671, 40, 50, BLACK);
		Rectangle managerButton = { 483 ,333,50,50 };
		Rectangle cashierButton = { 483,404 ,50,50 };
		if (IsButtonClicked(managerButton, MOUSE_BUTTON_LEFT)) {
			isManager = true;
			isCashier = false;
		}
		if (IsButtonClicked(cashierButton, MOUSE_BUTTON_LEFT)) {
			isManager = false;
			isCashier = true;
		}
		if (isManager == true) {
			DrawRec(managerButton, BLACK, BLACK);
			DrawRec(cashierButton, WHITE, BLACK);
		}
		else if (isCashier == true) {
			DrawRec(managerButton, WHITE, BLACK);
			DrawRec(cashierButton, BLACK, BLACK);
		}
		else {
			DrawRec(managerButton, WHITE, BLACK);
			DrawRec(cashierButton, WHITE, BLACK);
		}
		DrawText("Cashier", 538, 329, 40, BLACK);
		DrawText("Manager", 538, 400, 40, BLACK);

		Rectangle addButton = { 55 ,526,300,100 };
		DrawRec(addButton, "Add", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(addButton, MOUSE_BUTTON_LEFT)) {
			if (name != "\0" && (isCashier != false || isManager != false)) {
				if (isCashier == true) {
					string id = GenerateEmployeeId(CASHIER);
					Employee newEmployee(id, name, CASHIER);
					system.AddEmployee(newEmployee);
					interScreensVars.SetStringId(id);
					screen = M_New_Employee;
				}
				else if (isManager == true) {
					string id = GenerateEmployeeId(CASHIER);
					Employee newEmployee(id, name, MANAGER);
					system.AddEmployee(newEmployee);
					interScreensVars.SetStringId(id);
					screen = M_New_Employee;
				}
			}
		}
		EndDrawing();
	}
}

void MNewEmployee(int& screen, Core& system)
{
	string id = interScreensVars.GetStringId();
	while (screen == M_New_Employee) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearStringId();
			screen = M_Employee_List;
		}
		DrawText("New Employee Added", 692, 293, 40, BLACK);
		DrawEmployeeBox(453, 376, WHITE, BLACK, BLACK, *system.SearchEmployee(id));
		Rectangle departmentBox = { 923 ,376,400,100 };
		DrawRec(departmentBox, WHITE, BLACK);
		DrawText("->", 867, 400, 40, BLACK);
		if (system.SearchEmployee(id)->GetDepartment() == CASHIER) {
			DrawTextOnRec(departmentBox, CASHIER, 40, BLACK, CENTER);
		}
		if (system.SearchEmployee(id)->GetDepartment() == MANAGER) {
			DrawTextOnRec(departmentBox, MANAGER, 40, BLACK, CENTER);
		}
		EndDrawing();
	}
}

void MEditEmployee(int& screen, Core& system)
{
	string id = interScreensVars.GetStringId();
	InputField nameInput;
	bool isManager = false;
	bool isCashier = false;
	string name = system.SearchEmployee(interScreensVars.GetStringId())->GetName();
	string department = "\0";
	if (system.SearchEmployee(interScreensVars.GetStringId())->GetDepartment() == MANAGER) {
		isManager = true;
		isCashier = false;
		department = MANAGER;
	}
	else if (system.SearchEmployee(interScreensVars.GetStringId())->GetDepartment() == CASHIER) {
		isManager = false;
		isCashier = true;
		department = CASHIER;
	}
	while(screen == M_Edit_Employee){
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearStringId();
			screen = M_Employee_List;
		}
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);

		Rectangle saveButton = { 55, 416,300,100 };
		Rectangle deleteButton = { 55,526 ,300,100 };
		DrawRec(saveButton, "Save", GREEN, BLACK, BLACK, 40, CENTER);
		DrawRec(deleteButton, "Delete", RED, BLACK, BLACK, 40, CENTER);
		Rectangle nameInputField = { 483 ,294,500,100 };
		DrawText("Employee Name", 483, 241, 40, BLACK);
		DrawInputField(nameInputField, name, WHITE, BLACK, BLACK, 40, MAX_EMPLOYEE_NAME, nameInput);
		DrawText("Modify Employee Info", 646, 40, 50, BLACK);
		DrawEmployeeBox(900, 143, WHITE, BLACK, BLACK, *system.SearchEmployee(id));
		Rectangle departmentBox = { 483 ,143,400,100 };
		DrawRec(departmentBox, TextFormat("%s", system.SearchEmployee(id)->GetDepartment().c_str()), WHITE, BLACK, BLACK, 40, CENTER);
		Rectangle cashierButton = { 483 ,414,50,50 };
		Rectangle managerButton = { 483 ,484,50,50 };
		DrawText("Cashier", 538, 413, 40, BLACK);
		DrawText("Manager", 538, 483, 40, BLACK);
		if (IsButtonClicked(managerButton, MOUSE_BUTTON_LEFT)) {
			isManager = true;
			isCashier = false;
		}
		if (IsButtonClicked(cashierButton, MOUSE_BUTTON_LEFT)) {
			isManager = false;
			isCashier = true;
		}
		if (isManager == true) {
			DrawRec(managerButton, BLACK, BLACK);
			DrawRec(cashierButton, WHITE, BLACK);
			department = MANAGER;
		}
		else if (isCashier == true) {
			DrawRec(managerButton, WHITE, BLACK);
			DrawRec(cashierButton, BLACK, BLACK);
			department = CASHIER;
		}
		else {
			DrawRec(managerButton, WHITE, BLACK);
			DrawRec(cashierButton, WHITE, BLACK);
		}
		if (IsButtonClicked(saveButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.SetEmployee(system.SearchEmployee(id));
			system.SearchEmployee(id)->SetName(name);
			system.SearchEmployee(id)->SetDepartment(department);
			interScreensVars.ClearStringId();
			screen = M_Employee_Edited_Info;
		}
		if (IsButtonClicked(deleteButton, MOUSE_BUTTON_LEFT)) {
			system.RemoveEmployee(id);
			interScreensVars.ClearStringId();
			screen = M_Employee_List;
		}
		EndDrawing();
	}
}

void MEmployeeEditedInfo(int& screen, Core& system)
{
	Employee currentEmployee = *interScreensVars.GetEmployee();
	while (screen == M_Employee_Edited_Info) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearCurrentEmployee();
			screen = M_Employee_List;
		}
		DrawText("Employee Info Modified", 692, 293, 40, BLACK);
		DrawEmployeeBox(453, 376, WHITE, BLACK, BLACK, currentEmployee);
		Rectangle departmentBox = { 923 ,376,400,100 };
		DrawRec(departmentBox, WHITE, BLACK);
		DrawText("->", 867, 400, 40, BLACK);
		if (currentEmployee.GetDepartment() == CASHIER) {
			DrawTextOnRec(departmentBox, CASHIER, 40, BLACK, CENTER);
		}
		if (currentEmployee.GetDepartment() == MANAGER) {
			DrawTextOnRec(departmentBox, MANAGER, 40, BLACK, CENTER);
		}
		EndDrawing();
	}
}

void MRSearchSale(int& screen, Core& system)
{
	int month = ExtractMonth(GetCurrentDateTime());
	InputField monthInput;
	int year = ExtractYear(GetCurrentDateTime());
	InputField fromYearInput;

	while (screen == M_R_SearchSale) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		Rectangle monthField = { 368,335,200,100 };
		Rectangle yearField = { 598 ,335,400,100 };
		DrawInputField(monthField, month, WHITE, BLACK, BLACK, 50, 2, monthInput);
		DrawInputField(yearField, year, WHITE, BLACK, BLACK, 50, 4, fromYearInput);
		DrawText("Month", 368, 282, 40, BLACK);
		DrawText("Year", 598, 282, 40, BLACK);
		DrawText(TextFormat("Default: %d/%d", ExtractMonth(GetCurrentDateTime()), ExtractYear(GetCurrentDateTime())), 368, 434,40,BLACK);
		Rectangle returnButton = { 473,510,200,100 };
		Rectangle searchButton = { 693,510,200,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(searchButton, "Search", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Home;
		}
		if (IsButtonClicked(searchButton, MOUSE_BUTTON_LEFT) && !IsLaterThanToday(ExtractDay(GetCurrentDateTime()), month, year)) {
			interScreensVars.SetDate(1, month, year);
			screen = M_Report_List;
		}
		EndDrawing();
	}
}

void MReportList(int& screen, Core& system)
{
	int month = interScreensVars.GetMonth();
	int year = interScreensVars.GetYear();
	while (screen == M_Report_List) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			interScreensVars.ClearDate();
			screen = M_R_SearchSale;
		}

		DrawText(TextFormat("Date: %d/%d", month, year), 453, 46, 50, BLACK);
		DrawText(TextFormat("Total Sale: %d", system.GetTotalSaleByMonth(month, year)), 453, 113, 40, BLACK);
		DrawText(TextFormat("Total Item: %d", system.GetTotalSaleByMonth(month, year)), 453, 166, 40, BLACK);
		Rectangle financeReportButton = { 923,116 ,400,100 };
		DrawRec(financeReportButton, "Financial Report", WHITE, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(financeReportButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Finance_Report;
		}

		if (MonthHas31Days(month)) {
			int day = 1;
			vector<bool> isActive;
			for (int i = 0; i < 31; i++) {
				isActive.push_back(false);
			}

			for (int i = 0; i < 8; i++) {
				Rectangle dayButton = { 453 + i * (110), 256 ,100,100 };
				DrawRec(dayButton, TextFormat("%d", day), WHITE, BLACK, BLACK, 50, CENTER);
				if (IsButtonClicked(dayButton, MOUSE_BUTTON_LEFT)) {
					interScreensVars.SetDate(day, month, year);
					screen = M_Report_Day_List;
				}
				day++;
			}
			for (int i = 0; i < 8; i++) {
				Rectangle dayButton = { 453 + i * (110), 366 ,100,100 };
				DrawRec(dayButton, TextFormat("%d", day), WHITE, BLACK, BLACK, 50, CENTER);
				if (IsButtonClicked(dayButton, MOUSE_BUTTON_LEFT)) {
					interScreensVars.SetDate(day, month, year);
					screen = M_Report_Day_List;
				}
				day++;
			}
			for (int i = 0; i < 8; i++) {
				Rectangle dayButton = { 453 + i * (110), 476 ,100,100 };
				DrawRec(dayButton, TextFormat("%d", day), WHITE, BLACK, BLACK, 50, CENTER);
				if (IsButtonClicked(dayButton, MOUSE_BUTTON_LEFT)) {
					interScreensVars.SetDate(day, month, year);
					screen = M_Report_Day_List;
				}
				day++;
			}
			for (int i = 0; i < 7; i++) {
				Rectangle dayButton = { 453 + i * (110), 586 ,100,100 };
				DrawRec(dayButton, TextFormat("%d", day), WHITE, BLACK, BLACK, 50, CENTER);
				if (IsButtonClicked(dayButton, MOUSE_BUTTON_LEFT)) {
					interScreensVars.SetDate(day, month, year);
					screen = M_Report_Day_List;
				}
				day++;
			}
		}
		else if (!MonthHas31Days(month)) {
			int day = 1;
			vector<bool> isActive;
			for (int i = 0; i < 31; i++) {
				isActive.push_back(false);
			}

			for (int i = 0; i < 8; i++) {
				Rectangle dayButton = { 453 + i * (110), 256 ,100,100 };
				DrawRec(dayButton, TextFormat("%d", day), WHITE, BLACK, BLACK, 50, CENTER);
				if (IsButtonClicked(dayButton, MOUSE_BUTTON_LEFT)) {
					interScreensVars.SetDate(day, month, year);
					screen = M_Report_Day_List;
				}
				day++;
			}
			for (int i = 0; i < 8; i++) {
				Rectangle dayButton = { 453 + i * (110), 366 ,100,100 };
				DrawRec(dayButton, TextFormat("%d", day), WHITE, BLACK, BLACK, 50, CENTER);
				if (IsButtonClicked(dayButton, MOUSE_BUTTON_LEFT)) {
					interScreensVars.SetDate(day, month, year);
					screen = M_Report_Day_List;
				}
				day++;
			}
			for (int i = 0; i < 8; i++) {
				Rectangle dayButton = { 453 + i * (110), 476 ,100,100 };
				DrawRec(dayButton, TextFormat("%d", day), WHITE, BLACK, BLACK, 50, CENTER);
				if (IsButtonClicked(dayButton, MOUSE_BUTTON_LEFT)) {
					interScreensVars.SetDate(day, month, year);
					screen = M_Report_Day_List;
				}
				day++;
			}
			for (int i = 0; i < 6; i++) {
				Rectangle dayButton = { 453 + i * (110), 586 ,100,100 };
				DrawRec(dayButton, TextFormat("%d", day), WHITE, BLACK, BLACK, 50, CENTER);
				if (IsButtonClicked(dayButton, MOUSE_BUTTON_LEFT)) {
					interScreensVars.SetDate(day, month, year);
					screen = M_Report_Day_List;
				}
				day++;
			}
		}

		EndDrawing();
	}
}

void MFinanceReport(int& screen, Core& system)
{
	int month = interScreensVars.GetMonth();
	int year = interScreensVars.GetYear();
	while (screen == M_Finance_Report) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Report_List;
		}
		DrawText("Financial Report", 453, 46, 50, BLACK);
		DrawText(TextFormat("Date: %d/%d", month, year), 453, 113, 50, BLACK);

		DrawText(TextFormat("Net Income (Before Tax): $%.2f", system.GetTotalSaleAmountByMonth(month, year)+ system.GetTotalSaleAmountByMonth(month, year) * (system.GetTax() / 100)), 453, 261, 40, BLACK);
		DrawText(TextFormat("Tax (%.2f%%): $%.2f",system.GetTax(), system.GetTotalSaleAmountByMonth(month, year) *(system.GetTax()/100)), 453, 314, 40, BLACK);
		DrawText(TextFormat("Income after tax: $%.2f", system.GetTotalSaleAmountByMonth(month, year)), 453, 367, 40, BLACK);
		DrawText(TextFormat("Total Discount: $%f.2", system.GetTotalDiscoutAmountByMonth(month, year)), 453, 420, 40, BLACK);
		if (MonthHas31Days(month)) {
			DrawText(TextFormat("Average Month: $%.2f/day", system.GetTotalSaleAmountByMonth(month, year) / 31), 453, 473, 40, BLACK);
		}
		else {
			DrawText(TextFormat("Average Month: $%.2f/day", system.GetTotalSaleAmountByMonth(month, year) / 30), 453, 473, 40, BLACK);
		}
		EndDrawing();
	}
}

void MReportDayList(int& screen, Core& system)
{
	int month = interScreensVars.GetMonth();
	int year = interScreensVars.GetYear();
	int day = interScreensVars.GetDay();
	while (screen == M_Report_Day_List) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Report_List;
		}

		DrawText(TextFormat("Date: %d/%d/%d", month, day, year), 453, 46, 50, BLACK);
		DrawText(TextFormat("Total Sale: %d", system.GetTotalSale(month,day, year)), 453, 113, 40, BLACK);
		DrawText(TextFormat("Total Item: %d", system.GetTotalItemSold(month, day,year)), 453, 166, 40, BLACK);
		DrawText(TextFormat("Net Income (Before Tax):$%.2f", system.GetTotalSaleAmount(month, day, year) + system.GetTotalSaleAmount(month,day, year) * (system.GetTax() / 100)), 453, 219, 40, BLACK);
		DrawText(TextFormat("Income after tax: $%.2f", system.GetTotalSaleAmount(month, day, year)), 453, 272, 40, BLACK);
		DrawText(TextFormat("Total Discount: $%.2f", system.GetTotalDiscoutAmount(month, day, year)), 453, 325, 40, BLACK);
		Rectangle itemSoldButton = { 453 ,418,400,100 };
		DrawRec(itemSoldButton, "Items Sold", WHITE, BLACK, BLACK, 40, CENTER);
		EndDrawing();
	}
}

void MReportItemListSold(int& screen, Core& system)
{
	int month = interScreensVars.GetMonth();
	int year = interScreensVars.GetYear();
	int day = interScreensVars.GetDay();
	DisplayVars menuListVars;
	while (screen == M_Report_Item_List_Sold) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		Rectangle returnButton = { 55,636,300,100 };
		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawCurrentTime(5, 5, 35, BLACK);
		DrawText(TextFormat("%s", system.SearchEmployee(system.GetCurrentWorking())->GetName().c_str()), 5, 58, 40, BLACK);
		DrawText(TextFormat("%s", system.GetCurrentWorking().c_str()), 5, 111, 40, BLACK);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = M_Report_Day_List;
		}
		MenuListZone(420, 109, system, menuListVars);
		EndDrawing();
	}
}
