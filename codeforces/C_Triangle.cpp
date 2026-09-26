#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    for(int i = 5; i >= 1; i--){
        for(int j = i; j >= 1; j--){
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}