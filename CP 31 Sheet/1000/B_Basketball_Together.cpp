#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long N;
    long long D;

    cin >> N >> D;
    vector <long long> P(N);
    for(long long i = 0; i < N; i++) cin >> P[i];

    sort(P.begin(), P.end());

    long long left = -1;
    long long right = N - 1;
    long long team_size = 1;
    long long teams = 0;
    while(left < right){
        if (left < right && (P[right] * team_size) <= D){
            left++;
            team_size++;
        }
        else{
            right--;
            team_size = 1;
            teams++;
        }
    }

    cout << teams << "\n";
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