class Solution {
public:

    int util1(vector<int> &nums, int n, int index, int sum, int target, int &count){
        if(index >= n){
            if(sum == target)
                count ++;
            return count;
        }
       
        return util1(nums, n, index+1, sum+nums[index], target, count) + util1(nums, n, index+1, sum - nums[index], target, count);
        
    }
    int util2(vector<int> &nums, int index, int sum, vector<unordered_map<int, int> > &mp){
        if(index >= nums.size()){
            return (0 == sum) ;
        }
        
        auto it = mp[index].find(sum);
        if(it != mp[index].end())
            return it->second;
    
        mp[index][sum] = util2(nums, index+1, sum + nums[index], mp) + util2(nums, index+1, sum - nums[index], mp) ;
        
        return mp[index][sum];
    }

    int  util(vector<int> &nums, int index, int sum, int  target, map<pair<int, int> , int> &mp){
        if(index >= nums.size()){
            return (sum == target) ? 1 : 0 ;
        }
        if(mp.find({sum, index}) != mp.end())
            return mp[{sum, index}]; 
       
        mp[{sum, index}] = util(nums, index+1, sum + nums[index], target, mp) + util(nums, index+1, sum - nums[index], target, mp) ;
        
        return mp[{sum, index}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0;
        int index = 0, sum = 0;
        
        /*
        //recursive
        util1(nums, n, index, sum, target, res);
        return res;
        */

        /*
        //Memoization
        //1st  way
        vector<unordered_map<int, int> > dp(n);
        return util1(nums, index, target, dp);
        */
        //2nd way
        map<pair<int, int> , int> mp;
        return util(nums, index, 0, target, mp);
        
    }

};