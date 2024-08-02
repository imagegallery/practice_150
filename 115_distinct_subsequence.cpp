class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        const int MOD = 1e9 + 7;

        vector<vector< int>> dp(m+1, vector<int> (n+1, 0));
        
        for(int i = 0; i <= m; i++){
            dp[i][n] = 1;
        }
        for(int i = n-1; i >= 0; i--){
            dp[m][i] = 0;
        }
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = (dp[i+1][j+1] + dp[i+1][j])% MOD;
                }
                else
                    dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};