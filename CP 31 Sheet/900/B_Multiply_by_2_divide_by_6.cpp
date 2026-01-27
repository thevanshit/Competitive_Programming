#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;

    long long cnt2 = 0;
    long long cnt3 = 0;

    while(n > 0 && n % 3 == 0){
        cnt3++;
        n /= 3;
    }

    while (n > 0 && n % 2 == 0){
        cnt2++;
        n /= 2;
    }

    if (n > 1 || cnt2 > cnt3){
        cout << -1 << endl;
    }
    else {
        cout << (cnt3 - cnt2) + cnt3 << endl;
    }
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