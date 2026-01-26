#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    vector <int> a;
    cout << n << " ";
    while (true){
        if(n == 1){
            break;
        }
        if (n % 2 == 0){
            n /= 2;
            cout << n << " ";
        }
        else{
            n *= 3;
            n++;
            cout << n << " ";
        }
    }
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