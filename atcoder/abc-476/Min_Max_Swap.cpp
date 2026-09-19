#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

struct Node {
    pii mn = {INT_MAX, -1};
    pii mx = {INT_MIN, -1};
};

int n, m;
vector<int> p;
vector<Node> st;

Node merge_node(const Node& a, const Node& b) {
    Node r;
    r.mn = min(a.mn, b.mn);
    r.mx = max(a.mx, b.mx);
    return r;
}

void build(int v, int l, int r) {
    if (l == r) {
        st[v].mn = {p[l], l};
        st[v].mx = {p[l], l};
        return;
    }

    int mid = (l + r) / 2;

    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);

    st[v] = merge_node(st[v * 2], st[v * 2 + 1]);
}

void update(int v, int l, int r, int pos) {
    if (l == r) {
        st[v].mn = {p[pos], pos};
        st[v].mx = {p[pos], pos};
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid) {
        update(v * 2, l, mid, pos);
    } 
    else {
        update(v * 2 + 1, mid + 1, r, pos);
    }

    st[v] = merge_node(st[v * 2], st[v * 2 + 1]);
}

Node query(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return Node();
    }

    if (ql <= l && r <= qr) {
        return st[v];
    }

    int mid = (l + r) / 2;

    Node left = query(v * 2, l, mid, ql, qr);
    Node right = query(v * 2 + 1, mid + 1, r, ql, qr);

    return merge_node(left, right);
}

void solve() {
    cin >> n >> m;

    p.resize(n);

    for (int& x : p) {
        cin >> x;
    }

    st.resize(4 * n);
    build(1, 0, n - 1);

    while (m--) {
        int l, r;
        cin >> l >> r;

        --l;
        --r;

        Node cur = query(1, 0, n - 1, l, r);

        int x = cur.mn.second;
        int y = cur.mx.second;

        swap(p[x], p[y]);

        update(1, 0, n - 1, x);
        update(1, 0, n - 1, y);
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << p[i];
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}