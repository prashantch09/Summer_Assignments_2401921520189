#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hash;
        for(char &c : ransomNote){
            hash[c]++;
        }
        for(char &c : magazine){
            if(hash.find(c)!=hash.end()){
                hash[c]--;
            }
        }
        for(char &c : ransomNote){
            if(hash[c]>0) return false;
        }
        return true;
    }
};

int main() {
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;

    Solution obj;
    cout << obj.canConstruct(ransomNote, magazine);

    return 0;
}