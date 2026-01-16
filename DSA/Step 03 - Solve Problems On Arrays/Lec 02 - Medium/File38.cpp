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
    
    // vector <int> col (vec[0].size(),0);
    // vector <int> row (vec.size(),0);

    int col0 = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == 0)
            {
                vec[i][0] = 0;
                if (j != 0){
                    vec[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
            
        }
        
    }

    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 1; j < vec[0].size(); j++)
        {
            if (vec[i][j] != 0){

                if (vec[i][0] == 0 || vec[0][j] == 0){
                    vec[i][j] = 0;
                }
            }
        }
        
    }
    if (vec[0][0] == 0){
        for (int j = 0; j < vec[0].size(); j++)
        {
            vec[0][j] = 0;
        }
        
    }
    if (col0 == 0){
        for (int i = 0; i < vec.size(); i++)
        {
            vec[i][0] = 0;
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