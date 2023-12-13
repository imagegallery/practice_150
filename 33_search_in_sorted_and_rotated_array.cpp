class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;
            //cout << "left is: " << left << " right is: " << right << endl;
            if(nums[mid] == target)
                return mid;
            if(nums[left] <= nums[mid]){  //left sorted
                if(target >= nums[left] and target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }else{  //right sorted
                if(target >= nums[mid] and target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};