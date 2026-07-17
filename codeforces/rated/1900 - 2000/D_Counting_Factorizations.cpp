#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second

const int MOD = 1'000'000'007;
const ll LINF = 1'000'000'000'000'000'000LL;
const ld PI = acos(-1.0);

ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1; a %= m;
    while (b) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; }
    return res;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

void solve() {
    const ll MOD2 = 998244353;

    int n; cin >> n;
    vll a(2 * n);
    for (auto &x : a) cin >> x;
    sort(all(a));

    vector<pll> comp;
    for (auto x : a) {
        if (comp.empty() || comp.back().fi != x)
            comp.pb({x, 1});
        else
            comp.back().se++;
    }

    int lim = 2 * n + 5;
    vll fact(lim + 1), inv_fact(lim + 1);
    fact[0] = 1;
    for (int i = 1; i <= lim; ++i) fact[i] = fact[i - 1] * i % MOD2;
    inv_fact[lim] = mod_pow(fact[lim], MOD2 - 2, MOD2);
    for (int i = lim; i >= 1; --i) inv_fact[i - 1] = inv_fact[i] * i % MOD2;

    vector<pll> primes;
    for (auto &p : comp)
        if (is_prime(p.fi)) primes.pb(p);

    int m = sz(primes);
    if (m < n) { cout << 0 << '\n'; return; }

    vector<vll> dp(m + 1, vll(n + 1, 0));
    dp[m][0] = 1;
    for (int i = m - 1; i >= 0; --i) {
        ll cnt = primes[i].se;
        ll inv_cnt = inv_fact[cnt];
        ll inv_cnt_1 = cnt > 0 ? inv_fact[cnt - 1] : 0;
        for (int j = 0; j <= n; ++j) {
            ll val = inv_cnt * dp[i + 1][j] % MOD2;
            if (j > 0) val = (val + inv_cnt_1 * dp[i + 1][j - 1]) % MOD2;
            dp[i][j] = val;
        }
    }

    ll ans = dp[0][n];
    for (auto &p : comp)
        if (!is_prime(p.fi))
            ans = ans * inv_fact[p.se] % MOD2;

    ans = ans * fact[n] % MOD2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}
