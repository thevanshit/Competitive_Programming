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
    cin >> n;

    vi a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int l = 0, r = n - 1;

    while(a[l] == b[l]) l++;
    while(a[r] == b[r]) r--;
    while(l > 0 && b[l - 1] <= b[l]) l--;
    while(r < n - 1 && b[r + 1] >= b[r]) r++;

    cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}