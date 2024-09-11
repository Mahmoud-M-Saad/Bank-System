#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "employee.h"
using namespace std;

class Admin : public Employee {
public:

	Admin(string name, string password, string phone, string email, int id,double salary);
	//method
	 void displayInfo();

};
