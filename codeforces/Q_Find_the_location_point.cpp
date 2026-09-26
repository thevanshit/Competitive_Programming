#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int x, y;
    cin >> x >> y;

    if(x > 0 && y > 0){
        cout << "1st Quadrant\n";
    }
    else if(x < 0 && y > 0){
        cout << "2nd Quadrant\n";
    }
    else if(x < 0 && y < 0){
        cout << "3rd Quadrant\n";
    }
    else if(x > 0 && y < 0){
        cout << "4th Quadrant\n";
    }
    else if(x == 0 && y != 0){
        cout << "Y Axis\n";
    }
    else if(x != 0 && y == 0){
        cout << "X Axis\n";
    }
    else{
        cout << "Origin\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}