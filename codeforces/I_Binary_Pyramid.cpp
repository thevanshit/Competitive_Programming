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

    for (int i = 0; i < n; i++) {
        bool flag = true;
        if(i % 2 == 0) {
            flag = true;
        } else {
            flag = false;
        }
        for (int j = 0; j <= i; j++) {
            if(flag) {
                cout << 0;
                flag = false;
            } else {
                cout << 1;
                flag = true;
            }
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}