#include "admin.h"
#include "authFun.h"

vector<Admin> admin;
Admin::Admin(int id, string name, string phone, string email, string password, double salary)
	:Employee(id, name, phone, email, password, salary) {};

void Admin::displayInfo() {
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
		 << "|          Admin Card           |" << endl
		 << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
		 << "    ID: " << "A283" << id << endl
		 << "    Name: " << name << endl
		 << "    Phone: " << phone << endl
		 << "    Email: " << email << endl
		 << "    Salary: $" << salary << endl
		 << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
};
void Admin::performAction() {
	char subChoice = Validation::valid_sub_choice();
	switch (subChoice) {
	case 'A':
		staffActionsOn<Admin>(admin, 'A', name);
		break;
	case 'E':
		staffActionsOn<Employee>(emp, 'E', name);
		break;
	case 'C':
		staffActionsOn<Client>(client, 'C', name);
		break;
	};
}

//! To convert JSON type to Admin type and vice versa
static Admin JSONToAdmin(const json& j) {
	Admin admin = {
		j.at("id").get<int>(),
		j.at("name").get<string>(),
		j.at("phone").get<string>(),
		j.at("email").get<string>(),
		j.at("password").get<string>(),
		j.at("salary").get<double>()
	};
	return admin;
};
static json AdminToJSON(const Admin& admin) {
	json j = {
		{"id", admin.getId()},
		{"name", admin.getName()},
		{"phone", admin.getPhone()},
		{"email", admin.getEmail()},
		{"password", admin.getPassword()},
		{"salary", admin.getSalary()}
	};
	return j;
};

void loadAdminsFromJson() {
	loadDataFromJSON<Admin>("admin.json", admin, JSONToAdmin);
};
void saveAdminsToJson() {
	saveDataToJSON<Admin>("admin.json", admin, AdminToJSON);
};
