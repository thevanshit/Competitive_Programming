/*
 * ╔══════════════════════════════════════════════════════════════╗
 * ║              CPP BRAHMASTRA — Ultimate CP Boilerplate       ║
 * ║        One template to conquer every competitive problem    ║
 * ╚══════════════════════════════════════════════════════════════╝
 */

/* ======================== STANDARD INCLUDES ====================== */
#include <iostream>      // cin, cout, cerr
#include <algorithm>     // sort, min, max, lower_bound, swap, transform
#include <vector>        // vector
#include <string>        // string
#include <map>           // map
#include <set>           // set
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <queue>         // queue, priority_queue
#include <stack>         // stack
#include <deque>         // deque
#include <cmath>         // sqrt, abs, acos, round
#include <climits>       // INT_MAX, INT_MIN
#include <cstring>       // memset
#include <cstdlib>       // abs, rand
#include <numeric>       // accumulate, iota, gcd, lcm (C++17)
#include <functional>    // function, greater, less
#include <iterator>      // begin, end, next, prev
#include <sstream>       // stringstream
#include <iomanip>       // setprecision, setw
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, structured bindings
#include <bitset>        // bitset
#include <cassert>       // assert
#include <chrono>        // chrono
#include <random>        // random_device, mt19937
#include <limits>        // numeric_limits
#include <complex>       // complex
#include <optional>      // optional (C++17)
#include <array>         // array
#include <type_traits>   // enable_if, is_integral, etc.
using namespace std;

/* ========================== TYPEDEFS ========================== */
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<ld>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvll = vector<vll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

/* ========================== MACROS ============================ */
#define FAST_IO      ios::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repr(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define all(x)       begin(x), end(x)
#define rall(x)      rbegin(x), rend(x)
#define sz(x)        (int)(x).size()
#define pb           push_back
#define mp           make_pair
#define fi           first
#define se           second
#define endl         '\n'

/* ========================== DEBUG ============================= */
#ifdef LOCAL
#define debug(x)     cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debugv(v)    { cerr << #v << " = "; for (auto &_x : v) cerr << _x << ' '; cerr << endl; }
#define debugvv(v)   { cerr << #v << " =\n"; for (auto &_r : v) { for (auto &_x : _r) cerr << _x << ' '; cerr << endl; }}
#define debugm(m)    { cerr << #m << " =\n"; for (auto &[k, v] : m) cerr << k << " -> " << v << endl; }
#else
#define debug(x)
#define debug2(x, y)
#define debugv(v)
#define debugvv(v)
#define debugm(m)
#endif

/* ========================== CONSTANTS ========================= */
const int MOD  = 1'000'000'007;
const int MOD9 = 1'000'000'009;
const int INF  = 1'000'000'000;
const ll  LINF = 1'000'000'000'000'000'000LL;
const ld  EPS  = 1e-9;
const ld  PI   = acos(-1.0);

/* ========================== I/O HELPERS ======================= */
template<typename T> void read(T &t) { cin >> t; }
template<typename T, typename... Args> void read(T &t, Args&... args) { cin >> t; read(args...); }
template<typename T> void readv(vector<T> &v) { for (auto &x : v) cin >> x; }
template<typename T> void readvv(vector<vector<T>> &v) { for (auto &r : v) for (auto &x : r) cin >> x; }
template<typename T> void print(const T &t) { cout << t; }
template<typename T, typename... Args> void print(const T &t, const Args&... args) { cout << t; print(args...); }
template<typename T> void printv(const vector<T> &v, const string &sep = " ") {
    for (size_t i = 0; i < v.size(); ++i) cout << (i ? sep : "") << v[i];
}
template<typename T> void printlnv(const vector<T> &v, const string &sep = " ") { printv(v, sep); cout << endl; }
#define YESNO(b) cout << ((b) ? "YES" : "NO") << endl
#define YesNo(b) cout << ((b) ? "Yes" : "No") << endl

/* ========================== MATH HELPERS ====================== */
template<typename T> T sq(T x) { return x * x; }
template<typename T> T cdiv(T a, T b) { return (a + b - 1) / b; }
template<typename T> T sgn(T x) { return (x > 0) - (x < 0); }

ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m) - (b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }

ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1; a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll m = MOD) { return mod_pow(a, m - 2, m); }
ll mod_div(ll a, ll b, ll m = MOD) { return mod_mul(a, mod_inv(b, m), m); }

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll gcdv(const vll &v) { return accumulate(all(v), 0LL, gcd); }
ll lcmv(const vll &v) { return accumulate(all(v), 1LL, lcm); }

/* ========================== NUMBER THEORY ==================== */
bool is_prime(ll n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

vll get_divisors(ll n) {
    vll res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.pb(i);
            if (i != n / i) res.pb(n / i);
        }
    }
    sort(all(res));
    return res;
}

vll prime_factors(ll n) {
    vll res;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) { res.pb(i); n /= i; }
    }
    if (n > 1) res.pb(n);
    return res;
}

vector<pll> factorize(ll n) {
    vector<pll> res;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) { n /= i; cnt++; }
            res.pb({i, cnt});
        }
    }
    if (n > 1) res.pb({n, 1});
    return res;
}

vll sieve(ll n) {
    vector<bool> is_p(n + 1, true);
    vll primes;
    is_p[0] = is_p[1] = false;
    for (ll i = 2; i <= n; ++i) {
        if (is_p[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= n; j += i) is_p[j] = false;
        }
    }
    return primes;
}

