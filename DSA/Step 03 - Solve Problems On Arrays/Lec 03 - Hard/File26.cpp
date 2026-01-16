#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    
    int maxProd = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int prod = 1;
        for (int j = i; j < nums.size(); j++)
        {
            prod *= nums[j];
            maxProd = max(maxProd,prod);
        }
    }
    
    return maxProd;
}

// Example usage
int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray: " << maxProduct(nums) << endl;
    return 0;
}
