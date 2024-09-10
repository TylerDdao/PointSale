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
