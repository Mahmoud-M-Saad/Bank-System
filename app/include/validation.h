#pragma once
#include <iostream>
#include <fstream>
#include <regex>
#include <conio.h>
#include <algorithm>
#include <sstream>
#include <limits>
#include "generalFunctions.h"
using namespace std;

class Validation {
public:
	static int valid_id();
	static string valid_name();
	static string valid_phone();
	static string valid_email();
	static string valid_password();
	static double valid_amount(const double& min, const double& max);
};