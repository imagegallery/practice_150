class Solution {
public:
    bool dfs(unordered_map<int, vector<int> >&mp, vector<int> &visited, int c){
        if(visited[c] == 1)
            return false;
        if(mp[c].empty())
            return true;
        
        visited[c] = 1;
        for(auto i:mp[c]){
            if(!dfs(mp, visited, i))
                return false;
        }
        mp[c].clear();
        visited[c] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for(auto i:prerequisites){
            mp[i[0]].push_back(i[1]);
        }
        vector<int> visited(numCourses, 0);

        for(int i = 0; i <numCourses; i++){
            if(!dfs(mp, visited, i))
                return false;

        }
        return true;
    }
};