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

    for(int i = 1; i <= 2 * n - 1; i++){
        int st = abs(n - i) + 1;
        for(int j = 0; j < st; j++){
            cout << "*";
        }
        int sp = 2 * (n - st) + 1;
        for (int j = 0; j < sp; j++) {
            cout << ' ';
        }
        for(int j = 0; j < st; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}