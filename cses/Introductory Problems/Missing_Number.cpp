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
    int XOR1 = 0;
    int XOR2 = 0;
    for(int i = 1; i < n; i++){
        XOR1 ^= i;
        int val;
        cin >> val;
        XOR2 ^= val;
    }
    XOR1 ^= n;
    cout << (XOR1 ^ XOR2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}