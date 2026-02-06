#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long a, b;
    cin >> a >> b;

    if (a == b){
        cout << 0 << "\n";
        return;
    }
    
    long long ra = a;
    long long rb = b;

    while (ra % 2 == 0){
        ra /= 2;
    }
    while (rb % 2 == 0){
        rb /= 2;
    }

    if (ra != rb){
        cout << -1 << "\n";
        return;
    }
    else{
        a /= ra;
        b /= rb;

        a = log2(a);
        b = log2(b);

        long long diff = abs(a - b);
        long long result = ceil(diff / 3.0);
        cout << result << "\n";
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