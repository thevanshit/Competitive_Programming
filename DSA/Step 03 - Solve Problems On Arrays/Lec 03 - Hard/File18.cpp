#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to print a vector
void PrintVec(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to find the missing and repeating number
pair<int, int> findMissingAndRepeating(const vector<int>& arr) {
    int n = arr.size();

    map<int, int> hashmap;
    int repeating = -1, missing = -1;

    // Count occurrences of each number in arr
    for (int i = 0; i < n; i++) {
        hashmap[arr[i]]++;
    }

    // Find missing and repeating
    for (int i = 1; i <= n; i++) {
        if (hashmap[i] == 0) missing = i;
        if (hashmap[i] == 2) repeating = i;

        if (repeating != -1 && missing != -1){
            break;
        }
    }
    return {missing, repeating};
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1}; // n=6, missing=5, repeating=1
    cout << "Given vector Array is : ";
    PrintVec(arr);

    auto res = findMissingAndRepeating(arr);
    cout << "Missing: " << res.first << "\n";
    cout << "Repeating: " << res.second << "\n";
    return 0;
}
