#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

void solve() {
    int n, v;
    if (!(cin >> n >> v)) return; 
    vll w(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    ll mxc = 0;
    for (int i = 1; i <= n - 2; ++i) {
        if (i + (i + 1) + (i + 2) > v) break; 
        for (int j = i + 1; j <= n - 1; ++j) {
            if (i + j + (j + 1) > v) break; 
            for (int k = j + 1; k <= n; ++k) {
                if (i + j + k > v) break; 
                mxc = max(mxc, w[i] + w[j] + w[k]);
            }
        }
    }
    cout << mxc << '\n';
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}