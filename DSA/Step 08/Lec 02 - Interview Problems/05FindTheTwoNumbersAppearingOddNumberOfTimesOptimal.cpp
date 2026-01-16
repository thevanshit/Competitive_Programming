#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        int n = nums.size();
        long XOR = 0;

        for(int i = 0; i < n; i++){
            XOR ^= nums[i];
        }

        int Rightmost = (XOR & (XOR - 1)) ^ XOR;
        
        int XOR1 = 0;
        int XOR2 = 0;

        for(int i = 0; i < n; i++){
            if (Rightmost & nums[i]){
                XOR1 ^= nums[i];
            }
            else{
                XOR2 ^= nums[i];
            }
        }

        if (XOR1 < XOR2) return {XOR1, XOR2};
        else return {XOR2, XOR1};
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    
    Solution sol; 

    vector<int> ans = sol.singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    
    return 0;
}