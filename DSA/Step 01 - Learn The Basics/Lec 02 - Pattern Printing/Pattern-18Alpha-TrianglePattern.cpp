#include <bits/stdc++.h>
using namespace std;

void pattern18(int N)
{
    for (int i = 1; i <= N; i++)
    {
        char ch = 'A' + N - i;
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
    
}

int main()
{   
    int N = 5;
    
    pattern18(N);

    return 0;
}
