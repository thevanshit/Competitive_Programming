#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Push elements
    for (int i = 1; i <= 5; ++i) {
        st.push(i);  // or st.emplace(i);
    }

    // Display top element
    cout << "Top element of stack: " << st.top() << endl;

    // Display all elements (by popping)
    cout << "Stack elements (LIFO): ";
    stack<int> temp = st;  // make copy to print safely
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Size of the stack
    cout << "Size of stack: " << st.size() << endl;

    // Check if stack is empty
    if (st.empty())
        cout << "The stack is empty" << endl;
    else
        cout << "The stack is not empty" << endl;

    // Pop the top element
    st.pop();
    cout << "After one pop, top element: " << st.top() << endl;

    // Swap with another stack
    stack<int> st2;
    st2.push(100);
    st2.push(200);
    st.swap(st2);

    // After swap, display top of each stack
    cout << "After swapping:\n";
    cout << "st top: " << st.top() << endl;
    cout << "st2 top: " << st2.top() << endl;

    // Clear the stack manually
    while (!st.empty()) {
        st.pop();
    }
    cout << "Size of st after clearing: " << st.size() << endl;

    return 0;
}