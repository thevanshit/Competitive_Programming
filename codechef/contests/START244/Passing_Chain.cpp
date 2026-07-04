#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repr(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
#define dbg2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define dbgv(v) { cerr << #v << " = "; for (auto &_x : v) cerr << _x << ' '; cerr << endl; }
#else
#define dbg(x)
#define dbg2(x, y)
#define dbgv(v)
#endif
const int MOD = 1'000'000'007;
const int INF = 1'000'000'000;
const ll LINF = 1'000'000'000'000'000'000LL;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m) - (b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll m = MOD) { return mod_pow(a, m - 2, m); }

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

vector<ll> get_divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.pb(i);
            if (i != n / i) res.pb(n / i);
        }
    }
    sort(all(res));
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool is_even(ll n) { return n % 2 == 0; }
bool is_odd(ll n) { return n % 2 != 0; }

void solve() {
    int n, k;
    cin >> n >> k;
    
    int ans = 1 + k * ((n - 1) / k);
    cout << ans << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
