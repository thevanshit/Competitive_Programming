#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> ans;

        for(int i=1; i <= sqrt(n); i++) {

            if(n % i == 0) {
                ans.push_back(i);
                if((n / i) != i){
                    ans.push_back(n / i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int n = 54;
    Solution sol; 

    vector<int> ans = sol.divisors(n);
    
    cout << "The divisors of " << n << " are: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}