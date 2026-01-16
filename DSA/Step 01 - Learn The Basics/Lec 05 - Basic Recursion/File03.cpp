#include <iostream>
using namespace std;

void func(int i, int n){
   
   // Base Condition.
   if(i>n) return;
   cout<<i<<" ";

   // Function call to print i till i increments to n.
   func(i+1,n);

}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 10;
  func(1,n);
  return 0;

}