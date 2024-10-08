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
	do {

		Sid = Validation::valid_Sid();
		password = Validation::valid_password();		

		char userType = Sid[0]; // 1st => E,C,A
		int id = stoi(Sid.erase(0, 4)); // last => real id

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

	} while (true);  // Keep asking until credentials are correct

};

//void adminActions(char choice) {
//	
//	switch (choice) {
//	case '1':
//		addEmp();
//		break;
//
//	case '2':
//		e2 = getEmpById();
//		e2->displayInfo();
//		break;
//
//	case '3':
//		getAllEmps();
//		break;
//
//	case '4':
//		e2 = getEmpById();
//		e2->updateClient();
//		break;
//
//	case '5':
//		e2 = getEmpById();
//		deleteEmpByID(e2->getId());
//		break;
//
//	case '6':
//		deleteAllEmps();
//		break;
//
//	default:
//		errorMsg("Please choose a valid option.\n");
//		break;
//	}
//}
//

void employeeActions(char choice) {
	Client* c;
	switch (choice) {
	case '1':
		addUser(client, 'C');
		break;

	case '2':
		c = getUser<Client>(client);
		c->displayInfo();
		break;

	case '3':
		getAllUsers(client, 'C');
		break;

	case '4':
		c = getUser<Client>(client);
		updateUser(c, 'C');
		break;

	case '5':
		c = getUser<Client>(client);
		deleteUserByID(client, c);
		break;

	case '6':
		deleteAllUsers(client);
		break;

	default:
		errorMsg("Please choose a valid option.\n");
		break;
	}
};

void clientActions(char choice, Client& c) {
	Client* c2{};
	switch (choice) {
	case '1':
		c.displayInfo();
		break;

	case '2':
		c.checkBalance();
		break;

	case '3':
		c.deposit();
		break;

	case '4':
		c.withdraw();
		break;

	case '5':
		c2 = getUser<Client>(client);
		c.transferTo(*c2);
		break;

	case '6':
		cout << "6- Update your Password\n";
		break;

	default:
		errorMsg("Please choose a valid option.\n");
		break;
	}
};