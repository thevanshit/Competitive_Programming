#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, m;
    ll k, x, y;

    cin >> n >> m >> k;
    cin >> x >> y;

    vector<ll> a(n), b(m);

    for (ll& v : a) cin >> v;
    for (ll& v : b) cin >> v;

    sort(all(a));
    sort(all(b));

    vector<ll> pa(n + 1), pb(m + 1), pk(m + 1);

    for (int i = 0; i < n; i++) {
        pa[i + 1] = pa[i] + a[i];
    }

    for (int i = 0; i < m; i++) {
        pb[i + 1] = pb[i] + b[i];
        pk[i + 1] = pk[i] + (b[i] + k - 1) / k;
    }

    ll tot = x + y * k;
    int ans = 0;

    for (int j = 0; j <= m; j++) {
        if (pk[j] > y || pb[j] > tot) continue;

        ll rem = tot - pb[j];
        int d = upper_bound(all(pa), rem) - pa.begin() - 1;

        ans = max(ans, j + d);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}