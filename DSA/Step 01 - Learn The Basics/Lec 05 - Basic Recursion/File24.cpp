#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of N : ";
    cin >> n;

    vector <int> vec(n);

    vec[0] = 0;
    vec[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        vec[i] = vec[i-1] + vec[i-2];
    }
    
    for (int i = 0; i <= n; i++)
    {
        cout << vec[i] << " ";
    }
    
}