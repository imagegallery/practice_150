class MyHashMap {
    int m_size = 10000;
    vector<vector<pair<int, int>>> map;
public:
    
    MyHashMap() {
        map.resize(m_size);
    }
    
    void put(int key, int value) {
        int index = key % m_size;
        vector<pair<int, int>> &row = map[index];
        for(auto iter = row.begin(); iter != row.end(); iter++){
            if(iter->first == key){
                iter->second = value;
                return ;
            }
        }
        row.push_back({key, value});
    }
    
    int get(int key) {
        //return map[key];
        int index = key % m_size;
        vector<pair<int, int>> &row = map[index];
        for(auto iter = row.begin(); iter != row.end(); iter++){
            if(iter->first == key){
                return iter->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        //map[key] = -1;
        int index = key % m_size;
        vector<pair<int, int>> &row = map[index];
        for(auto iter = row.begin(); iter != row.end(); iter++){
            if(iter->first == key){
                row.erase(iter);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */