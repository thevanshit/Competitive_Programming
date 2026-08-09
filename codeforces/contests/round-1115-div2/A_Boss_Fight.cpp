#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<long long, int> freq;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        total += x;
        freq[x]++;
    }

    int maxFreq = 0;
    long long maxVal = 0;
    for (auto [val, cnt] : freq) {
        if (cnt > maxFreq) {
            maxFreq = cnt;
            maxVal = val;
        }
    }

    if (2LL * maxFreq <= n + 1) {
        cout << total << '\n';
    } else {
        cout << total + maxVal * (n - 2LL * maxFreq + 2) << '\n';
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}