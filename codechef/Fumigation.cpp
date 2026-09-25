#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 2e18;
    for (ll z = 1; z <= n; ++z) {
        if (a + b + c * z >= ans) break;
        if (z == 1) {
            ans = min(ans, a + b * n + c);
        } 
        else {
            ll y1 = (n + z - 1) / z;
            ll y2 = y1 + (n - y1) % (z - 1);
            ll y3 = max(y1, n - z + 1);
            auto get_x = [&](ll y) {
                return max(1LL, (n - y + z - 2) / (z - 1));
            };
            ans = min({ans, a * get_x(y1) + b * y1 + c * z, a * get_x(y2) + b * y2 + c * z, a * get_x(y3) + b * y3 + c * z});
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