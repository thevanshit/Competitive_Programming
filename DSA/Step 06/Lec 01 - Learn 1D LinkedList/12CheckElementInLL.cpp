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
bool CheckElementInLL(Node* Head, int target){
    bool present = false;
    Node* temp = Head;
    while(temp){
        if (temp -> data == target) present = true;
        temp = temp -> next;
    }
    return present;
}
int main (){
    vector <int> vec = {1, 2, 3, 4, 5};
    int target = 31;
    Node* Head = ConvertArrayToLL(vec);
    Node* temp = Head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
    if (CheckElementInLL(Head,target))
    cout << "Element is present in LL." << endl;
    else 
    cout << "Element is'nt present in LL." << endl;
    return 0;
}