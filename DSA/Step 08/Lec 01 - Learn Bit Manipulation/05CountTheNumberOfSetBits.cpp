#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBits(int n) {
        int count = 0; 

        while (n > 0) {
            count += (n & 1);  
            n >>= 1;  
        }

        return count;
    }
};

int main() {
    int n = 39;  

    Solution sol;
    int result = sol.countSetBits(n);

    cout << "The number of set bits is: " << result << endl;

    return 0;
}