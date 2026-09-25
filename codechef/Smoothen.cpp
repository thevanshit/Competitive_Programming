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
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int pf = -1, pl = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i + 1]) {
            if (pf == -1) pf = i;
            pl = i;
        }
    }
    if (pf == -1) {
        cout << -1 << '\n';
        return;
    }
    auto check = [&](ll X) {
        int k = 1;
        int L = 1, R = pf + 1;
        while (L <= R) {
            int m = L + (R - L) / 2;
            ll val = (m == 1) ? -1e18 : a[m - 1];
            if (val <= X) {
                k = m;
                L = m + 1;
            } else {
                R = m - 1;
            }
        }

        ll s = 0;
        int jf = n + 1;
        for (int j = k; j <= n; ++j) {
            s += a[j] - X;
            if (s < 0) {
                jf = j;
                break;
            }
        }

        if (jf == n + 1) return true;

        ll mxa = -1;
        int st = max(pl, k);
        for (int R = st; R <= jf - 1; ++R) {
            mxa = max(mxa, (ll)a[R + 1]);
        }
        
        return mxa >= X;
    };
    ll l = 1, h = 1e9, ans = 1;
    while (l <= h) {
        ll m = l + (h - l) / 2;
        if (check(m)) {
            ans = m;
            l = m + 1;
        } else {
            h = m - 1;
        }
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