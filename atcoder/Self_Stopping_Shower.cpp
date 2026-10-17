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
    ll n, k, t;
    cin >> n >> k >> t;

    vll a(n);
    for(ll &x : a) cin >> x;
    sort(all(a));

    ll an = 0, c = 0; 

    for(ll &x : a){
        if(c >= t) break;
        ll tg = min(t, x);
        if(tg > c){
            ll re = (tg - c + k - 1) / k;
            an += re;
            c += re * k;
        }
        c = max(c, x + k);
    }
    if(c < t){
        ll re = (t - c + k - 1) / k;
        an += re;
    }
    cout << an << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}