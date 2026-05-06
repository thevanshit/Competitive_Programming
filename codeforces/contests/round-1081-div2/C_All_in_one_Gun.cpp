#include <bits/stdc++.h>
using namespace std;

void solve() {

    long long n,h,k;
    cin>>n>>h>>k;

    vector<long long>a(n);
    for(auto &x:a) cin>>x;

    vector<long long> pref(n+1,0);
    for(int i=0;i<n;i++)
        pref[i+1]=pref[i]+a[i];

    long long S = pref[n];
    long long best_prefix = LLONG_MAX;

    for(int i=1;i<=n;i++)
        if(pref[i] >= h){
            best_prefix = i;
            break;
        }
    long long need = h;
    long long base_time = 0;

    if(best_prefix == LLONG_MAX){

        need -= S;
        base_time += n;

        long long cycle_time = n + k;

        long long cycles = need / S;
        base_time += cycles * cycle_time;
        need -= cycles * S;

        if(need <= 0){
            cout<<base_time<<"\n";
            return;
        }

        base_time += k;
    }else{
        need = h;
        base_time = 0;
    }

    vector<long long> prefix_min(n+1);
    vector<long long> suffix_max(n+2);

    prefix_min[0] = LLONG_MAX;
    for(int i=1;i<=n;i++)
        prefix_min[i] = min(prefix_min[i-1], a[i-1]);

    suffix_max[n] = LLONG_MIN;
    for(int i=n-1;i>=0;i--)
        suffix_max[i] = max(suffix_max[i+1], a[i]);

    long long best_p = LLONG_MAX;

    for(int p=1;p<=n;p++){

        if(pref[p] >= need){
            best_p = p;
            break;
        }

        if(p<n){
            long long gain = suffix_max[p] - prefix_min[p];
            if(pref[p] + gain >= need){
                best_p = p;
                break;
            }
        }
    }

    cout << base_time + best_p << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}