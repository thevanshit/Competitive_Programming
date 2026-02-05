#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long d;
    cin >> d;
    vector <long long> p;
    for(long long i = d + 1; ;i++){
        long long t = 1;
        for(long long j = 2; j * j <= i; j++){
            if (i % j == 0){
                t = 0;
            }
        }
        if (t){
            p.push_back(i);
            break;
        }
    }
    for (int i = p.back() + d; ; i++)
    {
        int t = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                t = 0;
                break;
            }
        }
        if (t)
        {
            p.push_back(i);
            break;
        }
    }
    cout << min(1ll * p[0] * p[1], 1ll * p[0] * p[0] * p[0]) << "\n";
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