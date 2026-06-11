#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }

    string decode(string& s, int& i) {
        string result = "";
        int num = 0;

        while (i < s.size()) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            else if (s[i] == '[') {
                i++;

                string decoded = decode(s, i);
                while (num--) {
                    result += decoded;
                }
                num = 0;
            }
            else if (s[i] == ']') {
                i++;
                return result;
            }
            else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};

int main() {
    string s;

    cin >> s;

    Solution sol;
    cout << sol.decodeString(s) << endl;

    return 0;
}