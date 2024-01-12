class TimeMap {
public:
    unordered_map<string, vector<pair<int, string> > >u_map;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        //timestamps are sorted
        /*if(u_map.find(key) != u_map.end()){
            u_map[key].push_back(make_pair(timestamp, value));
            vector<pair<int, string>> temp = u_map[key];
            sort(temp.begin(), temp.end(), [](pair<int, string> a, pair<int, string> b){return a.first < b.first;});
            u_map[key] = temp;
        }else
        {
            u_map[key].push_back(make_pair(timestamp, value));
        }*/
        u_map[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        int index = -1;
        //if(u_map.find(key) == u_map.end())
        //    return "";
        if(u_map.count(key) == 0)
            return "";
        int sz = u_map[key].size();
        int start = 0, end = sz;
        while(start < end){
            int mid = (start + end)/2;
            if(u_map[key][mid].first > timestamp)
                end = mid;
            else
                start = mid + 1;
        }
        if(start > 0 && start <= sz)
            return u_map[key][start-1].second;
        else
            return "";
       
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */