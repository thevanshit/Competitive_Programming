#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRangeXOR(int l, int r){			
		int ans = 0;
		
		for(int i=l; i <= r; i++) {
		    ans ^= i;
		}

		return ans;
	}
};

int main() {
    int l = 3, r = 5;

    Solution sol; 

    int ans = sol.findRangeXOR(l, r);
    
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    
    return 0;
}