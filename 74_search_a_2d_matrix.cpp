class Solution {
public:
    int binary_search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        while(st <= end){
            int mid = (st+end)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                end = mid-1;
            else
                st = mid + 1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //col
        int row = 0;
        for(int i = 0; i< m; i++){
            if (matrix[i][n-1] == target)
                return true;
            if(matrix[i][n-1] > target){
                row = i;break;
            }
        }
        if(binary_search(matrix[row], target) == -1)
            return false;
        return true;
    }
};