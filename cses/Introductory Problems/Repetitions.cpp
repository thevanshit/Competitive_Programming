#include <bits/stdc++.h>
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
    int max_run = 1, cur_run = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cur_run++;
        } else {
            cur_run = 1;
        }
        max_run = max(max_run, cur_run);
    }

    cout << max_run << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
