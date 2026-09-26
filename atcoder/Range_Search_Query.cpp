#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int q;
    if (!(cin >> q)) return;

    string s, t;
    cin >> s >> t;

    int n = sz(s), m = sz(t);

    vi p;
    for(int i = 0; i + m <= n; i++){
        bool match = true;
        for(int j = 0; j < m; j++){
            if(s[i + j] != t[j]){
                match = false;
                break;
            }
        }
        if(match) p.pb(i);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;

        if(r - l + 1 < m){
            cout << "No\n";
            continue;
        }

        auto it = lower_bound(all(p), l);
        if (it != p.end() && *it <= r - m + 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}