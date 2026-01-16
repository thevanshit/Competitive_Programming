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
Node* DeleteKthElement (Node* Head, int k){
    if (Head == nullptr || Head -> next == nullptr) return nullptr;

    // Case 1: deleting head
    if (k == 1) {
        Node* temp = Head;
        Head = Head->next;
        delete temp;
        return Head;
    }
    // Case 2: delete middle or last node
    Node* temp = Head;
    int count = 1;
    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }

    // If k is out of range
    if (temp == nullptr || temp->next == nullptr) {
        return Head;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return Head;
}
int main (){
    vector <int> vec = {1, 2, 3, 4, 5};
    int k = 3;
    Node* Head = ConvertArrayToLL(vec);
    Head = DeleteKthElement(Head,k);
    Node* temp = Head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
    return 0;
}