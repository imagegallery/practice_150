class Solution {
public:
    // unordered_set<int> cycle;
    // int cycleStart = -1;
    // void dfs(vector<vector<int>> &graph, vector<bool> &vis, int cur, int par = -1){
    //     if(vis[cur]){
    //         cycleStart = cur;
    //         return;
    //     }
    //     vis[cur] = true;
    //     for(auto child : graph[cur]){
    //         if(child == par)
    //             continue;
    //         if(cycle.empty())
    //             dfs(graph, vis, child, cur);
    //         if(cycleStart != -1)
    //             cycle.insert(cur);
    //         if(cur == cycleStart){
    //             cycleStart = -1;
    //             return;
    //         }
    //     }
    // }
    bool dfs(vector<vector<int>> &graph, vector<bool> &vis, int cur, int par = -1){
        if(vis[cur])
            return true;
        vis[cur] = true;
        for(auto child : graph[cur]){
            if(child != par && dfs(graph, vis, child, cur))
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        vector<bool> vis(n+1);

        for(int i = 0; i < n; i++){
            fill(vis.begin(), vis.end(), false);
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            if(dfs(graph, vis, edges[i][0]))
                return edges[i];
        }
        return {};

        // dfs(graph, vis, 1);

        // for(int i = n-1; i >=0 ; i--){
        //     if(cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
        //         return edges[i];
        // }
        // return {};
    }
};