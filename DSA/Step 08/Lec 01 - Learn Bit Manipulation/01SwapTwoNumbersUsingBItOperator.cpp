#include <bits/stdc++.h>
using namespace std;


void solve(){
    int A = 12;
    int B = 15;
    cout << "Before Swapping" << " : " << A << " , "<< B << endl;
    A = A ^ B;
    B = A ^ B;
    A = A ^ B;
    cout << "After Swapping" << " : " << A << " , "<< B << endl;
}


int main(){
    solve();
    return 0;
}