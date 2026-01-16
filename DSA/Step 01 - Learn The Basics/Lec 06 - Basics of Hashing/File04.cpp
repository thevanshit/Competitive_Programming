#include <iostream>
using namespace std;

int main() {
    // Step 1: Take input string from the user
    cout << "Enter a lowercase string: ";
    string s;
    cin >> s;

    // Step 2: Precompute frequency of each character using a hash array
    int hash[26] = {0}; // Only for lowercase letters a-z

    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++; // Mapping 'a' to 0, 'b' to 1, ..., 'z' to 25
    }

    // Step 3: Take number of queries from the user
    cout << "Enter number of queries: ";
    int q;
    cin >> q;

    // Step 4: For each query, take a character and print its frequency
    while (q--) {
        cout << "Enter character to find its frequency: ";
        char c;
        cin >> c;

        // Step 5: Output the frequency of that character
        cout << "Frequency of '" << c << "' is: " << hash[c - 'a'] << endl;
    }

    return 0;
}