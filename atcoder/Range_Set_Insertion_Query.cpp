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
    int n, q;
    if(!(cin >> n >> q)) return;

    vector<vector<pii>> iv(q + 1);
    for(int i = 0; i < q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        iv[x].pb({l, r});
    }
    vi d(n + 2, 0);
    for(int x = 1; x <= q; x++){
        if(iv[x].empty()) continue;
        sort(all(iv[x]));
        int cl = iv[x][0].ff, cr = iv[x][0].ss;
        for(int i = 1; i < sz(iv[x]); i++){
            if(iv[x][i].ff <= cr){
                cr = max(cr, iv[x][i].ss);
            } 
            else {
                d[cl]++; d[cr + 1]--;
                cl = iv[x][i].ff;
                cr = iv[x][i].ss;
            }
        }
        d[cl]++; d[cr + 1]--;
    }
    int c = 0;
    for(int i = 1; i <= n; i++){
        c += d[i];
        cout << c << (i == n ? "" : " ");
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}