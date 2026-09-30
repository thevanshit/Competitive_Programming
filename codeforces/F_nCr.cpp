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

ll fact(ll n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n * fact(n - 1);
}

void solve() {
    ll n, r;
    cin >> n >> r;

    if(r == 0 || r == n) {
        cout << 1 << "\n";
        return;
    }
    ll ncr = fact(n) / (fact(r) * fact(n - r));
    cout << ncr << "\n";    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}