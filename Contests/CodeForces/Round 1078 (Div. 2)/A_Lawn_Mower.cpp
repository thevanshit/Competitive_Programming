#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    long long w;
    cin >> n >> w;

    long long all_blocks = n / w;
    long long rem = n % w;

    long long removed = all_blocks * (w - 1) + min(rem, w - 1);

    cout << removed << "\n";
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