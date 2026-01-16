#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums){
        unordered_map <int, int> mpp;

        for(int i=0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        for(auto it : mpp) {
            if(it.second == 1) {
                return it.first;
            }
        }   

        return -1;
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 4, 3, 1, 4};

    Solution sol; 

    int ans = sol.singleNumber(nums);
    
    cout << "The single number in given array is: " << ans;
    
    return 0;
}
