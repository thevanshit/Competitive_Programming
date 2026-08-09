#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    if (Z <= Y) {
        cout << -1 << '\n';
        return;
    }

    int diff = Z - Y;
    int months = (X + diff - 1) / diff; 
    cout << months << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}