#include <bits/stdc++.h>
using namespace std;

void solve() {

    long long n, x, y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    for(long long i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> transfers(n);
    long long totalTransfers = 0;
    for(long long i = 0; i < n; i++) {
        transfers[i] = a[i] / x;
        totalTransfers += transfers[i];
    }

    long long result = 0;
    for(long long i = 0; i < n; i++) {
        long long usableTransfers = totalTransfers - transfers[i];
        long long candidate = a[i] + usableTransfers * y;
        result = max(result, candidate);
    }

    cout << result << '\n';
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
