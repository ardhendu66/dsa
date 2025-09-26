#include <iostream>
#include <stack>
using namespace std;

/**
 * [9, 3, 5, 7] ⟶ stack.top() = 9.
 * so my job is to just reverse 9, recursion will reverse rest, hence I took 9 from stack 
 * and give it to the recursion, recursion gives me reversed_stack. and then I put 9 bottom
 * of the stack and hence full stack reversed. 
*/

void insert_at_bottom(stack<int>& st, int ele) {
    // base case
    if(st.empty()) {
        st.push(ele);
        return;
    }
    int top = st.top();
    st.pop();
    insert_at_bottom(st, ele);
    st.push(top);
}

void reverseStack(stack<int>& myStack) {
    // base case
    if(myStack.empty()) {
        return;
    }
    int top = myStack.top();
    myStack.pop();
    reverseStack(myStack);
    // inserting top element bottom of the stack
    insert_at_bottom(myStack, top);
}

void print_Stack(stack<int>& st) {
    stack<int> myStack = st;
    cout << "Stack : ";
    while(!myStack.empty()) {
        cout << myStack.top() << "  ";
        myStack.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(9);
    st.push(3);
    st.push(5);
    st.push(7);
    print_Stack(st);
    reverseStack(st);
    print_Stack(st);
}