#pragma once
#include <iostream>
#include <vector>
#include "admin.h"
#include "client.h"
#include "employee.h"
#include <screen.h>
using namespace std;

// Template function for getting a user by ID
template <typename UserType>
UserType* getUserByID(vector<UserType>& users, int id);

// Template function to check credentials
template <typename UserType>
pair<bool, UserType*> checkCredentials(int id, const string& password, vector<UserType>& users);

Person* login();

template <typename UserType>
void staffActionsOn(vector<UserType>& userList, char userType, string name) {
	UserType* user{};
	char choice;
	do {
		system("CLS");
		printUserName(name);
		switch (userType) {
		case 'A':
			printSuperAdminMenu(); break;
		case 'E':
			printAdminMenu(); break;
		case 'C':
			printEmployeeMenu(); break;
		};
		choice = Validation::valid_choice();

		switch (choice) {
		case '1':
			addUser(userList, userType);
			break;

		case '2':
			user = getUser<UserType>(userList);
			user->displayInfo();
			break;

		case '3':
			getAllUsers(userList);
			break;

		case '4':
			user = getUser<UserType>(userList);
			updateUser(user, userType);
			break;

		case '5':
			user = getUser<UserType>(userList);
			deleteUserByID(user, userList);
			break;

		case '6':
			deleteAllUsers(userList);
			break;

		case '7':
			// go to login page
			break;

		case '8':
			system("CLS");
			drawText("Thank YOU!");
			saveEmpsToJson();
			saveClientsToJson();
			saveAdminsToJson();
			exit(0);

		default:
			errorMsg("Please choose a valid option.\n");
			break;
		};
		system("pause");
	} while (true);
};

void clientActions(Client& c, string name);