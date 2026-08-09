#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

// Values can reach Q (<= 5e5) < 2^19, so bits 0..18; use 20 for safety.
const int P = 20;

void solve() {
    int n, q;
    cin >> n >> q;

    vi a(n + 1, 0);
    vi lastDec(n + 1, 0); // global dec count at the time a[x] was last written
    int dec = 0;          // number of type-2 operations so far
    int xr = 0;

    // cntLow[p] = number of elements whose lowest set bit is p
    vi cntLow(P + 1, 0);

    // R[p][(r - off[p]) mod 2^(p+1)] = count of POSITIVE elements with value ≡ r (mod 2^(p+1))
    // Zero elements are tracked separately in cnt0 and never stored in R.
    vector<vi> R(P + 1);
    vi off(P + 1, 0);
    for (int p = 0; p <= P; p++) R[p].assign(1 << (p + 1), 0);

    int cnt0 = n; // number of elements with value 0 

    auto idx = [&](int p, int r) {
        int m = 1 << (p + 1);
        return ((r - off[p]) % m + m) % m;
    };

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            int old = max(a[x] - (dec - lastDec[x]), 0);
            int nw = old + 1;
            a[x] = nw;
            lastDec[x] = dec;
            xr ^= old ^ nw;
            if (old > 0) {
                cntLow[__builtin_ctz(old)]--;
                for (int p = 0; p <= P; p++) R[p][idx(p, old)]--;
            } else {
                cnt0--;
            }
            cntLow[__builtin_ctz(nw)]++;
            for (int p = 0; p <= P; p++) R[p][idx(p, nw)]++;
        } else {
            dec++;
            for (int p = 0; p <= P; p++) {
                if (cntLow[p] & 1) xr ^= (1 << (p + 1)) - 1;
            }
            int cnt1 = R[0][idx(0, 1)];
            for (int k = 1; k <= P; k++) cnt1 -= R[k][idx(k, (1 << k) + 1)];
            for (int p = 0; p <= P; p++) R[p][idx(p, 1)] -= cnt1;
            cnt0 += cnt1;
            vi ncnt(P + 1, 0);
            for (int p = 1; p <= P; p++) ncnt[0] += R[p][idx(p, 1 << p)];
            for (int p = 1; p <= P; p++) ncnt[p] = R[p][idx(p, (1 << p) + 1)];
            cntLow = ncnt;
            for (int p = 0; p <= P; p++) off[p]--;
        }
        cout << xr << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}