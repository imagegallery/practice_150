class Solution {
public:
    void dfs(vector<vector<int>> &heights,  int i, int j, vector<vector<bool>>& visited, int m, int n){
        if(visited[i][j])
            return;
        visited[i][j] = true;
        
        if(i+1 < m && heights[i+1][j] >= heights[i][j])
            dfs(heights, i+1, j, visited, m, n);
        if(i-1 >= 0 && heights[i-1][j] >= heights[i][j])
            dfs(heights, i-1, j, visited, m, n);
        
        if(j+1 < n && heights[i][j+1] >= heights[i][j])
            dfs(heights, i, j+1, visited, m, n);
        if(j-1 >= 0 && heights[i][j-1] >= heights[i][j])
            dfs(heights, i, j-1, visited, m, n);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, 0));
        vector<vector<bool>> atlantic(m, vector<bool>(n, 0));
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            dfs(heights, 0, i, pacific, m, n);
            dfs(heights, m-1, i, atlantic, m, n);
        }
        for(int i = 0; i < m; i++){
            dfs(heights, i, 0, pacific, m, n);
            dfs(heights, i, n-1, atlantic, m, n);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(atlantic[i][j] && pacific[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};