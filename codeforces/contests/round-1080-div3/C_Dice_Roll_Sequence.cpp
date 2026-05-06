#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    vector <long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];

    const long long INF = 1e18;
    vector<long long> dp(7, INF), newdp(7, INF);

    for(int v = 1; v <= 6; v++) {
        dp[v] = (a[0] != v);
    }

    for(int i = 1; i < n; i++) {
        fill(newdp.begin(), newdp.end(), INF);
        for(int v = 1; v <= 6; v++) {          
            for(int u = 1; u <= 6; u++) {      
                if(u == v) continue;
                if(u == 7 - v) continue;

                newdp[v] = min(newdp[v],
                                dp[u] + (a[i] != v));
            }
        }
        dp = newdp;
    }

    long long ops = *min_element(dp.begin()+1, dp.end());
    cout << ops << "\n";
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}