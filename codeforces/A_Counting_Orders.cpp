#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

const int MOD = 1e9 + 7;

void solve() {
    int n; 
    cin >> n;
        
    vector<int> a(n);
        
    for (int i = 0; i < n; i++) 
        cin >> a[i];
        
    sort(a.begin(), a.end());
        
    vector<int> b(n);
        
    for (int i = 0; i < n; i++) 
        cin >> b[i];
        
    sort(b.begin(), b.end(), greater<>());
        
    ll res = 1;
        
    for (int i = 0; i < n; i++){
        int cnt = a.size() - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
        res = res * max(cnt - i, 0) % MOD;
    }
    cout << res << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}