#include <iostream>
#include <vector>
#include <algorithm>  // for sort, next_permutation
using namespace std;

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void nextPermutationBrute(vector<int>& nums) {
    // Step 1: Generate all permutations
    vector<vector<int>> allPerms;
    vector<int> temp = nums;

    sort(temp.begin(), temp.end());

    do {
        allPerms.push_back(temp);
    } while (next_permutation(temp.begin(), temp.end()));

    // Step 2: Find current permutation and return next
    for (int i = 0; i < allPerms.size(); i++) {
        if (allPerms[i] == nums) {
            if (i + 1 < allPerms.size()) {
                nums = allPerms[i + 1]; // Return next permutation
            } else {
                nums = allPerms[0]; // If last, return first
            }
            return;
        }
    }
}

int main() {
    vector<int> arr = {3, 1, 2};

    cout << "Original array: ";
    printVector(arr);

    nextPermutationBrute(arr);

    cout << "Next permutation: ";
    printVector(arr);

    return 0;
}