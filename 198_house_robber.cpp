class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, 0);
        int max_so_far = 0;
        // Dp array contains max value at each index
        //dp[0] = cost[0]
        //dp[1] = max(cost[0], cost[1]);
        //dp[2] can be covered using jump by 2 from dp[0] by 2 and jump by 1 from dp[1]
        //as max_so_far is already have content of max till now so compare it with dp[i-2] only
        for(int i = 0; i < sz; i ++){
            if(i < 2){
                dp[i] = max(max_so_far, dp[i] + nums[i]);
                max_so_far = dp[i];
            }else{
                dp[i] = max(max_so_far, dp[i-2] + nums[i]);
                max_so_far = dp[i];
            }
        }
        return max_so_far;
    }
};