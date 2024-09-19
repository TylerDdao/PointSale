#pragma once

#include <iostream>

using namespace std;

#define MANAGER "Manager"
#define CASHIER "Cashier"

class Employee
{
	string id;
	string name;
	string deparment;

public:
	Employee* next;

	Employee();
	Employee(string id, string name, string department);
	string GetName();
	string GetId();
	string GetDepartment();
	bool SetName(string name);
	bool SetDepartment(string newDepartment);
};

