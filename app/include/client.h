#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>  // For std::max
#include "person.h"
using namespace std;

class Client : public Person {
private:
    double balance;

public:
    //! Constructor
    Client(int id, string name, string phone, string email, string password, double balance);

    //! Setters
    void setBalance(double balance);
    void setSalary(double salary) {};

    //! Getters
    int getId() const;
    string getName() const;
    string getPassword() const;
    double getBalance() const;

    //! Methods
    void displayInfo();
    void deposit();
    void withdraw();
    void checkBalance();
    void transferTo(Client& recipient);
};

extern vector<Client> client;


void clientActions(char choice, Client& c);

//! For JSON File
void loadClientsFromJson();
void saveClientsToJson();

void printAllClients();