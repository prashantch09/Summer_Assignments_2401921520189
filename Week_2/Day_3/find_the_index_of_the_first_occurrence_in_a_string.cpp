#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ln = needle.size();
        int lh = haystack.size();

        if(ln>lh) return -1;
        for(int i=0;i<=lh-ln;i++){
            if(haystack[i]==needle[0]){
                int k=0;
                for(int j=i;j<(i+ln);j++){
                    if(haystack[j]!=needle[k++]) break;
                    if(k==ln) return i;
                }
            }
        }
        
        return -1;
    }
};

int main() {
    string haystack, needle;

    cin >> haystack;
    cin >> needle;

    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;

    return 0;
}