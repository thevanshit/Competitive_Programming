#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 + y1) % 2 != (x2 + y2) % 2) {
        cout << -1 << '\n';
        return;
    }
    if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}