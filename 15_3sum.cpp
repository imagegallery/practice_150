class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int n = nums.size();
        for(int i = 0; i < n-2; i++){
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1])
                        j++;
                    j++;
                    while(j < k && nums[k-1] == nums[k])
                        k--;
                    k--;
                }
                else if (sum < 0){
                    j++;
                }else
                    k--;
            }
        }
        

        return result;
    }
};