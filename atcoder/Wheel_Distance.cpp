#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> d = b;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({d[i], i});
    }

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > d[u]) continue;
        int nxt = (u + 1) % n;
        if (d[nxt] > dist + a[u]) {
            d[nxt] = dist + a[u];
            pq.push({d[nxt], nxt});
        }
        int prv = (u - 1 + n) % n;
        if (d[prv] > dist + a[prv]) {
            d[prv] = dist + a[prv];
            pq.push({d[prv], prv});
        }
    }

    while (q--) {
        int s, t;
        cin >> s >> t;
        --s; --t;
        if (t == n) {
            cout << d[s] << "\n";
        } else {
            ll c1 = pref[t] - pref[s];
            ll c2 = pref[n] - c1;
            ll ans = min({c1, c2, d[s] + d[t]});
            cout << ans << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}