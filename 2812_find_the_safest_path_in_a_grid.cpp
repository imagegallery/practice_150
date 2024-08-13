class Solution {
public:
    vector<int> X = {0,1,0,-1};
    vector<int> Y = {1,0,-1,0};

    void bfs(vector<vector<int>>& grid){
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j])
                    q.push({i, j});
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = r + X[i];
                int y = c + Y[i];
                if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0){
                    grid[x][y] = grid[r][c] + 1;
                    q.push({x, y});
                }
            } 
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])
            return 0;
        
        bfs(grid);

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }


        priority_queue<pair<int, pair<int, int> > >pq;
        pq.push({grid[0][0], {0,0}});

        while(pq.top().second.first < n-1 || pq.top().second.second < n-1){
            int score = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            //cout << score << " " << r << " " << c << endl;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int x = r + X[i];
                int y = c + Y[i];
                if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0){
                    pq.push({min(score, grid[x][y]), {x,y}});
                    grid[x][y] *=-1;
                }
            }
        }
        return pq.top().first - 1;
        
    }
};