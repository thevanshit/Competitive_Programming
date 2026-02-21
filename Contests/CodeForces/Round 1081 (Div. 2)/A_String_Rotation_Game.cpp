#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    string s;
    cin >> s;

    int circular_changes = 0;
    bool has_equal = false;

    for(int i = 0; i < n; i++) {
        if(s[i] != s[(i+1)%n]) {
            circular_changes++;
        } else {
            has_equal = true;
        }
    }

    int ans;

    if(circular_changes == 0) {
        ans = 1;  
    }
    else if(has_equal) {
        ans = circular_changes + 1;
    }
    else {
        ans = circular_changes;
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