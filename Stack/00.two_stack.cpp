#include<iostream>
using namespace std;

class TwoStack {
    private:
        int* arr;
        int size;
        int top1, top2;
    public:
        TwoStack(int s) {
            this->size = s;
            this->top1 = -1;
            this->top2 = this->size;
            arr = new int[size];
        }
        void push1(int ele) {
            if(top1 == top2 - 1) {
                cout << "Stack1 Overflow! " << ele << " can't be pushed.\n";
                return;
            }
            arr[++top1] = ele;
        }
        void push2(int ele) {
            if(top2 == top1 + 1) {
                cout << "Stack2 Overflow! " << ele << " can't be pushed.\n";
                return;
            }
            arr[--top2] = ele;
        }
        int pop1() {
            if(top1 == -1) {
                cout << "Stack1 Underflow!\n";
                return -1;
            }
            return arr[top1--];
        }
        int pop2() {
            if(top2 == this->size) {
                cout << "Stack2 Underflow!\n";
                return -1;
            }
            return arr[top2++];
        }
};