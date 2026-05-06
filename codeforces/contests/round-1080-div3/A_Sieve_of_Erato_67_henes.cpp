#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    bool found = false;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 67) found = true;
    }

    if(found) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
