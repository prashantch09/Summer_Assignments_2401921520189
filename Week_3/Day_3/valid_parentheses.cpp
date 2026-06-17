#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<char> stack;
    int top = -1;
    
    bool check(char c){
        switch(c){
            case ')': return stack[top]=='(';
            case '}': return stack[top]=='{';
            case ']': return stack[top]=='[';

        }
        return false;
    }
    bool isValid(string s) {

        for(char c : s){
            if(top != -1 && check(c)){
                stack.pop_back();
                top--;
            }
            else{
                stack.push_back(c);
                top++;
            }
        }
        return top == -1;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;

    if (sol.isValid(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}