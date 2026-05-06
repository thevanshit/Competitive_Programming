#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s;
    cin >> s;

    long long cnt0 = 0;
    long long cnt1 = 0;

    for(long long i = 0; i < s.size(); i++){
        if (s[i] == '1') cnt1++;
        else cnt0++;
    }

    long long length_of_string_t = 0;
    for(long long i = 0; i < s.size(); i++){
        if (s[i] == '0' && cnt1 > 0){
            cnt1--;
            length_of_string_t++;
        }
        else if(s[i] == '1' && cnt0 > 0){
            cnt0--;
            length_of_string_t++;
        }
        else {
            break;
        }
    }

    cout << s.size() - length_of_string_t << endl;
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