#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<char> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    Solution obj;
    obj.reverseString(s);

    for (char ch : s) {
        cout << ch << " ";
    }

    cout << endl;

    return 0;
}