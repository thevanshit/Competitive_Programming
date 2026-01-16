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
Node* ConvertArrayToLL(vector<int>& vec) {
    if (vec.empty()) return nullptr; // Handle empty vector case
    Node* Head = new Node(vec[0]);
    Node* Mover = Head;

    for (int i = 1; i < vec.size(); i++)
    {
        Node* temp = new Node(vec[i]);
        Mover -> next = temp;
        Mover = temp;
    }
    
    return Head;
}
Node* InsertHead(Node* Head, int val){
    Node* temp = new Node(val, Head);
    return temp;
}
int main (){
    vector <int> vec = {1, 2, 3, 4, 5};
    int target = 31;
    Node* Head = ConvertArrayToLL(vec);
    int val = 21;
    Node* NewHead = InsertHead(Head, val);
    Node* temp = NewHead;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
    return 0;
}