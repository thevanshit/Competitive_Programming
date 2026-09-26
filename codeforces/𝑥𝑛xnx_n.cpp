#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n, q;
    cin >> n >> q;

    if(q == 0){
        cout << 1 << "\n";
        return;
    }

    ll po = 1;
    for(int i = 0; i < q; i++){
        po *= n;
    }
    cout << po << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}