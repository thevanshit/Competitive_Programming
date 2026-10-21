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
    ll n; cin >> n;
    ll l = 1, r = 2 * 1e6, an = 1;
    while(l <= r) {
        ll m = l + (r - l) / 2;
        unsigned __int128 s = (unsigned __int128)m * m * m + 5 * (unsigned __int128)m;
        s /= 6;
        if(s <= n) {
            an = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    cout << an << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}