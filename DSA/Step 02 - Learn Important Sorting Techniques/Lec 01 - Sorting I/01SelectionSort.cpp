#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int>vec){

    for (auto Itr = vec.begin(); Itr < vec.end(); Itr++)
    {
        cout << *Itr << " ";
    }
    cout << endl;
}

void SelectionSort(vector <int> &vec){

    for (int i = 0; i < vec.size()-1; i++)
    {
        int mini = i;
        for (int j = i+1; j < vec.size(); j++)
        {
            if (vec[mini]>vec[j])
            {
                mini = j;
            }
            
        }
        swap (vec[mini],vec[i]);
    }
    
}

int main ()
{
    vector <int> vec;
    vec = {13, 46, 24, 52, 20, 9};
    cout << "Befor Selection Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);
    SelectionSort(vec);
    cout << "After Selection Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);
}