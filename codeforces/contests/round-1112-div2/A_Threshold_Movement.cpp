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
    vi w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    if (n & 1) {
        cout << "NO\n";
        return;
    }

    int max_even = 0, min_odd = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (i & 1)  
            max_even = max(max_even, w[i]);
        else       
            min_odd = min(min_odd, w[i]);
    }

    cout << (min_odd - max_even >= 2 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}