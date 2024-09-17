#include "client.h"


//! Don't Use it or change in anything
/*
//! To Store data in vector
vector<Client> client;

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

void loadclientsFromJson() {
    loadDataFromJSON<Client>("client.json", client, deserializeClient);
};
void saveclientsToJson() {
    saveDataToJSON<Client>("client.json", client, serializeClient);
};

//! Testing JSON Connection will be Deleted Later
void printAllclient() {
    client.push_back(Client(0, "Name", "Phone", "Email", "Password", 0.0));
    for (int i = 0; i < client.size(); i++) {
        cout << "Id       : " << client[i].getId() << endl
            << "Name     : " << client[i].getName() << endl
            << "Phone    : " << client[i].getPhone() << endl
            << "Email    : " << client[i].getEmail() << endl
            << "Password : " << client[i].getPassword() << endl
            << "balance   : " << client[i].getBalance() << endl
            << "\n=*=*=*=*=*=*=*=\n";
    };
};
*/