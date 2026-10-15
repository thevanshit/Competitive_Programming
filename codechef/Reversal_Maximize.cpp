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

struct E {
    int s, m;
    bool operator<(const E& o) const {
        if (s != o.s) return s < o.s;
        return m > o.m; 
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vi pr(n + 1, 0);
    int b = 0; 
    for (int i = 1; i <= n; i++) {
        pr[i] = pr[i - 1] + (a[i] == i);
        if (a[i] == i) b++;
    }

    vector<E> ev;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            ev.pb({i + a[i], min(i, a[i])});
        }
    }
    sort(all(ev));

    int mxg = 0;
    int i = 0, k = sz(ev);
    while (i < k) {
        int s = ev[i].s;
        int j = i;
        int adj = (s % 2 == 0 && a[s / 2] == s / 2) ? 1 : 0;
        
        int cmx = 0;
        int cnt = 0;
        while (j < k && ev[j].s == s) {
            cnt++;
            int m = ev[j].m;
            int g = cnt - (pr[s - m] - pr[m - 1]) + adj;
            cmx = max(cmx, g);
            j++;
        }
        mxg = max(mxg, cmx);
        i = j;
    }
    cout << b + mxg << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}