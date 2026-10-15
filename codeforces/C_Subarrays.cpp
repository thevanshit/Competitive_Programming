#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector <int>;
using vll = vector <long long>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

void solve() {
    int n, k;
    cin >> n >> k;
    
    vi p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        p[i] = (p[i - 1] + x) % k;
    }
    
    vi cnt(k, 0);
    ll ans = 0;
    
    for (int r = k + 1; r <= n; r++) {
        cnt[p[r - k - 1]]++;
        ans += cnt[p[r]];
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