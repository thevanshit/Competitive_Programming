#include <bits/stdc++.h>
using namespace std;

long long digitSum(long long n) {
    long long s = 0;
    while(n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve() {
    long long x;
    cin >> x;

    int result = 0;
    for(long long y = x; y <= x + 90; y++) {
        if(y - digitSum(y) == x) {
            result++;
        }
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
