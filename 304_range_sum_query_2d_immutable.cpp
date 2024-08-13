//https://leetcode.com/problems/range-sum-query-2d-immutable/solutions/2104317/dp-visualised-interview-tips

class NumMatrix {
    
public:
    vector<vector<int>> mat;
    int m, n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        mat = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                mat[i][j] = matrix[i-1][j-1] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1, sum2, sum3;

        sum1 = mat[row2+1][col2+1];
        sum2 = mat[row2+1][col1] + mat[row1][col2+1];
        sum3 = mat[row1][col1];
        return sum1 - sum2 + sum3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */