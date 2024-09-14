#include "employee.h"

Employee::Employee(int id, string name, string phone, string email, string password, double salary) 
	:Person(id, name, phone, email, password), salary(salary) {};

void Employee::setSalary(double salary) { this->salary = salary; };

double Employee::getSalary() const { return salary; };

void Employee::displayInfo() {
	cout << "Id       : " << id << endl
		<< "Name     : " << name << endl
		<< "Phone    : " << phone << endl
		<< "Email    : " << email << endl
		<< "Password : " << password << endl
		<< "Salary   : " << salary << endl;
};