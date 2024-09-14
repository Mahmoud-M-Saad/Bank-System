#pragma once
#include <iostream>
#include <string>
using namespace std;

//! Colored Messages
const void errorMsg(const string& msg);
const void successMsg(const string& msg);
const void askMsg(const string& msg);
const void InfoMsg(const string& msg);

//! Print Function
const void printUserName(const string& name);