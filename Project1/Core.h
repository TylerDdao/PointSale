#pragma once
#include "Employee.h"
#include "Menu.h"
#include "Sale.h"
#include <vector>
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
	Sale* GetSaleHeadByMonth(int month, int year);
	Employee* GetEmployeeHead();
	Employee* GetEmployeeHead(string department);
	string GetEmployeeName(string id);
	string GetCurrentWorking();
	bool SetCurrentWorking(string id);

	int GetTotalEmployee();
	int GetTotalEmployee(string department);

	Menu* GetMenu(int index);
	Sale* GetSale(int month, int day, int year, int index);
	Sale* GetSaleByMonth(int month, int year, int index);
	Employee* GetEmployee(string department, int index);

	Item* SearchItem(string id);
	vector<string> GetAllItemId();
	Employee* SearchEmployee(string id);

	bool AddSale(Sale newSale);
	bool RemoveSale(int id);

	bool AddMenu(Menu newMenu);
	int GetTotalMenu();
	int GetTotalSale();
	int GetTotalSale(int month, int day, int year);
	int GetTotalSaleByMonth(int month, int year);
	float GetTotalSaleAmount(int month, int day, int year);
	float GetTotalSaleAmountByMonth(int month, int year);
	int GetTotalItemSold(int month, int day, int year);
	int GetTotalItemSoldByMonth(int month, int year);
	float GetTotalDiscoutAmount(int month,int day, int year);
	float GetTotalDiscoutAmountByMonth(int month, int year);
	int GetTotalItemSold(int month, int day, int year, string itemId);

	bool AddEmployee(Employee newEmployee);
	bool RemoveEmployee(string id);

	bool SetTax(float value);
	float GetTax();

	bool DeleteMenuList();
	bool DeleteSaleList();
	bool DeleteEmployeeList();
	bool DeleteAll();

	bool EmployeeIdVerify(string id);
	bool IsNewEmployeeIdValid(string id);

	int GetTotalItem();
};