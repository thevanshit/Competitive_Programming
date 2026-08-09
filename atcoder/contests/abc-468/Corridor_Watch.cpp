#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int m, d;
    string s;
    cin >> m >> d >> s;

    vi diff(m + 1, 0);
    for (int i = 0; i < m; i++) {
        if (s[i] == 'G') {
            int l = max(0, i - d);
            int r = min(m - 1, i + d);
            diff[l]++;
            diff[r + 1]--;
        }
    }

    int ans = 0, cur = 0;
    for (int i = 0; i < m; i++) {
        cur += diff[i];
        if (cur == 0) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}