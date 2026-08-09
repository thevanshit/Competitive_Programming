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
    for (int i = 1; i <= n; i++) cin >> a[i];
    vi dp(n + 2, -1); 
    int best = 0;    
    for (int i = 1; i <= n; i++) {
        int v = a[i];
        if (v == 1) {
            dp[1] = max(dp[1], best + 1); 
        } else if (dp[v - 1] != -1) {
            dp[v] = max(dp[v], dp[v - 1] + 1); 
        }
        best = max(best, dp[v]);
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
