#pragma once
#include <iostream>
#include <vector>
#include "admin.h"
#include "client.h"
#include "employee.h"
using namespace std;

// Template function for getting a user by ID
template <typename UserType>
UserType* getUserByID(vector<UserType>& users, int id);

// Template function to check credentials
template <typename UserType>
pair<bool, UserType*> checkCredentials(int id, const string& password, vector<UserType>& users);

Person* login();

//void adminActions(char choice);
void employeeActions(char choice);
void clientActions(char choice, Client& c);