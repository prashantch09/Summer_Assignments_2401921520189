#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private: 
    stack<int> st;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(min.empty() || val <= min.top() ){
            min.push(val);
        }
    }
    
    void pop() {
        if(st.top() <= min.top()){
            min.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

int main() {
    MinStack ms;

    int q;
    cin >> q;

    while (q--) {
        string op;
        cin >> op;

        if (op == "push") {
            int val;
            cin >> val;
            ms.push(val);
        }
        else if (op == "pop") {
            ms.pop();
        }
        else if (op == "top") {
            cout << ms.top() << endl;
        }
        else if (op == "getMin") {
            cout << ms.getMin() << endl;
        }
    }

    return 0;
}