#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    int Total_And;
    cin >> Total_And;
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        Total_And = (Total_And & x);
    }

    cout << Total_And << endl;
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