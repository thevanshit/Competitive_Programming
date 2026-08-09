#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int N;
    cin >> N;
    vi A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    bool ok = true;
    for (int i = 0; i < N / 2; i++) {
        if (A[i] != A[N - 1 - i]) { ok = false; break; }
    }
    if (ok) { cout << "Yes\n"; return; }

    int max_lo = 0, min_hi = INT_MAX;

    for (int i = 0; i < N / 2; i++) {
        int a = A[i], b = A[N - 1 - i];
        if (a == b) continue;

        if (abs(a - b) != 2) {
            cout << "No\n";
            return;
        }

        int lo = min(a, b);
        int hi = lo + 1; 
        max_lo = max(max_lo, lo);
        min_hi = min(min_hi, hi);
    }

    cout << (max_lo <= min_hi ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}