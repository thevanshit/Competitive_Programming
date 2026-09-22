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
    string s;
    cin >> n >> s;

    if(s[0] == '1'){
        cout << count(all(s), '0') << '\n';
        return;
    }

    int p = s.find('1');

    if(p == string::npos){
        cout << 0 << '\n';
        return;
    }

    int ans = count(all(s), '1');
    int o = 0;
    int z = count(s.begin() + p, s.end(), '0');

    ans = min(ans, z);

    for (int i = p; i < n; ++i) {
        if (s[i] == '1') {
            ++o;
        } else {
            --z;
        }

        ans = min(ans, o + z);
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