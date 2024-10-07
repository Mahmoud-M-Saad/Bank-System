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

	//! Getters
	double getSalary() const;
	string getPassword() const { return password; };
	string getName() const { return name; };
	int getId() const { return id; };

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

void employeeActions(char choice);

//! For JSON File
void loadEmpsFromJson();
void saveEmpsToJson();

void printAllEmp();
