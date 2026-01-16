#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumWithDivisor(const vector<int>& nums, int divisor) {
    int total = 0;
    for (int num : nums) {
        total += (num + divisor - 1) / divisor;
    }
    return total;
}

int smallestDivisorBinarySearch(const vector<int>& nums, int threshold) {
    int left = 1;
    int right = *max_element(nums.begin(), nums.end());
    int answer = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sumWithDivisor(nums, mid) <= threshold) {
            answer = mid;      // try smaller divisor
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int divisor = smallestDivisorBinarySearch(nums, threshold);
    cout << "Smallest Divisor (Binary Search): " << divisor << endl;
    return 0;
}
