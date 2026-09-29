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

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if ((x != 0 && 18 % x == 0) || x % 45 == 0) {
            cnt++;
        }
    }
    
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}