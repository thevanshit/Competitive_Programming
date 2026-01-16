#include <iostream>
#include <map>
using namespace std;

int main() {

    // Step 1: Take input for size of array
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    // Step 2: Input array elements
    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Precompute frequencies using map
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;  // Increase count for each number
    }

    // Optional: To see the entire map (uncomment below)
    
    cout << "\nFrequency Map of Elements:" << endl;
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }
    

    // Step 4: Handle queries
    cout << "\nEnter number of queries: ";
    int q;
    cin >> q;

    while (q--) {
        int number;
        cout << "\nEnter number to find its frequency: ";
        cin >> number;

        // Step 5: Output the frequency of the queried number
        cout << "Frequency of " << number << " is: " << mp[number] << endl;
    }

    return 0;
}