class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //    Extra memory and more then one pass.
    //    unordered_map <int, int> mp;
    //    int sz = nums.size();

    //    for(auto n:nums){
    //        mp[n]++;
    //    }
    //    for(auto itr: mp){
    //        if(itr.second > sz/2)
    //         return itr.first;
    //    }
    //    return 0;

        //o(n) time and constant space
        //        for eg: 2,2,1,1,3,3,3,3,1,1,1,1,1,
        //count =         1 2 1 0 1 2 3 4 3 2 1 0 1
        //majority =      2 2 2 1 3 3 3 3 3 3 3 1 1


        int majority = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(majority == nums[i])
                count++;
            else{
                if(count == 0){
                    majority = nums[i];
                    count ++;
                }
                else{
                    count--;
                    if(count == 0)
                        majority = nums[i];
                }
            }
        }
        return majority;
    }
};