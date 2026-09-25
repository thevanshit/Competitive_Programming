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
    vector<bool> isodd(n + 1);
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        isodd[v] = (i % 2 != 0);
    }
    int co = (n + 1) / 2;
    int ce = n / 2;
    for (int x = 1; x <= n; x++) {
        bool req = isodd[x];
        if (co == ce) {
            if (req) co--;
            else ce--;
        } else if (co > ce) {
            if (req) co--;
            else {
                cout << "NO\n";
                return;
            }
        } else {
            if (!req) ce--;
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}