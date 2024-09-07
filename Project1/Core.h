#pragma once
#include "Employee.h"
#include "Menu.h"
#include "Sale.h"
#include "FileHandling.h"
class Core
{
private:
	Menu* menuList;
	Sale* saleList;
	Employee* employeeList;

	string currentWorking;

	float taxRate;
public:
	Core();
	Menu* GetMenuHead();
	Sale* GetSaleHead();
	Employee* GetEmployeeHead();
	string GetEmployeeName(string id);
	string GetCurrentWorking();
	bool SetCurrentWorking(string id);

	Menu* GetMenu(int index);

	Item* SearchItem(string id);

	bool AddMenu(Menu newMenu);
	int GetTotalMenu();
	int GetTotalEmployee();
	int GetTotalSale();

	bool AddEmployee(Employee newEmployee);

	bool VerifyEmployeeId(string fileName, string idInput);
	bool SetTax(float value);
	float GetTax();

	bool DeleteMenuList();
	bool DeleteSaleList();
	bool DeleteEmployeeList();
	bool DeleteAll();
};