#include<iostream>
#include<stack>
using namespace std;

/**
 *  pushing element into stack => [1, 2, 3, 4, 5]
 *  5 ⟶ top element of stack
 *  4 ⟶ 2nd top element
 *  3 ⟶ next top element(also middle element)
 *  2 ⟶ next top element
 *  1 ⟶ next top element
**/

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
    /* when all done, we are putting those(initially who were kept outside of the stack)
    *  values into the stack again.
    *
    *  This is mainly because, as we reach to middle position, the base case is condition true.
    *  And during our journey(from top to middle position), we kept all top elements of middle
    *  element outside of the stack, now we deleted middle element and we have to put all those
    *  top elements inside the stack again.
    */ 
    st.push(top_element);
}

void delete_middle_element(stack<int>& st) {
    int N = st.size(), count = 0;
    recursive_helper(st, count, N);
}