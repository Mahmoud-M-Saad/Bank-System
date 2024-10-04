#pragma once
#include <iostream>
#include "employee.h"
using namespace std;

class Admin : public Employee {
public:

	//! Constructor
	Admin(int id, string name, string phone, string email, string password, double salary);

	//! Methods
	void updateAdmin();
	void displayInfo();
};

extern vector<Admin> admin;

//! CRUD Operations
void addAdmin();
Admin* getAdminByID(int id);
void getAllAdmins();
void deleteAdminByID(int id);
void deleteAllAdmins();

//! For JSON File
void loadEmpsFromJson();
void saveEmpsToJson();

void printAllAdmin();