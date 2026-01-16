#include <iostream>
#include <vector>
using namespace std;

// Function to count and print frequency of each element
void countFreq(int arr[], int n)
{
    // A boolean vector to mark elements that are already counted
    vector<bool> visited(n, false);

    cout << "\nFrequencies of elements in the array:\n" << endl;

    // Loop through each element
    for (int i = 0; i < n; i++) {

        // If already counted, skip to the next element
        if (visited[i] == true)
            continue;

        // Count frequency of arr[i]
        int count = 1;
        for (int j = i + 1; j < n; j++) {

            // If duplicate found, mark visited and increment count
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }

        // Print the element and its frequency
        cout << "Element " << arr[i] << " occurs " << count << " time(s)" << endl;
    }
}

int main()
{
    // Declare and initialize the array
    int arr[] = {10, 5, 10, 15, 10, 5};

    // Calculate size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the input array
    cout << "Input Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the frequency counting function
    countFreq(arr, n);

    return 0;
}