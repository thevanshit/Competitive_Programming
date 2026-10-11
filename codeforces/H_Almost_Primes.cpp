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

    vector<int> divcnt(n + 1, 0);

    for (int d = 1; d <= n; d++) {
        for (int m = d; m <= n; m += d) {
            divcnt[m]++;
        }
    }
    bool first = true;
    for (int i = 1; i <= n; i++) {
        if (divcnt[i] <= 4) {
            if (!first) cout << ' ';
            cout << i;
            first = false;
        }
    }

    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
