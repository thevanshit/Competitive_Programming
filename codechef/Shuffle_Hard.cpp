#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

const int MOD = 998244353;

struct Fenwick {
    int n;
    vi tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vi q(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    for (int i = n - k + 1; i < n; i++) {
        if (q[i] > q[i + 1]) {
            cout << 0 << '\n';
            return;
        }
    }
    vi pa(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && q[st.top()] < q[i]) {
            st.pop();
        }
        pa[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    vi B(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        B[i] = min(n, i + k - 1);
    }
    struct Event {
        int len, id, A, B;
        bool operator<(const Event& oth) const {
            if (len != oth.len) return len < oth.len;
            return id < oth.id;
        }
    };
    
    vector<Event> ev;
    for (int i = 1; i <= n; i++) {
        int A = B[pa[i]] + 1;
        int Bval = B[i];
        int len = Bval - A + 1;
        if (len <= 0) {
            cout << 0 << '\n';
            return;
        }
        ev.push_back({len, i, A, Bval});
    }
    sort(ev.begin(), ev.end());
    Fenwick fenw(n + 2);
    ll ans = 1;
    for (const auto& ev : ev) {
        int c = fenw.query(ev.B) - fenw.query(ev.A - 1);
        int choi = ev.len - c;
        if (choi <= 0) {
            cout << 0 << '\n';
            return;
        }
        ans = (ans * choi) % MOD;
        fenw.update(ev.A, 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}