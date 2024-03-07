class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0], sum = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            temp = max(nums[i], nums[i]+temp);
            sum = max(temp, sum);
            //cout << "temp is: " << temp << " sum is: " << sum << endl; 
        }
        return sum;

    }
};