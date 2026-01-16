#include <iostream>
#include <vector>
using namespace std;

void DisplayElements (vector <vector<int>> &vec){
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main (){

    vector <vector<int>> vec;
    vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "The Given 2D Vector Array is : " << endl;
    DisplayElements(vec);

    return 0;
}