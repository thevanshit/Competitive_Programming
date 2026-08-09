#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

bool check(int m, int n,
           const vector<int>& L, const vector<int>& R,
           const vector<int>& U, const vector<int>& V) {
    int last = 0;  
    for (int pos = 1; pos <= m; pos++) {
        bool found = false;
        for (int i = last + 1; i <= n; i++) {
            bool left_ok = (pos < L[i] || pos > R[i]);
            bool right_ok = (pos <= m - V[i] || pos >= m - U[i] + 2);
            if (left_ok && right_ok) {
                last = i;
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> L(n + 1), R(n + 1), U(n + 1), V(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i] >> U[i] >> V[i];
    }

    int ans = 0;
    for (int m = n; m >= 1; m--) {
        if (check(m, n, L, R, U, V)) {
            ans = m;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
