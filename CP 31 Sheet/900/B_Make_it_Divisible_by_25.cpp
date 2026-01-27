#include <bits/stdc++.h>
using namespace std;

const string subseq[] = {"00", "25", "50", "75"};
const int INF = 100;

int operators(string &s, string &t){
    int seprator = s.length() - 1;

    int result = 0;
    while(seprator >= 0 && s[seprator] != t[1]){
        seprator--;
        result++;
    }

    if (seprator < 0) return INF;

    seprator--;

    while(seprator >= 0 && s[seprator] != t[0]){
        seprator--;
        result++;
    }

    return seprator < 0 ? INF : result;
}

void solve(){
    string n;
    cin >> n;

    int ans = INF;
    for (auto e : subseq){
        ans = min(ans, operators(n, e));
    }

    cout << ans << endl;
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