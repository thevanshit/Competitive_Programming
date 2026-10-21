#include <bits/stdc++.h>
using namespace std;
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

const int MOD = 1e9 + 7;
const int MAX = 200005;
ll fact[MAX], invFact[MAX];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 1; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

ll W_row(int p, int q, int m, int N_r0, int N_r1) {
    if (m % 2 == 0) {
        if (p + q > N_r0) return 0;
        return (nCr(N_r0, p + q) * nCr(p + q, p)) % MOD;
    } else {
        if (p > N_r0 || q > N_r1) return 0;
        return (nCr(N_r0, p) * nCr(N_r1, q)) % MOD;
    }
}

ll W_col(int u, int v, int n, int N_c0, int N_c1) {
    if (n % 2 == 0) {
        if (u + v > N_c0) return 0;
        return (nCr(N_c0, u + v) * nCr(u + v, u)) % MOD;
    } else {
        if (u > N_c0 || v > N_c1) return 0;
        return (nCr(N_c0, u) * nCr(N_c1, v)) % MOD;
    }
}

ll F(int p, int q, int u, int v, int n, int m, const vi& RX, const vi& CX) {
    if (p > 0 && v > 0) return 0;
    if (q > 0 && u > 0) return 0;

    int nr = n - p - q;
    int mc = m - u - v;

    if (nr > 0 && mc > 0) return power(2, 1LL * (nr - 1) * (mc - 1));

    if (nr == 0 && mc > 0) {
        int req = q % 2;
        for (int x : CX) if (x != req) return 0;
        if (u > 0 && q != 0) return 0;
        if (v > 0 && q != n) return 0;
        return 1;
    }

    if (mc == 0 && nr > 0) {
        int req = v % 2;
        for (int x : RX) if (x != req) return 0;
        if (p > 0 && v != 0) return 0;
        if (q > 0 && v != m) return 0;
        return 1;
    }

    if (nr == 0 && mc == 0) {
        int rq = q % 2, rv = v % 2;
        for (int x : CX) if (x != rq) return 0;
        for (int x : RX) if (x != rv) return 0;
        if (u > 0 && q != 0) return 0;
        if (v > 0 && q != n) return 0;
        if (p > 0 && v != 0) return 0;
        if (q > 0 && v != m) return 0;
        return 1;
    }
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi RX(n), CX(m);
    for (int i = 0; i < n; i++) {
        int rx, ro, ra;
        cin >> rx >> ro >> ra;
        RX[i] = rx;
    }
    for (int j = 0; j < m; j++) {
        int cx, co, ca;
        cin >> cx >> co >> ca;
        CX[j] = cx;
    }

    ll sr = 0, sc = 0;
    int N_r0 = 0, N_r1 = 0, N_c0 = 0, N_c1 = 0;
    for (int i = 0; i < n; i++) {
        sr += RX[i];
        if (RX[i] == 0) N_r0++;
        if (RX[i] == (m % 2)) N_r1++;
    }
    for (int j = 0; j < m; j++) {
        sc += CX[j];
        if (CX[j] == 0) N_c0++;
        if (CX[j] == (n % 2)) N_c1++;
    }

    if ((sr % 2) != (sc % 2)) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;

    auto add = [&](ll ways, ll f_val, int parity) {
        if (!ways || !f_val) return;
        ll term = (ways * f_val) % MOD;
        if (parity % 2 == 1) ans = (ans - term + MOD) % MOD;
        else ans = (ans + term) % MOD;
    };

    for (int p = 0; p <= n; p++) {
        for (int u = 0; u <= m; u++) {
            ll w = (W_row(p, 0, m, N_r0, N_r1) * W_col(u, 0, n, N_c0, N_c1)) % MOD;
            add(w, F(p, 0, u, 0, n, m, RX, CX), p + u);
        }
    }

    for (int q = 0; q <= n; q++) {
        for (int v = 0; v <= m; v++) {
            if (q == 0 && v == 0) continue;
            ll w = (W_row(0, q, m, N_r0, N_r1) * W_col(0, v, n, N_c0, N_c1)) % MOD;
            add(w, F(0, q, 0, v, n, m, RX, CX), q + v);
        }
    }

    for (int k = 2; k < n; k++) {
        ll wr = 0;
        if (m % 2 == 0) {
            if (k <= N_r0) wr = (nCr(N_r0, k) * (power(2, k) - 2 + MOD)) % MOD;
        } else {
            wr = (nCr(n, k) - nCr(N_r0, k) + MOD) % MOD;
            wr = (wr - nCr(N_r1, k) + MOD) % MOD;
        }
        add(wr, power(2, 1LL * (n - k - 1) * (m - 1)), k);
    }

    for (int p = 1; p < n; p++) {
        int q = n - p;
        add(W_row(p, q, m, N_r0, N_r1), F(p, q, 0, 0, n, m, RX, CX), n);
    }

    for (int k = 2; k < m; k++) {
        ll wc = 0;
        if (n % 2 == 0) {
            if (k <= N_c0) wc = (nCr(N_c0, k) * (power(2, k) - 2 + MOD)) % MOD;
        } else {
            wc = (nCr(m, k) - nCr(N_c0, k) + MOD) % MOD;
            wc = (wc - nCr(N_c1, k) + MOD) % MOD;
        }
        add(wc, power(2, 1LL * (n - 1) * (m - k - 1)), k);
    }

    for (int u = 1; u < m; u++) {
        int v = m - u;
        add(W_col(u, v, n, N_c0, N_c1), F(0, 0, u, v, n, m, RX, CX), m);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;
    while (t--) solve();
}