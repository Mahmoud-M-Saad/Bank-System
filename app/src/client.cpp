#include "client.h"

// Constractor
Client:: Client(string name, string password, string phone, string email, int id, double balance)
	:Person(name, password, phone, email, id), balance(balance) {}

// Setter
void Client:: setBalance(double balance) {
	this->balance = balance;
}

// Getter
double Client::getBalance() {
	return balance;
}

// Method
void Client::deposit(double amount) {
	balance += amount;
}
void Client::withdraw(double amount) {
	if (amount <= balance) {
		balance -= amount;
	}
	else {
		cout << "Amount exceeded balance";
	}
}
void Client::transferTo(double amount, Client& account) {
	if (amount <= balance) {
		account.deposit(amount);
		balance -= amount;
	}
	else {
		cout << "Amount exceeded balance";
	}
}
void Client::checkBalance() {
	cout << "Balance  : " << balance << endl;
}
void Client::displayInfo() {
	cout << "Name     : " << name << endl
		<< "Password : " << password << endl
		<< "Phone    : " << phone << endl
		<< "Email    : " << email << endl
		<< "Id       : " << id << endl
		<< "Balance  : " << balance << endl;
}