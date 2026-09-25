#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

const int mx = 300005;
int sf[mx];

void precompute() {
    for (int i = 1; i < mx; i++) sf[i] = i;
    for (int i = 2; i * i < mx; i++) {
        if (sf[i] == i) {
            for (int j = i * i; j < mx; j += i) {
                if (sf[j] == j) sf[j] = i;
            }
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int &v : a) cin >> v;

    vi pr;
    int te = x;
    while (te > 1) {
        int p = sf[te];
        pr.pb(p);
        while (te % p == 0) te /= p;
    }

    ll ans = 0;
    for (int p : pr) {
        ll cur = 0;
        for (int v : a) {
            if (v % p == 0) {
                cur += v;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t = 1;
    cin >> t;
    while (t--) solve();
}