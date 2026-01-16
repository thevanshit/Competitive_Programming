#include <iostream>
#include <unordered_map>  // Include for using unordered_map (hashmap)
using namespace std;

// Function to count and print frequency of elements in an array
void Frequency(int arr[], int n)
{
    // Declare an unordered_map to store frequency of each unique element
    unordered_map<int, int> map;

    // Loop through the array and populate the map with element frequencies
    for (int i = 0; i < n; i++) {
        map[arr[i]]++;  // Increase count for arr[i]
    }

    // Print the frequency of each element
    cout << "\n Frequency of each unique element in the array:\n" << endl;
    for (auto x : map) {
        cout << "Element " << x.first << " occurs " << x.second << " time(s)." << endl;
    }
}

int main()
{
    // Input array
    int arr[] = {10, 5, 10, 15, 10, 5};

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the input array
    cout << "Input Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the frequency function
    Frequency(arr, n);

    return 0;
}