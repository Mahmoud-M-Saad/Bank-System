#include "employee.h"
#include "authFun.h"

vector<Employee> emp;
Employee::Employee(int id, string name, string phone, string email, string password, double salary)
    :Person(id, name, phone, email, password), salary(salary) {};

void Employee::setSalary(double salary) { this->salary = salary; };
double Employee::getSalary() const { return salary; };

void Employee::displayInfo() {
	cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
		 << "|         Employee Card         |" << endl
		 << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
		 << "    ID: " << "E254" << id << endl
		 << "    Name: " << name << endl
		 << "    Phone: " << phone << endl
		 << "    Email: " << email << endl
		 << "    Salary: $" << salary << endl
		 << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
};
void Employee::performAction() {
    staffActionsOn<Client>(client, 'C', name);
    return;
};

//! To convert JSON type to Employee type and vice versa
static Employee JSONToEmp(const json& j) {
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
static json EmpToJSON(const Employee& emp) {
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
    loadDataFromJSON<Employee>("employee.json", emp, JSONToEmp);
};
void saveEmpsToJson() {
    saveDataToJSON<Employee>("employee.json", emp, EmpToJSON);
};
