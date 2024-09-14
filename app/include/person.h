#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "validation.h"
using namespace std;

class Person {
protected:
	string name, password, phone, email;
	int id;

public:
	//! Constructor
	Person(int id, string name, string phone, string email, string password);

	//! Setters
	void setPhone(string phone);
	void setEmail(string email);
	void setPassword(string password);

	//! Getters
	int getId() const;
	string getName() const;
	string getPhone() const;
	string getEmail() const;
	string getPassword() const;

	//! Methods
	virtual void displayInfo()=0;
};