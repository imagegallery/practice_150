class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        // for(int i = 0; i < n+1; i++){
        //     dp[i][0] = 1;
        // }

        // for(int i = n-1; i >= 0; i--){
        //     for(int j = 1; j < amount+1; j++){
        //         dp[i][j] = dp[i+1][j];
        //         if(j-coins[i] >= 0){
        //             dp[i][j] += dp[i][j-coins[i]];
        //         }
        //     }
        // }
        // return dp[0][amount];

        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for(int i = n-1; i >= 0; i--){
            vector<int> nextDp(amount+1, 0);
            nextDp[0] = 1;
            for(int j = 1; j< amount+1; j++){
                nextDp[j] = dp[j];
                if(j-coins[i] >= 0){
                    nextDp[j] += nextDp[j-coins[i]]; 
                }
            }
            dp = nextDp;
        }
        return dp[amount];
    }
};