#include "generalFunctions.h"

//! red msg
const void errorMsg(const string& msg) {
	cout << endl << "\033[1;31m" + msg + "\033[0m" << endl;
};

//! green msg
const void successMsg(const string& msg) {
	cout << endl << "\033[1;32m" + msg + "\033[0m" << endl;
};

//! blue msg
const void askMsg(const string& msg) {
	cout << endl << "\033[1;34m" + msg + "\033[0m";
};

//! purple msg
const void InfoMsg(const string& msg) {
	cout << endl << "\033[1;35m" + msg + "\033[0m" << endl;
};

//! Print user name in big size
const void printUserName(const string& name) {
	string firstName = name.substr(0, name.find(' '));

	system("cls");

	if (firstName.size() > 10) {
		cout << "Hi!" + name << endl << endl;
	}
	else {
		cout << "\033[1;34m";
		// drawText("HI! " + firstName);
		cout << "\033[0m" << endl;
	}
};
