#include <iostream>
#include <vector>
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

    int repeating = -1;
    int missing = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i){
                count++;
            }
        }
        if ( count == 2){
            repeating = i;
        }
        if ( count == 0){
            missing = i;
        }
        if (repeating == -1 && missing == -1) break;
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
