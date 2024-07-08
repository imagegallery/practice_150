class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1)
            return nums[0];
        vector<int> dp(sz, 0);
        vector<int> dp1(sz, 0);
        int max_so_far = 0;
        int max_so_far1 = 0;
        for(int i = 0; i < sz-1; i++){
            if(i < 2){
                dp[i] = max(max_so_far, dp[i] + nums[i]);
                max_so_far = dp[i];
            }else{
                dp[i] = max(max_so_far, dp[i-2] + nums[i]);
                max_so_far = dp[i];
            }
        }
        
        for(int i = sz-1; i > 0; i--){
            if(i > sz-3){
                dp1[i] = max(max_so_far1, dp1[i] + nums[i]);
                max_so_far1 = dp1[i];
            }else{
                dp1[i] = max(max_so_far1, dp1[i+2] + nums[i]);
                max_so_far1 = dp1[i];
            }
        }
        return max(max_so_far, max_so_far1);

    }
};