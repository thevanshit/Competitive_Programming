#include <bits/stdc++.h>
using namespace std;

void pattern12(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        for (int j = 1; j <= (2 * N) - (2 * i); j++)
        {
            cout << "  ";
        }
        for(int j = i; j > 0; j--)
        {
            cout << j << " ";
        }

        cout << endl;

    }
    
}

int main()
{   
    int N = 5;
    pattern12(N);

    return 0;
}