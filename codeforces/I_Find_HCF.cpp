#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll HCF(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    cout << HCF(a, b) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}