#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    string s;
    cin >> s;
    int n = sz(s);

    ll ans = 0;

    for (int c = 0; c < n; c++) {
        int mismatches = 0;
        ans++; 
        for (int l = c - 1, r = c + 1; l >= 0 && r < n; l--, r++) {
            if (s[l] != s[r]) mismatches++;
            if (mismatches > 1) break;
            ans++;
        }
    }

    for (int c = 0; c < n - 1; c++) {
        int mismatches = (s[c] != s[c + 1]) ? 1 : 0;
        ans++; 
        for (int l = c - 1, r = c + 2; l >= 0 && r < n; l--, r++) {
            if (s[l] != s[r]) mismatches++;
            if (mismatches > 1) break;
            ans++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
