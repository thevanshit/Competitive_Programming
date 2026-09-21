#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

struct Seg {
    ll l, r;
    int id;
};

vector<ll> calc(vector<Seg> a) {
    sort(all(a), [](const Seg& x, const Seg& y) {
        if (x.l != y.l) return x.l < y.l;
        return x.r > y.r;
    });

    set<ll> s;
    vector<ll> res(a.size());

    for (const auto& x : a) {
        auto it = s.lower_bound(x.r);

        if (it != s.end()) {
            res[x.id] = *it - x.r;
        }

        s.insert(x.r);
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<Seg> a(n);
    map<pair<ll, ll>, int> cnt;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
        ++cnt[{a[i].l, a[i].r}];
    }

    vector<ll> ans = calc(a);

    vector<Seg> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = {-a[i].r, -a[i].l, a[i].id};
    }

    vector<ll> left = calc(b);

    for (int i = 0; i < n; ++i) {
        if (cnt[{a[i].l, a[i].r}] > 1) {
            ans[i] = 0;
        } else {
            ans[i] += left[i];
        }

        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}