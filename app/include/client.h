#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "person.h"
using namespace std;

class Client : public Person {
	double balance;
public:
	// Constractor
	Client(string name, string password, string phone, string email, int id, double balance);

	// Setter
	void setBalance(double balance);

	// Getter
	double getBalance();

	// Method
	void deposit(double amount);
	void withdraw(double amount);
	void transferTo(double amount, Client& account);
	void checkBalance();

	void displayInfo();
};
