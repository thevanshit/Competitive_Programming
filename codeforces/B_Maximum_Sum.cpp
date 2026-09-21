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
    for (int &x : a) cin >> x;

    sort(all(a));

    vector<ll> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }

    ll ans = 0;

    for (int m = 0; m <= k; m++) {
        int l = 2 * m;
        int r = n - (k - m);

        ans = max(ans, p[r] - p[l]);
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