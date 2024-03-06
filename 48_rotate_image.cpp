class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n ;i ++){
            for(int j = i; j <n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
        // int n = matrix.size();
        // int s = n-1;
        // for(int i = 0; i < (n+1)/2; i++){
        //     for(int j = i; j < s; j++){
        //         int temp = matrix[i][j];
        //         matrix[i][j] = matrix[n-1-j][i];
        //         matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        //         matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        //         matrix[j][n-1-i] = temp;
        //     }
        //     s--;
        // }
        // return;
    }
};