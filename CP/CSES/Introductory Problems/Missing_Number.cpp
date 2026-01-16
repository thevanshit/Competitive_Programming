#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    long long XOR1 = 0;
    long long XOR2 = 0;
    for(int i = 1; i < n; i++){
        int ele;
        cin >> ele;
        XOR1 ^= ele;
        XOR2 ^= i;
    }
    XOR2 ^= n;
    cout << (XOR1 ^ XOR2);
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