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

Employee* Core::GetEmployeeHead()
{
    return employeeList;
}

Menu* Core::GetMenu(int index)
{
	Menu* ptr = menuList;
	for (int i = 0; i < index;i++) {
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

bool Core::VerifyEmployeeId(string fileName, string idInput)
{
	ifstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	string line = "\0";
	while (getline(fp, line)) {
		string id = "\0";
		istringstream isLine(line);
		getline(isLine, id, ':');
		if (id == idInput) {
			return true;
		}
	}
    return false;
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
