#pragma once
#include "Item.h"
#include <string>

using namespace std;
class Menu
{
	string id;
	Item* itemList;
public:
	Menu* next;
	Menu();
	Menu(string id);

	bool AddItem(Item newItem);

	int GetTotalOfItem();
	string GetId();
	Item* GetItemHead();
	Item* GetItem(int index);
	Item* SearchItem(string id);

	bool DeleteItems();
};

