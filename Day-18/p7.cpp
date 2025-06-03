/*
D. Stack – LIFO (Last In First Out)
➤ Real-World Use: Browser back button
*/

//Program 1: Basic stack operations

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(100);
    st.push(200);
    st.push(300);

    cout << "Top of stack: " << st.top() << endl;
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    return 0;
}
