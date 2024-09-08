#pragma once
#include "Zones.h"

enum Screen { Home = 0, R_Login, R_Home, R_Menu, R_NewOrder, R_Current_Order, R_Confirm, Not_Found_404, Quit};

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

static InterScreensVars interScreensVars;
static Sale tempSale;

void HomeScreen(int& screen);
void NotFound404(int& screen);
void TestScreen(int& screen, Core& system);

void RLogin(int& screen, Core& system);
void RHome(int& screen, Core& system);
void RMenu(int& screen, Core& system);
void RConfirm(int& screen, Core& system);
void NewOrder(int& screen, Core& system);
void EditOrder(int& screen, Core& system);