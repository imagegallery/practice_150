class Solution {
public:
    int util(string word1, string word2, int i, int j){
        if(i == word1.size()){
            return word2.size() - j;
        }
        if(j == word2.size()){
            return word1.size() - i;
        }
        if(word1[i] == word2[j])
            return util(word1, word2, i+1, j+1);
        else{
            int a = util(word1, word2, i, j+1); //insert
            int b = util(word1, word2, i+1, j); //remove
            int c = util(word1, word2, i+1, j+1); //replace
            return min(a, min(b, c)) + 1;
        }
    }
    int util1(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i == word1.size()){
            return word2.size() - j;
        }
        if(j == word2.size()){
            return word1.size() - i;
        }
        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
            dp[i][j] = util1(word1, word2, i+1, j+1, dp);
        else{  
            int a = util1(word1, word2, i, j+1, dp); //insert
            int b = util1(word1, word2, i+1, j, dp); //remove
            int c = util1(word1, word2, i+1, j+1, dp); //replace
            dp[i][j] =  min(a, min(b, c)) + 1;
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if(n == 0)
            return m;
        if(m == 0)
            return n;
        
        //Memory limit exceeded
        //int res = util(word1, word2, 0, 0);
        // return res;

        //top down approach - memoization
        //vector<vector<int>> dp(m, vector<int>(n, -1));
        //int res = util1(word1, word2, 0, 0, dp);
        //return res;

        //bottom-up approach
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int i = 0; i <= m; i++){
            dp[i][n] = m - i;
        }
        for(int i = 0; i <= n; i++){
            dp[m][i] = n - i;
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(word1[i] == word2[j])
                    dp[i][j] = dp[i+1][j+1];
                else{
                    dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};