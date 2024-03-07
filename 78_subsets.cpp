class Solution {
public:
    void util(vector<int> &nums, vector<vector<int> >&res, vector<int> &temp, int n, int start){
       
        res.push_back(temp);
        for(int i = start; i < n; i++){
            temp.push_back(nums[i]);
            util(nums, res, temp, n, i+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        util(nums, res, temp, n, 0);
        return res;
    }
};