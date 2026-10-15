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
    int n, c;
    cin >> n >> c;

    int ans = 0;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    bool nR = false;
        
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) nR = true;
        ans += a[i];
        ans -= b[i];
    }

    if (nR) {
        nR = false;
        ans += c;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            if (a[i] < b[i]) {
                nR = true;
            }
        }
    }
    if (nR) cout << "-1\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}