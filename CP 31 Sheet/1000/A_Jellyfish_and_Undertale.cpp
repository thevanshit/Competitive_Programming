#include <bits/stdc++.h>
using namespace std;
 
 
void solve(){
    long long a;
    long long b;
    long long n;
    cin >> a >> b >> n;
    vector <int> arr(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long seconds = b;
 
    for(int i = 0; i < n; i++){
        seconds += min(arr[i], (int) (a - 1));
    }
 
    cout << seconds << endl;
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