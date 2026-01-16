#include <iostream>
#include <map>
using namespace std;

int main() {

    // Step 1: Take input String
    string str;
    cout << "Enter the String : ";
    cin >> str;

    // Step 2: Precompute frequencies using map
    map<char, int> mp;
    for (int i = 0; i < str.size(); i++) {
        mp[str[i]]++;  // Increase count for each number
    }

    // Optional: To see the entire map (uncomment below)
    
    cout << "\nFrequency Map of Elements:" << endl;
    for (auto Itr : mp)
    {
        cout << Itr.first << " -> " << Itr.second << endl;
    }
    

    // Step 4: Handle queries
    cout << "\nEnter number of queries: ";
    int q;
    cin >> q;

    while (q--) {
        char chr;
        cout << "\nEnter char to find its frequency: ";
        cin >> chr;

        // Step 5: Output the frequency of the queried number
        cout << "Frequency of " << chr << " is: " << mp[chr] << endl;
    }

    return 0;
}