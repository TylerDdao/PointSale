#include "FileHandling.h"

bool SaveMenus(string fileName, Core system)
{
	ofstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	Menu* menuPtr = system.GetMenuHead();
	Item* itemPtr = menuPtr->GetItemHead();
	fp << system.GetTax()<<endl;
	while (menuPtr != nullptr) {
		fp << menuPtr->GetId()<<"@"<<menuPtr->GetTotalOfItem()<<"@";
		while (itemPtr != nullptr) {
			fp << itemPtr->GetName() << "&" << itemPtr->GetId() << "&" << itemPtr->GetPrice();
			fp << ";";
			itemPtr = itemPtr->next;
		}
		fp << endl;
		menuPtr = menuPtr->next;
	}
	return true;
}

bool LoadMenus(string fileName, Core& system)
{
	ifstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	string tax = "\0";
	getline(fp, tax);
	system.SetTax(stof(tax));
	string line = "\0";
	while (getline(fp, line)) {
		string menuId = "\0";
		string numberOfItem = "\0";
		istringstream isLine(line);
		getline(isLine, menuId, '@');
		getline(isLine, numberOfItem, '@');
		Menu newMenu(menuId);
		for (int i = 0; i < stoi(numberOfItem); i++) {
			string itemName = "\0";
			string itemId = "\0";
			string price = "\0";
			getline(isLine, itemName, '&');
			getline(isLine, itemId, '&');
			getline(isLine, price, ';');
			Item newItem(itemName, itemId, stof(price));
			newMenu.AddItem(newItem);
		}
		system.AddMenu(newMenu);
	}
	return true;
}

bool SaveOrders(ofstream& fp, Sale sale)
{
	Order* ptr = sale.GetOrderHead();
	while (ptr != nullptr) {
		fp << ptr->GetItemId() << "?" << ptr->GetQuantity() << "?" << ptr->GetPrice() << "?" << ptr->GetNote()<<"&";
		ptr = ptr->next;
	}
	return true;
}

bool LoadOrders(istringstream& line, Sale& sale)
{
	string numberOfOrders = "\0";
	getline(line, numberOfOrders, '@');
	for (int i=0; i < stoi(numberOfOrders); i++) {
		string itemId = "\0";
		string quantity = "\0";
		string price = "\0";
		string note = "\0";
		getline(line,itemId, '?');
		getline(line, quantity, '?');
		getline(line, price, '?');
		getline(line, note, '&');
		Order newOrder(itemId, stoi(quantity), stof(price), note);
		sale.AddOrder(newOrder);
	}
	return true;
}

bool SaveSales(string fileName, Core system)
{
	ofstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	Sale* ptr = system.GetSaleHead();
	while (ptr != nullptr) {
		fp << ptr->GetId()<< "@" << ptr->GetTotal() << "@" << ptr->GetType() << "@" << ptr->GetPayment() << "@" << ptr->GetSaleTime()<<"@"<<ptr->GetTotalOrders()<<"@";
		SaveOrders(fp, *ptr);
		fp << endl;
		ptr = ptr->next;
	}
	return true;
}

bool LoadSales(string fileName, Core& system)
{
	ifstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	string line = "\0";
	while (getline(fp, line)) {
		istringstream isLine(line);
		string saleId = "\0";
		string total = "\0";
		string type = "\0";
		string payment = "\0";
		string saletime = "\0";
		getline(isLine, saleId, '@');
		getline(isLine, total, '@');
		getline(isLine, type, '@');
		getline(isLine, payment, '@');
		getline(isLine, saletime, '@');
		Sale newSale;
		if (payment == "Card") {
			newSale.SetPayment(Card);
		}
		else {
			newSale.SetPayment(Cash);
		}
		if (type == "Takeaway") {
			newSale.SetType(Takeaway);
		}
		else {
			newSale.SetType(Eat_In);
		}
		newSale.SetSale(saletime, stoi(saleId));
		LoadOrders(isLine, newSale);
		system.AddSale(newSale);
	}
	return true;
}
