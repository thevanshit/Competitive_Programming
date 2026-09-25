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
    vi cnt(105, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    vi ans;
    while (true) {
        bool add = false;
        for (int i = 100; i >= 1; --i) {
            if (cnt[i] > 0) {
                ans.pb(i);
                cnt[i]--;
                add = true;
            }
        }
        if (!add) break;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}