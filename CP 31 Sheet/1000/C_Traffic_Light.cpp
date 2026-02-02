#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    s += s;
    n += n;

    long long last_green_seen = -1;
    long long max_second = LLONG_MIN;
    for(long long ch = n - 1; ch >= 0; ch--){
        if (s[ch] == 'g'){
            last_green_seen = ch;
        }
        if (s[ch] == c){
            long long diff = last_green_seen - ch;
            max_second = max(max_second, diff);
        }
    }

    cout << max_second << "\n";
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