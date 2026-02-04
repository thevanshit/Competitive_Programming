#include <bits/stdc++.h>
using namespace std;

bool comp(pair<char,int> a, pair<char,int> b) {
    return a.second < b.second;
}

void solve(){
    long long n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char,int> freq;
    for (char c : s) {
        freq[tolower(c)]++;
    }

    vector<int> counts;
    for (auto &p : freq) {
        counts.push_back(p.second);
    }

    sort(counts.begin(), counts.end(), greater<int>());

    int ans = counts[0];
    if (counts.size() >= 2)
        ans += counts[1];

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