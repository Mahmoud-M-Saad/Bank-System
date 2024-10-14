#include "client.h"
#include "authFun.h"

vector<Client> client;
Client::Client(int id, string name, string phone, string email, string password, double balance)
    :Person(id, name, phone, email, password), balance(balance) {};

void Client::setBalance(double balance) { this->balance = balance; };
double Client::getBalance() const { return balance; };

void Client::displayInfo() {
    cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
         << "|          Client Card          |" << endl
         << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl
         << "    ID: " << "C372" << id << endl
         << "    Name: " << name << endl
         << "    Phone: " << phone << endl
         << "    Email: " << email << endl
         << "    Balance: $" << balance << endl
         << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
};
void Client::performAction() {
    clientActions(*this, name);
    return;
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
    amount = (recipient.balance <= 0) ?
        amount = Validation::valid_amount(1500, 1000000):
        amount = Validation::valid_amount(1, 1000000);
    //if (recipient.balance <= 0) {
    //    amount = Validation::valid_amount(1500, 1000000);
    //}
    //else {
    //    amount = Validation::valid_amount(1, 1000000);
    //}

    if (amount > balance) {
        errorMsg("The amount cannot exceed your balance $" + toDec(balance) + ". Please try again.");
    }
    else if (id == recipient.id) {
        errorMsg("Sorry! You can't transfer money to yourself. Please try again.");
    }
    else {
        askMsg("Are you sure you want to transfer $" + toDec(amount) + " to \"" + recipient.name + "\" (Y/N): ");
        char confirm = Validation::valid_choice();
        if (confirm == 'y' || confirm == 'Y') {
            balance -= amount;
            recipient.balance += amount;
            successMsg("Successfully transferred $" + toDec(amount) + " to " + recipient.name);
        }
        else {
            InfoMsg("Thanks for using our Bank,\nwe will return you to the options page.\n");
            return;
        }
    }
};

//! To convert JSON type to Client type and vice versa
static Client JSONToClient(const json& j) {
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
static json ClientToJSON(const Client& client) {
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
    loadDataFromJSON<Client>("client.json", client, JSONToClient);
};
void saveClientsToJson() {
    saveDataToJSON<Client>("client.json", client, ClientToJSON);
};
