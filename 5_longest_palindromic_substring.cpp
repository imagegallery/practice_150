class Solution {
public:
    void util(string s, int left, int right, int &maxLen, string &res){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            if(right-left + 1 > maxLen){
                maxLen = right-left+1;
                res = s.substr(left, right-left+1);
            }
            left -= 1;
            right += 1;
        }
    }
    string longestPalindrome(string s) {
        string res;
        int sz = s.size();
        int maxLen = 0;
        for(int i = 0; i < sz; i++){
            util(s, i, i, maxLen, res);
            util(s, i, i+1, maxLen, res);
        }
        return res;
    }
};