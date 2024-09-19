#include "Core.h"

Core::Core()
{
	menuList = nullptr;
	saleList = nullptr;
	employeeList = nullptr;
	this->currentWorking = "\0";

	this->taxRate = 0;
}

Menu* Core::GetMenuHead()
{
    return menuList;
}

Sale* Core::GetSaleHead()
{
    return saleList;
}

Sale* Core::GetSaleHead(int month, int day, int year)
{
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractDay(ptr->GetSaleTime()) == day && ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return ptr;
}

Sale* Core::GetSaleHeadByMonth(int month, int year)
{
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return ptr;
}

Employee* Core::GetEmployeeHead()
{
    return employeeList;
}

Employee* Core::GetEmployeeHead(string department)
{
	Employee* ptr = employeeList;
	while (ptr->GetDepartment() != department) {
		ptr = ptr->next;
	}
	if (ptr == nullptr) {
		return nullptr;
	}
	return ptr;
}

Menu* Core::GetMenu(int index)
{
	Menu* ptr = menuList;
	for (int i = 0; i < index;i++) {
		ptr = ptr->next;
	}
	return ptr;



}

Sale* Core::GetSale(int month, int day, int year, int index)
{
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractDay(ptr->GetSaleTime()) == day && ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			break;
		}
		ptr = ptr->next;
	}
	if (ptr == nullptr) {
		return ptr;
	}
	for (int i = 0; i < index; i++) {
		ptr = ptr->next;
	}
	return ptr;
}

Sale* Core::GetSaleByMonth(int month, int year, int index)
{
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			break;
		}
		ptr = ptr->next;
	}
	if (ptr == nullptr) {
		return ptr;
	}
	for (int i = 0; i < index; i++) {
		ptr = ptr->next;
	}
	return ptr;
}

Employee* Core::GetEmployee(string department, int index)
{
	int i = -1;
	Employee* ptr = employeeList;
	while (ptr != nullptr) {
		if (ptr->GetDepartment() == department) {
			i++;
		}
		if (i == index) {
			break;
		}
		ptr = ptr->next;
	}
	return ptr;
}

Item* Core::SearchItem(string id)
{
	Menu* menuPtr = menuList;
	Item* itemPtr = menuList->GetItemHead();
	while (menuPtr != nullptr) {
		itemPtr = menuPtr->SearchItem(id);
		if (itemPtr->GetId() == id) {
			return itemPtr;
		}
		menuPtr = menuPtr->next;
	}
	return nullptr;
}

int Core::GetTotalItem()
{
	int count = 0;
	Menu* menuPtr = menuList;
	while (menuList != nullptr) {
		Item* itemPtr = menuPtr->GetItemHead();
		while (itemPtr != nullptr) {
			count++;
			itemPtr = itemPtr->next;
		}
		menuPtr = menuPtr->next;
	}
	return count;
}

vector<string> Core::GetAllItemId()
{
	vector<string> itemIds;
	Menu* menuPtr = menuList;
	while (menuPtr != menuList) {
		Item* itemPtr = menuPtr->GetItemHead();
		while (itemPtr != nullptr) {
			itemIds.push_back(itemPtr->GetId());
			itemPtr = itemPtr->next;
		}
		menuPtr = menuPtr->next;
	}
	return vector<string>();
}

Employee* Core::SearchEmployee(string id)
{
	Employee* ptr = employeeList;
	while (ptr != nullptr) {
		if (ptr->GetId() == id) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}

bool Core::AddSale(Sale newSale)
{
	Sale* ptr = new Sale(newSale);
	if (ptr == nullptr) {

		return false;
	}
	ptr->next = saleList;
	saleList = ptr;
	return true;
}

bool Core::RemoveSale(int id)
{
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ptr->GetId() == id) {
			break;
		}
		ptr = ptr->next;
	}
	if (ptr == nullptr) {
		return false;
	}
	else if (saleList == ptr) {
		saleList = ptr->next;
		delete ptr;
		return true;
	}
	else
	{
		Sale* ptr2 = saleList;
		while (ptr2->next != ptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = ptr->next;
		delete ptr;
		return true;
	}
}

bool Core::AddMenu(Menu newMenu)
{
	Menu* ptr = new Menu(newMenu);
	if (ptr == nullptr) {
		return false;
	}
	if (menuList == nullptr) {
		menuList = ptr;
	}
	else {
		Menu* ptr2 = menuList;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = ptr;
	}
	return true;
}

int Core::GetTotalMenu()
{
	int count = 0;
	Menu* ptr = menuList;
	while (ptr != nullptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

int Core::GetTotalEmployee()
{
	int count = 0;
	Employee* ptr = employeeList;
	while (ptr != nullptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

int Core::GetTotalEmployee(string department)
{
	int count = 0;
	Employee* ptr = employeeList;
	while (ptr != nullptr) {
		if (ptr->GetDepartment() == department) {
			count++;
		}
		ptr = ptr->next;
	}
	return count;
}

int Core::GetTotalSale()
{
	int count = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

int Core::GetTotalSale(int month, int day, int year)
{
	int count = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractDay(ptr->GetSaleTime()) == day && ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			count++;
		}
		ptr = ptr->next;
	}
	return count;
}

int Core::GetTotalSaleByMonth(int month, int year)
{
	int count = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			count++;
		}
		ptr = ptr->next;
	}
	return count;
}

float Core::GetTotalSaleAmount(int month, int day, int year)
{
	float count = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year && ExtractDay(ptr->GetSaleTime()) == day) {
			count = count + ptr->GetTotal();
		}
		ptr = ptr->next;
	}
	return count;
}

