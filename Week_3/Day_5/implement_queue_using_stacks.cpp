#include <iostream>
#include <stack>
#include <string>
using namespace std;

class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;

    MyQueue() {
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        peek();

        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;

    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (op == "pop") {
            cout << q.pop() << endl;
        }
        else if (op == "peek") {
            cout << q.peek() << endl;
        }
        else if (op == "empty") {
            cout << (q.empty() ? "true" : "false") << endl;
        }
    }
    return 0;
}