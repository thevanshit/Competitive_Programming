#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    long long k;
    long long q;
    cin >> n >> k >> q;

    vector <long long> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > q){
            a[i] = 0;
        }
        else{
            a[i] = 1;
        }
    }

    long long count = 0;
    long long ways = 0;
    for(long long i = 0; i < n; i++){
        if (a[i] == 1){
            count++;
        }
        else {
            if (count >= k){
                long long diff = count - k + 1;
                ways += diff * (diff + 1) / 2;
            }
            count = 0;
        }
    }

    if (count >= k){
        long long diff = count - k + 1;
        ways += diff * (diff + 1) / 2;
    }

    cout << ways << "\n";
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