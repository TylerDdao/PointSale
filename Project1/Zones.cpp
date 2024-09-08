#include "Zones.h"

void MenuListZone(int posX, int posY, Core system, DisplayVars& menuListVars)
{
	Rectangle prevButton = { posX, posY, 100,50 };
	Rectangle nextButton = { posX + 836, posY, 100,50 };
	DrawRec(prevButton, "<-", WHITE, BLACK, BLACK, 30, CENTER);
	DrawRec(nextButton, "->", WHITE, BLACK, BLACK, 30, CENTER);
	if (menuListVars.isActive.size() != (size_t)system.GetTotalMenu()) {
		for (size_t i = 0; i < menuListVars.isActive.size();i++) {
			menuListVars.isActive.pop_back();
		}
		for (int i = 0; i < system.GetTotalMenu();i++) {
			menuListVars.isActive.push_back(false);
		}
	}
	menuListVars.remainder = system.GetTotalMenu() % 3;
	if (menuListVars.remainder == 0) {
		menuListVars.totalPage = system.GetTotalMenu() / 3;
	}
	else {
		menuListVars.totalPage = system.GetTotalMenu() / 3 + 1;
	}
	menuListVars.count = (menuListVars.currentPage * 3) - 3;
	if (menuListVars.currentPage < menuListVars.totalPage) {
		for (int i = 0;i < 3;i++) {
			Rectangle menuButton = { posX + 158 + i*(210),posY,200,50};
			DrawRec(menuButton, TextFormat("%s", system.GetMenu(menuListVars.count)->GetId().c_str()), WHITE, BLACK, BLACK, 30, CENTER);
			if (IsButtonClicked(menuButton, MOUSE_BUTTON_LEFT)) {
				fill(menuListVars.isActive.begin(), menuListVars.isActive.end(), false);
				menuListVars.isActive[menuListVars.count] = true;
			}
			menuListVars.count++;
		}
	}
	else if (menuListVars.currentPage == menuListVars.totalPage) {
		if (menuListVars.remainder != 0) {
			for (int i = 0; i < menuListVars.remainder;i++) {
				Rectangle menuButton = { posX + 158 + i * (210),posY,200,50 };
				DrawRec(menuButton, TextFormat("%s", system.GetMenu(menuListVars.count)->GetId().c_str()), WHITE, BLACK, BLACK, 30, CENTER);
				if (IsButtonClicked(menuButton, MOUSE_BUTTON_LEFT)) {
					fill(menuListVars.isActive.begin(), menuListVars.isActive.end(), false);
					menuListVars.isActive[menuListVars.count] = true;
				}
				menuListVars.count++;
			}
		}
		else {
			for (int i = 0;i < 3;i++) {
				Rectangle menuButton = { posX + 158 + i * (210),posY,200,50 };
				DrawRec(menuButton, TextFormat("%s", system.GetMenu(menuListVars.count)->GetId().c_str()), WHITE, BLACK, BLACK, 30, CENTER);
				if (IsButtonClicked(menuButton, MOUSE_BUTTON_LEFT)) {
					fill(menuListVars.isActive.begin(), menuListVars.isActive.end(), false);
					menuListVars.isActive[menuListVars.count] = true;
				}
				menuListVars.count++;
			}
		}
	}
	if (IsButtonClicked(prevButton, MOUSE_BUTTON_LEFT) && menuListVars.currentPage > 1) {
		menuListVars.currentPage--;
	}
	if (IsButtonClicked(nextButton, MOUSE_BUTTON_LEFT) && menuListVars.currentPage < menuListVars.totalPage) {
		menuListVars.currentPage++;
	}
}

