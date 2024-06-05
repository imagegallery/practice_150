class Solution {
public:
    bool dfs(unordered_map<int, vector<int> >& mp, int crs, vector<int>& res, vector<bool> & visited, vector<bool> &cycle){
        if(cycle[crs])  //if course is already in cycle
            return false;
        if(visited[crs])  // as crs is already added in output we dont have to run it again 
            return true;
        cycle[crs] = true;
        for(auto c: mp[crs]){
            if(!dfs(mp, c, res, visited, cycle))
                return false;
        }
        cycle[crs] = false;
        visited[crs] = true;
        res.push_back(crs);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> > mp;
        for(auto i: prerequisites){
            mp[i[0]].push_back(i[1]);
        }
        vector<bool> visited(numCourses, 0);  
        vector<bool> cycle(numCourses, 0); 
        vector<int> res;  
        //crs has 3 states
        //visited: when crs has been added to output represented by visited array
        //visiting: when crs is visited but not added to output array represented by cycle array
        //unvisited: when crs is neither visited nor added into output array.
        for(int i = 0; i < numCourses; i++){
            if(!dfs(mp, i, res, visited, cycle))
                return {};
        }
        return res;
    }
};