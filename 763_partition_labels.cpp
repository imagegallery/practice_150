class Solution {
public:
    int merge(vector<vector<int>> &arr){
        int start = 0;
        int n = arr.size();
        for(int i = 1; i < n; i++){
            if(arr[i][0] < arr[start][1]){
                if(arr[i][1] > arr[start][1])
                    arr[start][1] = arr[i][1];
            }
            else{
                start ++;
                arr[start] = arr[i];
            }
        }
        return start;
    }
    vector<int> partitionLabels1(string s) {
        unordered_map<char, vector<int>> mp;
        int n = s.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(mp.find(ch) == mp.end())
                mp[ch] = {i, i};
            else{
                mp[ch][1] = i;
            }
        }
        
        // for(auto item:mp){
        //     cout << item.first << " " << item.second[0] << " " << item.second[1] << endl;
        // }

        vector<vector<int>> arr;
        for(auto t : mp){
            arr.push_back(t.second);
        }
        sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });

        // for(auto t : arr){
        //     cout << t[0] << " " << t[1] << endl;
        // }

        int ind = merge(arr);
        for(int i = 0; i <= ind; i++){
            res.push_back(arr[i][1] - arr[i][0] +1);
        }

        return res;    
    }
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        for(int i = 0; i < n; i++){
            mp[s[i]] = i;
        }

        vector<int> res;
        int mxi = 0, prev = -1;

        for(int i = 0; i < n; i++){
            mxi = max(mxi, mp[s[i]]);
            if(mxi == i){
                res.push_back(mxi-prev);
                prev = mxi;
            }
        }
        return res;
    }
};