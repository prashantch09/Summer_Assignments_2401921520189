#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int len=1; len<=n/2; len++) {
            if (n % len != 0) continue;

            string pattern = s.substr(0, len);
            string temp = "";

            for (int i=0; i<n/len; i++) {
                temp += pattern;
            }

            if (temp == s) return true;
        }

        return false;
    }
};

int main() {
    string s;

    cin >> s;

    Solution sol;

    if (sol.repeatedSubstringPattern(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}