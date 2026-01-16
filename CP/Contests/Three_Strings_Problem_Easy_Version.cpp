#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    string A, B, C;
    cin >> A >> B >> C;

    long long b0 = 0, b1 = 0, c0 = 0, c1 = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] == '0') {
            if (B[i] == '1') b0++;
            if (C[i] == '1') c0++;
        } else {
            if (B[i] == '1') b1++;
            if (C[i] == '1') c1++;
        }
    }

    long long cost1 = llabs(b0 - c0) + llabs(b1 - c1);
    long long cost2 = llabs(b0 - c1) + llabs(b1 - c0) + N;

    cout << min(cost1, cost2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
