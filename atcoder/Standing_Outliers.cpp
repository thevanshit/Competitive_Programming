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
    ll d;
    if (!(cin >> n >> d)) return;
    
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    vi ans;
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (i != j && abs(x[i] - x[j]) < d) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.pb(i + 1);
        }
    }
    
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << (i + 1 == sz(ans) ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}