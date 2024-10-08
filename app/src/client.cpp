#include "client.h"
#include <globalFun.h>

//! To Store data in vector
vector<Client> client;

Client::Client(int id, string name, string phone, string email, string password, double balance)
    :Person(id, name, phone, email, password), balance(balance) {};

void Client::setBalance(double balance) { this->balance = balance; };
int Client::getId() const { return id; };
string Client::getName() const { return name; };
string Client::getPassword() const { return password; };
double Client::getBalance() const { return balance; };

void Client::displayInfo() {
    cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
         << "|          Client Card          |" << endl
         << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
         << "    ID: " << id << endl
         << "    Name: " << name << endl
         << "    Phone: " << phone << endl
         << "    Email: " << email << endl
         << "    Balance: $" << balance << endl
         << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
};
void Client::deposit() {
    double amount = Validation::valid_amount(1, 1000000.0);
    double newBalance = balance + amount;
    if (newBalance < 0 || newBalance > 1000000.0) {
        errorMsg("Your balance must be at least $1500 and not exceed $1000000.");
        errorMsg("Your balance now is $"+toDec(balance));
        return;
    }
    balance += amount;
    successMsg("Successfully added, Your balance now is: $" + toDec(balance));
}
void Client::withdraw() {
    double amount = Validation::valid_amount(1, 1000000.0);
    if (amount > balance) {
        errorMsg("The amount cannot exceed your balance $" + toDec(balance) + ". Please try again.");
    }
    else {
        balance -= amount;
        successMsg("Wait for your money, Your balance now is: $" + toDec(balance));
    }
};
void Client::checkBalance() {
    InfoMsg("Current balance: $" + toDec(balance));
}
void Client::transferTo(Client& recipient) {
    double amount;
    if (recipient.balance <= 0) {
        amount = Validation::valid_amount(1500, 1000000);
    }
    else {
        amount = Validation::valid_amount(1, 1000000);
    }

    if (amount > balance) {
        errorMsg("The amount cannot exceed your balance $" + toDec(balance) + ". Please try again.");
    }
    else {
        balance -= amount;
        recipient.balance += amount;
        successMsg("Successfully transferred $" + toDec(amount) + " to " + recipient.name);
    }
};

//! To convert JSON type to Client type and vice versa
static Client deserializeClient(const json& j) {
    Client client = {
        j.at("id").get<int>(),
        j.at("name").get<string>(),
        j.at("phone").get<string>(),
        j.at("email").get<string>(),
        j.at("password").get<string>(),
        j.at("balance").get<double>()
    };
    return client;
};
static json serializeClient(const Client& client) {
    json j = {
        {"id", client.getId()},
        {"name", client.getName()},
        {"phone", client.getPhone()},
        {"email", client.getEmail()},
        {"password", client.getPassword()},
        {"balance", client.getBalance()}
    };
    return j;
};

void loadClientsFromJson() {
    loadDataFromJSON<Client>("client.json", client, deserializeClient);
};
void saveClientsToJson() {
    saveDataToJSON<Client>("client.json", client, serializeClient);
};

//! Testing JSON Connection will be Deleted Later
void printAllClients() {
    if (!client.empty()) {
        client.push_back(Client(0, "Name", "Phone", "Email", "Password", 0.0));
    };
    for (int i = 0; i < client.size(); i++) {
        cout << "Client Id   : " << client[i].getId() << endl
             << "Client Name : " << client[i].getName() << endl
             << "Phone       : " << client[i].getPhone() << endl
             << "Email       : " << client[i].getEmail() << endl
             << "Password    : " << client[i].getPassword() << endl
             << "balance     : " << client[i].getBalance() << endl
             << "\n=*=*=*=*=*=*=*=\n";
    };
};