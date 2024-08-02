class Solution {
public:
    vector<int> X = {0, 1, 0, -1};
    vector<int> Y = {1, 0, -1, 0};
    int util(vector<vector<int>> &matrix, int i, int j, int m, int n, vector<vector<int>> &dp){
        if(dp[i][j] != 0)
            return dp[i][j];
        int res = 1;
        for(int p = 0; p < 4; p++){
            int new_i = i + X[p];
            int new_j = j + Y[p];
            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && matrix[i][j] < matrix[new_i][new_j]){
                res = max(res, 1+ util(matrix, new_i, new_j, m, n, dp));
            }
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxRes = INT_MIN;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                maxRes = max(maxRes, util(matrix, i, j, m, n, dp));
            }
        }
        return maxRes;
    }
};