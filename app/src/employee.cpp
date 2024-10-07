#include "employee.h"
#include <globalFun.h>

//! To Store data in vector
vector<Employee> emp;
static bool is_Found(int id) {
	return find_if(emp.begin(), emp.end(), [id](const Employee& e) { return e.getId() == id; }) != emp.end();
};

Employee::Employee(int id, string name, string phone, string email, string password, double salary)
    :Person(id, name, phone, email, password), salary(salary) {};

void Employee::setSalary(double salary) { this->salary = salary; };
double Employee::getSalary() const { return salary; };

void Employee::updateEmp() {
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
		successMsg("Employee updated successfully.");
		break;
	default:
		errorMsg("Please select only one of these options.");
		break;
	}
};
void Employee::displayInfo() {
    cout << "Id       : " << id << endl
        << "Name     : " << name << endl
        << "Phone    : " << phone << endl
        << "Email    : " << email << endl
        << "Password : " << password << endl
        << "Salary   : " << salary << endl;
};

void addEmp() {
	InfoMsg("Let's Start Adding New Employee,");
	string name = Validation::valid_name();
	string phone = Validation::valid_phone();
	string email = Validation::valid_email();
	string password = Validation::valid_password();
	double salary = Validation::valid_amount(5000.0, 25000.0);
	int id = (!emp.empty()) ? emp[emp.size() - 1].getId() + 1 : 1;

	emp.emplace_back(id, name, phone, email, password, salary);
	successMsg("Employee created successfully with ID: E256" + to_string(id)
		+ ",\nPlease remember your ID carefully.\n");
};
Employee* getEmpByID(int id) {
	if (is_Found(id)) {
		return &emp[id];
	}
	errorMsg("This ID is not found, please enter a valid ID.");
	return nullptr;
};
void getAllEmps() {
	if (emp.empty() || emp.size() <= 1) {
		errorMsg("Sorry! No Employees to display.");
		return;
	}

	for (int i = 1; i < emp.size(); ++i) {
		emp[i].displayInfo();
		cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
	}
};
void deleteEmpByID(int id) {
	if (is_Found(id) && id != 0) {
		auto it = remove_if(emp.begin(), emp.end(), [id](const Employee& e) { return e.getId() == id; });
		if (it != emp.end()) {
			emp.erase(it);
			successMsg("Employee with ID (" + to_string(id) + ") deleted successfully.");
		}
	} else {
		errorMsg("Invalid ID. Cannot delete.");
	};
};
void deleteAllEmps() {
    emp.clear();
	emp.emplace_back(0, "Name", "Phone", "Email", "Password", 5000);
	successMsg("All Employees deleted successfully.");
};

void employeeActions(char choice) {
	Client* c2;
	switch (choice) {
	case '1':
		addClient();
		break;

	case '2':
		c2 = getClientById();
		c2->displayInfo();
		break;

	case '3':
		getAllClients();
		break;

	case '4':
		c2 = getClientById();
		c2->updateClient();
		break;

	case '5':
		c2 = getClientById();
		deleteClientByID(c2->getId());
		break;

	case '6':
		deleteAllClients();
		break;

	default:
		errorMsg("Please choose a valid option.\n");
		break;
	}
}


//! To convert JSON type to Employee type and vice versa
static Employee deserializeEmployee(const json& j) {
    Employee emp = {
        j.at("id").get<int>(),
        j.at("name").get<string>(),
        j.at("phone").get<string>(),
        j.at("email").get<string>(),
        j.at("password").get<string>(),
        j.at("salary").get<double>()
    };
    return emp;
};
static json serializeEmployee(const Employee& emp) {
    json j = {
        {"id", emp.getId()},
        {"name", emp.getName()},
        {"phone", emp.getPhone()},
        {"email", emp.getEmail()},
        {"password", emp.getPassword()},
        {"salary", emp.getSalary()}
    };
    return j;
};

void loadEmpsFromJson() {
    loadDataFromJSON<Employee>("employee.json", emp, deserializeEmployee);
};
void saveEmpsToJson() {
    saveDataToJSON<Employee>("employee.json", emp, serializeEmployee);
};

//! Testing JSON Connection will be Deleted Later
void printAllEmp() {
	if (!emp.empty()) {
		emp.push_back(Employee(0, "Name", "Phone", "Email", "Password", 0.0));
	};
    for (int i = 0; i < emp.size(); i++) {
        cout << "Emp Id   : " << emp[i].getId() << endl
             << "Emp Name : " << emp[i].getName() << endl
             << "Phone    : " << emp[i].getPhone() << endl
             << "Email    : " << emp[i].getEmail() << endl
             << "Password : " << emp[i].getPassword() << endl
             << "Salary   : " << emp[i].getSalary() << endl 
             << "\n=*=*=*=*=*=*=*=\n";
    };
};
