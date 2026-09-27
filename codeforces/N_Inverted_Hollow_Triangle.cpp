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

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n - i; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            if(j == 1 || i == n) cout << "* ";
            else if(j == i) cout << "*";
            else cout << "  ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}