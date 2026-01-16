#include <iostream>
#include <unordered_map> // Required for using unordered_map
using namespace std;

// Function to calculate frequency and find max/min frequency elements
void Frequency(int arr[], int n)
{
    // Declare an unordered map to store element-frequency pairs
    unordered_map<int, int> map;

    // Step 1: Precompute frequencies of all elements
    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    // Step 2: Initialize tracking variables for max/min frequency
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    // Step 3: Traverse the map to find elements with highest and lowest frequency
    for (auto it : map) {
        int element = it.first;
        int count = it.second;

        // Update maximum frequency and element
        if (count > maxFreq) {
            maxFreq = count;
            maxEle = element;
        }

        // Update minimum frequency and element
        if (count < minFreq) {
            minFreq = count;
            minEle = element;
        }
    }

    // Step 4: Output results
    cout << "\n Input Frequencies:\n";
    for (auto it : map) {
        cout << "   ➤ Element: " << it.first << " → Frequency: " << it.second << endl;
    }

    cout << "\n Element with Highest Frequency:\n";
    cout << "   ➤ Element: " << maxEle << "\n";
    cout << "   ➤ Frequency: " << maxFreq << "\n";

    cout << "\n Element with Lowest Frequency:\n";
    cout << "   ➤ Element: " << minEle << "\n";
    cout << "   ➤ Frequency: " << minFreq << "\n";
}

int main()
{
    // Sample static array input
    int arr[] = {10, 5, 10, 15, 10, 5};

    // Determine the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display input
    cout << "Given Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Call the frequency analysis function
    Frequency(arr, n);

    return 0;
}