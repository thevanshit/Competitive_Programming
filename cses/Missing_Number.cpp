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
    ll c;
    for(ll i = 1; i <= n; i++){
        ll x; cin >> x;
        if(x != i) c = i;
    }
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}