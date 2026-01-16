#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<vector <int>> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> GetSpiralOrder(vector<vector <int>> &vec) {
    vector<int> result;
    int top = 0;
    int bottom = vec.size() - 1;
    int left = 0;
    int right = vec[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse Top Row
        for (int i = left; i <= right; i++) {
            result.push_back(vec[top][i]);
        }
        top++;

        // Traverse Right Column
        for (int i = top; i <= bottom; i++) {
            result.push_back(vec[i][right]);
        }
        right--;

        // Traverse Bottom Row (if not same as top)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(vec[bottom][i]);
            }
            bottom--;
        }

        // Traverse Left Column (if not same as right)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(vec[i][left]);
            }
            left++;
        }
    }

    return result;
}

void Print1DVector(vector<int> &vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector< vector <int>> vec = {
        {1, 2, 3, 4, 5, 6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 26, 9},
        {17, 30, 29, 28, 27, 10},
        {16, 15, 14, 13, 12, 11}
    };

    cout << "The given 2D Matrix is:\n";
    PrintTheArray(vec);

    vector<int> spiral = GetSpiralOrder(vec);

    cout << "The Spiral Order Traversal of the Matrix is:\n";
    Print1DVector(spiral);

    return 0;
}