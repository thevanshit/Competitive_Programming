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
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(ll j = 0; j < m; j++) {
        for(ll i = 0; i < n; i++) {
            if(i == n - 1 && j == m - 1) {
                cout << a[i][j];
            } else {
                cout << a[i][j] << " ";
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}