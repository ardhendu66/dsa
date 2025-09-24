#include<iostream>
#include<vector>
using namespace std;

class Stack {
    private:
        int* arr;
        int size;
        int top;
    public:
        Stack(int size) {
            this->size = size;
            this->arr = new int[size];
            this->top = -1;
        }
        void push(int ele) {
            if(this->top == this->size - 1) {
                cout << "Stack Overflow! : " << ele << " can't be pushed.\n";
                return;
            }
            arr[++this->top] = ele;
        }
        void pop() {
            if(this->top == -1) {
                cout << "Stack Underflow!\n";
                return;
            }
            this->top--;
            // cout << arr[top--] << " popped!\n";
        }
        int peek() {
            if(this->top == -1) {
                cout << "Stack is empty  ";
                return -1;
            }
            return arr[this->top];
        }
        bool empty() {
            return this->top == -1;
        }
};

void printStack(Stack st) {
    while(!st.empty()) {
        cout << st.peek() << "  ";
        st.pop();
    }
}

int main() {
    Stack st(5);
    cout << st.peek() << "\n";
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    printStack(st);

    return 0;
}