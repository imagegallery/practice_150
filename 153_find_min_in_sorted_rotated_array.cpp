class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        int left = 0, right = sz-1;
        //one sol more optimized
        while(left < right){
            int mid = (left+right)/2;
            if(nums[mid] < nums[right])
                right = mid;
            else if(nums[mid] > nums[right])
                left = mid + 1;
            
        }
        return nums[left];

        //another sol
        // while(left < right){
        //     if(nums[left] < nums[right])
        //         return nums[left];
        //     int mid = (left + right) / 2;
        //     if(nums[mid] >= nums[left]) { //left is sorted
        //         left = mid + 1;
        //     }else{
        //         right = mid;
        //     }
        // }
        // return nums[left];
        
    }
};