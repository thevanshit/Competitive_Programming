#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for (int &x : a) cin >> x;

    int minEle = a[0];
    int pos = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] < minEle) {
            minEle = a[i];
            pos = i;
        }
    }

    cout << minEle << " " << pos + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}