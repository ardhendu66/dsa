#include<iostream>
#include<stack>
using namespace std;

string reverse_string(string str) {
    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        st.push(str[i]);
    }
    str = "";
    while(!st.empty()) {
        str += st.top();
        st.pop();
    }
    return str;
}

int main() {
    cout << reverse_string(reverse_string("ardhendu"));
}