void ItemDisplayZone(int posX, int posY, Core system, Menu currentMenu, DisplayVars& itemListVars)
{
	Rectangle prevButton = { posX, posY + 417,100,100 };
	Rectangle nextButton = { posX + 710, posY + 417,100,100 };
	DrawRec(prevButton, "<-", WHITE, BLACK, BLACK, 50, CENTER);
	DrawRec(nextButton, "->", WHITE, BLACK, BLACK, 50, CENTER);
	if (currentMenu.GetTotalOfItem() == 0) {
		DrawText(TextFormat("Current Menu: %s", currentMenu.GetId().c_str()), posX, posY, 50, BLACK);
		DrawText("--/--", posX+ 355, posY+ 434, 50, BLACK);
		DrawText("No Item", posX+315, posY+225, 50, BLACK);
	}
	else {
		Rectangle prevButton = { posX, posY + 417,100,100 };
		Rectangle nextButton = { posX + 710, posY + 417,100,100 };
		DrawText(TextFormat("Current Menu: %s", currentMenu.GetId().c_str()), posX, posY, 50, BLACK);
		DrawText(TextFormat("%d/%d", itemListVars.currentPage, itemListVars.totalPage), posX + 355, posY + 434, 50, BLACK);
		DrawRec(prevButton, "<-", WHITE, BLACK, BLACK, 50, CENTER);
		DrawRec(nextButton, "->", WHITE, BLACK, BLACK, 50, CENTER);
		if (itemListVars.isActive.size() != (size_t)currentMenu.GetTotalOfItem()) {
			for (size_t i = 0; i < itemListVars.isActive.size();i++) {
				itemListVars.isActive.pop_back();
			}
			for (int i = 0; i < currentMenu.GetTotalOfItem();i++) {
				itemListVars.isActive.push_back(false);
			}
		}
		itemListVars.remainder = currentMenu.GetTotalOfItem() % 6;
		if (itemListVars.remainder == 0) {
			itemListVars.totalPage = currentMenu.GetTotalOfItem() / 6;
		}
		else if (itemListVars.remainder != 0 && currentMenu.GetTotalOfItem() > 6) {
			itemListVars.totalPage = currentMenu.GetTotalOfItem() / 6 + 1;
		}
		itemListVars.count = itemListVars.currentPage * 6 - 6;
		if (itemListVars.currentPage < itemListVars.totalPage) {
			for (int i = 0;i < 3;i++) {
				Rectangle itemButton = { posX,posY + 67 + i * (115),400,100 };
				DrawRec(itemButton, WHITE, BLACK);
				DrawTextOnRec(itemButton, itemButton.y + 5, TextFormat("%s", currentMenu.GetItem(itemListVars.count)->GetName().c_str()), 30, BLACK, LEFT);
				DrawTextOnRec(itemButton, itemButton.y + 45, TextFormat("%s | $%.2f", currentMenu.GetItem(itemListVars.count)->GetId().c_str(), currentMenu.GetItem(itemListVars.count)->GetPrice()), 30, BLACK, LEFT);
				if (IsButtonClicked(itemButton, MOUSE_BUTTON_LEFT)) {
					fill(itemListVars.isActive.begin(), itemListVars.isActive.end(), false);
					itemListVars.isActive[itemListVars.count] = true;
				}
				itemListVars.count++;
			}
			for (int i = 0; i < 3;i++) {
				Rectangle itemButton = { posX + 410,posY + 67 + i * (115),400,100 };
				DrawRec(itemButton, WHITE, BLACK);
				DrawTextOnRec(itemButton, itemButton.y + 5, TextFormat("%s", currentMenu.GetItem(itemListVars.count)->GetName().c_str()), 30, BLACK, LEFT);
				DrawTextOnRec(itemButton, itemButton.y + 45, TextFormat("%s | $%.2f", currentMenu.GetItem(itemListVars.count)->GetId().c_str(), currentMenu.GetItem(itemListVars.count)->GetPrice()), 30, BLACK, LEFT);
				if (IsButtonClicked(itemButton, MOUSE_BUTTON_LEFT)) {
					fill(itemListVars.isActive.begin(), itemListVars.isActive.end(), false);
					itemListVars.isActive[itemListVars.count] = true;
				}
				itemListVars.count++;
			}
		}
		else {
			if (itemListVars.remainder == 0) {
				for (int i = 0;i < 3;i++) {
					Rectangle itemButton = { posX,posY + 67 + i * (115),400,100 };
					DrawRec(itemButton, WHITE, BLACK);
					DrawTextOnRec(itemButton, itemButton.y + 5, TextFormat("%s", currentMenu.GetItem(itemListVars.count)->GetName().c_str()), 30, BLACK, LEFT);
					DrawTextOnRec(itemButton, itemButton.y + 45, TextFormat("%s | $%.2f", currentMenu.GetItem(itemListVars.count)->GetId().c_str(), currentMenu.GetItem(itemListVars.count)->GetPrice()), 30, BLACK, LEFT);
					if (IsButtonClicked(itemButton, MOUSE_BUTTON_LEFT)) {
						fill(itemListVars.isActive.begin(), itemListVars.isActive.end(), false);
						itemListVars.isActive[itemListVars.count] = true;
					}
					itemListVars.count++;
				}
				for (int i = 0; i < 3;i++) {
					Rectangle itemButton = { posX + 410,posY + 67 + i * (115),400,100 };
					DrawRec(itemButton, WHITE, BLACK);
					DrawTextOnRec(itemButton, itemButton.y + 5, TextFormat("%s", currentMenu.GetItem(itemListVars.count)->GetName().c_str()), 30, BLACK, LEFT);
					DrawTextOnRec(itemButton, itemButton.y + 45, TextFormat("%s | $%.2f", currentMenu.GetItem(itemListVars.count)->GetId().c_str(), currentMenu.GetItem(itemListVars.count)->GetPrice()), 30, BLACK, LEFT);
					if (IsButtonClicked(itemButton, MOUSE_BUTTON_LEFT)) {
						fill(itemListVars.isActive.begin(), itemListVars.isActive.end(), false);
						itemListVars.isActive[itemListVars.count] = true;
					}
					itemListVars.count++;
				}
			}
			else if (itemListVars.remainder != 0 && itemListVars.remainder <= 3) {
				for (int i = 0; i < itemListVars.remainder;i++) {
					Rectangle itemButton = { posX,posY + 67 + i * (115),400,100 };
					DrawRec(itemButton, WHITE, BLACK);
					DrawTextOnRec(itemButton, itemButton.y + 5, TextFormat("%s", currentMenu.GetItem(itemListVars.count)->GetName().c_str()), 30, BLACK, LEFT);
					DrawTextOnRec(itemButton, itemButton.y + 45, TextFormat("%s | $%.3f", currentMenu.GetItem(itemListVars.count)->GetId().c_str(), currentMenu.GetItem(itemListVars.count)->GetPrice()), 30, BLACK, LEFT);
					if (IsButtonClicked(itemButton, MOUSE_BUTTON_LEFT)) {
						fill(itemListVars.isActive.begin(), itemListVars.isActive.end(), false);
						itemListVars.isActive[itemListVars.count] = true;
					}
					itemListVars.count++;
				}
			}
			else if (itemListVars.remainder != 0 && itemListVars.remainder > 3) {
				for (int i = 0; i < 3;i++) {
					Rectangle itemButton = { posX,posY + 67 + i * (115),400,100 };
					DrawRec(itemButton, WHITE, BLACK);
					DrawTextOnRec(itemButton, itemButton.y + 5, TextFormat("%s", currentMenu.GetItem(itemListVars.count)->GetName().c_str()), 30, BLACK, LEFT);
					DrawTextOnRec(itemButton, itemButton.y + 45, TextFormat("%s | $%.2f", currentMenu.GetItem(itemListVars.count)->GetId().c_str(), currentMenu.GetItem(itemListVars.count)->GetPrice()), 30, BLACK, LEFT);
					if (IsButtonClicked(itemButton, MOUSE_BUTTON_LEFT)) {
						fill(itemListVars.isActive.begin(), itemListVars.isActive.end(), false);
						itemListVars.isActive[itemListVars.count] = true;
					}
					itemListVars.count++;
				}
				for (int i = 0; i < itemListVars.remainder -3;i++) {
					Rectangle itemButton = { posX + 410,posY + 67 + i * (115),400,100 };
					DrawRec(itemButton, WHITE, BLACK);
					DrawTextOnRec(itemButton, itemButton.y + 5, TextFormat("%s", currentMenu.GetItem(itemListVars.count)->GetName().c_str()), 30, BLACK, LEFT);
					DrawTextOnRec(itemButton, itemButton.y + 45, TextFormat("%s | $%.2f", currentMenu.GetItem(itemListVars.count)->GetId().c_str(), currentMenu.GetItem(itemListVars.count)->GetPrice()), 30, BLACK, LEFT);
					if (IsButtonClicked(itemButton, MOUSE_BUTTON_LEFT)) {
						fill(itemListVars.isActive.begin(), itemListVars.isActive.end(), false);
						itemListVars.isActive[itemListVars.count] = true;
					}
					itemListVars.count++;
				}
			}
		}
	}
	if (IsButtonClicked(nextButton, MOUSE_BUTTON_LEFT) && itemListVars.currentPage < itemListVars.totalPage) {
		itemListVars.currentPage++;
	}
	if (IsButtonClicked(prevButton, MOUSE_BUTTON_LEFT) && itemListVars.currentPage > 1) {
		itemListVars.currentPage--;
	}
}

