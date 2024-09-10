#include "Menu.h"

Menu::Menu()
{
	next = nullptr;
	itemList = nullptr;
	this->id = "\0";
}

Menu::Menu(string id)
{
	next = nullptr;
	itemList = nullptr;
	this->id = id;
}

bool Menu::ModifyId(string newId)
{
	this->id = newId;
	return true;
}

bool Menu::AddItem(Item newItem)
{
	Item* ptr = new Item(newItem);
	if (ptr == nullptr) {
		return false;
	}
	if (itemList == nullptr) {
		itemList = ptr;
	}
	else {
		Item* ptr2 = itemList;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = ptr;
	}
	return true;
}

int Menu::GetTotalOfItem()
{
	int count = 0;
	Item* ptr = itemList;
	while (ptr != nullptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

string Menu::GetId()
{
	return id;
}

Item* Menu::GetItemHead()
{
	return itemList;
}

Item* Menu::GetItem(int index)
{
	Item* ptr = itemList;
	for (int i = 0; i < index;i++) {
		ptr = ptr->next;
	}
	return ptr;
}

Item* Menu::SearchItem(string id)
{
	Item* ptr = itemList;
	while (ptr != nullptr) {
		if (ptr->GetId() == id) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}

bool Menu::RemoveItem(string id)
{
	Item* ptr = itemList;
	while (ptr != nullptr) {
		if (ptr->GetId() == id) {
			break;
		}
		ptr = ptr->next;
	}
	if (ptr == nullptr) {
		return false;
	}
	if (itemList == ptr) {
		if (ptr->next != nullptr) {
			itemList = ptr->next;
		}
		delete ptr;
	}
	else {
		Item* ptr2 = itemList;
		while (ptr2->next != ptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = ptr->next;
		delete ptr;
	}
	return true;
}

bool Menu::DeleteItems()
{
	while (itemList != nullptr) {
		Item* ptr = itemList;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		delete ptr;
	}
	return true;
}
