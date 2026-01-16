#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<vector <int>> &vec) {
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    
}

void MarkRow (vector <vector<int>> &vec, int i){

    for (int j = 0; j < vec[0].size(); j++)
    {
        if (vec[i][j] != 0){
            vec[i][j] = -1;
        }
    }
    
}

void MarkCol (vector <vector<int>> &vec, int j){

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i][j] != 0){
            vec[i][j] = -1;
        }
    }
    
}

void SetMatrixZero(vector<vector <int>> &vec) {
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == 0)
            {
                MarkCol(vec,j);
                MarkRow(vec,i);
            }
            
        }
        
    }
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == -1)
            {
                vec[i][j] = 0;
            }
            
        }
        
    }
    
    
}

int main() {
    vector< vector <int>> vec = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    SetMatrixZero(vec);

    cout << "The (After Setting the Matrix to Zero) in the Array is : " << endl;
    PrintTheArray(vec);
    return 0;
}