#include "screen.h"

void printOptions(string options) {
	string question =
		"Choose your operation : \n"
		"-----------------------\n";
	askMsg(question);
	InfoMsg(options);
}
void printSuperAdminMenu() {
	string options =
		"1- Add Admin\n"
		"2- Search for Admin by ID\n"
		"3- Get All Admins\n"
		"4- Update Admin information by ID\n"
		"5- Delete Admin by ID\n"
		"6- Delete All Admins\n"
		"7- Logout\n"
		"8- Exit Program\n";
	printOptions(options);
};
void printAdminMenu() {
	string options =
		"1- Add Employee\n"
		"2- Search for Employee by ID\n"
		"3- Get All Employees\n"
		"4- Update Employee information by ID\n"
		"5- Delete Employee by ID\n"
		"6- Delete All Employees\n"
		"7- Logout\n"
		"8- Exit Program\n";
	printOptions(options);
};
void printEmployeeMenu() {
	string options =
		"1- Add Client\n"
		"2- Search for Client by ID\n"
		"3- Get All Clients\n"
		"4- Update Client information by ID\n"
		"5- Delete Client by ID\n"
		"6- Delete All Clients\n"
		"7- Logout\n"
		"8- Exit Program\n";
	printOptions(options);
};
void printClientMenu() {
	string options =
		"1- Display your information\n"
		"2- Check Balance\n"
		"3- Deposit\n"
		"4- Withdraw\n"
		"5- Transfer to\n"
		"6- Update your Password\n"
		"7- Logout\n"
		"8- Exit Program\n";
	printOptions(options);
};