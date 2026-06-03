#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j = 0;
        int i = 0;

        while(i < n) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }

        while(j < n) {
            nums[j] = 0;
            j++;
        }
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
    obj.moveZeroes(nums);

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}