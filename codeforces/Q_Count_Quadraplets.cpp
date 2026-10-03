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
    int n;
    ll x;
    cin >> n >> x;
    vll a(n);
    for (auto &v : a)
        cin >> v;
    unordered_map<ll, ll> freq;
    ll cnt = 0;
    for (int k = 0; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
            ll nd = x - 3LL * a[k] + 4LL * a[l];
            auto it = freq.find(nd);
            if (it != freq.end())
                cnt += it -> second;
        }
        for (int i = 0; i < k; i++) {
            ll va = a[i] - 2LL * a[k];
            freq[va]++;
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}