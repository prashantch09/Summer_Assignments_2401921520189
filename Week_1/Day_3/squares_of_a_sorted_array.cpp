#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;

        for(int i = 0; i < n; i++) {
            res.push_back(nums[i] * nums[i]);
        }

        sort(res.begin(), res.end());

        return res;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.sortedSquares(nums);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}