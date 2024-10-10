#pragma once
#include <iostream>
#include "person.h"
#include "client.h"
using namespace std;

class Employee : public Person {
protected:
	double salary;

public:
	//! Constructor
	Employee(int id, string name, string phone, string email, string password, double salary);
	
	//! Setters
	void setSalary(double salary);
	void setBalance(double balance) {};

	//! Getters
	double getSalary() const;

	//! Methods
	void displayInfo();
	void performAction();
};

extern vector<Employee> emp;
void loadEmpsFromJson();
void saveEmpsToJson();