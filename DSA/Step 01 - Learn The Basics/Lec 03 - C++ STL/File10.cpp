#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> m;

    // Inserting values
    m.insert({1, "One"});
    m.insert({2, "Two"});
    m.insert({3, "Three"});

    // Inserting using []
    m[4] = "Four";
    m[5] = "Five";

    cout << "Elements present in the unordered_map:\n";
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Accessing a value
    cout << "\nThe value for key 3 is: " << m[3] << endl;

    // Checking if a key exists
    int key = 2;
    if (m.find(key) != m.end()) {
        cout << key << " is present in the map.\n";
    } else {
        cout << key << " is not present in the map.\n";
    }

    // Erasing a key
    m.erase(1);
    cout << "\nMap after erasing key 1:\n";
    for (auto x : m) {
        cout << x.first << " -> " << x.second << endl;
    }

    // Map size
    cout << "\nSize of map: " << m.size() << endl;

    // Checking empty
    if (!m.empty()) {
        cout << "Map is not empty.\n";
    } else {
        cout << "Map is empty.\n";
    }

    // Clearing all elements
    m.clear();
    cout << "Map cleared. Size is now: " << m.size() << endl;

    return 0;
}