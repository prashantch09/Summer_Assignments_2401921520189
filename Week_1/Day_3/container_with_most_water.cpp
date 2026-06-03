#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxArea = 0;
        int area = 0;
        int left = 0;
        int right = n - 1;

        while(left < right) {
            if(height[left] <= height[right]) {
                area = height[left] * (right - left);
                left++;
            }
            else {
                area = height[right] * (right - left);
                right--;
            }

            if(area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> height(n);

    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;
    cout << obj.maxArea(height);

    return 0;
}