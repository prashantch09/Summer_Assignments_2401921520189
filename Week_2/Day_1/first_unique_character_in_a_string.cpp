#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(char c : s){
            freq[c-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.firstUniqChar(s);

    return 0;
}