#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    vector <long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];
    long long max_streak = INT_MIN;
    long long cnt = 0;
    for(long long i = 0; i < n; i++){
        if (a[i] != 0){
            cnt++;
        }
        else{
            cnt = 0;
        }
        max_streak = max(max_streak, cnt);
    }

    cout << max_streak << "\n";
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