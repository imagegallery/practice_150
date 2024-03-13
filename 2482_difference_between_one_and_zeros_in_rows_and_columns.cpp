class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<int> oneRow(m, 0);
        vector<int> oneCol(n, 0);
        for(int i = 0; i < m; i++){
            int oneR = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    oneR ++;
                    oneCol[j] ++;
                }
            }
            oneRow[i] = oneR;
        }
        // for(int i = 0; i < m; i++)
        //     cout << oneRow[i] << " ";
        // cout << endl;
        // for(int i = 0; i < n; i++)
        //     cout << oneCol[i] << " ";

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int val = oneRow[i] + oneCol[j] - (m - oneRow[i]) - (n - oneCol[j]);
                //cout << val << endl;
                res[i][j] =val;
            }
        }
        return res;
        
    }
};