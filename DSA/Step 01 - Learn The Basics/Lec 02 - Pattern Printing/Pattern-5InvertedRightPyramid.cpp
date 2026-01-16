#include <bits/stdc++.h>
using namespace std;

void pattern5(int N)
{
    for (int i = N; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout <<"* ";
        }
        cout << endl;
    }
}

int main()
{   
    int N = 5;

    pattern5(N);

    return 0;
}