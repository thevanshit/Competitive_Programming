#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    long long k;

    cin >> n >> k;

    vector <long long> a(n * k);
    for(long long i = 0; i < (n * k); i++){
        cin >> a[i];
    }
    long long factor;
    if (n % 2 == 0)
        factor = ceil((n * 1.0) / 2) + 1;
    else
        factor = ceil((n * 1.0) / 2);

    long long sum_of_median = 0;
    long long start = n * k - (factor);
    while(k--){
        sum_of_median += a[start];
        start -= factor;
    }

    cout << sum_of_median << endl;
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