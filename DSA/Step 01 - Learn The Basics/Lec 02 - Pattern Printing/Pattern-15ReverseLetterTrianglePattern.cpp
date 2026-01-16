#include <bits/stdc++.h>
using namespace std;

void pattern15(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N; j > i; j--)
        {
            cout << char(65 + (N - j)) << " "; 
        }
        cout << endl;
    }
    
}

int main()
{
    int N = 5;
    pattern15(N);

    return 0;
}