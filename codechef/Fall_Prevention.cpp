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

    ll s = 0;
    ll miv = 0;
    bool del = false;
    bool pos = true;

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(!pos) continue;

        if(!del){
            miv = min(miv, x);
            s += x;
            if(s < 0){
                s -= miv;
                del = true;
                if(s < 0){
                    pos = false;
                }
            }
        }
        else{
            s += x;
            if(s < 0){
                pos = false;
            }
        }
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}