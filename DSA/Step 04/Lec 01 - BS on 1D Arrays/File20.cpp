#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element using binary search
int findPeakElement(const vector<int>& nums) {
    if (nums.size() == 1){
        return 0;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0 && nums[i] > nums[i + 1]){
            return 0;
        }
        else if (i == nums.size()-1 && nums[i] > nums[i - 1]){
            return nums.size()-1;
        }
        else if (nums[i-1] < nums[i] && nums[i] > nums[i+1]){
            return i;
        }

    }
    return -1;
}

int main() {
    vector<int> nums = {1, 3, 20, 4, 1, 0};
    cout << "Input array: ";
    for (int num : nums) cout << num << " ";

    int peakIndex = findPeakElement(nums);

    cout << "\n✅ Found Peak Element at index " << peakIndex
         << ", Value = " << nums[peakIndex] << endl;

    return 0;
}
