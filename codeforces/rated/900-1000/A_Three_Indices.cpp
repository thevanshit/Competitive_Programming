#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    vector <long long> p(n);
    for(long long i = 0; i < n; i++) cin >> p[i];

    long long i = 0;
    long long j = 0;
    long long k = 0;
    bool okay = false;
    for(long long x = 1; x < n - 1; x++){
        if (p[x] > p[x - 1] && p[x] > p[x + 1]){
            i = x;
            j = x + 1;
            k = x + 2;
            okay = true;
            break;
        }
    }

    if (okay){
        cout << "YES" << endl;
        cout << i << " " << j << " " << k << endl;
    }
    else 
        cout << "NO" << endl;

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