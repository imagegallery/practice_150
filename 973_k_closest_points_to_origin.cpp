class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> >  pq;
        vector<vector<int>> res;
        int n = points.size();
        for(int i = 0; i < n; i++){
            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]); 
            pq.push(make_pair(dist, i));
        }
        for(int i = 0; i < k; i++){
            pair<int, int> temp = pq.top();
            pq.pop();
            res.push_back(points[temp.second]);
        }
        return res;
    }
};