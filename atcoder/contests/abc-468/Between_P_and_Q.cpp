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
    vi p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];

    vi perm(n);
    iota(all(perm), 1);

    int pos_p = -1, pos_q = -1;
    int idx = 0;
    do {
        if (perm == p) pos_p = idx;
        if (perm == q) pos_q = idx;
        idx++;
    } while (next_permutation(all(perm)));

    if (pos_p < pos_q) {
        cout << pos_q - pos_p - 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}