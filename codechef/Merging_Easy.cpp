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

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vi p(n);
    for (int &x : p) cin >> x;

    vi s;
    int mx = 0, l = 0;
    for (int x : p) {
        if (x > mx) {
            if (l > 0) s.pb(l);
            l = 1;
            mx = x;
        } else {
            l++;
        }
    }
    if (l > 0) s.pb(l);

    vi dp = {1};
    int cs = 0;
    for (int x : s) {
        vi ndp(cs + x + 1, 0);
        for (int i = 0; i <= cs; i++) {
            ndp[i] = dp[i];
        }
        for (int i = 0; i <= cs; i++) {
            ndp[i + x] += dp[i];
            if (ndp[i + x] >= MOD) ndp[i + x] -= MOD;
        }
        dp = move(ndp);
        cs += x;
    }

    for (int i = 0; i <= n; i++) {
        cout << dp[i] << (i == n ? "" : " ");
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