#include <iostream>
#include <stack>
using namespace std;

bool matches(char ch, char top_of_stack) {
    // valid matches are being checked.
    /** here,
     * upcoming_closing_bracket : ch and opening bracket : st.top()
     * if they valid that means their occurrance is right otherwise not
    */
    return (
        (ch == ')' && top_of_stack == '(') ||
        (ch == '}' && top_of_stack == '{') ||
        (ch == ']' && top_of_stack == '[')
    );
}

bool isValidParanthesis(string str) {
    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        // checking for opening bracket, if open bracket then push it onto stack
        if(ch == '(' || ch == '{' || ch == '[') {
            // push it onto stack
            st.push(ch);
        }
        // checking for closing bracket, if any opening bracket founds then pop it
        // and finally following this operation, if stack is empty, then valid
        else {
            // if stack is empty and we are finding top of stack, gives runtime-error
            // hence we are checking it, if it empty or not ?
            if(!st.empty()) {
                char top = st.top();
                if(matches(ch, top)) {
                    // valid matches found, then pop the opening bracket
                    // possible cases : "()" or "{}" or "[]"
                    // first_character : top_element_of_the_stack (opening bracket)
                    // second_character : upcoming closing bracket
                    st.pop();
                }
                else {
                    // not valid order of parenthesis
                    // possible cases : "(}" or "(]" or "{)" or "{]" or "[)" or "[}" 
                    // first_character : top_element_of_the_stack (opening bracket)
                    // second_character : upcoming closing bracket
                    return false;
                };
            }
            else {
                // found a closing bracket, but stack is empty that means
                // either it is first character as well as closing character or
                // before its position we found a correct parentheses sequence (valid)
                // in both cases we can't get valid parentheses if we move further
                return false;
            }
        }
    }
    return st.empty();
}