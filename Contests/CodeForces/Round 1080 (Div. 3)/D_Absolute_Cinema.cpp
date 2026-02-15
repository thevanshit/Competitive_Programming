#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    vector <long long> A(n + 1);
    for(long long i = 1; i <= n; i++){
        cin >> A[i];
    }

    vector <long long> d(n + 1);
    for(long long i = 1; i < n; i++)
        d[i] = A[i+1] - A[i];

    vector <long long> a(n+1);
    for(long long i = 2; i < n; i++)
        a[i] = (d[i] - d[i-1]) / 2;

    long long sum_mid = 0;
    for(long long i = 2; i < n; i++)
        sum_mid += a[i];

    long long total = (d[n-1] + d[1]) / 2 + sum_mid;
    a[1] = (d[1] + total) / 2;
    a[n] = (total - d[n-1]) / 2;

    for(long long i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
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