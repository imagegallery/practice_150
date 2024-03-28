class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l]!=s[r])
                return false;
            l++;r--;
        }
        return true;
    }
    void util(string s, vector<vector<string>> &res, vector<string> temp, int start){
        if(start >= s.size()){
            res.push_back(temp);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(isPalindrome(s, start, i)){
                //cout << s.substr(start, i-start+1) << endl;
                temp.push_back(s.substr(start, i-start+1));
                util(s, res, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        util(s, res, temp, 0);
        return res;
    }
};