#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 1; i < int(s.size()); ++i) {
		if (s[i] < s[i - 1]) {
			cout << "YES" << endl;
			cout << i << " " << i + 1 << endl;
			return;
		}
	}

    cout << "NO" << "\n";
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}