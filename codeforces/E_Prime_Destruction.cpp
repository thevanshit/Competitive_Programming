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

    vi a(n);
    for (int& x : a) {
        cin >> x;
    }

    vi spf(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;

            if (1LL * i * i <= n) {
                for (ll j = 1LL * i * i; j <= n; j += i) {
                    if (spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    vector<ll> dp(n + 1);

    for (int x = k + 1; x <= n; ++x) {
        ll best = LLONG_MAX;
        int y = x;

        while (y > 1) {
            int p = spf[y];

            best = min(best, 1LL + 1LL * p * dp[x / p]);

            while (y % p == 0) {
                y /= p;
            }
        }

        dp[x] = best;
    }

    ll ans = 0;
    for (int x : a) {
        ans += dp[x];
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