#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    string K = "1";
    for(int i = 0; i < 100; i++) K.push_back('0');

    const int LOG = 350; 
    vector <vector<int>> up(LOG, vector<int>(N+1));

    for(int i = 1; i <= N; i++)
        up[0][i] = A[i];

    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= N; i++)
            up[j][i] = up[j-1][ up[j-1][i] ];

    vector<int> bits;
    while(!(K.size()==1 && K[0]=='0')) {

        int carry = 0;
        string next="";
        for(char c: K){
            int cur = carry*10 + (c-'0');
            next.push_back((cur/2)+'0');
            carry = cur%2;
        }

        bits.push_back(carry); 

        int pos=0;
        while(pos+1<(int)next.size() && next[pos]=='0') pos++;
        K = next.substr(pos);
    }

    for(int s=1;s<=N;s++){
        int cur = s;
        for(int j=0;j<(int)bits.size();j++){
            if(bits[j])
                cur = up[j][cur];
        }
        cout<< cur << " ";
    }
}
