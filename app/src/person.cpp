#include "person.h";

// Constractor
Person::Person(string name, string password, string phone, string email, int id)
	:name(name), password(password), phone(phone), email(email), id(id) {}

// Setter
void Person::setPassword(string password) {
	this->password = password;
}
void Person::setPhone(string phone) {
	this->phone = phone;
}
void Person::setEmail(string email) {
	this->email = email;
}

// Getter
string Person::getName() {
	return name;
}
string Person::getPassword() {
	return password;
}
string Person::getPhone() {
	return phone;
}
string Person::getEmail() {
	return email;
}
int Person::getId() {
	return id;
}