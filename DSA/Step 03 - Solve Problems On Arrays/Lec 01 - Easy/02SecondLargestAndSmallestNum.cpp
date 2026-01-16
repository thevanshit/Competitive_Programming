#include <iostream>
#include <vector>
using namespace std;

void SecondLargestNum (vector <int> &vec){

    int largest = vec[0];
    int slargest = INT_MIN;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > largest){

            slargest = largest;
            largest = vec[i];
        }
        else if (vec[i] < largest && vec[i] > slargest)
        {
            slargest = vec[i];
        }
        
    }
    cout << "The Second Largest Element in the array is ; " << slargest << endl;
}


void SecondSmallestNum (vector <int> &vec){

    int smallest = vec[0];
    int ssmallest = INT_MAX;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < smallest){

            ssmallest = smallest;
            smallest = vec[i];
        }
        else if (vec[i] > smallest && vec[i] < ssmallest)
        {
            ssmallest = vec[i];
        }
        
    }
    cout << "The Second Largest Element in the array is ; " << ssmallest ;
}

int main () {

    vector <int> vec;
    vec = {1, 4, 5, 3, 7, 7, 6};

    SecondLargestNum(vec);
    SecondSmallestNum(vec);

    return 0;
}