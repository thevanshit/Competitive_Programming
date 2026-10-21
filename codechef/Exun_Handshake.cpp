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
    int n; ll m;
    cin >> n >> m;
    vi a(n);
    for(int &x : a) cin >> x;
    sort(all(a));
    ll p = 0; int c = 0;
    for(int x : a){
        if((p + x) * (p + x - 1) / 2 <= m){
            p += x;
            c++;
        }
        else break;
    }
    cout << c << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}