#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> freq1(26,0);

        for(auto c : s1){
            freq1[c-'a']++;
        }

        for(int i=0; i<=m-n; i++){
            vector<int> freq2(26,0);
            int windowi = 0;
            int indx = i;

            while(windowi<n && indx<m){
                freq2[s2[windowi + indx] - 'a']++;
                windowi++;
            }

            bool check = true;
            for(int j=0; j<26; j++){
                if(freq1[j]!=freq2[j]){
                    check = false;
                    break;
                }
            }
            if(check) return true;
        }
        return false;
    }
};

int main() {
    string s1, s2;

    cin >> s1;
    cin >> s2;

    Solution sol;

    if(sol.checkInclusion(s1, s2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}