#include <bits/stdc++.h>
using namespace std;

void recursive_helper(stack<int>& st, int ele) {
    if(st.empty()) {
        st.push(ele);
        return;
    }
    int top = st.top();
    st.pop();
    recursive_helper(st, ele);
    st.push(top);
}

void easy_recursive_helper(stack<int>& st, int count, int size, int ele) {
    if(count == size) {
        st.push(ele);
        return;
    }
    int top = st.top();
    st.pop();
    easy_recursive_helper(st, count + 1, size, ele);
    st.push(ele);
}

stack<int> pushAtBottom(stack<int>& st, int x) {
    recursive_helper(st, x);
    easy_recursive_helper(st, 0, st.size(), x); // same as before
    return st;
}