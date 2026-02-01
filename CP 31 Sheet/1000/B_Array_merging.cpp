#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;

    vector <long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];
    vector <long long> b(n);
    for(long long i = 0; i < n; i++) cin >> b[i];

    unordered_map <long long, long long> bestA;
    unordered_map <long long, long long> bestB;
    
    for(long long i = 0; i < n; ){
        long long j = i;
        while(j < n && a[j] == a[i]) j++;
        bestA[a[i]] = max(bestA[a[i]], j - i);
        i = j;
    }
    for(long long i = 0; i < n; ){
        long long j = i;
        while(j < n && b[j] == b[i]) j++;
        bestB[b[i]] = max(bestB[b[i]], j - i);
        i = j;
    }

    long long result = 0;

    for(auto & p : bestA){
        result = max(result, bestA[p.first] + bestB[p.first]);
    }
    for(auto & p : bestB){
        result = max(result, bestA[p.first] + bestB[p.first]);
    }

    cout << result << "\n";
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