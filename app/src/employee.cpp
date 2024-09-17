#include "employee.h"

Employee::Employee(int id, string name, string phone, string email, string password, double salary)
    :Person(id, name, phone, email, password), salary(salary) {};

void Employee::setSalary(double salary) { this->salary = salary; };

double Employee::getSalary() const { return salary; };

void Employee::displayInfo() {
    cout << "Id       : " << id << endl
        << "Name     : " << name << endl
        << "Phone    : " << phone << endl
        << "Email    : " << email << endl
        << "Password : " << password << endl
        << "Salary   : " << salary << endl;
};

//! To Store data in vector
vector<Employee> emp;

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
    emp.push_back(Employee(0, "Name", "Phone", "Email", "Password", 0.0));
    for (int i = 0; i < emp.size(); i++) {
        cout << "Id       : " << emp[i].getId() << endl
             << "Name     : " << emp[i].getName() << endl
             << "Phone    : " << emp[i].getPhone() << endl
             << "Email    : " << emp[i].getEmail() << endl
             << "Password : " << emp[i].getPassword() << endl
             << "Salary   : " << emp[i].getSalary() << endl 
             << "\n=*=*=*=*=*=*=*=\n";
    };
};
