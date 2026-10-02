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

    for(int i = 1; i <= n; i += 2){
        cout << i << " ";
    }
    vi ev;
    for(int i = 2; i <= n; i += 2){
        ev.pb(i);
    }
    reverse(all(ev));
    for(int i = 0; i < sz(ev); i++){
        if(i == sz(ev) - 1) cout << ev[i];
        else cout << ev[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}