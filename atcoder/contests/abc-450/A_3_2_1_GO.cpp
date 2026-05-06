#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    for(long long i = n; i >= 1; i--){
        if (i == 1){
            cout << i;
            break;
        }
        cout << i << ",";
    }
    cout << "\n";
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}