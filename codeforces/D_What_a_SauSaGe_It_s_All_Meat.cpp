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
    cin >> n >> q;

    vi a(n);
    int ans = 0;
    auto good = [](int x) {
        return __builtin_parity((unsigned)x) == 0;
    };
    for (int &x : a) {
        cin >> x;
        ans += good(x);
    }
    cout << ans;
    while (q--) {
        int p, x;
        cin >> p >> x;
        --p;

        ans -= good(a[p]);
        a[p] = x;
        ans += good(a[p]);

        cout << ' ' << ans;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}