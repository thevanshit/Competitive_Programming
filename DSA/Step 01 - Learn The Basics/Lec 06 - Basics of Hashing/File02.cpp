#include <iostream>
using namespace std;

int main() {
    // Step 1: Take size of array input
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Step 2: Declare the array to store elements
    int arr[n];

    // Step 3: Input each element from the user
    cout << "Enter " << n << " numbers (each between 0 and 12):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 4: Declare and initialize a hash array to store frequencies
    // The size is 13 because we assume elements are between 0 and 12
    int hash[13] = {0};

    // Step 5: Precompute the frequency of each number
    // Only update frequency if number is in the range [0, 12]
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 && arr[i] <= 12) {
            hash[arr[i]]++;  // Increase count for this number
        } else {
            cout << "Warning: Number " << arr[i] << " is out of range and will be ignored." << endl;
        }
    }

    // Step 6: Take number of queries from the user
    int q;
    cout << "\nEnter the number of queries: ";
    cin >> q;

    // Step 7: Process each query
    cout << "Enter the numbers to query their frequency:" << endl;
    while (q--) {
        int number;
        cin >> number;

        // Step 8: Output frequency if in range, else output 0
        if (number >= 0 && number <= 12) {
            cout << "Frequency of " << number << " = " << hash[number] << endl;
        } else {
            cout << "Frequency of " << number << " = 0 (Number out of valid range 0-12)" << endl;
        }
    }

    return 0;
}