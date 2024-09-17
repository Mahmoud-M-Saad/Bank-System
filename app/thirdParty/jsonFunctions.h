#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

// Template to load data from JSON
template<typename Ty>
void loadDataFromJSON(const string& filename, vector<Ty>& data, Ty(*deserialize)(const json&)) {
    cout << "InLoad";
    ifstream infile("database/" + filename);

    if (infile.is_open()) {
        json j;
        infile >> j;  // Load JSON data from file to j

        data.clear();  // Clear existing data in vector

        // Deserialize each object and push to vector
        for (const auto& item : j) {
            data.push_back(deserialize(item));
        }
        infile.close();
    }
    else {
        cerr << "Could not open " + filename + " file." << endl;
    }
}

// Template to save data to JSON
template<typename Ty>
void saveDataToJSON(const string& filename, const vector<Ty>& data, json(*serialize)(const Ty&)) {
    json j;

    // Serialize each object and add to JSON array
    for (const auto& obj : data) {
        j.push_back(serialize(obj));
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
