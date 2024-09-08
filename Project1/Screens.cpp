#include "Screens.h"

void HomeScreen(int& screen)
{
	while (screen == Home) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(5, 5, 50, BLACK);
		DrawText("Offline", 5, 741, 30, RED);
		Rectangle registerButton = { 483, 224, 400, 100 };
		Rectangle managerButton = { 483, 334, 400, 100 };
		Rectangle quitButton = { 483, 444, 400, 100 };

		DrawRec(registerButton, WHITE, BLACK);
		DrawTextOnRec(registerButton, "Register", 50, BLACK, CENTER);

		DrawRec(managerButton, WHITE, BLACK);
		DrawTextOnRec(managerButton, "Manager", 50, BLACK, CENTER);

		DrawRec(quitButton, WHITE, BLACK);
		DrawTextOnRec(quitButton, "Quit", 50, BLACK, CENTER);

		if (IsButtonClicked(registerButton, MOUSE_BUTTON_LEFT)) {
			screen = R_Login;
		}
		if (IsButtonClicked(registerButton, MOUSE_BUTTON_LEFT)) {
			//Maneger site
		}
		if (IsButtonClicked(quitButton, MOUSE_BUTTON_LEFT)) {
			screen = Quit;
		}

		EndDrawing();
	}
}

void RLogin(int& screen, Core& system)
{
	InputField staffNumberField;
	string employeeId = "\0";
	while (screen == R_Login) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(5, 5, 50, BLACK);
		Rectangle idInputField = { 433,310,500,100 };
		DrawInputField(idInputField, employeeId, WHITE, BLACK, BLACK, 50, MAX_EMPLOYEE_ID, staffNumberField);
		DrawText("Staff ID", 433, 243, 50, BLACK);
		system.SetCurrentWorking(employeeId);
		Rectangle returnButton = { 433, 425, 200,100 };
		Rectangle loginButton = { 733, 425, 200,100 };
		DrawRec(returnButton, WHITE, BLACK);
		DrawRec(loginButton, WHITE, BLACK);
		DrawTextOnRec(returnButton, "Return", 40, BLACK, CENTER);
		DrawTextOnRec(loginButton, "Login", 40, BLACK, CENTER);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = Home;
		}
		if (IsButtonClicked(loginButton, MOUSE_BUTTON_LEFT)) {
			//Verify employee ID
			screen = R_Home;
			//else {
			//	prevScreen = screen;
			//	screen = Not_Found_404;
			//}
		}
		EndDrawing();
	}
}

void RHome(int& screen, Core& system)
{
	while (screen == R_Home) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(0, 0, 30, BLACK);
		Rectangle newSaleButton = { 483,279,400,100 };
		Rectangle logoutButton = { 483,384,400,100 };
		DrawRec(newSaleButton, "New Sale", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(logoutButton, "Log Out", WHITE, BLACK, BLACK, 40, CENTER);
		DrawText(TextFormat("%s", system.GetEmployeeName(system.GetCurrentWorking()).c_str()), 483, 135, 50, BLACK);
		DrawRectangle(483, 202, 200, 10, WHITE);
		DrawText(TextFormat("ID: %s", system.GetCurrentWorking().c_str()), 483, 212, 50, BLACK);
		if (IsButtonClicked(newSaleButton, MOUSE_BUTTON_LEFT)) {
			saleTemp.ClearSale();
			screen = R_Menu;
		}
		if (IsButtonClicked(logoutButton, MOUSE_BUTTON_LEFT)) {
			screen = Home;
		}
		EndDrawing();
	}
}

