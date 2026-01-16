#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node (int val){
        data = val;
        right = left = nullptr;
    }
};

void PostOrder(Node* root, vector<int> &arr){
    if(root == nullptr){
        return;
    }
    PostOrder(root->left, arr);
    PostOrder(root->right, arr);
    arr.push_back(root->data);
}

vector<int> Postorder(Node* root){
    vector<int> arr;
    PostOrder(root, arr);
    return arr;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = Postorder(root);

    cout << "Post Order Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}