/* ========================== COMBINATORICS ==================== */
vll fact, inv_fact;

void precompute_fact(ll n, ll m = MOD) {
    fact.resize(n + 1); inv_fact.resize(n + 1);
    fact[0] = 1;
    for (ll i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % m;
    inv_fact[n] = mod_inv(fact[n], m);
    for (ll i = n; i >= 1; --i) inv_fact[i - 1] = (inv_fact[i] * i) % m;
}

ll nCr(ll n, ll r, ll m = MOD) {
    if (r < 0 || r > n) return 0;
    return ((fact[n] * inv_fact[r]) % m * inv_fact[n - r]) % m;
}

ll nPr(ll n, ll r, ll m = MOD) {
    if (r < 0 || r > n) return 0;
    return (fact[n] * inv_fact[n - r]) % m;
}

/* ========================== BINARY SEARCH ==================== */
template<typename T>
T first_true(T lo, T hi, const function<bool(T)> &f) {
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        if (f(mid)) hi = mid; else lo = mid + 1;
    }
    return lo;
}

template<typename T>
T last_true(T lo, T hi, const function<bool(T)> &f) {
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) lo = mid; else hi = mid - 1;
    }
    return lo;
}

/* ========================== STRING UTILITIES ================= */
bool is_palindrome(const string &s) {
    int n = sz(s);
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - 1 - i]) return false;
    return true;
}

vi z_function(const string &s) {
    int n = sz(s); vi z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
    }
    return z;
}

vi prefix_function(const string &s) {
    int n = sz(s); vi pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

string to_lower(const string &s) {
    string res = s;
    transform(all(res), res.begin(), ::tolower);
    return res;
}

string to_upper(const string &s) {
    string res = s;
    transform(all(res), res.begin(), ::toupper);
    return res;
}

/* ========================== GRAPH HELPERS ==================== */
template<typename T>
using vv = vector<vector<T>>;

template<typename T>
vv<T> make_graph(int n, int edges, bool directed = false) {
    vv<T> g(n);
    for (int i = 0; i < edges; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        g[u].pb(v);
        if (!directed) g[v].pb(u);
    }
    return g;
}

template<typename T>
vv<pair<int, T>> make_weighted_graph(int n, int edges, bool directed = false) {
    vv<pair<int, T>> g(n);
    for (int i = 0; i < edges; ++i) {
        int u, v; T w; cin >> u >> v >> w; --u; --v;
        g[u].pb({v, w});
        if (!directed) g[v].pb({u, w});
    }
    return g;
}

/* ========================== GRID HELPERS ===================== */
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const string dir4 = "URDL";

bool in_bounds(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

/* ========================== DATA STRUCTURES ================== */
template<typename T>
struct Fenwick {
    int n; vector<T> bit;
    Fenwick(int n) : n(n), bit(n + 1) {}
    void add(int idx, T val) {
        for (++idx; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    T sum(int idx) {
        T res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    T range_sum(int l, int r) { return sum(r) - (l ? sum(l - 1) : 0); }
};

template<typename T>
struct SegTree {
    int n; vector<T> tree; T (*op)(T, T); T identity;
    SegTree(int n, T (*op)(T, T), T identity) : n(n), tree(4 * n), op(op), identity(identity) {}
    void build(const vector<T> &a, int node, int l, int r) {
        if (l == r) { tree[node] = a[l]; return; }
        int m = (l + r) / 2;
        build(a, 2 * node, l, m);
        build(a, 2 * node + 1, m + 1, r);
        tree[node] = op(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int pos, T val, int node, int l, int r) {
        if (l == r) { tree[node] = val; return; }
        int m = (l + r) / 2;
        if (pos <= m) update(pos, val, 2 * node, l, m);
        else update(pos, val, 2 * node + 1, m + 1, r);
        tree[node] = op(tree[2 * node], tree[2 * node + 1]);
    }
    T query(int ql, int qr, int node, int l, int r) {
        if (ql > r || qr < l) return identity;
        if (ql <= l && r <= qr) return tree[node];
        int m = (l + r) / 2;
        return op(query(ql, qr, 2 * node, l, m), query(ql, qr, 2 * node + 1, m + 1, r));
    }
};

/* ========================== DISJOINT SET UNION =============== */
struct DSU {
    vi parent, rank;
    DSU(int n) : parent(n), rank(n, 0) { iota(all(parent), 0); }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) ++rank[a];
        return true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
};

/* ========================== ALGORITHM HELPERS ================ */
template<typename T>
void sort_unique(vector<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

template<typename T>
T mex(const vector<T> &v) {
    set<T> s(all(v));
    T m = 0;
    while (s.count(m)) ++m;
    return m;
}

template<typename T>
int lis(const vector<T> &v) {
    vector<T> tails;
    for (auto &x : v) {
        auto it = lower_bound(all(tails), x);
        if (it == tails.end()) tails.pb(x);
        else *it = x;
    }
    return sz(tails);
}

/* ========================== MAIN SOLVER ====================== */
void solve() {
    // ╔════════════════════════════════════════════════════════╗
    // ║  Write your solution logic here                       ║
    // ╚════════════════════════════════════════════════════════╝

}

/* ============================================================= */
int main() {
    FAST_IO;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
