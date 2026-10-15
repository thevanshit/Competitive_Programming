#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector <int>;
using vll = vector <long long>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

const int MOD = 998244353;

int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (1LL * res * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return res;
}

vi rev;
vi roots{0, 1};

void precompute_ntt(int n) {
    if (sz(roots) >= n) return;
    int len = sz(roots);
    roots.resize(n);
    for (; len < n; len <<= 1) {
        int wlen = power(3, (MOD - 1) / (len << 1));
        for (int i = len; i < (len << 1); i++) {
            roots[i] = (i % 2 == 0) ? roots[i >> 1] : (1LL * roots[i - 1] * wlen) % MOD;
        }
    }
}

void ntt(vi& a, int n) {
    if (sz(rev) != n) {
        rev.resize(n);
        int k = __builtin_ctz(n);
        for (int i = 0; i < n; i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
        }
    }
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    
    precompute_ntt(n);
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                int u = a[i + j];
                int v = 1LL * a[i + j + k] * roots[k + j] % MOD;
                a[i + j] = (u + v < MOD ? u + v : u + v - MOD);
                a[i + j + k] = (u - v >= 0 ? u - v : u - v + MOD);
            }
        }
    }
}

vi multiply(vi a, vi b) {
    if (a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1;
    int n = 1;
    while (n < s) n <<= 1;
    a.resize(n); b.resize(n);
    ntt(a, n); ntt(b, n);
    int inv_n = power(n, MOD - 2);
    for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % MOD * inv_n % MOD;
    reverse(a.begin() + 1, a.end());
    ntt(a, n);
    a.resize(s);
    return a;
}

vi solve_dnc(int l, int r, const vector<vi>& polys, const vi& pref) {
    if (l == r) return polys[l];
    int target = pref[l] + (pref[r + 1] - pref[l]) / 2;
    auto it = upper_bound(pref.begin() + l, pref.begin() + r + 1, target);
    int pref_idx = distance(pref.begin(), it) - 1;
    int mid = max(l, min(pref_idx - 1, r - 1));
    return multiply(solve_dnc(l, mid, polys, pref), solve_dnc(mid + 1, r, polys, pref));
}

void solve() {
    int n;
    cin >> n;
    vi p(n);
    for (int &x : p) cin >> x;

    vi s;
    int mx = 0, l = 0;
    for (int x : p) {
        if (x > mx) {
            if (l > 0) s.pb(l);
            l = 1;
            mx = x;
        } else {
            l++;
        }
    }
    if (l > 0) s.pb(l);
    
    int k = sz(s);
    vector<vi> polys(k);
    vi pref(k + 1, 0);
    for (int i = 0; i < k; i++) {
        polys[i].assign(s[i] + 1, 0);
        polys[i][0] = 1;
        polys[i][s[i]] = 1;
        pref[i + 1] = pref[i] + s[i];
    }
    
    vi dp = solve_dnc(0, k - 1, polys, pref);
    dp.resize(n + 1, 0);
    
    for (int i = 0; i <= n; i++) {
        cout << dp[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}