#include "admin.h"

Admin::Admin(int id, string name, string phone, string email, string password, double salary) 
	:Employee(id, name, phone, email, password, salary) {};

void Admin::displayInfo() {
	cout << "Id       : " << id << endl
		<< "Name     : " << name << endl
		<< "Phone    : " << phone << endl
		<< "Email    : " << email << endl
		<< "Password : " << password << endl
		<< "Salary   : " << salary << endl;
};