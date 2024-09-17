#include "employee.h"

// Constractor
Employee::Employee(int id, string name, string phone, string email, string password, double salary)
	:Person(id,name,phone, email, password), salary(salary) {}

// Setter
void Employee::setSalary(double salary) {
	this->salary = salary;
}

// Getter
double Employee::getSalary()
{
	return salary;
}

// Method
void Employee::displayInfo() {
	cout << "Name     : " << name << endl
		<< "Password : " << password << endl
		<< "Phone    : " << phone << endl
		<< "Email    : " << email << endl
		<< "Id       : " << id << endl
		<< "Salary   : " << salary << endl;
}

// add
void addEmployee() {
	string name, phone, email, password;
	int id;
	double salary;
	cout << "What is the Employee's name ?\n ";
	cin >> name;
	cout << "What is the Employee's phone ?\n ";
	cin >> phone;
	cout << "What is the Employee's email ?\n ";
	cin >> email;
	cout << "What is the Employee's password ?\n ";
	cin >> password;
	cout << "What is the Employee's id ?\n ";
	cin >> id;
	cout << "What is the Employee's salary ?\n ";
	cin >> salary;

	emp.push_back(Employee(id, name, phone, email, password, salary));
}

// search
Employee* searchEmployee(int id) {
	for (int i = 0; i < emp.size(); i++) {
		if (emp[i].getId() == id) {
			return &emp[i];
		}
	}
	return NULL;
}

// list
void listEmployee(int id) {
	Employee* tm = searchEmployee(id);
	tm->displayInfo();
}

// edit
void editEmployee(int id) {
	Employee* tm = searchEmployee(id);
	int ch{};
	cout << "What is the label you want to edit ?\n"
		<< "1- phone\n2- email\n3- password\n4- salary\n";
	cin >> ch;
	if (ch == 1) {
		string ph;
		cout << "What is the Employee's phone ?\n ";
		cin >> ph;
		tm->setPhone(ph);
	}
	else if (ch == 2) {
		string mail;
		cout << "What is the Employee's email ?\n ";
		cin >> mail;
		tm->setEmail(mail);
	}
	else if (ch == 3) {
		string pw;
		cout << "What is the Employee's password ?\n ";
		cin >> pw;
		tm->setPassword(pw);
	}
	else if (ch == 4) {
		double s;
		cout << "What is the Employee's salary ?\n ";
		cin >> s;
		tm->setSalary(s);
	}
	/*switch (ch)
	{case 1:
		string ph;
		cout << "What is the Employee's phone ?\n ";
		cin >> ph;
		tm->setPhone(ph);
		break;
	case 2:
		string mail;
		cout << "What is the Employee's email ?\n ";
		cin >> mail;
		tm->setEmail(mail);
		break;
	case 3:
		string pw;
		cout << "What is the Employee's password ?\n ";
		cin >> pw;
		tm->setPassword(pw);
		break;
	case 4:
		double s;
		cout << "What is the Employee's salary ?\n ";
		cin >> s;
		tm->setSalary(s);
		break;
	}*/
}

// deleteAll
void deleteAllEmployee() {
	emp.clear();
}

// delete
void deleteEmployee(int id) {
	for (int i = 0; i < emp.size(); i++) {
		if (emp[i].getId() == id) {
			emp.erase(emp.begin() + i);
		}
	}
}