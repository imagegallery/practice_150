class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        //dfs will take o(m.n)^2 so better to use BFS which is O(m.n)
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                   q.push({i, j}); 
                }
            }
        }
        vector<vector<int>> dirs = {{0,1}, {1, 0}, {0,-1}, {-1, 0}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = r + dirs[i][0];
                int y = c + dirs[i][1];
                if(x < 0 || x >= m || y < 0 || y > n || grid[x][y] != INT_MAX)
                    continue;
                grid[x][y] = grid[r][c] + 1;
                q.push({x,y}); 
            }
        }
    }
};
