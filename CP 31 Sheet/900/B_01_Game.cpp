#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin >> s;

    long long n0s = 0;
    long long n1s = 0;
    for(char ch : s){
        if (ch == '1')
            n1s++;
        else
            n0s++;
    }

    long long factor = min(n0s, n1s);
    if(factor % 2 == 1)
        cout << "DA" << endl;
    else 
        cout << "NET" << endl;
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