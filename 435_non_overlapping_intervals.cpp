class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        //sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[1] < b[1]; });
                                                                // {if(a[0] < b[0])
                                                                //     return true;
                                                                // if(a[0] == b[0])
                                                                //     return a[1] < b[1];
                                                                // return false;});
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> res = intervals[0];
        int count = 1;

        for(int i = 1; i <n; i++){
            if(res[1] <= intervals[i][0]){
                count ++;
                res = intervals[i];
            }

        } 
        return n - count;                       
    }
};