void ItemChoosingZone(int posX, int posY, Core system, DisplayVars& menuListVars, DisplayVars& itemListVars)
{
	MenuListZone(posX, posY, system, menuListVars);
	for (int i = 0; i < system.GetTotalMenu();i++) {
		if (menuListVars.isActive[i] == true) {
			Menu currentMenu = *system.GetMenu(i);
			ItemDisplayZone(posX+63, posY+50, system, *system.GetMenu(i), itemListVars);
		}
	}
}

void OrderListZone(int posX, int posY, Core system, DisplayVars& orderListVars, Sale& saleTemp)
{
	Rectangle prevButton = { posX + 5,posY + 522,50,50 };
	Rectangle nextButton = { posX + 355, posY + 522,50,50 };
	DrawRec(prevButton, "<-", WHITE, BLACK, BLACK, 30, CENTER);
	DrawRec(nextButton, "->", WHITE, BLACK, BLACK, 30, CENTER);
	DrawText(TextFormat("%d/%d", orderListVars.currentPage, orderListVars.totalPage), posX + 175, posY + 527, 30, BLACK);
	DrawCurrentTime(posX+5, posY+5, 30, BLACK);
	DrawRectangle(posX, posY + 40, 205, 10, WHITE);
	DrawText(TextFormat("%s", system.GetEmployeeName(system.GetCurrentWorking()).c_str()), posX + 5, posY + 55,30, BLACK);
	DrawRectangle(posX, posY + 90, 105, 10, WHITE);
	DrawText(TextFormat("ID: %s", system.GetCurrentWorking().c_str()), posX + 5, posY + 105, 30, BLACK);
	DrawRectangle(posX, posY + 140, 55, 10, WHITE);
	DrawText(TextFormat("Sale: %d", saleTemp.GetId()), posX + 5, posY + 155, 30, BLACK);
	
	DrawText(TextFormat("Items count: %d", saleTemp.GetTotalOrders()), posX + 5, posY + 242, 30, BLACK);

	if (orderListVars.isActive.size() != (size_t)saleTemp.GetTotalOrders()) {
		for (size_t i =0; i < orderListVars.isActive.size(); i++) {
			orderListVars.isActive.pop_back();
		}
		for (int i = 0; i < saleTemp.GetTotalOrders(); i++) {
			orderListVars.isActive.push_back(false);
		}
	}
	orderListVars.remainder = saleTemp.GetTotalOrders() % 4;
	if (orderListVars.remainder == 0) {
		if (saleTemp.GetTotalOrders() <= 4) {
			orderListVars.totalPage = 1;
		}
		else {
			orderListVars.totalPage = saleTemp.GetTotalOrders() / 4;
		}
	}
	else
	{
		orderListVars.totalPage = saleTemp.GetTotalOrders() / 4 + 1;
	}
	orderListVars.count = orderListVars.currentPage * 4 - 4;

	if (orderListVars.currentPage < orderListVars.totalPage) {
		for (int i = 0; i < 4; i++) {
			Rectangle orderButton = { posX + 5, posY + 282 + i * (60), 400, 50 };
			if (saleTemp.GetOrder(orderListVars.count)->GetPrice() != system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(orderListVars.count)->GetQuantity()) {
				DrawRec(orderButton, YELLOW, BLACK);
				float discountedAmount = saleTemp.GetOrder(orderListVars.count)->GetPrice() - system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(orderListVars.count)->GetQuantity();
				DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f ($%.2f)", system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetId().c_str(), system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(orderListVars.count)->GetQuantity(), saleTemp.GetOrder(orderListVars.count)->GetPrice(), discountedAmount), 20, BLACK, LEFT);
			}
			else {
				DrawRec(orderButton, WHITE, BLACK);
				DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f", system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetId().c_str(), system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(orderListVars.count)->GetQuantity(), saleTemp.GetOrder(orderListVars.count)->GetPrice()), 20, BLACK, LEFT);
			}
			if (IsButtonClicked(orderButton, MOUSE_BUTTON_LEFT)) {
				fill(orderListVars.isActive.begin(), orderListVars.isActive.end(), false);
				orderListVars.isActive[orderListVars.count] = true;
			}
			orderListVars.count++;
		}
	}
	else if (orderListVars.currentPage == orderListVars.totalPage) {
		if (orderListVars.remainder == 0 && saleTemp.GetTotalOrders() > 0) {
			for (int i = 0; i < 4; i++) {
				Rectangle orderButton = { posX + 5, posY + 282 + i * (60), 400, 50 };
				if (saleTemp.GetOrder(orderListVars.count)->GetPrice() != system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(orderListVars.count)->GetQuantity()) {
					DrawRec(orderButton, YELLOW, BLACK);
					float discountedAmount = saleTemp.GetOrder(orderListVars.count)->GetPrice() - system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(orderListVars.count)->GetQuantity();
					DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f ($%.2f)", system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetId().c_str(), system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(orderListVars.count)->GetQuantity(), saleTemp.GetOrder(orderListVars.count)->GetPrice(), discountedAmount), 20, BLACK, LEFT);
				}
				else {
					DrawRec(orderButton, WHITE, BLACK);
					DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f", system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetId().c_str(), system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(orderListVars.count)->GetQuantity(), saleTemp.GetOrder(orderListVars.count)->GetPrice()), 20, BLACK, LEFT);
				}
				if (IsButtonClicked(orderButton, MOUSE_BUTTON_LEFT)) {
					fill(orderListVars.isActive.begin(), orderListVars.isActive.end(), false);
					orderListVars.isActive[orderListVars.count] = true;
				}
				orderListVars.count++;
			}
		}
		else
		{
			for (int i = 0; i < orderListVars.remainder; i++) {
				Rectangle orderButton = { posX + 5, posY + 282 + i * (60), 400, 50 };
				if (saleTemp.GetOrder(orderListVars.count)->GetPrice() != system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(orderListVars.count)->GetQuantity()) {
					DrawRec(orderButton, YELLOW, BLACK);
					float discountedAmount = saleTemp.GetOrder(orderListVars.count)->GetPrice() - system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice() * saleTemp.GetOrder(orderListVars.count)->GetQuantity();
					DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f ($%.2f)", saleTemp.GetOrder(orderListVars.count)->GetItemId().c_str(), system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(orderListVars.count)->GetQuantity(), saleTemp.GetOrder(orderListVars.count)->GetPrice(), discountedAmount), 20, BLACK, LEFT);
				}
				else {
					DrawRec(orderButton, WHITE, BLACK);
					DrawTextOnRec(orderButton, TextFormat("%s: $%.2f x %d = $%.2f", system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetId().c_str(), system.SearchItem(saleTemp.GetOrder(orderListVars.count)->GetItemId())->GetPrice(), saleTemp.GetOrder(orderListVars.count)->GetQuantity(), saleTemp.GetOrder(orderListVars.count)->GetPrice()), 20, BLACK, LEFT);
				}				
				if (IsButtonClicked(orderButton, MOUSE_BUTTON_LEFT)) {
					fill(orderListVars.isActive.begin(), orderListVars.isActive.end(), false);
					orderListVars.isActive[orderListVars.count] = true;
				}
				orderListVars.count++;
			}
		}
	}
	if (IsButtonClicked(prevButton, MOUSE_BUTTON_LEFT)&& orderListVars.currentPage>1) {
		orderListVars.currentPage--;
	}
	if (IsButtonClicked(nextButton, MOUSE_BUTTON_LEFT) && orderListVars.currentPage < orderListVars.totalPage) {
		orderListVars.currentPage++;
	}
	DrawRectangle(posX, posY+615, 205, 10, WHITE);
	DrawText(TextFormat("Sub Total: $%.2f", saleTemp.GetTotal()), posX + 5, posY + 625, 30, BLACK);
	DrawText(TextFormat("Tax (%.2f%%): $%.2f", system.GetTax(), (saleTemp.GetTotal() * system.GetTax()) /100), posX + 5, posY + 665, 30, BLACK);
	DrawRectangle(posX, posY + 705, 205, 10, WHITE);
	DrawText(TextFormat("Total: $%.2f", (saleTemp.GetTotal() * system.GetTax())/100 + saleTemp.GetTotal()), posX + 5, posY + 715, 40, BLACK);

}

