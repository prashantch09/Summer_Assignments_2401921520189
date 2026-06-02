#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
        int maxSubArray(int* nums, int numsSize) {

        int sum=0;
        int max = -1e9;

        for(int i=0;i<numsSize;i++){
            if(sum<0){
                sum=0;
            }

            sum=sum+nums[i];
            if(sum>max){
                max=sum;
            }
        }

        return max;
    }
};

int main() {
    int numsSize;
    cin >> numsSize;

    vector<int> nums(numsSize);
    for(int i = 0; i < numsSize; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.maxSubArray(nums.data(), numsSize);

    return 0;
}