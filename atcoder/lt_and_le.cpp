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

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < q; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        adj[u].pb({v, t}); 
    }
    int ti = 0, scnt = 0;
    vi dfn(n + 1, -1), low(n + 1, -1), scc(n + 1, -1);
    vi st;
    vector<bool> ins(n + 1, false);
    auto dfs = [&](auto& self, int u) -> void {
        dfn[u] = low[u] = ti++;
        st.pb(u);
        ins[u] = true;
        for (auto [v, w] : adj[u]) {
            if (dfn[v] == -1) {
                self(self, v);
                low[u] = min(low[u], low[v]);
            } 
            else if (ins[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            while (true) {
                int v = st.back();
                st.pop_back();
                ins[v] = false;
                scc[v] = scnt;
                if (u == v) break;
            }
            scnt++;
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == -1) dfs(dfs, i);
    }
    vector<vector<pii>> dag(scnt);
    for (int u = 1; u <= n; ++u) {
        for (auto [v, w] : adj[u]) {
            if (scc[u] == scc[v]) {
                if (w == 1) {
                    cout << "No\n";
                    return;
                }
            } else {
                dag[scc[u]].pb({scc[v], w});
            }
        }
    }
    vi dp(scnt, 1);
    for (int c = scnt - 1; c >= 0; --c) {
        for (auto [v_scc, w] : dag[c]) {
            dp[v_scc] = max(dp[v_scc], dp[c] + w);
        }
    }
    for (int c = 0; c < scnt; ++c) {
        if (dp[c] > n) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        cout << dp[scc[i]] << (i == n ? "" : " ");
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}