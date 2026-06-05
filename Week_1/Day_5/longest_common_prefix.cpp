#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";

        string prefix = strs[0];

        for (int i = 1; i < n; i++) {
            int j = 0;

            while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
                j++;
            }

            prefix.resize(j);

            if (prefix.size() == 0) {
                return "";
            }
        }

        return prefix;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution obj;
    cout << obj.longestCommonPrefix(strs) << endl;

    return 0;
}