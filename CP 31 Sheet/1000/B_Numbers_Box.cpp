#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n, m;
    cin >> n >> m;
    vector <vector<long long>> a(n, vector<long long> (m, 0));
    long long neg_count = 0;
    long long min_ele = INT_MAX;
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            cin >> a[i][j];
            if (a[i][j] < 0){
                neg_count++;
            }
            sum += abs(a[i][j]);
            min_ele = min(min_ele, abs(a[i][j]));
        }
    }
    if(neg_count % 2 == 1){
        cout << sum - 2 * min_ele << "\n";
    }
    else{
        cout << sum << "\n";
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