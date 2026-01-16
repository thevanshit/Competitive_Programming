#include <bits/stdc++.h>
using namespace std;

void pattern19(int N)
{
    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j < N - i; j++)
            cout << "* ";
        
        for (int j = 0; j < 2 * i; j++)
            cout << "  ";
        
        for (int j = 0; j < N - i; j++)
            cout << "* ";
        cout << endl;
    }

    
    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j <= i; j++)
            cout << "* ";
        
        for (int j = 0; j < 2 * (N - i - 1); j++)
            cout << "  ";
        
        for (int j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}

int main()
{
    int N = 5;
    pattern19(N);
    return 0;
}
