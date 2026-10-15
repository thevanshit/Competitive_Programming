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

    vector <int> cnt(n, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(ma[i][j] == 1) cnt[i]++;
        }
    }

    if (*max_element(all(cnt)) == 0){
        cout << -1 << '\n';
        return;
    }
    else{
        int mx = *max_element(all(cnt));
        for(int i = 0; i < n; i++) {
            if(cnt[i] == mx) {
                cout << i << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}