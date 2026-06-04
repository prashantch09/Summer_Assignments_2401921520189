#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bot = n - 1;
        int left = 0, right = m - 1;
        vector<int> res;

        while (top <= bot && left <= right) {
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int j = top; j <= bot; j++) {
                res.push_back(matrix[j][right]);
            }
            right--;

            if (top <= bot) {
                for (int k = right; k >= left; k--) {
                    res.push_back(matrix[bot][k]);
                }
                bot--;
            }

            if (left <= right) {
                for (int l = bot; l >= top; l--) {
                    res.push_back(matrix[l][left]);
                }
                left++;
            }
        }

        return res;
    }
};

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}