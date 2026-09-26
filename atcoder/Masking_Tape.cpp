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
    if(!(cin >> n >> q)) return;

    vi tim(n + 1, 0);
    vi unc(n + 1, 0);
    vector <bool> cov(n + 1, false);

    int lt = 0;
    vector <char> col(q + 1, 'a');
    
    for(int t = 1; t <= q; t++){
        int op;
        cin >> op;

        if(op == 1){
            int x;
            cin >> x;
            if(!cov[x]){
                if(lt > unc[x]){
                    tim[x] = max(tim[x], lt);
                }
                cov[x] = true;
            }
            else{
                cov[x] = false;
                unc[x] = t;
            }
        }
        else{
            char c;
            cin >> c;
            lt = t;
            col[t] = c;
        }
    }
    string ans = "";
    for(int i = 1; i <= n; i++){
        if(!cov[i]){
            if(lt > unc[i]){
                tim[i] = max(tim[i], lt);
            }
        }
        ans += col[tim[i]];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}