void RMenu(int& screen, Core& system)
{
	DisplayVars menuvar;
	DisplayVars itemvar;
	DisplayVars ordervar;
	//Order newOrder1(*system.GetMenu(0)->GetItem(0), 100);
	//saleTemp.AddOrder(newOrder1);
	//Order newOrder2(*system.GetMenu(0)->GetItem(1), 100);
	//saleTemp.AddOrder(newOrder2);
	//Order newOrder3(*system.GetMenu(0)->GetItem(2), 100);
	//saleTemp.AddOrder(newOrder3);
	while (screen == R_Menu) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawRectangle(410, 0, 956, 768, WHITE);
		ItemChoosingZone(420, 10, system, menuvar,itemvar);
		interScreensVars.ClearAll();
		for (size_t i = 0; i < menuvar.isActive.size(); i++) {
			if (menuvar.isActive[i] == true) {
				interScreensVars.currertMenu = system.GetMenu(i);
			}
		}
		for (size_t i = 0; i < itemvar.isActive.size(); i++) {
			if (itemvar.isActive[i] == true) {
				interScreensVars.currentItem = interScreensVars.currertMenu->GetItem(i);
			}
		}
		for (size_t i = 0; i < ordervar.isActive.size(); i++) {
			if (ordervar.isActive[i] == true) {
				interScreensVars.currentOrder = saleTemp.GetOrder(i);
			}
		}
		OrderListZone(0, 0, system, ordervar, saleTemp);
		Rectangle cancelButton = { 573, 612, 200,100 };
		Rectangle eatInButton = { 788, 612, 200,100 };
		Rectangle takeawayButton = { 1003, 612, 300,100 };
		DrawRec(cancelButton, "Cancel", RED, BLACK, BLACK, 40, CENTER);
		DrawRec(eatInButton, "Eat In", GREEN, BLACK, BLACK, 40, CENTER);
		DrawRec(takeawayButton, "Takeaway" , GREEN, BLACK, BLACK, 40, CENTER);
		if (interScreensVars.currentItem != nullptr) {
			screen = R_NewOrder;
		}
		if (interScreensVars.currentOrder != nullptr) {
			screen = R_Current_Order;
		}
		if (IsButtonClicked(cancelButton, MOUSE_BUTTON_LEFT)) {
			screen = R_Home;
		}
		if (IsButtonClicked(takeawayButton, MOUSE_BUTTON_LEFT) && saleTemp.GetTotalOrders() > 0) {
			saleTemp.SetType(Takeaway);
			screen = R_Confirm;

		}
		if (IsButtonClicked(eatInButton, MOUSE_BUTTON_LEFT) && saleTemp.GetTotalOrders() > 0) {
			saleTemp.SetType(Eat_In);
			screen = R_Confirm;
		}
		EndDrawing();
	}
}

