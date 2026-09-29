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

    for (int i = 1; i <= 2 * n - 1; i++) {
        int sp;
        int dot;
        if (i <= n) {
            sp = i - 1;
            dot = n - i + 1;
        } 
        else {
            sp = 2 * n - i - 1;
            dot = i - n + 1;
        }
        for (int j = 0; j < sp; j++) {
            cout << " ";
        }

        for (int j = 0; j < dot; j++) {
            cout << ".";
            if (j != dot - 1)
                cout << " ";
        }

        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}