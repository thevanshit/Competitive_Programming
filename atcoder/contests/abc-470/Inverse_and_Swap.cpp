#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, q;
    cin >> n >> q;

    vi p(n + 1), inv(n + 1); 
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        inv[p[i]] = i;
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            int a = p[x], b = p[y];
            swap(p[x], p[y]);
            inv[a] = y; 
            inv[b] = x; 
        } else {
            swap(p, inv);
        }
    }

    for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? '\n' : ' ');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}