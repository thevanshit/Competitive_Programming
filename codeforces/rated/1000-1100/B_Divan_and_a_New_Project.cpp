#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<long long, long long> &a, 
    const pair<long long, long long> &b){
    return a.second > b.second;
}

void solve(){
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for(long long i = 0; i < n; i++) {
        cin >> a[i].second;
        a[i].first = i + 1;
    }
    sort(a.begin(), a.end(), comp);

    vector <long long> x(n + 1);
    x[0] = 0;
    long long dist = 1;
    bool right = true;

    long long total = 0;

    for(auto &[idx, visits] : a){
        long long pos = right ? dist : -dist;
        x[idx] = pos;

        total += 2 * (visits * llabs(pos));
        if (!right) dist++;
        right = !right;
    }
    cout << total << "\n";
    for(int idx : x){
        cout << idx << " ";
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