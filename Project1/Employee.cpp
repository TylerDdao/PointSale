#include "Employee.h"

Employee::Employee()
{
	this->name = "\0";
	this->id = "\0";
	this->deparment = "\0";
	this->next = nullptr;
}

Employee::Employee(string id, string name, string department) {
	this->id = id;
	this->name = name;
	this->deparment = department;
	this->next = nullptr;
}

string Employee::GetName()
{
	return name;
}

string Employee::GetId()
{
	return id;
}

string Employee::GetDepartment()
{
	return deparment;
}

bool Employee::SetName(string name)
{
	this->name = name;
	return true;
}

bool Employee::SetDepartment(string newDepartment)
{
	if (newDepartment == CASHIER) {
		this->id[0] = 'C';
	}
	else if (newDepartment == MANAGER) {
		this->id[0] = 'M';
	}
	this->deparment = newDepartment;
	return true;
}
