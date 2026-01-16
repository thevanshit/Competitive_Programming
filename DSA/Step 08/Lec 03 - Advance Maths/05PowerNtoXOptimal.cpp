#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double power(double x, long long n) {
        if (n == 0) return 1.0;
        double half = power(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }

    double myPow(double x, int n) {
        long long num = n;  // promote to long long to avoid overflow
        if (num < 0) {
            return 1.0 / power(x, -num);
        }
        return power(x, num);
    }
};


int main() {
    Solution sol;
    double x = 2.0;
    int n = 10;

    double result = sol.myPow(x, n);

    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}