#include "globalFun.h"

template <typename UserType>
UserType* getUserByID(vector<UserType>& users, int id) {
	auto it = find_if(users.begin(), users.end(), [id](const UserType& u) { return u.getId() == id; });
	if (it != users.end()) {
		return &(*it);
	}
	errorMsg("This ID is not found, please enter a valid ID.");
	return nullptr;
};

template <typename UserType>
pair<bool, UserType*> checkCredentials(int id, const string& password, vector<UserType>& users) {
	UserType* user = getUserByID(users, id);
	if (user) {
		if (user->getPassword() == password) {
			return { true, user };  // Successful login
		}
		else {
			errorMsg("Incorrect password.");
			return { false, nullptr };
		}
	}
	return { false, nullptr };  // ID not found
};

Person* login() {
	string Sid, password;
	bool success = false;

	do {
		askMsg("Enter ID: ");
		cin >> Sid;
		if (cin.fail() || cin.peek() != '\n') {
			cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
			errorMsg("Invalid input. please enter a vaild ID.\n");
			continue;
		};

		askMsg("Enter Password: ");
		cin >> password;
		if (cin.fail() || cin.peek() != '\n') {
			cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
			errorMsg("Invalid input. Password is invalid.\n");
			continue;
		};

		char userType = Sid[0];
		int id = stoi(Sid.erase(0, 4));

		switch (userType) {
		case 'A': {
			auto [isSuccessful, user] = checkCredentials(id, password, admin);
			if (isSuccessful) {
				return static_cast<Admin*>(user);
			}
			else {
				errorMsg("Invalid credentials for Admin.");
			}
			break;
		}
		case 'E': {
			auto [isSuccessful, user] = checkCredentials(id, password, emp);
			if (isSuccessful) {
				return static_cast<Employee*>(user);
			}
			else {
				errorMsg("Invalid credentials for Employee.");
			}
			break;
		}
		case 'C': {
			auto [isSuccessful, user] = checkCredentials(id, password, client);
			if (isSuccessful) {
				return static_cast<Client*>(user);
			}
			else {
				errorMsg("Invalid credentials for Client.");
			}
			break;
		}
		default:
			errorMsg("Invalid ID format.");
			break;
		}

	} while (!success);  // Keep asking until credentials are correct

	return nullptr;  // Fallback in case of failure (should never reach this)
}
