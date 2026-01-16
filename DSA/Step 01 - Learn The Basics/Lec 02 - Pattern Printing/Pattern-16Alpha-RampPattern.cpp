#include <bits/stdc++.h>
using namespace std;

void pattern16(int N)
{
      for(int i=0;i<N;i++){

          char ch = 'A'+i;
          for(int j=0;j<=i;j++){
            
            cout<<ch<<" ";
              
          }
          cout<<endl;
          
      }
}

int main()
{   
    int N = 5;
    pattern16(N);

    return 0;
}