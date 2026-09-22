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

    set<ll> s;

    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        s.insert(x - i);
    }

    int ans = 0;
    int cur = 0;
    ll prv = 0;

    for (ll x : s) {
        if (cur > 0 && x == prv + 1) {
            ++cur;
        } else {
            cur = 1;
        }

        ans = max(ans, cur);
        prv = x;
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