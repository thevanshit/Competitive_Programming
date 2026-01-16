#include <iostream>
using namespace std;

int squareRoot(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x;
    int ans = 0;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (mid * mid <= x){
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans; // floor(sqrt(x))
}

int main() {
    int x;
    x = 95;

    int result = squareRoot(x);
    cout << "\n🔹 Integer square root of " << x << " is: " << result << endl;

    return 0;
}
