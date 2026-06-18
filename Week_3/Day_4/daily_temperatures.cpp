#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; 

        for (int i=0; i<n ; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {

                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> temperatures(n);

    for (int i=0; i<n; i++) {
        cin >> temperatures[i];
    }

    Solution sol;
    vector<int> result = sol.dailyTemperatures(temperatures);

    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;
    return 0;
}