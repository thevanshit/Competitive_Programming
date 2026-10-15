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
    int n, m;
    cin >> n >> m;
    
    vi d(n + 1, 0);
    vi p(n + 1);
    iota(all(p), 0);
    int c = n;
    
    auto find = [&](auto& self, int i) -> int {
        return p[i] == i ? i : p[i] = self(self, p[i]);
    };
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++; d[v]++;
        int ru = find(find, u), rv = find(find, v);
        if (ru != rv) {
            p[ru] = rv;
            c--;
        }
    }
    
    int mxd = 0;
    bool z = false;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) z = true;
        mxd = max(mxd, d[i]);
    }
    
    if (z) cout << "Brain Melt\n";
    else if (c > 1) cout << "Many\n";
    else if (m == n - 1 && mxd == n - 1) cout << "2\n";
    else cout << "Many\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}