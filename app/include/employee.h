#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "person.h"
using namespace std;

class Employee : public Person {
	double salary;
public:
	// Constractor
	Employee(string name, string password, string phone, string email, int id, double salary);

	// Setter
	void setSalary(double salary);

	// Getter
	double getSalary();

	// Method
	void displayInfo();
};
