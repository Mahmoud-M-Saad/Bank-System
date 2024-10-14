#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

// Template to load data from JSON
template<typename Ty>
void loadDataFromJSON(const string& filename, vector<Ty>& userVector, Ty(*toObj)(const json&)) {
    ifstream infile("database/" + filename);

    if (infile.is_open()) {
        json j;
        infile >> j;  // Load JSON data from file to j

        userVector.clear();  // Clear existing data in vector

        // Deserialize each object and push to vector
        for (const auto& item : j) {
            userVector.push_back(toObj(item));
        }
        infile.close();
    }
    else {
        cerr << "Could not open " + filename + " file." << endl;
    }
}

// Template to save data to JSON
template<typename Ty>
void saveDataToJSON(const string& filename, const vector<Ty>& userVector, json(*toJSON)(const Ty&)) {
    json j;

    // Serialize each object and add to JSON array
    for (const auto& obj : userVector) {
        j.push_back(toJSON(obj));
    }

    ofstream outfile("database/" + filename);
    if (outfile.is_open()) {
        outfile << j.dump(4);  // Save with indentation
        outfile.close();
    }
    else {
        cerr << "Could not open " + filename + " file." << endl;
    }
}
