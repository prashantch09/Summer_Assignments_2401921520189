#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void generate(string& curr, int open, int close, int n) {
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            generate(curr, open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            generate(curr, open, close + 1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr;
        generate(curr, 0, 0, n);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}