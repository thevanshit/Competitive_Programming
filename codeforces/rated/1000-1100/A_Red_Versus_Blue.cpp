#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    long long r;
    cin >> r;
    long long b;
    cin >> b;

    long long p = r / (b + 1);
    long long q = r % (b + 1);
    for(long long i = 0; i < q; i++){
        cout << string(p + 1, 'R') << 'B';
    }
    for(long long i = q; i < b; i++){
        cout << string(p, 'R') << 'B';
    }
    cout << string(p, 'R');
    cout << "\n";
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