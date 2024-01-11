class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, float> > temp;
        for(int i = 0; i < n; i++){
            temp.push_back(make_pair(position[i], (float)(target-position[i])/speed[i]));
        }
        sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int>b)
            {return a.first < b.first;});
    
        float maxTime = 0;
        int fleet = 0;
        for(int i = n-1; i>=0; i--){
            //cout << st.top() << " " << temp[i].second << endl;
            if(temp[i].second > maxTime){
                maxTime = temp[i].second;
                fleet++;
            }
                //st.push(temp[i].second);
        }
        return fleet;
        //return st.size();
    }
};