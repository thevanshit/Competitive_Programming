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

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    int c = min(n, k + 1);
    ll ans = accumulate(a.begin(), a.begin() + c, 0LL);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}