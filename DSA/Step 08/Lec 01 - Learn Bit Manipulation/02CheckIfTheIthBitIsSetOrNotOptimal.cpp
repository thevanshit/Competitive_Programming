#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i) {
        return (n & (1 << i)) != 0;  
    }
};

int main() {
    Solution sol;
    int num = 15;  
    int bitIndex = 3;  

    if (sol.checkIthBit(num, bitIndex)) {
        cout << "The " << bitIndex << "-th bit of " << num << " is set (1)." << endl;
    } else {
        cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << endl;
    }

    return 0;
}