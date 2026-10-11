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
    int m = 1;
    while (m <= n) m <<= 1;
    int len = 2 * m - 1;
    cout << len << '\n';
    for (int i = 1; i <= len; i++) {
        if (i & 1) cout << 0 << (i == len ? "" : " ");
        else cout << ((i & -i) / 2) << (i == len ? "" : " ");
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}