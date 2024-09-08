#pragma once
#include "Item.h"
class Order
{
	string item;
	int quantity;
	string note;
	float price;
public:
	Order* next;

	Order();
	Order(string itemId, int quantity, float price, string note);
	bool ModifyOrder(Order newOrder);

	bool Increase(int value);
	bool Decrease(int value);
	int GetQuantity();
	float GetPrice();
	string GetItemId();
	string GetNote();
};

