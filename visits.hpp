#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Visit {
private:
    map<string, vector<string>> peopleMap;
public:
    void visitKBandT();
    void visitNotKBNotHome();
    void visitKBvSNotTNotH();
    void remove();
    void print();
    void readFile();
    string location1 = "Krusty-Burger";
    string location2 = "Tavern";
    string location3 = "School";
    string location4 = "Home";

};