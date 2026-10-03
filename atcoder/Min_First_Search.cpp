#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

const int MOD = 998244353;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vi q(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
    }
    vi st;
    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && q[st.back()] < q[i]) {
            st.pop_back();
        }
        if (i > 1) {
            int l = st.empty() ? 1 : st.back();
            ans = (ans * (i - l)) % MOD;
        }
        st.pb(i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}