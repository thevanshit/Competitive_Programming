#include <bits/stdc++.h>
using namespace std;

bool hasOddDigit(long long x) {
    while (x > 0) {
        if ((x % 10) % 2 == 1) return true;
        x /= 10;
    }
    return false;
}

void solve() {
    long long N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0 << "\n";
        return;
    }

    vector<int> digits;
    long long temp = N;
    while (temp > 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }

    if (digits.size() == 1) {
        cout << -1 << "\n";
        return;
    }

    for (int d : digits) {
        if (d % 2 == 1) {
            cout << 1 << "\n";
            return;
        }
    }

    for (int d : digits) {
        long long x = N - d;
        if (x % 2 == 1 || hasOddDigit(x)) {
            cout << 2 << "\n";
            return;
        }
    }

    cout << 3 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
