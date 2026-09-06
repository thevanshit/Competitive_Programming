// How do Red Coder solve the problem "Type Code Faster" from the book "Competitive Programming 4".
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

constexpr int lsOne(int S) { return S & -S; }

int N;
array<double, 20> x, y;
array<array<double, 20>, 20> dist;
array<double, 1 << 16> memo;

double dp(int mask) {
    double &ans = memo[mask];
    if (ans > -0.5) return ans;
    if (mask == 0) return 0;
    ans = 1e9;
    int p1 = countr_zero(static_cast<unsigned>(lsOne(mask)));
    int m = mask ^ lsOne(mask);
    while (m) {
        int p2 = countr_zero(static_cast<unsigned>(lsOne(m)));
        ans = min(ans, dist[p1][p2] + dp(mask ^ lsOne(mask) ^ lsOne(m)));
        m -= lsOne(m);
    }
    return ans;
}

void solve() {
    for (int i = 0; i < 2 * N; ++i) {
        string name;
        cin >> name >> x[i] >> y[i];
    }
    for (int i = 0; i < 2 * N - 1; ++i)
        for (int j = i + 1; j < 2 * N; ++j)
            dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
    ranges::fill(memo, -1.0);
    cout << fixed << setprecision(2) << dp((1 << (2 * N)) - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int caseNo = 0;
    while (cin >> N && N) {
        cout << "Case " << ++caseNo << ": ";
        solve();
    }
}