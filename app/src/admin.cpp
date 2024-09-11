#include "admin.h"

// Constractor
Admin::Admin(string name, string password, string phone, string email, int id, double salary)
	:Employee(name, password, phone, email, id,salary) {}

// Method
void Admin::displayInfo() {
	cout << "Name     : " << name << endl
		<< "Password : " << password << endl
		<< "Phone    : " << phone << endl
		<< "Email    : " << email << endl
		<< "Id       : " << id << endl
		<< "Salary   : " << salary << endl;
}