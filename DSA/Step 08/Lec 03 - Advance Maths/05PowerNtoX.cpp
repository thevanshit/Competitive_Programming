#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1.0) return 1; 
        
        long long temp = n; 

        if (n < 0) { 
            x = 1 / x;
            temp = -1*1LL*n;
        }

        double ans = 1;

        for (long long i = 0; i < temp; i++) {
            ans *= x; 
        }
        return ans;
    }
};

int main() {
    Solution sol;
    printf("%.4f\n", sol.myPow(2.0000, 10));
    printf("%.4f\n", sol.myPow(2.0000, -2)); 
    return 0;
}