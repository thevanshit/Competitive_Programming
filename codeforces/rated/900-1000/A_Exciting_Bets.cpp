#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long a;
    long long b;

    cin >> a >> b;
    long long max_excitement = abs(a - b);

    long long min_operations = min(a % max_excitement, max_excitement - a % max_excitement);

    if (max_excitement == 0){
        min_operations = 0;
    }
    cout << max_excitement << " " << min_operations;
    cout << endl;
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