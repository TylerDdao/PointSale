#pragma once
#include "Item.h"
class Order
{
	string item;
	int quantity;
	string note;
	float price;
	bool isPromoted;
public:
	Order* next;

	Order();
	Order(string itemId, int quantity, float price, string note);
	bool ModifyOrder(Order newOrder);
	bool IsPromoted();
	bool SetPromoted(bool value);

	bool Increase(int value);
	bool Decrease(int value);
	int GetQuantity();
	float GetPrice();
	string GetItemId();
	string GetNote();
};

