class Solution {
public:
    bool check(int i, int j, int m, int n, vector<vector<int>>& grid, int &fresh){
        if(i >=0 && i < m && j >= 0 && j < n && grid[i][j] == 1){
            grid[i][j] = 2;
            fresh --;
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int> > q;
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j] == 2){
                    //cout << i << " " << j;
                    q.push(make_pair(i, j));
                }
                else if(grid[i][j] == 1)
                    fresh++;
            }        
        }
        //cout << endl;
        int count = -1;
        while(!q.empty()){
            //cout << endl;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                pair<int, int> temp = q.front();
                q.pop();
                //cout << temp.first << " " << temp.second  << " " << count << endl;
                if(check(temp.first, temp.second+1, m, n, grid, fresh)){
                    q.push(make_pair(temp.first, temp.second+1));
                }
                if(check(temp.first+1, temp.second, m, n, grid, fresh)){
                    q.push(make_pair(temp.first+1, temp.second));
                }
                if(check(temp.first, temp.second-1, m, n, grid, fresh)){
                    q.push(make_pair(temp.first, temp.second-1));
                }
                if(check(temp.first-1, temp.second, m, n, grid, fresh)){
                    q.push(make_pair(temp.first-1, temp.second));
                }
            }
            count ++;
            //cout << "end of 1 level " << endl;
        }
        if(fresh > 0)
            return -1;
        if(count == -1)
            return 0;
        return count;
    }
};
