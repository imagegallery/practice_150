class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i <= 31; i++){
            int sum = 0;
            for(int j = 0; j < nums.size(); j++){
                sum += (nums[j]>>i) & 1;
            }
            sum = sum % 3;
            res |= sum << i;
        }
        return res;
    }
};