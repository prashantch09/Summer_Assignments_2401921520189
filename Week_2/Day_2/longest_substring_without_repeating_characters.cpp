#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> hash(256,-1);
       int l=0,r=0,max=0;
       int n=s.length();
       
       while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            if(max<len) max=len;
            hash[s[r]]=r;
            r++;
       }
       return max;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.lengthOfLongestSubstring(s);

    return 0;
}