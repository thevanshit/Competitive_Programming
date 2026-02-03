#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    long long x;
    cin >> n >> x;
    vector <long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];
    long long left_limit = a[0];
    long long right_limit = a[0];

    long long result = 0;
    for(long long i = 1; i < n; i++){
        if (left_limit > a[i]){
            left_limit = a[i];
        }
        if (right_limit < a[i]){
            right_limit = a[i];
        }
        if (right_limit - left_limit > 2 * x){
            result++;
            left_limit = right_limit = a[i];
        }
    }

    cout << result << "\n";
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