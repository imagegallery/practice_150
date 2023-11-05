class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int minjumps = 0;
        int n = nums.size();
        for(int i = n-2; i>= 0; i--){
            minjumps++;
            if(nums[i] >= minjumps)
                minjumps = 0;
        }
        return (minjumps==0);

        //Failing for the last test case [1,0,8,0]
        // int n = nums.size();
        
        // vector<bool> jumps(n, false);
        // jumps[0] = true;
        // for(int i = 0; i < n-1; i++){
        //     if(nums[i] >= n)
        //         return true;
        //     else{
        //         if(jumps[i] == false)
        //             return false;
                
        //         for(int j = i+1; j <= i + nums[i]; j++){
        //             jumps[j] = true;
        //             if(j == n-1)
        //                 return true;
        //         }
        //     }
        // }
        // return jumps[n-1];
    }
};