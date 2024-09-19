#include "validation.h"

static bool is_valid_id(int id) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        errorMsg("Invalid ID. Please provide a valid ID.");
    }

    return true;
};

static string trim(const string& str) {
    regex spaceRegex("^\\s+|\\s+$");
    return regex_replace(str, spaceRegex, "");
}

static bool is_valid_name(string name) {
    // Trim spaces
    name = trim(name);

    // Validate length
    //if (name.length() < 5 || name.length() > 20 || !all_of(name.begin(), name.end(), ::isalpha)) {
    if (name.length() < 5 || name.length() > 20) {
        errorMsg("Name must be between 5 and 20 characters.");
        return false;
    }

    // Validate alphabetic characters and spaces
    regex nameRegex(R"([a-zA-Z\s]+)");
    if (name.empty() || !regex_match(name, nameRegex)) {
        errorMsg("Name must contain only alphabetic characters.");
        return false;
    }

    return true;
};

static bool is_valid_phone(const string& phone) {
    regex phoneRegex(R"(^01[0125][0-9]{8}$)");
    if (!regex_match(phone, phoneRegex)) {
        errorMsg("Invalid phone number.");
        errorMsg("Please enter a valid Egyptian phone number (starts with 010,011,012,015 e.g., 01012345678).");
        return false;
    }

    return true;
};

static bool is_valid_email(const string& email) {
    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    if (email.empty() || !regex_match(email, emailRegex) || email.length() > 50) {
        errorMsg("Invalid email format. Please enter a valid email.");
        return false;
    }

    //! Search for the email in DB
    //if (get_name_by_email(email) != "Not Found") {
    //    errorMsg("This email is already registered.");
    //    return false;
    //}

    return true;
};

static string hash_password(string& password) {
    char ch;
    password.clear();
    while ((ch = _getch()) != '\r') {  // '\r' is Enter key
        if (ch == '\b') {  // Backspace
            if (!password.empty()) {
                cout << "\b \b";  // Erase '*' on backspace
                password.pop_back();
            }
        }
        else {
            password.push_back(ch);
            cout << '*';
        }
    }
    return password;
};
static bool is_valid_password(const string& password) {
    if (password.empty() || password.length() < 8) {
        errorMsg("Password must be at least 8 characters long.");
        return false;
    }

    return true;
};

int Validation::valid_id() {
    int id;
    while (true) {
        askMsg("Enter ID: ");
        cin >> id;
        if (is_valid_id(id)) {
            return id;
        }
    }
};

string Validation::valid_name() {
    string name;
    while (true) {
        askMsg("Enter Your Name: ");
        getline(cin, name);
        if (is_valid_name(name)) {
            return name;
        }
    }
};

string Validation::valid_phone() {
    string phone;
    while (true) {
        askMsg("Enter your Egyptian Phone Number: ");
        getline(cin, phone);
        if (is_valid_phone(phone)) {
            return phone;
        }
    }
};

string Validation::valid_email() {
    string email;
    while (true) {
        askMsg("Enter your Email: ");
        getline(cin, email);
        if (is_valid_email(email)) {
            return email;
        }
    }
};

string Validation::valid_password() {
    string password;
    while (true) {
        askMsg("Enter your Password: ");
        password = hash_password(password);
        if (is_valid_password(password)) {
            return password;
        }
    }
};

double Validation::valid_amount(double min, double max) {
    double amount;
    while (true) {
        cout << endl;
        askMsg("Enter the amount: ");
        cin >> amount;
        if (cin.fail() || amount < min || amount > max) {
            errorMsg("Invalid amount. Please enter a value between $" + toDec(min) + " and $" + toDec(max));
            cin.clear();  // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard invalid input
        }
        else {
            return amount;
        }
    }
};

double Validation::valid_balance() {
    return valid_amount(1500.0, 1000000.0);
};

double Validation::valid_salary() {
    return valid_amount(5000.0, 25000.0);
};
