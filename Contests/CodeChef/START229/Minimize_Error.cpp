#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, Q;
    cin >> N >> Q;

    long long L = (N + Q) / (Q + 1);
    cout << L / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
}