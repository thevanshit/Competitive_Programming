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

void solve() {

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
}
