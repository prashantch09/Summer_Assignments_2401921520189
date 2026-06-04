#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if( m*n != r*c) return mat;

        vector<int> mid;
        vector<vector<int>> res(r, vector<int>(c));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mid.push_back(mat[i][j]);
            }
        }
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0;j--){
                res[i][j] = mid.back();
                mid.pop_back();
            }
        }
        return res;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    Solution obj;
    vector<vector<int>> result = obj.matrixReshape(mat, r, c);

    for (const auto& row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}