float Core::GetTotalSaleAmountByMonth(int month, int year)
{
	float count = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			count = count + ptr->GetTotal();
		}
		ptr = ptr->next;
	}
	return count;
}

int Core::GetTotalItemSold(int month, int day, int year)
{
	int count = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year && ExtractDay(ptr->GetSaleTime()) == day) {
			count = count + ptr->GetTotalItemSold();
		}
		ptr = ptr->next;
	}
	return count;
}

int Core::GetTotalItemSoldByMonth(int month, int year)
{
	int count = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			count = count + ptr->GetTotalItemSold();
		}
		ptr = ptr->next;
	}
	return count;
}

float Core::GetTotalDiscoutAmount(int month, int day, int year)
{
	float amount = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year, ExtractDay(ptr->GetSaleTime())==day) {
			Order* orderPtr = ptr->GetOrderHead();
			while (orderPtr != nullptr) {
				if (orderPtr->IsPromoted()) {
					Item* itemPtr = SearchItem(orderPtr->GetItemId());
					float discountAmount = itemPtr->GetPrice() - orderPtr->GetPrice();
					amount += discountAmount;
				}
				orderPtr = orderPtr->next;
			}
		}
		ptr = ptr->next;
	}
	return 0-amount;
}

float Core::GetTotalDiscoutAmountByMonth(int month, int year)
{
	float amount = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year) {
			Order* orderPtr = ptr->GetOrderHead();
			while (orderPtr != nullptr) {
				if (orderPtr->IsPromoted()) {
					Item* itemPtr = SearchItem(orderPtr->GetItemId());
					float discountAmount = itemPtr->GetPrice() - orderPtr->GetPrice();
					amount += discountAmount;
				}
				orderPtr = orderPtr->next;
			}
		}
		ptr = ptr->next;
	}
	return 0 - amount;
}

int Core::GetTotalItemSold(int month, int day, int year, string itemId)
{
	int count = 0;
	Sale* ptr = saleList;
	while (ptr != nullptr) {
		if (ExtractMonth(ptr->GetSaleTime()) == month && ExtractYear(ptr->GetSaleTime()) == year && ExtractDay(ptr->GetSaleTime()) == day) {
			count = count + ptr->GetTotalItemSold(itemId);
		}
		ptr = ptr->next;
	}
	return count;
}

bool Core::AddEmployee(Employee newEmployee)
{
	Employee* ptr = new Employee(newEmployee);
	if (ptr == nullptr) {
		return false;
	}
	if (employeeList == nullptr) {
		employeeList = ptr;
	}
	else {
		Employee* ptr2 = employeeList;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = ptr;
	}
	return true;
}

bool Core::RemoveEmployee(string id)
{
	Employee* ptr = employeeList;
	while (ptr != nullptr) {
		if (ptr->GetId() == id) {
			break;
		}
		ptr = ptr->next;
	}
	if (ptr == nullptr) {
		return false;
	}
	else {
		if (employeeList == ptr) {
			employeeList = ptr->next;
			delete ptr;
		}
		else {
			Employee* ptr2 = employeeList;
			while (ptr2->next != ptr) {
				ptr2 = ptr2->next;
			}
			ptr2->next = ptr->next;
			delete ptr;
		}
		return true;
	}
}

bool Core::SetTax(float value)
{
	this->taxRate = value;
	return true;
}

float Core::GetTax()
{
	return taxRate;
}

bool Core::DeleteMenuList()
{
	Menu* ptr1 = menuList;
	while (ptr1 != menuList) {
		Menu* ptr2 = ptr1;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->DeleteItems();
		delete ptr2;
	}
	return true;
}

bool Core::DeleteSaleList()
{
	Sale* ptr1 = saleList;
	while (ptr1 != saleList){
		Sale* ptr2 = ptr1;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->DeleteItems();
		delete ptr2;
	}
	return true;
}

bool Core::DeleteEmployeeList()
{
	Employee* ptr1 = employeeList;
	while (ptr1 != employeeList) {
		Employee* ptr2 = ptr1;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		delete ptr2;
	}
	return true;
}

bool Core::DeleteAll()
{
	DeleteEmployeeList();
	DeleteMenuList();
	DeleteSaleList();
	return true;
}

bool Core::EmployeeIdVerify(string id)
{
	Employee* ptr = employeeList;
	while (ptr != nullptr) {
		if (ptr->GetId() == id) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

bool Core::IsNewEmployeeIdValid(string id)
{
	Employee* ptr = employeeList;
	while (ptr != nullptr) {
		if (ptr->GetId() == id) {
			return false;
		}
		ptr = ptr->next;
	}
	return true;
}

string Core::GetEmployeeName(string id)
{
	Employee* ptr = employeeList;
	if (ptr == nullptr) {
		return "\0";
	}
	else
	{
		while (ptr != nullptr) {
			if (ptr->GetId() == id) {
				return ptr->GetName();
			}
			ptr = ptr->next;
		}
		return "\0";
	}
}

string Core::GetCurrentWorking()
{
	return currentWorking;
}

bool Core::SetCurrentWorking(string id)
{
	this->currentWorking = id;
	return true;
}