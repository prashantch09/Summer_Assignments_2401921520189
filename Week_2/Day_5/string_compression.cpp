#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int read = 0;

        while (read < n) {
            char curr = chars[read];
            int count = 0;

            while (read < n && chars[read] == curr) {
                read++;
                count++;
            }
            chars[write++] = curr;

            if (count>1) {
                string freq = to_string(count);

                for (char c : freq) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};

int main() {
    int n;
    cin >> n;

    vector<char> chars(n);
    for (int i=0; i<n; i++) {
        cin >> chars[i];
    }

    Solution sol;
    int length = sol.compress(chars);

    cout << length << endl;
    for (int i=0; i<length; i++) {
        cout << chars[i];
    }

    cout << endl;
    return 0;
}