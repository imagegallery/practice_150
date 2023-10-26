class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for(auto str: strs){
            string st = str;
            sort(st.begin(), st.end());
            mp[st].push_back(str);
        }    

        for(auto i: mp){
            res.push_back(i.second);
        }
        return res;
    }
};