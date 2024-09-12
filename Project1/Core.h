#pragma once
#include "Employee.h"
#include "Menu.h"
#include "Sale.h"
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
	Sale* GetSaleHead(int month, int day, int year);
	Employee* GetEmployeeHead();
	Employee* GetEmployeeHead(string department);
	string GetEmployeeName(string id);
	string GetCurrentWorking();
	bool SetCurrentWorking(string id);

	int GetTotalEmployee();
	int GetTotalEmployee(string department);

	Menu* GetMenu(int index);
	Sale* GetSale(int month, int day, int year, int index);
	Employee* GetEmployee(string department, int index);

	Item* SearchItem(string id);
	Employee* SearchEmployee(string id);

	bool AddSale(Sale newSale);
	bool RemoveSale(int id);

	bool AddMenu(Menu newMenu);
	int GetTotalMenu();
	int GetTotalEmployee();
	int GetTotalSale();
	int GetTotalSale(int month, int day, int year);

	bool AddEmployee(Employee newEmployee);

	bool SetTax(float value);
	float GetTax();

	bool DeleteMenuList();
	bool DeleteSaleList();
	bool DeleteEmployeeList();
	bool DeleteAll();

	bool EmployeeIdVerify(string id);

	//Communication

};