#include <iostream>
#include <vector>
using namespace std;

int main (){

    pair <int,int> couple;
    couple = {69,96};
    cout << couple.first << " " << couple.second << endl;

    pair <int,char> couple1;
    couple1 = {69,'F'};
    cout << couple1.first << " " <<  couple1.second << endl;

    pair <int,pair <int,int>> couple2;
    couple2 = {69, {96,100}};
    cout << couple2.first << " " <<  couple2.second.second << endl;

    pair <int,int> arr[] = {{1,2},{4,6},{7,8}};
    cout << arr[1].first << endl;

    return 0;
}