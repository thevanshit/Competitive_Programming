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
    int n; cin >> n;
    string s; cin >> s;
    int c = count(all(s), '1');
    
    if (c <= 1) cout << 0 << '\n';
    else if (c == 2) cout << 1 << '\n';
    else cout << s.rfind('1') - s.find('1') << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}