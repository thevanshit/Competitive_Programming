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
    int n;
    cin >> n;
    
    int o = 0, e = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 1 || x > 1000000) {
            cout << -1 << '\n';
            exit(0);
        }
        if (x & 1) o++;
        else e++;
    }
    
    if ((o == 1 && e == 1) || (o == 3 && e == 0)) cout << "Larpity\n";
    else cout << "Moggity\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}