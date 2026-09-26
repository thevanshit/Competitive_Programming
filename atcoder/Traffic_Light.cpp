#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    char c;
    cin >> c;

    if(c == 'B'){
        cout << 'Y' << "\n";
    }
    else if(c == 'Y'){
        cout << 'R' << "\n";
    }
    else{
        cout << 'B' << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}