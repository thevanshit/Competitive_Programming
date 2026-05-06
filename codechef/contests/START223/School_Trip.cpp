#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N, X, K;
    cin >> N >> X >> K;

    int low = (X / K) * K;
    int ans = abs(X - low);

    int high = low + K;
    if (high <= N) {
        ans = min(ans, abs(X - high));
    }

    cout << ans << endl;
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