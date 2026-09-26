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

    int po = 0;
    int ne = 0;
    int ev = 0;
    int od = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(x > 0) po++;
        if(x < 0) ne++;
        if(x % 2 == 0) ev++;
        if(x % 2 != 0) od++;
    }
    cout << po << "\n" << ne << "\n" << ev << "\n" << od << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}