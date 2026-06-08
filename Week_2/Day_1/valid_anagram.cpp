#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        vector<int> freq(26);

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            freq[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
};

int main() {
    string s, t;
    cin >> s >> t;

    Solution obj;
    cout << obj.isAnagram(s, t);

    return 0;
}