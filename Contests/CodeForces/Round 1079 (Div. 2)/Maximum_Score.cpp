#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    vector<long long> a(n), b(n);

    for(long long i = 0; i < n; i++) cin >> a[i];
    for(long long i = 0; i < n; i++) cin >> b[i];

    long long sumA = 0;
    long long min_diff = LLONG_MAX;

    for(long long i = 0; i < n; i++) {
        sumA += a[i];
        min_diff = min(min_diff, a[i] - b[i]);
    }

    long long result = sumA - min_diff;

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
