#include <bits/stdc++.h>
using namespace std;


void solve(){
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int One_Three_pair = min(X, Z);
    int Two_Pair = Y / 2;

    cout << (One_Three_pair + Two_Pair) << endl;
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