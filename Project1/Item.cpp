#include "Item.h"

Item::Item()
{
	next = nullptr;
	this->price = 0;
	this->name = "\0";
	this->id = "\0";
}

Item::Item(string name, string id, float price)
{
	next = nullptr;
	this->price = price;
	this->name = name;
	this->id = id;
}

string Item::GetName()
{
	return name;
}

string Item::GetId()
{
	return id;
}

float Item::GetPrice()
{
	return price;
}
