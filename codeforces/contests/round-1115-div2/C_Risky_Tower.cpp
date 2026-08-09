#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<ll> a((size_t)n * m);
    vector<ll> vals;
    vals.reserve((size_t)n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[(size_t)i * m + j];
            vals.pb(a[(size_t)i * m + j]);
        }
        sort(a.begin() + (size_t)i * m, a.begin() + (size_t)i * m + m, greater<ll>());
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    int M = sz(vals);

    vi bitCnt(M + 1, 0);
    vector<ll> bitSum(M + 1, 0);

    ll totalCnt = 0, totalSum = 0;
    int ans = m; 

    auto add = [&](ll x) {
        int idx = int(lower_bound(all(vals), x) - vals.begin()) + 1;
        for (int i = idx; i <= M; i += i & -i) {
            ++bitCnt[i];
            bitSum[i] += x;
        }
        ++totalCnt;
        totalSum += x;
    };

    int hi = 0;
    while ((1LL << (hi + 1)) <= M) ++hi;

    for (int k = n; k >= 1; --k) {
        for (int j = 0; j < m; ++j) add(a[(size_t)(k - 1) * m + j]);

        ll X = v[k];
        if (totalSum < X) continue; 

        ll T = totalSum - X;

        int idx = 0;
        ll accSum = 0, accCnt = 0;
        for (int b = hi; b >= 0; --b) {
            int nxt = idx + (1 << b);
            if (nxt <= M && accSum + bitSum[nxt] <= T) {
                idx = nxt;
                accSum += bitSum[nxt];
                accCnt += bitCnt[nxt];
            }
        }

        ll kSkip;
        if (idx == M) {
            kSkip = totalCnt; 
        } else {
            ll vNext = vals[idx];
            kSkip = accCnt + (T - accSum) / vNext;
        }
        ll c = totalCnt - kSkip;
        ans = min(ans, (int)c);
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