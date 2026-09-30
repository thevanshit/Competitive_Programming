#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

bool isfactor(ll a, ll b){
    if(b % a == 0) return true;
    return false;
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> fac;
    for(ll i = 1; i <= n; i++){
        if(isfactor(i, n)){
            fac.pb(i);
        }
    }
    for(ll &f : fac){
        if(f == n) cout << f;
        else cout << f << " ";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}