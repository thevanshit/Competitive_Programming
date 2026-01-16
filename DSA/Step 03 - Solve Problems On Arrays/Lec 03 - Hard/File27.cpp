#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int Prefix = 1;
    int Suffix = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (Prefix == 0) Prefix = 1;
        if ( Suffix == 0) Suffix = 1;

        Prefix *= nums[i];
        Suffix *= nums[nums.size() - 1 - i];

        maxProd = max(maxProd, max(Prefix,Suffix));
    }
    
    return maxProd;
}

// Example usage
int main() {
    vector<int> nums = {2, 3, -1, 4};
    cout << "Maximum product subarray: " << maxProduct(nums) << endl;
    return 0;
}
