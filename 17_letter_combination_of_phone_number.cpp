class Solution {
public:
    unordered_map<char, string> dialPad= { {'2', "abc"}, 
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
    };
    

    void util(string digits, vector<string> &res, string str, int k){
        if(k == digits.size()){
            res.push_back(str);
            return;
        }
        string chars = dialPad[digits[k]];
        for(int i = 0; i < chars.size(); i++){
            string str1 = str;
            str += chars[i];
            util(digits, res, str, k+1);
            str = str1;
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        vector<string> res;
        util(digits, res, "", 0);
        return res;
    }
};