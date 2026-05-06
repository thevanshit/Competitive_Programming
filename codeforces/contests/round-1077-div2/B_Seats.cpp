#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ones = 0;
    for (char c : s) if (c == '1') ones++;

    int added = 0;

    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            i++;
            continue;
        }

        int j = i;
        while (j < n && s[j] == '0') j++;
        int L = j - i;

        bool has_adjacent_one =
            (i > 0 && s[i - 1] == '1') ||
            (j < n && s[j] == '1');

        if (has_adjacent_one) {
            added += max(0, (L - 1 + 2) / 3);   // ceil((L-1)/3)
        } else {
            added += (L + 2) / 3;               // ceil(L/3)
        }

        i = j;
    }

    cout << ones + added << '\n';
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