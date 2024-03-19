class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto i: tasks){
            mp[i] ++;
        }
        priority_queue<int> pq;
        for(auto i: mp){
            pq.push(i.second);            
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> remain;
            int cycle = n+1;
            while(cycle and !pq.empty()){
                int max_freq = pq.top();
                pq.pop();
                if(max_freq > 1)
                    remain.push_back(max_freq - 1);
                time ++;
                cycle --;
            }
            for(auto i:remain)
                pq.push(i);
            if(pq.empty())
                break;
            time += cycle;
        }
        return time;
    }
};