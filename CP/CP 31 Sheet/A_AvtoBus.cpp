#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    if (n % 2 == 1){
        cout << -1 << endl;
    }
    else{
        if (n <= 4){
            if (n < 4){
                cout << - 1 << endl;
            }
            else{
                cout << 1 << " " << 1 << endl;
            }
        }
        else{
            cout << (n + 5) / 6 << " " << n / 4 << endl;
        }
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