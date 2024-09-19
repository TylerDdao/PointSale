#pragma once
#include "Order.h"
#include "Time.h"
#include "Randomizer.h"
#include <string>

using namespace std;

enum Type { Takeaway = 0, Eat_In };
enum Payment { Cash = 0, Card };
class Sale
{
	int id;
	string saleTime;
	Order* orderList;
	float total;
	string type;
	string payment;
public:
	Sale* next;

	Sale();

	bool SetType(Type type);
	bool SetPayment(Payment payment);

	int GetId();
	float GetTotal();
	string GetSaleTime();
	bool SetSale(string time, int id);
	bool ClearSale();
	
	bool AddOrder(Order newOrder);
	bool ModifyOrder(Order currentOrder, Order newOrder);
	bool RemoveOrder(Order currentOrder);

	int GetTotalOrders();

	int GetTotalItemSold();
	int GetTotalItemSold(string itemId);


	string GetType();
	string GetPayment();

	Order* GetOrder(int index);
	Order* GetOrderHead();
	bool DeleteItems();
};

