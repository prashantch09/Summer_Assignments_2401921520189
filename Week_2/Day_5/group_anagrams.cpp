#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<std::string, vector<std::string>> anghash;

        for(const auto& c : strs){
            std::string key = c;
            sort(key.begin(),key.end());
            anghash[key].push_back(c);
        }
        vector<vector<std::string>> res;
        for(const auto& it : anghash){
            res.push_back(it.second);
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i=0; i<n; i++) {
        cin >> strs[i];
    }

    Solution sol;
    vector<vector<string>> result = sol.groupAnagrams(strs);
    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}