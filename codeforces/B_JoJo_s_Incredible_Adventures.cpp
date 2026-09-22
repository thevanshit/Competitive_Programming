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

    if(count(all(s), '1') == n){
        cout << 1LL * n * n << "\n";
        return;
    }

    int best = 0;
    int cur = 0;

    for(int i = 0; i < 2 * n; i++){
        if(s[i % n] == '1'){
            best = max(best, ++cur);
        } else {
            cur = 0;
        }
    }

    int x = (best + 1) / 2;
    int y = best + 1 - x;

    cout << 1LL * x * y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}