class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second >= b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1 sol is add nums entries in unorderd_map and then sort the map acc to values and get the top-k elements from the map
        // unordered_map<int, int> mp;
        
        // vector<int> res;
        // for(auto num:nums){
        //     mp[num] ++;
        // }
        // vector<pair<int, int>> tmp;
        // for(auto &item: mp)
        //     tmp.push_back(item);

        // sort(tmp.begin(), tmp.end(), cmp);

        // mp.sort();
        // for(auto itr: tmp){
        //     cout << itr.first << " " << itr.second << endl;
        // }
        // for(int i = 0 ; i < k ; i++){
        //     res.push_back(tmp[i].first);
        // }

        //2 sol used map and sort the array and add elements into map and return top k elements from map
        // map<int, int> mp;
        // vector<int> res;
        // sort(nums.begin(), nums.end());
        
        // for(auto itr : mp){
        //     res.push_back(itr.first);
        //     k--;
        //     if (k ==0)
        //         break;
        // }
        // return res;

        //3 sol add nums into unordered_map and then use min-heap to take top k elements into min_heap
        unordered_map<int, int> mp;
        
        vector<int> res;
        for(auto num:nums){
            mp[num] ++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it = mp.begin(); it != mp.end(); it ++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > mp.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};