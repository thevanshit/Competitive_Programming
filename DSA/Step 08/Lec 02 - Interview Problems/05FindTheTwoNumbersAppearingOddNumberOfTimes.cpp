#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        vector<int> ans;
        unordered_map <int, int> mpp;

        for(int i=0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        for(auto it : mpp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }   

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};

    Solution sol; 

    vector<int> ans = sol.singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1];
    
    return 0;
}