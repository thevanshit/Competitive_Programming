#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    cout << "Original vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Sorting (optional but ensures we start from lowest permutation)
    sort(v.begin(), v.end());

    // Generate all permutations using next_permutation
    cout << "All permutations:\n";
    do {
        for (int x : v) cout << x << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    // After all permutations, vector resets to original sorted order
    cout << "\nAfter all permutations, vector becomes: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Custom range permutation
    vector<int> a = {1, 2, 3, 4};
    cout << "\nOriginal vector a: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    // Only permute middle 3 elements (2,3,4)
    next_permutation(a.begin() + 1, a.end());

    cout << "After next_permutation(a.begin()+1, a.end()): ";
    for (int x : a) cout << x << " ";
    cout << endl;

    // Check if there is a next permutation
    vector<int> b = {3, 2, 1};
    bool hasNext = next_permutation(b.begin(), b.end());

    cout << "\nDoes b have a next permutation? ";
    if (hasNext)
        cout << "Yes\n";
    else {
        cout << "No (was last permutation), now reset to smallest: ";
        for (int x : b) cout << x << " ";
        cout << endl;
    }

    return 0;
}