#include <iostream>
#include <string>
using namespace std;

class Node {
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
    if (vec.empty()) return nullptr;

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
Node* DeleteKthElement (Node* Head, int val){
    if (Head == nullptr || Head -> next == nullptr) return nullptr;

    Node* temp = Head;
    while (temp -> next != nullptr){
        if (temp -> next -> data == val){
            Node* DelNode = temp -> next;
            temp -> next = temp -> next -> next;
            delete(DelNode);
            DelNode = nullptr;
        }
        temp = temp -> next;
    }
    return Head;
}
int main (){
    vector <int> vec = {1, 2, 3, 4, 5};
    int val = 3;
    Node* Head = ConvertArrayToLL(vec);
    Head = DeleteKthElement(Head,val);
    Node* temp = Head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
    return 0;
}