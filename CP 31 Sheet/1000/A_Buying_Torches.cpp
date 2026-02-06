#include <bits/stdc++.h>
using namespace std;

long long ceil_division(long long a, long long b) {
	return (a + b - 1) / b;
}

void solve(){
    long long x, y, k;
    cin >> x >> y >> k;

    long long sticks_needed = k * y + k - 1;
    long long sticks_gained_per_trade = x - 1;

    long long result = ceil_division(sticks_needed, sticks_gained_per_trade);

    cout << result + k << "\n";
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