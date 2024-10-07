#include "admin.h"

//! To Store data in vector
vector<Admin> admin;
static bool is_Found(int id) {
	return find_if(admin.begin(), admin.end(), [id](const Admin& e) { return e.getId() == id; }) != admin.end();
};

Admin::Admin(int id, string name, string phone, string email, string password, double salary)
	:Employee(id, name, phone, email, password, salary) {};

void Admin::updateAdmin() {
	if (!is_Found(id)) {
		errorMsg("This id is not found, Please enter a valid ID.");
		return;
	}
	char option;
	askMsg("What is the field you want to edit ?\n");
	askMsg("1.Name\n2.Phone\n3.Email\n4.Password\n5.Salary\n6.All Fields\n\nPlease choose of these options: ");
	cin >> option; cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch (option) {
	case '1':
		name = Validation::valid_name();
		successMsg("Name updated successfully.");
		break;
	case '2':
		phone = Validation::valid_phone();
		successMsg("Phone updated successfully.");
		break;
	case '3':
		email = Validation::valid_email();
		successMsg("Email updated successfully.");
		break;
	case '4':
		password = Validation::valid_password();
		successMsg("Password updated successfully.");
		break;
	case '5':
		salary = Validation::valid_amount(5000.0, 25000.0);
		successMsg("Salary updated successfully.");
		break;
	case '6':
		name = Validation::valid_name();
		phone = Validation::valid_phone();
		email = Validation::valid_email();
		password = Validation::valid_password();
		salary = Validation::valid_amount(5000.0, 25000.0);
		successMsg("Admin updated successfully.");
		break;
	default:
		errorMsg("Please select only one of these options.");
		break;
	}
};
void Admin::displayInfo() {
	cout << "Id       : " << id << endl
		<< "Name     : " << name << endl
		<< "Phone    : " << phone << endl
		<< "Email    : " << email << endl
		<< "Password : " << password << endl
		<< "Salary   : " << salary << endl;
};

void addAdmin() {
	InfoMsg("Let's Start Adding New Admin,");
	string name = Validation::valid_name();
	string phone = Validation::valid_phone();
	string email = Validation::valid_email();
	string password = Validation::valid_password();
	double salary = Validation::valid_amount(5000.0, 25000.0);
	int id = (!admin.empty()) ? admin[admin.size() - 1].getId() + 1 : 1;

	admin.emplace_back(id, name, phone, email, password, salary);
	successMsg("Admin created successfully with ID: E256" + to_string(id)
		+ ",\nPlease remember your ID carefully.\n");
};
Admin* getAdminByID(int id) {
	if (is_Found(id)) {
		return &admin[id];
	}
	errorMsg("This ID is not found, please enter a valid ID.");
	return nullptr;
};
void getAllAdmins() {
	if (admin.empty() || admin.size() <= 1) {
		errorMsg("Sorry! No Admins to display.");
		return;
	}

	for (int i = 1; i < admin.size(); ++i) {
		admin[i].displayInfo();
		cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
	}
};
void deleteAdminByID(int id) {
	if (is_Found(id) && id != 0) {
		auto it = remove_if(admin.begin(), admin.end(), [id](const Admin& e) { return e.getId() == id; });
		if (it != admin.end()) {
			admin.erase(it);
			successMsg("Admin with ID (" + to_string(id) + ") deleted successfully.");
		}
	}
	else {
		errorMsg("Invalid ID. Cannot delete.");
	};
};
void deleteAllAdmins() {
	admin.clear();
	admin.emplace_back(0, "Name", "Phone", "Email", "Password", 5000);
	successMsg("All Admins deleted successfully.");
};

//! To convert JSON type to Admin type and vice versa
static Admin deserializeAdmin(const json& j) {
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
static json serializeAdmin(const Admin& admin) {
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
	loadDataFromJSON<Admin>("admin.json", admin, deserializeAdmin);
};
void saveAdminsToJson() {
	saveDataToJSON<Admin>("admin.json", admin, serializeAdmin);
};

//! Testing JSON Connection will be Deleted Later
void printAllAdmin() {
	if (!admin.empty()) {
		admin.push_back(Admin(0, "Name", "Phone", "Email", "Password", 0.0));
	};
	for (int i = 0; i < admin.size(); i++) {
		cout << "Emp Id   : " << admin[i].getId() << endl
			<< "Emp Name : " << admin[i].getName() << endl
			<< "Phone    : " << admin[i].getPhone() << endl
			<< "Email    : " << admin[i].getEmail() << endl
			<< "Password : " << admin[i].getPassword() << endl
			<< "Salary   : " << admin[i].getSalary() << endl
			<< "\n=*=*=*=*=*=*=*=\n";
	};
};