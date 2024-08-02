class Solution {
public:
    int dfs(vector<vector<int> > &adj, int index, int &count, vector<bool> &visited){
        if(visited[index])
            return 0;
        
        count++;
        visited[index] = true;
        for(auto i: adj[index]){
            dfs(adj, i, count, visited);
        }
        return count;

    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int> > adj(n);

        long long  x1, y1, r1, x2, y2, r2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    x1 = bombs[i][0];
                    y1 = bombs[i][1];
                    r1 = bombs[i][2];

                    x2 = bombs[j][0];
                    y2 = bombs[j][1];
                    r2 = bombs[j][2];

                    //long long  d = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
                    //cout << d << " " << r1 << " " << r2 << endl;
                    if(pow(x1-x2, 2) + pow(y1-y2, 2) <= r1 * r1)
                        adj[i].push_back(j);
                    if(pow(x1-x2, 2) + pow(y1-y2, 2) <= r2 * r2) 
                        adj[j].push_back(i);
                }
            }   
        }
        
        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            vector<bool> visited(n, 0);
            int c = 0;
            res = max(res, dfs(adj, i, c, visited));
        }
        return res;
    }
};