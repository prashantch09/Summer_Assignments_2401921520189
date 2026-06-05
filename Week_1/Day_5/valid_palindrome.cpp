#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum((unsigned char)s[left]))
                left++;

            while (left < right && !isalnum((unsigned char)s[right]))
                right--;

            if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right]))
                return false;

            right--;
            left++;
        }

        return true;
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution obj;

    if (obj.isPalindrome(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}