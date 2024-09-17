#pragma once
#include <iostream>
#include "person.h"
using namespace std;

class Client : public Person {
	
};

//! For JSON File
void loadEmpsFromJson();
void saveEmpsToJson();

void printAllEmp();