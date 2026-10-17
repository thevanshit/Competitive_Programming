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
    ll an = 0;
    for(int l = 3; l <= 20; l++){
        bool ok = false;
        for(ll a = 1; ; a++){
            __int128_t p = 1;
            bool po = 1; 
            for(int i = 0; i < l; i++){
                p *= (a + i);
                if(p > n) {po = 0; break;}
            }
            if(!po) break;
            ok = true;
            ll lo = 1, hi = (l == 3 ? 1000000000LL : 1000000LL), d = 0;
            while(lo <= hi){
                ll m = lo + (hi - lo) / 2;
                __int128_t tp = 1;
                bool tpo = true;

                for (int i = 0; i < l; ++i) {
                    tp *= (a + i * (__int128_t)m);
                    if (tp > n) { tpo = 0; break; }
                }
                
                if (tpo) {
                    d = m;        
                    lo = m + 1; 
                } else {
                    hi = m - 1; 
                }
            }
            an += d;
        }
        if(!ok) break;
    }
    cout << an << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}