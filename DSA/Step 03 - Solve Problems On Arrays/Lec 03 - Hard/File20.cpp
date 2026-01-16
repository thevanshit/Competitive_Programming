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

    int XOR = 0;
    for (int i = 0; i < n; i++) {
        XOR ^= arr[i];
        XOR ^= (i + 1);
    }

    int BitNo = 0;
    while ((XOR & (1 << BitNo)) == 0) {
        BitNo++;
    }

    int Zero = 0;
    int One = 0;

    for (int i = 0; i < n; i++) {
        if ((arr[i] & (1 << BitNo)) != 0) {
            One ^= arr[i];
        } else {
            Zero ^= arr[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if ((i & (1 << BitNo)) != 0) {
            One ^= i;
        } else {
            Zero ^= i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == Zero) cnt++;
    }

    if (cnt == 2) return {One, Zero}; // Missing, Repeating
    else return {Zero, One};

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
