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

//! 20.2359 => 20.23
const string toDec(const double& amount) {
	return to_string(amount).erase(to_string(amount).find('.') + 3);
}

//const void update(int id, char type) {
//    string diffField = "Not Mention.";
//    if (type == 'C') {
//        diffField = "Balance";
//    } else if (type == 'E') {
//        diffField = "Salary";
//    };
//
//    char option;
//    askMsg("What is the field you want to edit ?\n");
//    askMsg("1.Name\n2.Phone\n3.Email\n4.Password\n5."+diffField+"\n6.All Fields\n\nPlease choose of these options: ");
//    cin >> option; cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    switch (option) {
//    case '1':
//        name = Validation::valid_name();
//        successMsg("Name updated successfully.");
//        break;
//    case '2':
//        phone = Validation::valid_phone();
//        successMsg("Phone updated successfully.");
//        break;
//    case '3':
//        email = Validation::valid_email();
//        successMsg("Email updated successfully.");
//        break;
//    case '4':
//        password = Validation::valid_password();
//        successMsg("Password updated successfully.");
//        break;
//    case '5':
//        balance = Validation::valid_amount(1, 1000000.0);
//        successMsg("Balance updated successfully.");
//        break;
//    case '6':
//        name = Validation::valid_name();
//        phone = Validation::valid_phone();
//        email = Validation::valid_email();
//        password = Validation::valid_password();
//        balance = Validation::valid_amount(1, 1000000.0);
//        successMsg("Employee updated successfully.");
//        break;
//    default:
//        errorMsg("Please select only one of these options.");
//        break;
//    }
//}

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
