#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<bool> occ(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        occ[a] = true;
    }
    
    vi ans;
    for (int i = 1; i <= n; ++i) {
        if (!occ[i]) {
            ans.pb(i);
            if (sz(ans) == k) break;
        }
    }
    
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << (i == k - 1 ? "" : " ");
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