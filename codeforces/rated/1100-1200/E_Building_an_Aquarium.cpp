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
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &v : a) cin >> v;

    ll lo = 1, hi = *max_element(all(a)) + x;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;  
        ll water = 0;
        for (auto v : a) {
            if (mid > v) water += mid - v;
            if (water > x) break;  
        }
        if (water <= x) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}