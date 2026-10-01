#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vi q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    ll ans = 1;
    for (int i = 1; i <= k; ++i) {
        ans = (ans * i) % MOD;
    }
    for (int i = 0; i < n - k; ++i) {
        ans = (ans * k) % MOD;
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}