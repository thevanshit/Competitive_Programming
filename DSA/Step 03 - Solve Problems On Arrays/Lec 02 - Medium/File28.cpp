#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> &vec) {
    for (auto Itr : vec) {
        cout << Itr << " ";
    }
    cout << endl;
}

void AlternativeSort(vector<int> &vec) {
    
    vector <int> posvec;
    vector <int> negvec;
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i] > 0){
            posvec.push_back(vec[i]);
        }
        else {
            negvec.push_back(vec[i]);
        }
    }
    if(negvec.size() < posvec.size()){
        for (int i = 0; i < negvec.size(); i++)
        {
            vec[2*i] = posvec[i];
            vec[2*i+1] = negvec[i];
        }
        int index = 2 * negvec.size();
        for (int i = negvec.size(); i < posvec.size(); i++)
        {
            vec[index] = posvec[i];
            index++;
        }
        
    }
    else {
        for (int i = 0; i < posvec.size(); i++)
        {
            vec[2*i] = posvec[i];
            vec[2*i+1] = negvec[i];
        }
        int index = 2 * posvec.size();
        for (int i = posvec.size(); i < negvec.size(); i++)
        {
            vec[index] = negvec[i];
            index++;
        }
        
    }
}

int main() {
    vector<int> vec = {-3, 1, -2, -5, 2, -4};

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    AlternativeSort(vec);

    cout << "The given Vector Array (After Alternative Sort) is:\n";
    PrintTheArray(vec);
    return 0;
}