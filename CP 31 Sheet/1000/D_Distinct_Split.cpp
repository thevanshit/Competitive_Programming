#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector <int> cnt(26, 0), p(26, 0);
    for(char ch : s) cnt[ch - 'a']++;
    int result = 0;
    for(char ch : s){
        cnt[ch - 'a']--;
        p[ch - 'a']++;
        int curr = 0;
        for(int i = 0; i < 26; i++){
            curr += min(1, cnt[i]) + min(1, p[i]);
        }
        result = max(curr, result);
    }

    cout << result << "\n";
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