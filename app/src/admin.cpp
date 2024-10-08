#include "admin.h"

//! To Store data in vector
vector<Admin> admin;
Admin::Admin(int id, string name, string phone, string email, string password, double salary)
	:Employee(id, name, phone, email, password, salary) {};

void Admin::displayInfo() {
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
		 << "|          Admin Card           |" << endl
		 << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
		 << "    ID: " << id << endl
		 << "    Name: " << name << endl
		 << "    Phone: " << phone << endl
		 << "    Email: " << email << endl
		 << "    Salary: $" << salary << endl
		 << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
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