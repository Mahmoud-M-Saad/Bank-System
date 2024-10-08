#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "validation.h"
#include "jsonFunctions.h"
using namespace std;

class Person {
protected:
	string name, password, phone, email;
	int id;

public:
	//! Constructor
	Person(int id, string name, string phone, string email, string password);

	//! Setters
	void setName(string name);
	void setPhone(string phone);
	void setEmail(string email);
	void setPassword(string password);

	virtual string getPassword() const = 0;  
	virtual string getName() const = 0;      
	virtual int getId() const = 0;
	//virtual ~Person() = default;

	//! Getters
	string getPhone() const;
	string getEmail() const;
};