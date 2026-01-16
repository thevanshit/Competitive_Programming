#include <iostream>
using namespace std;

int squareRoot(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x;
    int ans = 0;

    while (left <= right) {
        // Avoid overflow by using long long
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        cout << "Checking mid = " << mid << ", square = " << square << endl;

        if (square == x) {
            return mid; // Perfect square!
        }
        else if (square < x) {
            ans = mid;      // mid might be our floor value
            left = mid + 1;
        }
        else {
            right = mid - 1; // square too large, reduce range
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
