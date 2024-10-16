#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Validation;

//! Colored Messages
const void errorMsg(const string& msg);
const void successMsg(const string& msg);
const void askMsg(const string& msg);
const void InfoMsg(const string& msg);

//! Global Functions
const string toDec(const double& amount);

//! CRUD operations
//! Create
template <typename Ty>
void addUser(vector<Ty>& userVector, char userType) {
	InfoMsg("Let's Start Adding New User,");
	string name = Validation::valid_name();
	string phone = Validation::valid_phone();
	string email = Validation::valid_email();
	string password = Validation::valid_password("Enter Your Password: ");
	int id = (!userVector.empty()) ? userVector[userVector.size() - 1].getId() + 1 : 1;
	string msg;  double amount;

	switch (userType) {
	case 'A':
		// salary for employee or admin
		amount = Validation::valid_amount(5000.0, 25000.0);
		msg = "Admin created successfully with ID: A283" + to_string(id);
		break;

	case 'E':
		// salary for employee or admin
		amount = Validation::valid_amount(5000.0, 25000.0);
		msg = "Employee created successfully with ID: E254" + to_string(id);
		break;

	case 'C':
		// balance for client
		amount = Validation::valid_amount(1500, 1000000);
		msg = "Client created successfully with ID: C372" + to_string(id);
		break;

	default:
		break;
	};

	userVector.emplace_back(id, name, phone, email, password, amount);
	successMsg(msg + ",\nPlease remember your ID carefully.\n");
};

//! Read
template <typename Ty>
Ty* getUser(vector<Ty>& userVector) {
	Ty* user = nullptr;
	do {
		int id = Validation::valid_id();
		user = getUserByID(userVector, id);
	} while (!user);

	return user;
};
template <typename Ty>
void getAllUsers(vector<Ty>& userVector) {
	if (userVector.empty() || userVector.size() <= 1) {
		errorMsg("Sorry! No users to display.");
		return;
	}

	for (int i = 1; i < userVector.size(); ++i) {
		userVector[i].displayInfo();
	}
};

//! Update
template <typename Ty>
void updateUser(Ty& user, char userType) {
	char option;
	askMsg("What is the field you want to edit?\n");
	askMsg("1. Name\n2. Phone\n3. Email\n4. Password");
	(userType == 'C') ? askMsg("5. Balance") : askMsg("5. Salary");
	askMsg("6. All Fields\n\nPlease choose one of these options: ");

	while (true) {
		cin >> option;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (option >= '1' && option <= '6') break;
		askMsg("Please select only one of these options: ");
	}

	switch (option) {
	case '1':
		user->setName(Validation::valid_name());
		successMsg("Name updated successfully.");
		break;
	case '2':
		user->setPhone(Validation::valid_phone());
		successMsg("Phone updated successfully.");
		break;
	case '3':
		user->setEmail(Validation::valid_email());
		successMsg("Email updated successfully.");
		break;
	case '4':
		updatePassword(user);
		break;
	case '5':
		(userType == 'C') ?
			user->setBalance(Validation::valid_amount(1, 1000000.0)) :
			user->setSalary(Validation::valid_amount(5000.0, 25000.0));
		successMsg("Amount updated successfully.");
		break;
	case '6':
		user->setName(Validation::valid_name());
		user->setPhone(Validation::valid_phone());
		user->setEmail(Validation::valid_email());
		updatePassword(user);
		(userType == 'C') ?
			user->setBalance(Validation::valid_amount(1, 1000000.0)) :
			user->setSalary(Validation::valid_amount(5000.0, 25000.0));
		successMsg("User updated successfully.");
		break;
	}
};

//valid then ask for new like Gmail
template <typename Ty>
void updatePassword(Ty* user) {
	while (true) {
		string oldPassword = Validation::valid_password("Enter the Old Password: ");
		if (user->getPassword() == oldPassword) {
			string newPassword = Validation::valid_password("Enter the New Password: ");
			if (newPassword == oldPassword) {
				errorMsg("Sorry! You can't set the new password as exactly the old one.");
				errorMsg("So, Please try again later.\n");
				return;
			} else {
				user->setPassword(newPassword);
				successMsg("Password updated successfully.");
			};
			break;
		}
		errorMsg("Incorrect password.");
	};
};

// Ask for both then valid
/* template <typename Ty>
void updatePassword(Ty* user) {
	while (true) {
		string oldpassword = Validation::valid_password("Enter Your Old Password: ");
		string newPassword = Validation::valid_password("Enter Your New Password: ");
		if (user->getPassword() == oldpassword) {
			user->setPassword(newPassword);
			break;
		}
		errorMsg("The old password is incorrect.");
	};
}; */

//! Delete
template <typename Ty>
void deleteUserByID(Ty* user, vector<Ty>& userVector) {
	auto it = userVector.begin() + (user - &userVector[0]);
	userVector.erase(it);
	successMsg("User deleted successfully.");
};

template <typename Ty>
void deleteAllUsers(vector<Ty>& userVector) {
	userVector.clear();
	userVector.emplace_back(0, "Name", "Phone", "Email", "Password", 0.0);
	successMsg("All Users deleted successfully.");
};

//! Print Function
void drawText(string text);
const void printUserName(const string& name);