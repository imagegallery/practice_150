class Solution {
public:
    void util(vector<int> candidates, int target, int sum, vector<int> &temp, vector<vector<int>> &res, int start){
        if(sum == target){
            res.push_back(temp);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            sum += candidates[i];
            if(sum > target){
                sum -= candidates[i];
                break;
            }else{
                temp.push_back(candidates[i]);
                util(candidates, target, sum, temp, res, i+1);
                sum -= candidates[i];
                temp.pop_back();     
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        util(candidates, target, sum, temp, res, 0);
        return res;
    }
};