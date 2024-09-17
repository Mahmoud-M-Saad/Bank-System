#include "client.h"

//! To Store data in vector
vector<Client> client;

Client::Client(int id, string name, string phone, string email, string password, double balance)
    :Person(id, name, phone, email, password), balance(balance) {};

void Client::setBalance(double balance) { this->balance = balance; };

double Client::getBalance() const { return balance; };

void Client::deposit() {
    double amount = Validation::valid_balance();
    balance += amount;
    successMsg("Successfully added, Your balance now is: $" + toDec(balance));
}

void Client::withdraw() {
    double amount = Validation::valid_balance();
    if (amount > balance) {
        errorMsg("The amount cannot exceed your balance $" + toDec(balance) + ". Please try again.");
    }
    else {
        balance -= amount;
        successMsg("Wait for your money, Your balance now is: $" + toDec(balance));
    }
};

void Client::displayInfo() {
    cout << "==========================\n";
    cout << "|       Client Card      |\n";
    cout << "==========================\n";
    cout << "==========================\n";
    cout << "| ID: " << id << "                  |\n";
    cout << "| Name: " << setw(16) << left << name << "    |\n";
    cout << "| Balance: $" << setw(10) << fixed << setprecision(2) << balance << "|\n";
    cout << "==========================\n";
}

void Client::checkBalance() {
    InfoMsg("Current balance: $" + toDec(balance));
}

void Client::transferTo(Client& recipient) {
    double amount;
    if (recipient.balance <= 0) {
        amount = Validation::valid_balance();
    }
    else {
        amount = Validation::valid_amount(1,1000000);
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

void addClient() {
    string name = Validation::valid_name();
    string phone = Validation::valid_phone();
    string email = Validation::valid_email();
    string password = Validation::valid_password();
    double balance = Validation::valid_balance();
    int id = (!client.empty()) ? client[client.size() - 1].getId() + 1 : 0;

    Client newClient = { id, name, phone, email, password, balance };
    client.push_back(newClient);
};

void removeAllClients() {
    client.clear();
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
    client.push_back(Client(0, "Name", "Phone", "Email", "Password", 0.0));
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