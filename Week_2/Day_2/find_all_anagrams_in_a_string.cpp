#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<int> freq1(26,0);
        vector<int> res;
        for(auto c : p){
            freq1[c-'a']++;
        }

        for(int i=0; i<=m-n; i++){
            vector<int> freq2(26,0);
            int windowi = 0;
            int indx = i;

            while(windowi<n && indx<m){
                freq2[s[windowi + indx] - 'a']++;
                windowi++;
            }

            bool check = true;
            for(int j=0; j<26; j++){
                if(freq1[j]!=freq2[j]){
                    check = false;
                    break;
                }
            }
            if(check) res.push_back(i);
        }
        return res;
    }
};

int main() {
    string s, p;

    cin >> s;
    cin >> p;

    Solution sol;
    vector<int> result = sol.findAnagrams(s, p);

    for(int i = 0; i < result.size(); i++){
        cout << result[i];
        if(i < result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}