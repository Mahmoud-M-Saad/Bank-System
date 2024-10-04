#include "admin.h"
#include "client.h"
using namespace std;

int main() {
	//! Get All Data from JSON Files
	loadEmpsFromJson();
	loadClientsFromJson();
	//loadAdminsFromJson();
	//! ============================

	//! Project Logic
	cout << "Welcome, Sir! This project is working great."<< endl;
	addEmp();
	printAllEmp();
	printAllClients();

	//! Saving All Data to JSON Files
	saveEmpsToJson();
	saveClientsToJson();
	//saveAdminsToJson();
}
