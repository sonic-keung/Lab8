#include "visits.hpp"

// open and read file
void Visit::readFile() {
    string people;
    ifstream readFile;
    string readLine;
    string places;
    readFile.open("../peoplePlaces.txt");
    while (getline(readFile, readLine)){
        vector<string>locations;
        istringstream iss(readLine);
        iss >> people;
        while (iss >> places) {
            locations.push_back(places);
        }
        peopleMap.insert(pair<string, vector<string>>(people, locations));
        locations.clear();
    }
}

// display file alphabetically by name
void Visit::print() {
    for (auto it = peopleMap.begin(); it != peopleMap.end(); it++){
        cout << it->first << endl;
    }
}

// display people who visited Krusty-Burger and Tavern only
void Visit::visitKBandT() {
    for (auto it = peopleMap.begin(); it != peopleMap.end(); it++) {
        vector<string> visits = it->second;
        string sChar = it->first;

        if (find(visits.begin(), visits.end(), location1) != visits.end()) {
            if (find(visits.begin(), visits.end(), location2) != visits.end()) {
                cout << sChar << endl;
            }
        }
    }
}

// display people who did not visit Krusty-Burger and home only
void Visit::visitNotKBNotHome() {
    for (auto it = peopleMap.begin(); it != peopleMap.end(); it++) {
        vector<string> visits = it->second;
        string sChar = it->first;

        if (!(find(visits.begin(), visits.end(), location1) != visits.end())) {
            if (!(find(visits.begin(), visits.end(), location4) != visits.end())) {
                cout << sChar << endl;
            }
        }
    }
}

// display people who visited Krusty-Burger but not Tavern and Home only
void Visit::visitKBvSNotTNotH() {
    for (auto it = peopleMap.begin(); it != peopleMap.end(); it++) {
        vector<string> visits = it->second;
        string sChar = it->first;

        if (find(visits.begin(), visits.end(), location1) != visits.end()) {
            if (find(visits.begin(), visits.end(), location3) != visits.end()) {
                if (!(find(visits.begin(), visits.end(), location2) != visits.end())) {
                    if (!(find(visits.begin(), visits.end(), location4) != visits.end())) {
                        cout << sChar << endl;
                    }
                }
            }
        }
    }
}

// display people who visited all locations
void Visit::remove() {
    for (auto it = peopleMap.begin(); it != peopleMap.end(); ) {
        vector<string> visits = it->second;
        string sChar = it->first;

        if (find(visits.begin(), visits.end(), location1) != visits.end() &&
                find(visits.begin(), visits.end(), location2) != visits.end() &&
                find(visits.begin(), visits.end(), location3) != visits.end() &&
                find(visits.begin(), visits.end(), location4) != visits.end()) {
            cout << sChar << endl;
            it = peopleMap.erase(it);
        } else {
            it++;
        }
    }
}

