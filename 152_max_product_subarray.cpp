class Solution {
public:
    int maxProduct_accepted(vector<int>& nums) {
        double pre = 1, suff = 1;
        double res = INT_MIN;
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            pre = pre * nums[i];
            suff = suff * nums[sz-1-i];
            res = max({res, pre, suff});
            if(pre == 0)
                pre = 1;
            if(suff == 0)
                suff = 1;
            //double temp = currMax * nums[i];
            //currMax = max(temp, max(currMin*nums[i], nums[i]));
            //currMin = min(temp, min(currMin*nums[i], nums[i]));
            //res = max(res, max(currMax, currMin));
        }    
        return res;
        
    }
    
    int maxProduct(vector<int>& nums) {
        double currMax = 1, currMin = 1;
        double res = INT_MIN;
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            
            double temp = currMax * nums[i];
            currMax = max(temp, max(currMin*nums[i], (double)nums[i]));
            currMin = min(temp, min(currMin*nums[i], (double)nums[i]));
            res = max(res, max(currMax, currMin));
        }    
        return res;
    }
      
};