#include "admin.h"
#include "client.h"
#include "globalFun.h"
#include <screen.h>
using namespace std;

int main() {
	loadEmpsFromJson();
	loadClientsFromJson();
	loadAdminsFromJson();
	//! =========================================
    cout << "\033[1;35m";
	drawText("NAME BANK");
    cout << "\033[0m" << endl;

	Person* user = login();  // Login returns the appropriate user type (Admin*, Employee*, Client*)
	char UserType{};
	string name;
    char choice;
    
    
    //! =========================================
    if (auto client = dynamic_cast<Client*>(user)) {
        UserType = 'C';
        name = client->getName();
        printUserName(name);
        printClientMenu();
        askMsg("Enter your choice: ");
        cin >> choice;
        if (choice < '1' || choice > '6') {
            errorMsg("Invalid choice. Please choose a valid option.");
        }
        else {
            clientActions(choice, *client);
        }
    }
    else if (auto emp = dynamic_cast<Employee*>(user)) {
        UserType = 'E';
        name = emp->getName();
        printUserName(name);
        printEmployeeMenu();
        askMsg("Enter your choice: ");
        cin >> choice;
        if (choice < '1' || choice > '6') {
            errorMsg("Invalid choice. Please choose a valid option.");
        }
        else {
            cout << choice;
            employeeActions(choice);
        }
    }
    else if (auto admin = dynamic_cast<Admin*>(user)) {
        UserType = 'A';
        name = admin->getName();
        printUserName(name);

        //char subChoice;
        //while (true) {
        //    askMsg("Choose Operations on Client or Employee (C/E): ");
        //    cin >> subChoice;
        //    if (cin.fail() || cin.peek() != '\n') {
        //        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //        errorMsg("Invalid input. Please enter only one character (C/E).\n");
        //        continue;
        //    };

        //    if (subChoice == 'C' || subChoice == 'c') {
        //        printEmployeeMenu(); break;
        //    }
        //    else if (subChoice == 'E' || subChoice == 'e') {
        //        printAdminMenu(); break;
        //    }
        //    else {
        //        errorMsg("Invalid input. Please enter only one character (C/E).\n");
        //    };
        //};

    };
    //! =========================================


	//! =========================================
	saveEmpsToJson();
	saveClientsToJson();
	saveAdminsToJson();
};