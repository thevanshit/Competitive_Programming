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
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int st = 0; st < 100; st++) {
            int nxt = 0;
            while (x > 0) {
                int d = x % 10;
                nxt += d * d;
                x /= 10;
            }
            x = nxt;
        }
        cnt[x]++;
    }
    
    ll ans = 0;
    for (auto const& [val, count] : cnt) {
        ans += 1LL * count * (count - 1) / 2;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}