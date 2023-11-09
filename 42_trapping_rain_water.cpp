class Solution {
public:
    int trap(vector<int>& height) {
        // we need to calculate for ith element {min(max from 0 to i-1, max from i+1 to n) - height[l] >= 0}
        int l = 0, r = height.size()-1;
        int maxL = height[l], maxR = height[r];
        int ans = 0;
        while(l < r){
            if(maxL <= maxR){
                //As we need min(maxL, maxR) and here we know maxL is less than maxR 
                //so just subtract height[i] from maxL only and if val is -ve then update maxL.
                l++;
                int val = (maxL - height[l]);
                if(val >= 0)
                    ans += val;
                else
                    maxL = height[l];
            }else{
                r--;
                int val = maxR - height[r];
                if(val >= 0)
                    ans += val;
                else
                    maxR = height[r];
            }
        }
        return ans;
    }
};