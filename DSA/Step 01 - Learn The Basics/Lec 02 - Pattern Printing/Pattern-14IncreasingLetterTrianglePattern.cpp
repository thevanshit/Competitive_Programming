#include <bits/stdc++.h>
using namespace std;

void pattern14(int N)
{
      for(int i=0;i<N;i++){

          for(char ch = 'A'; ch<='A'+i;ch++){
              cout<<ch<<" ";
              
          }
          cout<<endl;
          
      }
}

int main()
{   
    // Here, we have taken the value of N as 5.
    // We can also take input from the user.
    int N = 5;
    pattern14(N);

    return 0;
}