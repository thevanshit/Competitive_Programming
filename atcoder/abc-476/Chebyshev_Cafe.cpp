#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n;
    ll m;

    cin >> n >> m;

    vector<ll> a(n), b(n);

    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;

    vector<ll> c(2 * n - 1);
    vector<ll> d(2 * n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll w = (a[i] * b[j]) % m;

            c[i + j] += w;
            d[i - j + n - 1] += w;
        }
    }

    vector<ll> gc(2 * n - 1), gd(2 * n - 1);

    auto build = [](const vector<ll>& w, vector<ll>& res) {
        int sz = w.size();

        vector<ll> sw(sz + 1), sp(sz + 1);

        for (int i = 0; i < sz; i++) {
            sw[i + 1] = sw[i] + w[i];
            sp[i + 1] = sp[i] + 1LL * i * w[i];
        }

        for (int x = 0; x < sz; x++) {
            ll left_w = sw[x];
            ll left_p = sp[x];

            ll right_w = sw[sz] - sw[x + 1];
            ll right_p = sp[sz] - sp[x + 1];

            res[x] = 1LL * x * left_w - left_p
                   + right_p - 1LL * x * right_w;
        }
    };

    build(c, gc);
    build(d, gd);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll x = gc[i + j];
            ll y = gd[i - j + n - 1];

            ll f = (x + y) / 2;
            ll value = f + 1LL * i * n + j;

            ans ^= value;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}