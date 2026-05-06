#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin >> n;
    vector <long long> s(n);
    vector <long long> p(n);

    for(long long i = 0; i < n; i++){
        cin >> s[i];
        p[i] = i + 1;
    }

    long long l = 0;
    long long r = 0;
    bool flag = true;

    while(l < n){
        r = l;
        while (r + 1 < n && s[r] == s[r + 1]) r++;

        if (l == r) {
            flag = false;
            break;
        }

        rotate(p.begin() + l, p.begin() + l + 1, p.begin() + r + 1);

        l = r + 1;
    }
    if (flag){
        for(long long val : p){
            cout << val << " ";
        }
        cout << "\n";
    }
    else {
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