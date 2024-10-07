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
    int getId() const;
    string getName() const;
    string getPassword() const;
    double getBalance() const;

    //! Methods
    void updateClient();
    void displayInfo();
    void deposit();
    void withdraw();
    void checkBalance();
    void transferTo(Client& recipient);
};

extern vector<Client> client;

//! CRUD Operations
void addClient();
//Client* getClientByID(int id);
void getAllClients();
void deleteClientByID(int id);
void deleteAllClients();

Client* getClientById();
void clientActions(char choice, Client& c);

//! For JSON File
void loadClientsFromJson();
void saveClientsToJson();

void printAllClients();