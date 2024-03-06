class Solution {
public:
    
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> res;
        int n = queries.size();
        vector<int> candles;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '|'){
                candles.push_back(i);
            }
        }
        
        for(int i = 0; i < n; i++){
            int count = 0;
            int start = queries[i][0];
            int end = queries[i][1];
            if(candles.size() <= 1){
                res.push_back(0);
                continue;
            }
            int l = lower_bound(candles.begin(), candles.end(), start) - candles.begin();
            //cout << "l is: " << l <<endl;
            int r = upper_bound(candles.begin(), candles.end(), end) - candles.begin() - 1;
            //cout << "r is: " << r <<endl;
            if(l >= r)
                res.push_back(0);
            else{
                res.push_back( (candles[r] - candles[l]) - (r - l));
            }
        }
        return res;

    }
};