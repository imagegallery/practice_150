
class Solution {
public:
    bool isMatch(vector<int>& triplet, vector<int>& target){
        return triplet[0] == target[0] && triplet[1] == target[1] && triplet[2] == target[2];
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
       
        /*
        int first = 0, second = 0, third = 0;
        
        for(auto t:triplets){
            if(t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2])
                first = 1;
            if(t[0] <= target[0] && t[1] == target[1] && t[2] <= target[2])
                second = 1;
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] == target[2])
                third = 1;
        }
        // Another kind of for loop
        for(auto t:triplets){
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
                first = max(first, t[0]);
                second = max(second, t[1]);
                third = max(third, t[2]);
            }
        }
        */
        vector<int> res(3, 0);
        for(auto t:triplets){
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
                res = {max(res[0], t[0]), max(res[1], t[1]), max(res[2], t[2]) };
            }
        }
        return res == target;
    }
};