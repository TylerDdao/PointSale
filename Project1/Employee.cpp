#include "Employee.h"

Employee::Employee()
{
	this->name = "\0";
	this->id = "\0";
	this->deparment = Unknown;
	this->next = nullptr;
}

Employee::Employee(string id, string name, Department department) {
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
