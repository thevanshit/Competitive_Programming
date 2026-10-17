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
    int n;
    cin >> n;
    
    int mxc = -1;
    int mnc = 2e9;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > mxc) mxc = x;
        if (x < mnc) mnc = x;
    }
    if (n == 1) {
        cout << mxc << '\n';
        return;
    }
    ll ans = mxc;
    ll M = mxc;
    for (int d = 29; d >= 0; d--) {
        if ((M >> d) & 1) {
            ll w = (M & ~((1LL << (d + 1)) - 1)) | ((1LL << d) - 1);
            if (mnc <= w) {
                ans = max(ans, M | w);
            }
        }
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