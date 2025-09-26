#include<iostream>
#include<stack>
using namespace std;

class SortStackObject {
    private: 
        stack<int> st;
    public:
        SortStackObject() {
            st.push(9);
            st.push(4);
            st.push(8);
            st.push(2);
            st.push(5);
        }
        void printStack() {
            stack<int> ref = st;
            while(!ref.empty()) {
                cout << ref.top() << " ";
                ref.pop();
            }
            cout << endl;
        }
        void insertSortedOrder(int ele) {
            // when stack is empty, we push the element
            // and also when the upcoming element greater than the top of the stack then push
            if(st.empty() || st.top() < ele) {
                st.push(ele);
                return;
            }
            int top = st.top();
            st.pop();
            insertSortedOrder(ele);
            st.push(top);
        }
        void sortStack() {
            // base case : when stack is empty
            if(st.empty()) return;
            // take stack.top() value and keep it outside of the stack
            int top = st.top();
            st.pop();
            // do this process until stack becomes empty 
            sortStack();
            // when base case reached, we are inserting element in such a way that 
            // all the element in stack should be in sorted order;
            // this function first will be reached when stack becomes empty()
            // assume stack : [9, 4, 8, 2] ---> top() = 9
            insertSortedOrder(top);
        }
};


int main() {
    SortStackObject myStack = SortStackObject();
    myStack.printStack();
    myStack.sortStack();
    myStack.printStack();
}