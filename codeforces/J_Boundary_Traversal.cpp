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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ma[i][j];
        }
    }

    if (n == 1) {
        for (int j = 0; j < m; j++) {
            cout << ma[0][j] << ' ';
        }
        cout << '\n';
        return;
    }

    if (m == 1) {
        for (int i = 0; i < n; i++) {
            cout << ma[i][0] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int j = 0; j < m; j++) {
        cout << ma[0][j] << ' ';
    }

    for (int i = 1; i < n; i++) {
        cout << ma[i][m - 1] << ' ';
    }

    for (int j = m - 2; j >= 0; j--) {
        cout << ma[n - 1][j] << ' ';
    }

    for (int i = n - 2; i >= 1; i--) {
        if (i == 1) cout << ma[i][0];
        else cout << ma[i][0] << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}