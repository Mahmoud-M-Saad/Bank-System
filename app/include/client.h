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
    void setSalary(double salary) {};

    //! Getters
    double getBalance() const;

    //! Methods
    void displayInfo();
    void performAction();

    //! Special Methods
    void deposit();
    void withdraw();
    void checkBalance();
    void transferTo(Client& recipient);
};

extern vector<Client> client;
void loadClientsFromJson();
void saveClientsToJson();
