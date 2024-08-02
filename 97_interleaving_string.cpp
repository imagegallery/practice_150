class Solution {
public:
bool util1(string &s1, string &s2, string &s3, int i, int j , int k){
        if(k == s3.size()){
            if(i == s1.size() && j == s2.size())
                return true;
            return false;
        }
        bool a = false, b = false;
        if(s1[i] == s3[k]){
            a = util1(s1, s2, s3, i+1, j, k+1);
        }
        if(s2[j] == s3[k]){
            b = util1(s1, s2, s3, i,j+1, k+1);
        }
        return a || b;
    }
    bool util2(string &s1, string &s2, string &s3, int i, int j ,map<pair<int, int>, bool> &dp){
        
        if(i == s1.size() && j == s2.size())
            return true;
        //cout << i << " "<< j <<endl;
        
        if(dp.find({i, j}) != dp.end())
            return dp[{i, j}];
        
        bool a = false, b = false;
        if(i < s1.size() && s1[i] == s3[i+j] && util2(s1, s2, s3, i+1, j, dp)){
            return true;
        }
        if(j < s2.size() && s2[j] == s3[i+j] && util2(s1, s2, s3, i, j+1, dp)){
            return true;
        }
        dp[{i, j}] = false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), p = s3.size();
        if(m+n != p)
            return false;
        /*
        //recursion
        
        int i = 0, j = 0, k = 0;
        return util1(s1, s2, s3, i, j, k);
        */

        /*
        //memoization
        map<pair<int, int>, bool> dp;
        //cout << dp.size() << " " << dp[0].size() << " " << dp[0][0].size() << endl;
        int i = 0, j = 0;
        return util2(s1, s2, s3, i, j, dp);
        */

        // Dp
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;
        for(int i = m; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                if(i < m && s1[i] == s3[i+j] && dp[i+1][j])
                    dp[i][j] = true;
                if(j < n && s2[j] == s3[i+j] && dp[i][j+1])
                    dp[i][j] = true;
            }
        }
        return dp[0][0];
        
    }
};