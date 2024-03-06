class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        //sort by start time
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
                                                    {return a[0] < b[0];});
        res.push_back(intervals[0]);
        int j = 0;
        //vector<int> start = intervals[0];
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            if(res[j][1] < intervals[i][0]){
                res.push_back(intervals[i]);
                j++;
                //start = intervals[i];
            }else{
                res[j][0] = min(res[j][0], intervals[i][0]);
                res[j][1] = max(res[j][1], intervals[i][1]);
            }
        }
        //res.push_back(start);
        return res;
        
    }
};