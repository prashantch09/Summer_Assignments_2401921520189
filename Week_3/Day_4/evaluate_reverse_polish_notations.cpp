#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    stack<int> st;

    int cal(int a,int b,char c){

        switch(c){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens){
        for(string c : tokens){
            if(c=="+" || c=="-" || c=="*" || c=="/"){
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();
                st.push(cal(a,b,c[0]));
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> tokens(n);

    for (int i=0; i<n; i++) {
        cin >> tokens[i];
    }

    Solution sol;
    cout << sol.evalRPN(tokens) << endl;

    return 0;
}