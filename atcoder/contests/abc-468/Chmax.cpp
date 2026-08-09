#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

const int INF = INT_MAX / 2;

struct SegTree {
    int n, size;
    vi seg;

    SegTree(int n, const vi& arr) : n(n) {
        size = 1;
        while (size < n) size <<= 1;
        seg.assign(2 * size, INF);
        for (int i = 0; i < n; i++) {
            seg[size + i] = arr[i];
        }
        for (int i = size - 1; i > 0; i--) {
            seg[i] = min(seg[2 * i], seg[2 * i + 1]);
        }
    }

    void update(int idx, int val) {
        idx += size;
        seg[idx] = val;
        while (idx > 1) {
            idx >>= 1;
            seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
        }
    }

    int query(int l, int r) {
        if (l > r) return INF;
        l += size;
        r += size;
        int res = INF;
        while (l <= r) {
            if (l & 1) res = min(res, seg[l++]);
            if (!(r & 1)) res = min(res, seg[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vi pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }

    vi arr(n);
    for (int v = 1; v <= n; v++) {
        arr[v - 1] = pos[v];
    }
    SegTree seg(n, arr);

    int ans = 0;
    int low = 0; 
    int high = 0;

    for (int k = 0; k < n; k++) {
        int v = p[k];

        if (v > high) {
            ans++;
            high = v;
        } else if (v > low) {
            int min_pos = seg.query(low, v - 2); 
            if (min_pos >= INF) {
                ans++;
                low = v;
            }
        }
        seg.update(v - 1, INF);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}
