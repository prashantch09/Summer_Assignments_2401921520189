#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nge[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(nge[num]);
        }
        return ans;
    }
};

int main() {
    int n1;
    cin >> n1;

    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    int n2;
    cin >> n2;

    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    Solution sol;
    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}