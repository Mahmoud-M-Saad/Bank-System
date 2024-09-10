#include "employee.h"

// Constractor
Employee::Employee(string name, string password, string phone, string email, int id, double salary)
	:Person(name, password, phone, email, id), salary(salary) {}

// Setter
void Employee::setSalary(double salary) {
	this->salary = salary;
}

// Getter
double Employee::getSalary()
{
	return salary;
}

// Method
void Employee::displayInfo() {
	cout << "Name     : " << name << endl
		<< "Password : " << password << endl
		<< "Phone    : " << phone << endl
		<< "Email    : " << email << endl
		<< "Id       : " << id << endl
		<< "Salary   : " << salary << endl;
}