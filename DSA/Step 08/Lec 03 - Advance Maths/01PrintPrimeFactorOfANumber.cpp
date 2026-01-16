#include <bits/stdc++.h>
using namespace std;

bool PrimeCheck(int num){
    bool isPrime = true;
    for(int i = 2; i <= sqrt(num); i++){
        if (num % i == 0){
            isPrime = false;
        }
    }
    return isPrime;
}

int main(){
    int num = 780;
    vector <int> PrimeFactor;

    for(int i = 2; i * i <= num; i++){
        if (num % i == 0){
            if(PrimeCheck(i)){
                PrimeFactor.push_back(i);
            }
            if (PrimeCheck(num / i) && (num / i) != i){
                PrimeFactor.push_back(num / i);
            }
        }
    }

    for(auto ele : PrimeFactor){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}