void RConfirm(int& screen, Core& system)
{
	DisplayVars ordersSummaryVar;
	InputField amountTakenInput;
	while (screen == R_Confirm) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawCurrentTime(5, 5, 50, BLACK);
		DrawText(TextFormat("%s", system.GetEmployeeName(system.GetCurrentWorking()).c_str()), 5, 72, 30, BLACK);
		DrawText(TextFormat("Sale: %d", saleTemp.GetId()), 585, 127, 50, BLACK);
		DrawText(TextFormat("Type: %s", saleTemp.GetType().c_str()), 585, 194, 50, BLACK);
		DrawText(TextFormat("Sub Total: $%.2f", saleTemp.GetTotal()), 590, 271, 30, BLACK);
		DrawText(TextFormat("Tax (%.2f%%): $%.2f",system.GetTax(),saleTemp.GetTotal()*(system.GetTax()/100)), 590, 311, 30, BLACK);
		DrawText(TextFormat("Total: $%.2f", saleTemp.GetTotal() + (saleTemp.GetTotal() * (system.GetTax() / 100))), 590, 361, 50, BLACK);

		Rectangle returnButton = { 373,612,200,100 };
		Rectangle cashButton = { 583,612,200,100 };
		Rectangle cardButton = { 793,612,200,100 };

		DrawRec(returnButton, "Return", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(cashButton, "Cash", GREEN, BLACK, BLACK, 40, CENTER);
		DrawRec(cardButton, "Card", GREEN, BLACK, BLACK, 40, CENTER);

		//Orders summary
		Rectangle prevButton = { 170,467,100,100 };
		Rectangle nextButton = { 470,467,100,100 };
		DrawRec(prevButton, "<-", WHITE, BLACK, BLACK, 50, CENTER);
		DrawRec(nextButton, "->", WHITE, BLACK, BLACK, 50, CENTER);
		ordersSummaryVar.remainder = saleTemp.GetTotalOrders() % 4;
		if (ordersSummaryVar.remainder == 0) {
			if (saleTemp.GetTotalOrders() <= 4) {
				ordersSummaryVar.totalPage = 1;
			}
			else {
				ordersSummaryVar.totalPage = saleTemp.GetTotalOrders() / 4;
			}
		}
		else
		{
			ordersSummaryVar.totalPage = saleTemp.GetTotalOrders() / 4 + 1;
		}
		ordersSummaryVar.count = ordersSummaryVar.currentPage * 4 - 4;

		if (ordersSummaryVar.currentPage < ordersSummaryVar.totalPage) {
			for (int i = 0; i < 4; i++) {
				Rectangle orderButton = { 170, 127 + i * (60), 400, 50 };
				if (saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice() != system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity()) {
					DrawRec(orderButton, YELLOW, BLACK);
					float discountedAmount = saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice() - system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity();
					DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d ($%.2f)", system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetName().c_str(), system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity(), discountedAmount), 20, BLACK, LEFT);
				}
				else {
					DrawRec(orderButton, WHITE, BLACK);
					DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f", system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetId().c_str(), system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity(), saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice()), 20, BLACK, LEFT);
				}
				ordersSummaryVar.count++;
			}
		}
		else if (ordersSummaryVar.currentPage == ordersSummaryVar.totalPage) {
			if (ordersSummaryVar.remainder == 0 && saleTemp.GetTotalOrders() > 0) {
				for (int i = 0; i < 4; i++) {
					Rectangle orderButton = { 170, 127 + i * (60), 400, 50 };
					if (saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice() != system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity()) {
						DrawRec(orderButton, YELLOW, BLACK);
						float discountedAmount = saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice() - system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity();
						DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d ($%.2f)", system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetName().c_str(), system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity(), discountedAmount), 20, BLACK, LEFT);
					}
					else {
						DrawRec(orderButton, WHITE, BLACK);
						DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f", system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetId().c_str(), system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity(), saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice()), 20, BLACK, LEFT);
					}
					ordersSummaryVar.count++;
				}
			}
			else
			{
				for (int i = 0; i < ordersSummaryVar.remainder; i++) {
					Rectangle orderButton = { 170, 127 + i * (60), 400, 50 };
					if (saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice() != system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity()) {
						DrawRec(orderButton, YELLOW, BLACK);
						float discountedAmount = saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice() - system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity();
						DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d ($%.2f)", system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetName().c_str(), system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity(), discountedAmount), 20, BLACK, LEFT);
					}
					else {
						DrawRec(orderButton, WHITE, BLACK);
						DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f", system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetId().c_str(), system.SearchItem(saleTemp.GetOrder(ordersSummaryVar.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(ordersSummaryVar.count)->GetQuantity(), saleTemp.GetOrder(ordersSummaryVar.count)->GetPrice()), 20, BLACK, LEFT);
					}
					ordersSummaryVar.count++;
				}
			}
		}
		if (IsButtonClicked(prevButton, MOUSE_BUTTON_LEFT) && ordersSummaryVar.currentPage > 1) {
			ordersSummaryVar.currentPage--;
		}
		if (IsButtonClicked(nextButton, MOUSE_BUTTON_LEFT) && ordersSummaryVar.currentPage < ordersSummaryVar.totalPage) {
			ordersSummaryVar.currentPage++;
		}
		if (IsButtonClicked(cashButton, MOUSE_BUTTON_LEFT)) {
			saleTemp.SetPayment(Cash);
			saleTemp.SetSale(GetCurrentDateTime(), saleTemp.GetId());
			system.AddSale(saleTemp);
			screen = R_Home;
		}
		if (IsButtonClicked(cardButton, MOUSE_BUTTON_LEFT)) {
			saleTemp.SetPayment(Card);
			saleTemp.SetSale(GetCurrentDateTime(), saleTemp.GetId());
			system.AddSale(saleTemp);
			screen = R_Home;
		}
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = R_Menu;
		}

		EndDrawing();
	}
}

