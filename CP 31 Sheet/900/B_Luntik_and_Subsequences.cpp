#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    long long cnt0 = 0;
    long long cnt1 = 0;
    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        if (x == 1){
            cnt1++;
        }
        if(x == 0){
            cnt0++;
        }
    }

    cout << ((1ll << cnt0) * (cnt1)) << endl;
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