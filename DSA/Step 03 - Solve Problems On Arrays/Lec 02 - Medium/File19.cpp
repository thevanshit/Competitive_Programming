#include <iostream>
#include <vector>
#include <map>
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
    int count = 0;
    int el;
    for (int i = 0; i < n; i++)
    {
        if (count == 0){
            count = 1;
            el = vec[i];
        }
        else if (vec[i] == el){
            count++;
        }
        else{
            count--;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] == el){
            cnt++;
        }
    }
    if (cnt > n/2)
    {
        return el;
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
