class Solution {
public:
    bool findSuccessors(vector<int> &hand, int groupSize, int i, int n){
        int next = hand[i] + 1;
        int count = 1;
        hand[i] = -1;

        i ++;
        while(i < n && count < groupSize){
            if(hand[i] == next){
                next = hand[i] + 1;
                count ++;
                hand[i] = -1;
            }
            i++; 
        }
        return count == groupSize;
    }
    bool isNStraightHand1(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
            return false;   

        sort(hand.begin(), hand.end());

        for(int i = 0; i < n; i++){
            if(hand[i] >= 0){
                if(!findSuccessors(hand, groupSize, i, n))
                    return false;
            }
        }
        return true;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int, int> mp;

        for(auto i:hand){
            mp[i] ++;
        }

        priority_queue<int, vector<int>, greater<int>> minH;
        for(auto i:mp){
            minH.push(i.first);
        }

        while(!minH.empty()){
            int i = minH.top();
            for(int j = 0; j < groupSize; j++){
                int next = i+j;
                if(mp.find(next) == mp.end())
                    return false;
                mp[next] -=1;
                if(mp[next] == 0){
                    if(next != minH.top())
                        return false;
                    minH.pop();
                }
            }
        }
        return true;
    }
};