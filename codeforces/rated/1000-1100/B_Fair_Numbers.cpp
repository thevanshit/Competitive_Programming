#include <bits/stdc++.h>
using namespace std;

bool satisfy(long long x){
    long long num = x;
    set <long long> digits;
    while(num){
        long long rem = num % 10;
        if (rem != 0) digits.insert(rem);
        num /= 10;
    }
    num = x;
    bool satisfy = true;
    for(auto &val : digits){
        if (num % val != 0){
            satisfy = false;
            break;
        }
    }
    return satisfy;
}

void solve(){
    long long n;
    cin >> n;

    long long ans = n;

    for(long long i = n; ;i++){
        bool flag = satisfy(i);
        if (flag) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
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