class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, int>> >& mp, int root, int &maxtime, int time){
        if(mp.find(root) != mp.end()){
        
            for(int i = 0; i < mp[root].size(); i++){
              
                time = time + mp[root][i].second;
                
                maxtime = max(maxtime, time);
                dfs(mp, mp[root][i].first, maxtime, time);
                time = time - mp[root][i].second;
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<pair<int, int>>> mp;

        for(int i = 0; i < n; i++){
            mp[manager[i]].push_back({i, informTime[i]});
        }

        // for(auto key : mp){
        //     cout << "key is: " << key.first << endl;
        //     for(int i = 0; i < key.second.size(); i++){
        //         cout << key.second[i].first << " " << key.second[i].second <<endl;
        //     }
        // }

        //int time = mp[-1][0].second;
        int time = mp[-1][0].second, index = 0;
        int maxtime = time;
        dfs(mp, mp[-1][0].first , maxtime, time);
        return maxtime;
    }
};
/*
[2,2,-1,2,2,2,3,3,0,0, 7]
[3,0,1,2,0,0,0,5,0,0,0]
*/