#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums){
        int XOR = 0;

        for(int i = 0; i < nums.size(); i++) {
            XOR ^= nums[i];    
        }

        return XOR;        
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 4, 3, 1, 4};

    Solution sol; 

    int ans = sol.singleNumber(nums);
    
    cout << "The single number in given array is: " << ans;
    
    return 0;
}