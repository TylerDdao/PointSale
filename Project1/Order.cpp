#include "Order.h"

Order::Order()
{
	this->item = "\0";
	this->quantity = quantity;
	this->next = nullptr;
	this->price = 0;
	this->note = "\0";
}

Order::Order(string itemId, int quantity,float price, string note)
{
	this->item = itemId;
	this->quantity = quantity;
	this->next = nullptr;
	this->price = price;
	this->note = "\0";
}

bool Order::Increase(int value)
{
	this->price = (price / quantity);
	this->quantity += value;
	this->price = (price * quantity);
	return true;
}

bool Order::Decrease(int value)
{
	this->price = (price / quantity);
	this->quantity -= value;
	this->price = (price * quantity);
	return false;
}

int Order::GetQuantity()
{
	return quantity;
}

float Order::GetPrice()
{
	return price;
}

string Order::GetItemId()
{
	return item;
}

string Order::GetNote()
{
	return note;
}
