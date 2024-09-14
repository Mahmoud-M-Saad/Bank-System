#include "admin.h"
#include "client.h"
using namespace std;

int main() {
	//! Get All Data from JSON Files
	loadEmpsFromJson();
	//! ============================

	//! Project Logic
	cout << "Welcome, Sir! This project is working great."<< endl;
	printAllEmp();

	//! Saving All Data to JSON Files
	saveEmpsToJson();
}
