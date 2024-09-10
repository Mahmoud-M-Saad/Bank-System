#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "validation.h"
using namespace std;

class Person {
protected:
	string name, password, phone, email;
	int id;
public:
	// Constractor
	Person(string name, string password, string phone, string email, int id);

	// Setter
	void setPassword(string password);
	void setPhone(string phone);
	void setEmail(string email);

	// Getter
	string getName();
	string getPassword();
	string getPhone();
	string getEmail();
	int getId();

	// Method
	virtual void displayInfo()=0;
};