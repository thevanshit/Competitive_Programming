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

void SetMatrixZero(vector<vector <int>> &vec) {
    
    vector <int> col (vec[0].size(),0);
    vector <int> row (vec.size(),0);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == 0)
            {
                col[j] = 1;
                row[i] = 1;
            }
            
        }
        
    }
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (row[i] || col[j])
            {
                vec[i][j] = 0;
            }
            
        }
        
    }
    
    
}

int main() {
    vector< vector <int>> vec = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1 , 1}
    };

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    SetMatrixZero(vec);

    cout << "The (After Setting the Matrix to Zero) in the Array is : " << endl;
    PrintTheArray(vec);
    return 0;
}