class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //This solution gives you TLE.
        
        // int n = houses.size();
        // vector<int> temp(n, INT_MAX);
        // int radius = 0;
        // for(auto heater: heaters){
        //     int i = 0;
        //     for(auto house: houses){
        //         temp[i] = min(temp[i], abs(heater-house));
        //         radius = max(radius, temp[i]);
        //         i++;
        //     }
        // }
        
        // return radius;

        /*
        Example:    h = house,  * = heater  M = INT_MAX

        h   h   h   h   h   h   h   h   h    houses
        1   2   3   4   5   6   7   8   9    index
        *           *       *                heaters
                
        0   2   1   0   1   0   -   -   -    (distance to nearest RHS heater)
        0   1   2   0   1   0   1   2   3    (distance to nearest LHS heater)

        0   1   1   0   1   0   1   2   3    (res = minimum of above two)

        Result is maximum value in res, which is 3.
        */

        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());

        vector<int> temp(houses.size(), INT_MAX);
        int radius = 0;

        for(int i = 0, h = 0; i < houses.size() && h < heaters.size();){
            if(houses[i] <= heaters[h]){
                temp[i] = heaters[h] - houses[i];
                i++;
            }else{
                h++;
            }
        }
        for(int i = houses.size() - 1, h = heaters.size() - 1; i >= 0 && h >= 0;){
            if(houses[i] >= heaters[h]){
                temp[i] = min(temp[i], houses[i] - heaters[h]);
                i--;
            }else{
                h--;
            }
            
        }
        for(auto i: temp){
            radius = max(radius, i);
        }
        return radius;
    }
};