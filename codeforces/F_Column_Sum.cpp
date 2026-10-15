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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ma(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ma[i][j];
        }
    }

    vector<int> s(m, 0);

    for(int j = 0; j < m; j++) {
        int su = 0;
        for(int i = 0; i < n; i++) {
            su += ma[i][j];
        }
        s[j] = su;
    }

    for(int j = 0; j < m; j++) {
        cout << s[j] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}