#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "json.hpp"
#include "person.h"
using namespace std;

class Employee : public Person {
protected:
	double salary;
public:
	// Constractor
	Employee(int id,string name,  string phone, string email, string password, double salary);

	// Setter
	void setSalary(double salary);

	// Getter
	double getSalary();

	// Method
	void displayInfo();


};
	static vector<Employee>emp;

	// add
	void addEmployee();

	// search
	Employee* searchEmployee(int id);

	// list
	void listEmployee(int id);

	// edit
	void editEmployee(int id);

	// deleteAll
	void deleteAllEmployee();

	// delete
	void deleteEmployee(int id);