class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        int sz = coins.size();
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < sz; j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};