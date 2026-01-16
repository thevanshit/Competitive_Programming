#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element using binary search
int findPeakElement(const vector<int>& nums) {
    
    int low = 1;
    int high = nums.size()-2;
    if (nums.size() == 1){
        return 0;
    }
    while (low < high){
        if (nums[0] > nums[1]){
            return 0;
        }
        else if (nums[nums.size()-1] > nums[nums.size()-2]){
            return nums.size()-1;
        }
        int mid = low + (high - low)/2;
        if ((nums[mid] > nums[mid - 1]) && (nums[mid] > nums[mid + 1])){
            return mid;
        }
        else if (nums[mid] > nums[mid - 1]){
            low = mid + 1;
        }
        else if (nums[mid] > nums[mid + 1]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 3, 20, 4, 23, 0};
    cout << "Input array: ";
    for (int num : nums) cout << num << " ";

    int peakIndex = findPeakElement(nums);

    cout << "\n✅ Found Peak Element at index " << peakIndex
         << ", Value = " << nums[peakIndex] << endl;

    return 0;
}
