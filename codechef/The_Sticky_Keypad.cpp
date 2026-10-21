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
    ll n; char d;
    cin >> n >> d;
    string s = to_string(n);
    for(int i = 0; i < sz(s); i++){
        if(s[i] == d){
            ll p = 1;
            for(int j = 0; j < sz(s) - i - 1; j++) p *= 10;
            n = (n / p + 1) * p;
            s = to_string(n);
            i = -1;
        }
    }
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}