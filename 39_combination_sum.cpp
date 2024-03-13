class Solution {
public:
    void util1(vector<int> &nums, int target, vector<vector<int> >& res, vector<int> temp, int n, int i){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(target < 0)
            return;
        if(i == n)
            return;
        util1(nums, target, res, temp, n, i+1);
        temp.push_back(nums[i]);
        util1(nums, target - nums[i], res, temp, n, i);
        temp.pop_back();
    }
    void util(vector<int> &nums, int target, vector<vector<int> >& res, vector<int> temp, int n, int begin){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        for(int i = begin; i < n ; i++){
            if(target < nums[i])
                break;
            temp.push_back(nums[i]);
            util(nums, target - nums[i], res, temp, n, i);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        //util1(candidates, target, res, temp, n, 0);
        util(candidates, target, res, temp, n, 0);
        return res;
    }
};