#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;

    long long a = 1;
    for(long long g = 2; g * g <= n; g++){
        if (n % g == 0){
            a = n / g;
            break;
        }
    }

    cout << a << " " << n - a << "\n";
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