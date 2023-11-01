class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //Sol1 using 2 extra array for storing left and right products
        // vector<int> left(n, 0);
        // vector<int> right(n, 0);
        // left[0] = 1;
        // right[n-1] = 1;
        // for(int i = 1; i < n; i++){
        //     left[i] = left[i-1] * nums[i-1];
        // }
        // for(int i = n-2; i >= 0; i--){
        //     right[i] = right[i+1] * nums[i+1]; 
        // }
        // for(int i = 0; i < n; i ++){
        //     left[i] *= right[i];
        // }
        // return left;

        //Sol2 without using any extra array
        vector<int> result(n, 1);
        int pre = 1, suf = 1;
        for(int i = 0; i < n; i++){
            result[i] *= pre;
            pre *= nums[i];
            result[n-1-i] *= suf;
            suf *= nums[n-1-i]; 
        }
        return result;
    }
};