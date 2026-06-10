#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int c = 0;

        for(int i = 0; t[i] != '\0'; i++){
            if(s[c] == t[i]){
                c++;
            }
        }

        if(c == s.size()) return true;
        return false;
    }
};

int main() {
    string s, t;

    cin >> s;
    cin >> t;

    Solution sol;

    if(sol.isSubsequence(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}