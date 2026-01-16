#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int sumWithDivisor(const vector<int>& nums, int divisor) {
    int total = 0;
    for (int num : nums){
        total += (int) ceil((double)num / divisor);
    }
    return total;
}

int smallestDivisorBruteForce(const vector<int>& nums, int threshold) {
    int maxNum = *max_element(nums.begin(), nums.end());
    for (int divisor = 1; divisor <= maxNum; ++divisor) {
        if (sumWithDivisor(nums, divisor) <= threshold) {
            return divisor;
        }
    }
    return -1; // theoretically unreachable if input valid
}

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int divisor = smallestDivisorBruteForce(nums, threshold);
    cout << "Smallest Divisor (Brute Force): " << divisor << endl;
    return 0;
}
