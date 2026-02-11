#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){

    int N,K;
    cin>>N>>K;

    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];

    vector<pair<ll,int>> v;
    for(int i=0;i<N;i++)
        v.push_back({A[i], i+1});

    sort(v.begin(), v.end());

    set<int> idx;

    // check feasibility
    auto valid = [&]() -> bool {

    if(idx.empty()) return false;

    // start coverage
    if(*idx.begin() > K) return false;

    // end coverage
    if(*idx.rbegin() < N-K+1) return false;

    auto it = idx.begin();
    int prev = *it;
    ++it;

    // check coverage gaps
    for(; it!=idx.end(); ++it){

        if(*it - prev > K)
            return false;

        prev = *it;
    }

    return true;
};


    ll ans = 0;

    int l=0;

    for(int r=0;r<N;r++){

        idx.insert(v[r].second);

        while(l<=r){

            if(valid()){
                ans = max(ans, v[r].first - v[l].first);
                idx.erase(v[l].second);
                l++;
            }
            else break;
        }
    }

    cout<<ans<<"\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}
