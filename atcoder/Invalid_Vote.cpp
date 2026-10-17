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
    if(!(cin >> n >> m)) return;
    vector<string> s(n);
    for(auto &x : s) cin >> x;
    vi v(n, 0);
    for(int k = 0; k < m; k++){
        string t; cin >> t; 
        int ex = -1, d1 = -1, c1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == t){
                ex = i; 
                break;
            }
            if(sz(s[i]) == sz(t)){
                int dif = 0;
                for(int j = 0; j < sz(t); j++){
                    dif += (s[i][j] != t[j]);
                }
                if(dif == 1) {
                    d1 = i; 
                    c1++;
                }
            }
        }
        if(ex != -1){
            v[ex]++;
        }
        else if(c1 == 1){
            v[d1]++;
        }
    }
    for(auto &x : v) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}