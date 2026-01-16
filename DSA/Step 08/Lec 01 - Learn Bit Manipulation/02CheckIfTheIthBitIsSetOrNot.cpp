#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i) {
        string binary = "";
        while (n > 0) {
            binary += (n % 2 == 0 ? '0' : '1');  
            n /= 2;  
        }

        if (i >= binary.size()) return false;

        return binary[i] == '1';
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