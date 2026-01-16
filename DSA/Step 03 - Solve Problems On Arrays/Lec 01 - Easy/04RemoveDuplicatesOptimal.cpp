#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Removes duplicates in-place from a sorted array and returns new length.
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); ++j) {
        if (nums[j] != nums[i]) {
            ++i;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the sorted array: ";
    for (int& x : nums) cin >> x;

    int newLen = removeDuplicates(nums);
    cout << "Number of unique elements: " << newLen << '\n';
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLen; ++i) cout << nums[i] << ' ';
    cout << '\n';

    return 0;
}
