#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        
        bool isPositive = true;

        if(dividend >= 0 && divisor < 0) 
            isPositive = false;
        else if(dividend < 0 && divisor > 0)
            isPositive = false;

        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);

        long long ans = 0;

        while(n >= d) {
           long long temp = d;
           long long multiple = 1;

           while (temp << 1 <= n){
                temp <<= 1;
                multiple <<= 1;
           }

           n -= temp;
           ans += multiple;
        }

        if(ans > INT_MAX && isPositive) 
            return INT_MAX;
        if(ans > INT_MAX && !isPositive)
            return INT_MIN;

        return isPositive ? ans : -1*ans;
    }
};

int main() {
    int dividend = 22, divisor = 3;
    
    Solution sol; 

    int ans = sol.divide(dividend, divisor);
    
    cout << "The result of dividing " << dividend << " and " << divisor << " is " << ans;
    
    return 0;
}