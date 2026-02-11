#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    vector <long long> a(n);
    long long odd_ele = 0;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] % 2 == 1){
            odd_ele++;
        }
    } 
    if ((odd_ele % 2 == 1)){
        cout << "No" << "\n";
    }
    else {
        cout << "Yes" << "\n";
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