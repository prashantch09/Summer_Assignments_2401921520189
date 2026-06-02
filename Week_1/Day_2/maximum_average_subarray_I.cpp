#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        double maxavg = -1e9;
        int left = 0;
        int right = k-1;

        double sum = 0;
        while(left<=right){
            sum += nums[left++];
        }
        left = 0;
        if(maxavg<(sum/k)) maxavg = sum/k;

        while(++right<n){
            sum = sum - nums[left++] + nums[right];
            if(maxavg<(sum/k)) maxavg = sum/k;
        }
        return maxavg;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution obj;
    cout << obj.findMaxAverage(nums, k);

    return 0;
}