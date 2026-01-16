#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    // Inserting using insert()
    m.insert({1, "One"});
    m.insert({2, "Two"});
    m.insert({3, "Three"});

    // Inserting using []
    m[4] = "Four";
    m[5] = "Five";

    cout << "Elements present in the map:\n";
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Accessing value by key
    cout << "\nThe value for key 3 is: " << m[3] << endl;

    // Checking if key exists
    int n = 2;
    if (m.find(n) != m.end())
        cout << n << " is present in map" << endl;
    else
        cout << n << " is not present in map" << endl;

    // Erasing key 1
    m.erase(1);

    cout << "\nMap after deleting key 1:\n";
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Size of map
    cout << "\nSize of the map: " << m.size() << endl;

    // Checking empty
    if (!m.empty())
        cout << "Map is not empty" << endl;
    else
        cout << "Map is empty" << endl;

    // Clearing the map
    m.clear();
    cout << "Size after clearing the map: " << m.size() << endl;

    return 0;
}