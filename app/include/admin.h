#pragma once
#include <iostream>
#include "employee.h"
using namespace std;

class Admin : public Employee {
public:

	//! Constructor
	Admin(int id, string name, string phone, string email, string password, double salary);

	//! Methods
	void displayInfo();
};