void NotFound404(int& screen)
{

	while (screen == Not_Found_404) {
		BeginDrawing();
		
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(0, 0, 50, BLACK);
		DrawText("404 Error: Not Found", 359, 290, 70, RED);
		Rectangle rec = { 583,384,200,100 };
		DrawRec(rec, WHITE, BLACK);
		DrawTextOnRec(rec, "Return", 40, BLACK, CENTER);
		if (IsButtonClicked(rec, MOUSE_BUTTON_LEFT)) {
			screen = prevScreen;
		}
		EndDrawing();
	}
}

void EditOrder(int& screen, Core& system)
{
	Order currentOrder = *interScreensVars.currentOrder;
	DisplayVars ordervar;
	InputField quantityInput;
	InputField percentPromotionInput;
	InputField amountPromotionInput;
	InputField noteInput;
	int quantity = currentOrder.GetQuantity();
	string note = currentOrder.GetNote();
	while (screen == R_Current_Order) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		OrderListZone(0, 0, system, ordervar, saleTemp);
		DrawRectangle(410, 0, 956, 768, WHITE);
		DrawText(TextFormat("Sale: %d", saleTemp.GetId()), 792, 21, 50, BLACK);
		Rectangle orderBox = { 688,88,400,50 };
		if (currentOrder.GetPrice() != system.SearchItem(currentOrder.GetItemId())->GetPrice() * currentOrder.GetQuantity()) {
			float discount = currentOrder.GetPrice()-(system.SearchItem(currentOrder.GetItemId())->GetPrice()*currentOrder.GetQuantity());
			DrawRec(orderBox, TextFormat("%s: $%.2f x %d = $%.2f ($%.2f)", currentOrder.GetItemId().c_str(), system.SearchItem(currentOrder.GetItemId())->GetPrice(), currentOrder.GetQuantity(), currentOrder.GetPrice(), discount), YELLOW, BLACK, BLACK, 20, LEFT);
		}
		else {
			DrawRec(orderBox, TextFormat("%s: $%.2f x %d = $%.2f", currentOrder.GetItemId().c_str(), system.SearchItem(currentOrder.GetItemId())->GetPrice(), currentOrder.GetQuantity(), currentOrder.GetPrice()), WHITE, BLACK, BLACK, 20, LEFT);
		}
		Rectangle quantityInputBox = { 458,300,300,100 };
		Rectangle noteBox = { 458,440,800,100 };
		Rectangle modifyButton = { 788,612,200,100 };
		Rectangle deleteButton = { 998,612,200,100 };
		Rectangle cancelButton = { 573,612,200,100 };
		DrawInputField(quantityInputBox, quantity, WHITE, BLACK, BLACK, 30, 3, quantityInput);
		DrawInputField(noteBox, note, WHITE, BLACK, BLACK, 30, MAX_CHARS, noteInput);
		DrawText("Quantity", 458, 260, 30, BLACK);
		DrawText("Note", 458, 400, 30, BLACK);
		DrawRec(modifyButton, "Modify", WHITE, BLACK, BLACK, 40, CENTER);
		DrawRec(deleteButton, "Delete", RED, BLACK, BLACK, 40, CENTER);
		DrawRec(cancelButton, "Cancel", WHITE, BLACK, BLACK, 40, CENTER);

		if (IsButtonClicked(modifyButton, MOUSE_BUTTON_LEFT)) {
			float newPrice = system.SearchItem(currentOrder.GetItemId())->GetPrice() * quantity;
			Order newOrder(currentOrder.GetItemId(), quantity, newPrice, note);
			saleTemp.ModifyOrder(currentOrder, newOrder);
			screen = R_Menu;
		}
		if (IsButtonClicked(deleteButton, MOUSE_BUTTON_LEFT)) {
			saleTemp.RemoveOrder(currentOrder);
			screen = R_Menu;
		}
		if (IsButtonClicked(cancelButton, MOUSE_BUTTON_LEFT)) {
			screen = R_Menu;
		}
		EndDrawing();
	}
}

