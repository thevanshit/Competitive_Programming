#include <bits/stdc++.h>
using namespace std;

void pattern17(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << "  ";
        }
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch << " ";
            if (j <= breakpoint) ch++;
            else ch--;
        }
        
        for (int j = 0; j < N - i - 1; j++)
        {
            cout << "  ";
        }
        
        cout << endl;
    }
    
}

int main()
{   
    int N = 5;
    
    pattern17(N);

    return 0;
}