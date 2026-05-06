#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long B, G, X, Y, N;
    cin >> B >> G >> X >> Y >> N;

    if (X + Y > N) {
        cout << -1 << "\n";
        return;
    }

    long long R = (B + G + N - 1) / N; 

    if (B >= R * X && G >= R * Y) {
        cout << R << "\n";
    } else {
        cout << -1 << "\n";
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