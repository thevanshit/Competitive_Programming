#include <iostream>
#include <vector>
using namespace std;

void PrintTheArray(vector<int> vec) {
    for (auto Itr = vec.begin(); Itr < vec.end(); Itr++) {
        cout << *Itr << " ";
    }
    cout << endl;
}

int PartitionIndex(vector <int> &vec,int low,int high){

    int Pivot = vec[low];
    int i = low;
    int j = high;
    while (i < j){
        while(vec[i] <= Pivot && i < high){
            i++;
        }
        while(vec[j] > Pivot && j > low){
            j--;
        }
        if (i < j){
            swap(vec[i],vec[j]);
        }
    }
    swap (vec[low],vec[j]);
    return j;

}

void QuickSort(vector<int> &vec,int low,int high) {
   
    if (low < high){
        int PartNum = PartitionIndex(vec,low,high);

        QuickSort(vec,low,PartNum-1);
        QuickSort(vec,PartNum+1,high);
    }
    
}

int main() {
    vector<int> vec = {3, 1, 2, 4, 1, 5, 2, 6, 4};

    int low = 0;
    int high = vec.size()-1;

    cout << "Before Quick Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);

    QuickSort(vec,low,high);

    cout << "After Quick Sorting the Vector Array is : " << endl;
    PrintTheArray(vec);

    return 0;
}