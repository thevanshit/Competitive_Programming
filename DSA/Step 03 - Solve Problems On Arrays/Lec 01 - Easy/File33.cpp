#include <iostream>
#include <vector>
#include <set>
using namespace std;

void PrintTheArray(vector <int> vec){

    for (auto Itr : vec)
    {
        cout << Itr << " ";
    }
    cout << endl;
}

vector <int> FindTheIntersection(vector <int> &vec1,vector <int> &vec2){

    
    vector <int> VisitedVec(vec2.size());
    vector <int> IntersectedVec;
    
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec2.size(); j++)
        {
            if (vec1[i] == vec2[j] && VisitedVec[j] == 0)
            {
                IntersectedVec.push_back(vec1[i]);
                VisitedVec[j] = 1;
                break;
            }
            
        }
        
    }
    
    
    return IntersectedVec;
}

int main (){


    vector <int> vec1;
    vec1 = {1, 1, 2, 3, 4, 4, 5};
    cout << "The Given 1st Vector Array is : " << endl;
    PrintTheArray(vec1);

    vector <int> vec2;
    vec2 = {2, 3, 4, 4, 5, 6};
    cout << "The Given 2nd Vector Array is : " << endl;
    PrintTheArray(vec2);

    vector <int> ResultVec;
    cout << "The Resultant Vector Array is : " << endl;
    ResultVec = FindTheIntersection(vec1,vec2);

    PrintTheArray(ResultVec);
}