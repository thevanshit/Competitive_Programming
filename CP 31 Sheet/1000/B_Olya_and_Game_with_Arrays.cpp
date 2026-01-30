#include <bits/stdc++.h>
using namespace std;


using ll = long long;

void solve() {
    int n;
    cin >> n;

    ll global_min = LLONG_MAX;
    vector<ll> second_mins;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<ll> v(m);
        for (ll &x : v) cin >> x;

        sort(v.begin(), v.end());

        global_min = min(global_min, v[0]);
        second_mins.push_back(v[1]);
    }

    ll sum_second = 0;
    for (ll x : second_mins) sum_second += x;

    ll min_second = *min_element(second_mins.begin(), second_mins.end());

    ll answer = global_min + sum_second - min_second;
    cout << answer << endl;
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