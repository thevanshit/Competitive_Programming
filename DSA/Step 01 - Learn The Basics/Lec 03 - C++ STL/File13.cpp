#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Declare unordered_multimap
    unordered_multimap<int, string> umm;

    // Insert key-value pairs (including duplicates)
    umm.insert({1, "Apple"});
    umm.insert({2, "Banana"});
    umm.insert({1, "Apricot"});
    umm.insert({3, "Cherry"});
    umm.insert({2, "Blueberry"});
    umm.insert({4, "Dragonfruit"});

    // Display elements (unordered)
    cout << "Elements in the unordered_multimap:\n";
    for (auto it = umm.begin(); it != umm.end(); ++it) {
        cout << it->first << " => " << it->second << endl;
    }

    // Count number of elements with key 2
    int key = 2;
    cout << "\nCount of key " << key << ": " << umm.count(key) << endl;

    // Find and print all values for key = 1 using equal_range
    cout << "\nAll values for key = 1:\n";
    auto range = umm.equal_range(1);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " => " << it->second << endl;
    }

    // Erase all entries for key = 2
    umm.erase(2);

    cout << "\nAfter erasing key 2:\n";
    for (auto it = umm.begin(); it != umm.end(); ++it) {
        cout << it->first << " => " << it->second << endl;
    }

    // Erase one element using iterator
    if (!umm.empty()) {
        umm.erase(umm.begin());
    }

    cout << "\nAfter erasing one element from beginning:\n";
    for (auto it = umm.begin(); it != umm.end(); ++it) {
        cout << it->first << " => " << it->second << endl;
    }

    // Size and empty check
    cout << "\nSize: " << umm.size() << endl;
    cout << "Is empty? " << (umm.empty() ? "Yes" : "No") << endl;

    // Clear all elements
    umm.clear();
    cout << "Size after clear: " << umm.size() << endl;

    return 0;
}