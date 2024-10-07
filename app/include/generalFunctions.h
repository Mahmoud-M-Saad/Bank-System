#pragma once
#include <iostream>
//#include <cctype>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//! Colored Messages
const void errorMsg(const string& msg);
const void successMsg(const string& msg);
const void askMsg(const string& msg);
const void InfoMsg(const string& msg);

//! Global Functions
const string toDec(const double& amount);

//! Print Function
void drawText(string text);
const void printUserName(const string& name);