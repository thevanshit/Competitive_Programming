#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> vec) {
    for (auto Itr = vec.begin(); Itr < vec.end(); Itr++) {
        cout << *Itr << " ";
    }
    cout << endl;
}

void Merge(vector <int> &vec,int low,int mid,int high){

    vector <int> temp;

    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){

        if (vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else{
            temp.push_back(vec[right]);
            right++;
        }
        
    }
    while (left <= mid)
    {
        temp.push_back(vec[left]);
        left++;
    }
    while (right <= high){
        temp.push_back(vec[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        vec[i] = temp[i - low];
    }
    
}

void MergeSort(vector<int> &vec,int low,int high) {
    
    if (low >= high){
        return;
    }
    int mid = (low + high) / 2;
    MergeSort(vec,low,mid);
    MergeSort(vec,mid+1,high);

    Merge(vec,low,mid,high);
    
}

int main() {
    vector<int> vec = {3, 1, 2, 4, 1, 5, 2, 6, 4};

    int low = 0;
    int high = vec.size()-1;

    cout << "Before Merge Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);

    MergeSort(vec,low,high);

    cout << "After Merge Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);

    return 0;
}