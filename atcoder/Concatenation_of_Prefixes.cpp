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
    ll n, q;
    cin >> n >> q;

    vll a(n + 1, 0), s(n + 1, 0), ss(n + 1, 0), t(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        ss[i] = ss[i - 1] + s[i];
        t[i] = t[i - 1] + i;
    }
    auto f = [&](ll x) -> ll{
        if(x == 0) return 0;
        int k = prev(upper_bound(all(t), x)) - t.begin();
        return ss[k] + s[x - t[k]];
    };
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}