#include "Sale.h"

Sale::Sale()
{
	this->id = GenerateId();
	this->saleTime = "\0";
	this->next = nullptr;
	this->orderList = nullptr;
	this->total = 0;
}

bool Sale::SetType(Type type)
{
	if (type == Eat_In) {
		this->type = "Eat In";
	}
	if (type == Takeaway) {
		this->type = "Takeaway";
	}
	return true;
}

bool Sale::SetPayment(Payment payment)
{
	if (payment == Cash) {
		this->payment = "Cash";
	}
	if (payment == Card) {
		this->payment = "Card";
	}
	return true;
}

int Sale::GetId()
{
	return id;
}

float Sale::GetTotal()
{
	return total;
}

string Sale::GetSaleTime()
{
	return saleTime;
}

bool Sale::SetSale(string time, int id)
{
	this->saleTime = GetCurrentDateTime();
	this->id = id;
	return true;
}

bool Sale::ClearSale()
{
	this->id = GenerateId();
	this->saleTime = "\0";
	this->next = nullptr;
	this->orderList = nullptr;
	this->total = 0;
	return true;
}

bool Sale::AddOrder(Order newOrder)
{
	Order* ptr = new Order(newOrder);
	if (ptr == nullptr) {
		return false;
	}
	ptr->next = orderList;
	orderList = ptr;
	this->total = total + ptr->GetPrice();
	return true;
}

bool Sale::ModifyOrder(Order currentOrder, Order newOrder)
{
	Order* ptr = orderList;
	while (ptr != nullptr) {
		if (ptr->GetQuantity() == currentOrder.GetQuantity() && ptr->GetPrice() == currentOrder.GetPrice() && ptr->GetItemId() == currentOrder.GetItemId() && ptr->GetNote() == currentOrder.GetNote()) {
			break;
		}
		ptr = ptr->next;
	}
	ptr->ModifyOrder(newOrder);
	this->total = total - currentOrder.GetPrice() + newOrder.GetPrice();
	return true;
}

bool Sale::RemoveOrder(Order currentOrder)
{
	Order* ptr = orderList;
	while (ptr != nullptr) {
		if (ptr->GetQuantity() == currentOrder.GetQuantity() && ptr->GetPrice() == currentOrder.GetPrice() && ptr->GetItemId() == currentOrder.GetItemId() && ptr->GetNote() == currentOrder.GetNote()) {
			break;
		}
		ptr = ptr->next;
	}
	if (ptr != nullptr) {
		if (orderList == ptr) {
			orderList = ptr->next;
		}
		else {
			Order* ptr2 = orderList;
			while (ptr2->next != ptr) {
				ptr2 = ptr2->next;
			}
			ptr2->next = ptr->next;
			delete ptr;
		}
	}
	this->total = total - ptr->GetPrice();
	return true;
}

int Sale::GetTotalOrders()
{
	int count = 0;
	Order* ptr = orderList;
	while (ptr != nullptr) {
		ptr = ptr->next;
		count++;
	}
	return count;
}

string Sale::GetType()
{
	return type;
}

string Sale::GetPayment()
{
	return payment;
}

Order* Sale::GetOrder(int index)
{
	Order* ptr = orderList;
	for (int i = 0; i < index; i++) {
		ptr = ptr->next;
	}
	return ptr;
}

Order* Sale::GetOrderHead()
{
	return orderList;
}

bool Sale::DeleteItems()
{
	while (orderList != nullptr) {
		Order* ptr = orderList;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		delete ptr;
	}
	return true;
}
