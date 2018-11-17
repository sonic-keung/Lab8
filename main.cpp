#include "visits.hpp"

using namespace std;

int main() {
    Visit v;

    // read the peoplePlaces.txt file
    v.readFile();

    // print everybody in the city alphabetically
    cout << "Everybody in the city\n" << endl;
    v.print();

    cout << "\n\nVisited both Krusty-Burger and Tavern" << endl;
    v.visitKBandT();

    cout << "\n\nDid NOT visit Krusty-Burger and Home" << endl;
    v.visitNotKBNotHome();

    cout << "\n\nVisited Krusty-Burger and School but did NOT visit Tavern and Home" << endl;
    v.visitKBvSNotTNotH();

    cout << "\n\nRemoving visited all locations" << endl;
    v.remove();

    cout << "\nEverybody in the city after removing people who visited all location" << endl;
    v.print();

    return 0;
}