void NewOrderZone(int posX, int posY, Core system, Sale& saleTemp, int quantity, float amountPromotion, float percentPromotion, string note, Item current, DisplayVars ordervar, InputField quantityInput, InputField percentPromotionInput, InputField amountPromotionInput, InputField noteInput)
{
	DrawText(TextFormat("Add Item to Sale : %d", saleTemp.GetId()), posX + 195, posY, 50, BLACK);
	Rectangle itemBox = { 215,67,400,100 };
	DrawRec(itemBox, WHITE, BLACK);
	DrawTextOnRec(itemBox,posY+72, TextFormat("%s", current.GetName().c_str()), 30,BLACK, LEFT);
	DrawTextOnRec(itemBox,posY+112, TextFormat("%s/$%.3f", current.GetId().c_str(), current.GetPrice()), 30, BLACK, LEFT);

	Rectangle quantityInputBox = { posX,posY+279,300,100 };
	Rectangle percentPromotionBox = { posX+385,posY+279,200,100 };
	Rectangle amountPromotionBox = { posX+600,posY+279,200,100 };
	Rectangle noteBox = { posX,posY+419,800,100 };
	DrawInputField(quantityInputBox, quantity, WHITE, BLACK, BLACK, 30, 3, quantityInput);
	DrawInputField(percentPromotionBox, percentPromotion, WHITE, BLACK, BLACK, 30, 3, percentPromotionInput);
	DrawInputField(amountPromotionBox, amountPromotion, WHITE, BLACK, BLACK, 30, 10, amountPromotionInput);
	DrawInputField(noteBox, note, WHITE, BLACK, BLACK, 30, MAX_CHARS, noteInput);
	DrawText("Quantity", posX, posY + 239, 30, BLACK);
	DrawText("Promotion (%)", posX + 385, posY + 239, 30, BLACK);
	DrawText("Promotion ($)", posX + 600, posY + 239, 30, BLACK);
	DrawText("Note", posX, posY + 379, 30, BLACK);
}
