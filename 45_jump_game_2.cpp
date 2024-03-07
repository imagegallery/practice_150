class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // for(int i = 1; i < n; i++){
        //     nums[i] = max(nums[i-1], i + nums[i]);
        // }
        // int res = 0, ind = 0;
        // while(ind < n-1){
        //     res++;
        //     ind = nums[ind];
        // }
        // return res;

        int totalJump = 0, farthest = 0, currentJump = 0;
        for(int i = 0; i < n-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == currentJump){
                totalJump++;
                currentJump = farthest;
            }
        }
        return totalJump;
    }
};