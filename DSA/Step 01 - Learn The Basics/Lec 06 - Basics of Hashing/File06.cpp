#include <iostream>
using namespace std;

int main() {

    // Step 1: Take input string from user
    cout << "Enter the string (can include letters, digits, or symbols): ";
    string s;
    cin >> s;

    // Step 2: Precompute the frequency of each ASCII character
    int hash[256] = {0}; // ASCII range (0-255)
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++; // Count occurrences
    }

    // Step 3: Ask user how many queries they want to perform
    cout << "Enter number of character frequency queries: ";
    int q;
    cin >> q;

    // Step 4: For each query, ask the character and print its frequency
    while (q--) {
        cout << "Enter character to find frequency: ";
        char c;
        cin >> c;

        cout << "Frequency of '" << c << "' is: " << hash[c] << endl;
    }

    return 0;
}