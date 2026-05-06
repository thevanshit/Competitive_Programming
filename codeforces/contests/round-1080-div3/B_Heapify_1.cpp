#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll core(ll x) {
    while (x % 2 == 0) x /= 2;
    return x;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n+1), pos(n+1);

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (ll val = 1; val <= n; val++) {
        if (core(pos[val]) != core(val)) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
