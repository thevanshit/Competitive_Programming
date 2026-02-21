#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    string s;
    cin >> s;

    long long ones = 0;
    for(char c : s)
        if(c == '1') ones++;

    long long zeros = n - ones;

    if(ones % 2 == 0) {
        if (ones == 0) {
            cout << 0 << "\n";
            return;
        }
        vector<long long> ops;
        for(long long i = 0; i < n; i++) {
            if(s[i] == '1')
                ops.push_back(i + 1);
        }
        cout << ops.size() << "\n";
        for(long long i : ops) cout << i << " ";
        cout << "\n";
        return;
    }

    if(zeros % 2 == 1) {  
        vector<long long> ops;
        for(long long i = 0; i < n; i++) {
            if(s[i] == '0')
                ops.push_back(i + 1);
        }
        cout << ops.size() << "\n";
        for(long long i : ops) cout << i << " ";
        cout << "\n";
        return;
    }

    cout << -1 << "\n";
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