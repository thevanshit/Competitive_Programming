#include <iostream>
#include <map>  // multimap is in map header
using namespace std;

int main() {
    multimap<int, string> mm;

    // Inserting key-value pairs (some with duplicate keys)
    mm.insert({1, "Apple"});
    mm.insert({2, "Banana"});
    mm.insert({1, "Apricot"});
    mm.insert({3, "Cherry"});
    mm.insert({2, "Blueberry"});
    mm.insert({4, "Dragonfruit"});

    // Display elements in multimap (ordered by key)
    cout << "Elements in the multimap:\n";
    for (auto it = mm.begin(); it != mm.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Count how many values for a key
    int key = 2;
    cout << "\nNumber of elements with key " << key << ": " << mm.count(key) << endl;

    // Find all values of a specific key using equal_range
    cout << "\nAll values for key " << key << ":\n";
    auto range = mm.equal_range(key);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Erase all entries with a key
    mm.erase(1);

    cout << "\nAfter erasing all elements with key 1:\n";
    for (auto it = mm.begin(); it != mm.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Erase one element using iterator (first element)
    mm.erase(mm.begin());

    cout << "\nAfter erasing first element:\n";
    for (auto it = mm.begin(); it != mm.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Size and empty check
    cout << "\nSize of multimap: " << mm.size() << endl;
    cout << "Is multimap empty? " << (mm.empty() ? "Yes" : "No") << endl;

    // Clear the multimap
    mm.clear();
    cout << "Size after clearing: " << mm.size() << endl;

    return 0;
}