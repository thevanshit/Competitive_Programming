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

    vi c(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    int ans = 1e9;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(i <= k + 1 && j >= n - k && j - i <= 2 * k + 1) {
                ans = min(ans, c[i] + c[j]);
            }
        }
    }
    if(ans == 1e9) {
        cout << -1 << "\n";
    } 
    else {
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}