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

    vi cnt(n + 1, 0);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        mx = max(mx, ++cnt[c]);
    }

    cout << n - mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}