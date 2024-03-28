class Solution {
public:
    void util1(vector<int> nums, set<vector<int>> &res, vector<int> temp, int start){
        res.insert(temp);
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            util1(nums, res, temp, i+1);
            temp.pop_back();
        }
    }
    void util(vector<int> nums, vector<vector<int>> &res, vector<int> temp, int start){
        res.push_back(temp);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            util(nums, res, temp, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // set<vector<int>> res;
        // sort(nums.begin(), nums.end());
        // vector<int> temp;
        // util(nums, res, temp, 0);
        // vector<vector<int>> ans;
        // for(auto i: res){
        //     ans.push_back(i);
        // }
        // return ans;

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        util(nums, res, temp, 0);
        return res;
    }
};