#include <iostream>
#include <vector>
using namespace std;

// Function to count the frequency of each element and
// determine the element with the highest and lowest frequency
void countFreq(int arr[], int n)
{
    // A boolean vector to keep track of visited elements to avoid counting them again
    vector<bool> visited(n, false);

    // Initialize variables to store max and min frequency and their corresponding elements
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    // Loop through each element of the array
    for (int i = 0; i < n; i++) {

        // If the element is already visited (already counted), skip it
        if (visited[i] == true)
            continue;

        // Count frequency of current element
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true; // Mark duplicate as visited
                count++;
            }
        }

        // Update max frequency and corresponding element
        if (count > maxFreq) {
            maxEle = arr[i];
            maxFreq = count;
        }

        // Update min frequency and corresponding element
        if (count < minFreq) {
            minEle = arr[i];
            minFreq = count;
        }
    }

    // Output the results
    cout << "\n📊 Element with the Highest Frequency:\n";
    cout << "   ➤ Element: " << maxEle << "\n";
    cout << "   ➤ Frequency: " << maxFreq << "\n";

    cout << "\n📉 Element with the Lowest Frequency:\n";
    cout << "   ➤ Element: " << minEle << "\n";
    cout << "   ➤ Frequency: " << minFreq << "\n";
}

int main()
{
    // Input: You can change or extend this part for user input if required
    int arr[] = {10, 5, 10, 15, 10, 5};

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the input array
    cout << "📥 Input Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call function to count frequency and find min/max
    countFreq(arr, n);

    return 0;
}