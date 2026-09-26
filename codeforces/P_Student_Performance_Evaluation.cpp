#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n;
    cin >> n;

    if(n > 90){
        cout << "Excellent\n";
    }
    else if(n > 80){
        cout << "Good\n";
    }
    else if(n > 70){
        cout << "Fair\n";
    }
    else if(n > 60){
        cout << "Meets Expectations\n";
    }
    else{
        cout << "Below Par\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}