#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    sum += mat[i][j];
                }
            }
        }

        int l = n - 1;
        int r = 0;
        while(r < n) {
            if(r != l) {
                sum += mat[l][r];
            }
            l--;
            r++;
        }

        return sum;
    }
};

int main() {
    int n;
    cin >> n;  // Size of square matrix

    vector<vector<int>> mat(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    cout << obj.diagonalSum(mat) << endl;

    return 0;
}