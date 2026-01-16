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

void TransposeTheMatrix(vector<vector <int>> &vec){

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec[0].size(); j++)
        {
            swap(vec[i][j],vec[j][i]);
        }
    }
}

void ReverseTheMatrix(vector <int> &vec){

    int left = 0;
    int right = vec.size()-1;

    while(left < right){
        swap(vec[left],vec[right]);
        left++;
        right--;
    }
}

void RotateMatrixBy90(vector<vector <int>> &vec) {
    
    TransposeTheMatrix(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        ReverseTheMatrix(vec[i]);
    }
    
}

int main() {
    vector< vector <int>> vec = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "The given Vector Array is:\n";
    PrintTheArray(vec);

    RotateMatrixBy90(vec);

    cout << "The (After rotating the Matrix by 90) in the Array is : " << endl;
    PrintTheArray(vec);
    return 0;
}