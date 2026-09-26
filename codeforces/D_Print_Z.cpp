#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    for(int i = 1; i <= 5; i++){
        cout << "*";
    }
    cout << "\n";
    for(int i = 1; i <= 3; i++){
        int cnt = 4;
        for(int j = 1; j <= 5; j++){
            if(j == cnt){
                cout << "*";
                cnt--;
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    for(int i = 1; i <= 5; i++){
        cout << "*";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}