#include "person.h";

Person::Person(int id, string name, string phone, string email, string password) 
	:id(id), name(name), phone(phone), email(email), password(password) {};

void Person::setName(string name) { this->name = name; };
void Person::setPhone(string phone) { this->phone = phone; };
void Person::setEmail(string email) { this->email = email; };
void Person::setPassword(string password) { this->password = password; };

int Person::getId() const { return id; };
string Person::getName() const { return name; };
string Person::getPhone() const { return phone; };
string Person::getEmail() const { return email; };
string Person::getPassword() const { return password; };
