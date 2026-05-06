#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    
    long long pXor;
    if (a % 4 == 1){
        pXor = a - 1;
    }
    else if (a % 4 == 2){
        pXor = 1;
    }
    else if (a % 4 == 3){
        pXor = a;
    }
    else{
        pXor = 0;
    }
 
    if (pXor == b){
        cout << a << "\n";
    }
    else if ((pXor ^ b) != a){
        cout << a + 1 << "\n";
    }
    else {
        cout << a + 2 << "\n";
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