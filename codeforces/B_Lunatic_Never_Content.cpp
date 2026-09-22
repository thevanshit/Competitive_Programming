#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for(int &x : a) cin >> x;

    ll g = 0;

    for(int i = 0; i < n / 2; i++){
        g = gcd(g, llabs(1LL * a[i] - a[n - 1 - i]));
    }

    cout << g << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}