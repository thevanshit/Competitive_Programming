#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

int longestAlternating(const string& s, char start) {
    int endSame = 0;  
    int endOther = 0; 
    for (char c : s) {
        if (c == start) {
            endSame = max(endSame, endOther + 1);
        } else if (endSame > 0) {
            endOther = max(endOther, endSame + 1);
        }
    }
    return max(endSame, endOther);
}

int largestEven(int L) {
    if (L < 2) return -1;
    return (L % 2 == 0) ? L : L - 1;
}

int largestOdd(int L) {
    if (L < 1) return -1;
    return (L % 2 == 1) ? L : L - 1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for (char c : s) {
        if (c == '0') cnt0++;
        else cnt1++;
    }
    int d = cnt0 - cnt1;

    int L0 = longestAlternating(s, '0');
    int L1 = longestAlternating(s, '1');

    int best = -1;

    if (abs(d) <= 1) {
        best = max(best, largestEven(L0));
        best = max(best, largestEven(L1));
        best = max(best, 0);  
    }
    
    if (d >= 0 && d <= 2) {
        best = max(best, largestOdd(L0));
    }

    if (d >= -2 && d <= 0) {
        best = max(best, largestOdd(L1));
    }

    cout << (best == -1 ? -1 : n - best) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
}