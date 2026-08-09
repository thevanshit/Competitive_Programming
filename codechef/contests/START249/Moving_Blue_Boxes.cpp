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
    vi p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    struct Element {
        int val, idx;
    };
    
    vector<Element> P;
    P.pb({0, 0}); 
    
    int current_max = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] > current_max) {
            current_max = p[i];
            P.pb({p[i], i});
        }
    }
    
    int m = P.size() - 1;
    vi dp(m + 1, -1e9);
    dp[0] = 0;
    
    int ptr = 0;
    int current_max_dp = -1e9;
    
    for (int j = 1; j <= m; j++) {
        while (ptr < j && P[ptr].idx <= P[j].idx - 2) {
            current_max_dp = max(current_max_dp, dp[ptr]);
            ptr++;
        }
        
        int best = -1e9;
        
        if (current_max_dp >= 0) {
            best = max(best, current_max_dp + 1);
        }
        
        if (P[j].idx - P[j-1].idx == 1 && P[j].val - P[j-1].val == 1) {
            if (dp[j-1] >= 0) {
                best = max(best, dp[j-1] + 1);
            }
        }
        
        dp[j] = best;
    }
    
    int max_red = 0;
    for (int j = 0; j <= m; j++) {
        max_red = max(max_red, dp[j]);
    }
    
    cout << n - max_red << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}