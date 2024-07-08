class Solution {
public:
    void util(string s, int left, int right, int &maxLen){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            maxLen++;
            left -= 1;
            right += 1;
        }
    }
    int countSubstrings(string s) {
        int res = 0;
        int sz = s.size();

        for(int i = 0; i < sz; i++){
            util(s, i, i, res);
            util(s, i, i+1, res);
        }
        return res;
    }
};