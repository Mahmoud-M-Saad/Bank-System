#pragma once
#include <iostream>
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

    //! Getters
    double getBalance() const;

    //! Methods
    void deposit();
    void withdraw();
    void displayInfo();
    void checkBalance();
    void transferTo(Client& recipient);
};

//! For JSON File
void loadClientsFromJson();
void saveClientsToJson();
void removeAllClients();

void printAllClients();