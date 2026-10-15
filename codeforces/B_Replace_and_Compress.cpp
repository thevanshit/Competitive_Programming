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
    string s;
    cin >> s;
    
    int n = sz(s);
    bool p2 = false, m2 = false;
    
    for (int i = 1; i < n - 1; i++) {
        if (s[i-1] == s[i] && s[i] == s[i+1]) p2 = true;
        if (s[i-1] != s[i] && s[i] != s[i+1]) m2 = true;
    }
    
    cout << 1 + p2 + m2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}