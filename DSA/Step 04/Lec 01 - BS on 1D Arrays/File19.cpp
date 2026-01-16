#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element using binary search
int findPeakElement(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        // Midpoint
        int mid = left + (right - left) / 2;

        cout << "Checking mid at index " << mid << " with value " << nums[mid] << endl;

        // If current mid is greater than next element, move left
        if (nums[mid] > nums[mid + 1]) {
            cout << "nums[" << mid << "] > nums[" << mid + 1 << "] → Moving left\n";
            right = mid; // peak is at mid or to the left of mid
        } else {
            cout << "nums[" << mid << "] <= nums[" << mid + 1 << "] → Moving right\n";
            left = mid + 1; // peak is to the right of mid
        }
    }

    // left == right is the index of a peak
    cout << "➡️  Peak element is at index " << left << " with value " << nums[left] << endl;
    return left;
}

int main() {
    vector<int> nums = {1, 3, 20, 4, 5, 21, 0};
    cout << "Input array: ";
    for (int num : nums) cout << num << " ";
    cout << "\n\n";

    int peakIndex = findPeakElement(nums);

    cout << "\n✅ Found Peak Element at index " << peakIndex
         << ", Value = " << nums[peakIndex] << endl;

    return 0;
}
