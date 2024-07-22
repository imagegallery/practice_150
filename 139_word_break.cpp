class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       int sz = s.size();
       vector<bool> dp (sz+1, false);
       dp[sz] = true;

       for(int i = sz-1; i >= 0; i--){
            for(auto word: wordDict){
                int wsz = word.size();
                if(i + wsz <= sz && s.substr(i, wsz) == word){
                    dp[i] = dp[i+wsz];
                }
                if(dp[i])
                    break;
            }
        }
        return dp[0];
       
    }
}; 