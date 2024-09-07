#pragma once

#include <iostream>

using namespace std;

enum Department { Unknown = 0, Manager, Cashier };

class Employee
{
	string id;
	string name;
	Department deparment;

public:
	Employee* next;

	Employee();
	Employee(string id, string name, Department department);
	string GetName();
	string GetId();
};