void NewOrder(int& screen, Core& system)
{
	Item current = *interScreensVars.currentItem;
	DisplayVars ordervar;
	InputField quantityInput;
	InputField percentPromotionInput;
	InputField amountPromotionInput;
	InputField noteInput;
	int quantity = 0;
	float amountPromotion = 0;
	float percentPromotion = 0;
	string note = "\0";
	while (screen == R_NewOrder) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		OrderListZone(0, 0, system, ordervar, saleTemp);
		DrawRectangle(410, 0, 956, 768, WHITE);
		DrawText(TextFormat("Add Item to Sale: %d", saleTemp.GetId()), 653, 21, 50, BLACK);
		Rectangle itemBox = { 688,88,400,100 };
		DrawRec(itemBox, WHITE, BLACK);
		DrawTextOnRec(itemBox, 93, TextFormat("%s", current.GetName().c_str()), 30, BLACK, LEFT);
		DrawTextOnRec(itemBox, 133, TextFormat("%s/$%.3f", current.GetId().c_str(), current.GetPrice()), 30, BLACK, LEFT);

		Rectangle quantityInputBox = { 458,300,300,100 };
		Rectangle percentPromotionBox = { 843,300,200,100 };
		Rectangle amountPromotionBox = { 1058,300,200,100 };
		Rectangle noteBox = { 458,440,800,100 };
		Rectangle addButton = { 1003,612,200,100 };
		Rectangle cancelButton = { 573,612,200,100 };
		DrawInputField(quantityInputBox, quantity, WHITE, BLACK, BLACK, 30, 3, quantityInput);
		DrawInputField(percentPromotionBox, percentPromotion, WHITE, BLACK, BLACK, 30, 3, percentPromotionInput);
		DrawInputField(amountPromotionBox, amountPromotion, WHITE, BLACK, BLACK, 30, 10, amountPromotionInput);
		DrawInputField(noteBox, note, WHITE, BLACK, BLACK, 30, MAX_CHARS, noteInput);
		DrawText("Quantity", 458, 260, 30, BLACK);
		DrawText("Promotion (%)", 843, 260, 30, BLACK);
		DrawText("Promotion ($)", 1058, 260, 30, BLACK);
		DrawText("Note", 458, 400, 30, BLACK);
		DrawRec(addButton, "Add", GREEN, BLACK, BLACK, 40, CENTER);
		DrawRec(cancelButton, "Cancel", RED, BLACK, BLACK, 40, CENTER);
		if (IsButtonClicked(addButton, MOUSE_BUTTON_LEFT) && quantity != 0) {
			float orderPrice = current.GetPrice() * quantity;
			float discountedAmount = (current.GetPrice() * (percentPromotion / 100)) + amountPromotion;
			orderPrice -= discountedAmount * quantity;
			Order newOrder(current.GetId(), quantity, orderPrice, note);
			saleTemp.AddOrder(newOrder);
			screen = R_Menu;
		}
		if (IsButtonClicked(cancelButton, MOUSE_BUTTON_LEFT)) {
			screen = R_Menu;
		}
		EndDrawing();
	}
}

InterScreensVars::InterScreensVars()
{
	for (size_t i = 0;i < isActive.size();i++) {
		isActive.pop_back();
	}
	currertMenu = nullptr;
	currentItem = nullptr;
	currentOrder = nullptr;
}

void InterScreensVars::ClearAll()
{
	for (size_t i = 0;i < isActive.size();i++) {
		isActive.pop_back();
	}
	currertMenu = nullptr;
	currentItem = nullptr;
	currentOrder = nullptr;
}

void InterScreensVars::ClearCurrentItem()
{
	currentItem = nullptr;
}

void InterScreensVars::ClearCurrentOrder()
{
	currentOrder = nullptr;
}
