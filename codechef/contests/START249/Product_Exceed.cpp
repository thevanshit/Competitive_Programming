#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int X, Y, P;
    cin >> X >> Y >> P;

    if (X * Y >= P) {
        cout << 0 << '\n';
        return;
    }

    int ans = INT_MAX;
    int max_i = (P + Y - 1) / Y - X;

    for (int i = 0; i <= max_i; i++) {
        int nx = X + i;
        int need_ny = (P + nx - 1) / nx; 
        int j = max(0, need_ny - Y);
        ans = min(ans, i + j);
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
