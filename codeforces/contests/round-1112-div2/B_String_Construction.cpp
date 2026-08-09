#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == n - 1) {
        cout << "-1\n";
        return;
    }

    int runs = n - k;         
    int x = k / 2;           
    int y = k - x;       

    string s;
    s.append(1 + x, '0');

    if (runs >= 2) s.append(1 + y, '1');

    for (int i = 3; i <= runs; ++i) s += (i & 1) ? '0' : '1';

    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}