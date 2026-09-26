#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int l, r; 
    cin >> l >> r;

    for(int i = l; i <= r; i++){
        cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}