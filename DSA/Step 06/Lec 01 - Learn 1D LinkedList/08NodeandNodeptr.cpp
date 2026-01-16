#include <iostream>
#include <string>
using namespace std;

class Node{
    public :
    int data;
    Node* next;
    public : 

    Node (int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node (int data1){
        data = data1;
        next = nullptr;
    }
};
int main (){
    vector <int> vec = {1, 2, 3, 4, 5};
    Node X = Node(vec[3], nullptr);
    Node* Y = &X;
    cout << Y << endl;
    cout << Y -> data << endl;
    return 0;
}