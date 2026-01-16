#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray (vector <int> &vec){
    for(auto It : vec){
        cout << It << " ";
    }
    cout << endl;
}

int MaximumElement(vector<int> &vec) {
    int n;
    n = vec.size();
    for (int  i = 0; i < n; i++)
    {
        int count;
        count = 0;
        for (int j = i; j < n; j++)
        {
            if(vec[i] == vec[j]){
                count++;
            }
        }
        if (count > n/2){
            return vec[i];
        }
    }
    return -1;
}

int main()
{
    vector <int> vec;
    vec = {2, 2, 3, 3, 1, 2, 2};
    cout << "The Given Vector Array is : " << endl;
    PrintTheArray(vec);

    MaximumElement(vec);

    int MaxiElement;
    MaxiElement = MaximumElement(vec);
    cout << "The Element Occuring More than N/2 the given Vector Array is : " << MaxiElement << endl;
    return 0;
}
