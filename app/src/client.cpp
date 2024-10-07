#include "client.h"
#include <globalFun.h>

//! To Store data in vector
vector<Client> client;
static bool is_Found(int id) {
    return find_if(client.begin(), client.end(), [id](const Client& e) { return e.getId() == id; }) != client.end();
};

Client::Client(int id, string name, string phone, string email, string password, double balance)
    :Person(id, name, phone, email, password), balance(balance) {};

void Client::setBalance(double balance) { this->balance = balance; };
int Client::getId() const { return id; };
string Client::getName() const { return name; };
string Client::getPassword() const { return password; };
double Client::getBalance() const { return balance; };

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

void Client::updateClient() {
    if (!is_Found(id)) {
        errorMsg("This id is not found, Please enter a valid ID.");
        return;
    }
    char option;
    askMsg("What is the field you want to edit ?\n");
    askMsg("1.Name\n2.Phone\n3.Email\n4.Password\n5.Balance\n6.All Fields\n\nPlease choose of these options: ");
    cin >> option; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (option) {
    case '1':
        name = Validation::valid_name();
        successMsg("Name updated successfully.");
        break;
    case '2':
        phone = Validation::valid_phone();
        successMsg("Phone updated successfully.");
        break;
    case '3':
        email = Validation::valid_email();
        successMsg("Email updated successfully.");
        break;
    case '4':
        password = Validation::valid_password();
        successMsg("Password updated successfully.");
        break;
    case '5':
        balance = Validation::valid_amount(1, 1000000.0);
        successMsg("Balance updated successfully.");
        break;
    case '6':
        name = Validation::valid_name();
        phone = Validation::valid_phone();
        email = Validation::valid_email();
        password = Validation::valid_password();
        balance = Validation::valid_amount(1, 1000000.0);
        successMsg("Employee updated successfully.");
        break;
    default:
        errorMsg("Please select only one of these options.");
        break;
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

void addClient() {
    string name = Validation::valid_name();
    string phone = Validation::valid_phone();
    string email = Validation::valid_email();
    string password = Validation::valid_password();
    double balance = Validation::valid_amount(1500, 1000000);
    int id = (!client.empty()) ? client[client.size() - 1].getId() + 1 : 1;

    Client newClient = { id, name, phone, email, password, balance };
    client.push_back(newClient);
};
//Client* getClientByID(int id) {
//    if (is_Found(id)) {
//        return &client[id];
//    }
//    errorMsg("This ID is not found, please enter a valid ID.");
//    return nullptr;
//};
void getAllClients() {
    if (client.empty() || client.size() <= 1) {
        errorMsg("Sorry! No clients to display.");
        return;
    }

    for (int i = 1; i < client.size(); ++i) {
        client[i].displayInfo();
        cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
    }
};
void deleteClientByID(int id) {
    if (is_Found(id) && id != 0) {
        auto it = remove_if(client.begin(), client.end(), [id](const Client& c) { return c.getId() == id; });
        if (it != client.end()) {
            client.erase(it);
            successMsg("Client with ID (" + to_string(id) + ") deleted successfully.");
        }
    }
    else {
        errorMsg("Invalid ID. Cannot delete.");
    };
};
void deleteAllClients() {
    client.clear();
    client.emplace_back(0, "C Name", "C Phone", "C Email", "C Password", 1500);
    successMsg("All clients deleted successfully.");
};

Client* getClientById() {
    Client* c2 = nullptr;
    int id = Validation::valid_id();
    c2 = getUserByID(client, id);
    while (c2 == nullptr) {
        errorMsg("Client not found. Please enter a valid ID.");
        id = Validation::valid_id();
        c2 = getUserByID(client, id);
    }
    return c2;
};

void clientActions(char choice, Client& c) {    
    Client* c2;
    switch (choice) {
    case '1':
        c.displayInfo();
        break;

    case '2':
        c.checkBalance();
        break;

    case '3':
        c.deposit();
        break;

    case '4':
        c.withdraw();
        break;

    case '5':
        c2 = getClientById();
        c.transferTo(*c2);
        break;

    case '6':
        cout << "6- Update your Password\n";
        break;

    default:
        errorMsg("Please choose a valid option.\n");
        break;
    }
}

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