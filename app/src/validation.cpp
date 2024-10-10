#include "validation.h"

static string hash_password(string& password) {
    char ch;
    password.clear();
    while ((ch = _getch()) != '\r') {
        if (ch == '\b' && !password.empty()) {
            cout << "\b \b"; password.pop_back();
        }
        else {
            password.push_back(ch); cout << '*';
        };
    }
    return password;
};

template <typename Func>
string validate_input(Func validation_func, const string& prompt, const string& error_msg) {
    string input{};
    while (true) {
        askMsg(prompt);
        if (prompt == "Enter Your Password: ") {
            input = hash_password(input);
            cout << endl;
        }
        else {
            getline(cin, input);
        }
        if (validation_func(input)) { return input; };
        errorMsg(error_msg);
    }
};

static bool is_valid_choice(const string& choice) {
    regex choiceRegex(R"(^[1-8]$)"); // one char from 1 to 7
    return (regex_match(choice, choiceRegex));
};
static bool is_valid_sub_choice(const string& sub_choice) {
    regex sub_choiceRegex(R"(^[CEA]$)"); // one char C/c or E/e 
    return (regex_match(sub_choice, sub_choiceRegex));
};
static bool is_valid_Sid(const string& Sid) {
    regex SidRegex(R"(^[EAC][a-zA-Z0-9]{3,4}\d{1,2}$)");
    return (regex_match(Sid, SidRegex));
};
static bool is_valid_name(const string& name) {
    regex nameRegex(R"(^\s*([a-zA-Z]+(?:\s+[a-zA-Z]+)*)\s*$)");
    return ((regex_match(name, nameRegex) && name.length() >= 5 && name.length() <= 20));
};
static bool is_valid_phone(const string& phone) {
    regex phoneRegex(R"(^01[0125][0-9]{8}$)");
    return regex_match(phone, phoneRegex);
};
static bool is_valid_email(const string& email) {
    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    //! check if the email is already found
    return (regex_match(email, emailRegex) && email.length() <= 40);
};
static bool is_valid_password(const string& password) {
    return password.length() >= 8;
};
static bool is_valid_amount(const string& input, double min, double max) {
    double amount;
    stringstream ss(input); ss >> amount;
    return !(ss.fail() || !ss.eof() || amount < min || amount > max);
};

char Validation::valid_choice() {
    string qus = "Please select only one of these options: ";
    string errMsg = "Please choose a valid option.";
    return (validate_input(is_valid_choice, qus, errMsg)).at(0);
};
char Validation::valid_sub_choice() {
    string qus = "Choose Operations on Client or Employee (C/E/A): ";
    string errMsg = "Invalid input. Please enter only one character (C/E/A).";
    return (validate_input(is_valid_sub_choice, qus, errMsg)).at(0);
};
int Validation::valid_id() {
    string errMsg = "Invalid ID.";
    string Sid = validate_input(is_valid_Sid, "Enter ID: ", errMsg);
    int id = stoi(Sid.erase(0, 4));
    return id;
};
string Validation::valid_Sid() {
    string errMsg = "Invalid ID.";
    return validate_input(is_valid_Sid, "Enter ID: ", errMsg);
};
string Validation::valid_name() {
    string errMsg = "Invalid name. Name must be 5-20 alphabetic characters.";
    return validate_input(is_valid_name, "Enter Name: ", errMsg);
};
string Validation::valid_phone() {
    string errMsg = "Invalid Egyptian phone number. Phone should start with 010, 011, 012, or 015 (e.g., 01012345678).";
    return validate_input(is_valid_phone, "Enter Phone: ", errMsg);
};
string Validation::valid_email() {
    string errMsg = "Invalid email format. (e.g., mail@gmail.com).";
    return validate_input(is_valid_email, "Enter Email: ", errMsg);
};
string Validation::valid_password(string qus) {
    string errMsg = "Invalid password. Can't be less than 8 characters.";
    return validate_input(is_valid_password, qus, errMsg);
};
double Validation::valid_amount(const double& min, const double& max) {
    string errMsg = "Invalid amount. Please enter a value between $" + toDec(min) + "and $" + toDec(max);
    string amountStr = validate_input(
        [min, max](const string& input) { return is_valid_amount(input, min, max); },
        "Enter the amount: ", errMsg
    );
    return stod(amountStr); // Convert validated string to double and return
};
