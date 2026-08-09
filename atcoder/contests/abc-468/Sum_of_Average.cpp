#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll modpow(ll a, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> Q(n + 1, 0);
    ll prefix = 0; 
    for (int i = 1; i <= n; i++) {
        prefix = (prefix + a[i - 1]) % MOD;
        Q[i] = (Q[i - 1] + prefix) % MOD;
    }

    vector<ll> inv(n + 1);
    for (int i = 1; i <= n; i++) {
        inv[i] = modpow(i, MOD - 2);
    }

    ll ans = 0;
    ll QN = Q[n];
    for (int len = 1; len <= n; len++) {
        ll sum_len = (QN - Q[len - 1] - Q[n - len]) % MOD;
        if (sum_len < 0) sum_len += MOD;
        ans = (ans + sum_len * inv[len]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
