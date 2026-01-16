#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> check(26, 0);
    for (char c : S) {
        check[c - 'a']++;
        if (check[c - 'a'] > 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
