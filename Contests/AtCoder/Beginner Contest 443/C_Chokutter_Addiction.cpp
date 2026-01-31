#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long N;
    long long T;

    cin >> N >> T;

    if (N == 0){
        cout << T << "\n";
        return;
    }

    long long curr_time = 0;
    long long total = 0;
    for (long long i = 0; i < N; i++){
        long long pass_time;
        cin >> pass_time;

        if (curr_time >= T) break;

        if (pass_time > curr_time){
            total += min(T, pass_time) - curr_time;
            curr_time = pass_time + 100;
        }
    }

    if (curr_time < T){
        total += T - curr_time;
    }

    cout << total << "\n";
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}