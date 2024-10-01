#pragma once
#include <iostream>
#include "person.h"
using namespace std;

class Employee : public Person {
protected:
	double salary;

public:

	//! Constructor
	Employee(int id, string name, string phone, string email, string password, double salary);
	
	//! Setters
	void setSalary(double salary);

	//! Getters
	double getSalary() const;

	//! Methods
	void updateEmp();
	void displayInfo();
};

extern vector<Employee> emp;

//! CRUD Operations
void addEmp();
Employee* getEmpByID(int id);
void getAllEmps();
void deleteEmpByID(int id);
void deleteAllEmps();

//! For JSON File
void loadEmpsFromJson();
void saveEmpsToJson();

void printAllEmp();
