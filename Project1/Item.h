#pragma once
#include <iostream>
#include <string>

using namespace std;
class Item
{
	string name;
	float price;
	string id;
public:
	Item* next;
	Item();
	Item(string name, string id, float price);

	bool ModifyItem(string name, string id, float price);
	string GetName();
	string GetId();
	float GetPrice();
};

