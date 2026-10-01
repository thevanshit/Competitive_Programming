#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
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
    vi a(n);
    vi freq(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= n + 1) {
            freq[a[i]]++;
        }
    }
    int mex = 0;
    while (freq[mex] > 0) {
        mex++;
    }
    ll moves = 0;
    for (int i = 0; i < mex; ++i) {
        moves += 1LL * (freq[i] - 1) * i;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] > mex) {
            moves += (a[i] - (mex + 1));
        }
    }
    
    if (moves % 2 != 0) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}