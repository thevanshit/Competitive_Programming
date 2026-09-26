#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vi nx(n), pr(n);
    for (int i = 0; i < n; ++i) {
        nx[i] = i + 1;
        pr[i] = i - 1;
    }
    nx[n - 1] = -1;
    int l = k - 1;
    int r = n - k;

    int m = n;
    ll ans = 0;

    while (m >= k) {
        if (a[l] >= a[r]) {
            int p = l;
            int nl = nx[p];
            int nr = (l < r ? r : pr[r]);

            int x = pr[p], y = nx[p];
            if (x != -1) nx[x] = y;
            if (y != -1) pr[y] = x;

            l = nl;
            r = nr;
            ans += a[p];
        } else {
            int p = r;
            int nr = pr[p];
            int nl = (r > l ? l : nx[l]);

            int x = pr[p], y = nx[p];
            if (x != -1) nx[x] = y;
            if (y != -1) pr[y] = x;

            l = nl;
            r = nr;
            ans += a[p];
        }
        --m;
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