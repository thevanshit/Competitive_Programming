#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    string s;
    cin >> n;
    cin >> s;

    long long ans = 0;
    long long balance = 0;
    for(char c : s){
        if (c == '(') balance++;
        else {
            balance--;
            if (balance < 0){
                balance = 0;
                ans++;
            }
        }
    }

    cout << ans << "\n";
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