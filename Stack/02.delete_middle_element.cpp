#include<iostream>
#include<stack>
using namespace std;

void recursive_helper(stack<int>& st, int count, int size) {
    // base case
    if(count == size/2) {
        // when we reach the middle element position, we pop the element
        st.pop();
        return;
    }
    // placing top() element out of the stack. 
    int top_element = st.top();
    st.pop();
    // then we are going deeper into stack.
    recursive_helper(st, count + 1, size);
    // when all done, we are putting those(initially who were kept outside of the stack)
    // values into the stack again.
    /* This is mainly because, as we reach to middle position, the base case is condition true.
    *  And during our journey(from top to middle position), we kept all top elements of middle *  element outside of the stack, now we deleted middle element and we have to put all those *  top elements inside the stack again.
    */ 
    st.push(top_element);
}