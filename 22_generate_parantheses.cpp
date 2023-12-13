class Solution {
public:

    void util(int n, int open, int close, vector<string> &res, string str){
        if(str.size() == 2*n){
            //cout << str << endl;
            res.push_back(str);
            return;
        }
        
        if(open < n)    util(n, open + 1, close, res, str + "(");
        if(close < open) util(n, open, close + 1, res, str + ")");
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        util(n, 0, 0, res, "");

        return res;
    }
};