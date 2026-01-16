#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector <long long> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    if (a.size() == 1){
        cout << 0 << endl;
        return;
    }

    long long cnt = 0;

    for(long long k = n - 2; k >= 0; k--){
        while (a[k + 1] <= a[k] && a[k] > 0){
            a[k] /= 2;
            cnt++;
        }
        if (a[k] == a[k + 1]){
            cout << -1 << endl;
            return;
        }
    }

    cout << cnt << endl;
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