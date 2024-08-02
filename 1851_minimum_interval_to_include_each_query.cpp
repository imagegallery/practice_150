class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int m = queries.size();
        sort(intervals.begin(), intervals.end(), [] (vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        //keeping copy to have the result in correct order
        vector<pair<int,int>> v;
        for(int i=0;i<queries.size();i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());

        //book keeping to get the result for the corresponding query
        unordered_map<int, int> mp;

        // auto cmp = [](vector<int> a,  vector<int> b){
        //     if (a[0] == b[0])
        //         return a[1] > b[1];
        //     return a[0] > b[0];
        // };
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
        //priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp) > pq1(cmp);
        //priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq2; //max heap add elements by multiplying by -1.
        vector<int> result(m);
        int i = 0, n = intervals.size();
        for(auto q:v){
            while( i < n && intervals[i][0] <= q.first){
                pq.push({(intervals[i][1] - intervals[i][0] + 1), intervals[i][1] });
                i++;
            }
            while(!pq.empty() && pq.top().second < q.first) 
                pq.pop();
            
            result[q.second] = (pq.empty()) ? -1 : pq.top().first;
        }
        
        // for(auto q: queries){
        //     result.push_back(mp[q]);
        // }

        return result;

        //time complexity: O(n^2)
        // int n = queries.size();

        // sort(intervals.begin(), intervals.end(), [] (vector<int> a, vector<int> b){
        //     return a[0] < b[0];
        // });

        // // for(auto interval: intervals){
        // //     cout << interval[0] << " " << interval[1] << endl;
        // // }
        // int m = intervals.size();
        // vector<int> result (n, INT_MAX);
        // for(int i = 0; i < n; i++){
        //     //cout << "query is: "<< queries[i] << endl;
        //     for(int j = 0; j < m ; j++){
        //         if(intervals[j][0] <= queries[i] && intervals[j][1] >= queries[i]){
        //             result[i] = min(result[i], intervals[j][1] - intervals[j][0] + 1);
        //             //cout << result[i] << endl;
        //         }
        //     }
        //     if(result[i] == INT_MAX)
        //         result[i] = -1;
        // }
        // return result;
        
    }
};