class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> dp(sz, 1);
        int max_len = 1;
        for(int i = sz-2; i>= 0; i--){
            for(int j = i+1; j < sz; j++){
                if(nums[i] < nums[j] ){
                    dp[i] = max(dp[i], dp[j]+1);
                    max_len = max(max_len, dp[i]);
                }
            }
        }
        return max_len;
        
    }
};
//[4,10,4,3,8,9]