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
    string s;
    cin >> s;

    vector<array<int, 10>> nxt(n + 2);
    for(int d = 0; d < 10; d++) nxt[n + 1][d] = n + 1;
    for(int i = n; i >= 1; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i - 1] - '0'] = i;
    }

    vll d2(n + 5, 0), d1(n + 5, 0), f(n + 5, 0);

    for (int l = 1; l <= n; l++) {
        int p1 = nxt[l][2];
        if (p1 > n) continue;
        int p2 = nxt[p1 + 1][0];
        if (p2 > n) continue;
        int p3 = nxt[p2 + 1][2];
        if (p3 > n) continue;
        
        int L_l = nxt[p3 + 1][5];
        int R_bad = nxt[p3 + 1][6];
        
        int R_l = min(n, R_bad - 1);
        if (L_l <= R_l) {
            ll C = R_l - L_l + 1;
            d2[l] += C;
            d2[l + 1] -= C;
            d2[L_l + 1] -= 1;
            d2[R_l + 2] += 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        d1[i] = d1[i - 1] + d2[i];
        f[i] = f[i - 1] + d1[i];
        ll tot = 1LL * i * (n - i + 1);
        cout << tot - f[i] << (i == n ? "" : " ");
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